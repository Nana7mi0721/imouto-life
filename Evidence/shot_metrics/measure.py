import sys, json
sys.path.insert(0,'work/out/shot_metrics')
from lib import *
import numpy as np

def cover(g, x0, x1, y):
    "ink coverage of row y over cols x0..x1": 
    return float(np.clip(g[y, x0:x1+1]-BG,0,None).sum())

def edges(g, x0,x1, y0,y1, bg):
    prof = np.array([float(np.clip(g[y, x0:x1+1]-bg,0,None).sum()) for y in range(y0,y1+1)])
    return prof

def sub_edges(prof, y_start, thr_frac=0.30):
    mx = prof.max()
    if mx<=0: return None
    t = mx*thr_frac
    idx = np.nonzero(prof>=t)[0]
    a,b = idx[0], idx[-1]
    # interpolate top
    if a>0:
        top = y_start + a - (prof[a]-t)/(prof[a]-prof[a-1])
    else:
        top = y_start + a
    if b<prof.size-1:
        bot = y_start + b + (prof[b]-t)/(prof[b]-prof[b+1])
    else:
        bot = y_start + b
    cen = (prof*np.arange(y_start,y_start+prof.size)).sum()/prof.sum()
    return top,bot,cen,mx

def split_bands(prof, y_start, gap=2):
    "split into contiguous runs of nonzero-ish coverage"
    mx=prof.max(); th=mx*0.06
    runs=[]; s=None; z=0
    for i,v in enumerate(prof):
        if v>th:
            if s is None: s=i
            z=0
        else:
            if s is not None:
                z+=1
                if z>=gap:
                    runs.append((s,i-z)); s=None; z=0
    if s is not None: runs.append((s,len(prof)-1))
    return runs

def panel_rect(g, x0,x1,y0,y1, bg, thr=150):
    "find bright border lines: columns/rows whose max is high & coverage large"
    sub=g[y0:y1+1, x0:x1+1]
    colmax=sub.max(axis=0); rowmax=sub.max(axis=1)
    return colmax,rowmax

if __name__=='__main__':
    pass
