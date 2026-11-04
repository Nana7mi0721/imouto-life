
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_007946e0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  undefined4 *puVar5;
  float *pfVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  int local_b0;
  float local_ac [4];
  undefined4 *local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  undefined4 local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  undefined4 local_5c;
  float *local_58;
  undefined4 local_54;
  undefined1 local_50 [16];
  undefined4 local_40 [16];
  
  fVar4 = (float)(param_3 - param_2);
  local_b0 = param_2;
  local_98 = fVar4;
  local_94 = fVar4;
  local_ac[0] = 0.0;
  local_ac[1] = 0.0;
  local_ac[2] = 0.0;
  local_ac[3] = 0.0;
  if (param_2 < param_3) {
    iVar9 = param_2 << 6;
    iVar8 = param_2 << 4;
    do {
      local_b8 = 0.5;
      if (*(char *)(param_1 + 0x3c) == '\0') {
        pfVar6 = (float *)(*(int *)(param_1 + 0x4c) + iVar9);
        local_90 = *pfVar6;
        local_8c = pfVar6[1];
        local_88 = pfVar6[2];
        local_84 = pfVar6[3];
      }
      else {
        FUN_00797350(&local_90,*(int *)(param_1 + 0x74) + iVar8);
      }
      if (*(char *)(param_1 + 0x3c) == '\0') {
        iVar1 = *(int *)(param_1 + 0x4c) + 0x10 + iVar9;
        local_80 = *(float *)(*(int *)(param_1 + 0x4c) + 0x10 + iVar9);
        local_7c = *(float *)(iVar1 + 4);
        local_78 = *(float *)(iVar1 + 8);
        local_74 = *(undefined4 *)(iVar1 + 0xc);
      }
      else {
        FUN_00797350(&local_80,*(int *)(param_1 + 0x74) + 6 + iVar8);
      }
      local_b4 = local_78 + local_88;
      local_bc = local_7c + local_8c;
      local_c0 = local_80 + local_90;
      FUN_005fc500(&local_c0,&local_bc,&local_b4);
      FUN_0060fe40(&local_68,local_50,&local_b8);
      local_ac[0] = local_68 + local_ac[0];
      iVar8 = iVar8 + 0x10;
      iVar9 = iVar9 + 0x40;
      fVar4 = (float)((int)fVar4 + -1);
      local_ac[1] = local_ac[1] + local_64;
      local_ac[2] = local_ac[2] + local_60;
    } while (fVar4 != 0.0);
  }
  fVar4 = _DAT_00804108 / (float)(int)local_94;
  local_ac[0] = local_ac[0] * fVar4;
  local_ac[1] = local_ac[1] * fVar4;
  local_ac[2] = local_ac[2] * fVar4;
  local_6c = local_ac[param_4];
  if (param_2 < param_3) {
    local_58 = local_ac + param_4;
    local_bc = (float)(param_2 << 6);
    fVar4 = (float)(param_2 << 4);
    local_c0 = fVar4;
    local_b8 = local_bc;
    local_b4 = local_98;
    do {
      fVar10 = local_bc;
      fVar11 = local_c0;
      local_54 = 0x3f000000;
      if (*(char *)(param_1 + 0x3c) == '\0') {
        pfVar6 = (float *)(*(int *)(param_1 + 0x4c) + (int)local_bc);
        local_90 = *pfVar6;
        local_8c = pfVar6[1];
        local_88 = pfVar6[2];
        local_84 = pfVar6[3];
      }
      else {
        FUN_00797350(&local_90,*(int *)(param_1 + 0x74) + (int)local_c0);
      }
      if (*(char *)(param_1 + 0x3c) == '\0') {
        iVar8 = *(int *)(param_1 + 0x4c) + 0x10 + (int)fVar10;
        local_80 = *(float *)(*(int *)(param_1 + 0x4c) + 0x10 + (int)fVar10);
        local_7c = *(float *)(iVar8 + 4);
        local_78 = *(float *)(iVar8 + 8);
        local_74 = *(undefined4 *)(iVar8 + 0xc);
      }
      else {
        FUN_00797350(&local_80,*(int *)(param_1 + 0x74) + 6 + (int)fVar11);
      }
      local_98 = local_78 + local_88;
      local_70 = local_7c + local_8c;
      local_9c = (undefined4 *)(local_90 + local_80);
      FUN_005fc500(&local_9c,&local_70,&local_98);
      FUN_0060fe40(local_ac,local_50,&local_54);
      if (local_6c < *local_58) {
        if (*(char *)(param_1 + 0x3c) == '\0') {
          iVar8 = *(int *)(param_1 + 0x4c);
          local_9c = (undefined4 *)((int)fVar10 + iVar8);
          puVar5 = local_9c;
          puVar7 = local_40;
          for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
          puVar5 = (undefined4 *)((int)local_b8 + iVar8);
          puVar7 = local_9c;
          for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
          puVar5 = local_40;
          puVar7 = (undefined4 *)((int)local_b8 + *(int *)(param_1 + 0x4c));
          for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
        }
        else {
          puVar5 = (undefined4 *)((int)fVar11 + *(int *)(param_1 + 0x74));
          puVar7 = (undefined4 *)(*(int *)(param_1 + 0x74) + (int)fVar4);
          uVar2 = *puVar5;
          local_64 = (float)puVar5[1];
          uVar3 = puVar5[2];
          local_5c = puVar5[3];
          *puVar5 = *puVar7;
          puVar5[1] = puVar7[1];
          puVar5[2] = puVar7[2];
          puVar5[3] = puVar7[3];
          puVar5 = (undefined4 *)((int)fVar4 + *(int *)(param_1 + 0x74));
          *puVar5 = uVar2;
          puVar5[1] = local_64;
          puVar5[2] = uVar3;
          puVar5[3] = local_5c;
        }
        local_b0 = local_b0 + 1;
        fVar4 = (float)((int)fVar4 + 0x10);
        local_b8 = (float)((int)local_b8 + 0x40);
        fVar10 = local_bc;
        fVar11 = local_c0;
      }
      local_c0 = (float)((int)fVar11 + 0x10);
      local_bc = (float)((int)fVar10 + 0x40);
      local_b4 = (float)((int)local_b4 + -1);
    } while (local_b4 != 0.0);
  }
  if (((int)local_94 / 3 + param_2 < local_b0) && (local_b0 < (param_3 - (int)local_94 / 3) + -1)) {
    return local_b0;
  }
  return ((int)local_94 >> 1) + param_2;
}

