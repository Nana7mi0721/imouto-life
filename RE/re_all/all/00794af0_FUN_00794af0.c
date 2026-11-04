
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00794af0(int param_1,int param_2,int param_3)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  local_9c = (float)(param_3 - param_2);
  local_8c = 0.0;
  local_88 = 0.0;
  local_84 = 0.0;
  local_48 = 0.0;
  local_44 = 0.0;
  local_40 = 0.0;
  local_3c = 0;
  local_94 = local_9c;
  if (param_2 < param_3) {
    iVar4 = param_2 << 6;
    iVar3 = param_2 << 4;
    local_90 = local_9c;
    do {
      local_98 = 0.5;
      if (*(char *)(param_1 + 0x3c) == '\0') {
        pfVar2 = (float *)(*(int *)(param_1 + 0x4c) + iVar4);
        local_6c = *pfVar2;
        local_68 = pfVar2[1];
        local_64 = pfVar2[2];
        local_60 = pfVar2[3];
      }
      else {
        FUN_00797350(&local_6c,*(int *)(param_1 + 0x74) + iVar3);
      }
      if (*(char *)(param_1 + 0x3c) == '\0') {
        iVar1 = *(int *)(param_1 + 0x4c) + 0x10 + iVar4;
        local_7c = *(float *)(*(int *)(param_1 + 0x4c) + 0x10 + iVar4);
        local_78 = *(float *)(iVar1 + 4);
        local_74 = *(float *)(iVar1 + 8);
        local_70 = *(float *)(iVar1 + 0xc);
      }
      else {
        FUN_00797350(&local_7c,*(int *)(param_1 + 0x74) + 6 + iVar3);
      }
      local_38 = local_74 + local_64;
      local_34 = local_78 + local_68;
      local_5c = local_7c + local_6c;
      FUN_005fc500(&local_5c,&local_34,&local_38);
      FUN_0060fe40(&local_58,&local_30,&local_98);
      local_8c = local_58 + local_8c;
      iVar3 = iVar3 + 0x10;
      iVar4 = iVar4 + 0x40;
      local_90 = (float)((int)local_90 + -1);
      local_88 = local_88 + local_54;
      local_84 = local_84 + local_50;
    } while (local_90 != 0.0);
  }
  local_90 = (float)(int)local_9c;
  fVar5 = _DAT_00804108 / local_90;
  local_8c = local_8c * fVar5;
  local_88 = local_88 * fVar5;
  local_84 = local_84 * fVar5;
  if (param_2 < param_3) {
    iVar3 = param_2 << 6;
    param_2 = param_2 << 4;
    fVar5 = local_94;
    do {
      local_5c = 0.5;
      if (*(char *)(param_1 + 0x3c) == '\0') {
        pfVar2 = (float *)(*(int *)(param_1 + 0x4c) + iVar3);
        local_6c = *pfVar2;
        local_68 = pfVar2[1];
        local_64 = pfVar2[2];
        local_60 = pfVar2[3];
      }
      else {
        FUN_00797350(&local_6c,*(int *)(param_1 + 0x74) + param_2);
      }
      if (*(char *)(param_1 + 0x3c) == '\0') {
        iVar4 = *(int *)(param_1 + 0x4c) + 0x10 + iVar3;
        local_58 = *(float *)(*(int *)(param_1 + 0x4c) + 0x10 + iVar3);
        local_54 = *(float *)(iVar4 + 4);
        local_50 = *(float *)(iVar4 + 8);
        local_4c = *(undefined4 *)(iVar4 + 0xc);
      }
      else {
        FUN_00797350(&local_58,*(int *)(param_1 + 0x74) + 6 + param_2);
      }
      local_9c = local_64 + local_50;
      local_94 = local_68 + local_54;
      local_98 = local_6c + local_58;
      FUN_005fc500(&local_98,&local_94,&local_9c);
      FUN_0060fe40(&local_30,local_20,&local_5c);
      local_9c = local_28 - local_84;
      local_94 = local_2c - local_88;
      local_98 = local_30 - local_8c;
      FUN_005fc500(&local_98,&local_94,&local_9c);
      pfVar2 = (float *)FUN_005fc560(local_10,&local_7c,&local_7c);
      local_7c = *pfVar2;
      param_2 = param_2 + 0x10;
      local_78 = pfVar2[1];
      iVar3 = iVar3 + 0x40;
      local_48 = local_7c + local_48;
      local_74 = pfVar2[2];
      fVar5 = (float)((int)fVar5 + -1);
      local_70 = pfVar2[3];
      local_44 = local_44 + local_78;
      local_40 = local_40 + local_74;
    } while (fVar5 != 0.0);
  }
  local_9c = _DAT_00804108 / (local_90 - _DAT_00804108);
  FUN_0061a860(&local_9c);
  FUN_007973e0();
  return;
}

