
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005ed960(uint param_1)

{
  float fVar1;
  undefined4 *puVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int *piVar15;
  int *piVar16;
  int *local_74;
  int local_70;
  int *local_6c;
  int local_68;
  char *local_64;
  undefined4 *local_5c;
  int local_58;
  float *local_54;
  int *local_50;
  int local_4c;
  int local_48;
  int local_44;
  uint local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_00dccde0 == '\0') {
    return 0xffffffff;
  }
  if (((((DAT_00cc6e00 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc6e28)) ||
      ((DAT_00cc6e30 <= (int)(param_1 & 0xffff) ||
       (local_38 = *(int **)(DAT_00cc6e04 + (param_1 & 0xffff) * 4), local_38 == (int *)0x0)))) ||
     ((*local_38 * 0x10000 != (param_1 & 0x3ff0000) || (local_38[4] != 0)))) {
    return 0xffffffff;
  }
  local_30 = local_38[0x10];
  if ((char)local_38[0x67] == '\0') {
    return 0;
  }
  local_34 = (int *)local_38[0x6c];
  *(undefined1 *)(local_38 + 0x67) = 0;
  piVar15 = *(int **)(local_30 + 0xb0);
  local_68 = 0;
  if (0 < *(int *)(local_30 + 0xac)) {
    do {
      if ((*(char *)((int)piVar15 + 0x4a) != '\0') && (*(char *)(*local_34 + 0x210) != '\0')) {
        iVar12 = *piVar15;
        piVar11 = (int *)piVar15[0x17];
        local_70 = 0;
        if (0 < piVar15[0x15]) {
          puVar10 = (undefined4 *)local_34[0x2a] + 3;
          puVar6 = (undefined4 *)local_34[0x2a];
          do {
            puVar2 = (undefined4 *)(*(int *)(iVar12 + 0x1a4) * *piVar11 + *(int *)(iVar12 + 0x1a8));
            *puVar6 = *puVar2;
            puVar6[1] = puVar2[1];
            puVar6[2] = puVar2[2];
            puVar2 = (undefined4 *)(*(int *)(iVar12 + 0x1b0) + piVar11[1] * 0x24);
            *puVar10 = *puVar2;
            puVar10[1] = puVar2[1];
            puVar10[2] = puVar2[2];
            piVar11 = (int *)((int)piVar11 + piVar15[0x16]);
            local_70 = local_70 + 1;
            puVar10 = puVar10 + 6;
            puVar6 = puVar6 + 6;
          } while (local_70 < piVar15[0x15]);
        }
      }
      local_68 = local_68 + 1;
      local_34 = local_34 + 0x2e;
      piVar15 = piVar15 + 0x1f;
    } while (local_68 < *(int *)(local_30 + 0xac));
  }
  local_34 = (int *)local_38[0x7f];
  local_68 = 0;
  if (0 < *(int *)(local_30 + 0x7c)) {
    local_74 = (int *)(*(int *)(local_30 + 0x80) + 0x1b8);
    local_64 = (char *)(local_38[0x5f] + 0x210);
    do {
      if ((*local_74 != 0) && (*local_64 != '\0')) {
        *local_64 = '\0';
        if (*(char *)((int)local_38 + 0x19d) == '\0') {
          local_70 = 0;
          if (0 < *local_74) {
            local_54 = (float *)(*(int *)(local_64 + -4) + 8);
            do {
              fVar1 = local_54[-1];
              local_50 = (int *)*local_54;
              if (0 < local_38[0x7d]) {
                iVar12 = local_38[0x7d];
                pfVar3 = (float *)((int)local_34 + 4);
                pcVar7 = (char *)(local_38[0x7e] + 1);
                do {
                  if ((*(char *)(pfVar3 + -1) != '\0') && (*pcVar7 == '\0')) {
                    local_50 = (int *)(*(float *)(*(int *)((int)pfVar3[1] + 0x74) + local_70 * 4) *
                                       *pfVar3 + (float)local_50);
                  }
                  pfVar3 = pfVar3 + 3;
                  pcVar7 = pcVar7 + 0x14;
                  iVar12 = iVar12 + -1;
                } while (iVar12 != 0);
              }
              if ((float)_DAT_007d5348 <= (float)local_50) {
                piVar15 = *(int **)((int)fVar1 + 0x10);
                iVar12 = 0;
                if (0 < *(int *)((int)fVar1 + 0xc)) {
                  do {
                    uVar13 = 0;
                    if (piVar15[1] != 0) {
                      iVar14 = *(int *)(((*piVar15 - *(int *)(local_30 + 0xb0)) / 0x7c) * 0xb8 +
                                        local_38[0x6c] + 0xa8);
                      piVar11 = (int *)piVar15[2];
                      do {
                        pfVar3 = (float *)(iVar14 + *piVar11 * 0x18);
                        uVar13 = uVar13 + 1;
                        *pfVar3 = (float)piVar11[1] * (float)local_50 + *pfVar3;
                        pfVar3[1] = (float)piVar11[2] * (float)local_50 + pfVar3[1];
                        pfVar3[2] = (float)piVar11[3] * (float)local_50 + pfVar3[2];
                        pfVar3[3] = (float)piVar11[4] * (float)local_50 + pfVar3[3];
                        pfVar3[4] = (float)piVar11[5] * (float)local_50 + pfVar3[4];
                        pfVar3[5] = (float)piVar11[6] * (float)local_50 + pfVar3[5];
                        piVar11 = piVar11 + 7;
                      } while (uVar13 < (uint)piVar15[1]);
                    }
                    iVar12 = iVar12 + 1;
                    piVar15 = piVar15 + 4;
                  } while (iVar12 < *(int *)((int)fVar1 + 0xc));
                }
              }
              local_54 = local_54 + 3;
              local_70 = local_70 + 1;
            } while (local_70 < *local_74);
          }
        }
        local_6c = (int *)local_74[-0x11];
        local_1c = 0;
        if (0 < local_74[-0x12]) {
          local_3c = (int *)(*(int *)(local_64 + -8) + 0xac);
          do {
            if (*(char *)((int)local_6c + 0x4a) != '\0') {
              local_44 = *(int *)(*local_6c + 0x1b0);
              iVar12 = local_6c[0x13];
              local_48 = local_6c[0x17];
              local_4c = local_6c[0x16];
              local_40 = (uint)(*(int *)(local_6c[1] + 0x168) != 0);
              iVar14 = local_3c[-1];
              local_20 = 0;
              if (0 < local_6c[0x10]) {
                local_50 = (int *)(*local_3c + 0xc);
                local_54 = (float *)(local_6c[0x11] + 4);
                local_58 = iVar14;
                do {
                  piVar16 = local_50;
                  pfVar3 = local_54;
                  local_70 = *(int *)((int)local_54 + 8);
                  piVar15 = *(int **)((int)local_54 + 0xec);
                  piVar11 = (int *)*local_50;
                  if (*(short *)local_54 == 3) {
                    if (*piVar11 != 0) {
                      local_5c = (undefined4 *)*piVar11;
LAB_005eddc5:
                      switch(*(short *)pfVar3) {
                      case 0:
                        if (0 < local_70) {
                          local_28 = local_70;
                          do {
                            iVar5 = *piVar15 * local_4c + local_48;
                            iVar4 = local_44 + *(int *)(iVar5 + 4) * 0x24;
                            if (local_40 == 0) {
                              iVar9 = 0;
                              local_70 = 0;
                            }
                            else {
                              local_70 = iVar4 + 0xc;
                              iVar9 = iVar4 + 0x18;
                            }
                            if (iVar12 < 2) {
                              local_2c = 0;
                            }
                            else {
                              local_2c = iVar5 + 0x1c;
                            }
                            if (iVar12 < 1) {
                              iVar8 = 0;
                            }
                            else {
                              iVar8 = iVar5 + 0x14;
                            }
                            FUN_005e86d0(&local_5c,iVar14 + *piVar15 * 0x18,iVar4,iVar5 + 8,
                                         iVar5 + 0xc,iVar8,local_2c,local_70,iVar9,0,0,0,0);
                            piVar15 = piVar15 + 1;
                            local_28 = local_28 + -1;
                          } while (local_28 != 0);
                          local_28 = 0;
                          pfVar3 = local_54;
                        }
                        break;
                      case 1:
                        uVar13 = *(int *)((int)pfVar3 + 0x104) + 0xfU & 0xfffffff0;
                        if (0 < local_70) {
                          local_24 = local_70;
                          do {
                            iVar5 = *piVar15 * local_4c + local_48;
                            iVar4 = local_44 + *(int *)(iVar5 + 4) * 0x24;
                            if (local_40 == 0) {
                              local_28 = 0;
                              local_2c = 0;
                            }
                            else {
                              local_28 = iVar4 + 0x18;
                              local_2c = iVar4 + 0xc;
                            }
                            if (iVar12 < 2) {
                              local_70 = 0;
                            }
                            else {
                              local_70 = iVar5 + 0x1c;
                            }
                            if (iVar12 < 1) {
                              iVar9 = 0;
                            }
                            else {
                              iVar9 = iVar5 + 0x14;
                            }
                            FUN_005e86d0(&local_5c,iVar14 + *piVar15 * 0x18,iVar4,iVar5 + 8,
                                         iVar5 + 0xc,iVar9,local_70,local_2c,local_28,uVar13 + 0x2c,
                                         uVar13,0,0);
                            uVar13 = uVar13 + 0x30;
                            piVar15 = piVar15 + 1;
                            local_24 = local_24 + -1;
                            iVar14 = local_58;
                          } while (local_24 != 0);
                          local_24 = 0;
                          pfVar3 = local_54;
                        }
                        break;
                      case 2:
                        uVar13 = *(int *)((int)pfVar3 + 0x104) + 0xfU & 0xfffffff0;
                        if (0 < local_70) {
                          do {
                            iVar5 = *piVar15 * local_4c + local_48;
                            iVar4 = local_44 + *(int *)(iVar5 + 4) * 0x24;
                            if (local_40 == 0) {
                              local_24 = 0;
                              local_28 = 0;
                            }
                            else {
                              local_24 = iVar4 + 0x18;
                              local_28 = iVar4 + 0xc;
                            }
                            if (iVar12 < 2) {
                              local_2c = 0;
                            }
                            else {
                              local_2c = iVar5 + 0x1c;
                            }
                            iVar9 = 0;
                            if (0 < iVar12) {
                              iVar9 = iVar5 + 0x14;
                            }
                            FUN_005e86d0(&local_5c,iVar14 + *piVar15 * 0x18,iVar4,iVar5 + 8,
                                         iVar5 + 0xc,iVar9,local_2c,local_28,local_24,uVar13 + 0x2c,
                                         uVar13,uVar13 + 0x3c,uVar13 + 0x10);
                            uVar13 = uVar13 + 0x40;
                            piVar15 = piVar15 + 1;
                            local_70 = local_70 + -1;
                            iVar14 = local_58;
                          } while (local_70 != 0);
                          pfVar3 = local_54;
                        }
                        break;
                      case 3:
                        puVar10 = local_5c;
                        if (0 < local_70) {
                          do {
                            iVar4 = iVar14 + *piVar15 * 0x18;
                            *puVar10 = *(undefined4 *)(iVar14 + *piVar15 * 0x18);
                            puVar10[1] = *(undefined4 *)(iVar4 + 4);
                            puVar10[2] = *(undefined4 *)(iVar4 + 8);
                            puVar10 = puVar10 + 3;
                            piVar15 = piVar15 + 1;
                            local_70 = local_70 + -1;
                          } while (local_70 != 0);
                        }
                      }
                      piVar16 = local_50;
                      if (*(short *)pfVar3 != 3) {
                        local_18 = 0;
                        local_14 = 0;
                        local_10 = 0;
                        local_c = *(int *)(*(int *)((int)pfVar3 + 0x120) + 0x10) *
                                  *(int *)((int)pfVar3 + 8);
                        local_8 = 1;
                        local_4 = 1;
                        FUN_005d52f0(*(undefined4 *)(*local_50 + 4),0,&local_18,DAT_00f3a1c0,0,0,0);
                      }
                    }
                  }
                  else if ((piVar11[1] != 0) &&
                          (iVar4 = FUN_005ed8e0(*(int *)(*(int *)((int)local_54 + 0x120) + 0x10) *
                                                local_70), -1 < iVar4)) {
                    local_5c = DAT_00f3a1c0;
                    goto LAB_005eddc5;
                  }
                  local_20 = local_20 + 1;
                  local_54 = (float *)((int)pfVar3 + 0x138);
                  local_50 = piVar16 + 6;
                } while (local_20 < local_6c[0x10]);
              }
            }
            local_6c = local_6c + 0x1f;
            local_3c = local_3c + 0x2e;
            local_1c = local_1c + 1;
          } while (local_1c < local_74[-0x12]);
        }
      }
      local_64 = local_64 + 0x2b8;
      local_74 = local_74 + 0x75;
      local_34 = (int *)((int)local_34 + local_38[0x7d] * 0xc);
      local_68 = local_68 + 1;
    } while (local_68 < *(int *)(local_30 + 0x7c));
  }
  return 0;
}

