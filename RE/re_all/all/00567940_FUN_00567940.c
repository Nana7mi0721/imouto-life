
undefined4 FUN_00567940(void)

{
  int iVar1;
  
  if (DAT_00a37d7c == 0) {
    if (DAT_00aaf0e0 == 0) {
      DAT_00aaf0dc = 2;
      iVar1 = FUN_005d1710();
      if (-1 < iVar1) {
        return 0;
      }
    }
    DAT_00aaf0dc = 1;
    iVar1 = FUN_005b5c10();
    if (-1 < iVar1) {
      return 0;
    }
    DAT_00aaf0dc = 0;
  }
  iVar1 = FUN_005d18e0();
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  iVar1 = FUN_0050e7d0();
  if ((iVar1 == 0) && (iVar1 = FUN_005677e0(), iVar1 < 0)) {
    FUN_005d19e0();
    return 0xffffffff;
  }
  FUN_005d4bf0();
  return 0;
}

