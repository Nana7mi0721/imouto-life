
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00619f90(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  if (_DAT_0080451c < ABS(param_1[2])) {
    fVar5 = param_1[2] * param_1[2] + param_1[1] * param_1[1];
    fVar6 = _DAT_00804108 / SQRT(fVar5);
    fVar1 = param_1[1];
    fVar2 = param_1[2];
    *param_2 = 0.0;
    param_2[3] = 0.0;
    param_2[1] = -(fVar6 * fVar2);
    param_2[2] = fVar6 * fVar1;
    fVar3 = *param_1;
    fVar4 = *param_1;
    param_3[3] = 0.0;
    *param_3 = fVar6 * fVar5;
    param_3[1] = -(fVar6 * fVar1 * fVar4);
    param_3[2] = -(fVar6 * fVar2) * fVar3;
    return;
  }
  fVar4 = param_1[1] * param_1[1] + *param_1 * *param_1;
  fVar5 = _DAT_00804108 / SQRT(fVar4);
  fVar1 = *param_1;
  fVar2 = param_1[1];
  param_2[2] = 0.0;
  param_2[3] = 0.0;
  *param_2 = -(fVar5 * fVar2);
  param_2[1] = fVar5 * fVar1;
  fVar2 = *param_2;
  fVar3 = param_1[2];
  *param_3 = -(fVar5 * fVar1 * param_1[2]);
  param_3[3] = 0.0;
  param_3[1] = fVar2 * fVar3;
  param_3[2] = fVar5 * fVar4;
  return;
}

