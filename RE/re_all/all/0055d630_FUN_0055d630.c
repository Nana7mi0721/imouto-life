
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0055d630(int *param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  
  if (param_1[0x1c] == 0) {
    return 0xffffffff;
  }
  fVar1 = (float)param_1[0x26] - *param_2;
  if (fVar1 < 0.0) {
    fVar1 = -fVar1;
  }
  if (fVar1 < _DAT_007d652c) {
    fVar1 = (float)param_1[0x27] - param_2[1];
    if (fVar1 < 0.0) {
      fVar1 = -fVar1;
    }
    if (fVar1 < _DAT_007d652c) {
      fVar1 = (float)param_1[0x28] - param_2[2];
      if (fVar1 < 0.0) {
        fVar1 = -fVar1;
      }
      if (fVar1 < _DAT_007d652c) {
        return 0;
      }
    }
  }
  param_1[0x26] = (int)*param_2;
  param_1[0x27] = (int)param_2[1];
  param_1[0x28] = (int)param_2[2];
  iVar2 = FUN_0057efa0(param_1,param_2);
  if (iVar2 < 0) {
    return 0xffffffff;
  }
  param_1[0x2f] = 1;
  if (*param_1 != 0) {
    if (DAT_00a83c64 == 0) {
      iVar2 = FUN_0057e790(param_1);
    }
    else {
      iVar2 = param_1[0x14];
    }
    if (iVar2 == 0) {
      return 0;
    }
  }
  if ((((param_1[0x1c] != 0) && (*param_1 != 0)) && (param_1[0x2f] != 0)) &&
     ((DAT_00a83c64 != 0 || (iVar2 = FUN_0057efd0(param_1,0), -1 < iVar2)))) {
    param_1[0x2f] = 0;
  }
  return 0;
}

