
/* Library Function - Single Match
    __onexit_lk
   
   Library: Visual Studio 2003 Release */

void __onexit_lk(void)

{
  size_t sVar1;
  void *pvVar2;
  size_t sVar3;
  undefined4 unaff_EDI;
  
  sVar1 = __msize(DAT_00f49cb8);
  if (sVar1 < (uint)((int)DAT_00f49cb4 + (4 - (int)DAT_00f49cb8))) {
    sVar3 = 0x800;
    if (sVar1 < 0x800) {
      sVar3 = sVar1;
    }
    pvVar2 = _realloc(DAT_00f49cb8,sVar3 + sVar1);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = _realloc(DAT_00f49cb8,sVar1 + 0x10);
      if (pvVar2 == (void *)0x0) {
        return;
      }
    }
    DAT_00f49cb4 = (undefined4 *)((int)pvVar2 + ((int)DAT_00f49cb4 - (int)DAT_00f49cb8 >> 2) * 4);
    DAT_00f49cb8 = pvVar2;
  }
  *DAT_00f49cb4 = unaff_EDI;
  DAT_00f49cb4 = DAT_00f49cb4 + 1;
  return;
}

