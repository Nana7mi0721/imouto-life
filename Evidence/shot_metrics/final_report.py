import sys, json, math
sys.path.insert(0,'work/out/shot_metrics')
from lib import load
import numpy as np

def g_of(tag):
    a,size = load(tag)
    return a.mean(axis=2), size

def prof_rows(g, x0, x1, y0, y1, bg):
    return np.clip(g[y0:y1+1, x0:x1+1]-bg, 0, None).sum(axis=1)

def bands(p, y0, frac=0.10, minink=3.0):
    mx = p.max(); th = mx*frac
    out=[]; s=None
    for i,v in enumerate(p):
        if v>th:
            if s is None: s=i
        else:
            if s is not None:
                out.append((s,i-1)); s=None
    if s is not None: out.append((s,len(p)-1))
    # drop tiny bands
    out=[(a,b) for a,b in out if p[a:b+1].max()>=minink]
    return [(y0+a, y0+b) for a,b in out]

def sub_top(p, i0, i1, frac=0.35):
    "subpixel top/bot of band [i0,i1] using frac of band peak, linear interp"
    seg = p[i0:i1+1]
    mx = seg.max(); t = mx*frac
    a = np.nonzero(seg>=t)[0][0]; b = np.nonzero(seg>=t)[0][-1]
    top = i0+a
    if a>0:
        top = i0+a - (seg[a]-t)/(seg[a]-seg[a-1])
    bot = i0+b
    if b<len(seg)-1:
        bot = i0+b + (seg[b]-t)/(seg[b]-seg[b+1])
    cen = (seg*np.arange(i0,i1+1)).sum()/seg.sum()
    return top, bot, cen

def lsq_pitch(vals):
    x = np.arange(len(vals), dtype=float)
    A = np.vstack([x, np.ones_like(x)]).T
    m,b = np.linalg.lstsq(A, np.array(vals), rcond=None)[0]
    return m

def xcorr_pitch(p, lo, hi):
    p = p - p.mean()
    best=(-1e9,None)
    for lag in range(lo, hi+1):
        v = float((p[:-lag]*p[lag:]).sum()/math.sqrt((p[:-lag]**2).sum()*(p[lag:]**2).sum()))
        if v>best[0]: best=(v,lag)
    return best[1], best[0]

res={}

# ---------- message windows ----------
MSG = {
 '89EF6522': dict(x0=300, x1=1050, y0=725, y1=845, bg=25, thr=170),
 '7125681D': dict(x0=300, x1=1050, y0=725, y1=845, bg=25, thr=170),
 '4F39D9DB': dict(x0=300, x1=1050, y0=725, y1=845, bg=25, thr=170),
}
msg={}
for tag,cfg in MSG.items():
    g,size = g_of(tag); s = size[0]/1024.0
    p = prof_rows(g, cfg['x0'], cfg['x1'], cfg['y0'], cfg['y1'], cfg['bg'])
    bs = bands(p, cfg['y0'])
    rows=[]
    for (ya,yb) in bs:
        t,b,c = sub_top(p, ya-cfg['y0'], yb-cfg['y0'])
        rows.append(dict(top=ya+t, bot=ya+b, cen=ya+c, h=(ya+b)-(ya+t)))
    tops=[r['top'] for r in rows]; cens=[r['cen'] for r in rows]
    pitch_top = lsq_pitch(tops) if len(tops)>1 else None
    pitch_cen = lsq_pitch(cens) if len(cens)>1 else None
    xc = xcorr_pitch(p, 25, 55)
    msg[tag]=dict(size=size, s=s, bands=[[r['top'],r['bot']] for r in rows],
                  ink_h=[r['h'] for r in rows],
                  pitch_screen=dict(top_lsq=pitch_top, cen_lsq=pitch_cen, xcorr=xc[0], xcorr_r=xc[1]),
                  pitch_native=dict(top_lsq=(pitch_top/s if pitch_top else None),
                                    cen_lsq=(pitch_cen/s if pitch_cen else None),
                                    xcorr=xc[0]/s))
res['message']=msg
print('--- message windows ---')
for tag,v in msg.items():
    print(tag, 'size',v['size'], 's=%.4f'%v['s'])
    print('  bands', [[round(a,1),round(b,1)] for a,b in v['bands']], 'ink_h',[round(h,2) for h in v['ink_h']])
    print('  pitch screen', {k:(round(x,3) if x else x) for k,x in v['pitch_screen'].items()},
          ' native', {k:(round(x,3) if x else x) for k,x in v['pitch_native'].items()})

