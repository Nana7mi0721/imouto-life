
undefined4 FUN_0059b8e0(int param_1,int param_2)

{
  if (((DAT_00e80630 != param_1) || (DAT_00e80634 != param_2)) || (DAT_00e39a54 != 0)) {
    if (DAT_00f3a04c == 0) {
      return 0xffffffff;
    }
    if (param_1 != 0) {
      FUN_005d3cb0(0,param_1,0,param_2);
    }
    DAT_00e80630 = param_1;
    DAT_00e80634 = param_2;
  }
  return 0;
}

