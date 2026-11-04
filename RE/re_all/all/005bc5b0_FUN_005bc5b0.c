
undefined4 FUN_005bc5b0(int param_1,undefined4 param_2)

{
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (param_1 == DAT_00ef7314) {
    if (DAT_00ef7324 == 0) {
      return 0;
    }
  }
  else if ((DAT_00ef7324 == 0) && (FUN_00568ca0(0), DAT_00dda46c != 0)) {
    FUN_00584d70();
  }
  DAT_00ef72e8 = 1;
  if (DAT_00ef7314 == 0) {
    if (param_1 == 0) {
      DAT_00ef72cc = 1;
      DAT_00ef72e8 = 1;
      DAT_00ef7314 = param_1;
      DAT_00ef7318 = param_2;
      return 0;
    }
  }
  else if (param_1 != 0) {
    DAT_00ef72cc = 1;
    DAT_00ef72e8 = 1;
    DAT_00ef7314 = param_1;
    DAT_00ef7318 = param_2;
    return 0;
  }
  DAT_00ef72e4 = 1;
  DAT_00ef7314 = param_1;
  DAT_00ef72cc = 1;
  DAT_00ef7318 = param_2;
  return 0;
}

