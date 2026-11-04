
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005a8740(int param_1,int param_2,float param_3,float param_4,int param_5,int param_6,
            uint param_7,uint param_8)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  int iVar8;
  uint uVar9;
  float *pfVar10;
  float *pfVar11;
  float *pfVar12;
  int iVar13;
  int local_a8;
  float local_a4;
  float local_a0;
  int local_9c;
  int local_98;
  float local_94 [4];
  float local_84;
  float local_80 [4];
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
  
  iVar13 = *(int *)(param_5 + 0x4c);
  local_a8 = 0;
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  param_3 = param_3 - (float)_DAT_00804a60;
  param_4 = param_4 - (float)_DAT_00804a60;
  if (((DAT_00e79688 == 0) && (iVar8 = FUN_005d35f0(), iVar8 != 0)) && (DAT_00e79688 != 1)) {
    FUN_005d3930();
    DAT_00e79688 = 1;
    DAT_00e399fc = 0;
  }
  param_7 = (param_8 | 0x4000) * 2 | param_7;
  if (*(char *)(iVar13 + 10) != '\0') {
    param_7 = param_7 | 0x10000;
  }
  if (*(char *)(iVar13 + 0x12) != '\0') {
    param_7 = param_7 | 0x20000;
  }
  if (DAT_00e39a4c != *(int *)**(undefined4 **)(param_5 + 0x100)) {
    FUN_0059bcf0(*(int *)**(undefined4 **)(param_5 + 0x100));
  }
  if (((DAT_00a3d360 != 0) || (DAT_00e39a00 != 0)) || (DAT_00e399fc != param_7)) {
    FUN_005a7f60();
  }
  fVar1 = DAT_00e79684;
  fVar5 = DAT_00a380b8;
  local_9c = *(int *)(param_5 + 0x88);
  local_3c = DAT_00e79684;
  local_34 = 0;
  if ((param_6 != 0) && (local_34 = (uint)(*(int *)(param_6 + 0x88) != local_9c), param_6 != 0)) {
    local_a8 = param_6 + 0x8c;
  }
  if ((int)((*(int *)(param_5 + 0x60) - DAT_00a3819c) + -1 + param_1 &
            param_2 + -1 + (*(int *)(param_5 + 100) - DAT_00a381a0) & (DAT_00a38198 - param_2) - 1U
           & (DAT_00a38194 - param_1) - 1U) < 0) {
    if (DAT_00e7967c == 2) {
      if (0 < local_9c) {
        pfVar11 = (float *)(local_a8 + 0x34);
        pfVar12 = (float *)(param_5 + 0xc0);
        local_98 = local_9c;
        do {
          FUN_0059bcf0(**(undefined4 **)pfVar12[0x10]);
          puVar4 = (undefined4 *)pfVar11[0x10];
          FUN_0059bd80(*(undefined4 *)*puVar4,puVar4[5],puVar4[6]);
          if (DAT_00e39a1c != 0) {
            FUN_005a0d80(0,0,1,1);
          }
          if (DAT_00dda46c != 0) {
            FUN_00584d70();
          }
          if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
             (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
            if (DAT_00e79678 != 0) {
              FUN_005a7ce0();
              if (DAT_00e79680 == 4) {
                uVar9 = (int)DAT_00e79678 / 3;
              }
              else if (DAT_00e79680 == 2) {
                uVar9 = (int)DAT_00e79678 / 2;
              }
              else if (DAT_00e79680 == 6) {
                uVar9 = DAT_00e79678 - 2;
              }
              else if (DAT_00e79680 == 5) {
                uVar9 = DAT_00e79678 - 2;
              }
              else if (DAT_00e79680 == 3) {
                uVar9 = DAT_00e79678 - 1;
              }
              else {
                uVar9 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
              }
              iVar13 = DAT_00e7967c + DAT_00e79674 * 3;
              FUN_005d3b40(DAT_00e79680,uVar9,*(undefined4 *)(&DAT_00e39a5c + iVar13 * 4),
                           *(undefined4 *)(&DAT_007da3e8 + iVar13 * 4));
              DAT_00a37de4 = DAT_00a37de4 + 1;
            }
            DAT_00e79678 = 0;
            DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
            DAT_00e79674 = 0;
            DAT_00e79680 = 4;
          }
          pfVar7 = DAT_00e39a58;
          DAT_00e39a58[4] = local_3c;
          pfVar7[0x22] = local_3c;
          *pfVar7 = param_3 + pfVar12[-1];
          pfVar7[1] = param_4 + *pfVar12;
          pfVar7[10] = pfVar12[3] + param_3;
          pfVar7[0xb] = *pfVar12 + param_4;
          pfVar7[0x14] = pfVar12[-1] + param_3;
          pfVar7[0x15] = param_4 + pfVar12[8];
          pfVar7[0x1e] = pfVar12[3] + param_3;
          pfVar7[0x1f] = param_4 + pfVar12[8];
          pfVar7[0x28] = pfVar12[-1] + param_3;
          pfVar7[0x29] = param_4 + pfVar12[8];
          pfVar7[0x32] = pfVar12[3] + param_3;
          pfVar7[0x33] = *pfVar12 + param_4;
          if (DAT_00a380e8 == 1) {
            local_a4 = ((pfVar12[-1] + param_3) - pfVar11[-1]) - (float)_DAT_00a380e0;
            local_a0 = ((pfVar12[3] + param_3) - pfVar11[-1]) - (float)_DAT_00a380e0;
            local_68 = ((*pfVar12 + param_4) - *pfVar11) - (float)_DAT_00a380e4;
            local_64 = ((pfVar12[8] + param_4) - *pfVar11) - (float)_DAT_00a380e4;
          }
          else {
            local_a4 = (float)_DAT_00a380e0 + (pfVar12[-1] - pfVar11[-1]);
            local_a0 = (pfVar12[3] - pfVar11[-1]) + (float)_DAT_00a380e0;
            local_68 = (float)_DAT_00a380e4 + (*pfVar12 - *pfVar11);
            local_64 = (pfVar12[8] - *pfVar11) + (float)_DAT_00a380e4;
          }
          local_a4 = _DAT_00e39a44 * local_a4;
          local_a0 = _DAT_00e39a44 * local_a0;
          local_68 = _DAT_00e39a48 * local_68;
          local_64 = _DAT_00e39a48 * local_64;
          pfVar7[6] = local_a4;
          pfVar7[7] = local_68;
          pfVar7[0x10] = local_a0;
          pfVar7[0x11] = local_68;
          pfVar7[0x1a] = local_a4;
          pfVar7[0x1b] = local_64;
          pfVar7[0x25] = local_64;
          pfVar7[0x2f] = local_64;
          pfVar7[0x24] = local_a0;
          pfVar7[0x38] = local_a0;
          pfVar7[0x2e] = local_a4;
          pfVar7[0x39] = local_68;
          pfVar7[8] = pfVar12[1];
          pfVar7[9] = pfVar12[2];
          pfVar7[0x12] = pfVar12[5];
          pfVar7[0x13] = pfVar12[2];
          pfVar7[0x1c] = pfVar12[1];
          pfVar7[0x1d] = pfVar12[10];
          pfVar7[0x26] = pfVar12[5];
          pfVar7[0x27] = pfVar12[10];
          pfVar7[0x30] = pfVar12[1];
          pfVar7[0x31] = pfVar12[10];
          pfVar7[0x3a] = pfVar12[5];
          fVar1 = pfVar12[2];
          pfVar7[2] = fVar5;
          pfVar7[0x3b] = fVar1;
          pfVar7[0xc] = fVar5;
          pfVar7[0x16] = fVar5;
          pfVar7[0x20] = fVar5;
          pfVar7[0x2a] = fVar5;
          pfVar7[0x34] = fVar5;
          DAT_00e39a58 = DAT_00e39a58 + 0x3c;
          DAT_00e79678 = DAT_00e79678 + 6;
          if (local_34 == 0) {
            pfVar11 = pfVar11 + 0x1e;
          }
          pfVar12 = pfVar12 + 0x1e;
          local_98 = local_98 + -1;
        } while (local_98 != 0);
      }
    }
    else {
      local_a8 = 0;
      pfVar11 = (float *)(param_5 + 0xcc);
      while( true ) {
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
           (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
          if (DAT_00e79678 != 0) {
            FUN_005a7ce0();
            if (DAT_00e79680 == 4) {
              uVar9 = (int)DAT_00e79678 / 3;
            }
            else if (DAT_00e79680 == 2) {
              uVar9 = (int)DAT_00e79678 / 2;
            }
            else if (DAT_00e79680 == 6) {
              uVar9 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 5) {
              uVar9 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 3) {
              uVar9 = DAT_00e79678 - 1;
            }
            else {
              uVar9 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
            }
            iVar13 = DAT_00e7967c + DAT_00e79674 * 3;
            FUN_005d3b40(DAT_00e79680,uVar9,*(undefined4 *)(&DAT_00e39a5c + iVar13 * 4),
                         *(undefined4 *)(&DAT_007da3e8 + iVar13 * 4));
            DAT_00a37de4 = DAT_00a37de4 + 1;
          }
          DAT_00e79678 = 0;
          DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
          DAT_00e79674 = 0;
          DAT_00e79680 = 4;
        }
        pfVar12 = DAT_00e39a58;
        DAT_00e39a58[4] = fVar1;
        pfVar12[0x19] = fVar1;
        *pfVar12 = param_3 + pfVar11[-4];
        pfVar12[1] = param_4 + pfVar11[-3];
        pfVar12[7] = param_3 + *pfVar11;
        pfVar12[8] = param_4 + pfVar11[-3];
        pfVar12[0xe] = param_3 + pfVar11[-4];
        pfVar12[0xf] = param_4 + pfVar11[5];
        pfVar12[0x15] = param_3 + *pfVar11;
        pfVar12[0x16] = param_4 + pfVar11[5];
        pfVar12[0x1c] = param_3 + pfVar11[-4];
        pfVar12[0x1d] = param_4 + pfVar11[5];
        pfVar12[0x23] = param_3 + *pfVar11;
        pfVar12[0x24] = param_4 + pfVar11[-3];
        pfVar12[5] = pfVar11[-2];
        pfVar12[6] = pfVar11[-1];
        pfVar12[0xc] = pfVar11[2];
        pfVar12[0xd] = pfVar11[-1];
        pfVar12[0x13] = pfVar11[-2];
        pfVar12[0x14] = pfVar11[7];
        pfVar12[0x1a] = pfVar11[2];
        pfVar12[0x1b] = pfVar11[7];
        pfVar12[0x21] = pfVar11[-2];
        pfVar12[0x22] = pfVar11[7];
        pfVar12[0x28] = pfVar11[2];
        fVar2 = pfVar11[-1];
        pfVar12[2] = fVar5;
        pfVar12[0x29] = fVar2;
        pfVar12[9] = fVar5;
        pfVar12[0x10] = fVar5;
        pfVar12[0x17] = fVar5;
        pfVar12[0x1e] = fVar5;
        pfVar12[0x25] = fVar5;
        DAT_00e39a58 = DAT_00e39a58 + 0x2a;
        DAT_00e79678 = DAT_00e79678 + 6;
        local_a8 = local_a8 + 1;
        if (local_9c <= local_a8) break;
        pfVar12 = pfVar11 + 0x2b;
        pfVar11 = pfVar11 + 0x1e;
        FUN_0059bcf0(**(undefined4 **)*pfVar12);
        FUN_005a0d80(0,0,1,1);
      }
    }
  }
  else if (-1 < (int)((*(int *)(param_5 + 0x60) - DAT_00a38194) + -1 + param_1 &
                      (*(int *)(param_5 + 100) - DAT_00a38198) + -1 + param_2 &
                      (DAT_00a381a0 - param_2) - 1U & (DAT_00a3819c - param_1) - 1U)) {
    local_6c = DAT_00a381a4;
    local_70 = DAT_00a381a8;
    local_84 = DAT_00a381ac;
    local_40 = DAT_00a381b0;
    if (DAT_00e7967c == 1) {
      local_a8 = 0;
      pfVar11 = (float *)(param_5 + 0xcc);
      while( true ) {
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
           (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
          if (DAT_00e79678 != 0) {
            FUN_005a7ce0();
            if (DAT_00e79680 == 4) {
              uVar9 = (int)DAT_00e79678 / 3;
            }
            else if (DAT_00e79680 == 2) {
              uVar9 = (int)DAT_00e79678 / 2;
            }
            else if (DAT_00e79680 == 6) {
              uVar9 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 5) {
              uVar9 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 3) {
              uVar9 = DAT_00e79678 - 1;
            }
            else {
              uVar9 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
            }
            iVar13 = DAT_00e7967c + DAT_00e79674 * 3;
            FUN_005d3b40(DAT_00e79680,uVar9,*(undefined4 *)(&DAT_00e39a5c + iVar13 * 4),
                         *(undefined4 *)(&DAT_007da3e8 + iVar13 * 4));
            DAT_00a37de4 = DAT_00a37de4 + 1;
          }
          DAT_00e79678 = 0;
          DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
          DAT_00e79674 = 0;
          DAT_00e79680 = 4;
        }
        pfVar7 = DAT_00e39a58;
        DAT_00e39a58[4] = fVar1;
        pfVar7[0x19] = fVar1;
        pfVar12 = local_2c;
        iVar13 = 0;
        local_30 = param_3 + pfVar11[-4];
        local_2c[0] = param_4 + pfVar11[-3];
        local_24 = *pfVar11 + param_3;
        local_20 = param_4 + pfVar11[-3];
        local_18 = param_3 + pfVar11[-4];
        local_14 = param_4 + pfVar11[5];
        local_8 = param_4 + pfVar11[5];
        local_c = *pfVar11 + param_3;
        local_94[0] = pfVar11[-2];
        local_94[2] = pfVar11[-2];
        local_94[1] = pfVar11[2];
        local_94[3] = pfVar11[2];
        local_80[0] = pfVar11[-1];
        local_80[1] = pfVar11[-1];
        local_80[2] = pfVar11[7];
        local_80[3] = pfVar11[7];
        local_38 = 1.0 / (float)*(int *)((int)pfVar11[0xd] + 0x14);
        fVar2 = 1.0 / (float)*(int *)((int)pfVar11[0xd] + 0x18);
        do {
          if (local_6c <= pfVar12[-1]) {
            if (local_84 < pfVar12[-1]) {
              *(float *)((int)local_94 + iVar13) =
                   *(float *)((int)local_94 + iVar13) - (pfVar12[-1] - local_84) * local_38;
              pfVar12[-1] = local_84;
            }
          }
          else {
            *(float *)((int)local_94 + iVar13) =
                 (local_6c - pfVar12[-1]) * local_38 + *(float *)((int)local_94 + iVar13);
            pfVar12[-1] = local_6c;
          }
          if (local_70 <= *pfVar12) {
            if (local_40 < *pfVar12) {
              *(float *)((int)local_80 + iVar13) =
                   *(float *)((int)local_80 + iVar13) - fVar2 * (*pfVar12 - local_40);
              *pfVar12 = local_40;
            }
          }
          else {
            *(float *)((int)local_80 + iVar13) =
                 (local_70 - *pfVar12) * fVar2 + *(float *)((int)local_80 + iVar13);
            *pfVar12 = local_70;
          }
          iVar13 = iVar13 + 4;
          pfVar12 = pfVar12 + 3;
        } while (iVar13 < 0x10);
        pfVar7[2] = fVar5;
        pfVar7[9] = fVar5;
        pfVar7[0x10] = fVar5;
        pfVar7[0x17] = fVar5;
        pfVar7[0x1e] = fVar5;
        *pfVar7 = local_30;
        pfVar7[0x25] = fVar5;
        local_a8 = local_a8 + 1;
        pfVar7[1] = local_2c[0];
        pfVar7[7] = local_24;
        pfVar7[8] = local_20;
        pfVar7[0xe] = local_18;
        pfVar7[0xf] = local_14;
        pfVar7[0x15] = local_c;
        pfVar7[0x16] = local_8;
        pfVar7[0x1c] = local_18;
        pfVar7[0x1d] = local_14;
        pfVar7[0x23] = local_24;
        pfVar7[0x24] = local_20;
        pfVar7[5] = local_94[0];
        pfVar7[6] = local_80[0];
        pfVar7[0xc] = local_94[1];
        pfVar7[0xd] = local_80[1];
        pfVar7[0x13] = local_94[2];
        pfVar7[0x14] = local_80[2];
        pfVar7[0x1a] = local_94[3];
        pfVar7[0x1b] = local_80[3];
        pfVar7[0x21] = local_94[2];
        pfVar7[0x22] = local_80[2];
        pfVar7[0x28] = local_94[1];
        pfVar7[0x29] = local_80[1];
        DAT_00e39a58 = DAT_00e39a58 + 0x2a;
        DAT_00e79678 = DAT_00e79678 + 6;
        if (local_9c <= local_a8) break;
        pfVar12 = pfVar11 + 0x2b;
        pfVar11 = pfVar11 + 0x1e;
        FUN_0059bcf0(**(undefined4 **)*pfVar12);
        FUN_005a0d80(0,0,1,1);
      }
    }
    else if ((DAT_00e7967c == 2) && (0 < local_9c)) {
      pfVar11 = (float *)(local_a8 + 0x34);
      pfVar12 = (float *)(param_5 + 0xcc);
      do {
        FUN_0059bcf0(**(undefined4 **)pfVar12[0xd]);
        puVar4 = (undefined4 *)pfVar11[0x10];
        FUN_0059bd80(*(undefined4 *)*puVar4,puVar4[5],puVar4[6]);
        if (DAT_00e39a1c != 0) {
          FUN_005a0d80(0,0,1,1);
        }
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
           (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
          if (DAT_00e79678 != 0) {
            FUN_005a7ce0();
            if (DAT_00e79680 == 4) {
              uVar9 = (int)DAT_00e79678 / 3;
            }
            else if (DAT_00e79680 == 2) {
              uVar9 = (int)DAT_00e79678 / 2;
            }
            else if (DAT_00e79680 == 6) {
              uVar9 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 5) {
              uVar9 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 3) {
              uVar9 = DAT_00e79678 - 1;
            }
            else {
              uVar9 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
            }
            iVar13 = DAT_00e7967c + DAT_00e79674 * 3;
            FUN_005d3b40(DAT_00e79680,uVar9,*(undefined4 *)(&DAT_00e39a5c + iVar13 * 4),
                         *(undefined4 *)(&DAT_007da3e8 + iVar13 * 4));
            DAT_00a37de4 = DAT_00a37de4 + 1;
          }
          DAT_00e79678 = 0;
          DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
          DAT_00e79674 = 0;
          DAT_00e79680 = 4;
        }
        pfVar7 = DAT_00e39a58;
        fVar6 = _DAT_00e39a48;
        fVar2 = _DAT_00e39a44;
        local_38 = 1.0 / (float)*(int *)((int)pfVar12[0xd] + 0x14);
        fVar1 = 1.0 / (float)*(int *)((int)pfVar12[0xd] + 0x18);
        local_68 = _DAT_00e39a44;
        DAT_00e39a58[4] = local_3c;
        pfVar7[0x22] = local_3c;
        local_30 = param_3 + pfVar12[-4];
        local_2c[0] = param_4 + pfVar12[-3];
        local_24 = param_3 + *pfVar12;
        local_20 = param_4 + pfVar12[-3];
        local_18 = local_30;
        local_14 = pfVar12[5] + param_4;
        local_8 = pfVar12[5] + param_4;
        local_c = param_3 + *pfVar12;
        local_80[0] = pfVar12[-2];
        local_80[2] = pfVar12[-2];
        local_80[1] = pfVar12[2];
        local_80[3] = pfVar12[2];
        local_94[0] = pfVar12[-1];
        local_94[1] = pfVar12[-1];
        local_94[2] = pfVar12[7];
        local_94[3] = pfVar12[7];
        if (DAT_00a380e8 == 1) {
          local_60[0] = _DAT_00e39a44 * ((local_30 - pfVar11[-1]) - (float)_DAT_00a380e0);
          local_60[2] = local_60[0];
          local_60[1] = (((*pfVar12 + param_3) - pfVar11[-1]) - (float)_DAT_00a380e0) *
                        _DAT_00e39a44;
          local_60[3] = local_60[1];
          local_50[0] = _DAT_00e39a48 *
                        (((pfVar12[-3] + param_4) - *pfVar11) - (float)_DAT_00a380e4);
          local_50[1] = local_50[0];
          fVar3 = ((pfVar12[5] + param_4) - *pfVar11) - (float)_DAT_00a380e4;
        }
        else {
          local_60[0] = _DAT_00e39a44 * ((float)_DAT_00a380e0 + (pfVar12[-4] - pfVar11[-1]));
          local_60[2] = local_60[0];
          local_60[1] = ((*pfVar12 - pfVar11[-1]) + (float)_DAT_00a380e0) * _DAT_00e39a44;
          local_60[3] = local_60[1];
          local_50[0] = _DAT_00e39a48 * ((float)_DAT_00a380e4 + (pfVar12[-3] - *pfVar11));
          local_50[1] = local_50[0];
          fVar3 = (pfVar12[5] - *pfVar11) + (float)_DAT_00a380e4;
        }
        local_50[2] = fVar3 * _DAT_00e39a48;
        pfVar10 = local_2c;
        iVar13 = 0;
        local_50[3] = fVar3 * _DAT_00e39a48;
        local_60[0] = local_60[2];
        local_60[1] = local_60[3];
        local_50[0] = local_50[1];
        do {
          if (local_6c <= pfVar10[-1]) {
            if (local_84 < pfVar10[-1]) {
              fVar3 = pfVar10[-1];
              *(float *)((int)local_80 + iVar13) =
                   *(float *)((int)local_80 + iVar13) - local_38 * (fVar3 - local_84);
              *(float *)((int)local_60 + iVar13) =
                   *(float *)((int)local_60 + iVar13) - fVar2 * (fVar3 - local_84);
              pfVar10[-1] = local_84;
            }
          }
          else {
            fVar3 = pfVar10[-1];
            *(float *)((int)local_80 + iVar13) =
                 local_38 * (local_6c - fVar3) + *(float *)((int)local_80 + iVar13);
            *(float *)((int)local_60 + iVar13) =
                 (local_6c - fVar3) * fVar2 + *(float *)((int)local_60 + iVar13);
            pfVar10[-1] = local_6c;
          }
          if (local_70 <= *pfVar10) {
            if (local_40 < *pfVar10) {
              fVar3 = *pfVar10;
              *(float *)((int)local_94 + iVar13) =
                   *(float *)((int)local_94 + iVar13) - fVar1 * (fVar3 - local_40);
              *(float *)((int)local_50 + iVar13) =
                   *(float *)((int)local_50 + iVar13) - fVar6 * (fVar3 - local_40);
              *pfVar10 = local_40;
            }
          }
          else {
            fVar3 = *pfVar10;
            *(float *)((int)local_94 + iVar13) =
                 fVar1 * (local_70 - fVar3) + *(float *)((int)local_94 + iVar13);
            *(float *)((int)local_50 + iVar13) =
                 (local_70 - fVar3) * fVar6 + *(float *)((int)local_50 + iVar13);
            *pfVar10 = local_70;
          }
          iVar13 = iVar13 + 4;
          pfVar10 = pfVar10 + 3;
        } while (iVar13 < 0x10);
        pfVar7[2] = fVar5;
        pfVar7[0xc] = fVar5;
        pfVar7[0x16] = fVar5;
        pfVar7[0x20] = fVar5;
        pfVar7[0x2a] = fVar5;
        pfVar7[0x34] = fVar5;
        *pfVar7 = local_30;
        pfVar7[1] = local_2c[0];
        pfVar7[10] = local_24;
        pfVar7[0xb] = local_20;
        pfVar7[0x14] = local_18;
        pfVar7[0x15] = local_14;
        pfVar7[0x1e] = local_c;
        pfVar7[0x1f] = local_8;
        pfVar7[0x28] = local_18;
        pfVar7[0x29] = local_14;
        pfVar7[0x32] = local_24;
        pfVar7[0x33] = local_20;
        pfVar7[6] = local_60[0];
        pfVar7[7] = local_50[0];
        pfVar7[0x10] = local_60[1];
        pfVar7[0x11] = local_50[1];
        pfVar7[0x1a] = local_60[2];
        pfVar7[0x1b] = local_50[2];
        pfVar7[0x24] = local_60[3];
        pfVar7[0x25] = local_50[3];
        pfVar7[0x2e] = local_60[2];
        pfVar7[0x2f] = local_50[2];
        pfVar7[0x38] = local_60[1];
        pfVar7[0x39] = local_50[1];
        pfVar7[8] = local_80[0];
        pfVar7[9] = local_94[0];
        pfVar7[0x12] = local_80[1];
        pfVar7[0x13] = local_94[1];
        pfVar7[0x1c] = local_80[2];
        pfVar7[0x1d] = local_94[2];
        pfVar7[0x26] = local_80[3];
        pfVar7[0x27] = local_94[3];
        pfVar7[0x30] = local_80[2];
        pfVar7[0x31] = local_94[2];
        pfVar7[0x3a] = local_80[1];
        pfVar7[0x3b] = local_94[1];
        DAT_00e39a58 = DAT_00e39a58 + 0x3c;
        DAT_00e79678 = DAT_00e79678 + 6;
        if (local_34 == 0) {
          pfVar11 = pfVar11 + 0x1e;
        }
        pfVar12 = pfVar12 + 0x1e;
        local_9c = local_9c + -1;
      } while (local_9c != 0);
      return 0;
    }
  }
  return 0;
}

