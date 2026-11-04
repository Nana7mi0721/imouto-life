
float * __thiscall
FUN_00637400(int param_1,float *param_2,float param_3,float param_4,float param_5,int param_6,
            float *param_7,float *param_8,uint param_9,uint param_10,float param_11)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  float10 fVar9;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  undefined4 local_c8;
  float local_c4;
  uint local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98 [4];
  undefined4 local_88 [34];
  
  param_9 = (*(int *)(param_9 + 0xe8) != 2) - 1 & param_9;
  local_ac = (float)param_9;
  iVar6 = *(int *)(param_1 + 0x44);
  local_c0 = (*(int *)(param_10 + 0xe8) != 2) - 1 & param_10;
  if (iVar6 == *(int *)(param_1 + 0x48)) {
    iVar2 = iVar6 * 2;
    if (iVar6 == 0) {
      iVar2 = 1;
    }
    FUN_0063af40(iVar2);
  }
  *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
  puVar8 = (undefined4 *)(iVar6 * 0x88 + *(int *)(param_1 + 0x4c));
  if (puVar8 != (undefined4 *)0x0) {
    puVar7 = local_88;
    for (iVar2 = 0x22; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
  }
  pfVar3 = (float *)(iVar6 * 0x88 + *(int *)(param_1 + 0x4c));
  pfVar5 = pfVar3;
  for (iVar6 = 0x22; iVar6 != 0; iVar6 = iVar6 + -1) {
    *pfVar5 = -NAN;
    pfVar5 = pfVar5 + 1;
  }
  pfVar5 = pfVar3 + 4;
  *pfVar5 = *param_2;
  pfVar3[5] = param_2[1];
  pfVar3[6] = param_2[2];
  fVar1 = param_2[3];
  pfVar3[0x1b] = param_4;
  pfVar3[7] = fVar1;
  pfVar3[0x1a] = param_3;
  pfVar3[0x19] = param_5;
  fVar1 = *(float *)(param_6 + 0x54);
  pfVar3[0x1c] = 0.0;
  pfVar3[0x16] = fVar1;
  pfVar3[0x15] = 0.0;
  pfVar3[0x14] = 0.0;
  local_e8 = *param_7 * pfVar3[5] - param_7[1] * *pfVar5;
  local_ec = *pfVar5 * param_7[2] - *param_7 * pfVar3[6];
  local_e0 = param_7[1] * pfVar3[6] - param_7[2] * pfVar3[5];
  FUN_005fc500(&local_e0,&local_ec,&local_e8);
  *pfVar3 = local_bc;
  pfVar3[1] = local_b8;
  pfVar3[2] = local_b4;
  pfVar3[3] = local_b0;
  if (param_9 == 0) {
    local_d4 = 0.0;
    local_d0 = 0.0;
    local_cc = 0.0;
    local_c8 = 0;
    pfVar4 = &local_d4;
  }
  else {
    fVar9 = (float10)FUN_005fcc30(&local_bc);
    local_e0 = (float)fVar9;
    fVar9 = (float10)FUN_005fcc30(&local_bc);
    local_e8 = (float)fVar9;
    fVar9 = (float10)FUN_005fcc30(&local_bc);
    local_ec = (float)fVar9;
    FUN_005fc500(&local_ec,&local_e8,&local_e0);
    local_dc = local_cc * *(float *)(param_9 + 0x15c);
    local_e4 = local_d0 * *(float *)(param_9 + 0x158);
    local_d8 = local_d4 * *(float *)(param_9 + 0x154);
    FUN_005fc500(&local_d8,&local_e4,&local_dc);
    pfVar4 = local_98;
  }
  pfVar3[0xc] = *pfVar4;
  pfVar3[0xd] = pfVar4[1];
  fVar1 = pfVar4[3];
  pfVar3[0xe] = pfVar4[2];
  pfVar3[0xf] = fVar1;
  local_d8 = -pfVar3[6];
  local_e4 = -pfVar3[5];
  local_dc = -*pfVar5;
  FUN_005fc500(&local_dc,&local_e4,&local_d8);
  local_e0 = local_d0 * *param_8 - local_d4 * param_8[1];
  local_e8 = local_d4 * param_8[2] - local_cc * *param_8;
  local_ec = local_cc * param_8[1] - local_d0 * param_8[2];
  FUN_005fc500(&local_ec,&local_e8,&local_e0);
  pfVar3[8] = local_bc;
  pfVar3[9] = local_b8;
  pfVar3[10] = local_b4;
  pfVar3[0xb] = local_b0;
  if (local_c0 == 0) {
    local_d4 = 0.0;
    local_d0 = 0.0;
    local_cc = 0.0;
    local_c8 = 0;
    pfVar5 = &local_d4;
  }
  else {
    fVar9 = (float10)FUN_005fcc30(&local_bc);
    local_d8 = (float)fVar9;
    fVar9 = (float10)FUN_005fcc30(&local_bc);
    local_e4 = (float)fVar9;
    fVar9 = (float10)FUN_005fcc30(&local_bc);
    local_dc = (float)fVar9;
    FUN_005fc500(&local_dc,&local_e4,&local_d8);
    local_e0 = local_cc * *(float *)(local_c0 + 0x15c);
    local_e8 = local_d0 * *(float *)(local_c0 + 0x158);
    local_ec = local_d4 * *(float *)(local_c0 + 0x154);
    FUN_005fc500(&local_ec,&local_e8,&local_e0);
    pfVar5 = local_98;
  }
  local_e8 = 0.0;
  local_ec = 0.0;
  pfVar3[0x10] = *pfVar5;
  pfVar3[0x11] = pfVar5[1];
  fVar1 = pfVar5[3];
  pfVar3[0x12] = pfVar5[2];
  pfVar3[0x13] = fVar1;
  if (local_ac != 0.0) {
    local_d8 = pfVar3[0xc] * param_7[1] - pfVar3[0xd] * *param_7;
    local_e4 = *param_7 * pfVar3[0xe] - pfVar3[0xc] * param_7[2];
    local_dc = pfVar3[0xd] * param_7[2] - param_7[1] * pfVar3[0xe];
    FUN_005fc500(&local_dc,&local_e4,&local_d8);
    local_a4 = local_b8;
    local_a8 = local_bc;
    local_a0 = local_b4;
    local_9c = local_b0;
    local_e8 = local_bc * *param_2 + local_b4 * param_2[2] + local_b8 * param_2[1] +
               *(float *)((int)local_ac + 0x150);
  }
  if (local_c0 != 0) {
    local_d8 = -pfVar3[0x12];
    local_e4 = -pfVar3[0x11];
    local_dc = -pfVar3[0x10];
    FUN_005fc500(&local_dc,&local_e4,&local_d8);
    local_e0 = local_d4 * param_8[1] - local_d0 * *param_8;
    local_ec = local_cc * *param_8 - local_d4 * param_8[2];
    local_c4 = local_d0 * param_8[2] - local_cc * param_8[1];
    FUN_005fc500(&local_c4,&local_ec,&local_e0);
    local_a8 = local_bc;
    local_a4 = local_b8;
    local_9c = local_b0;
    local_a0 = local_b4;
    local_c4 = *(float *)(local_c0 + 0x150);
    fVar9 = (float10)FUN_005fcc30(&local_a8);
    local_ec = (float)(fVar9 + (float10)local_c4);
  }
  pfVar3[0x17] = param_11 / (local_ec + local_e8);
  if (local_ac == 0.0) {
    local_c4 = 0.0;
    local_d8 = 0.0;
    local_e4 = 0.0;
    iVar6 = FUN_005fc500(&local_e4,&local_d8,&local_c4);
    local_dc = 0.0;
    local_e0 = 0.0;
    local_e8 = 0.0;
    iVar2 = FUN_005fc500(&local_e8,&local_e0,&local_dc);
  }
  else {
    iVar6 = (int)local_ac + 0x130;
    iVar2 = (int)local_ac + 0x140;
  }
  fVar9 = (float10)FUN_005fcc30(iVar6);
  local_ec = (float)fVar9;
  fVar9 = (float10)FUN_005fcc30(iVar2);
  local_ac = (float)(fVar9 + (float10)local_ec);
  if (local_c0 == 0) {
    local_c4 = 0.0;
    local_d8 = 0.0;
    local_e4 = 0.0;
    iVar6 = FUN_005fc500(&local_e4,&local_d8,&local_c4);
    local_dc = 0.0;
    local_e0 = 0.0;
    local_e8 = 0.0;
    iVar2 = FUN_005fc500(&local_e8,&local_e0,&local_dc);
  }
  else {
    iVar6 = local_c0 + 0x130;
    iVar2 = local_c0 + 0x140;
  }
  fVar9 = (float10)FUN_005fcc30(iVar2);
  local_ec = (float)fVar9;
  fVar9 = (float10)FUN_005fcc30(iVar6);
  pfVar3[0x1e] = 0.0;
  pfVar3[0x1f] = 0.0;
  pfVar3[0x20] = 1e+10;
  pfVar3[0x1d] = (float)(-(((float10)local_ec - fVar9) + (float10)local_ac) * (float10)pfVar3[0x17])
  ;
  return pfVar3;
}

