
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005c4530(int param_1,int param_2,int param_3,int param_4,float param_5,float param_6,
            float param_7,float param_8,int param_9,int param_10,uint param_11,int param_12)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  float *pfVar13;
  float *pfVar14;
  int iVar15;
  float *pfVar16;
  int *local_bc;
  int local_a8;
  float local_a0 [4];
  float local_90 [4];
  float local_80;
  float local_7c;
  float local_78;
  int local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60 [4];
  float local_50 [4];
  float local_40;
  float local_3c;
  float local_38;
  uint local_34;
  float local_30;
  float local_2c [2];
  float local_24;
  float local_20;
  float local_18;
  float local_14;
  float local_c;
  float local_8;
  
  iVar10 = param_3;
  iVar15 = param_2;
  local_bc = (int *)0x0;
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((param_1 == param_3) || (param_2 == param_4)) {
    return 0xffffffff;
  }
  if (param_12 == 0) {
    uVar11 = 0;
  }
  else {
    uVar11 = -(uint)(DAT_00a380bc != 1) & 2;
  }
  uVar12 = uVar11 | param_11 | 0x8000;
  if (*(char *)(*(int *)(param_9 + 0x4c) + 10) != '\0') {
    uVar12 = uVar11 | param_11 | 0x18000;
  }
  if (*(char *)(*(int *)(param_9 + 0x4c) + 0x12) != '\0') {
    uVar12 = uVar12 | 0x20000;
  }
  if (DAT_00ef7314 != *(int *)(**(int **)(param_9 + 0x100) + 4)) {
    iVar3 = **(int **)(param_9 + 0x100);
    FUN_005bc5b0(*(undefined4 *)(iVar3 + 4),*(undefined4 *)(iVar3 + 8));
  }
  if (((DAT_00a3d360 != 0) || (DAT_00ef72cc != 0)) || (DAT_00ef72c8 != uVar12)) {
    FUN_005bcf50();
  }
  fVar9 = DAT_00f07344;
  fVar1 = DAT_00a381a8;
  fVar8 = DAT_00a380b8;
  local_a8 = *(int *)(param_9 + 0x88);
  local_34 = 0;
  if ((param_10 != 0) && (local_34 = (uint)(*(int *)(param_10 + 0x88) != local_a8), param_10 != 0))
  {
    local_bc = (int *)(param_10 + 0x8c);
  }
  local_64 = (param_7 - param_5) / *(float *)(param_9 + 0x68);
  local_70 = (param_8 - param_6) / *(float *)(param_9 + 0x6c);
  if (param_3 < param_1) {
    param_3 = param_1;
    param_1 = iVar10;
  }
  if (param_4 < param_2) {
    param_2 = param_4;
    param_4 = iVar15;
  }
  if ((int)((param_4 - DAT_00a381a0) - 1U & (param_3 - DAT_00a3819c) - 1U &
            (DAT_00a38198 - param_2) - 1U & (DAT_00a38194 - param_1) - 1U) < 0) {
    if (DAT_00f0733c == 1) {
      iVar15 = 0;
      pfVar16 = (float *)(param_9 + 0xc4);
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
        pfVar14 = DAT_00f0732c;
        DAT_00f0732c[4] = fVar9;
        pfVar14[0xb] = fVar9;
        pfVar14[0x12] = fVar9;
        pfVar14[0x19] = fVar9;
        pfVar14[0x20] = fVar9;
        pfVar14[0x27] = fVar9;
        fVar1 = param_5 + local_64 * pfVar16[-2];
        fVar5 = local_64 * pfVar16[2] + param_5;
        fVar7 = param_6 + local_70 * pfVar16[-1];
        fVar6 = param_6 + pfVar16[7] * local_70;
        *pfVar14 = fVar1;
        pfVar14[1] = fVar7;
        pfVar14[7] = fVar5;
        pfVar14[8] = fVar7;
        pfVar14[0xe] = fVar1;
        pfVar14[0xf] = fVar6;
        pfVar14[0x16] = fVar6;
        pfVar14[0x1d] = fVar6;
        pfVar14[0x15] = fVar5;
        pfVar14[0x23] = fVar5;
        pfVar14[0x1c] = fVar1;
        pfVar14[0x24] = fVar7;
        pfVar14[5] = *pfVar16;
        pfVar14[6] = pfVar16[1];
        pfVar14[0xc] = pfVar16[4];
        pfVar14[0xd] = pfVar16[1];
        pfVar14[0x13] = *pfVar16;
        pfVar14[0x14] = pfVar16[9];
        pfVar14[0x1a] = pfVar16[4];
        pfVar14[0x1b] = pfVar16[9];
        pfVar14[0x21] = *pfVar16;
        pfVar14[0x22] = pfVar16[9];
        pfVar14[0x28] = pfVar16[4];
        fVar1 = pfVar16[1];
        pfVar14[2] = fVar8;
        pfVar14[0x29] = fVar1;
        pfVar14[9] = fVar8;
        pfVar14[0x10] = fVar8;
        pfVar14[3] = 1.0;
        pfVar14[0x17] = fVar8;
        pfVar14[0x1e] = fVar8;
        pfVar14[0x25] = fVar8;
        pfVar14[10] = 1.0;
        iVar15 = iVar15 + 1;
        pfVar14[0x11] = 1.0;
        pfVar14[0x18] = 1.0;
        pfVar14[0x1f] = 1.0;
        pfVar14[0x26] = 1.0;
        DAT_00f0732c = DAT_00f0732c + 0x2a;
        DAT_00f07334 = DAT_00f07334 + 6;
        if (local_a8 <= iVar15) break;
        pfVar14 = pfVar16 + 0x2d;
        pfVar16 = pfVar16 + 0x1e;
        FUN_005bc5b0(*(undefined4 *)(*(int *)*pfVar14 + 4),*(undefined4 *)(*(int *)*pfVar14 + 8));
        FUN_005bbac0();
      }
    }
    else if ((DAT_00f0733c == 2) && (0 < local_a8)) {
      local_bc = (int *)((int)local_bc + 0x74);
      pfVar16 = (float *)(param_9 + 0xc0);
      do {
        FUN_005bc5b0(*(undefined4 *)(*(int *)pfVar16[0x10] + 4),
                     *(undefined4 *)(*(int *)pfVar16[0x10] + 8));
        piVar4 = (int *)*local_bc;
        FUN_005bc640(*(undefined4 *)(*piVar4 + 4),*(undefined4 *)(*piVar4 + 8),piVar4[5],piVar4[6]);
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
        pfVar14 = DAT_00f0732c;
        DAT_00f0732c[4] = fVar9;
        pfVar14[0xe] = fVar9;
        pfVar14[0x18] = fVar9;
        pfVar14[0x22] = fVar9;
        pfVar14[0x2c] = fVar9;
        pfVar14[0x36] = fVar9;
        fVar1 = param_5 + local_64 * pfVar16[-1];
        fVar5 = local_64 * pfVar16[3] + param_5;
        fVar6 = param_6 + local_70 * *pfVar16;
        fVar7 = local_70 * pfVar16[8] + param_6;
        *pfVar14 = fVar1;
        pfVar14[1] = fVar6;
        pfVar14[10] = fVar5;
        pfVar14[0xb] = fVar6;
        pfVar14[0x14] = fVar1;
        pfVar14[0x15] = fVar7;
        pfVar14[0x1f] = fVar7;
        pfVar14[0x29] = fVar7;
        pfVar14[0x1e] = fVar5;
        pfVar14[0x32] = fVar5;
        pfVar14[0x28] = fVar1;
        pfVar14[0x33] = fVar6;
        if (DAT_00a380e8 == 1) {
          local_6c = (fVar1 - (float)local_bc[-0x11]) - (float)_DAT_00a380e0;
          local_68 = (fVar5 - (float)local_bc[-0x11]) - (float)_DAT_00a380e0;
          local_80 = (fVar6 - (float)local_bc[-0x10]) - (float)_DAT_00a380e4;
          local_7c = (fVar7 - (float)local_bc[-0x10]) - (float)_DAT_00a380e4;
        }
        else {
          local_6c = (float)_DAT_00a380e0 + (pfVar16[-1] - (float)local_bc[-0x11]);
          local_68 = (pfVar16[3] - (float)local_bc[-0x11]) + (float)_DAT_00a380e0;
          local_80 = (float)_DAT_00a380e4 + (*pfVar16 - (float)local_bc[-0x10]);
          local_7c = (pfVar16[8] - (float)local_bc[-0x10]) + (float)_DAT_00a380e4;
        }
        local_6c = _DAT_00ef730c * local_6c;
        local_68 = _DAT_00ef730c * local_68;
        local_80 = _DAT_00ef7310 * local_80;
        local_7c = _DAT_00ef7310 * local_7c;
        pfVar14[6] = local_6c;
        pfVar14[7] = local_80;
        pfVar14[0x10] = local_68;
        pfVar14[0x11] = local_80;
        pfVar14[0x1a] = local_6c;
        pfVar14[0x1b] = local_7c;
        pfVar14[0x25] = local_7c;
        pfVar14[0x2f] = local_7c;
        pfVar14[0x24] = local_68;
        pfVar14[0x38] = local_68;
        pfVar14[0x2e] = local_6c;
        pfVar14[0x39] = local_80;
        pfVar14[8] = pfVar16[1];
        pfVar14[9] = pfVar16[2];
        pfVar14[0x12] = pfVar16[5];
        pfVar14[0x13] = pfVar16[2];
        pfVar14[0x1c] = pfVar16[1];
        pfVar14[0x1d] = pfVar16[10];
        pfVar14[0x26] = pfVar16[5];
        pfVar14[0x27] = pfVar16[10];
        pfVar14[0x30] = pfVar16[1];
        pfVar14[0x31] = pfVar16[10];
        pfVar14[0x3a] = pfVar16[5];
        fVar1 = pfVar16[2];
        pfVar14[2] = fVar8;
        pfVar14[0x3b] = fVar1;
        pfVar14[0xc] = fVar8;
        pfVar14[0x16] = fVar8;
        pfVar14[3] = 1.0;
        pfVar14[0x20] = fVar8;
        pfVar14[0xd] = 1.0;
        pfVar14[0x2a] = fVar8;
        pfVar14[0x17] = 1.0;
        pfVar14[0x34] = fVar8;
        pfVar14[0x21] = 1.0;
        pfVar14[0x2b] = 1.0;
        pfVar14[0x35] = 1.0;
        DAT_00f0732c = DAT_00f0732c + 0x3c;
        DAT_00f07334 = DAT_00f07334 + 6;
        if (local_34 == 0) {
          local_bc = local_bc + 0x1e;
        }
        pfVar16 = pfVar16 + 0x1e;
        local_a8 = local_a8 + -1;
      } while (local_a8 != 0);
    }
  }
  else if (-1 < (int)((param_4 - DAT_00a38198) - 1U & (param_3 - DAT_00a38194) - 1U &
                      (DAT_00a381a0 - param_2) - 1U & (DAT_00a3819c - param_1) - 1U)) {
    local_78 = DAT_00a381a4;
    local_3c = DAT_00a381ac;
    local_40 = DAT_00a381b0;
    if (DAT_00f0733c == 1) {
      local_74 = 0;
      pfVar16 = (float *)(param_9 + 0xc0);
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
        pfVar13 = DAT_00f0732c;
        DAT_00f0732c[4] = fVar9;
        pfVar13[0xb] = fVar9;
        pfVar13[0x12] = fVar9;
        pfVar13[0x19] = fVar9;
        pfVar13[0x20] = fVar9;
        pfVar13[0x27] = fVar9;
        pfVar14 = local_2c;
        iVar15 = 0;
        local_30 = param_5 + local_64 * pfVar16[-1];
        local_24 = pfVar16[3] * local_64 + param_5;
        local_2c[0] = param_6 + local_70 * *pfVar16;
        local_14 = local_70 * pfVar16[8] + param_6;
        local_20 = local_2c[0];
        local_18 = local_30;
        local_8 = local_14;
        local_c = local_24;
        local_a0[0] = pfVar16[1];
        local_a0[2] = pfVar16[1];
        local_a0[1] = pfVar16[5];
        local_a0[3] = pfVar16[5];
        local_90[0] = pfVar16[2];
        local_90[1] = pfVar16[2];
        local_90[2] = pfVar16[10];
        local_90[3] = pfVar16[10];
        local_38 = 1.0 / (local_64 * (float)*(int *)((int)pfVar16[0x10] + 0x14));
        fVar5 = 1.0 / ((float)*(int *)((int)pfVar16[0x10] + 0x18) * local_70);
        do {
          if (local_78 <= pfVar14[-1]) {
            if (local_3c < pfVar14[-1]) {
              *(float *)((int)local_a0 + iVar15) =
                   *(float *)((int)local_a0 + iVar15) - local_38 * (pfVar14[-1] - local_3c);
              pfVar14[-1] = local_3c;
            }
          }
          else {
            *(float *)((int)local_a0 + iVar15) =
                 (local_78 - pfVar14[-1]) * local_38 + *(float *)((int)local_a0 + iVar15);
            pfVar14[-1] = local_78;
          }
          if (fVar1 <= *pfVar14) {
            if (local_40 < *pfVar14) {
              *(float *)((int)local_90 + iVar15) =
                   *(float *)((int)local_90 + iVar15) - fVar5 * (*pfVar14 - local_40);
              *pfVar14 = local_40;
            }
          }
          else {
            *(float *)((int)local_90 + iVar15) =
                 (fVar1 - *pfVar14) * fVar5 + *(float *)((int)local_90 + iVar15);
            *pfVar14 = fVar1;
          }
          iVar15 = iVar15 + 4;
          pfVar14 = pfVar14 + 3;
        } while (iVar15 < 0x10);
        pfVar13[2] = fVar8;
        pfVar13[9] = fVar8;
        pfVar13[0x10] = fVar8;
        pfVar13[0x17] = fVar8;
        *pfVar13 = local_30;
        pfVar13[0x1e] = fVar8;
        pfVar13[0x25] = fVar8;
        pfVar13[1] = local_2c[0];
        local_74 = local_74 + 1;
        pfVar13[7] = local_24;
        pfVar13[8] = local_20;
        pfVar13[0xe] = local_18;
        pfVar13[0xf] = local_14;
        pfVar13[0x15] = local_c;
        pfVar13[0x16] = local_8;
        pfVar13[0x1c] = local_18;
        pfVar13[0x1d] = local_14;
        pfVar13[0x23] = local_24;
        pfVar13[0x24] = local_20;
        pfVar13[5] = local_a0[0];
        pfVar13[6] = local_90[0];
        pfVar13[0xc] = local_a0[1];
        pfVar13[0xd] = local_90[1];
        pfVar13[0x13] = local_a0[2];
        pfVar13[0x14] = local_90[2];
        pfVar13[0x1a] = local_a0[3];
        pfVar13[0x1b] = local_90[3];
        pfVar13[0x21] = local_a0[2];
        pfVar13[0x22] = local_90[2];
        pfVar13[0x28] = local_a0[1];
        pfVar13[0x29] = local_90[1];
        pfVar13[3] = 1.0;
        pfVar13[10] = 1.0;
        pfVar13[0x11] = 1.0;
        pfVar13[0x18] = 1.0;
        pfVar13[0x1f] = 1.0;
        pfVar13[0x26] = 1.0;
        DAT_00f0732c = DAT_00f0732c + 0x2a;
        DAT_00f07334 = DAT_00f07334 + 6;
        if (local_a8 <= local_74) break;
        pfVar14 = pfVar16 + 0x2e;
        pfVar16 = pfVar16 + 0x1e;
        FUN_005bc5b0(*(undefined4 *)(*(int *)*pfVar14 + 4),*(undefined4 *)(*(int *)*pfVar14 + 8));
        FUN_005bbac0();
      }
    }
    else if ((DAT_00f0733c == 2) && (0 < local_a8)) {
      local_bc = (int *)((int)local_bc + 0x74);
      pfVar16 = (float *)(param_9 + 0xc0);
      local_74 = local_a8;
      do {
        FUN_005bc5b0(*(undefined4 *)(*(int *)pfVar16[0x10] + 4),
                     *(undefined4 *)(*(int *)pfVar16[0x10] + 8));
        piVar4 = (int *)*local_bc;
        FUN_005bc640(*(undefined4 *)(*piVar4 + 4),*(undefined4 *)(*piVar4 + 8),piVar4[5],piVar4[6]);
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
        pfVar14 = DAT_00f0732c;
        fVar7 = _DAT_00ef7310;
        fVar6 = _DAT_00ef730c;
        local_38 = 1.0 / (local_64 * (float)*(int *)((int)pfVar16[0x10] + 0x14));
        fVar5 = 1.0 / (local_70 * (float)*(int *)((int)pfVar16[0x10] + 0x18));
        local_80 = _DAT_00ef730c;
        local_6c = _DAT_00ef7310;
        DAT_00f0732c[4] = fVar9;
        pfVar14[0xe] = fVar9;
        pfVar14[0x18] = fVar9;
        pfVar14[0x22] = fVar9;
        pfVar14[0x2c] = fVar9;
        pfVar14[0x36] = fVar9;
        local_30 = param_5 + pfVar16[-1] * local_64;
        local_24 = param_5 + pfVar16[3] * local_64;
        local_2c[0] = param_6 + *pfVar16 * local_70;
        local_14 = param_6 + pfVar16[8] * local_70;
        local_20 = local_2c[0];
        local_18 = local_30;
        local_8 = local_14;
        local_c = local_24;
        if (DAT_00a380e8 == 1) {
          local_50[0] = _DAT_00ef730c * ((local_30 - (float)local_bc[-0x11]) - (float)_DAT_00a380e0)
          ;
          local_50[2] = local_50[0];
          local_50[1] = ((local_24 - (float)local_bc[-0x11]) - (float)_DAT_00a380e0) * _DAT_00ef730c
          ;
          local_50[3] = local_50[1];
          local_60[0] = _DAT_00ef7310 *
                        ((local_2c[0] - (float)local_bc[-0x10]) - (float)_DAT_00a380e4);
          local_60[1] = local_60[0];
          fVar2 = (local_14 - (float)local_bc[-0x10]) - (float)_DAT_00a380e4;
        }
        else {
          local_50[0] = _DAT_00ef730c *
                        ((float)_DAT_00a380e0 + (pfVar16[-1] - (float)local_bc[-0x11]));
          local_50[2] = local_50[0];
          local_50[1] = ((pfVar16[3] - (float)local_bc[-0x11]) + (float)_DAT_00a380e0) *
                        _DAT_00ef730c;
          local_50[3] = local_50[1];
          local_60[0] = _DAT_00ef7310 * ((float)_DAT_00a380e4 + (*pfVar16 - (float)local_bc[-0x10]))
          ;
          local_60[1] = local_60[0];
          fVar2 = (pfVar16[8] - (float)local_bc[-0x10]) + (float)_DAT_00a380e4;
        }
        pfVar13 = local_2c;
        iVar15 = 0;
        local_60[2] = fVar2 * _DAT_00ef7310;
        local_60[3] = fVar2 * _DAT_00ef7310;
        local_90[0] = pfVar16[1];
        local_90[2] = pfVar16[1];
        local_90[1] = pfVar16[5];
        local_90[3] = pfVar16[5];
        local_a0[0] = pfVar16[2];
        local_a0[1] = pfVar16[2];
        local_a0[2] = pfVar16[10];
        local_a0[3] = pfVar16[10];
        local_60[0] = local_60[1];
        local_50[0] = local_50[2];
        local_50[1] = local_50[3];
        do {
          if (local_78 <= pfVar13[-1]) {
            if (local_3c < pfVar13[-1]) {
              fVar2 = pfVar13[-1];
              *(float *)((int)local_90 + iVar15) =
                   *(float *)((int)local_90 + iVar15) - local_38 * (fVar2 - local_3c);
              *(float *)((int)local_50 + iVar15) =
                   *(float *)((int)local_50 + iVar15) - fVar6 * (fVar2 - local_3c);
              pfVar13[-1] = local_3c;
            }
          }
          else {
            fVar2 = pfVar13[-1];
            *(float *)((int)local_90 + iVar15) =
                 local_38 * (local_78 - fVar2) + *(float *)((int)local_90 + iVar15);
            *(float *)((int)local_50 + iVar15) =
                 (local_78 - fVar2) * fVar6 + *(float *)((int)local_50 + iVar15);
            pfVar13[-1] = local_78;
          }
          if (fVar1 <= *pfVar13) {
            if (local_40 < *pfVar13) {
              fVar2 = *pfVar13;
              *(float *)((int)local_a0 + iVar15) =
                   *(float *)((int)local_a0 + iVar15) - fVar5 * (fVar2 - local_40);
              *(float *)((int)local_60 + iVar15) =
                   *(float *)((int)local_60 + iVar15) - fVar7 * (fVar2 - local_40);
              *pfVar13 = local_40;
            }
          }
          else {
            fVar2 = *pfVar13;
            *(float *)((int)local_a0 + iVar15) =
                 fVar5 * (fVar1 - fVar2) + *(float *)((int)local_a0 + iVar15);
            *(float *)((int)local_60 + iVar15) =
                 (fVar1 - fVar2) * fVar7 + *(float *)((int)local_60 + iVar15);
            *pfVar13 = fVar1;
          }
          iVar15 = iVar15 + 4;
          pfVar13 = pfVar13 + 3;
        } while (iVar15 < 0x10);
        pfVar14[2] = fVar8;
        pfVar14[0xc] = fVar8;
        pfVar14[0x16] = fVar8;
        pfVar14[0x20] = fVar8;
        pfVar14[0x2a] = fVar8;
        pfVar14[0x34] = fVar8;
        *pfVar14 = local_30;
        pfVar14[1] = local_2c[0];
        pfVar14[10] = local_24;
        pfVar14[0xb] = local_20;
        pfVar14[0x14] = local_18;
        pfVar14[0x15] = local_14;
        pfVar14[0x1e] = local_c;
        pfVar14[0x1f] = local_8;
        pfVar14[0x28] = local_18;
        pfVar14[0x29] = local_14;
        pfVar14[0x32] = local_24;
        pfVar14[0x33] = local_20;
        pfVar14[6] = local_50[0];
        pfVar14[7] = local_60[0];
        pfVar14[0x10] = local_50[1];
        pfVar14[0x11] = local_60[1];
        pfVar14[0x1a] = local_50[2];
        pfVar14[0x1b] = local_60[2];
        pfVar14[0x24] = local_50[3];
        pfVar14[0x25] = local_60[3];
        pfVar14[0x2e] = local_50[2];
        pfVar14[0x2f] = local_60[2];
        pfVar14[0x38] = local_50[1];
        pfVar14[0x39] = local_60[1];
        pfVar14[8] = local_90[0];
        pfVar14[9] = local_a0[0];
        pfVar14[0x12] = local_90[1];
        pfVar14[0x13] = local_a0[1];
        pfVar14[0x1c] = local_90[2];
        pfVar14[0x1d] = local_a0[2];
        pfVar14[0x26] = local_90[3];
        pfVar14[0x27] = local_a0[3];
        pfVar14[0x30] = local_90[2];
        pfVar14[0x31] = local_a0[2];
        pfVar14[0x3a] = local_90[1];
        pfVar14[0x3b] = local_a0[1];
        pfVar14[3] = 1.0;
        pfVar14[0xd] = 1.0;
        pfVar14[0x17] = 1.0;
        pfVar14[0x21] = 1.0;
        pfVar14[0x2b] = 1.0;
        pfVar14[0x35] = 1.0;
        DAT_00f0732c = DAT_00f0732c + 0x3c;
        DAT_00f07334 = DAT_00f07334 + 6;
        if (local_34 == 0) {
          local_bc = local_bc + 0x1e;
        }
        pfVar16 = pfVar16 + 0x1e;
        local_74 = local_74 + -1;
      } while (local_74 != 0);
      return 0;
    }
  }
  return 0;
}

