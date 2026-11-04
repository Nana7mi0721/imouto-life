
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004bd8e0(int *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  int local_128;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  uint local_b8;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_84;
  int local_80;
  int local_24;
  int local_20;
  int local_1c;
  int local_14;
  int local_c;
  
  if ((param_1[4] != 0) && (*(char *)((int)param_1 + 0x5d) == '\0')) {
    FUN_004bfab0();
    *(char *)(param_1 + 0x17) = '\x01' - (*(char *)(param_1[4] + 0x56) != '\0');
    if ((param_1[0xb] == -1) && (-1 < param_1[0x1a])) {
      if (*(char *)(param_1[4] + 0x55) == '\0') {
        param_1[2] = ((*(short *)(param_1[4] + 0x48) + -2) / 2) * param_1[0x1c] + 1 +
                     (int)*(short *)(param_1[4] + 0x4a);
        if (param_1[0x1a] == 0) {
          param_1[1] = ((*(short *)(param_1[4] + 0x48) + -2) / 2) * param_1[0x1b] + 1 +
                       (int)*(short *)(param_1[4] + 0x4a);
        }
        if (param_1[0x1a] == 1) {
          cVar4 = FUN_0049ba00();
          if (cVar4 == '\0') {
            local_94 = 0;
          }
          else {
            local_94 = *(short *)(param_1[4] + 0x4a) + 1;
          }
          param_1[1] = ((*(short *)(param_1[4] + 0x48) + -2) / 2) * param_1[0x1b] + 1 + local_94;
        }
        if (param_1[0x1a] == 2) {
          cVar4 = FUN_0049ba00();
          if (cVar4 == '\0') {
            local_98 = 0;
          }
          else {
            local_98 = param_1[0x1b] / 2;
          }
          param_1[1] = *(short *)(param_1[4] + 0x4a) + 1 +
                       ((*(short *)(param_1[4] + 0x48) + -2) / 2) * param_1[0x1b] + local_98;
        }
      }
      else {
        uVar16 = (int)*(short *)(param_1[4] + 0x48) & 0x80000001;
        if ((int)uVar16 < 0) {
          uVar16 = (uVar16 - 1 | 0xfffffffe) + 1;
        }
        if (uVar16 == 0) {
          param_1[2] = ((*(short *)(param_1[4] + 0x48) + -2) / 2) * param_1[0x1c] + 1 +
                       (int)*(short *)(param_1[4] + 0x4a);
          if (param_1[0x1a] == 0) {
            param_1[1] = ((*(short *)(param_1[4] + 0x48) + -2) / 2) * param_1[0x1b] + 1 +
                         (int)*(short *)(param_1[4] + 0x4a);
          }
          if (param_1[0x1a] == 1) {
            cVar4 = FUN_0049ba00();
            if (cVar4 == '\0') {
              local_80 = 0;
            }
            else {
              local_80 = *(short *)(param_1[4] + 0x4a) + 1;
            }
            param_1[1] = ((*(short *)(param_1[4] + 0x48) + -2) / 2) * param_1[0x1b] + 1 + local_80;
          }
          if (param_1[0x1a] == 2) {
            cVar4 = FUN_0049ba00();
            if (cVar4 == '\0') {
              local_84 = 0;
            }
            else {
              local_84 = (int)*DAT_00a16690;
            }
            param_1[1] = *(short *)(param_1[4] + 0x4a) + 1 +
                         ((*(short *)(param_1[4] + 0x48) + -2) / 2) * param_1[0x1b] + local_84;
          }
        }
        else {
          if (*(short *)(param_1[4] + 0x48) < 5) {
            local_14 = -1;
          }
          else {
            local_14 = -3;
          }
          param_1[2] = ((*(short *)(param_1[4] + 0x48) + local_14) / 2) * param_1[0x1c] + 1 +
                       (int)*(short *)(param_1[4] + 0x4a) + param_1[0x1c] / 2;
          if (param_1[0x1a] == 0) {
            param_1[1] = ((*(short *)(param_1[4] + 0x48) + local_14) / 2) * param_1[0x1b] + 1 +
                         (int)*(short *)(param_1[4] + 0x4a) + param_1[0x1b] / 2;
          }
          if (param_1[0x1a] == 1) {
            cVar4 = FUN_0049ba00();
            if (cVar4 == '\0') {
              local_8c = 0;
            }
            else {
              local_8c = *(short *)(param_1[4] + 0x4a) + 1;
            }
            param_1[1] = ((*(short *)(param_1[4] + 0x48) + local_14) / 2) * param_1[0x1b] + 1 +
                         local_8c + param_1[0x1b] / 2;
          }
          if (param_1[0x1a] == 2) {
            cVar4 = FUN_0049ba00();
            if (cVar4 == '\0') {
              local_90 = 0;
            }
            else {
              local_90 = (int)(param_1[0x1b] + (param_1[0x1b] >> 0x1f & 3U)) >> 2;
            }
            param_1[1] = *(short *)(param_1[4] + 0x4a) + 1 +
                         ((*(short *)(param_1[4] + 0x48) + local_14) / 2) * param_1[0x1b] + local_90
                         + param_1[0x1b] / 2;
          }
        }
      }
    }
    else if (param_1[0x1a] == -1) {
      param_1[1] = 1;
    }
    iVar5 = FUN_00478140(1);
    param_1[5] = iVar5 + _DAT_00a180f8;
    iVar5 = FUN_00478270(1);
    param_1[6] = iVar5 + _DAT_00a180fc;
    iVar5 = FUN_004bf870(1);
    param_1[8] = iVar5 + _DAT_00a180fc;
    iVar5 = FUN_004bf980(0);
    param_1[7] = iVar5;
    if (0xff - DAT_00a117bc < (int)*(short *)(param_1[4] + 0x44)) {
      local_9c = 0xff - DAT_00a117bc;
    }
    else {
      local_9c = (int)*(short *)(param_1[4] + 0x44);
    }
    param_1[9] = local_9c;
    param_1[10] = (int)*(short *)(param_1[4] + 0x46);
    if (param_1[9] != 0) {
      cVar4 = FUN_004bf9b0(*(undefined4 *)(param_1[4] + 0x28),*(undefined4 *)(param_1[4] + 0x2c));
      if ((cVar4 == '\0') || (*(int *)(param_1[4] + 0x68) != 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) && (0 < *(int *)(param_1[4] + 0xc4))) {
        bVar1 = false;
      }
      local_c = 1;
      if (bVar1) {
        local_c = 3;
      }
      switch(param_1[10]) {
      case 0:
        if ((param_1[9] != 0xff) || (bVar1)) {
          FUN_005160d0(1,param_1[9] / local_c);
        }
        else {
          FUN_005160d0(0,0xff);
        }
        break;
      case 1:
        FUN_005160d0(2,param_1[9] / local_c);
        break;
      case 2:
        FUN_005160d0(3,param_1[9] / local_c);
        break;
      case 3:
        FUN_005160d0(0xb,param_1[9] / local_c);
      }
      if ((*param_1 != -1) && (iVar5 = FUN_004cd340(), *param_1 < iVar5)) {
        FUN_004cde80(*param_1);
        iVar5 = FUN_004ce080();
        if ((param_1[1] < iVar5) &&
           ((-DAT_0084b264 <= param_1[5] + param_1[0xc] &&
            (param_1[5] - param_1[0xc] <= *DAT_00a16718 + 1 + DAT_0084b264)))) {
          iVar5 = ((param_1[5] - DAT_00a1816c) * (DAT_00a18174 + -100)) / 100 + param_1[5];
          iVar6 = (param_1[0xc] * DAT_00a18174) / 100;
          iVar7 = (param_1[0xd] * DAT_00a18174) / 100;
          iVar8 = (param_1[0xe] * DAT_00a18174) / 100;
          iVar9 = (param_1[0xf] * DAT_00a18174) / 100;
          iVar10 = (param_1[0x18] * DAT_00a18174) / 100;
          iVar11 = (param_1[0x19] * DAT_00a18174) / 100;
          iVar12 = ((param_1[6] - DAT_00a18170) * (DAT_00a18174 + -100)) / 100 + param_1[6] +
                   _DAT_00a18c74;
          iVar15 = ((param_1[8] - DAT_00a18170) * (DAT_00a18174 + -100)) / 100 + param_1[8] +
                   _DAT_00a18c74;
          if (param_1[3] != -1) {
            if (param_1[2] < 1) {
              local_b8 = 1;
            }
            else {
              local_b8 = param_1[2];
            }
            FUN_004cde80(param_1[3]);
            iVar13 = FUN_004ce080();
            if (local_b8 < iVar13 - 1U) {
              if (param_1[2] < 1) {
                local_bc = 1;
              }
              else {
                local_bc = param_1[2];
              }
              local_c0 = local_bc;
            }
            else {
              FUN_004cde80(param_1[3]);
              local_c0 = FUN_004ce080();
              local_c0 = local_c0 + -1;
            }
            param_1[2] = local_c0;
          }
          if ((param_1[3] != -1) && (*DAT_00a16688 == '\x01')) {
            if (*(int *)(param_1[4] + 0xc4) < 0) {
              local_c4 = 0;
            }
            else {
              local_c4 = *(int *)(param_1[4] + 0xc4);
            }
            uVar16 = local_c4 >> 0x1f;
            if (DAT_0084b248 == 1) {
              if (iVar8 / 2 < (int)(local_c4 + (uVar16 & 7)) >> 3) {
                local_c8 = iVar8 / 2;
              }
              else {
                local_c8 = (int)(local_c4 + (uVar16 & 7)) >> 3;
              }
              if ((iVar8 << 2) / 5 < (int)(local_c4 + (uVar16 & 3)) >> 2) {
                local_cc = (iVar8 << 2) / 5;
              }
              else {
                local_cc = (int)(local_c4 + (uVar16 & 3)) >> 2;
              }
              if (iVar8 / 2 < (int)(local_c4 + (uVar16 & 7)) >> 3) {
                local_d0 = iVar8 / 2;
              }
              else {
                local_d0 = (int)(local_c4 + (uVar16 & 7)) >> 3;
              }
              if ((iVar8 << 2) / 5 < (int)(local_c4 + (uVar16 & 3)) >> 2) {
                local_d4 = (iVar8 << 2) / 5;
              }
              else {
                local_d4 = (int)(local_c4 + (uVar16 & 3)) >> 2;
              }
              iVar13 = param_1[2];
              uVar20 = DAT_0084b240;
              FUN_004cde80(param_1[3]);
              puVar14 = (undefined4 *)FUN_004ce990(iVar13);
              FUN_0051f060((iVar5 - iVar8) + local_d4,(iVar15 - iVar9) + local_d0,
                           (iVar5 + iVar8) - local_cc,iVar15 - local_c8,*puVar14,uVar20);
            }
            if (DAT_0084b248 == 2) {
              if (iVar8 / 2 < (int)(local_c4 + (uVar16 & 7)) >> 3) {
                local_d8 = iVar8 / 2;
              }
              else {
                local_d8 = (int)(local_c4 + (uVar16 & 7)) >> 3;
              }
              if ((iVar8 << 2) / 5 < (int)(local_c4 + (uVar16 & 3)) >> 2) {
                local_dc = (iVar8 << 2) / 5;
              }
              else {
                local_dc = (int)(local_c4 + (uVar16 & 3)) >> 2;
              }
              if (iVar8 / 2 < (int)(local_c4 + (uVar16 & 7)) >> 3) {
                local_e0 = iVar8 / 2;
              }
              else {
                local_e0 = (int)(local_c4 + (uVar16 & 7)) >> 3;
              }
              if ((iVar8 << 2) / 5 < (int)(local_c4 + (uVar16 & 3)) >> 2) {
                local_e4 = (iVar8 << 2) / 5;
              }
              else {
                local_e4 = (int)(local_c4 + (uVar16 & 3)) >> 2;
              }
              iVar13 = param_1[2];
              uVar20 = DAT_0084b240;
              FUN_004cde80(param_1[3]);
              puVar14 = (undefined4 *)FUN_004ce990(iVar13);
              FUN_0051f060(((iVar5 - iVar8) + local_e4) * 2,((iVar15 - iVar9) + local_e0) * 2,
                           ((iVar5 + iVar8) - local_dc) * 2,(iVar15 - local_d8) * 2,*puVar14,uVar20)
              ;
            }
          }
          bVar3 = true;
          if ((DAT_0084b248 == 1) && (DAT_00a18174 == 100)) {
            bVar3 = false;
          }
          if ((*(int *)(param_1[4] + 0xe8) < 1) && (*(int *)(param_1[4] + 0x10c) < 1)) {
            bVar2 = false;
          }
          else {
            bVar2 = true;
          }
          if (bVar2) {
            FUN_004fe844();
            FUN_004fe844();
            FUN_004fe844();
            if (*(int *)(param_1[4] + 0x114) == 0) {
              FUN_004febf1(*(int *)(param_1[4] + 0x110) - *(int *)(param_1[4] + 0x10c));
            }
            local_24 = FUN_004fe844();
            local_20 = FUN_004fe844();
            local_1c = FUN_004fe844();
          }
          if ((*param_1 == -1) || (bVar1)) {
            if ((*param_1 != -1) && (bVar1)) {
              if (bVar3) {
                iVar8 = (DAT_0084b264 * DAT_00a18174) / 100;
                if (bVar2) {
                  if (local_1c + 0xff < 0x100) {
                    local_144 = local_1c + 0xff;
                  }
                  else {
                    local_144 = 0xff;
                  }
                  if (local_20 + 0xff < 0x100) {
                    local_148 = local_20 + 0xff;
                  }
                  else {
                    local_148 = 0xff;
                  }
                  if (local_24 + 0xff < 0x100) {
                    local_14c = local_24 + 0xff;
                  }
                  else {
                    local_14c = 0xff;
                  }
                  FUN_005161e0(local_14c,local_148,local_144);
                }
                uVar20 = 0;
                FUN_004cde80(*param_1);
                puVar14 = (undefined4 *)FUN_004ce990(uVar20);
                uVar20 = FUN_0052a120(((param_1[1] + -1) % param_1[0x1b]) * param_1[0x18],
                                      (((param_1[1] + -1) / param_1[0x1b]) * param_1[0x19] +
                                      param_1[0x19]) - DAT_0084b264 / 2,param_1[0x18],
                                      DAT_0084b264 / 2,*puVar14);
                FUN_0051f060((iVar5 - iVar6) * DAT_0084b248,
                             (((iVar12 - iVar7) + iVar11) - iVar8 / 2) * DAT_0084b248,
                             (iVar5 - iVar6) * DAT_0084b248 + iVar10 * DAT_0084b248,
                             (((iVar12 - iVar7) + iVar11) - iVar8 / 2) * DAT_0084b248 +
                             (iVar8 / 2) * DAT_0084b248,uVar20,DAT_0084b240);
                FUN_00515700(uVar20,0);
                FUN_005160d0(param_1[10] + 1,param_1[9]);
                uVar20 = 0;
                FUN_004cde80(*param_1);
                puVar14 = (undefined4 *)FUN_004ce990(uVar20);
                uVar20 = FUN_0052a120(((param_1[1] + -1) % param_1[0x1b]) * param_1[0x18],
                                      ((param_1[1] + -1) / param_1[0x1b]) * param_1[0x19],
                                      param_1[0x18],param_1[0x19] - DAT_0084b264 / 2,*puVar14);
                FUN_0051f060((iVar5 - iVar6) * DAT_0084b248,(iVar12 - iVar7) * DAT_0084b248,
                             ((iVar5 - iVar6) + iVar10) * DAT_0084b248,
                             (((iVar12 - iVar7) + iVar11) - iVar8 / 2) * DAT_0084b248,uVar20,
                             DAT_0084b240);
                FUN_00515700(uVar20,0);
                if (bVar2) {
                  FUN_005160d0(2,0xff);
                  if (local_1c < 0x100) {
                    local_150 = local_1c;
                  }
                  else {
                    local_150 = 0xff;
                  }
                  if (local_20 < 0x100) {
                    local_154 = local_20;
                  }
                  else {
                    local_154 = 0xff;
                  }
                  if (local_24 < 0x100) {
                    local_158 = local_24;
                  }
                  else {
                    local_158 = 0xff;
                  }
                  FUN_005161e0(local_158,local_154,local_150);
                  uVar20 = 0;
                  FUN_004cde80(*param_1);
                  puVar14 = (undefined4 *)FUN_004ce990(uVar20);
                  uVar20 = FUN_0052a120(((param_1[1] + -1) % param_1[0x1b]) * param_1[0x18],
                                        (((param_1[1] + -1) / param_1[0x1b]) * param_1[0x19] +
                                        param_1[0x19]) - DAT_0084b264 / 2,param_1[0x18],
                                        DAT_0084b264 / 2,*puVar14);
                  FUN_0051f060((iVar5 - iVar6) * DAT_0084b248,
                               (((iVar12 - iVar7) + iVar11) - iVar8 / 2) * DAT_0084b248,
                               (iVar5 - iVar6) * DAT_0084b248 + iVar10 * DAT_0084b248,
                               (((iVar12 - iVar7) + iVar11) - iVar8 / 2) * DAT_0084b248 +
                               (iVar8 / 2) * DAT_0084b248,uVar20,DAT_0084b240);
                  FUN_00515700(uVar20,0);
                  FUN_005160d0(2,param_1[9]);
                  uVar20 = 0;
                  FUN_004cde80(*param_1);
                  puVar14 = (undefined4 *)FUN_004ce990(uVar20);
                  uVar20 = FUN_0052a120(((param_1[1] + -1) % param_1[0x1b]) * param_1[0x18],
                                        ((param_1[1] + -1) / param_1[0x1b]) * param_1[0x19],
                                        param_1[0x18],param_1[0x19] - DAT_0084b264 / 2,*puVar14);
                  FUN_0051f060((iVar5 - iVar6) * DAT_0084b248,(iVar12 - iVar7) * DAT_0084b248,
                               ((iVar5 - iVar6) + iVar10) * DAT_0084b248,
                               (((iVar12 - iVar7) + iVar11) - iVar8 / 2) * DAT_0084b248,uVar20,
                               DAT_0084b240);
                  FUN_00515700(uVar20,0);
                  FUN_004bf5b0(0,0,0);
                }
              }
              else {
                if (bVar2) {
                  if (local_1c + 0xff < 0x100) {
                    local_12c = local_1c + 0xff;
                  }
                  else {
                    local_12c = 0xff;
                  }
                  if (local_20 + 0xff < 0x100) {
                    local_130 = local_20 + 0xff;
                  }
                  else {
                    local_130 = 0xff;
                  }
                  if (local_24 + 0xff < 0x100) {
                    local_134 = local_24 + 0xff;
                  }
                  else {
                    local_134 = 0xff;
                  }
                  FUN_005161e0(local_134,local_130,local_12c);
                }
                uVar19 = 0;
                uVar18 = 0;
                uVar17 = 0;
                uVar20 = DAT_0084b240;
                FUN_004cde80(*param_1);
                puVar14 = (undefined4 *)FUN_004ce990(uVar17);
                FUN_00526e30(iVar5 - iVar6,((iVar12 - iVar7) + iVar11) - DAT_0084b264 / 2,
                             ((param_1[1] + -1) % param_1[0x1b]) * param_1[0x18],
                             (((param_1[1] + -1) / param_1[0x1b]) * param_1[0x19] + param_1[0x19]) -
                             DAT_0084b264 / 2,param_1[0x18],DAT_0084b264 / 2,*puVar14,uVar20,uVar18,
                             uVar19);
                FUN_005160d0(param_1[10] + 1,param_1[9]);
                uVar19 = 0;
                uVar18 = 0;
                uVar17 = 0;
                uVar20 = DAT_0084b240;
                FUN_004cde80(*param_1);
                puVar14 = (undefined4 *)FUN_004ce990(uVar17);
                FUN_00526e30(iVar5 - iVar6,iVar12 - iVar7,
                             ((param_1[1] + -1) % param_1[0x1b]) * param_1[0x18],
                             ((param_1[1] + -1) / param_1[0x1b]) * param_1[0x19],param_1[0x18],
                             param_1[0x19] - DAT_0084b264 / 2,*puVar14,uVar20,uVar18,uVar19);
                if (bVar2) {
                  FUN_005160d0(2,0xff);
                  if (local_1c < 0x100) {
                    local_138 = local_1c;
                  }
                  else {
                    local_138 = 0xff;
                  }
                  if (local_20 < 0x100) {
                    local_13c = local_20;
                  }
                  else {
                    local_13c = 0xff;
                  }
                  if (local_24 < 0x100) {
                    local_140 = local_24;
                  }
                  else {
                    local_140 = 0xff;
                  }
                  FUN_005161e0(local_140,local_13c,local_138);
                  uVar19 = 0;
                  uVar18 = 0;
                  uVar17 = 0;
                  uVar20 = DAT_0084b240;
                  FUN_004cde80(*param_1);
                  puVar14 = (undefined4 *)FUN_004ce990(uVar17);
                  FUN_00526e30(iVar5 - iVar6,((iVar12 - iVar7) + iVar11) - DAT_0084b264 / 2,
                               ((param_1[1] + -1) % param_1[0x1b]) * param_1[0x18],
                               (((param_1[1] + -1) / param_1[0x1b]) * param_1[0x19] + param_1[0x19])
                               - DAT_0084b264 / 2,param_1[0x18],DAT_0084b264 / 2,*puVar14,uVar20,
                               uVar18,uVar19);
                  FUN_005160d0(2,param_1[9]);
                  uVar19 = 0;
                  uVar18 = 0;
                  uVar17 = 0;
                  uVar20 = DAT_0084b240;
                  FUN_004cde80(*param_1);
                  puVar14 = (undefined4 *)FUN_004ce990(uVar17);
                  FUN_00526e30(iVar5 - iVar6,iVar12 - iVar7,
                               ((param_1[1] + -1) % param_1[0x1b]) * param_1[0x18],
                               ((param_1[1] + -1) / param_1[0x1b]) * param_1[0x19],param_1[0x18],
                               param_1[0x19] - DAT_0084b264 / 2,*puVar14,uVar20,uVar18,uVar19);
                  FUN_004bf5b0(0,0,0);
                }
              }
            }
          }
          else {
            if (bVar2) {
              if (local_1c + 0xff < 0x100) {
                local_114 = local_1c + 0xff;
              }
              else {
                local_114 = 0xff;
              }
              if (local_20 + 0xff < 0x100) {
                local_118 = local_20 + 0xff;
              }
              else {
                local_118 = 0xff;
              }
              if (local_24 + 0xff < 0x100) {
                local_11c = local_24 + 0xff;
              }
              else {
                local_11c = 0xff;
              }
              FUN_005161e0(local_11c,local_118,local_114);
            }
            if (bVar3) {
              iVar8 = param_1[1];
              uVar20 = DAT_0084b240;
              FUN_004cde80(*param_1);
              puVar14 = (undefined4 *)FUN_004ce990(iVar8);
              FUN_0051f060((iVar5 - iVar6) * DAT_0084b248,(iVar12 - iVar7) * DAT_0084b248,
                           (iVar5 + iVar6) * DAT_0084b248,iVar12 * DAT_0084b248,*puVar14,uVar20);
            }
            else {
              iVar8 = param_1[1];
              uVar20 = DAT_0084b240;
              FUN_004cde80(*param_1);
              puVar14 = (undefined4 *)FUN_004ce990(iVar8);
              FUN_0051e930(iVar5 - iVar6,iVar12 - iVar7,*puVar14,uVar20);
            }
            if (bVar2) {
              FUN_005160d0(2,0xff);
              if (local_1c < 0x100) {
                local_120 = local_1c;
              }
              else {
                local_120 = 0xff;
              }
              if (local_20 < 0x100) {
                local_124 = local_20;
              }
              else {
                local_124 = 0xff;
              }
              if (local_24 < 0x100) {
                local_128 = local_24;
              }
              else {
                local_128 = 0xff;
              }
              FUN_005161e0(local_128,local_124,local_120);
              if (bVar3) {
                iVar8 = param_1[1];
                uVar20 = DAT_0084b240;
                FUN_004cde80(*param_1);
                puVar14 = (undefined4 *)FUN_004ce990(iVar8);
                FUN_0051f060((iVar5 - iVar6) * DAT_0084b248,(iVar12 - iVar7) * DAT_0084b248,
                             (iVar5 + iVar6) * DAT_0084b248,iVar12 * DAT_0084b248,*puVar14,uVar20);
              }
              else {
                iVar8 = param_1[1];
                uVar20 = DAT_0084b240;
                FUN_004cde80(*param_1);
                puVar14 = (undefined4 *)FUN_004ce990(iVar8);
                FUN_0051e930(iVar5 - iVar6,iVar12 - iVar7,*puVar14,uVar20);
              }
              FUN_004bf5b0(0,0,0);
            }
          }
        }
      }
    }
  }
  return;
}

