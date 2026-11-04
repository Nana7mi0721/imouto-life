
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00586310(float *param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  
  fVar2 = _DAT_007d5340;
  fVar1 = param_4 * param_4 + param_2 * param_2 + param_3 * param_3;
  if (fVar1 < (float)_DAT_007d5348) {
    *param_1 = _DAT_007d5340;
    param_1[1] = fVar2;
    param_1[2] = fVar2;
    return;
  }
  fVar3 = (float10)FUN_0056d670(fVar1);
  fVar1 = (float)fVar3;
  *param_1 = param_2 / fVar1;
  param_1[1] = param_3 / fVar1;
  param_1[2] = param_4 / fVar1;
  return;
}

