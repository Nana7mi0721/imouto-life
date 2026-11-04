
undefined4 * __thiscall
FUN_00640610(undefined4 *param_1,float *param_2,float param_3,float param_4,float *param_5,
            float *param_6)

{
  float *pfVar1;
  float *pfVar2;
  undefined4 uVar3;
  float10 fVar4;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  pfVar2 = param_2;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_3 = *(float *)((int)param_3 + 0x20) * *param_2 +
            *(float *)((int)param_3 + 0x24) * param_2[1] +
            *(float *)((int)param_3 + 0x28) * param_2[2];
  fVar4 = (float10)FUN_005fcc30(param_2);
  param_2 = (float *)(float)fVar4;
  fVar4 = (float10)FUN_005fcc30(pfVar2);
  local_24 = (float)fVar4;
  FUN_005fc500(&local_24,&param_2,&param_3);
  uVar3 = local_14;
  pfVar1 = (float *)(param_1 + 4);
  *pfVar1 = local_20;
  param_1[5] = local_1c;
  local_14 = 0;
  param_1[6] = local_18;
  param_1[7] = uVar3;
  local_20 = -*pfVar2;
  local_1c = -pfVar2[1];
  local_18 = -pfVar2[2];
  param_3 = local_20 * *(float *)((int)param_4 + 0x20) +
            local_1c * *(float *)((int)param_4 + 0x24) + local_18 * *(float *)((int)param_4 + 0x28);
  fVar4 = (float10)FUN_005fcc30(&local_20);
  param_2 = (float *)(float)fVar4;
  fVar4 = (float10)FUN_005fcc30(&local_20);
  param_4 = (float)fVar4;
  FUN_005fc500(&param_4,&param_2,&param_3);
  pfVar2 = (float *)(param_1 + 8);
  local_14 = 0;
  *pfVar2 = local_10;
  param_1[9] = local_c;
  param_1[10] = local_8;
  param_1[0xb] = local_4;
  local_20 = *param_5 * *pfVar1;
  local_1c = (float)param_1[5] * param_5[1];
  local_18 = (float)param_1[6] * param_5[2];
  param_1[0xc] = local_20;
  param_1[0xd] = local_1c;
  param_1[0xe] = local_18;
  param_1[0xf] = 0;
  param_3 = (float)param_1[10] * param_6[2];
  param_2 = (float *)((float)param_1[9] * param_6[1]);
  param_4 = *param_6 * *pfVar2;
  FUN_005fc500(&param_4,&param_2,&param_3);
  param_1[0x10] = local_10;
  param_1[0x11] = local_c;
  param_1[0x12] = local_8;
  param_1[0x13] = local_4;
  param_1[0x14] =
       *pfVar2 * (float)param_1[0x10] +
       *pfVar1 * (float)param_1[0xc] +
       (float)param_1[5] * (float)param_1[0xd] +
       (float)param_1[6] * (float)param_1[0xe] +
       (float)param_1[9] * (float)param_1[0x11] + (float)param_1[10] * (float)param_1[0x12];
  return param_1;
}

