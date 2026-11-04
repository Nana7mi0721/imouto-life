
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall
FUN_0063dab0(int param_1,float param_2,float param_3,int param_4,int param_5,float *param_6,
            int param_7,int param_8,float *param_9,int param_10,float *param_11,float *param_12)

{
  float fVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  float *pfVar5;
  undefined4 uVar6;
  float *pfVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  float fVar10;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
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
  undefined1 local_70 [16];
  undefined1 local_60 [16];
  undefined1 local_50 [16];
  undefined1 local_40 [16];
  undefined1 local_30 [16];
  undefined1 local_20 [32];
  
  local_d4 = param_12[2] - *(float *)(param_4 + 0x3c);
  local_cc = param_12[1] - *(float *)(param_4 + 0x38);
  local_d0 = *param_12 - *(float *)(param_4 + 0x34);
  FUN_005fc500(&local_d0,&local_cc,&local_d4);
  local_d4 = param_12[2] - *(float *)(param_7 + 0x3c);
  local_cc = param_12[1] - *(float *)(param_7 + 0x38);
  local_d0 = *param_12 - *(float *)(param_7 + 0x34);
  FUN_005fc500(&local_d0,&local_cc,&local_d4);
  iVar2 = *(int *)(param_5 + 0x44);
  if (iVar2 == 0) {
    local_d4 = 0.0;
    local_cc = 0.0;
    local_d0 = 0.0;
    FUN_005fc530(&local_d0,&local_cc,&local_d4);
  }
  else {
    local_d4 = (float)(iVar2 + 0x130);
    pfVar5 = &local_b0;
    pfVar7 = &local_90;
    FUN_0060f480(local_40,iVar2 + 0x140,param_5 + 0x10,pfVar7,pfVar5);
    uVar4 = FUN_006170e0(pfVar7,pfVar5);
    uVar4 = FUN_0060f480(local_70,local_d4,param_5,uVar4);
    pfVar5 = (float *)FUN_0060f480(local_60,uVar4);
    local_a0 = *pfVar5;
    local_9c = pfVar5[1];
    local_98 = pfVar5[2];
    local_94 = pfVar5[3];
  }
  iVar2 = *(int *)(param_8 + 0x44);
  if (iVar2 == 0) {
    local_d4 = 0.0;
    local_cc = 0.0;
    local_d0 = 0.0;
    FUN_005fc530(&local_d0,&local_cc,&local_d4);
  }
  else {
    local_d4 = (float)(iVar2 + 0x130);
    puVar9 = local_50;
    puVar8 = local_60;
    FUN_0060f480(local_70,iVar2 + 0x140,param_8 + 0x10,puVar8,puVar9);
    uVar4 = FUN_006170e0(puVar8,puVar9);
    uVar4 = FUN_0060f480(local_40,local_d4,param_8,uVar4);
    pfVar5 = (float *)FUN_0060f480(&local_90,uVar4);
    local_c0 = *pfVar5;
    local_bc = pfVar5[1];
    local_b8 = pfVar5[2];
    local_b4 = pfVar5[3];
  }
  local_d4 = local_98 - local_b8;
  local_cc = local_9c - local_bc;
  local_d0 = local_a0 - local_c0;
  FUN_005fc500(&local_d0,&local_cc,&local_d4);
  local_c4 = local_80 * *param_11 + local_7c * param_11[1] + local_78 * param_11[2];
  local_d4 = param_6[2] - param_9[2];
  local_cc = param_6[1] - param_9[1];
  local_d0 = *param_6 - *param_9;
  FUN_005fc500(&local_d0,&local_cc,&local_d4);
  local_d4 = -1e+18;
  local_cc = 1e+18;
  fVar3 = -(local_8c * param_11[1] + local_88 * param_11[2] + local_90 * *param_11);
  fVar10 = *(float *)(param_1 + param_10 * 4);
  fVar1 = *(float *)(param_1 + 0x10 + param_10 * 4);
  if (fVar10 < fVar1) {
    if (fVar3 <= fVar1) {
      if (fVar10 <= fVar3) {
        return (float10)_DAT_007d5344;
      }
      fVar3 = fVar3 - fVar10;
      local_cc = 0.0;
    }
    else {
      fVar3 = fVar3 - fVar1;
      local_d4 = 0.0;
    }
  }
  local_d0 = *(float *)(param_1 + 0x20 + param_10 * 4);
  local_c8 = ((fVar3 * *(float *)(param_1 + 0x38)) / param_2 - local_c4 * *(float *)(param_1 + 0x34)
             ) * *(float *)(param_1 + 0x30) * param_3 + local_d0;
  if ((local_cc < local_c8) || (local_c8 < local_d4)) {
    local_c8 = _DAT_007d5344;
  }
  *(float *)(param_1 + 0x20 + param_10 * 4) = local_c8;
  local_c8 = local_c8 - local_d0;
  local_c4 = local_c8 * param_11[2];
  local_d4 = local_c8 * param_11[1];
  local_cc = local_c8 * *param_11;
  FUN_005fc500(&local_cc,&local_d4,&local_c4);
  local_c4 = local_b0 * param_11[1] - local_ac * *param_11;
  local_d4 = local_a8 * *param_11 - local_b0 * param_11[2];
  local_cc = local_ac * param_11[2] - local_a8 * param_11[1];
  FUN_005fc500(&local_cc,&local_d4,&local_c4);
  FUN_006170e0(local_20,param_11);
  local_c4 = *(float *)(param_4 + 0x150);
  fVar10 = local_c8;
  uVar4 = FUN_005fc730(local_60,param_4 + 0x100,local_30,local_c8);
  uVar6 = FUN_0060fe40(local_70,param_11,&local_c4,uVar4);
  FUN_0063abf0(uVar6,uVar4,fVar10);
  local_c4 = *(float *)(param_7 + 0x150);
  fVar10 = -local_c8;
  uVar4 = FUN_005fc730(local_60,param_7 + 0x100,local_20,fVar10);
  uVar6 = FUN_0060fe40(local_70,param_11,&local_c4,uVar4);
  FUN_0063abf0(uVar6,uVar4,fVar10);
  return (float10)local_c8;
}

