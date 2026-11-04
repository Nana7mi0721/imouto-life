
undefined4 FUN_0059bbd0(int param_1,int *param_2)

{
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if (param_1 == 0) {
    if (DAT_00e39a54 == 0) {
      if ((DAT_00e39a2c == 0) && (DAT_00e39a30 == *param_2)) {
        return 0;
      }
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
    }
    DAT_00e39a30 = *param_2;
  }
  else if (param_1 == 1) {
    if (DAT_00e39a54 == 0) {
      if (((DAT_00e39a2c == 1) && (DAT_00e39a34 == *param_2)) && (DAT_00e39a38 == param_2[1])) {
        return 0;
      }
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
    }
    DAT_00e39a34 = *param_2;
    DAT_00e39a38 = param_2[1];
  }
  else if ((param_1 == 2) && (DAT_00e39a54 == 0)) {
    if (DAT_00e39a2c == 2) {
      return 0;
    }
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
  }
  DAT_00e39a2c = param_1;
  DAT_00e39a18 = 1;
  DAT_00e39a00 = 1;
  return 0;
}

