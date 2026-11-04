
void FUN_00613000(float *param_1,float *param_2,float param_3,float *param_4,undefined4 *param_5,
                 undefined4 *param_6)

{
  undefined4 *puVar1;
  float10 fVar2;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  undefined1 local_60 [16];
  undefined1 local_50 [16];
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  undefined1 local_10 [16];
  
  local_9c = param_2[2] - param_1[2];
  local_a4 = param_2[1] - param_1[1];
  local_98 = 0.5;
  local_a0 = *param_2 - *param_1;
  FUN_005fc500(&local_a0,&local_a4,&local_9c);
  FUN_0060fe40(&local_90,local_60,&local_98);
  local_90 = local_90 + param_3;
  local_8c = local_8c + param_3;
  local_9c = 0.5;
  local_88 = local_88 + param_3;
  local_98 = param_1[2] + param_2[2];
  local_a0 = param_2[1] + param_1[1];
  local_a4 = *param_1 + *param_2;
  FUN_005fc500(&local_a4,&local_a0,&local_98);
  FUN_0060fe40(local_50,local_60,&local_9c);
  local_98 = ABS(param_4[10]);
  local_a0 = ABS(param_4[9]);
  local_a4 = ABS(param_4[8]);
  local_9c = ABS(param_4[6]);
  local_78 = ABS(param_4[5]);
  local_74 = ABS(param_4[4]);
  local_7c = ABS(param_4[2]);
  local_94 = ABS(param_4[1]);
  local_80 = ABS(*param_4);
  FUN_005fcc50(&local_80,&local_94,&local_7c,&local_74,&local_78,&local_9c,&local_a4,&local_a0,
               &local_98);
  fVar2 = (float10)FUN_005fcc30(local_50);
  local_80 = (float)(fVar2 + (float10)param_4[0xe]);
  fVar2 = (float10)FUN_005fcc30(local_50);
  local_94 = (float)(fVar2 + (float10)param_4[0xd]);
  fVar2 = (float10)FUN_005fcc30(local_50);
  local_7c = (float)(fVar2 + (float10)param_4[0xc]);
  FUN_005fc500(&local_7c,&local_94,&local_80);
  local_64 = 0;
  local_70 = local_40 * local_90 + local_3c * local_8c + local_38 * local_88;
  local_6c = local_30 * local_90 + local_2c * local_8c + local_28 * local_88;
  local_68 = local_20 * local_90 + local_1c * local_8c + local_18 * local_88;
  puVar1 = (undefined4 *)FUN_005fc590(local_60,local_10,&local_70);
  *param_5 = *puVar1;
  param_5[1] = puVar1[1];
  param_5[2] = puVar1[2];
  param_5[3] = puVar1[3];
  puVar1 = (undefined4 *)FUN_0060f480(local_60,local_10,&local_70);
  *param_6 = *puVar1;
  param_6[1] = puVar1[1];
  param_6[2] = puVar1[2];
  param_6[3] = puVar1[3];
  return;
}

