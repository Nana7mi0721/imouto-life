
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00628ac0(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float *param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *param_2 * *param_4 + param_4[1] * param_2[1] + param_2[2] * param_4[2];
  fVar4 = (param_3[1] - param_1[1]) * param_2[1] +
          (*param_3 - *param_1) * *param_2 + (param_3[2] - param_1[2]) * param_2[2];
  fVar2 = -((param_3[2] - param_1[2]) * param_4[2] +
           (*param_3 - *param_1) * *param_4 + (param_3[1] - param_1[1]) * param_4[1]);
  fVar3 = _DAT_00804108 - fVar1 * fVar1;
  if (fVar3 <= _DAT_008298b0) {
    *param_5 = 0.0;
    *param_6 = 0.0;
    return;
  }
  fVar3 = _DAT_00804108 / fVar3;
  *param_5 = (fVar2 * fVar1 + fVar4) * fVar3;
  *param_6 = (fVar4 * fVar1 + fVar2) * fVar3;
  return;
}

