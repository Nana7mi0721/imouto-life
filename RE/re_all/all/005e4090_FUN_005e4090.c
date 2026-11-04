
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005e4090(uint param_1)

{
  short sVar1;
  float fVar2;
  int iVar3;
  bool bVar4;
  undefined4 *puVar5;
  float *pfVar6;
  int iVar7;
  char *pcVar8;
  undefined4 *puVar9;
  uint uVar10;
  char *pcVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  undefined4 *puVar18;
  int iVar19;
  int local_58;
  int *local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int *local_34;
  int *local_30;
  float *local_2c;
  int local_28;
  int local_24;
  int *local_20;
  uint local_1c;
  int *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (DAT_00dccde0 == '\0') {
    return 0xffffffff;
  }
  if (((((DAT_00cc6e00 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc6e28)) ||
      ((DAT_00cc6e30 <= (int)(param_1 & 0xffff) ||
       (local_18 = *(int **)(DAT_00cc6e04 + (param_1 & 0xffff) * 4), local_18 == (int *)0x0)))) ||
     ((*local_18 * 0x10000 != (param_1 & 0x3ff0000) || (local_18[4] != 0)))) {
    return 0xffffffff;
  }
  local_10 = local_18[0x10];
  if ((char)local_18[0x67] == '\0') {
    return 0;
  }
  *(undefined1 *)(local_18 + 0x67) = 0;
  bVar4 = true;
  if ((DAT_00a37d78 == 0) || ((DAT_00ddb4b0 == 0 && (DAT_00ddb5f0 == 0)))) {
    bVar4 = false;
  }
  local_34 = (int *)local_18[0x6c];
  piVar12 = *(int **)(local_10 + 0xb0);
  local_28 = 0;
  if (0 < *(int *)(local_10 + 0xac)) {
    do {
      if ((*(char *)((int)piVar12 + 0x4a) != '\0') && (*(char *)(*local_34 + 0x210) != '\0')) {
        iVar14 = *piVar12;
        piVar13 = (int *)piVar12[0x17];
        local_58 = 0;
        if (0 < piVar12[0x15]) {
          puVar18 = (undefined4 *)local_34[0x2a] + 3;
          puVar9 = (undefined4 *)local_34[0x2a];
          do {
            puVar5 = (undefined4 *)(*piVar13 * *(int *)(iVar14 + 0x1a4) + *(int *)(iVar14 + 0x1a8));
            *puVar9 = *puVar5;
            puVar9[1] = puVar5[1];
            puVar9[2] = puVar5[2];
            puVar5 = (undefined4 *)(*(int *)(iVar14 + 0x1b0) + piVar13[1] * 0x24);
            *puVar18 = *puVar5;
            puVar18[1] = puVar5[1];
            puVar18[2] = puVar5[2];
            piVar13 = (int *)((int)piVar13 + piVar12[0x16]);
            local_58 = local_58 + 1;
            puVar18 = puVar18 + 6;
            puVar9 = puVar9 + 6;
          } while (local_58 < piVar12[0x15]);
        }
      }
      local_28 = local_28 + 1;
      local_34 = local_34 + 0x2e;
      piVar12 = piVar12 + 0x1f;
    } while (local_28 < *(int *)(local_10 + 0xac));
  }
  local_4c = *(int *)(local_10 + 0x80);
  local_24 = local_18[0x5f];
  local_14 = local_18[0x7f];
  local_28 = 0;
  if (0 < *(int *)(local_10 + 0x7c)) {
    do {
      if ((*(int *)(local_4c + 0x1b8) != 0) && (*(char *)(local_24 + 0x210) != '\0')) {
        *(undefined1 *)(local_24 + 0x210) = 0;
        if (*(char *)((int)local_18 + 0x19d) == '\0') {
          local_58 = 0;
          if (0 < *(int *)(local_4c + 0x1b8)) {
            local_2c = (float *)(*(int *)(local_24 + 0x20c) + 8);
            do {
              fVar2 = local_2c[-1];
              local_20 = (int *)*local_2c;
              if (0 < local_18[0x7d]) {
                iVar14 = local_18[0x7d];
                pfVar6 = (float *)(local_14 + 4);
                pcVar11 = (char *)(local_18[0x7e] + 1);
                do {
                  if ((*(char *)(pfVar6 + -1) != '\0') && (*pcVar11 == '\0')) {
                    local_20 = (int *)(*(float *)(*(int *)((int)pfVar6[1] + 0x74) + local_58 * 4) *
                                       *pfVar6 + (float)local_20);
                  }
                  pfVar6 = pfVar6 + 3;
                  pcVar11 = pcVar11 + 0x14;
                  iVar14 = iVar14 + -1;
                } while (iVar14 != 0);
              }
              if ((float)_DAT_007d5348 <= (float)local_20) {
                piVar12 = *(int **)((int)fVar2 + 0x10);
                iVar14 = 0;
                if (0 < *(int *)((int)fVar2 + 0xc)) {
                  do {
                    uVar15 = 0;
                    if (piVar12[1] != 0) {
                      iVar3 = *(int *)(((*piVar12 - *(int *)(local_10 + 0xb0)) / 0x7c) * 0xb8 +
                                       local_18[0x6c] + 0xa8);
                      piVar13 = (int *)piVar12[2];
                      do {
                        pfVar6 = (float *)(iVar3 + *piVar13 * 0x18);
                        uVar15 = uVar15 + 1;
                        *pfVar6 = (float)piVar13[1] * (float)local_20 + *pfVar6;
                        pfVar6[1] = (float)piVar13[2] * (float)local_20 + pfVar6[1];
                        pfVar6[2] = (float)piVar13[3] * (float)local_20 + pfVar6[2];
                        pfVar6[3] = (float)piVar13[4] * (float)local_20 + pfVar6[3];
                        pfVar6[4] = (float)piVar13[5] * (float)local_20 + pfVar6[4];
                        pfVar6[5] = (float)piVar13[6] * (float)local_20 + pfVar6[5];
                        piVar13 = piVar13 + 7;
                      } while (uVar15 < (uint)piVar12[1]);
                    }
                    iVar14 = iVar14 + 1;
                    piVar12 = piVar12 + 4;
                  } while (iVar14 < *(int *)((int)fVar2 + 0xc));
                }
              }
              local_2c = local_2c + 3;
              local_58 = local_58 + 1;
            } while (local_58 < *(int *)(local_4c + 0x1b8));
          }
        }
        local_2c = *(float **)(local_4c + 0x174);
        local_34 = *(int **)(local_24 + 0x208);
        local_4 = 0;
        if (0 < *(int *)(local_4c + 0x170)) {
          do {
            if (*(char *)((int)local_2c + 0x4a) != '\0') {
              local_3c = *(int *)((int)*local_2c + 0x1b0);
              iVar14 = (int)local_2c[0x13];
              local_44 = (int)local_2c[0x16];
              local_40 = (int)local_2c[0x17];
              local_1c = (uint)(*(int *)((int)local_2c[1] + 0x168) != 0);
              iVar3 = *(int *)((int)local_34 + 0xa8);
              local_8 = 0;
              if (0 < (int)local_2c[0x10]) {
                local_30 = (int *)(*(int *)((int)local_34 + 0xac) + 8);
                local_50 = (int *)((int)local_2c[0x11] + 0x108);
                do {
                  piVar12 = (int *)local_50[-6];
                  iVar19 = local_50[-0x3f];
                  if ((short)local_50[-0x41] == 0) {
                    if (bVar4) goto LAB_005e451a;
LAB_005e4bdf:
                    if (*(int *)local_30[1] == 0) {
                      piVar12 = (int *)local_50[-6];
                      switch((short)local_50[-0x41]) {
                      case 0:
                        puVar18 = (undefined4 *)(*local_30 + 0xfU & 0xfffffff0);
                        local_58 = 0;
                        if (3 < iVar19) {
                          iVar7 = (iVar19 - 4U >> 2) + 1;
                          local_58 = iVar7 * 4;
                          puVar9 = puVar18;
                          piVar13 = piVar12;
                          do {
                            iVar16 = iVar3 + *piVar13 * 0x18;
                            *puVar9 = *(undefined4 *)(iVar3 + *piVar13 * 0x18);
                            piVar12 = piVar13 + 4;
                            puVar18 = puVar9 + 0x20;
                            iVar7 = iVar7 + -1;
                            puVar9[1] = *(undefined4 *)(iVar16 + 4);
                            puVar9[2] = *(undefined4 *)(iVar16 + 8);
                            iVar16 = iVar3 + piVar13[1] * 0x18;
                            puVar9[8] = *(undefined4 *)(iVar3 + piVar13[1] * 0x18);
                            puVar9[9] = *(undefined4 *)(iVar16 + 4);
                            puVar9[10] = *(undefined4 *)(iVar16 + 8);
                            iVar16 = iVar3 + piVar13[2] * 0x18;
                            puVar9[0x10] = *(undefined4 *)(iVar3 + piVar13[2] * 0x18);
                            puVar9[0x11] = *(undefined4 *)(iVar16 + 4);
                            puVar9[0x12] = *(undefined4 *)(iVar16 + 8);
                            iVar16 = iVar3 + piVar13[3] * 0x18;
                            puVar9[0x18] = *(undefined4 *)(iVar3 + piVar13[3] * 0x18);
                            puVar9[0x19] = *(undefined4 *)(iVar16 + 4);
                            puVar9[0x1a] = *(undefined4 *)(iVar16 + 8);
                            puVar9 = puVar18;
                            piVar13 = piVar12;
                          } while (iVar7 != 0);
                        }
                        if (local_58 < iVar19) {
                          iVar19 = iVar19 - local_58;
                          do {
                            iVar7 = iVar3 + *piVar12 * 0x18;
                            *puVar18 = *(undefined4 *)(iVar3 + *piVar12 * 0x18);
                            piVar12 = piVar12 + 1;
                            iVar19 = iVar19 + -1;
                            puVar18[1] = *(undefined4 *)(iVar7 + 4);
                            puVar18[2] = *(undefined4 *)(iVar7 + 8);
                            puVar18 = puVar18 + 8;
                          } while (iVar19 != 0);
                        }
                        break;
                      case 1:
                        uVar15 = *local_30 + 0xfU & 0xfffffff0;
                        local_58 = 0;
                        if (3 < iVar19) {
                          iVar7 = (iVar19 - 4U >> 2) + 1;
                          local_58 = iVar7 * 4;
                          uVar10 = uVar15;
                          piVar13 = piVar12;
                          do {
                            iVar16 = iVar3 + *piVar13 * 0x18;
                            *(undefined4 *)(uVar10 + 0x10) =
                                 *(undefined4 *)(iVar3 + *piVar13 * 0x18);
                            piVar12 = piVar13 + 4;
                            uVar15 = uVar10 + 0xc0;
                            iVar7 = iVar7 + -1;
                            *(undefined4 *)(uVar10 + 0x14) = *(undefined4 *)(iVar16 + 4);
                            *(undefined4 *)(uVar10 + 0x18) = *(undefined4 *)(iVar16 + 8);
                            iVar16 = iVar3 + piVar13[1] * 0x18;
                            *(undefined4 *)(uVar10 + 0x40) =
                                 *(undefined4 *)(iVar3 + piVar13[1] * 0x18);
                            *(undefined4 *)(uVar10 + 0x44) = *(undefined4 *)(iVar16 + 4);
                            *(undefined4 *)(uVar10 + 0x48) = *(undefined4 *)(iVar16 + 8);
                            iVar16 = iVar3 + piVar13[2] * 0x18;
                            *(undefined4 *)(uVar10 + 0x70) =
                                 *(undefined4 *)(iVar3 + piVar13[2] * 0x18);
                            *(undefined4 *)(uVar10 + 0x74) = *(undefined4 *)(iVar16 + 4);
                            *(undefined4 *)(uVar10 + 0x78) = *(undefined4 *)(iVar16 + 8);
                            iVar16 = iVar3 + piVar13[3] * 0x18;
                            *(undefined4 *)(uVar10 + 0xa0) =
                                 *(undefined4 *)(iVar3 + piVar13[3] * 0x18);
                            *(undefined4 *)(uVar10 + 0xa4) = *(undefined4 *)(iVar16 + 4);
                            *(undefined4 *)(uVar10 + 0xa8) = *(undefined4 *)(iVar16 + 8);
                            uVar10 = uVar15;
                            piVar13 = piVar12;
                          } while (iVar7 != 0);
                        }
                        if (local_58 < iVar19) {
                          iVar19 = iVar19 - local_58;
                          puVar18 = (undefined4 *)(uVar15 + 0x14);
                          do {
                            iVar7 = iVar3 + *piVar12 * 0x18;
                            puVar18[-1] = *(undefined4 *)(iVar3 + *piVar12 * 0x18);
                            piVar12 = piVar12 + 1;
                            iVar19 = iVar19 + -1;
                            *puVar18 = *(undefined4 *)(iVar7 + 4);
                            puVar18[1] = *(undefined4 *)(iVar7 + 8);
                            puVar18 = puVar18 + 0xc;
                          } while (iVar19 != 0);
                        }
                        break;
                      case 2:
                        if (0 < iVar19) {
                          puVar18 = (undefined4 *)((*local_30 + 0xfU & 0xfffffff0) + 0x30);
                          do {
                            iVar7 = iVar3 + *piVar12 * 0x18;
                            *puVar18 = *(undefined4 *)(iVar3 + *piVar12 * 0x18);
                            puVar18[1] = *(undefined4 *)(iVar7 + 4);
                            puVar18[2] = *(undefined4 *)(iVar7 + 8);
                            puVar18 = puVar18 + 0x10;
                            piVar12 = piVar12 + 1;
                            iVar19 = iVar19 + -1;
                          } while (iVar19 != 0);
                        }
                        break;
                      case 3:
                        puVar18 = (undefined4 *)(*local_30 + 0xfU & 0xfffffff0);
                        local_58 = 0;
                        if (3 < iVar19) {
                          iVar7 = (iVar19 - 4U >> 2) + 1;
                          local_58 = iVar7 * 4;
                          piVar13 = piVar12;
                          do {
                            iVar16 = iVar3 + *piVar13 * 0x18;
                            *puVar18 = *(undefined4 *)(iVar3 + *piVar13 * 0x18);
                            piVar12 = piVar13 + 4;
                            puVar18[1] = *(undefined4 *)(iVar16 + 4);
                            puVar18[2] = *(undefined4 *)(iVar16 + 8);
                            puVar18 = (undefined4 *)
                                      ((int)puVar18 + (uint)*(ushort *)((int)local_50 + -0x102));
                            puVar9 = (undefined4 *)(iVar3 + piVar13[1] * 0x18);
                            *puVar18 = *puVar9;
                            puVar18[1] = puVar9[1];
                            puVar18[2] = puVar9[2];
                            puVar18 = (undefined4 *)
                                      ((int)puVar18 + (uint)*(ushort *)((int)local_50 + -0x102));
                            puVar9 = (undefined4 *)(iVar3 + piVar13[2] * 0x18);
                            *puVar18 = *puVar9;
                            puVar18[1] = puVar9[1];
                            puVar18[2] = puVar9[2];
                            puVar18 = (undefined4 *)
                                      ((int)puVar18 + (uint)*(ushort *)((int)local_50 + -0x102));
                            puVar9 = (undefined4 *)(iVar3 + piVar13[3] * 0x18);
                            *puVar18 = *puVar9;
                            puVar18[1] = puVar9[1];
                            puVar18[2] = puVar9[2];
                            puVar18 = (undefined4 *)
                                      ((int)puVar18 + (uint)*(ushort *)((int)local_50 + -0x102));
                            iVar7 = iVar7 + -1;
                            piVar13 = piVar12;
                          } while (iVar7 != 0);
                        }
                        if (local_58 < iVar19) {
                          iVar19 = iVar19 - local_58;
                          do {
                            iVar7 = iVar3 + *piVar12 * 0x18;
                            *puVar18 = *(undefined4 *)(iVar3 + *piVar12 * 0x18);
                            piVar12 = piVar12 + 1;
                            puVar18[1] = *(undefined4 *)(iVar7 + 4);
                            puVar18[2] = *(undefined4 *)(iVar7 + 8);
                            puVar18 = (undefined4 *)
                                      ((int)puVar18 + (uint)*(ushort *)((int)local_50 + -0x102));
                            iVar19 = iVar19 + -1;
                          } while (iVar19 != 0);
                        }
                      }
                    }
                  }
                  else {
                    if (DAT_00a37dc8 == 0) goto LAB_005e4bdf;
LAB_005e451a:
                    if (*(int *)local_30[1] != 0) {
                      local_20 = piVar12;
                      iVar7 = FUN_005d5fa0(*(int *)local_30[1],0,0,&local_48,0x2000,0);
                      if (iVar7 == 0) {
                        local_38 = *(int *)(local_50[7] + 0x10);
                        sVar1 = (short)local_50[-0x41];
                        if (sVar1 == 0) {
                          if (local_1c == 0) {
                            if (0 < iVar19) {
                              puVar18 = (undefined4 *)(local_48 + 0x18);
                              local_c = iVar19;
                              do {
                                iVar7 = *piVar12 * local_44 + local_40;
                                puVar9 = (undefined4 *)(iVar3 + *piVar12 * 0x18);
                                puVar5 = (undefined4 *)(local_3c + *(int *)(iVar7 + 4) * 0x24);
                                puVar18[-6] = *puVar9;
                                puVar18[-5] = puVar9[1];
                                puVar18[-4] = puVar9[2];
                                puVar18[-3] = *puVar5;
                                puVar18[-2] = puVar5[1];
                                puVar18[-1] = puVar5[2];
                                *puVar18 = *(undefined4 *)(iVar7 + 8);
                                puVar18[1] = *(undefined4 *)(iVar7 + 0xc);
                                if (0 < iVar14) {
                                  puVar9 = (undefined4 *)(iVar7 + 0x18);
                                  puVar5 = puVar18 + 3;
                                  iVar7 = iVar14;
                                  do {
                                    puVar5[-1] = puVar9[-1];
                                    iVar7 = iVar7 + -1;
                                    *puVar5 = *puVar9;
                                    puVar5[1] = 0x3f800000;
                                    puVar5[2] = 0x3f800000;
                                    puVar9 = puVar9 + 2;
                                    puVar5 = puVar5 + 4;
                                  } while (iVar7 != 0);
                                }
                                puVar18 = (undefined4 *)((int)puVar18 + local_38);
                                piVar12 = piVar12 + 1;
                                local_c = local_c + -1;
                              } while (local_c != 0);
                            }
                          }
                          else if (0 < iVar19) {
                            puVar18 = (undefined4 *)(local_48 + 0x18);
                            local_c = iVar19;
                            do {
                              iVar7 = *piVar12 * local_44 + local_40;
                              puVar9 = (undefined4 *)(iVar3 + *piVar12 * 0x18);
                              puVar5 = (undefined4 *)(local_3c + *(int *)(iVar7 + 4) * 0x24);
                              puVar18[-6] = *puVar9;
                              puVar18[-5] = puVar9[1];
                              puVar18[-4] = puVar9[2];
                              puVar18[3] = *puVar5;
                              puVar18[4] = puVar5[1];
                              puVar18[5] = puVar5[2];
                              *puVar18 = puVar5[6];
                              puVar18[1] = puVar5[7];
                              puVar18[2] = puVar5[8];
                              puVar18[-3] = puVar5[3];
                              puVar18[-2] = puVar5[4];
                              puVar18[-1] = puVar5[5];
                              puVar18[6] = *(undefined4 *)(iVar7 + 8);
                              puVar18[7] = *(undefined4 *)(iVar7 + 0xc);
                              if (0 < iVar14) {
                                puVar9 = (undefined4 *)(iVar7 + 0x18);
                                puVar5 = puVar18 + 9;
                                iVar7 = iVar14;
                                do {
                                  puVar5[-1] = puVar9[-1];
                                  iVar7 = iVar7 + -1;
                                  *puVar5 = *puVar9;
                                  puVar5[1] = 0x3f800000;
                                  puVar5[2] = 0x3f800000;
                                  puVar9 = puVar9 + 2;
                                  puVar5 = puVar5 + 4;
                                } while (iVar7 != 0);
                              }
                              puVar18 = (undefined4 *)((int)puVar18 + local_38);
                              piVar12 = piVar12 + 1;
                              local_c = local_c + -1;
                            } while (local_c != 0);
                            local_c = 0;
                          }
                        }
                        else if (sVar1 == 1) {
                          puVar18 = (undefined4 *)(*local_50 + 0xfU & 0xfffffff0);
                          if (local_1c == 0) {
                            if (0 < iVar19) {
                              pcVar11 = (char *)(local_48 + 0xd);
                              local_c = iVar19;
                              do {
                                iVar7 = *piVar12 * local_44 + local_40;
                                local_20 = (int *)(local_3c + *(int *)(iVar7 + 4) * 0x24);
                                puVar9 = (undefined4 *)(iVar3 + *piVar12 * 0x18);
                                *(undefined4 *)(pcVar11 + -0xd) = *puVar9;
                                *(undefined4 *)(pcVar11 + -9) = puVar9[1];
                                *(undefined4 *)(pcVar11 + -5) = puVar9[2];
                                pcVar11[-1] = *(char *)(puVar18 + 0xb) * '\x03';
                                *pcVar11 = *(char *)((int)puVar18 + 0x2d) * '\x03';
                                pcVar11[1] = *(char *)((int)puVar18 + 0x2e) * '\x03';
                                pcVar11[2] = *(char *)((int)puVar18 + 0x2f) * '\x03';
                                *(undefined4 *)(pcVar11 + 3) = *puVar18;
                                *(undefined4 *)(pcVar11 + 7) = puVar18[1];
                                *(undefined4 *)(pcVar11 + 0xb) = puVar18[2];
                                *(undefined4 *)(pcVar11 + 0xf) = puVar18[3];
                                *(int *)(pcVar11 + 0x13) = *local_20;
                                *(int *)(pcVar11 + 0x17) = local_20[1];
                                *(int *)(pcVar11 + 0x1b) = local_20[2];
                                *(undefined4 *)(pcVar11 + 0x1f) = *(undefined4 *)(iVar7 + 8);
                                *(undefined4 *)(pcVar11 + 0x23) = *(undefined4 *)(iVar7 + 0xc);
                                if (0 < iVar14) {
                                  pcVar8 = pcVar11 + 0x2b;
                                  iVar16 = iVar14;
                                  puVar9 = (undefined4 *)(iVar7 + 0x18);
                                  do {
                                    *(undefined4 *)(pcVar8 + -4) = puVar9[-1];
                                    iVar16 = iVar16 + -1;
                                    *(undefined4 *)pcVar8 = *puVar9;
                                    pcVar8[4] = '\0';
                                    pcVar8[5] = '\0';
                                    pcVar8[6] = -0x80;
                                    pcVar8[7] = '?';
                                    pcVar8[8] = '\0';
                                    pcVar8[9] = '\0';
                                    pcVar8[10] = -0x80;
                                    pcVar8[0xb] = '?';
                                    pcVar8 = pcVar8 + 0x10;
                                    puVar9 = puVar9 + 2;
                                  } while (iVar16 != 0);
                                }
                                pcVar11 = pcVar11 + local_38;
                                puVar18 = puVar18 + 0xc;
                                piVar12 = piVar12 + 1;
                                local_c = local_c + -1;
                              } while (local_c != 0);
                              local_c = 0;
                            }
                          }
                          else if (0 < iVar19) {
                            pcVar11 = (char *)(local_48 + 0xd);
                            local_c = iVar19;
                            do {
                              iVar16 = *piVar12;
                              iVar17 = iVar16 * local_44 + local_40;
                              puVar9 = (undefined4 *)(local_3c + *(int *)(iVar17 + 4) * 0x24);
                              iVar7 = iVar3 + iVar16 * 0x18;
                              *(undefined4 *)(pcVar11 + -0xd) =
                                   *(undefined4 *)(iVar3 + iVar16 * 0x18);
                              *(undefined4 *)(pcVar11 + -9) = *(undefined4 *)(iVar7 + 4);
                              *(undefined4 *)(pcVar11 + -5) = *(undefined4 *)(iVar7 + 8);
                              pcVar11[-1] = *(char *)(puVar18 + 0xb) * '\x03';
                              *pcVar11 = *(char *)((int)puVar18 + 0x2d) * '\x03';
                              pcVar11[1] = *(char *)((int)puVar18 + 0x2e) * '\x03';
                              pcVar11[2] = *(char *)((int)puVar18 + 0x2f) * '\x03';
                              *(undefined4 *)(pcVar11 + 3) = *puVar18;
                              *(undefined4 *)(pcVar11 + 7) = puVar18[1];
                              *(undefined4 *)(pcVar11 + 0xb) = puVar18[2];
                              *(undefined4 *)(pcVar11 + 0xf) = puVar18[3];
                              *(undefined4 *)(pcVar11 + 0x2b) = *puVar9;
                              *(undefined4 *)(pcVar11 + 0x2f) = puVar9[1];
                              *(undefined4 *)(pcVar11 + 0x33) = puVar9[2];
                              *(undefined4 *)(pcVar11 + 0x1f) = puVar9[6];
                              *(undefined4 *)(pcVar11 + 0x23) = puVar9[7];
                              *(undefined4 *)(pcVar11 + 0x27) = puVar9[8];
                              *(undefined4 *)(pcVar11 + 0x13) = puVar9[3];
                              *(undefined4 *)(pcVar11 + 0x17) = puVar9[4];
                              *(undefined4 *)(pcVar11 + 0x1b) = puVar9[5];
                              *(undefined4 *)(pcVar11 + 0x37) = *(undefined4 *)(iVar17 + 8);
                              *(undefined4 *)(pcVar11 + 0x3b) = *(undefined4 *)(iVar17 + 0xc);
                              if (0 < iVar14) {
                                pcVar8 = pcVar11 + 0x43;
                                iVar7 = iVar14;
                                puVar9 = (undefined4 *)(iVar17 + 0x18);
                                do {
                                  *(undefined4 *)(pcVar8 + -4) = puVar9[-1];
                                  iVar7 = iVar7 + -1;
                                  *(undefined4 *)pcVar8 = *puVar9;
                                  pcVar8[4] = '\0';
                                  pcVar8[5] = '\0';
                                  pcVar8[6] = -0x80;
                                  pcVar8[7] = '?';
                                  pcVar8[8] = '\0';
                                  pcVar8[9] = '\0';
                                  pcVar8[10] = -0x80;
                                  pcVar8[0xb] = '?';
                                  pcVar8 = pcVar8 + 0x10;
                                  puVar9 = puVar9 + 2;
                                } while (iVar7 != 0);
                              }
                              pcVar11 = pcVar11 + local_38;
                              piVar12 = local_20 + 1;
                              puVar18 = puVar18 + 0xc;
                              local_c = local_c + -1;
                              local_20 = piVar12;
                            } while (local_c != 0);
                            local_c = 0;
                          }
                        }
                        else if (sVar1 == 2) {
                          puVar18 = (undefined4 *)(*local_50 + 0xfU & 0xfffffff0);
                          if (local_1c == 0) {
                            if (0 < iVar19) {
                              pcVar11 = (char *)(local_48 + 0xd);
                              local_c = iVar19;
                              do {
                                iVar7 = *piVar12 * local_44 + local_40;
                                local_20 = (int *)(local_3c + *(int *)(iVar7 + 4) * 0x24);
                                puVar9 = (undefined4 *)(iVar3 + *piVar12 * 0x18);
                                *(undefined4 *)(pcVar11 + -0xd) = *puVar9;
                                *(undefined4 *)(pcVar11 + -9) = puVar9[1];
                                *(undefined4 *)(pcVar11 + -5) = puVar9[2];
                                pcVar11[-1] = *(char *)(puVar18 + 0xb) * '\x03';
                                *pcVar11 = *(char *)((int)puVar18 + 0x2d) * '\x03';
                                pcVar11[1] = *(char *)((int)puVar18 + 0x2e) * '\x03';
                                pcVar11[2] = *(char *)((int)puVar18 + 0x2f) * '\x03';
                                pcVar11[3] = *(char *)(puVar18 + 0xf) * '\x03';
                                pcVar11[4] = *(char *)((int)puVar18 + 0x3d) * '\x03';
                                pcVar11[5] = *(char *)((int)puVar18 + 0x3e) * '\x03';
                                pcVar11[6] = *(char *)((int)puVar18 + 0x3f) * '\x03';
                                *(undefined4 *)(pcVar11 + 7) = *puVar18;
                                *(undefined4 *)(pcVar11 + 0xb) = puVar18[1];
                                *(undefined4 *)(pcVar11 + 0xf) = puVar18[2];
                                *(undefined4 *)(pcVar11 + 0x13) = puVar18[3];
                                *(undefined4 *)(pcVar11 + 0x17) = puVar18[4];
                                *(undefined4 *)(pcVar11 + 0x1b) = puVar18[5];
                                *(undefined4 *)(pcVar11 + 0x1f) = puVar18[6];
                                *(undefined4 *)(pcVar11 + 0x23) = puVar18[7];
                                *(int *)(pcVar11 + 0x27) = *local_20;
                                *(int *)(pcVar11 + 0x2b) = local_20[1];
                                *(int *)(pcVar11 + 0x2f) = local_20[2];
                                *(undefined4 *)(pcVar11 + 0x33) = *(undefined4 *)(iVar7 + 8);
                                *(undefined4 *)(pcVar11 + 0x37) = *(undefined4 *)(iVar7 + 0xc);
                                if (0 < iVar14) {
                                  pcVar8 = pcVar11 + 0x3f;
                                  iVar16 = iVar14;
                                  puVar9 = (undefined4 *)(iVar7 + 0x18);
                                  do {
                                    *(undefined4 *)(pcVar8 + -4) = puVar9[-1];
                                    iVar16 = iVar16 + -1;
                                    *(undefined4 *)pcVar8 = *puVar9;
                                    pcVar8[4] = '\0';
                                    pcVar8[5] = '\0';
                                    pcVar8[6] = -0x80;
                                    pcVar8[7] = '?';
                                    pcVar8[8] = '\0';
                                    pcVar8[9] = '\0';
                                    pcVar8[10] = -0x80;
                                    pcVar8[0xb] = '?';
                                    pcVar8 = pcVar8 + 0x10;
                                    puVar9 = puVar9 + 2;
                                  } while (iVar16 != 0);
                                }
                                pcVar11 = pcVar11 + local_38;
                                puVar18 = puVar18 + 0x10;
                                piVar12 = piVar12 + 1;
                                local_c = local_c + -1;
                              } while (local_c != 0);
                              local_c = 0;
                            }
                          }
                          else if (0 < iVar19) {
                            pcVar11 = (char *)(local_48 + 0xd);
                            local_c = iVar19;
                            do {
                              iVar16 = *piVar12;
                              iVar17 = iVar16 * local_44 + local_40;
                              puVar9 = (undefined4 *)(local_3c + *(int *)(iVar17 + 4) * 0x24);
                              iVar7 = iVar3 + iVar16 * 0x18;
                              *(undefined4 *)(pcVar11 + -0xd) =
                                   *(undefined4 *)(iVar3 + iVar16 * 0x18);
                              *(undefined4 *)(pcVar11 + -9) = *(undefined4 *)(iVar7 + 4);
                              *(undefined4 *)(pcVar11 + -5) = *(undefined4 *)(iVar7 + 8);
                              pcVar11[-1] = *(char *)(puVar18 + 0xb) * '\x03';
                              *pcVar11 = *(char *)((int)puVar18 + 0x2d) * '\x03';
                              pcVar11[1] = *(char *)((int)puVar18 + 0x2e) * '\x03';
                              pcVar11[2] = *(char *)((int)puVar18 + 0x2f) * '\x03';
                              pcVar11[3] = *(char *)(puVar18 + 0xf) * '\x03';
                              pcVar11[4] = *(char *)((int)puVar18 + 0x3d) * '\x03';
                              pcVar11[5] = *(char *)((int)puVar18 + 0x3e) * '\x03';
                              pcVar11[6] = *(char *)((int)puVar18 + 0x3f) * '\x03';
                              *(undefined4 *)(pcVar11 + 7) = *puVar18;
                              *(undefined4 *)(pcVar11 + 0xb) = puVar18[1];
                              *(undefined4 *)(pcVar11 + 0xf) = puVar18[2];
                              *(undefined4 *)(pcVar11 + 0x13) = puVar18[3];
                              *(undefined4 *)(pcVar11 + 0x17) = puVar18[4];
                              *(undefined4 *)(pcVar11 + 0x1b) = puVar18[5];
                              *(undefined4 *)(pcVar11 + 0x1f) = puVar18[6];
                              *(undefined4 *)(pcVar11 + 0x23) = puVar18[7];
                              *(undefined4 *)(pcVar11 + 0x3f) = *puVar9;
                              *(undefined4 *)(pcVar11 + 0x43) = puVar9[1];
                              *(undefined4 *)(pcVar11 + 0x47) = puVar9[2];
                              *(undefined4 *)(pcVar11 + 0x33) = puVar9[6];
                              *(undefined4 *)(pcVar11 + 0x37) = puVar9[7];
                              *(undefined4 *)(pcVar11 + 0x3b) = puVar9[8];
                              *(undefined4 *)(pcVar11 + 0x27) = puVar9[3];
                              *(undefined4 *)(pcVar11 + 0x2b) = puVar9[4];
                              *(undefined4 *)(pcVar11 + 0x2f) = puVar9[5];
                              *(undefined4 *)(pcVar11 + 0x4b) = *(undefined4 *)(iVar17 + 8);
                              *(undefined4 *)(pcVar11 + 0x4f) = *(undefined4 *)(iVar17 + 0xc);
                              if (0 < iVar14) {
                                pcVar8 = pcVar11 + 0x57;
                                iVar7 = iVar14;
                                puVar9 = (undefined4 *)(iVar17 + 0x18);
                                do {
                                  *(undefined4 *)(pcVar8 + -4) = puVar9[-1];
                                  iVar7 = iVar7 + -1;
                                  *(undefined4 *)pcVar8 = *puVar9;
                                  pcVar8[4] = '\0';
                                  pcVar8[5] = '\0';
                                  pcVar8[6] = -0x80;
                                  pcVar8[7] = '?';
                                  pcVar8[8] = '\0';
                                  pcVar8[9] = '\0';
                                  pcVar8[10] = -0x80;
                                  pcVar8[0xb] = '?';
                                  pcVar8 = pcVar8 + 0x10;
                                  puVar9 = puVar9 + 2;
                                } while (iVar7 != 0);
                              }
                              pcVar11 = pcVar11 + local_38;
                              piVar12 = local_20 + 1;
                              puVar18 = puVar18 + 0x10;
                              local_c = local_c + -1;
                              local_20 = piVar12;
                            } while (local_c != 0);
                            local_c = 0;
                          }
                        }
                        FUN_005d4be0(*(undefined4 *)local_30[1]);
                        goto LAB_005e4bdf;
                      }
                    }
                  }
                  local_30 = local_30 + 6;
                  local_8 = local_8 + 1;
                  local_50 = local_50 + 0x4e;
                } while (local_8 < (int)local_2c[0x10]);
              }
            }
            local_2c = local_2c + 0x1f;
            local_34 = (int *)((int)local_34 + 0xb8);
            local_4 = local_4 + 1;
          } while (local_4 < *(int *)(local_4c + 0x170));
        }
      }
      local_24 = local_24 + 0x2b8;
      local_4c = local_4c + 0x1d4;
      local_14 = local_14 + local_18[0x7d] * 0xc;
      local_28 = local_28 + 1;
    } while (local_28 < *(int *)(local_10 + 0x7c));
  }
  return 0;
}

