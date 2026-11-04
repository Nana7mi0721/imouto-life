import json
d=open('work/Data/BasicData/CommonEvent.dat','rb').read()
def score(t,cp):
    s=0
    for ch in t:
        c=ord(ch)
        if ch=='\ufffd': s-=30
        elif 0xFF61<=c<=0xFF9F: s-=6 if cp else 0
        elif 0x3040<=c<=0x30FF: s+=3
        elif 0x4E00<=c<=0x9FFF: s+=2
        elif 0x3000<=c<=0x303F: s+=1
    return s
res=[]
for kw in ['\u81ea\u52d5\u521d\u671f\u5316','\u5ea7\u6a19\u5909\u6570\u521d\u671f\u5316','\u5fdc\u63f4\u4f1a\u8a71']:
    b=kw.encode('cp932'); i=d.find(b)
    seg=d[i-6:i+len(b)+2] if i>=0 else b''
    cp=seg.decode('cp932','replace'); gb=seg.decode('gbk','replace')
    res.append({'kw':kw,'idx':i,'cp':cp,'gb':gb,'cp_score':score(cp,True),'gb_score':score(gb,False)})
print(json.dumps(res,ensure_ascii=True,indent=1))
