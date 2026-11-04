
uint FUN_005b69d0(void)

{
  int iVar1;
  
  if (DAT_00a37dcc == 0) {
    if ((DAT_00a380cc != 0) || (iVar1 = 0xff, DAT_00a37fd4 != 0)) {
      iVar1 = DAT_00a380d0;
    }
    return ((iVar1 << 8 | (uint)DAT_00a38114) << 8 | (uint)DAT_00a38115) << 8 | (uint)DAT_00a38116;
  }
  if ((DAT_00a380cc != 0) || (iVar1 = 0xff, DAT_00a37fd4 != 0)) {
    iVar1 = DAT_00a380d0;
  }
  return ((iVar1 << 8 | (uint)DAT_00a38116) << 8 | (uint)DAT_00a38115) << 8 | (uint)DAT_00a38114;
}

