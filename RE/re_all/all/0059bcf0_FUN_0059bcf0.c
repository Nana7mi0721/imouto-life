
undefined4 FUN_0059bcf0(int param_1)

{
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if (param_1 == DAT_00e39a4c) {
    if (DAT_00e39a54 == 0) {
      return 0;
    }
  }
  else if ((DAT_00e39a54 == 0) && (FUN_00568ca0(0), DAT_00dda46c != 0)) {
    FUN_00584d70();
  }
  DAT_00e39a1c = 1;
  if (DAT_00e39a4c == 0) {
    if (param_1 == 0) {
      DAT_00e39a4c = param_1;
      DAT_00e39a00 = 1;
      return 0;
    }
  }
  else if (param_1 != 0) {
    DAT_00e39a00 = 1;
    DAT_00e39a1c = 1;
    DAT_00e39a4c = param_1;
    return 0;
  }
  DAT_00e39a18 = 1;
  DAT_00e39a4c = param_1;
  DAT_00e39a00 = 1;
  return 0;
}

