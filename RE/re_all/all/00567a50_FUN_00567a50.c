
undefined4
FUN_00567a50(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_005800b0();
  while (0 < iVar1) {
    FUN_0057fe80();
    if (DAT_00a20bf4 < 2) {
      uVar2 = 2;
    }
    else {
      uVar2 = 0;
    }
    FUN_0056da20(uVar2);
    iVar1 = FUN_005800b0();
  }
  if (DAT_00a37d78 == 1) {
    if (DAT_00aaf0dc == 1) {
      uVar2 = FUN_005b6810();
      return uVar2;
    }
    if (DAT_00aaf0dc == 2) {
      uVar2 = FUN_005d1730();
      return uVar2;
    }
  }
  else {
    if (DAT_00a4973c == 0) {
      FUN_005d19e0();
    }
    if (param_1 == 1) {
      FUN_005173e0(param_2,param_3);
      DAT_00a37e70 = param_4;
      DAT_00a37e74 = param_5;
    }
    if (DAT_00a4973c == 0) {
      DAT_00a37e80 = DAT_00a37e7c;
      iVar1 = FUN_005d18e0();
      if (-1 < iVar1) {
        iVar1 = FUN_0050e7d0();
        if ((iVar1 != 0) || (iVar1 = FUN_005677e0(), -1 < iVar1)) {
          FUN_005d4bf0();
          return 0;
        }
        FUN_005d19e0();
      }
      return 0xffffffff;
    }
  }
  return 0;
}

