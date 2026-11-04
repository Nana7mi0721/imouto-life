
/* Library Function - Single Match
    ___mbbtype_mt
   
   Library: Visual Studio 2003 Release */

int ___mbbtype_mt(int param_1,byte param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = (uint)param_2;
  if (param_3 == 1) {
    return (-(uint)((*(byte *)(uVar2 + 0x1d + param_1) & 8) != 0) & 3) - 1;
  }
  bVar1 = *(byte *)(uVar2 + 0x1d + param_1);
  if ((bVar1 & 4) != 0) {
    return 1;
  }
  if (((*(ushort *)(PTR_DAT_0084be08 + uVar2 * 2) & 0x157) == 0) && ((bVar1 & 3) == 0)) {
    return -1;
  }
  return 0;
}

