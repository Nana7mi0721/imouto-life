
undefined4 FUN_0057def0(void)

{
  int iVar1;
  
  if (DAT_00aa4270 == 0) {
    return 0xffffffff;
  }
  if (DAT_00aa4fa8 != 0) {
    DAT_00aa4fb0 = 1;
    iVar1 = FUN_005501a0();
    while ((iVar1 == 0 && (DAT_00aa4fb0 == 1))) {
      Sleep(2);
      iVar1 = FUN_005501a0();
    }
  }
  return 0;
}

