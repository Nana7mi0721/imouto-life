
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0062cc90(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  float *pfVar4;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  float local_60;
  float local_5c;
  float local_58;
  float local_50;
  float local_4c;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  *(ushort *)(param_5 + 4) = *(ushort *)(param_5 + 4) & 0xfff0;
  local_a8 = param_3[2] - param_2[2];
  local_b4 = param_3[1] - param_2[1];
  local_b0 = *param_3 - *param_2;
  FUN_005fc500(&local_b0,&local_b4,&local_a8);
  local_a8 = param_4[2] - param_2[2];
  local_b4 = param_4[1] - param_2[1];
  local_b0 = *param_4 - *param_2;
  FUN_005fc500(&local_b0,&local_b4,&local_a8);
  local_a8 = param_1[2] - param_2[2];
  local_b4 = param_1[1] - param_2[1];
  local_b0 = *param_1 - *param_2;
  FUN_005fc500(&local_b0,&local_b4,&local_a8);
  local_ac = local_30 * local_60 + local_5c * local_2c + local_58 * local_28;
  local_a4 = local_80 * local_30 + local_7c * local_2c + local_78 * local_28;
  if ((local_ac <= _DAT_007d5344) && (local_a4 <= _DAT_007d5344)) {
    *param_5 = *param_2;
    param_5[1] = param_2[1];
    param_5[2] = param_2[2];
    fVar1 = param_2[3];
    *(byte *)(param_5 + 4) = *(byte *)(param_5 + 4) | 1;
    param_5[5] = 1.0;
    param_5[3] = fVar1;
    param_5[6] = 0.0;
    param_5[7] = 0.0;
    param_5[8] = 0.0;
    return 1;
  }
  local_a8 = param_1[2] - param_3[2];
  local_b4 = param_1[1] - param_3[1];
  local_b0 = *param_1 - *param_3;
  FUN_005fc500(&local_b0,&local_b4,&local_a8);
  local_98 = local_50 * local_60 + local_5c * local_4c + local_58 * local_48;
  local_b0 = local_50 * local_80 + local_7c * local_4c + local_78 * local_48;
  if ((_DAT_007d5344 <= local_98) && (local_b0 <= local_98)) {
    *param_5 = *param_3;
    param_5[1] = param_3[1];
    param_5[2] = param_3[2];
    fVar1 = param_3[3];
    *(byte *)(param_5 + 4) = *(byte *)(param_5 + 4) | 2;
    param_5[6] = 1.0;
    param_5[3] = fVar1;
    param_5[5] = 0.0;
    param_5[7] = 0.0;
    param_5[8] = 0.0;
    return 1;
  }
  local_a8 = local_b0 * local_ac - local_98 * local_a4;
  if (((local_a8 <= _DAT_007d5344) && (_DAT_007d5344 <= local_ac)) && (local_98 <= _DAT_007d5344)) {
    local_b4 = local_ac / (local_ac - local_98);
    FUN_0060fe40(&local_70,&local_60,&local_b4);
    local_a8 = local_68 + param_2[2];
    local_b0 = local_6c + param_2[1];
    local_ac = local_70 + *param_2;
    FUN_005fc500(&local_ac,&local_b0,&local_a8);
    fVar1 = _DAT_00804108 - local_b4;
    *(byte *)(param_5 + 4) = *(byte *)(param_5 + 4) | 3;
    *param_5 = local_94;
    param_5[5] = fVar1;
    param_5[1] = local_90;
    param_5[6] = local_b4;
    param_5[2] = local_8c;
    param_5[3] = local_88;
    param_5[7] = 0.0;
    param_5[8] = 0.0;
    return 1;
  }
  local_b4 = param_1[2] - param_4[2];
  local_a0 = param_1[1] - param_4[1];
  local_9c = *param_1 - *param_4;
  FUN_005fc500(&local_9c,&local_a0,&local_b4);
  fVar1 = local_40 * local_60 + local_5c * local_3c + local_58 * local_38;
  local_a0 = local_40 * local_80 + local_7c * local_3c + local_78 * local_38;
  if ((_DAT_007d5344 <= local_a0) && (fVar1 <= local_a0)) {
    *param_5 = *param_4;
    param_5[1] = param_4[1];
    param_5[2] = param_4[2];
    fVar1 = param_4[3];
    *(byte *)(param_5 + 4) = *(byte *)(param_5 + 4) | 4;
    param_5[7] = 1.0;
    param_5[3] = fVar1;
    param_5[5] = 0.0;
    param_5[6] = 0.0;
    param_5[8] = 0.0;
    return 1;
  }
  local_ac = fVar1 * local_a4 - local_a0 * local_ac;
  if (((local_ac <= _DAT_007d5344) && (_DAT_007d5344 <= local_a4)) && (local_a0 <= _DAT_007d5344)) {
    local_b4 = local_a4 / (local_a4 - local_a0);
    FUN_0060fe40(&local_70,&local_80,&local_b4);
    local_9c = local_68 + param_2[2];
    local_a8 = local_6c + param_2[1];
    local_b0 = local_70 + *param_2;
    FUN_005fc500(&local_b0,&local_a8,&local_9c);
    fVar1 = _DAT_00804108 - local_b4;
    *(byte *)(param_5 + 4) = *(byte *)(param_5 + 4) | 5;
    *param_5 = local_94;
    param_5[5] = fVar1;
    param_5[1] = local_90;
    param_5[7] = local_b4;
    param_5[2] = local_8c;
    param_5[3] = local_88;
    param_5[6] = 0.0;
    param_5[8] = 0.0;
    return 1;
  }
  local_a4 = local_a0 * local_98 - fVar1 * local_b0;
  if (((local_a4 <= _DAT_007d5344) && (local_b0 = local_b0 - local_98, _DAT_007d5344 <= local_b0))
     && (_DAT_007d5344 <= fVar1 - local_a0)) {
    local_b4 = local_b0 / ((fVar1 - local_a0) + local_b0);
    local_9c = param_4[2] - param_3[2];
    local_a8 = param_4[1] - param_3[1];
    local_b0 = *param_4 - *param_3;
    FUN_005fc500(&local_b0,&local_a8,&local_9c);
    FUN_0060fe40(&local_70,local_20,&local_b4);
    local_ac = local_68 + param_3[2];
    local_a4 = local_6c + param_3[1];
    local_a0 = local_70 + *param_3;
    FUN_005fc500(&local_a0,&local_a4,&local_ac);
    fVar1 = _DAT_00804108 - local_b4;
    *(byte *)(param_5 + 4) = *(byte *)(param_5 + 4) | 6;
    *param_5 = local_94;
    param_5[6] = fVar1;
    param_5[1] = local_90;
    param_5[7] = local_b4;
    param_5[2] = local_8c;
    param_5[3] = local_88;
    param_5[5] = 0.0;
    param_5[8] = 0.0;
    return 1;
  }
  fVar1 = _DAT_00804108 / (local_a4 + local_ac + local_a8);
  local_84 = fVar1 * local_ac;
  local_ac = fVar1 * local_a8;
  local_9c = local_78 * local_ac;
  local_a8 = local_7c * local_ac;
  local_b4 = local_80 * local_ac;
  FUN_005fc500(&local_b4,&local_a8,&local_9c);
  uVar3 = FUN_0060fe40(&local_70,&local_60,&local_84,local_20);
  uVar3 = FUN_0060f480(&local_94,param_2,uVar3);
  pfVar4 = (float *)FUN_0060f480(local_10,uVar3);
  fVar2 = _DAT_00804108;
  *param_5 = *pfVar4;
  param_5[1] = pfVar4[1];
  param_5[2] = pfVar4[2];
  fVar1 = pfVar4[3];
  *(byte *)(param_5 + 4) = *(byte *)(param_5 + 4) | 7;
  param_5[3] = fVar1;
  FUN_0062dec0((fVar2 - local_84) - local_ac,local_84,local_ac,0);
  return 1;
}

