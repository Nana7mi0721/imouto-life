
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005c29f0(float *param_1)

{
  int iVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((((_DAT_00f130c4 == *param_1) && (_DAT_00f130c8 == param_1[1])) &&
      (_DAT_00f130cc == param_1[2])) && (_DAT_00f130d0 == param_1[3])) {
    if (DAT_00ef7324 == 0) {
      return 0;
    }
  }
  else if (DAT_00ef7324 == 0) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
  }
  iVar1 = FUN_005d27a0();
  if ((iVar1 != 0) && (DAT_00f07348 != 0)) {
    DAT_00f07348 = 0;
  }
  FUN_005d2d90(1,param_1);
  _DAT_00f130c4 = *param_1;
  _DAT_00f130c8 = param_1[1];
  _DAT_00f130cc = param_1[2];
  _DAT_00f130d0 = param_1[3];
  _DAT_00f130d4 = param_1[4];
  _DAT_00f130d8 = param_1[5];
  return 0;
}

