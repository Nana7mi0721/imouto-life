
undefined4 FUN_0050ef90(void)

{
  int iVar1;
  
  if (DAT_00a2d288 == 0) {
    return 0xffffffff;
  }
  iVar1 = 0;
  if (0 < DAT_00a2d294) {
    do {
      SendMessageW(DAT_00a2d28c,0x416,0,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_00a2d294);
  }
  DAT_00a2d294 = 0;
  return 0;
}

