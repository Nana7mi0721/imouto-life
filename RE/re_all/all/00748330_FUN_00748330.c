
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00748330(int param_1,int param_2,int param_3,int param_4,float param_5,float param_6,
                 float param_7,int param_8,int param_9,int param_10,int param_11)

{
  uint *puVar1;
  ushort *puVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  uint3 uVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  byte bVar13;
  undefined1 uVar14;
  ushort uVar15;
  short sVar16;
  uint uVar17;
  uint uVar18;
  byte *pbVar19;
  byte *pbVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  uint *puVar24;
  int iVar25;
  float fVar26;
  ushort uVar27;
  int local_a4 [4];
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74 [4];
  int local_64;
  float local_60;
  float local_5c;
  float local_58;
  uint *local_54;
  undefined4 *local_50;
  undefined4 *local_4c;
  undefined4 *local_48;
  int *local_44;
  float local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_2c;
  int local_28;
  int local_24;
  float local_20;
  float local_1c;
  undefined4 *local_18;
  undefined4 local_14;
  int local_10;
  undefined *local_c;
  int local_8;
  
  local_24 = 0;
  if (*(int *)(*(int *)(param_2 + 0x14) + 0x18) == 0) {
    param_8 = 0;
  }
  iVar8 = *(int *)(param_1 + 0x14);
  if (((*(int *)(*(int *)(param_2 + 0x14) + 0x20) == *(int *)(iVar8 + 0x20)) &&
      (*(int *)(iVar8 + 0x24) != 1)) && (*(int *)(iVar8 + 0x2c) != 1)) {
    FUN_0056d4d0(-param_5,&local_60,&local_5c);
    local_44 = (int *)(local_60 * (float)_DAT_008372c0);
    local_58 = (float)FUN_0050e270(local_44);
    local_44 = (int *)(local_5c * (float)_DAT_008372c0);
    local_3c = FUN_0050e270(local_44);
    FUN_0056d4d0(param_5,&local_60,&local_5c);
    local_44 = (int *)(local_60 * (float)_DAT_008372c0);
    local_4c = (undefined4 *)FUN_0050e270(local_44);
    local_44 = (int *)(local_5c * (float)_DAT_008372c0);
    iVar8 = FUN_0050e270(local_44);
    fVar26 = (float)*(int *)(param_2 + 4);
    iVar25 = param_3 * 0x40000;
    iVar23 = param_4 * 0x40000;
    if (*(int *)(param_2 + 4) < 0) {
      fVar26 = fVar26 + _DAT_007d4bd8;
    }
    fVar26 = fVar26 * param_6 * (float)_DAT_00804a60;
    fVar4 = (float)*(int *)(param_2 + 8);
    if (*(int *)(param_2 + 8) < 0) {
      fVar4 = fVar4 + _DAT_007d4bd8;
    }
    fVar5 = fVar4 * param_7 * (float)_DAT_00804a60;
    local_1c = (float)iVar8;
    local_50 = (undefined4 *)(fVar26 * local_1c);
    fVar4 = (float)(int)local_4c;
    local_44 = (int *)(fVar4 * fVar26);
    local_4c = (undefined4 *)(fVar5 * local_1c);
    local_54 = (uint *)(fVar4 * fVar5);
    local_48 = (undefined4 *)-(float)local_50;
    local_40 = -(float)local_54;
    local_14 = (float)local_48 - local_40;
    local_74[0] = FUN_0050e270(local_14);
    local_74[0] = local_74[0] + iVar25;
    local_14 = -(float)local_4c;
    local_20 = local_14 - (float)local_44;
    local_a4[0] = FUN_0050e270(local_20);
    local_a4[0] = local_a4[0] + iVar23;
    local_48 = (undefined4 *)((float)local_48 - (float)local_54);
    local_74[1] = FUN_0050e270(local_48);
    local_74[1] = local_74[1] + iVar25;
    local_48 = (undefined4 *)((float)local_4c - (float)local_44);
    local_a4[1] = FUN_0050e270(local_48);
    local_a4[1] = local_a4[1] + iVar23;
    local_54 = (uint *)((float)local_50 - (float)local_54);
    local_74[2] = FUN_0050e270(local_54);
    local_74[2] = local_74[2] + iVar25;
    local_54 = (uint *)((float)local_4c + (float)local_44);
    local_a4[2] = FUN_0050e270(local_54);
    local_a4[2] = local_a4[2] + iVar23;
    local_54 = (uint *)((float)local_50 - local_40);
    local_74[3] = FUN_0050e270(local_54);
    local_74[3] = local_74[3] + iVar25;
    local_44 = (int *)(local_14 + (float)local_44);
    iVar8 = FUN_0050e270(local_44);
    iVar8 = iVar8 + iVar23;
    uVar12 = iVar8 >> 0x1f;
    uVar9 = local_74[1] >> 0x1f;
    uVar21 = local_a4[1] >> 0x1f;
    uVar11 = local_74[2] >> 0x1f;
    uVar10 = local_a4[2] >> 0x1f;
    uVar18 = local_74[0] >> 0x1f;
    uVar22 = local_a4[0] >> 0x1f;
    uVar17 = local_74[3] >> 0x1f;
    local_a4[3] = iVar8;
    if (param_9 != 0) {
      if (param_10 == 0) {
        local_94 = (int)(local_74[3] + (uVar17 & 0x3ffff)) >> 0x12;
        local_90 = (int)(iVar8 + (uVar12 & 0x3ffff)) >> 0x12;
        local_8c = (int)(local_74[0] + (uVar18 & 0x3ffff)) >> 0x12;
        local_88 = (int)(local_a4[0] + (uVar22 & 0x3ffff)) >> 0x12;
        local_84 = (int)(local_74[2] + (uVar11 & 0x3ffff)) >> 0x12;
        local_80 = (int)(local_a4[2] + (uVar10 & 0x3ffff)) >> 0x12;
        local_7c = (int)(local_74[1] + (uVar9 & 0x3ffff)) >> 0x12;
        local_78 = (int)(local_a4[1] + (uVar21 & 0x3ffff)) >> 0x12;
        FUN_00748180(param_1,param_2,&local_94,param_8,param_11);
        return;
      }
      local_94 = (int)(local_74[2] + (uVar11 & 0x3ffff)) >> 0x12;
      local_90 = (int)(local_a4[2] + (uVar10 & 0x3ffff)) >> 0x12;
      local_8c = (int)(local_74[1] + (uVar9 & 0x3ffff)) >> 0x12;
      local_88 = (int)(local_a4[1] + (uVar21 & 0x3ffff)) >> 0x12;
      local_84 = (int)(local_74[3] + (uVar17 & 0x3ffff)) >> 0x12;
      local_80 = (int)(iVar8 + (uVar12 & 0x3ffff)) >> 0x12;
      local_7c = (int)(local_74[0] + (uVar18 & 0x3ffff)) >> 0x12;
      local_78 = (int)(local_a4[0] + (uVar22 & 0x3ffff)) >> 0x12;
      FUN_00748180(param_1,param_2,&local_94,param_8,param_11);
      return;
    }
    if (param_10 != 0) {
      local_94 = (int)(local_74[1] + (uVar9 & 0x3ffff)) >> 0x12;
      local_90 = (int)(local_a4[1] + (uVar21 & 0x3ffff)) >> 0x12;
      local_8c = (int)(local_74[2] + (uVar11 & 0x3ffff)) >> 0x12;
      local_88 = (int)(local_a4[2] + (uVar10 & 0x3ffff)) >> 0x12;
      local_84 = (int)(local_74[0] + (uVar18 & 0x3ffff)) >> 0x12;
      local_80 = (int)(local_a4[0] + (uVar22 & 0x3ffff)) >> 0x12;
      local_7c = (int)(local_74[3] + (uVar17 & 0x3ffff)) >> 0x12;
      local_78 = (int)(iVar8 + (uVar12 & 0x3ffff)) >> 0x12;
      FUN_00748180(param_1,param_2,&local_94,param_8,param_11);
      return;
    }
    local_44 = (int *)(local_1c / param_6);
    local_38 = FUN_0050e270(local_44);
    local_44 = (int *)((float)(int)local_58 / param_7);
    local_34 = FUN_0050e270(local_44);
    local_54 = (uint *)0x0;
    local_44 = (int *)0x0;
    uVar12 = (uint)(local_a4[0] < local_a4[1]);
    if (local_a4[1] < local_a4[0]) {
      local_54 = (uint *)0x1;
    }
    local_54 = (uint *)(uint)(local_a4[1] < local_a4[0]);
    if (local_74[0] < local_74[1]) {
      local_44 = (int *)0x1;
    }
    local_44 = (int *)(uint)(local_74[0] < local_74[1]);
    uVar9 = (uint)(local_74[1] < local_74[0]);
    if (local_a4[uVar12] < local_a4[2]) {
      uVar12 = 2;
    }
    if (local_a4[2] < local_a4[(int)local_54]) {
      local_54 = (uint *)0x2;
    }
    if (local_74[(int)local_44] < local_74[2]) {
      local_44 = (int *)0x2;
    }
    if (local_74[2] < local_74[uVar9]) {
      uVar9 = 2;
    }
    if (local_a4[uVar12] < iVar8) {
      uVar12 = 3;
    }
    puVar24 = local_54;
    if (iVar8 < local_a4[(int)local_54]) {
      puVar24 = (uint *)0x3;
    }
    if (local_74[(int)local_44] < local_74[3]) {
      local_44 = (int *)0x3;
    }
    if (local_74[3] < local_74[uVar9]) {
      uVar9 = 3;
    }
    local_84 = ((int)(local_74[uVar9] + (local_74[uVar9] >> 0x1f & 0x3ffffU)) >> 0x12) + -2;
    local_80 = ((int)(local_a4[(int)puVar24] + (local_a4[(int)puVar24] >> 0x1f & 0x3ffffU)) >> 0x12)
               + -2;
    local_7c = ((int)(local_74[(int)local_44] + (local_74[(int)local_44] >> 0x1f & 0x3ffffU)) >>
               0x12) + 4;
    local_44 = local_a4 + uVar12;
    iVar8 = local_a4[uVar12];
    local_78 = ((int)(iVar8 + (iVar8 >> 0x1f & 0x3ffffU)) >> 0x12) + 4;
    FUN_00514e10(&local_84,&DAT_00dca3e4);
    iVar8 = local_80;
    if ((local_84 != local_7c) && (local_80 != local_78)) {
      *local_44 = local_78 << 0x12;
      iVar23 = iVar8 - param_4;
      local_4c = (undefined4 *)(iVar8 << 0x12);
      local_a4[(int)puVar24] = (int)local_4c;
      param_3 = local_84 - param_3;
      local_54 = (uint *)((float)(param_3 * local_3c - iVar23 * (int)local_58) / param_6);
      iVar8 = FUN_0050e270(local_54);
      local_40 = (float)(iVar8 + (*(uint *)(param_2 + 4) >> 1) * 0x40000);
      local_54 = (uint *)((float)(iVar23 * local_3c + param_3 * (int)local_58) / param_7);
      iVar8 = FUN_0050e270(local_54);
      local_14 = (float)(iVar8 + (*(uint *)(param_2 + 8) >> 1) * 0x40000);
      local_54 = (uint *)*local_44;
      param_4 = ((int)((int)local_54 + ((int)local_54 >> 0x1f & 0x3ffffU)) >> 0x12) - param_4;
      local_44 = (int *)((float)(param_3 * local_3c - param_4 * (int)local_58) / param_6);
      iVar8 = FUN_0050e270(local_44);
      local_50 = (undefined4 *)(iVar8 + (*(uint *)(param_2 + 4) >> 1) * 0x40000);
      local_44 = *(int **)(param_2 + 8);
      local_58 = (float)(param_4 * local_3c + param_3 * (int)local_58) / param_7;
      iVar23 = FUN_0050e270(local_58);
      iVar8 = DAT_00dca3f8;
      local_28 = (int)(((int)local_54 - (int)local_4c) +
                      ((int)local_54 - (int)local_4c >> 0x1f & 0x3ffffU)) >> 0x12;
      if (local_28 != 0) {
        local_2c = ((int)local_50 - (int)local_40) / local_28;
        iVar25 = *(int *)(param_2 + 0xc);
        local_28 = (int)((iVar23 + ((uint)local_44 >> 1) * 0x40000) - (int)local_14) / local_28;
        iVar23 = *(int *)(param_2 + 0x14);
        local_1c = *(float *)(iVar23 + 0xc);
        local_64 = *(int *)(*(int *)(param_1 + 0x14) + 0xc);
        puVar24 = (uint *)((uint)*(byte *)(*(int *)(*(int *)(param_1 + 0x14) + 0x14) + 4) * local_84
                           + local_64 * local_80 + *(int *)(param_1 + 0xc));
        if (param_11 != 0) {
          local_24 = *(int *)(param_11 + 0xc);
          local_20 = *(float *)(*(int *)(param_11 + 0x14) + 0xc);
        }
        local_3c = *(int *)(iVar23 + 0x3c);
        local_58 = *(float *)(iVar23 + 0x1c);
        local_18 = &DAT_00d0a2e0 + DAT_00dca3f8 * 0x100;
        local_c = &DAT_00d4a6e0 + DAT_00dca3f8 * 0x800;
        local_50 = &DAT_00d0a2e0 + (DAT_00dca3fc >> 0x10 & 0xff) * 0x100;
        local_48 = &DAT_00d0a2e0 + (DAT_00dca3fc >> 8 & 0xff) * 0x100;
        local_4c = &DAT_00d0a2e0 + (DAT_00dca3fc & 0xff) * 0x100;
        uVar12 = 0;
        if (local_44 != (int *)0x0) {
          do {
            (&DAT_00f448d8)[uVar12] = iVar25;
            iVar25 = iVar25 + (int)local_1c;
            uVar12 = uVar12 + 1;
          } while (uVar12 < local_44);
        }
        if (param_11 != 0) {
          uVar12 = *(uint *)(param_11 + 8);
          uVar9 = 0;
          iVar23 = local_24;
          if (uVar12 != 0) {
            do {
              (&DAT_00f408d8)[uVar9] = iVar23;
              uVar9 = uVar9 + 1;
              iVar23 = iVar23 + (int)local_20;
            } while (uVar9 < uVar12);
          }
        }
        iVar23 = *(int *)(param_2 + 0x14);
        local_54 = puVar24;
        if (*(int *)(iVar23 + 0x24) == 1) {
          FUN_0056d420(&DAT_00f404d8,*(undefined4 *)(iVar23 + 0x3c),
                       ((uint)(*(int *)(iVar23 + 0x20) != 0) * 2 + 2) * *(int *)(iVar23 + 0x28));
          iVar8 = DAT_00dca3f8;
        }
        fVar26 = local_40;
        uVar12 = *(int *)(param_2 + 4) << 0x12;
        local_10 = local_78 - local_80;
        uVar9 = *(int *)(param_2 + 8) << 0x12;
        local_7c = local_7c - local_84;
        local_28 = local_28 - local_7c * local_34;
        local_2c = local_2c - local_7c * local_38;
        local_64 = local_64 -
                   (uint)*(byte *)(*(int *)(*(int *)(param_1 + 0x14) + 0x14) + 4) * local_7c;
        iVar23 = *(int *)(param_2 + 0x14);
        local_40 = local_14;
        local_8 = local_7c;
        if (*(int *)(iVar23 + 0x20) == 0) {
          if (*(int *)(iVar23 + 0x24) == 1) {
            switch(DAT_00dca3f4) {
            case 0:
switchD_0075479d_caseD_0:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          uVar15 = *(ushort *)
                                    (local_3c +
                                    (uint)*(byte *)(((int)((int)fVar26 +
                                                          ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                   + (&DAT_00f448d8)
                                                     [(int)((int)local_14 +
                                                           ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                                      0x12]) * 2);
                          *(ushort *)puVar24 =
                               (*(short *)(local_50 + (uVar15 >> 0xb)) << 6 |
                               *(ushort *)(local_48 + (uVar15 >> 5 & 0x3f))) << 5 |
                               *(ushort *)(local_4c + (uVar15 & 0x1f));
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                         (uVar21 = (uint)*(byte *)(((int)((int)fVar26 +
                                                         ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                  + (&DAT_00f448d8)
                                                    [(int)((int)local_14 +
                                                          ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                                     0x12]), (float)uVar21 != local_58)) {
                        uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                        *(ushort *)puVar24 =
                             (*(short *)(local_50 + (uVar15 >> 0xb)) << 6 |
                             *(ushort *)(local_48 + (uVar15 >> 5 & 0x3f))) << 5 |
                             *(ushort *)(local_4c + (uVar15 & 0x1f));
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    iVar8 = local_7c;
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        *(ushort *)local_54 =
                             *(ushort *)
                              (&DAT_00f404d8 +
                              (uint)*(byte *)(((uint)fVar26 >> 0x12) +
                                             (&DAT_00f448d8)[(uint)local_14 >> 0x12]) * 2);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      local_54 = (uint *)((int)local_54 + 2);
                      iVar8 = iVar8 + -1;
                    } while (iVar8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    local_54 = (uint *)((int)local_54 + local_64);
                    local_10 = local_10 + -1;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  iVar8 = local_7c;
                  do {
                    if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                       (uVar21 = (uint)*(byte *)(((uint)fVar26 >> 0x12) +
                                                (&DAT_00f448d8)[(uint)local_14 >> 0x12]),
                       (float)uVar21 != local_58)) {
                      *(ushort *)local_54 = *(ushort *)(&DAT_00f404d8 + uVar21 * 2);
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    local_54 = (uint *)((int)local_54 + 2);
                    iVar8 = iVar8 + -1;
                  } while (iVar8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  local_54 = (uint *)((int)local_54 + local_64);
                  local_10 = local_10 + -1;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar15 = *(ushort *)
                                  (local_3c + (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8) * 2);
                        bVar13 = (&DAT_00dca2e0)[*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                        uVar7 = (ushort)*puVar24;
                        uVar21 = uVar7 & 0x1f;
                        *(ushort *)puVar24 =
                             (ushort)((local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                      (uint)bVar13 + (uVar7 & 0xffffffe0) * 8 >> 3) & 0x7e0 |
                             ((*(short *)(local_50 + (uVar15 >> 0xb)) - (uVar7 >> 0xb)) *
                              (ushort)bVar13 + (uVar7 >> 3 & 0x1f00)) * 8 & 0xf800 |
                             (ushort)((local_4c[uVar15 & 0x1f] - uVar21) * (uint)bVar13 +
                                      uVar21 * 0x100 >> 8);
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                      iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar21 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8);
                      if ((float)uVar21 != local_58) {
                        uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                        bVar13 = (&DAT_00dca2e0)[*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                        uVar7 = (ushort)*puVar24;
                        uVar21 = uVar7 & 0x1f;
                        *(ushort *)puVar24 =
                             (ushort)((local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                      (uint)bVar13 + (uVar7 & 0xffffffe0) * 8 >> 3) & 0x7e0 |
                             ((*(short *)(local_50 + (uVar15 >> 0xb)) - (uVar7 >> 0xb)) *
                              (ushort)bVar13 + (uVar7 >> 3 & 0x1f00)) * 8 & 0xf800 |
                             (ushort)((local_4c[uVar15 & 0x1f] - uVar21) * (uint)bVar13 +
                                      uVar21 * 0x100 >> 8);
                      }
                    }
                    local_40 = (float)((int)local_40 + local_34);
                    fVar26 = (float)((int)fVar26 + local_38);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  local_40 = (float)((int)local_40 + local_28);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 == 0) {
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar21 = (uint)(ushort)*puVar24;
                      uVar10 = uVar21 << 8;
                      uVar11 = (uint)*(ushort *)
                                      (local_3c +
                                      (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8) * 2);
                      uVar18 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                      *(ushort *)puVar24 =
                           (ushort)(((uVar11 & 0xf800) - (uVar21 & 0xf800)) * uVar18 +
                                    (uVar10 & 0xfff80000) >> 8) & 0xf800 |
                           (ushort)(((uVar11 & 0x7e0) - (uVar21 & 0x7e0)) * uVar18 +
                                    (uVar10 & 0xffffe000) >> 8) & 0x7e0 |
                           (ushort)(((uVar11 & 0x1f) - (uVar21 & 0x1f)) * uVar18 + (uVar10 & 0x1f00)
                                   >> 8);
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                    iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    uVar21 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8);
                    if ((float)uVar21 != local_58) {
                      uVar11 = (uint)(ushort)*puVar24;
                      uVar10 = uVar11 << 8;
                      uVar21 = (uint)*(ushort *)(local_3c + uVar21 * 2);
                      uVar18 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                      *(ushort *)puVar24 =
                           (ushort)(((uVar21 & 0xf800) - (uVar11 & 0xf800)) * uVar18 +
                                    (uVar10 & 0xfff80000) >> 8) & 0xf800 |
                           (ushort)(((uVar21 & 0x7e0) - (uVar11 & 0x7e0)) * uVar18 +
                                    (uVar10 & 0xffffe000) >> 8) & 0x7e0 |
                           (ushort)(((uVar21 & 0x1f) - (uVar11 & 0x1f)) * uVar18 + (uVar10 & 0x1f00)
                                   >> 8);
                    }
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  local_14 = (float)((int)local_14 + local_34);
                  puVar24 = (uint *)((int)puVar24 + 2);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                local_14 = (float)((int)local_14 + local_28);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            case 1:
              if (iVar8 == 0xff) goto switchD_0075479d_caseD_0;
              if (iVar8 != 0) {
                if (param_11 == 0) {
                  if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                            uVar15 = *(ushort *)
                                      (local_3c +
                                      (uint)*(byte *)(((int)((int)fVar26 +
                                                            ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                                      0x12) + (&DAT_00f448d8)
                                                              [(int)((int)local_40 +
                                                                    ((int)local_40 >> 0x1f &
                                                                    0x3ffffU)) >> 0x12]) * 2);
                            uVar7 = (ushort)*puVar24;
                            *(ushort *)puVar24 =
                                 ((uVar7 >> 5 & 0x3f) +
                                 *(short *)(local_c +
                                           (local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) * 4)
                                 ) * 0x20 |
                                 ((uVar7 >> 0xb) +
                                 *(short *)(local_c +
                                           (local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) * 4)) *
                                 0x800 | (uVar7 & 0x1f) +
                                         *(short *)(local_c +
                                                   (local_4c[uVar15 & 0x1f] - (uVar7 & 0x1f)) * 4);
                          }
                          local_40 = (float)((int)local_40 + local_34);
                          fVar26 = (float)((int)fVar26 + local_38);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        local_40 = (float)((int)local_40 + local_28);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if ((((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) &&
                           (uVar21 = (uint)*(byte *)(((int)((int)fVar26 +
                                                           ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12
                                                     ) + (&DAT_00f448d8)
                                                         [(int)((int)local_40 +
                                                               ((int)local_40 >> 0x1f & 0x3ffffU))
                                                          >> 0x12]), (float)uVar21 != local_58)) {
                          uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                          uVar7 = (ushort)*puVar24;
                          *(ushort *)puVar24 =
                               ((uVar7 >> 5 & 0x3f) +
                               *(short *)(local_c +
                                         (local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) * 4))
                               * 0x20 | ((uVar7 >> 0xb) +
                                        *(short *)(local_c +
                                                  (local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                                  4)) * 0x800 |
                               (uVar7 & 0x1f) +
                               *(short *)(local_c + (local_4c[uVar15 & 0x1f] - (uVar7 & 0x1f)) * 4);
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          uVar15 = *(ushort *)
                                    (local_3c +
                                    (uint)*(byte *)(((int)((int)fVar26 +
                                                          ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                   + (&DAT_00f448d8)
                                                     [(int)((int)local_40 +
                                                           ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                                      0x12]) * 2);
                          uVar7 = (ushort)*puVar24;
                          *(ushort *)puVar24 =
                               ((uVar7 >> 5 & 0x3f) +
                               *(short *)(local_c + ((uVar15 >> 5 & 0x3f) - (uVar7 >> 5 & 0x3f)) * 4
                                         )) * 0x20 |
                               ((uVar7 >> 0xb) +
                               *(short *)(local_c +
                                         ((uint)(uVar15 >> 0xb) - (uint)(uVar7 >> 0xb)) * 4)) *
                               0x800 | (uVar7 & 0x1f) +
                                       *(short *)(local_c + ((uVar15 & 0x1f) - (uVar7 & 0x1f)) * 4);
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if ((((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) &&
                         (uVar21 = (uint)*(byte *)(((int)((int)fVar26 +
                                                         ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                  + (&DAT_00f448d8)
                                                    [(int)((int)local_40 +
                                                          ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                                     0x12]), (float)uVar21 != local_58)) {
                        uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                        uVar7 = (ushort)*puVar24;
                        *(ushort *)puVar24 =
                             ((uVar7 >> 5 & 0x3f) +
                             *(short *)(local_c + ((uVar15 >> 5 & 0x3f) - (uVar7 >> 5 & 0x3f)) * 4))
                             * 0x20 | ((uVar7 >> 0xb) +
                                      *(short *)(local_c +
                                                ((uint)(uVar15 >> 0xb) - (uint)(uVar7 >> 0xb)) * 4))
                                      * 0x800 |
                             (uVar7 & 0x1f) +
                             *(short *)(local_c + ((uVar15 & 0x1f) - (uVar7 & 0x1f)) * 4);
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          iVar25 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar25] + iVar23)];
                          uVar15 = *(ushort *)
                                    (local_3c +
                                    (uint)*(byte *)((&DAT_00f448d8)[iVar25] + iVar23) * 2);
                          uVar7 = (ushort)*puVar24;
                          uVar21 = (uint)uVar7;
                          *(ushort *)puVar24 =
                               (ushort)((local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                        uVar11 * iVar8 + (uVar21 & 0xffffffe0) * 0x800 >> 0xb) &
                               0x7e0 | (ushort)((local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                                uVar11 * DAT_00dca3f8 + (uVar21 & 0xfffff800) * 0x20
                                               >> 5) & 0xf800 |
                               (ushort)((local_4c[uVar15 & 0x1f] - (uVar21 & 0x1f)) * uVar11 *
                                        DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10) & 0x1f;
                          iVar8 = DAT_00dca3f8;
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar21 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                        if ((float)uVar21 != local_58) {
                          uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                          uVar7 = (ushort)*puVar24;
                          uVar21 = (uint)uVar7;
                          *(ushort *)puVar24 =
                               (ushort)((local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                        uVar11 * iVar8 + (uVar21 & 0xffffffe0) * 0x800 >> 0xb) &
                               0x7e0 | (ushort)((local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                                uVar11 * DAT_00dca3f8 + (uVar21 & 0xfffff800) * 0x20
                                               >> 5) & 0xf800 |
                               (ushort)((local_4c[uVar15 & 0x1f] - (uVar21 & 0x1f)) * uVar11 *
                                        DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10) & 0x1f;
                          iVar8 = DAT_00dca3f8;
                        }
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar11 = (uint)*(ushort *)
                                        (local_3c +
                                        (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25) * 2);
                        uVar21 = (uint)(ushort)*puVar24;
                        uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        *(ushort *)puVar24 =
                             (ushort)(((uVar11 & 0xf800) - (uVar21 & 0xf800)) * uVar10 * iVar8 +
                                      (uVar21 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                             (ushort)(((uVar11 & 0x7e0) - (uVar21 & 0x7e0)) * uVar10 * DAT_00dca3f8
                                      + (uVar21 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                             (ushort)(((uVar11 & 0x1f) - (uVar21 & 0x1f)) * uVar10 * DAT_00dca3f8 +
                                      (uVar21 & 0x1f) * 0x10000 >> 0x10);
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar21 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                      if ((float)uVar21 != local_58) {
                        uVar21 = (uint)*(ushort *)(local_3c + uVar21 * 2);
                        uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        uVar11 = (uint)(ushort)*puVar24;
                        *(ushort *)puVar24 =
                             (ushort)(((uVar21 & 0xf800) - (uVar11 & 0xf800)) * uVar10 * iVar8 +
                                      (uVar11 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                             (ushort)(((uVar21 & 0x7e0) - (uVar11 & 0x7e0)) * uVar10 * DAT_00dca3f8
                                      + (uVar11 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                             (ushort)(((uVar21 & 0x1f) - (uVar11 & 0x1f)) * uVar10 * DAT_00dca3f8 +
                                      (uVar11 & 0x1f) * 0x10000 >> 0x10);
                        iVar8 = DAT_00dca3f8;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              break;
            case 2:
              if (iVar8 != 0) {
                if (param_11 == 0) {
                  if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            uVar15 = *(ushort *)
                                      (local_3c +
                                      (uint)*(byte *)(((int)((int)fVar26 +
                                                            ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                                      0x12) + (&DAT_00f448d8)
                                                              [(int)((int)local_14 +
                                                                    ((int)local_14 >> 0x1f &
                                                                    0x3ffffU)) >> 0x12]) * 2);
                            uVar15 = (*(short *)(local_18 + local_50[uVar15 >> 0xb]) * 0x40 +
                                     *(short *)(local_18 + local_48[uVar15 >> 5 & 0x3f])) * 0x20 +
                                     *(short *)(local_18 + local_4c[uVar15 & 0x1f]);
                            uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                            uVar11 = uVar21 & 0x8210820;
                            *(ushort *)puVar24 =
                                 (short)uVar11 - (short)(uVar11 >> 5) |
                                 ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                           (uVar21 = (uint)*(byte *)(((int)((int)fVar26 +
                                                           ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12
                                                     ) + (&DAT_00f448d8)
                                                         [(int)((int)local_14 +
                                                               ((int)local_14 >> 0x1f & 0x3ffffU))
                                                          >> 0x12]), (float)uVar21 != local_58)) {
                          uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                          uVar15 = (*(short *)(local_18 + local_50[uVar15 >> 0xb]) * 0x40 +
                                   *(short *)(local_18 + local_48[uVar15 >> 5 & 0x3f])) * 0x20 +
                                   *(short *)(local_18 + local_4c[uVar15 & 0x1f]);
                          uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                          uVar11 = uVar21 & 0x8210820;
                          *(ushort *)puVar24 =
                               (short)uVar11 - (short)(uVar11 >> 5) |
                               ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          uVar15 = *(ushort *)
                                    (local_3c +
                                    (uint)*(byte *)(((int)((int)fVar26 +
                                                          ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                   + (&DAT_00f448d8)
                                                     [(int)((int)local_14 +
                                                           ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                                      0x12]) * 2);
                          uVar15 = (*(short *)(local_18 + (uVar15 >> 0xb)) * 0x40 +
                                   *(short *)(local_18 + (uVar15 >> 5 & 0x3f))) * 0x20 +
                                   *(short *)(local_18 + (uVar15 & 0x1f));
                          uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                          uVar11 = uVar21 & 0x8210820;
                          *(ushort *)puVar24 =
                               (short)uVar11 - (short)(uVar11 >> 5) |
                               ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                         (uVar21 = (uint)*(byte *)(((int)((int)fVar26 +
                                                         ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                  + (&DAT_00f448d8)
                                                    [(int)((int)local_14 +
                                                          ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                                     0x12]), (float)uVar21 != local_58)) {
                        uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                        uVar15 = (*(short *)(local_18 + (uVar15 >> 0xb)) * 0x40 +
                                 *(short *)(local_18 + (uVar15 >> 5 & 0x3f))) * 0x20 +
                                 *(short *)(local_18 + (uVar15 & 0x1f));
                        uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                        uVar11 = uVar21 & 0x8210820;
                        *(ushort *)puVar24 =
                             (short)uVar11 - (short)(uVar11 >> 5) |
                             ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar15 = *(ushort *)
                                    (local_3c + (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8) * 2
                                    );
                          uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                          uVar15 = (*(short *)(local_18 + (local_50[uVar15 >> 0xb] * uVar21 >> 8)) *
                                    0x40 + *(short *)(local_18 +
                                                     (local_48[uVar15 >> 5 & 0x3f] * uVar21 >> 8)))
                                   * 0x20 + *(short *)(local_18 +
                                                      (local_4c[uVar15 & 0x1f] * uVar21 >> 8));
                          uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                          uVar11 = uVar21 & 0x8210820;
                          *(ushort *)puVar24 =
                               (short)uVar11 - (short)(uVar11 >> 5) |
                               ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar21 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8);
                        if ((float)uVar21 != local_58) {
                          uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                          uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                          uVar15 = (*(short *)(local_18 + (local_50[uVar15 >> 0xb] * uVar21 >> 8)) *
                                    0x40 + *(short *)(local_18 +
                                                     (local_48[uVar15 >> 5 & 0x3f] * uVar21 >> 8)))
                                   * 0x20 + *(short *)(local_18 +
                                                      (local_4c[uVar15 & 0x1f] * uVar21 >> 8));
                          uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                          uVar11 = uVar21 & 0x8210820;
                          *(ushort *)puVar24 =
                               (short)uVar11 - (short)(uVar11 >> 5) |
                               ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar21 = (uint)*(ushort *)
                                        (local_3c +
                                        (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8) * 2);
                        uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                        uVar15 = (*(short *)(local_18 + ((uVar21 & 0xf800) * uVar11 >> 0x13)) * 0x40
                                 + *(short *)(local_18 + ((uVar21 & 0x7e0) * uVar11 >> 0xd))) * 0x20
                                 + *(short *)(local_18 + ((uVar21 & 0x1f) * uVar11 >> 8));
                        uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                        uVar11 = uVar21 & 0x8210820;
                        *(ushort *)puVar24 =
                             (short)uVar11 - (short)(uVar11 >> 5) |
                             ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar21 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8);
                      if ((float)uVar21 != local_58) {
                        uVar21 = (uint)*(ushort *)(local_3c + uVar21 * 2);
                        uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                        uVar15 = (*(short *)(local_18 + ((uVar21 & 0xf800) * uVar11 >> 0x13)) * 0x40
                                 + *(short *)(local_18 + ((uVar21 & 0x7e0) * uVar11 >> 0xd))) * 0x20
                                 + *(short *)(local_18 + ((uVar21 & 0x1f) * uVar11 >> 8));
                        uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                        uVar11 = uVar21 & 0x8210820;
                        *(ushort *)puVar24 =
                             (short)uVar11 - (short)(uVar11 >> 5) |
                             ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              break;
            case 3:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          uVar15 = *(ushort *)
                                    (local_3c +
                                    (uint)*(byte *)(((int)((int)fVar26 +
                                                          ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                   + (&DAT_00f448d8)
                                                     [(int)((int)local_14 +
                                                           ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                                      0x12]) * 2);
                          uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                   ((ushort)((*(short *)(local_18 + local_50[uVar15 >> 0xb]) * 0x40
                                             + *(short *)(local_18 + local_48[uVar15 >> 5 & 0x3f]))
                                             * 0x20 + *(short *)(local_18 + local_4c[uVar15 & 0x1f])
                                            ) & 0xf7def7df);
                          uVar21 = uVar11 & 0x8210820;
                          *(ushort *)puVar24 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11
                          ;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                         (uVar21 = (uint)*(byte *)(((int)((int)fVar26 +
                                                         ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                  + (&DAT_00f448d8)
                                                    [(int)((int)local_14 +
                                                          ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                                     0x12]), (float)uVar21 != local_58)) {
                        uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                        uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                 ((ushort)((*(short *)(local_18 + local_50[uVar15 >> 0xb]) * 0x40 +
                                           *(short *)(local_18 + local_48[uVar15 >> 5 & 0x3f])) *
                                           0x20 + *(short *)(local_18 + local_4c[uVar15 & 0x1f])) &
                                 0xf7def7df);
                        uVar21 = uVar11 & 0x8210820;
                        *(ushort *)puVar24 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        uVar15 = *(ushort *)
                                  (local_3c +
                                  (uint)*(byte *)(((int)((int)fVar26 +
                                                        ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) +
                                                 (&DAT_00f448d8)
                                                 [(int)((int)local_14 +
                                                       ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12])
                                  * 2);
                        uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                 ((ushort)((*(short *)(local_18 + (uVar15 >> 0xb)) * 0x40 +
                                           *(short *)(local_18 + (uVar15 >> 5 & 0x3f))) * 0x20 +
                                          *(short *)(local_18 + (uVar15 & 0x1f))) & 0xf7def7df);
                        uVar21 = uVar11 & 0x8210820;
                        *(ushort *)puVar24 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                       (uVar21 = (uint)*(byte *)(((int)((int)fVar26 +
                                                       ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) +
                                                (&DAT_00f448d8)
                                                [(int)((int)local_14 +
                                                      ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]),
                       (float)uVar21 != local_58)) {
                      uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                      uVar11 = ((ushort)*puVar24 | 0x8210820) -
                               ((ushort)((*(short *)(local_18 + (uVar15 >> 0xb)) * 0x40 +
                                         *(short *)(local_18 + (uVar15 >> 5 & 0x3f))) * 0x20 +
                                        *(short *)(local_18 + (uVar15 & 0x1f))) & 0xf7def7df);
                      uVar21 = uVar11 & 0x8210820;
                      *(ushort *)puVar24 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar15 = *(ushort *)
                                  (local_3c + (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8) * 2);
                        uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                        uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                 ((ushort)((*(short *)(local_18 +
                                                      (local_50[uVar15 >> 0xb] * uVar21 >> 8)) *
                                            0x40 + *(short *)(local_18 +
                                                             (local_48[uVar15 >> 5 & 0x3f] * uVar21
                                                             >> 8))) * 0x20 +
                                          *(short *)(local_18 +
                                                    (local_4c[uVar15 & 0x1f] * uVar21 >> 8))) &
                                 0xf7def7df);
                        uVar21 = uVar11 & 0x8210820;
                        *(ushort *)puVar24 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar21 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8);
                      if ((float)uVar21 != local_58) {
                        uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                        uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                        uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                 ((ushort)((*(short *)(local_18 +
                                                      (local_50[uVar15 >> 0xb] * uVar21 >> 8)) *
                                            0x40 + *(short *)(local_18 +
                                                             (local_48[uVar15 >> 5 & 0x3f] * uVar21
                                                             >> 8))) * 0x20 +
                                          *(short *)(local_18 +
                                                    (local_4c[uVar15 & 0x1f] * uVar21 >> 8))) &
                                 0xf7def7df);
                        uVar21 = uVar11 & 0x8210820;
                        *(ushort *)puVar24 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 == 0) {
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar21 = (uint)*(ushort *)
                                      (local_3c +
                                      (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8) * 2);
                      uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                      uVar11 = ((ushort)*puVar24 | 0x8210820) -
                               ((ushort)((*(short *)(local_18 + ((uVar21 & 0xf800) * uVar11 >> 0x13)
                                                    ) * 0x40 +
                                         *(short *)(local_18 + ((uVar21 & 0x7e0) * uVar11 >> 0xd)))
                                         * 0x20 + *(short *)(local_18 +
                                                            ((uVar21 & 0x1f) * uVar11 >> 8))) &
                               0xf7def7df);
                      uVar21 = uVar11 & 0x8210820;
                      *(ushort *)puVar24 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                    iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    uVar21 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8);
                    if ((float)uVar21 != local_58) {
                      uVar21 = (uint)*(ushort *)(local_3c + uVar21 * 2);
                      uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                      uVar11 = ((ushort)*puVar24 | 0x8210820) -
                               ((ushort)((*(short *)(local_18 + ((uVar21 & 0xf800) * uVar11 >> 0x13)
                                                    ) * 0x40 +
                                         *(short *)(local_18 + ((uVar21 & 0x7e0) * uVar11 >> 0xd)))
                                         * 0x20 + *(short *)(local_18 +
                                                            ((uVar21 & 0x1f) * uVar11 >> 8))) &
                               0xf7def7df);
                      uVar21 = uVar11 & 0x8210820;
                      *(ushort *)puVar24 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                    }
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  local_14 = (float)((int)local_14 + local_34);
                  puVar24 = (uint *)((int)puVar24 + 2);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                local_14 = (float)((int)local_14 + local_28);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            case 4:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          uVar15 = *(ushort *)
                                    (local_3c +
                                    (uint)*(byte *)(((int)((int)fVar26 +
                                                          ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                   + (&DAT_00f448d8)
                                                     [(int)((int)local_40 +
                                                           ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                                      0x12]) * 2);
                          uVar7 = (ushort)*puVar24;
                          *(ushort *)puVar24 =
                               (ushort)((uVar7 >> 5 & 0x3f) * local_48[uVar15 >> 5 & 0x3f] >> 1) &
                               0x7e0 | (uVar7 >> 5 & 0x7c0) * *(short *)(local_50 + (uVar15 >> 0xb))
                                       & 0xf800 |
                               (ushort)((uVar7 & 0x1f) * local_4c[uVar15 & 0x1f] >> 5);
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if ((((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) &&
                         (uVar21 = (uint)*(byte *)(((int)((int)fVar26 +
                                                         ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                  + (&DAT_00f448d8)
                                                    [(int)((int)local_40 +
                                                          ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                                     0x12]), (float)uVar21 != local_58)) {
                        uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                        uVar7 = (ushort)*puVar24;
                        *(ushort *)puVar24 =
                             (ushort)((uVar7 >> 5 & 0x3f) * local_48[uVar15 >> 5 & 0x3f] >> 1) &
                             0x7e0 | (uVar7 >> 5 & 0x7c0) * *(short *)(local_50 + (uVar15 >> 0xb)) &
                                     0xf800 |
                             (ushort)((uVar7 & 0x1f) * local_4c[uVar15 & 0x1f] >> 5);
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        uVar21 = (uint)*(ushort *)
                                        (local_3c +
                                        (uint)*(byte *)(((int)((int)fVar26 +
                                                              ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                                        0x12) + (&DAT_00f448d8)
                                                                [(int)((int)local_14 +
                                                                      ((int)local_14 >> 0x1f &
                                                                      0x3ffffU)) >> 0x12]) * 2);
                        uVar11 = (uint)(ushort)*puVar24;
                        *(ushort *)puVar24 =
                             (ushort)((uVar21 & 0x7e0) * (uVar11 & 0x7e0) >> 0xb) & 0x7e0 |
                             (ushort)((uVar21 & 0xf800) * (uVar11 & 0xf800) >> 0x10) & 0xf800 |
                             (ushort)((uVar21 & 0x1f) * (uVar11 & 0x1f) >> 5);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                       (uVar21 = (uint)*(byte *)(((int)((int)fVar26 +
                                                       ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) +
                                                (&DAT_00f448d8)
                                                [(int)((int)local_14 +
                                                      ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]),
                       (float)uVar21 != local_58)) {
                      uVar21 = (uint)*(ushort *)(local_3c + uVar21 * 2);
                      uVar11 = (uint)(ushort)*puVar24;
                      *(ushort *)puVar24 =
                           (ushort)((uVar21 & 0x7e0) * (uVar11 & 0x7e0) >> 0xb) & 0x7e0 |
                           (ushort)((uVar21 & 0xf800) * (uVar11 & 0xf800) >> 0x10) & 0xf800 |
                           (ushort)((uVar21 & 0x1f) * (uVar11 & 0x1f) >> 5);
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar15 = *(ushort *)
                                  (local_3c + (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8) * 2);
                        uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                        uVar7 = (ushort)*puVar24;
                        *(ushort *)puVar24 =
                             (ushort)((uVar7 >> 5 & 0x3f) * local_48[uVar15 >> 5 & 0x3f] * uVar21 >>
                                     9) & 0x7e0 |
                             (ushort)((uint)(uVar7 >> 0xb) * local_50[uVar15 >> 0xb] * uVar21 >> 2)
                             & 0xf800 |
                             (ushort)((uVar7 & 0x1f) * local_4c[uVar15 & 0x1f] * uVar21 >> 0xd);
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                      iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar21 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8);
                      if ((float)uVar21 != local_58) {
                        uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                        uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                        uVar7 = (ushort)*puVar24;
                        *(ushort *)puVar24 =
                             (ushort)((uVar7 >> 5 & 0x3f) * local_48[uVar15 >> 5 & 0x3f] * uVar21 >>
                                     9) & 0x7e0 |
                             (ushort)((uint)(uVar7 >> 0xb) * local_50[uVar15 >> 0xb] * uVar21 >> 2)
                             & 0xf800 |
                             (ushort)((uVar7 & 0x1f) * local_4c[uVar15 & 0x1f] * uVar21 >> 0xd);
                      }
                    }
                    local_40 = (float)((int)local_40 + local_34);
                    fVar26 = (float)((int)fVar26 + local_38);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  local_40 = (float)((int)local_40 + local_28);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 == 0) {
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar15 = *(ushort *)
                                (local_3c + (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8) * 2);
                      uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                      uVar7 = (ushort)*puVar24;
                      *(ushort *)puVar24 =
                           (ushort)((int)((uVar15 >> 5 & 0x3f) * (uVar7 >> 5 & 0x3f) * uVar21) >> 9)
                           & 0x7e0 | (ushort)((int)((uint)(uVar15 >> 0xb) * (uint)(uVar7 >> 0xb) *
                                                   uVar21) >> 2) & 0xf800 |
                           (ushort)((int)((uVar15 & 0x1f) * (uVar7 & 0x1f) * uVar21) >> 0xd);
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                    iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    uVar21 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8);
                    if ((float)uVar21 != local_58) {
                      uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                      uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                      uVar7 = (ushort)*puVar24;
                      *(ushort *)puVar24 =
                           (ushort)((int)((uVar15 >> 5 & 0x3f) * (uVar7 >> 5 & 0x3f) * uVar21) >> 9)
                           & 0x7e0 | (ushort)((int)((uint)(uVar15 >> 0xb) * (uint)(uVar7 >> 0xb) *
                                                   uVar21) >> 2) & 0xf800 |
                           (ushort)((int)((uVar15 & 0x1f) * (uVar7 & 0x1f) * uVar21) >> 0xd);
                    }
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  local_14 = (float)((int)local_14 + local_34);
                  puVar24 = (uint *)((int)puVar24 + 2);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                local_14 = (float)((int)local_14 + local_28);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            case 10:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          uVar7 = ~*(ushort *)
                                    (local_3c +
                                    (uint)*(byte *)(((int)((int)fVar26 +
                                                          ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                   + (&DAT_00f448d8)
                                                     [(int)((int)local_40 +
                                                           ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                                      0x12]) * 2);
                          uVar15 = (ushort)*puVar24;
                          *(ushort *)puVar24 =
                               ((uVar15 >> 5 & 0x3f) +
                               *(short *)(local_c +
                                         (local_48[uVar7 >> 5 & 0x3f] - (uVar15 >> 5 & 0x3f)) * 4))
                               * 0x20 | ((uVar15 >> 0xb) +
                                        *(short *)(local_c +
                                                  (local_50[uVar7 >> 0xb] - (uint)(uVar15 >> 0xb)) *
                                                  4)) * 0x800 |
                               (uVar15 & 0x1f) +
                               *(short *)(local_c + (local_4c[uVar7 & 0x1f] - (uVar15 & 0x1f)) * 4);
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if ((((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) &&
                         (uVar21 = (uint)*(byte *)(((int)((int)fVar26 +
                                                         ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                  + (&DAT_00f448d8)
                                                    [(int)((int)local_40 +
                                                          ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                                     0x12]), (float)uVar21 != local_58)) {
                        uVar15 = (ushort)*puVar24;
                        uVar7 = ~*(ushort *)(local_3c + uVar21 * 2);
                        *(ushort *)puVar24 =
                             ((uVar15 >> 5 & 0x3f) +
                             *(short *)(local_c +
                                       (local_48[uVar7 >> 5 & 0x3f] - (uVar15 >> 5 & 0x3f)) * 4)) *
                             0x20 | ((uVar15 >> 0xb) +
                                    *(short *)(local_c +
                                              (local_50[uVar7 >> 0xb] - (uint)(uVar15 >> 0xb)) * 4))
                                    * 0x800 |
                             (uVar15 & 0x1f) +
                             *(short *)(local_c + (local_4c[uVar7 & 0x1f] - (uVar15 & 0x1f)) * 4);
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        uVar15 = (ushort)*puVar24;
                        uVar7 = ~*(ushort *)
                                  (local_3c +
                                  (uint)*(byte *)(((int)((int)fVar26 +
                                                        ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) +
                                                 (&DAT_00f448d8)
                                                 [(int)((int)local_40 +
                                                       ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12])
                                  * 2);
                        *(ushort *)puVar24 =
                             ((uVar15 >> 5 & 0x3f) +
                             *(short *)(local_c + ((uVar7 >> 5 & 0x3f) - (uVar15 >> 5 & 0x3f)) * 4))
                             * 0x20 | ((uVar15 >> 0xb) +
                                      *(short *)(local_c +
                                                ((uint)(uVar7 >> 0xb) - (uint)(uVar15 >> 0xb)) * 4))
                                      * 0x800 |
                             (uVar15 & 0x1f) +
                             *(short *)(local_c + ((uVar7 & 0x1f) - (uVar15 & 0x1f)) * 4);
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if ((((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) &&
                       (uVar21 = (uint)*(byte *)(((int)((int)fVar26 +
                                                       ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) +
                                                (&DAT_00f448d8)
                                                [(int)((int)local_40 +
                                                      ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12]),
                       (float)uVar21 != local_58)) {
                      uVar7 = ~*(ushort *)(local_3c + uVar21 * 2);
                      uVar15 = (ushort)*puVar24;
                      *(ushort *)puVar24 =
                           ((uVar15 >> 5 & 0x3f) +
                           *(short *)(local_c + ((uVar7 >> 5 & 0x3f) - (uVar15 >> 5 & 0x3f)) * 4)) *
                           0x20 | ((uVar15 >> 0xb) +
                                  *(short *)(local_c +
                                            ((uint)(uVar7 >> 0xb) - (uint)(uVar15 >> 0xb)) * 4)) *
                                  0x800 |
                           (uVar15 & 0x1f) +
                           *(short *)(local_c + ((uVar7 & 0x1f) - (uVar15 & 0x1f)) * 4);
                    }
                    local_40 = (float)((int)local_40 + local_34);
                    fVar26 = (float)((int)fVar26 + local_38);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  local_40 = (float)((int)local_40 + local_28);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        iVar25 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar25] + iVar23)];
                        uVar7 = ~*(ushort *)
                                  (local_3c + (uint)*(byte *)((&DAT_00f448d8)[iVar25] + iVar23) * 2)
                        ;
                        uVar15 = (ushort)*puVar24;
                        uVar21 = (uint)uVar15;
                        *(ushort *)puVar24 =
                             (ushort)((local_48[uVar7 >> 5 & 0x3f] - (uVar15 >> 5 & 0x3f)) * uVar11
                                      * iVar8 + (uVar21 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                             (ushort)((local_50[uVar7 >> 0xb] - (uint)(uVar15 >> 0xb)) * uVar11 *
                                      DAT_00dca3f8 + (uVar21 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                             (ushort)((local_4c[uVar7 & 0x1f] - (uVar21 & 0x1f)) * uVar11 *
                                      DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10) & 0x1f;
                        iVar8 = DAT_00dca3f8;
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                      iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar21 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                      if ((float)uVar21 != local_58) {
                        uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        uVar15 = (ushort)*puVar24;
                        uVar11 = (uint)uVar15;
                        uVar7 = ~*(ushort *)(local_3c + uVar21 * 2);
                        *(ushort *)puVar24 =
                             (ushort)((local_48[uVar7 >> 5 & 0x3f] - (uVar15 >> 5 & 0x3f)) * uVar10
                                      * iVar8 + (uVar11 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                             (ushort)((local_50[uVar7 >> 0xb] - (uint)(uVar15 >> 0xb)) * uVar10 *
                                      DAT_00dca3f8 + (uVar11 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                             (ushort)((local_4c[uVar7 & 0x1f] - (uVar11 & 0x1f)) * uVar10 *
                                      DAT_00dca3f8 + uVar11 * 0x10000 >> 0x10) & 0x1f;
                        iVar8 = DAT_00dca3f8;
                      }
                    }
                    local_40 = (float)((int)local_40 + local_34);
                    fVar26 = (float)((int)fVar26 + local_38);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  local_40 = (float)((int)local_40 + local_28);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 == 0) {
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar21 = (uint)(ushort)~*(ushort *)
                                               (local_3c +
                                               (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25) * 2
                                               );
                      uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                      uVar11 = (uint)(ushort)*puVar24;
                      *(ushort *)puVar24 =
                           (ushort)(((uVar21 & 0x7e0) - (uVar11 & 0x7e0)) * uVar10 * iVar8 +
                                    (uVar11 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                           (ushort)(((uVar21 & 0xf800) - (uVar11 & 0xf800)) * uVar10 * DAT_00dca3f8
                                    + (uVar11 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                           (ushort)(((uVar21 & 0x1f) - (uVar11 & 0x1f)) * uVar10 * DAT_00dca3f8 +
                                    (uVar11 & 0x1f) * 0x10000 >> 0x10);
                      iVar8 = DAT_00dca3f8;
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                    iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    uVar21 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                    if ((float)uVar21 != local_58) {
                      uVar11 = (uint)(ushort)~*(ushort *)(local_3c + uVar21 * 2);
                      uVar21 = (uint)(ushort)*puVar24;
                      uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                      *(ushort *)puVar24 =
                           (ushort)(((uVar11 & 0x7e0) - (uVar21 & 0x7e0)) * uVar10 * iVar8 +
                                    (uVar21 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                           (ushort)(((uVar11 & 0xf800) - (uVar21 & 0xf800)) * uVar10 * DAT_00dca3f8
                                    + (uVar21 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                           (ushort)(((uVar11 & 0x1f) - (uVar21 & 0x1f)) * uVar10 * DAT_00dca3f8 +
                                    (uVar21 & 0x1f) * 0x10000 >> 0x10);
                      iVar8 = DAT_00dca3f8;
                    }
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  local_14 = (float)((int)local_14 + local_34);
                  puVar24 = (uint *)((int)puVar24 + 2);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                local_14 = (float)((int)local_14 + local_28);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            case 0xb:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          uVar15 = *(ushort *)
                                    (local_3c +
                                    (uint)*(byte *)(((int)((int)fVar26 +
                                                          ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                   + (&DAT_00f448d8)
                                                     [(int)((int)local_40 +
                                                           ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                                      0x12]) * 2);
                          uVar7 = (ushort)*puVar24;
                          uVar21 = uVar7 >> 5 & 0x3f;
                          *(ushort *)puVar24 =
                               ((uVar7 >> 5 & 0x3f) +
                               *(short *)(local_c +
                                         ((local_48[uVar15 >> 5 & 0x3f] * uVar21 >> 6) - uVar21) * 4
                                         )) * 0x20 |
                               ((uVar7 >> 0xb) +
                               *(short *)(local_c +
                                         ((local_50[uVar15 >> 0xb] * (uint)(uVar7 >> 0xb) >> 5) -
                                         (uint)(uVar7 >> 0xb)) * 4)) * 0x800 |
                               (uVar7 & 0x1f) +
                               *(short *)(local_c +
                                         ((local_4c[uVar15 & 0x1f] * (uVar7 & 0x1f) >> 5) -
                                         (uVar7 & 0x1f)) * 4);
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if ((((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) &&
                         (uVar21 = (uint)*(byte *)(((int)((int)fVar26 +
                                                         ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                  + (&DAT_00f448d8)
                                                    [(int)((int)local_40 +
                                                          ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                                     0x12]), (float)uVar21 != local_58)) {
                        uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                        uVar7 = (ushort)*puVar24;
                        uVar21 = uVar7 >> 5 & 0x3f;
                        *(ushort *)puVar24 =
                             ((uVar7 >> 5 & 0x3f) +
                             *(short *)(local_c +
                                       ((local_48[uVar15 >> 5 & 0x3f] * uVar21 >> 6) - uVar21) * 4))
                             * 0x20 | ((uVar7 >> 0xb) +
                                      *(short *)(local_c +
                                                ((local_50[uVar15 >> 0xb] * (uint)(uVar7 >> 0xb) >>
                                                 5) - (uint)(uVar7 >> 0xb)) * 4)) * 0x800 |
                             (uVar7 & 0x1f) +
                             *(short *)(local_c +
                                       ((local_4c[uVar15 & 0x1f] * (uVar7 & 0x1f) >> 5) -
                                       (uVar7 & 0x1f)) * 4);
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        uVar15 = *(ushort *)
                                  (local_3c +
                                  (uint)*(byte *)(((int)((int)fVar26 +
                                                        ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) +
                                                 (&DAT_00f448d8)
                                                 [(int)((int)local_40 +
                                                       ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12])
                                  * 2);
                        uVar7 = (ushort)*puVar24;
                        uVar21 = uVar7 >> 5 & 0x3f;
                        *(ushort *)puVar24 =
                             ((uVar7 >> 5 & 0x3f) +
                             *(short *)(local_c +
                                       (((int)((uVar15 >> 5 & 0x3f) * uVar21) >> 6) - uVar21) * 4))
                             * 0x20 | ((uVar7 >> 0xb) +
                                      *(short *)(local_c +
                                                (((int)((uint)(uVar15 >> 0xb) * (uint)(uVar7 >> 0xb)
                                                       ) >> 5) - (uint)(uVar7 >> 0xb)) * 4)) * 0x800
                             | (uVar7 & 0x1f) +
                               *(short *)(local_c +
                                         (((int)((uVar15 & 0x1f) * (uVar7 & 0x1f)) >> 5) -
                                         (uVar7 & 0x1f)) * 4);
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if ((((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) &&
                       (uVar21 = (uint)*(byte *)(((int)((int)fVar26 +
                                                       ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) +
                                                (&DAT_00f448d8)
                                                [(int)((int)local_40 +
                                                      ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12]),
                       (float)uVar21 != local_58)) {
                      uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                      uVar7 = (ushort)*puVar24;
                      uVar21 = uVar7 >> 5 & 0x3f;
                      *(ushort *)puVar24 =
                           ((uVar7 >> 5 & 0x3f) +
                           *(short *)(local_c +
                                     (((int)((uVar15 >> 5 & 0x3f) * uVar21) >> 6) - uVar21) * 4)) *
                           0x20 | ((uVar7 >> 0xb) +
                                  *(short *)(local_c +
                                            (((int)((uint)(uVar15 >> 0xb) * (uint)(uVar7 >> 0xb)) >>
                                             5) - (uint)(uVar7 >> 0xb)) * 4)) * 0x800 |
                           (uVar7 & 0x1f) +
                           *(short *)(local_c +
                                     (((int)((uVar15 & 0x1f) * (uVar7 & 0x1f)) >> 5) -
                                     (uVar7 & 0x1f)) * 4);
                    }
                    local_40 = (float)((int)local_40 + local_34);
                    fVar26 = (float)((int)fVar26 + local_38);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  local_40 = (float)((int)local_40 + local_28);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar15 = *(ushort *)
                                  (local_3c + (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25) * 2)
                        ;
                        uVar7 = (ushort)*puVar24;
                        uVar21 = (uint)uVar7;
                        uVar11 = uVar7 >> 5 & 0x3f;
                        uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        *(ushort *)puVar24 =
                             (ushort)(((local_48[uVar15 >> 5 & 0x3f] * uVar11 >> 6) - uVar11) *
                                      uVar10 * iVar8 + (uVar21 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0
                             | (ushort)(((local_50[uVar15 >> 0xb] * (uint)(uVar7 >> 0xb) >> 5) -
                                        (uint)(uVar7 >> 0xb)) * uVar10 * DAT_00dca3f8 +
                                        (uVar21 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                             (ushort)(((local_4c[uVar15 & 0x1f] * (uVar21 & 0x1f) >> 5) -
                                      (uVar21 & 0x1f)) * uVar10 * DAT_00dca3f8 + uVar21 * 0x10000 >>
                                     0x10) & 0x1f;
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar21 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                      if ((float)uVar21 != local_58) {
                        uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                        uVar7 = (ushort)*puVar24;
                        uVar21 = (uint)uVar7;
                        uVar11 = uVar7 >> 5 & 0x3f;
                        uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        *(ushort *)puVar24 =
                             (ushort)(((local_48[uVar15 >> 5 & 0x3f] * uVar11 >> 6) - uVar11) *
                                      uVar10 * iVar8 + (uVar21 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0
                             | (ushort)(((local_50[uVar15 >> 0xb] * (uint)(uVar7 >> 0xb) >> 5) -
                                        (uint)(uVar7 >> 0xb)) * uVar10 * DAT_00dca3f8 +
                                        (uVar21 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                             (ushort)(((local_4c[uVar15 & 0x1f] * (uVar21 & 0x1f) >> 5) -
                                      (uVar21 & 0x1f)) * uVar10 * DAT_00dca3f8 + uVar21 * 0x10000 >>
                                     0x10) & 0x1f;
                        iVar8 = DAT_00dca3f8;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 == 0) {
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar15 = *(ushort *)
                                (local_3c + (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25) * 2);
                      uVar7 = (ushort)*puVar24;
                      uVar21 = (uint)uVar7;
                      uVar10 = uVar7 >> 5 & 0x3f;
                      uVar18 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                      uVar11 = uVar21 & 0x1f;
                      *(ushort *)puVar24 =
                           (ushort)((int)((((int)((uVar15 >> 5 & 0x3f) * uVar10) >> 6) - uVar10) *
                                          uVar18 * iVar8 + (uVar21 & 0x7e0) * 0x800) >> 0xb) & 0x7e0
                           | (ushort)((int)((((int)((uint)(uVar15 >> 0xb) * (uint)(uVar7 >> 0xb)) >>
                                             5) - (uint)(uVar7 >> 0xb)) * uVar18 * DAT_00dca3f8 +
                                           (uVar21 & 0xfffff800) * 0x20) >> 5) & 0xf800 |
                           (ushort)((((int)((uVar15 & 0x1f) * uVar11) >> 5) - uVar11) * uVar18 *
                                    DAT_00dca3f8 + uVar11 * 0x10000 >> 0x10);
                      iVar8 = DAT_00dca3f8;
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                    iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    uVar21 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                    if ((float)uVar21 != local_58) {
                      uVar15 = *(ushort *)(local_3c + uVar21 * 2);
                      uVar7 = (ushort)*puVar24;
                      uVar21 = (uint)uVar7;
                      uVar10 = uVar7 >> 5 & 0x3f;
                      uVar18 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                      uVar11 = uVar21 & 0x1f;
                      *(ushort *)puVar24 =
                           (ushort)((int)((((int)((uVar15 >> 5 & 0x3f) * uVar10) >> 6) - uVar10) *
                                          uVar18 * iVar8 + (uVar21 & 0x7e0) * 0x800) >> 0xb) & 0x7e0
                           | (ushort)((int)((((int)((uint)(uVar15 >> 0xb) * (uint)(uVar7 >> 0xb)) >>
                                             5) - (uint)(uVar7 >> 0xb)) * uVar18 * DAT_00dca3f8 +
                                           (uVar21 & 0xfffff800) * 0x20) >> 5) & 0xf800 |
                           (ushort)((((int)((uVar15 & 0x1f) * uVar11) >> 5) - uVar11) * uVar18 *
                                    DAT_00dca3f8 + uVar11 * 0x10000 >> 0x10);
                      iVar8 = DAT_00dca3f8;
                    }
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  local_14 = (float)((int)local_14 + local_34);
                  puVar24 = (uint *)((int)puVar24 + 2);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                local_14 = (float)((int)local_14 + local_28);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            }
          }
          else {
            switch(DAT_00dca3f4) {
            case 0:
switchD_0075854f_caseD_0:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            uVar15 = *(ushort *)
                                      ((&DAT_00f448d8)
                                       [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                        0x12] + ((int)((int)fVar26 +
                                                      ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) * 2
                                      );
                            *(ushort *)puVar24 =
                                 (*(short *)(local_50 + (uVar15 >> 0xb)) << 6 |
                                 *(ushort *)(local_48 + (uVar15 >> 5 & 0x3f))) << 5 |
                                 *(ushort *)(local_4c + (uVar15 & 0x1f));
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          uVar15 = *(ushort *)
                                    ((&DAT_00f448d8)
                                     [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                      0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                              >> 0x12) * 2);
                          if ((float)(uint)uVar15 != local_58) {
                            *(ushort *)puVar24 =
                                 (*(short *)(local_50 + (uVar15 >> 0xb)) << 6 |
                                 *(ushort *)(local_48 + (uVar15 >> 5 & 0x3f))) << 5 |
                                 *(ushort *)(local_4c + (uVar15 & 0x1f));
                          }
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar15 = *(ushort *)
                                    ((&DAT_00f448d8)
                                     [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                      0x12] + iVar8 * 4);
                          bVar13 = *(byte *)((&DAT_00f448d8)
                                             [(int)((int)local_40 +
                                                   ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                             iVar8 * 4 + 2);
                          uVar7 = (ushort)*puVar24;
                          uVar21 = uVar7 & 0x1f;
                          *(ushort *)puVar24 =
                               (ushort)((local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                        (uint)bVar13 + (uVar7 & 0xffffffe0) * 8 >> 3) & 0x7e0 |
                               ((*(short *)(local_50 + (uVar15 >> 0xb)) - (uVar7 >> 0xb)) *
                                (ushort)bVar13 + (uVar7 >> 3 & 0x1f00)) * 8 & 0xf800 |
                               (ushort)((local_4c[uVar15 & 0x1f] - uVar21) * (uint)bVar13 +
                                        uVar21 * 0x100 >> 8);
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        puVar2 = (ushort *)
                                 ((&DAT_00f448d8)
                                  [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12
                                  ] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12
                                      ) * 4);
                        bVar13 = (byte)puVar2[1];
                        if (bVar13 != 0) {
                          if (bVar13 == 0xff) {
                            uVar15 = *puVar2;
                            *(ushort *)puVar24 =
                                 (*(short *)(local_50 + (uVar15 >> 0xb)) << 6 |
                                 *(ushort *)(local_48 + (uVar15 >> 5 & 0x3f))) << 5 |
                                 *(ushort *)(local_4c + (uVar15 & 0x1f));
                          }
                          else {
                            uVar15 = *puVar2;
                            uVar7 = (ushort)*puVar24;
                            uVar21 = uVar7 & 0x1f;
                            *(ushort *)puVar24 =
                                 (ushort)((local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                          (uint)bVar13 + (uVar7 & 0xffffffe0) * 8 >> 3) & 0x7e0 |
                                 ((*(short *)(local_50 + (uVar15 >> 0xb)) - (uVar7 >> 0xb)) *
                                  (ushort)bVar13 + (uVar7 >> 3 & 0x1f00)) * 8 & 0xf800 |
                                 (ushort)((local_4c[uVar15 & 0x1f] - uVar21) * (uint)bVar13 +
                                          uVar21 * 0x100 >> 8);
                          }
                        }
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      iVar8 = local_7c;
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          *(ushort *)local_54 =
                               *(ushort *)
                                (((uint)fVar26 >> 0x11 & 0xfffffffe) +
                                (&DAT_00f448d8)[(uint)local_14 >> 0x12]);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        local_54 = (uint *)((int)local_54 + 2);
                        iVar8 = iVar8 + -1;
                      } while (iVar8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      local_54 = (uint *)((int)local_54 + local_64);
                      local_10 = local_10 + -1;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    iVar8 = local_7c;
                    do {
                      if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                         (uVar15 = *(ushort *)
                                    (((uint)fVar26 >> 0x11 & 0xfffffffe) +
                                    (&DAT_00f448d8)[(uint)local_14 >> 0x12]),
                         (float)(uint)uVar15 != local_58)) {
                        *(ushort *)local_54 = uVar15;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      local_54 = (uint *)((int)local_54 + 2);
                      iVar8 = iVar8 + -1;
                    } while (iVar8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    local_54 = (uint *)((int)local_54 + local_64);
                    local_10 = local_10 + -1;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar10 = (uint)*(ushort *)
                                        ((&DAT_00f448d8)
                                         [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU))
                                          >> 0x12] + iVar8 * 4);
                        uVar11 = (uint)*(byte *)((&DAT_00f448d8)
                                                 [(int)((int)local_14 +
                                                       ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]
                                                 + iVar8 * 4 + 2);
                        uVar21 = (uint)(ushort)*puVar24;
                        *(ushort *)puVar24 =
                             (ushort)(((uVar10 & 0xf800) - (uVar21 & 0xf800)) * uVar11 +
                                      (uVar21 & 0xfffff800) * 0x100 >> 8) & 0xf800 |
                             (ushort)(((uVar10 & 0x7e0) - (uVar21 & 0x7e0)) * uVar11 +
                                      (uVar21 & 0xffffffe0) * 0x100 >> 8) & 0x7e0 |
                             (ushort)(((uVar10 & 0x1f) - (uVar21 & 0x1f)) * uVar11 +
                                      (uVar21 & 0x1f) * 0x100 >> 8);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      puVar2 = (ushort *)
                               ((&DAT_00f448d8)
                                [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]
                               + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) * 4
                               );
                      bVar13 = (byte)puVar2[1];
                      if (bVar13 != 0) {
                        if (bVar13 == 0xff) {
                          *(ushort *)puVar24 = *puVar2;
                        }
                        else {
                          uVar21 = (uint)(ushort)*puVar24;
                          uVar10 = (uint)*puVar2;
                          uVar11 = (uint)bVar13;
                          *(ushort *)puVar24 =
                               (ushort)(((uVar10 & 0xf800) - (uVar21 & 0xf800)) * uVar11 +
                                        (uVar21 & 0xfffff800) * 0x100 >> 8) & 0xf800 |
                               (ushort)(((uVar10 & 0x7e0) - (uVar21 & 0x7e0)) * uVar11 +
                                        (uVar21 & 0xffffffe0) * 0x100 >> 8) & 0x7e0 |
                               (ushort)(((uVar10 & 0x1f) - (uVar21 & 0x1f)) * uVar11 +
                                        (uVar21 & 0x1f) * 0x100 >> 8);
                        }
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar15 = *(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 2);
                          bVar13 = (&DAT_00dca2e0)[*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                          uVar7 = (ushort)*puVar24;
                          uVar21 = uVar7 & 0x1f;
                          *(ushort *)puVar24 =
                               (ushort)((local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                        (uint)bVar13 + (uVar7 & 0xffffffe0) * 8 >> 3) & 0x7e0 |
                               ((*(short *)(local_50 + (uVar15 >> 0xb)) - (uVar7 >> 0xb)) *
                                (ushort)bVar13 + (uVar7 >> 3 & 0x1f00)) * 8 & 0xf800 |
                               (ushort)((local_4c[uVar15 & 0x1f] - uVar21) * (uint)bVar13 +
                                        uVar21 * 0x100 >> 8);
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar15 = *(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 2);
                        if ((float)(uint)uVar15 != local_58) {
                          bVar13 = (&DAT_00dca2e0)[*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                          uVar7 = (ushort)*puVar24;
                          uVar21 = uVar7 & 0x1f;
                          *(ushort *)puVar24 =
                               (ushort)((local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                        (uint)bVar13 + (uVar7 & 0xffffffe0) * 8 >> 3) & 0x7e0 |
                               ((*(short *)(local_50 + (uVar15 >> 0xb)) - (uVar7 >> 0xb)) *
                                (ushort)bVar13 + (uVar7 >> 3 & 0x1f00)) * 8 & 0xf800 |
                               (ushort)((local_4c[uVar15 & 0x1f] - uVar21) * (uint)bVar13 +
                                        uVar21 * 0x100 >> 8);
                        }
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar15 = *(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                        uVar11 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar8 * 4 + 2);
                        uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                        uVar7 = (ushort)*puVar24;
                        uVar21 = (uint)uVar7;
                        *(ushort *)puVar24 =
                             (ushort)((local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) * uVar10
                                      * uVar11 + (uVar21 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                             (ushort)((local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) * uVar10 *
                                      uVar11 + (uVar21 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                             (ushort)((local_4c[uVar15 & 0x1f] - (uVar21 & 0x1f)) * uVar10 * uVar11
                                      + (uVar21 & 0x1f) * 0x10000 >> 0x10);
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                      iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                      bVar13 = (byte)puVar2[1];
                      if (bVar13 != 0) {
                        uVar15 = *puVar2;
                        bVar3 = *(byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                        uVar7 = (ushort)*puVar24;
                        uVar21 = (uint)uVar7;
                        uVar11 = uVar15 >> 5 & 0x3f;
                        if (bVar13 == 0xff) {
                          bVar13 = (&DAT_00dca2e0)[bVar3];
                          *(ushort *)puVar24 =
                               (ushort)((local_48[uVar11] - (uVar7 >> 5 & 0x3f)) * (uint)bVar13 +
                                        (uVar21 & 0xffffffe0) * 8 >> 3) & 0x7e0 |
                               ((*(short *)(local_50 + (uVar15 >> 0xb)) - (uVar7 >> 0xb)) *
                                (ushort)bVar13 + (uVar7 >> 3 & 0x1f00)) * 8 & 0xf800 |
                               (ushort)((local_4c[uVar15 & 0x1f] - (uVar21 & 0x1f)) * (uint)bVar13 +
                                        (uVar21 & 0x1f) * 0x100 >> 8);
                        }
                        else {
                          uVar10 = (uint)(byte)(&DAT_00dca2e0)[bVar3];
                          uVar18 = (uint)bVar13;
                          *(ushort *)puVar24 =
                               (ushort)((local_48[uVar11] - (uVar7 >> 5 & 0x3f)) * uVar10 * uVar18 +
                                        (uVar21 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                               (ushort)((local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) * uVar10 *
                                        uVar18 + (uVar21 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                               (ushort)((local_4c[uVar15 & 0x1f] - (uVar21 & 0x1f)) * uVar10 *
                                        uVar18 + (uVar21 & 0x1f) * 0x10000 >> 0x10);
                        }
                      }
                    }
                    local_40 = (float)((int)local_40 + local_34);
                    fVar26 = (float)((int)fVar26 + local_38);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  local_40 = (float)((int)local_40 + local_28);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (*(int *)(iVar23 + 0x2c) != 1) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar18 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                        uVar21 = (uint)(ushort)*puVar24;
                        uVar11 = uVar21 << 8;
                        uVar10 = (uint)*(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 2);
                        *(ushort *)puVar24 =
                             (ushort)(((uVar10 & 0xf800) - (uVar21 & 0xf800)) * uVar18 +
                                      (uVar11 & 0xfff80000) >> 8) & 0xf800 |
                             (ushort)(((uVar10 & 0x7e0) - (uVar21 & 0x7e0)) * uVar18 +
                                      (uVar11 & 0xffffe000) >> 8) & 0x7e0 |
                             (ushort)(((uVar10 & 0x1f) - (uVar21 & 0x1f)) * uVar18 +
                                      (uVar11 & 0x1f00) >> 8);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar21 = (uint)*(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 2);
                      if ((float)uVar21 != local_58) {
                        uVar11 = (uint)(ushort)*puVar24;
                        uVar10 = uVar11 << 8;
                        uVar18 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                        *(ushort *)puVar24 =
                             (ushort)(((uVar21 & 0xf800) - (uVar11 & 0xf800)) * uVar18 +
                                      (uVar10 & 0xfff80000) >> 8) & 0xf800 |
                             (ushort)(((uVar21 & 0x7e0) - (uVar11 & 0x7e0)) * uVar18 +
                                      (uVar10 & 0xffffe000) >> 8) & 0x7e0 |
                             (ushort)(((uVar21 & 0x1f) - (uVar11 & 0x1f)) * uVar18 +
                                      (uVar10 & 0x1f00) >> 8);
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 == 0) {
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar18 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                      puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                      uVar21 = (uint)(ushort)*puVar24;
                      uVar22 = (uint)(byte)puVar2[1];
                      uVar11 = uVar21 << 0x10;
                      uVar10 = (uint)*puVar2;
                      *(ushort *)puVar24 =
                           (ushort)(((uVar10 & 0x7e0) - (uVar21 & 0x7e0)) * uVar18 * uVar22 +
                                    (uVar11 & 0xffe00000) >> 0x10) & 0x7e0 |
                           (ushort)(((uVar10 & 0xf800) - (uVar21 & 0xf800)) * uVar18 * uVar22 +
                                    (uVar11 & 0xf8000000) >> 0x10) & 0xf800 |
                           (ushort)(((uVar10 & 0x1f) - (uVar21 & 0x1f)) * uVar18 * uVar22 +
                                    (uVar11 & 0x1f0000) >> 0x10);
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                    iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                    bVar13 = (byte)puVar2[1];
                    uVar21 = (uint)bVar13;
                    if (bVar13 != 0) {
                      uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                      uVar11 = (uint)(ushort)*puVar24;
                      if (bVar13 == 0xff) {
                        uVar21 = uVar11 << 8;
                        uVar18 = (uint)*puVar2;
                        uVar7 = (ushort)(((uVar18 & 0xf800) - (uVar11 & 0xf800)) * uVar10 +
                                         (uVar21 & 0xfff80000) >> 8) & 0xf800 |
                                (ushort)(((uVar18 & 0x7e0) - (uVar11 & 0x7e0)) * uVar10 +
                                         (uVar21 & 0xffffe000) >> 8) & 0x7e0;
                        uVar15 = (ushort)(((uVar18 & 0x1f) - (uVar11 & 0x1f)) * uVar10 +
                                          (uVar21 & 0x1f00) >> 8);
                      }
                      else {
                        uVar18 = uVar11 << 0x10;
                        uVar22 = (uint)*puVar2;
                        uVar7 = (ushort)(((uVar22 & 0x7e0) - (uVar11 & 0x7e0)) * uVar10 * uVar21 +
                                         (uVar18 & 0xffe00000) >> 0x10) & 0x7e0 |
                                (ushort)(((uVar22 & 0xf800) - (uVar11 & 0xf800)) * uVar10 * uVar21 +
                                         (uVar18 & 0xf8000000) >> 0x10) & 0xf800;
                        uVar15 = (ushort)(((uVar22 & 0x1f) - (uVar11 & 0x1f)) * uVar10 * uVar21 +
                                          (uVar18 & 0x1f0000) >> 0x10);
                      }
                      *(ushort *)puVar24 = uVar7 | uVar15;
                    }
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  local_14 = (float)((int)local_14 + local_34);
                  puVar24 = (uint *)((int)puVar24 + 2);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                local_14 = (float)((int)local_14 + local_28);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            case 1:
              if (iVar8 == 0xff) goto switchD_0075854f_caseD_0;
              if (iVar8 != 0) {
                if (param_11 == 0) {
                  if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                    if (*(int *)(iVar23 + 0x2c) != 1) {
                      if (param_8 == 0) {
                        do {
                          do {
                            if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                              uVar15 = *(ushort *)
                                        ((&DAT_00f448d8)
                                         [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU))
                                          >> 0x12] +
                                        ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                        0x12) * 2);
                              uVar7 = (ushort)*puVar24;
                              *(ushort *)puVar24 =
                                   ((uVar7 >> 5 & 0x3f) +
                                   *(short *)(local_c +
                                             (local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                             4)) * 0x20 |
                                   ((uVar7 >> 0xb) +
                                   *(short *)(local_c +
                                             (local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) * 4))
                                   * 0x800 | (uVar7 & 0x1f) +
                                             *(short *)(local_c +
                                                       (local_4c[uVar15 & 0x1f] - (uVar7 & 0x1f)) *
                                                       4);
                            }
                            local_40 = (float)((int)local_40 + local_34);
                            fVar26 = (float)((int)fVar26 + local_38);
                            puVar24 = (uint *)((int)puVar24 + 2);
                            local_8 = local_8 + -1;
                          } while (local_8 != 0);
                          local_40 = (float)((int)local_40 + local_28);
                          fVar26 = (float)((int)fVar26 + local_2c);
                          puVar24 = (uint *)((int)puVar24 + local_64);
                          local_10 = local_10 + -1;
                          local_8 = local_7c;
                        } while (local_10 != 0);
                        return;
                      }
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                            uVar15 = *(ushort *)
                                      ((&DAT_00f448d8)
                                       [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                        0x12] + ((int)((int)fVar26 +
                                                      ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) * 2
                                      );
                            if ((float)(uint)uVar15 != local_58) {
                              uVar7 = (ushort)*puVar24;
                              *(ushort *)puVar24 =
                                   ((uVar7 >> 5 & 0x3f) +
                                   *(short *)(local_c +
                                             (local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                             4)) * 0x20 |
                                   ((uVar7 >> 0xb) +
                                   *(short *)(local_c +
                                             (local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) * 4))
                                   * 0x800 | (uVar7 & 0x1f) +
                                             *(short *)(local_c +
                                                       (local_4c[uVar15 & 0x1f] - (uVar7 & 0x1f)) *
                                                       4);
                            }
                          }
                          local_40 = (float)((int)local_40 + local_34);
                          fVar26 = (float)((int)fVar26 + local_38);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        local_40 = (float)((int)local_40 + local_28);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                            uVar15 = (ushort)*puVar24;
                            uVar11 = (uint)uVar15;
                            puVar2 = (ushort *)
                                     ((&DAT_00f448d8)
                                      [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                       0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)
                                                     ) >> 0x12) * 4);
                            uVar7 = *puVar2;
                            uVar21 = (uint)(byte)puVar2[1];
                            *(ushort *)puVar24 =
                                 (ushort)((local_48[uVar7 >> 5 & 0x3f] - (uVar15 >> 5 & 0x3f)) *
                                          uVar21 * iVar8 + (uVar11 & 0xffffffe0) * 0x800 >> 0xb) &
                                 0x7e0 | (ushort)((local_50[uVar7 >> 0xb] - (uint)(uVar15 >> 0xb)) *
                                                  uVar21 * DAT_00dca3f8 +
                                                  (uVar11 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                 (ushort)((local_4c[uVar7 & 0x1f] - (uVar11 & 0x1f)) * uVar21 *
                                          DAT_00dca3f8 + uVar11 * 0x10000 >> 0x10) & 0x1f;
                            iVar8 = DAT_00dca3f8;
                          }
                          local_40 = (float)((int)local_40 + local_34);
                          fVar26 = (float)((int)fVar26 + local_38);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        local_40 = (float)((int)local_40 + local_28);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          puVar2 = (ushort *)
                                   ((&DAT_00f448d8)
                                    [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                     0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) * 4);
                          bVar13 = (byte)puVar2[1];
                          if (bVar13 != 0) {
                            if (bVar13 == 0xff) {
                              uVar15 = *puVar2;
                              uVar7 = (ushort)*puVar24;
                              *(ushort *)puVar24 =
                                   ((uVar7 >> 5 & 0x3f) +
                                   *(short *)(local_c +
                                             (local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                             4)) * 0x20 |
                                   ((uVar7 >> 0xb) +
                                   *(short *)(local_c +
                                             (local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) * 4))
                                   * 0x800 | (uVar7 & 0x1f) +
                                             *(short *)(local_c +
                                                       (local_4c[uVar15 & 0x1f] - (uVar7 & 0x1f)) *
                                                       4);
                            }
                            else {
                              uVar15 = *puVar2;
                              uVar7 = (ushort)*puVar24;
                              uVar21 = (uint)uVar7;
                              uVar11 = (uint)bVar13;
                              *(ushort *)puVar24 =
                                   (ushort)((local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                            uVar11 * DAT_00dca3f8 + (uVar21 & 0xffffffe0) * 0x800 >>
                                           0xb) & 0x7e0 |
                                   (ushort)((local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                            uVar11 * DAT_00dca3f8 + (uVar21 & 0xfffff800) * 0x20 >>
                                           5) & 0xf800 |
                                   (ushort)((local_4c[uVar15 & 0x1f] - (uVar21 & 0x1f)) * uVar11 *
                                            DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10) & 0x1f;
                            }
                          }
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                            uVar15 = (ushort)*puVar24;
                            uVar7 = *(ushort *)
                                     ((&DAT_00f448d8)
                                      [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                       0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)
                                                     ) >> 0x12) * 2);
                            *(ushort *)puVar24 =
                                 ((uVar15 >> 5 & 0x3f) +
                                 *(short *)(local_c +
                                           ((uVar7 >> 5 & 0x3f) - (uVar15 >> 5 & 0x3f)) * 4)) * 0x20
                                 | ((uVar15 >> 0xb) +
                                   *(short *)(local_c +
                                             ((uint)(uVar7 >> 0xb) - (uint)(uVar15 >> 0xb)) * 4)) *
                                   0x800 | (uVar15 & 0x1f) +
                                           *(short *)(local_c +
                                                     ((uVar7 & 0x1f) - (uVar15 & 0x1f)) * 4);
                          }
                          local_40 = (float)((int)local_40 + local_34);
                          fVar26 = (float)((int)fVar26 + local_38);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        local_40 = (float)((int)local_40 + local_28);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          uVar15 = *(ushort *)
                                    ((&DAT_00f448d8)
                                     [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                      0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                              >> 0x12) * 2);
                          if ((float)(uint)uVar15 != local_58) {
                            uVar7 = (ushort)*puVar24;
                            *(ushort *)puVar24 =
                                 ((uVar7 >> 5 & 0x3f) +
                                 *(short *)(local_c +
                                           ((uVar15 >> 5 & 0x3f) - (uVar7 >> 5 & 0x3f)) * 4)) * 0x20
                                 | ((uVar7 >> 0xb) +
                                   *(short *)(local_c +
                                             ((uint)(uVar15 >> 0xb) - (uint)(uVar7 >> 0xb)) * 4)) *
                                   0x800 | (uVar7 & 0x1f) +
                                           *(short *)(local_c +
                                                     ((uVar15 & 0x1f) - (uVar7 & 0x1f)) * 4);
                          }
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar10 = (uint)*(ushort *)
                                          ((&DAT_00f448d8)
                                           [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)
                                                 ) >> 0x12] + iVar8 * 4);
                          uVar11 = (uint)*(byte *)((&DAT_00f448d8)
                                                   [(int)((int)local_14 +
                                                         ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                                   ] + iVar8 * 4 + 2);
                          uVar21 = (uint)(ushort)*puVar24;
                          *(ushort *)puVar24 =
                               (ushort)(((uVar10 & 0xf800) - (uVar21 & 0xf800)) * uVar11 *
                                        DAT_00dca3f8 + (uVar21 & 0xfffff800) * 0x10000 >> 0x10) &
                               0xf800 | (ushort)(((uVar10 & 0x7e0) - (uVar21 & 0x7e0)) * uVar11 *
                                                 DAT_00dca3f8 + (uVar21 & 0xffffffe0) * 0x10000 >>
                                                0x10) & 0x7e0 |
                               (ushort)(((uVar10 & 0x1f) - (uVar21 & 0x1f)) * uVar11 * DAT_00dca3f8
                                        + (uVar21 & 0x1f) * 0x10000 >> 0x10);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        bVar13 = *(byte *)((&DAT_00f448d8)
                                           [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)
                                                 ) >> 0x12] + 2 + iVar8 * 4);
                        if (bVar13 != 0) {
                          uVar15 = *(ushort *)
                                    ((&DAT_00f448d8)
                                     [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                      0x12] + iVar8 * 4);
                          uVar11 = (uint)uVar15;
                          uVar7 = (ushort)*puVar24;
                          uVar21 = (uint)uVar7;
                          if (bVar13 == 0xff) {
                            uVar15 = ((uVar7 >> 5 & 0x3f) +
                                     *(short *)(local_c +
                                               ((uVar15 >> 5 & 0x3f) - (uVar7 >> 5 & 0x3f)) * 4)) *
                                     0x20 | ((uVar7 >> 0xb) +
                                            *(short *)(local_c +
                                                      ((uint)(uVar15 >> 0xb) - (uint)(uVar7 >> 0xb))
                                                      * 4)) * 0x800 |
                                     (uVar7 & 0x1f) +
                                     *(short *)(local_c + ((uVar11 & 0x1f) - (uVar21 & 0x1f)) * 4);
                          }
                          else {
                            uVar10 = (uint)bVar13;
                            uVar15 = (ushort)(((uVar11 & 0xf800) - (uVar21 & 0xf800)) * uVar10 *
                                              DAT_00dca3f8 + (uVar21 & 0xfffff800) * 0x10000 >> 0x10
                                             ) & 0xf800 |
                                     (ushort)(((uVar11 & 0x7e0) - (uVar21 & 0x7e0)) * uVar10 *
                                              DAT_00dca3f8 + (uVar21 & 0xffffffe0) * 0x10000 >> 0x10
                                             ) & 0x7e0 |
                                     (ushort)(((uVar11 & 0x1f) - (uVar21 & 0x1f)) * uVar10 *
                                              DAT_00dca3f8 + (uVar21 & 0x1f) * 0x10000 >> 0x10);
                          }
                          *(ushort *)puVar24 = uVar15;
                        }
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                            iVar25 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                     0x12;
                            iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                            uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                                 [*(byte *)((&DAT_00f408d8)[iVar25] + iVar23)];
                            uVar15 = *(ushort *)((&DAT_00f448d8)[iVar25] + iVar23 * 2);
                            uVar7 = (ushort)*puVar24;
                            uVar21 = (uint)uVar7;
                            *(ushort *)puVar24 =
                                 (ushort)((local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                          uVar11 * iVar8 + (uVar21 & 0xffffffe0) * 0x800 >> 0xb) &
                                 0x7e0 | (ushort)((local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                                  uVar11 * DAT_00dca3f8 +
                                                  (uVar21 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                 (ushort)((local_4c[uVar15 & 0x1f] - (uVar21 & 0x1f)) * uVar11 *
                                          DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10) & 0x1f;
                            iVar8 = DAT_00dca3f8;
                          }
                          local_40 = (float)((int)local_40 + local_34);
                          fVar26 = (float)((int)fVar26 + local_38);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        local_40 = (float)((int)local_40 + local_28);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar15 = *(ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 2);
                          if ((float)(uint)uVar15 != local_58) {
                            uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                                 [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                            uVar7 = (ushort)*puVar24;
                            uVar21 = (uint)uVar7;
                            *(ushort *)puVar24 =
                                 (ushort)((local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                          uVar11 * iVar8 + (uVar21 & 0xffffffe0) * 0x800 >> 0xb) &
                                 0x7e0 | (ushort)((local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                                  uVar11 * DAT_00dca3f8 +
                                                  (uVar21 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                 (ushort)((local_4c[uVar15 & 0x1f] - (uVar21 & 0x1f)) * uVar11 *
                                          DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10) & 0x1f;
                            iVar8 = DAT_00dca3f8;
                          }
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          iVar25 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar25] + iVar23)];
                          puVar2 = (ushort *)((&DAT_00f448d8)[iVar25] + iVar23 * 4);
                          uVar15 = *puVar2;
                          uVar11 = (uint)(byte)puVar2[1];
                          uVar7 = (ushort)*puVar24;
                          uVar21 = (uint)uVar7;
                          *(ushort *)puVar24 =
                               (ushort)((local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                        uVar10 * uVar11 * iVar8 + (uVar21 & 0xffffffe0) * 0x80000 >>
                                       0x13) & 0x7e0 |
                               (ushort)((local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) * uVar10 *
                                        uVar11 * DAT_00dca3f8 + (uVar21 & 0xfffff800) * 0x2000 >>
                                       0xd) & 0xf800 |
                               (byte)((local_4c[uVar15 & 0x1f] - (uVar21 & 0x1f)) * uVar10 * uVar11
                                      * DAT_00dca3f8 + uVar21 * 0x1000000 >> 0x18) & 0x1f;
                          iVar8 = DAT_00dca3f8;
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        bVar13 = (byte)puVar2[1];
                        if (bVar13 != 0) {
                          uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          if (bVar13 == 0xff) {
                            uVar15 = *puVar2;
                            uVar7 = (ushort)*puVar24;
                            uVar11 = (uint)uVar7;
                            uVar7 = (ushort)((local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                             uVar21 * iVar8 + (uVar11 & 0xffffffe0) * 0x800 >> 0xb)
                                    & 0x7e0 | (ushort)((local_50[uVar15 >> 0xb] -
                                                       (uint)(uVar7 >> 0xb)) * uVar21 * DAT_00dca3f8
                                                       + (uVar11 & 0xfffff800) * 0x20 >> 5) & 0xf800
                            ;
                            uVar15 = (ushort)((local_4c[uVar15 & 0x1f] - (uVar11 & 0x1f)) * uVar21 *
                                              DAT_00dca3f8 + uVar11 * 0x10000 >> 0x10);
                          }
                          else {
                            uVar15 = *puVar2;
                            uVar11 = (uint)bVar13;
                            uVar7 = (ushort)*puVar24;
                            uVar10 = (uint)uVar7;
                            uVar7 = (ushort)((local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                             uVar21 * uVar11 * iVar8 +
                                             (uVar10 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                                    (ushort)((local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                             uVar21 * uVar11 * DAT_00dca3f8 +
                                             (uVar10 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800;
                            uVar15 = (ushort)(byte)((local_4c[uVar15 & 0x1f] - (uVar10 & 0x1f)) *
                                                    uVar21 * uVar11 * DAT_00dca3f8 +
                                                    uVar10 * 0x1000000 >> 0x18);
                          }
                          *(ushort *)puVar24 = uVar7 | uVar15 & 0x1f;
                          iVar8 = DAT_00dca3f8;
                        }
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar11 = (uint)*(ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 2);
                          uVar21 = (uint)(ushort)*puVar24;
                          uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          *(ushort *)puVar24 =
                               (ushort)(((uVar11 & 0x7e0) - (uVar21 & 0x7e0)) * uVar10 * iVar8 +
                                        (uVar21 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                               (ushort)(((uVar11 & 0xf800) - (uVar21 & 0xf800)) * uVar10 *
                                        DAT_00dca3f8 + (uVar21 & 0xfffff800) * 0x10000 >> 0x10) &
                               0xf800 | (ushort)(((uVar11 & 0x1f) - (uVar21 & 0x1f)) * uVar10 *
                                                 DAT_00dca3f8 + (uVar21 & 0x1f) * 0x10000 >> 0x10);
                          iVar8 = DAT_00dca3f8;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar21 = (uint)*(ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 2);
                        if ((float)uVar21 != local_58) {
                          uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          uVar11 = (uint)(ushort)*puVar24;
                          *(ushort *)puVar24 =
                               (ushort)(((uVar21 & 0x7e0) - (uVar11 & 0x7e0)) * uVar10 * iVar8 +
                                        (uVar11 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                               (ushort)(((uVar21 & 0xf800) - (uVar11 & 0xf800)) * uVar10 *
                                        DAT_00dca3f8 + (uVar11 & 0xfffff800) * 0x10000 >> 0x10) &
                               0xf800 | (ushort)(((uVar21 & 0x1f) - (uVar11 & 0x1f)) * uVar10 *
                                                 DAT_00dca3f8 + (uVar11 & 0x1f) * 0x10000 >> 0x10);
                          iVar8 = DAT_00dca3f8;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        uVar15 = *puVar2;
                        uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        uVar7 = (ushort)*puVar24;
                        uVar21 = (uint)uVar7;
                        uVar10 = (uint)(byte)puVar2[1];
                        *(ushort *)puVar24 =
                             (ushort)(((uVar15 >> 5 & 0x3f) - (uVar7 >> 5 & 0x3f)) * uVar11 * uVar10
                                      * iVar8 + (uVar21 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                             (ushort)(((uint)(uVar15 >> 0xb) - (uint)(uVar7 >> 0xb)) * uVar11 *
                                      uVar10 * DAT_00dca3f8 + (uVar21 & 0xfffff800) * 0x2000 >> 0xd)
                             & 0xf800 |
                             (ushort)(byte)(((uVar15 & 0x1f) - (uVar21 & 0x1f)) * uVar11 * uVar10 *
                                            DAT_00dca3f8 + (uVar21 & 0x1f) * 0x1000000 >> 0x18);
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)(((int)fVar26 >> 0x1f & 0x3ffffU) + (int)fVar26) >> 0x12;
                      puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                      bVar13 = (byte)puVar2[1];
                      uVar21 = (uint)bVar13;
                      if (bVar13 != 0) {
                        uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        uVar15 = (ushort)*puVar24;
                        uVar10 = (uint)uVar15;
                        uVar7 = *puVar2;
                        uVar18 = (uint)uVar7;
                        if (bVar13 == 0xff) {
                          uVar15 = (ushort)(((uVar18 & 0x7e0) - (uVar10 & 0x7e0)) * uVar11 * iVar8 +
                                            (uVar10 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                                   (ushort)(((uVar18 & 0xf800) - (uVar10 & 0xf800)) * uVar11 *
                                            DAT_00dca3f8 + (uVar10 & 0xfffff800) * 0x10000 >> 0x10)
                                   & 0xf800;
                          uVar7 = (ushort)(((uVar18 & 0x1f) - (uVar10 & 0x1f)) * uVar11 *
                                           DAT_00dca3f8 + (uVar10 & 0x1f) * 0x10000 >> 0x10);
                        }
                        else {
                          uVar15 = (ushort)(((uVar7 >> 5 & 0x3f) - (uVar15 >> 5 & 0x3f)) * uVar11 *
                                            uVar21 * iVar8 + (uVar10 & 0xffffffe0) * 0x80000 >> 0x13
                                           ) & 0x7e0 |
                                   (ushort)(((uint)(uVar7 >> 0xb) - (uint)(uVar15 >> 0xb)) * uVar11
                                            * uVar21 * DAT_00dca3f8 + (uVar10 & 0xfffff800) * 0x2000
                                           >> 0xd) & 0xf800;
                          uVar7 = (ushort)(byte)(((uVar18 & 0x1f) - (uVar10 & 0x1f)) * uVar11 *
                                                 uVar21 * DAT_00dca3f8 + (uVar10 & 0x1f) * 0x1000000
                                                >> 0x18);
                        }
                        *(ushort *)puVar24 = uVar15 | uVar7;
                        iVar8 = DAT_00dca3f8;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              break;
            case 2:
              if (iVar8 != 0) {
                if (param_11 == 0) {
                  if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                    if (*(int *)(iVar23 + 0x2c) != 1) {
                      if (param_8 == 0) {
                        do {
                          do {
                            if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                              uVar15 = *(ushort *)
                                        ((&DAT_00f448d8)
                                         [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU))
                                          >> 0x12] +
                                        ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                        0x12) * 2);
                              uVar15 = (*(short *)(local_18 + local_50[uVar15 >> 0xb]) * 0x40 +
                                       *(short *)(local_18 + local_48[uVar15 >> 5 & 0x3f])) * 0x20 +
                                       *(short *)(local_18 + local_4c[uVar15 & 0x1f]);
                              uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                              uVar11 = uVar21 & 0x8210820;
                              *(ushort *)puVar24 =
                                   (short)uVar11 - (short)(uVar11 >> 5) |
                                   ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                            }
                            fVar26 = (float)((int)fVar26 + local_38);
                            local_14 = (float)((int)local_14 + local_34);
                            puVar24 = (uint *)((int)puVar24 + 2);
                            local_8 = local_8 + -1;
                          } while (local_8 != 0);
                          fVar26 = (float)((int)fVar26 + local_2c);
                          local_14 = (float)((int)local_14 + local_28);
                          puVar24 = (uint *)((int)puVar24 + local_64);
                          local_10 = local_10 + -1;
                          local_8 = local_7c;
                        } while (local_10 != 0);
                        return;
                      }
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            uVar15 = *(ushort *)
                                      ((&DAT_00f448d8)
                                       [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                        0x12] + ((int)((int)fVar26 +
                                                      ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) * 2
                                      );
                            if ((float)(uint)uVar15 != local_58) {
                              uVar15 = (*(short *)(local_18 + local_50[uVar15 >> 0xb]) * 0x40 +
                                       *(short *)(local_18 + local_48[uVar15 >> 5 & 0x3f])) * 0x20 +
                                       *(short *)(local_18 + local_4c[uVar15 & 0x1f]);
                              uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                              uVar11 = uVar21 & 0x8210820;
                              *(ushort *)puVar24 =
                                   (short)uVar11 - (short)(uVar11 >> 5) |
                                   ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                            }
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            puVar2 = (ushort *)
                                     ((&DAT_00f448d8)
                                      [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                       0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)
                                                     ) >> 0x12) * 4);
                            uVar21 = (uint)*puVar2;
                            uVar11 = (uint)(byte)puVar2[1];
                            uVar15 = (*(short *)(local_18 +
                                                local_50[(uVar21 & 0xf800) * uVar11 >> 0x13]) * 0x40
                                     + *(short *)(local_18 +
                                                 local_48[(uVar21 & 0x7e0) * uVar11 >> 0xd])) * 0x20
                                     + *(short *)(local_18 + local_4c[(uVar21 & 0x1f) * uVar11 >> 8]
                                                 );
                            uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                            uVar11 = uVar21 & 0x8210820;
                            *(ushort *)puVar24 =
                                 (short)uVar11 - (short)(uVar11 >> 5) |
                                 ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          puVar2 = (ushort *)
                                   ((&DAT_00f448d8)
                                    [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                     0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) * 4);
                          bVar13 = (byte)puVar2[1];
                          if (bVar13 != 0) {
                            uVar15 = *puVar2;
                            uVar21 = (uint)uVar15;
                            if (bVar13 == 0xff) {
                              uVar15 = (*(short *)(local_18 + local_50[uVar15 >> 0xb]) * 0x40 +
                                       *(short *)(local_18 + local_48[uVar15 >> 5 & 0x3f])) * 0x20 +
                                       *(short *)(local_18 + local_4c[uVar21 & 0x1f]);
                            }
                            else {
                              uVar11 = (uint)bVar13;
                              uVar15 = (*(short *)(local_18 +
                                                  local_50[(uVar21 & 0xf800) * uVar11 >> 0x13]) *
                                        0x40 + *(short *)(local_18 +
                                                         local_48[(uVar21 & 0x7e0) * uVar11 >> 0xd])
                                       ) * 0x20 +
                                       *(short *)(local_18 + local_4c[(uVar21 & 0x1f) * uVar11 >> 8]
                                                 );
                            }
                            uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                            uVar11 = uVar21 & 0x8210820;
                            *(ushort *)puVar24 =
                                 (short)uVar11 - (short)(uVar11 >> 5) |
                                 ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                          }
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            uVar15 = *(ushort *)
                                      ((&DAT_00f448d8)
                                       [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                        0x12] + ((int)((int)fVar26 +
                                                      ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) * 2
                                      );
                            uVar15 = (*(short *)(local_18 + (uVar15 >> 0xb)) * 0x40 +
                                     *(short *)(local_18 + (uVar15 >> 5 & 0x3f))) * 0x20 +
                                     *(short *)(local_18 + (uVar15 & 0x1f));
                            uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                            uVar11 = uVar21 & 0x8210820;
                            *(ushort *)puVar24 =
                                 (short)uVar11 - (short)(uVar11 >> 5) |
                                 ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          uVar15 = *(ushort *)
                                    ((&DAT_00f448d8)
                                     [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                      0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                              >> 0x12) * 2);
                          if ((float)(uint)uVar15 != local_58) {
                            uVar15 = (*(short *)(local_18 + (uVar15 >> 0xb)) * 0x40 +
                                     *(short *)(local_18 + (uVar15 >> 5 & 0x3f))) * 0x20 +
                                     *(short *)(local_18 + (uVar15 & 0x1f));
                            uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                            uVar11 = uVar21 & 0x8210820;
                            *(ushort *)puVar24 =
                                 (short)uVar11 - (short)(uVar11 >> 5) |
                                 ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                          }
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          puVar2 = (ushort *)
                                   ((&DAT_00f448d8)
                                    [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                     0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) * 4);
                          uVar21 = (uint)*puVar2;
                          uVar11 = (uint)(byte)puVar2[1];
                          uVar15 = (*(short *)(local_18 + ((uVar21 & 0xf800) * uVar11 >> 0x13)) *
                                    0x40 + *(short *)(local_18 + ((uVar21 & 0x7e0) * uVar11 >> 0xd))
                                   ) * 0x20 + *(short *)(local_18 + ((uVar21 & 0x1f) * uVar11 >> 8))
                          ;
                          uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                          uVar11 = uVar21 & 0x8210820;
                          *(ushort *)puVar24 =
                               (short)uVar11 - (short)(uVar11 >> 5) |
                               ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        puVar2 = (ushort *)
                                 ((&DAT_00f448d8)
                                  [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                  ] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12
                                      ) * 4);
                        bVar13 = (byte)puVar2[1];
                        if (bVar13 != 0) {
                          uVar15 = *puVar2;
                          uVar21 = (uint)uVar15;
                          if (bVar13 == 0xff) {
                            uVar15 = (*(short *)(local_18 + (uVar15 >> 0xb)) * 0x40 +
                                     *(short *)(local_18 + (uVar15 >> 5 & 0x3f))) * 0x20 +
                                     *(short *)(local_18 + (uVar21 & 0x1f));
                          }
                          else {
                            uVar11 = (uint)bVar13;
                            uVar15 = (*(short *)(local_18 + ((uVar21 & 0xf800) * uVar11 >> 0x13)) *
                                      0x40 + *(short *)(local_18 +
                                                       ((uVar21 & 0x7e0) * uVar11 >> 0xd))) * 0x20 +
                                     *(short *)(local_18 + ((uVar21 & 0x1f) * uVar11 >> 8));
                          }
                          uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                          uVar11 = uVar21 & 0x8210820;
                          *(ushort *)puVar24 =
                               (short)uVar11 - (short)(uVar11 >> 5) |
                               ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                     0x12;
                            iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                            uVar15 = *(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 2);
                            uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                                 [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                            uVar15 = (*(short *)(local_18 + (local_50[uVar15 >> 0xb] * uVar21 >> 8))
                                      * 0x40 + *(short *)(local_18 +
                                                         (local_48[uVar15 >> 5 & 0x3f] * uVar21 >> 8
                                                         ))) * 0x20 +
                                     *(short *)(local_18 + (local_4c[uVar15 & 0x1f] * uVar21 >> 8));
                            uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                            uVar11 = uVar21 & 0x8210820;
                            *(ushort *)puVar24 =
                                 (short)uVar11 - (short)(uVar11 >> 5) |
                                 ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar15 = *(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 2);
                          if ((float)(uint)uVar15 != local_58) {
                            uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                                 [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                            uVar15 = (*(short *)(local_18 + (local_50[uVar15 >> 0xb] * uVar21 >> 8))
                                      * 0x40 + *(short *)(local_18 +
                                                         (local_48[uVar15 >> 5 & 0x3f] * uVar21 >> 8
                                                         ))) * 0x20 +
                                     *(short *)(local_18 + (local_4c[uVar15 & 0x1f] * uVar21 >> 8));
                            uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                            uVar11 = uVar21 & 0x8210820;
                            *(ushort *)puVar24 =
                                 (short)uVar11 - (short)(uVar11 >> 5) |
                                 ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                          }
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                          puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                          uVar15 = *puVar2;
                          uVar21 = (uint)(byte)puVar2[1];
                          uVar15 = (*(short *)(local_18 +
                                              (local_50[uVar15 >> 0xb] * uVar11 * uVar21 >> 0x10)) *
                                    0x40 + *(short *)(local_18 +
                                                     (local_48[uVar15 >> 5 & 0x3f] * uVar11 * uVar21
                                                     >> 0x10))) * 0x20 +
                                   *(short *)(local_18 +
                                             (local_4c[uVar15 & 0x1f] * uVar11 * uVar21 >> 0x10));
                          uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                          uVar11 = uVar21 & 0x8210820;
                          *(ushort *)puVar24 =
                               (short)uVar11 - (short)(uVar11 >> 5) |
                               ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                        bVar13 = (byte)puVar2[1];
                        if (bVar13 != 0) {
                          uVar15 = *puVar2;
                          uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                          if (bVar13 == 0xff) {
                            sVar16 = *(short *)(local_18 + (local_50[uVar15 >> 0xb] * uVar21 >> 8))
                                     * 0x40 + *(short *)(local_18 +
                                                        (local_48[uVar15 >> 5 & 0x3f] * uVar21 >> 8)
                                                        );
                            uVar21 = local_4c[uVar15 & 0x1f] * uVar21 >> 8;
                          }
                          else {
                            uVar11 = (uint)bVar13;
                            sVar16 = *(short *)(local_18 +
                                               (local_50[uVar15 >> 0xb] * uVar21 * uVar11 >> 0x10))
                                     * 0x40 + *(short *)(local_18 +
                                                        (local_48[uVar15 >> 5 & 0x3f] * uVar21 *
                                                         uVar11 >> 0x10));
                            uVar21 = local_4c[uVar15 & 0x1f] * uVar21 * uVar11 >> 0x10;
                          }
                          uVar15 = sVar16 * 0x20 + *(short *)(local_18 + uVar21);
                          uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                          uVar11 = uVar21 & 0x8210820;
                          *(ushort *)puVar24 =
                               (short)uVar11 - (short)(uVar11 >> 5) |
                               ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar11 = (uint)*(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 2);
                          uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                          uVar15 = (*(short *)(local_18 + ((uVar11 & 0xf800) * uVar21 >> 0x13)) *
                                    0x40 + *(short *)(local_18 + ((uVar11 & 0x7e0) * uVar21 >> 0xd))
                                   ) * 0x20 + *(short *)(local_18 + ((uVar11 & 0x1f) * uVar21 >> 8))
                          ;
                          uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                          uVar11 = uVar21 & 0x8210820;
                          *(ushort *)puVar24 =
                               (short)uVar11 - (short)(uVar11 >> 5) |
                               ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar21 = (uint)*(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 2);
                        if ((float)uVar21 != local_58) {
                          uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                          uVar15 = (*(short *)(local_18 + ((uVar21 & 0xf800) * uVar11 >> 0x13)) *
                                    0x40 + *(short *)(local_18 + ((uVar21 & 0x7e0) * uVar11 >> 0xd))
                                   ) * 0x20 + *(short *)(local_18 + ((uVar21 & 0x1f) * uVar11 >> 8))
                          ;
                          uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                          uVar11 = uVar21 & 0x8210820;
                          *(ushort *)puVar24 =
                               (short)uVar11 - (short)(uVar11 >> 5) |
                               ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar25 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        puVar2 = (ushort *)((&DAT_00f448d8)[iVar25] + iVar8 * 4);
                        uVar21 = (uint)*puVar2;
                        uVar11 = (uint)(byte)puVar2[1];
                        iVar23 = (byte)(&DAT_00dca2e0)[*(byte *)((&DAT_00f408d8)[iVar25] + iVar8)] *
                                 uVar11;
                        uVar15 = (*(short *)(local_18 +
                                            ((uVar21 & 0xf800) *
                                             (uint)(byte)(&DAT_00dca2e0)
                                                         [*(byte *)((&DAT_00f408d8)[iVar25] + iVar8)
                                                         ] * uVar11 >> 0x1b)) * 0x40 +
                                 *(short *)(local_18 + ((uVar21 & 0x7e0) * iVar23 >> 0x15))) * 0x20
                                 + *(short *)(local_18 + ((uVar21 & 0x1f) * iVar23 >> 0x10));
                        uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                        uVar11 = uVar21 & 0x8210820;
                        *(ushort *)puVar24 =
                             (short)uVar11 - (short)(uVar11 >> 5) |
                             ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                      pbVar19 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                      bVar13 = (byte)puVar2[1];
                      if (bVar13 != 0) {
                        if (bVar13 == 0xff) {
                          uVar21 = (uint)(byte)(&DAT_00dca2e0)[*pbVar19];
                          uVar11 = (uint)*puVar2;
                          sVar16 = *(short *)(local_18 + ((uVar11 & 0xf800) * uVar21 >> 0x13)) *
                                   0x40 + *(short *)(local_18 + ((uVar11 & 0x7e0) * uVar21 >> 0xd));
                          uVar21 = (uVar11 & 0x1f) * uVar21 >> 8;
                        }
                        else {
                          uVar21 = (uint)*puVar2;
                          iVar8 = (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * (uint)bVar13;
                          sVar16 = *(short *)(local_18 +
                                             ((uVar21 & 0xf800) *
                                              (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * (uint)bVar13
                                             >> 0x1b)) * 0x40 +
                                   *(short *)(local_18 + ((uVar21 & 0x7e0) * iVar8 >> 0x15));
                          uVar21 = (uVar21 & 0x1f) * iVar8 >> 0x10;
                        }
                        uVar15 = sVar16 * 0x20 + *(short *)(local_18 + uVar21);
                        uVar21 = ((ushort)*puVar24 & 0xf7def7df) + (uVar15 & 0xf7def7df);
                        uVar11 = uVar21 & 0x8210820;
                        *(ushort *)puVar24 =
                             (short)uVar11 - (short)(uVar11 >> 5) |
                             ((ushort)*puVar24 | uVar15) & 0x820 | (ushort)uVar21;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              break;
            case 3:
              if (iVar8 != 0) {
                if (param_11 == 0) {
                  if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                    if (*(int *)(iVar23 + 0x2c) != 1) {
                      if (param_8 == 0) {
                        do {
                          do {
                            if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                              uVar15 = *(ushort *)
                                        ((&DAT_00f448d8)
                                         [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU))
                                          >> 0x12] +
                                        ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                        0x12) * 2);
                              uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                       ((ushort)((*(short *)(local_18 + local_50[uVar15 >> 0xb]) *
                                                  0x40 + *(short *)(local_18 +
                                                                   local_48[uVar15 >> 5 & 0x3f])) *
                                                 0x20 + *(short *)(local_18 +
                                                                  local_4c[uVar15 & 0x1f])) &
                                       0xf7def7df);
                              uVar21 = uVar11 & 0x8210820;
                              *(ushort *)puVar24 =
                                   (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                            }
                            fVar26 = (float)((int)fVar26 + local_38);
                            local_14 = (float)((int)local_14 + local_34);
                            puVar24 = (uint *)((int)puVar24 + 2);
                            local_8 = local_8 + -1;
                          } while (local_8 != 0);
                          fVar26 = (float)((int)fVar26 + local_2c);
                          local_14 = (float)((int)local_14 + local_28);
                          puVar24 = (uint *)((int)puVar24 + local_64);
                          local_10 = local_10 + -1;
                          local_8 = local_7c;
                        } while (local_10 != 0);
                        return;
                      }
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            uVar15 = *(ushort *)
                                      ((&DAT_00f448d8)
                                       [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                        0x12] + ((int)((int)fVar26 +
                                                      ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) * 2
                                      );
                            if ((float)(uint)uVar15 != local_58) {
                              uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                       ((ushort)((*(short *)(local_18 + local_50[uVar15 >> 0xb]) *
                                                  0x40 + *(short *)(local_18 +
                                                                   local_48[uVar15 >> 5 & 0x3f])) *
                                                 0x20 + *(short *)(local_18 +
                                                                  local_4c[uVar15 & 0x1f])) &
                                       0xf7def7df);
                              uVar21 = uVar11 & 0x8210820;
                              *(ushort *)puVar24 =
                                   (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                            }
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            puVar2 = (ushort *)
                                     ((&DAT_00f448d8)
                                      [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                       0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)
                                                     ) >> 0x12) * 4);
                            uVar21 = (uint)*puVar2;
                            uVar11 = (uint)(byte)puVar2[1];
                            uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                     ((ushort)((*(short *)(local_18 +
                                                          local_50[(uVar21 & 0xf800) * uVar11 >>
                                                                   0x13]) * 0x40 +
                                               *(short *)(local_18 +
                                                         local_48[(uVar21 & 0x7e0) * uVar11 >> 0xd])
                                               ) * 0x20 +
                                              *(short *)(local_18 +
                                                        local_4c[(uVar21 & 0x1f) * uVar11 >> 8])) &
                                     0xf7def7df);
                            uVar21 = uVar11 & 0x8210820;
                            *(ushort *)puVar24 =
                                 (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          puVar2 = (ushort *)
                                   ((&DAT_00f448d8)
                                    [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                     0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) * 4);
                          bVar13 = (byte)puVar2[1];
                          if (bVar13 != 0) {
                            uVar15 = *puVar2;
                            uVar21 = (uint)uVar15;
                            if (bVar13 == 0xff) {
                              uVar15 = (*(short *)(local_18 + local_50[uVar15 >> 0xb]) * 0x40 +
                                       *(short *)(local_18 + local_48[uVar15 >> 5 & 0x3f])) * 0x20 +
                                       *(short *)(local_18 + local_4c[uVar21 & 0x1f]);
                            }
                            else {
                              uVar11 = (uint)bVar13;
                              uVar15 = (*(short *)(local_18 +
                                                  local_50[(uVar21 & 0xf800) * uVar11 >> 0x13]) *
                                        0x40 + *(short *)(local_18 +
                                                         local_48[(uVar21 & 0x7e0) * uVar11 >> 0xd])
                                       ) * 0x20 +
                                       *(short *)(local_18 + local_4c[(uVar21 & 0x1f) * uVar11 >> 8]
                                                 );
                            }
                            uVar11 = ((ushort)*puVar24 | 0x8210820) - (uVar15 & 0xf7def7df);
                            uVar21 = uVar11 & 0x8210820;
                            *(ushort *)puVar24 =
                                 (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                          }
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            uVar15 = *(ushort *)
                                      ((&DAT_00f448d8)
                                       [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                        0x12] + ((int)((int)fVar26 +
                                                      ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) * 2
                                      );
                            uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                     ((ushort)((*(short *)(local_18 + (uVar15 >> 0xb)) * 0x40 +
                                               *(short *)(local_18 + (uVar15 >> 5 & 0x3f))) * 0x20 +
                                              *(short *)(local_18 + (uVar15 & 0x1f))) & 0xf7def7df);
                            uVar21 = uVar11 & 0x8210820;
                            *(ushort *)puVar24 =
                                 (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          uVar15 = *(ushort *)
                                    ((&DAT_00f448d8)
                                     [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                      0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                              >> 0x12) * 2);
                          if ((float)(uint)uVar15 != local_58) {
                            uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                     ((ushort)((*(short *)(local_18 + (uVar15 >> 0xb)) * 0x40 +
                                               *(short *)(local_18 + (uVar15 >> 5 & 0x3f))) * 0x20 +
                                              *(short *)(local_18 + (uVar15 & 0x1f))) & 0xf7def7df);
                            uVar21 = uVar11 & 0x8210820;
                            *(ushort *)puVar24 =
                                 (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                          }
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          puVar2 = (ushort *)
                                   ((&DAT_00f448d8)
                                    [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                     0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) * 4);
                          uVar21 = (uint)*puVar2;
                          uVar11 = (uint)(byte)puVar2[1];
                          uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                   ((ushort)((*(short *)(local_18 +
                                                        ((uVar21 & 0xf800) * uVar11 >> 0x13)) * 0x40
                                             + *(short *)(local_18 +
                                                         ((uVar21 & 0x7e0) * uVar11 >> 0xd))) * 0x20
                                            + *(short *)(local_18 + ((uVar21 & 0x1f) * uVar11 >> 8))
                                            ) & 0xf7def7df);
                          uVar21 = uVar11 & 0x8210820;
                          *(ushort *)puVar24 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11
                          ;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        puVar2 = (ushort *)
                                 ((&DAT_00f448d8)
                                  [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                  ] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12
                                      ) * 4);
                        bVar13 = (byte)puVar2[1];
                        if (bVar13 != 0) {
                          uVar15 = *puVar2;
                          uVar21 = (uint)uVar15;
                          if (bVar13 == 0xff) {
                            uVar15 = (*(short *)(local_18 + (uVar15 >> 0xb)) * 0x40 +
                                     *(short *)(local_18 + (uVar15 >> 5 & 0x3f))) * 0x20 +
                                     *(short *)(local_18 + (uVar21 & 0x1f));
                          }
                          else {
                            uVar11 = (uint)bVar13;
                            uVar15 = (*(short *)(local_18 + ((uVar21 & 0xf800) * uVar11 >> 0x13)) *
                                      0x40 + *(short *)(local_18 +
                                                       ((uVar21 & 0x7e0) * uVar11 >> 0xd))) * 0x20 +
                                     *(short *)(local_18 + ((uVar21 & 0x1f) * uVar11 >> 8));
                          }
                          uVar11 = ((ushort)*puVar24 | 0x8210820) - (uVar15 & 0xf7def7df);
                          uVar21 = uVar11 & 0x8210820;
                          *(ushort *)puVar24 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11
                          ;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                     0x12;
                            iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                            uVar15 = *(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 2);
                            uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                                 [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                            uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                     ((ushort)((*(short *)(local_18 +
                                                          (local_50[uVar15 >> 0xb] * uVar21 >> 8)) *
                                                0x40 + *(short *)(local_18 +
                                                                 (local_48[uVar15 >> 5 & 0x3f] *
                                                                  uVar21 >> 8))) * 0x20 +
                                              *(short *)(local_18 +
                                                        (local_4c[uVar15 & 0x1f] * uVar21 >> 8))) &
                                     0xf7def7df);
                            uVar21 = uVar11 & 0x8210820;
                            *(ushort *)puVar24 =
                                 (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar15 = *(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 2);
                          if ((float)(uint)uVar15 != local_58) {
                            uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                                 [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                            uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                     ((ushort)((*(short *)(local_18 +
                                                          (local_50[uVar15 >> 0xb] * uVar21 >> 8)) *
                                                0x40 + *(short *)(local_18 +
                                                                 (local_48[uVar15 >> 5 & 0x3f] *
                                                                  uVar21 >> 8))) * 0x20 +
                                              *(short *)(local_18 +
                                                        (local_4c[uVar15 & 0x1f] * uVar21 >> 8))) &
                                     0xf7def7df);
                            uVar21 = uVar11 & 0x8210820;
                            *(ushort *)puVar24 =
                                 (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                          }
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                          uVar15 = *puVar2;
                          uVar21 = (uint)(byte)puVar2[1];
                          uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                          uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                   ((ushort)((*(short *)(local_18 +
                                                        (local_50[uVar15 >> 0xb] * uVar11 * uVar21
                                                        >> 0x10)) * 0x40 +
                                             *(short *)(local_18 +
                                                       (local_48[uVar15 >> 5 & 0x3f] * uVar11 *
                                                        uVar21 >> 0x10))) * 0x20 +
                                            *(short *)(local_18 +
                                                      (local_4c[uVar15 & 0x1f] * uVar11 * uVar21 >>
                                                      0x10))) & 0xf7def7df);
                          uVar21 = uVar11 & 0x8210820;
                          *(ushort *)puVar24 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11
                          ;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                        bVar13 = (byte)puVar2[1];
                        if (bVar13 != 0) {
                          uVar15 = *puVar2;
                          uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                          if (bVar13 == 0xff) {
                            sVar16 = *(short *)(local_18 + (local_50[uVar15 >> 0xb] * uVar21 >> 8))
                                     * 0x40 + *(short *)(local_18 +
                                                        (local_48[uVar15 >> 5 & 0x3f] * uVar21 >> 8)
                                                        );
                            uVar21 = local_4c[uVar15 & 0x1f] * uVar21 >> 8;
                          }
                          else {
                            uVar11 = (uint)bVar13;
                            sVar16 = *(short *)(local_18 +
                                               (local_50[uVar15 >> 0xb] * uVar21 * uVar11 >> 0x10))
                                     * 0x40 + *(short *)(local_18 +
                                                        (local_48[uVar15 >> 5 & 0x3f] * uVar21 *
                                                         uVar11 >> 0x10));
                            uVar21 = local_4c[uVar15 & 0x1f] * uVar21 * uVar11 >> 0x10;
                          }
                          uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                   ((ushort)(sVar16 * 0x20 + *(short *)(local_18 + uVar21)) &
                                   0xf7def7df);
                          uVar21 = uVar11 & 0x8210820;
                          *(ushort *)puVar24 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11
                          ;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar11 = (uint)*(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 2);
                          uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                          uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                   ((ushort)((*(short *)(local_18 +
                                                        ((uVar11 & 0xf800) * uVar21 >> 0x13)) * 0x40
                                             + *(short *)(local_18 +
                                                         ((uVar11 & 0x7e0) * uVar21 >> 0xd))) * 0x20
                                            + *(short *)(local_18 + ((uVar11 & 0x1f) * uVar21 >> 8))
                                            ) & 0xf7def7df);
                          uVar21 = uVar11 & 0x8210820;
                          *(ushort *)puVar24 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11
                          ;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar21 = (uint)*(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 2);
                        if ((float)uVar21 != local_58) {
                          uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                          uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                   ((ushort)((*(short *)(local_18 +
                                                        ((uVar21 & 0xf800) * uVar11 >> 0x13)) * 0x40
                                             + *(short *)(local_18 +
                                                         ((uVar21 & 0x7e0) * uVar11 >> 0xd))) * 0x20
                                            + *(short *)(local_18 + ((uVar21 & 0x1f) * uVar11 >> 8))
                                            ) & 0xf7def7df);
                          uVar21 = uVar11 & 0x8210820;
                          *(ushort *)puVar24 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11
                          ;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar25 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        puVar2 = (ushort *)((&DAT_00f448d8)[iVar25] + iVar8 * 4);
                        uVar21 = (uint)*puVar2;
                        uVar11 = (uint)(byte)puVar2[1];
                        iVar23 = (byte)(&DAT_00dca2e0)[*(byte *)((&DAT_00f408d8)[iVar25] + iVar8)] *
                                 uVar11;
                        uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                 ((ushort)((*(short *)(local_18 +
                                                      ((uVar21 & 0xf800) *
                                                       (uint)(byte)(&DAT_00dca2e0)
                                                                   [*(byte *)((&DAT_00f408d8)
                                                                              [iVar25] + iVar8)] *
                                                       uVar11 >> 0x1b)) * 0x40 +
                                           *(short *)(local_18 + ((uVar21 & 0x7e0) * iVar23 >> 0x15)
                                                     )) * 0x20 +
                                          *(short *)(local_18 + ((uVar21 & 0x1f) * iVar23 >> 0x10)))
                                 & 0xf7def7df);
                        uVar21 = uVar11 & 0x8210820;
                        *(ushort *)puVar24 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                      bVar13 = (byte)puVar2[1];
                      if (bVar13 != 0) {
                        bVar3 = *(byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                        if (bVar13 == 0xff) {
                          uVar21 = (uint)(byte)(&DAT_00dca2e0)[bVar3];
                          uVar11 = (uint)*puVar2;
                          sVar16 = *(short *)(local_18 + ((uVar11 & 0xf800) * uVar21 >> 0x13)) *
                                   0x40 + *(short *)(local_18 + ((uVar11 & 0x7e0) * uVar21 >> 0xd));
                          uVar21 = (uVar11 & 0x1f) * uVar21 >> 8;
                        }
                        else {
                          uVar21 = (uint)*puVar2;
                          iVar8 = (uint)(byte)(&DAT_00dca2e0)[bVar3] * (uint)bVar13;
                          sVar16 = *(short *)(local_18 +
                                             ((uVar21 & 0xf800) * (uint)(byte)(&DAT_00dca2e0)[bVar3]
                                              * (uint)bVar13 >> 0x1b)) * 0x40 +
                                   *(short *)(local_18 + ((uVar21 & 0x7e0) * iVar8 >> 0x15));
                          uVar21 = (uVar21 & 0x1f) * iVar8 >> 0x10;
                        }
                        uVar11 = ((ushort)*puVar24 | 0x8210820) -
                                 ((ushort)(sVar16 * 0x20 + *(short *)(local_18 + uVar21)) &
                                 0xf7def7df);
                        uVar21 = uVar11 & 0x8210820;
                        *(ushort *)puVar24 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar11;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              break;
            case 4:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                            uVar15 = *(ushort *)
                                      ((&DAT_00f448d8)
                                       [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                        0x12] + ((int)((int)fVar26 +
                                                      ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) * 2
                                      );
                            uVar7 = (ushort)*puVar24;
                            *(ushort *)puVar24 =
                                 (ushort)((uVar7 >> 5 & 0x3f) * local_48[uVar15 >> 5 & 0x3f] >> 1) &
                                 0x7e0 | (uVar7 >> 5 & 0x7c0) *
                                         *(short *)(local_50 + (uVar15 >> 0xb)) & 0xf800 |
                                 (ushort)((uVar7 & 0x1f) * local_4c[uVar15 & 0x1f] >> 5);
                          }
                          local_40 = (float)((int)local_40 + local_34);
                          fVar26 = (float)((int)fVar26 + local_38);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        local_40 = (float)((int)local_40 + local_28);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          uVar15 = *(ushort *)
                                    ((&DAT_00f448d8)
                                     [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                      0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                              >> 0x12) * 2);
                          if ((float)(uint)uVar15 != local_58) {
                            uVar7 = (ushort)*puVar24;
                            *(ushort *)puVar24 =
                                 (ushort)((uVar7 >> 5 & 0x3f) * local_48[uVar15 >> 5 & 0x3f] >> 1) &
                                 0x7e0 | (uVar7 >> 5 & 0x7c0) *
                                         *(short *)(local_50 + (uVar15 >> 0xb)) & 0xf800 |
                                 (ushort)((uVar7 & 0x1f) * local_4c[uVar15 & 0x1f] >> 5);
                          }
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          uVar15 = (ushort)*puVar24;
                          puVar2 = (ushort *)
                                   ((&DAT_00f448d8)
                                    [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                     0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) * 4);
                          uVar7 = *puVar2;
                          uVar21 = (uint)(byte)puVar2[1];
                          *(ushort *)puVar24 =
                               (ushort)((uVar15 >> 5 & 0x3f) * local_48[uVar7 >> 5 & 0x3f] * uVar21
                                       >> 9) & 0x7e0 |
                               (ushort)((uint)(uVar15 >> 0xb) * local_50[uVar7 >> 0xb] * uVar21 >> 2
                                       ) & 0xf800 |
                               (ushort)((uVar15 & 0x1f) * local_4c[uVar7 & 0x1f] * uVar21 >> 0xd);
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        puVar2 = (ushort *)
                                 ((&DAT_00f448d8)
                                  [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12
                                  ] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12
                                      ) * 4);
                        bVar13 = (byte)puVar2[1];
                        uVar15 = *puVar2;
                        if (bVar13 == 0xff) {
                          uVar7 = (ushort)*puVar24;
                          *(ushort *)puVar24 =
                               (ushort)((uVar7 >> 5 & 0x3f) * local_48[uVar15 >> 5 & 0x3f] >> 1) &
                               0x7e0 | (uVar7 >> 5 & 0x7c0) * *(short *)(local_50 + (uVar15 >> 0xb))
                                       & 0xf800 |
                               (ushort)((uVar7 & 0x1f) * local_4c[uVar15 & 0x1f] >> 5);
                        }
                        else {
                          uVar7 = (ushort)*puVar24;
                          uVar21 = (uint)bVar13;
                          *(ushort *)puVar24 =
                               (ushort)((uVar7 >> 5 & 0x3f) * local_48[uVar15 >> 5 & 0x3f] * uVar21
                                       >> 9) & 0x7e0 |
                               (ushort)((uint)(uVar7 >> 0xb) * local_50[uVar15 >> 0xb] * uVar21 >> 2
                                       ) & 0xf800 |
                               (ushort)((uVar7 & 0x1f) * local_4c[uVar15 & 0x1f] * uVar21 >> 0xd);
                        }
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          uVar21 = (uint)*(ushort *)
                                          ((&DAT_00f448d8)
                                           [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)
                                                 ) >> 0x12] +
                                          ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                          0x12) * 2);
                          uVar11 = (uint)(ushort)*puVar24;
                          *(ushort *)puVar24 =
                               (ushort)((uVar11 & 0x7e0) * (uVar21 & 0x7e0) >> 0xb) & 0x7e0 |
                               (ushort)((uVar11 & 0xf800) * (uVar21 & 0xf800) >> 0x10) & 0xf800 |
                               (ushort)((uVar11 & 0x1f) * (uVar21 & 0x1f) >> 5);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                         (uVar21 = (uint)*(ushort *)
                                          ((&DAT_00f448d8)
                                           [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)
                                                 ) >> 0x12] +
                                          ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                          0x12) * 2), (float)uVar21 != local_58)) {
                        uVar11 = (uint)(ushort)*puVar24;
                        *(ushort *)puVar24 =
                             (ushort)((uVar11 & 0x7e0) * (uVar21 & 0x7e0) >> 0xb) & 0x7e0 |
                             (ushort)((uVar11 & 0xf800) * (uVar21 & 0xf800) >> 0x10) & 0xf800 |
                             (ushort)((uVar11 & 0x1f) * (uVar21 & 0x1f) >> 5);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar15 = *(ushort *)
                                  ((&DAT_00f448d8)
                                   [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                    0x12] + iVar8 * 4);
                        uVar21 = (uint)*(byte *)((&DAT_00f448d8)
                                                 [(int)((int)local_14 +
                                                       ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]
                                                 + iVar8 * 4 + 2);
                        uVar7 = (ushort)*puVar24;
                        *(ushort *)puVar24 =
                             (ushort)((int)((uVar7 >> 5 & 0x3f) * (uVar15 >> 5 & 0x3f) * uVar21) >>
                                     9) & 0x7e0 |
                             (ushort)((int)((uint)(uVar7 >> 0xb) * (uint)(uVar15 >> 0xb) * uVar21)
                                     >> 2) & 0xf800 |
                             (ushort)((int)((uVar7 & 0x1f) * (uVar15 & 0x1f) * uVar21) >> 0xd);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      bVar13 = *(byte *)((&DAT_00f448d8)
                                         [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU))
                                          >> 0x12] + 2 + iVar8 * 4);
                      puVar2 = (ushort *)
                               ((&DAT_00f448d8)
                                [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]
                               + iVar8 * 4);
                      if (bVar13 == 0xff) {
                        uVar21 = (uint)*puVar2;
                        uVar11 = (uint)(ushort)*puVar24;
                        uVar27 = (ushort)((uVar11 & 0x7e0) * (uVar21 & 0x7e0) >> 0xb) & 0x7e0 |
                                 (ushort)((uVar11 & 0xf800) * (uVar21 & 0xf800) >> 0x10) & 0xf800;
                        uVar15 = (ushort)((uVar11 & 0x1f) * (uVar21 & 0x1f) >> 5);
                      }
                      else {
                        uVar15 = *puVar2;
                        uVar7 = (ushort)*puVar24;
                        uVar21 = (uint)bVar13;
                        uVar27 = (ushort)((int)((uVar7 >> 5 & 0x3f) * (uVar15 >> 5 & 0x3f) * uVar21)
                                         >> 9) & 0x7e0 |
                                 (ushort)((int)((uint)(uVar7 >> 0xb) * (uint)(uVar15 >> 0xb) *
                                               uVar21) >> 2) & 0xf800;
                        uVar15 = (ushort)((int)((uVar7 & 0x1f) * (uVar15 & 0x1f) * uVar21) >> 0xd);
                      }
                      *(ushort *)puVar24 = uVar27 | uVar15;
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar15 = *(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 2);
                          uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                          uVar7 = (ushort)*puVar24;
                          *(ushort *)puVar24 =
                               (ushort)((uVar7 >> 5 & 0x3f) * local_48[uVar15 >> 5 & 0x3f] * uVar21
                                       >> 9) & 0x7e0 |
                               (ushort)((uint)(uVar7 >> 0xb) * local_50[uVar15 >> 0xb] * uVar21 >> 2
                                       ) & 0xf800 |
                               (ushort)((uVar7 & 0x1f) * local_4c[uVar15 & 0x1f] * uVar21 >> 0xd);
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar15 = *(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 2);
                        if ((float)(uint)uVar15 != local_58) {
                          uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                          uVar7 = (ushort)*puVar24;
                          *(ushort *)puVar24 =
                               (ushort)((uVar7 >> 5 & 0x3f) * local_48[uVar15 >> 5 & 0x3f] * uVar21
                                       >> 9) & 0x7e0 |
                               (ushort)((uint)(uVar7 >> 0xb) * local_50[uVar15 >> 0xb] * uVar21 >> 2
                                       ) & 0xf800 |
                               (ushort)((uVar7 & 0x1f) * local_4c[uVar15 & 0x1f] * uVar21 >> 0xd);
                        }
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                        puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                        uVar15 = *puVar2;
                        uVar21 = (uint)(byte)puVar2[1];
                        uVar7 = (ushort)*puVar24;
                        *(ushort *)puVar24 =
                             (ushort)((uVar7 >> 5 & 0x3f) * local_48[uVar15 >> 5 & 0x3f] * uVar11 *
                                      uVar21 >> 0x11) & 0x7e0 |
                             (ushort)((uint)(uVar7 >> 0xb) * local_50[uVar15 >> 0xb] * uVar11 *
                                      uVar21 >> 10) & 0xf800 |
                             (ushort)((uVar7 & 0x1f) * local_4c[uVar15 & 0x1f] * uVar11 * uVar21 >>
                                     0x15);
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                      iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                      uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                      bVar13 = (byte)puVar2[1];
                      uVar15 = *puVar2;
                      uVar7 = (ushort)*puVar24;
                      uVar11 = uVar7 >> 5 & 0x3f;
                      if (bVar13 == 0xff) {
                        uVar27 = (ushort)(uVar11 * local_48[uVar15 >> 5 & 0x3f] * uVar21 >> 9) &
                                 0x7e0 | (ushort)((uint)(uVar7 >> 0xb) * local_50[uVar15 >> 0xb] *
                                                  uVar21 >> 2) & 0xf800;
                        uVar15 = (ushort)((uVar7 & 0x1f) * local_4c[uVar15 & 0x1f] * uVar21 >> 0xd);
                      }
                      else {
                        uVar10 = (uint)bVar13;
                        uVar27 = (ushort)(uVar11 * local_48[uVar15 >> 5 & 0x3f] * uVar21 * uVar10 >>
                                         0x11) & 0x7e0 |
                                 (ushort)((uint)(uVar7 >> 0xb) * local_50[uVar15 >> 0xb] * uVar21 *
                                          uVar10 >> 10) & 0xf800;
                        uVar15 = (ushort)((uVar7 & 0x1f) * local_4c[uVar15 & 0x1f] * uVar21 * uVar10
                                         >> 0x15);
                      }
                      *(ushort *)puVar24 = uVar27 | uVar15;
                    }
                    local_40 = (float)((int)local_40 + local_34);
                    fVar26 = (float)((int)fVar26 + local_38);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  local_40 = (float)((int)local_40 + local_28);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (*(int *)(iVar23 + 0x2c) != 1) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                        uVar15 = *(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 2);
                        uVar7 = (ushort)*puVar24;
                        *(ushort *)puVar24 =
                             (ushort)((int)((uVar7 >> 5 & 0x3f) * (uVar15 >> 5 & 0x3f) * uVar21) >>
                                     9) & 0x7e0 |
                             (ushort)((int)((uint)(uVar7 >> 0xb) * (uint)(uVar15 >> 0xb) * uVar21)
                                     >> 2) & 0xf800 |
                             (ushort)((int)((uVar7 & 0x1f) * (uVar15 & 0x1f) * uVar21) >> 0xd);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar15 = *(ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 2);
                      if ((float)(uint)uVar15 != local_58) {
                        uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                        uVar7 = (ushort)*puVar24;
                        *(ushort *)puVar24 =
                             (ushort)((int)((uVar7 >> 5 & 0x3f) * (uVar15 >> 5 & 0x3f) * uVar21) >>
                                     9) & 0x7e0 |
                             (ushort)((int)((uint)(uVar7 >> 0xb) * (uint)(uVar15 >> 0xb) * uVar21)
                                     >> 2) & 0xf800 |
                             (ushort)((int)((uVar7 & 0x1f) * (uVar15 & 0x1f) * uVar21) >> 0xd);
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 == 0) {
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                      uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)];
                      uVar15 = *puVar2;
                      uVar11 = (uint)(byte)puVar2[1];
                      uVar7 = (ushort)*puVar24;
                      *(ushort *)puVar24 =
                           (ushort)((int)((uVar7 >> 5 & 0x3f) * (uVar15 >> 5 & 0x3f) * uVar21 *
                                         uVar11) >> 0x11) & 0x7e0 |
                           (ushort)((int)((uint)(uVar7 >> 0xb) * (uint)(uVar15 >> 0xb) * uVar21 *
                                         uVar11) >> 10) & 0xf800 |
                           (ushort)((int)((uVar7 & 0x1f) * (uVar15 & 0x1f) * uVar21 * uVar11) >>
                                   0x15);
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                    iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                    bVar13 = (byte)puVar2[1];
                    uVar15 = *puVar2;
                    uVar21 = (uint)bVar13;
                    uVar10 = uVar15 >> 5 & 0x3f;
                    uVar11 = (uint)(byte)(&DAT_00dca2e0)[*(byte *)((&DAT_00f408d8)[iVar23] + iVar8)]
                    ;
                    uVar7 = (ushort)*puVar24;
                    if (bVar13 == 0xff) {
                      uVar27 = (ushort)((int)((uVar7 >> 5 & 0x3f) * uVar10 * uVar11) >> 9) & 0x7e0 |
                               (ushort)((int)((uint)(uVar7 >> 0xb) * (uint)(uVar15 >> 0xb) * uVar11)
                                       >> 2) & 0xf800;
                      uVar15 = (ushort)((int)((uVar7 & 0x1f) * (uVar15 & 0x1f) * uVar11) >> 0xd);
                    }
                    else {
                      uVar27 = (ushort)((int)((uVar7 >> 5 & 0x3f) * uVar10 * uVar11 * uVar21) >>
                                       0x11) & 0x7e0 |
                               (ushort)((int)((uint)(uVar7 >> 0xb) * (uint)(uVar15 >> 0xb) * uVar11
                                             * uVar21) >> 10) & 0xf800;
                      uVar15 = (ushort)((int)((uVar7 & 0x1f) * (uVar15 & 0x1f) * uVar11 * uVar21) >>
                                       0x15);
                    }
                    *(ushort *)puVar24 = uVar27 | uVar15;
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  local_14 = (float)((int)local_14 + local_34);
                  puVar24 = (uint *)((int)puVar24 + 2);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                local_14 = (float)((int)local_14 + local_28);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            case 10:
              if (param_11 != 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                            iVar25 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                     0x12;
                            iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                            uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                                 [*(byte *)((&DAT_00f408d8)[iVar25] + iVar23)];
                            uVar15 = (ushort)*puVar24;
                            uVar21 = (uint)uVar15;
                            uVar7 = ~*(ushort *)((&DAT_00f448d8)[iVar25] + iVar23 * 2);
                            *(ushort *)puVar24 =
                                 (ushort)((local_48[uVar7 >> 5 & 0x3f] - (uVar15 >> 5 & 0x3f)) *
                                          uVar11 * iVar8 + (uVar21 & 0xffffffe0) * 0x800 >> 0xb) &
                                 0x7e0 | (ushort)((local_50[uVar7 >> 0xb] - (uint)(uVar15 >> 0xb)) *
                                                  uVar11 * DAT_00dca3f8 +
                                                  (uVar21 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                 (ushort)((local_4c[uVar7 & 0x1f] - (uVar21 & 0x1f)) * uVar11 *
                                          DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10) & 0x1f;
                            iVar8 = DAT_00dca3f8;
                          }
                          local_40 = (float)((int)local_40 + local_34);
                          fVar26 = (float)((int)fVar26 + local_38);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        local_40 = (float)((int)local_40 + local_28);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar21 = (uint)*(ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 2);
                          if ((float)uVar21 != local_58) {
                            uVar18 = (uint)(byte)(&DAT_00dca2e0)
                                                 [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                            uVar15 = (ushort)*puVar24;
                            uVar10 = (uint)uVar15;
                            uVar21 = ~uVar21;
                            uVar11 = uVar21 & 0xffff;
                            *(ushort *)puVar24 =
                                 (ushort)((local_48[uVar11 >> 5 & 0x3f] - (uVar15 >> 5 & 0x3f)) *
                                          uVar18 * iVar8 + (uVar10 & 0xffffffe0) * 0x800 >> 0xb) &
                                 0x7e0 | (ushort)((local_50[uVar11 >> 0xb] - (uint)(uVar15 >> 0xb))
                                                  * uVar18 * DAT_00dca3f8 +
                                                  (uVar10 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                 (ushort)((local_4c[uVar21 & 0x1f] - (uVar10 & 0x1f)) * uVar18 *
                                          DAT_00dca3f8 + uVar10 * 0x10000 >> 0x10) & 0x1f;
                            iVar8 = DAT_00dca3f8;
                          }
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          iVar25 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar25] + iVar23)];
                          puVar2 = (ushort *)((&DAT_00f448d8)[iVar25] + iVar23 * 4);
                          uVar11 = (uint)(byte)puVar2[1];
                          uVar7 = ~*puVar2;
                          uVar15 = (ushort)*puVar24;
                          uVar21 = (uint)uVar15;
                          *(ushort *)puVar24 =
                               (ushort)((local_48[uVar7 >> 5 & 0x3f] - (uVar15 >> 5 & 0x3f)) *
                                        uVar10 * uVar11 * iVar8 + (uVar21 & 0xffffffe0) * 0x80000 >>
                                       0x13) & 0x7e0 |
                               (ushort)((local_50[uVar7 >> 0xb] - (uint)(uVar15 >> 0xb)) * uVar10 *
                                        uVar11 * DAT_00dca3f8 + (uVar21 & 0xfffff800) * 0x2000 >>
                                       0xd) & 0xf800 |
                               (byte)((local_4c[uVar7 & 0x1f] - (uVar21 & 0x1f)) * uVar10 * uVar11 *
                                      DAT_00dca3f8 + uVar21 * 0x1000000 >> 0x18) & 0x1f;
                          iVar8 = DAT_00dca3f8;
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        iVar23 = (int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        bVar13 = (byte)puVar2[1];
                        if (bVar13 != 0) {
                          uVar21 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          if (bVar13 == 0xff) {
                            uVar15 = (ushort)*puVar24;
                            uVar11 = (uint)uVar15;
                            uVar7 = ~*puVar2;
                            uVar27 = (ushort)((local_48[uVar7 >> 5 & 0x3f] - (uVar15 >> 5 & 0x3f)) *
                                              uVar21 * iVar8 + (uVar11 & 0xffffffe0) * 0x800 >> 0xb)
                                     & 0x7e0 | (ushort)((local_50[uVar7 >> 0xb] -
                                                        (uint)(uVar15 >> 0xb)) * uVar21 *
                                                        DAT_00dca3f8 + (uVar11 & 0xfffff800) * 0x20
                                                       >> 5) & 0xf800;
                            uVar15 = (ushort)((local_4c[uVar7 & 0x1f] - (uVar11 & 0x1f)) * uVar21 *
                                              DAT_00dca3f8 + uVar11 * 0x10000 >> 0x10);
                          }
                          else {
                            uVar7 = ~*puVar2;
                            uVar11 = (uint)bVar13;
                            uVar15 = (ushort)*puVar24;
                            uVar10 = (uint)uVar15;
                            uVar27 = (ushort)((local_48[uVar7 >> 5 & 0x3f] - (uVar15 >> 5 & 0x3f)) *
                                              uVar21 * uVar11 * iVar8 +
                                              (uVar10 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                                     (ushort)((local_50[uVar7 >> 0xb] - (uint)(uVar15 >> 0xb)) *
                                              uVar21 * uVar11 * DAT_00dca3f8 +
                                              (uVar10 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800;
                            uVar15 = (ushort)(byte)((local_4c[uVar7 & 0x1f] - (uVar10 & 0x1f)) *
                                                    uVar21 * uVar11 * DAT_00dca3f8 +
                                                    uVar10 * 0x1000000 >> 0x18);
                          }
                          *(ushort *)puVar24 = uVar27 | uVar15 & 0x1f;
                          iVar8 = DAT_00dca3f8;
                        }
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          uVar21 = (uint)(ushort)~*(ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 2);
                          uVar11 = (uint)(ushort)*puVar24;
                          *(ushort *)puVar24 =
                               (ushort)(((uVar21 & 0xf800) - (uVar11 & 0xf800)) * uVar10 * iVar8 +
                                        (uVar11 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                               (ushort)(((uVar21 & 0x7e0) - (uVar11 & 0x7e0)) * uVar10 *
                                        DAT_00dca3f8 + (uVar11 & 0xffffffe0) * 0x10000 >> 0x10) &
                               0x7e0 | (ushort)(((uVar21 & 0x1f) - (uVar11 & 0x1f)) * uVar10 *
                                                DAT_00dca3f8 + (uVar11 & 0x1f) * 0x10000 >> 0x10);
                          iVar8 = DAT_00dca3f8;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar21 = (uint)*(ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 2);
                        if ((float)uVar21 != local_58) {
                          uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          uVar21 = ~uVar21;
                          uVar11 = (uint)(ushort)*puVar24;
                          *(ushort *)puVar24 =
                               (ushort)(((uVar21 & 0xf800) - (uVar11 & 0xf800)) * uVar10 * iVar8 +
                                        (uVar11 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                               (ushort)(((uVar21 & 0x7e0) - (uVar11 & 0x7e0)) * uVar10 *
                                        DAT_00dca3f8 + (uVar11 & 0xffffffe0) * 0x10000 >> 0x10) &
                               0x7e0 | (ushort)(((uVar21 & 0x1f) - (uVar11 & 0x1f)) * uVar10 *
                                                DAT_00dca3f8 + (uVar11 & 0x1f) * 0x10000 >> 0x10);
                          iVar8 = DAT_00dca3f8;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        uVar10 = (uint)(byte)puVar2[1];
                        uVar7 = ~*puVar2;
                        uVar15 = (ushort)*puVar24;
                        uVar21 = (uint)uVar15;
                        *(ushort *)puVar24 =
                             (ushort)(((uVar7 >> 5 & 0x3f) - (uVar15 >> 5 & 0x3f)) * uVar11 * uVar10
                                      * iVar8 + (uVar21 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                             (ushort)(((uint)(uVar7 >> 0xb) - (uint)(uVar15 >> 0xb)) * uVar11 *
                                      uVar10 * DAT_00dca3f8 + (uVar21 & 0xfffff800) * 0x2000 >> 0xd)
                             & 0xf800 |
                             (ushort)(byte)(((uVar7 & 0x1f) - (uVar21 & 0x1f)) * uVar11 * uVar10 *
                                            DAT_00dca3f8 + (uVar21 & 0x1f) * 0x1000000 >> 0x18);
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)(((int)fVar26 >> 0x1f & 0x3ffffU) + (int)fVar26) >> 0x12;
                      puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                      bVar13 = (byte)puVar2[1];
                      uVar21 = (uint)bVar13;
                      if (bVar13 != 0) {
                        uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        uVar7 = ~*puVar2;
                        uVar10 = (uint)uVar7;
                        uVar15 = (ushort)*puVar24;
                        uVar18 = (uint)uVar15;
                        if (bVar13 == 0xff) {
                          uVar7 = (ushort)(((uVar10 & 0xf800) - (uVar18 & 0xf800)) * uVar11 * iVar8
                                           + (uVar18 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                                  (ushort)(((uVar10 & 0x7e0) - (uVar18 & 0x7e0)) * uVar11 *
                                           DAT_00dca3f8 + (uVar18 & 0xffffffe0) * 0x10000 >> 0x10) &
                                  0x7e0;
                          uVar15 = (ushort)(((uVar10 & 0x1f) - (uVar18 & 0x1f)) * uVar11 *
                                            DAT_00dca3f8 + (uVar18 & 0x1f) * 0x10000 >> 0x10);
                        }
                        else {
                          uVar7 = (ushort)(((uVar7 >> 5 & 0x3f) - (uVar15 >> 5 & 0x3f)) * uVar11 *
                                           uVar21 * iVar8 + (uVar18 & 0xffffffe0) * 0x80000 >> 0x13)
                                  & 0x7e0 | (ushort)(((uint)(uVar7 >> 0xb) - (uint)(uVar15 >> 0xb))
                                                     * uVar11 * uVar21 * DAT_00dca3f8 +
                                                     (uVar18 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800
                          ;
                          uVar15 = (ushort)(byte)(((uVar10 & 0x1f) - (uVar18 & 0x1f)) * uVar11 *
                                                  uVar21 * DAT_00dca3f8 +
                                                  (uVar18 & 0x1f) * 0x1000000 >> 0x18);
                        }
                        *(ushort *)puVar24 = uVar7 | uVar15;
                        iVar8 = DAT_00dca3f8;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) == 0xffffff) {
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          uVar7 = ~*(ushort *)
                                    ((&DAT_00f448d8)
                                     [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                      0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                              >> 0x12) * 2);
                          uVar15 = (ushort)*puVar24;
                          *(ushort *)puVar24 =
                               ((uVar15 >> 5 & 0x3f) +
                               *(short *)(local_c + ((uVar7 >> 5 & 0x3f) - (uVar15 >> 5 & 0x3f)) * 4
                                         )) * 0x20 |
                               ((uVar15 >> 0xb) +
                               *(short *)(local_c +
                                         ((uint)(uVar7 >> 0xb) - (uint)(uVar15 >> 0xb)) * 4)) *
                               0x800 | (uVar15 & 0x1f) +
                                       *(short *)(local_c + ((uVar7 & 0x1f) - (uVar15 & 0x1f)) * 4);
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if ((((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) &&
                         (uVar15 = *(ushort *)
                                    ((&DAT_00f448d8)
                                     [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                      0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                              >> 0x12) * 2), (float)(uint)uVar15 != local_58)) {
                        uVar15 = ~uVar15;
                        uVar7 = (ushort)*puVar24;
                        *(ushort *)puVar24 =
                             ((uVar7 >> 5 & 0x3f) +
                             *(short *)(local_c + ((uVar15 >> 5 & 0x3f) - (uVar7 >> 5 & 0x3f)) * 4))
                             * 0x20 | ((uVar7 >> 0xb) +
                                      *(short *)(local_c +
                                                ((uint)(uVar15 >> 0xb) - (uint)(uVar7 >> 0xb)) * 4))
                                      * 0x800 |
                             (uVar7 & 0x1f) +
                             *(short *)(local_c + ((uVar15 & 0x1f) - (uVar7 & 0x1f)) * 4);
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        puVar2 = (ushort *)
                                 ((&DAT_00f448d8)
                                  [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                  ] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12
                                      ) * 4);
                        uVar11 = (uint)(byte)puVar2[1];
                        uVar10 = (uint)(ushort)~*puVar2;
                        uVar21 = (uint)(ushort)*puVar24;
                        *(ushort *)puVar24 =
                             (ushort)(((uVar10 & 0x7e0) - (uVar21 & 0x7e0)) * uVar11 * DAT_00dca3f8
                                      + (uVar21 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                             (ushort)(((uVar10 & 0xf800) - (uVar21 & 0xf800)) * uVar11 *
                                      DAT_00dca3f8 + (uVar21 & 0xfffff800) * 0x10000 >> 0x10) &
                             0xf800 | (ushort)(((uVar10 & 0x1f) - (uVar21 & 0x1f)) * uVar11 *
                                               DAT_00dca3f8 + (uVar21 & 0x1f) * 0x10000 >> 0x10);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                      puVar2 = (ushort *)
                               ((&DAT_00f448d8)
                                [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12]
                               + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) * 4
                               );
                      bVar13 = (byte)puVar2[1];
                      if (bVar13 != 0) {
                        uVar15 = ~*puVar2;
                        if (bVar13 == 0xff) {
                          uVar7 = (ushort)*puVar24;
                          uVar15 = ((uVar7 >> 5 & 0x3f) +
                                   *(short *)(local_c +
                                             ((uVar15 >> 5 & 0x3f) - (uVar7 >> 5 & 0x3f)) * 4)) *
                                   0x20 | ((uVar7 >> 0xb) +
                                          *(short *)(local_c +
                                                    ((uint)(uVar15 >> 0xb) - (uint)(uVar7 >> 0xb)) *
                                                    4)) * 0x800 |
                                   (uVar7 & 0x1f) +
                                   *(short *)(local_c + ((uVar15 & 0x1f) - (uVar7 & 0x1f)) * 4);
                        }
                        else {
                          uVar11 = (uint)bVar13;
                          uVar10 = (uint)uVar15;
                          uVar21 = (uint)(ushort)*puVar24;
                          uVar15 = (ushort)(((uVar10 & 0x7e0) - (uVar21 & 0x7e0)) * uVar11 *
                                            DAT_00dca3f8 + (uVar21 & 0xffffffe0) * 0x10000 >> 0x10)
                                   & 0x7e0 | (ushort)(((uVar10 & 0xf800) - (uVar21 & 0xf800)) *
                                                      uVar11 * DAT_00dca3f8 +
                                                      (uVar21 & 0xfffff800) * 0x10000 >> 0x10) &
                                             0xf800 |
                                   (ushort)(((uVar10 & 0x1f) - (uVar21 & 0x1f)) * uVar11 *
                                            DAT_00dca3f8 + (uVar21 & 0x1f) * 0x10000 >> 0x10);
                        }
                        *(ushort *)puVar24 = uVar15;
                      }
                    }
                    local_40 = (float)((int)local_40 + local_34);
                    fVar26 = (float)((int)fVar26 + local_38);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  local_40 = (float)((int)local_40 + local_28);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (*(int *)(iVar23 + 0x2c) == 1) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        uVar15 = (ushort)*puVar24;
                        uVar11 = (uint)uVar15;
                        puVar2 = (ushort *)
                                 ((&DAT_00f448d8)
                                  [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12
                                  ] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12
                                      ) * 4);
                        uVar21 = (uint)(byte)puVar2[1];
                        uVar7 = ~*puVar2;
                        *(ushort *)puVar24 =
                             (ushort)((local_48[uVar7 >> 5 & 0x3f] - (uVar15 >> 5 & 0x3f)) * uVar21
                                      * iVar8 + (uVar11 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                             (ushort)((local_50[uVar7 >> 0xb] - (uint)(uVar15 >> 0xb)) * uVar21 *
                                      DAT_00dca3f8 + (uVar11 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                             (ushort)((local_4c[uVar7 & 0x1f] - (uVar11 & 0x1f)) * uVar21 *
                                      DAT_00dca3f8 + uVar11 * 0x10000 >> 0x10) & 0x1f;
                        iVar8 = DAT_00dca3f8;
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                      puVar2 = (ushort *)
                               ((&DAT_00f448d8)
                                [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12]
                               + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) * 4
                               );
                      bVar13 = (byte)puVar2[1];
                      if (bVar13 != 0) {
                        uVar15 = ~*puVar2;
                        if (bVar13 == 0xff) {
                          uVar7 = (ushort)*puVar24;
                          *(ushort *)puVar24 =
                               ((uVar7 >> 5 & 0x3f) +
                               *(short *)(local_c +
                                         (local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) * 4))
                               * 0x20 | ((uVar7 >> 0xb) +
                                        *(short *)(local_c +
                                                  (local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) *
                                                  4)) * 0x800 |
                               (uVar7 & 0x1f) +
                               *(short *)(local_c + (local_4c[uVar15 & 0x1f] - (uVar7 & 0x1f)) * 4);
                        }
                        else {
                          uVar7 = (ushort)*puVar24;
                          uVar21 = (uint)uVar7;
                          uVar11 = (uint)bVar13;
                          *(ushort *)puVar24 =
                               (ushort)((local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) *
                                        uVar11 * DAT_00dca3f8 + (uVar21 & 0xffffffe0) * 0x800 >> 0xb
                                       ) & 0x7e0 |
                               (ushort)((local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) * uVar11 *
                                        DAT_00dca3f8 + (uVar21 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                               (ushort)((local_4c[uVar15 & 0x1f] - (uVar21 & 0x1f)) * uVar11 *
                                        DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10) & 0x1f;
                        }
                      }
                    }
                    local_40 = (float)((int)local_40 + local_34);
                    fVar26 = (float)((int)fVar26 + local_38);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  local_40 = (float)((int)local_40 + local_28);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 != 0) {
                do {
                  do {
                    if ((((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) &&
                       (uVar15 = *(ushort *)
                                  ((&DAT_00f448d8)
                                   [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                    0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                            >> 0x12) * 2), (float)(uint)uVar15 != local_58)) {
                      uVar7 = (ushort)*puVar24;
                      uVar15 = ~uVar15;
                      *(ushort *)puVar24 =
                           ((uVar7 >> 5 & 0x3f) +
                           *(short *)(local_c +
                                     (local_48[uVar15 >> 5 & 0x3f] - (uVar7 >> 5 & 0x3f)) * 4)) *
                           0x20 | ((uVar7 >> 0xb) +
                                  *(short *)(local_c +
                                            (local_50[uVar15 >> 0xb] - (uint)(uVar7 >> 0xb)) * 4)) *
                                  0x800 |
                           (uVar7 & 0x1f) +
                           *(short *)(local_c + (local_4c[uVar15 & 0x1f] - (uVar7 & 0x1f)) * 4);
                    }
                    local_40 = (float)((int)local_40 + local_34);
                    fVar26 = (float)((int)fVar26 + local_38);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  local_40 = (float)((int)local_40 + local_28);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                    uVar15 = (ushort)*puVar24;
                    uVar7 = ~*(ushort *)
                              ((&DAT_00f448d8)
                               [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12] +
                              ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) * 2);
                    *(ushort *)puVar24 =
                         ((uVar15 >> 5 & 0x3f) +
                         *(short *)(local_c +
                                   (local_48[uVar7 >> 5 & 0x3f] - (uVar15 >> 5 & 0x3f)) * 4)) * 0x20
                         | ((uVar15 >> 0xb) +
                           *(short *)(local_c + (local_50[uVar7 >> 0xb] - (uint)(uVar15 >> 0xb)) * 4
                                     )) * 0x800 |
                         (uVar15 & 0x1f) +
                         *(short *)(local_c + (local_4c[uVar7 & 0x1f] - (uVar15 & 0x1f)) * 4);
                  }
                  local_40 = (float)((int)local_40 + local_34);
                  fVar26 = (float)((int)fVar26 + local_38);
                  puVar24 = (uint *)((int)puVar24 + 2);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                local_40 = (float)((int)local_40 + local_28);
                fVar26 = (float)((int)fVar26 + local_2c);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              break;
            case 0xb:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                            uVar15 = *(ushort *)
                                      ((&DAT_00f448d8)
                                       [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                        0x12] + ((int)((int)fVar26 +
                                                      ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) * 2
                                      );
                            uVar7 = (ushort)*puVar24;
                            uVar21 = uVar7 >> 5 & 0x3f;
                            *(ushort *)puVar24 =
                                 ((uVar7 >> 5 & 0x3f) +
                                 *(short *)(local_c +
                                           ((local_48[uVar15 >> 5 & 0x3f] * uVar21 >> 6) - uVar21) *
                                           4)) * 0x20 |
                                 ((uVar7 >> 0xb) +
                                 *(short *)(local_c +
                                           ((local_50[uVar15 >> 0xb] * (uint)(uVar7 >> 0xb) >> 5) -
                                           (uint)(uVar7 >> 0xb)) * 4)) * 0x800 |
                                 (uVar7 & 0x1f) +
                                 *(short *)(local_c +
                                           ((local_4c[uVar15 & 0x1f] * (uVar7 & 0x1f) >> 5) -
                                           (uVar7 & 0x1f)) * 4);
                          }
                          local_40 = (float)((int)local_40 + local_34);
                          fVar26 = (float)((int)fVar26 + local_38);
                          puVar24 = (uint *)((int)puVar24 + 2);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        local_40 = (float)((int)local_40 + local_28);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          uVar15 = *(ushort *)
                                    ((&DAT_00f448d8)
                                     [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                      0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                              >> 0x12) * 2);
                          if ((float)(uint)uVar15 != local_58) {
                            uVar7 = (ushort)*puVar24;
                            uVar21 = uVar7 >> 5 & 0x3f;
                            *(ushort *)puVar24 =
                                 ((uVar7 >> 5 & 0x3f) +
                                 *(short *)(local_c +
                                           ((local_48[uVar15 >> 5 & 0x3f] * uVar21 >> 6) - uVar21) *
                                           4)) * 0x20 |
                                 ((uVar7 >> 0xb) +
                                 *(short *)(local_c +
                                           ((local_50[uVar15 >> 0xb] * (uint)(uVar7 >> 0xb) >> 5) -
                                           (uint)(uVar7 >> 0xb)) * 4)) * 0x800 |
                                 (uVar7 & 0x1f) +
                                 *(short *)(local_c +
                                           ((local_4c[uVar15 & 0x1f] * (uVar7 & 0x1f) >> 5) -
                                           (uVar7 & 0x1f)) * 4);
                          }
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          puVar2 = (ushort *)
                                   ((&DAT_00f448d8)
                                    [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                     0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) * 4);
                          uVar15 = *puVar2;
                          uVar7 = (ushort)*puVar24;
                          uVar21 = (uint)uVar7;
                          uVar11 = uVar7 >> 5 & 0x3f;
                          uVar10 = (uint)(byte)puVar2[1];
                          *(ushort *)puVar24 =
                               (ushort)(((local_48[uVar15 >> 5 & 0x3f] * uVar11 >> 6) - uVar11) *
                                        uVar10 * DAT_00dca3f8 + (uVar21 & 0xffffffe0) * 0x800 >> 0xb
                                       ) & 0x7e0 |
                               (ushort)(((local_50[uVar15 >> 0xb] * (uint)(uVar7 >> 0xb) >> 5) -
                                        (uint)(uVar7 >> 0xb)) * uVar10 * DAT_00dca3f8 +
                                        (uVar21 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                               (ushort)(((local_4c[uVar15 & 0x1f] * (uVar21 & 0x1f) >> 5) -
                                        (uVar21 & 0x1f)) * uVar10 * DAT_00dca3f8 + uVar21 * 0x10000
                                       >> 0x10) & 0x1f;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        bVar13 = *(byte *)((&DAT_00f448d8)
                                           [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)
                                                 ) >> 0x12] + 2 + iVar8 * 4);
                        uVar15 = *(ushort *)
                                  ((&DAT_00f448d8)
                                   [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                    0x12] + iVar8 * 4);
                        uVar7 = (ushort)*puVar24;
                        uVar21 = (uint)uVar7;
                        if (bVar13 == 0xff) {
                          uVar11 = uVar7 >> 5 & 0x3f;
                          uVar15 = ((uVar7 >> 5 & 0x3f) +
                                   *(short *)(local_c +
                                             ((local_48[uVar15 >> 5 & 0x3f] * uVar11 >> 6) - uVar11)
                                             * 4)) * 0x20 |
                                   ((uVar7 >> 0xb) +
                                   *(short *)(local_c +
                                             ((local_50[uVar15 >> 0xb] * (uint)(uVar7 >> 0xb) >> 5)
                                             - (uint)(uVar7 >> 0xb)) * 4)) * 0x800 |
                                   (uVar7 & 0x1f) +
                                   *(short *)(local_c +
                                             ((local_4c[uVar15 & 0x1f] * (uVar21 & 0x1f) >> 5) -
                                             (uVar21 & 0x1f)) * 4);
                        }
                        else {
                          uVar11 = uVar7 >> 5 & 0x3f;
                          uVar10 = (uint)bVar13;
                          uVar15 = (ushort)(((local_48[uVar15 >> 5 & 0x3f] * uVar11 >> 6) - uVar11)
                                            * uVar10 * DAT_00dca3f8 + (uVar21 & 0xffffffe0) * 0x800
                                           >> 0xb) & 0x7e0 |
                                   (ushort)(((local_50[uVar15 >> 0xb] * (uint)(uVar7 >> 0xb) >> 5) -
                                            (uint)(uVar7 >> 0xb)) * uVar10 * DAT_00dca3f8 +
                                            (uVar21 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                                   (ushort)(((local_4c[uVar15 & 0x1f] * (uVar21 & 0x1f) >> 5) -
                                            (uVar21 & 0x1f)) * uVar10 * DAT_00dca3f8 +
                                            uVar21 * 0x10000 >> 0x10) & 0x1f;
                        }
                        *(ushort *)puVar24 = uVar15;
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                          uVar15 = *(ushort *)
                                    ((&DAT_00f448d8)
                                     [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                      0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                              >> 0x12) * 2);
                          uVar7 = (ushort)*puVar24;
                          uVar21 = uVar7 >> 5 & 0x3f;
                          *(ushort *)puVar24 =
                               ((uVar7 >> 5 & 0x3f) +
                               *(short *)(local_c +
                                         (((int)((uVar15 >> 5 & 0x3f) * uVar21) >> 6) - uVar21) * 4)
                               ) * 0x20 |
                               ((uVar7 >> 0xb) +
                               *(short *)(local_c +
                                         (((int)((uint)(uVar15 >> 0xb) * (uint)(uVar7 >> 0xb)) >> 5)
                                         - (uint)(uVar7 >> 0xb)) * 4)) * 0x800 |
                               (uVar7 & 0x1f) +
                               *(short *)(local_c +
                                         (((int)((uVar15 & 0x1f) * (uVar7 & 0x1f)) >> 5) -
                                         (uVar7 & 0x1f)) * 4);
                        }
                        local_40 = (float)((int)local_40 + local_34);
                        fVar26 = (float)((int)fVar26 + local_38);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      local_40 = (float)((int)local_40 + local_28);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                        uVar15 = *(ushort *)
                                  ((&DAT_00f448d8)
                                   [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >>
                                    0x12] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                            >> 0x12) * 2);
                        if ((float)(uint)uVar15 != local_58) {
                          uVar7 = (ushort)*puVar24;
                          uVar21 = uVar7 >> 5 & 0x3f;
                          *(ushort *)puVar24 =
                               ((uVar7 >> 5 & 0x3f) +
                               *(short *)(local_c +
                                         (((int)((uVar15 >> 5 & 0x3f) * uVar21) >> 6) - uVar21) * 4)
                               ) * 0x20 |
                               ((uVar7 >> 0xb) +
                               *(short *)(local_c +
                                         (((int)((uint)(uVar15 >> 0xb) * (uint)(uVar7 >> 0xb)) >> 5)
                                         - (uint)(uVar7 >> 0xb)) * 4)) * 0x800 |
                               (uVar7 & 0x1f) +
                               *(short *)(local_c +
                                         (((int)((uVar15 & 0x1f) * (uVar7 & 0x1f)) >> 5) -
                                         (uVar7 & 0x1f)) * 4);
                        }
                      }
                      local_40 = (float)((int)local_40 + local_34);
                      fVar26 = (float)((int)fVar26 + local_38);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    local_40 = (float)((int)local_40 + local_28);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        puVar2 = (ushort *)
                                 ((&DAT_00f448d8)
                                  [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                  ] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12
                                      ) * 4);
                        uVar21 = (uint)(ushort)*puVar24;
                        uVar18 = (uint)*puVar2;
                        uVar11 = (uint)(byte)puVar2[1];
                        uVar10 = uVar21 & 0x1f;
                        *(ushort *)puVar24 =
                             (ushort)((((uVar21 & 0xf800) * (uVar18 & 0xf800) >> 0x1b) -
                                      (uint)(ushort)((ushort)*puVar24 >> 0xb)) * uVar11 *
                                      DAT_00dca3f8 + (uVar21 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                             (ushort)((((uVar18 & 0x7e0) * (uVar21 & 0x7e0) >> 0xb) -
                                      (uVar21 & 0x7e0)) * uVar11 * DAT_00dca3f8 +
                                      (uVar21 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                             (ushort)((((uVar18 & 0x1f) * uVar10 >> 5) - uVar10) * uVar11 *
                                      DAT_00dca3f8 + uVar10 * 0x10000 >> 0x10);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_40 < uVar9)) {
                      puVar2 = (ushort *)
                               ((&DAT_00f448d8)
                                [(int)((int)local_40 + ((int)local_40 >> 0x1f & 0x3ffffU)) >> 0x12]
                               + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) * 4
                               );
                      bVar13 = (byte)puVar2[1];
                      uVar15 = *puVar2;
                      uVar10 = (uint)uVar15;
                      uVar21 = (uint)bVar13;
                      uVar7 = (ushort)*puVar24;
                      uVar11 = (uint)uVar7;
                      if (bVar13 == 0xff) {
                        uVar21 = uVar7 >> 5 & 0x3f;
                        *(ushort *)puVar24 =
                             ((uVar7 >> 5 & 0x3f) +
                             *(short *)(local_c +
                                       (((int)((uVar15 >> 5 & 0x3f) * uVar21) >> 6) - uVar21) * 4))
                             * 0x20 | ((uVar7 >> 0xb) +
                                      *(short *)(local_c +
                                                (((int)((uint)(uVar15 >> 0xb) * (uint)(uVar7 >> 0xb)
                                                       ) >> 5) - (uint)(uVar7 >> 0xb)) * 4)) * 0x800
                             | (uVar7 & 0x1f) +
                               *(short *)(local_c +
                                         (((int)((uVar10 & 0x1f) * (uVar11 & 0x1f)) >> 5) -
                                         (uVar11 & 0x1f)) * 4);
                      }
                      else {
                        uVar18 = uVar11 & 0x1f;
                        *(ushort *)puVar24 =
                             (ushort)((((uVar11 & 0xf800) * (uVar10 & 0xf800) >> 0x1b) -
                                      (uint)(uVar7 >> 0xb)) * uVar21 * DAT_00dca3f8 +
                                      (uVar11 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                             (ushort)((((uVar10 & 0x7e0) * (uVar11 & 0x7e0) >> 0xb) -
                                      (uVar11 & 0x7e0)) * uVar21 * DAT_00dca3f8 +
                                      (uVar11 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                             (ushort)((((uVar10 & 0x1f) * uVar18 >> 5) - uVar18) * uVar21 *
                                      DAT_00dca3f8 + uVar18 * 0x10000 >> 0x10);
                      }
                    }
                    local_40 = (float)((int)local_40 + local_34);
                    fVar26 = (float)((int)fVar26 + local_38);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  local_40 = (float)((int)local_40 + local_28);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          uVar15 = *(ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 2);
                          uVar7 = (ushort)*puVar24;
                          uVar21 = (uint)uVar7;
                          uVar11 = uVar7 >> 5 & 0x3f;
                          uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          *(ushort *)puVar24 =
                               (ushort)(((local_48[uVar15 >> 5 & 0x3f] * uVar11 >> 6) - uVar11) *
                                        uVar10 * iVar8 + (uVar21 & 0xffffffe0) * 0x800 >> 0xb) &
                               0x7e0 | (ushort)(((local_50[uVar15 >> 0xb] * (uint)(uVar7 >> 0xb) >>
                                                 5) - (uint)(uVar7 >> 0xb)) * uVar10 * DAT_00dca3f8
                                                + (uVar21 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                               (ushort)(((local_4c[uVar15 & 0x1f] * (uVar21 & 0x1f) >> 5) -
                                        (uVar21 & 0x1f)) * uVar10 * DAT_00dca3f8 + uVar21 * 0x10000
                                       >> 0x10) & 0x1f;
                          iVar8 = DAT_00dca3f8;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = (uint *)((int)puVar24 + 2);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar15 = *(ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 2);
                        if ((float)(uint)uVar15 != local_58) {
                          uVar7 = (ushort)*puVar24;
                          uVar21 = (uint)uVar7;
                          uVar11 = uVar7 >> 5 & 0x3f;
                          uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          *(ushort *)puVar24 =
                               (ushort)(((local_48[uVar15 >> 5 & 0x3f] * uVar11 >> 6) - uVar11) *
                                        uVar10 * iVar8 + (uVar21 & 0xffffffe0) * 0x800 >> 0xb) &
                               0x7e0 | (ushort)(((local_50[uVar15 >> 0xb] * (uint)(uVar7 >> 0xb) >>
                                                 5) - (uint)(uVar7 >> 0xb)) * uVar10 * DAT_00dca3f8
                                                + (uVar21 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                               (ushort)(((local_4c[uVar15 & 0x1f] * (uVar21 & 0x1f) >> 5) -
                                        (uVar21 & 0x1f)) * uVar10 * DAT_00dca3f8 + uVar21 * 0x10000
                                       >> 0x10) & 0x1f;
                          iVar8 = DAT_00dca3f8;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        uVar15 = *puVar2;
                        uVar7 = (ushort)*puVar24;
                        uVar21 = (uint)uVar7;
                        uVar11 = uVar7 >> 5 & 0x3f;
                        uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        uVar18 = (uint)(byte)puVar2[1];
                        *(ushort *)puVar24 =
                             (ushort)(((local_48[uVar15 >> 5 & 0x3f] * uVar11 >> 6) - uVar11) *
                                      uVar10 * uVar18 * iVar8 + (uVar21 & 0xffffffe0) * 0x80000 >>
                                     0x13) & 0x7e0 |
                             (ushort)(((local_50[uVar15 >> 0xb] * (uint)(uVar7 >> 0xb) >> 5) -
                                      (uint)(uVar7 >> 0xb)) * uVar10 * uVar18 * DAT_00dca3f8 +
                                      (uVar21 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                             (byte)(((local_4c[uVar15 & 0x1f] * (uVar21 & 0x1f) >> 5) -
                                    (uVar21 & 0x1f)) * uVar10 * uVar18 * DAT_00dca3f8 +
                                    uVar21 * 0x1000000 >> 0x18) & 0x1f;
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                      pbVar19 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                      uVar21 = (uint)(byte)puVar2[1];
                      if ((byte)puVar2[1] == 0xff) {
                        uVar15 = *puVar2;
                        uVar7 = (ushort)*puVar24;
                        uVar21 = (uint)uVar7;
                        uVar11 = uVar7 >> 5 & 0x3f;
                        uVar10 = (uint)(byte)(&DAT_00dca2e0)[*pbVar19];
                        uVar7 = (ushort)(((local_48[uVar15 >> 5 & 0x3f] * uVar11 >> 6) - uVar11) *
                                         uVar10 * iVar8 + (uVar21 & 0xffffffe0) * 0x800 >> 0xb) &
                                0x7e0 | (ushort)(((local_50[uVar15 >> 0xb] * (uint)(uVar7 >> 0xb) >>
                                                  5) - (uint)(uVar7 >> 0xb)) * uVar10 * DAT_00dca3f8
                                                 + (uVar21 & 0xfffff800) * 0x20 >> 5) & 0xf800;
                        uVar15 = (ushort)(((local_4c[uVar15 & 0x1f] * (uVar21 & 0x1f) >> 5) -
                                          (uVar21 & 0x1f)) * uVar10 * DAT_00dca3f8 +
                                          uVar21 * 0x10000 >> 0x10);
                      }
                      else {
                        uVar15 = *puVar2;
                        uVar7 = (ushort)*puVar24;
                        uVar11 = (uint)uVar7;
                        uVar10 = uVar7 >> 5 & 0x3f;
                        uVar18 = (uint)(byte)(&DAT_00dca2e0)[*pbVar19];
                        uVar7 = (ushort)(((local_48[uVar15 >> 5 & 0x3f] * uVar10 >> 6) - uVar10) *
                                         uVar18 * uVar21 * iVar8 + (uVar11 & 0xffffffe0) * 0x80000
                                        >> 0x13) & 0x7e0 |
                                (ushort)(((local_50[uVar15 >> 0xb] * (uint)(uVar7 >> 0xb) >> 5) -
                                         (uint)(uVar7 >> 0xb)) * uVar18 * uVar21 * DAT_00dca3f8 +
                                         (uVar11 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800;
                        uVar15 = (ushort)(byte)(((local_4c[uVar15 & 0x1f] * (uVar11 & 0x1f) >> 5) -
                                                (uVar11 & 0x1f)) * uVar18 * uVar21 * DAT_00dca3f8 +
                                                uVar11 * 0x1000000 >> 0x18);
                      }
                      *(ushort *)puVar24 = uVar7 | uVar15 & 0x1f;
                      iVar8 = DAT_00dca3f8;
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (*(int *)(iVar23 + 0x2c) != 1) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar15 = (ushort)*puVar24;
                        uVar21 = (uint)uVar15;
                        uVar10 = uVar15 >> 5 & 0x3f;
                        uVar7 = *(ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 2);
                        uVar18 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        uVar11 = uVar21 & 0x1f;
                        *(ushort *)puVar24 =
                             (ushort)((int)((((int)((uVar7 >> 5 & 0x3f) * uVar10) >> 6) - uVar10) *
                                            uVar18 * iVar8 + (uVar21 & 0x7e0) * 0x800) >> 0xb) &
                             0x7e0 | (ushort)((int)((((int)((uint)(uVar7 >> 0xb) *
                                                           (uint)(uVar15 >> 0xb)) >> 5) -
                                                    (uint)(uVar15 >> 0xb)) * uVar18 * DAT_00dca3f8 +
                                                   (uVar21 & 0xfffff800) * 0x20) >> 5) & 0xf800 |
                             (ushort)((((int)((uVar7 & 0x1f) * uVar11) >> 5) - uVar11) * uVar18 *
                                      DAT_00dca3f8 + uVar11 * 0x10000 >> 0x10);
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = (uint *)((int)puVar24 + 2);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar15 = *(ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 2);
                      if ((float)(uint)uVar15 != local_58) {
                        uVar7 = (ushort)*puVar24;
                        uVar21 = (uint)uVar7;
                        uVar10 = uVar7 >> 5 & 0x3f;
                        uVar18 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        uVar11 = uVar21 & 0x1f;
                        *(ushort *)puVar24 =
                             (ushort)((int)((((int)((uVar15 >> 5 & 0x3f) * uVar10) >> 6) - uVar10) *
                                            uVar18 * iVar8 + (uVar21 & 0x7e0) * 0x800) >> 0xb) &
                             0x7e0 | (ushort)((int)((((int)((uint)(uVar15 >> 0xb) *
                                                           (uint)(uVar7 >> 0xb)) >> 5) -
                                                    (uint)(uVar7 >> 0xb)) * uVar18 * DAT_00dca3f8 +
                                                   (uVar21 & 0xfffff800) * 0x20) >> 5) & 0xf800 |
                             (ushort)((((int)((uVar15 & 0x1f) * uVar11) >> 5) - uVar11) * uVar18 *
                                      DAT_00dca3f8 + uVar11 * 0x10000 >> 0x10);
                        iVar8 = DAT_00dca3f8;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 == 0) {
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                      uVar15 = (ushort)*puVar24;
                      uVar21 = (uint)uVar15;
                      uVar11 = uVar15 >> 5 & 0x3f;
                      uVar7 = *puVar2;
                      uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                      uVar18 = (uint)(byte)puVar2[1];
                      uVar22 = uVar21 & 0x1f;
                      *(ushort *)puVar24 =
                           (ushort)((int)((((int)((uVar7 >> 5 & 0x3f) * uVar11) >> 6) - uVar11) *
                                          uVar10 * uVar18 * iVar8 + (uVar21 & 0x7e0) * 0x80000) >>
                                   0x13) & 0x7e0 |
                           (ushort)((int)((((int)((uint)(uVar7 >> 0xb) * (uint)(uVar15 >> 0xb)) >> 5
                                           ) - (uint)(uVar15 >> 0xb)) * uVar10 * uVar18 *
                                          DAT_00dca3f8 + (uVar21 & 0xfffff800) * 0x2000) >> 0xd) &
                           0xf800 | (short)(char)((((int)((uVar7 & 0x1f) * uVar22) >> 5) - uVar22) *
                                                  uVar10 * uVar18 * DAT_00dca3f8 +
                                                  uVar22 * 0x1000000 >> 0x18);
                      iVar8 = DAT_00dca3f8;
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = (uint *)((int)puVar24 + 2);
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                    iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    puVar2 = (ushort *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                    bVar13 = (byte)puVar2[1];
                    uVar15 = *puVar2;
                    uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                         [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                    uVar21 = (uint)bVar13;
                    uVar7 = (ushort)*puVar24;
                    uVar11 = (uint)uVar7;
                    if (bVar13 == 0xff) {
                      uVar18 = uVar11 & 0x1f;
                      uVar21 = uVar7 >> 5 & 0x3f;
                      uVar7 = (ushort)((int)((((int)((uVar15 >> 5 & 0x3f) * uVar21) >> 6) - uVar21)
                                             * uVar10 * iVar8 + (uVar11 & 0x7e0) * 0x800) >> 0xb) &
                              0x7e0 | (ushort)((int)((((int)((uint)(uVar15 >> 0xb) *
                                                            (uint)(uVar7 >> 0xb)) >> 5) -
                                                     (uint)(uVar7 >> 0xb)) * uVar10 * DAT_00dca3f8 +
                                                    (uVar11 & 0xfffff800) * 0x20) >> 5) & 0xf800;
                      uVar15 = (ushort)((((int)((uVar15 & 0x1f) * uVar18) >> 5) - uVar18) * uVar10 *
                                        DAT_00dca3f8 + uVar18 * 0x10000 >> 0x10);
                    }
                    else {
                      uVar22 = uVar11 & 0x1f;
                      uVar18 = uVar7 >> 5 & 0x3f;
                      uVar7 = (ushort)((int)((((int)((uVar15 >> 5 & 0x3f) * uVar18) >> 6) - uVar18)
                                             * uVar10 * uVar21 * iVar8 + (uVar11 & 0x7e0) * 0x80000)
                                      >> 0x13) & 0x7e0 |
                              (ushort)((int)((((int)((uint)(uVar15 >> 0xb) * (uint)(uVar7 >> 0xb))
                                              >> 5) - (uint)(uVar7 >> 0xb)) * uVar10 * uVar21 *
                                             DAT_00dca3f8 + (uVar11 & 0xfffff800) * 0x2000) >> 0xd)
                              & 0xf800;
                      uVar15 = (ushort)(char)((((int)((uVar15 & 0x1f) * uVar22) >> 5) - uVar22) *
                                              uVar10 * uVar21 * DAT_00dca3f8 + uVar22 * 0x1000000 >>
                                             0x18);
                    }
                    *(ushort *)puVar24 = uVar7 | uVar15;
                    iVar8 = DAT_00dca3f8;
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  local_14 = (float)((int)local_14 + local_34);
                  puVar24 = (uint *)((int)puVar24 + 2);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                local_14 = (float)((int)local_14 + local_28);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            }
          }
        }
        else if (*(int *)(iVar23 + 0x20) == 1) {
          if (*(int *)(iVar23 + 0x24) == 1) {
            switch(DAT_00dca3f4) {
            case 0:
switchD_00748bff_caseD_0:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) +
                                            (&DAT_00f448d8)
                                            [(int)((int)local_14 +
                                                  ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]);
                          *(byte *)puVar24 =
                               *(byte *)(local_4c + *(byte *)(local_3c + (uint)*pbVar19 * 4));
                          *(byte *)((int)puVar24 + 1) =
                               *(byte *)(local_48 + *(byte *)(local_3c + 1 + (uint)*pbVar19 * 4));
                          *(byte *)((int)puVar24 + 2) =
                               *(byte *)(local_50 + *(byte *)(local_3c + 2 + (uint)*pbVar19 * 4));
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                           0x12) + (&DAT_00f448d8)
                                                   [(int)((int)local_14 +
                                                         ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                                   ]);
                        if ((float)(uint)*pbVar19 != local_58) {
                          *(byte *)puVar24 =
                               *(byte *)(local_4c + *(byte *)(local_3c + (uint)*pbVar19 * 4));
                          *(byte *)((int)puVar24 + 1) =
                               *(byte *)(local_48 + *(byte *)(local_3c + 1 + (uint)*pbVar19 * 4));
                          *(byte *)((int)puVar24 + 2) =
                               *(byte *)(local_50 + *(byte *)(local_3c + 2 + (uint)*pbVar19 * 4));
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    iVar8 = local_7c;
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        *local_54 = *(uint *)(&DAT_00f404d8 +
                                             (uint)*(byte *)(((uint)fVar26 >> 0x12) +
                                                            (&DAT_00f448d8)[(uint)local_14 >> 0x12])
                                             * 4);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      local_54 = local_54 + 1;
                      iVar8 = iVar8 + -1;
                    } while (iVar8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    local_54 = (uint *)((int)local_54 + local_64);
                    local_10 = local_10 + -1;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  iVar8 = local_7c;
                  do {
                    if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                       (uVar21 = (uint)*(byte *)(((uint)fVar26 >> 0x12) +
                                                (&DAT_00f448d8)[(uint)local_14 >> 0x12]),
                       (float)uVar21 != local_58)) {
                      *local_54 = *(uint *)(&DAT_00f404d8 + uVar21 * 4);
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    local_54 = local_54 + 1;
                    iVar8 = iVar8 + -1;
                  } while (iVar8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  local_54 = (uint *)((int)local_54 + local_64);
                  local_10 = local_10 + -1;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8);
                        *(byte *)puVar24 =
                             (byte)((local_4c[*(byte *)(local_3c + (uint)*pbVar19 * 4)] -
                                    (uint)(byte)*puVar24) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                    (uint)(byte)*puVar24 * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((local_48[*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4)] -
                                    (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((local_50[*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4)] -
                                    (uint)*(byte *)((int)puVar24 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8);
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                      if ((float)(uint)*pbVar19 != local_58) {
                        *(byte *)puVar24 =
                             (byte)((local_4c[*(byte *)(local_3c + (uint)*pbVar19 * 4)] -
                                    (uint)(byte)*puVar24) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                    (uint)(byte)*puVar24 * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((local_48[*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4)] -
                                    (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((local_50[*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4)] -
                                    (uint)*(byte *)((int)puVar24 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 == 0) {
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8);
                      *(byte *)puVar24 =
                           (byte)(((uint)*(byte *)(local_3c + (uint)*pbVar19 * 4) -
                                  (uint)(byte)*puVar24) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                  (uint)(byte)*puVar24 * 0x100 >> 8);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)(((uint)*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) -
                                  (uint)*(byte *)((int)puVar24 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                  (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                      *(byte *)((int)puVar24 + 2) =
                           (byte)(((uint)*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) -
                                  (uint)*(byte *)((int)puVar24 + 2)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                  (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                    iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8);
                    pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                    if ((float)(uint)*pbVar19 != local_58) {
                      *(byte *)puVar24 =
                           (byte)(((uint)*(byte *)(local_3c + (uint)*pbVar19 * 4) -
                                  (uint)(byte)*puVar24) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                  (uint)(byte)*puVar24 * 0x100 >> 8);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)(((uint)*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) -
                                  (uint)*(byte *)((int)puVar24 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                  (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                      *(byte *)((int)puVar24 + 2) =
                           (byte)(((uint)*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) -
                                  (uint)*(byte *)((int)puVar24 + 2)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                  (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                    }
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  local_14 = (float)((int)local_14 + local_34);
                  puVar24 = puVar24 + 1;
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                local_14 = (float)((int)local_14 + local_28);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            case 1:
              if (iVar8 == 0xff) goto switchD_00748bff_caseD_0;
              if (iVar8 != 0) {
                if (param_11 == 0) {
                  if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)
                                                     ) >> 0x12) +
                                              (&DAT_00f448d8)
                                              [(int)((int)local_14 +
                                                    ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]);
                            *(byte *)puVar24 =
                                 (byte)((local_4c[*(byte *)(local_3c + (uint)*pbVar19 * 4)] -
                                        (uint)(byte)*puVar24) * DAT_00dca3f8 +
                                        (uint)(byte)*puVar24 * 0x100 >> 8);
                            *(byte *)((int)puVar24 + 1) =
                                 (byte)((local_48[*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4)] -
                                        (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                            *(byte *)((int)puVar24 + 2) =
                                 (byte)((local_50[*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4)] -
                                        (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) +
                                            (&DAT_00f448d8)
                                            [(int)((int)local_14 +
                                                  ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]);
                          if ((float)(uint)*pbVar19 != local_58) {
                            *(byte *)puVar24 =
                                 (byte)((local_4c[*(byte *)(local_3c + (uint)*pbVar19 * 4)] -
                                        (uint)(byte)*puVar24) * DAT_00dca3f8 +
                                        (uint)(byte)*puVar24 * 0x100 >> 8);
                            *(byte *)((int)puVar24 + 1) =
                                 (byte)((local_48[*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4)] -
                                        (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                            *(byte *)((int)puVar24 + 2) =
                                 (byte)((local_50[*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4)] -
                                        (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                          }
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) +
                                            (&DAT_00f448d8)
                                            [(int)((int)local_14 +
                                                  ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]);
                          *(byte *)puVar24 =
                               (byte)(((uint)*(byte *)(local_3c + (uint)*pbVar19 * 4) -
                                      (uint)(byte)*puVar24) * DAT_00dca3f8 +
                                      (uint)(byte)*puVar24 * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) -
                                      (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) -
                                      (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                           0x12) + (&DAT_00f448d8)
                                                   [(int)((int)local_14 +
                                                         ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                                   ]);
                        if ((float)(uint)*pbVar19 != local_58) {
                          *(byte *)puVar24 =
                               (byte)(((uint)*(byte *)(local_3c + (uint)*pbVar19 * 4) -
                                      (uint)(byte)*puVar24) * DAT_00dca3f8 +
                                      (uint)(byte)*puVar24 * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) -
                                      (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) -
                                      (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                          pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                          *(byte *)puVar24 =
                               (byte)((local_4c[*(byte *)(local_3c + (uint)*pbVar19 * 4)] -
                                      (uint)(byte)*puVar24) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20]
                                      * iVar8 + (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((local_48[*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4)] -
                                      (uint)*(byte *)((int)puVar24 + 1)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)((local_50[*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4)] -
                                      (uint)*(byte *)((int)puVar24 + 2)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                          iVar8 = DAT_00dca3f8;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                        pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                        if ((float)(uint)*pbVar19 != local_58) {
                          *(byte *)puVar24 =
                               (byte)((local_4c[*(byte *)(local_3c + (uint)*pbVar19 * 4)] -
                                      (uint)(byte)*puVar24) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20]
                                      * iVar8 + (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((local_48[*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4)] -
                                      (uint)*(byte *)((int)puVar24 + 1)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)((local_50[*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4)] -
                                      (uint)*(byte *)((int)puVar24 + 2)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                          iVar8 = DAT_00dca3f8;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                        pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                        *(byte *)puVar24 =
                             (byte)(((uint)*(byte *)(local_3c + (uint)*pbVar19 * 4) -
                                    (uint)(byte)*puVar24) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                    iVar8 + (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) -
                                    (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) -
                                    (uint)*(byte *)((int)puVar24 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                      if ((float)(uint)*pbVar19 != local_58) {
                        *(byte *)puVar24 =
                             (byte)(((uint)*(byte *)(local_3c + (uint)*pbVar19 * 4) -
                                    (uint)(byte)*puVar24) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                    iVar8 + (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) -
                                    (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) -
                                    (uint)*(byte *)((int)puVar24 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                        iVar8 = DAT_00dca3f8;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              break;
            case 2:
              if (iVar8 != 0) {
                if (param_11 == 0) {
                  if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                    uVar21 = (uint)local_14;
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                            pbVar19 = (byte *)(local_3c +
                                              (uint)*(byte *)(((int)((int)fVar26 +
                                                                    ((int)fVar26 >> 0x1f & 0x3ffffU)
                                                                    ) >> 0x12) +
                                                             (&DAT_00f448d8)
                                                             [(int)(uVar21 + ((int)uVar21 >> 0x1f &
                                                                             0x3ffffU)) >> 0x12]) *
                                              4);
                            local_14._0_2_ =
                                 CONCAT11(*(undefined1 *)(local_18 + local_48[pbVar19[1]]),
                                          *(undefined1 *)(local_18 + local_4c[*pbVar19]));
                            local_14._0_3_ =
                                 CONCAT12(*(undefined1 *)(local_18 + local_50[pbVar19[2]]),
                                          (ushort)local_14);
                            local_14 = (float)(uint)(uint3)local_14;
                            uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                            uVar10 = uVar11 & 0x1010100;
                            *puVar24 = uVar10 - (uVar10 >> 8) |
                                       ((uint)local_14 | *puVar24) & 0x10100 | uVar11;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          uVar21 = uVar21 + local_34;
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        uVar21 = uVar21 + local_28;
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if ((((uint)fVar26 < uVar12) && (uVar21 < uVar9)) &&
                           (uVar11 = (uint)*(byte *)(((int)((int)fVar26 +
                                                           ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12
                                                     ) + (&DAT_00f448d8)
                                                         [(int)(uVar21 + ((int)uVar21 >> 0x1f &
                                                                         0x3ffffU)) >> 0x12]),
                           (float)uVar11 != local_58)) {
                          local_14._0_2_ =
                               CONCAT11(*(undefined1 *)
                                         (local_18 + local_48[*(byte *)(local_3c + 1 + uVar11 * 4)])
                                        ,*(undefined1 *)
                                          (local_18 + local_4c[*(byte *)(local_3c + uVar11 * 4)]));
                          local_14._0_3_ =
                               CONCAT12(*(undefined1 *)
                                         (local_18 + local_50[*(byte *)(local_3c + 2 + uVar11 * 4)])
                                        ,(ushort)local_14);
                          local_14 = (float)(uint)(uint3)local_14;
                          uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                          uVar10 = uVar11 & 0x1010100;
                          *puVar24 = uVar10 - (uVar10 >> 8) | ((uint)local_14 | *puVar24) & 0x10100
                                     | uVar11;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        uVar21 = uVar21 + local_34;
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      uVar21 = uVar21 + local_28;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  uVar21 = (uint)local_14;
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                          uVar11 = (uint)*(byte *)(((int)((int)fVar26 +
                                                         ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                  + (&DAT_00f448d8)
                                                    [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)
                                                          ) >> 0x12]);
                          iVar8 = local_3c + uVar11 * 4;
                          local_14._0_2_ =
                               CONCAT11(*(undefined1 *)(local_18 + *(byte *)(iVar8 + 1)),
                                        *(undefined1 *)(local_18 + *(byte *)(local_3c + uVar11 * 4))
                                       );
                          local_14 = (float)(uint)CONCAT12(*(undefined1 *)
                                                            (local_18 + *(byte *)(iVar8 + 2)),
                                                           (ushort)local_14);
                          uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                          uVar10 = uVar11 & 0x1010100;
                          *puVar24 = uVar10 - (uVar10 >> 8) | ((uint)local_14 | *puVar24) & 0x10100
                                     | uVar11;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        uVar21 = uVar21 + local_34;
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      uVar21 = uVar21 + local_28;
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if ((((uint)fVar26 < uVar12) && (uVar21 < uVar9)) &&
                         (uVar11 = (uint)*(byte *)(((int)((int)fVar26 +
                                                         ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                  + (&DAT_00f448d8)
                                                    [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)
                                                          ) >> 0x12]), (float)uVar11 != local_58)) {
                        local_14._0_2_ =
                             CONCAT11(*(undefined1 *)
                                       (local_18 + *(byte *)(local_3c + 1 + uVar11 * 4)),
                                      *(undefined1 *)(local_18 + *(byte *)(local_3c + uVar11 * 4)));
                        local_14._0_3_ =
                             CONCAT12(*(undefined1 *)
                                       (local_18 + *(byte *)(local_3c + 2 + uVar11 * 4)),
                                      (ushort)local_14);
                        local_14 = (float)(uint)(uint3)local_14;
                        uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                        uVar10 = uVar11 & 0x1010100;
                        *puVar24 = uVar10 - (uVar10 >> 8) | ((uint)local_14 | *puVar24) & 0x10100 |
                                   uVar11;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      uVar21 = uVar21 + local_34;
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    uVar21 = uVar21 + local_28;
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  uVar21 = (uint)local_14;
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                          iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          pbVar19 = (byte *)(local_3c +
                                            (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25) * 4);
                          uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          local_14._0_2_ =
                               CONCAT11((char)(local_48[pbVar19[1]] * uVar11 * iVar8 >> 0x10),
                                        (char)(local_4c[*pbVar19] * uVar11 * iVar8 >> 0x10));
                          local_14._0_3_ =
                               CONCAT12((char)(local_50[pbVar19[2]] * uVar11 * iVar8 >> 0x10),
                                        (ushort)local_14);
                          local_14 = (float)(uint)(uint3)local_14;
                          uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                          uVar10 = uVar11 & 0x1010100;
                          *puVar24 = uVar10 - (uVar10 >> 8) | ((uint)local_14 | *puVar24) & 0x10100
                                     | uVar11;
                          iVar8 = DAT_00dca3f8;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        uVar21 = uVar21 + local_34;
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      uVar21 = uVar21 + local_28;
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                        iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        uVar11 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                        if ((float)uVar11 != local_58) {
                          uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          local_14._0_2_ =
                               CONCAT11((char)(local_48[*(byte *)(local_3c + 1 + uVar11 * 4)] *
                                               uVar10 * iVar8 >> 0x10),
                                        (char)(local_4c[*(byte *)(local_3c + uVar11 * 4)] * uVar10 *
                                               iVar8 >> 0x10));
                          local_14._0_3_ =
                               CONCAT12((char)(local_50[*(byte *)(local_3c + 2 + uVar11 * 4)] *
                                               uVar10 * iVar8 >> 0x10),(ushort)local_14);
                          local_14 = (float)(uint)(uint3)local_14;
                          uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                          uVar10 = uVar11 & 0x1010100;
                          *puVar24 = uVar10 - (uVar10 >> 8) | ((uint)local_14 | *puVar24) & 0x10100
                                     | uVar11;
                          iVar8 = DAT_00dca3f8;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      uVar21 = uVar21 + local_34;
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    uVar21 = uVar21 + local_28;
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                uVar21 = (uint)local_14;
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                        iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)(local_3c +
                                          (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25) * 4);
                        uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        local_14._0_2_ =
                             CONCAT11((char)(pbVar19[1] * uVar11 * iVar8 >> 0x10),
                                      (char)(*pbVar19 * uVar11 * iVar8 >> 0x10));
                        local_14._0_3_ =
                             CONCAT12((char)(pbVar19[2] * uVar11 * iVar8 >> 0x10),(ushort)local_14);
                        local_14 = (float)(uint)(uint3)local_14;
                        uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                        uVar10 = uVar11 & 0x1010100;
                        *puVar24 = uVar10 - (uVar10 >> 8) | ((uint)local_14 | *puVar24) & 0x10100 |
                                   uVar11;
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      uVar21 = uVar21 + local_34;
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    uVar21 = uVar21 + local_28;
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                      iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar11 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                      if ((float)uVar11 != local_58) {
                        uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        local_14._0_2_ =
                             CONCAT11((char)(*(byte *)(local_3c + 1 + uVar11 * 4) * uVar10 * iVar8
                                            >> 0x10),
                                      (char)(*(byte *)(local_3c + uVar11 * 4) * uVar10 * iVar8 >>
                                            0x10));
                        local_14._0_3_ =
                             CONCAT12((char)(*(byte *)(local_3c + 2 + uVar11 * 4) * uVar10 * iVar8
                                            >> 0x10),(ushort)local_14);
                        local_14 = (float)(uint)(uint3)local_14;
                        uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                        uVar10 = uVar11 & 0x1010100;
                        *puVar24 = uVar10 - (uVar10 >> 8) | ((uint)local_14 | *puVar24) & 0x10100 |
                                   uVar11;
                        iVar8 = DAT_00dca3f8;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    uVar21 = uVar21 + local_34;
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  uVar21 = uVar21 + local_28;
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              break;
            case 3:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  uVar21 = (uint)local_14;
                  if (param_8 == 0) {
                    do {
                      do {
                        uVar11 = (uint)local_14;
                        if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                          pbVar19 = (byte *)(local_3c +
                                            (uint)*(byte *)(((int)((int)fVar26 +
                                                                  ((int)fVar26 >> 0x1f & 0x3ffffU))
                                                            >> 0x12) +
                                                           (&DAT_00f448d8)
                                                           [(int)(uVar21 + ((int)uVar21 >> 0x1f &
                                                                           0x3ffffU)) >> 0x12]) * 4)
                          ;
                          local_14._0_2_ =
                               CONCAT11(*(undefined1 *)(local_18 + local_48[pbVar19[1]]),
                                        *(undefined1 *)(local_18 + local_4c[*pbVar19]));
                          local_14._3_1_ = SUB41(uVar11,3);
                          local_14._0_3_ =
                               CONCAT12(*(undefined1 *)(local_18 + local_50[pbVar19[2]]),
                                        (ushort)local_14);
                          uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                          uVar11 = uVar10 & 0x1010100;
                          *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        uVar21 = uVar21 + local_34;
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      uVar21 = uVar21 + local_28;
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      uVar11 = (uint)local_14;
                      if ((((uint)fVar26 < uVar12) && (uVar21 < uVar9)) &&
                         (uVar10 = (uint)*(byte *)(((int)((int)fVar26 +
                                                         ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12)
                                                  + (&DAT_00f448d8)
                                                    [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)
                                                          ) >> 0x12]), (float)uVar10 != local_58)) {
                        local_14._0_2_ =
                             CONCAT11(*(undefined1 *)
                                       (local_18 + local_48[*(byte *)(local_3c + 1 + uVar10 * 4)]),
                                      *(undefined1 *)
                                       (local_18 + local_4c[*(byte *)(local_3c + uVar10 * 4)]));
                        local_14._3_1_ = SUB41(uVar11,3);
                        local_14._0_3_ =
                             CONCAT12(*(undefined1 *)
                                       (local_18 + local_50[*(byte *)(local_3c + 2 + uVar10 * 4)]),
                                      (ushort)local_14);
                        uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                        uVar11 = uVar10 & 0x1010100;
                        *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      uVar21 = uVar21 + local_34;
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    uVar21 = uVar21 + local_28;
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                uVar21 = (uint)local_14;
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                        uVar11 = (uint)*(byte *)(((int)((int)fVar26 +
                                                       ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) +
                                                (&DAT_00f448d8)
                                                [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >>
                                                 0x12]);
                        iVar8 = local_3c + uVar11 * 4;
                        local_14._0_2_ =
                             CONCAT11(*(undefined1 *)(local_18 + *(byte *)(iVar8 + 1)),
                                      *(undefined1 *)(local_18 + *(byte *)(local_3c + uVar11 * 4)));
                        local_14 = (float)CONCAT22(CONCAT11(local_14._3_1_,
                                                            *(undefined1 *)
                                                             (local_18 + *(byte *)(iVar8 + 2))),
                                                   (ushort)local_14);
                        uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                        uVar11 = uVar10 & 0x1010100;
                        *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      uVar21 = uVar21 + local_34;
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    uVar21 = uVar21 + local_28;
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    uVar11 = (uint)local_14;
                    if ((((uint)fVar26 < uVar12) && (uVar21 < uVar9)) &&
                       (uVar10 = (uint)*(byte *)(((int)((int)fVar26 +
                                                       ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) +
                                                (&DAT_00f448d8)
                                                [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >>
                                                 0x12]), (float)uVar10 != local_58)) {
                      local_14._0_2_ =
                           CONCAT11(*(undefined1 *)(local_18 + *(byte *)(local_3c + 1 + uVar10 * 4))
                                    ,*(undefined1 *)(local_18 + *(byte *)(local_3c + uVar10 * 4)));
                      local_14._3_1_ = SUB41(uVar11,3);
                      local_14._0_3_ =
                           CONCAT12(*(undefined1 *)(local_18 + *(byte *)(local_3c + 2 + uVar10 * 4))
                                    ,(ushort)local_14);
                      uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                      uVar11 = uVar10 & 0x1010100;
                      *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    uVar21 = uVar21 + local_34;
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  uVar21 = uVar21 + local_28;
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                uVar21 = (uint)local_14;
                if (param_8 == 0) {
                  do {
                    do {
                      uVar11 = (uint)local_14;
                      if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                        iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)(local_3c +
                                          (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25) * 4);
                        uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        local_14._0_2_ =
                             CONCAT11((char)(local_48[pbVar19[1]] * uVar10 * iVar8 >> 0x10),
                                      (char)(local_4c[*pbVar19] * uVar10 * iVar8 >> 0x10));
                        local_14._3_1_ = SUB41(uVar11,3);
                        local_14._0_3_ =
                             CONCAT12((char)(local_50[pbVar19[2]] * uVar10 * iVar8 >> 0x10),
                                      (ushort)local_14);
                        uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                        uVar11 = uVar10 & 0x1010100;
                        *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      uVar21 = uVar21 + local_34;
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    uVar21 = uVar21 + local_28;
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    uVar11 = (uint)local_14;
                    if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                      iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      uVar10 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                      if ((float)uVar10 != local_58) {
                        uVar18 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        local_14._0_2_ =
                             CONCAT11((char)(local_48[*(byte *)(local_3c + 1 + uVar10 * 4)] * uVar18
                                             * iVar8 >> 0x10),
                                      (char)(local_4c[*(byte *)(local_3c + uVar10 * 4)] * uVar18 *
                                             iVar8 >> 0x10));
                        local_14._3_1_ = SUB41(uVar11,3);
                        local_14._0_3_ =
                             CONCAT12((char)(local_50[*(byte *)(local_3c + 2 + uVar10 * 4)] * uVar18
                                             * iVar8 >> 0x10),(ushort)local_14);
                        uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                        uVar11 = uVar10 & 0x1010100;
                        *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                        iVar8 = DAT_00dca3f8;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    uVar21 = uVar21 + local_34;
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  uVar21 = uVar21 + local_28;
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              uVar21 = (uint)local_14;
              if (param_8 == 0) {
                do {
                  do {
                    uVar11 = (uint)local_14;
                    if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                      iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar19 = (byte *)(local_3c +
                                        (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25) * 4);
                      uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                      local_14._0_2_ =
                           CONCAT11((char)(pbVar19[1] * uVar10 * iVar8 >> 0x10),
                                    (char)(*pbVar19 * uVar10 * iVar8 >> 0x10));
                      local_14._3_1_ = SUB41(uVar11,3);
                      local_14._0_3_ =
                           CONCAT12((char)(pbVar19[2] * uVar10 * iVar8 >> 0x10),(ushort)local_14);
                      uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                      uVar11 = uVar10 & 0x1010100;
                      *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                      iVar8 = DAT_00dca3f8;
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    uVar21 = uVar21 + local_34;
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  uVar21 = uVar21 + local_28;
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  uVar11 = (uint)local_14;
                  if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                    iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    uVar10 = (uint)*(byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                    if ((float)uVar10 != local_58) {
                      uVar18 = (uint)(byte)(&DAT_00dca2e0)
                                           [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                      local_14._0_2_ =
                           CONCAT11((char)(*(byte *)(local_3c + 1 + uVar10 * 4) * uVar18 * iVar8 >>
                                          0x10),
                                    (char)(*(byte *)(local_3c + uVar10 * 4) * uVar18 * iVar8 >> 0x10
                                          ));
                      local_14._3_1_ = SUB41(uVar11,3);
                      local_14._0_3_ =
                           CONCAT12((char)(*(byte *)(local_3c + 2 + uVar10 * 4) * uVar18 * iVar8 >>
                                          0x10),(ushort)local_14);
                      uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                      uVar11 = uVar10 & 0x1010100;
                      *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                      iVar8 = DAT_00dca3f8;
                    }
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  uVar21 = uVar21 + local_34;
                  puVar24 = puVar24 + 1;
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                uVar21 = uVar21 + local_28;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            case 4:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) +
                                            (&DAT_00f448d8)
                                            [(int)((int)local_14 +
                                                  ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]);
                          *(byte *)puVar24 =
                               (byte)((uint)(byte)*puVar24 *
                                      local_4c[*(byte *)(local_3c + (uint)*pbVar19 * 4)] >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((uint)*(byte *)((int)puVar24 + 1) *
                                      local_48[*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4)] >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)((uint)*(byte *)((int)puVar24 + 2) *
                                      local_50[*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4)] >> 8);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                           0x12) + (&DAT_00f448d8)
                                                   [(int)((int)local_14 +
                                                         ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                                   ]);
                        if ((float)(uint)*pbVar19 != local_58) {
                          *(byte *)puVar24 =
                               (byte)((uint)(byte)*puVar24 *
                                      local_4c[*(byte *)(local_3c + (uint)*pbVar19 * 4)] >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((uint)*(byte *)((int)puVar24 + 1) *
                                      local_48[*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4)] >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)((uint)*(byte *)((int)puVar24 + 2) *
                                      local_50[*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4)] >> 8);
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                           0x12) + (&DAT_00f448d8)
                                                   [(int)((int)local_14 +
                                                         ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                                   ]);
                        *(byte *)puVar24 =
                             (byte)((uint)*(byte *)(local_3c + (uint)*pbVar19 * 4) *
                                    (uint)(byte)*puVar24 >> 8);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((uint)*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) *
                                    (uint)*(byte *)((int)puVar24 + 1) >> 8);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((uint)*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) *
                                    (uint)*(byte *)((int)puVar24 + 2) >> 8);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                         0x12) + (&DAT_00f448d8)
                                                 [(int)((int)local_14 +
                                                       ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12])
                      ;
                      if ((float)(uint)*pbVar19 != local_58) {
                        *(byte *)puVar24 =
                             (byte)((uint)*(byte *)(local_3c + (uint)*pbVar19 * 4) *
                                    (uint)(byte)*puVar24 >> 8);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((uint)*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) *
                                    (uint)*(byte *)((int)puVar24 + 1) >> 8);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((uint)*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) *
                                    (uint)*(byte *)((int)puVar24 + 2) >> 8);
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8);
                        pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                        *(byte *)puVar24 =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                    local_4c[*(byte *)(local_3c + (uint)*pbVar19 * 4)] *
                                    (uint)(byte)*puVar24 >> 0x10);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                    local_48[*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4)] *
                                    (uint)*(byte *)((int)puVar24 + 1) >> 0x10);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                    local_50[*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4)] *
                                    (uint)*(byte *)((int)puVar24 + 2) >> 0x10);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8);
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                      if ((float)(uint)*pbVar19 != local_58) {
                        *(byte *)puVar24 =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                    local_4c[*(byte *)(local_3c + (uint)*pbVar19 * 4)] *
                                    (uint)(byte)*puVar24 >> 0x10);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                    local_48[*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4)] *
                                    (uint)*(byte *)((int)puVar24 + 1) >> 0x10);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                    local_50[*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4)] *
                                    (uint)*(byte *)((int)puVar24 + 2) >> 0x10);
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 == 0) {
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8);
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                      *(byte *)puVar24 =
                           (byte)((uint)*(byte *)(local_3c + (uint)*pbVar19 * 4) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)(byte)*puVar24 >>
                                 0x10);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)((uint)*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                  (uint)*(byte *)((int)puVar24 + 1) >> 0x10);
                      *(byte *)((int)puVar24 + 2) =
                           (byte)((uint)*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                  (uint)*(byte *)((int)puVar24 + 2) >> 0x10);
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                    iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8);
                    pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                    if ((float)(uint)*pbVar19 != local_58) {
                      *(byte *)puVar24 =
                           (byte)((uint)*(byte *)(local_3c + (uint)*pbVar19 * 4) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)(byte)*puVar24 >>
                                 0x10);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)((uint)*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                  (uint)*(byte *)((int)puVar24 + 1) >> 0x10);
                      *(byte *)((int)puVar24 + 2) =
                           (byte)((uint)*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                  (uint)*(byte *)((int)puVar24 + 2) >> 0x10);
                    }
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  local_14 = (float)((int)local_14 + local_34);
                  puVar24 = puVar24 + 1;
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                local_14 = (float)((int)local_14 + local_28);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            case 10:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) +
                                            (&DAT_00f448d8)
                                            [(int)((int)local_14 +
                                                  ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]);
                          *(byte *)puVar24 =
                               (byte)(((uint)*(byte *)(local_4c +
                                                      (byte)~*(byte *)(local_3c + (uint)*pbVar19 * 4
                                                                      )) - (uint)(byte)*puVar24) *
                                      DAT_00dca3f8 + (uint)(byte)*puVar24 * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)*(byte *)(local_48 +
                                                      (byte)~*(byte *)(local_3c + 1 +
                                                                      (uint)*pbVar19 * 4)) -
                                      (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)*(byte *)(local_50 +
                                                      (byte)~*(byte *)(local_3c + 2 +
                                                                      (uint)*pbVar19 * 4)) -
                                      (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                           0x12) + (&DAT_00f448d8)
                                                   [(int)((int)local_14 +
                                                         ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                                   ]);
                        if ((float)(uint)*pbVar19 != local_58) {
                          *(byte *)puVar24 =
                               (byte)(((uint)*(byte *)(local_4c +
                                                      (byte)~*(byte *)(local_3c + (uint)*pbVar19 * 4
                                                                      )) - (uint)(byte)*puVar24) *
                                      DAT_00dca3f8 + (uint)(byte)*puVar24 * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)*(byte *)(local_48 +
                                                      (byte)~*(byte *)(local_3c + 1 +
                                                                      (uint)*pbVar19 * 4)) -
                                      (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)*(byte *)(local_50 +
                                                      (byte)~*(byte *)(local_3c + 2 +
                                                                      (uint)*pbVar19 * 4)) -
                                      (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                           0x12) + (&DAT_00f448d8)
                                                   [(int)((int)local_14 +
                                                         ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                                   ]);
                        *(byte *)puVar24 =
                             (byte)(((uint)(byte)~*(byte *)(local_3c + (uint)*pbVar19 * 4) -
                                    (uint)(byte)*puVar24) * DAT_00dca3f8 +
                                    (uint)(byte)*puVar24 * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)(byte)~*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) -
                                    (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)(byte)~*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) -
                                    (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                         0x12) + (&DAT_00f448d8)
                                                 [(int)((int)local_14 +
                                                       ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12])
                      ;
                      if ((float)(uint)*pbVar19 != local_58) {
                        *(byte *)puVar24 =
                             (byte)(((uint)(byte)~*(byte *)(local_3c + (uint)*pbVar19 * 4) -
                                    (uint)(byte)*puVar24) * DAT_00dca3f8 +
                                    (uint)(byte)*puVar24 * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)(byte)~*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) -
                                    (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)(byte)~*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) -
                                    (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                        pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                        *(byte *)puVar24 =
                             (byte)(((uint)*(byte *)(local_4c +
                                                    (byte)~*(byte *)(local_3c + (uint)*pbVar19 * 4))
                                    - (uint)(byte)*puVar24) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20]
                                    * iVar8 + (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)*(byte *)(local_48 +
                                                    (byte)~*(byte *)(local_3c + 1 +
                                                                    (uint)*pbVar19 * 4)) -
                                    (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)*(byte *)(local_50 +
                                                    (byte)~*(byte *)(local_3c + 2 +
                                                                    (uint)*pbVar19 * 4)) -
                                    (uint)*(byte *)((int)puVar24 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                      if ((float)(uint)*pbVar19 != local_58) {
                        *(byte *)puVar24 =
                             (byte)(((uint)*(byte *)(local_4c +
                                                    (byte)~*(byte *)(local_3c + (uint)*pbVar19 * 4))
                                    - (uint)(byte)*puVar24) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20]
                                    * iVar8 + (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)*(byte *)(local_48 +
                                                    (byte)~*(byte *)(local_3c + 1 +
                                                                    (uint)*pbVar19 * 4)) -
                                    (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)*(byte *)(local_50 +
                                                    (byte)~*(byte *)(local_3c + 2 +
                                                                    (uint)*pbVar19 * 4)) -
                                    (uint)*(byte *)((int)puVar24 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                        iVar8 = DAT_00dca3f8;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 == 0) {
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                      *(byte *)puVar24 =
                           (byte)(((uint)(byte)~*(byte *)(local_3c + (uint)*pbVar19 * 4) -
                                  (uint)(byte)*puVar24) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                  iVar8 + (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)(((uint)(byte)~*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) -
                                  (uint)*(byte *)((int)puVar24 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                      *(byte *)((int)puVar24 + 2) =
                           (byte)(((uint)(byte)~*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) -
                                  (uint)*(byte *)((int)puVar24 + 2)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                      iVar8 = DAT_00dca3f8;
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                    iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                    pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                    if ((float)(uint)*pbVar19 != local_58) {
                      *(byte *)puVar24 =
                           (byte)(((uint)(byte)~*(byte *)(local_3c + (uint)*pbVar19 * 4) -
                                  (uint)(byte)*puVar24) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                  iVar8 + (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)(((uint)(byte)~*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) -
                                  (uint)*(byte *)((int)puVar24 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                      *(byte *)((int)puVar24 + 2) =
                           (byte)(((uint)(byte)~*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) -
                                  (uint)*(byte *)((int)puVar24 + 2)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                      iVar8 = DAT_00dca3f8;
                    }
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  local_14 = (float)((int)local_14 + local_34);
                  puVar24 = puVar24 + 1;
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                local_14 = (float)((int)local_14 + local_28);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            case 0xb:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          uVar21 = (uint)(byte)*puVar24;
                          pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) +
                                            (&DAT_00f448d8)
                                            [(int)((int)local_14 +
                                                  ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]);
                          *(byte *)puVar24 =
                               (byte)(((local_4c[*(byte *)(local_3c + (uint)*pbVar19 * 4)] * uVar21
                                        >> 8 & 0xff) - uVar21) * DAT_00dca3f8 + uVar21 * 0x100 >> 8)
                          ;
                          uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((local_48[*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4)] *
                                        uVar21 >> 8 & 0xff) - uVar21) * DAT_00dca3f8 +
                                      uVar21 * 0x100 >> 8);
                          uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((local_50[*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4)] *
                                        uVar21 >> 8 & 0xff) - uVar21) * DAT_00dca3f8 +
                                      uVar21 * 0x100 >> 8);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                           0x12) + (&DAT_00f448d8)
                                                   [(int)((int)local_14 +
                                                         ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                                   ]);
                        if ((float)(uint)*pbVar19 != local_58) {
                          uVar21 = (uint)(byte)*puVar24;
                          *(byte *)puVar24 =
                               (byte)(((local_4c[*(byte *)(local_3c + (uint)*pbVar19 * 4)] * uVar21
                                        >> 8 & 0xff) - uVar21) * DAT_00dca3f8 + uVar21 * 0x100 >> 8)
                          ;
                          uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((local_48[*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4)] *
                                        uVar21 >> 8 & 0xff) - uVar21) * DAT_00dca3f8 +
                                      uVar21 * 0x100 >> 8);
                          uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((local_50[*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4)] *
                                        uVar21 >> 8 & 0xff) - uVar21) * DAT_00dca3f8 +
                                      uVar21 * 0x100 >> 8);
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        uVar21 = (uint)(byte)*puVar24;
                        pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                           0x12) + (&DAT_00f448d8)
                                                   [(int)((int)local_14 +
                                                         ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                                   ]);
                        *(byte *)puVar24 =
                             (byte)((((int)(*(byte *)(local_3c + (uint)*pbVar19 * 4) * uVar21) >> 8)
                                    - uVar21) * DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((((int)(*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) * uVar21)
                                     >> 8) - uVar21) * DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((((int)(*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) * uVar21)
                                     >> 8) - uVar21) * DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      pbVar19 = (byte *)(((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                         0x12) + (&DAT_00f448d8)
                                                 [(int)((int)local_14 +
                                                       ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12])
                      ;
                      if ((float)(uint)*pbVar19 != local_58) {
                        uVar21 = (uint)(byte)*puVar24;
                        *(byte *)puVar24 =
                             (byte)((((int)(*(byte *)(local_3c + (uint)*pbVar19 * 4) * uVar21) >> 8)
                                    - uVar21) * DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((((int)(*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) * uVar21)
                                     >> 8) - uVar21) * DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((((int)(*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) * uVar21)
                                     >> 8) - uVar21) * DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                        pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                        uVar21 = (uint)(byte)*puVar24;
                        *(byte *)puVar24 =
                             (byte)(((local_4c[*(byte *)(local_3c + (uint)*pbVar19 * 4)] * uVar21 >>
                                      8 & 0xff) - uVar21) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                    iVar8 + uVar21 * 0x10000 >> 0x10);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((local_48[*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4)] *
                                      uVar21 >> 8 & 0xff) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    uVar21 * 0x10000 >> 0x10);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((local_50[*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4)] *
                                      uVar21 >> 8 & 0xff) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    uVar21 * 0x10000 >> 0x10);
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                      if ((float)(uint)*pbVar19 != local_58) {
                        uVar21 = (uint)(byte)*puVar24;
                        *(byte *)puVar24 =
                             (byte)(((local_4c[*(byte *)(local_3c + (uint)*pbVar19 * 4)] * uVar21 >>
                                      8 & 0xff) - uVar21) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                    iVar8 + uVar21 * 0x10000 >> 0x10);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((local_48[*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4)] *
                                      uVar21 >> 8 & 0xff) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    uVar21 * 0x10000 >> 0x10);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((local_50[*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4)] *
                                      uVar21 >> 8 & 0xff) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    uVar21 * 0x10000 >> 0x10);
                        iVar8 = DAT_00dca3f8;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 == 0) {
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                      uVar21 = (uint)(byte)*puVar24;
                      *(byte *)puVar24 =
                           (byte)((((int)(*(byte *)(local_3c + (uint)*pbVar19 * 4) * uVar21) >> 8) -
                                  uVar21) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * iVar8 +
                                  uVar21 * 0x10000 >> 0x10);
                      uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)((((int)(*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) * uVar21) >>
                                   8) - uVar21) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                  DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10);
                      uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                      *(byte *)((int)puVar24 + 2) =
                           (byte)((((int)(*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) * uVar21) >>
                                   8) - uVar21) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                  DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10);
                      iVar8 = DAT_00dca3f8;
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                    iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25);
                    pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                    if ((float)(uint)*pbVar19 != local_58) {
                      uVar21 = (uint)(byte)*puVar24;
                      *(byte *)puVar24 =
                           (byte)((((int)(*(byte *)(local_3c + (uint)*pbVar19 * 4) * uVar21) >> 8) -
                                  uVar21) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * iVar8 +
                                  uVar21 * 0x10000 >> 0x10);
                      uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)((((int)(*(byte *)(local_3c + 1 + (uint)*pbVar19 * 4) * uVar21) >>
                                   8) - uVar21) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                  DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10);
                      uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                      *(byte *)((int)puVar24 + 2) =
                           (byte)((((int)(*(byte *)(local_3c + 2 + (uint)*pbVar19 * 4) * uVar21) >>
                                   8) - uVar21) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                  DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10);
                      iVar8 = DAT_00dca3f8;
                    }
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  local_14 = (float)((int)local_14 + local_34);
                  puVar24 = puVar24 + 1;
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                local_14 = (float)((int)local_14 + local_28);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            }
          }
          else {
            switch(DAT_00dca3f4) {
            case 0:
switchD_0074c784_caseD_0:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            pbVar19 = (byte *)((&DAT_00f448d8)
                                               [(int)((int)local_14 +
                                                     ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                              ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                              >> 0x12) * 4);
                            *(byte *)puVar24 = *(byte *)(local_4c + *pbVar19);
                            *(byte *)((int)puVar24 + 1) = *(byte *)(local_48 + pbVar19[1]);
                            *(byte *)((int)puVar24 + 2) = *(byte *)(local_50 + pbVar19[2]);
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                           (puVar1 = (uint *)((&DAT_00f448d8)
                                              [(int)((int)local_14 +
                                                    ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                             ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) * 4), (float)*puVar1 != local_58)) {
                          *(byte *)puVar24 = *(byte *)(local_4c + (byte)*puVar1);
                          *(byte *)((int)puVar24 + 1) =
                               *(byte *)(local_48 + *(byte *)((int)puVar1 + 1));
                          *(byte *)((int)puVar24 + 2) =
                               *(byte *)(local_50 + *(byte *)((int)puVar1 + 2));
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          pbVar19 = (byte *)((&DAT_00f448d8)
                                             [(int)((int)local_14 +
                                                   ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                            ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                            >> 0x12) * 4);
                          *(byte *)puVar24 =
                               (byte)((local_4c[*pbVar19] - (uint)(byte)*puVar24) * (uint)pbVar19[3]
                                      + (uint)(byte)*puVar24 * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((local_48[pbVar19[1]] - (uint)*(byte *)((int)puVar24 + 1)) *
                                      (uint)pbVar19[3] + (uint)*(byte *)((int)puVar24 + 1) * 0x100
                                     >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)((local_50[pbVar19[2]] - (uint)*(byte *)((int)puVar24 + 2)) *
                                      (uint)pbVar19[3] + (uint)*(byte *)((int)puVar24 + 2) * 0x100
                                     >> 8);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        pbVar19 = (byte *)((&DAT_00f448d8)
                                           [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)
                                                 ) >> 0x12] +
                                          ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                          0x12) * 4);
                        if (pbVar19[3] != 0) {
                          if (pbVar19[3] == 0xff) {
                            *(byte *)puVar24 = *(byte *)(local_4c + *pbVar19);
                            *(byte *)((int)puVar24 + 1) = *(byte *)(local_48 + pbVar19[1]);
                            *(byte *)((int)puVar24 + 2) = *(byte *)(local_50 + pbVar19[2]);
                          }
                          else {
                            *(byte *)puVar24 =
                                 (byte)((local_4c[*pbVar19] - (uint)(byte)*puVar24) *
                                        (uint)pbVar19[3] + (uint)(byte)*puVar24 * 0x100 >> 8);
                            *(byte *)((int)puVar24 + 1) =
                                 (byte)((local_48[pbVar19[1]] - (uint)*(byte *)((int)puVar24 + 1)) *
                                        (uint)pbVar19[3] + (uint)*(byte *)((int)puVar24 + 1) * 0x100
                                       >> 8);
                            *(byte *)((int)puVar24 + 2) =
                                 (byte)((local_50[pbVar19[2]] - (uint)*(byte *)((int)puVar24 + 2)) *
                                        (uint)pbVar19[3] + (uint)*(byte *)((int)puVar24 + 2) * 0x100
                                       >> 8);
                          }
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      iVar8 = local_7c;
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          *local_54 = *(uint *)(((uint)fVar26 >> 0x10 & 0xfffffffc) +
                                               (&DAT_00f448d8)[(uint)local_14 >> 0x12]);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        local_54 = local_54 + 1;
                        iVar8 = iVar8 + -1;
                      } while (iVar8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      local_54 = (uint *)((int)local_54 + local_64);
                      local_10 = local_10 + -1;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    iVar8 = local_7c;
                    do {
                      if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                         (uVar21 = *(uint *)(((uint)fVar26 >> 0x10 & 0xfffffffc) +
                                            (&DAT_00f448d8)[(uint)local_14 >> 0x12]),
                         (float)uVar21 != local_58)) {
                        *local_54 = uVar21;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      local_54 = local_54 + 1;
                      iVar8 = iVar8 + -1;
                    } while (iVar8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    local_54 = (uint *)((int)local_54 + local_64);
                    local_10 = local_10 + -1;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (&DAT_00f448d8)
                                [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]
                                + iVar23 * 4;
                        *(byte *)puVar24 =
                             (byte)(((uint)*(byte *)((&DAT_00f448d8)
                                                     [(int)((int)local_14 +
                                                           ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                                      0x12] + iVar23 * 4) - (uint)(byte)*puVar24) *
                                    (uint)*(byte *)(iVar8 + 3) + (uint)(byte)*puVar24 * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)*(byte *)(iVar8 + 1) - (uint)*(byte *)((int)puVar24 + 1))
                                    * (uint)*(byte *)(iVar8 + 3) +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)*(byte *)(iVar8 + 2) - (uint)*(byte *)((int)puVar24 + 2))
                                    * (uint)*(byte *)(iVar8 + 3) +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      puVar1 = (uint *)((&DAT_00f448d8)
                                        [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU))
                                         >> 0x12] +
                                       ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                       0x12) * 4);
                      if (*(byte *)((int)puVar1 + 3) != 0) {
                        if (*(byte *)((int)puVar1 + 3) == 0xff) {
                          *puVar24 = *puVar1;
                        }
                        else {
                          *(byte *)puVar24 =
                               (byte)(((uint)(byte)*puVar1 - (uint)(byte)*puVar24) *
                                      (uint)*(byte *)((int)puVar1 + 3) +
                                      (uint)(byte)*puVar24 * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)*(byte *)((int)puVar1 + 1) -
                                      (uint)*(byte *)((int)puVar24 + 1)) *
                                      (uint)*(byte *)((int)puVar1 + 3) +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)*(byte *)((int)puVar1 + 2) -
                                      (uint)*(byte *)((int)puVar24 + 2)) *
                                      (uint)*(byte *)((int)puVar1 + 3) +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                        }
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                          pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                          *(byte *)puVar24 =
                               (byte)((local_4c[*pbVar19] - (uint)(byte)*puVar24) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                      (uint)(byte)*puVar24 * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((local_48[pbVar19[1]] - (uint)*(byte *)((int)puVar24 + 1)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)((local_50[pbVar19[2]] - (uint)*(byte *)((int)puVar24 + 2)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        puVar1 = (uint *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                        pbVar19 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                        if ((float)*puVar1 != local_58) {
                          *(byte *)puVar24 =
                               (byte)((local_4c[(byte)*puVar1] - (uint)(byte)*puVar24) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar19] +
                                      (uint)(byte)*puVar24 * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((local_48[*(byte *)((int)puVar1 + 1)] -
                                      (uint)*(byte *)((int)puVar24 + 1)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar19] +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)((local_50[*(byte *)((int)puVar1 + 2)] -
                                      (uint)*(byte *)((int)puVar24 + 2)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar19] +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                        *(byte *)puVar24 =
                             (byte)((local_4c[*pbVar19] - (uint)(byte)*puVar24) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] +
                                    (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((local_48[pbVar19[1]] - (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((local_50[pbVar19[2]] - (uint)*(byte *)((int)puVar24 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                      if (pbVar19[3] != 0) {
                        uVar21 = (uint)(byte)*puVar24;
                        if (pbVar19[3] == 0xff) {
                          *(byte *)puVar24 =
                               (byte)((local_4c[*pbVar19] - uVar21) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] + uVar21 * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((local_48[pbVar19[1]] - (uint)*(byte *)((int)puVar24 + 1)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)((local_50[pbVar19[2]] - (uint)*(byte *)((int)puVar24 + 2)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                        }
                        else {
                          *(byte *)puVar24 =
                               (byte)((local_4c[*pbVar19] - uVar21) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] +
                                      uVar21 * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((local_48[pbVar19[1]] - (uint)*(byte *)((int)puVar24 + 1)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)((local_50[pbVar19[2]] - (uint)*(byte *)((int)puVar24 + 2)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                        }
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (*(int *)(iVar23 + 0x2c) != 1) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                        pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                        *(byte *)puVar24 =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                    ((uint)*pbVar19 - (uint)(byte)*puVar24) +
                                    (uint)(byte)*puVar24 * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)pbVar19[1] - (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)pbVar19[2] - (uint)*(byte *)((int)puVar24 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      puVar1 = (uint *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                      pbVar19 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                      if ((float)*puVar1 != local_58) {
                        *(byte *)puVar24 =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                    ((uint)(byte)*puVar1 - (uint)(byte)*puVar24) +
                                    (uint)(byte)*puVar24 * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)*(byte *)((int)puVar1 + 1) -
                                    (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar19] +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)*(byte *)((int)puVar1 + 2) -
                                    (uint)*(byte *)((int)puVar24 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar19] +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 == 0) {
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                      *(byte *)puVar24 =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                  ((uint)*pbVar19 - (uint)(byte)*puVar24) * (uint)pbVar19[3] +
                                  (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)(((uint)pbVar19[1] - (uint)*(byte *)((int)puVar24 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] +
                                  (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                      *(byte *)((int)puVar24 + 2) =
                           (byte)(((uint)pbVar19[2] - (uint)*(byte *)((int)puVar24 + 2)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] +
                                  (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                    iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                    pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                    if (pbVar19[3] != 0) {
                      uVar21 = (uint)(byte)*puVar24;
                      if (pbVar19[3] == 0xff) {
                        *(byte *)puVar24 =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (*pbVar19 - uVar21) +
                                    uVar21 * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)pbVar19[1] - (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)pbVar19[2] - (uint)*(byte *)((int)puVar24 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                      }
                      else {
                        *(byte *)puVar24 =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (*pbVar19 - uVar21) *
                                    (uint)pbVar19[3] + uVar21 * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)pbVar19[1] - (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)pbVar19[2] - (uint)*(byte *)((int)puVar24 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                      }
                    }
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  local_14 = (float)((int)local_14 + local_34);
                  puVar24 = puVar24 + 1;
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                local_14 = (float)((int)local_14 + local_28);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            case 1:
              if (iVar8 == 0xff) goto switchD_0074c784_caseD_0;
              if (iVar8 != 0) {
                if (param_11 == 0) {
                  if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                    if (*(int *)(iVar23 + 0x2c) != 1) {
                      if (param_8 == 0) {
                        do {
                          do {
                            if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                              pbVar19 = (byte *)((&DAT_00f448d8)
                                                 [(int)((int)local_14 +
                                                       ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]
                                                + ((int)((int)fVar26 +
                                                        ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) *
                                                  4);
                              *(byte *)puVar24 =
                                   (byte)((local_4c[*pbVar19] - (uint)(byte)*puVar24) * DAT_00dca3f8
                                          + (uint)(byte)*puVar24 * 0x100 >> 8);
                              *(byte *)((int)puVar24 + 1) =
                                   (byte)((local_48[pbVar19[1]] - (uint)*(byte *)((int)puVar24 + 1))
                                          * DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 1) * 0x100
                                         >> 8);
                              *(byte *)((int)puVar24 + 2) =
                                   (byte)((local_50[pbVar19[2]] - (uint)*(byte *)((int)puVar24 + 2))
                                          * DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 2) * 0x100
                                         >> 8);
                            }
                            fVar26 = (float)((int)fVar26 + local_38);
                            local_14 = (float)((int)local_14 + local_34);
                            puVar24 = puVar24 + 1;
                            local_8 = local_8 + -1;
                          } while (local_8 != 0);
                          fVar26 = (float)((int)fVar26 + local_2c);
                          local_14 = (float)((int)local_14 + local_28);
                          puVar24 = (uint *)((int)puVar24 + local_64);
                          local_10 = local_10 + -1;
                          local_8 = local_7c;
                        } while (local_10 != 0);
                        return;
                      }
                      do {
                        do {
                          if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                             (puVar1 = (uint *)((&DAT_00f448d8)
                                                [(int)((int)local_14 +
                                                      ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                               ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)
                                                     ) >> 0x12) * 4), (float)*puVar1 != local_58)) {
                            *(byte *)puVar24 =
                                 (byte)((local_4c[(byte)*puVar1] - (uint)(byte)*puVar24) *
                                        DAT_00dca3f8 + (uint)(byte)*puVar24 * 0x100 >> 8);
                            *(byte *)((int)puVar24 + 1) =
                                 (byte)((local_48[*(byte *)((int)puVar1 + 1)] -
                                        (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                            *(byte *)((int)puVar24 + 2) =
                                 (byte)((local_50[*(byte *)((int)puVar1 + 2)] -
                                        (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            pbVar19 = (byte *)((&DAT_00f448d8)
                                               [(int)((int)local_14 +
                                                     ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                              ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                              >> 0x12) * 4);
                            *(byte *)puVar24 =
                                 (byte)((local_4c[*pbVar19] - (uint)(byte)*puVar24) *
                                        (uint)pbVar19[3] * DAT_00dca3f8 +
                                        (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                            *(byte *)((int)puVar24 + 1) =
                                 (byte)((local_48[pbVar19[1]] - (uint)*(byte *)((int)puVar24 + 1)) *
                                        (uint)pbVar19[3] * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                            *(byte *)((int)puVar24 + 2) =
                                 (byte)((local_50[pbVar19[2]] - (uint)*(byte *)((int)puVar24 + 2)) *
                                        (uint)pbVar19[3] * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          pbVar19 = (byte *)((&DAT_00f448d8)
                                             [(int)((int)local_14 +
                                                   ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                            ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                            >> 0x12) * 4);
                          if (pbVar19[3] != 0) {
                            uVar21 = (uint)(byte)*puVar24;
                            if (pbVar19[3] == 0xff) {
                              *(byte *)puVar24 =
                                   (byte)((local_4c[*pbVar19] - uVar21) * DAT_00dca3f8 +
                                          uVar21 * 0x100 >> 8);
                              *(byte *)((int)puVar24 + 1) =
                                   (byte)((local_48[pbVar19[1]] - (uint)*(byte *)((int)puVar24 + 1))
                                          * DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 1) * 0x100
                                         >> 8);
                              *(byte *)((int)puVar24 + 2) =
                                   (byte)((local_50[pbVar19[2]] - (uint)*(byte *)((int)puVar24 + 2))
                                          * DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 2) * 0x100
                                         >> 8);
                            }
                            else {
                              *(byte *)puVar24 =
                                   (byte)((local_4c[*pbVar19] - uVar21) * (uint)pbVar19[3] *
                                          DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10);
                              *(byte *)((int)puVar24 + 1) =
                                   (byte)((local_48[pbVar19[1]] - (uint)*(byte *)((int)puVar24 + 1))
                                          * (uint)pbVar19[3] * DAT_00dca3f8 +
                                          (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                              *(byte *)((int)puVar24 + 2) =
                                   (byte)((local_50[pbVar19[2]] - (uint)*(byte *)((int)puVar24 + 2))
                                          * (uint)pbVar19[3] * DAT_00dca3f8 +
                                          (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                            }
                          }
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                            iVar8 = (&DAT_00f448d8)
                                    [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                     0x12] + iVar23 * 4;
                            *(byte *)puVar24 =
                                 (byte)(((uint)*(byte *)((&DAT_00f448d8)
                                                         [(int)((int)local_14 +
                                                               ((int)local_14 >> 0x1f & 0x3ffffU))
                                                          >> 0x12] + iVar23 * 4) -
                                        (uint)(byte)*puVar24) * DAT_00dca3f8 +
                                        (uint)(byte)*puVar24 * 0x100 >> 8);
                            *(byte *)((int)puVar24 + 1) =
                                 (byte)(((uint)*(byte *)(iVar8 + 1) -
                                        (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                            *(byte *)((int)puVar24 + 2) =
                                 (byte)(((uint)*(byte *)(iVar8 + 2) -
                                        (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                           (puVar1 = (uint *)((&DAT_00f448d8)
                                              [(int)((int)local_14 +
                                                    ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                             ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) * 4), (float)*puVar1 != local_58)) {
                          *(byte *)puVar24 =
                               (byte)(((uint)(byte)*puVar1 - (uint)(byte)*puVar24) * DAT_00dca3f8 +
                                      (uint)(byte)*puVar24 * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)*(byte *)((int)puVar1 + 1) -
                                      (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)*(byte *)((int)puVar1 + 2) -
                                      (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          iVar8 = (&DAT_00f448d8)
                                  [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                  ] + iVar23 * 4;
                          *(byte *)puVar24 =
                               (byte)(((uint)*(byte *)((&DAT_00f448d8)
                                                       [(int)((int)local_14 +
                                                             ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                                        0x12] + iVar23 * 4) - (uint)(byte)*puVar24)
                                      * (uint)*(byte *)(iVar8 + 3) * DAT_00dca3f8 +
                                      (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)*(byte *)(iVar8 + 1) -
                                      (uint)*(byte *)((int)puVar24 + 1)) *
                                      (uint)*(byte *)(iVar8 + 3) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)*(byte *)(iVar8 + 2) -
                                      (uint)*(byte *)((int)puVar24 + 2)) *
                                      (uint)*(byte *)(iVar8 + 3) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        pbVar19 = (byte *)((&DAT_00f448d8)
                                           [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)
                                                 ) >> 0x12] +
                                          ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                          0x12) * 4);
                        if (pbVar19[3] != 0) {
                          uVar21 = (uint)(byte)*puVar24;
                          if (pbVar19[3] == 0xff) {
                            *(byte *)puVar24 =
                                 (byte)((*pbVar19 - uVar21) * DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                            *(byte *)((int)puVar24 + 1) =
                                 (byte)(((uint)pbVar19[1] - (uint)*(byte *)((int)puVar24 + 1)) *
                                        DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 1) * 0x100 >>
                                       8);
                            *(byte *)((int)puVar24 + 2) =
                                 (byte)(((uint)pbVar19[2] - (uint)*(byte *)((int)puVar24 + 2)) *
                                        DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 2) * 0x100 >>
                                       8);
                          }
                          else {
                            *(byte *)puVar24 =
                                 (byte)((*pbVar19 - uVar21) * (uint)pbVar19[3] * DAT_00dca3f8 +
                                        uVar21 * 0x10000 >> 0x10);
                            *(byte *)((int)puVar24 + 1) =
                                 (byte)(((uint)pbVar19[1] - (uint)*(byte *)((int)puVar24 + 1)) *
                                        (uint)pbVar19[3] * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                            *(byte *)((int)puVar24 + 2) =
                                 (byte)(((uint)pbVar19[2] - (uint)*(byte *)((int)puVar24 + 2)) *
                                        (uint)pbVar19[3] * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                          }
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                     0x12;
                            iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                            pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                            pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                            *(byte *)puVar24 =
                                 (byte)((local_4c[*pbVar19] - (uint)(byte)*puVar24) *
                                        (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * iVar8 +
                                        (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                            *(byte *)((int)puVar24 + 1) =
                                 (byte)((local_48[pbVar19[1]] - (uint)*(byte *)((int)puVar24 + 1)) *
                                        (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                            *(byte *)((int)puVar24 + 2) =
                                 (byte)((local_50[pbVar19[2]] - (uint)*(byte *)((int)puVar24 + 2)) *
                                        (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                            iVar8 = DAT_00dca3f8;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          puVar1 = (uint *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                          pbVar19 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                          if ((float)*puVar1 != local_58) {
                            *(byte *)puVar24 =
                                 (byte)((local_4c[(byte)*puVar1] - (uint)(byte)*puVar24) *
                                        (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * iVar8 +
                                        (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                            *(byte *)((int)puVar24 + 1) =
                                 (byte)((local_48[*(byte *)((int)puVar1 + 1)] -
                                        (uint)*(byte *)((int)puVar24 + 1)) *
                                        (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                            *(byte *)((int)puVar24 + 2) =
                                 (byte)((local_50[*(byte *)((int)puVar1 + 2)] -
                                        (uint)*(byte *)((int)puVar24 + 2)) *
                                        (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                            iVar8 = DAT_00dca3f8;
                          }
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                          pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                          *(byte *)puVar24 =
                               (byte)((local_4c[*pbVar19] - (uint)(byte)*puVar24) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                      iVar8 + (uint)(byte)*puVar24 * 0x1000000 >> 0x18);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((local_48[pbVar19[1]] - (uint)*(byte *)((int)puVar24 + 1)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                      DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 1) * 0x1000000
                                     >> 0x18);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)((local_50[pbVar19[2]] - (uint)*(byte *)((int)puVar24 + 2)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                      DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 2) * 0x1000000
                                     >> 0x18);
                          iVar8 = DAT_00dca3f8;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                        if (pbVar19[3] != 0) {
                          uVar21 = (uint)(byte)*puVar24;
                          if (pbVar19[3] == 0xff) {
                            *(byte *)puVar24 =
                                 (byte)((local_4c[*pbVar19] - uVar21) *
                                        (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * iVar8 +
                                        uVar21 * 0x10000 >> 0x10);
                            *(byte *)((int)puVar24 + 1) =
                                 (byte)((local_48[pbVar19[1]] - (uint)*(byte *)((int)puVar24 + 1)) *
                                        (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                            bVar13 = (byte)((local_50[pbVar19[2]] -
                                            (uint)*(byte *)((int)puVar24 + 2)) *
                                            (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                            (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                          }
                          else {
                            *(byte *)puVar24 =
                                 (byte)((local_4c[*pbVar19] - uVar21) *
                                        (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                        iVar8 + uVar21 * 0x1000000 >> 0x18);
                            *(byte *)((int)puVar24 + 1) =
                                 (byte)((local_48[pbVar19[1]] - (uint)*(byte *)((int)puVar24 + 1)) *
                                        (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                        DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 1) * 0x1000000
                                       >> 0x18);
                            bVar13 = (byte)((local_50[pbVar19[2]] -
                                            (uint)*(byte *)((int)puVar24 + 2)) *
                                            (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3]
                                            * DAT_00dca3f8 +
                                            (uint)*(byte *)((int)puVar24 + 2) * 0x1000000 >> 0x18);
                          }
                          *(byte *)((int)puVar24 + 2) = bVar13;
                          iVar8 = DAT_00dca3f8;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                          pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                          *(byte *)puVar24 =
                               (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                      ((uint)*pbVar19 - (uint)(byte)*puVar24) * DAT_00dca3f8 +
                                      (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)pbVar19[1] - (uint)*(byte *)((int)puVar24 + 1)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)pbVar19[2] - (uint)*(byte *)((int)puVar24 + 2)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        puVar1 = (uint *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                        pbVar19 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                        if ((float)*puVar1 != local_58) {
                          *(byte *)puVar24 =
                               (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                      ((uint)(byte)*puVar1 - (uint)(byte)*puVar24) * DAT_00dca3f8 +
                                      (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)*(byte *)((int)puVar1 + 1) -
                                      (uint)*(byte *)((int)puVar24 + 1)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)*(byte *)((int)puVar1 + 2) -
                                      (uint)*(byte *)((int)puVar24 + 2)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                        pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                        *(byte *)puVar24 =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                    ((uint)*pbVar19 - (uint)(byte)*puVar24) * (uint)pbVar19[3] *
                                    DAT_00dca3f8 + (uint)(byte)*puVar24 * 0x1000000 >> 0x18);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)pbVar19[1] - (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                    DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 1) * 0x1000000 >>
                                   0x18);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)pbVar19[2] - (uint)*(byte *)((int)puVar24 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                    DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 2) * 0x1000000 >>
                                   0x18);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                      if (pbVar19[3] != 0) {
                        uVar21 = (uint)(byte)*puVar24;
                        if (pbVar19[3] == 0xff) {
                          *(byte *)puVar24 =
                               (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (*pbVar19 - uVar21) *
                                      DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)pbVar19[1] - (uint)*(byte *)((int)puVar24 + 1)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)pbVar19[2] - (uint)*(byte *)((int)puVar24 + 2)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                        }
                        else {
                          *(byte *)puVar24 =
                               (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (*pbVar19 - uVar21) *
                                      (uint)pbVar19[3] * DAT_00dca3f8 + uVar21 * 0x1000000 >> 0x18);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)pbVar19[1] - (uint)*(byte *)((int)puVar24 + 1)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                      DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 1) * 0x1000000
                                     >> 0x18);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)pbVar19[2] - (uint)*(byte *)((int)puVar24 + 2)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                      DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 2) * 0x1000000
                                     >> 0x18);
                        }
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              break;
            case 2:
              if (iVar8 != 0) {
                if (param_11 == 0) {
                  if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                    if (*(int *)(iVar23 + 0x2c) != 1) {
                      uVar21 = (uint)local_14;
                      if (param_8 == 0) {
                        do {
                          do {
                            if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                              pbVar19 = (byte *)((&DAT_00f448d8)
                                                 [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU))
                                                  >> 0x12] +
                                                ((int)((int)fVar26 +
                                                      ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) * 4
                                                );
                              local_14._0_2_ =
                                   CONCAT11(*(undefined1 *)(local_18 + local_48[pbVar19[1]]),
                                            *(undefined1 *)(local_18 + local_4c[*pbVar19]));
                              local_14._0_3_ =
                                   CONCAT12(*(undefined1 *)(local_18 + local_50[pbVar19[2]]),
                                            (ushort)local_14);
                              local_14 = (float)(uint)(uint3)local_14;
                              uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                              uVar10 = uVar11 & 0x1010100;
                              *puVar24 = uVar10 - (uVar10 >> 8) |
                                         ((uint)local_14 | *puVar24) & 0x10100 | uVar11;
                            }
                            fVar26 = (float)((int)fVar26 + local_38);
                            uVar21 = uVar21 + local_34;
                            puVar24 = puVar24 + 1;
                            local_8 = local_8 + -1;
                          } while (local_8 != 0);
                          fVar26 = (float)((int)fVar26 + local_2c);
                          uVar21 = uVar21 + local_28;
                          puVar24 = (uint *)((int)puVar24 + local_64);
                          local_10 = local_10 + -1;
                          local_8 = local_7c;
                        } while (local_10 != 0);
                        return;
                      }
                      do {
                        do {
                          if ((((uint)fVar26 < uVar12) && (uVar21 < uVar9)) &&
                             (puVar1 = (uint *)((&DAT_00f448d8)
                                                [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >>
                                                 0x12] + ((int)((int)fVar26 +
                                                               ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                                         0x12) * 4), (float)*puVar1 != local_58)) {
                            local_14._0_2_ =
                                 CONCAT11(*(undefined1 *)
                                           (local_18 + local_48[*(byte *)((int)puVar1 + 1)]),
                                          *(undefined1 *)(local_18 + local_4c[(byte)*puVar1]));
                            local_14._0_3_ =
                                 CONCAT12(*(undefined1 *)
                                           (local_18 + local_50[*(byte *)((int)puVar1 + 2)]),
                                          (ushort)local_14);
                            local_14 = (float)(uint)(uint3)local_14;
                            uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                            uVar10 = uVar11 & 0x1010100;
                            *puVar24 = uVar10 - (uVar10 >> 8) |
                                       ((uint)local_14 | *puVar24) & 0x10100 | uVar11;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          uVar21 = uVar21 + local_34;
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        uVar21 = uVar21 + local_28;
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    uVar21 = (uint)local_14;
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                            pbVar19 = (byte *)((&DAT_00f448d8)
                                               [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >>
                                                0x12] + ((int)((int)fVar26 +
                                                              ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                                        0x12) * 4);
                            uVar11 = (uint)pbVar19[3];
                            local_14._0_2_ =
                                 CONCAT11((char)(local_48[pbVar19[1]] * uVar11 * DAT_00dca3f8 >>
                                                0x10),
                                          (char)(local_4c[*pbVar19] * uVar11 * DAT_00dca3f8 >> 0x10)
                                         );
                            local_14._0_3_ =
                                 CONCAT12((char)(local_50[pbVar19[2]] * uVar11 * DAT_00dca3f8 >>
                                                0x10),(ushort)local_14);
                            local_14 = (float)(uint)(uint3)local_14;
                            uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                            uVar10 = uVar11 & 0x1010100;
                            *puVar24 = uVar10 - (uVar10 >> 8) |
                                       ((uint)local_14 | *puVar24) & 0x10100 | uVar11;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          uVar21 = uVar21 + local_34;
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        uVar21 = uVar21 + local_28;
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                          pbVar19 = (byte *)((&DAT_00f448d8)
                                             [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >>
                                              0x12] + ((int)((int)fVar26 +
                                                            ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                                      0x12) * 4);
                          bVar13 = pbVar19[3];
                          if (bVar13 != 0) {
                            if (bVar13 == 0xff) {
                              local_14._0_2_ =
                                   CONCAT11(*(undefined1 *)(local_18 + local_48[pbVar19[1]]),
                                            *(undefined1 *)(local_18 + local_4c[*pbVar19]));
                              local_14._0_3_ =
                                   CONCAT12(*(undefined1 *)(local_18 + local_50[pbVar19[2]]),
                                            (ushort)local_14);
                            }
                            else {
                              uVar11 = (uint)bVar13;
                              local_14._0_2_ =
                                   CONCAT11((char)(local_48[pbVar19[1]] * uVar11 * DAT_00dca3f8 >>
                                                  0x10),
                                            (char)(local_4c[*pbVar19] * uVar11 * DAT_00dca3f8 >>
                                                  0x10));
                              local_14._0_3_ =
                                   CONCAT12((char)(local_50[pbVar19[2]] * uVar11 * DAT_00dca3f8 >>
                                                  0x10),(ushort)local_14);
                            }
                            local_14 = (float)(uint)(uint3)local_14;
                            uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                            uVar10 = uVar11 & 0x1010100;
                            *puVar24 = uVar10 - (uVar10 >> 8) |
                                       ((uint)local_14 | *puVar24) & 0x10100 | uVar11;
                          }
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        uVar21 = uVar21 + local_34;
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      uVar21 = uVar21 + local_28;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    uVar21 = (uint)local_14;
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                            iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                            iVar8 = (&DAT_00f448d8)
                                    [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                    iVar23 * 4;
                            local_14._0_2_ =
                                 CONCAT11(*(undefined1 *)(local_18 + *(byte *)(iVar8 + 1)),
                                          *(undefined1 *)
                                           (local_18 +
                                           *(byte *)((&DAT_00f448d8)
                                                     [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU
                                                                     )) >> 0x12] + iVar23 * 4)));
                            local_14 = (float)(uint)CONCAT12(*(undefined1 *)
                                                              (local_18 + *(byte *)(iVar8 + 2)),
                                                             (ushort)local_14);
                            uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                            uVar10 = uVar11 & 0x1010100;
                            *puVar24 = uVar10 - (uVar10 >> 8) |
                                       ((uint)local_14 | *puVar24) & 0x10100 | uVar11;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          uVar21 = uVar21 + local_34;
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        uVar21 = uVar21 + local_28;
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if ((((uint)fVar26 < uVar12) && (uVar21 < uVar9)) &&
                           (puVar1 = (uint *)((&DAT_00f448d8)
                                              [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >>
                                               0x12] + ((int)((int)fVar26 +
                                                             ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                                       0x12) * 4), (float)*puVar1 != local_58)) {
                          local_14._0_2_ =
                               CONCAT11(*(undefined1 *)(local_18 + *(byte *)((int)puVar1 + 1)),
                                        *(undefined1 *)(local_18 + (byte)*puVar1));
                          local_14 = (float)(uint)CONCAT12(*(undefined1 *)
                                                            (local_18 + *(byte *)((int)puVar1 + 2)),
                                                           (ushort)local_14);
                          uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                          uVar10 = uVar11 & 0x1010100;
                          *puVar24 = uVar10 - (uVar10 >> 8) | ((uint)local_14 | *puVar24) & 0x10100
                                     | uVar11;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        uVar21 = uVar21 + local_34;
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      uVar21 = uVar21 + local_28;
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  uVar21 = (uint)local_14;
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                          iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          iVar8 = (&DAT_00f448d8)
                                  [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                  iVar23 * 4;
                          uVar11 = (uint)*(byte *)(iVar8 + 3);
                          local_14._0_2_ =
                               CONCAT11((char)(*(byte *)(iVar8 + 1) * uVar11 * DAT_00dca3f8 >> 0x10)
                                        ,(char)(*(byte *)((&DAT_00f448d8)
                                                          [(int)(uVar21 + ((int)uVar21 >> 0x1f &
                                                                          0x3ffffU)) >> 0x12] +
                                                         iVar23 * 4) * uVar11 * DAT_00dca3f8 >> 0x10
                                               ));
                          local_14 = (float)(uint)CONCAT12((char)(*(byte *)(iVar8 + 2) * uVar11 *
                                                                  DAT_00dca3f8 >> 0x10),
                                                           (ushort)local_14);
                          uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                          uVar10 = uVar11 & 0x1010100;
                          *puVar24 = uVar10 - (uVar10 >> 8) | ((uint)local_14 | *puVar24) & 0x10100
                                     | uVar11;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        uVar21 = uVar21 + local_34;
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      uVar21 = uVar21 + local_28;
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                        pbVar19 = (byte *)((&DAT_00f448d8)
                                           [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12
                                           ] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)
                                                     ) >> 0x12) * 4);
                        bVar13 = pbVar19[3];
                        if (bVar13 != 0) {
                          if (bVar13 == 0xff) {
                            uVar14 = *(undefined1 *)(local_18 + pbVar19[1]);
                            local_14._0_2_ = (ushort)*(byte *)(local_18 + *pbVar19);
                            local_14._0_3_ =
                                 CONCAT12(*(undefined1 *)(local_18 + pbVar19[2]),(ushort)local_14);
                          }
                          else {
                            uVar11 = (uint)bVar13;
                            uVar14 = (undefined1)(pbVar19[1] * uVar11 * DAT_00dca3f8 >> 0x10);
                            local_14._0_2_ =
                                 (ushort)(byte)(*pbVar19 * uVar11 * DAT_00dca3f8 >> 0x10);
                            local_14._0_3_ =
                                 CONCAT12((char)(pbVar19[2] * uVar11 * DAT_00dca3f8 >> 0x10),
                                          (ushort)local_14);
                          }
                          uVar6 = (uint3)local_14 >> 0x10;
                          local_14._0_2_ = CONCAT11(uVar14,(undefined1)local_14);
                          local_14 = (float)(uint)CONCAT12((char)uVar6,(ushort)local_14);
                          uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                          uVar10 = uVar11 & 0x1010100;
                          *puVar24 = uVar10 - (uVar10 >> 8) | ((uint)local_14 | *puVar24) & 0x10100
                                     | uVar11;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      uVar21 = uVar21 + local_34;
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    uVar21 = uVar21 + local_28;
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    uVar21 = (uint)local_14;
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                            iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                            iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                            pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                            uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                                 [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                            local_14._0_2_ =
                                 CONCAT11((char)(local_48[pbVar19[1]] * uVar11 * iVar8 >> 0x10),
                                          (char)(local_4c[*pbVar19] * uVar11 * iVar8 >> 0x10));
                            local_14._0_3_ =
                                 CONCAT12((char)(local_50[pbVar19[2]] * uVar11 * iVar8 >> 0x10),
                                          (ushort)local_14);
                            local_14 = (float)(uint)(uint3)local_14;
                            uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                            uVar10 = uVar11 & 0x1010100;
                            *puVar24 = uVar10 - (uVar10 >> 8) |
                                       ((uint)local_14 | *puVar24) & 0x10100 | uVar11;
                            iVar8 = DAT_00dca3f8;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          uVar21 = uVar21 + local_34;
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        uVar21 = uVar21 + local_28;
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                          iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          puVar1 = (uint *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                          if ((float)*puVar1 != local_58) {
                            uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                                 [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                            local_14._0_2_ =
                                 CONCAT11((char)(local_48[*(byte *)((int)puVar1 + 1)] * uVar11 *
                                                 iVar8 >> 0x10),
                                          (char)(local_4c[(byte)*puVar1] * uVar11 * iVar8 >> 0x10));
                            local_14._0_3_ =
                                 CONCAT12((char)(local_50[*(byte *)((int)puVar1 + 2)] * uVar11 *
                                                 iVar8 >> 0x10),(ushort)local_14);
                            local_14 = (float)(uint)(uint3)local_14;
                            uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                            uVar10 = uVar11 & 0x1010100;
                            *puVar24 = uVar10 - (uVar10 >> 8) |
                                       ((uint)local_14 | *puVar24) & 0x10100 | uVar11;
                            iVar8 = DAT_00dca3f8;
                          }
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        uVar21 = uVar21 + local_34;
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      uVar21 = uVar21 + local_28;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  uVar21 = (uint)local_14;
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                          iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                          uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          uVar10 = (uint)pbVar19[3];
                          local_14._0_2_ =
                               CONCAT11((char)(local_48[pbVar19[1]] * uVar11 * uVar10 * iVar8 >>
                                              0x18),
                                        (char)(local_4c[*pbVar19] * uVar11 * uVar10 * iVar8 >> 0x18)
                                       );
                          local_14._0_3_ =
                               CONCAT12((char)(local_50[pbVar19[2]] * uVar11 * uVar10 * iVar8 >>
                                              0x18),(ushort)local_14);
                          local_14 = (float)(uint)(uint3)local_14;
                          uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                          uVar10 = uVar11 & 0x1010100;
                          *puVar24 = uVar10 - (uVar10 >> 8) | ((uint)local_14 | *puVar24) & 0x10100
                                     | uVar11;
                          iVar8 = DAT_00dca3f8;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        uVar21 = uVar21 + local_34;
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      uVar21 = uVar21 + local_28;
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                        iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        bVar13 = pbVar19[3];
                        if (bVar13 != 0) {
                          bVar3 = *(byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                          if (bVar13 == 0xff) {
                            uVar11 = (uint)(byte)(&DAT_00dca2e0)[bVar3];
                            local_14._0_2_ =
                                 CONCAT11((char)(local_48[pbVar19[1]] * uVar11 * iVar8 >> 0x10),
                                          (char)(local_4c[*pbVar19] * uVar11 * iVar8 >> 0x10));
                            uVar14 = (undefined1)(local_50[pbVar19[2]] * uVar11 * iVar8 >> 0x10);
                          }
                          else {
                            uVar10 = (uint)(byte)(&DAT_00dca2e0)[bVar3];
                            uVar11 = (uint)bVar13;
                            local_14._0_2_ =
                                 CONCAT11((char)(local_48[pbVar19[1]] * uVar10 * uVar11 * iVar8 >>
                                                0x18),
                                          (char)(local_4c[*pbVar19] * uVar10 * uVar11 * iVar8 >>
                                                0x18));
                            uVar14 = (undefined1)
                                     (local_50[pbVar19[2]] * uVar10 * uVar11 * iVar8 >> 0x18);
                          }
                          local_14._0_3_ = CONCAT12(uVar14,(ushort)local_14);
                          local_14 = (float)(uint)(uint3)local_14;
                          uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                          uVar10 = uVar11 & 0x1010100;
                          *puVar24 = uVar10 - (uVar10 >> 8) | ((uint)local_14 | *puVar24) & 0x10100
                                     | uVar11;
                          iVar8 = DAT_00dca3f8;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      uVar21 = uVar21 + local_34;
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    uVar21 = uVar21 + local_28;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  uVar21 = (uint)local_14;
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                          iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                          uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          local_14._0_2_ =
                               CONCAT11((char)(pbVar19[1] * uVar11 * iVar8 >> 0x10),
                                        (char)(*pbVar19 * uVar11 * iVar8 >> 0x10));
                          local_14._0_3_ =
                               CONCAT12((char)(pbVar19[2] * uVar11 * iVar8 >> 0x10),(ushort)local_14
                                       );
                          local_14 = (float)(uint)(uint3)local_14;
                          uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                          uVar10 = uVar11 & 0x1010100;
                          *puVar24 = uVar10 - (uVar10 >> 8) | ((uint)local_14 | *puVar24) & 0x10100
                                     | uVar11;
                          iVar8 = DAT_00dca3f8;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        uVar21 = uVar21 + local_34;
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      uVar21 = uVar21 + local_28;
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                        iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        puVar1 = (uint *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        if ((float)*puVar1 != local_58) {
                          uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          local_14._0_2_ =
                               CONCAT11((char)(*(byte *)((int)puVar1 + 1) * uVar11 * iVar8 >> 0x10),
                                        (char)((byte)*puVar1 * uVar11 * iVar8 >> 0x10));
                          local_14._0_3_ =
                               CONCAT12((char)(*(byte *)((int)puVar1 + 2) * uVar11 * iVar8 >> 0x10),
                                        (ushort)local_14);
                          local_14 = (float)(uint)(uint3)local_14;
                          uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                          uVar10 = uVar11 & 0x1010100;
                          *puVar24 = uVar10 - (uVar10 >> 8) | ((uint)local_14 | *puVar24) & 0x10100
                                     | uVar11;
                          iVar8 = DAT_00dca3f8;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      uVar21 = uVar21 + local_34;
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    uVar21 = uVar21 + local_28;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                uVar21 = (uint)local_14;
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                        iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        iVar23 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)] *
                                 (uint)pbVar19[3];
                        local_14._0_2_ =
                             CONCAT11((char)((uint)pbVar19[1] * iVar23 * iVar8 >> 0x18),
                                      (char)((uint)*pbVar19 * iVar23 * iVar8 >> 0x18));
                        local_14._0_3_ =
                             CONCAT12((char)((uint)pbVar19[2] * iVar23 * iVar8 >> 0x18),
                                      (ushort)local_14);
                        local_14 = (float)(uint)(uint3)local_14;
                        uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                        uVar10 = uVar11 & 0x1010100;
                        *puVar24 = uVar10 - (uVar10 >> 8) | ((uint)local_14 | *puVar24) & 0x10100 |
                                   uVar11;
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      uVar21 = uVar21 + local_34;
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    uVar21 = uVar21 + local_28;
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                      iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)(((int)fVar26 >> 0x1f & 0x3ffffU) + (int)fVar26) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                      bVar13 = pbVar19[3];
                      if (bVar13 != 0) {
                        uVar11 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        if (bVar13 == 0xff) {
                          local_14._0_2_ =
                               CONCAT11((char)(pbVar19[1] * uVar11 * iVar8 >> 0x10),
                                        (char)(*pbVar19 * uVar11 * iVar8 >> 0x10));
                          uVar14 = (undefined1)(pbVar19[2] * uVar11 * iVar8 >> 0x10);
                        }
                        else {
                          iVar23 = uVar11 * bVar13;
                          local_14._0_2_ =
                               CONCAT11((char)((uint)pbVar19[1] * iVar23 * iVar8 >> 0x18),
                                        (char)((uint)*pbVar19 * iVar23 * iVar8 >> 0x18));
                          uVar14 = (undefined1)((uint)pbVar19[2] * iVar23 * iVar8 >> 0x18);
                        }
                        local_14._0_3_ = CONCAT12(uVar14,(ushort)local_14);
                        local_14 = (float)(uint)(uint3)local_14;
                        uVar11 = ((uint)local_14 & 0xfefeff) + (*puVar24 & 0xfefeff);
                        uVar10 = uVar11 & 0x1010100;
                        *puVar24 = uVar10 - (uVar10 >> 8) | ((uint)local_14 | *puVar24) & 0x10100 |
                                   uVar11;
                        iVar8 = DAT_00dca3f8;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    uVar21 = uVar21 + local_34;
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  uVar21 = uVar21 + local_28;
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              break;
            case 3:
              if (iVar8 != 0) {
                if (param_11 == 0) {
                  if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                    if (*(int *)(iVar23 + 0x2c) != 1) {
                      uVar21 = (uint)local_14;
                      if (param_8 == 0) {
                        do {
                          do {
                            uVar11 = (uint)local_14;
                            if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                              pbVar19 = (byte *)((&DAT_00f448d8)
                                                 [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU))
                                                  >> 0x12] +
                                                ((int)((int)fVar26 +
                                                      ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12) * 4
                                                );
                              local_14._0_2_ =
                                   CONCAT11(*(undefined1 *)(local_18 + local_48[pbVar19[1]]),
                                            *(undefined1 *)(local_18 + local_4c[*pbVar19]));
                              local_14._3_1_ = SUB41(uVar11,3);
                              local_14._0_3_ =
                                   CONCAT12(*(undefined1 *)(local_18 + local_50[pbVar19[2]]),
                                            (ushort)local_14);
                              uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                              uVar11 = uVar10 & 0x1010100;
                              *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                            }
                            fVar26 = (float)((int)fVar26 + local_38);
                            uVar21 = uVar21 + local_34;
                            puVar24 = puVar24 + 1;
                            local_8 = local_8 + -1;
                          } while (local_8 != 0);
                          fVar26 = (float)((int)fVar26 + local_2c);
                          uVar21 = uVar21 + local_28;
                          puVar24 = (uint *)((int)puVar24 + local_64);
                          local_10 = local_10 + -1;
                          local_8 = local_7c;
                        } while (local_10 != 0);
                        return;
                      }
                      do {
                        do {
                          uVar11 = (uint)local_14;
                          if ((((uint)fVar26 < uVar12) && (uVar21 < uVar9)) &&
                             (puVar1 = (uint *)((&DAT_00f448d8)
                                                [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >>
                                                 0x12] + ((int)((int)fVar26 +
                                                               ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                                         0x12) * 4), (float)*puVar1 != local_58)) {
                            local_14._0_2_ =
                                 CONCAT11(*(undefined1 *)
                                           (local_18 + local_48[*(byte *)((int)puVar1 + 1)]),
                                          *(undefined1 *)(local_18 + local_4c[(byte)*puVar1]));
                            local_14._3_1_ = SUB41(uVar11,3);
                            local_14._0_3_ =
                                 CONCAT12(*(undefined1 *)
                                           (local_18 + local_50[*(byte *)((int)puVar1 + 2)]),
                                          (ushort)local_14);
                            uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                            uVar11 = uVar10 & 0x1010100;
                            *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          uVar21 = uVar21 + local_34;
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        uVar21 = uVar21 + local_28;
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    uVar21 = (uint)local_14;
                    if (param_8 == 0) {
                      do {
                        do {
                          uVar11 = (uint)local_14;
                          if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                            pbVar19 = (byte *)((&DAT_00f448d8)
                                               [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >>
                                                0x12] + ((int)((int)fVar26 +
                                                              ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                                        0x12) * 4);
                            uVar10 = (uint)pbVar19[3];
                            local_14._0_2_ =
                                 CONCAT11((char)(local_48[pbVar19[1]] * uVar10 * DAT_00dca3f8 >>
                                                0x10),
                                          (char)(local_4c[*pbVar19] * uVar10 * DAT_00dca3f8 >> 0x10)
                                         );
                            local_14._3_1_ = SUB41(uVar11,3);
                            local_14._0_3_ =
                                 CONCAT12((char)(local_50[pbVar19[2]] * uVar10 * DAT_00dca3f8 >>
                                                0x10),(ushort)local_14);
                            uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                            uVar11 = uVar10 & 0x1010100;
                            *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          uVar21 = uVar21 + local_34;
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        uVar21 = uVar21 + local_28;
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                          pbVar19 = (byte *)((&DAT_00f448d8)
                                             [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >>
                                              0x12] + ((int)((int)fVar26 +
                                                            ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                                      0x12) * 4);
                          bVar13 = pbVar19[3];
                          if (bVar13 != 0) {
                            if (bVar13 == 0xff) {
                              local_14._0_2_ =
                                   CONCAT11(*(undefined1 *)(local_18 + local_48[pbVar19[1]]),
                                            *(undefined1 *)(local_18 + local_4c[*pbVar19]));
                              local_14._0_3_ =
                                   CONCAT12(*(undefined1 *)(local_18 + local_50[pbVar19[2]]),
                                            (ushort)local_14);
                            }
                            else {
                              uVar11 = (uint)bVar13;
                              local_14._0_2_ =
                                   CONCAT11((char)(local_48[pbVar19[1]] * uVar11 * DAT_00dca3f8 >>
                                                  0x10),
                                            (char)(local_4c[*pbVar19] * uVar11 * DAT_00dca3f8 >>
                                                  0x10));
                              local_14._0_3_ =
                                   CONCAT12((char)(local_50[pbVar19[2]] * uVar11 * DAT_00dca3f8 >>
                                                  0x10),(ushort)local_14);
                            }
                            uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                            uVar11 = uVar10 & 0x1010100;
                            *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                          }
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        uVar21 = uVar21 + local_34;
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      uVar21 = uVar21 + local_28;
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    uVar21 = (uint)local_14;
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                            iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                            iVar8 = (&DAT_00f448d8)
                                    [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                    iVar23 * 4;
                            local_14._0_2_ =
                                 CONCAT11(*(undefined1 *)(local_18 + *(byte *)(iVar8 + 1)),
                                          *(undefined1 *)
                                           (local_18 +
                                           *(byte *)((&DAT_00f448d8)
                                                     [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU
                                                                     )) >> 0x12] + iVar23 * 4)));
                            local_14 = (float)CONCAT22(CONCAT11(local_14._3_1_,
                                                                *(undefined1 *)
                                                                 (local_18 + *(byte *)(iVar8 + 2))),
                                                       (ushort)local_14);
                            uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                            uVar11 = uVar10 & 0x1010100;
                            *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          uVar21 = uVar21 + local_34;
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        uVar21 = uVar21 + local_28;
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if ((((uint)fVar26 < uVar12) && (uVar21 < uVar9)) &&
                           (puVar1 = (uint *)((&DAT_00f448d8)
                                              [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >>
                                               0x12] + ((int)((int)fVar26 +
                                                             ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                                       0x12) * 4), (float)*puVar1 != local_58)) {
                          local_14._0_2_ =
                               CONCAT11(*(undefined1 *)(local_18 + *(byte *)((int)puVar1 + 1)),
                                        *(undefined1 *)(local_18 + (byte)*puVar1));
                          local_14 = (float)CONCAT22(CONCAT11(local_14._3_1_,
                                                              *(undefined1 *)
                                                               (local_18 +
                                                               *(byte *)((int)puVar1 + 2))),
                                                     (ushort)local_14);
                          uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                          uVar11 = uVar10 & 0x1010100;
                          *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        uVar21 = uVar21 + local_34;
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      uVar21 = uVar21 + local_28;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  uVar21 = (uint)local_14;
                  if (param_8 == 0) {
                    do {
                      do {
                        uVar11 = (uint)local_14;
                        if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                          iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          iVar8 = (&DAT_00f448d8)
                                  [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                  iVar23 * 4;
                          uVar10 = (uint)*(byte *)(iVar8 + 3);
                          local_14._0_2_ =
                               CONCAT11((char)(*(byte *)(iVar8 + 1) * uVar10 * DAT_00dca3f8 >> 0x10)
                                        ,(char)(*(byte *)((&DAT_00f448d8)
                                                          [(int)(uVar21 + ((int)uVar21 >> 0x1f &
                                                                          0x3ffffU)) >> 0x12] +
                                                         iVar23 * 4) * uVar10 * DAT_00dca3f8 >> 0x10
                                               ));
                          local_14._3_1_ = SUB41(uVar11,3);
                          local_14._0_3_ =
                               CONCAT12((char)(*(byte *)(iVar8 + 2) * uVar10 * DAT_00dca3f8 >> 0x10)
                                        ,(ushort)local_14);
                          uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                          uVar11 = uVar10 & 0x1010100;
                          *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        uVar21 = uVar21 + local_34;
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      uVar21 = uVar21 + local_28;
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                        pbVar19 = (byte *)((&DAT_00f448d8)
                                           [(int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12
                                           ] + ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)
                                                     ) >> 0x12) * 4);
                        bVar13 = pbVar19[3];
                        if (bVar13 != 0) {
                          if (bVar13 == 0xff) {
                            uVar14 = *(undefined1 *)(local_18 + pbVar19[1]);
                            local_14._0_2_ = (ushort)*(byte *)(local_18 + *pbVar19);
                            local_14._0_3_ =
                                 CONCAT12(*(undefined1 *)(local_18 + pbVar19[2]),(ushort)local_14);
                            uVar6 = (uint3)local_14;
                          }
                          else {
                            uVar11 = (uint)bVar13;
                            uVar14 = (undefined1)(pbVar19[1] * uVar11 * DAT_00dca3f8 >> 0x10);
                            local_14._0_3_ =
                                 CONCAT12((char)(pbVar19[2] * uVar11 * DAT_00dca3f8 >> 0x10),
                                          (short)(*pbVar19 * uVar11 * DAT_00dca3f8 >> 0x10)) &
                                 0xff00ff;
                            uVar6 = (uint3)local_14;
                          }
                          local_14 = (float)CONCAT13(local_14._3_1_,uVar6);
                          local_14._0_1_ = (undefined1)uVar6;
                          local_14._0_2_ = CONCAT11(uVar14,(undefined1)local_14);
                          uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                          uVar11 = uVar10 & 0x1010100;
                          *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      uVar21 = uVar21 + local_34;
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    uVar21 = uVar21 + local_28;
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    uVar21 = (uint)local_14;
                    if (param_8 == 0) {
                      do {
                        do {
                          uVar11 = (uint)local_14;
                          if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                            iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                            iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                            pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                            uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                                 [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                            local_14._0_2_ =
                                 CONCAT11((char)(local_48[pbVar19[1]] * uVar10 * iVar8 >> 0x10),
                                          (char)(local_4c[*pbVar19] * uVar10 * iVar8 >> 0x10));
                            local_14._3_1_ = SUB41(uVar11,3);
                            local_14._0_3_ =
                                 CONCAT12((char)(local_50[pbVar19[2]] * uVar10 * iVar8 >> 0x10),
                                          (ushort)local_14);
                            uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                            uVar11 = uVar10 & 0x1010100;
                            *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                            iVar8 = DAT_00dca3f8;
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          uVar21 = uVar21 + local_34;
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        uVar21 = uVar21 + local_28;
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        uVar11 = (uint)local_14;
                        if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                          iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          puVar1 = (uint *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                          if ((float)*puVar1 != local_58) {
                            uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                                 [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                            local_14._0_2_ =
                                 CONCAT11((char)(local_48[*(byte *)((int)puVar1 + 1)] * uVar10 *
                                                 iVar8 >> 0x10),
                                          (char)(local_4c[(byte)*puVar1] * uVar10 * iVar8 >> 0x10));
                            local_14._3_1_ = SUB41(uVar11,3);
                            local_14._0_3_ =
                                 CONCAT12((char)(local_50[*(byte *)((int)puVar1 + 2)] * uVar10 *
                                                 iVar8 >> 0x10),(ushort)local_14);
                            uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                            uVar11 = uVar10 & 0x1010100;
                            *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                            iVar8 = DAT_00dca3f8;
                          }
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        uVar21 = uVar21 + local_34;
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      uVar21 = uVar21 + local_28;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  uVar21 = (uint)local_14;
                  if (param_8 == 0) {
                    do {
                      do {
                        uVar11 = (uint)local_14;
                        if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                          iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                          uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          uVar18 = (uint)pbVar19[3];
                          local_14._0_2_ =
                               CONCAT11((char)(local_48[pbVar19[1]] * uVar10 * uVar18 * iVar8 >>
                                              0x18),
                                        (char)(local_4c[*pbVar19] * uVar10 * uVar18 * iVar8 >> 0x18)
                                       );
                          local_14._3_1_ = SUB41(uVar11,3);
                          local_14._0_3_ =
                               CONCAT12((char)(local_50[pbVar19[2]] * uVar10 * uVar18 * iVar8 >>
                                              0x18),(ushort)local_14);
                          uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                          uVar11 = uVar10 & 0x1010100;
                          *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                          iVar8 = DAT_00dca3f8;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        uVar21 = uVar21 + local_34;
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      uVar21 = uVar21 + local_28;
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      uVar11 = (uint)local_14;
                      if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                        iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        bVar13 = pbVar19[3];
                        if (bVar13 != 0) {
                          bVar3 = *(byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                          if (bVar13 == 0xff) {
                            uVar10 = (uint)(byte)(&DAT_00dca2e0)[bVar3];
                            local_14._0_2_ =
                                 CONCAT11((char)(local_48[pbVar19[1]] * uVar10 * iVar8 >> 0x10),
                                          (char)(local_4c[*pbVar19] * uVar10 * iVar8 >> 0x10));
                            uVar14 = (undefined1)(local_50[pbVar19[2]] * uVar10 * iVar8 >> 0x10);
                          }
                          else {
                            uVar18 = (uint)(byte)(&DAT_00dca2e0)[bVar3];
                            uVar10 = (uint)bVar13;
                            local_14._0_2_ =
                                 CONCAT11((char)(local_48[pbVar19[1]] * uVar18 * uVar10 * iVar8 >>
                                                0x18),
                                          (char)(local_4c[*pbVar19] * uVar18 * uVar10 * iVar8 >>
                                                0x18));
                            uVar14 = (undefined1)
                                     (local_50[pbVar19[2]] * uVar18 * uVar10 * iVar8 >> 0x18);
                          }
                          local_14._3_1_ = SUB41(uVar11,3);
                          local_14._0_3_ = CONCAT12(uVar14,(ushort)local_14);
                          uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                          uVar11 = uVar10 & 0x1010100;
                          *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                          iVar8 = DAT_00dca3f8;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      uVar21 = uVar21 + local_34;
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    uVar21 = uVar21 + local_28;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  uVar21 = (uint)local_14;
                  if (param_8 == 0) {
                    do {
                      do {
                        uVar11 = (uint)local_14;
                        if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                          iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                          uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          local_14._0_2_ =
                               CONCAT11((char)(pbVar19[1] * uVar10 * iVar8 >> 0x10),
                                        (char)(*pbVar19 * uVar10 * iVar8 >> 0x10));
                          local_14._3_1_ = SUB41(uVar11,3);
                          local_14._0_3_ =
                               CONCAT12((char)(pbVar19[2] * uVar10 * iVar8 >> 0x10),(ushort)local_14
                                       );
                          uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                          uVar11 = uVar10 & 0x1010100;
                          *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                          iVar8 = DAT_00dca3f8;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        uVar21 = uVar21 + local_34;
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      uVar21 = uVar21 + local_28;
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      uVar11 = (uint)local_14;
                      if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                        iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        puVar1 = (uint *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        if ((float)*puVar1 != local_58) {
                          uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                               [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                          local_14._0_2_ =
                               CONCAT11((char)(*(byte *)((int)puVar1 + 1) * uVar10 * iVar8 >> 0x10),
                                        (char)((byte)*puVar1 * uVar10 * iVar8 >> 0x10));
                          local_14._3_1_ = SUB41(uVar11,3);
                          local_14._0_3_ =
                               CONCAT12((char)(*(byte *)((int)puVar1 + 2) * uVar10 * iVar8 >> 0x10),
                                        (ushort)local_14);
                          uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                          uVar11 = uVar10 & 0x1010100;
                          *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                          iVar8 = DAT_00dca3f8;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      uVar21 = uVar21 + local_34;
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    uVar21 = uVar21 + local_28;
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                uVar21 = (uint)local_14;
                if (param_8 == 0) {
                  do {
                    do {
                      uVar11 = (uint)local_14;
                      if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                        iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        iVar23 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)] *
                                 (uint)pbVar19[3];
                        local_14._0_2_ =
                             CONCAT11((char)((uint)pbVar19[1] * iVar23 * iVar8 >> 0x18),
                                      (char)((uint)*pbVar19 * iVar23 * iVar8 >> 0x18));
                        local_14._3_1_ = SUB41(uVar11,3);
                        local_14._0_3_ =
                             CONCAT12((char)((uint)pbVar19[2] * iVar23 * iVar8 >> 0x18),
                                      (ushort)local_14);
                        uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                        uVar11 = uVar10 & 0x1010100;
                        *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      uVar21 = uVar21 + local_34;
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    uVar21 = uVar21 + local_28;
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    uVar11 = (uint)local_14;
                    if (((uint)fVar26 < uVar12) && (uVar21 < uVar9)) {
                      iVar23 = (int)(uVar21 + ((int)uVar21 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)(((int)fVar26 >> 0x1f & 0x3ffffU) + (int)fVar26) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                      bVar13 = pbVar19[3];
                      if (bVar13 != 0) {
                        uVar10 = (uint)(byte)(&DAT_00dca2e0)
                                             [*(byte *)((&DAT_00f408d8)[iVar23] + iVar25)];
                        if (bVar13 == 0xff) {
                          local_14._0_2_ =
                               CONCAT11((char)(pbVar19[1] * uVar10 * iVar8 >> 0x10),
                                        (char)(*pbVar19 * uVar10 * iVar8 >> 0x10));
                          uVar14 = (undefined1)(pbVar19[2] * uVar10 * iVar8 >> 0x10);
                        }
                        else {
                          iVar23 = uVar10 * bVar13;
                          local_14._0_2_ =
                               CONCAT11((char)((uint)pbVar19[1] * iVar23 * iVar8 >> 0x18),
                                        (char)((uint)*pbVar19 * iVar23 * iVar8 >> 0x18));
                          uVar14 = (undefined1)((uint)pbVar19[2] * iVar23 * iVar8 >> 0x18);
                        }
                        local_14._3_1_ = SUB41(uVar11,3);
                        local_14._0_3_ = CONCAT12(uVar14,(ushort)local_14);
                        uVar10 = (*puVar24 | 0x1010100) - ((uint)local_14 & 0xfefefeff);
                        uVar11 = uVar10 & 0x1010100;
                        *puVar24 = uVar11 - (uVar11 >> 8) & uVar10;
                        iVar8 = DAT_00dca3f8;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    uVar21 = uVar21 + local_34;
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  uVar21 = uVar21 + local_28;
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              break;
            case 4:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            pbVar19 = (byte *)((&DAT_00f448d8)
                                               [(int)((int)local_14 +
                                                     ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                              ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                              >> 0x12) * 4);
                            *(byte *)puVar24 =
                                 (byte)((uint)(byte)*puVar24 * local_4c[*pbVar19] >> 8);
                            *(byte *)((int)puVar24 + 1) =
                                 (byte)((uint)*(byte *)((int)puVar24 + 1) * local_48[pbVar19[1]] >>
                                       8);
                            *(byte *)((int)puVar24 + 2) =
                                 (byte)((uint)*(byte *)((int)puVar24 + 2) * local_50[pbVar19[2]] >>
                                       8);
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                           (puVar1 = (uint *)((&DAT_00f448d8)
                                              [(int)((int)local_14 +
                                                    ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                             ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) * 4), (float)*puVar1 != local_58)) {
                          *(byte *)puVar24 =
                               (byte)((uint)(byte)*puVar24 * local_4c[(byte)*puVar1] >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((uint)*(byte *)((int)puVar24 + 1) *
                                      local_48[*(byte *)((int)puVar1 + 1)] >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)((uint)*(byte *)((int)puVar24 + 2) *
                                      local_50[*(byte *)((int)puVar1 + 2)] >> 8);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          pbVar19 = (byte *)((&DAT_00f448d8)
                                             [(int)((int)local_14 +
                                                   ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                            ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                            >> 0x12) * 4);
                          *(byte *)puVar24 =
                               (byte)((uint)(byte)*puVar24 * local_4c[*pbVar19] * (uint)pbVar19[3]
                                     >> 0x10);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((uint)*(byte *)((int)puVar24 + 1) * local_48[pbVar19[1]] *
                                      (uint)pbVar19[3] >> 0x10);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)((uint)*(byte *)((int)puVar24 + 2) * local_50[pbVar19[2]] *
                                      (uint)pbVar19[3] >> 0x10);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)
                                           [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)
                                                 ) >> 0x12] + iVar8 * 4);
                        if (*(char *)((&DAT_00f448d8)
                                      [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                       0x12] + 3 + iVar8 * 4) == -1) {
                          *(byte *)puVar24 = (byte)((uint)(byte)*puVar24 * local_4c[*pbVar19] >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((uint)*(byte *)((int)puVar24 + 1) * local_48[pbVar19[1]] >> 8)
                          ;
                          bVar13 = (byte)((uint)*(byte *)((int)puVar24 + 2) * local_50[pbVar19[2]]
                                         >> 8);
                        }
                        else {
                          *(byte *)puVar24 =
                               (byte)((uint)(byte)*puVar24 * local_4c[*pbVar19] * (uint)pbVar19[3]
                                     >> 0x10);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((uint)*(byte *)((int)puVar24 + 1) * local_48[pbVar19[1]] *
                                      (uint)pbVar19[3] >> 0x10);
                          bVar13 = (byte)((uint)*(byte *)((int)puVar24 + 2) * local_50[pbVar19[2]] *
                                          (uint)pbVar19[3] >> 0x10);
                        }
                        *(byte *)((int)puVar24 + 2) = bVar13;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          iVar8 = (&DAT_00f448d8)
                                  [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                  ] + iVar23 * 4;
                          *(byte *)puVar24 =
                               (byte)((uint)(byte)*puVar24 *
                                      (uint)*(byte *)((&DAT_00f448d8)
                                                      [(int)((int)local_14 +
                                                            ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                                       0x12] + iVar23 * 4) >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((uint)*(byte *)(iVar8 + 1) * (uint)*(byte *)((int)puVar24 + 1)
                                     >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)((uint)*(byte *)(iVar8 + 2) * (uint)*(byte *)((int)puVar24 + 2)
                                     >> 8);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                         (puVar1 = (uint *)((&DAT_00f448d8)
                                            [(int)((int)local_14 +
                                                  ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                           ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                           0x12) * 4), (float)*puVar1 != local_58)) {
                        *(byte *)puVar24 = (byte)((uint)(byte)*puVar24 * (uint)(byte)*puVar1 >> 8);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((uint)*(byte *)((int)puVar1 + 1) *
                                    (uint)*(byte *)((int)puVar24 + 1) >> 8);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((uint)*(byte *)((int)puVar1 + 2) *
                                    (uint)*(byte *)((int)puVar24 + 2) >> 8);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)
                                           [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)
                                                 ) >> 0x12] + iVar8 * 4);
                        *(byte *)puVar24 =
                             (byte)((uint)(byte)*puVar24 *
                                    (uint)*(byte *)((&DAT_00f448d8)
                                                    [(int)((int)local_14 +
                                                          ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                                     0x12] + 3 + iVar8 * 4) * (uint)*pbVar19 >> 0x10
                                   );
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((uint)pbVar19[1] * (uint)*(byte *)((int)puVar24 + 1) *
                                    (uint)pbVar19[3] >> 0x10);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((uint)pbVar19[2] * (uint)*(byte *)((int)puVar24 + 2) *
                                    (uint)pbVar19[3] >> 0x10);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      pbVar19 = (byte *)((&DAT_00f448d8)
                                         [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU))
                                          >> 0x12] +
                                        ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                        0x12) * 4);
                      if (pbVar19[3] == 0xff) {
                        *(byte *)puVar24 = (byte)((uint)(byte)*puVar24 * (uint)*pbVar19 >> 8);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((uint)pbVar19[1] * (uint)*(byte *)((int)puVar24 + 1) >> 8);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((uint)pbVar19[2] * (uint)*(byte *)((int)puVar24 + 2) >> 8);
                      }
                      else {
                        *(byte *)puVar24 =
                             (byte)((uint)(byte)*puVar24 * (uint)pbVar19[3] * (uint)*pbVar19 >> 0x10
                                   );
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((uint)pbVar19[1] * (uint)*(byte *)((int)puVar24 + 1) *
                                    (uint)pbVar19[3] >> 0x10);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((uint)pbVar19[2] * (uint)*(byte *)((int)puVar24 + 2) *
                                    (uint)pbVar19[3] >> 0x10);
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                          pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                          *(byte *)puVar24 =
                               (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * local_4c[*pbVar19] *
                                      (uint)(byte)*puVar24 >> 0x10);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * local_48[pbVar19[1]] *
                                      (uint)*(byte *)((int)puVar24 + 1) >> 0x10);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * local_50[pbVar19[2]] *
                                      (uint)*(byte *)((int)puVar24 + 2) >> 0x10);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        puVar1 = (uint *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                        pbVar19 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                        if ((float)*puVar1 != local_58) {
                          *(byte *)puVar24 =
                               (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                      local_4c[(byte)*puVar1] * (uint)(byte)*puVar24 >> 0x10);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                      local_48[*(byte *)((int)puVar1 + 1)] *
                                      (uint)*(byte *)((int)puVar24 + 1) >> 0x10);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                      local_50[*(byte *)((int)puVar1 + 2)] *
                                      (uint)*(byte *)((int)puVar24 + 2) >> 0x10);
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                        pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                        *(byte *)puVar24 =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * local_4c[*pbVar19] *
                                    (uint)(byte)*puVar24 * (uint)pbVar19[3] >> 0x18);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * local_48[pbVar19[1]] *
                                    (uint)*(byte *)((int)puVar24 + 1) * (uint)pbVar19[3] >> 0x18);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * local_50[pbVar19[2]] *
                                    (uint)*(byte *)((int)puVar24 + 2) * (uint)pbVar19[3] >> 0x18);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                      if (pbVar19[3] == 0xff) {
                        *(byte *)puVar24 =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * local_4c[*pbVar19] *
                                    (uint)(byte)*puVar24 >> 0x10);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * local_48[pbVar19[1]] *
                                    (uint)*(byte *)((int)puVar24 + 1) >> 0x10);
                        bVar13 = (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * local_50[pbVar19[2]]
                                        * (uint)*(byte *)((int)puVar24 + 2) >> 0x10);
                      }
                      else {
                        *(byte *)puVar24 =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * local_4c[*pbVar19] *
                                    (uint)(byte)*puVar24 * (uint)pbVar19[3] >> 0x18);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * local_48[pbVar19[1]] *
                                    (uint)*(byte *)((int)puVar24 + 1) * (uint)pbVar19[3] >> 0x18);
                        bVar13 = (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * local_50[pbVar19[2]]
                                        * (uint)*(byte *)((int)puVar24 + 2) * (uint)pbVar19[3] >>
                                       0x18);
                      }
                      *(byte *)((int)puVar24 + 2) = bVar13;
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (*(int *)(iVar23 + 0x2c) != 1) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                        pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                        *(byte *)puVar24 =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)(byte)*puVar24 *
                                    (uint)*pbVar19 >> 0x10);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[1] *
                                    (uint)*(byte *)((int)puVar24 + 1) >> 0x10);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[2] *
                                    (uint)*(byte *)((int)puVar24 + 2) >> 0x10);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      puVar1 = (uint *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                      pbVar19 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                      if ((float)*puVar1 != local_58) {
                        *(byte *)puVar24 =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] * (uint)(byte)*puVar24 *
                                    (uint)(byte)*puVar1 >> 0x10);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                    (uint)*(byte *)((int)puVar1 + 1) *
                                    (uint)*(byte *)((int)puVar24 + 1) >> 0x10);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                    (uint)*(byte *)((int)puVar1 + 2) *
                                    (uint)*(byte *)((int)puVar24 + 2) >> 0x10);
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 == 0) {
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                      *(byte *)puVar24 =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)(byte)*puVar24 *
                                  (uint)pbVar19[3] * (uint)*pbVar19 >> 0x18);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[1] *
                                  (uint)*(byte *)((int)puVar24 + 1) * (uint)pbVar19[3] >> 0x18);
                      *(byte *)((int)puVar24 + 2) =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[2] *
                                  (uint)*(byte *)((int)puVar24 + 2) * (uint)pbVar19[3] >> 0x18);
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                    iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar8 * 4);
                    pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar8);
                    if (pbVar19[3] == 0xff) {
                      *(byte *)puVar24 =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)(byte)*puVar24 *
                                  (uint)*pbVar19 >> 0x10);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[1] *
                                  (uint)*(byte *)((int)puVar24 + 1) >> 0x10);
                      bVar13 = (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[2] *
                                      (uint)*(byte *)((int)puVar24 + 2) >> 0x10);
                    }
                    else {
                      *(byte *)puVar24 =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)(byte)*puVar24 *
                                  (uint)pbVar19[3] * (uint)*pbVar19 >> 0x18);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[1] *
                                  (uint)*(byte *)((int)puVar24 + 1) * (uint)pbVar19[3] >> 0x18);
                      bVar13 = (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[2] *
                                      (uint)*(byte *)((int)puVar24 + 2) * (uint)pbVar19[3] >> 0x18);
                    }
                    *(byte *)((int)puVar24 + 2) = bVar13;
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  local_14 = (float)((int)local_14 + local_34);
                  puVar24 = puVar24 + 1;
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                local_14 = (float)((int)local_14 + local_28);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            case 10:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            pbVar19 = (byte *)((&DAT_00f448d8)
                                               [(int)((int)local_14 +
                                                     ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                              ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                              >> 0x12) * 4);
                            *(byte *)puVar24 =
                                 (byte)(((uint)*(byte *)(local_4c + (byte)~*pbVar19) -
                                        (uint)(byte)*puVar24) * DAT_00dca3f8 +
                                        (uint)(byte)*puVar24 * 0x100 >> 8);
                            *(byte *)((int)puVar24 + 1) =
                                 (byte)(((uint)*(byte *)(local_48 + (byte)~pbVar19[1]) -
                                        (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                            *(byte *)((int)puVar24 + 2) =
                                 (byte)(((uint)*(byte *)(local_50 + (byte)~pbVar19[2]) -
                                        (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                           (puVar1 = (uint *)((&DAT_00f448d8)
                                              [(int)((int)local_14 +
                                                    ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                             ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) * 4), (float)*puVar1 != local_58)) {
                          *(byte *)puVar24 =
                               (byte)(((uint)*(byte *)(local_4c + (byte)~(byte)*puVar1) -
                                      (uint)(byte)*puVar24) * DAT_00dca3f8 +
                                      (uint)(byte)*puVar24 * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)*(byte *)(local_48 + (byte)~*(byte *)((int)puVar1 + 1))
                                      - (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)*(byte *)(local_50 + (byte)~*(byte *)((int)puVar1 + 2))
                                      - (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          pbVar19 = (byte *)((&DAT_00f448d8)
                                             [(int)((int)local_14 +
                                                   ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                            ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                            >> 0x12) * 4);
                          *(byte *)puVar24 =
                               (byte)(((uint)*(byte *)(local_4c + (byte)~*pbVar19) -
                                      (uint)(byte)*puVar24) * (uint)pbVar19[3] * DAT_00dca3f8 +
                                      (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)*(byte *)(local_48 + (byte)~pbVar19[1]) -
                                      (uint)*(byte *)((int)puVar24 + 1)) * (uint)pbVar19[3] *
                                      DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >>
                                     0x10);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)*(byte *)(local_50 + (byte)~pbVar19[2]) -
                                      (uint)*(byte *)((int)puVar24 + 2)) * (uint)pbVar19[3] *
                                      DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >>
                                     0x10);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar8 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)
                                           [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)
                                                 ) >> 0x12] + iVar8 * 4);
                        uVar21 = (uint)(byte)*puVar24;
                        if (*(char *)((&DAT_00f448d8)
                                      [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                       0x12] + 3 + iVar8 * 4) == -1) {
                          *(byte *)puVar24 =
                               (byte)((*(byte *)(local_4c + (byte)~*pbVar19) - uVar21) *
                                      DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)*(byte *)(local_48 + (byte)~pbVar19[1]) -
                                      (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)*(byte *)(local_50 + (byte)~pbVar19[2]) -
                                      (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                        }
                        else {
                          *(byte *)puVar24 =
                               (byte)((*(byte *)(local_4c + (byte)~*pbVar19) - uVar21) *
                                      (uint)pbVar19[3] * DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)*(byte *)(local_48 + (byte)~pbVar19[1]) -
                                      (uint)*(byte *)((int)puVar24 + 1)) * (uint)pbVar19[3] *
                                      DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >>
                                     0x10);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)*(byte *)(local_50 + (byte)~pbVar19[2]) -
                                      (uint)*(byte *)((int)puVar24 + 2)) * (uint)pbVar19[3] *
                                      DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >>
                                     0x10);
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          iVar8 = (&DAT_00f448d8)
                                  [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                  ] + iVar23 * 4;
                          *(byte *)puVar24 =
                               (byte)(((uint)(byte)~*(byte *)((&DAT_00f448d8)
                                                              [(int)((int)local_14 +
                                                                    ((int)local_14 >> 0x1f &
                                                                    0x3ffffU)) >> 0x12] + iVar23 * 4
                                                             ) - (uint)(byte)*puVar24) *
                                      DAT_00dca3f8 + (uint)(byte)*puVar24 * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)(byte)~*(byte *)(iVar8 + 1) -
                                      (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)(byte)~*(byte *)(iVar8 + 2) -
                                      (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                         (puVar1 = (uint *)((&DAT_00f448d8)
                                            [(int)((int)local_14 +
                                                  ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                           ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                           0x12) * 4), (float)*puVar1 != local_58)) {
                        *(byte *)puVar24 =
                             (byte)(((uint)(byte)~(byte)*puVar1 - (uint)(byte)*puVar24) *
                                    DAT_00dca3f8 + (uint)(byte)*puVar24 * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)(byte)~*(byte *)((int)puVar1 + 1) -
                                    (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)(byte)~*(byte *)((int)puVar1 + 2) -
                                    (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (&DAT_00f448d8)
                                [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]
                                + iVar23 * 4;
                        *(byte *)puVar24 =
                             (byte)(((uint)(byte)~*(byte *)((&DAT_00f448d8)
                                                            [(int)((int)local_14 +
                                                                  ((int)local_14 >> 0x1f & 0x3ffffU)
                                                                  ) >> 0x12] + iVar23 * 4) -
                                    (uint)(byte)*puVar24) * (uint)*(byte *)(iVar8 + 3) *
                                    DAT_00dca3f8 + (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)(byte)~*(byte *)(iVar8 + 1) -
                                    (uint)*(byte *)((int)puVar24 + 1)) * (uint)*(byte *)(iVar8 + 3)
                                    * DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >>
                                   0x10);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)(byte)~*(byte *)(iVar8 + 2) -
                                    (uint)*(byte *)((int)puVar24 + 2)) * (uint)*(byte *)(iVar8 + 3)
                                    * DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >>
                                   0x10);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (&DAT_00f448d8)
                              [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                              iVar23 * 4;
                      uVar21 = (uint)(byte)*puVar24;
                      iVar23 = (byte)~*(byte *)((&DAT_00f448d8)
                                                [(int)((int)local_14 +
                                                      ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                               iVar23 * 4) - uVar21;
                      if (*(char *)(iVar8 + 3) == -1) {
                        *(byte *)puVar24 = (byte)(iVar23 * DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)(byte)~*(byte *)(iVar8 + 1) -
                                    (uint)*(byte *)((int)puVar24 + 1)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x100 >> 8);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)(byte)~*(byte *)(iVar8 + 2) -
                                    (uint)*(byte *)((int)puVar24 + 2)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x100 >> 8);
                      }
                      else {
                        *(byte *)puVar24 =
                             (byte)(iVar23 * (uint)*(byte *)(iVar8 + 3) * DAT_00dca3f8 +
                                    uVar21 * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)(byte)~*(byte *)(iVar8 + 1) -
                                    (uint)*(byte *)((int)puVar24 + 1)) * (uint)*(byte *)(iVar8 + 3)
                                    * DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >>
                                   0x10);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)(byte)~*(byte *)(iVar8 + 2) -
                                    (uint)*(byte *)((int)puVar24 + 2)) * (uint)*(byte *)(iVar8 + 3)
                                    * DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >>
                                   0x10);
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                          pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                          *(byte *)puVar24 =
                               (byte)(((uint)*(byte *)(local_4c + (byte)~*pbVar19) -
                                      (uint)(byte)*puVar24) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20]
                                      * iVar8 + (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)*(byte *)(local_48 + (byte)~pbVar19[1]) -
                                      (uint)*(byte *)((int)puVar24 + 1)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)*(byte *)(local_50 + (byte)~pbVar19[2]) -
                                      (uint)*(byte *)((int)puVar24 + 2)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                          iVar8 = DAT_00dca3f8;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        puVar1 = (uint *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        pbVar19 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                        if ((float)*puVar1 != local_58) {
                          *(byte *)puVar24 =
                               (byte)(((uint)*(byte *)(local_4c + (byte)~(byte)*puVar1) -
                                      (uint)(byte)*puVar24) * (uint)(byte)(&DAT_00dca2e0)[*pbVar19]
                                      * iVar8 + (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((uint)*(byte *)(local_48 + (byte)~*(byte *)((int)puVar1 + 1))
                                      - (uint)*(byte *)((int)puVar24 + 1)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((uint)*(byte *)(local_50 + (byte)~*(byte *)((int)puVar1 + 2))
                                      - (uint)*(byte *)((int)puVar24 + 2)) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                          iVar8 = DAT_00dca3f8;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                        *(byte *)puVar24 =
                             (byte)(((uint)*(byte *)(local_4c + (byte)~*pbVar19) -
                                    (uint)(byte)*puVar24) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] *
                                    (uint)pbVar19[3] * iVar8 + (uint)(byte)*puVar24 * 0x1000000 >>
                                   0x18);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)*(byte *)(local_48 + (byte)~pbVar19[1]) -
                                    (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                    DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 1) * 0x1000000 >>
                                   0x18);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)*(byte *)(local_50 + (byte)~pbVar19[2]) -
                                    (uint)*(byte *)((int)puVar24 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                    DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 2) * 0x1000000 >>
                                   0x18);
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                      uVar21 = (uint)(byte)*puVar24;
                      if (pbVar19[3] == 0xff) {
                        *(byte *)puVar24 =
                             (byte)((*(byte *)(local_4c + (byte)~*pbVar19) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * iVar8 + uVar21 * 0x10000
                                   >> 0x10);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)*(byte *)(local_48 + (byte)~pbVar19[1]) -
                                    (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                        bVar13 = (byte)(((uint)*(byte *)(local_50 + (byte)~pbVar19[2]) -
                                        (uint)*(byte *)((int)puVar24 + 2)) *
                                        (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                        (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                      }
                      else {
                        *(byte *)puVar24 =
                             (byte)((*(byte *)(local_4c + (byte)~*pbVar19) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] * iVar8
                                    + uVar21 * 0x1000000 >> 0x18);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)*(byte *)(local_48 + (byte)~pbVar19[1]) -
                                    (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                    DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 1) * 0x1000000 >>
                                   0x18);
                        bVar13 = (byte)(((uint)*(byte *)(local_50 + (byte)~pbVar19[2]) -
                                        (uint)*(byte *)((int)puVar24 + 2)) *
                                        (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                        DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 2) * 0x1000000
                                       >> 0x18);
                      }
                      *(byte *)((int)puVar24 + 2) = bVar13;
                      iVar8 = DAT_00dca3f8;
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (*(int *)(iVar23 + 0x2c) != 1) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                        *(byte *)puVar24 =
                             (byte)(((uint)(byte)~*pbVar19 - (uint)(byte)*puVar24) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * iVar8 +
                                    (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)(byte)~pbVar19[1] - (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)(byte)~pbVar19[2] - (uint)*(byte *)((int)puVar24 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      puVar1 = (uint *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                      pbVar19 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                      if ((float)*puVar1 != local_58) {
                        *(byte *)puVar24 =
                             (byte)(((uint)(byte)~(byte)*puVar1 - (uint)(byte)*puVar24) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * iVar8 +
                                    (uint)(byte)*puVar24 * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((uint)(byte)~*(byte *)((int)puVar1 + 1) -
                                    (uint)*(byte *)((int)puVar24 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((uint)(byte)~*(byte *)((int)puVar1 + 2) -
                                    (uint)*(byte *)((int)puVar24 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                        iVar8 = DAT_00dca3f8;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 == 0) {
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                      *(byte *)puVar24 =
                           (byte)(((uint)(byte)~*pbVar19 - (uint)(byte)*puVar24) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] * iVar8 +
                                  (uint)(byte)*puVar24 * 0x1000000 >> 0x18);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)(((uint)(byte)~pbVar19[1] - (uint)*(byte *)((int)puVar24 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                  DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 1) * 0x1000000 >>
                                 0x18);
                      *(byte *)((int)puVar24 + 2) =
                           (byte)(((uint)(byte)~pbVar19[2] - (uint)*(byte *)((int)puVar24 + 2)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                  DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 2) * 0x1000000 >>
                                 0x18);
                      iVar8 = DAT_00dca3f8;
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                    iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                    pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                    uVar21 = (uint)(byte)*puVar24;
                    if (pbVar19[3] == 0xff) {
                      *(byte *)puVar24 =
                           (byte)(((byte)~*pbVar19 - uVar21) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20]
                                  * iVar8 + uVar21 * 0x10000 >> 0x10);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)(((uint)(byte)~pbVar19[1] - (uint)*(byte *)((int)puVar24 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar24 + 1) * 0x10000 >> 0x10);
                      bVar13 = (byte)(((uint)(byte)~pbVar19[2] - (uint)*(byte *)((int)puVar24 + 2))
                                      * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar24 + 2) * 0x10000 >> 0x10);
                    }
                    else {
                      *(byte *)puVar24 =
                           (byte)(((byte)~*pbVar19 - uVar21) * (uint)(byte)(&DAT_00dca2e0)[*pbVar20]
                                  * (uint)pbVar19[3] * iVar8 + uVar21 * 0x1000000 >> 0x18);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)(((uint)(byte)~pbVar19[1] - (uint)*(byte *)((int)puVar24 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                  DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 1) * 0x1000000 >>
                                 0x18);
                      bVar13 = (byte)(((uint)(byte)~pbVar19[2] - (uint)*(byte *)((int)puVar24 + 2))
                                      * (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                      DAT_00dca3f8 + (uint)*(byte *)((int)puVar24 + 2) * 0x1000000
                                     >> 0x18);
                    }
                    *(byte *)((int)puVar24 + 2) = bVar13;
                    iVar8 = DAT_00dca3f8;
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  local_14 = (float)((int)local_14 + local_34);
                  puVar24 = puVar24 + 1;
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                local_14 = (float)((int)local_14 + local_28);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            case 0xb:
              if (param_11 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(iVar23 + 0x2c) != 1) {
                    if (param_8 == 0) {
                      do {
                        do {
                          if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                            pbVar19 = (byte *)((&DAT_00f448d8)
                                               [(int)((int)local_14 +
                                                     ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                              ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                              >> 0x12) * 4);
                            uVar21 = (uint)(byte)*puVar24;
                            *(byte *)puVar24 =
                                 (byte)(((local_4c[*pbVar19] * uVar21 >> 8 & 0xff) - uVar21) *
                                        DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                            uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                            *(byte *)((int)puVar24 + 1) =
                                 (byte)(((local_48[pbVar19[1]] * uVar21 >> 8 & 0xff) - uVar21) *
                                        DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                            uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                            *(byte *)((int)puVar24 + 2) =
                                 (byte)(((local_50[pbVar19[2]] * uVar21 >> 8 & 0xff) - uVar21) *
                                        DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                          }
                          fVar26 = (float)((int)fVar26 + local_38);
                          local_14 = (float)((int)local_14 + local_34);
                          puVar24 = puVar24 + 1;
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        fVar26 = (float)((int)fVar26 + local_2c);
                        local_14 = (float)((int)local_14 + local_28);
                        puVar24 = (uint *)((int)puVar24 + local_64);
                        local_10 = local_10 + -1;
                        local_8 = local_7c;
                      } while (local_10 != 0);
                      return;
                    }
                    do {
                      do {
                        if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                           (puVar1 = (uint *)((&DAT_00f448d8)
                                              [(int)((int)local_14 +
                                                    ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                             ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                             >> 0x12) * 4), (float)*puVar1 != local_58)) {
                          uVar21 = (uint)(byte)*puVar24;
                          *(byte *)puVar24 =
                               (byte)(((local_4c[(byte)*puVar1] * uVar21 >> 8 & 0xff) - uVar21) *
                                      DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                          uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((local_48[*(byte *)((int)puVar1 + 1)] * uVar21 >> 8 & 0xff) -
                                      uVar21) * DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                          uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((local_50[*(byte *)((int)puVar1 + 2)] * uVar21 >> 8 & 0xff) -
                                      uVar21) * DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          pbVar19 = (byte *)((&DAT_00f448d8)
                                             [(int)((int)local_14 +
                                                   ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                            ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU))
                                            >> 0x12) * 4);
                          uVar21 = (uint)(byte)*puVar24;
                          *(byte *)puVar24 =
                               (byte)(((local_4c[*pbVar19] * uVar21 >> 8 & 0xff) - uVar21) *
                                      (uint)pbVar19[3] * DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10);
                          uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((local_48[pbVar19[1]] * uVar21 >> 8 & 0xff) - uVar21) *
                                      (uint)pbVar19[3] * DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10);
                          uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((local_50[pbVar19[2]] * uVar21 >> 8 & 0xff) - uVar21) *
                                      (uint)pbVar19[3] * DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        pbVar19 = (byte *)((&DAT_00f448d8)
                                           [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)
                                                 ) >> 0x12] +
                                          ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                          0x12) * 4);
                        uVar21 = (uint)(byte)*puVar24;
                        iVar8 = (local_4c[*pbVar19] * uVar21 >> 8 & 0xff) - uVar21;
                        if (pbVar19[3] == 0xff) {
                          *(byte *)puVar24 = (byte)(iVar8 * DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                          uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((local_48[pbVar19[1]] * uVar21 >> 8 & 0xff) - uVar21) *
                                      DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                          uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((local_50[pbVar19[2]] * uVar21 >> 8 & 0xff) - uVar21) *
                                      DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                        }
                        else {
                          *(byte *)puVar24 =
                               (byte)(iVar8 * (uint)pbVar19[3] * DAT_00dca3f8 + uVar21 * 0x10000 >>
                                     0x10);
                          uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((local_48[pbVar19[1]] * uVar21 >> 8 & 0xff) - uVar21) *
                                      (uint)pbVar19[3] * DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10);
                          uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((local_50[pbVar19[2]] * uVar21 >> 8 & 0xff) - uVar21) *
                                      (uint)pbVar19[3] * DAT_00dca3f8 + uVar21 * 0x10000 >> 0x10);
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          iVar8 = (&DAT_00f448d8)
                                  [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                                  ] + iVar23 * 4;
                          uVar21 = (uint)(byte)*puVar24;
                          *(byte *)puVar24 =
                               (byte)((((int)(*(byte *)((&DAT_00f448d8)
                                                        [(int)((int)local_14 +
                                                              ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                                         0x12] + iVar23 * 4) * uVar21) >> 8) -
                                      uVar21) * DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                          uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)((((int)(*(byte *)(iVar8 + 1) * uVar21) >> 8) - uVar21) *
                                      DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                          uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)((((int)(*(byte *)(iVar8 + 2) * uVar21) >> 8) - uVar21) *
                                      DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if ((((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) &&
                         (puVar1 = (uint *)((&DAT_00f448d8)
                                            [(int)((int)local_14 +
                                                  ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                           ((int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >>
                                           0x12) * 4), (float)*puVar1 != local_58)) {
                        uVar21 = (uint)(byte)*puVar24;
                        *(byte *)puVar24 =
                             (byte)((((int)((byte)*puVar1 * uVar21) >> 8) - uVar21) * DAT_00dca3f8 +
                                    uVar21 * 0x100 >> 8);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((((int)(*(byte *)((int)puVar1 + 1) * uVar21) >> 8) - uVar21) *
                                    DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((((int)(*(byte *)((int)puVar1 + 2) * uVar21) >> 8) - uVar21) *
                                    DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar8 = (&DAT_00f448d8)
                                [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12]
                                + iVar23 * 4;
                        uVar21 = (uint)(byte)*puVar24;
                        *(byte *)puVar24 =
                             (byte)((((int)(*(byte *)((&DAT_00f448d8)
                                                      [(int)((int)local_14 +
                                                            ((int)local_14 >> 0x1f & 0x3ffffU)) >>
                                                       0x12] + iVar23 * 4) * uVar21) >> 8) - uVar21)
                                    * (uint)*(byte *)(iVar8 + 3) * DAT_00dca3f8 + uVar21 * 0x10000
                                   >> 0x10);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((((int)(*(byte *)(iVar8 + 1) * uVar21) >> 8) - uVar21) *
                                    (uint)*(byte *)(iVar8 + 3) * DAT_00dca3f8 + uVar21 * 0x10000 >>
                                   0x10);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((((int)(*(byte *)(iVar8 + 2) * uVar21) >> 8) - uVar21) *
                                    (uint)*(byte *)(iVar8 + 3) * DAT_00dca3f8 + uVar21 * 0x10000 >>
                                   0x10);
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar8 = (&DAT_00f448d8)
                              [(int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                              iVar23 * 4;
                      uVar21 = (uint)(byte)*puVar24;
                      iVar23 = ((int)(*(byte *)((&DAT_00f448d8)
                                                [(int)((int)local_14 +
                                                      ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12] +
                                               iVar23 * 4) * uVar21) >> 8) - uVar21;
                      if (*(char *)(iVar8 + 3) == -1) {
                        *(byte *)puVar24 = (byte)(iVar23 * DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((((int)(*(byte *)(iVar8 + 1) * uVar21) >> 8) - uVar21) *
                                    DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((((int)(*(byte *)(iVar8 + 2) * uVar21) >> 8) - uVar21) *
                                    DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                      }
                      else {
                        *(byte *)puVar24 =
                             (byte)(iVar23 * (uint)*(byte *)(iVar8 + 3) * DAT_00dca3f8 +
                                    uVar21 * 0x10000 >> 0x10);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((((int)(*(byte *)(iVar8 + 1) * uVar21) >> 8) - uVar21) *
                                    (uint)*(byte *)(iVar8 + 3) * DAT_00dca3f8 + uVar21 * 0x10000 >>
                                   0x10);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((((int)(*(byte *)(iVar8 + 2) * uVar21) >> 8) - uVar21) *
                                    (uint)*(byte *)(iVar8 + 3) * DAT_00dca3f8 + uVar21 * 0x10000 >>
                                   0x10);
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(iVar23 + 0x2c) != 1) {
                  if (param_8 == 0) {
                    do {
                      do {
                        if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                          iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12
                          ;
                          iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                          pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                          pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                          uVar21 = (uint)(byte)*puVar24;
                          *(byte *)puVar24 =
                               (byte)(((local_4c[*pbVar19] * uVar21 >> 8 & 0xff) - uVar21) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * iVar8 +
                                      uVar21 * 0x10000 >> 0x10);
                          uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((local_48[pbVar19[1]] * uVar21 >> 8 & 0xff) - uVar21) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                      uVar21 * 0x10000 >> 0x10);
                          uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((local_50[pbVar19[2]] * uVar21 >> 8 & 0xff) - uVar21) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                      uVar21 * 0x10000 >> 0x10);
                          iVar8 = DAT_00dca3f8;
                        }
                        fVar26 = (float)((int)fVar26 + local_38);
                        local_14 = (float)((int)local_14 + local_34);
                        puVar24 = puVar24 + 1;
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      fVar26 = (float)((int)fVar26 + local_2c);
                      local_14 = (float)((int)local_14 + local_28);
                      puVar24 = (uint *)((int)puVar24 + local_64);
                      local_10 = local_10 + -1;
                      local_8 = local_7c;
                    } while (local_10 != 0);
                    return;
                  }
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        puVar1 = (uint *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        pbVar19 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                        if ((float)*puVar1 != local_58) {
                          uVar21 = (uint)(byte)*puVar24;
                          *(byte *)puVar24 =
                               (byte)(((local_4c[(byte)*puVar1] * uVar21 >> 8 & 0xff) - uVar21) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * iVar8 +
                                      uVar21 * 0x10000 >> 0x10);
                          uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                          *(byte *)((int)puVar24 + 1) =
                               (byte)(((local_48[*(byte *)((int)puVar1 + 1)] * uVar21 >> 8 & 0xff) -
                                      uVar21) * (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * DAT_00dca3f8
                                      + uVar21 * 0x10000 >> 0x10);
                          uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                          *(byte *)((int)puVar24 + 2) =
                               (byte)(((local_50[*(byte *)((int)puVar1 + 2)] * uVar21 >> 8 & 0xff) -
                                      uVar21) * (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * DAT_00dca3f8
                                      + uVar21 * 0x10000 >> 0x10);
                          iVar8 = DAT_00dca3f8;
                        }
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                        uVar21 = (uint)(byte)*puVar24;
                        *(byte *)puVar24 =
                             (byte)(((local_4c[*pbVar19] * uVar21 >> 8 & 0xff) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] * iVar8
                                    + uVar21 * 0x1000000 >> 0x18);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((local_48[pbVar19[1]] * uVar21 >> 8 & 0xff) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                    DAT_00dca3f8 + uVar21 * 0x1000000 >> 0x18);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)(((local_50[pbVar19[2]] * uVar21 >> 8 & 0xff) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                    DAT_00dca3f8 + uVar21 * 0x1000000 >> 0x18);
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                      uVar21 = (uint)(byte)*puVar24;
                      if (pbVar19[3] == 0xff) {
                        *(byte *)puVar24 =
                             (byte)(((local_4c[*pbVar19] * uVar21 >> 8 & 0xff) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * iVar8 + uVar21 * 0x10000
                                   >> 0x10);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((local_48[pbVar19[1]] * uVar21 >> 8 & 0xff) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    uVar21 * 0x10000 >> 0x10);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                        bVar13 = (byte)(((local_50[pbVar19[2]] * uVar21 >> 8 & 0xff) - uVar21) *
                                        (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                        uVar21 * 0x10000 >> 0x10);
                      }
                      else {
                        *(byte *)puVar24 =
                             (byte)(((local_4c[*pbVar19] * uVar21 >> 8 & 0xff) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] * iVar8
                                    + uVar21 * 0x1000000 >> 0x18);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)(((local_48[pbVar19[1]] * uVar21 >> 8 & 0xff) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                    DAT_00dca3f8 + uVar21 * 0x1000000 >> 0x18);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                        bVar13 = (byte)(((local_50[pbVar19[2]] * uVar21 >> 8 & 0xff) - uVar21) *
                                        (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                        DAT_00dca3f8 + uVar21 * 0x1000000 >> 0x18);
                      }
                      *(byte *)((int)puVar24 + 2) = bVar13;
                      iVar8 = DAT_00dca3f8;
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (*(int *)(iVar23 + 0x2c) != 1) {
                if (param_8 == 0) {
                  do {
                    do {
                      if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                        iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                        iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                        pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                        pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                        uVar21 = (uint)(byte)*puVar24;
                        *(byte *)puVar24 =
                             (byte)((((int)(*pbVar19 * uVar21) >> 8) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * iVar8 + uVar21 * 0x10000
                                   >> 0x10);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((((int)(pbVar19[1] * uVar21) >> 8) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    uVar21 * 0x10000 >> 0x10);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((((int)(pbVar19[2] * uVar21) >> 8) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                    uVar21 * 0x10000 >> 0x10);
                        iVar8 = DAT_00dca3f8;
                      }
                      fVar26 = (float)((int)fVar26 + local_38);
                      local_14 = (float)((int)local_14 + local_34);
                      puVar24 = puVar24 + 1;
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    fVar26 = (float)((int)fVar26 + local_2c);
                    local_14 = (float)((int)local_14 + local_28);
                    puVar24 = (uint *)((int)puVar24 + local_64);
                    local_10 = local_10 + -1;
                    local_8 = local_7c;
                  } while (local_10 != 0);
                  return;
                }
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      puVar1 = (uint *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                      pbVar19 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                      if ((float)*puVar1 != local_58) {
                        uVar21 = (uint)(byte)*puVar24;
                        *(byte *)puVar24 =
                             (byte)((((int)((byte)*puVar1 * uVar21) >> 8) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * iVar8 + uVar21 * 0x10000
                                   >> 0x10);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                        *(byte *)((int)puVar24 + 1) =
                             (byte)((((int)(*(byte *)((int)puVar1 + 1) * uVar21) >> 8) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * DAT_00dca3f8 +
                                    uVar21 * 0x10000 >> 0x10);
                        uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                        *(byte *)((int)puVar24 + 2) =
                             (byte)((((int)(*(byte *)((int)puVar1 + 2) * uVar21) >> 8) - uVar21) *
                                    (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * DAT_00dca3f8 +
                                    uVar21 * 0x10000 >> 0x10);
                        iVar8 = DAT_00dca3f8;
                      }
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              if (param_8 == 0) {
                do {
                  do {
                    if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                      iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                      iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                      pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                      pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                      uVar21 = (uint)(byte)*puVar24;
                      *(byte *)puVar24 =
                           (byte)((((int)(*pbVar19 * uVar21) >> 8) - uVar21) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] * iVar8 +
                                  uVar21 * 0x1000000 >> 0x18);
                      uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)((((int)(pbVar19[1] * uVar21) >> 8) - uVar21) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                  DAT_00dca3f8 + uVar21 * 0x1000000 >> 0x18);
                      uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                      *(byte *)((int)puVar24 + 2) =
                           (byte)((((int)(pbVar19[2] * uVar21) >> 8) - uVar21) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                  DAT_00dca3f8 + uVar21 * 0x1000000 >> 0x18);
                      iVar8 = DAT_00dca3f8;
                    }
                    fVar26 = (float)((int)fVar26 + local_38);
                    local_14 = (float)((int)local_14 + local_34);
                    puVar24 = puVar24 + 1;
                    local_8 = local_8 + -1;
                  } while (local_8 != 0);
                  fVar26 = (float)((int)fVar26 + local_2c);
                  local_14 = (float)((int)local_14 + local_28);
                  puVar24 = (uint *)((int)puVar24 + local_64);
                  local_10 = local_10 + -1;
                  local_8 = local_7c;
                } while (local_10 != 0);
                return;
              }
              do {
                do {
                  if (((uint)fVar26 < uVar12) && ((uint)local_14 < uVar9)) {
                    iVar23 = (int)((int)local_14 + ((int)local_14 >> 0x1f & 0x3ffffU)) >> 0x12;
                    iVar25 = (int)((int)fVar26 + ((int)fVar26 >> 0x1f & 0x3ffffU)) >> 0x12;
                    pbVar19 = (byte *)((&DAT_00f448d8)[iVar23] + iVar25 * 4);
                    pbVar20 = (byte *)((&DAT_00f408d8)[iVar23] + iVar25);
                    uVar21 = (uint)(byte)*puVar24;
                    if (pbVar19[3] == 0xff) {
                      *(byte *)puVar24 =
                           (byte)((((int)(*pbVar19 * uVar21) >> 8) - uVar21) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * iVar8 + uVar21 * 0x10000
                                 >> 0x10);
                      uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)((((int)(pbVar19[1] * uVar21) >> 8) - uVar21) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                  uVar21 * 0x10000 >> 0x10);
                      uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                      bVar13 = (byte)((((int)(pbVar19[2] * uVar21) >> 8) - uVar21) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * DAT_00dca3f8 +
                                      uVar21 * 0x10000 >> 0x10);
                    }
                    else {
                      *(byte *)puVar24 =
                           (byte)((((int)(*pbVar19 * uVar21) >> 8) - uVar21) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] * iVar8 +
                                  uVar21 * 0x1000000 >> 0x18);
                      uVar21 = (uint)*(byte *)((int)puVar24 + 1);
                      *(byte *)((int)puVar24 + 1) =
                           (byte)((((int)(pbVar19[1] * uVar21) >> 8) - uVar21) *
                                  (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                  DAT_00dca3f8 + uVar21 * 0x1000000 >> 0x18);
                      uVar21 = (uint)*(byte *)((int)puVar24 + 2);
                      bVar13 = (byte)((((int)(pbVar19[2] * uVar21) >> 8) - uVar21) *
                                      (uint)(byte)(&DAT_00dca2e0)[*pbVar20] * (uint)pbVar19[3] *
                                      DAT_00dca3f8 + uVar21 * 0x1000000 >> 0x18);
                    }
                    *(byte *)((int)puVar24 + 2) = bVar13;
                    iVar8 = DAT_00dca3f8;
                  }
                  fVar26 = (float)((int)fVar26 + local_38);
                  local_14 = (float)((int)local_14 + local_34);
                  puVar24 = puVar24 + 1;
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
                fVar26 = (float)((int)fVar26 + local_2c);
                local_14 = (float)((int)local_14 + local_28);
                puVar24 = (uint *)((int)puVar24 + local_64);
                local_10 = local_10 + -1;
                local_8 = local_7c;
              } while (local_10 != 0);
              return;
            }
          }
        }
      }
    }
  }
  return;
}

