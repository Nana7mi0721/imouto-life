import struct, os, collections
ARC = 'E:/EROGAME/Imouto! Life ~Monochrome~ zh-CN Ver/Data.wolf'
ROOT = 'E:/Study/github program/imoto life/work/imouto/Data'
SRC = bytes([0x38,0x50,0x40,0x28,0x72,0x4f,0x21,0x70,0x3b,0x73,0x35,0x38])
def keycreate(src):
    L=len(src); k=bytearray(12)
    if L>12: k[:]=src[:12]
    else:
        i=0
        while i+L<=12:
            k[i:i+L]=src; i+=L
        if i<12: k[i:]=src[:12-i]
    k=list(k)
    k[0]=(~k[0])&0xFF
    k[1]=((k[1]>>4)|(k[1]<<4))&0xFF
    k[2]=k[2]^0x8a
    k[3]=(~(((k[3]>>4)|(k[3]<<4))&0xFF))&0xFF
    k[4]=(~k[4])&0xFF
    k[5]=k[5]^0xac
    k[6]=(~k[6])&0xFF
    k[7]=(~(((k[7]>>3)|(k[7]<<5))&0xFF))&0xFF
    k[8]=((k[8]>>5)|(k[8]<<3))&0xFF
    k[9]=k[9]^0x7f
    k[10]=((((k[10]>>4)|(k[10]<<4))&0xFF))^0xd6
    k[11]=k[11]^0xcc
    return bytes(k)
KEY=keycreate(SRC)
def xorat(buf,pos):
    off=pos%12
    return bytes(b^KEY[(off+i)%12] for i,b in enumerate(buf))
f=open(ARC,'rb')
Head,Version,HeadSize,DataStart,NameStart,FileStart,DirStart,CodePage=struct.unpack('<HHIQQQQQ', xorat(f.read(48),0))
print('Head %x Version %d HeadSize %d DataStart %d NameStart %d FileStart %d DirStart %d CodePage %d' % (Head,Version,HeadSize,DataStart,NameStart,FileStart,DirStart,CodePage))
f.seek(NameStart); hb=xorat(f.read(HeadSize),0)
def d_at(rel): return struct.unpack_from('<QQQQ', hb, rel)
def f_at(rel):
    na,attr=struct.unpack_from('<QQ',hb,rel)
    da,ds,ps=struct.unpack_from('<QQQ',hb,rel+40)
    return na,attr,da,ds,ps
names=[]
def walk(rel,prefix):
    daddr,pdir,num,faddr=d_at(rel)
    for i in range(num):
        na,attr,da,ds,ps=f_at(FileStart+faddr+i*64)
        end=hb.find(bytes([0]),na)
        nm=hb[na:end].decode('cp932',errors='replace')
        if attr & 0x10: walk(DirStart+da, prefix+nm+'/')
        else: names.append((prefix+nm,ds,ps))
walk(DirStart,'')
print('files:',len(names),'total size:',sum(d for _,d,_ in names))
print('top:',collections.Counter(n.split('/')[0] for n,_,_ in names).most_common(25))
disk=set()
for dp,dn,fn in os.walk(ROOT):
    for x in fn:
        rel=os.path.relpath(os.path.join(dp,x),ROOT).replace(chr(92),'/')
        disk.add(rel)
arc=set(n for n,_,_ in names)
print('on disk:',len(disk),'in arc:',len(arc),'missing:',len(arc-disk),'extra:',len(disk-arc))
print('missing sample:',sorted(arc-disk)[:6])
print('extra sample:',sorted(disk-arc)[:6])
# verify one file's data offset correctness by comparing sizes
by=dict((n,(ds,ps)) for n,ds,ps in names)
diff=[(n,by[n][0]) for n in list(arc&disk)[:400] if os.path.getsize(os.path.join(ROOT,n.replace('/',chr(92))))!=by[n][0]]
print('size mismatches in 400 samples:',len(diff), diff[:3])