import sys, json, math
sys.path.insert(0,'work/out/shot_metrics')
from lib import load
import numpy as np

def g_of(tag):
    a,size = load(tag)
    return a.mean(axis=2), size

def prof(g, x0, x1, y0, y1, bg):
    return np.clip(g[y0:y1+1, x0:x1+1]-bg, 0, None).sum(axis=1)

def bands(p, y0, frac=0.08, minfrac=0.02):
    mx=p.max(); th=mx*frac; out=[]; s=None
    for i,v in enumerate(p):
        if v>th:
            if s is None: s=i
        else:
            if s is not None:
                out.append((s,i-1)); s=None
    if s is not None: out.append((s,len(p)-1))
    return [(y0+a,y0+b) for a,b in out if p[a:b+1].max()>=mx*minfrac]

def sub_edges(p, ya, yb, y0, frac=0.40):
    i0=ya-y0; i1=yb-y0; seg=p[i0:i1+1]
    mx=seg.max(); t=mx*frac
    a=int(np.nonzero(seg>=t)[0][0]); b=int(np.nonzero(seg>=t)[0][-1])
    top=i0+a; bot=i0+b
    if a>0: top=i0+a-(seg[a]-t)/(seg[a]-seg[a-1])
    if b<len(seg)-1: bot=i0+b+(seg[b]-t)/(seg[b]-seg[b+1])
    cen=(seg*np.arange(i0,i1+1)).sum()/seg.sum()
    return top+y0, bot+y0, cen+y0

def lsq(v):
    x=np.arange(len(v),dtype=float)
    A=np.vstack([x,np.ones_like(x)]).T
    return float(np.linalg.lstsq(A,np.array(v,dtype=float),rcond=None)[0][0])

def xcorr(p, lo, hi):
    p=p-p.mean(); best=(-9,None)
    for lag in range(lo,hi+1):
        a=p[:-lag]; b=p[lag:]
        r=float((a*b).sum()/math.sqrt((a*a).sum()*(b*b).sum()))
        if r>best[0]: best=(r,lag)
    return best[1],best[0]

def vertex(seg, i):
    if 0<i<len(seg)-1:
        y0_,y1_,y2_=float(seg[i-1]),float(seg[i]),float(seg[i+1])
        d=(y0_-2*y1_+y2_)
        if d!=0: return i+0.5*(y0_-y2_)/d
    return float(i)

def bright(g, fixed, lo, hi, axis):
    seg = g[fixed, lo:hi+1] if axis==0 else g[lo:hi+1, fixed]
    i=int(np.argmax(seg))
    return lo+vertex(seg,i), float(seg[i])

def ink_x(g, ya, yb, x0, x1, bg, thr):
    sub=g[ya:yb+1, x0:x1+1]
    col=np.clip(sub-bg,0,None).max(axis=0)
    idx=np.nonzero(col>=thr)[0]
    if len(idx)==0: return None
    return [int(x0+idx[0]), int(x0+idx[-1])]

MSG = {
 '89EF6522': dict(x0=300,x1=1050,y0=730,y1=845,bg=25),
 '7125681D': dict(x0=300,x1=1050,y0=730,y1=845,bg=25),
 '4F39D9DB': dict(x0=300,x1=1050,y0=730,y1=845,bg=25),
}
out={}
print('=== message windows ===')
for tag,c in MSG.items():
    g,size=g_of(tag); s=size[0]/1024.0
    p=prof(g,c['x0'],c['x1'],c['y0'],c['y1'],c['bg'])
    bs=bands(p,c['y0'])
    rows=[]
    for ya,yb in bs:
        t,b,ce=sub_edges(p,ya,yb,c['y0'])
        rows.append((t,b,ce,b-t))
    print(tag,size,'s=%.4f'%s,'bands',[(round(r[0],1),round(r[1],1)) for r in rows],'h',[round(r[3],2) for r in rows])
    if len(rows)>1:
        pt=lsq([r[0] for r in rows]); pc=lsq([r[2] for r in rows])
        xc=xcorr(p,28,45)
        print('  pitch screen top=%.3f cen=%.3f xcorr=%d(r=%.3f) | native top=%.3f cen=%.3f xcorr=%.3f'%(pt,pc,xc[0],xc[1],pt/s,pc/s,xc[0]/s))
        out[tag]=dict(size=size,s=s,bands=[[r[0],r[1]] for r in rows],ink_h=[r[3] for r in rows],
                      pitch_screen=dict(top=pt,cen=pc,xcorr=xc[0],xcorr_r=xc[1]),
                      pitch_native=dict(top=pt/s,cen=pc/s,xcorr=xc[0]/s))
    else:
        out[tag]=dict(size=size,s=s,bands=[[r[0],r[1]] for r in rows],ink_h=[r[3] for r in rows])

