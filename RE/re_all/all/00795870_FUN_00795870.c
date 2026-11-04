
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00795870(int param_1,int *param_2,float *param_3,float *param_4,float *param_5,float *param_6,
            int param_7,int param_8)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  float10 fVar5;
  float local_8c;
  char local_85;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  int local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  int local_28;
  ushort local_24;
  ushort local_22;
  ushort local_20;
  ushort local_1c;
  ushort local_1a;
  ushort local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  undefined4 local_8;
  float local_4;
  
  local_84 = param_4[2] - param_3[2];
  local_5c = param_7;
  local_80 = param_4[1] - param_3[1];
  puVar4 = (ushort *)(*(int *)(param_1 + 0x88) + param_7 * 0x10);
  local_8c = *param_4 - *param_3;
  local_28 = 0;
  FUN_005fc500(&local_8c,&local_80,&local_84);
  fVar5 = (float10)FUN_005fcc30(&local_38);
  local_8c = (float)((float10)_DAT_00804108 / SQRT(fVar5));
  FUN_0061a860(&local_8c);
  local_8c = param_4[2] - param_3[2];
  local_80 = param_4[1] - param_3[1];
  local_84 = *param_4 - *param_3;
  FUN_005fc500(&local_84,&local_80,&local_8c);
  local_4 = local_6c * local_38 + local_34 * local_68 + local_30 * local_64;
  if (local_38 == _DAT_007d5344) {
    local_38 = 1e+18;
  }
  else {
    local_38 = _DAT_00804108 / local_38;
  }
  if (local_34 == _DAT_007d5344) {
    local_34 = _DAT_008048f0;
  }
  else {
    local_34 = _DAT_00804108 / local_34;
  }
  if (local_30 == _DAT_007d5344) {
    local_30 = _DAT_008048f0;
  }
  else {
    local_30 = _DAT_00804108 / local_30;
  }
  local_14 = (uint)(local_38 < (float)_DAT_007d0a60);
  local_10 = (uint)(local_34 < (float)_DAT_007d0a60);
  local_c = (uint)(local_30 < (float)_DAT_007d0a60);
  local_58 = *param_3;
  local_54 = param_3[1];
  local_50 = param_3[2];
  local_4c = param_3[3];
  local_7c = *param_3;
  local_78 = param_3[1];
  local_74 = param_3[2];
  local_70 = param_3[3];
  if (*param_4 < local_58) {
    local_58 = *param_4;
  }
  if (param_4[1] < local_54) {
    local_54 = param_4[1];
  }
  if (param_4[2] < local_50) {
    local_50 = param_4[2];
  }
  if (param_4[3] < local_4c) {
    local_4c = param_4[3];
  }
  if (local_7c < *param_4) {
    local_7c = *param_4;
  }
  if (local_78 < param_4[1]) {
    local_78 = param_4[1];
  }
  if (local_74 < param_4[2]) {
    local_74 = param_4[2];
  }
  if (local_70 < param_4[3]) {
    local_70 = param_4[3];
  }
  local_6c = local_58 + *param_5;
  local_68 = local_54 + param_5[1];
  local_60 = local_4c;
  local_64 = local_50 + param_5[2];
  local_7c = local_7c + *param_6;
  local_78 = local_78 + param_6[1];
  local_74 = local_74 + param_6[2];
  local_58 = local_6c;
  local_54 = local_68;
  local_50 = local_64;
  FUN_007972b0(param_1 + 4);
  FUN_00797300(param_1 + 0x14);
  FUN_00793100(&local_24,&local_6c,0);
  local_68 = local_78;
  local_6c = local_7c;
  local_64 = local_74;
  local_60 = local_70;
  FUN_007972b0(param_1 + 4);
  FUN_00797300(param_1 + 0x14);
  FUN_00793100(&local_1c,&local_6c,1);
  do {
    while( true ) {
      if (param_8 <= param_7) {
        if (DAT_00f488d8 < local_28) {
          DAT_00f488d8 = local_28;
        }
        return;
      }
      local_8 = 0x3f800000;
      local_28 = local_28 + 1;
      local_84 = 0.0;
      iVar2 = FUN_00797420(((((local_22 <= puVar4[4] && local_20 <= puVar4[5]) &&
                             puVar4[1] <= local_1a) && local_24 <= puVar4[3]) &&
                           puVar4[2] <= local_18) && *puVar4 <= local_1c,1,0);
      local_85 = -1 < *(int *)(puVar4 + 6);
      if (iVar2 != 0) {
        local_80 = (float)puVar4[2] / *(float *)(param_1 + 0x2c);
        local_84 = (float)puVar4[1] / *(float *)(param_1 + 0x28);
        local_8c = (float)*puVar4 / *(float *)(param_1 + 0x24);
        FUN_005fc530(&local_8c,&local_84,&local_80);
        FUN_00612f50(param_1 + 4);
        local_54 = local_78;
        local_50 = local_74;
        local_58 = local_7c;
        local_80 = (float)puVar4[5] / *(float *)(param_1 + 0x2c);
        local_4c = local_70;
        local_84 = (float)puVar4[4] / *(float *)(param_1 + 0x28);
        local_8c = (float)puVar4[3] / *(float *)(param_1 + 0x24);
        FUN_005fc530(&local_8c,&local_84,&local_80);
        FUN_00612f50(param_1 + 4);
        local_58 = local_58 + *param_5;
        local_3c = local_60;
        local_54 = local_54 + param_5[1];
        local_50 = local_50 + param_5[2];
        local_48 = local_6c + *param_6;
        local_44 = local_68 + param_6[1];
        local_40 = local_64 + param_6[2];
        uVar3 = FUN_00614950(param_3,&local_38,&local_14,&local_58,&local_8,0,local_4);
        local_84 = (float)(uVar3 & 0xff);
      }
      if (local_85 != '\0') break;
LAB_00795e75:
      if (local_84 == 0.0) goto LAB_00795e7d;
LAB_00795e9d:
      puVar4 = puVar4 + 8;
      local_5c = local_5c + 1;
      param_7 = local_5c;
    }
    if (local_84 != 0.0) {
      (**(code **)(*param_2 + 4))
                ((int)*(uint *)(puVar4 + 6) >> 0x15,*(uint *)(puVar4 + 6) & 0x1fffff);
      goto LAB_00795e75;
    }
LAB_00795e7d:
    if (local_85 != '\0') goto LAB_00795e9d;
    puVar1 = puVar4 + 6;
    puVar4 = puVar4 + *(int *)puVar1 * -8;
    local_5c = local_5c - *(int *)puVar1;
    param_7 = local_5c;
  } while( true );
}

