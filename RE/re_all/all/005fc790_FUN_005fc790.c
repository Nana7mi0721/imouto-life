
undefined4 FUN_005fc790(undefined4 param_1,float *param_2,float *param_3)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = param_2[8] * param_3[2] + param_2[10] * param_3[10] + param_2[9] * param_3[6];
  local_8 = param_2[8] * param_3[1] + param_2[10] * param_3[9] + param_2[9] * param_3[5];
  local_4 = param_2[8] * *param_3 + param_2[10] * param_3[8] + param_2[9] * param_3[4];
  local_18 = param_3[2] * param_2[4] + param_2[6] * param_3[10] + param_2[5] * param_3[6];
  local_14 = param_3[1] * param_2[4] + param_2[6] * param_3[9] + param_2[5] * param_3[5];
  local_10 = param_2[4] * *param_3 + param_2[6] * param_3[8] + param_2[5] * param_3[4];
  pfVar1 = param_2 + 2;
  pfVar2 = param_2 + 1;
  fVar3 = *param_2;
  local_1c = *param_2 * *param_3 + param_2[2] * param_3[8] + param_2[1] * param_3[4];
  param_2 = (float *)(*param_2 * param_3[2] + param_2[2] * param_3[10] + param_2[1] * param_3[6]);
  param_3 = (float *)(param_3[1] * fVar3 + param_3[5] * *pfVar2 + *pfVar1 * param_3[9]);
  FUN_005fc530(&local_1c,&param_3,&param_2);
  FUN_005fc530(&local_10,&local_14,&local_18);
  FUN_005fc530(&local_4,&local_8,&local_c);
  return param_1;
}

