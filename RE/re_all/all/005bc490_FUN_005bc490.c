
undefined4 FUN_005bc490(int param_1,int *param_2)

{
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (param_1 == 0) {
    if (DAT_00ef7324 == 0) {
      if ((DAT_00ef72f4 == 0) && (DAT_00ef72f8 == *param_2)) {
        return 0;
      }
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
    }
    DAT_00ef72f8 = *param_2;
  }
  else if (param_1 == 1) {
    if (DAT_00ef7324 == 0) {
      if (((DAT_00ef72f4 == 1) && (DAT_00ef72fc == *param_2)) && (DAT_00ef7300 == param_2[1])) {
        return 0;
      }
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
    }
    DAT_00ef72fc = *param_2;
    DAT_00ef7300 = param_2[1];
  }
  else if ((param_1 == 2) && (DAT_00ef7324 == 0)) {
    if (DAT_00ef72f4 == 2) {
      return 0;
    }
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
  }
  DAT_00ef72f4 = param_1;
  DAT_00ef72e4 = 1;
  DAT_00ef72cc = 1;
  return 0;
}

