
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005bc640(int param_1,undefined4 param_2,int param_3,int param_4)

{
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (DAT_00ef7324 == 0) {
    if (param_1 == DAT_00ef731c) {
      return 0;
    }
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
  }
  DAT_00ef72e8 = 1;
  DAT_00ef72cc = 1;
  if (DAT_00ef731c == 0) {
    if (param_1 == 0) goto LAB_005bc6a6;
  }
  else if (param_1 != 0) goto LAB_005bc6a6;
  DAT_00ef72e4 = 1;
LAB_005bc6a6:
  DAT_00ef731c = param_1;
  DAT_00ef7320 = param_2;
  if (param_1 != 0) {
    _DAT_00ef7304 = (float)param_3;
    _DAT_00ef7308 = (float)param_4;
    _DAT_00ef730c = 1.0 / _DAT_00ef7304;
    _DAT_00ef7310 = 1.0 / _DAT_00ef7308;
  }
  return 0;
}

