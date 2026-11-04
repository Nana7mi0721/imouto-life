
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00619760(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float *param_6,float *param_7,float param_8,float *param_9,float param_10)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = *param_7 * *param_9 + param_9[2] * param_7[2] + param_7[1] * param_9[1];
  fVar2 = param_7[1] * param_6[1] + param_6[2] * param_7[2] + *param_6 * *param_7;
  fVar3 = *param_6 * *param_9 + param_6[1] * param_9[1] + param_6[2] * param_9[2];
  fVar6 = _DAT_00804108 - fVar1 * fVar1;
  if (fVar6 == _DAT_007d5344) {
    *param_4 = 0.0;
  }
  else {
    fVar6 = (fVar2 - fVar3 * fVar1) / fVar6;
    *param_4 = fVar6;
    if (-param_8 <= fVar6) {
      if (fVar6 <= param_8) goto LAB_00619811;
      fVar6 = param_8;
    }
    else {
      fVar6 = -param_8;
    }
    *param_4 = fVar6;
  }
LAB_00619811:
  fVar3 = fVar1 * *param_4 - fVar3;
  *param_5 = fVar3;
  fVar6 = -param_10;
  if (fVar6 <= fVar3) {
    if (fVar3 <= param_10) goto LAB_006198c0;
    *param_5 = param_10;
    fVar2 = fVar1 * param_10 + fVar2;
    *param_4 = fVar2;
    if (fVar2 < -param_8) {
      *param_4 = -param_8;
      goto LAB_006198c0;
    }
  }
  else {
    *param_5 = fVar6;
    fVar2 = fVar6 * fVar1 + fVar2;
    *param_4 = fVar2;
    if (fVar2 < -param_8) {
      *param_4 = -param_8;
      goto LAB_006198c0;
    }
  }
  if (param_8 < fVar2) {
    *param_4 = param_8;
  }
LAB_006198c0:
  fVar1 = *param_4;
  fVar2 = param_7[1];
  fVar6 = *param_4;
  fVar3 = param_7[2];
  *param_2 = *param_4 * *param_7;
  param_2[1] = fVar1 * fVar2;
  param_2[2] = fVar6 * fVar3;
  param_2[3] = 0.0;
  fVar1 = *param_5;
  fVar2 = param_9[1];
  fVar6 = *param_5;
  fVar3 = param_9[2];
  *param_3 = *param_5 * *param_9;
  param_3[1] = fVar1 * fVar2;
  param_3[2] = fVar6 * fVar3;
  param_3[3] = 0.0;
  fVar1 = param_6[1];
  fVar2 = param_2[1];
  fVar6 = param_6[2];
  fVar3 = param_2[2];
  fVar4 = param_3[1];
  fVar5 = param_3[2];
  *param_1 = (*param_6 - *param_2) + *param_3;
  param_1[1] = (fVar1 - fVar2) + fVar4;
  param_1[2] = (fVar6 - fVar3) + fVar5;
  param_1[3] = 0.0;
  return;
}

