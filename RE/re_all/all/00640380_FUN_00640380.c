
float * __thiscall
FUN_00640380(float *param_1,float param_2,float param_3,float *param_4,float *param_5,float *param_6
            ,float *param_7,float param_8,float *param_9,float param_10)

{
  float *pfVar1;
  float *pfVar2;
  float10 fVar3;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  *param_1 = *param_6;
  local_14 = 0;
  param_1[1] = param_6[1];
  param_1[2] = param_6[2];
  param_1[3] = param_6[3];
  local_20 = param_4[1] * param_1[2] - param_4[2] * param_1[1];
  local_1c = param_4[2] * *param_1 - param_1[2] * *param_4;
  local_18 = param_1[1] * *param_4 - param_4[1] * *param_1;
  param_6 = (float *)(local_20 * *(float *)((int)param_2 + 0x20) +
                     local_1c * *(float *)((int)param_2 + 0x24) +
                     local_18 * *(float *)((int)param_2 + 0x28));
  fVar3 = (float10)FUN_005fcc30(&local_20);
  param_4 = (float *)(float)fVar3;
  fVar3 = (float10)FUN_005fcc30(&local_20);
  param_2 = (float)fVar3;
  FUN_005fc500(&param_2,&param_4,&param_6);
  pfVar1 = param_1 + 4;
  *pfVar1 = local_10;
  local_1c = -param_1[1];
  param_1[5] = local_c;
  param_1[6] = local_8;
  param_1[7] = local_4;
  local_18 = -param_1[2];
  param_6 = (float *)(local_1c * *param_5 - -*param_1 * param_5[1]);
  param_4 = (float *)(-*param_1 * param_5[2] - local_18 * *param_5);
  param_2 = local_18 * param_5[1] - local_1c * param_5[2];
  FUN_005fc500(&param_2,&param_4,&param_6);
  fVar3 = (float10)FUN_005fcc30(&local_20);
  param_5 = (float *)(float)fVar3;
  fVar3 = (float10)FUN_005fcc30(&local_20);
  param_3 = (float)fVar3;
  fVar3 = (float10)FUN_005fcc30(&local_20);
  local_24 = (float)fVar3;
  FUN_005fc500(&local_24,&param_3,&param_5);
  pfVar2 = param_1 + 8;
  *pfVar2 = local_10;
  param_1[9] = local_c;
  param_1[10] = local_8;
  param_1[0xb] = local_4;
  param_6 = (float *)(param_1[6] * param_7[2]);
  param_4 = (float *)(param_1[5] * param_7[1]);
  param_2 = *param_7 * *pfVar1;
  FUN_005fc500(&param_2,&param_4,&param_6);
  param_1[0xc] = local_10;
  param_1[0xd] = local_c;
  param_1[0xe] = local_8;
  param_1[0xf] = local_4;
  param_6 = (float *)(param_1[10] * param_9[2]);
  param_4 = (float *)(param_1[9] * param_9[1]);
  param_2 = *param_9 * *pfVar2;
  FUN_005fc500(&param_2,&param_4,&param_6);
  param_1[0x10] = local_10;
  param_1[0x11] = local_c;
  param_1[0x12] = local_8;
  param_1[0x13] = local_4;
  fVar3 = (float10)FUN_005fcc30(pfVar2);
  param_6 = (float *)(float)fVar3;
  fVar3 = (float10)FUN_005fcc30(pfVar1);
  param_1[0x14] = (float)(fVar3 + (float10)(float)param_6 + (float10)param_8 + (float10)param_10);
  return param_1;
}

