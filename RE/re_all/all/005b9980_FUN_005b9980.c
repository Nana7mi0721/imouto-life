
undefined4 FUN_005b9980(uint param_1,int param_2)

{
  uint uVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (5 < param_1) {
    return 0xffffffff;
  }
  if (((&DAT_00f0738c)[param_1] != param_2) || (DAT_00ef7324 != 0)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    (&DAT_00f0738c)[param_1] = param_2;
    if (param_2 == 1) {
      if ((int)DAT_00f07388 < (int)param_1) {
        DAT_00f07388 = param_1;
        FUN_005b96d0();
        DAT_00ef72cc = param_2;
        return 0;
      }
    }
    else {
      uVar1 = param_1;
      if (DAT_00f07388 == param_1) {
        while ((DAT_00f07388 = uVar1, 0 < (int)DAT_00f07388 && ((&DAT_00f0738c)[DAT_00f07388] == 0))
              ) {
          uVar1 = DAT_00f07388 - 1;
        }
      }
    }
    FUN_005b96d0();
    DAT_00ef72cc = 1;
  }
  return 0;
}

