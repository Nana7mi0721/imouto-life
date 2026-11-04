
void __thiscall FUN_0061b320(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
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
  
  FUN_005fc650(param_1,param_1 + 0x10,param_1 + 0x20,param_1 + 4,param_1 + 0x14,param_1 + 0x24,
               param_1 + 8,param_1 + 0x18,param_1 + 0x28);
  fVar1 = -*(float *)(param_1 + 0x30);
  fVar2 = -*(float *)(param_1 + 0x34);
  fVar3 = -*(float *)(param_1 + 0x38);
  local_4c = local_c * fVar2 + local_10 * fVar1 + local_8 * fVar3;
  local_48 = local_1c * fVar2 + local_20 * fVar1 + local_18 * fVar3;
  local_44 = local_2c * fVar2 + local_30 * fVar1 + local_28 * fVar3;
  FUN_005fc500(&local_44,&local_48,&local_4c);
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

