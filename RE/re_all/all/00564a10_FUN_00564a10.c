
undefined4 FUN_00564a10(ushort *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  *param_1 = 0;
  param_1[1] = 0;
  if (DAT_00aa57e8 == DAT_00aa57e4) {
    return 0;
  }
  *param_1 = (&DAT_00aa4fe0)[DAT_00aa57e4];
  uVar3 = 1;
  DAT_00aa57e4 = DAT_00aa57e4 + 1;
  if (DAT_00aa57e4 == 0x401) {
    DAT_00aa57e4 = 0;
  }
  iVar4 = DAT_00aa57e4;
  uVar1 = *param_1;
  iVar2 = FUN_00564010(uVar1);
  if ((iVar2 == 0) && ((uVar1 & 0xfc00) == 0xd800)) {
    if (DAT_00aa57e8 == iVar4) {
      if (iVar4 == 0) {
        DAT_00aa57e4 = 0x400;
        return 0;
      }
      DAT_00aa57e4 = iVar4 + -1;
      return 0;
    }
    param_1[1] = (&DAT_00aa4fe0)[iVar4];
    uVar3 = 2;
    iVar4 = DAT_00aa57e4;
    if (param_2 == 0) goto LAB_00564ae8;
    iVar4 = DAT_00aa57e4 + 1;
    DAT_00aa57e4 = iVar4;
    if (iVar4 == 0x401) {
      iVar4 = 0;
      DAT_00aa57e4 = 0;
    }
  }
  if (param_2 != 0) {
    return uVar3;
  }
LAB_00564ae8:
  if (iVar4 == 0) {
    DAT_00aa57e4 = 0x400;
    return uVar3;
  }
  DAT_00aa57e4 = iVar4 + -1;
  return uVar3;
}

