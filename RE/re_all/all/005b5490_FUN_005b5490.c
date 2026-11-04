
undefined4 FUN_005b5490(void)

{
  int iVar1;
  
  DAT_00a37d78 = 0;
  iVar1 = FUN_005d3380();
  if ((-1 < iVar1) && (iVar1 = FUN_005d18e0(), -1 < iVar1)) {
    do {
      iVar1 = FUN_005d6050();
      if (iVar1 != 0) goto LAB_005b54d0;
      iVar1 = FUN_00598850();
    } while (iVar1 == -2);
    if ((iVar1 == 0) && (iVar1 = FUN_00598040(), iVar1 == 0)) {
      FUN_005a6fe0();
      if (DAT_00a37dc8 != 0) {
        FUN_005a2e20();
        FUN_00597870();
        iVar1 = FUN_0050e7d0();
        if (iVar1 == 0) {
          FUN_005a7410();
        }
      }
      DAT_00a37d78 = 1;
      return 0;
    }
  }
LAB_005b54d0:
  if (DAT_00ddb5c8 != 0) {
    FUN_005d3370(DAT_00ddb5c8);
    DAT_00ddb5c8 = 0;
  }
  FUN_005d3630();
  DAT_00e79688 = 0;
  FUN_005d33e0();
  FUN_005d33b0();
  FUN_005d19e0();
  return 0xffffffff;
}

