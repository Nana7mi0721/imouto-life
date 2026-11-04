
undefined4 FUN_0059a840(int param_1)

{
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if (DAT_00e39a54 == 0) {
    if (DAT_00e79848 == param_1) {
      return 0;
    }
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
  }
  FUN_005d3a70(0xc3,param_1);
  DAT_00e79848 = param_1;
  DAT_00e39a00 = 1;
  return 0;
}

