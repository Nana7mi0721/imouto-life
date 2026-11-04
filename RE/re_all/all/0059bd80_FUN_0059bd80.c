
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0059bd80(int param_1,int param_2,int param_3)

{
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if (DAT_00e39a54 == 0) {
    if (param_1 == DAT_00e39a50) {
      return 0;
    }
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
  }
  DAT_00e39a1c = 1;
  DAT_00e39a00 = 1;
  if (DAT_00e39a50 == 0) {
    if (param_1 == 0) goto LAB_0059bde2;
  }
  else if (param_1 != 0) goto LAB_0059bde2;
  DAT_00e39a18 = 1;
LAB_0059bde2:
  DAT_00e39a50 = param_1;
  if (param_1 != 0) {
    _DAT_00e39a3c = (float)param_2;
    _DAT_00e39a40 = (float)param_3;
    _DAT_00e39a44 = 1.0 / _DAT_00e39a3c;
    _DAT_00e39a48 = 1.0 / _DAT_00e39a40;
  }
  return 0;
}

