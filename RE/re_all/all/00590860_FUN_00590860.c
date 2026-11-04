
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00590860(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  byte bVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  byte bVar16;
  byte bVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  byte *pbVar24;
  byte *pbVar25;
  byte *pbVar26;
  float10 fVar27;
  float fVar28;
  float fVar29;
  uint local_5c;
  int local_58;
  int local_54;
  uint local_50;
  uint local_34;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (DAT_00a37dc8 == 1) {
    FUN_005dbc00(param_1,param_2);
    return 0;
  }
  local_14 = 0;
  iVar9 = FUN_00586970(param_1,1);
  if (iVar9 < 0) {
    return 0xffffffff;
  }
  iVar9 = (int)ROUND(*(float *)(param_1 + 0x18) * (float)_DAT_008052e8);
  local_54 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24);
  pbVar25 = *(byte **)(param_1 + 0x48c);
  pbVar24 = *(byte **)(param_1 + 0x8cc);
  pbVar26 = *(byte **)(param_1 + 0xd0c);
  iVar19 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20);
  iVar10 = *(int *)(param_1 + 0xd08) + iVar19 * -4;
  iVar18 = *(int *)(param_1 + 0x488) + iVar19 * -4;
  switch(*(undefined4 *)(param_1 + 4)) {
  case 0:
    if (param_2 == 0) {
      do {
        iVar12 = iVar19;
        do {
          iVar23 = (uint)pbVar24[3] * iVar9;
          *pbVar26 = (byte)(((uint)*pbVar24 - (uint)*pbVar25) * iVar23 + (uint)*pbVar25 * 0x10000 >>
                           0x10);
          pbVar26[1] = (byte)(((uint)pbVar24[1] - (uint)pbVar25[1]) * iVar23 +
                              (uint)pbVar25[1] * 0x10000 >> 0x10);
          pbVar26[2] = (byte)(((uint)pbVar24[2] - (uint)pbVar25[2]) * iVar23 +
                              (uint)pbVar25[2] * 0x10000 >> 0x10);
          pbVar26[3] = pbVar25[3];
          pbVar25 = pbVar25 + 4;
          pbVar24 = pbVar24 + 4;
          pbVar26 = pbVar26 + 4;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
        pbVar26 = pbVar26 + iVar10;
        pbVar25 = pbVar25 + iVar18;
        pbVar24 = pbVar24 + iVar18;
        local_54 = local_54 + -1;
      } while (local_54 != 0);
      FUN_00586b00();
      return 0;
    }
  case 0x11:
    do {
      local_58 = iVar19;
      do {
        bVar7 = pbVar25[3];
        bVar8 = pbVar24[3];
        bVar16 = (&DAT_00a62a60)[CONCAT11(pbVar25[1],bVar7)];
        bVar17 = (&DAT_00a62a60)[CONCAT11(pbVar25[2],bVar7)];
        bVar3 = (&DAT_00a62a60)[CONCAT11(pbVar24[1],bVar8)];
        bVar4 = (&DAT_00a62a60)[CONCAT11(pbVar24[2],bVar8)];
        iVar12 = (uint)bVar8 * iVar9;
        *pbVar26 = (&DAT_00a52a60)
                   [(uint)bVar7 +
                    ((int)(((uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,bVar8)] -
                           (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar25,bVar7)]) * iVar12 +
                          (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar25,bVar7)] * 0x10000) >> 0x10 &
                    0xffU) * 0x100];
        pbVar26[1] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)(((uint)bVar3 - (uint)bVar16) * iVar12 + (uint)bVar16 * 0x10000) >> 0x10
                      & 0xffU) * 0x100];
        pbVar26[2] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)(((uint)bVar4 - (uint)bVar17) * iVar12 + (uint)bVar17 * 0x10000) >> 0x10
                      & 0xffU) * 0x100];
        pbVar26[3] = pbVar25[3];
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        local_58 = local_58 + -1;
      } while (local_58 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    FUN_00586b00();
    return 0;
  case 2:
    if (param_2 == 0) {
      do {
        local_58 = iVar19;
        do {
          bVar7 = pbVar25[1];
          bVar8 = pbVar24[1];
          bVar16 = pbVar25[2];
          bVar17 = pbVar24[2];
          iVar12 = (uint)pbVar24[3] * iVar9;
          uVar15 = (uint)*pbVar25;
          *pbVar26 = (byte)((((int)(*pbVar24 * uVar15) >> 8) - uVar15) * iVar12 + uVar15 * 0x10000
                           >> 0x10);
          pbVar26[1] = (byte)((((int)((uint)bVar8 * (uint)bVar7) >> 8) - (uint)pbVar25[1]) * iVar12
                              + (uint)pbVar25[1] * 0x10000 >> 0x10);
          pbVar26[2] = (byte)((((int)((uint)bVar17 * (uint)bVar16) >> 8) - (uint)pbVar25[2]) *
                              iVar12 + (uint)pbVar25[2] * 0x10000 >> 0x10);
          pbVar26[3] = pbVar25[3];
          pbVar25 = pbVar25 + 4;
          pbVar24 = pbVar24 + 4;
          pbVar26 = pbVar26 + 4;
          local_58 = local_58 + -1;
        } while (local_58 != 0);
        pbVar26 = pbVar26 + iVar10;
        pbVar25 = pbVar25 + iVar18;
        pbVar24 = pbVar24 + iVar18;
        local_54 = local_54 + -1;
      } while (local_54 != 0);
      FUN_00586b00();
      return 0;
    }
  case 0x13:
    do {
      local_58 = iVar19;
      do {
        bVar7 = pbVar25[3];
        uVar11 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[1],bVar7)];
        uVar15 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar25,bVar7)];
        uVar14 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[2],bVar7)];
        bVar7 = (&DAT_00a62a60)[CONCAT11(pbVar24[1],pbVar24[3])];
        iVar12 = (uint)pbVar24[3] * iVar9;
        bVar8 = (&DAT_00a62a60)[CONCAT11(pbVar24[2],pbVar24[3])];
        *pbVar26 = (&DAT_00a52a60)
                   [(uint)pbVar25[3] +
                    ((int)((((int)((byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,pbVar24[3])] * uVar15) >>
                            8) - uVar15) * iVar12 + uVar15 * 0x10000) >> 0x10 & 0xffU) * 0x100];
        pbVar26[1] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((((int)(bVar7 * uVar11) >> 8) - uVar11) * iVar12 + uVar11 * 0x10000) >>
                       0x10 & 0xffU) * 0x100];
        pbVar26[2] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((((int)(bVar8 * uVar14) >> 8) - uVar14) * iVar12 + uVar14 * 0x10000) >>
                       0x10 & 0xffU) * 0x100];
        pbVar26[3] = pbVar25[3];
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        local_58 = local_58 + -1;
      } while (local_58 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    FUN_00586b00();
    return 0;
  case 3:
    if (param_2 == 0) {
      do {
        local_58 = iVar19;
        do {
          uVar15 = (uint)*pbVar25;
          iVar12 = (uint)pbVar24[3] * iVar9;
          local_50 = uVar15 - *pbVar24;
          local_5c = (uint)pbVar25[1] - (uint)pbVar24[1];
          iVar23 = (uint)pbVar25[2] - (uint)pbVar24[2];
          if ((int)local_50 < 0) {
            local_50 = 0;
          }
          if ((int)local_5c < 0) {
            local_5c = 0;
          }
          if (iVar23 < 0) {
            iVar23 = 0;
          }
          *pbVar26 = (byte)((local_50 - uVar15) * iVar12 + uVar15 * 0x10000 >> 0x10);
          pbVar26[1] = (byte)((local_5c - pbVar25[1]) * iVar12 + (uint)pbVar25[1] * 0x10000 >> 0x10)
          ;
          pbVar26[2] = (byte)((iVar23 - (uint)pbVar25[2]) * iVar12 + (uint)pbVar25[2] * 0x10000 >>
                             0x10);
          pbVar26[3] = pbVar25[3];
          pbVar25 = pbVar25 + 4;
          pbVar24 = pbVar24 + 4;
          pbVar26 = pbVar26 + 4;
          local_58 = local_58 + -1;
        } while (local_58 != 0);
        pbVar26 = pbVar26 + iVar10;
        pbVar25 = pbVar25 + iVar18;
        pbVar24 = pbVar24 + iVar18;
        local_54 = local_54 + -1;
      } while (local_54 != 0);
      FUN_00586b00();
      return 0;
    }
  case 0x14:
    do {
      local_58 = iVar19;
      do {
        bVar7 = pbVar25[3];
        uVar11 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[1],bVar7)];
        uVar15 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar25,bVar7)];
        uVar14 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[2],bVar7)];
        iVar12 = (uint)pbVar24[3] * iVar9;
        local_50 = uVar15 - (byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,pbVar24[3])];
        local_5c = uVar11 - (byte)(&DAT_00a62a60)[CONCAT11(pbVar24[1],pbVar24[3])];
        iVar23 = uVar14 - (byte)(&DAT_00a62a60)[CONCAT11(pbVar24[2],pbVar24[3])];
        if ((int)local_50 < 0) {
          local_50 = 0;
        }
        if ((int)local_5c < 0) {
          local_5c = 0;
        }
        if (iVar23 < 0) {
          iVar23 = 0;
        }
        *pbVar26 = (&DAT_00a52a60)
                   [(uint)pbVar25[3] +
                    ((int)((local_50 - uVar15) * iVar12 + uVar15 * 0x10000) >> 0x10 & 0xffU) * 0x100
                   ];
        pbVar26[1] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_5c - uVar11) * iVar12 + uVar11 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[2] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((iVar23 - uVar14) * iVar12 + uVar14 * 0x10000) >> 0x10 & 0xffU) * 0x100
                     ];
        pbVar26[3] = pbVar25[3];
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        local_58 = local_58 + -1;
      } while (local_58 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    FUN_00586b00();
    return 0;
  case 4:
    if (param_2 == 0) {
      do {
        local_58 = iVar19;
        do {
          uVar15 = (uint)*pbVar25;
          iVar12 = (uint)pbVar24[3] * iVar9;
          local_50 = *pbVar24 + uVar15;
          local_5c = (uint)pbVar24[1] + (uint)pbVar25[1];
          uVar14 = (uint)pbVar24[2] + (uint)pbVar25[2];
          if (0xff < local_50) {
            local_50 = 0xff;
          }
          if (0xff < local_5c) {
            local_5c = 0xff;
          }
          if (0xff < uVar14) {
            uVar14 = 0xff;
          }
          *pbVar26 = (byte)((local_50 - uVar15) * iVar12 + uVar15 * 0x10000 >> 0x10);
          pbVar26[1] = (byte)((local_5c - pbVar25[1]) * iVar12 + (uint)pbVar25[1] * 0x10000 >> 0x10)
          ;
          pbVar26[2] = (byte)((uVar14 - pbVar25[2]) * iVar12 + (uint)pbVar25[2] * 0x10000 >> 0x10);
          pbVar26[3] = pbVar25[3];
          pbVar25 = pbVar25 + 4;
          pbVar24 = pbVar24 + 4;
          pbVar26 = pbVar26 + 4;
          local_58 = local_58 + -1;
        } while (local_58 != 0);
        pbVar26 = pbVar26 + iVar10;
        pbVar25 = pbVar25 + iVar18;
        pbVar24 = pbVar24 + iVar18;
        local_54 = local_54 + -1;
      } while (local_54 != 0);
      FUN_00586b00();
      return 0;
    }
  case 0x15:
    do {
      local_58 = iVar19;
      do {
        bVar7 = pbVar25[3];
        uVar11 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[1],bVar7)];
        uVar15 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar25,bVar7)];
        uVar14 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[2],bVar7)];
        iVar12 = (uint)pbVar24[3] * iVar9;
        local_50 = (byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,pbVar24[3])] + uVar15;
        local_5c = (byte)(&DAT_00a62a60)[CONCAT11(pbVar24[1],pbVar24[3])] + uVar11;
        local_34 = (byte)(&DAT_00a62a60)[CONCAT11(pbVar24[2],pbVar24[3])] + uVar14;
        if (0xff < local_50) {
          local_50 = 0xff;
        }
        if (0xff < local_5c) {
          local_5c = 0xff;
        }
        if (0xff < local_34) {
          local_34 = 0xff;
        }
        *pbVar26 = (&DAT_00a52a60)
                   [(uint)pbVar25[3] +
                    ((int)((local_50 - uVar15) * iVar12 + uVar15 * 0x10000) >> 0x10 & 0xffU) * 0x100
                   ];
        pbVar26[1] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_5c - uVar11) * iVar12 + uVar11 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[2] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_34 - uVar14) * iVar12 + uVar14 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[3] = pbVar25[3];
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        local_58 = local_58 + -1;
      } while (local_58 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    FUN_00586b00();
    return 0;
  case 5:
    if (param_2 == 0) {
      do {
        local_58 = iVar19;
        do {
          iVar12 = (uint)pbVar24[3] * iVar9;
          uVar15 = (uint)*pbVar25;
          iVar23 = 0xff - ((int)((0xff - (uint)*pbVar24) * (0xff - uVar15)) >> 8);
          local_5c = 0xff - ((int)((0xff - (uint)pbVar24[1]) * (0xff - (uint)pbVar25[1])) >> 8);
          iVar13 = 0xff - ((int)((0xff - (uint)pbVar24[2]) * (0xff - (uint)pbVar25[2])) >> 8);
          if (0xff < iVar23) {
            iVar23 = 0xff;
          }
          if (0xff < (int)local_5c) {
            local_5c = 0xff;
          }
          if (0xff < iVar13) {
            iVar13 = 0xff;
          }
          *pbVar26 = (byte)((iVar23 - uVar15) * iVar12 + uVar15 * 0x10000 >> 0x10);
          pbVar26[1] = (byte)((local_5c - pbVar25[1]) * iVar12 + (uint)pbVar25[1] * 0x10000 >> 0x10)
          ;
          pbVar26[2] = (byte)((iVar13 - (uint)pbVar25[2]) * iVar12 + (uint)pbVar25[2] * 0x10000 >>
                             0x10);
          pbVar26[3] = pbVar25[3];
          pbVar25 = pbVar25 + 4;
          pbVar24 = pbVar24 + 4;
          pbVar26 = pbVar26 + 4;
          local_58 = local_58 + -1;
        } while (local_58 != 0);
        pbVar26 = pbVar26 + iVar10;
        pbVar25 = pbVar25 + iVar18;
        pbVar24 = pbVar24 + iVar18;
        local_54 = local_54 + -1;
      } while (local_54 != 0);
      FUN_00586b00();
      return 0;
    }
  case 0x16:
    do {
      local_58 = iVar19;
      do {
        bVar7 = pbVar25[3];
        uVar14 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar25,bVar7)];
        uVar11 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[1],bVar7)];
        iVar12 = iVar9 * (uint)pbVar24[3];
        uVar15 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[2],bVar7)];
        iVar23 = 0xff - ((int)((0xff - (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,pbVar24[3])]) *
                              (0xff - uVar14)) >> 8);
        local_5c = 0xff - ((int)((0xff - (uint)(byte)(&DAT_00a62a60)
                                                     [CONCAT11(pbVar24[1],pbVar24[3])]) *
                                (0xff - uVar11)) >> 8);
        local_34 = 0xff - ((int)((0xff - (uint)(byte)(&DAT_00a62a60)
                                                     [CONCAT11(pbVar24[2],pbVar24[3])]) *
                                (0xff - uVar15)) >> 8);
        if (0xff < iVar23) {
          iVar23 = 0xff;
        }
        if (0xff < (int)local_5c) {
          local_5c = 0xff;
        }
        if (0xff < (int)local_34) {
          local_34 = 0xff;
        }
        *pbVar26 = (&DAT_00a52a60)
                   [(uint)pbVar25[3] +
                    ((int)((iVar23 - uVar14) * iVar12 + uVar14 * 0x10000) >> 0x10 & 0xffU) * 0x100];
        pbVar26[1] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_5c - uVar11) * iVar12 + uVar11 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[2] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_34 - uVar15) * iVar12 + uVar15 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[3] = pbVar25[3];
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        local_58 = local_58 + -1;
      } while (local_58 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    FUN_00586b00();
    return 0;
  case 6:
    if (param_2 == 0) {
      do {
        local_58 = iVar19;
        do {
          iVar12 = (uint)pbVar24[3] * iVar9;
          uVar15 = (uint)*pbVar25;
          if (*pbVar25 < 0x80) {
            local_50 = (int)(*pbVar24 * uVar15 * 2) >> 8;
          }
          else {
            local_50 = ((int)(((0x100 - uVar15) * (uint)*pbVar24 + uVar15 * 0x100) * 2) >> 8) +
                       -0xff;
          }
          if (0xff < (int)local_50) {
            local_50 = 0xff;
          }
          if (pbVar25[1] < 0x80) {
            local_5c = (int)((uint)pbVar24[1] * (uint)pbVar25[1] * 2) >> 8;
          }
          else {
            local_5c = ((int)(((uint)pbVar24[1] * (0x100 - (uint)pbVar25[1]) +
                              (uint)pbVar25[1] * 0x100) * 2) >> 8) + -0xff;
          }
          if (0xff < (int)local_5c) {
            local_5c = 0xff;
          }
          if (pbVar25[2] < 0x80) {
            local_34 = (int)((uint)pbVar24[2] * (uint)pbVar25[2] * 2) >> 8;
          }
          else {
            local_34 = ((int)(((uint)pbVar24[2] * (0x100 - (uint)pbVar25[2]) +
                              (uint)pbVar25[2] * 0x100) * 2) >> 8) + -0xff;
          }
          if (0xff < (int)local_34) {
            local_34 = 0xff;
          }
          *pbVar26 = (byte)((local_50 - uVar15) * iVar12 + uVar15 * 0x10000 >> 0x10);
          pbVar26[1] = (byte)((local_5c - pbVar25[1]) * iVar12 + (uint)pbVar25[1] * 0x10000 >> 0x10)
          ;
          pbVar26[2] = (byte)((local_34 - pbVar25[2]) * iVar12 + (uint)pbVar25[2] * 0x10000 >> 0x10)
          ;
          pbVar26[3] = pbVar25[3];
          pbVar25 = pbVar25 + 4;
          pbVar24 = pbVar24 + 4;
          pbVar26 = pbVar26 + 4;
          local_58 = local_58 + -1;
        } while (local_58 != 0);
        pbVar26 = pbVar26 + iVar10;
        pbVar25 = pbVar25 + iVar18;
        pbVar24 = pbVar24 + iVar18;
        local_54 = local_54 + -1;
      } while (local_54 != 0);
      FUN_00586b00();
      return 0;
    }
  case 0x17:
    do {
      local_58 = iVar19;
      do {
        bVar7 = pbVar24[3];
        bVar8 = pbVar25[3];
        iVar12 = iVar9 * (uint)bVar7;
        uVar11 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[1],bVar8)];
        uVar15 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar25,bVar8)];
        uVar14 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[2],bVar8)];
        if (uVar15 < 0x80) {
          local_50 = (int)((byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,bVar7)] * uVar15 * 2) >> 8;
        }
        else {
          local_50 = ((int)(((0x100 - uVar15) *
                             (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,bVar7)] + uVar15 * 0x100)
                           * 2) >> 8) + -0xff;
        }
        if (0xff < (int)local_50) {
          local_50 = 0xff;
        }
        if (uVar11 < 0x80) {
          local_5c = (int)((byte)(&DAT_00a62a60)[CONCAT11(pbVar24[1],bVar7)] * uVar11 * 2) >> 8;
        }
        else {
          local_5c = ((int)(((0x100 - uVar11) *
                             (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar24[1],bVar7)] +
                            uVar11 * 0x100) * 2) >> 8) + -0xff;
        }
        if (0xff < (int)local_5c) {
          local_5c = 0xff;
        }
        if (uVar14 < 0x80) {
          local_34 = (int)((byte)(&DAT_00a62a60)[CONCAT11(pbVar24[2],bVar7)] * uVar14 * 2) >> 8;
        }
        else {
          local_34 = ((int)(((0x100 - uVar14) *
                             (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar24[2],bVar7)] +
                            uVar14 * 0x100) * 2) >> 8) + -0xff;
        }
        if (0xff < (int)local_34) {
          local_34 = 0xff;
        }
        *pbVar26 = (&DAT_00a52a60)
                   [(uint)pbVar25[3] +
                    ((int)((local_50 - uVar15) * iVar12 + uVar15 * 0x10000) >> 0x10 & 0xffU) * 0x100
                   ];
        pbVar26[1] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_5c - uVar11) * iVar12 + uVar11 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[2] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_34 - uVar14) * iVar12 + uVar14 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[3] = pbVar25[3];
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        local_58 = local_58 + -1;
      } while (local_58 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    FUN_00586b00();
    return 0;
  case 7:
    if (param_2 == 0) {
      do {
        local_58 = iVar19;
        do {
          iVar12 = (uint)pbVar24[3] * iVar9;
          if ((*pbVar24 == 0xff) ||
             (local_50 = (uint)((longlong)((ulonglong)*pbVar25 << 8) /
                               (longlong)(int)(0xff - (uint)*pbVar24)), 0xff < (int)local_50)) {
            local_50 = 0xff;
          }
          if ((pbVar24[1] == 0xff) ||
             (local_5c = (uint)((longlong)((ulonglong)pbVar25[1] << 8) /
                               (longlong)(int)(0xff - (uint)pbVar24[1])), 0xff < (int)local_5c)) {
            local_5c = 0xff;
          }
          if (pbVar24[2] == 0xff) {
            iVar23 = 0xff;
          }
          else {
            iVar23 = (int)((longlong)((ulonglong)pbVar25[2] << 8) /
                          (longlong)(int)(0xff - (uint)pbVar24[2]));
            if (0xff < iVar23) {
              iVar23 = 0xff;
            }
          }
          *pbVar26 = (byte)((local_50 - *pbVar25) * iVar12 + (uint)*pbVar25 * 0x10000 >> 0x10);
          pbVar26[1] = (byte)((local_5c - pbVar25[1]) * iVar12 + (uint)pbVar25[1] * 0x10000 >> 0x10)
          ;
          pbVar26[2] = (byte)((iVar23 - (uint)pbVar25[2]) * iVar12 + (uint)pbVar25[2] * 0x10000 >>
                             0x10);
          pbVar26[3] = pbVar25[3];
          pbVar25 = pbVar25 + 4;
          pbVar24 = pbVar24 + 4;
          pbVar26 = pbVar26 + 4;
          local_58 = local_58 + -1;
        } while (local_58 != 0);
        pbVar26 = pbVar26 + iVar10;
        pbVar25 = pbVar25 + iVar18;
        pbVar24 = pbVar24 + iVar18;
        local_54 = local_54 + -1;
      } while (local_54 != 0);
      FUN_00586b00();
      return 0;
    }
  case 0x18:
    do {
      local_58 = iVar19;
      do {
        bVar7 = pbVar25[3];
        uVar14 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar25,bVar7)];
        bVar8 = pbVar24[3];
        uVar11 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[1],bVar7)];
        iVar12 = iVar9 * (uint)bVar8;
        uVar15 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[2],bVar7)];
        if ((0xfe < (byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,bVar8)]) ||
           (local_50 = (int)(uVar14 << 8) /
                       (int)(0xff - (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,bVar8)]),
           0xff < (int)local_50)) {
          local_50 = 0xff;
        }
        if ((0xfe < (byte)(&DAT_00a62a60)[CONCAT11(pbVar24[1],bVar8)]) ||
           (local_5c = (int)(uVar11 << 8) /
                       (int)(0xff - (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar24[1],bVar8)]),
           0xff < (int)local_5c)) {
          local_5c = 0xff;
        }
        if ((byte)(&DAT_00a62a60)[CONCAT11(pbVar24[2],bVar8)] < 0xff) {
          iVar23 = (int)(uVar15 << 8) /
                   (int)(0xff - (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar24[2],bVar8)]);
          if (0xff < iVar23) {
            iVar23 = 0xff;
          }
        }
        else {
          iVar23 = 0xff;
        }
        *pbVar26 = (&DAT_00a52a60)
                   [(uint)pbVar25[3] +
                    ((int)((local_50 - uVar14) * iVar12 + uVar14 * 0x10000) >> 0x10 & 0xffU) * 0x100
                   ];
        pbVar26[1] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_5c - uVar11) * iVar12 + uVar11 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[2] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((iVar23 - uVar15) * iVar12 + uVar15 * 0x10000) >> 0x10 & 0xffU) * 0x100
                     ];
        pbVar26[3] = pbVar25[3];
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        local_58 = local_58 + -1;
      } while (local_58 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    FUN_00586b00();
    return 0;
  case 8:
    if (param_2 == 0) {
      do {
        local_58 = iVar19;
        do {
          iVar12 = (uint)pbVar24[3] * iVar9;
          uVar15 = (uint)*pbVar25;
          local_50 = (int)((uVar15 - 0xff) * 0x100) / (int)(*pbVar24 + 1) + 0xff;
          if ((int)local_50 < 0) {
            local_50 = 0;
          }
          local_5c = (int)((pbVar25[1] - 0xff) * 0x100) / (int)(pbVar24[1] + 1) + 0xff;
          if ((int)local_5c < 0) {
            local_5c = 0;
          }
          iVar23 = (int)((pbVar25[2] - 0xff) * 0x100) / (int)(pbVar24[2] + 1) + 0xff;
          if (iVar23 < 0) {
            iVar23 = 0;
          }
          *pbVar26 = (byte)((local_50 - uVar15) * iVar12 + uVar15 * 0x10000 >> 0x10);
          pbVar26[1] = (byte)((local_5c - pbVar25[1]) * iVar12 + (uint)pbVar25[1] * 0x10000 >> 0x10)
          ;
          pbVar26[2] = (byte)((iVar23 - (uint)pbVar25[2]) * iVar12 + (uint)pbVar25[2] * 0x10000 >>
                             0x10);
          pbVar26[3] = pbVar25[3];
          pbVar25 = pbVar25 + 4;
          pbVar24 = pbVar24 + 4;
          pbVar26 = pbVar26 + 4;
          local_58 = local_58 + -1;
        } while (local_58 != 0);
        pbVar26 = pbVar26 + iVar10;
        pbVar25 = pbVar25 + iVar18;
        pbVar24 = pbVar24 + iVar18;
        local_54 = local_54 + -1;
      } while (local_54 != 0);
      FUN_00586b00();
      return 0;
    }
  case 0x19:
    do {
      local_58 = iVar19;
      do {
        bVar7 = pbVar25[3];
        uVar14 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar25,bVar7)];
        bVar8 = pbVar24[3];
        uVar11 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[1],bVar7)];
        uVar15 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[2],bVar7)];
        iVar12 = (uint)bVar8 * iVar9;
        local_50 = (int)((uVar14 - 0xff) * 0x100) /
                   (int)((byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,bVar8)] + 1) + 0xff;
        if ((int)local_50 < 0) {
          local_50 = 0;
        }
        local_5c = (int)((uVar11 - 0xff) * 0x100) /
                   (int)((byte)(&DAT_00a62a60)[CONCAT11(pbVar24[1],bVar8)] + 1) + 0xff;
        if ((int)local_5c < 0) {
          local_5c = 0;
        }
        iVar23 = (int)((uVar15 - 0xff) * 0x100) /
                 (int)((byte)(&DAT_00a62a60)[CONCAT11(pbVar24[2],bVar8)] + 1) + 0xff;
        if (iVar23 < 0) {
          iVar23 = 0;
        }
        *pbVar26 = (&DAT_00a52a60)
                   [(uint)pbVar25[3] +
                    ((int)((local_50 - uVar14) * iVar12 + uVar14 * 0x10000) >> 0x10 & 0xffU) * 0x100
                   ];
        pbVar26[1] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_5c - uVar11) * iVar12 + uVar11 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[2] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((iVar23 - uVar15) * iVar12 + uVar15 * 0x10000) >> 0x10 & 0xffU) * 0x100
                     ];
        pbVar26[3] = pbVar25[3];
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        local_58 = local_58 + -1;
      } while (local_58 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    FUN_00586b00();
    return 0;
  case 9:
    if (param_2 == 0) {
      do {
        local_58 = iVar19;
        do {
          bVar7 = *pbVar25;
          iVar12 = (uint)pbVar24[3] * iVar9;
          bVar8 = *pbVar24;
          if (bVar7 < *pbVar24) {
            bVar8 = bVar7;
          }
          bVar16 = pbVar25[1];
          if (pbVar24[1] <= pbVar25[1]) {
            bVar16 = pbVar24[1];
          }
          bVar17 = pbVar25[2];
          if (pbVar24[2] <= pbVar25[2]) {
            bVar17 = pbVar24[2];
          }
          *pbVar26 = (byte)(((uint)bVar8 - (uint)bVar7) * iVar12 + (uint)bVar7 * 0x10000 >> 0x10);
          pbVar26[1] = (byte)(((uint)bVar16 - (uint)pbVar25[1]) * iVar12 +
                              (uint)pbVar25[1] * 0x10000 >> 0x10);
          pbVar26[2] = (byte)(((uint)bVar17 - (uint)pbVar25[2]) * iVar12 +
                              (uint)pbVar25[2] * 0x10000 >> 0x10);
          pbVar26[3] = pbVar25[3];
          pbVar25 = pbVar25 + 4;
          pbVar24 = pbVar24 + 4;
          pbVar26 = pbVar26 + 4;
          local_58 = local_58 + -1;
        } while (local_58 != 0);
        pbVar26 = pbVar26 + iVar10;
        pbVar25 = pbVar25 + iVar18;
        pbVar24 = pbVar24 + iVar18;
        local_54 = local_54 + -1;
      } while (local_54 != 0);
      FUN_00586b00();
      return 0;
    }
  case 0x1a:
    do {
      local_58 = iVar19;
      do {
        bVar7 = pbVar25[3];
        uVar11 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[1],bVar7)];
        uVar15 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar25,bVar7)];
        uVar14 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[2],bVar7)];
        iVar12 = (uint)pbVar24[3] * iVar9;
        bVar7 = pbVar24[3];
        local_50 = uVar15;
        if ((byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,bVar7)] <= uVar15) {
          local_50 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,bVar7)];
        }
        local_5c = uVar11;
        if ((byte)(&DAT_00a62a60)[CONCAT11(pbVar24[1],bVar7)] <= uVar11) {
          local_5c = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar24[1],bVar7)];
        }
        local_34 = uVar14;
        if ((byte)(&DAT_00a62a60)[CONCAT11(pbVar24[2],bVar7)] <= uVar14) {
          local_34 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar24[2],bVar7)];
        }
        *pbVar26 = (&DAT_00a52a60)
                   [(uint)pbVar25[3] +
                    ((int)((local_50 - uVar15) * iVar12 + uVar15 * 0x10000) >> 0x10 & 0xffU) * 0x100
                   ];
        pbVar26[1] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_5c - uVar11) * iVar12 + uVar11 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[2] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_34 - uVar14) * iVar12 + uVar14 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[3] = pbVar25[3];
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        local_58 = local_58 + -1;
      } while (local_58 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    FUN_00586b00();
    return 0;
  case 10:
    if (param_2 == 0) {
      do {
        local_58 = iVar19;
        do {
          bVar7 = *pbVar25;
          iVar12 = (uint)pbVar24[3] * iVar9;
          bVar8 = *pbVar24;
          if (*pbVar24 < bVar7) {
            bVar8 = bVar7;
          }
          bVar16 = pbVar25[1];
          if (pbVar25[1] <= pbVar24[1]) {
            bVar16 = pbVar24[1];
          }
          bVar17 = pbVar25[2];
          if (pbVar25[2] <= pbVar24[2]) {
            bVar17 = pbVar24[2];
          }
          *pbVar26 = (byte)(((uint)bVar8 - (uint)bVar7) * iVar12 + (uint)bVar7 * 0x10000 >> 0x10);
          pbVar26[1] = (byte)(((uint)bVar16 - (uint)pbVar25[1]) * iVar12 +
                              (uint)pbVar25[1] * 0x10000 >> 0x10);
          pbVar26[2] = (byte)(((uint)bVar17 - (uint)pbVar25[2]) * iVar12 +
                              (uint)pbVar25[2] * 0x10000 >> 0x10);
          pbVar26[3] = pbVar25[3];
          pbVar25 = pbVar25 + 4;
          pbVar24 = pbVar24 + 4;
          pbVar26 = pbVar26 + 4;
          local_58 = local_58 + -1;
        } while (local_58 != 0);
        pbVar26 = pbVar26 + iVar10;
        pbVar25 = pbVar25 + iVar18;
        pbVar24 = pbVar24 + iVar18;
        local_54 = local_54 + -1;
      } while (local_54 != 0);
      FUN_00586b00();
      return 0;
    }
  case 0x1b:
    do {
      local_58 = iVar19;
      do {
        bVar7 = pbVar25[3];
        uVar11 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[1],bVar7)];
        uVar15 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar25,bVar7)];
        uVar14 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[2],bVar7)];
        iVar12 = (uint)pbVar24[3] * iVar9;
        bVar7 = pbVar24[3];
        local_50 = uVar15;
        if (uVar15 <= (byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,bVar7)]) {
          local_50 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,bVar7)];
        }
        local_5c = uVar11;
        if (uVar11 <= (byte)(&DAT_00a62a60)[CONCAT11(pbVar24[1],bVar7)]) {
          local_5c = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar24[1],bVar7)];
        }
        local_34 = uVar14;
        if (uVar14 <= (byte)(&DAT_00a62a60)[CONCAT11(pbVar24[2],bVar7)]) {
          local_34 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar24[2],bVar7)];
        }
        *pbVar26 = (&DAT_00a52a60)
                   [(uint)pbVar25[3] +
                    ((int)((local_50 - uVar15) * iVar12 + uVar15 * 0x10000) >> 0x10 & 0xffU) * 0x100
                   ];
        pbVar26[1] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_5c - uVar11) * iVar12 + uVar11 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[2] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_34 - uVar14) * iVar12 + uVar14 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[3] = pbVar25[3];
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        local_58 = local_58 + -1;
      } while (local_58 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    FUN_00586b00();
    return 0;
  case 0xb:
    if (param_2 == 0) {
      do {
        local_58 = iVar19;
        do {
          fVar28 = (float)_DAT_0081ec30;
          bVar7 = *pbVar24;
          iVar12 = (uint)pbVar24[3] * iVar9;
          if (bVar7 < 0x80) {
            bVar8 = *pbVar25;
            fVar29 = 1.0 - (float)bVar7 / fVar28;
            fVar29 = fVar29 + fVar29;
          }
          else {
            bVar8 = *pbVar25;
            fVar29 = (float)_DAT_00804a60 / ((float)bVar7 / fVar28);
          }
          fVar27 = (float10)FUN_0056d500((float)bVar8 / fVar28,fVar29);
          local_20 = (float)fVar27;
          bVar7 = pbVar24[1];
          if (bVar7 < 0x80) {
            fVar29 = 1.0 - (float)bVar7 / (float)_DAT_0081ec30;
            fVar29 = fVar29 + fVar29;
            fVar28 = (float)pbVar25[1] / (float)_DAT_0081ec30;
          }
          else {
            fVar29 = (float)_DAT_00804a60 / ((float)bVar7 / (float)_DAT_0081ec30);
            fVar28 = (float)pbVar25[1] / (float)_DAT_0081ec30;
          }
          fVar27 = (float10)FUN_0056d500(fVar28,fVar29);
          local_1c = (float)fVar27;
          bVar7 = pbVar24[2];
          if (bVar7 < 0x80) {
            fVar29 = 1.0 - (float)bVar7 / (float)_DAT_0081ec30;
            fVar29 = fVar29 + fVar29;
            fVar28 = (float)pbVar25[2] / (float)_DAT_0081ec30;
          }
          else {
            fVar29 = (float)_DAT_00804a60 / ((float)bVar7 / (float)_DAT_0081ec30);
            fVar28 = (float)pbVar25[2] / (float)_DAT_0081ec30;
          }
          fVar27 = (float10)FUN_0056d500(fVar28,fVar29);
          local_18 = (float)_DAT_0081ec30;
          local_20 = local_20 * local_18;
          local_1c = local_1c * local_18;
          local_18 = local_18 * (float)fVar27;
          FUN_0056d5b0(&local_20,&local_10);
          if (local_10 < 0) {
            iVar23 = 0;
          }
          else {
            iVar23 = local_10;
            if (0xff < local_10) {
              iVar23 = 0xff;
            }
          }
          if (local_c < 0) {
            local_5c = 0;
          }
          else {
            local_5c = 0xff;
            if (local_c < 0x100) {
              local_5c = local_c;
            }
          }
          if (local_8 < 0) {
            iVar13 = 0;
          }
          else {
            iVar13 = local_8;
            if (0xff < local_8) {
              iVar13 = 0xff;
            }
          }
          *pbVar26 = (byte)((iVar23 - (uint)*pbVar25) * iVar12 + (uint)*pbVar25 * 0x10000 >> 0x10);
          pbVar26[1] = (byte)((local_5c - pbVar25[1]) * iVar12 + (uint)pbVar25[1] * 0x10000 >> 0x10)
          ;
          pbVar26[2] = (byte)((iVar13 - (uint)pbVar25[2]) * iVar12 + (uint)pbVar25[2] * 0x10000 >>
                             0x10);
          pbVar26[3] = pbVar25[3];
          pbVar25 = pbVar25 + 4;
          pbVar24 = pbVar24 + 4;
          pbVar26 = pbVar26 + 4;
          local_58 = local_58 + -1;
        } while (local_58 != 0);
        pbVar26 = pbVar26 + iVar10;
        pbVar25 = pbVar25 + iVar18;
        pbVar24 = pbVar24 + iVar18;
        local_54 = local_54 + -1;
      } while (local_54 != 0);
      FUN_00586b00();
      return 0;
    }
  case 0x1c:
    do {
      local_58 = iVar19;
      do {
        bVar7 = pbVar25[3];
        uVar14 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar25,bVar7)];
        bVar8 = pbVar24[3];
        uVar11 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[1],bVar7)];
        uVar15 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[2],bVar7)];
        bVar7 = (&DAT_00a62a60)[CONCAT11(pbVar24[1],bVar8)];
        bVar16 = (&DAT_00a62a60)[CONCAT11(pbVar24[2],bVar8)];
        iVar12 = (uint)bVar8 * iVar9;
        fVar28 = (float)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,bVar8)] / (float)_DAT_0081ec30;
        if ((byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,bVar8)] < 0x80) {
          fVar28 = 1.0 - fVar28;
          fVar28 = fVar28 + fVar28;
        }
        else {
          fVar28 = (float)_DAT_00804a60 / fVar28;
        }
        fVar27 = (float10)FUN_0056d500((float)uVar14 / (float)_DAT_0081ec30,fVar28);
        local_20 = (float)fVar27;
        fVar28 = (float)bVar7 / (float)_DAT_0081ec30;
        if (bVar7 < 0x80) {
          fVar28 = 1.0 - fVar28;
          fVar28 = fVar28 + fVar28;
        }
        else {
          fVar28 = (float)_DAT_00804a60 / fVar28;
        }
        fVar27 = (float10)FUN_0056d500((float)uVar11 / (float)_DAT_0081ec30,fVar28);
        local_1c = (float)fVar27;
        fVar28 = (float)bVar16 / (float)_DAT_0081ec30;
        if (bVar16 < 0x80) {
          fVar28 = 1.0 - fVar28;
          fVar28 = fVar28 + fVar28;
        }
        else {
          fVar28 = (float)_DAT_00804a60 / fVar28;
        }
        fVar27 = (float10)FUN_0056d500((float)uVar15 / (float)_DAT_0081ec30,fVar28);
        local_18 = (float)_DAT_0081ec30;
        local_20 = local_20 * local_18;
        local_1c = local_1c * local_18;
        local_18 = local_18 * (float)fVar27;
        FUN_0056d5b0(&local_20,&local_10);
        if (local_10 < 0) {
          iVar23 = 0;
        }
        else {
          iVar23 = local_10;
          if (0xff < local_10) {
            iVar23 = 0xff;
          }
        }
        if (local_c < 0) {
          local_5c = 0;
        }
        else {
          local_5c = 0xff;
          if (local_c < 0x100) {
            local_5c = local_c;
          }
        }
        if (local_8 < 0) {
          iVar13 = 0;
        }
        else {
          iVar13 = local_8;
          if (0xff < local_8) {
            iVar13 = 0xff;
          }
        }
        *pbVar26 = (&DAT_00a52a60)
                   [(uint)pbVar25[3] +
                    ((int)((iVar23 - uVar14) * iVar12 + uVar14 * 0x10000) >> 0x10 & 0xffU) * 0x100];
        pbVar26[1] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_5c - uVar11) * iVar12 + uVar11 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[2] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((iVar13 - uVar15) * iVar12 + uVar15 * 0x10000) >> 0x10 & 0xffU) * 0x100
                     ];
        pbVar26[3] = pbVar25[3];
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        local_58 = local_58 + -1;
      } while (local_58 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    FUN_00586b00();
    return 0;
  case 0xc:
    if (param_2 == 0) {
      do {
        local_58 = iVar19;
        do {
          iVar12 = (uint)pbVar24[3] * iVar9;
          bVar7 = *pbVar24;
          uVar15 = (uint)*pbVar25;
          if (bVar7 < 0x80) {
            iVar23 = (int)(bVar7 * uVar15 * 2) >> 8;
          }
          else {
            iVar23 = ((int)(((0x100 - uVar15) * (uint)bVar7 + uVar15 * 0x100) * 2) >> 8) + -0xff;
          }
          if (0xff < iVar23) {
            iVar23 = 0xff;
          }
          if (pbVar24[1] < 0x80) {
            local_5c = (int)((uint)pbVar25[1] * (uint)pbVar24[1] * 2) >> 8;
          }
          else {
            local_5c = ((int)(((0x100 - (uint)pbVar25[1]) * (uint)pbVar24[1] +
                              (uint)pbVar25[1] * 0x100) * 2) >> 8) + -0xff;
          }
          if (0xff < (int)local_5c) {
            local_5c = 0xff;
          }
          if (pbVar24[2] < 0x80) {
            iVar13 = (int)((uint)pbVar24[2] * (uint)pbVar25[2] * 2) >> 8;
          }
          else {
            iVar13 = ((int)(((0x100 - (uint)pbVar25[2]) * (uint)pbVar24[2] +
                            (uint)pbVar25[2] * 0x100) * 2) >> 8) + -0xff;
          }
          if (0xff < iVar13) {
            iVar13 = 0xff;
          }
          *pbVar26 = (byte)((iVar23 - uVar15) * iVar12 + uVar15 * 0x10000 >> 0x10);
          pbVar26[1] = (byte)((local_5c - pbVar25[1]) * iVar12 + (uint)pbVar25[1] * 0x10000 >> 0x10)
          ;
          pbVar26[2] = (byte)((iVar13 - (uint)pbVar25[2]) * iVar12 + (uint)pbVar25[2] * 0x10000 >>
                             0x10);
          pbVar26[3] = pbVar25[3];
          pbVar25 = pbVar25 + 4;
          pbVar24 = pbVar24 + 4;
          pbVar26 = pbVar26 + 4;
          local_58 = local_58 + -1;
        } while (local_58 != 0);
        pbVar26 = pbVar26 + iVar10;
        pbVar25 = pbVar25 + iVar18;
        pbVar24 = pbVar24 + iVar18;
        local_54 = local_54 + -1;
      } while (local_54 != 0);
      FUN_00586b00();
      return 0;
    }
  case 0x1d:
    do {
      local_58 = iVar19;
      do {
        bVar7 = pbVar24[3];
        bVar8 = pbVar25[3];
        uVar20 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[1],bVar8)];
        iVar12 = (uint)bVar7 * iVar9;
        uVar14 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar25,bVar8)];
        uVar11 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[2],bVar8)];
        uVar21 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,bVar7)];
        uVar22 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar24[1],bVar7)];
        uVar15 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar24[2],bVar7)];
        if (uVar21 < 0x80) {
          local_50 = (int)(uVar21 * uVar14 * 2) >> 8;
        }
        else {
          local_50 = ((int)(((0x100 - uVar14) * uVar21 + uVar14 * 0x100) * 2) >> 8) + -0xff;
        }
        if (0xff < (int)local_50) {
          local_50 = 0xff;
        }
        if (uVar22 < 0x80) {
          local_5c = (int)(uVar22 * uVar20 * 2) >> 8;
        }
        else {
          local_5c = ((int)(((0x100 - uVar20) * uVar22 + uVar20 * 0x100) * 2) >> 8) + -0xff;
        }
        if (0xff < (int)local_5c) {
          local_5c = 0xff;
        }
        if (uVar15 < 0x80) {
          local_34 = (int)(uVar15 * uVar11 * 2) >> 8;
        }
        else {
          local_34 = ((int)(((0x100 - uVar11) * uVar15 + uVar11 * 0x100) * 2) >> 8) + -0xff;
        }
        if (0xff < (int)local_34) {
          local_34 = 0xff;
        }
        *pbVar26 = (&DAT_00a52a60)
                   [(uint)pbVar25[3] +
                    ((int)((local_50 - uVar14) * iVar12 + uVar14 * 0x10000) >> 0x10 & 0xffU) * 0x100
                   ];
        pbVar26[1] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_5c - uVar20) * iVar12 + uVar20 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[2] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_34 - uVar11) * iVar12 + uVar11 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[3] = pbVar25[3];
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        local_58 = local_58 + -1;
      } while (local_58 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    FUN_00586b00();
    return 0;
  case 0xd:
    if (param_2 == 0) {
      do {
        local_58 = iVar19;
        do {
          iVar12 = (uint)pbVar24[3] * iVar9;
          uVar15 = (uint)*pbVar25;
          local_50 = (int)(((0x80 - uVar15) * (uint)*pbVar24 + uVar15 * 0x80) * 2) >> 8;
          if (0xff < (int)local_50) {
            local_50 = 0xff;
          }
          local_5c = (int)(((uint)pbVar24[1] * (0x80 - (uint)pbVar25[1]) + (uint)pbVar25[1] * 0x80)
                          * 2) >> 8;
          if (0xff < (int)local_5c) {
            local_5c = 0xff;
          }
          iVar23 = (int)(((uint)pbVar24[2] * (0x80 - (uint)pbVar25[2]) + (uint)pbVar25[2] * 0x80) *
                        2) >> 8;
          if (0xff < iVar23) {
            iVar23 = 0xff;
          }
          *pbVar26 = (byte)((local_50 - uVar15) * iVar12 + uVar15 * 0x10000 >> 0x10);
          pbVar26[1] = (byte)((local_5c - pbVar25[1]) * iVar12 + (uint)pbVar25[1] * 0x10000 >> 0x10)
          ;
          pbVar26[2] = (byte)((iVar23 - (uint)pbVar25[2]) * iVar12 + (uint)pbVar25[2] * 0x10000 >>
                             0x10);
          pbVar26[3] = pbVar25[3];
          pbVar25 = pbVar25 + 4;
          pbVar24 = pbVar24 + 4;
          pbVar26 = pbVar26 + 4;
          local_58 = local_58 + -1;
        } while (local_58 != 0);
        pbVar26 = pbVar26 + iVar10;
        pbVar25 = pbVar25 + iVar18;
        pbVar24 = pbVar24 + iVar18;
        local_54 = local_54 + -1;
      } while (local_54 != 0);
      FUN_00586b00();
      return 0;
    }
  case 0x1e:
    do {
      local_58 = iVar19;
      do {
        bVar7 = pbVar25[3];
        uVar11 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[1],bVar7)];
        uVar15 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar25,bVar7)];
        uVar14 = (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar25[2],bVar7)];
        bVar7 = pbVar24[3];
        iVar12 = (uint)pbVar24[3] * iVar9;
        local_50 = (int)(((uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,bVar7)] * (0x80 - uVar15) +
                         uVar15 * 0x80) * 2) >> 8;
        if (0xff < (int)local_50) {
          local_50 = 0xff;
        }
        local_5c = (int)(((0x80 - uVar11) * (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar24[1],bVar7)]
                         + uVar11 * 0x80) * 2) >> 8;
        if (0xff < (int)local_5c) {
          local_5c = 0xff;
        }
        iVar23 = (int)(((0x80 - uVar14) * (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar24[2],bVar7)] +
                       uVar14 * 0x80) * 2) >> 8;
        if (0xff < iVar23) {
          iVar23 = 0xff;
        }
        *pbVar26 = (&DAT_00a52a60)
                   [(uint)pbVar25[3] +
                    ((int)((local_50 - uVar15) * iVar12 + uVar15 * 0x10000) >> 0x10 & 0xffU) * 0x100
                   ];
        pbVar26[1] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((local_5c - uVar11) * iVar12 + uVar11 * 0x10000) >> 0x10 & 0xffU) *
                      0x100];
        pbVar26[2] = (&DAT_00a52a60)
                     [(uint)pbVar25[3] +
                      ((int)((iVar23 - uVar14) * iVar12 + uVar14 * 0x10000) >> 0x10 & 0xffU) * 0x100
                     ];
        pbVar26[3] = pbVar25[3];
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        local_58 = local_58 + -1;
      } while (local_58 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    FUN_00586b00();
    return 0;
  case 0xe:
    if (param_2 == 0) {
      do {
        local_58 = iVar19;
        do {
          iVar23 = (int)((uint)pbVar24[3] * iVar9) >> 8;
          iVar12 = 0x100 - iVar23;
          uVar15 = (uint)pbVar25[3] * iVar12 + iVar23 * 0x100;
          if (uVar15 != 0) {
            *pbVar26 = (byte)(((uint)*pbVar25 * (uint)pbVar25[3] * iVar12 +
                              (uint)*pbVar24 * iVar23 * 0x100) / uVar15);
            pbVar26[1] = (byte)(((uint)pbVar25[1] * (uint)pbVar25[3] * iVar12 +
                                (uint)pbVar24[1] * iVar23 * 0x100) / uVar15);
            bVar7 = pbVar25[3];
            bVar8 = pbVar25[2];
            bVar16 = pbVar24[2];
            pbVar26[3] = (byte)(uVar15 >> 8);
            pbVar26[2] = (byte)(((uint)bVar8 * (uint)bVar7 * iVar12 + (uint)bVar16 * iVar23 * 0x100)
                               / uVar15);
          }
          pbVar25 = pbVar25 + 4;
          pbVar24 = pbVar24 + 4;
          pbVar26 = pbVar26 + 4;
          local_58 = local_58 + -1;
        } while (local_58 != 0);
        pbVar26 = pbVar26 + iVar10;
        pbVar25 = pbVar25 + iVar18;
        pbVar24 = pbVar24 + iVar18;
        local_54 = local_54 + -1;
      } while (local_54 != 0);
      FUN_00586b00();
      return 0;
    }
  case 0x1f:
    do {
      local_58 = iVar19;
      do {
        bVar7 = pbVar25[3];
        bVar8 = (&DAT_00a62a60)[CONCAT11(*pbVar25,bVar7)];
        bVar16 = pbVar24[3];
        bVar17 = (&DAT_00a62a60)[CONCAT11(pbVar25[1],bVar7)];
        bVar3 = (&DAT_00a62a60)[CONCAT11(pbVar25[2],bVar7)];
        bVar4 = (&DAT_00a62a60)[CONCAT11(*pbVar24,bVar16)];
        bVar1 = (&DAT_00a62a60)[CONCAT11(pbVar24[1],bVar16)];
        bVar2 = (&DAT_00a62a60)[CONCAT11(pbVar24[2],bVar16)];
        iVar12 = (int)(iVar9 * (uint)bVar16) >> 8;
        iVar23 = 0x100 - iVar12;
        uVar15 = iVar23 * (uint)bVar7 + iVar12 * 0x100;
        if (uVar15 != 0) {
          bVar7 = (byte)(uVar15 >> 8);
          pbVar26[3] = bVar7;
          *pbVar26 = (&DAT_00a52a60)
                     [(uint)bVar7 +
                      (((uint)pbVar25[3] * iVar23 * (uint)bVar8 + iVar12 * (uint)bVar4 * 0x100) /
                       uVar15 & 0xff) * 0x100];
          pbVar26[1] = (&DAT_00a52a60)
                       [(uint)bVar7 +
                        (((uint)pbVar25[3] * iVar23 * (uint)bVar17 + iVar12 * (uint)bVar1 * 0x100) /
                         uVar15 & 0xff) * 0x100];
          pbVar26[2] = (&DAT_00a52a60)
                       [(uint)bVar7 +
                        (((uint)pbVar25[3] * iVar23 * (uint)bVar3 + iVar12 * (uint)bVar2 * 0x100) /
                         uVar15 & 0xff) * 0x100];
        }
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        local_58 = local_58 + -1;
      } while (local_58 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    FUN_00586b00();
    return 0;
  case 0xf:
    if (param_2 == 0) {
      do {
        local_58 = iVar19;
        do {
          iVar12 = (int)((uint)pbVar24[3] * iVar9) >> 8;
          uVar14 = (0x100 - iVar12) * (uint)pbVar25[3] + iVar12 * 0x100;
          uVar15 = uVar14 >> 8;
          if (uVar15 != 0) {
            uVar11 = ((uint)*pbVar24 * iVar12 + (uint)*pbVar25 * (uint)pbVar25[3]) / uVar15;
            if (0xff < uVar11) {
              uVar11 = 0xff;
            }
            *pbVar26 = (byte)uVar11;
            uVar11 = ((uint)pbVar25[1] * (uint)pbVar25[3] + (uint)pbVar24[1] * iVar12) / uVar15;
            if (0xff < uVar11) {
              uVar11 = 0xff;
            }
            pbVar26[1] = (byte)uVar11;
            uVar15 = ((uint)pbVar25[2] * (uint)pbVar25[3] + (uint)pbVar24[2] * iVar12) / uVar15;
            if (0xff < uVar15) {
              uVar15 = 0xff;
            }
            pbVar26[2] = (byte)uVar15;
            pbVar26[3] = (byte)(uVar14 >> 8);
          }
          pbVar25 = pbVar25 + 4;
          pbVar24 = pbVar24 + 4;
          pbVar26 = pbVar26 + 4;
          local_58 = local_58 + -1;
        } while (local_58 != 0);
        pbVar26 = pbVar26 + iVar10;
        pbVar25 = pbVar25 + iVar18;
        pbVar24 = pbVar24 + iVar18;
        local_54 = local_54 + -1;
      } while (local_54 != 0);
      FUN_00586b00();
      return 0;
    }
  case 0x20:
    do {
      local_58 = iVar19;
      do {
        bVar7 = pbVar25[3];
        bVar8 = (&DAT_00a62a60)[CONCAT11(pbVar25[1],bVar7)];
        bVar16 = (&DAT_00a62a60)[CONCAT11(pbVar25[2],bVar7)];
        bVar17 = pbVar24[3];
        bVar3 = (&DAT_00a62a60)[CONCAT11(pbVar24[1],bVar17)];
        bVar4 = (&DAT_00a62a60)[CONCAT11(pbVar24[2],bVar17)];
        iVar12 = (int)(iVar9 * (uint)bVar17) >> 8;
        uVar15 = (0x100 - iVar12) * (uint)bVar7 + iVar12 * 0x100;
        uVar14 = uVar15 >> 8;
        if (uVar14 != 0) {
          uVar11 = ((uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar25,bVar7)] * (uint)pbVar25[3] +
                   (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar24,bVar17)] * iVar12) / uVar14;
          if (0xff < uVar11) {
            uVar11 = 0xff;
          }
          *pbVar26 = (&DAT_00a52a60)[uVar14 + (uVar11 & 0xff) * 0x100];
          uVar11 = ((uint)pbVar25[3] * (uint)bVar8 + iVar12 * (uint)bVar3) / uVar14;
          if (0xff < uVar11) {
            uVar11 = 0xff;
          }
          pbVar26[1] = (&DAT_00a52a60)[uVar14 + (uVar11 & 0xff) * 0x100];
          uVar11 = ((uint)pbVar25[3] * (uint)bVar16 + iVar12 * (uint)bVar4) / uVar14;
          if (0xff < uVar11) {
            uVar11 = 0xff;
          }
          pbVar26[2] = (&DAT_00a52a60)[uVar14 + (uVar11 & 0xff) * 0x100];
          pbVar26[3] = (byte)(uVar15 >> 8);
        }
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        local_58 = local_58 + -1;
      } while (local_58 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    FUN_00586b00();
    return 0;
  case 0x10:
    if (param_2 != 0) goto switchD_00590939_caseD_21;
    iVar12 = iVar19;
    while( true ) {
      do {
        bVar7 = pbVar25[3];
        bVar8 = pbVar24[3];
        *pbVar26 = *pbVar25;
        pbVar26[1] = pbVar25[1];
        pbVar26[2] = pbVar25[2];
        pbVar26[3] = (byte)((((int)((uint)bVar8 * (uint)bVar7) >> 8) - (uint)pbVar25[3]) *
                            iVar9 * 0xff + (uint)pbVar25[3] * 0x10000 >> 0x10);
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
      if (local_54 == 0) break;
      iVar12 = iVar19;
    }
    break;
  case 0x21:
switchD_00590939_caseD_21:
    do {
      local_58 = iVar19;
      do {
        bVar7 = pbVar25[3];
        uVar15 = (uint)bVar7;
        uVar5 = (&DAT_00a62a60)[CONCAT11(pbVar25[1],bVar7)];
        uVar6 = (&DAT_00a62a60)[CONCAT11(pbVar25[2],bVar7)];
        bVar7 = (&DAT_00a62a60)[CONCAT11(*pbVar25,bVar7)];
        iVar12 = (((int)(pbVar24[3] * uVar15) >> 8) - uVar15) * iVar9 * 0xff + uVar15 * 0x10000;
        bVar8 = (byte)((uint)iVar12 >> 0x10);
        pbVar26[3] = bVar8;
        *pbVar26 = (&DAT_00a52a60)[(iVar12 >> 0x10 & 0xffU) + (uint)bVar7 * 0x100];
        pbVar26[1] = (&DAT_00a52a60)[CONCAT11(uVar5,bVar8)];
        pbVar26[2] = (&DAT_00a52a60)[CONCAT11(uVar6,pbVar26[3])];
        pbVar25 = pbVar25 + 4;
        pbVar24 = pbVar24 + 4;
        pbVar26 = pbVar26 + 4;
        local_58 = local_58 + -1;
      } while (local_58 != 0);
      pbVar26 = pbVar26 + iVar10;
      pbVar25 = pbVar25 + iVar18;
      pbVar24 = pbVar24 + iVar18;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    FUN_00586b00();
    return 0;
  }
  FUN_00586b00();
  return 0;
}

