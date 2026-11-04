
undefined4 FUN_005a0c60(int param_1)

{
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  FUN_0059b660(0);
  if ((DAT_00e80614 != param_1) || (DAT_00e39a54 != 0)) {
    FUN_005d3bf0(param_1);
    DAT_00e80614 = param_1;
  }
  return 0;
}

