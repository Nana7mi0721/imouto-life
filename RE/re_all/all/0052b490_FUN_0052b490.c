
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0052b490(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  undefined4 *puVar5;
  float *pfVar6;
  undefined4 *puVar7;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0 [16];
  undefined4 local_80 [32];
  
  iVar3 = param_1 + 0x60;
  if (*(int *)(param_1 + 0x44) == 0) {
    iVar3 = param_1 + 0xc0;
  }
  local_e4 = _DAT_007d5564;
  iVar2 = 8;
  local_e0 = _DAT_007d5564;
  local_dc = _DAT_007d5564;
  local_f0 = _DAT_007d5560;
  local_ec = _DAT_007d5560;
  local_e8 = _DAT_007d5560;
  do {
    FUN_00586200(&local_cc,iVar3,param_1 + 0x204);
    if (local_cc < local_e4) {
      local_e4 = local_cc;
    }
    if (local_c8 < local_e0) {
      local_e0 = local_c8;
    }
    if (local_c4 < local_dc) {
      local_dc = local_c4;
    }
    if (local_f0 < local_cc) {
      local_f0 = local_cc;
    }
    if (local_ec < local_c8) {
      local_ec = local_c8;
    }
    if (local_e8 < local_c4) {
      local_e8 = local_c4;
    }
    iVar3 = iVar3 + 0xc;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  pfVar4 = (float *)(param_1 + 0x16c);
  fVar1 = (float)_DAT_00804a60;
  *(float *)(param_1 + 0x15c) = -((local_e4 + local_f0) * fVar1);
  *(float *)(param_1 + 0x160) = -((local_e0 + local_ec) * fVar1);
  *(float *)(param_1 + 0x164) = -local_dc;
  fVar1 = (float)_DAT_00829868;
  *pfVar4 = fVar1 / (local_f0 - local_e4);
  *(float *)(param_1 + 0x180) = fVar1 / (local_ec - local_e0);
  *(float *)(param_1 + 0x194) = 1.0 / (local_e8 - local_dc);
  FUN_005850a0(param_1 + 0x1ac,param_1 + 300,pfVar4);
  FUN_00521c60(param_1 + 300);
  pfVar6 = local_c0;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar6 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar6 = pfVar6 + 1;
  }
  FUN_00584f80(local_80,local_c0);
  DAT_00a384e0 = 2;
  puVar5 = local_80;
  puVar7 = &DAT_00a38510;
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  FUN_00524b70();
  return 0;
}

