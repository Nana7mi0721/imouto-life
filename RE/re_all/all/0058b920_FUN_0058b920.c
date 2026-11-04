
undefined4 FUN_0058b920(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  uint local_9c;
  uint local_88;
  undefined1 *local_78;
  
  if (DAT_00a37dc8 == 1) {
    FUN_005db830(param_1,param_2);
    return 0;
  }
  uVar2 = (uint)(*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20)) / param_2;
  local_88 = (uint)(*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24)) / param_2;
  iVar3 = FUN_00586970(param_1,1);
  if (iVar3 < 0) {
    return 0xffffffff;
  }
  iVar3 = *(int *)(param_1 + 0x488);
  iVar4 = *(int *)(param_1 + 0xd08) + uVar2 * -4;
  pbVar9 = *(byte **)(param_1 + 0x48c);
  local_78 = *(undefined1 **)(param_1 + 0xd0c);
  if (param_2 == 2) {
    do {
      pbVar10 = pbVar9 + iVar3;
      local_9c = uVar2;
      do {
        *local_78 = (char)((int)((uint)pbVar10[4 - iVar3] + (uint)pbVar10[4] + (uint)*pbVar9 +
                                (uint)*pbVar10) >> 2);
        local_78[1] = (char)((int)((uint)pbVar10[1 - iVar3] + (uint)pbVar10[5 - iVar3] +
                                   (uint)pbVar10[5] + (uint)pbVar10[1]) >> 2);
        local_78[2] = (char)((int)((uint)pbVar10[2 - iVar3] + (uint)pbVar10[6 - iVar3] +
                                   (uint)pbVar10[6] + (uint)pbVar10[2]) >> 2);
        local_78[3] = (char)((int)((uint)pbVar10[3 - iVar3] + (uint)pbVar10[7 - iVar3] +
                                   (uint)pbVar10[7] + (uint)pbVar10[3]) >> 2);
        pbVar9 = pbVar9 + 8;
        pbVar10 = pbVar10 + 8;
        local_78 = local_78 + 4;
        local_9c = local_9c - 1;
      } while (local_9c != 0);
      pbVar9 = pbVar9 + iVar3 * 2 + uVar2 * -8;
      local_78 = local_78 + iVar4;
      local_88 = local_88 - 1;
    } while (local_88 != 0);
  }
  else if (param_2 == 4) {
    iVar1 = iVar3 * 3;
    do {
      pbVar10 = pbVar9 + iVar3 * 2 + 8;
      local_9c = uVar2;
      do {
        *local_78 = (char)((int)((uint)pbVar10[-8 - iVar3] + (uint)pbVar10[-4 - iVar3] +
                                 (uint)pbVar10[4 - iVar3] + (uint)pbVar10[iVar3 + -8] +
                                 (uint)pbVar10[iVar3 + -4] + (uint)pbVar9[iVar3 + 8] +
                                 (uint)pbVar10[-8] + (uint)pbVar10[-4] + (uint)pbVar10[4] +
                                 (uint)pbVar10[iVar3 + 4] + (uint)pbVar9[0xc] + (uint)pbVar9[8] +
                                 (uint)pbVar9[4] + (uint)*pbVar9 + (uint)*pbVar10 +
                                (uint)pbVar10[iVar3]) >> 4);
        local_78[1] = (char)((int)((uint)pbVar10[-7 - iVar3] + (uint)pbVar10[-3 - iVar3] +
                                   (uint)pbVar10[1 - iVar3] + (uint)pbVar10[5 - iVar3] +
                                   (uint)pbVar10[iVar3 + -7] + (uint)pbVar10[iVar3 + -3] +
                                   (uint)pbVar9[iVar1 + 0xd] + (uint)pbVar9[iVar1 + 9] +
                                   (uint)pbVar10[-7] + (uint)pbVar10[5] + (uint)pbVar10[-3] +
                                   (uint)pbVar10[1] + (uint)pbVar9[0xd] + (uint)pbVar9[9] +
                                   (uint)pbVar9[5] + (uint)pbVar9[1]) >> 4);
        local_78[2] = (char)((int)((uint)pbVar10[-6 - iVar3] + (uint)pbVar10[-2 - iVar3] +
                                   (uint)pbVar10[2 - iVar3] + (uint)pbVar10[6 - iVar3] +
                                   (uint)pbVar10[iVar3 + -2] + (uint)pbVar10[iVar3 + -6] +
                                   (uint)pbVar9[iVar1 + 10] + (uint)pbVar9[iVar1 + 0xe] +
                                   (uint)pbVar10[-6] + (uint)pbVar10[6] + (uint)pbVar10[-2] +
                                   (uint)pbVar10[2] + (uint)pbVar9[0xe] + (uint)pbVar9[10] +
                                   (uint)pbVar9[6] + (uint)pbVar9[2]) >> 4);
        local_78[3] = (char)((int)((uint)pbVar10[iVar3 + -1] + (uint)pbVar10[-5 - iVar3] +
                                   (uint)pbVar10[-1 - iVar3] + (uint)pbVar10[3 - iVar3] +
                                   (uint)pbVar10[7 - iVar3] + (uint)pbVar10[iVar3 + -5] +
                                   (uint)pbVar9[iVar1 + 0xb] + (uint)pbVar9[iVar1 + 0xf] +
                                   (uint)pbVar10[7] + (uint)pbVar10[-5] + (uint)pbVar10[3] +
                                   (uint)pbVar10[-1] + (uint)pbVar9[0xf] + (uint)pbVar9[0xb] +
                                   (uint)pbVar9[7] + (uint)pbVar9[3]) >> 4);
        pbVar9 = pbVar9 + 0x10;
        pbVar10 = pbVar10 + 0x10;
        local_78 = local_78 + 4;
        local_9c = local_9c - 1;
      } while (local_9c != 0);
      pbVar9 = pbVar9 + iVar3 * 4 + uVar2 * -0x10;
      local_78 = local_78 + iVar4;
      local_88 = local_88 - 1;
    } while (local_88 != 0);
  }
  else if (param_2 == 8) {
    iVar1 = iVar3 * 7;
    iVar5 = 1 - iVar3;
    iVar6 = 2 - iVar3;
    iVar7 = 3 - iVar3;
    do {
      pbVar10 = pbVar9 + iVar3 * 6 + 0x1c;
      pbVar11 = pbVar9 + iVar3 * 4 + 0x18;
      pbVar8 = pbVar9 + iVar3 * 2 + 0x18;
      local_9c = uVar2;
      do {
        *local_78 = (char)((int)((uint)pbVar11[iVar3] + (uint)pbVar10[iVar3] +
                                 (uint)pbVar8[-0x18 - iVar3] + (uint)pbVar8[-0x14 - iVar3] +
                                 (uint)pbVar8[-0x10 - iVar3] + (uint)pbVar8[-0xc - iVar3] +
                                 (uint)pbVar8[-8 - iVar3] + (uint)pbVar8[-4 - iVar3] +
                                 (uint)pbVar8[4 - iVar3] + (uint)pbVar11[4 - iVar3] +
                                 (uint)pbVar8[iVar3 + -0x18] + (uint)pbVar8[iVar3 + -0x14] +
                                 (uint)pbVar11[iVar3 + -0x18] + (uint)pbVar8[iVar3 + -0x10] +
                                 (uint)pbVar11[iVar3 + -0x14] + (uint)pbVar8[iVar3 + -8] +
                                 (uint)pbVar11[iVar3 + -0x10] + (uint)pbVar10[iVar3 + -0x18] +
                                 (uint)pbVar8[iVar3 + -4] + (uint)pbVar11[iVar3 + -8] +
                                 (uint)pbVar10[iVar3 + -0x14] + (uint)pbVar11[iVar3 + -4] +
                                 (uint)pbVar10[iVar3 + -0x10] + (uint)pbVar8[iVar3 + -0xc] +
                                 (uint)pbVar10[iVar3 + -8] + (uint)pbVar10[iVar3 + -4] +
                                 (uint)pbVar11[iVar3 + -0xc] + (uint)pbVar10[iVar3 + -0xc] +
                                 (uint)pbVar9[iVar3 + 0x18] + (uint)pbVar10[iVar3 + -0x1c] +
                                 (uint)pbVar9[iVar3 * 5 + 0x1c] + (uint)pbVar8[iVar3] +
                                 (uint)pbVar11[-0x18] + (uint)pbVar11[-0x14] + (uint)pbVar11[-0x10]
                                 + (uint)pbVar11[-0xc] + (uint)pbVar11[-8] + (uint)pbVar11[-4] +
                                 (uint)pbVar11[4] + (uint)pbVar10[-0x1c] + (uint)pbVar10[-0x18] +
                                 (uint)pbVar10[-0x14] + (uint)pbVar10[-0xc] + (uint)pbVar10[-8] +
                                 (uint)pbVar10[-4] + (uint)pbVar9[0x1c] + (uint)pbVar9[0x18] +
                                 (uint)pbVar9[0x14] + (uint)pbVar9[0x10] + (uint)pbVar9[0xc] +
                                 (uint)pbVar9[8] + (uint)pbVar9[4] + (uint)pbVar8[-0x18] +
                                 (uint)pbVar8[-0x14] + (uint)pbVar8[-0x10] + (uint)pbVar8[-0xc] +
                                 (uint)pbVar8[-8] + (uint)pbVar8[-4] + (uint)pbVar8[4] +
                                 (uint)*pbVar9 + (uint)*pbVar8 + (uint)*pbVar11 + (uint)*pbVar10 +
                                (uint)pbVar10[-0x10]) >> 6);
        local_78[1] = (char)((int)((uint)pbVar8[iVar3 + -0x17] + (uint)pbVar11[iVar3 + -0x17] +
                                   (uint)pbVar8[iVar3 + -0x13] + (uint)pbVar11[iVar3 + -0x13] +
                                   (uint)pbVar10[iVar3 + -0x17] + (uint)pbVar8[iVar3 + -0xb] +
                                   (uint)pbVar10[iVar3 + -0x13] + (uint)pbVar11[iVar3 + -0xb] +
                                   (uint)pbVar8[iVar3 + -7] + (uint)pbVar11[iVar3 + -7] +
                                   (uint)pbVar10[iVar3 + -0xb] + (uint)pbVar8[iVar3 + -0xf] +
                                   (uint)pbVar10[iVar3 + -7] + (uint)pbVar8[iVar3 + -3] +
                                   (uint)pbVar11[iVar3 + -0xf] + (uint)pbVar11[iVar3 + -3] +
                                   (uint)pbVar10[iVar3 + -0xf] + (uint)pbVar10[iVar3 + -3] +
                                   (uint)pbVar8[-0x17 - iVar3] + (uint)pbVar8[-0x13 - iVar3] +
                                   (uint)pbVar10[iVar3 + -0x1b] + (uint)pbVar8[-0xf - iVar3] +
                                   (uint)pbVar9[iVar1 + 0x1d] + (uint)pbVar8[-0xb - iVar3] +
                                   (uint)pbVar8[-7 - iVar3] + (uint)pbVar8[-3 - iVar3] +
                                   (uint)pbVar8[iVar5] + (uint)pbVar8[5 - iVar3] +
                                   (uint)pbVar11[iVar5] + (uint)pbVar11[5 - iVar3] +
                                   (uint)pbVar10[-3 - iVar3] + (uint)pbVar10[iVar5] +
                                   (uint)pbVar11[-0x17] + (uint)pbVar11[-0x13] + (uint)pbVar11[-0xf]
                                   + (uint)pbVar11[-0xb] + (uint)pbVar11[-7] + (uint)pbVar11[5] +
                                   (uint)pbVar11[-3] + (uint)pbVar11[1] + (uint)pbVar10[-0x1b] +
                                   (uint)pbVar10[-0x17] + (uint)pbVar10[-0x13] + (uint)pbVar10[-0xf]
                                   + (uint)pbVar10[-0xb] + (uint)pbVar10[-7] + (uint)pbVar10[-3] +
                                   (uint)pbVar10[1] + (uint)pbVar9[0x1d] + (uint)pbVar9[0x19] +
                                   (uint)pbVar9[0x15] + (uint)pbVar9[0x11] + (uint)pbVar9[0xd] +
                                   (uint)pbVar9[9] + (uint)pbVar9[5] + (uint)pbVar9[1] +
                                   (uint)pbVar8[-0x17] + (uint)pbVar8[-0x13] + (uint)pbVar8[-0xf] +
                                   (uint)pbVar8[-0xb] + (uint)pbVar8[-7] + (uint)pbVar8[5] +
                                   (uint)pbVar8[-3] + (uint)pbVar8[1]) >> 6);
        local_78[2] = (char)((int)((uint)pbVar8[-10 - iVar3] + (uint)pbVar8[-6 - iVar3] +
                                   (uint)pbVar8[-2 - iVar3] + (uint)pbVar8[iVar6] +
                                   (uint)pbVar8[6 - iVar3] + (uint)pbVar11[iVar6] +
                                   (uint)pbVar11[6 - iVar3] + (uint)pbVar10[-2 - iVar3] +
                                   (uint)pbVar8[iVar3 + -0x16] + (uint)pbVar10[iVar6] +
                                   (uint)pbVar11[iVar3 + -0x16] + (uint)pbVar10[iVar3 + -0x16] +
                                   (uint)pbVar9[iVar1 + 0x1e] + (uint)pbVar8[-0x16 - iVar3] +
                                   (uint)pbVar8[-0x12 - iVar3] + (uint)pbVar8[-0xe - iVar3] +
                                   (uint)pbVar10[iVar3 + -0x1a] + (uint)pbVar8[iVar3 + -0xe] +
                                   (uint)pbVar8[iVar3 + -10] + (uint)pbVar11[iVar3 + -0xe] +
                                   (uint)pbVar8[iVar3 + -2] + (uint)pbVar11[iVar3 + -10] +
                                   (uint)pbVar8[iVar3 + -0x12] + (uint)pbVar11[iVar3 + -2] +
                                   (uint)pbVar10[iVar3 + -0xe] + (uint)pbVar11[iVar3 + -0x12] +
                                   (uint)pbVar10[iVar3 + -10] + (uint)pbVar8[iVar3 + -6] +
                                   (uint)pbVar10[iVar3 + -2] + (uint)pbVar10[iVar3 + -0x12] +
                                   (uint)pbVar11[iVar3 + -6] + (uint)pbVar10[iVar3 + -6] +
                                   (uint)pbVar11[-0x16] + (uint)pbVar11[-0x12] + (uint)pbVar11[-0xe]
                                   + (uint)pbVar11[-10] + (uint)pbVar11[-6] + (uint)pbVar11[6] +
                                   (uint)pbVar11[-2] + (uint)pbVar11[2] + (uint)pbVar10[-0x1a] +
                                   (uint)pbVar10[-0x16] + (uint)pbVar10[-0x12] + (uint)pbVar10[-0xe]
                                   + (uint)pbVar10[-10] + (uint)pbVar10[-6] + (uint)pbVar10[-2] +
                                   (uint)pbVar10[2] + (uint)pbVar9[0x1e] + (uint)pbVar9[0x1a] +
                                   (uint)pbVar9[0x16] + (uint)pbVar9[0x12] + (uint)pbVar9[0xe] +
                                   (uint)pbVar9[10] + (uint)pbVar9[6] + (uint)pbVar9[2] +
                                   (uint)pbVar8[-0x16] + (uint)pbVar8[-0x12] + (uint)pbVar8[-0xe] +
                                   (uint)pbVar8[-10] + (uint)pbVar8[-6] + (uint)pbVar8[6] +
                                   (uint)pbVar8[-2] + (uint)pbVar8[2]) >> 6);
        local_78[3] = (char)((int)((uint)pbVar8[iVar3 + -1] + (uint)pbVar11[iVar3 + -1] +
                                   (uint)pbVar8[iVar3 + -9] + (uint)pbVar10[iVar3 + -1] +
                                   (uint)pbVar11[iVar3 + -9] + (uint)pbVar10[iVar3 + -9] +
                                   (uint)pbVar10[iVar3 + -0x19] + (uint)pbVar8[-5 - iVar3] +
                                   (uint)pbVar8[-1 - iVar3] + (uint)pbVar8[iVar7] +
                                   (uint)pbVar8[7 - iVar3] + (uint)pbVar11[iVar7] +
                                   (uint)pbVar11[7 - iVar3] + (uint)pbVar10[-1 - iVar3] +
                                   (uint)pbVar8[iVar3 + -0x15] + (uint)pbVar10[iVar7] +
                                   (uint)pbVar11[iVar3 + -0x15] + (uint)pbVar10[iVar3 + -0x15] +
                                   (uint)pbVar8[iVar3 + -0x11] + (uint)pbVar11[iVar3 + -0x11] +
                                   (uint)pbVar8[iVar3 + -0xd] + (uint)pbVar11[iVar3 + -0xd] +
                                   (uint)pbVar10[iVar3 + -0x11] + (uint)pbVar8[iVar3 + -5] +
                                   (uint)pbVar10[iVar3 + -0xd] + (uint)pbVar11[iVar3 + -5] +
                                   (uint)pbVar10[iVar3 + -5] + (uint)pbVar9[iVar1 + 0x1f] +
                                   (uint)pbVar8[-0x15 - iVar3] + (uint)pbVar8[-0x11 - iVar3] +
                                   (uint)pbVar8[-0xd - iVar3] + (uint)pbVar8[-9 - iVar3] +
                                   (uint)pbVar11[-0x15] + (uint)pbVar11[-0x11] + (uint)pbVar11[-0xd]
                                   + (uint)pbVar11[-9] + (uint)pbVar11[7] + (uint)pbVar11[-5] +
                                   (uint)pbVar11[3] + (uint)pbVar11[-1] + (uint)pbVar10[-0x19] +
                                   (uint)pbVar10[-0x15] + (uint)pbVar10[-0x11] + (uint)pbVar10[-0xd]
                                   + (uint)pbVar10[-9] + (uint)pbVar10[-5] + (uint)pbVar10[3] +
                                   (uint)pbVar10[-1] + (uint)pbVar9[0x1f] + (uint)pbVar9[0x1b] +
                                   (uint)pbVar9[0x17] + (uint)pbVar9[0x13] + (uint)pbVar9[0xf] +
                                   (uint)pbVar9[0xb] + (uint)pbVar9[7] + (uint)pbVar9[3] +
                                   (uint)pbVar8[-0x15] + (uint)pbVar8[-0x11] + (uint)pbVar8[-0xd] +
                                   (uint)pbVar8[-9] + (uint)pbVar8[7] + (uint)pbVar8[-5] +
                                   (uint)pbVar8[3] + (uint)pbVar8[-1]) >> 6);
        local_78 = local_78 + 4;
        pbVar9 = pbVar9 + 0x20;
        pbVar8 = pbVar8 + 0x20;
        pbVar11 = pbVar11 + 0x20;
        pbVar10 = pbVar10 + 0x20;
        local_9c = local_9c - 1;
      } while (local_9c != 0);
      local_78 = local_78 + iVar4;
      pbVar9 = pbVar9 + iVar3 * 8 + uVar2 * -0x20;
      local_88 = local_88 - 1;
    } while (local_88 != 0);
  }
  FUN_00586b00();
  return 0;
}

