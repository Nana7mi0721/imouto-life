
undefined4 FUN_005bb750(int param_1)

{
  if ((DAT_00f136f0 == 0) || (param_1 == 0)) {
    if ((DAT_00ef7324 == 0) && ((DAT_00f136f4 == 0 && (DAT_00f13700 == 0)))) {
      return 0;
    }
  }
  else if (DAT_00ef7324 == 0) {
    return 0;
  }
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((DAT_00ef7324 != 0) || (DAT_00f136f4 != 0)) {
    FUN_005d2bb0(0,0,0);
    DAT_00f136f4 = 0;
    if (DAT_00ef7324 != 0) goto LAB_005bb7c4;
  }
  if (DAT_00f13700 == 0) {
    DAT_00ef72cc = 1;
    DAT_00f136f0 = 0;
    return 0;
  }
LAB_005bb7c4:
  FUN_005d2c60(0);
  DAT_00f13700 = 0;
  DAT_00f136f0 = 0;
  DAT_00ef72cc = 1;
  return 0;
}

