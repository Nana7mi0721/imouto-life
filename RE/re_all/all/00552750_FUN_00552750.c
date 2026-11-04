
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00552750(uint param_1,uint param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  double dVar8;
  byte bVar9;
  undefined1 uVar10;
  byte bVar11;
  short sVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  float *pfVar17;
  float *pfVar18;
  int iVar19;
  int iVar20;
  float *pfVar21;
  float *pfVar22;
  undefined4 *puVar23;
  undefined2 *puVar24;
  uint uVar25;
  float *pfVar26;
  float fVar27;
  undefined2 *puVar28;
  short *psVar29;
  byte *pbVar30;
  undefined1 *puVar31;
  byte *pbVar32;
  undefined1 *puVar33;
  undefined4 *puVar34;
  undefined4 *puVar35;
  short *psVar36;
  uint uVar37;
  short sVar38;
  int iVar39;
  float *pfVar40;
  int iVar41;
  int iVar42;
  undefined4 *puVar43;
  float *pfVar44;
  int iVar45;
  int iVar46;
  int iVar47;
  undefined2 uVar48;
  int iVar49;
  int iVar50;
  float *pfVar51;
  float *pfVar52;
  int iVar53;
  int iVar54;
  byte local_76;
  byte local_75;
  int local_74;
  int local_70;
  int local_64;
  float local_60;
  float local_5c;
  float local_54;
  float local_50;
  float local_44;
  float *local_3c;
  float *local_38;
  int local_34;
  float *local_30;
  float *local_2c;
  float *local_28;
  int local_20;
  int local_18;
  float *local_14;
  float *local_10;
  float *local_c;
  float *local_8;
  float *local_4;
  
  if (((((DAT_00cc50a0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc50c8)) ||
      ((DAT_00cc50d0 <= (int)(param_1 & 0xffff) ||
       (piVar2 = *(int **)(DAT_00cc50a4 + (param_1 & 0xffff) * 4), piVar2 == (int *)0x0)))) ||
     (*piVar2 * 0x10000 != (param_1 & 0x3ff0000))) {
    return 0xffffffff;
  }
  if ((((piVar2[0xc] == 1) || ((int)param_2 < 0)) ||
      (((param_2 & 0x7c000000) != DAT_00cc50c8 ||
       (((DAT_00cc50d0 <= (int)(param_2 & 0xffff) ||
         (piVar3 = *(int **)(DAT_00cc50a4 + (param_2 & 0xffff) * 4), piVar3 == (int *)0x0)) ||
        (*piVar3 * 0x10000 != (param_2 & 0x3ff0000))))))) || (piVar3[0xc] == 1)) {
    return 0xffffffff;
  }
  iVar41 = piVar3[0x12];
  iVar4 = piVar2[0x12];
  if (iVar4 == iVar41) {
    return 0xffffffff;
  }
  if ((short)piVar2[0xd] != (short)piVar3[0xd]) {
    return 0xffffffff;
  }
  if (*(short *)((int)piVar2 + 0x36) != *(short *)((int)piVar3 + 0x36)) {
    return 0xffffffff;
  }
  if (piVar2[0xe] != piVar3[0xe]) {
    return 0xffffffff;
  }
  if (*(short *)((int)piVar2 + 0x42) != *(short *)((int)piVar3 + 0x42)) {
    return 0xffffffff;
  }
  dVar8 = ((double)iVar4 / (double)iVar41) * _DAT_007d62b8;
  if (iVar4 < iVar41) {
    iVar13 = FUN_0050e240(dVar8);
    dVar8 = (double)piVar2[0xe];
    iVar4 = piVar2[0x12];
    iVar41 = piVar3[0x12];
    if (piVar2[0xe] < 0) {
      dVar8 = dVar8 + _DAT_007d49f0;
    }
    iVar14 = FUN_0050e240(dVar8 * _DAT_008044f8);
    dVar8 = (double)piVar2[0xe];
    if (piVar2[0xe] < 0) {
      dVar8 = dVar8 + _DAT_007d49f0;
    }
    iVar15 = FUN_0050e240(dVar8 * _DAT_008298b8);
    dVar8 = (double)piVar2[0xe];
    if (piVar2[0xe] < 0) {
      dVar8 = dVar8 + _DAT_007d49f0;
    }
    iVar16 = FUN_0050e240(dVar8 * _DAT_007d62b0);
    if ((short)piVar2[0xd] == 1) {
      if (*(short *)((int)piVar2 + 0x42) == 8) {
        iVar49 = piVar2[0x13];
        iVar45 = piVar3[0x13];
        if (*(short *)((int)piVar2 + 0x36) != 1) {
          if (*(short *)((int)piVar2 + 0x36) != 2) {
            return 0;
          }
          iVar39 = iVar16 * 2;
          iVar53 = 0;
          for (iVar50 = iVar53; (iVar39 < iVar4 && (iVar16 * 2 + iVar50 < iVar41));
              iVar50 = iVar50 + local_64 + (int)fVar27) {
            local_54 = 0.0;
            fVar27 = (float)iVar15;
            if (iVar15 <= iVar16) {
              pbVar32 = (byte *)(iVar49 + iVar53 * 2);
              iVar39 = ((iVar53 + iVar15) * 2 - (int)pbVar32) + iVar49;
              local_60 = (float)iVar15;
              do {
                iVar54 = 0;
                if (0 < iVar14) {
                  pbVar30 = pbVar32;
                  iVar46 = iVar14;
                  do {
                    iVar19 = (pbVar30[iVar39] - 0x80) * (*pbVar30 - 0x80);
                    iVar54 = iVar54 + ((int)(iVar19 + (iVar19 >> 0x1f & 0x7fU)) >> 7);
                    pbVar30 = pbVar30 + 2;
                    iVar46 = iVar46 + -1;
                  } while (iVar46 != 0);
                }
                if ((int)local_54 < iVar54) {
                  fVar27 = local_60;
                  local_54 = (float)iVar54;
                }
                local_60 = (float)((int)local_60 + 1);
                iVar39 = iVar39 + 2;
              } while ((int)local_60 <= iVar16);
            }
            iVar39 = 0;
            puVar31 = (undefined1 *)(iVar45 + iVar50 * 2);
            if (0 < (int)fVar27) {
              iVar47 = ((int)fVar27 + iVar53) * 2 - (int)puVar31;
              iVar54 = (iVar53 * 2 - (int)puVar31) + iVar49;
              iVar19 = ((int)fVar27 + iVar50) * 2 - (int)puVar31;
              iVar46 = (int)fVar27;
              do {
                *puVar31 = puVar31[iVar54];
                iVar20 = (uint)(byte)puVar31[iVar47 + iVar49] * iVar46;
                iVar42 = (uint)(byte)puVar31[iVar54] * iVar39;
                iVar39 = iVar39 + 1;
                iVar46 = iVar46 + -1;
                puVar31 = puVar31 + 2;
                puVar31[iVar19 + iVar45 + -2] = (char)((iVar20 + iVar42) / (int)fVar27);
              } while (iVar39 < (int)fVar27);
            }
            iVar39 = iVar50 + (int)fVar27 * 2;
            if ((iVar39 < iVar41) && ((int)fVar27 + iVar53 < iVar4)) {
              iVar54 = ((int)fVar27 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
              local_64 = (int)(iVar54 + (iVar54 >> 0x1f & 0x1ffU)) >> 9;
              iVar54 = local_64 - (int)fVar27;
              puVar31 = (undefined1 *)(iVar49 + ((int)fVar27 + iVar53) * 2);
              if (iVar4 < iVar54 + (int)fVar27 + iVar53) {
                iVar54 = (iVar4 - (int)fVar27) - iVar53;
                local_64 = iVar54 + (int)fVar27;
              }
              if (iVar41 < iVar54 + (int)fVar27 * 2 + iVar50) {
                iVar54 = (iVar41 + (int)fVar27 * -2) - iVar50;
                local_64 = iVar54 + (int)fVar27;
              }
              if (0 < iVar54) {
                iVar39 = iVar39 * 2 - (int)puVar31;
                do {
                  puVar31[iVar45 + iVar39] = *puVar31;
                  puVar31 = puVar31 + 2;
                  iVar54 = iVar54 + -1;
                } while (iVar54 != 0);
              }
            }
            iVar53 = iVar53 + local_64;
            iVar39 = iVar16 * 2 + iVar53;
          }
          do {
            if (iVar41 <= iVar50) {
LAB_005561fb:
              iVar39 = iVar16 * 2;
              local_70 = 0;
              for (local_74 = 0; (iVar39 < iVar4 && (iVar16 * 2 + local_74 < iVar41));
                  local_74 = local_74 + local_64 + (int)fVar27) {
                local_54 = 0.0;
                fVar27 = (float)iVar15;
                if (iVar15 <= iVar16) {
                  pbVar32 = (byte *)(iVar49 + 1 + local_70 * 2);
                  iVar39 = ((local_70 + iVar15) * 2 - (int)pbVar32) + 1 + iVar49;
                  local_60 = (float)iVar15;
                  do {
                    iVar50 = 0;
                    if (0 < iVar14) {
                      pbVar30 = pbVar32;
                      iVar53 = iVar14;
                      do {
                        iVar54 = (pbVar30[iVar39] - 0x80) * (*pbVar30 - 0x80);
                        iVar50 = iVar50 + ((int)(iVar54 + (iVar54 >> 0x1f & 0x7fU)) >> 7);
                        pbVar30 = pbVar30 + 2;
                        iVar53 = iVar53 + -1;
                      } while (iVar53 != 0);
                    }
                    if ((int)local_54 < iVar50) {
                      fVar27 = local_60;
                      local_54 = (float)iVar50;
                    }
                    local_60 = (float)((int)local_60 + 1);
                    iVar39 = iVar39 + 2;
                  } while ((int)local_60 <= iVar16);
                }
                iVar39 = 0;
                puVar31 = (undefined1 *)(iVar45 + 1 + local_74 * 2);
                if (0 < (int)fVar27) {
                  iVar50 = (local_70 * 2 - (int)puVar31) + 1 + iVar49;
                  puVar33 = puVar31;
                  iVar53 = (int)fVar27;
                  do {
                    *puVar33 = puVar33[iVar50];
                    iVar54 = (uint)(byte)puVar33[iVar49 + 1 +
                                                 (((int)fVar27 + local_70) * 2 - (int)puVar31)] *
                             iVar53;
                    iVar46 = (uint)(byte)puVar33[iVar50] * iVar39;
                    iVar39 = iVar39 + 1;
                    iVar53 = iVar53 + -1;
                    puVar33[(((int)fVar27 + local_74) * 2 - (int)puVar31) + 1 + iVar45] =
                         (char)((iVar54 + iVar46) / (int)fVar27);
                    puVar33 = puVar33 + 2;
                  } while (iVar39 < (int)fVar27);
                }
                iVar39 = local_74 + (int)fVar27 * 2;
                if ((iVar39 < iVar41) && ((int)fVar27 + local_70 < iVar4)) {
                  iVar50 = ((int)fVar27 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
                  local_64 = (int)(iVar50 + (iVar50 >> 0x1f & 0x1ffU)) >> 9;
                  iVar50 = local_64 - (int)fVar27;
                  puVar31 = (undefined1 *)(iVar49 + 1 + ((int)fVar27 + local_70) * 2);
                  if (iVar4 < iVar50 + (int)fVar27 + local_70) {
                    iVar50 = (iVar4 - (int)fVar27) - local_70;
                    local_64 = iVar50 + (int)fVar27;
                  }
                  if (iVar41 < iVar50 + (int)fVar27 * 2 + local_74) {
                    iVar50 = (iVar41 + (int)fVar27 * -2) - local_74;
                    local_64 = iVar50 + (int)fVar27;
                  }
                  if (0 < iVar50) {
                    iVar39 = iVar39 * 2 - (int)puVar31;
                    do {
                      puVar31[iVar39 + 1 + iVar45] = *puVar31;
                      puVar31 = puVar31 + 2;
                      iVar50 = iVar50 + -1;
                    } while (iVar50 != 0);
                  }
                }
                local_70 = local_70 + local_64;
                iVar39 = iVar16 * 2 + local_70;
              }
              if (iVar41 <= local_74) {
                return 0;
              }
              while (local_70 < iVar4) {
                local_54 = 0.0;
                fVar27 = (float)iVar15;
                if (iVar15 <= iVar16) {
                  pbVar32 = (byte *)(iVar49 + 1 + local_70 * 2);
                  local_c = (float *)-iVar15;
                  local_10 = (float *)(((local_70 + iVar15) * 2 - (int)pbVar32) + 1 + iVar49);
                  local_60 = (float)iVar15;
                  do {
                    iVar39 = 0;
                    if (0 < iVar14) {
                      iVar50 = (int)local_60 + local_70;
                      pbVar30 = pbVar32;
                      local_4 = (float *)iVar14;
                      do {
                        if ((int)local_c + iVar50 < iVar4) {
                          iVar53 = *pbVar30 - 0x80;
                        }
                        else {
                          iVar53 = 0;
                        }
                        if (iVar50 < iVar4) {
                          iVar54 = pbVar30[(int)local_10] - 0x80;
                        }
                        else {
                          iVar54 = 0;
                        }
                        iVar39 = iVar39 + ((int)(iVar54 * iVar53 + (iVar54 * iVar53 >> 0x1f & 0x7fU)
                                                ) >> 7);
                        iVar50 = iVar50 + 1;
                        pbVar30 = pbVar30 + 2;
                        local_4 = (float *)((int)local_4 + -1);
                      } while (local_4 != (float *)0x0);
                    }
                    if ((int)local_54 < iVar39) {
                      fVar27 = local_60;
                      local_54 = (float)iVar39;
                    }
                    local_c = (float *)((int)local_c + -1);
                    local_10 = (float *)((int)local_10 + 2);
                    local_60 = (float)((int)local_60 + 1);
                  } while ((int)local_60 <= iVar16);
                }
                iVar39 = 0;
                pbVar32 = (byte *)(iVar45 + 1 + local_74 * 2);
                if (0 < (int)fVar27) {
                  iVar50 = local_74 + (int)fVar27;
                  iVar53 = (local_70 + (int)fVar27) * 2 - (int)pbVar32;
                  iVar46 = local_70 * 2 - (int)pbVar32;
                  iVar54 = iVar50 * 2 - (int)pbVar32;
                  local_10 = (float *)fVar27;
                  do {
                    if (iVar39 + local_74 + (local_70 - local_74) < iVar4) {
                      bVar9 = pbVar32[iVar46 + 1 + iVar49];
                    }
                    else {
                      bVar9 = 0x80;
                    }
                    if ((local_70 - local_74) + iVar50 < iVar4) {
                      bVar11 = pbVar32[iVar53 + 1 + iVar49];
                    }
                    else {
                      bVar11 = 0x80;
                    }
                    if (local_74 + iVar39 < iVar41) {
                      *pbVar32 = bVar9;
                    }
                    if (iVar50 < iVar41) {
                      pbVar32[iVar54 + 1 + iVar45] =
                           (byte)((int)((uint)bVar11 * (int)local_10 + (uint)bVar9 * iVar39) /
                                 (int)fVar27);
                    }
                    local_10 = (float *)((int)local_10 + -1);
                    iVar39 = iVar39 + 1;
                    iVar50 = iVar50 + 1;
                    pbVar32 = pbVar32 + 2;
                  } while (iVar39 < (int)fVar27);
                }
                iVar39 = (int)fVar27 * 2 + local_74;
                if ((iVar39 < iVar41) && (iVar50 = local_70 + (int)fVar27, iVar50 < iVar4)) {
                  puVar31 = (undefined1 *)(iVar49 + 1 + iVar50 * 2);
                  iVar53 = ((int)fVar27 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
                  local_64 = (int)(iVar53 + (iVar53 >> 0x1f & 0x1ffU)) >> 9;
                  iVar53 = local_64 - (int)fVar27;
                  if (iVar4 < iVar53 + (int)fVar27 + local_70) {
                    iVar53 = (iVar4 - (int)fVar27) - local_70;
                    local_64 = iVar53 + (int)fVar27;
                  }
                  if (iVar41 < iVar53 + (int)fVar27 * 2 + local_74) {
                    iVar53 = (iVar41 + (int)fVar27 * -2) - local_74;
                    local_64 = iVar53 + (int)fVar27;
                  }
                  if (0 < iVar53) {
                    iVar39 = iVar39 * 2 - (int)puVar31;
                    do {
                      uVar10 = 0x80;
                      if (iVar50 < iVar4) {
                        uVar10 = *puVar31;
                      }
                      puVar31[iVar39 + 1 + iVar45] = uVar10;
                      iVar50 = iVar50 + 1;
                      puVar31 = puVar31 + 2;
                      iVar53 = iVar53 + -1;
                    } while (iVar53 != 0);
                  }
                }
                local_70 = local_70 + local_64;
                local_74 = local_74 + local_64 + (int)fVar27;
                if (iVar41 <= local_74) {
                  return 0;
                }
              }
              if (iVar41 <= local_74) {
                return 0;
              }
              iVar41 = iVar41 - local_74;
              puVar31 = (undefined1 *)(iVar45 + 1 + local_74 * 2);
              if (iVar41 < 1) {
                return 0;
              }
              do {
                *puVar31 = 0x80;
                puVar31 = puVar31 + 2;
                iVar41 = iVar41 + -1;
              } while (iVar41 != 0);
              return 0;
            }
            if (iVar4 <= iVar53) {
              if (iVar50 < iVar41) {
                iVar39 = iVar41 - iVar50;
                puVar31 = (undefined1 *)(iVar45 + iVar50 * 2);
                if (0 < iVar39) {
                  do {
                    *puVar31 = 0x80;
                    puVar31 = puVar31 + 2;
                    iVar39 = iVar39 + -1;
                  } while (iVar39 != 0);
                }
              }
              goto LAB_005561fb;
            }
            local_54 = 0.0;
            fVar27 = (float)iVar15;
            if (iVar15 <= iVar16) {
              local_c = (float *)-iVar15;
              pbVar32 = (byte *)(iVar49 + iVar53 * 2);
              local_10 = (float *)(((iVar53 + iVar15) * 2 - (int)pbVar32) + iVar49);
              local_60 = (float)iVar15;
              do {
                iVar39 = 0;
                if (0 < iVar14) {
                  iVar54 = (int)local_60 + iVar53;
                  pbVar30 = pbVar32;
                  local_4 = (float *)iVar14;
                  do {
                    if ((int)local_c + iVar54 < iVar4) {
                      iVar46 = *pbVar30 - 0x80;
                    }
                    else {
                      iVar46 = 0;
                    }
                    if (iVar54 < iVar4) {
                      iVar19 = pbVar30[(int)local_10] - 0x80;
                    }
                    else {
                      iVar19 = 0;
                    }
                    iVar39 = iVar39 + ((int)(iVar19 * iVar46 + (iVar19 * iVar46 >> 0x1f & 0x7fU)) >>
                                      7);
                    iVar54 = iVar54 + 1;
                    pbVar30 = pbVar30 + 2;
                    local_4 = (float *)((int)local_4 + -1);
                  } while (local_4 != (float *)0x0);
                }
                if ((int)local_54 < iVar39) {
                  fVar27 = local_60;
                  local_54 = (float)iVar39;
                }
                local_c = (float *)((int)local_c + -1);
                local_10 = (float *)((int)local_10 + 2);
                local_60 = (float)((int)local_60 + 1);
              } while ((int)local_60 <= iVar16);
            }
            iVar39 = 0;
            pbVar32 = (byte *)(iVar45 + iVar50 * 2);
            if (0 < (int)fVar27) {
              iVar54 = iVar50 + (int)fVar27;
              iVar47 = iVar53 * 2 - (int)pbVar32;
              iVar46 = (iVar53 + (int)fVar27) * 2 - (int)pbVar32;
              iVar19 = iVar54 * 2 - (int)pbVar32;
              local_10 = (float *)fVar27;
              do {
                if ((iVar53 - iVar50) + iVar39 + iVar50 < iVar4) {
                  local_76 = pbVar32[iVar47 + iVar49];
                }
                else {
                  local_76 = 0x80;
                }
                if ((iVar53 - iVar50) + iVar54 < iVar4) {
                  bVar9 = pbVar32[iVar46 + iVar49];
                }
                else {
                  bVar9 = 0x80;
                }
                if (iVar39 + iVar50 < iVar41) {
                  *pbVar32 = local_76;
                }
                if (iVar54 < iVar41) {
                  pbVar32[iVar19 + iVar45] =
                       (byte)((int)((uint)bVar9 * (int)local_10 + (uint)local_76 * iVar39) /
                             (int)fVar27);
                }
                local_10 = (float *)((int)local_10 + -1);
                iVar39 = iVar39 + 1;
                iVar54 = iVar54 + 1;
                pbVar32 = pbVar32 + 2;
              } while (iVar39 < (int)fVar27);
            }
            iVar39 = iVar50 + (int)fVar27 * 2;
            if ((iVar39 < iVar41) && (iVar54 = iVar53 + (int)fVar27, iVar54 < iVar4)) {
              puVar31 = (undefined1 *)(iVar49 + iVar54 * 2);
              iVar46 = ((int)fVar27 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
              local_64 = (int)(iVar46 + (iVar46 >> 0x1f & 0x1ffU)) >> 9;
              iVar46 = local_64 - (int)fVar27;
              if (iVar4 < iVar46 + (int)fVar27 + iVar53) {
                iVar46 = (iVar4 - (int)fVar27) - iVar53;
                local_64 = iVar46 + (int)fVar27;
              }
              if (iVar41 < iVar46 + (int)fVar27 * 2 + iVar50) {
                iVar46 = (iVar41 + (int)fVar27 * -2) - iVar50;
                local_64 = iVar46 + (int)fVar27;
              }
              if (0 < iVar46) {
                iVar39 = iVar39 * 2 - (int)puVar31;
                do {
                  uVar10 = 0x80;
                  if (iVar54 < iVar4) {
                    uVar10 = *puVar31;
                  }
                  puVar31[iVar45 + iVar39] = uVar10;
                  iVar54 = iVar54 + 1;
                  puVar31 = puVar31 + 2;
                  iVar46 = iVar46 + -1;
                } while (iVar46 != 0);
              }
            }
            iVar53 = iVar53 + local_64;
            iVar50 = iVar50 + local_64 + (int)fVar27;
          } while( true );
        }
        local_70 = 0;
        local_74 = 0;
        if (iVar16 * 2 < iVar4) {
          do {
            if (iVar41 <= iVar16 * 2 + local_74) break;
            local_54 = 0.0;
            fVar27 = (float)iVar15;
            if (iVar15 <= iVar16) {
              local_60 = (float)iVar15;
              do {
                iVar50 = 0;
                iVar39 = 0;
                pbVar32 = (byte *)(iVar49 + local_70);
                if (0 < iVar14) {
                  do {
                    iVar53 = (((byte *)(iVar49 + local_70))[iVar50 + (int)local_60] - 0x80) *
                             (*pbVar32 - 0x80);
                    iVar50 = iVar50 + 1;
                    iVar39 = iVar39 + ((int)(iVar53 + (iVar53 >> 0x1f & 0x7fU)) >> 7);
                    pbVar32 = pbVar32 + 1;
                  } while (iVar50 < iVar14);
                }
                if ((int)local_54 < iVar39) {
                  fVar27 = local_60;
                  local_54 = (float)iVar39;
                }
                local_60 = (float)((int)local_60 + 1);
              } while ((int)local_60 <= iVar16);
            }
            iVar50 = 0;
            iVar39 = iVar45 + local_74;
            if (0 < (int)fVar27) {
              pbVar32 = (byte *)(((iVar39 - iVar45) - local_74) + iVar49 + local_70);
              iVar53 = (int)fVar27;
              local_4 = (float *)(iVar39 + (int)fVar27);
              do {
                *(byte *)(iVar39 + iVar50) = *pbVar32;
                iVar54 = (uint)pbVar32[(int)fVar27] * iVar53;
                iVar46 = (uint)*pbVar32 * iVar50;
                iVar50 = iVar50 + 1;
                iVar53 = iVar53 + -1;
                pbVar32 = pbVar32 + 1;
                *(char *)local_4 = (char)((iVar54 + iVar46) / (int)fVar27);
                local_4 = (float *)((int)local_4 + 1);
              } while (iVar50 < (int)fVar27);
            }
            if ((local_74 + (int)fVar27 * 2 < iVar41) && ((int)fVar27 + local_70 < iVar4)) {
              iVar39 = ((int)fVar27 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
              local_64 = (int)(iVar39 + (iVar39 >> 0x1f & 0x1ffU)) >> 9;
              iVar39 = iVar49 + (int)fVar27 + local_70;
              iVar50 = local_64 - (int)fVar27;
              if (iVar4 < iVar50 + (int)fVar27 + local_70) {
                iVar50 = (iVar4 - (int)fVar27) - local_70;
                local_64 = iVar50 + (int)fVar27;
              }
              if (iVar41 < iVar50 + (int)fVar27 * 2 + local_74) {
                iVar50 = (iVar41 + (int)fVar27 * -2) - local_74;
                local_64 = iVar50 + (int)fVar27;
              }
              iVar53 = 0;
              if (0 < iVar50) {
                puVar31 = (undefined1 *)
                          (((iVar39 - iVar49) - local_70) + iVar45 + (int)fVar27 + local_74);
                do {
                  *puVar31 = *(undefined1 *)(iVar39 + iVar53);
                  iVar53 = iVar53 + 1;
                  puVar31 = puVar31 + 1;
                } while (iVar53 < iVar50);
              }
            }
            local_70 = local_70 + local_64;
            local_74 = local_74 + local_64 + (int)fVar27;
          } while (iVar16 * 2 + local_70 < iVar4);
        }
        if (iVar41 <= local_74) {
          return 0;
        }
        while (local_70 < iVar4) {
          local_54 = 0.0;
          fVar27 = (float)iVar15;
          if (iVar15 <= iVar16) {
            local_10 = (float *)(local_70 + iVar15);
            local_c = (float *)-iVar15;
            local_60 = (float)iVar15;
            do {
              iVar39 = 0;
              if (0 < iVar14) {
                iVar50 = iVar14;
                pfVar52 = local_10;
                pbVar32 = (byte *)(iVar49 + local_70);
                do {
                  if ((int)local_c + (int)pfVar52 < iVar4) {
                    iVar53 = *pbVar32 - 0x80;
                  }
                  else {
                    iVar53 = 0;
                  }
                  if ((int)pfVar52 < iVar4) {
                    iVar54 = *(byte *)(iVar49 + (int)pfVar52) - 0x80;
                  }
                  else {
                    iVar54 = 0;
                  }
                  iVar39 = iVar39 + ((int)(iVar54 * iVar53 + (iVar54 * iVar53 >> 0x1f & 0x7fU)) >> 7
                                    );
                  pfVar52 = (float *)((int)pfVar52 + 1);
                  pbVar32 = pbVar32 + 1;
                  iVar50 = iVar50 + -1;
                } while (iVar50 != 0);
              }
              if ((int)local_54 < iVar39) {
                fVar27 = local_60;
                local_54 = (float)iVar39;
              }
              local_c = (float *)((int)local_c + -1);
              local_10 = (float *)((int)local_10 + 1);
              local_60 = (float)((int)local_60 + 1);
            } while ((int)local_60 <= iVar16);
          }
          local_54 = 0.0;
          if (0 < (int)fVar27) {
            iVar39 = (int)fVar27 + local_70;
            puVar31 = (undefined1 *)(iVar45 + (int)fVar27 + local_74);
            iVar50 = local_74;
            local_8 = (float *)fVar27;
            do {
              if ((local_70 - local_74) + iVar50 < iVar4) {
                bVar9 = *(byte *)((iVar49 - (int)fVar27) + iVar39);
              }
              else {
                bVar9 = 0x80;
              }
              if (iVar39 < iVar4) {
                local_76 = *(byte *)(iVar39 + iVar49);
              }
              else {
                local_76 = 0x80;
              }
              if (iVar50 < iVar41) {
                *(byte *)(iVar45 + iVar50) = bVar9;
              }
              if ((local_74 - local_70) + iVar39 < iVar41) {
                *puVar31 = (char)((int)((uint)local_76 * (int)local_8 + (uint)bVar9 * (int)local_54)
                                 / (int)fVar27);
              }
              local_8 = (float *)((int)local_8 + -1);
              local_54 = (float)((int)local_54 + 1);
              iVar50 = iVar50 + 1;
              iVar39 = iVar39 + 1;
              puVar31 = puVar31 + 1;
            } while ((int)local_54 < (int)fVar27);
          }
          iVar39 = (int)fVar27 * 2;
          if ((iVar39 + local_74 < iVar41) && (iVar50 = (int)fVar27 + local_70, iVar50 < iVar4)) {
            iVar53 = ((int)fVar27 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
            local_64 = (int)(iVar53 + (iVar53 >> 0x1f & 0x1ffU)) >> 9;
            iVar53 = local_64 - (int)fVar27;
            if (iVar4 < iVar53 + (int)fVar27 + local_70) {
              iVar53 = (iVar4 - (int)fVar27) - local_70;
              local_64 = iVar53 + (int)fVar27;
            }
            if (iVar41 < iVar53 + iVar39 + local_74) {
              iVar53 = (iVar41 + (int)fVar27 * -2) - local_74;
              local_64 = iVar53 + (int)fVar27;
            }
            iVar54 = 0;
            if (0 < iVar53) {
              puVar31 = (undefined1 *)(iVar39 + iVar45 + local_74);
              do {
                if (iVar50 < iVar4) {
                  uVar10 = *(undefined1 *)(iVar49 + (int)fVar27 + local_70 + iVar54);
                }
                else {
                  uVar10 = 0x80;
                }
                *puVar31 = uVar10;
                iVar54 = iVar54 + 1;
                iVar50 = iVar50 + 1;
                puVar31 = puVar31 + 1;
              } while (iVar54 < iVar53);
            }
          }
          local_70 = local_70 + local_64;
          local_74 = local_74 + local_64 + (int)fVar27;
          if (iVar41 <= local_74) {
            return 0;
          }
        }
        if (iVar41 <= local_74) {
          return 0;
        }
        goto LAB_00556c48;
      }
      if (*(short *)((int)piVar2 + 0x42) != 0x10) {
        return 0;
      }
      iVar49 = piVar2[0x13];
      iVar45 = piVar3[0x13];
      if (*(short *)((int)piVar2 + 0x36) != 1) {
        if (*(short *)((int)piVar2 + 0x36) != 2) {
          return 0;
        }
        iVar39 = iVar16 * 2;
        iVar53 = 0;
        for (iVar50 = 0; (iVar39 < iVar4 && (iVar16 * 2 + iVar50 < iVar41));
            iVar50 = iVar50 + local_64 + (int)fVar27) {
          local_54 = 0.0;
          fVar27 = (float)iVar15;
          if (iVar15 <= iVar16) {
            psVar29 = (short *)(iVar49 + iVar53 * 4);
            iVar39 = ((iVar53 + iVar15) * 4 - (int)psVar29) + iVar49;
            local_60 = (float)iVar15;
            do {
              iVar54 = 0;
              if (0 < iVar14) {
                psVar36 = psVar29;
                iVar46 = iVar14;
                do {
                  iVar19 = (int)*(short *)(iVar39 + (int)psVar36) * (int)*psVar36;
                  iVar54 = iVar54 + ((int)(iVar19 + (iVar19 >> 0x1f & 0x7fffU)) >> 0xf);
                  psVar36 = psVar36 + 2;
                  iVar46 = iVar46 + -1;
                } while (iVar46 != 0);
              }
              if ((int)local_54 < iVar54) {
                fVar27 = local_60;
                local_54 = (float)iVar54;
              }
              local_60 = (float)((int)local_60 + 1);
              iVar39 = iVar39 + 4;
            } while ((int)local_60 <= iVar16);
          }
          iVar39 = 0;
          puVar24 = (undefined2 *)(iVar45 + iVar50 * 4);
          if (0 < (int)fVar27) {
            iVar47 = ((int)fVar27 + iVar53) * 4 - (int)puVar24;
            iVar54 = (iVar53 * 4 - (int)puVar24) + iVar49;
            iVar19 = ((int)fVar27 + iVar50) * 4 - (int)puVar24;
            iVar46 = (int)fVar27;
            do {
              *puVar24 = *(undefined2 *)((int)puVar24 + iVar54);
              iVar20 = *(short *)(iVar47 + iVar49 + (int)puVar24) * iVar46;
              iVar42 = *(short *)((int)puVar24 + iVar54) * iVar39;
              iVar39 = iVar39 + 1;
              iVar46 = iVar46 + -1;
              puVar24 = puVar24 + 2;
              *(short *)(iVar19 + iVar45 + -4 + (int)puVar24) =
                   (short)((iVar20 + iVar42) / (int)fVar27);
            } while (iVar39 < (int)fVar27);
          }
          iVar39 = iVar50 + (int)fVar27 * 2;
          if ((iVar39 < iVar41) && ((int)fVar27 + iVar53 < iVar4)) {
            iVar54 = ((int)fVar27 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
            local_64 = (int)(iVar54 + (iVar54 >> 0x1f & 0x1ffU)) >> 9;
            iVar54 = local_64 - (int)fVar27;
            puVar24 = (undefined2 *)(iVar49 + ((int)fVar27 + iVar53) * 4);
            if (iVar4 < iVar54 + (int)fVar27 + iVar53) {
              iVar54 = (iVar4 - (int)fVar27) - iVar53;
              local_64 = iVar54 + (int)fVar27;
            }
            if (iVar41 < iVar54 + (int)fVar27 * 2 + iVar50) {
              iVar54 = (iVar41 + (int)fVar27 * -2) - iVar50;
              local_64 = iVar54 + (int)fVar27;
            }
            if (0 < iVar54) {
              iVar39 = iVar39 * 4 - (int)puVar24;
              do {
                *(undefined2 *)(iVar39 + iVar45 + (int)puVar24) = *puVar24;
                puVar24 = puVar24 + 2;
                iVar54 = iVar54 + -1;
              } while (iVar54 != 0);
            }
          }
          iVar53 = iVar53 + local_64;
          iVar39 = iVar16 * 2 + iVar53;
        }
        do {
          if (iVar41 <= iVar50) {
LAB_0055522d:
            local_70 = 0;
            iVar39 = iVar16 * 2;
            for (local_74 = 0; (iVar39 < iVar4 && (iVar16 * 2 + local_74 < iVar41));
                local_74 = local_74 + local_64 + (int)fVar27) {
              local_54 = 0.0;
              fVar27 = (float)iVar15;
              if (iVar15 <= iVar16) {
                psVar29 = (short *)(iVar49 + 2 + local_70 * 4);
                iVar39 = ((local_70 + iVar15) * 4 - (int)psVar29) + 2 + iVar49;
                local_60 = (float)iVar15;
                do {
                  iVar50 = 0;
                  if (0 < iVar14) {
                    psVar36 = psVar29;
                    iVar53 = iVar14;
                    do {
                      iVar54 = (int)*(short *)((int)psVar36 + iVar39) * (int)*psVar36;
                      iVar50 = iVar50 + ((int)(iVar54 + (iVar54 >> 0x1f & 0x7fffU)) >> 0xf);
                      psVar36 = psVar36 + 2;
                      iVar53 = iVar53 + -1;
                    } while (iVar53 != 0);
                  }
                  if ((int)local_54 < iVar50) {
                    fVar27 = local_60;
                    local_54 = (float)iVar50;
                  }
                  local_60 = (float)((int)local_60 + 1);
                  iVar39 = iVar39 + 4;
                } while ((int)local_60 <= iVar16);
              }
              puVar24 = (undefined2 *)(iVar45 + 2 + local_74 * 4);
              if (0 < (int)fVar27) {
                iVar39 = (local_70 * 4 - (int)puVar24) + 2 + iVar49;
                iVar53 = 0;
                puVar28 = puVar24;
                iVar50 = (int)fVar27;
                do {
                  *puVar28 = *(undefined2 *)((int)puVar28 + iVar39);
                  iVar54 = *(short *)((int)puVar28 +
                                     iVar49 + 2 + (((int)fVar27 + local_70) * 4 - (int)puVar24)) *
                           iVar50;
                  iVar46 = *(short *)((int)puVar28 + iVar39) * iVar53;
                  iVar53 = iVar53 + 1;
                  iVar50 = iVar50 + -1;
                  *(short *)((int)puVar28 +
                            (((int)fVar27 + local_74) * 4 - (int)puVar24) + 2 + iVar45) =
                       (short)((iVar54 + iVar46) / (int)fVar27);
                  puVar28 = puVar28 + 2;
                } while (iVar53 < (int)fVar27);
              }
              iVar39 = local_74 + (int)fVar27 * 2;
              if ((iVar39 < iVar41) && ((int)fVar27 + local_70 < iVar4)) {
                iVar50 = ((int)fVar27 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
                local_64 = (int)(iVar50 + (iVar50 >> 0x1f & 0x1ffU)) >> 9;
                iVar50 = local_64 - (int)fVar27;
                puVar24 = (undefined2 *)(iVar49 + 2 + ((int)fVar27 + local_70) * 4);
                if (iVar4 < iVar50 + (int)fVar27 + local_70) {
                  iVar50 = (iVar4 - (int)fVar27) - local_70;
                  local_64 = iVar50 + (int)fVar27;
                }
                if (iVar41 < iVar50 + (int)fVar27 * 2 + local_74) {
                  iVar50 = (iVar41 + (int)fVar27 * -2) - local_74;
                  local_64 = iVar50 + (int)fVar27;
                }
                if (0 < iVar50) {
                  iVar39 = iVar39 * 4 - (int)puVar24;
                  do {
                    *(undefined2 *)((int)puVar24 + iVar39 + 2 + iVar45) = *puVar24;
                    puVar24 = puVar24 + 2;
                    iVar50 = iVar50 + -1;
                  } while (iVar50 != 0);
                }
              }
              local_70 = local_70 + local_64;
              iVar39 = iVar16 * 2 + local_70;
            }
            if (iVar41 <= local_74) {
              return 0;
            }
            while (local_70 < iVar4) {
              local_54 = 0.0;
              fVar27 = (float)iVar15;
              if (iVar15 <= iVar16) {
                psVar29 = (short *)(iVar49 + 2 + local_70 * 4);
                local_c = (float *)-iVar15;
                local_10 = (float *)(((local_70 + iVar15) * 4 - (int)psVar29) + 2 + iVar49);
                local_60 = (float)iVar15;
                do {
                  iVar39 = 0;
                  if (0 < iVar14) {
                    iVar53 = local_70 + (int)local_60;
                    iVar50 = iVar14;
                    psVar36 = psVar29;
                    do {
                      if ((int)local_c + iVar53 < iVar4) {
                        iVar54 = (int)*psVar36;
                      }
                      else {
                        iVar54 = 0;
                      }
                      if (iVar53 < iVar4) {
                        iVar46 = (int)*(short *)((int)local_10 + (int)psVar36);
                      }
                      else {
                        iVar46 = 0;
                      }
                      iVar39 = iVar39 + ((int)(iVar46 * iVar54 + (iVar46 * iVar54 >> 0x1f & 0x7fffU)
                                              ) >> 0xf);
                      iVar53 = iVar53 + 1;
                      psVar36 = psVar36 + 2;
                      iVar50 = iVar50 + -1;
                    } while (iVar50 != 0);
                  }
                  if ((int)local_54 < iVar39) {
                    fVar27 = local_60;
                    local_54 = (float)iVar39;
                  }
                  local_c = (float *)((int)local_c + -1);
                  local_10 = (float *)((int)local_10 + 4);
                  local_60 = (float)((int)local_60 + 1);
                } while ((int)local_60 <= iVar16);
              }
              iVar39 = 0;
              psVar29 = (short *)(iVar45 + 2 + local_74 * 4);
              if (0 < (int)fVar27) {
                iVar50 = (int)fVar27 + local_74;
                iVar53 = (local_70 + (int)fVar27) * 4 - (int)psVar29;
                iVar46 = local_70 * 4 - (int)psVar29;
                iVar54 = iVar50 * 4 - (int)psVar29;
                local_10 = (float *)fVar27;
                do {
                  if (iVar39 + local_74 + (local_70 - local_74) < iVar4) {
                    sVar38 = *(short *)((int)psVar29 + iVar49 + 2 + iVar46);
                  }
                  else {
                    sVar38 = 0;
                  }
                  if ((local_70 - local_74) + iVar50 < iVar4) {
                    sVar12 = *(short *)((int)psVar29 + iVar53 + 2 + iVar49);
                  }
                  else {
                    sVar12 = 0;
                  }
                  if (local_74 + iVar39 < iVar41) {
                    *psVar29 = sVar38;
                  }
                  if (iVar50 < iVar41) {
                    *(short *)((int)psVar29 + iVar54 + 2 + iVar45) =
                         (short)(((int)sVar12 * (int)local_10 + sVar38 * iVar39) / (int)fVar27);
                  }
                  local_10 = (float *)((int)local_10 + -1);
                  iVar39 = iVar39 + 1;
                  iVar50 = iVar50 + 1;
                  psVar29 = psVar29 + 2;
                } while (iVar39 < (int)fVar27);
              }
              iVar39 = local_74 + (int)fVar27 * 2;
              if ((iVar39 < iVar41) && (iVar50 = (int)fVar27 + local_70, iVar50 < iVar4)) {
                puVar24 = (undefined2 *)(iVar49 + 2 + iVar50 * 4);
                iVar53 = ((int)fVar27 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
                local_64 = (int)(iVar53 + (iVar53 >> 0x1f & 0x1ffU)) >> 9;
                iVar53 = local_64 - (int)fVar27;
                if (iVar4 < iVar53 + (int)fVar27 + local_70) {
                  iVar53 = (iVar4 - (int)fVar27) - local_70;
                  local_64 = iVar53 + (int)fVar27;
                }
                if (iVar41 < iVar53 + (int)fVar27 * 2 + local_74) {
                  iVar53 = (iVar41 + (int)fVar27 * -2) - local_74;
                  local_64 = iVar53 + (int)fVar27;
                }
                if (0 < iVar53) {
                  iVar39 = iVar39 * 4 - (int)puVar24;
                  do {
                    if (iVar50 < iVar4) {
                      uVar48 = *puVar24;
                    }
                    else {
                      uVar48 = 0;
                    }
                    *(undefined2 *)((int)puVar24 + iVar39 + 2 + iVar45) = uVar48;
                    iVar50 = iVar50 + 1;
                    puVar24 = puVar24 + 2;
                    iVar53 = iVar53 + -1;
                  } while (iVar53 != 0);
                }
              }
              local_70 = local_70 + local_64;
              local_74 = local_74 + local_64 + (int)fVar27;
              if (iVar41 <= local_74) {
                return 0;
              }
            }
            if (iVar41 <= local_74) {
              return 0;
            }
            iVar41 = iVar41 - local_74;
            puVar24 = (undefined2 *)(iVar45 + 2 + local_74 * 4);
            if (iVar41 < 1) {
              return 0;
            }
            do {
              *puVar24 = 0;
              puVar24 = puVar24 + 2;
              iVar41 = iVar41 + -1;
            } while (iVar41 != 0);
            return 0;
          }
          if (iVar4 <= iVar53) {
            if (iVar50 < iVar41) {
              iVar39 = iVar41 - iVar50;
              puVar24 = (undefined2 *)(iVar45 + iVar50 * 4);
              if (0 < iVar39) {
                do {
                  *puVar24 = 0;
                  puVar24 = puVar24 + 2;
                  iVar39 = iVar39 + -1;
                } while (iVar39 != 0);
              }
            }
            goto LAB_0055522d;
          }
          local_54 = 0.0;
          fVar27 = (float)iVar15;
          if (iVar15 <= iVar16) {
            local_c = (float *)-iVar15;
            psVar29 = (short *)(iVar49 + iVar53 * 4);
            local_10 = (float *)(((iVar53 + iVar15) * 4 - (int)psVar29) + iVar49);
            local_60 = (float)iVar15;
            do {
              iVar39 = 0;
              if (0 < iVar14) {
                iVar46 = (int)local_60 + iVar53;
                iVar54 = iVar14;
                psVar36 = psVar29;
                do {
                  if (iVar46 + (int)local_c < iVar4) {
                    iVar19 = (int)*psVar36;
                  }
                  else {
                    iVar19 = 0;
                  }
                  if (iVar46 < iVar4) {
                    iVar47 = (int)*(short *)((int)local_10 + (int)psVar36);
                  }
                  else {
                    iVar47 = 0;
                  }
                  iVar39 = iVar39 + ((int)(iVar47 * iVar19 + (iVar47 * iVar19 >> 0x1f & 0x7fffU)) >>
                                    0xf);
                  iVar46 = iVar46 + 1;
                  psVar36 = psVar36 + 2;
                  iVar54 = iVar54 + -1;
                } while (iVar54 != 0);
              }
              if ((int)local_54 < iVar39) {
                fVar27 = local_60;
                local_54 = (float)iVar39;
              }
              local_c = (float *)((int)local_c + -1);
              local_10 = (float *)((int)local_10 + 4);
              local_60 = (float)((int)local_60 + 1);
            } while ((int)local_60 <= iVar16);
          }
          iVar39 = 0;
          psVar29 = (short *)(iVar45 + iVar50 * 4);
          if (0 < (int)fVar27) {
            iVar54 = (int)fVar27 + iVar50;
            iVar46 = (iVar53 + (int)fVar27) * 4 - (int)psVar29;
            iVar47 = iVar53 * 4 - (int)psVar29;
            iVar19 = iVar54 * 4 - (int)psVar29;
            local_10 = (float *)fVar27;
            do {
              if (iVar39 + iVar50 + (iVar53 - iVar50) < iVar4) {
                sVar38 = *(short *)(iVar47 + iVar49 + (int)psVar29);
              }
              else {
                sVar38 = 0;
              }
              if ((iVar53 - iVar50) + iVar54 < iVar4) {
                sVar12 = *(short *)(iVar46 + iVar49 + (int)psVar29);
              }
              else {
                sVar12 = 0;
              }
              if (iVar50 + iVar39 < iVar41) {
                *psVar29 = sVar38;
              }
              if (iVar54 < iVar41) {
                *(short *)(iVar19 + iVar45 + (int)psVar29) =
                     (short)(((int)sVar12 * (int)local_10 + sVar38 * iVar39) / (int)fVar27);
              }
              local_10 = (float *)((int)local_10 + -1);
              iVar39 = iVar39 + 1;
              iVar54 = iVar54 + 1;
              psVar29 = psVar29 + 2;
            } while (iVar39 < (int)fVar27);
          }
          iVar39 = iVar50 + (int)fVar27 * 2;
          if ((iVar39 < iVar41) && (iVar54 = (int)fVar27 + iVar53, iVar54 < iVar4)) {
            puVar24 = (undefined2 *)(iVar49 + iVar54 * 4);
            iVar46 = ((int)fVar27 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
            local_64 = (int)(iVar46 + (iVar46 >> 0x1f & 0x1ffU)) >> 9;
            iVar46 = local_64 - (int)fVar27;
            if (iVar4 < iVar46 + (int)fVar27 + iVar53) {
              iVar46 = (iVar4 - (int)fVar27) - iVar53;
              local_64 = iVar46 + (int)fVar27;
            }
            if (iVar41 < iVar46 + (int)fVar27 * 2 + iVar50) {
              iVar46 = (iVar41 + (int)fVar27 * -2) - iVar50;
              local_64 = iVar46 + (int)fVar27;
            }
            if (0 < iVar46) {
              iVar39 = iVar39 * 4 - (int)puVar24;
              do {
                if (iVar54 < iVar4) {
                  uVar48 = *puVar24;
                }
                else {
                  uVar48 = 0;
                }
                *(undefined2 *)((int)puVar24 + iVar45 + iVar39) = uVar48;
                iVar54 = iVar54 + 1;
                puVar24 = puVar24 + 2;
                iVar46 = iVar46 + -1;
              } while (iVar46 != 0);
            }
          }
          iVar53 = iVar53 + local_64;
          iVar50 = iVar50 + local_64 + (int)fVar27;
        } while( true );
      }
      iVar39 = iVar16 * 2;
      local_70 = 0;
      for (local_74 = 0; (iVar39 < iVar4 && (iVar16 * 2 + local_74 < iVar41));
          local_74 = local_74 + local_64 + (int)fVar27) {
        local_54 = 0.0;
        fVar27 = (float)iVar15;
        if (iVar15 <= iVar16) {
          psVar29 = (short *)(iVar49 + local_70 * 2);
          iVar39 = ((local_70 + iVar15) * 2 - (int)psVar29) + iVar49;
          local_60 = (float)iVar15;
          do {
            iVar50 = 0;
            if (0 < iVar14) {
              psVar36 = psVar29;
              iVar53 = iVar14;
              do {
                iVar54 = (int)*(short *)(iVar39 + (int)psVar36) * (int)*psVar36;
                iVar50 = iVar50 + ((int)(iVar54 + (iVar54 >> 0x1f & 0x7fffU)) >> 0xf);
                psVar36 = psVar36 + 1;
                iVar53 = iVar53 + -1;
              } while (iVar53 != 0);
            }
            if ((int)local_54 < iVar50) {
              fVar27 = local_60;
              local_54 = (float)iVar50;
            }
            local_60 = (float)((int)local_60 + 1);
            iVar39 = iVar39 + 2;
          } while ((int)local_60 <= iVar16);
        }
        puVar24 = (undefined2 *)(iVar45 + local_74 * 2);
        if (0 < (int)fVar27) {
          iVar54 = ((int)fVar27 + local_70) * 2 - (int)puVar24;
          iVar39 = (local_70 * 2 - (int)puVar24) + iVar49;
          iVar53 = ((int)fVar27 + local_74) * 2 - (int)puVar24;
          iVar46 = 0;
          iVar50 = (int)fVar27;
          do {
            *puVar24 = *(undefined2 *)((int)puVar24 + iVar39);
            iVar19 = *(short *)(iVar54 + iVar49 + (int)puVar24) * iVar50;
            iVar47 = *(short *)((int)puVar24 + iVar39) * iVar46;
            iVar46 = iVar46 + 1;
            iVar50 = iVar50 + -1;
            puVar24 = puVar24 + 1;
            *(short *)(iVar53 + iVar45 + -2 + (int)puVar24) =
                 (short)((iVar19 + iVar47) / (int)fVar27);
          } while (iVar46 < (int)fVar27);
        }
        iVar39 = local_74 + (int)fVar27 * 2;
        if ((iVar39 < iVar41) && ((int)fVar27 + local_70 < iVar4)) {
          iVar50 = ((int)fVar27 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
          local_64 = (int)(iVar50 + (iVar50 >> 0x1f & 0x1ffU)) >> 9;
          iVar50 = local_64 - (int)fVar27;
          puVar24 = (undefined2 *)(iVar49 + ((int)fVar27 + local_70) * 2);
          if (iVar4 < iVar50 + (int)fVar27 + local_70) {
            iVar50 = (iVar4 - (int)fVar27) - local_70;
            local_64 = iVar50 + (int)fVar27;
          }
          if (iVar41 < iVar50 + (int)fVar27 * 2 + local_74) {
            iVar50 = (iVar41 + (int)fVar27 * -2) - local_74;
            local_64 = iVar50 + (int)fVar27;
          }
          if (0 < iVar50) {
            iVar39 = iVar39 * 2 - (int)puVar24;
            do {
              *(undefined2 *)(iVar39 + iVar45 + (int)puVar24) = *puVar24;
              puVar24 = puVar24 + 1;
              iVar50 = iVar50 + -1;
            } while (iVar50 != 0);
          }
        }
        local_70 = local_70 + local_64;
        iVar39 = iVar16 * 2 + local_70;
      }
      if (iVar41 <= local_74) {
        return 0;
      }
      while (local_70 < iVar4) {
        local_54 = 0.0;
        fVar27 = (float)iVar15;
        if (iVar15 <= iVar16) {
          local_c = (float *)-iVar15;
          psVar29 = (short *)(iVar49 + local_70 * 2);
          local_10 = (float *)(((local_70 + iVar15) * 2 - (int)psVar29) + iVar49);
          local_60 = (float)iVar15;
          do {
            iVar39 = 0;
            if (0 < iVar14) {
              iVar53 = local_70 + (int)local_60;
              iVar50 = iVar14;
              psVar36 = psVar29;
              do {
                if ((int)local_c + iVar53 < iVar4) {
                  iVar54 = (int)*psVar36;
                }
                else {
                  iVar54 = 0;
                }
                if (iVar53 < iVar4) {
                  iVar46 = (int)*(short *)((int)psVar36 + (int)local_10);
                }
                else {
                  iVar46 = 0;
                }
                iVar39 = iVar39 + ((int)(iVar46 * iVar54 + (iVar46 * iVar54 >> 0x1f & 0x7fffU)) >>
                                  0xf);
                iVar53 = iVar53 + 1;
                psVar36 = psVar36 + 1;
                iVar50 = iVar50 + -1;
              } while (iVar50 != 0);
            }
            if ((int)local_54 < iVar39) {
              fVar27 = local_60;
              local_54 = (float)iVar39;
            }
            local_c = (float *)((int)local_c + -1);
            local_10 = (float *)((int)local_10 + 2);
            local_60 = (float)((int)local_60 + 1);
          } while ((int)local_60 <= iVar16);
        }
        iVar39 = 0;
        psVar29 = (short *)(iVar45 + local_74 * 2);
        if (0 < (int)fVar27) {
          iVar50 = (int)fVar27 + local_74;
          iVar53 = (local_70 + (int)fVar27) * 2 - (int)psVar29;
          iVar46 = local_70 * 2 - (int)psVar29;
          iVar54 = iVar50 * 2 - (int)psVar29;
          local_10 = (float *)fVar27;
          do {
            if (iVar39 + local_74 + (local_70 - local_74) < iVar4) {
              sVar38 = *(short *)(iVar46 + iVar49 + (int)psVar29);
            }
            else {
              sVar38 = 0;
            }
            if ((local_70 - local_74) + iVar50 < iVar4) {
              sVar12 = *(short *)(iVar53 + iVar49 + (int)psVar29);
            }
            else {
              sVar12 = 0;
            }
            if (local_74 + iVar39 < iVar41) {
              *psVar29 = sVar38;
            }
            if (iVar50 < iVar41) {
              *(short *)(iVar54 + iVar45 + (int)psVar29) =
                   (short)(((int)sVar12 * (int)local_10 + sVar38 * iVar39) / (int)fVar27);
            }
            local_10 = (float *)((int)local_10 + -1);
            iVar39 = iVar39 + 1;
            iVar50 = iVar50 + 1;
            psVar29 = psVar29 + 1;
          } while (iVar39 < (int)fVar27);
        }
        iVar39 = local_74 + (int)fVar27 * 2;
        if ((iVar39 < iVar41) && (iVar50 = (int)fVar27 + local_70, iVar50 < iVar4)) {
          puVar24 = (undefined2 *)(iVar49 + iVar50 * 2);
          iVar53 = ((int)fVar27 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
          local_64 = (int)(iVar53 + (iVar53 >> 0x1f & 0x1ffU)) >> 9;
          iVar53 = local_64 - (int)fVar27;
          if (iVar4 < iVar53 + (int)fVar27 + local_70) {
            iVar53 = (iVar4 - (int)fVar27) - local_70;
            local_64 = iVar53 + (int)fVar27;
          }
          if (iVar41 < iVar53 + (int)fVar27 * 2 + local_74) {
            iVar53 = (iVar41 + (int)fVar27 * -2) - local_74;
            local_64 = iVar53 + (int)fVar27;
          }
          if (0 < iVar53) {
            iVar39 = iVar39 * 2 - (int)puVar24;
            do {
              if (iVar50 < iVar4) {
                uVar48 = *puVar24;
              }
              else {
                uVar48 = 0;
              }
              *(undefined2 *)((int)puVar24 + iVar45 + iVar39) = uVar48;
              iVar50 = iVar50 + 1;
              puVar24 = puVar24 + 1;
              iVar53 = iVar53 + -1;
            } while (iVar53 != 0);
          }
        }
        local_70 = local_70 + local_64;
        local_74 = local_74 + local_64 + (int)fVar27;
        if (iVar41 <= local_74) {
          return 0;
        }
      }
      if (iVar41 <= local_74) {
        return 0;
      }
      goto LAB_00559cfa;
    }
    if ((short)piVar2[0xd] != 3) {
      return 0;
    }
    iVar45 = piVar2[0x13];
    local_34 = piVar3[0x13];
    if (*(short *)((int)piVar2 + 0x36) != 1) {
      if (*(short *)((int)piVar2 + 0x36) != 2) {
        return 0;
      }
      local_74 = 0;
      local_70 = local_74;
      if (iVar16 * 2 < iVar4) {
        do {
          if (iVar41 <= iVar16 * 2 + local_74) break;
          local_44 = 0.0;
          local_50 = (float)iVar15;
          if (iVar15 <= iVar16) {
            local_10 = (float *)(iVar45 + (iVar15 + local_70) * 8);
            local_60 = (float)iVar15;
            do {
              local_5c = 0.0;
              iVar49 = 0;
              pfVar52 = (float *)(iVar45 + local_70 * 8);
              pfVar18 = local_10;
              if (3 < iVar14) {
                iVar39 = (iVar14 - 4U >> 2) + 1;
                iVar49 = iVar39 * 4;
                pfVar22 = pfVar52;
                pfVar44 = local_10;
                do {
                  pfVar52 = pfVar22 + 8;
                  pfVar18 = pfVar44 + 8;
                  iVar39 = iVar39 + -1;
                  local_5c = pfVar44[6] * pfVar22[6] +
                             pfVar44[4] * pfVar22[4] +
                             pfVar44[2] * pfVar22[2] + *pfVar44 * *pfVar22 + local_5c;
                  pfVar22 = pfVar52;
                  pfVar44 = pfVar18;
                } while (iVar39 != 0);
              }
              if (iVar49 < iVar14) {
                iVar49 = iVar14 - iVar49;
                do {
                  fVar27 = *pfVar18;
                  pfVar18 = pfVar18 + 2;
                  iVar49 = iVar49 + -1;
                  local_5c = fVar27 * *pfVar52 + local_5c;
                  pfVar52 = pfVar52 + 2;
                } while (iVar49 != 0);
              }
              if (local_44 < local_5c) {
                local_44 = local_5c;
                local_50 = local_60;
              }
              local_10 = local_10 + 2;
              local_60 = (float)((int)local_60 + 1);
            } while ((int)local_60 <= iVar16);
          }
          pfVar52 = (float *)(iVar45 + ((int)local_50 + local_70) * 8);
          pfVar18 = (float *)(iVar45 + local_70 * 8);
          pfVar22 = (float *)(local_34 + local_74 * 8);
          pfVar44 = (float *)(local_34 + (local_74 + (int)local_50) * 8);
          local_54 = 0.0;
          pfVar21 = pfVar52;
          if (3 < (int)local_50) {
            fVar27 = (float)(int)local_50;
            local_20 = 2;
            pfVar17 = pfVar18;
            pfVar26 = pfVar52;
            pfVar40 = pfVar22;
            pfVar51 = pfVar44;
            local_c = (float *)((int)local_50 + -2);
            do {
              *pfVar40 = *pfVar17;
              fVar5 = (float)(int)local_54;
              local_54 = (float)((int)local_54 + 4);
              pfVar18 = pfVar17 + 8;
              pfVar21 = pfVar26 + 8;
              pfVar22 = pfVar40 + 8;
              pfVar44 = pfVar51 + 8;
              *pfVar51 = (fVar5 * *pfVar17 + (float)((int)local_c + 2) * *pfVar26) / fVar27;
              pfVar40[2] = pfVar17[2];
              iVar49 = local_20 + 1;
              pfVar51[2] = ((float)(local_20 + -1) * pfVar17[2] +
                           (float)((int)local_c + 1) * pfVar26[2]) / fVar27;
              pfVar40[4] = pfVar17[4];
              fVar5 = (float)local_20;
              local_20 = local_20 + 4;
              pfVar51[4] = (fVar5 * pfVar17[4] + pfVar26[4] * (float)(int)local_c) / fVar27;
              pfVar40[6] = pfVar17[6];
              pfVar51[6] = ((float)iVar49 * pfVar17[6] + (float)((int)local_c + -1) * pfVar26[6]) /
                           fVar27;
              pfVar17 = pfVar18;
              pfVar26 = pfVar21;
              pfVar40 = pfVar22;
              pfVar51 = pfVar44;
              local_c = (float *)((int)local_c + -4);
            } while ((int)local_54 < (int)local_50 + -3);
          }
          if ((int)local_54 < (int)local_50) {
            local_c = (float *)((int)local_50 - (int)local_54);
            do {
              iVar49 = (int)local_54 + 1;
              *pfVar22 = *pfVar18;
              pfVar22 = pfVar22 + 2;
              *pfVar44 = ((float)(int)local_c * *pfVar21 + (float)(int)local_54 * *pfVar18) /
                         (float)(int)local_50;
              pfVar18 = pfVar18 + 2;
              pfVar21 = pfVar21 + 2;
              pfVar44 = pfVar44 + 2;
              local_54 = (float)iVar49;
              local_c = (float *)((int)local_c + -1);
            } while (iVar49 < (int)local_50);
          }
          iVar49 = (int)local_50 * 2 + local_74;
          if ((iVar49 < iVar41) && ((int)local_50 + local_70 < iVar4)) {
            iVar39 = ((int)local_50 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
            local_64 = (int)(iVar39 + (iVar39 >> 0x1f & 0x1ffU)) >> 9;
            pfVar18 = (float *)(local_34 + iVar49 * 8);
            iVar49 = local_64 - (int)local_50;
            if (iVar4 < iVar49 + (int)local_50 + local_70) {
              iVar49 = (iVar4 - (int)local_50) - local_70;
              local_64 = iVar49 + (int)local_50;
            }
            if (iVar41 < iVar49 + (int)local_50 * 2 + local_74) {
              iVar49 = (iVar41 + (int)local_50 * -2) - local_74;
              local_64 = iVar49 + (int)local_50;
            }
            iVar39 = 0;
            if (3 < iVar49) {
              iVar50 = (iVar49 - 4U >> 2) + 1;
              iVar39 = iVar50 * 4;
              pfVar22 = pfVar52;
              pfVar44 = pfVar18;
              do {
                pfVar52 = pfVar22 + 8;
                *pfVar44 = *pfVar22;
                pfVar18 = pfVar44 + 8;
                iVar50 = iVar50 + -1;
                pfVar44[2] = pfVar22[2];
                pfVar44[4] = pfVar22[4];
                pfVar44[6] = pfVar22[6];
                pfVar22 = pfVar52;
                pfVar44 = pfVar18;
              } while (iVar50 != 0);
            }
            if (iVar39 < iVar49) {
              iVar49 = iVar49 - iVar39;
              do {
                fVar27 = *pfVar52;
                pfVar52 = pfVar52 + 2;
                *pfVar18 = fVar27;
                pfVar18 = pfVar18 + 2;
                iVar49 = iVar49 + -1;
              } while (iVar49 != 0);
            }
          }
          local_70 = local_70 + local_64;
          local_74 = local_74 + local_64 + (int)local_50;
        } while (iVar16 * 2 + local_70 < iVar4);
      }
      do {
        if (iVar41 <= local_74) goto LAB_005534eb;
        if (iVar4 <= local_70) {
          if (local_74 < iVar41) {
            iVar49 = iVar41 - local_74;
            puVar23 = (undefined4 *)(local_34 + local_74 * 8);
            if (0 < iVar49) {
              do {
                *puVar23 = 0;
                puVar23 = puVar23 + 2;
                iVar49 = iVar49 + -1;
              } while (iVar49 != 0);
            }
          }
          goto LAB_005534eb;
        }
        local_44 = 0.0;
        local_50 = (float)iVar15;
        if (iVar15 <= iVar16) {
          pfVar52 = (float *)(iVar45 + local_70 * 8);
          local_18 = local_70 + iVar15 + 3;
          local_14 = (float *)(iVar45 + (local_70 + iVar15) * 8);
          fVar27 = (float)iVar15;
          local_60 = (float)iVar15;
          do {
            local_5c = 0.0;
            iVar49 = 0;
            pfVar18 = local_14;
            pfVar22 = pfVar52;
            if (3 < iVar14) {
              local_10 = (float *)local_18;
              iVar39 = local_70 + 1;
              iVar50 = (iVar14 - 4U >> 2) + 1;
              iVar49 = iVar50 * 4;
              do {
                if (iVar39 + -1 < iVar4) {
                  local_50 = *pfVar22;
                }
                else {
                  local_50 = 0.0;
                }
                if (iVar39 + -1 + (int)local_60 < iVar4) {
                  local_3c = (float *)*pfVar18;
                }
                else {
                  local_3c = (float *)0x0;
                }
                fVar5 = (float)local_3c * local_50;
                if (iVar39 < iVar4) {
                  local_50 = pfVar22[2];
                }
                else {
                  local_50 = 0.0;
                }
                if ((int)local_60 + iVar39 < iVar4) {
                  local_3c = (float *)pfVar18[2];
                }
                else {
                  local_3c = (float *)0x0;
                }
                fVar6 = (float)local_3c * local_50;
                if (iVar39 + 1 < iVar4) {
                  local_50 = pfVar22[4];
                }
                else {
                  local_50 = 0.0;
                }
                if ((int)local_10 + -1 < iVar4) {
                  local_3c = (float *)pfVar18[4];
                }
                else {
                  local_3c = (float *)0x0;
                }
                fVar7 = (float)local_3c * local_50;
                if (iVar39 + 2 < iVar4) {
                  local_50 = pfVar22[6];
                }
                else {
                  local_50 = 0.0;
                }
                if ((int)local_10 < iVar4) {
                  local_3c = (float *)pfVar18[6];
                }
                else {
                  local_3c = (float *)0x0;
                }
                local_10 = (float *)((int)local_10 + 4);
                pfVar22 = pfVar22 + 8;
                pfVar18 = pfVar18 + 8;
                iVar39 = iVar39 + 4;
                iVar50 = iVar50 + -1;
                local_5c = (float)local_3c * local_50 + fVar7 + fVar6 + fVar5 + local_5c;
              } while (iVar50 != 0);
            }
            if (iVar49 < iVar14) {
              iVar39 = local_70 + iVar49;
              iVar50 = (int)local_60 + iVar49 + local_70;
              iVar49 = iVar14 - iVar49;
              do {
                if (iVar39 < iVar4) {
                  local_50 = *pfVar22;
                }
                else {
                  local_50 = 0.0;
                }
                if (iVar50 < iVar4) {
                  local_3c = (float *)*pfVar18;
                }
                else {
                  local_3c = (float *)0x0;
                }
                pfVar22 = pfVar22 + 2;
                pfVar18 = pfVar18 + 2;
                iVar39 = iVar39 + 1;
                iVar50 = iVar50 + 1;
                iVar49 = iVar49 + -1;
                local_5c = (float)local_3c * local_50 + local_5c;
              } while (iVar49 != 0);
            }
            if (local_44 < local_5c) {
              local_44 = local_5c;
              fVar27 = local_60;
            }
            local_14 = local_14 + 2;
            local_18 = local_18 + 1;
            local_60 = (float)((int)local_60 + 1);
          } while ((int)local_60 <= iVar16);
          local_50 = fVar27;
        }
        local_3c = (float *)(iVar45 + local_70 * 8);
        pfVar52 = (float *)(iVar45 + ((int)local_50 + local_70) * 8);
        local_2c = (float *)(local_34 + local_74 * 8);
        local_28 = (float *)(local_34 + (local_74 + (int)local_50) * 8);
        local_54 = 0.0;
        local_30 = pfVar52;
        if (3 < (int)local_50) {
          local_c = (float *)(local_70 + 3);
          local_20 = (int)local_50 + -2;
          iVar39 = (int)local_50 + local_70 + 3;
          iVar49 = local_74 + (int)local_50 + 1;
          local_4 = (float *)0x1;
          do {
            if ((-3 - (int)local_50) + iVar39 < iVar4) {
              local_44 = *local_3c;
            }
            else {
              local_44 = 0.0;
            }
            if (iVar39 + -3 < iVar4) {
              local_60 = *local_30;
            }
            else {
              local_60 = 0.0;
            }
            if ((-1 - (int)local_50) + iVar49 < iVar41) {
              *local_2c = local_44;
            }
            if (iVar49 + -1 < iVar41) {
              *local_28 = ((float)(local_20 + 2) * local_60 + (float)(int)local_54 * local_44) /
                          (float)(int)local_50;
            }
            if ((-2 - (int)local_50) + iVar39 < iVar4) {
              local_44 = local_3c[2];
            }
            else {
              local_44 = 0.0;
            }
            if ((local_70 - local_74) + iVar49 < iVar4) {
              local_60 = local_30[2];
            }
            else {
              local_60 = 0.0;
            }
            if (local_74 + (int)local_4 < iVar41) {
              local_2c[2] = local_44;
            }
            if (iVar49 < iVar41) {
              local_28[2] = ((float)(local_20 + 1) * local_60 + (float)(int)local_4 * local_44) /
                            (float)(int)local_50;
            }
            if ((-1 - (int)local_50) + iVar39 < iVar4) {
              local_44 = local_3c[4];
            }
            else {
              local_44 = 0.0;
            }
            if (iVar39 + -1 < iVar4) {
              local_60 = local_30[4];
            }
            else {
              local_60 = 0.0;
            }
            if ((1 - (int)local_50) + iVar49 < iVar41) {
              local_2c[4] = local_44;
            }
            if (iVar49 + 1 < iVar41) {
              local_28[4] = ((float)local_20 * local_60 + local_44 * (float)((int)local_4 + 1)) /
                            (float)(int)local_50;
            }
            if ((int)local_c < iVar4) {
              local_44 = local_3c[6];
            }
            else {
              local_44 = 0.0;
            }
            if (iVar39 < iVar4) {
              local_60 = local_30[6];
            }
            else {
              local_60 = 0.0;
            }
            if ((2 - (int)local_50) + iVar49 < iVar41) {
              local_2c[6] = local_44;
            }
            if (iVar49 + 2 < iVar41) {
              local_28[6] = ((float)(local_20 + -1) * local_60 +
                            (float)((int)local_4 + 2) * local_44) / (float)(int)local_50;
            }
            local_3c = local_3c + 8;
            local_30 = local_30 + 8;
            local_2c = local_2c + 8;
            local_28 = local_28 + 8;
            local_c = (float *)((int)local_c + 4);
            local_20 = local_20 + -4;
            local_54 = (float)((int)local_54 + 4);
            local_4 = (float *)((int)local_4 + 4);
            iVar39 = iVar39 + 4;
            iVar49 = iVar49 + 4;
          } while ((int)local_54 < (int)local_50 + -3);
        }
        if ((int)local_54 < (int)local_50) {
          local_4 = (float *)((int)local_50 - (int)local_54);
          iVar39 = (int)local_54 + (int)local_50 + local_74;
          iVar49 = (int)local_54 + local_74;
          do {
            if ((local_70 - local_74) + iVar49 < iVar4) {
              local_44 = *local_3c;
            }
            else {
              local_44 = 0.0;
            }
            if ((local_70 - local_74) + iVar39 < iVar4) {
              local_60 = *local_30;
            }
            else {
              local_60 = 0.0;
            }
            if (iVar49 < iVar41) {
              *local_2c = local_44;
            }
            if (iVar39 < iVar41) {
              *local_28 = ((float)(int)local_4 * local_60 + (float)(int)local_54 * local_44) /
                          (float)(int)local_50;
            }
            local_3c = local_3c + 2;
            local_30 = local_30 + 2;
            local_2c = local_2c + 2;
            local_28 = local_28 + 2;
            local_54 = (float)((int)local_54 + 1);
            local_4 = (float *)((int)local_4 + -1);
            iVar49 = iVar49 + 1;
            iVar39 = iVar39 + 1;
          } while ((int)local_54 < (int)local_50);
        }
        iVar49 = local_74 + (int)local_50 * 2;
        if ((iVar49 < iVar41) && (local_70 + (int)local_50 < iVar4)) {
          iVar39 = ((int)local_50 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
          local_64 = (int)(iVar39 + (iVar39 >> 0x1f & 0x1ffU)) >> 9;
          iVar39 = local_64 - (int)local_50;
          pfVar18 = (float *)(local_34 + iVar49 * 8);
          if (iVar4 < iVar39 + (int)local_50 + local_70) {
            iVar39 = (iVar4 - (int)local_50) - local_70;
            local_64 = iVar39 + (int)local_50;
          }
          if (iVar41 < iVar39 + (int)local_50 * 2 + local_74) {
            iVar39 = (iVar41 + (int)local_50 * -2) - local_74;
            local_64 = iVar39 + (int)local_50;
          }
          iVar49 = 0;
          if (3 < iVar39) {
            iVar50 = local_70 + (int)local_50 + 2;
            iVar53 = (iVar39 - 4U >> 2) + 1;
            iVar49 = iVar53 * 4;
            local_3c = pfVar52;
            do {
              if (iVar50 + -2 < iVar4) {
                local_44 = *local_3c;
              }
              else {
                local_44 = 0.0;
              }
              *pfVar18 = local_44;
              if (iVar50 + -1 < iVar4) {
                local_44 = local_3c[2];
              }
              else {
                local_44 = 0.0;
              }
              pfVar18[2] = local_44;
              if (iVar50 < iVar4) {
                local_44 = local_3c[4];
              }
              else {
                local_44 = 0.0;
              }
              pfVar18[4] = local_44;
              if (iVar50 + 1 < iVar4) {
                local_44 = local_3c[6];
              }
              else {
                local_44 = 0.0;
              }
              pfVar52 = local_3c + 8;
              pfVar18[6] = local_44;
              pfVar18 = pfVar18 + 8;
              iVar50 = iVar50 + 4;
              iVar53 = iVar53 + -1;
              local_3c = pfVar52;
            } while (iVar53 != 0);
          }
          if (iVar49 < iVar39) {
            iVar50 = iVar49 + (int)local_50 + local_70;
            iVar39 = iVar39 - iVar49;
            do {
              if (iVar50 < iVar4) {
                local_44 = *pfVar52;
              }
              else {
                local_44 = 0.0;
              }
              pfVar52 = pfVar52 + 2;
              *pfVar18 = local_44;
              pfVar18 = pfVar18 + 2;
              iVar50 = iVar50 + 1;
              iVar39 = iVar39 + -1;
            } while (iVar39 != 0);
          }
        }
        local_74 = local_74 + (int)local_50 + local_64;
        local_70 = local_70 + local_64;
      } while( true );
    }
    iVar49 = iVar16 * 2;
    local_70 = 0;
    for (local_74 = 0; (iVar49 < iVar4 && (iVar16 * 2 + local_74 < iVar41));
        local_74 = local_74 + local_64 + (int)local_50) {
      local_44 = 0.0;
      local_50 = (float)iVar15;
      if (iVar15 <= iVar16) {
        local_8 = (float *)(iVar45 + (iVar15 + local_70) * 4);
        local_60 = (float)iVar15;
        do {
          local_5c = 0.0;
          iVar49 = 0;
          pfVar52 = (float *)(iVar45 + local_70 * 4);
          pfVar18 = local_8;
          if (3 < iVar14) {
            iVar39 = (iVar14 - 4U >> 2) + 1;
            iVar49 = iVar39 * 4;
            pfVar22 = pfVar52;
            pfVar44 = local_8;
            do {
              pfVar52 = pfVar22 + 4;
              pfVar18 = pfVar44 + 4;
              iVar39 = iVar39 + -1;
              local_5c = pfVar44[3] * pfVar22[3] +
                         pfVar44[2] * pfVar22[2] +
                         pfVar44[1] * pfVar22[1] + *pfVar44 * *pfVar22 + local_5c;
              pfVar22 = pfVar52;
              pfVar44 = pfVar18;
            } while (iVar39 != 0);
          }
          if (iVar49 < iVar14) {
            iVar49 = iVar14 - iVar49;
            do {
              fVar27 = *pfVar18;
              pfVar18 = pfVar18 + 1;
              iVar49 = iVar49 + -1;
              local_5c = fVar27 * *pfVar52 + local_5c;
              pfVar52 = pfVar52 + 1;
            } while (iVar49 != 0);
          }
          if (local_44 < local_5c) {
            local_44 = local_5c;
            local_50 = local_60;
          }
          local_8 = local_8 + 1;
          local_60 = (float)((int)local_60 + 1);
        } while ((int)local_60 <= iVar16);
      }
      pfVar52 = (float *)(iVar45 + ((int)local_50 + local_70) * 4);
      pfVar18 = (float *)(iVar45 + local_70 * 4);
      pfVar22 = (float *)(local_34 + local_74 * 4);
      pfVar44 = (float *)(local_34 + (local_74 + (int)local_50) * 4);
      local_54 = 0.0;
      pfVar21 = pfVar52;
      if (3 < (int)local_50) {
        fVar27 = (float)(int)local_50;
        local_20 = 2;
        pfVar17 = pfVar18;
        pfVar26 = pfVar52;
        pfVar40 = pfVar22;
        pfVar51 = pfVar44;
        local_4 = (float *)((int)local_50 + -2);
        do {
          *pfVar40 = *pfVar17;
          fVar5 = (float)(int)local_54;
          local_54 = (float)((int)local_54 + 4);
          pfVar18 = pfVar17 + 4;
          pfVar21 = pfVar26 + 4;
          pfVar22 = pfVar40 + 4;
          pfVar44 = pfVar51 + 4;
          *pfVar51 = (fVar5 * *pfVar17 + (float)((int)local_4 + 2) * *pfVar26) / fVar27;
          pfVar40[1] = pfVar17[1];
          pfVar51[1] = ((float)(local_20 + -1) * pfVar17[1] + (float)((int)local_4 + 1) * pfVar26[1]
                       ) / fVar27;
          pfVar40[2] = pfVar17[2];
          fVar5 = (float)local_20;
          iVar49 = local_20 + 1;
          local_20 = local_20 + 4;
          pfVar51[2] = (fVar5 * pfVar17[2] + pfVar26[2] * (float)(int)local_4) / fVar27;
          pfVar40[3] = pfVar17[3];
          pfVar51[3] = ((float)iVar49 * pfVar17[3] + (float)((int)local_4 + -1) * pfVar26[3]) /
                       fVar27;
          pfVar17 = pfVar18;
          pfVar26 = pfVar21;
          pfVar40 = pfVar22;
          pfVar51 = pfVar44;
          local_4 = (float *)((int)local_4 + -4);
        } while ((int)local_54 < (int)local_50 + -3);
      }
      if ((int)local_54 < (int)local_50) {
        local_4 = (float *)((int)local_50 - (int)local_54);
        do {
          iVar49 = (int)local_54 + 1;
          *pfVar22 = *pfVar18;
          pfVar22 = pfVar22 + 1;
          *pfVar44 = ((float)(int)local_54 * *pfVar18 + (float)(int)local_4 * *pfVar21) /
                     (float)(int)local_50;
          pfVar18 = pfVar18 + 1;
          pfVar21 = pfVar21 + 1;
          pfVar44 = pfVar44 + 1;
          local_54 = (float)iVar49;
          local_4 = (float *)((int)local_4 + -1);
        } while (iVar49 < (int)local_50);
      }
      iVar49 = (int)local_50 * 2 + local_74;
      if ((iVar49 < iVar41) && ((int)local_50 + local_70 < iVar4)) {
        iVar39 = ((int)local_50 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
        local_64 = (int)(iVar39 + (iVar39 >> 0x1f & 0x1ffU)) >> 9;
        pfVar18 = (float *)(local_34 + iVar49 * 4);
        iVar49 = local_64 - (int)local_50;
        if (iVar4 < iVar49 + (int)local_50 + local_70) {
          iVar49 = (iVar4 - (int)local_50) - local_70;
          local_64 = iVar49 + (int)local_50;
        }
        if (iVar41 < (int)local_50 * 2 + iVar49 + local_74) {
          iVar49 = (iVar41 + (int)local_50 * -2) - local_74;
          local_64 = iVar49 + (int)local_50;
        }
        iVar39 = 0;
        if (3 < iVar49) {
          iVar50 = (iVar49 - 4U >> 2) + 1;
          iVar39 = iVar50 * 4;
          pfVar22 = pfVar52;
          pfVar44 = pfVar18;
          do {
            pfVar52 = pfVar22 + 4;
            *pfVar44 = *pfVar22;
            pfVar18 = pfVar44 + 4;
            iVar50 = iVar50 + -1;
            pfVar44[1] = pfVar22[1];
            pfVar44[2] = pfVar22[2];
            pfVar44[3] = pfVar22[3];
            pfVar22 = pfVar52;
            pfVar44 = pfVar18;
          } while (iVar50 != 0);
        }
        if (iVar39 < iVar49) {
          iVar49 = iVar49 - iVar39;
          do {
            fVar27 = *pfVar52;
            pfVar52 = pfVar52 + 1;
            *pfVar18 = fVar27;
            pfVar18 = pfVar18 + 1;
            iVar49 = iVar49 + -1;
          } while (iVar49 != 0);
        }
      }
      local_70 = local_70 + local_64;
      iVar49 = iVar16 * 2 + local_70;
    }
    if (iVar41 <= local_74) {
      return 0;
    }
    while (local_70 < iVar4) {
      local_44 = 0.0;
      local_50 = (float)iVar15;
      if (iVar15 <= iVar16) {
        pfVar52 = (float *)(iVar45 + local_70 * 4);
        local_c = (float *)(local_70 + iVar15 + 3);
        local_8 = (float *)(iVar45 + (local_70 + iVar15) * 4);
        fVar27 = (float)iVar15;
        local_60 = (float)iVar15;
        do {
          local_5c = 0.0;
          iVar49 = 0;
          pfVar18 = local_8;
          pfVar22 = pfVar52;
          if (3 < iVar14) {
            local_10 = local_c;
            iVar39 = local_70 + 1;
            iVar50 = (iVar14 - 4U >> 2) + 1;
            iVar49 = iVar50 * 4;
            do {
              if (iVar39 + -1 < iVar4) {
                local_50 = *pfVar22;
              }
              else {
                local_50 = 0.0;
              }
              if (iVar39 + -1 + (int)local_60 < iVar4) {
                local_3c = (float *)*pfVar18;
              }
              else {
                local_3c = (float *)0x0;
              }
              fVar5 = (float)local_3c * local_50;
              if (iVar39 < iVar4) {
                local_50 = pfVar22[1];
              }
              else {
                local_50 = 0.0;
              }
              if ((int)local_60 + iVar39 < iVar4) {
                local_3c = (float *)pfVar18[1];
              }
              else {
                local_3c = (float *)0x0;
              }
              fVar6 = (float)local_3c * local_50;
              if (iVar39 + 1 < iVar4) {
                local_50 = pfVar22[2];
              }
              else {
                local_50 = 0.0;
              }
              if ((int)local_10 + -1 < iVar4) {
                local_3c = (float *)pfVar18[2];
              }
              else {
                local_3c = (float *)0x0;
              }
              fVar7 = (float)local_3c * local_50;
              if (iVar39 + 2 < iVar4) {
                local_50 = pfVar22[3];
              }
              else {
                local_50 = 0.0;
              }
              if ((int)local_10 < iVar4) {
                local_3c = (float *)pfVar18[3];
              }
              else {
                local_3c = (float *)0x0;
              }
              local_10 = (float *)((int)local_10 + 4);
              pfVar22 = pfVar22 + 4;
              pfVar18 = pfVar18 + 4;
              iVar39 = iVar39 + 4;
              iVar50 = iVar50 + -1;
              local_5c = (float)local_3c * local_50 + fVar7 + fVar6 + fVar5 + local_5c;
            } while (iVar50 != 0);
          }
          if (iVar49 < iVar14) {
            iVar39 = local_70 + iVar49;
            iVar50 = (int)local_60 + iVar49 + local_70;
            iVar49 = iVar14 - iVar49;
            do {
              if (iVar39 < iVar4) {
                local_50 = *pfVar22;
              }
              else {
                local_50 = 0.0;
              }
              if (iVar50 < iVar4) {
                local_3c = (float *)*pfVar18;
              }
              else {
                local_3c = (float *)0x0;
              }
              pfVar22 = pfVar22 + 1;
              pfVar18 = pfVar18 + 1;
              iVar39 = iVar39 + 1;
              iVar50 = iVar50 + 1;
              iVar49 = iVar49 + -1;
              local_5c = (float)local_3c * local_50 + local_5c;
            } while (iVar49 != 0);
          }
          if (local_44 < local_5c) {
            local_44 = local_5c;
            fVar27 = local_60;
          }
          local_8 = local_8 + 1;
          local_c = (float *)((int)local_c + 1);
          local_60 = (float)((int)local_60 + 1);
        } while ((int)local_60 <= iVar16);
        local_50 = fVar27;
      }
      local_3c = (float *)(iVar45 + local_70 * 4);
      pfVar52 = (float *)(iVar45 + ((int)local_50 + local_70) * 4);
      local_2c = (float *)(local_34 + local_74 * 4);
      local_30 = (float *)(local_34 + (local_74 + (int)local_50) * 4);
      local_54 = 0.0;
      local_28 = pfVar52;
      if (3 < (int)local_50) {
        local_8 = (float *)(local_70 + 3);
        local_20 = (int)local_50 + -2;
        iVar39 = (int)local_50 + local_70 + 3;
        iVar49 = local_74 + (int)local_50 + 1;
        local_4 = (float *)0x1;
        do {
          if ((-3 - (int)local_50) + iVar39 < iVar4) {
            local_44 = *local_3c;
          }
          else {
            local_44 = 0.0;
          }
          if (iVar39 + -3 < iVar4) {
            local_60 = *local_28;
          }
          else {
            local_60 = 0.0;
          }
          if (iVar49 + (-1 - (int)local_50) < iVar41) {
            *local_2c = local_44;
          }
          if (iVar49 + -1 < iVar41) {
            *local_30 = ((float)(local_20 + 2) * local_60 + (float)(int)local_54 * local_44) /
                        (float)(int)local_50;
          }
          if (iVar39 + (-2 - (int)local_50) < iVar4) {
            local_44 = local_3c[1];
          }
          else {
            local_44 = 0.0;
          }
          if ((local_70 - local_74) + iVar49 < iVar4) {
            local_60 = local_28[1];
          }
          else {
            local_60 = 0.0;
          }
          if ((int)local_4 + local_74 < iVar41) {
            local_2c[1] = local_44;
          }
          if (iVar49 < iVar41) {
            local_30[1] = ((float)(local_20 + 1) * local_60 + (float)(int)local_4 * local_44) /
                          (float)(int)local_50;
          }
          if (iVar39 + (-1 - (int)local_50) < iVar4) {
            local_44 = local_3c[2];
          }
          else {
            local_44 = 0.0;
          }
          if (iVar39 + -1 < iVar4) {
            local_60 = local_28[2];
          }
          else {
            local_60 = 0.0;
          }
          if (iVar49 + (1 - (int)local_50) < iVar41) {
            local_2c[2] = local_44;
          }
          if (iVar49 + 1 < iVar41) {
            local_30[2] = ((float)local_20 * local_60 + local_44 * (float)((int)local_4 + 1)) /
                          (float)(int)local_50;
          }
          if ((int)local_8 < iVar4) {
            local_44 = local_3c[3];
          }
          else {
            local_44 = 0.0;
          }
          if (iVar39 < iVar4) {
            local_60 = local_28[3];
          }
          else {
            local_60 = 0.0;
          }
          if (iVar49 + (2 - (int)local_50) < iVar41) {
            local_2c[3] = local_44;
          }
          if (iVar49 + 2 < iVar41) {
            local_30[3] = ((float)(local_20 + -1) * local_60 + local_44 * (float)((int)local_4 + 2))
                          / (float)(int)local_50;
          }
          local_3c = local_3c + 4;
          local_28 = local_28 + 4;
          local_2c = local_2c + 4;
          local_30 = local_30 + 4;
          local_8 = (float *)((int)local_8 + 4);
          local_20 = local_20 + -4;
          local_54 = (float)((int)local_54 + 4);
          local_4 = (float *)((int)local_4 + 4);
          iVar39 = iVar39 + 4;
          iVar49 = iVar49 + 4;
        } while ((int)local_54 < (int)local_50 + -3);
      }
      if ((int)local_54 < (int)local_50) {
        local_4 = (float *)((int)local_50 - (int)local_54);
        iVar39 = (int)local_54 + (int)local_50 + local_74;
        iVar49 = (int)local_54 + local_74;
        do {
          if ((local_70 - local_74) + iVar49 < iVar4) {
            local_44 = *local_3c;
          }
          else {
            local_44 = 0.0;
          }
          if ((local_70 - local_74) + iVar39 < iVar4) {
            local_60 = *local_28;
          }
          else {
            local_60 = 0.0;
          }
          if (iVar49 < iVar41) {
            *local_2c = local_44;
          }
          if (iVar39 < iVar41) {
            *local_30 = ((float)(int)local_4 * local_60 + (float)(int)local_54 * local_44) /
                        (float)(int)local_50;
          }
          local_3c = local_3c + 1;
          local_28 = local_28 + 1;
          local_2c = local_2c + 1;
          local_30 = local_30 + 1;
          local_54 = (float)((int)local_54 + 1);
          local_4 = (float *)((int)local_4 + -1);
          iVar49 = iVar49 + 1;
          iVar39 = iVar39 + 1;
        } while ((int)local_54 < (int)local_50);
      }
      iVar49 = local_74 + (int)local_50 * 2;
      if ((iVar49 < iVar41) && ((int)local_50 + local_70 < iVar4)) {
        iVar39 = ((int)local_50 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
        local_64 = (int)(iVar39 + (iVar39 >> 0x1f & 0x1ffU)) >> 9;
        iVar39 = local_64 - (int)local_50;
        pfVar18 = (float *)(local_34 + iVar49 * 4);
        if (iVar4 < iVar39 + (int)local_50 + local_70) {
          iVar39 = (iVar4 - (int)local_50) - local_70;
          local_64 = iVar39 + (int)local_50;
        }
        if (iVar41 < iVar39 + (int)local_50 * 2 + local_74) {
          iVar39 = (iVar41 + (int)local_50 * -2) - local_74;
          local_64 = iVar39 + (int)local_50;
        }
        local_54 = 0.0;
        if (3 < iVar39) {
          iVar49 = (int)local_50 + local_70 + 2;
          iVar50 = (iVar39 - 4U >> 2) + 1;
          local_54 = (float)(iVar50 * 4);
          local_3c = pfVar52;
          do {
            if (iVar49 + -2 < iVar4) {
              local_44 = *local_3c;
            }
            else {
              local_44 = 0.0;
            }
            *pfVar18 = local_44;
            if (iVar49 + -1 < iVar4) {
              local_44 = local_3c[1];
            }
            else {
              local_44 = 0.0;
            }
            pfVar18[1] = local_44;
            if (iVar49 < iVar4) {
              local_44 = local_3c[2];
            }
            else {
              local_44 = 0.0;
            }
            pfVar18[2] = local_44;
            if (iVar49 + 1 < iVar4) {
              local_44 = local_3c[3];
            }
            else {
              local_44 = 0.0;
            }
            pfVar52 = local_3c + 4;
            pfVar18[3] = local_44;
            pfVar18 = pfVar18 + 4;
            iVar49 = iVar49 + 4;
            iVar50 = iVar50 + -1;
            local_3c = pfVar52;
          } while (iVar50 != 0);
        }
        if ((int)local_54 < iVar39) {
          iVar49 = (int)local_54 + (int)local_50 + local_70;
          iVar39 = iVar39 - (int)local_54;
          do {
            if (iVar49 < iVar4) {
              local_44 = *pfVar52;
            }
            else {
              local_44 = 0.0;
            }
            pfVar52 = pfVar52 + 1;
            *pfVar18 = local_44;
            pfVar18 = pfVar18 + 1;
            iVar49 = iVar49 + 1;
            iVar39 = iVar39 + -1;
          } while (iVar39 != 0);
        }
      }
      local_70 = local_70 + local_64;
      local_74 = local_74 + local_64 + (int)local_50;
      if (iVar41 <= local_74) {
        return 0;
      }
    }
  }
  else {
    iVar13 = FUN_0050e240(dVar8);
    dVar8 = (double)piVar2[0xe];
    iVar4 = piVar2[0x12];
    iVar41 = piVar3[0x12];
    if (piVar2[0xe] < 0) {
      dVar8 = dVar8 + _DAT_007d49f0;
    }
    iVar14 = FUN_0050e240(dVar8 * _DAT_008044f8);
    dVar8 = (double)piVar2[0xe];
    if (piVar2[0xe] < 0) {
      dVar8 = dVar8 + _DAT_007d49f0;
    }
    iVar15 = FUN_0050e240(dVar8 * _DAT_008298b8);
    dVar8 = (double)piVar2[0xe];
    if (piVar2[0xe] < 0) {
      dVar8 = dVar8 + _DAT_007d49f0;
    }
    iVar16 = FUN_0050e240(dVar8 * _DAT_007d62b0);
    if ((short)piVar2[0xd] == 1) {
      if (*(short *)((int)piVar2 + 0x42) == 8) {
        iVar49 = piVar2[0x13];
        iVar45 = piVar3[0x13];
        if (*(short *)((int)piVar2 + 0x36) != 1) {
          if (*(short *)((int)piVar2 + 0x36) != 2) {
            return 0;
          }
          iVar53 = iVar16 * 2;
          iVar50 = 0;
          for (iVar39 = 0; (iVar53 < iVar4 && (iVar16 * 2 + iVar39 < iVar41));
              iVar39 = iVar39 + (int)local_60) {
            local_3c = (float *)0x0;
            iVar53 = iVar15;
            if (iVar15 <= iVar16) {
              pbVar32 = (byte *)(iVar49 + iVar50 * 2);
              iVar54 = ((iVar50 + iVar15) * 2 - (int)pbVar32) + iVar49;
              local_64 = iVar15;
              do {
                iVar46 = 0;
                if (0 < iVar14) {
                  pbVar30 = pbVar32;
                  iVar19 = iVar14;
                  do {
                    iVar47 = (pbVar30[iVar54] - 0x80) * (*pbVar30 - 0x80);
                    iVar46 = iVar46 + ((int)(iVar47 + (iVar47 >> 0x1f & 0x7fU)) >> 7);
                    pbVar30 = pbVar30 + 2;
                    iVar19 = iVar19 + -1;
                  } while (iVar19 != 0);
                }
                if ((int)local_3c < iVar46) {
                  iVar53 = local_64;
                  local_3c = (float *)iVar46;
                }
                local_64 = local_64 + 1;
                iVar54 = iVar54 + 2;
              } while (local_64 <= iVar16);
            }
            iVar54 = 0;
            pbVar32 = (byte *)(iVar49 + (iVar53 + iVar50) * 2);
            if (0 < iVar53) {
              pbVar30 = pbVar32;
              iVar46 = iVar53;
              do {
                iVar19 = (uint)pbVar30[(iVar50 * 2 - (int)pbVar32) + iVar49] * iVar46;
                iVar47 = (uint)*pbVar30 * iVar54;
                iVar54 = iVar54 + 1;
                iVar46 = iVar46 + -1;
                pbVar30[(iVar39 * 2 - (int)pbVar32) + iVar45] = (byte)((iVar19 + iVar47) / iVar53);
                pbVar30 = pbVar30 + 2;
              } while (iVar54 < iVar53);
            }
            if (iVar39 + iVar53 < iVar41) {
              iVar54 = iVar53 * 2 + iVar50;
              if (iVar54 < iVar4) {
                iVar46 = (iVar53 << 0x12) / (iVar13 + -0x200) + 0x100;
                local_60 = (float)((int)((iVar46 >> 0x1f & 0x1ffU) + iVar46) >> 9);
                puVar31 = (undefined1 *)(iVar49 + iVar54 * 2);
                iVar54 = (int)local_60 - iVar53;
                if (iVar4 < iVar53 * 2 + iVar54 + iVar50) {
                  iVar54 = (iVar4 + iVar53 * -2) - iVar50;
                  local_60 = (float)(iVar54 + iVar53);
                }
                if (iVar41 < iVar54 + iVar53 + iVar39) {
                  iVar54 = (iVar41 - iVar53) - iVar39;
                  local_60 = (float)(iVar54 + iVar53);
                }
                if (0 < iVar54) {
                  iVar46 = (iVar39 + iVar53) * 2 - (int)puVar31;
                  do {
                    puVar31[iVar45 + iVar46] = *puVar31;
                    puVar31 = puVar31 + 2;
                    iVar54 = iVar54 + -1;
                  } while (iVar54 != 0);
                }
              }
            }
            iVar50 = iVar50 + (int)local_60 + iVar53;
            iVar53 = iVar16 * 2 + iVar50;
          }
          for (; iVar39 < iVar41; iVar39 = iVar39 + (int)local_60) {
            if (iVar4 <= iVar50) {
              if (iVar39 < iVar41) {
                iVar50 = iVar41 - iVar39;
                puVar31 = (undefined1 *)(iVar45 + iVar39 * 2);
                if (0 < iVar50) {
                  do {
                    *puVar31 = 0x80;
                    puVar31 = puVar31 + 2;
                    iVar50 = iVar50 + -1;
                  } while (iVar50 != 0);
                }
              }
              break;
            }
            local_3c = (float *)0x0;
            iVar53 = iVar15;
            if (iVar15 <= iVar16) {
              pbVar32 = (byte *)(iVar49 + iVar50 * 2);
              local_c = (float *)-iVar15;
              local_10 = (float *)(((iVar50 + iVar15) * 2 - (int)pbVar32) + iVar49);
              local_64 = iVar15;
              do {
                iVar54 = 0;
                if (0 < iVar14) {
                  iVar46 = local_64 + iVar50;
                  pbVar30 = pbVar32;
                  local_4 = (float *)iVar14;
                  do {
                    if (iVar46 + (int)local_c < iVar4) {
                      iVar19 = *pbVar30 - 0x80;
                    }
                    else {
                      iVar19 = 0;
                    }
                    if (iVar46 < iVar4) {
                      iVar47 = pbVar30[(int)local_10] - 0x80;
                    }
                    else {
                      iVar47 = 0;
                    }
                    iVar54 = iVar54 + ((int)(iVar47 * iVar19 + (iVar47 * iVar19 >> 0x1f & 0x7fU)) >>
                                      7);
                    iVar46 = iVar46 + 1;
                    pbVar30 = pbVar30 + 2;
                    local_4 = (float *)((int)local_4 + -1);
                  } while (local_4 != (float *)0x0);
                }
                if ((int)local_3c < iVar54) {
                  iVar53 = local_64;
                  local_3c = (float *)iVar54;
                }
                local_c = (float *)((int)local_c + -1);
                local_10 = (float *)((int)local_10 + 2);
                local_64 = local_64 + 1;
              } while (local_64 <= iVar16);
            }
            iVar54 = 0;
            pbVar32 = (byte *)(iVar49 + (iVar50 + iVar53) * 2);
            if (0 < iVar53) {
              iVar20 = iVar50 * 2 - (int)pbVar32;
              iVar47 = iVar39 * 2 - (int)pbVar32;
              iVar46 = iVar53;
              iVar19 = iVar50;
              do {
                if (iVar19 < iVar4) {
                  local_75 = pbVar32[iVar20 + iVar49];
                }
                else {
                  local_75 = 0x80;
                }
                if (iVar19 + iVar53 < iVar4) {
                  local_76 = *pbVar32;
                }
                else {
                  local_76 = 0x80;
                }
                if ((iVar39 - iVar50) + iVar19 < iVar41) {
                  pbVar32[iVar47 + iVar45] =
                       (byte)((int)((uint)local_76 * iVar54 + (uint)local_75 * iVar46) / iVar53);
                }
                iVar54 = iVar54 + 1;
                iVar19 = iVar19 + 1;
                iVar46 = iVar46 + -1;
                pbVar32 = pbVar32 + 2;
              } while (iVar54 < iVar53);
            }
            if (iVar39 + iVar53 < iVar41) {
              iVar54 = iVar50 + iVar53 * 2;
              if (iVar54 < iVar4) {
                iVar46 = (iVar53 << 0x12) / (iVar13 + -0x200) + 0x100;
                local_60 = (float)((int)(iVar46 + (iVar46 >> 0x1f & 0x1ffU)) >> 9);
                iVar46 = (int)local_60 - iVar53;
                puVar31 = (undefined1 *)(iVar49 + iVar54 * 2);
                if (iVar4 < iVar53 * 2 + iVar46 + iVar50) {
                  iVar46 = (iVar4 + iVar53 * -2) - iVar50;
                  local_60 = (float)(iVar46 + iVar53);
                }
                if (iVar41 < iVar46 + iVar53 + iVar39) {
                  iVar46 = (iVar41 - iVar53) - iVar39;
                  local_60 = (float)(iVar46 + iVar53);
                }
                if (0 < iVar46) {
                  iVar19 = (iVar39 + iVar53) * 2 - (int)puVar31;
                  iVar54 = iVar50 + iVar53;
                  do {
                    uVar10 = 0x80;
                    if (iVar54 < iVar4) {
                      uVar10 = *puVar31;
                    }
                    puVar31[iVar45 + iVar19] = uVar10;
                    iVar54 = iVar54 + 1;
                    puVar31 = puVar31 + 2;
                    iVar46 = iVar46 + -1;
                  } while (iVar46 != 0);
                }
              }
            }
            iVar50 = iVar50 + (int)local_60 + iVar53;
          }
          local_74 = 0;
          local_70 = 0;
          if (iVar16 * 2 < iVar4) {
            do {
              if (iVar41 <= iVar16 * 2 + local_70) break;
              local_3c = (float *)0x0;
              iVar39 = iVar15;
              if (iVar15 <= iVar16) {
                pbVar32 = (byte *)(iVar49 + 1 + local_74 * 2);
                iVar50 = ((local_74 + iVar15) * 2 - (int)pbVar32) + 1 + iVar49;
                local_64 = iVar15;
                do {
                  iVar53 = 0;
                  if (0 < iVar14) {
                    pbVar30 = pbVar32;
                    iVar54 = iVar14;
                    do {
                      iVar46 = (pbVar30[iVar50] - 0x80) * (*pbVar30 - 0x80);
                      iVar53 = iVar53 + ((int)(iVar46 + (iVar46 >> 0x1f & 0x7fU)) >> 7);
                      pbVar30 = pbVar30 + 2;
                      iVar54 = iVar54 + -1;
                    } while (iVar54 != 0);
                  }
                  if ((int)local_3c < iVar53) {
                    iVar39 = local_64;
                    local_3c = (float *)iVar53;
                  }
                  local_64 = local_64 + 1;
                  iVar50 = iVar50 + 2;
                } while (local_64 <= iVar16);
              }
              iVar50 = 0;
              pbVar32 = (byte *)(iVar49 + 1 + (iVar39 + local_74) * 2);
              if (0 < iVar39) {
                iVar46 = local_74 * 2 - (int)pbVar32;
                iVar54 = local_70 * 2 - (int)pbVar32;
                iVar53 = iVar39;
                do {
                  iVar19 = (uint)pbVar32[iVar46 + 1 + iVar49] * iVar53;
                  iVar47 = (uint)*pbVar32 * iVar50;
                  iVar50 = iVar50 + 1;
                  iVar53 = iVar53 + -1;
                  pbVar32 = pbVar32 + 2;
                  pbVar32[iVar54 + iVar45 + -1] = (byte)((iVar19 + iVar47) / iVar39);
                } while (iVar50 < iVar39);
              }
              if (iVar39 + local_70 < iVar41) {
                iVar50 = iVar39 * 2 + local_74;
                if (iVar50 < iVar4) {
                  iVar53 = (iVar39 << 0x12) / (iVar13 + -0x200) + 0x100;
                  local_60 = (float)((int)((iVar53 >> 0x1f & 0x1ffU) + iVar53) >> 9);
                  puVar31 = (undefined1 *)(iVar49 + 1 + iVar50 * 2);
                  iVar50 = (int)local_60 - iVar39;
                  if (iVar4 < iVar39 * 2 + iVar50 + local_74) {
                    iVar50 = (iVar4 + iVar39 * -2) - local_74;
                    local_60 = (float)(iVar50 + iVar39);
                  }
                  if (iVar41 < iVar50 + iVar39 + local_70) {
                    iVar50 = (iVar41 - iVar39) - local_70;
                    local_60 = (float)(iVar50 + iVar39);
                  }
                  if (0 < iVar50) {
                    iVar53 = (iVar39 + local_70) * 2 - (int)puVar31;
                    do {
                      puVar31[iVar53 + 1 + iVar45] = *puVar31;
                      puVar31 = puVar31 + 2;
                      iVar50 = iVar50 + -1;
                    } while (iVar50 != 0);
                  }
                }
              }
              local_74 = local_74 + (int)local_60 + iVar39;
              local_70 = local_70 + (int)local_60;
            } while (local_74 + iVar16 * 2 < iVar4);
          }
          if (iVar41 <= local_70) {
            return 0;
          }
          while (local_74 < iVar4) {
            local_3c = (float *)0x0;
            iVar39 = iVar15;
            if (iVar15 <= iVar16) {
              pbVar32 = (byte *)(iVar49 + 1 + local_74 * 2);
              local_c = (float *)-iVar15;
              local_10 = (float *)(((local_74 + iVar15) * 2 - (int)pbVar32) + 1 + iVar49);
              local_64 = iVar15;
              do {
                iVar50 = 0;
                if (0 < iVar14) {
                  iVar53 = local_64 + local_74;
                  pbVar30 = pbVar32;
                  local_4 = (float *)iVar14;
                  do {
                    if (iVar53 + (int)local_c < iVar4) {
                      iVar54 = *pbVar30 - 0x80;
                    }
                    else {
                      iVar54 = 0;
                    }
                    if (iVar53 < iVar4) {
                      iVar46 = pbVar30[(int)local_10] - 0x80;
                    }
                    else {
                      iVar46 = 0;
                    }
                    iVar50 = iVar50 + ((int)(iVar46 * iVar54 + (iVar46 * iVar54 >> 0x1f & 0x7fU)) >>
                                      7);
                    iVar53 = iVar53 + 1;
                    pbVar30 = pbVar30 + 2;
                    local_4 = (float *)((int)local_4 + -1);
                  } while (local_4 != (float *)0x0);
                }
                if ((int)local_3c < iVar50) {
                  iVar39 = local_64;
                  local_3c = (float *)iVar50;
                }
                local_c = (float *)((int)local_c + -1);
                local_10 = (float *)((int)local_10 + 2);
                local_64 = local_64 + 1;
              } while (local_64 <= iVar16);
            }
            iVar50 = 0;
            pbVar32 = (byte *)(iVar49 + 1 + (local_74 + iVar39) * 2);
            if (0 < iVar39) {
              iVar46 = local_74 * 2 - (int)pbVar32;
              iVar19 = local_70 * 2 - (int)pbVar32;
              iVar53 = iVar39;
              iVar54 = local_74;
              do {
                if (iVar54 < iVar4) {
                  local_75 = pbVar32[iVar46 + 1 + iVar49];
                }
                else {
                  local_75 = 0x80;
                }
                if (iVar54 + iVar39 < iVar4) {
                  local_76 = *pbVar32;
                }
                else {
                  local_76 = 0x80;
                }
                if ((local_70 - local_74) + iVar54 < iVar41) {
                  pbVar32[iVar19 + 1 + iVar45] =
                       (byte)((int)((uint)local_75 * iVar53 + (uint)local_76 * iVar50) / iVar39);
                }
                iVar50 = iVar50 + 1;
                iVar54 = iVar54 + 1;
                iVar53 = iVar53 + -1;
                pbVar32 = pbVar32 + 2;
              } while (iVar50 < iVar39);
            }
            if (local_70 + iVar39 < iVar41) {
              iVar50 = local_74 + iVar39 * 2;
              if (iVar50 < iVar4) {
                iVar53 = (iVar39 << 0x12) / (iVar13 + -0x200) + 0x100;
                local_60 = (float)((int)(iVar53 + (iVar53 >> 0x1f & 0x1ffU)) >> 9);
                iVar53 = (int)local_60 - iVar39;
                puVar31 = (undefined1 *)(iVar49 + 1 + iVar50 * 2);
                if (iVar4 < iVar39 * 2 + iVar53 + local_74) {
                  iVar53 = (iVar4 + iVar39 * -2) - local_74;
                  local_60 = (float)(iVar53 + iVar39);
                }
                if (iVar41 < iVar53 + iVar39 + local_70) {
                  iVar53 = (iVar41 - iVar39) - local_70;
                  local_60 = (float)(iVar53 + iVar39);
                }
                if (0 < iVar53) {
                  iVar50 = local_74 + iVar39;
                  iVar54 = (local_70 + iVar39) * 2 - (int)puVar31;
                  do {
                    uVar10 = 0x80;
                    if (iVar50 < iVar4) {
                      uVar10 = *puVar31;
                    }
                    puVar31[iVar54 + 1 + iVar45] = uVar10;
                    iVar50 = iVar50 + 1;
                    puVar31 = puVar31 + 2;
                    iVar53 = iVar53 + -1;
                  } while (iVar53 != 0);
                }
              }
            }
            local_74 = local_74 + (int)local_60 + iVar39;
            local_70 = local_70 + (int)local_60;
            if (iVar41 <= local_70) {
              return 0;
            }
          }
          if (iVar41 <= local_70) {
            return 0;
          }
          iVar41 = iVar41 - local_70;
          puVar31 = (undefined1 *)(iVar45 + 1 + local_70 * 2);
          if (iVar41 < 1) {
            return 0;
          }
          do {
            *puVar31 = 0x80;
            puVar31 = puVar31 + 2;
            iVar41 = iVar41 + -1;
          } while (iVar41 != 0);
          return 0;
        }
        local_74 = 0;
        local_70 = 0;
        if (iVar16 * 2 < iVar4) {
          do {
            if (iVar41 <= iVar16 * 2 + local_70) break;
            local_3c = (float *)0x0;
            iVar39 = iVar15;
            if (iVar15 <= iVar16) {
              local_64 = iVar15;
              do {
                iVar50 = 0;
                iVar53 = 0;
                pbVar32 = (byte *)(iVar49 + local_74);
                if (0 < iVar14) {
                  do {
                    iVar54 = (((byte *)(iVar49 + local_74))[iVar50 + local_64] - 0x80) *
                             (*pbVar32 - 0x80);
                    iVar50 = iVar50 + 1;
                    iVar53 = iVar53 + ((int)(iVar54 + (iVar54 >> 0x1f & 0x7fU)) >> 7);
                    pbVar32 = pbVar32 + 1;
                  } while (iVar50 < iVar14);
                }
                if ((int)local_3c < iVar53) {
                  iVar39 = local_64;
                  local_3c = (float *)iVar53;
                }
                local_64 = local_64 + 1;
              } while (local_64 <= iVar16);
            }
            iVar50 = 0;
            if (0 < iVar39) {
              pbVar32 = (byte *)(iVar49 + local_74);
              iVar53 = iVar39;
              local_4 = (float *)(iVar45 + local_70);
              do {
                iVar54 = (uint)*(byte *)(iVar49 + iVar39 + local_74 + iVar50) * iVar50;
                iVar46 = (uint)*pbVar32 * iVar53;
                iVar50 = iVar50 + 1;
                iVar53 = iVar53 + -1;
                pbVar32 = pbVar32 + 1;
                *(char *)local_4 = (char)((iVar54 + iVar46) / iVar39);
                local_4 = (float *)((int)local_4 + 1);
              } while (iVar50 < iVar39);
            }
            if ((iVar39 + local_70 < iVar41) && (iVar50 = iVar39 * 2, iVar50 + local_74 < iVar4)) {
              iVar53 = (iVar39 << 0x12) / (iVar13 + -0x200) + 0x100;
              local_60 = (float)((int)(iVar53 + (iVar53 >> 0x1f & 0x1ffU)) >> 9);
              iVar53 = iVar50 + iVar49 + local_74;
              iVar54 = (int)local_60 - iVar39;
              if (iVar4 < iVar50 + iVar54 + local_74) {
                iVar54 = (iVar4 + iVar39 * -2) - local_74;
                local_60 = (float)(iVar54 + iVar39);
              }
              if (iVar41 < iVar54 + iVar39 + local_70) {
                iVar54 = (iVar41 - iVar39) - local_70;
                local_60 = (float)(iVar54 + iVar39);
              }
              iVar50 = 0;
              if (0 < iVar54) {
                puVar31 = (undefined1 *)
                          ((((iVar53 - iVar49) - iVar39) - local_74) + iVar45 + local_70);
                do {
                  *puVar31 = *(undefined1 *)(iVar53 + iVar50);
                  iVar50 = iVar50 + 1;
                  puVar31 = puVar31 + 1;
                } while (iVar50 < iVar54);
              }
            }
            local_70 = local_70 + (int)local_60;
            local_74 = local_74 + (int)local_60 + iVar39;
          } while (iVar16 * 2 + local_74 < iVar4);
        }
        if (iVar41 <= local_70) {
          return 0;
        }
        while (local_74 < iVar4) {
          local_3c = (float *)0x0;
          iVar39 = iVar15;
          if (iVar15 <= iVar16) {
            local_10 = (float *)(local_74 + iVar15);
            local_c = (float *)-iVar15;
            local_64 = iVar15;
            do {
              iVar50 = 0;
              if (0 < iVar14) {
                pfVar52 = local_10;
                iVar53 = iVar14;
                pbVar32 = (byte *)(iVar49 + local_74);
                do {
                  if ((int)local_c + (int)pfVar52 < iVar4) {
                    iVar54 = *pbVar32 - 0x80;
                  }
                  else {
                    iVar54 = 0;
                  }
                  if ((int)pfVar52 < iVar4) {
                    iVar46 = *(byte *)(iVar49 + (int)pfVar52) - 0x80;
                  }
                  else {
                    iVar46 = 0;
                  }
                  iVar50 = iVar50 + ((int)(iVar46 * iVar54 + (iVar46 * iVar54 >> 0x1f & 0x7fU)) >> 7
                                    );
                  pfVar52 = (float *)((int)pfVar52 + 1);
                  pbVar32 = pbVar32 + 1;
                  iVar53 = iVar53 + -1;
                } while (iVar53 != 0);
              }
              if ((int)local_3c < iVar50) {
                iVar39 = local_64;
                local_3c = (float *)iVar50;
              }
              local_c = (float *)((int)local_c + -1);
              local_10 = (float *)((int)local_10 + 1);
              local_64 = local_64 + 1;
            } while (local_64 <= iVar16);
          }
          iVar50 = 0;
          if (0 < iVar39) {
            local_8 = (float *)(iVar39 + local_74);
            iVar53 = local_70;
            iVar54 = iVar39;
            do {
              if ((local_74 - local_70) + iVar53 < iVar4) {
                bVar9 = *(byte *)((iVar49 - iVar39) + (int)local_8);
              }
              else {
                bVar9 = 0x80;
              }
              if ((int)local_8 < iVar4) {
                bVar11 = *(byte *)(((iVar49 + iVar39 + local_74) - local_70) + iVar53);
              }
              else {
                bVar11 = 0x80;
              }
              if (iVar53 < iVar41) {
                *(char *)(iVar45 + iVar53) =
                     (char)((int)((uint)bVar9 * iVar54 + (uint)bVar11 * iVar50) / iVar39);
              }
              iVar50 = iVar50 + 1;
              local_8 = (float *)((int)local_8 + 1);
              iVar53 = iVar53 + 1;
              iVar54 = iVar54 + -1;
            } while (iVar50 < iVar39);
          }
          if ((iVar39 + local_70 < iVar41) && (iVar50 = iVar39 * 2, iVar50 + local_74 < iVar4)) {
            iVar53 = (iVar39 << 0x12) / (iVar13 + -0x200) + 0x100;
            local_60 = (float)((int)(iVar53 + (iVar53 >> 0x1f & 0x1ffU)) >> 9);
            iVar53 = (int)local_60 - iVar39;
            if (iVar4 < iVar50 + iVar53 + local_74) {
              iVar53 = (iVar4 + iVar39 * -2) - local_74;
              local_60 = (float)(iVar53 + iVar39);
            }
            if (iVar41 < iVar53 + iVar39 + local_70) {
              iVar53 = (iVar41 - iVar39) - local_70;
              local_60 = (float)(iVar53 + iVar39);
            }
            iVar54 = 0;
            if (0 < iVar53) {
              puVar31 = (undefined1 *)(iVar45 + iVar39 + local_70);
              iVar46 = iVar39 + local_74;
              do {
                if (iVar46 < iVar4) {
                  uVar10 = *(undefined1 *)(iVar49 + iVar50 + local_74 + iVar54);
                }
                else {
                  uVar10 = 0x80;
                }
                *puVar31 = uVar10;
                iVar54 = iVar54 + 1;
                iVar46 = iVar46 + 1;
                puVar31 = puVar31 + 1;
              } while (iVar54 < iVar53);
            }
          }
          local_70 = local_70 + (int)local_60;
          local_74 = local_74 + (int)local_60 + iVar39;
          if (iVar41 <= local_70) {
            return 0;
          }
        }
        if (iVar41 <= local_70) {
          return 0;
        }
        local_74 = local_70;
LAB_00556c48:
        if (iVar41 - local_74 < 1) {
          return 0;
        }
        _memset((void *)(local_74 + iVar45),0x80,iVar41 - local_74);
        return 0;
      }
      if (*(short *)((int)piVar2 + 0x42) != 0x10) {
        return 0;
      }
      iVar49 = piVar2[0x13];
      iVar45 = piVar3[0x13];
      if (*(short *)((int)piVar2 + 0x36) != 1) {
        if (*(short *)((int)piVar2 + 0x36) != 2) {
          return 0;
        }
        iVar39 = iVar16 * 2;
        local_74 = 0;
        for (local_70 = 0; (iVar39 < iVar4 && (iVar16 * 2 + local_70 < iVar41));
            local_70 = local_70 + (int)local_60) {
          local_3c = (float *)0x0;
          iVar39 = iVar15;
          if (iVar15 <= iVar16) {
            psVar29 = (short *)(iVar49 + local_74 * 4);
            iVar50 = ((local_74 + iVar15) * 4 - (int)psVar29) + iVar49;
            local_64 = iVar15;
            do {
              iVar53 = 0;
              if (0 < iVar14) {
                psVar36 = psVar29;
                iVar54 = iVar14;
                do {
                  iVar46 = (int)*(short *)((int)psVar36 + iVar50) * (int)*psVar36;
                  iVar53 = iVar53 + ((int)(iVar46 + (iVar46 >> 0x1f & 0x7fffU)) >> 0xf);
                  psVar36 = psVar36 + 2;
                  iVar54 = iVar54 + -1;
                } while (iVar54 != 0);
              }
              if ((int)local_3c < iVar53) {
                iVar39 = local_64;
                local_3c = (float *)iVar53;
              }
              local_64 = local_64 + 1;
              iVar50 = iVar50 + 4;
            } while (local_64 <= iVar16);
          }
          psVar29 = (short *)(iVar49 + (iVar39 + local_74) * 4);
          if (0 < iVar39) {
            iVar53 = 0;
            psVar36 = psVar29;
            iVar50 = iVar39;
            do {
              iVar54 = *(short *)((int)psVar36 + (local_74 * 4 - (int)psVar29) + iVar49) * iVar50;
              iVar46 = *psVar36 * iVar53;
              iVar53 = iVar53 + 1;
              iVar50 = iVar50 + -1;
              *(short *)((int)psVar36 + (local_70 * 4 - (int)psVar29) + iVar45) =
                   (short)((iVar54 + iVar46) / iVar39);
              psVar36 = psVar36 + 2;
            } while (iVar53 < iVar39);
          }
          if (local_70 + iVar39 < iVar41) {
            iVar50 = iVar39 * 2 + local_74;
            if (iVar50 < iVar4) {
              iVar53 = (iVar39 << 0x12) / (iVar13 + -0x200) + 0x100;
              local_60 = (float)((int)((iVar53 >> 0x1f & 0x1ffU) + iVar53) >> 9);
              puVar24 = (undefined2 *)(iVar49 + iVar50 * 4);
              iVar50 = (int)local_60 - iVar39;
              if (iVar4 < iVar39 * 2 + iVar50 + local_74) {
                iVar50 = (iVar4 + iVar39 * -2) - local_74;
                local_60 = (float)(iVar50 + iVar39);
              }
              if (iVar41 < iVar50 + iVar39 + local_70) {
                iVar50 = (iVar41 - iVar39) - local_70;
                local_60 = (float)(iVar50 + iVar39);
              }
              if (0 < iVar50) {
                iVar53 = (local_70 + iVar39) * 4 - (int)puVar24;
                do {
                  *(undefined2 *)(iVar53 + iVar45 + (int)puVar24) = *puVar24;
                  puVar24 = puVar24 + 2;
                  iVar50 = iVar50 + -1;
                } while (iVar50 != 0);
              }
            }
          }
          local_74 = local_74 + (int)local_60 + iVar39;
          iVar39 = iVar16 * 2 + local_74;
        }
        if (local_70 < iVar41) {
          do {
            if (iVar4 <= local_74) {
              if (local_70 < iVar41) {
                iVar39 = iVar41 - local_70;
                puVar24 = (undefined2 *)(iVar45 + local_70 * 4);
                if (0 < iVar39) {
                  do {
                    *puVar24 = 0;
                    puVar24 = puVar24 + 2;
                    iVar39 = iVar39 + -1;
                  } while (iVar39 != 0);
                }
              }
              break;
            }
            local_3c = (float *)0x0;
            iVar39 = iVar15;
            if (iVar15 <= iVar16) {
              psVar29 = (short *)(iVar49 + local_74 * 4);
              local_c = (float *)-iVar15;
              local_10 = (float *)(((local_74 + iVar15) * 4 - (int)psVar29) + iVar49);
              local_64 = iVar15;
              do {
                iVar50 = 0;
                if (0 < iVar14) {
                  iVar54 = local_74 + local_64;
                  iVar53 = iVar14;
                  psVar36 = psVar29;
                  do {
                    if ((int)local_c + iVar54 < iVar4) {
                      iVar46 = (int)*psVar36;
                    }
                    else {
                      iVar46 = 0;
                    }
                    if (iVar54 < iVar4) {
                      iVar19 = (int)*(short *)((int)local_10 + (int)psVar36);
                    }
                    else {
                      iVar19 = 0;
                    }
                    iVar50 = iVar50 + ((int)(iVar19 * iVar46 + (iVar19 * iVar46 >> 0x1f & 0x7fffU))
                                      >> 0xf);
                    iVar54 = iVar54 + 1;
                    psVar36 = psVar36 + 2;
                    iVar53 = iVar53 + -1;
                  } while (iVar53 != 0);
                }
                if ((int)local_3c < iVar50) {
                  iVar39 = local_64;
                  local_3c = (float *)iVar50;
                }
                local_c = (float *)((int)local_c + -1);
                local_10 = (float *)((int)local_10 + 4);
                local_64 = local_64 + 1;
              } while (local_64 <= iVar16);
            }
            iVar50 = 0;
            psVar29 = (short *)(iVar49 + (local_74 + iVar39) * 4);
            if (0 < iVar39) {
              iVar19 = local_74 * 4 - (int)psVar29;
              iVar46 = local_70 * 4 - (int)psVar29;
              iVar53 = local_74;
              iVar54 = iVar39;
              do {
                if (iVar53 < iVar4) {
                  sVar38 = *(short *)((int)psVar29 + iVar19 + iVar49);
                }
                else {
                  sVar38 = 0;
                }
                if (iVar53 + iVar39 < iVar4) {
                  sVar12 = *psVar29;
                }
                else {
                  sVar12 = 0;
                }
                if ((local_70 - local_74) + iVar53 < iVar41) {
                  *(short *)((int)psVar29 + iVar46 + iVar45) =
                       (short)((sVar38 * iVar54 + sVar12 * iVar50) / iVar39);
                }
                iVar50 = iVar50 + 1;
                iVar53 = iVar53 + 1;
                iVar54 = iVar54 + -1;
                psVar29 = psVar29 + 2;
              } while (iVar50 < iVar39);
            }
            if (iVar39 + local_70 < iVar41) {
              iVar50 = local_74 + iVar39 * 2;
              if (iVar50 < iVar4) {
                iVar53 = (iVar39 << 0x12) / (iVar13 + -0x200) + 0x100;
                local_60 = (float)((int)(iVar53 + (iVar53 >> 0x1f & 0x1ffU)) >> 9);
                iVar53 = (int)local_60 - iVar39;
                puVar24 = (undefined2 *)(iVar49 + iVar50 * 4);
                if (iVar4 < iVar39 * 2 + iVar53 + local_74) {
                  iVar53 = (iVar4 + iVar39 * -2) - local_74;
                  local_60 = (float)(iVar53 + iVar39);
                }
                if (iVar41 < iVar53 + iVar39 + local_70) {
                  iVar53 = (iVar41 - iVar39) - local_70;
                  local_60 = (float)(iVar53 + iVar39);
                }
                if (0 < iVar53) {
                  iVar54 = (iVar39 + local_70) * 4 - (int)puVar24;
                  iVar50 = local_74 + iVar39;
                  do {
                    if (iVar50 < iVar4) {
                      uVar48 = *puVar24;
                    }
                    else {
                      uVar48 = 0;
                    }
                    *(undefined2 *)(iVar45 + iVar54 + (int)puVar24) = uVar48;
                    iVar50 = iVar50 + 1;
                    puVar24 = puVar24 + 2;
                    iVar53 = iVar53 + -1;
                  } while (iVar53 != 0);
                }
              }
            }
            local_74 = local_74 + (int)local_60 + iVar39;
            local_70 = local_70 + (int)local_60;
          } while (local_70 < iVar41);
        }
        local_74 = 0;
        iVar39 = iVar16 * 2;
        for (local_70 = 0; (iVar39 < iVar4 && (iVar16 * 2 + local_70 < iVar41));
            local_70 = local_70 + (int)local_60) {
          local_3c = (float *)0x0;
          iVar39 = iVar15;
          if (iVar15 <= iVar16) {
            psVar29 = (short *)(iVar49 + 2 + local_74 * 4);
            iVar50 = ((local_74 + iVar15) * 4 - (int)psVar29) + 2 + iVar49;
            local_64 = iVar15;
            do {
              iVar53 = 0;
              if (0 < iVar14) {
                psVar36 = psVar29;
                iVar54 = iVar14;
                do {
                  iVar46 = (int)*(short *)((int)psVar36 + iVar50) * (int)*psVar36;
                  iVar53 = iVar53 + ((int)(iVar46 + (iVar46 >> 0x1f & 0x7fffU)) >> 0xf);
                  psVar36 = psVar36 + 2;
                  iVar54 = iVar54 + -1;
                } while (iVar54 != 0);
              }
              if ((int)local_3c < iVar53) {
                iVar39 = local_64;
                local_3c = (float *)iVar53;
              }
              local_64 = local_64 + 1;
              iVar50 = iVar50 + 4;
            } while (local_64 <= iVar16);
          }
          iVar50 = 0;
          psVar29 = (short *)(iVar49 + 2 + (iVar39 + local_74) * 4);
          if (0 < iVar39) {
            psVar36 = psVar29;
            iVar53 = iVar39;
            do {
              iVar54 = *(short *)((int)psVar36 + (local_74 * 4 - (int)psVar29) + 2 + iVar49) *
                       iVar53;
              iVar46 = *psVar36 * iVar50;
              iVar50 = iVar50 + 1;
              iVar53 = iVar53 + -1;
              *(short *)((int)psVar36 + (local_70 * 4 - (int)psVar29) + 2 + iVar45) =
                   (short)((iVar54 + iVar46) / iVar39);
              psVar36 = psVar36 + 2;
            } while (iVar50 < iVar39);
          }
          if (iVar39 + local_70 < iVar41) {
            iVar50 = iVar39 * 2 + local_74;
            if (iVar50 < iVar4) {
              iVar53 = (iVar39 << 0x12) / (iVar13 + -0x200) + 0x100;
              local_60 = (float)((int)((iVar53 >> 0x1f & 0x1ffU) + iVar53) >> 9);
              puVar24 = (undefined2 *)(iVar49 + 2 + iVar50 * 4);
              iVar50 = (int)local_60 - iVar39;
              if (iVar4 < iVar39 * 2 + iVar50 + local_74) {
                iVar50 = (iVar4 + iVar39 * -2) - local_74;
                local_60 = (float)(iVar50 + iVar39);
              }
              if (iVar41 < iVar50 + iVar39 + local_70) {
                iVar50 = (iVar41 - iVar39) - local_70;
                local_60 = (float)(iVar50 + iVar39);
              }
              if (0 < iVar50) {
                iVar53 = (iVar39 + local_70) * 4 - (int)puVar24;
                do {
                  *(undefined2 *)(iVar53 + 2 + iVar45 + (int)puVar24) = *puVar24;
                  puVar24 = puVar24 + 2;
                  iVar50 = iVar50 + -1;
                } while (iVar50 != 0);
              }
            }
          }
          local_74 = local_74 + (int)local_60 + iVar39;
          iVar39 = local_74 + iVar16 * 2;
        }
        if (iVar41 <= local_70) {
          return 0;
        }
        while (local_74 < iVar4) {
          local_3c = (float *)0x0;
          iVar39 = iVar15;
          if (iVar15 <= iVar16) {
            psVar29 = (short *)(iVar49 + 2 + local_74 * 4);
            local_c = (float *)-iVar15;
            local_10 = (float *)(((local_74 + iVar15) * 4 - (int)psVar29) + 2 + iVar49);
            local_64 = iVar15;
            do {
              iVar50 = 0;
              if (0 < iVar14) {
                iVar54 = local_74 + local_64;
                iVar53 = iVar14;
                psVar36 = psVar29;
                do {
                  if ((int)local_c + iVar54 < iVar4) {
                    iVar46 = (int)*psVar36;
                  }
                  else {
                    iVar46 = 0;
                  }
                  if (iVar54 < iVar4) {
                    iVar19 = (int)*(short *)((int)local_10 + (int)psVar36);
                  }
                  else {
                    iVar19 = 0;
                  }
                  iVar50 = iVar50 + ((int)(iVar19 * iVar46 + (iVar19 * iVar46 >> 0x1f & 0x7fffU)) >>
                                    0xf);
                  iVar54 = iVar54 + 1;
                  psVar36 = psVar36 + 2;
                  iVar53 = iVar53 + -1;
                } while (iVar53 != 0);
              }
              if ((int)local_3c < iVar50) {
                iVar39 = local_64;
                local_3c = (float *)iVar50;
              }
              local_c = (float *)((int)local_c + -1);
              local_10 = (float *)((int)local_10 + 4);
              local_64 = local_64 + 1;
            } while (local_64 <= iVar16);
          }
          iVar50 = 0;
          psVar29 = (short *)(iVar49 + 2 + (local_74 + iVar39) * 4);
          if (0 < iVar39) {
            iVar46 = local_74 * 4 - (int)psVar29;
            iVar19 = local_70 * 4 - (int)psVar29;
            iVar53 = local_74;
            iVar54 = iVar39;
            do {
              if (iVar53 < iVar4) {
                sVar38 = *(short *)((int)psVar29 + iVar46 + 2 + iVar49);
              }
              else {
                sVar38 = 0;
              }
              if (iVar53 + iVar39 < iVar4) {
                sVar12 = *psVar29;
              }
              else {
                sVar12 = 0;
              }
              if (iVar53 + (local_70 - local_74) < iVar41) {
                *(short *)((int)psVar29 + iVar19 + 2 + iVar45) =
                     (short)((sVar12 * iVar50 + sVar38 * iVar54) / iVar39);
              }
              iVar50 = iVar50 + 1;
              iVar53 = iVar53 + 1;
              iVar54 = iVar54 + -1;
              psVar29 = psVar29 + 2;
            } while (iVar50 < iVar39);
          }
          if (iVar39 + local_70 < iVar41) {
            iVar50 = local_74 + iVar39 * 2;
            if (iVar50 < iVar4) {
              iVar53 = (iVar39 << 0x12) / (iVar13 + -0x200) + 0x100;
              local_60 = (float)((int)(iVar53 + (iVar53 >> 0x1f & 0x1ffU)) >> 9);
              iVar53 = (int)local_60 - iVar39;
              puVar24 = (undefined2 *)(iVar49 + 2 + iVar50 * 4);
              if (iVar4 < iVar39 * 2 + iVar53 + local_74) {
                iVar53 = (iVar4 + iVar39 * -2) - local_74;
                local_60 = (float)(iVar53 + iVar39);
              }
              if (iVar41 < iVar53 + iVar39 + local_70) {
                iVar53 = (iVar41 - iVar39) - local_70;
                local_60 = (float)(iVar53 + iVar39);
              }
              if (0 < iVar53) {
                iVar50 = local_74 + iVar39;
                iVar54 = (iVar39 + local_70) * 4 - (int)puVar24;
                do {
                  if (iVar50 < iVar4) {
                    uVar48 = *puVar24;
                  }
                  else {
                    uVar48 = 0;
                  }
                  *(undefined2 *)(iVar54 + 2 + iVar45 + (int)puVar24) = uVar48;
                  iVar50 = iVar50 + 1;
                  puVar24 = puVar24 + 2;
                  iVar53 = iVar53 + -1;
                } while (iVar53 != 0);
              }
            }
          }
          local_74 = local_74 + (int)local_60 + iVar39;
          local_70 = local_70 + (int)local_60;
          if (iVar41 <= local_70) {
            return 0;
          }
        }
        if (iVar41 <= local_70) {
          return 0;
        }
        iVar41 = iVar41 - local_70;
        puVar24 = (undefined2 *)(iVar45 + 2 + local_70 * 4);
        if (iVar41 < 1) {
          return 0;
        }
        do {
          *puVar24 = 0;
          puVar24 = puVar24 + 2;
          iVar41 = iVar41 + -1;
        } while (iVar41 != 0);
        return 0;
      }
      iVar39 = iVar16 * 2;
      local_74 = 0;
      for (local_70 = 0; (iVar39 < iVar4 && (iVar16 * 2 + local_70 < iVar41));
          local_70 = local_70 + (int)local_60) {
        local_3c = (float *)0x0;
        iVar39 = iVar15;
        if (iVar15 <= iVar16) {
          psVar29 = (short *)(iVar49 + local_74 * 2);
          iVar50 = ((local_74 + iVar15) * 2 - (int)psVar29) + iVar49;
          local_64 = iVar15;
          do {
            iVar53 = 0;
            if (0 < iVar14) {
              psVar36 = psVar29;
              iVar54 = iVar14;
              do {
                iVar46 = (int)*(short *)(iVar50 + (int)psVar36) * (int)*psVar36;
                iVar53 = iVar53 + ((int)(iVar46 + (iVar46 >> 0x1f & 0x7fffU)) >> 0xf);
                psVar36 = psVar36 + 1;
                iVar54 = iVar54 + -1;
              } while (iVar54 != 0);
            }
            if ((int)local_3c < iVar53) {
              iVar39 = local_64;
              local_3c = (float *)iVar53;
            }
            local_64 = local_64 + 1;
            iVar50 = iVar50 + 2;
          } while (local_64 <= iVar16);
        }
        iVar50 = 0;
        psVar29 = (short *)(iVar49 + (iVar39 + local_74) * 2);
        if (0 < iVar39) {
          iVar54 = local_74 * 2 - (int)psVar29;
          iVar46 = local_70 * 2 - (int)psVar29;
          iVar53 = iVar39;
          do {
            iVar19 = *(short *)((int)psVar29 + iVar54 + iVar49) * iVar53;
            iVar47 = *psVar29 * iVar50;
            iVar50 = iVar50 + 1;
            iVar53 = iVar53 + -1;
            psVar29 = psVar29 + 1;
            *(short *)(iVar46 + iVar45 + -2 + (int)psVar29) = (short)((iVar19 + iVar47) / iVar39);
          } while (iVar50 < iVar39);
        }
        if (local_70 + iVar39 < iVar41) {
          iVar50 = iVar39 * 2 + local_74;
          if (iVar50 < iVar4) {
            iVar53 = (iVar39 << 0x12) / (iVar13 + -0x200) + 0x100;
            local_60 = (float)((int)((iVar53 >> 0x1f & 0x1ffU) + iVar53) >> 9);
            puVar24 = (undefined2 *)(iVar49 + iVar50 * 2);
            iVar50 = (int)local_60 - iVar39;
            if (iVar4 < iVar39 * 2 + iVar50 + local_74) {
              iVar50 = (iVar4 + iVar39 * -2) - local_74;
              local_60 = (float)(iVar50 + iVar39);
            }
            if (iVar41 < iVar50 + iVar39 + local_70) {
              iVar50 = (iVar41 - iVar39) - local_70;
              local_60 = (float)(iVar50 + iVar39);
            }
            if (0 < iVar50) {
              iVar53 = (local_70 + iVar39) * 2 - (int)puVar24;
              do {
                *(undefined2 *)(iVar53 + iVar45 + (int)puVar24) = *puVar24;
                puVar24 = puVar24 + 1;
                iVar50 = iVar50 + -1;
              } while (iVar50 != 0);
            }
          }
        }
        local_74 = local_74 + (int)local_60 + iVar39;
        iVar39 = iVar16 * 2 + local_74;
      }
      if (iVar41 <= local_70) {
        return 0;
      }
      while (local_74 < iVar4) {
        local_3c = (float *)0x0;
        iVar39 = iVar15;
        if (iVar15 <= iVar16) {
          local_c = (float *)-iVar15;
          psVar29 = (short *)(iVar49 + local_74 * 2);
          local_10 = (float *)(((local_74 + iVar15) * 2 - (int)psVar29) + iVar49);
          local_64 = iVar15;
          do {
            iVar50 = 0;
            if (0 < iVar14) {
              iVar54 = local_74 + local_64;
              iVar53 = iVar14;
              psVar36 = psVar29;
              do {
                if ((int)local_c + iVar54 < iVar4) {
                  iVar46 = (int)*psVar36;
                }
                else {
                  iVar46 = 0;
                }
                if (iVar54 < iVar4) {
                  iVar19 = (int)*(short *)((int)local_10 + (int)psVar36);
                }
                else {
                  iVar19 = 0;
                }
                iVar50 = iVar50 + ((int)(iVar19 * iVar46 + (iVar19 * iVar46 >> 0x1f & 0x7fffU)) >>
                                  0xf);
                iVar54 = iVar54 + 1;
                psVar36 = psVar36 + 1;
                iVar53 = iVar53 + -1;
              } while (iVar53 != 0);
            }
            if ((int)local_3c < iVar50) {
              iVar39 = local_64;
              local_3c = (float *)iVar50;
            }
            local_c = (float *)((int)local_c + -1);
            local_10 = (float *)((int)local_10 + 2);
            local_64 = local_64 + 1;
          } while (local_64 <= iVar16);
        }
        iVar50 = 0;
        psVar29 = (short *)(iVar49 + (iVar39 + local_74) * 2);
        if (0 < iVar39) {
          iVar46 = local_74 * 2 - (int)psVar29;
          iVar19 = local_70 * 2 - (int)psVar29;
          iVar53 = local_74;
          iVar54 = iVar39;
          do {
            if (iVar53 < iVar4) {
              sVar38 = *(short *)(iVar46 + iVar49 + (int)psVar29);
            }
            else {
              sVar38 = 0;
            }
            if (iVar39 + iVar53 < iVar4) {
              sVar12 = *psVar29;
            }
            else {
              sVar12 = 0;
            }
            if ((local_70 - local_74) + iVar53 < iVar41) {
              *(short *)(iVar19 + iVar45 + (int)psVar29) =
                   (short)((sVar12 * iVar50 + sVar38 * iVar54) / iVar39);
            }
            iVar50 = iVar50 + 1;
            iVar53 = iVar53 + 1;
            iVar54 = iVar54 + -1;
            psVar29 = psVar29 + 1;
          } while (iVar50 < iVar39);
        }
        if (iVar39 + local_70 < iVar41) {
          iVar50 = local_74 + iVar39 * 2;
          if (iVar50 < iVar4) {
            iVar53 = (iVar39 << 0x12) / (iVar13 + -0x200) + 0x100;
            local_60 = (float)((int)(iVar53 + (iVar53 >> 0x1f & 0x1ffU)) >> 9);
            iVar53 = (int)local_60 - iVar39;
            puVar24 = (undefined2 *)(iVar49 + iVar50 * 2);
            if (iVar4 < iVar39 * 2 + iVar53 + local_74) {
              iVar53 = (iVar4 + iVar39 * -2) - local_74;
              local_60 = (float)(iVar53 + iVar39);
            }
            if (iVar41 < iVar53 + iVar39 + local_70) {
              iVar53 = (iVar41 - iVar39) - local_70;
              local_60 = (float)(iVar53 + iVar39);
            }
            if (0 < iVar53) {
              iVar54 = (iVar39 + local_70) * 2 - (int)puVar24;
              iVar50 = local_74 + iVar39;
              do {
                if (iVar50 < iVar4) {
                  uVar48 = *puVar24;
                }
                else {
                  uVar48 = 0;
                }
                *(undefined2 *)(iVar45 + iVar54 + (int)puVar24) = uVar48;
                iVar50 = iVar50 + 1;
                puVar24 = puVar24 + 1;
                iVar53 = iVar53 + -1;
              } while (iVar53 != 0);
            }
          }
        }
        local_74 = local_74 + (int)local_60 + iVar39;
        local_70 = local_70 + (int)local_60;
        if (iVar41 <= local_70) {
          return 0;
        }
      }
      if (iVar41 <= local_70) {
        return 0;
      }
      local_74 = local_70;
LAB_00559cfa:
      uVar25 = iVar41 - local_74;
      if ((int)uVar25 < 1) {
        return 0;
      }
      puVar23 = (undefined4 *)(iVar45 + local_74 * 2);
      for (uVar37 = uVar25 >> 1; uVar37 != 0; uVar37 = uVar37 - 1) {
        *puVar23 = 0;
        puVar23 = puVar23 + 1;
      }
      for (uVar25 = (uint)((uVar25 & 1) != 0); uVar25 != 0; uVar25 = uVar25 - 1) {
        *(undefined2 *)puVar23 = 0;
        puVar23 = (undefined4 *)((int)puVar23 + 2);
      }
      return 0;
    }
    if ((short)piVar2[0xd] != 3) {
      return 0;
    }
    iVar45 = piVar2[0x13];
    local_34 = piVar3[0x13];
    if (*(short *)((int)piVar2 + 0x36) != 1) {
      if (*(short *)((int)piVar2 + 0x36) != 2) {
        return 0;
      }
      iVar49 = iVar16 * 2;
      local_74 = 0;
      for (local_70 = 0; (iVar49 < iVar4 && (iVar16 * 2 + local_70 < iVar41));
          local_70 = local_70 + (int)local_60) {
        local_3c = (float *)0x0;
        local_54 = (float)iVar15;
        if (iVar15 <= iVar16) {
          local_8 = (float *)(iVar45 + (iVar15 + local_74) * 8);
          local_64 = iVar15;
          do {
            local_5c = 0.0;
            iVar49 = 0;
            pfVar52 = (float *)(iVar45 + local_74 * 8);
            pfVar18 = local_8;
            if (3 < iVar14) {
              iVar39 = (iVar14 - 4U >> 2) + 1;
              iVar49 = iVar39 * 4;
              pfVar22 = pfVar52;
              pfVar44 = local_8;
              do {
                pfVar52 = pfVar22 + 8;
                pfVar18 = pfVar44 + 8;
                iVar39 = iVar39 + -1;
                local_5c = pfVar44[6] * pfVar22[6] +
                           pfVar44[4] * pfVar22[4] +
                           pfVar44[2] * pfVar22[2] + *pfVar44 * *pfVar22 + local_5c;
                pfVar22 = pfVar52;
                pfVar44 = pfVar18;
              } while (iVar39 != 0);
            }
            if (iVar49 < iVar14) {
              iVar49 = iVar14 - iVar49;
              do {
                fVar27 = *pfVar18;
                pfVar18 = pfVar18 + 2;
                iVar49 = iVar49 + -1;
                local_5c = fVar27 * *pfVar52 + local_5c;
                pfVar52 = pfVar52 + 2;
              } while (iVar49 != 0);
            }
            if ((float)local_3c < local_5c) {
              local_3c = (float *)local_5c;
              local_54 = (float)local_64;
            }
            local_8 = local_8 + 2;
            local_64 = local_64 + 1;
          } while (local_64 <= iVar16);
        }
        pfVar52 = (float *)(iVar45 + local_74 * 8);
        pfVar18 = (float *)(iVar45 + ((int)local_54 + local_74) * 8);
        pfVar22 = (float *)(local_34 + local_70 * 8);
        local_50 = 0.0;
        if (3 < (int)local_54) {
          fVar27 = (float)(int)local_54;
          local_4 = (float *)0x2;
          pfVar44 = pfVar52;
          pfVar21 = pfVar18;
          pfVar17 = pfVar22;
          local_8 = (float *)((int)local_54 + -2);
          do {
            iVar39 = (int)local_50 + 4;
            pfVar52 = pfVar44 + 8;
            pfVar18 = pfVar21 + 8;
            pfVar22 = pfVar17 + 8;
            *pfVar17 = ((float)(int)local_50 * *pfVar21 + (float)((int)local_8 + 2) * *pfVar44) /
                       fVar27;
            pfVar17[2] = ((float)((int)local_4 + -1) * pfVar21[2] +
                         (float)((int)local_8 + 1) * pfVar44[2]) / fVar27;
            fVar5 = (float)(int)local_4;
            iVar49 = (int)local_4 + 1;
            local_4 = (float *)((int)local_4 + 4);
            pfVar17[4] = (pfVar44[4] * (float)(int)local_8 + pfVar21[4] * fVar5) / fVar27;
            pfVar17[6] = ((float)iVar49 * pfVar21[6] + (float)((int)local_8 + -1) * pfVar44[6]) /
                         fVar27;
            pfVar44 = pfVar52;
            pfVar21 = pfVar18;
            pfVar17 = pfVar22;
            local_50 = (float)iVar39;
            local_8 = (float *)((int)local_8 + -4);
          } while (iVar39 < (int)local_54 + -3);
        }
        if ((int)local_50 < (int)local_54) {
          local_4 = (float *)((int)local_54 - (int)local_50);
          do {
            fVar5 = (float)(int)local_50;
            local_50 = (float)((int)local_50 + 1);
            fVar27 = *pfVar18;
            pfVar18 = pfVar18 + 2;
            *pfVar22 = ((float)(int)local_4 * *pfVar52 + fVar5 * fVar27) / (float)(int)local_54;
            pfVar52 = pfVar52 + 2;
            pfVar22 = pfVar22 + 2;
            local_4 = (float *)((int)local_4 + -1);
          } while ((int)local_50 < (int)local_54);
        }
        if (local_70 + (int)local_54 < iVar41) {
          iVar49 = (int)local_54 * 2 + local_74;
          if (iVar49 < iVar4) {
            iVar39 = ((int)local_54 << 0x12) / (iVar13 + -0x200) + 0x100;
            local_60 = (float)((int)(iVar39 + (iVar39 >> 0x1f & 0x1ffU)) >> 9);
            puVar23 = (undefined4 *)(iVar45 + iVar49 * 8);
            puVar34 = (undefined4 *)(local_34 + (local_70 + (int)local_54) * 8);
            iVar49 = (int)local_60 - (int)local_54;
            if (iVar4 < iVar49 + (int)local_54 * 2 + local_74) {
              iVar49 = (iVar4 + (int)local_54 * -2) - local_74;
              local_60 = (float)(iVar49 + (int)local_54);
            }
            if (iVar41 < iVar49 + (int)local_54 + local_70) {
              iVar49 = (iVar41 - (int)local_54) - local_70;
              local_60 = (float)(iVar49 + (int)local_54);
            }
            iVar39 = 0;
            if (3 < iVar49) {
              iVar50 = (iVar49 - 4U >> 2) + 1;
              iVar39 = iVar50 * 4;
              puVar35 = puVar23;
              puVar43 = puVar34;
              do {
                puVar23 = puVar35 + 8;
                *puVar43 = *puVar35;
                puVar34 = puVar43 + 8;
                iVar50 = iVar50 + -1;
                puVar43[2] = puVar35[2];
                puVar43[4] = puVar35[4];
                puVar43[6] = puVar35[6];
                puVar35 = puVar23;
                puVar43 = puVar34;
              } while (iVar50 != 0);
            }
            if (iVar39 < iVar49) {
              iVar49 = iVar49 - iVar39;
              do {
                uVar1 = *puVar23;
                puVar23 = puVar23 + 2;
                *puVar34 = uVar1;
                puVar34 = puVar34 + 2;
                iVar49 = iVar49 + -1;
              } while (iVar49 != 0);
            }
          }
        }
        local_74 = local_74 + (int)local_60 + (int)local_54;
        iVar49 = iVar16 * 2 + local_74;
      }
      do {
        if (iVar41 <= local_70) {
LAB_00557819:
          local_74 = 0;
          iVar49 = iVar16 * 2;
          for (local_70 = 0; (iVar49 < iVar4 && (iVar16 * 2 + local_70 < iVar41));
              local_70 = local_70 + (int)local_60) {
            local_3c = (float *)0x0;
            local_54 = (float)iVar15;
            if (iVar15 <= iVar16) {
              pfVar52 = (float *)(iVar45 + 4 + local_74 * 8);
              pfVar18 = (float *)(iVar45 + 4 + (local_74 + iVar15) * 8);
              local_64 = iVar15;
              do {
                local_5c = 0.0;
                iVar49 = 0;
                pfVar22 = pfVar52;
                pfVar44 = pfVar18;
                if (3 < iVar14) {
                  iVar39 = (iVar14 - 4U >> 2) + 1;
                  iVar49 = iVar39 * 4;
                  pfVar21 = pfVar52;
                  pfVar17 = pfVar18;
                  do {
                    pfVar22 = pfVar21 + 8;
                    pfVar44 = pfVar17 + 8;
                    iVar39 = iVar39 + -1;
                    local_5c = pfVar17[6] * pfVar21[6] +
                               pfVar17[4] * pfVar21[4] +
                               pfVar17[2] * pfVar21[2] + *pfVar17 * *pfVar21 + local_5c;
                    pfVar21 = pfVar22;
                    pfVar17 = pfVar44;
                  } while (iVar39 != 0);
                }
                if (iVar49 < iVar14) {
                  iVar49 = iVar14 - iVar49;
                  do {
                    fVar27 = *pfVar44;
                    pfVar44 = pfVar44 + 2;
                    iVar49 = iVar49 + -1;
                    local_5c = fVar27 * *pfVar22 + local_5c;
                    pfVar22 = pfVar22 + 2;
                  } while (iVar49 != 0);
                }
                if ((float)local_3c < local_5c) {
                  local_3c = (float *)local_5c;
                  local_54 = (float)local_64;
                }
                local_64 = local_64 + 1;
                pfVar18 = pfVar18 + 2;
              } while (local_64 <= iVar16);
            }
            pfVar52 = (float *)(iVar45 + 4 + local_74 * 8);
            pfVar18 = (float *)(iVar45 + 4 + (local_74 + (int)local_54) * 8);
            pfVar22 = (float *)(local_34 + 4 + local_70 * 8);
            local_50 = 0.0;
            if (3 < (int)local_54) {
              fVar27 = (float)(int)local_54;
              local_4 = (float *)0x2;
              pfVar44 = pfVar52;
              pfVar21 = pfVar18;
              pfVar17 = pfVar22;
              local_8 = (float *)((int)local_54 + -2);
              do {
                iVar39 = (int)local_50 + 4;
                pfVar52 = pfVar44 + 8;
                pfVar18 = pfVar21 + 8;
                pfVar22 = pfVar17 + 8;
                *pfVar17 = ((float)(int)local_50 * *pfVar21 + (float)((int)local_8 + 2) * *pfVar44)
                           / fVar27;
                pfVar17[2] = ((float)((int)local_4 + -1) * pfVar21[2] +
                             (float)((int)local_8 + 1) * pfVar44[2]) / fVar27;
                fVar5 = (float)(int)local_4;
                iVar49 = (int)local_4 + 1;
                local_4 = (float *)((int)local_4 + 4);
                pfVar17[4] = (pfVar44[4] * (float)(int)local_8 + pfVar21[4] * fVar5) / fVar27;
                pfVar17[6] = ((float)iVar49 * pfVar21[6] + (float)((int)local_8 + -1) * pfVar44[6])
                             / fVar27;
                pfVar44 = pfVar52;
                pfVar21 = pfVar18;
                pfVar17 = pfVar22;
                local_50 = (float)iVar39;
                local_8 = (float *)((int)local_8 + -4);
              } while (iVar39 < (int)local_54 + -3);
            }
            if ((int)local_50 < (int)local_54) {
              local_4 = (float *)((int)local_54 - (int)local_50);
              do {
                fVar27 = (float)(int)local_4;
                iVar49 = (int)local_50 + 1;
                local_4 = (float *)((int)local_4 + -1);
                *pfVar22 = ((float)(int)local_50 * *pfVar18 + fVar27 * *pfVar52) /
                           (float)(int)local_54;
                pfVar52 = pfVar52 + 2;
                pfVar18 = pfVar18 + 2;
                pfVar22 = pfVar22 + 2;
                local_50 = (float)iVar49;
              } while (iVar49 < (int)local_54);
            }
            if ((int)local_54 + local_70 < iVar41) {
              iVar49 = local_74 + (int)local_54 * 2;
              if (iVar49 < iVar4) {
                iVar39 = ((int)local_54 << 0x12) / (iVar13 + -0x200) + 0x100;
                local_60 = (float)((int)(iVar39 + (iVar39 >> 0x1f & 0x1ffU)) >> 9);
                iVar39 = (int)local_60 - (int)local_54;
                puVar23 = (undefined4 *)(iVar45 + 4 + iVar49 * 8);
                puVar34 = (undefined4 *)(local_34 + 4 + ((int)local_54 + local_70) * 8);
                if (iVar4 < iVar39 + (int)local_54 * 2 + local_74) {
                  iVar39 = (iVar4 + (int)local_54 * -2) - local_74;
                  local_60 = (float)(iVar39 + (int)local_54);
                }
                if (iVar41 < iVar39 + (int)local_54 + local_70) {
                  iVar39 = (iVar41 - (int)local_54) - local_70;
                  local_60 = (float)(iVar39 + (int)local_54);
                }
                iVar49 = 0;
                if (3 < iVar39) {
                  iVar50 = (iVar39 - 4U >> 2) + 1;
                  iVar49 = iVar50 * 4;
                  puVar35 = puVar23;
                  puVar43 = puVar34;
                  do {
                    puVar23 = puVar35 + 8;
                    *puVar43 = *puVar35;
                    puVar34 = puVar43 + 8;
                    iVar50 = iVar50 + -1;
                    puVar43[2] = puVar35[2];
                    puVar43[4] = puVar35[4];
                    puVar43[6] = puVar35[6];
                    puVar35 = puVar23;
                    puVar43 = puVar34;
                  } while (iVar50 != 0);
                }
                if (iVar49 < iVar39) {
                  iVar39 = iVar39 - iVar49;
                  do {
                    uVar1 = *puVar23;
                    puVar23 = puVar23 + 2;
                    *puVar34 = uVar1;
                    puVar34 = puVar34 + 2;
                    iVar39 = iVar39 + -1;
                  } while (iVar39 != 0);
                }
              }
            }
            local_74 = local_74 + (int)local_60 + (int)local_54;
            iVar49 = local_74 + iVar16 * 2;
          }
          if (iVar41 <= local_70) {
            return 0;
          }
          while (local_74 < iVar4) {
            local_3c = (float *)0x0;
            local_54 = (float)iVar15;
            if (iVar15 <= iVar16) {
              pfVar52 = (float *)(iVar45 + 4 + local_74 * 8);
              local_10 = (float *)(iVar15 + local_74 + 3);
              local_c = (float *)(iVar45 + 4 + (iVar15 + local_74) * 8);
              local_64 = iVar15;
              do {
                local_5c = 0.0;
                iVar49 = 0;
                pfVar18 = pfVar52;
                pfVar22 = local_c;
                if (3 < iVar14) {
                  iVar39 = local_74 + 1;
                  iVar50 = (iVar14 - 4U >> 2) + 1;
                  iVar49 = iVar50 * 4;
                  pfVar44 = local_10;
                  do {
                    if (iVar39 + -1 < iVar4) {
                      local_30 = (float *)*pfVar18;
                    }
                    else {
                      local_30 = (float *)0x0;
                    }
                    if (iVar39 + -1 + local_64 < iVar4) {
                      local_38 = (float *)*pfVar22;
                    }
                    else {
                      local_38 = (float *)0x0;
                    }
                    fVar27 = (float)local_38 * (float)local_30;
                    if (iVar39 < iVar4) {
                      local_30 = (float *)pfVar18[2];
                    }
                    else {
                      local_30 = (float *)0x0;
                    }
                    if (local_64 + iVar39 < iVar4) {
                      local_38 = (float *)pfVar22[2];
                    }
                    else {
                      local_38 = (float *)0x0;
                    }
                    fVar5 = (float)local_38 * (float)local_30;
                    if (iVar39 + 1 < iVar4) {
                      local_30 = (float *)pfVar18[4];
                    }
                    else {
                      local_30 = (float *)0x0;
                    }
                    if ((int)pfVar44 + -1 < iVar4) {
                      local_38 = (float *)pfVar22[4];
                    }
                    else {
                      local_38 = (float *)0x0;
                    }
                    fVar6 = (float)local_38 * (float)local_30;
                    if (iVar39 + 2 < iVar4) {
                      local_30 = (float *)pfVar18[6];
                    }
                    else {
                      local_30 = (float *)0x0;
                    }
                    if ((int)pfVar44 < iVar4) {
                      local_38 = (float *)pfVar22[6];
                    }
                    else {
                      local_38 = (float *)0x0;
                    }
                    pfVar18 = pfVar18 + 8;
                    pfVar22 = pfVar22 + 8;
                    iVar39 = iVar39 + 4;
                    pfVar44 = (float *)((int)pfVar44 + 4);
                    iVar50 = iVar50 + -1;
                    local_5c = (float)local_38 * (float)local_30 + fVar6 + fVar5 + fVar27 + local_5c
                    ;
                  } while (iVar50 != 0);
                }
                if (iVar49 < iVar14) {
                  iVar39 = iVar49 + local_74;
                  iVar50 = local_64 + iVar49 + local_74;
                  iVar49 = iVar14 - iVar49;
                  do {
                    if (iVar39 < iVar4) {
                      local_30 = (float *)*pfVar18;
                    }
                    else {
                      local_30 = (float *)0x0;
                    }
                    if (iVar50 < iVar4) {
                      local_38 = (float *)*pfVar22;
                    }
                    else {
                      local_38 = (float *)0x0;
                    }
                    pfVar18 = pfVar18 + 2;
                    pfVar22 = pfVar22 + 2;
                    iVar39 = iVar39 + 1;
                    iVar50 = iVar50 + 1;
                    iVar49 = iVar49 + -1;
                    local_5c = (float)local_38 * (float)local_30 + local_5c;
                  } while (iVar49 != 0);
                }
                if ((float)local_3c < local_5c) {
                  local_3c = (float *)local_5c;
                  local_54 = (float)local_64;
                }
                local_c = local_c + 2;
                local_10 = (float *)((int)local_10 + 1);
                local_64 = local_64 + 1;
              } while (local_64 <= iVar16);
            }
            local_38 = (float *)(iVar45 + 4 + local_74 * 8);
            iVar49 = local_74 + (int)local_54;
            local_28 = (float *)(iVar45 + 4 + iVar49 * 8);
            pfVar52 = (float *)(local_34 + 4 + local_70 * 8);
            local_50 = 0.0;
            if (3 < (int)local_54) {
              local_4 = (float *)((int)local_54 + -2);
              local_2c = (float *)(local_74 + 2);
              iVar50 = local_70 + 1;
              iVar39 = iVar49 + 2;
              do {
                if ((-2 - (int)local_54) + iVar39 < iVar4) {
                  local_3c = (float *)*local_38;
                }
                else {
                  local_3c = (float *)0x0;
                }
                if (iVar39 + -2 < iVar4) {
                  local_30 = (float *)*local_28;
                }
                else {
                  local_30 = (float *)0x0;
                }
                if (iVar50 + -1 < iVar41) {
                  *pfVar52 = ((float)(int)local_50 * (float)local_30 +
                             (float)((int)local_4 + 2) * (float)local_3c) / (float)(int)local_54;
                }
                if ((-1 - (int)local_54) + iVar39 < iVar4) {
                  local_3c = (float *)local_38[2];
                }
                else {
                  local_3c = (float *)0x0;
                }
                if (iVar39 + -1 < iVar4) {
                  local_30 = (float *)local_28[2];
                }
                else {
                  local_30 = (float *)0x0;
                }
                if (iVar50 < iVar41) {
                  pfVar52[2] = ((float)((int)local_4 + 1) * (float)local_3c +
                               (float)((-1 - local_74) + (int)local_2c) * (float)local_30) /
                               (float)(int)local_54;
                }
                if ((int)local_2c < iVar4) {
                  local_3c = (float *)local_38[4];
                }
                else {
                  local_3c = (float *)0x0;
                }
                if (iVar39 < iVar4) {
                  local_30 = (float *)local_28[4];
                }
                else {
                  local_30 = (float *)0x0;
                }
                if (iVar50 + 1 < iVar41) {
                  pfVar52[4] = ((float)(int)local_4 * (float)local_3c +
                               (float)((1 - local_70) + iVar50) * (float)local_30) /
                               (float)(int)local_54;
                }
                if ((1 - (int)local_54) + iVar39 < iVar4) {
                  local_3c = (float *)local_38[6];
                }
                else {
                  local_3c = (float *)0x0;
                }
                if (iVar39 + 1 < iVar4) {
                  local_30 = (float *)local_28[6];
                }
                else {
                  local_30 = (float *)0x0;
                }
                if (iVar50 + 2 < iVar41) {
                  pfVar52[6] = ((float)((int)local_4 + -1) * (float)local_3c +
                               (float)((2 - local_70) + iVar50) * (float)local_30) /
                               (float)(int)local_54;
                }
                local_28 = local_28 + 8;
                local_2c = (float *)((int)local_2c + 4);
                local_50 = (float)((int)local_50 + 4);
                local_38 = local_38 + 8;
                local_4 = (float *)((int)local_4 + -4);
                pfVar52 = pfVar52 + 8;
                iVar50 = iVar50 + 4;
                iVar39 = iVar39 + 4;
              } while ((int)local_50 < (int)local_54 + -3);
            }
            if ((int)local_50 < (int)local_54) {
              local_4 = (float *)((int)local_54 - (int)local_50);
              iVar39 = local_74 + (int)local_50;
              do {
                if (iVar39 < iVar4) {
                  local_3c = (float *)*local_38;
                }
                else {
                  local_3c = (float *)0x0;
                }
                if ((int)local_54 + iVar39 < iVar4) {
                  local_30 = (float *)*local_28;
                }
                else {
                  local_30 = (float *)0x0;
                }
                if ((local_70 - local_74) + iVar39 < iVar41) {
                  *pfVar52 = ((float)(int)local_4 * (float)local_3c +
                             (float)(int)local_50 * (float)local_30) / (float)(int)local_54;
                }
                local_28 = local_28 + 2;
                local_50 = (float)((int)local_50 + 1);
                local_4 = (float *)((int)local_4 + -1);
                local_38 = local_38 + 2;
                pfVar52 = pfVar52 + 2;
                iVar39 = iVar39 + 1;
              } while ((int)local_50 < (int)local_54);
            }
            iVar39 = (int)local_54 + local_70;
            if ((iVar39 < iVar41) && (iVar50 = local_74 + (int)local_54 * 2, iVar50 < iVar4)) {
              puVar23 = (undefined4 *)(local_34 + 4 + iVar39 * 8);
              iVar53 = ((int)local_54 << 0x12) / (iVar13 + -0x200) + 0x100;
              local_38 = (float *)(iVar45 + 4 + iVar50 * 8);
              local_60 = (float)((int)(iVar53 + (iVar53 >> 0x1f & 0x1ffU)) >> 9);
              iVar53 = (int)local_60 - (int)local_54;
              if (iVar4 < iVar50 + iVar53) {
                iVar53 = (iVar4 + (int)local_54 * -2) - local_74;
                local_60 = (float)((int)local_54 + iVar53);
              }
              if (iVar41 < iVar39 + iVar53) {
                iVar53 = (iVar41 - (int)local_54) - local_70;
                local_60 = (float)((int)local_54 + iVar53);
              }
              iVar39 = 0;
              if (3 < iVar53) {
                iVar49 = iVar49 + 2;
                iVar50 = (iVar53 - 4U >> 2) + 1;
                iVar39 = iVar50 * 4;
                do {
                  if (iVar49 + -2 < iVar4) {
                    local_30 = (float *)*local_38;
                  }
                  else {
                    local_30 = (float *)0x0;
                  }
                  *puVar23 = local_30;
                  if (iVar49 + -1 < iVar4) {
                    local_30 = (float *)local_38[2];
                  }
                  else {
                    local_30 = (float *)0x0;
                  }
                  puVar23[2] = local_30;
                  if (iVar49 < iVar4) {
                    local_30 = (float *)local_38[4];
                  }
                  else {
                    local_30 = (float *)0x0;
                  }
                  puVar23[4] = local_30;
                  if (iVar49 + 1 < iVar4) {
                    local_30 = (float *)local_38[6];
                  }
                  else {
                    local_30 = (float *)0x0;
                  }
                  local_38 = local_38 + 8;
                  puVar23[6] = local_30;
                  puVar23 = puVar23 + 8;
                  iVar49 = iVar49 + 4;
                  iVar50 = iVar50 + -1;
                } while (iVar50 != 0);
              }
              if (iVar39 < iVar53) {
                iVar49 = iVar39 + (int)local_54 + local_74;
                iVar53 = iVar53 - iVar39;
                do {
                  if (iVar49 < iVar4) {
                    local_30 = (float *)*local_38;
                  }
                  else {
                    local_30 = (float *)0x0;
                  }
                  local_38 = local_38 + 2;
                  *puVar23 = local_30;
                  puVar23 = puVar23 + 2;
                  iVar49 = iVar49 + 1;
                  iVar53 = iVar53 + -1;
                } while (iVar53 != 0);
              }
            }
            local_74 = local_74 + (int)local_60 + (int)local_54;
            local_70 = local_70 + (int)local_60;
            if (iVar41 <= local_70) {
              return 0;
            }
          }
          if (iVar41 <= local_70) {
            return 0;
          }
          iVar41 = iVar41 - local_70;
          puVar23 = (undefined4 *)(local_34 + 4 + local_70 * 8);
          if (iVar41 < 1) {
            return 0;
          }
          do {
            *puVar23 = 0;
            puVar23 = puVar23 + 2;
            iVar41 = iVar41 + -1;
          } while (iVar41 != 0);
          return 0;
        }
        if (iVar4 <= local_74) {
          if (local_70 < iVar41) {
            iVar49 = iVar41 - local_70;
            puVar23 = (undefined4 *)(local_34 + local_70 * 8);
            if (0 < iVar49) {
              do {
                *puVar23 = 0;
                puVar23 = puVar23 + 2;
                iVar49 = iVar49 + -1;
              } while (iVar49 != 0);
            }
          }
          goto LAB_00557819;
        }
        local_3c = (float *)0x0;
        local_54 = (float)iVar15;
        if (iVar15 <= iVar16) {
          pfVar52 = (float *)(iVar45 + local_74 * 8);
          local_8 = (float *)(iVar15 + local_74 + 3);
          local_4 = (float *)(iVar45 + (iVar15 + local_74) * 8);
          iVar49 = iVar15;
          local_64 = iVar15;
          do {
            local_5c = 0.0;
            local_50 = 0.0;
            pfVar18 = pfVar52;
            pfVar22 = local_4;
            if (3 < iVar14) {
              local_10 = local_8;
              iVar50 = (iVar14 - 4U >> 2) + 1;
              local_50 = (float)(iVar50 * 4);
              iVar39 = local_74 + 1;
              do {
                if (iVar39 + -1 < iVar4) {
                  local_54 = *pfVar18;
                }
                else {
                  local_54 = 0.0;
                }
                if (iVar39 + -1 + local_64 < iVar4) {
                  local_38 = (float *)*pfVar22;
                }
                else {
                  local_38 = (float *)0x0;
                }
                fVar27 = (float)local_38 * local_54;
                if (iVar39 < iVar4) {
                  local_54 = pfVar18[2];
                }
                else {
                  local_54 = 0.0;
                }
                if (local_64 + iVar39 < iVar4) {
                  local_38 = (float *)pfVar22[2];
                }
                else {
                  local_38 = (float *)0x0;
                }
                fVar5 = (float)local_38 * local_54;
                if (iVar39 + 1 < iVar4) {
                  local_54 = pfVar18[4];
                }
                else {
                  local_54 = 0.0;
                }
                if ((int)local_10 + -1 < iVar4) {
                  local_38 = (float *)pfVar22[4];
                }
                else {
                  local_38 = (float *)0x0;
                }
                fVar6 = (float)local_38 * local_54;
                if (iVar39 + 2 < iVar4) {
                  local_54 = pfVar18[6];
                }
                else {
                  local_54 = 0.0;
                }
                if ((int)local_10 < iVar4) {
                  local_38 = (float *)pfVar22[6];
                }
                else {
                  local_38 = (float *)0x0;
                }
                local_10 = (float *)((int)local_10 + 4);
                pfVar18 = pfVar18 + 8;
                pfVar22 = pfVar22 + 8;
                iVar39 = iVar39 + 4;
                iVar50 = iVar50 + -1;
                local_5c = (float)local_38 * local_54 + fVar6 + fVar5 + fVar27 + local_5c;
              } while (iVar50 != 0);
            }
            if ((int)local_50 < iVar14) {
              iVar39 = (int)local_50 + local_64 + local_74;
              iVar53 = (int)local_50 + local_74;
              iVar50 = iVar14 - (int)local_50;
              do {
                if (iVar53 < iVar4) {
                  local_54 = *pfVar18;
                }
                else {
                  local_54 = 0.0;
                }
                if (iVar39 < iVar4) {
                  local_38 = (float *)*pfVar22;
                }
                else {
                  local_38 = (float *)0x0;
                }
                pfVar18 = pfVar18 + 2;
                pfVar22 = pfVar22 + 2;
                iVar53 = iVar53 + 1;
                iVar39 = iVar39 + 1;
                iVar50 = iVar50 + -1;
                local_5c = (float)local_38 * local_54 + local_5c;
              } while (iVar50 != 0);
            }
            if ((float)local_3c < local_5c) {
              local_3c = (float *)local_5c;
              iVar49 = local_64;
            }
            local_8 = (float *)((int)local_8 + 1);
            local_64 = local_64 + 1;
            local_4 = local_4 + 2;
          } while (local_64 <= iVar16);
          local_54 = (float)iVar49;
        }
        local_28 = (float *)(iVar45 + local_74 * 8);
        iVar49 = (int)local_54 + local_74;
        local_2c = (float *)(iVar45 + iVar49 * 8);
        local_30 = (float *)(local_34 + local_70 * 8);
        local_50 = 0.0;
        if (3 < (int)local_54) {
          local_38 = (float *)(local_74 + 2);
          iVar39 = local_70 + 1;
          iVar50 = iVar49 + 2;
          local_4 = (float *)((int)local_54 + -2);
          do {
            if ((-2 - (int)local_54) + iVar50 < iVar4) {
              local_3c = (float *)*local_28;
            }
            else {
              local_3c = (float *)0x0;
            }
            if (iVar50 + -2 < iVar4) {
              local_5c = *local_2c;
            }
            else {
              local_5c = 0.0;
            }
            if (iVar39 + -1 < iVar41) {
              *local_30 = ((float)(int)local_50 * local_5c +
                          (float)((int)local_4 + 2) * (float)local_3c) / (float)(int)local_54;
            }
            if ((-1 - (int)local_54) + iVar50 < iVar4) {
              local_3c = (float *)local_28[2];
            }
            else {
              local_3c = (float *)0x0;
            }
            if (iVar50 + -1 < iVar4) {
              local_5c = local_2c[2];
            }
            else {
              local_5c = 0.0;
            }
            if (iVar39 < iVar41) {
              local_30[2] = ((float)((int)local_4 + 1) * (float)local_3c +
                            (float)((-1 - local_74) + (int)local_38) * local_5c) /
                            (float)(int)local_54;
            }
            if ((int)local_38 < iVar4) {
              local_3c = (float *)local_28[4];
            }
            else {
              local_3c = (float *)0x0;
            }
            if (iVar50 < iVar4) {
              local_5c = local_2c[4];
            }
            else {
              local_5c = 0.0;
            }
            if (iVar39 + 1 < iVar41) {
              local_30[4] = ((float)(int)local_4 * (float)local_3c +
                            (float)((1 - local_70) + iVar39) * local_5c) / (float)(int)local_54;
            }
            if ((1 - (int)local_54) + iVar50 < iVar4) {
              local_3c = (float *)local_28[6];
            }
            else {
              local_3c = (float *)0x0;
            }
            if (iVar50 + 1 < iVar4) {
              local_5c = local_2c[6];
            }
            else {
              local_5c = 0.0;
            }
            if (iVar39 + 2 < iVar41) {
              local_30[6] = ((float)((int)local_4 + -1) * (float)local_3c +
                            (float)((2 - local_70) + iVar39) * local_5c) / (float)(int)local_54;
            }
            local_38 = (float *)((int)local_38 + 4);
            local_28 = local_28 + 8;
            local_2c = local_2c + 8;
            local_30 = local_30 + 8;
            local_50 = (float)((int)local_50 + 4);
            local_4 = (float *)((int)local_4 + -4);
            iVar39 = iVar39 + 4;
            iVar50 = iVar50 + 4;
          } while ((int)local_50 < (int)local_54 + -3);
        }
        if ((int)local_50 < (int)local_54) {
          local_4 = (float *)((int)local_54 - (int)local_50);
          iVar39 = (int)local_50 + local_74;
          do {
            if (iVar39 < iVar4) {
              local_3c = (float *)*local_28;
            }
            else {
              local_3c = (float *)0x0;
            }
            if (iVar39 + (int)local_54 < iVar4) {
              local_5c = *local_2c;
            }
            else {
              local_5c = 0.0;
            }
            if ((local_70 - local_74) + iVar39 < iVar41) {
              *local_30 = ((float)(int)local_50 * local_5c + (float)(int)local_4 * (float)local_3c)
                          / (float)(int)local_54;
            }
            local_28 = local_28 + 2;
            local_2c = local_2c + 2;
            local_30 = local_30 + 2;
            local_50 = (float)((int)local_50 + 1);
            local_4 = (float *)((int)local_4 + -1);
            iVar39 = iVar39 + 1;
          } while ((int)local_50 < (int)local_54);
        }
        if (local_70 + (int)local_54 < iVar41) {
          iVar39 = (int)local_54 * 2 + local_74;
          if (iVar39 < iVar4) {
            iVar50 = ((int)local_54 << 0x12) / (iVar13 + -0x200) + 0x100;
            puVar23 = (undefined4 *)(iVar45 + iVar39 * 8);
            local_60 = (float)((int)(iVar50 + (iVar50 >> 0x1f & 0x1ffU)) >> 9);
            iVar39 = (int)local_60 - (int)local_54;
            puVar34 = (undefined4 *)(local_34 + (local_70 + (int)local_54) * 8);
            if (iVar4 < iVar39 + (int)local_54 * 2 + local_74) {
              iVar39 = (iVar4 + (int)local_54 * -2) - local_74;
              local_60 = (float)(iVar39 + (int)local_54);
            }
            if (iVar41 < iVar39 + (int)local_54 + local_70) {
              iVar39 = (iVar41 - (int)local_54) - local_70;
              local_60 = (float)(iVar39 + (int)local_54);
            }
            iVar50 = 0;
            if (3 < iVar39) {
              iVar49 = iVar49 + 2;
              iVar53 = (iVar39 - 4U >> 2) + 1;
              iVar50 = iVar53 * 4;
              do {
                if (iVar49 + -2 < iVar4) {
                  local_38 = (float *)*puVar23;
                }
                else {
                  local_38 = (float *)0x0;
                }
                *puVar34 = local_38;
                if (iVar49 + -1 < iVar4) {
                  local_38 = (float *)puVar23[2];
                }
                else {
                  local_38 = (float *)0x0;
                }
                puVar34[2] = local_38;
                if (iVar49 < iVar4) {
                  local_38 = (float *)puVar23[4];
                }
                else {
                  local_38 = (float *)0x0;
                }
                puVar34[4] = local_38;
                if (iVar49 + 1 < iVar4) {
                  local_38 = (float *)puVar23[6];
                }
                else {
                  local_38 = (float *)0x0;
                }
                puVar23 = puVar23 + 8;
                puVar34[6] = local_38;
                puVar34 = puVar34 + 8;
                iVar49 = iVar49 + 4;
                iVar53 = iVar53 + -1;
              } while (iVar53 != 0);
            }
            if (iVar50 < iVar39) {
              iVar49 = iVar50 + (int)local_54 + local_74;
              iVar39 = iVar39 - iVar50;
              do {
                if (iVar49 < iVar4) {
                  local_38 = (float *)*puVar23;
                }
                else {
                  local_38 = (float *)0x0;
                }
                puVar23 = puVar23 + 2;
                *puVar34 = local_38;
                puVar34 = puVar34 + 2;
                iVar49 = iVar49 + 1;
                iVar39 = iVar39 + -1;
              } while (iVar39 != 0);
            }
          }
        }
        local_74 = local_74 + (int)local_60 + (int)local_54;
        local_70 = local_70 + (int)local_60;
      } while( true );
    }
    iVar49 = iVar16 * 2;
    local_74 = 0;
    for (local_70 = 0; (iVar49 < iVar4 && (iVar16 * 2 + local_70 < iVar41));
        local_70 = local_70 + (int)local_60) {
      local_3c = (float *)0x0;
      local_54 = (float)iVar15;
      if (iVar15 <= iVar16) {
        pfVar52 = (float *)(iVar45 + local_74 * 4);
        pfVar18 = (float *)(iVar45 + (local_74 + iVar15) * 4);
        local_64 = iVar15;
        do {
          local_5c = 0.0;
          iVar49 = 0;
          pfVar22 = pfVar52;
          pfVar44 = pfVar18;
          if (3 < iVar14) {
            iVar39 = (iVar14 - 4U >> 2) + 1;
            iVar49 = iVar39 * 4;
            pfVar21 = pfVar52;
            pfVar17 = pfVar18;
            do {
              pfVar22 = pfVar21 + 4;
              pfVar44 = pfVar17 + 4;
              iVar39 = iVar39 + -1;
              local_5c = pfVar17[3] * pfVar21[3] +
                         pfVar17[2] * pfVar21[2] +
                         pfVar17[1] * pfVar21[1] + *pfVar17 * *pfVar21 + local_5c;
              pfVar21 = pfVar22;
              pfVar17 = pfVar44;
            } while (iVar39 != 0);
          }
          if (iVar49 < iVar14) {
            iVar49 = iVar14 - iVar49;
            do {
              fVar27 = *pfVar44;
              pfVar44 = pfVar44 + 1;
              iVar49 = iVar49 + -1;
              local_5c = fVar27 * *pfVar22 + local_5c;
              pfVar22 = pfVar22 + 1;
            } while (iVar49 != 0);
          }
          if ((float)local_3c < local_5c) {
            local_3c = (float *)local_5c;
            local_54 = (float)local_64;
          }
          local_64 = local_64 + 1;
          pfVar18 = pfVar18 + 1;
        } while (local_64 <= iVar16);
      }
      pfVar52 = (float *)(iVar45 + local_74 * 4);
      pfVar18 = (float *)(iVar45 + (local_74 + (int)local_54) * 4);
      pfVar22 = (float *)(local_34 + local_70 * 4);
      local_50 = 0.0;
      if (3 < (int)local_54) {
        fVar27 = (float)(int)local_54;
        local_4 = (float *)0x2;
        pfVar44 = pfVar52;
        pfVar21 = pfVar18;
        pfVar17 = pfVar22;
        local_8 = (float *)((int)local_54 + -2);
        do {
          iVar39 = (int)local_50 + 4;
          pfVar52 = pfVar44 + 4;
          pfVar18 = pfVar21 + 4;
          pfVar22 = pfVar17 + 4;
          *pfVar17 = ((float)(int)local_50 * *pfVar21 + (float)((int)local_8 + 2) * *pfVar44) /
                     fVar27;
          pfVar17[1] = ((float)((int)local_4 + -1) * pfVar21[1] +
                       (float)((int)local_8 + 1) * pfVar44[1]) / fVar27;
          fVar5 = (float)(int)local_4;
          iVar49 = (int)local_4 + 1;
          local_4 = (float *)((int)local_4 + 4);
          pfVar17[2] = (pfVar21[2] * fVar5 + pfVar44[2] * (float)(int)local_8) / fVar27;
          pfVar17[3] = ((float)iVar49 * pfVar21[3] + (float)((int)local_8 + -1) * pfVar44[3]) /
                       fVar27;
          pfVar44 = pfVar52;
          pfVar21 = pfVar18;
          pfVar17 = pfVar22;
          local_50 = (float)iVar39;
          local_8 = (float *)((int)local_8 + -4);
        } while (iVar39 < (int)local_54 + -3);
      }
      if ((int)local_50 < (int)local_54) {
        local_4 = (float *)((int)local_54 - (int)local_50);
        do {
          fVar5 = (float)(int)local_50;
          local_50 = (float)((int)local_50 + 1);
          fVar27 = *pfVar18;
          pfVar18 = pfVar18 + 1;
          *pfVar22 = ((float)(int)local_4 * *pfVar52 + fVar5 * fVar27) / (float)(int)local_54;
          pfVar52 = pfVar52 + 1;
          pfVar22 = pfVar22 + 1;
          local_4 = (float *)((int)local_4 + -1);
        } while ((int)local_50 < (int)local_54);
      }
      iVar49 = (int)local_54 + local_70;
      if ((iVar49 < iVar41) && (iVar39 = local_74 + (int)local_54 * 2, iVar39 < iVar4)) {
        iVar50 = ((int)local_54 << 0x12) / (iVar13 + -0x200) + 0x100;
        local_60 = (float)((int)(iVar50 + (iVar50 >> 0x1f & 0x1ffU)) >> 9);
        puVar23 = (undefined4 *)(iVar45 + iVar39 * 4);
        iVar50 = (int)local_60 - (int)local_54;
        puVar34 = (undefined4 *)(local_34 + iVar49 * 4);
        if (iVar4 < iVar39 + iVar50) {
          iVar50 = (iVar4 + (int)local_54 * -2) - local_74;
          local_60 = (float)((int)local_54 + iVar50);
        }
        if (iVar41 < iVar49 + iVar50) {
          iVar50 = (iVar41 - (int)local_54) - local_70;
          local_60 = (float)((int)local_54 + iVar50);
        }
        iVar49 = 0;
        if (3 < iVar50) {
          iVar39 = (iVar50 - 4U >> 2) + 1;
          iVar49 = iVar39 * 4;
          puVar35 = puVar23;
          puVar43 = puVar34;
          do {
            puVar23 = puVar35 + 4;
            *puVar43 = *puVar35;
            puVar34 = puVar43 + 4;
            iVar39 = iVar39 + -1;
            puVar43[1] = puVar35[1];
            puVar43[2] = puVar35[2];
            puVar43[3] = puVar35[3];
            puVar35 = puVar23;
            puVar43 = puVar34;
          } while (iVar39 != 0);
        }
        if (iVar49 < iVar50) {
          iVar50 = iVar50 - iVar49;
          do {
            uVar1 = *puVar23;
            puVar23 = puVar23 + 1;
            *puVar34 = uVar1;
            puVar34 = puVar34 + 1;
            iVar50 = iVar50 + -1;
          } while (iVar50 != 0);
        }
      }
      local_74 = local_74 + (int)local_60 + (int)local_54;
      iVar49 = local_74 + iVar16 * 2;
    }
    if (iVar41 <= local_70) {
      return 0;
    }
    while (local_74 < iVar4) {
      local_3c = (float *)0x0;
      local_54 = (float)iVar15;
      if (iVar15 <= iVar16) {
        pfVar52 = (float *)(iVar45 + local_74 * 4);
        local_10 = (float *)(iVar15 + local_74 + 3);
        local_c = (float *)(iVar45 + (iVar15 + local_74) * 4);
        local_64 = iVar15;
        do {
          local_5c = 0.0;
          iVar49 = 0;
          pfVar18 = pfVar52;
          pfVar22 = local_c;
          if (3 < iVar14) {
            iVar39 = local_74 + 1;
            iVar50 = (iVar14 - 4U >> 2) + 1;
            iVar49 = iVar50 * 4;
            pfVar44 = local_10;
            do {
              if (iVar39 + -1 < iVar4) {
                local_38 = (float *)*pfVar18;
              }
              else {
                local_38 = (float *)0x0;
              }
              if (iVar39 + -1 + local_64 < iVar4) {
                local_30 = (float *)*pfVar22;
              }
              else {
                local_30 = (float *)0x0;
              }
              fVar27 = (float)local_30 * (float)local_38;
              if (iVar39 < iVar4) {
                local_38 = (float *)pfVar18[1];
              }
              else {
                local_38 = (float *)0x0;
              }
              if (local_64 + iVar39 < iVar4) {
                local_30 = (float *)pfVar22[1];
              }
              else {
                local_30 = (float *)0x0;
              }
              fVar5 = (float)local_30 * (float)local_38;
              if (iVar39 + 1 < iVar4) {
                local_38 = (float *)pfVar18[2];
              }
              else {
                local_38 = (float *)0x0;
              }
              if ((int)pfVar44 + -1 < iVar4) {
                local_30 = (float *)pfVar22[2];
              }
              else {
                local_30 = (float *)0x0;
              }
              fVar6 = (float)local_30 * (float)local_38;
              if (iVar39 + 2 < iVar4) {
                local_38 = (float *)pfVar18[3];
              }
              else {
                local_38 = (float *)0x0;
              }
              if ((int)pfVar44 < iVar4) {
                local_30 = (float *)pfVar22[3];
              }
              else {
                local_30 = (float *)0x0;
              }
              pfVar18 = pfVar18 + 4;
              pfVar22 = pfVar22 + 4;
              iVar39 = iVar39 + 4;
              pfVar44 = (float *)((int)pfVar44 + 4);
              iVar50 = iVar50 + -1;
              local_5c = (float)local_30 * (float)local_38 + fVar6 + fVar5 + fVar27 + local_5c;
            } while (iVar50 != 0);
          }
          if (iVar49 < iVar14) {
            iVar39 = iVar49 + local_74;
            iVar50 = local_64 + iVar49 + local_74;
            iVar49 = iVar14 - iVar49;
            do {
              if (iVar39 < iVar4) {
                local_38 = (float *)*pfVar18;
              }
              else {
                local_38 = (float *)0x0;
              }
              if (iVar50 < iVar4) {
                local_30 = (float *)*pfVar22;
              }
              else {
                local_30 = (float *)0x0;
              }
              pfVar18 = pfVar18 + 1;
              pfVar22 = pfVar22 + 1;
              iVar39 = iVar39 + 1;
              iVar50 = iVar50 + 1;
              iVar49 = iVar49 + -1;
              local_5c = (float)local_30 * (float)local_38 + local_5c;
            } while (iVar49 != 0);
          }
          if ((float)local_3c < local_5c) {
            local_3c = (float *)local_5c;
            local_54 = (float)local_64;
          }
          local_c = local_c + 1;
          local_10 = (float *)((int)local_10 + 1);
          local_64 = local_64 + 1;
        } while (local_64 <= iVar16);
      }
      local_38 = (float *)(iVar45 + local_74 * 4);
      iVar49 = local_74 + (int)local_54;
      local_28 = (float *)(iVar45 + iVar49 * 4);
      pfVar52 = (float *)(local_34 + local_70 * 4);
      local_50 = 0.0;
      if (3 < (int)local_54) {
        local_4 = (float *)((int)local_54 + -2);
        local_2c = (float *)(local_74 + 2);
        iVar50 = local_70 + 1;
        iVar39 = iVar49 + 2;
        do {
          if ((-2 - (int)local_54) + iVar39 < iVar4) {
            local_30 = (float *)*local_38;
          }
          else {
            local_30 = (float *)0x0;
          }
          if (iVar39 + -2 < iVar4) {
            local_3c = (float *)*local_28;
          }
          else {
            local_3c = (float *)0x0;
          }
          if (iVar50 + -1 < iVar41) {
            *pfVar52 = ((float)(int)local_50 * (float)local_3c +
                       (float)((int)local_4 + 2) * (float)local_30) / (float)(int)local_54;
          }
          if ((-1 - (int)local_54) + iVar39 < iVar4) {
            local_30 = (float *)local_38[1];
          }
          else {
            local_30 = (float *)0x0;
          }
          if (iVar39 + -1 < iVar4) {
            local_3c = (float *)local_28[1];
          }
          else {
            local_3c = (float *)0x0;
          }
          if (iVar50 < iVar41) {
            pfVar52[1] = ((float)((int)local_4 + 1) * (float)local_30 +
                         (float)((-1 - local_74) + (int)local_2c) * (float)local_3c) /
                         (float)(int)local_54;
          }
          if ((int)local_2c < iVar4) {
            local_30 = (float *)local_38[2];
          }
          else {
            local_30 = (float *)0x0;
          }
          if (iVar39 < iVar4) {
            local_3c = (float *)local_28[2];
          }
          else {
            local_3c = (float *)0x0;
          }
          if (iVar50 + 1 < iVar41) {
            pfVar52[2] = ((float)(int)local_4 * (float)local_30 +
                         (float)((1 - local_70) + iVar50) * (float)local_3c) / (float)(int)local_54;
          }
          if ((1 - (int)local_54) + iVar39 < iVar4) {
            local_30 = (float *)local_38[3];
          }
          else {
            local_30 = (float *)0x0;
          }
          if (iVar39 + 1 < iVar4) {
            local_3c = (float *)local_28[3];
          }
          else {
            local_3c = (float *)0x0;
          }
          if (iVar50 + 2 < iVar41) {
            pfVar52[3] = ((float)((int)local_4 + -1) * (float)local_30 +
                         (float)((2 - local_70) + iVar50) * (float)local_3c) / (float)(int)local_54;
          }
          local_28 = local_28 + 4;
          local_2c = (float *)((int)local_2c + 4);
          local_50 = (float)((int)local_50 + 4);
          local_38 = local_38 + 4;
          local_4 = (float *)((int)local_4 + -4);
          pfVar52 = pfVar52 + 4;
          iVar50 = iVar50 + 4;
          iVar39 = iVar39 + 4;
        } while ((int)local_50 < (int)local_54 + -3);
      }
      if ((int)local_50 < (int)local_54) {
        local_4 = (float *)((int)local_54 - (int)local_50);
        iVar39 = local_74 + (int)local_50;
        do {
          if (iVar39 < iVar4) {
            local_30 = (float *)*local_38;
          }
          else {
            local_30 = (float *)0x0;
          }
          if ((int)local_54 + iVar39 < iVar4) {
            local_3c = (float *)*local_28;
          }
          else {
            local_3c = (float *)0x0;
          }
          if ((local_70 - local_74) + iVar39 < iVar41) {
            *pfVar52 = ((float)(int)local_50 * (float)local_3c +
                       (float)(int)local_4 * (float)local_30) / (float)(int)local_54;
          }
          local_28 = local_28 + 1;
          local_50 = (float)((int)local_50 + 1);
          local_4 = (float *)((int)local_4 + -1);
          local_38 = local_38 + 1;
          pfVar52 = pfVar52 + 1;
          iVar39 = iVar39 + 1;
        } while ((int)local_50 < (int)local_54);
      }
      iVar39 = (int)local_54 + local_70;
      if ((iVar39 < iVar41) && (iVar50 = local_74 + (int)local_54 * 2, iVar50 < iVar4)) {
        iVar53 = ((int)local_54 << 0x12) / (iVar13 + -0x200) + 0x100;
        local_60 = (float)((int)(iVar53 + (iVar53 >> 0x1f & 0x1ffU)) >> 9);
        puVar23 = (undefined4 *)(local_34 + iVar39 * 4);
        iVar53 = (int)local_60 - (int)local_54;
        local_38 = (float *)(iVar45 + iVar50 * 4);
        if (iVar4 < iVar50 + iVar53) {
          iVar53 = (iVar4 + (int)local_54 * -2) - local_74;
          local_60 = (float)((int)local_54 + iVar53);
        }
        if (iVar41 < iVar39 + iVar53) {
          iVar53 = (iVar41 - (int)local_54) - local_70;
          local_60 = (float)((int)local_54 + iVar53);
        }
        iVar39 = 0;
        if (3 < iVar53) {
          iVar49 = iVar49 + 2;
          iVar50 = (iVar53 - 4U >> 2) + 1;
          iVar39 = iVar50 * 4;
          do {
            if (iVar49 + -2 < iVar4) {
              local_30 = (float *)*local_38;
            }
            else {
              local_30 = (float *)0x0;
            }
            *puVar23 = local_30;
            if (iVar49 + -1 < iVar4) {
              local_30 = (float *)local_38[1];
            }
            else {
              local_30 = (float *)0x0;
            }
            puVar23[1] = local_30;
            if (iVar49 < iVar4) {
              local_30 = (float *)local_38[2];
            }
            else {
              local_30 = (float *)0x0;
            }
            puVar23[2] = local_30;
            if (iVar49 + 1 < iVar4) {
              local_30 = (float *)local_38[3];
            }
            else {
              local_30 = (float *)0x0;
            }
            local_38 = local_38 + 4;
            puVar23[3] = local_30;
            puVar23 = puVar23 + 4;
            iVar49 = iVar49 + 4;
            iVar50 = iVar50 + -1;
          } while (iVar50 != 0);
        }
        if (iVar39 < iVar53) {
          iVar49 = iVar39 + (int)local_54 + local_74;
          iVar53 = iVar53 - iVar39;
          do {
            if (iVar49 < iVar4) {
              local_30 = (float *)*local_38;
            }
            else {
              local_30 = (float *)0x0;
            }
            local_38 = local_38 + 1;
            *puVar23 = local_30;
            puVar23 = puVar23 + 1;
            iVar49 = iVar49 + 1;
            iVar53 = iVar53 + -1;
          } while (iVar53 != 0);
        }
      }
      local_74 = local_74 + (int)local_60 + (int)local_54;
      local_70 = local_70 + (int)local_60;
      if (iVar41 <= local_70) {
        return 0;
      }
    }
    local_74 = local_70;
  }
  if (local_74 < iVar41) {
    iVar41 = iVar41 - local_74;
    if (0 < iVar41) {
      puVar23 = (undefined4 *)(local_34 + local_74 * 4);
      for (; iVar41 != 0; iVar41 = iVar41 + -1) {
        *puVar23 = 0;
        puVar23 = puVar23 + 1;
      }
      return 0;
    }
  }
  return 0;
LAB_005534eb:
  local_70 = 0;
  local_74 = 0;
  if (iVar16 * 2 < iVar4) {
    do {
      if (iVar41 <= iVar16 * 2 + local_74) break;
      local_44 = 0.0;
      local_50 = (float)iVar15;
      if (iVar15 <= iVar16) {
        local_8 = (float *)(iVar45 + 4 + (iVar15 + local_70) * 8);
        local_60 = (float)iVar15;
        do {
          local_5c = 0.0;
          iVar49 = 0;
          pfVar52 = (float *)(iVar45 + 4 + local_70 * 8);
          pfVar18 = local_8;
          if (3 < iVar14) {
            iVar39 = (iVar14 - 4U >> 2) + 1;
            iVar49 = iVar39 * 4;
            pfVar22 = pfVar52;
            pfVar44 = local_8;
            do {
              pfVar52 = pfVar22 + 8;
              pfVar18 = pfVar44 + 8;
              iVar39 = iVar39 + -1;
              local_5c = pfVar44[6] * pfVar22[6] +
                         pfVar44[4] * pfVar22[4] +
                         pfVar44[2] * pfVar22[2] + *pfVar44 * *pfVar22 + local_5c;
              pfVar22 = pfVar52;
              pfVar44 = pfVar18;
            } while (iVar39 != 0);
          }
          if (iVar49 < iVar14) {
            iVar49 = iVar14 - iVar49;
            do {
              fVar27 = *pfVar18;
              pfVar18 = pfVar18 + 2;
              iVar49 = iVar49 + -1;
              local_5c = fVar27 * *pfVar52 + local_5c;
              pfVar52 = pfVar52 + 2;
            } while (iVar49 != 0);
          }
          if (local_44 < local_5c) {
            local_44 = local_5c;
            local_50 = local_60;
          }
          local_8 = local_8 + 2;
          local_60 = (float)((int)local_60 + 1);
        } while ((int)local_60 <= iVar16);
      }
      pfVar52 = (float *)(iVar45 + 4 + ((int)local_50 + local_70) * 8);
      pfVar18 = (float *)(iVar45 + 4 + local_70 * 8);
      pfVar22 = (float *)(local_34 + 4 + local_74 * 8);
      pfVar44 = (float *)(local_34 + 4 + (local_74 + (int)local_50) * 8);
      local_54 = 0.0;
      pfVar21 = pfVar52;
      if (3 < (int)local_50) {
        fVar27 = (float)(int)local_50;
        local_20 = 2;
        pfVar17 = pfVar18;
        pfVar26 = pfVar52;
        pfVar40 = pfVar22;
        pfVar51 = pfVar44;
        local_4 = (float *)((int)local_50 + -2);
        do {
          *pfVar40 = *pfVar17;
          fVar5 = (float)(int)local_54;
          local_54 = (float)((int)local_54 + 4);
          pfVar18 = pfVar17 + 8;
          pfVar21 = pfVar26 + 8;
          pfVar22 = pfVar40 + 8;
          pfVar44 = pfVar51 + 8;
          *pfVar51 = (fVar5 * *pfVar17 + (float)((int)local_4 + 2) * *pfVar26) / fVar27;
          pfVar40[2] = pfVar17[2];
          pfVar51[2] = ((float)(local_20 + -1) * pfVar17[2] + (float)((int)local_4 + 1) * pfVar26[2]
                       ) / fVar27;
          pfVar40[4] = pfVar17[4];
          fVar5 = (float)local_20;
          iVar49 = local_20 + 1;
          local_20 = local_20 + 4;
          pfVar51[4] = (fVar5 * pfVar17[4] + pfVar26[4] * (float)(int)local_4) / fVar27;
          pfVar40[6] = pfVar17[6];
          pfVar51[6] = ((float)iVar49 * pfVar17[6] + (float)((int)local_4 + -1) * pfVar26[6]) /
                       fVar27;
          pfVar17 = pfVar18;
          pfVar26 = pfVar21;
          pfVar40 = pfVar22;
          pfVar51 = pfVar44;
          local_4 = (float *)((int)local_4 + -4);
        } while ((int)local_54 < (int)local_50 + -3);
      }
      if ((int)local_54 < (int)local_50) {
        local_4 = (float *)((int)local_50 - (int)local_54);
        do {
          iVar49 = (int)local_54 + 1;
          *pfVar22 = *pfVar18;
          pfVar22 = pfVar22 + 2;
          *pfVar44 = ((float)(int)local_4 * *pfVar21 + (float)(int)local_54 * *pfVar18) /
                     (float)(int)local_50;
          pfVar18 = pfVar18 + 2;
          pfVar21 = pfVar21 + 2;
          pfVar44 = pfVar44 + 2;
          local_54 = (float)iVar49;
          local_4 = (float *)((int)local_4 + -1);
        } while (iVar49 < (int)local_50);
      }
      iVar49 = (int)local_50 * 2 + local_74;
      if ((iVar49 < iVar41) && ((int)local_50 + local_70 < iVar4)) {
        iVar39 = ((int)local_50 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
        local_64 = (int)(iVar39 + (iVar39 >> 0x1f & 0x1ffU)) >> 9;
        pfVar18 = (float *)(local_34 + 4 + iVar49 * 8);
        iVar49 = local_64 - (int)local_50;
        if (iVar4 < iVar49 + (int)local_50 + local_70) {
          iVar49 = (iVar4 - (int)local_50) - local_70;
          local_64 = iVar49 + (int)local_50;
        }
        if (iVar41 < iVar49 + (int)local_50 * 2 + local_74) {
          iVar49 = (iVar41 + (int)local_50 * -2) - local_74;
          local_64 = iVar49 + (int)local_50;
        }
        iVar39 = 0;
        if (3 < iVar49) {
          iVar50 = (iVar49 - 4U >> 2) + 1;
          iVar39 = iVar50 * 4;
          pfVar22 = pfVar52;
          pfVar44 = pfVar18;
          do {
            pfVar52 = pfVar22 + 8;
            *pfVar44 = *pfVar22;
            pfVar18 = pfVar44 + 8;
            iVar50 = iVar50 + -1;
            pfVar44[2] = pfVar22[2];
            pfVar44[4] = pfVar22[4];
            pfVar44[6] = pfVar22[6];
            pfVar22 = pfVar52;
            pfVar44 = pfVar18;
          } while (iVar50 != 0);
        }
        if (iVar39 < iVar49) {
          iVar49 = iVar49 - iVar39;
          do {
            fVar27 = *pfVar52;
            pfVar52 = pfVar52 + 2;
            *pfVar18 = fVar27;
            pfVar18 = pfVar18 + 2;
            iVar49 = iVar49 + -1;
          } while (iVar49 != 0);
        }
      }
      local_70 = local_70 + local_64;
      local_74 = local_74 + local_64 + (int)local_50;
    } while (iVar16 * 2 + local_70 < iVar4);
  }
  if (iVar41 <= local_74) {
    return 0;
  }
  while (local_70 < iVar4) {
    local_44 = 0.0;
    local_50 = (float)iVar15;
    if (iVar15 <= iVar16) {
      pfVar52 = (float *)(iVar45 + 4 + local_70 * 8);
      local_c = (float *)(local_70 + iVar15 + 3);
      local_8 = (float *)(iVar45 + 4 + (local_70 + iVar15) * 8);
      fVar27 = (float)iVar15;
      local_60 = (float)iVar15;
      do {
        local_5c = 0.0;
        iVar49 = 0;
        pfVar18 = local_8;
        pfVar22 = pfVar52;
        if (3 < iVar14) {
          local_10 = local_c;
          iVar39 = local_70 + 1;
          iVar50 = (iVar14 - 4U >> 2) + 1;
          iVar49 = iVar50 * 4;
          do {
            if (iVar39 + -1 < iVar4) {
              local_50 = *pfVar22;
            }
            else {
              local_50 = 0.0;
            }
            if (iVar39 + -1 + (int)local_60 < iVar4) {
              local_3c = (float *)*pfVar18;
            }
            else {
              local_3c = (float *)0x0;
            }
            fVar5 = (float)local_3c * local_50;
            if (iVar39 < iVar4) {
              local_50 = pfVar22[2];
            }
            else {
              local_50 = 0.0;
            }
            if ((int)local_60 + iVar39 < iVar4) {
              local_3c = (float *)pfVar18[2];
            }
            else {
              local_3c = (float *)0x0;
            }
            fVar6 = (float)local_3c * local_50;
            if (iVar39 + 1 < iVar4) {
              local_50 = pfVar22[4];
            }
            else {
              local_50 = 0.0;
            }
            if ((int)local_10 + -1 < iVar4) {
              local_3c = (float *)pfVar18[4];
            }
            else {
              local_3c = (float *)0x0;
            }
            fVar7 = (float)local_3c * local_50;
            if (iVar39 + 2 < iVar4) {
              local_50 = pfVar22[6];
            }
            else {
              local_50 = 0.0;
            }
            if ((int)local_10 < iVar4) {
              local_3c = (float *)pfVar18[6];
            }
            else {
              local_3c = (float *)0x0;
            }
            local_10 = (float *)((int)local_10 + 4);
            pfVar22 = pfVar22 + 8;
            pfVar18 = pfVar18 + 8;
            iVar39 = iVar39 + 4;
            iVar50 = iVar50 + -1;
            local_5c = (float)local_3c * local_50 + fVar7 + fVar6 + fVar5 + local_5c;
          } while (iVar50 != 0);
        }
        if (iVar49 < iVar14) {
          iVar39 = local_70 + iVar49;
          iVar50 = (int)local_60 + iVar49 + local_70;
          iVar49 = iVar14 - iVar49;
          do {
            if (iVar39 < iVar4) {
              local_50 = *pfVar22;
            }
            else {
              local_50 = 0.0;
            }
            if (iVar50 < iVar4) {
              local_3c = (float *)*pfVar18;
            }
            else {
              local_3c = (float *)0x0;
            }
            pfVar22 = pfVar22 + 2;
            pfVar18 = pfVar18 + 2;
            iVar39 = iVar39 + 1;
            iVar50 = iVar50 + 1;
            iVar49 = iVar49 + -1;
            local_5c = (float)local_3c * local_50 + local_5c;
          } while (iVar49 != 0);
        }
        if (local_44 < local_5c) {
          local_44 = local_5c;
          fVar27 = local_60;
        }
        local_8 = local_8 + 2;
        local_c = (float *)((int)local_c + 1);
        local_60 = (float)((int)local_60 + 1);
      } while ((int)local_60 <= iVar16);
      local_50 = fVar27;
    }
    local_3c = (float *)(iVar45 + 4 + local_70 * 8);
    pfVar52 = (float *)(iVar45 + 4 + ((int)local_50 + local_70) * 8);
    local_2c = (float *)(local_34 + 4 + local_74 * 8);
    local_30 = (float *)(local_34 + 4 + (local_74 + (int)local_50) * 8);
    local_54 = 0.0;
    local_28 = pfVar52;
    if (3 < (int)local_50) {
      local_8 = (float *)(local_70 + 3);
      local_20 = (int)local_50 + -2;
      iVar39 = (int)local_50 + local_70 + 3;
      iVar49 = local_74 + (int)local_50 + 1;
      local_4 = (float *)0x1;
      do {
        if (iVar39 + (-3 - (int)local_50) < iVar4) {
          local_44 = *local_3c;
        }
        else {
          local_44 = 0.0;
        }
        if (iVar39 + -3 < iVar4) {
          local_60 = *local_28;
        }
        else {
          local_60 = 0.0;
        }
        if (iVar49 + (-1 - (int)local_50) < iVar41) {
          *local_2c = local_44;
        }
        if (iVar49 + -1 < iVar41) {
          *local_30 = ((float)(local_20 + 2) * local_60 + (float)(int)local_54 * local_44) /
                      (float)(int)local_50;
        }
        if (iVar39 + (-2 - (int)local_50) < iVar4) {
          local_44 = local_3c[2];
        }
        else {
          local_44 = 0.0;
        }
        if ((local_70 - local_74) + iVar49 < iVar4) {
          local_60 = local_28[2];
        }
        else {
          local_60 = 0.0;
        }
        if ((int)local_4 + local_74 < iVar41) {
          local_2c[2] = local_44;
        }
        if (iVar49 < iVar41) {
          local_30[2] = ((float)(local_20 + 1) * local_60 + (float)(int)local_4 * local_44) /
                        (float)(int)local_50;
        }
        if (iVar39 + (-1 - (int)local_50) < iVar4) {
          local_44 = local_3c[4];
        }
        else {
          local_44 = 0.0;
        }
        if (iVar39 + -1 < iVar4) {
          local_60 = local_28[4];
        }
        else {
          local_60 = 0.0;
        }
        if (iVar49 + (1 - (int)local_50) < iVar41) {
          local_2c[4] = local_44;
        }
        if (iVar49 + 1 < iVar41) {
          local_30[4] = ((float)local_20 * local_60 + local_44 * (float)((int)local_4 + 1)) /
                        (float)(int)local_50;
        }
        if ((int)local_8 < iVar4) {
          local_44 = local_3c[6];
        }
        else {
          local_44 = 0.0;
        }
        if (iVar39 < iVar4) {
          local_60 = local_28[6];
        }
        else {
          local_60 = 0.0;
        }
        if (iVar49 + (2 - (int)local_50) < iVar41) {
          local_2c[6] = local_44;
        }
        if (iVar49 + 2 < iVar41) {
          local_30[6] = ((float)(local_20 + -1) * local_60 + (float)((int)local_4 + 2) * local_44) /
                        (float)(int)local_50;
        }
        local_3c = local_3c + 8;
        local_28 = local_28 + 8;
        local_2c = local_2c + 8;
        local_30 = local_30 + 8;
        local_8 = (float *)((int)local_8 + 4);
        local_20 = local_20 + -4;
        local_54 = (float)((int)local_54 + 4);
        local_4 = (float *)((int)local_4 + 4);
        iVar39 = iVar39 + 4;
        iVar49 = iVar49 + 4;
      } while ((int)local_54 < (int)local_50 + -3);
    }
    if ((int)local_54 < (int)local_50) {
      local_4 = (float *)((int)local_50 - (int)local_54);
      iVar39 = (int)local_54 + (int)local_50 + local_74;
      iVar49 = (int)local_54 + local_74;
      do {
        if ((local_70 - local_74) + iVar49 < iVar4) {
          local_44 = *local_3c;
        }
        else {
          local_44 = 0.0;
        }
        if ((local_70 - local_74) + iVar39 < iVar4) {
          local_60 = *local_28;
        }
        else {
          local_60 = 0.0;
        }
        if (iVar49 < iVar41) {
          *local_2c = local_44;
        }
        if (iVar39 < iVar41) {
          *local_30 = ((float)(int)local_4 * local_60 + (float)(int)local_54 * local_44) /
                      (float)(int)local_50;
        }
        local_3c = local_3c + 2;
        local_28 = local_28 + 2;
        local_2c = local_2c + 2;
        local_30 = local_30 + 2;
        local_54 = (float)((int)local_54 + 1);
        local_4 = (float *)((int)local_4 + -1);
        iVar49 = iVar49 + 1;
        iVar39 = iVar39 + 1;
      } while ((int)local_54 < (int)local_50);
    }
    iVar49 = local_74 + (int)local_50 * 2;
    if ((iVar49 < iVar41) && ((int)local_50 + local_70 < iVar4)) {
      iVar39 = ((int)local_50 * iVar13 * 0x200) / (0x200 - iVar13) + 0x100;
      local_64 = (int)(iVar39 + (iVar39 >> 0x1f & 0x1ffU)) >> 9;
      iVar39 = local_64 - (int)local_50;
      pfVar18 = (float *)(local_34 + 4 + iVar49 * 8);
      if (iVar4 < iVar39 + (int)local_50 + local_70) {
        iVar39 = (iVar4 - (int)local_50) - local_70;
        local_64 = iVar39 + (int)local_50;
      }
      if (iVar41 < iVar39 + (int)local_50 * 2 + local_74) {
        iVar39 = (iVar41 + (int)local_50 * -2) - local_74;
        local_64 = iVar39 + (int)local_50;
      }
      local_54 = 0.0;
      if (3 < iVar39) {
        iVar49 = (int)local_50 + local_70 + 2;
        iVar50 = (iVar39 - 4U >> 2) + 1;
        local_54 = (float)(iVar50 * 4);
        local_3c = pfVar52;
        do {
          if (iVar49 + -2 < iVar4) {
            local_44 = *local_3c;
          }
          else {
            local_44 = 0.0;
          }
          *pfVar18 = local_44;
          if (iVar49 + -1 < iVar4) {
            local_44 = local_3c[2];
          }
          else {
            local_44 = 0.0;
          }
          pfVar18[2] = local_44;
          if (iVar49 < iVar4) {
            local_44 = local_3c[4];
          }
          else {
            local_44 = 0.0;
          }
          pfVar18[4] = local_44;
          if (iVar49 + 1 < iVar4) {
            local_44 = local_3c[6];
          }
          else {
            local_44 = 0.0;
          }
          pfVar52 = local_3c + 8;
          pfVar18[6] = local_44;
          pfVar18 = pfVar18 + 8;
          iVar49 = iVar49 + 4;
          iVar50 = iVar50 + -1;
          local_3c = pfVar52;
        } while (iVar50 != 0);
      }
      if ((int)local_54 < iVar39) {
        iVar49 = (int)local_54 + (int)local_50 + local_70;
        iVar39 = iVar39 - (int)local_54;
        do {
          if (iVar49 < iVar4) {
            local_44 = *pfVar52;
          }
          else {
            local_44 = 0.0;
          }
          pfVar52 = pfVar52 + 2;
          *pfVar18 = local_44;
          pfVar18 = pfVar18 + 2;
          iVar49 = iVar49 + 1;
          iVar39 = iVar39 + -1;
        } while (iVar39 != 0);
      }
    }
    local_70 = local_70 + local_64;
    local_74 = local_74 + local_64 + (int)local_50;
    if (iVar41 <= local_74) {
      return 0;
    }
  }
  if (iVar41 <= local_74) {
    return 0;
  }
  iVar41 = iVar41 - local_74;
  puVar23 = (undefined4 *)(local_34 + 4 + local_74 * 8);
  if (iVar41 < 1) {
    return 0;
  }
  do {
    *puVar23 = 0;
    puVar23 = puVar23 + 2;
    iVar41 = iVar41 + -1;
  } while (iVar41 != 0);
  return 0;
}

