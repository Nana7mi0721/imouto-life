import sys, glob, os, json
sys.path.insert(0,'work/out/shot_metrics')
from lib import load
import numpy as np
from PIL import Image

def tag_of(f):
    n=os.path.basename(f); return n[1:9] if n.startswith('{') else n[:8]

files=sorted(glob.glob('prt sc/*.png'))
cands={}
for f in files:
    tag=tag_of(f)
    a,size=load(tag); g=a.mean(axis=2)
    H,W=g.shape
    # coarse grid 8x8 blocks: uniform & dark
    bs=8
    gy, gx = H//bs, W//bs
    blk=g[:gy*bs,:gx*bs].reshape(gy,bs,gx,bs)
    mu=blk.mean(axis=(1,3)); sd=blk.std(axis=(1,3))
    m=(sd<6)&(mu>25)&(mu<66)
    # find rows of blocks with >=8 consecutive uniform-dark blocks
    hits=[]
    for y in range(gy):
        run=0; best=(0,None)
        for x in range(gx):
            if m[y,x]: run+=1
            else:
                if run>best[0]: best=(run,x-run)
                run=0
        if run>best[0]: best=(run,gx-run)
        if best[0]>=10: hits.append((y*bs,best[1]*bs,best[0]*bs))
    if hits:
        ys=[h[0] for h in hits]
        cands[tag]=dict(size=list(size), rows=len(hits), y0=min(ys), y1=max(ys)+bs,
                        x0=min(h[1] for h in hits), x1=max(h[1]+h[2] for h in hits))
print(json.dumps(cands, ensure_ascii=False, indent=1))
