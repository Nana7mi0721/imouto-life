import sys, json, math
sys.path.insert(0,'work/out/shot_metrics')
from lib import load
import numpy as np

def g_of(tag):
    a,size=load(tag); return a.mean(axis=2), size

def vertex(seg,i):
    if 0<i<len(seg)-1:
        a,b,c=float(seg[i-1]),float(seg[i]),float(seg[i+1]); d=a-2*b+c
        if d!=0: return i+0.5*(a-c)/d
    return float(i)

def bright(g,fixed,lo,hi,axis,expect):
    "locate the bright line near 'expect' (screen px) and refine by parabola"
    seg = g[fixed,lo:hi+1] if axis==0 else g[lo:hi+1,fixed]
    i=int(np.argmax(seg)); pos=float(lo+vertex(seg,i)); val=float(seg[i])
    return pos,val,[float(x) for x in seg],lo

def panel(tag,c):
    g,size=g_of(tag); s=size[0]/1024.0
    L=bright(g,c['row'],*c['L'],0,None)
    R=bright(g,c['row'],*c['R'],0,None)
    T=bright(g,c['col'],*c['T'],1,None)
    B=bright(g,c['col'],*c['B'],1,None)
    W=R[0]-L[0]; H=B[0]-T[0]
    return dict(tag=tag,size=list(size),s=s,L=L[0],R=R[0],T=T[0],B=B[0],
                W_screen=W,H_screen=H,W_native=W/s,H_native=H/s,
                seg=dict(L=L[2],Loff=L[3],R=R[2],Roff=R[3],T=T[2],Toff=T[3],B=B[2],Boff=B[3]))

CFG={
 '89EF6522': dict(row=420,L=(636,648),R=(870,882),col=700,T=(340,350),B=(512,522)),
 'EE3763D0': dict(row=400,L=(639,644),R=(882,887),col=750,T=(346,351),B=(557,562)),
}
out={}
for tag,c in CFG.items():
    p=panel(tag,c); out[tag]=p
    print(tag,p['size'],'s=%.4f'%p['s'])
    for k,off in [('L',p['seg']['Loff']),('R',p['seg']['Roff']),('T',p['seg']['Toff']),('B',p['seg']['Boff'])]:
        seg=p['seg'][k]
        print('  %s window %d..%d  %s'%(k,off,off+len(seg)-1,[round(x) for x in seg]))
    print('  L=%.2f R=%.2f T=%.2f B=%.2f'%(p['L'],p['R'],p['T'],p['B']))
    print('  W=%.2f screen / %.2f native ; H=%.2f / %.2f'%(p['W_screen'],p['W_native'],p['H_screen'],p['H_native']))
json.dump(out,open('work/out/shot_metrics/metrics_borders.json','w',encoding='utf-8'),ensure_ascii=False,indent=1)
print('---')
print('W diff native = %.2f'%(out['EE3763D0']['W_native']-out['89EF6522']['W_native']))
print('L diff screen = %.2f'%(out['EE3763D0']['L']-out['89EF6522']['L']))
