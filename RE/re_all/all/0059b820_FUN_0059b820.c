
undefined4 FUN_0059b820(int param_1,int param_2)

{
  if ((DAT_00e80624 != param_1) || (DAT_00e39a54 != 0)) {
    if (DAT_00f3a04c == 0) {
      return 0xffffffff;
    }
    FUN_005d3d20(param_1);
    DAT_00e80624 = param_1;
    DAT_00e80620 = param_2;
    if (param_2 == 0) {
      DAT_00e39a00 = 1;
    }
  }
  return 0;
}

