
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005a9a90(int param_1,int param_2,int param_3,int param_4,float param_5,float param_6,
            float param_7,float param_8,int param_9,int param_10,uint param_11,int param_12)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  float *pfVar15;
  float *pfVar16;
  float *pfVar17;
  int iVar18;
  float *local_bc;
  int local_b4;
  int local_a0;
  float local_94 [4];
  float local_84 [4];
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c [4];
  float local_4c;
  float local_48;
  float local_44 [4];
  uint local_34;
  float local_30;
  float local_2c [2];
  float local_24;
  float local_20;
  float local_18;
  float local_14;
  float local_c;
  float local_8;
  
  iVar12 = param_3;
  iVar11 = param_2;
  iVar18 = *(int *)(param_9 + 0x4c);
  local_bc = (float *)0x0;
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if ((param_1 == param_3) || (param_2 == param_4)) {
    return 0xffffffff;
  }
  if (DAT_00e79688 == 0) {
    FUN_0059d430();
  }
  if (param_12 == 0) {
    uVar13 = 0;
  }
  else {
    uVar13 = -(uint)(DAT_00a380bc != 1) & 2;
  }
  uVar14 = uVar13 | param_11 | 0x8000;
  if (*(char *)(iVar18 + 10) != '\0') {
    uVar14 = uVar13 | param_11 | 0x18000;
  }
  if (*(char *)(iVar18 + 0x12) != '\0') {
    uVar14 = uVar14 | 0x20000;
  }
  if (DAT_00e39a4c != *(int *)**(undefined4 **)(param_9 + 0x100)) {
    FUN_0059bcf0(*(int *)**(undefined4 **)(param_9 + 0x100));
  }
  if (((DAT_00a3d360 != 0) || (DAT_00e39a00 != 0)) || (DAT_00e399fc != uVar14)) {
    FUN_005a7f60();
  }
  fVar10 = DAT_00e79684;
  fVar7 = DAT_00a380b8;
  local_b4 = *(int *)(param_9 + 0x88);
  local_34 = 0;
  if ((param_10 != 0) && (local_34 = (uint)(*(int *)(param_10 + 0x88) != local_b4), param_10 != 0))
  {
    local_bc = (float *)(param_10 + 0x8c);
  }
  local_48 = (param_7 - param_5) / *(float *)(param_9 + 0x68);
  local_68 = (param_8 - param_6) / *(float *)(param_9 + 0x6c);
  local_4c = (float)_DAT_00804a60;
  param_5 = param_5 - local_4c;
  param_6 = param_6 - local_4c;
  if (param_3 < param_1) {
    param_3 = param_1;
    param_1 = iVar12;
  }
  if (param_4 < param_2) {
    param_2 = param_4;
    param_4 = iVar11;
  }
  if ((int)((param_4 - DAT_00a381a0) - 1U & (param_3 - DAT_00a3819c) - 1U &
            (DAT_00a38198 - param_2) - 1U & (DAT_00a38194 - param_1) - 1U) < 0) {
    if (DAT_00e7967c == 1) {
      local_bc = (float *)0x0;
      pfVar17 = (float *)(param_9 + 0xc4);
      while( true ) {
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
           (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
          if (DAT_00e79678 != 0) {
            FUN_005a7ce0();
            if (DAT_00e79680 == 4) {
              uVar13 = (int)DAT_00e79678 / 3;
            }
            else if (DAT_00e79680 == 2) {
              uVar13 = (int)DAT_00e79678 / 2;
            }
            else if (DAT_00e79680 == 6) {
              uVar13 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 5) {
              uVar13 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 3) {
              uVar13 = DAT_00e79678 - 1;
            }
            else {
              uVar13 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
            }
            iVar18 = DAT_00e7967c + DAT_00e79674 * 3;
            FUN_005d3b40(DAT_00e79680,uVar13,*(undefined4 *)(&DAT_00e39a5c + iVar18 * 4),
                         *(undefined4 *)(&DAT_007da3e8 + iVar18 * 4));
            DAT_00a37de4 = DAT_00a37de4 + 1;
          }
          DAT_00e79678 = 0;
          DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
          DAT_00e79674 = 0;
          DAT_00e79680 = 4;
        }
        pfVar16 = DAT_00e39a58;
        DAT_00e39a58[4] = fVar10;
        pfVar16[0x19] = fVar10;
        fVar1 = param_5 + local_48 * pfVar17[-2];
        fVar4 = local_48 * pfVar17[2] + param_5;
        fVar5 = param_6 + local_68 * pfVar17[-1];
        fVar6 = local_68 * pfVar17[7] + param_6;
        *pfVar16 = fVar1;
        pfVar16[1] = fVar5;
        pfVar16[7] = fVar4;
        pfVar16[8] = fVar5;
        pfVar16[0xe] = fVar1;
        pfVar16[0xf] = fVar6;
        pfVar16[0x16] = fVar6;
        pfVar16[0x1d] = fVar6;
        pfVar16[0x15] = fVar4;
        pfVar16[0x23] = fVar4;
        pfVar16[0x1c] = fVar1;
        pfVar16[0x24] = fVar5;
        pfVar16[5] = *pfVar17;
        pfVar16[6] = pfVar17[1];
        pfVar16[0xc] = pfVar17[4];
        pfVar16[0xd] = pfVar17[1];
        pfVar16[0x13] = *pfVar17;
        pfVar16[0x14] = pfVar17[9];
        pfVar16[0x1a] = pfVar17[4];
        pfVar16[0x1b] = pfVar17[9];
        pfVar16[0x21] = *pfVar17;
        pfVar16[0x22] = pfVar17[9];
        pfVar16[0x28] = pfVar17[4];
        fVar1 = pfVar17[1];
        pfVar16[2] = fVar7;
        pfVar16[0x29] = fVar1;
        pfVar16[9] = fVar7;
        pfVar16[0x10] = fVar7;
        pfVar16[0x17] = fVar7;
        pfVar16[0x1e] = fVar7;
        pfVar16[0x25] = fVar7;
        DAT_00e39a58 = DAT_00e39a58 + 0x2a;
        DAT_00e79678 = DAT_00e79678 + 6;
        local_bc = (float *)((int)local_bc + 1);
        if (local_b4 <= (int)local_bc) break;
        pfVar16 = pfVar17 + 0x2d;
        pfVar17 = pfVar17 + 0x1e;
        FUN_0059bcf0(**(undefined4 **)*pfVar16);
        FUN_005a0d80(0,0,1,1);
      }
    }
    else if ((DAT_00e7967c == 2) && (0 < local_b4)) {
      local_bc = (float *)((int)local_bc + 0x34);
      pfVar17 = (float *)(param_9 + 0xc0);
      local_a0 = local_b4;
      do {
        FUN_0059bcf0(**(undefined4 **)pfVar17[0x10]);
        puVar3 = (undefined4 *)local_bc[0x10];
        FUN_0059bd80(*(undefined4 *)*puVar3,puVar3[5],puVar3[6]);
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
              uVar13 = (int)DAT_00e79678 / 3;
            }
            else if (DAT_00e79680 == 2) {
              uVar13 = (int)DAT_00e79678 / 2;
            }
            else if (DAT_00e79680 == 6) {
              uVar13 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 5) {
              uVar13 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 3) {
              uVar13 = DAT_00e79678 - 1;
            }
            else {
              uVar13 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
            }
            iVar18 = DAT_00e7967c + DAT_00e79674 * 3;
            FUN_005d3b40(DAT_00e79680,uVar13,*(undefined4 *)(&DAT_00e39a5c + iVar18 * 4),
                         *(undefined4 *)(&DAT_007da3e8 + iVar18 * 4));
            DAT_00a37de4 = DAT_00a37de4 + 1;
          }
          DAT_00e79678 = 0;
          DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
          DAT_00e79674 = 0;
          DAT_00e79680 = 4;
        }
        pfVar16 = DAT_00e39a58;
        DAT_00e39a58[4] = fVar10;
        pfVar16[0x22] = fVar10;
        fVar1 = param_5 + local_48 * pfVar17[-1];
        fVar4 = local_48 * pfVar17[3] + param_5;
        fVar5 = param_6 + local_68 * *pfVar17;
        fVar6 = local_68 * pfVar17[8] + param_6;
        *pfVar16 = fVar1;
        pfVar16[1] = fVar5;
        pfVar16[10] = fVar4;
        pfVar16[0xb] = fVar5;
        pfVar16[0x14] = fVar1;
        pfVar16[0x15] = fVar6;
        pfVar16[0x1f] = fVar6;
        pfVar16[0x29] = fVar6;
        pfVar16[0x1e] = fVar4;
        pfVar16[0x32] = fVar4;
        pfVar16[0x28] = fVar1;
        pfVar16[0x33] = fVar5;
        if (DAT_00a380e8 == 1) {
          local_74 = (fVar1 - local_bc[-1]) - (float)_DAT_00a380e0;
          local_70 = (fVar4 - local_bc[-1]) - (float)_DAT_00a380e0;
          local_64 = (fVar5 - *local_bc) - (float)_DAT_00a380e4;
          local_60 = (fVar6 - *local_bc) - (float)_DAT_00a380e4;
        }
        else {
          local_74 = (float)_DAT_00a380e0 + (pfVar17[-1] - local_bc[-1]);
          local_70 = (pfVar17[3] - local_bc[-1]) + (float)_DAT_00a380e0;
          local_64 = (float)_DAT_00a380e4 + (*pfVar17 - *local_bc);
          local_60 = (pfVar17[8] - *local_bc) + (float)_DAT_00a380e4;
        }
        local_74 = _DAT_00e39a44 * local_74;
        local_70 = _DAT_00e39a44 * local_70;
        local_64 = _DAT_00e39a48 * local_64;
        local_60 = _DAT_00e39a48 * local_60;
        pfVar16[6] = local_74;
        pfVar16[7] = local_64;
        pfVar16[0x10] = local_70;
        pfVar16[0x11] = local_64;
        pfVar16[0x1a] = local_74;
        pfVar16[0x1b] = local_60;
        pfVar16[0x25] = local_60;
        pfVar16[0x2f] = local_60;
        pfVar16[0x24] = local_70;
        pfVar16[0x38] = local_70;
        pfVar16[0x2e] = local_74;
        pfVar16[0x39] = local_64;
        pfVar16[8] = pfVar17[1];
        pfVar16[9] = pfVar17[2];
        pfVar16[0x12] = pfVar17[5];
        pfVar16[0x13] = pfVar17[2];
        pfVar16[0x1c] = pfVar17[1];
        pfVar16[0x1d] = pfVar17[10];
        pfVar16[0x26] = pfVar17[5];
        pfVar16[0x27] = pfVar17[10];
        pfVar16[0x30] = pfVar17[1];
        pfVar16[0x31] = pfVar17[10];
        pfVar16[0x3a] = pfVar17[5];
        fVar1 = pfVar17[2];
        pfVar16[2] = fVar7;
        pfVar16[0x3b] = fVar1;
        pfVar16[0xc] = fVar7;
        pfVar16[0x16] = fVar7;
        pfVar16[0x20] = fVar7;
        pfVar16[0x2a] = fVar7;
        pfVar16[0x34] = fVar7;
        DAT_00e39a58 = DAT_00e39a58 + 0x3c;
        DAT_00e79678 = DAT_00e79678 + 6;
        if (local_34 == 0) {
          local_bc = local_bc + 0x1e;
        }
        pfVar17 = pfVar17 + 0x1e;
        local_a0 = local_a0 + -1;
      } while (local_a0 != 0);
      return 0;
    }
  }
  else if (-1 < (int)((param_4 - DAT_00a38198) - 1U & (param_3 - DAT_00a38194) - 1U &
                      (DAT_00a381a0 - param_2) - 1U & (DAT_00a3819c - param_1) - 1U)) {
    local_6c = DAT_00a381a4 - local_4c;
    fVar1 = DAT_00a381a8 - local_4c;
    fVar4 = DAT_00a381ac - local_4c;
    local_4c = DAT_00a381b0 - local_4c;
    if (DAT_00e7967c == 1) {
      local_bc = (float *)0x0;
      pfVar17 = (float *)(param_9 + 0xc0);
      while( true ) {
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
           (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
          if (DAT_00e79678 != 0) {
            FUN_005a7ce0();
            if (DAT_00e79680 == 4) {
              uVar13 = (int)DAT_00e79678 / 3;
            }
            else if (DAT_00e79680 == 2) {
              uVar13 = (int)DAT_00e79678 / 2;
            }
            else if (DAT_00e79680 == 6) {
              uVar13 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 5) {
              uVar13 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 3) {
              uVar13 = DAT_00e79678 - 1;
            }
            else {
              uVar13 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
            }
            iVar18 = DAT_00e7967c + DAT_00e79674 * 3;
            FUN_005d3b40(DAT_00e79680,uVar13,*(undefined4 *)(&DAT_00e39a5c + iVar18 * 4),
                         *(undefined4 *)(&DAT_007da3e8 + iVar18 * 4));
            DAT_00a37de4 = DAT_00a37de4 + 1;
          }
          DAT_00e79678 = 0;
          DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
          DAT_00e79674 = 0;
          DAT_00e79680 = 4;
        }
        pfVar15 = DAT_00e39a58;
        DAT_00e39a58[4] = fVar10;
        pfVar15[0x19] = fVar10;
        pfVar16 = local_2c;
        iVar18 = 0;
        local_30 = param_5 + local_48 * pfVar17[-1];
        local_24 = pfVar17[3] * local_48 + param_5;
        local_2c[0] = param_6 + local_68 * *pfVar17;
        local_14 = local_68 * pfVar17[8] + param_6;
        local_20 = local_2c[0];
        local_18 = local_30;
        local_8 = local_14;
        local_c = local_24;
        local_94[0] = pfVar17[1];
        local_94[2] = pfVar17[1];
        local_94[1] = pfVar17[5];
        local_94[3] = pfVar17[5];
        local_84[0] = pfVar17[2];
        local_84[1] = pfVar17[2];
        local_84[2] = pfVar17[10];
        local_84[3] = pfVar17[10];
        fVar5 = 1.0 / (local_48 * (float)*(int *)((int)pfVar17[0x10] + 0x14));
        fVar6 = 1.0 / ((float)*(int *)((int)pfVar17[0x10] + 0x18) * local_68);
        do {
          if (local_6c <= pfVar16[-1]) {
            if (fVar4 < pfVar16[-1]) {
              *(float *)((int)local_94 + iVar18) =
                   *(float *)((int)local_94 + iVar18) - (pfVar16[-1] - fVar4) * fVar5;
              pfVar16[-1] = fVar4;
            }
          }
          else {
            *(float *)((int)local_94 + iVar18) =
                 (local_6c - pfVar16[-1]) * fVar5 + *(float *)((int)local_94 + iVar18);
            pfVar16[-1] = local_6c;
          }
          if (fVar1 <= *pfVar16) {
            if (local_4c < *pfVar16) {
              *(float *)((int)local_84 + iVar18) =
                   *(float *)((int)local_84 + iVar18) - fVar6 * (*pfVar16 - local_4c);
              *pfVar16 = local_4c;
            }
          }
          else {
            *(float *)((int)local_84 + iVar18) =
                 (fVar1 - *pfVar16) * fVar6 + *(float *)((int)local_84 + iVar18);
            *pfVar16 = fVar1;
          }
          iVar18 = iVar18 + 4;
          pfVar16 = pfVar16 + 3;
        } while (iVar18 < 0x10);
        pfVar15[2] = fVar7;
        pfVar15[9] = fVar7;
        pfVar15[0x10] = fVar7;
        pfVar15[0x17] = fVar7;
        pfVar15[0x1e] = fVar7;
        *pfVar15 = local_30;
        pfVar15[0x25] = fVar7;
        local_bc = (float *)((int)local_bc + 1);
        pfVar15[1] = local_2c[0];
        pfVar15[7] = local_24;
        pfVar15[8] = local_20;
        pfVar15[0xe] = local_18;
        pfVar15[0xf] = local_14;
        pfVar15[0x15] = local_c;
        pfVar15[0x16] = local_8;
        pfVar15[0x1c] = local_18;
        pfVar15[0x1d] = local_14;
        pfVar15[0x23] = local_24;
        pfVar15[0x24] = local_20;
        pfVar15[5] = local_94[0];
        pfVar15[6] = local_84[0];
        pfVar15[0xc] = local_94[1];
        pfVar15[0xd] = local_84[1];
        pfVar15[0x13] = local_94[2];
        pfVar15[0x14] = local_84[2];
        pfVar15[0x1a] = local_94[3];
        pfVar15[0x1b] = local_84[3];
        pfVar15[0x21] = local_94[2];
        pfVar15[0x22] = local_84[2];
        pfVar15[0x28] = local_94[1];
        pfVar15[0x29] = local_84[1];
        DAT_00e39a58 = DAT_00e39a58 + 0x2a;
        DAT_00e79678 = DAT_00e79678 + 6;
        if (local_b4 <= (int)local_bc) break;
        pfVar16 = pfVar17 + 0x2e;
        pfVar17 = pfVar17 + 0x1e;
        FUN_0059bcf0(**(undefined4 **)*pfVar16);
        FUN_005a0d80(0,0,1,1);
      }
    }
    else if ((DAT_00e7967c == 2) && (0 < local_b4)) {
      local_bc = (float *)((int)local_bc + 0x34);
      pfVar17 = (float *)(param_9 + 0xc0);
      do {
        FUN_0059bcf0(**(undefined4 **)pfVar17[0x10]);
        puVar3 = (undefined4 *)local_bc[0x10];
        FUN_0059bd80(*(undefined4 *)*puVar3,puVar3[5],puVar3[6]);
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
              uVar13 = (int)DAT_00e79678 / 3;
            }
            else if (DAT_00e79680 == 2) {
              uVar13 = (int)DAT_00e79678 / 2;
            }
            else if (DAT_00e79680 == 6) {
              uVar13 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 5) {
              uVar13 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 3) {
              uVar13 = DAT_00e79678 - 1;
            }
            else {
              uVar13 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
            }
            iVar18 = DAT_00e7967c + DAT_00e79674 * 3;
            FUN_005d3b40(DAT_00e79680,uVar13,*(undefined4 *)(&DAT_00e39a5c + iVar18 * 4),
                         *(undefined4 *)(&DAT_007da3e8 + iVar18 * 4));
            DAT_00a37de4 = DAT_00a37de4 + 1;
          }
          DAT_00e79678 = 0;
          DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
          DAT_00e79674 = 0;
          DAT_00e79680 = 4;
        }
        pfVar16 = DAT_00e39a58;
        fVar9 = _DAT_00e39a48;
        fVar8 = _DAT_00e39a44;
        fVar5 = 1.0 / (local_48 * (float)*(int *)((int)pfVar17[0x10] + 0x14));
        fVar6 = 1.0 / (local_68 * (float)*(int *)((int)pfVar17[0x10] + 0x18));
        local_64 = _DAT_00e39a44;
        local_74 = _DAT_00e39a48;
        DAT_00e39a58[4] = fVar10;
        pfVar16[0x22] = fVar10;
        local_30 = param_5 + local_48 * pfVar17[-1];
        local_24 = param_5 + pfVar17[3] * local_48;
        local_2c[0] = param_6 + local_68 * *pfVar17;
        local_14 = param_6 + pfVar17[8] * local_68;
        local_20 = local_2c[0];
        local_18 = local_30;
        local_8 = local_14;
        local_c = local_24;
        if (DAT_00a380e8 == 1) {
          local_5c[0] = _DAT_00e39a44 * ((local_30 - local_bc[-1]) - (float)_DAT_00a380e0);
          local_5c[2] = local_5c[0];
          local_5c[1] = ((local_24 - local_bc[-1]) - (float)_DAT_00a380e0) * _DAT_00e39a44;
          local_5c[3] = local_5c[1];
          local_44[0] = _DAT_00e39a48 * ((local_2c[0] - *local_bc) - (float)_DAT_00a380e4);
          local_44[1] = local_44[0];
          fVar2 = (local_14 - *local_bc) - (float)_DAT_00a380e4;
        }
        else {
          local_5c[0] = _DAT_00e39a44 * ((float)_DAT_00a380e0 + (pfVar17[-1] - local_bc[-1]));
          local_5c[2] = local_5c[0];
          local_5c[1] = ((pfVar17[3] - local_bc[-1]) + (float)_DAT_00a380e0) * _DAT_00e39a44;
          local_5c[3] = local_5c[1];
          local_44[0] = _DAT_00e39a48 * ((float)_DAT_00a380e4 + (*pfVar17 - *local_bc));
          local_44[1] = local_44[0];
          fVar2 = (pfVar17[8] - *local_bc) + (float)_DAT_00a380e4;
        }
        pfVar15 = local_2c;
        iVar18 = 0;
        local_44[2] = fVar2 * _DAT_00e39a48;
        local_44[3] = fVar2 * _DAT_00e39a48;
        local_84[0] = pfVar17[1];
        local_84[2] = pfVar17[1];
        local_84[1] = pfVar17[5];
        local_84[3] = pfVar17[5];
        local_94[0] = pfVar17[2];
        local_94[1] = pfVar17[2];
        local_94[2] = pfVar17[10];
        local_94[3] = pfVar17[10];
        local_5c[0] = local_5c[2];
        local_5c[1] = local_5c[3];
        local_44[0] = local_44[1];
        do {
          if (local_6c <= pfVar15[-1]) {
            if (fVar4 < pfVar15[-1]) {
              fVar2 = pfVar15[-1];
              *(float *)((int)local_84 + iVar18) =
                   *(float *)((int)local_84 + iVar18) - fVar5 * (fVar2 - fVar4);
              *(float *)((int)local_5c + iVar18) =
                   *(float *)((int)local_5c + iVar18) - fVar8 * (fVar2 - fVar4);
              pfVar15[-1] = fVar4;
            }
          }
          else {
            fVar2 = pfVar15[-1];
            *(float *)((int)local_84 + iVar18) =
                 fVar5 * (local_6c - fVar2) + *(float *)((int)local_84 + iVar18);
            *(float *)((int)local_5c + iVar18) =
                 (local_6c - fVar2) * fVar8 + *(float *)((int)local_5c + iVar18);
            pfVar15[-1] = local_6c;
          }
          if (fVar1 <= *pfVar15) {
            if (local_4c < *pfVar15) {
              fVar2 = *pfVar15;
              *(float *)((int)local_94 + iVar18) =
                   *(float *)((int)local_94 + iVar18) - fVar6 * (fVar2 - local_4c);
              *(float *)((int)local_44 + iVar18) =
                   *(float *)((int)local_44 + iVar18) - fVar9 * (fVar2 - local_4c);
              *pfVar15 = local_4c;
            }
          }
          else {
            fVar2 = *pfVar15;
            *(float *)((int)local_94 + iVar18) =
                 fVar6 * (fVar1 - fVar2) + *(float *)((int)local_94 + iVar18);
            *(float *)((int)local_44 + iVar18) =
                 (fVar1 - fVar2) * fVar9 + *(float *)((int)local_44 + iVar18);
            *pfVar15 = fVar1;
          }
          iVar18 = iVar18 + 4;
          pfVar15 = pfVar15 + 3;
        } while (iVar18 < 0x10);
        pfVar16[2] = fVar7;
        pfVar16[0xc] = fVar7;
        pfVar16[0x16] = fVar7;
        pfVar16[0x20] = fVar7;
        pfVar16[0x2a] = fVar7;
        pfVar16[0x34] = fVar7;
        *pfVar16 = local_30;
        pfVar16[1] = local_2c[0];
        pfVar16[10] = local_24;
        pfVar16[0xb] = local_20;
        pfVar16[0x14] = local_18;
        pfVar16[0x15] = local_14;
        pfVar16[0x1e] = local_c;
        pfVar16[0x1f] = local_8;
        pfVar16[0x28] = local_18;
        pfVar16[0x29] = local_14;
        pfVar16[0x32] = local_24;
        pfVar16[0x33] = local_20;
        pfVar16[6] = local_5c[0];
        pfVar16[7] = local_44[0];
        pfVar16[0x10] = local_5c[1];
        pfVar16[0x11] = local_44[1];
        pfVar16[0x1a] = local_5c[2];
        pfVar16[0x1b] = local_44[2];
        pfVar16[0x24] = local_5c[3];
        pfVar16[0x25] = local_44[3];
        pfVar16[0x2e] = local_5c[2];
        pfVar16[0x2f] = local_44[2];
        pfVar16[0x38] = local_5c[1];
        pfVar16[0x39] = local_44[1];
        pfVar16[8] = local_84[0];
        pfVar16[9] = local_94[0];
        pfVar16[0x12] = local_84[1];
        pfVar16[0x13] = local_94[1];
        pfVar16[0x1c] = local_84[2];
        pfVar16[0x1d] = local_94[2];
        pfVar16[0x26] = local_84[3];
        pfVar16[0x27] = local_94[3];
        pfVar16[0x30] = local_84[2];
        pfVar16[0x31] = local_94[2];
        pfVar16[0x3a] = local_84[1];
        pfVar16[0x3b] = local_94[1];
        DAT_00e39a58 = DAT_00e39a58 + 0x3c;
        DAT_00e79678 = DAT_00e79678 + 6;
        if (local_34 == 0) {
          local_bc = local_bc + 0x1e;
        }
        pfVar17 = pfVar17 + 0x1e;
        local_b4 = local_b4 + -1;
      } while (local_b4 != 0);
      return 0;
    }
  }
  return 0;
}

