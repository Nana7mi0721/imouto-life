
void FUN_00646250(float *param_1,float *param_2,float *param_3)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float *pfVar4;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  pfVar4 = param_2;
  pfVar1 = param_2 + 3;
  fVar3 = *param_2;
  pfVar2 = param_2 + 1;
  local_34 = (param_2[2] * *param_3 + param_3[1] * *pfVar1) - param_3[2] * *param_2;
  local_30 = (*pfVar1 * *param_3 + param_3[2] * param_2[1]) - param_3[1] * param_2[2];
  param_2 = (float *)((-(*param_2 * *param_3) - param_3[1] * param_2[1]) - param_3[2] * param_2[2]);
  param_3 = (float *)((param_3[1] * fVar3 + param_3[2] * *pfVar1) - *pfVar2 * *param_3);
  FUN_0061a080(&local_30,&local_34,&param_3,&param_2);
  param_2 = (float *)-pfVar4[2];
  param_3 = (float *)-pfVar4[1];
  local_30 = -*pfVar4;
  FUN_0061a080(&local_30,&param_3,&param_2,pfVar1);
  local_34 = ((local_14 * local_4 - local_10 * local_20) - local_1c * local_c) - local_18 * local_8;
  local_2c = (local_18 * local_4 + local_c * local_20 + local_14 * local_8) - local_1c * local_10;
  local_28 = (local_1c * local_4 + local_18 * local_10 + local_14 * local_c) - local_8 * local_20;
  local_24 = (local_20 * local_4 + local_14 * local_10 + local_1c * local_8) - local_18 * local_c;
  FUN_00646400(&local_24,&local_28,&local_2c,&local_34);
  *param_1 = local_20;
  param_1[1] = local_1c;
  param_1[2] = local_18;
  param_1[3] = 0.0;
  return;
}

