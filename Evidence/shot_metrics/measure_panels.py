import sys, json, math
sys.path.insert(0,'work/out/shot_metrics')
from lib import load
import numpy as np

def g_of(tag):
    a,size=load(tag); return a.mean(axis=2), size

def prof(g,x0,x1,y0,y1,thr):
    return np.clip(g[y0:y1+1,x0:x1+1]-thr,0,None).sum(axis=1)

def bands(p,y0,frac=0.10,gap=8,minfrac=0.03):
    mx=p.max(); th=mx*frac; out=[]; s=None; z=0
    for i,v in enumerate(p):
        if v>th:
            if s is None: s=i
            z=0
        else:
            if s is not None:
                z+=1
                if z>=gap: out.append((s,i-z)); s=None; z=0
    if s is not None: out.append((s,len(p)-1))
    return [(y0+a,y0+b) for a,b in out if p[a:b+1].max()>=mx*minfrac]

def sub_edges(p,ya,yb,y0,frac=0.40):
    i0=ya-y0; i1=yb-y0; seg=p[i0:i1+1]
    mx=seg.max(); t=mx*frac
    a=int(np.nonzero(seg>=t)[0][0]); b=int(np.nonzero(seg>=t)[0][-1])
    top=i0+a; bot=i0+b
    if a>0: top=i0+a-(seg[a]-t)/(seg[a]-seg[a-1])
    if b<len(seg)-1: bot=i0+b+(seg[b]-t)/(seg[b]-seg[b+1])
    cen=(seg*np.arange(i0,i1+1)).sum()/seg.sum()
    return float(top+y0),float(bot+y0),float(cen+y0)

def lsq(v):
    x=np.arange(len(v),dtype=float); A=np.vstack([x,np.ones_like(x)]).T
    return float(np.linalg.lstsq(A,np.array(v,dtype=float),rcond=None)[0][0])

def vertex(seg,i):
    if 0<i<len(seg)-1:
        a,b,c=float(seg[i-1]),float(seg[i]),float(seg[i+1]); d=a-2*b+c
        if d!=0: return i+0.5*(a-c)/d
    return float(i)

def bright(g,fixed,lo,hi,axis):
    seg = g[fixed,lo:hi+1] if axis==0 else g[lo:hi+1,fixed]
    i=int(np.argmax(seg)); return float(lo+vertex(seg,i)), float(seg[i]), [float(x) for x in seg]

def ink_x(g,ya,yb,x0,x1,thr):
    col=np.clip(g[ya:yb+1,x0:x1+1]-thr,0,None).max(axis=0)
    idx=np.nonzero(col>=3)[0]
    return [int(x0+idx[0]),int(x0+idx[-1])] if len(idx) else None

def cell_starts(g,ya,yb,x0,x1,thr):
    "glyph cell segmentation: columns with ink, split by >=2px gaps"
    col=np.clip(g[ya:yb+1,x0:x1+1]-thr,0,None).sum(axis=0)
    on=col>col.max()*0.02
    runs=[];s=None
    for i,v in enumerate(on):
        if v and s is None: s=i
        elif not v and s is not None: runs.append((s,i-1)); s=None
    if s is not None: runs.append((s,len(on)-1))
    return [(x0+a,x0+b) for a,b in runs if b-a>=2]

PAN={
 '89EF6522': dict(row=420,L=(636,648),R=(870,882),col=700,T=(340,350),B=(512,522),
                  x0=650,x1=870,y0=352,y1=512,thr=185,label='L/R/T/B bright line (single line, dark scene)'),
 'EE3763D0': dict(row=400,L=(638,646),R=(880,888),col=750,T=(344,352),B=(555,563),
                  x0=650,x1=874,y0=352,y1=555,thr=185,label='inner bright line (outer band excluded)'),
}
print('=== choice panels: borders + text rows ===')
pan={}
for tag,c in PAN.items():
    g,size=g_of(tag); s=size[0]/1024.0
    L=bright(g,c['row'],*c['L'],0); R=bright(g,c['row'],*c['R'],0)
    T=bright(g,c['col'],*c['T'],1); B=bright(g,c['col'],*c['B'],1)
    p=prof(g,c['x0'],c['x1'],c['y0'],c['y1'],c['thr'])
    bs=bands(p,c['y0']); rows=[]
    for ya,yb in bs:
        t,b,ce=sub_edges(p,ya,yb,c['y0'])
        xs=ink_x(g,int(round(t)),int(round(b)),c['x0'],c['x1'],c['thr'])
        cells=cell_starts(g,int(round(t)),int(round(b)),c['x0'],c['x1'],c['thr'])
        rows.append(dict(top=t,bot=b,cen=ce,h=b-t,x=xs,cells=[x[0] for x in cells]))
    W=R[0]-L[0]; H=B[0]-T[0]
    pt=lsq([r['top'] for r in rows]); pc=lsq([r['cen'] for r in rows])
    wid=max(r['x'][1]-r['x'][0] for r in rows if r['x'])
    print(tag,size,'s=%.4f'%s,'  [%s]'%c['label'])
    print('  seg L',[round(x) for x in L[2]])
    print('  seg R',[round(x) for x in R[2]])
    print('  seg T',[round(x) for x in T[2]])
    print('  seg B',[round(x) for x in B[2]])
    print('  L=%.2f R=%.2f T=%.2f B=%.2f'%(L[0],R[0],T[0],B[0]))
    print('  W=%.2f/%.2f  H=%.2f/%.2f (screen/native)'%(W,W/s,H,H/s))
    for i,r in enumerate(rows):
        print('   row%d top=%.2f bot=%.2f h=%.2f x=[%d,%d] w=%d cells=%s'%(i,r['top'],r['bot'],r['h'],r['x'][0],r['x'][1],r['x'][1]-r['x'][0],r['cells']))
    print('  pitch top=%.3f cen=%.3f | native %.3f %.3f'%(pt,pc,pt/s,pc/s))
    print('  top pad %.2f/%.2f  bot pad %.2f/%.2f'%(rows[0]['top']-T[0],(rows[0]['top']-T[0])/s,B[0]-rows[-1]['bot'],(B[0]-rows[-1]['bot'])/s))
    print('  left inset %.2f/%.2f  right gap %.2f/%.2f'%(rows[0]['x'][0]-L[0],(rows[0]['x'][0]-L[0])/s,R[0]-max(r['x'][1] for r in rows),(R[0]-max(r['x'][1] for r in rows))/s))
    print('  W-widestink %.2f/%.2f'%(W-wid,(W-wid)/s))
    pan[tag]=dict(size=list(size),s=s,border=dict(L=L[0],R=R[0],T=T[0],B=B[0]),W_screen=W,H_screen=H,
        W_native=W/s,H_native=H/s,rows=rows,pitch_screen=dict(top=pt,cen=pc),pitch_native=dict(top=pt/s,cen=pc/s),
        widest_ink=wid,W_minus_widest=(W-wid)/s,inset=(rows[0]['x'][0]-L[0])/s,
        top_pad=(rows[0]['top']-T[0])/s,bot_pad=(B[0]-rows[-1]['bot'])/s,note=c['label'])
json.dump(pan,open('work/out/shot_metrics/metrics_panels.json','w',encoding='utf-8'),ensure_ascii=False,indent=1)
print('ok panels')
