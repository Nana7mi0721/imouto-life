
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0065f270(float *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  double local_10;
  
  iVar2 = FUN_0065e820((double)param_1[1],param_2);
  fVar1 = param_1[1] * (float)_DAT_008053e8 + param_1[2] * (float)_DAT_008053f0 + *param_1;
  if ((iVar2 == 0) || (fVar1 <= (float)_DAT_007d0a60)) {
    local_10 = 0.473684211;
  }
  else {
    local_10 = (double)((param_1[1] * (float)_DAT_008053d0) / fVar1);
    if ((double)((*param_1 * (float)_DAT_008053c8) / fVar1) <= _DAT_007d0a60) {
      uVar4 = 0;
      goto LAB_0065f35c;
    }
  }
  if (param_2 != 0) {
    _rand();
  }
  uVar4 = __ftol();
  if (0xff < uVar4) {
    uVar4 = 0xff;
  }
LAB_0065f35c:
  if (_DAT_007d0a60 < local_10) {
    if (param_2 != 0) {
      _rand();
    }
    uVar3 = __ftol();
    if (0xff < uVar3) {
      uVar3 = 0xff;
    }
    return (iVar2 << 8 | uVar4) << 8 | uVar3;
  }
  return (iVar2 << 8 | uVar4) << 8;
}