PAN = {
 '89EF6522': dict(row=420, L=(630,650), R=(860,890), col=700, T=(336,356), B=(512,530),
                  x0=652,x1=868,y0=352,y1=512,bg=60,thr=185),
 'EE3763D0': dict(row=400, L=(626,650), R=(868,895), col=750, T=(336,356), B=(553,572),
                  x0=652,x1=876,y0=352,y1=555,bg=59,thr=185),
}
print('=== choice panels ===')
pan={}
for tag,c in PAN.items():
    g,size=g_of(tag); s=size[0]/1024.0
    L=bright(g,c['row'],c['L'][0],c['L'][1],0)
    R=bright(g,c['row'],c['R'][0],c['R'][1],0)
    T=bright(g,c['col'],c['T'][0],c['T'][1],1)
    B=bright(g,c['col'],c['B'][0],c['B'][1],1)
    p=prof(g,c['x0'],c['x1'],c['y0'],c['y1'],c['bg'])
    bs=bands(p,c['y0'])
    rows=[]
    for ya,yb in bs:
        t,b,ce=sub_edges(p,ya,yb,c['y0'])
        xs=ink_x(g,int(round(t)),int(round(b)),c['x0'],c['x1'],c['bg'],c['thr'])
        rows.append(dict(top=t,bot=b,cen=ce,h=b-t,x=xs))
    W=R[0]-L[0]; H=B[0]-T[0]
    pt=lsq([r['top'] for r in rows]); pc=lsq([r['cen'] for r in rows])
    wid=max(r['x'][1]-r['x'][0] for r in rows if r['x'])
    print(tag,size,'s=%.4f'%s)
    print('  L=%.2f(%.0f) R=%.2f(%.0f) T=%.2f(%.0f) B=%.2f(%.0f)'%(L[0],L[1],R[0],R[1],T[0],T[1],B[0],B[1]))
    print('  W=%.2f screen / %.2f native ; H=%.2f / %.2f'%(W,W/s,H,H/s))
    for i,r in enumerate(rows):
        print('   row%d top=%.2f bot=%.2f h=%.2f cen=%.2f x=%s'%(i,r['top'],r['bot'],r['h'],r['cen'],r['x']))
    print('  pitch top=%.3f cen=%.3f screen | %.3f %.3f native'%(pt,pc,pt/s,pc/s))
    print('  top pad %.2f/%.2f  bot pad %.2f/%.2f'%(rows[0]['top']-T[0],(rows[0]['top']-T[0])/s, B[0]-rows[-1]['bot'],(B[0]-rows[-1]['bot'])/s))
    print('  left inset %.2f/%.2f  right gap %.2f/%.2f'%(rows[0]['x'][0]-L[0],(rows[0]['x'][0]-L[0])/s, R[0]-max(r['x'][1] for r in rows),(R[0]-max(r['x'][1] for r in rows))/s))
    print('  W-widestink %.2f/%.2f'%(W-wid,(W-wid)/s))
    pan[tag]=dict(size=size,s=s,border=dict(L=L[0],R=R[0],T=T[0],B=B[0]),W_screen=W,H_screen=H,W_native=W/s,H_native=H/s,
                  rows=rows,pitch_screen=dict(top=pt,cen=pc),pitch_native=dict(top=pt/s,cen=pc/s),
                  widest_ink=wid,W_minus_widest=(W-wid)/s,
                  inset=(rows[0]['x'][0]-L[0])/s, top_pad=(rows[0]['top']-T[0])/s, bot_pad=(B[0]-rows[-1]['bot'])/s)
out['choice_panel']=pan

def conv(o):
    if isinstance(o,dict): return {k:conv(v) for k,v in o.items()}
    if isinstance(o,(list,tuple)): return [conv(v) for v in o]
    if isinstance(o,(np.floating,)): return float(o)
    if isinstance(o,(np.integer,)): return int(o)
    return o
json.dump(conv(out), open('work/out/shot_metrics/metrics2.json','w',encoding='utf-8'), ensure_ascii=False, indent=1)
print('wrote metrics2.json')
