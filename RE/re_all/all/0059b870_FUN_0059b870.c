
undefined4 FUN_0059b870(int param_1)

{
  if ((DAT_00e80620 == 0) || (param_1 == 0)) {
    if ((DAT_00e39a54 == 0) && (DAT_00e80624 == 0)) {
      return 0;
    }
  }
  else if (DAT_00e39a54 == 0) {
    return 0;
  }
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if ((DAT_00e39a54 != 0) || (DAT_00e80624 != 0)) {
    FUN_005d3d20(0);
    DAT_00e80624 = 0;
  }
  DAT_00e80620 = 0;
  DAT_00e39a00 = 1;
  return 0;
}

