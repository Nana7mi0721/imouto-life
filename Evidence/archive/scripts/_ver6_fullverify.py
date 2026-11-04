import struct, os, sys
ARC='E:/EROGAME/Imouto! Life ~Monochrome~ zh-CN Ver/Data.wolf'
ROOT='E:/Study/github program/Imouto Life/work/Data'
SRC=bytes([0x38,0x50,0x40,0x28,0x72,0x4f,0x21,0x70,0x3b,0x73,0x35,0x38])
def keycreate(src):
    L=len(src); k=bytearray(12); i=0
    while i+L<=12: k[i:i+L]=src; i+=L
    if i<12: k[i:]=src[:12-i]
    k=list(k)
    k[0]=(~k[0])&0xFF; k[1]=((k[1]>>4)|(k[1]<<4))&0xFF; k[2]=k[2]^0x8a
    k[3]=(~(((k[3]>>4)|(k[3]<<4))&0xFF))&0xFF; k[4]=(~k[4])&0xFF; k[5]=k[5]^0xac
    k[6]=(~k[6])&0xFF; k[7]=(~(((k[7]>>3)|(k[7]<<5))&0xFF))&0xFF; k[8]=((k[8]>>5)|(k[8]<<3))&0xFF
    k[9]=k[9]^0x7f; k[10]=((((k[10]>>4)|(k[10]<<4))&0xFF))^0xd6; k[11]=k[11]^0xcc
    return bytes(k)
KEY=keycreate(SRC)
def xorat(buf,pos):
    off=pos%12
    return bytes(b^KEY[(off+i)%12] for i,b in enumerate(buf))
f=open(ARC,'rb')
Head,Version,HeadSize,DataStart,NameStart,FileStart,DirStart,CodePage=struct.unpack('<HHIQQQQQ', xorat(f.read(48),0))
f.seek(NameStart); hb=xorat(f.read(HeadSize),0)
def d_at(rel): return struct.unpack_from('<QQQQ', hb, rel)
def f_at(rel):
    na,attr=struct.unpack_from('<QQ',hb,rel); da,ds,ps=struct.unpack_from('<QQQ',hb,rel+40); return na,attr,da,ds,ps
def name_of(na):
    n=struct.unpack_from('<H', hb, na)[0]; start=na+n*4+4; end=hb.find(bytes([0]), start)
    return hb[start:end].decode('cp932', errors='replace')
res=[]
def walk(rel,prefix):
    daddr,pdir,num,faddr=d_at(rel)
    for i in range(num):
        na,attr,da,ds,ps=f_at(FileStart+faddr+i*64); nm=name_of(na)
        if attr & 0x10: walk(DirStart+da, prefix+nm+'/')
        else: res.append((prefix+nm,da,ds,ps))
walk(DirStart,'')
MINC=4
def ver6_decode(src):
    destsize=struct.unpack_from('<I',src,0)[0]; coded=struct.unpack_from('<I',src,4)[0]-9; keycode=src[8]
    out=bytearray(); sp=9; n=coded
    while n>0:
        if src[sp]!=keycode:
            out.append(src[sp]); sp+=1; n-=1; continue
        if src[sp+1]==keycode:
            out.append(keycode); sp+=2; n-=2; continue
        code=src[sp+1]
        if code>keycode: code-=1
        sp+=2; n-=2; conbo=code>>3
        if code & 0x4: conbo |= src[sp]<<5; sp+=1; n-=1
        conbo+=MINC; idxsize=code & 0x3
        if idxsize==0: index=src[sp]; sp+=1; n-=1
        elif idxsize==1: index=struct.unpack_from('<H',src,sp)[0]; sp+=2; n-=2
        else: index=struct.unpack_from('<H',src,sp)[0] | (src[sp+2]<<16); sp+=3; n-=3
        index+=1
        if index<conbo:
            num=index
            while conbo>num:
                out += out[len(out)-num:len(out)-num+num]; conbo-=num; num+=num
            if conbo: out += out[len(out)-num:len(out)-num+conbo]
        else: out += out[len(out)-index:len(out)-index+conbo]
    return bytes(out[:destsize])
ok=0; bad=[]; missing=[]; total=0
for nm,da,ds,ps in res:
    p=os.path.join(ROOT, nm.replace('/', os.sep))
    if not os.path.exists(p): missing.append(nm); continue
    if ds==0: 
        total+=0; 
        orig=open(p,'rb').read()
        if len(orig)==0: ok+=1
        else: bad.append(nm)
        continue
    f.seek(DataStart+da); raw=f.read(ps if ps!=0xffffffffffffffff else ds)
    blk=xorat(raw, ds)
    dec = blk if ps==0xffffffffffffffff else ver6_decode(blk)
    orig=open(p,'rb').read(); total+=len(orig)
    if dec==orig: ok+=1
    else: bad.append(nm)
print('entries',len(res),'verified',ok,'bad',len(bad),'missing',len(missing),'total bytes',total)
print('bad sample', bad[:5]); print('missing sample', missing[:5])
