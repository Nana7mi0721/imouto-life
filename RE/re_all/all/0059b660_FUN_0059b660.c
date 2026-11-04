
undefined4 FUN_0059b660(int param_1)

{
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if ((DAT_00e80628 != param_1) || (DAT_00e39a54 != 0)) {
    FUN_005d3bd0(param_1);
    DAT_00e80628 = param_1;
  }
  DAT_00e80614 = 0;
  DAT_00e39a00 = 1;
  return 0;
}

