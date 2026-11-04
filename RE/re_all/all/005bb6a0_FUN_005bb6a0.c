
undefined4 FUN_005bb6a0(int param_1)

{
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((DAT_00f13700 != param_1) || (DAT_00ef7324 != 0)) {
    if (param_1 != 0) {
      FUN_005d2c60(param_1);
    }
    DAT_00f13700 = param_1;
    DAT_00ef72cc = 1;
  }
  return 0;
}

