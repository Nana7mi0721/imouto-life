
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005c34c0(int param_1,int param_2,float param_3,float param_4,int param_5,int param_6,
            uint param_7,uint param_8)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float *pfVar9;
  float *pfVar10;
  int iVar11;
  float *pfVar12;
  float local_a4;
  float local_a0;
  int *local_9c;
  int local_98;
  float local_90 [4];
  float local_80 [4];
  float local_70;
  float local_6c;
  float local_68;
  int local_64;
  float local_60 [4];
  float local_50 [4];
  float local_40;
  float local_3c;
  uint local_38;
  float local_34;
  float local_30;
  float local_2c [2];
  float local_24;
  float local_20;
  float local_18;
  float local_14;
  float local_c;
  float local_8;
  
  local_9c = (int *)0x0;
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  param_7 = (param_8 | 0x4000) * 2 | param_7;
  if (*(char *)(*(int *)(param_5 + 0x4c) + 10) != '\0') {
    param_7 = param_7 | 0x10000;
  }
  if (*(char *)(*(int *)(param_5 + 0x4c) + 0x12) != '\0') {
    param_7 = param_7 | 0x20000;
  }
  if (DAT_00ef7314 != *(int *)(**(int **)(param_5 + 0x100) + 4)) {
    iVar11 = **(int **)(param_5 + 0x100);
    FUN_005bc5b0(*(undefined4 *)(iVar11 + 4),*(undefined4 *)(iVar11 + 8));
  }
  if (((DAT_00a3d360 != 0) || (DAT_00ef72cc != 0)) || (DAT_00ef72c8 != param_7)) {
    FUN_005bcf50();
  }
  fVar8 = DAT_00f07344;
  fVar1 = DAT_00a381a8;
  fVar5 = DAT_00a380b8;
  local_98 = *(int *)(param_5 + 0x88);
  local_38 = 0;
  if ((param_6 != 0) && (local_38 = (uint)(*(int *)(param_6 + 0x88) != local_98), param_6 != 0)) {
    local_9c = (int *)(param_6 + 0x8c);
  }
  if ((int)((*(int *)(param_5 + 0x60) - DAT_00a3819c) + -1 + param_1 &
            param_2 + -1 + (*(int *)(param_5 + 100) - DAT_00a381a0) & (DAT_00a38198 - param_2) - 1U
           & (DAT_00a38194 - param_1) - 1U) < 0) {
    if (DAT_00f0733c == 2) {
      if (0 < local_98) {
        local_9c = (int *)((int)local_9c + 0x74);
        pfVar12 = (float *)(param_5 + 0xc0);
        do {
          FUN_005bc5b0(*(undefined4 *)(*(int *)pfVar12[0x10] + 4),
                       *(undefined4 *)(*(int *)pfVar12[0x10] + 8));
          piVar3 = (int *)*local_9c;
          FUN_005bc640(*(undefined4 *)(*piVar3 + 4),*(undefined4 *)(*piVar3 + 8),piVar3[5],piVar3[6]
                      );
          if (DAT_00ef72e8 != 0) {
            FUN_005bbac0();
          }
          if (DAT_00dda46c != 0) {
            FUN_00584d70();
          }
          if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
             (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <=
              DAT_00f07334 + 6)) {
            FUN_005c3310(0,0);
            DAT_00f07340 = 4;
          }
          pfVar10 = DAT_00f0732c;
          DAT_00f0732c[4] = fVar8;
          pfVar10[0xe] = fVar8;
          pfVar10[0x18] = fVar8;
          pfVar10[0x22] = fVar8;
          pfVar10[0x2c] = fVar8;
          pfVar10[0x36] = fVar8;
          *pfVar10 = param_3 + pfVar12[-1];
          pfVar10[1] = param_4 + *pfVar12;
          pfVar10[10] = param_3 + pfVar12[3];
          pfVar10[0xb] = *pfVar12 + param_4;
          pfVar10[0x14] = pfVar12[-1] + param_3;
          pfVar10[0x15] = pfVar12[8] + param_4;
          pfVar10[0x1e] = param_3 + pfVar12[3];
          pfVar10[0x1f] = pfVar12[8] + param_4;
          pfVar10[0x28] = pfVar12[-1] + param_3;
          pfVar10[0x29] = pfVar12[8] + param_4;
          pfVar10[0x32] = param_3 + pfVar12[3];
          pfVar10[0x33] = *pfVar12 + param_4;
          if (DAT_00a380e8 == 1) {
            local_a4 = ((pfVar12[-1] + param_3) - (float)local_9c[-0x11]) - (float)_DAT_00a380e0;
            local_a0 = ((pfVar12[3] + param_3) - (float)local_9c[-0x11]) - (float)_DAT_00a380e0;
            local_70 = ((*pfVar12 + param_4) - (float)local_9c[-0x10]) - (float)_DAT_00a380e4;
            local_6c = ((pfVar12[8] + param_4) - (float)local_9c[-0x10]) - (float)_DAT_00a380e4;
          }
          else {
            local_a4 = (float)_DAT_00a380e0 + (pfVar12[-1] - (float)local_9c[-0x11]);
            local_a0 = (pfVar12[3] - (float)local_9c[-0x11]) + (float)_DAT_00a380e0;
            local_70 = (float)_DAT_00a380e4 + (*pfVar12 - (float)local_9c[-0x10]);
            local_6c = (pfVar12[8] - (float)local_9c[-0x10]) + (float)_DAT_00a380e4;
          }
          local_a4 = _DAT_00ef730c * local_a4;
          local_a0 = _DAT_00ef730c * local_a0;
          local_70 = _DAT_00ef7310 * local_70;
          local_6c = _DAT_00ef7310 * local_6c;
          pfVar10[6] = local_a4;
          pfVar10[7] = local_70;
          pfVar10[0x10] = local_a0;
          pfVar10[0x11] = local_70;
          pfVar10[0x1a] = local_a4;
          pfVar10[0x1b] = local_6c;
          pfVar10[0x25] = local_6c;
          pfVar10[0x2f] = local_6c;
          pfVar10[0x24] = local_a0;
          pfVar10[0x38] = local_a0;
          pfVar10[0x2e] = local_a4;
          pfVar10[0x39] = local_70;
          pfVar10[8] = pfVar12[1];
          pfVar10[9] = pfVar12[2];
          pfVar10[0x12] = pfVar12[5];
          pfVar10[0x13] = pfVar12[2];
          pfVar10[0x1c] = pfVar12[1];
          pfVar10[0x1d] = pfVar12[10];
          pfVar10[0x26] = pfVar12[5];
          pfVar10[0x27] = pfVar12[10];
          pfVar10[0x30] = pfVar12[1];
          pfVar10[0x31] = pfVar12[10];
          pfVar10[0x3a] = pfVar12[5];
          fVar1 = pfVar12[2];
          pfVar10[2] = fVar5;
          pfVar10[0x3b] = fVar1;
          pfVar10[0xc] = fVar5;
          pfVar10[0x16] = fVar5;
          pfVar10[3] = 1.0;
          pfVar10[0x20] = fVar5;
          pfVar10[0xd] = 1.0;
          pfVar10[0x2a] = fVar5;
          pfVar10[0x17] = 1.0;
          pfVar10[0x34] = fVar5;
          pfVar10[0x21] = 1.0;
          pfVar10[0x2b] = 1.0;
          pfVar10[0x35] = 1.0;
          DAT_00f0732c = DAT_00f0732c + 0x3c;
          DAT_00f07334 = DAT_00f07334 + 6;
          if (local_38 == 0) {
            local_9c = local_9c + 0x1e;
          }
          pfVar12 = pfVar12 + 0x1e;
          local_98 = local_98 + -1;
        } while (local_98 != 0);
      }
    }
    else {
      iVar11 = 0;
      pfVar12 = (float *)(param_5 + 0xcc);
      while( true ) {
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
           (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <=
            DAT_00f07334 + 6)) {
          FUN_005c3310(0,0);
          DAT_00f07340 = 4;
        }
        pfVar10 = DAT_00f0732c;
        DAT_00f0732c[4] = fVar8;
        pfVar10[0xb] = fVar8;
        pfVar10[0x12] = fVar8;
        pfVar10[0x19] = fVar8;
        pfVar10[0x20] = fVar8;
        pfVar10[0x27] = fVar8;
        *pfVar10 = pfVar12[-4] + param_3;
        pfVar10[1] = pfVar12[-3] + param_4;
        pfVar10[7] = *pfVar12 + param_3;
        pfVar10[8] = pfVar12[-3] + param_4;
        pfVar10[0xe] = pfVar12[-4] + param_3;
        pfVar10[0xf] = pfVar12[5] + param_4;
        pfVar10[0x15] = *pfVar12 + param_3;
        pfVar10[0x16] = pfVar12[5] + param_4;
        pfVar10[0x1c] = pfVar12[-4] + param_3;
        pfVar10[0x1d] = pfVar12[5] + param_4;
        pfVar10[0x23] = *pfVar12 + param_3;
        pfVar10[0x24] = pfVar12[-3] + param_4;
        pfVar10[5] = pfVar12[-2];
        pfVar10[6] = pfVar12[-1];
        pfVar10[0xc] = pfVar12[2];
        pfVar10[0xd] = pfVar12[-1];
        pfVar10[0x13] = pfVar12[-2];
        pfVar10[0x14] = pfVar12[7];
        pfVar10[0x1a] = pfVar12[2];
        pfVar10[0x1b] = pfVar12[7];
        pfVar10[0x21] = pfVar12[-2];
        pfVar10[0x22] = pfVar12[7];
        pfVar10[0x28] = pfVar12[2];
        fVar1 = pfVar12[-1];
        pfVar10[2] = fVar5;
        pfVar10[0x29] = fVar1;
        pfVar10[9] = fVar5;
        pfVar10[0x10] = fVar5;
        pfVar10[3] = 1.0;
        pfVar10[0x17] = fVar5;
        pfVar10[10] = 1.0;
        pfVar10[0x1e] = fVar5;
        pfVar10[0x11] = 1.0;
        pfVar10[0x25] = fVar5;
        pfVar10[0x18] = 1.0;
        pfVar10[0x1f] = 1.0;
        pfVar10[0x26] = 1.0;
        DAT_00f0732c = DAT_00f0732c + 0x2a;
        DAT_00f07334 = DAT_00f07334 + 6;
        iVar11 = iVar11 + 1;
        if (local_98 <= iVar11) break;
        pfVar10 = pfVar12 + 0x2b;
        pfVar12 = pfVar12 + 0x1e;
        FUN_005bc5b0(*(undefined4 *)(*(int *)*pfVar10 + 4),*(undefined4 *)(*(int *)*pfVar10 + 8));
        FUN_005bbac0();
      }
    }
  }
  else if (-1 < (int)((*(int *)(param_5 + 0x60) - DAT_00a38194) + -1 + param_1 &
                      (*(int *)(param_5 + 100) - DAT_00a38198) + -1 + param_2 &
                      (DAT_00a381a0 - param_2) - 1U & (DAT_00a3819c - param_1) - 1U)) {
    local_68 = DAT_00a381a4;
    local_3c = DAT_00a381ac;
    local_40 = DAT_00a381b0;
    if (DAT_00f0733c == 1) {
      local_64 = 0;
      pfVar12 = (float *)(param_5 + 0xcc);
      while( true ) {
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
           (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <=
            DAT_00f07334 + 6)) {
          FUN_005c3310(0,0);
          DAT_00f07340 = 4;
        }
        pfVar9 = DAT_00f0732c;
        DAT_00f0732c[4] = fVar8;
        pfVar9[0xb] = fVar8;
        pfVar9[0x12] = fVar8;
        pfVar9[0x19] = fVar8;
        pfVar9[0x20] = fVar8;
        pfVar9[0x27] = fVar8;
        pfVar10 = local_2c;
        iVar11 = 0;
        local_30 = param_3 + pfVar12[-4];
        local_2c[0] = param_4 + pfVar12[-3];
        local_24 = *pfVar12 + param_3;
        local_20 = param_4 + pfVar12[-3];
        local_18 = param_3 + pfVar12[-4];
        local_14 = param_4 + pfVar12[5];
        local_8 = param_4 + pfVar12[5];
        local_c = *pfVar12 + param_3;
        local_90[0] = pfVar12[-2];
        local_90[2] = pfVar12[-2];
        local_90[1] = pfVar12[2];
        local_90[3] = pfVar12[2];
        local_80[0] = pfVar12[-1];
        local_80[1] = pfVar12[-1];
        local_80[2] = pfVar12[7];
        local_80[3] = pfVar12[7];
        local_34 = 1.0 / (float)*(int *)((int)pfVar12[0xd] + 0x14);
        fVar4 = 1.0 / (float)*(int *)((int)pfVar12[0xd] + 0x18);
        do {
          if (local_68 <= pfVar10[-1]) {
            if (local_3c < pfVar10[-1]) {
              *(float *)((int)local_90 + iVar11) =
                   *(float *)((int)local_90 + iVar11) - local_34 * (pfVar10[-1] - local_3c);
              pfVar10[-1] = local_3c;
            }
          }
          else {
            *(float *)((int)local_90 + iVar11) =
                 (local_68 - pfVar10[-1]) * local_34 + *(float *)((int)local_90 + iVar11);
            pfVar10[-1] = local_68;
          }
          if (fVar1 <= *pfVar10) {
            if (local_40 < *pfVar10) {
              *(float *)((int)local_80 + iVar11) =
                   *(float *)((int)local_80 + iVar11) - fVar4 * (*pfVar10 - local_40);
              *pfVar10 = local_40;
            }
          }
          else {
            *(float *)((int)local_80 + iVar11) =
                 (fVar1 - *pfVar10) * fVar4 + *(float *)((int)local_80 + iVar11);
            *pfVar10 = fVar1;
          }
          iVar11 = iVar11 + 4;
          pfVar10 = pfVar10 + 3;
        } while (iVar11 < 0x10);
        pfVar9[2] = fVar5;
        pfVar9[9] = fVar5;
        pfVar9[0x10] = fVar5;
        pfVar9[0x17] = fVar5;
        *pfVar9 = local_30;
        pfVar9[0x1e] = fVar5;
        pfVar9[0x25] = fVar5;
        pfVar9[1] = local_2c[0];
        local_64 = local_64 + 1;
        pfVar9[7] = local_24;
        pfVar9[8] = local_20;
        pfVar9[0xe] = local_18;
        pfVar9[0xf] = local_14;
        pfVar9[0x15] = local_c;
        pfVar9[0x16] = local_8;
        pfVar9[0x1c] = local_18;
        pfVar9[0x1d] = local_14;
        pfVar9[0x23] = local_24;
        pfVar9[0x24] = local_20;
        pfVar9[5] = local_90[0];
        pfVar9[6] = local_80[0];
        pfVar9[0xc] = local_90[1];
        pfVar9[0xd] = local_80[1];
        pfVar9[0x13] = local_90[2];
        pfVar9[0x14] = local_80[2];
        pfVar9[0x1a] = local_90[3];
        pfVar9[0x1b] = local_80[3];
        pfVar9[0x21] = local_90[2];
        pfVar9[0x22] = local_80[2];
        pfVar9[0x28] = local_90[1];
        pfVar9[0x29] = local_80[1];
        pfVar9[3] = 1.0;
        pfVar9[10] = 1.0;
        pfVar9[0x11] = 1.0;
        pfVar9[0x18] = 1.0;
        pfVar9[0x1f] = 1.0;
        pfVar9[0x26] = 1.0;
        DAT_00f0732c = DAT_00f0732c + 0x2a;
        DAT_00f07334 = DAT_00f07334 + 6;
        if (local_98 <= local_64) break;
        pfVar10 = pfVar12 + 0x2b;
        pfVar12 = pfVar12 + 0x1e;
        FUN_005bc5b0(*(undefined4 *)(*(int *)*pfVar10 + 4),*(undefined4 *)(*(int *)*pfVar10 + 8));
        FUN_005bbac0();
      }
    }
    else if ((DAT_00f0733c == 2) && (0 < local_98)) {
      local_9c = (int *)((int)local_9c + 0x74);
      pfVar12 = (float *)(param_5 + 0xcc);
      local_64 = local_98;
      do {
        FUN_005bc5b0(*(undefined4 *)(*(int *)pfVar12[0xd] + 4),
                     *(undefined4 *)(*(int *)pfVar12[0xd] + 8));
        piVar3 = (int *)*local_9c;
        FUN_005bc640(*(undefined4 *)(*piVar3 + 4),*(undefined4 *)(*piVar3 + 8),piVar3[5],piVar3[6]);
        if (DAT_00ef72e8 != 0) {
          FUN_005bbac0();
        }
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
           (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <=
            DAT_00f07334 + 6)) {
          FUN_005c3310(0,0);
          DAT_00f07340 = 4;
        }
        pfVar10 = DAT_00f0732c;
        fVar7 = _DAT_00ef7310;
        fVar6 = _DAT_00ef730c;
        local_34 = 1.0 / (float)*(int *)((int)pfVar12[0xd] + 0x14);
        fVar4 = 1.0 / (float)*(int *)((int)pfVar12[0xd] + 0x18);
        local_70 = _DAT_00ef730c;
        DAT_00f0732c[4] = fVar8;
        pfVar10[0xe] = fVar8;
        pfVar10[0x18] = fVar8;
        pfVar10[0x22] = fVar8;
        pfVar10[0x2c] = fVar8;
        pfVar10[0x36] = fVar8;
        local_30 = param_3 + pfVar12[-4];
        local_2c[0] = param_4 + pfVar12[-3];
        local_24 = *pfVar12 + param_3;
        local_20 = param_4 + pfVar12[-3];
        local_18 = local_30;
        local_14 = param_4 + pfVar12[5];
        local_8 = param_4 + pfVar12[5];
        local_c = *pfVar12 + param_3;
        local_80[0] = pfVar12[-2];
        local_80[2] = pfVar12[-2];
        local_80[1] = pfVar12[2];
        local_80[3] = pfVar12[2];
        local_90[0] = pfVar12[-1];
        local_90[1] = pfVar12[-1];
        local_90[2] = pfVar12[7];
        local_90[3] = pfVar12[7];
        if (DAT_00a380e8 == 1) {
          local_60[0] = _DAT_00ef730c * ((local_30 - (float)local_9c[-0x11]) - (float)_DAT_00a380e0)
          ;
          local_60[2] = local_60[0];
          local_60[1] = (((*pfVar12 + param_3) - (float)local_9c[-0x11]) - (float)_DAT_00a380e0) *
                        _DAT_00ef730c;
          local_60[3] = local_60[1];
          local_50[0] = _DAT_00ef7310 *
                        (((pfVar12[-3] + param_4) - (float)local_9c[-0x10]) - (float)_DAT_00a380e4);
          local_50[1] = local_50[0];
          fVar2 = ((pfVar12[5] + param_4) - (float)local_9c[-0x10]) - (float)_DAT_00a380e4;
        }
        else {
          local_60[0] = _DAT_00ef730c *
                        ((float)_DAT_00a380e0 + (pfVar12[-4] - (float)local_9c[-0x11]));
          local_60[2] = local_60[0];
          local_60[1] = ((*pfVar12 - (float)local_9c[-0x11]) + (float)_DAT_00a380e0) * _DAT_00ef730c
          ;
          local_60[3] = local_60[1];
          local_50[0] = _DAT_00ef7310 *
                        ((float)_DAT_00a380e4 + (pfVar12[-3] - (float)local_9c[-0x10]));
          local_50[1] = local_50[0];
          fVar2 = (pfVar12[5] - (float)local_9c[-0x10]) + (float)_DAT_00a380e4;
        }
        local_50[2] = fVar2 * _DAT_00ef7310;
        pfVar9 = local_2c;
        iVar11 = 0;
        local_50[3] = fVar2 * _DAT_00ef7310;
        local_60[0] = local_60[2];
        local_60[1] = local_60[3];
        local_50[0] = local_50[1];
        do {
          if (local_68 <= pfVar9[-1]) {
            if (local_3c < pfVar9[-1]) {
              fVar2 = pfVar9[-1];
              *(float *)((int)local_80 + iVar11) =
                   *(float *)((int)local_80 + iVar11) - local_34 * (fVar2 - local_3c);
              *(float *)((int)local_60 + iVar11) =
                   *(float *)((int)local_60 + iVar11) - fVar6 * (fVar2 - local_3c);
              pfVar9[-1] = local_3c;
            }
          }
          else {
            fVar2 = pfVar9[-1];
            *(float *)((int)local_80 + iVar11) =
                 local_34 * (local_68 - fVar2) + *(float *)((int)local_80 + iVar11);
            *(float *)((int)local_60 + iVar11) =
                 (local_68 - fVar2) * fVar6 + *(float *)((int)local_60 + iVar11);
            pfVar9[-1] = local_68;
          }
          if (fVar1 <= *pfVar9) {
            if (local_40 < *pfVar9) {
              fVar2 = *pfVar9;
              *(float *)((int)local_90 + iVar11) =
                   *(float *)((int)local_90 + iVar11) - fVar4 * (fVar2 - local_40);
              *(float *)((int)local_50 + iVar11) =
                   *(float *)((int)local_50 + iVar11) - fVar7 * (fVar2 - local_40);
              *pfVar9 = local_40;
            }
          }
          else {
            fVar2 = *pfVar9;
            *(float *)((int)local_90 + iVar11) =
                 fVar4 * (fVar1 - fVar2) + *(float *)((int)local_90 + iVar11);
            *(float *)((int)local_50 + iVar11) =
                 (fVar1 - fVar2) * fVar7 + *(float *)((int)local_50 + iVar11);
            *pfVar9 = fVar1;
          }
          iVar11 = iVar11 + 4;
          pfVar9 = pfVar9 + 3;
        } while (iVar11 < 0x10);
        pfVar10[2] = fVar5;
        pfVar10[0xc] = fVar5;
        pfVar10[0x16] = fVar5;
        pfVar10[0x20] = fVar5;
        pfVar10[0x2a] = fVar5;
        pfVar10[0x34] = fVar5;
        *pfVar10 = local_30;
        pfVar10[1] = local_2c[0];
        pfVar10[10] = local_24;
        pfVar10[0xb] = local_20;
        pfVar10[0x14] = local_18;
        pfVar10[0x15] = local_14;
        pfVar10[0x1e] = local_c;
        pfVar10[0x1f] = local_8;
        pfVar10[0x28] = local_18;
        pfVar10[0x29] = local_14;
        pfVar10[0x32] = local_24;
        pfVar10[0x33] = local_20;
        pfVar10[6] = local_60[0];
        pfVar10[7] = local_50[0];
        pfVar10[0x10] = local_60[1];
        pfVar10[0x11] = local_50[1];
        pfVar10[0x1a] = local_60[2];
        pfVar10[0x1b] = local_50[2];
        pfVar10[0x24] = local_60[3];
        pfVar10[0x25] = local_50[3];
        pfVar10[0x2e] = local_60[2];
        pfVar10[0x2f] = local_50[2];
        pfVar10[0x38] = local_60[1];
        pfVar10[0x39] = local_50[1];
        pfVar10[8] = local_80[0];
        pfVar10[9] = local_90[0];
        pfVar10[0x12] = local_80[1];
        pfVar10[0x13] = local_90[1];
        pfVar10[0x1c] = local_80[2];
        pfVar10[0x1d] = local_90[2];
        pfVar10[0x26] = local_80[3];
        pfVar10[0x27] = local_90[3];
        pfVar10[0x30] = local_80[2];
        pfVar10[0x31] = local_90[2];
        pfVar10[0x3a] = local_80[1];
        pfVar10[0x3b] = local_90[1];
        pfVar10[3] = 1.0;
        pfVar10[0xd] = 1.0;
        pfVar10[0x17] = 1.0;
        pfVar10[0x21] = 1.0;
        pfVar10[0x2b] = 1.0;
        pfVar10[0x35] = 1.0;
        DAT_00f0732c = DAT_00f0732c + 0x3c;
        DAT_00f07334 = DAT_00f07334 + 6;
        if (local_38 == 0) {
          local_9c = local_9c + 0x1e;
        }
        pfVar12 = pfVar12 + 0x1e;
        local_64 = local_64 + -1;
      } while (local_64 != 0);
      return 0;
    }
  }
  return 0;
}

