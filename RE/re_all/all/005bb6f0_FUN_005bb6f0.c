
undefined4 FUN_005bb6f0(int param_1,int param_2)

{
  if ((DAT_00f136f4 != param_1) || (DAT_00ef7324 != 0)) {
    if (DAT_00f3a070 == 0) {
      return 0xffffffff;
    }
    FUN_005d2bb0(param_1,0,0);
    DAT_00f136f4 = param_1;
    DAT_00f136f0 = param_2;
    if (param_2 == 0) {
      DAT_00ef72cc = 1;
    }
  }
  return 0;
}

