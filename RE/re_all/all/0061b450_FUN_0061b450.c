
void __thiscall FUN_0061b450(float *param_1,undefined4 *param_2,float param_3)

{
  float *pfVar1;
  float *pfVar2;
  float10 fVar3;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_34 = 0;
  pfVar1 = param_1 + 4;
  pfVar2 = param_1 + 8;
  local_40 = *(float *)((int)param_3 + 0x30) * *param_1 +
             param_1[2] * *(float *)((int)param_3 + 0x38) +
             param_1[1] * *(float *)((int)param_3 + 0x34) + param_1[0xc];
  local_3c = *(float *)((int)param_3 + 0x30) * *pfVar1 +
             param_1[6] * *(float *)((int)param_3 + 0x38) +
             param_1[5] * *(float *)((int)param_3 + 0x34) + param_1[0xd];
  local_38 = *(float *)((int)param_3 + 0x30) * *pfVar2 +
             param_1[10] * *(float *)((int)param_3 + 0x38) +
             param_1[9] * *(float *)((int)param_3 + 0x34) + param_1[0xe];
  param_3 = *(float *)((int)param_3 + 8) * *pfVar2 +
            param_1[9] * *(float *)((int)param_3 + 0x18) +
            param_1[10] * *(float *)((int)param_3 + 0x28);
  fVar3 = (float10)FUN_005fccd0(pfVar2);
  local_60 = (float)fVar3;
  fVar3 = (float10)FUN_005fccb0(pfVar2);
  local_5c = (float)fVar3;
  fVar3 = (float10)FUN_005fccf0(pfVar1);
  local_58 = (float)fVar3;
  fVar3 = (float10)FUN_005fccd0(pfVar1);
  local_54 = (float)fVar3;
  fVar3 = (float10)FUN_005fccb0(pfVar1);
  local_50 = (float)fVar3;
  fVar3 = (float10)FUN_005fccf0(param_1);
  local_4c = (float)fVar3;
  fVar3 = (float10)FUN_005fccd0(param_1);
  local_48 = (float)fVar3;
  fVar3 = (float10)FUN_005fccb0(param_1);
  local_44 = (float)fVar3;
  FUN_005fcc50(&local_44,&local_48,&local_4c,&local_50,&local_54,&local_58,&local_5c,&local_60,
               &param_3);
  *param_2 = local_30;
  param_2[1] = local_2c;
  param_2[2] = local_28;
  param_2[3] = local_24;
  param_2[4] = local_20;
  param_2[5] = local_1c;
  param_2[6] = local_18;
  param_2[7] = local_14;
  param_2[8] = local_10;
  param_2[9] = local_c;
  param_2[10] = local_8;
  param_2[0xb] = local_4;
  param_2[0xc] = local_40;
  param_2[0xd] = local_3c;
  param_2[0xe] = local_38;
  param_2[0xf] = local_34;
  return;
}

