
undefined4 FUN_0059a650(uint param_1,int param_2,int param_3)

{
  if ((DAT_00f3a04c != 0) && (param_1 < 0x10)) {
    DAT_00e7984c = 3;
    DAT_00e39a00 = 1;
    if (param_2 == 0x10) {
      if ((&DAT_00e80544)[param_1] != param_3) {
        FUN_005d3ad0(param_1,5,param_3);
        (&DAT_00e80544)[param_1] = param_3;
      }
    }
    else if (param_2 == 0x11) {
      if ((&DAT_00e80584)[param_1] != param_3) {
        FUN_005d3ad0(param_1,6,param_3);
        (&DAT_00e80584)[param_1] = param_3;
        return 0;
      }
    }
    else if ((param_2 == 0x12) && ((&DAT_00e805c4)[param_1] != param_3)) {
      FUN_005d3ad0(param_1,7,param_3);
      (&DAT_00e805c4)[param_1] = param_3;
      return 0;
    }
  }
  return 0;
}

