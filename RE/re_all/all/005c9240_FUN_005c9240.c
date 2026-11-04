
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005c9240(int *param_1,int param_2,int param_3)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  float *pfVar5;
  float fVar6;
  int iVar7;
  float *pfVar8;
  uint uVar9;
  int local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar7 = 0;
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_2 + 0x88) != 1) {
    return 0xffffffff;
  }
  uVar9 = param_1[3] | 0x8000;
  if (*(char *)(*(int *)(param_2 + 0x4c) + 10) != '\0') {
    uVar9 = param_1[3] | 0x18000;
  }
  if (*(char *)(*(int *)(param_2 + 0x4c) + 0x12) != '\0') {
    uVar9 = uVar9 | 0x20000;
  }
  if (DAT_00ef7314 != *(int *)(**(int **)(param_2 + 0x100) + 4)) {
    iVar2 = **(int **)(param_2 + 0x100);
    FUN_005bc5b0(*(undefined4 *)(iVar2 + 4),*(undefined4 *)(iVar2 + 8));
  }
  if (((DAT_00a3d360 != 0) || (DAT_00ef72cc != 0)) || (DAT_00ef72c8 != uVar9)) {
    FUN_005bcf50();
  }
  fVar6 = DAT_00f07344;
  fVar4 = DAT_00a380b8;
  if (param_3 != 0) {
    iVar7 = param_3 + 0x8c;
  }
  if (DAT_00f0733c == 1) {
    pfVar8 = (float *)param_1[1];
    iVar7 = 0;
    if (0 < *param_1) {
      do {
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
           (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <=
            DAT_00f07334 + 6)) {
          FUN_005c3310(0,0);
          DAT_00f07340 = 4;
        }
        pfVar5 = DAT_00f0732c;
        DAT_00f0732c[4] = fVar6;
        pfVar5[0xb] = fVar6;
        pfVar5[0x12] = fVar6;
        pfVar5[0x19] = fVar6;
        pfVar5[0x20] = fVar6;
        pfVar5[0x27] = fVar6;
        pfVar5[5] = pfVar8[2];
        iVar7 = iVar7 + 1;
        pfVar5[6] = pfVar8[3];
        pfVar5[0xc] = pfVar8[6];
        pfVar5[0xd] = pfVar8[7];
        pfVar5[0x13] = pfVar8[10];
        pfVar5[0x14] = pfVar8[0xb];
        pfVar5[0x1a] = pfVar8[0xe];
        pfVar5[0x1b] = pfVar8[0xf];
        pfVar5[0x21] = pfVar8[10];
        pfVar5[0x22] = pfVar8[0xb];
        pfVar5[0x28] = pfVar8[6];
        pfVar5[0x29] = pfVar8[7];
        *pfVar5 = *pfVar8;
        pfVar5[1] = pfVar8[1];
        pfVar5[7] = pfVar8[4];
        pfVar5[8] = pfVar8[5];
        pfVar5[0xe] = pfVar8[8];
        pfVar5[0xf] = pfVar8[9];
        pfVar5[0x15] = pfVar8[0xc];
        pfVar5[0x16] = pfVar8[0xd];
        pfVar5[0x1c] = pfVar8[8];
        pfVar5[0x1d] = pfVar8[9];
        pfVar5[0x23] = pfVar8[4];
        fVar1 = pfVar8[5];
        pfVar5[2] = fVar4;
        pfVar5[0x24] = fVar1;
        pfVar5[9] = fVar4;
        pfVar5[0x10] = fVar4;
        pfVar5[3] = 1.0;
        pfVar5[0x17] = fVar4;
        pfVar5[10] = 1.0;
        pfVar5[0x1e] = fVar4;
        pfVar5[0x11] = 1.0;
        pfVar5[0x25] = fVar4;
        pfVar5[0x18] = 1.0;
        pfVar5[0x1f] = 1.0;
        pfVar5[0x26] = 1.0;
        DAT_00f0732c = DAT_00f0732c + 0x2a;
        DAT_00f07334 = DAT_00f07334 + 6;
        pfVar8 = pfVar8 + 0x10;
      } while (iVar7 < *param_1);
    }
  }
  else if (DAT_00f0733c == 2) {
    FUN_005bc5b0(*(undefined4 *)(**(int **)(param_2 + 0x100) + 4),
                 *(undefined4 *)(**(int **)(param_2 + 0x100) + 8));
    piVar3 = *(int **)(iVar7 + 0x74);
    FUN_005bc640(*(undefined4 *)(*piVar3 + 4),*(undefined4 *)(*piVar3 + 8),piVar3[5],piVar3[6]);
    if (DAT_00ef72e8 != 0) {
      FUN_005bbac0();
    }
    local_24 = 0;
    if (0 < *param_1) {
      pfVar8 = (float *)param_1[1];
      do {
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
           (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <=
            DAT_00f07334 + 6)) {
          FUN_005c3310(0,0);
          DAT_00f07340 = 4;
        }
        pfVar5 = DAT_00f0732c;
        DAT_00f0732c[4] = fVar6;
        pfVar5[0xe] = fVar6;
        pfVar5[0x18] = fVar6;
        pfVar5[0x22] = fVar6;
        pfVar5[0x2c] = fVar6;
        pfVar5[0x36] = fVar6;
        *pfVar5 = *pfVar8;
        pfVar5[1] = pfVar8[1];
        pfVar5[10] = pfVar8[4];
        pfVar5[0xb] = pfVar8[5];
        pfVar5[0x14] = pfVar8[8];
        pfVar5[0x15] = pfVar8[9];
        pfVar5[0x1e] = pfVar8[0xc];
        pfVar5[0x1f] = pfVar8[0xd];
        pfVar5[0x28] = pfVar8[8];
        pfVar5[0x29] = pfVar8[9];
        pfVar5[0x32] = pfVar8[4];
        pfVar5[0x33] = pfVar8[5];
        local_14 = (float)_DAT_00a380e0;
        if (DAT_00a380e8 == 1) {
          local_20 = (*pfVar8 - *(float *)(iVar7 + 0x30)) - local_14;
          fVar1 = (float)_DAT_00a380e4;
          local_10 = (pfVar8[1] - *(float *)(iVar7 + 0x34)) - fVar1;
          local_1c = (pfVar8[4] - *(float *)(iVar7 + 0x30)) - local_14;
          local_c = (pfVar8[5] - *(float *)(iVar7 + 0x34)) - fVar1;
          local_18 = (pfVar8[8] - *(float *)(iVar7 + 0x30)) - local_14;
          local_8 = (pfVar8[9] - *(float *)(iVar7 + 0x34)) - fVar1;
          local_14 = (pfVar8[0xc] - *(float *)(iVar7 + 0x30)) - local_14;
          fVar1 = (pfVar8[0xd] - *(float *)(iVar7 + 0x34)) - fVar1;
        }
        else {
          local_20 = local_14 + (*(float *)(param_2 + 0xbc) - *(float *)(iVar7 + 0x30));
          fVar1 = (float)_DAT_00a380e4;
          local_10 = fVar1 + (*(float *)(param_2 + 0xc0) - *(float *)(iVar7 + 0x34));
          local_1c = (*(float *)(param_2 + 0xcc) - *(float *)(iVar7 + 0x40)) + local_14;
          local_c = (*(float *)(param_2 + 0xd0) - *(float *)(iVar7 + 0x44)) + fVar1;
          local_18 = (*(float *)(param_2 + 0xdc) - *(float *)(iVar7 + 0x50)) + local_14;
          local_8 = (*(float *)(param_2 + 0xe0) - *(float *)(iVar7 + 0x54)) + fVar1;
          local_14 = (*(float *)(param_2 + 0xec) - *(float *)(iVar7 + 0x60)) + local_14;
          fVar1 = (*(float *)(param_2 + 0xf0) - *(float *)(iVar7 + 100)) + fVar1;
        }
        local_8 = local_8 * _DAT_00ef7310;
        local_c = local_c * _DAT_00ef7310;
        local_10 = _DAT_00ef7310 * local_10;
        local_14 = local_14 * _DAT_00ef730c;
        local_18 = local_18 * _DAT_00ef730c;
        local_1c = local_1c * _DAT_00ef730c;
        local_20 = _DAT_00ef730c * local_20;
        fVar1 = fVar1 * _DAT_00ef7310;
        pfVar5[6] = local_20;
        pfVar5[7] = local_10;
        pfVar5[0x10] = local_1c;
        pfVar5[0x11] = local_c;
        pfVar5[0x1a] = local_18;
        pfVar5[0x1b] = local_8;
        pfVar5[0x24] = local_14;
        pfVar5[0x25] = fVar1;
        pfVar5[0x2e] = local_18;
        pfVar5[0x2f] = local_8;
        pfVar5[0x38] = local_1c;
        pfVar5[0x39] = local_c;
        pfVar5[8] = pfVar8[2];
        pfVar5[9] = pfVar8[3];
        pfVar5[0x12] = pfVar8[6];
        pfVar5[0x13] = pfVar8[7];
        pfVar5[0x1c] = pfVar8[10];
        pfVar5[0x1d] = pfVar8[0xb];
        pfVar5[0x26] = pfVar8[0xe];
        pfVar5[0x27] = pfVar8[0xf];
        pfVar5[0x30] = pfVar8[10];
        pfVar5[0x31] = pfVar8[0xb];
        pfVar5[0x3a] = pfVar8[6];
        fVar1 = pfVar8[7];
        pfVar5[2] = fVar4;
        pfVar5[0x3b] = fVar1;
        pfVar5[0xc] = fVar4;
        pfVar5[0x16] = fVar4;
        pfVar5[3] = 1.0;
        pfVar5[0x20] = fVar4;
        pfVar5[0xd] = 1.0;
        pfVar5[0x2a] = fVar4;
        pfVar5[0x17] = 1.0;
        pfVar5[0x34] = fVar4;
        pfVar5[0x21] = 1.0;
        pfVar5[0x2b] = 1.0;
        pfVar5[0x35] = 1.0;
        DAT_00f0732c = DAT_00f0732c + 0x3c;
        DAT_00f07334 = DAT_00f07334 + 6;
        local_24 = local_24 + 1;
        pfVar8 = pfVar8 + 0x10;
      } while (local_24 < *param_1);
      return 0;
    }
  }
  return 0;
}