# ---------- choice panels ----------
def panel(tag, cfg):
    g,size = g_of(tag); s=size[0]/1024.0
    # border bright-line centers
    L = brightline(g, cfg['row'], cfg['Lwin'], axis=0)
    R = brightline(g, cfg['row'], cfg['Rwin'], axis=0)
    T = brightline(g, cfg['col'], cfg['Twin'], axis=1)
    B = brightline(g, cfg['col'], cfg['Bwin'], axis=1)
    p = prof_rows(g, cfg['x0'], cfg['x1'], cfg['y0'], cfg['y1'], cfg['bg'])
    bs = bands(p, cfg['y0'])
    rows=[]
    for (ya,yb) in bs:
        t,b,c = sub_top(p, ya-cfg['y0'], yb-cfg['y0'])
        xs = ink_x(g, ya, yb, cfg['x0'], cfg['x1'], cfg['bg'], cfg['thr'])
        rows.append(dict(top=ya+t, bot=ya+b, cen=ya+c, h=(ya+b)-(ya+t), x=xs))
    tops=[r['top'] for r in rows]; cens=[r['cen'] for r in rows]
    return dict(size=size, s=s, L=L, R=R, T=T, B=B, rows=rows,
                pitch_screen=dict(top_lsq=lsq_pitch(tops), cen_lsq=lsq_pitch(cens)),
                pitch_native=dict(top_lsq=lsq_pitch(tops)/s, cen_lsq=lsq_pitch(cens)/s))

def brightline(g, idx, win, axis):
    if axis==0:
        seg = g[idx, win[0]:win[1]+1]
        x0 = win[0]
    else:
        seg = g[win[0]:win[1]+1, idx]
        x0 = win[0]
    i = int(np.argmax(seg))
    # parabola vertex on 3 points
    if 0<i<len(seg)-1:
        y0_,y1_,y2_ = seg[i-1], seg[i], seg[i+1]
        denom = (y0_-2*y1_+y2_)
        off = 0.5*(y0_-y2_)/denom if denom!=0 else 0.0
    else:
        off = 0.0
    return x0 + i + off, float(seg[i])

def ink_x(g, ya, yb, x0, x1, bg, thr):
    sub = g[ya:yb+1, x0:x1+1]
    col = np.clip(sub-bg,0,None).max(axis=0)
    idx = np.nonzero(col>=thr)[0]
    if len(idx)==0: return None
    return [x0+int(idx[0]), x0+int(idx[-1])]

P89 = dict(row=420, Lwin=(630,650), Rwin=(860,890), col=700, Twin=(336,356), Bwin=(505,530),
           x0=650, x1=872, y0=352, y1=512, bg=60, thr=185)
PEE = dict(row=400, Lwin=(626,650), Rwin=(868,895), col=750, Twin=(336,356), Bwin=(550,570),
           x0=648, x1=882, y0=352, y1=555, bg=59, thr=185)
pan={}
for tag,cfg in [('89EF6522',P89), ('EE3763D0',PEE)]:
    pan[tag]=panel(tag,cfg)
res['choice_panel']=pan
print('--- choice panels ---')
for tag,v in pan.items():
    print(tag,'size',v['size'],'s=%.4f'%v['s'])
    print('  L=%.2f(%.0f) R=%.2f(%.0f) T=%.2f(%.0f) B=%.2f(%.0f)'%(v['L'][0],v['L'][1],v['R'][0],v['R'][1],v['T'][0],v['T'][1],v['B'][0],v['B'][1]))
    W=v['R'][0]-v['L'][0]; H=v['B'][0]-v['T'][0]
    print('  W=%.2f screen = %.2f native ; H=%.2f screen = %.2f native'%(W,W/v['s'],H,H/v['s']))
    for i,r in enumerate(v['rows']):
        print('   row%d top=%.2f bot=%.2f h=%.2f cen=%.2f x=%s w=%s'%(i, r['top'],r['bot'],r['h'],r['cen'], r['x'], (r['x'][1]-r['x'][0]) if r['x'] else None))
    print('  pitch screen', {k:round(x,3) for k,x in v['pitch_screen'].items()}, 'native', {k:round(x,3) for k,x in v['pitch_native'].items()})
    r0=v['rows'][0]; rl=v['rows'][-1]
    print('  top pad (T->first ink top) = %.2f screen = %.2f native'%(r0['top']-v['T'][0], (r0['top']-v['T'][0])/v['s']))
    print('  bot pad (last ink bot->B) = %.2f screen = %.2f native'%(v['B'][0]-rl['bot'], (v['B'][0]-rl['bot'])/v['s']))
    print('  left inset (L->first ink left) = %.2f screen = %.2f native'%(r0['x'][0]-v['L'][0], (r0['x'][0]-v['L'][0])/v['s']))
    print('  right gap (last ink right->R) = %.2f screen = %.2f native'%(v['R'][0]-max(r['x'][1] for r in v['rows']), (v['R'][0]-max(r['x'][1] for r in v['rows']))/v['s']))
    wid=max(r['x'][1]-r['x'][0] for r in v['rows'])
    print('  W - widest ink = %.2f screen = %.2f native'%(W-wid,(W-wid)/v['s']))

json.dump(res, open('work/out/shot_metrics/metrics2.json','w',encoding='utf-8'), ensure_ascii=False, indent=1)
print('wrote metrics2.json')
