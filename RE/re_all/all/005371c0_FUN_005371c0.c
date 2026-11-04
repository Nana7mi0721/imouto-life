
undefined4 FUN_005371c0(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (DAT_00a4b760 != 0) {
    FUN_005364a0(1);
    FUN_00581030(8);
    if (DAT_00a4baa4 != 0) {
      FUN_0056e1d0(DAT_00a4baa4);
      DAT_00a4baa4 = 0;
    }
    if (1 < DAT_00a4baa8) {
      puVar1 = &DAT_00a4baa8;
      do {
        iVar2 = 0x10;
        do {
          FUN_00515700(*puVar1,0);
          *puVar1 = 0;
          puVar1 = puVar1 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      } while ((int)puVar1 < 0xa4bca8);
    }
    iVar2 = FUN_005e2310();
    if (iVar2 == 0) {
      DAT_00a4b760 = iVar2;
      return 0;
    }
  }
  return 0xffffffff;
}

