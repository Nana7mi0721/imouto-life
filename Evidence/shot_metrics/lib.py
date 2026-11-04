import glob, numpy as np
from PIL import Image

def path(tag):
    g = glob.glob('prt sc/{%s*' % tag)
    assert g, tag
    return g[0]

def load(tag):
    im = Image.open(path(tag)).convert('RGB')
    return np.asarray(im).astype(np.float32), im.size

def rows_profile(a, x0, x1, y0, y1, thr=200):
    sub = a[y0:y1, x0:x1].mean(axis=2)
    return (sub > thr).sum(axis=1)

def runs(mask):
    out=[]; s=None
    for i,v in enumerate(mask):
        if v and s is None: s=i
        elif not v and s is not None: out.append((s,i-1)); s=None
    if s is not None: out.append((s,len(mask)-1))
    return out
