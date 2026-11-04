
undefined4 FUN_005bc2c0(int param_1,int param_2,int param_3)

{
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((((DAT_00ef7324 != 0) || (DAT_00ef72e0 != param_1)) || (DAT_00ef72d4 != param_2)) ||
     (DAT_00ef72d0 != param_3)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00ef72e0 = param_1;
    DAT_00ef72d0 = param_3;
    DAT_00ef72d4 = param_2;
    DAT_00ef72cc = 1;
    DAT_00ef72e4 = 1;
  }
  return 0;
}

