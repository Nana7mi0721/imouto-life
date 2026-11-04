
undefined4 FUN_005bb9e0(int param_1,undefined4 param_2)

{
  if ((DAT_00f136f8 != param_1) || (DAT_00ef7324 != 0)) {
    if (DAT_00f3a070 == 0) {
      return 0xffffffff;
    }
    if (param_1 != 0) {
      FUN_005d2cb0(param_1,param_2,0);
    }
    DAT_00f136fc = param_2;
    DAT_00f136f8 = param_1;
  }
  return 0;
}

