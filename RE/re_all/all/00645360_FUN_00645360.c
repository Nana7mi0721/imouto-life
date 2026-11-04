
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00645360(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float10 fVar2;
  float local_20;
  float local_1c;
  float local_18;
  
  local_20 = *param_1;
  local_1c = param_1[1];
  local_18 = param_1[2];
  fVar2 = (float10)FUN_006c5580();
  *param_2 = (float)(fVar2 + fVar2);
  if ((float10)_DAT_00802ebc < fVar2 + fVar2) {
    local_20 = -*param_1;
    local_1c = -param_1[1];
    local_18 = -param_1[2];
    fVar2 = (float10)FUN_006c5580();
    *param_2 = (float)(fVar2 + fVar2);
  }
  *param_3 = local_20;
  param_3[1] = local_1c;
  param_3[2] = local_18;
  param_3[3] = 0.0;
  if (_DAT_00804520 < *param_2) {
    fVar1 = _DAT_00804108 /
            SQRT(param_3[2] * param_3[2] + param_3[1] * param_3[1] + *param_3 * *param_3);
    *param_3 = fVar1 * *param_3;
    param_3[1] = fVar1 * param_3[1];
    param_3[2] = fVar1 * param_3[2];
  }
  return;
}

