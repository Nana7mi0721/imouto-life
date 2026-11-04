
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005afa20(int *param_1,int param_2,int param_3)

{
  int iVar1;
  float fVar2;
  undefined4 *puVar3;
  float fVar4;
  float *pfVar5;
  float fVar6;
  float *pfVar7;
  uint uVar8;
  int local_2c;
  int local_28;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_28 = 0;
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_2 + 0x88) != 1) {
    return 0xffffffff;
  }
  if (DAT_00e79688 == 0) {
    FUN_0059d430();
  }
  uVar8 = param_1[3] | 0x8000;
  if (*(char *)(*(int *)(param_2 + 0x4c) + 10) != '\0') {
    uVar8 = param_1[3] | 0x18000;
  }
  if (*(char *)(*(int *)(param_2 + 0x4c) + 0x12) != '\0') {
    uVar8 = uVar8 | 0x20000;
  }
  if (DAT_00e39a4c != *(int *)**(undefined4 **)(param_2 + 0x100)) {
    FUN_0059bcf0(*(int *)**(undefined4 **)(param_2 + 0x100));
  }
  if (((DAT_00a3d360 != 0) || (DAT_00e39a00 != 0)) || (DAT_00e399fc != uVar8)) {
    FUN_005a7f60();
  }
  fVar6 = DAT_00e79684;
  fVar4 = DAT_00a380b8;
  if (param_3 != 0) {
    local_28 = param_3 + 0x8c;
  }
  if (DAT_00e7967c == 1) {
    local_2c = 0;
    pfVar7 = (float *)param_1[1];
    if (0 < *param_1) {
      do {
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
           (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
          if (DAT_00e79678 != 0) {
            FUN_005a7ce0();
            if (DAT_00e79680 == 4) {
              uVar8 = (int)DAT_00e79678 / 3;
            }
            else if (DAT_00e79680 == 2) {
              uVar8 = (int)DAT_00e79678 / 2;
            }
            else if (DAT_00e79680 == 6) {
              uVar8 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 5) {
              uVar8 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 3) {
              uVar8 = DAT_00e79678 - 1;
            }
            else {
              uVar8 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
            }
            iVar1 = DAT_00e7967c + DAT_00e79674 * 3;
            FUN_005d3b40(DAT_00e79680,uVar8,*(undefined4 *)(&DAT_00e39a5c + iVar1 * 4),
                         *(undefined4 *)(&DAT_007da3e8 + iVar1 * 4));
            DAT_00a37de4 = DAT_00a37de4 + 1;
          }
          DAT_00e79678 = 0;
          DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
          DAT_00e79674 = 0;
          DAT_00e79680 = 4;
        }
        pfVar5 = DAT_00e39a58;
        DAT_00e39a58[4] = fVar6;
        pfVar5[0xb] = fVar6;
        pfVar5[0x12] = fVar6;
        pfVar5[0x19] = fVar6;
        pfVar5[0x20] = fVar6;
        pfVar5[0x27] = fVar6;
        pfVar5[5] = pfVar7[2];
        pfVar5[6] = pfVar7[3];
        pfVar5[0xc] = pfVar7[6];
        pfVar5[0xd] = pfVar7[7];
        pfVar5[0x13] = pfVar7[10];
        pfVar5[0x14] = pfVar7[0xb];
        pfVar5[0x1a] = pfVar7[0xe];
        pfVar5[0x1b] = pfVar7[0xf];
        pfVar5[0x21] = pfVar7[10];
        pfVar5[0x22] = pfVar7[0xb];
        pfVar5[0x28] = pfVar7[6];
        pfVar5[0x29] = pfVar7[7];
        *pfVar5 = *pfVar7;
        pfVar5[1] = pfVar7[1];
        pfVar5[7] = pfVar7[4];
        pfVar5[8] = pfVar7[5];
        pfVar5[0xe] = pfVar7[8];
        pfVar5[0xf] = pfVar7[9];
        pfVar5[0x15] = pfVar7[0xc];
        pfVar5[0x16] = pfVar7[0xd];
        pfVar5[0x1c] = pfVar7[8];
        pfVar5[0x1d] = pfVar7[9];
        pfVar5[0x23] = pfVar7[4];
        fVar2 = pfVar7[5];
        pfVar5[2] = fVar4;
        pfVar5[0x24] = fVar2;
        pfVar5[9] = fVar4;
        pfVar5[0x10] = fVar4;
        pfVar5[0x17] = fVar4;
        pfVar5[0x1e] = fVar4;
        pfVar5[0x25] = fVar4;
        DAT_00e39a58 = DAT_00e39a58 + 0x2a;
        DAT_00e79678 = DAT_00e79678 + 6;
        local_2c = local_2c + 1;
        pfVar7 = pfVar7 + 0x10;
      } while (local_2c < *param_1);
    }
  }
  else if (DAT_00e7967c == 2) {
    FUN_0059bcf0(*(undefined4 *)**(undefined4 **)(param_2 + 0x100));
    puVar3 = *(undefined4 **)(local_28 + 0x74);
    FUN_0059bd80(*(undefined4 *)*puVar3,puVar3[5],puVar3[6]);
    if (DAT_00e39a1c != 0) {
      FUN_005a0d80(0,0,1,1);
    }
    local_2c = 0;
    if (0 < *param_1) {
      pfVar7 = (float *)param_1[1];
      do {
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
           (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
          if (DAT_00e79678 != 0) {
            FUN_005a7ce0();
            if (DAT_00e79680 == 4) {
              uVar8 = (int)DAT_00e79678 / 3;
            }
            else if (DAT_00e79680 == 2) {
              uVar8 = (int)DAT_00e79678 / 2;
            }
            else if (DAT_00e79680 == 6) {
              uVar8 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 5) {
              uVar8 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 3) {
              uVar8 = DAT_00e79678 - 1;
            }
            else {
              uVar8 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
            }
            iVar1 = DAT_00e7967c + DAT_00e79674 * 3;
            FUN_005d3b40(DAT_00e79680,uVar8,*(undefined4 *)(&DAT_00e39a5c + iVar1 * 4),
                         *(undefined4 *)(&DAT_007da3e8 + iVar1 * 4));
            DAT_00a37de4 = DAT_00a37de4 + 1;
          }
          DAT_00e79678 = 0;
          DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
          DAT_00e79674 = 0;
          DAT_00e79680 = 4;
        }
        pfVar5 = DAT_00e39a58;
        DAT_00e39a58[4] = fVar6;
        pfVar5[0xe] = fVar6;
        pfVar5[0x18] = fVar6;
        pfVar5[0x22] = fVar6;
        pfVar5[0x2c] = fVar6;
        pfVar5[0x36] = fVar6;
        *pfVar5 = *pfVar7;
        pfVar5[1] = pfVar7[1];
        pfVar5[10] = pfVar7[4];
        pfVar5[0xb] = pfVar7[5];
        pfVar5[0x14] = pfVar7[8];
        pfVar5[0x15] = pfVar7[9];
        pfVar5[0x1e] = pfVar7[0xc];
        pfVar5[0x1f] = pfVar7[0xd];
        pfVar5[0x28] = pfVar7[8];
        pfVar5[0x29] = pfVar7[9];
        pfVar5[0x32] = pfVar7[4];
        pfVar5[0x33] = pfVar7[5];
        local_14 = (float)_DAT_00a380e0;
        if (DAT_00a380e8 == 1) {
          local_20 = (*pfVar7 - *(float *)(local_28 + 0x30)) - local_14;
          fVar2 = (float)_DAT_00a380e4;
          local_10 = (pfVar7[1] - *(float *)(local_28 + 0x34)) - fVar2;
          local_1c = (pfVar7[4] - *(float *)(local_28 + 0x30)) - local_14;
          local_c = (pfVar7[5] - *(float *)(local_28 + 0x34)) - fVar2;
          local_18 = (pfVar7[8] - *(float *)(local_28 + 0x30)) - local_14;
          local_8 = (pfVar7[9] - *(float *)(local_28 + 0x34)) - fVar2;
          local_14 = (pfVar7[0xc] - *(float *)(local_28 + 0x30)) - local_14;
          fVar2 = (pfVar7[0xd] - *(float *)(local_28 + 0x34)) - fVar2;
        }
        else {
          local_20 = local_14 + (*(float *)(param_2 + 0xbc) - *(float *)(local_28 + 0x30));
          fVar2 = (float)_DAT_00a380e4;
          local_10 = fVar2 + (*(float *)(param_2 + 0xc0) - *(float *)(local_28 + 0x34));
          local_1c = (*(float *)(param_2 + 0xcc) - *(float *)(local_28 + 0x40)) + local_14;
          local_c = (*(float *)(param_2 + 0xd0) - *(float *)(local_28 + 0x44)) + fVar2;
          local_18 = (*(float *)(param_2 + 0xdc) - *(float *)(local_28 + 0x50)) + local_14;
          local_8 = (*(float *)(param_2 + 0xe0) - *(float *)(local_28 + 0x54)) + fVar2;
          local_14 = (*(float *)(param_2 + 0xec) - *(float *)(local_28 + 0x60)) + local_14;
          fVar2 = (*(float *)(param_2 + 0xf0) - *(float *)(local_28 + 100)) + fVar2;
        }
        local_8 = local_8 * _DAT_00e39a48;
        local_c = local_c * _DAT_00e39a48;
        local_10 = _DAT_00e39a48 * local_10;
        local_14 = local_14 * _DAT_00e39a44;
        local_18 = local_18 * _DAT_00e39a44;
        local_1c = local_1c * _DAT_00e39a44;
        local_20 = _DAT_00e39a44 * local_20;
        fVar2 = fVar2 * _DAT_00e39a48;
        pfVar5[6] = local_20;
        pfVar5[7] = local_10;
        pfVar5[0x10] = local_1c;
        pfVar5[0x11] = local_c;
        pfVar5[0x1a] = local_18;
        pfVar5[0x1b] = local_8;
        pfVar5[0x24] = local_14;
        pfVar5[0x25] = fVar2;
        pfVar5[0x2e] = local_18;
        pfVar5[0x2f] = local_8;
        pfVar5[0x38] = local_1c;
        pfVar5[0x39] = local_c;
        pfVar5[8] = pfVar7[2];
        pfVar5[9] = pfVar7[3];
        pfVar5[0x12] = pfVar7[6];
        pfVar5[0x13] = pfVar7[7];
        pfVar5[0x1c] = pfVar7[10];
        pfVar5[0x1d] = pfVar7[0xb];
        pfVar5[0x26] = pfVar7[0xe];
        pfVar5[0x27] = pfVar7[0xf];
        pfVar5[0x30] = pfVar7[10];
        pfVar5[0x31] = pfVar7[0xb];
        pfVar5[0x3a] = pfVar7[6];
        fVar2 = pfVar7[7];
        pfVar5[2] = fVar4;
        pfVar5[0x3b] = fVar2;
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
        DAT_00e39a58 = DAT_00e39a58 + 0x3c;
        DAT_00e79678 = DAT_00e79678 + 6;
        local_2c = local_2c + 1;
        pfVar7 = pfVar7 + 0x10;
      } while (local_2c < *param_1);
      return 0;
    }
  }
  return 0;
}

