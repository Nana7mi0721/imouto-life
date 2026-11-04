
undefined4 FUN_0059b780(int param_1)

{
  if ((DAT_00e8061c == 0) || (param_1 == 0)) {
    if ((DAT_00e39a54 == 0) && ((DAT_00e8062c == 0 && (DAT_00e80628 == 0)))) {
      return 0;
    }
  }
  else if (DAT_00e39a54 == 0) {
    return 0;
  }
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if ((DAT_00e39a54 != 0) || (DAT_00e8062c != 0)) {
    FUN_005d3c30(0);
    DAT_00e8062c = 0;
    if (DAT_00e39a54 != 0) goto LAB_0059b7ed;
  }
  if (DAT_00e80628 == 0) {
    DAT_00e39a00 = 1;
    DAT_00e80614 = 0;
    DAT_00e8061c = 0;
    return 0;
  }
LAB_0059b7ed:
  FUN_005d3bd0(0);
  DAT_00e80628 = 0;
  DAT_00e8061c = 0;
  DAT_00e80614 = 0;
  DAT_00e39a00 = 1;
  return 0;
}

