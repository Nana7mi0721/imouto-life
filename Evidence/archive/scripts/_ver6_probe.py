import struct, os
ARC='E:/EROGAME/Imouto! Life ~Monochrome~ zh-CN Ver/Data.wolf'
SRC=bytes([0x38,0x50,0x40,0x28,0x72,0x4f,0x21,0x70,0x3b,0x73,0x35,0x38])
def keycreate(src):
    L=len(src); k=bytearray(12)
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
raw48=f.read(48)
Head,Version,HeadSize,DataStart,NameStart,FileStart,DirStart,CodePage=struct.unpack('<HHIQQQQQ', xorat(raw48,0))
print('Head %x Version %d HeadSize %d DataStart %d NameStart %d FileStart %d DirStart %d CodePage %d'%(Head,Version,HeadSize,DataStart,NameStart,FileStart,DirStart,CodePage))
print('key', KEY.hex())
f.seek(NameStart); hb=xorat(f.read(HeadSize),0)
print('hb len', len(hb), 'filetab', FileStart, 'dirtab', DirStart, 'fileslots', (DirStart-FileStart)/64, 'dirslots',(HeadSize-DirStart)/32)
def d_at(rel): return struct.unpack_from('<QQQQ', hb, rel)
def f_at(rel):
    na,attr=struct.unpack_from('<QQ',hb,rel)
    da,ds,ps=struct.unpack_from('<QQQ',hb,rel+40)
    return na,attr,da,ds,ps
def name_of(na):
    n=struct.unpack_from('<H', hb, na)[0]
    start=na+n*4+4
    end=hb.find(bytes([0]), start)
    return hb[start:end].decode('cp932', errors='replace')
res=[]
def walk(rel,prefix):
    daddr,pdir,num,faddr=d_at(rel)
    for i in range(num):
        na,attr,da,ds,ps=f_at(FileStart+faddr+i*64)
        nm=name_of(na)
        if attr & 0x10: walk(DirStart+da, prefix+nm+'/')
        else: res.append((prefix+nm,da,ds,ps))
walk(DirStart,'')
tot=sum(d for _,_,d,_ in res)
comp=sum(1 for *_,ps in res if ps!=0xffffffffffffffff)
print('entries',len(res),'total',tot,'compressed',comp,'uncompressed',len(res)-comp)
print('first5', res[:5])
