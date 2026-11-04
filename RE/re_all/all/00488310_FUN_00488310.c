
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00488310(int param_1,char param_2)

{
  double dVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined8 uVar10;
  int local_a68;
  int local_a64;
  int local_a60;
  int local_a5c;
  int local_a58;
  int local_a54;
  int local_a50;
  int local_a4c;
  int local_a48;
  int local_a44;
  int local_a40;
  int local_a3c;
  int local_a38;
  int local_a34;
  int local_a30;
  int local_a2c;
  int local_a28;
  int local_a24;
  int local_a20;
  int local_a1c;
  int local_a18;
  int local_a14;
  int local_a10;
  int local_a0c;
  int local_a08;
  int local_a04;
  int local_a00;
  int local_9fc;
  int local_9f8;
  int local_9f4;
  int local_9f0;
  int local_9ec;
  int local_9e8;
  int local_9e4;
  int local_9e0;
  int local_9dc;
  int local_974;
  int local_970;
  int local_96c;
  int local_968;
  int local_964;
  int local_960;
  int local_95c;
  int local_958;
  int local_954;
  int local_950;
  int local_94c;
  int local_948;
  int local_944;
  int local_940;
  int local_93c;
  int local_938;
  int local_934;
  int local_930;
  int local_92c;
  int local_928;
  int local_924;
  int local_920;
  int local_91c;
  int local_918;
  int local_914;
  int local_910;
  int local_90c;
  int local_908;
  int local_904;
  int local_900;
  int local_8fc;
  int local_8f8;
  int local_8f4;
  int local_8f0;
  int local_8ec;
  int local_8e8;
  int local_7c0;
  int local_7bc;
  int local_7a8;
  int local_768;
  int local_6c8;
  int local_6c4;
  int local_6a0;
  int local_69c;
  int local_68c;
  int local_67c;
  int local_660;
  int local_618;
  int local_480;
  int local_47c;
  int local_468;
  int local_428;
  int local_300;
  int local_2fc;
  int local_2c8;
  int local_2c4;
  int local_270;
  int local_268;
  int local_248;
  int local_224;
  int local_1f8;
  int local_1ec;
  int local_1e4;
  int local_1c4;
  int local_1a0;
  int local_174;
  int local_168;
  int local_164;
  int local_160;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_140;
  int local_13c;
  int local_138;
  int aiStack_124 [4];
  int aiStack_114 [4];
  int local_104;
  int local_100;
  double local_fc;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  double local_d4;
  double local_cc;
  int aiStack_c4 [4];
  int aiStack_b4 [4];
  int local_a4;
  int local_a0;
  double local_9c;
  int local_90;
  int local_8c;
  char local_85;
  int local_84;
  undefined4 local_80;
  int local_7c [4];
  int local_6c;
  int local_64 [4];
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  if ((*(char *)(param_1 + 0x279) == '\0') && (*(char *)(param_1 + 0x27a) == '\0')) {
    if (*(int *)(param_1 + 0x1b4) < 1) {
      *(undefined4 *)(param_1 + 0x1b4) = 1;
    }
    local_3c = *(int *)(param_1 + 0x1d0);
    local_38 = *(int *)(param_1 + 0x1d4);
    local_10 = *(int *)(param_1 + 0x1d8);
    local_c = *(int *)(param_1 + 0x1dc);
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    if (0 < *(int *)(param_1 + 0x2b8)) {
      local_50 = FUN_004fe844();
      local_4c = FUN_004fe844();
      local_48 = FUN_004fe844();
    }
    if (*(int *)(param_1 + 0x2c8) < 1) {
      local_50 = FUN_004fe844();
      local_4c = FUN_004fe844();
      local_48 = FUN_004fe844();
    }
    else {
      local_50 = FUN_004fe844();
      local_4c = FUN_004fe844();
      local_48 = FUN_004fe844();
    }
    if (0 < *(int *)(param_1 + 0x324)) {
      if (*(int *)(param_1 + 0x32c) == 0) {
        local_80 = FUN_004febf1();
        local_50 = FUN_004fe844();
        local_4c = FUN_004fe844();
        local_48 = FUN_004fe844();
      }
      else if (*(int *)(param_1 + 0x32c) == 1) {
        local_84 = *(int *)(param_1 + 0x324) - *(int *)(param_1 + 0x328);
        local_50 = FUN_004fe844();
        local_4c = FUN_004fe844();
        local_48 = FUN_004fe844();
      }
    }
    if (*(int *)(param_1 + 0x2dc) < 1) {
      local_2c4 = 1;
    }
    else {
      local_2c4 = *(int *)(param_1 + 0x2dc);
    }
    local_6c = *(int *)(param_1 + 0x2cc) -
               ((*(int *)(param_1 + 0x2cc) - *(int *)(param_1 + 0x2d0)) * *(int *)(param_1 + 0x2e0))
               / local_2c4;
    if (*(int *)(param_1 + 0x2dc) < 1) {
      local_2c8 = 1;
    }
    else {
      local_2c8 = *(int *)(param_1 + 0x2dc);
    }
    local_20 = *(int *)(param_1 + 0x2d4) -
               ((*(int *)(param_1 + 0x2d4) - *(int *)(param_1 + 0x2d8)) * *(int *)(param_1 + 0x2e0))
               / local_2c8;
    if (0 < *(int *)(param_1 + 0x2f4)) {
      uVar7 = *(uint *)(param_1 + 0x2f4) & 0x80000001;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;
      }
      local_85 = (-(uVar7 != 0) & 2U) - 1;
      if (*(int *)(param_1 + 0x2fc) < *(int *)(param_1 + 0x2f8)) {
        local_6c = (int)local_85 *
                   ((*(int *)(param_1 + 0x2e4) * *(int *)(param_1 + 0x2fc)) /
                   *(int *)(param_1 + 0x2f8)) + local_6c;
        local_20 = (int)local_85 *
                   ((*(int *)(param_1 + 0x2e8) * *(int *)(param_1 + 0x2fc)) /
                   *(int *)(param_1 + 0x2f8)) + local_20;
      }
      else {
        local_6c = (int)local_85 *
                   (*(int *)(param_1 + 0x2e4) -
                   ((*(int *)(param_1 + 0x2fc) - *(int *)(param_1 + 0x2f8)) *
                   *(int *)(param_1 + 0x2e4)) / *(int *)(param_1 + 0x2f8)) + local_6c;
        local_20 = (int)local_85 *
                   (*(int *)(param_1 + 0x2e8) -
                   ((*(int *)(param_1 + 0x2fc) - *(int *)(param_1 + 0x2f8)) *
                   *(int *)(param_1 + 0x2e8)) / *(int *)(param_1 + 0x2f8)) + local_20;
      }
    }
    local_1c = 0;
    local_34 = 0;
    local_30 = 100;
    if ((*(int *)(param_1 + 0x310) != 100) || (*(int *)(param_1 + 0x314) != 100)) {
      if (*(int *)(param_1 + 0x31c) < 1) {
        local_1c = *(int *)(param_1 + 0x300);
        local_34 = *(int *)(param_1 + 0x308);
        local_30 = *(int *)(param_1 + 0x310);
      }
      else {
        local_1c = *(int *)(param_1 + 0x300) -
                   ((*(int *)(param_1 + 0x300) - *(int *)(param_1 + 0x304)) *
                   *(int *)(param_1 + 0x31c)) / *(int *)(param_1 + 0x318);
        local_34 = *(int *)(param_1 + 0x308) -
                   ((*(int *)(param_1 + 0x308) - *(int *)(param_1 + 0x30c)) *
                   *(int *)(param_1 + 0x31c)) / *(int *)(param_1 + 0x318);
        local_30 = *(int *)(param_1 + 0x310) -
                   ((*(int *)(param_1 + 0x310) - *(int *)(param_1 + 0x314)) *
                   *(int *)(param_1 + 0x31c)) / *(int *)(param_1 + 0x318);
      }
    }
    if ((*(int *)(param_1 + 0x33c) != 0) && (-1 < *(int *)(param_1 + 0x338))) {
      iVar2 = FUN_004febf1();
      local_3c = ((*(int *)(param_1 + 0x33c) - iVar2) * *(int *)(param_1 + 0x330)) /
                 *(int *)(param_1 + 0x33c) + local_3c;
      iVar2 = FUN_004febf1();
      local_38 = ((*(int *)(param_1 + 0x33c) - iVar2) * *(int *)(param_1 + 0x330)) /
                 *(int *)(param_1 + 0x33c) + local_38;
      iVar2 = FUN_004febf1();
      local_10 = ((*(int *)(param_1 + 0x33c) - iVar2) * *(int *)(param_1 + 0x334)) /
                 *(int *)(param_1 + 0x33c) + local_10;
      iVar2 = FUN_004febf1();
      local_c = ((*(int *)(param_1 + 0x33c) - iVar2) * *(int *)(param_1 + 0x334)) /
                *(int *)(param_1 + 0x33c) + local_c;
    }
    local_54 = 0;
    local_18 = 0;
    local_2c = 0;
    local_14 = 0;
    local_44 = 0;
    local_40 = 0;
    local_8 = 0;
    *(int *)(param_1 + 0x188) = *(int *)(param_1 + 0x188) + 10000;
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 10000;
    *(int *)(param_1 + 0x18c) = *(int *)(param_1 + 0x18c) + 10000;
    *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + 10000;
    if (((*(char *)(param_1 + 0x278) == '\0') || (*(char *)(param_1 + 0x279) != '\0')) &&
       (*(int *)(param_1 + 0x1b0) != -1)) {
      if ((*(char *)(param_1 + 0x264) == '\0') && (*(char *)(param_1 + 0x265) == '\0')) {
        if (*(char *)(param_1 + 0x240) == '\0') {
          if ((*(int *)(param_1 + 0x1b8) == *(int *)(param_1 + 0x1bc)) &&
             (*(int *)(param_1 + 0x1b8) % 0xe10 == 0)) {
            if (*(short *)(param_1 + 0x268) < 3) {
              local_54 = FUN_004fe844();
              local_2c = FUN_004fe844();
              local_18 = FUN_004fe844();
              if (*(short *)(param_1 + 0x268) == 1) {
                local_14 = FUN_004fe844();
              }
              else {
                if (*(short *)(param_1 + 0x268) == 2) {
                  local_428 = *(int *)(param_1 + 400) -
                              ((*(int *)(param_1 + 400) - *(int *)(param_1 + 0x194)) *
                              *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4);
                }
                else {
                  local_428 = FUN_004fe844();
                }
                local_14 = local_428;
              }
            }
            else if (2 < *(short *)(param_1 + 0x268)) {
              local_54 = FUN_004fe844();
              local_2c = FUN_004fe844();
              local_18 = *(int *)(param_1 + 0x188) -
                         ((*(int *)(param_1 + 0x188) - *(int *)(param_1 + 0x18c)) *
                         *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4);
              if (*(short *)(param_1 + 0x268) == 4) {
                local_468 = *(int *)(param_1 + 400) -
                            ((*(int *)(param_1 + 400) - *(int *)(param_1 + 0x194)) *
                            *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4);
              }
              else {
                local_468 = FUN_004fe844();
              }
              local_14 = local_468;
            }
          }
          else {
            if (local_3c == 100) {
              local_47c = local_10;
            }
            else {
              local_47c = local_3c;
            }
            local_f0 = local_47c;
            if (local_38 == 100) {
              local_480 = local_c;
            }
            else {
              local_480 = local_38;
            }
            local_ec = local_480;
            if (*(short *)(param_1 + 0x268) < 3) {
              local_54 = FUN_004fe844();
              local_2c = FUN_004fe844();
            }
            else if (2 < *(short *)(param_1 + 0x268)) {
              local_54 = FUN_004fe844();
              local_2c = FUN_004fe844();
            }
          }
        }
        else {
          local_fc = ((double)(*(int *)(param_1 + 0x1b8) +
                              ((*(int *)(param_1 + 0x1bc) - *(int *)(param_1 + 0x1b8)) *
                              *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4)) /
                     _DAT_007d1020) * _DAT_007d1028;
          for (local_138 = 0; local_138 < 4; local_138 = local_138 + 1) {
            local_64[local_138] =
                 ((*(int *)(param_1 + 0x210 + local_138 * 4) -
                  *(int *)(param_1 + 0x200 + local_138 * 4)) * *(int *)(param_1 + 0x1b0)) /
                 *(int *)(param_1 + 0x1b4) + *(int *)(param_1 + 0x200 + local_138 * 4);
            local_7c[local_138] =
                 ((*(int *)(param_1 + 0x230 + local_138 * 4) -
                  *(int *)(param_1 + 0x220 + local_138 * 4)) * *(int *)(param_1 + 0x1b0)) /
                 *(int *)(param_1 + 0x1b4) + *(int *)(param_1 + 0x220 + local_138 * 4);
          }
          iVar2 = local_64[0] + local_64[1] + local_64[2] + local_64[3];
          local_100 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
          iVar2 = local_7c[0] + local_7c[1] + local_7c[2] + local_7c[3];
          local_104 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
          for (local_13c = 0; local_13c < 4; local_13c = local_13c + 1) {
            FUN_004feea4(-local_fc);
            FUN_004fef54(-local_fc);
            iVar2 = FUN_004fe844();
            aiStack_124[local_13c] = iVar2;
            FUN_004feea4(local_fc);
            FUN_004fef54(local_fc);
            iVar2 = FUN_004fe844();
            aiStack_114[local_13c] = iVar2;
            local_64[local_13c] = aiStack_124[local_13c];
            local_7c[local_13c] = aiStack_114[local_13c];
          }
          for (local_140 = 0; local_140 < 4; local_140 = local_140 + 1) {
            iVar2 = FUN_004fe844();
            local_64[local_140] = iVar2;
            iVar2 = FUN_004fe844();
            local_7c[local_140] = iVar2;
          }
        }
      }
      else if (*(char *)(param_1 + 0x265) == '\0') {
        *(int *)(param_1 + 0x188) = *(int *)(param_1 + 0x188) + -10000;
        *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + -10000;
        *(int *)(param_1 + 0x18c) = *(int *)(param_1 + 0x18c) + -10000;
        *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + -10000;
        if (*(short *)(param_1 + 0x268) < 3) {
          iVar2 = FUN_004fe844();
          *(float *)(param_1 + 0x5c) = (float)(iVar2 * DAT_0084b248);
          iVar2 = FUN_004fe844();
          *(float *)(param_1 + 0x60) = (float)(iVar2 * DAT_0084b248);
        }
        else if (2 < *(short *)(param_1 + 0x268)) {
          iVar2 = FUN_004fe844();
          *(float *)(param_1 + 0x5c) = (float)(iVar2 * DAT_0084b248);
          iVar2 = FUN_004fe844();
          *(float *)(param_1 + 0x60) = (float)(iVar2 * DAT_0084b248);
        }
        *(int *)(param_1 + 0x188) = *(int *)(param_1 + 0x188) + 10000;
        *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 10000;
        *(int *)(param_1 + 0x18c) = *(int *)(param_1 + 0x18c) + 10000;
        *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + 10000;
      }
      else {
        if (*(short *)(param_1 + 0x268) < 3) {
          local_54 = FUN_004fe844();
          local_2c = FUN_004fe844();
          local_18 = FUN_004fe844();
          if (*(short *)(param_1 + 0x268) == 1) {
            local_14 = FUN_004fe844();
          }
          else {
            if (*(short *)(param_1 + 0x268) == 2) {
              local_618 = *(int *)(param_1 + 400) -
                          ((*(int *)(param_1 + 400) - *(int *)(param_1 + 0x194)) *
                          *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4);
            }
            else {
              local_618 = FUN_004fe844();
            }
            local_14 = local_618;
          }
        }
        else if (2 < *(short *)(param_1 + 0x268)) {
          local_54 = FUN_004fe844();
          local_2c = FUN_004fe844();
          local_18 = *(int *)(param_1 + 0x188) -
                     ((*(int *)(param_1 + 0x188) - *(int *)(param_1 + 0x18c)) *
                     *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4);
          if (*(short *)(param_1 + 0x268) == 4) {
            local_660 = *(int *)(param_1 + 400) -
                        ((*(int *)(param_1 + 400) - *(int *)(param_1 + 0x194)) *
                        *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4);
          }
          else {
            local_660 = FUN_004fe844();
          }
          local_14 = local_660;
        }
        iVar5 = local_14;
        iVar2 = local_18;
        if (*(int *)(param_1 + 0x37c) == -1) {
          if (local_18 < local_54) {
            local_18 = local_54;
            local_54 = iVar2;
          }
          if (local_14 < local_2c) {
            local_14 = local_2c;
            local_2c = iVar5;
          }
        }
      }
    }
    else if ((*(char *)(param_1 + 0x264) == '\0') && (*(char *)(param_1 + 0x265) == '\0')) {
      if (*(char *)(param_1 + 0x240) == '\0') {
        if ((*(int *)(param_1 + 0x1b8) == *(int *)(param_1 + 0x1bc)) &&
           (*(int *)(param_1 + 0x1b8) % 0xe10 == 0)) {
          if (*(short *)(param_1 + 0x268) < 3) {
            local_54 = FUN_004fe844();
            local_2c = FUN_004fe844();
            local_18 = FUN_004fe844();
            local_14 = FUN_004fe844();
          }
          else if (2 < *(short *)(param_1 + 0x268)) {
            local_54 = FUN_004fe844();
            local_2c = FUN_004fe844();
            local_18 = *(int *)(param_1 + 0x188);
            local_14 = FUN_004fe844();
          }
        }
        else {
          if (local_3c == 100) {
            local_2fc = local_10;
          }
          else {
            local_2fc = local_3c;
          }
          local_90 = local_2fc;
          if (local_38 == 100) {
            local_300 = local_c;
          }
          else {
            local_300 = local_38;
          }
          local_8c = local_300;
          if (*(short *)(param_1 + 0x268) < 3) {
            local_54 = FUN_004fe844();
            local_2c = FUN_004fe844();
          }
          else if (2 < *(short *)(param_1 + 0x268)) {
            local_54 = FUN_004fe844();
            local_2c = FUN_004fe844();
          }
        }
      }
      else {
        local_9c = ((double)*(int *)(param_1 + 0x1b8) / _DAT_007d1020) * _DAT_007d1028;
        local_d4 = (double)local_3c / _DAT_00829840;
        local_cc = (double)local_10 / _DAT_00829840;
        for (local_d8 = 0; local_d8 < 4; local_d8 = local_d8 + 1) {
          local_64[local_d8] = *(int *)(param_1 + 0x200 + local_d8 * 4);
          local_7c[local_d8] = *(int *)(param_1 + 0x220 + local_d8 * 4);
        }
        iVar2 = local_64[0] + local_64[1] + local_64[2] + local_64[3];
        local_a0 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
        iVar2 = local_7c[0] + local_7c[1] + local_7c[2] + local_7c[3];
        local_a4 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
        for (local_dc = 0; local_dc < 4; local_dc = local_dc + 1) {
          FUN_004feea4(-local_9c);
          FUN_004fef54(-local_9c);
          iVar2 = FUN_004fe844();
          aiStack_c4[local_dc] = iVar2;
          FUN_004feea4(local_9c);
          FUN_004fef54(local_9c);
          iVar2 = FUN_004fe844();
          aiStack_b4[local_dc] = iVar2;
          local_64[local_dc] = aiStack_c4[local_dc];
          local_7c[local_dc] = aiStack_b4[local_dc];
        }
        for (local_e0 = 0; local_e0 < 4; local_e0 = local_e0 + 1) {
          iVar2 = FUN_004fe844();
          local_64[local_e0] = iVar2;
          iVar2 = FUN_004fe844();
          local_7c[local_e0] = iVar2;
        }
      }
    }
    else if (*(char *)(param_1 + 0x265) == '\0') {
      *(int *)(param_1 + 0x188) = *(int *)(param_1 + 0x188) + -10000;
      *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + -10000;
      if (*(short *)(param_1 + 0x268) < 3) {
        iVar2 = FUN_004fe844();
        *(float *)(param_1 + 0x5c) = (float)(iVar2 * DAT_0084b248);
        iVar2 = FUN_004fe844();
        *(float *)(param_1 + 0x60) = (float)(iVar2 * DAT_0084b248);
      }
      else if (2 < *(short *)(param_1 + 0x268)) {
        iVar2 = FUN_004fe844();
        *(float *)(param_1 + 0x5c) = (float)(iVar2 * DAT_0084b248);
        iVar2 = FUN_004fe844();
        *(float *)(param_1 + 0x60) = (float)(iVar2 * DAT_0084b248);
      }
      *(int *)(param_1 + 0x188) = *(int *)(param_1 + 0x188) + 10000;
      *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 10000;
    }
    else {
      if (*(short *)(param_1 + 0x268) < 3) {
        local_54 = FUN_004fe844();
        local_2c = FUN_004fe844();
        local_18 = FUN_004fe844();
        local_14 = FUN_004fe844();
      }
      else if (2 < *(short *)(param_1 + 0x268)) {
        local_54 = FUN_004fe844();
        local_2c = FUN_004fe844();
        local_18 = *(int *)(param_1 + 0x188);
        local_14 = FUN_004fe844();
      }
      iVar5 = local_14;
      iVar2 = local_18;
      if (*(int *)(param_1 + 0x37c) == -1) {
        if (local_18 < local_54) {
          local_e4 = local_18;
          local_18 = local_54;
          local_54 = iVar2;
        }
        if (local_14 < local_2c) {
          local_e8 = local_14;
          local_14 = local_2c;
          local_2c = iVar5;
        }
      }
    }
    *(int *)(param_1 + 0x188) = *(int *)(param_1 + 0x188) + -10000;
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + -10000;
    *(int *)(param_1 + 0x18c) = *(int *)(param_1 + 0x18c) + -10000;
    *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + -10000;
    local_54 = local_54 + -10000;
    local_18 = local_18 + -10000;
    local_2c = local_2c + -10000;
    local_14 = local_14 + -10000;
    if (*(char *)(param_1 + 0x266) != '\0') {
      *(undefined4 *)(param_1 + 0x1fc) = 0;
      *(undefined4 *)(param_1 + 0x1f8) = 0;
      if (*(char *)(param_1 + 0x264) == '\0') {
        uVar7 = DAT_00a17ebc >> 0x1f;
        uVar8 = DAT_00a17ec0 >> 0x1f;
        if (*(char *)(param_1 + 0x240) == '\0') {
          local_54 = local_54 - ((int)(DAT_00a17ebc + (uVar7 & 3)) >> 2);
          local_18 = local_18 - ((int)(DAT_00a17ebc + (uVar7 & 3)) >> 2);
          local_2c = local_2c - ((int)(DAT_00a17ec0 + (uVar8 & 3)) >> 2);
          local_14 = local_14 - ((int)(DAT_00a17ec0 + (uVar8 & 3)) >> 2);
          for (local_154 = 0; local_154 < 2; local_154 = local_154 + 1) {
            if (DAT_00a180f4 != '\0') {
              iVar2 = FUN_0047a490();
              if ((DAT_0084b230 - iVar2 * DAT_0084b264) / 2 < 0) {
                local_69c = 0;
              }
              else {
                iVar2 = FUN_0047a490();
                local_69c = (DAT_0084b230 - iVar2 * DAT_0084b264) / 2;
              }
              if (local_54 < -local_69c) {
                iVar2 = FUN_0047a490();
                *(int *)(param_1 + 0x1f8) = iVar2 * DAT_0084b264 + *(int *)(param_1 + 0x1f8);
                iVar2 = FUN_0047a490();
                local_54 = iVar2 * DAT_0084b264 + local_54;
                iVar2 = FUN_0047a490();
                local_18 = iVar2 * DAT_0084b264 + local_18;
              }
              if (DAT_0084b230 < local_54) {
                iVar2 = FUN_0047a490();
                *(int *)(param_1 + 0x1f8) = *(int *)(param_1 + 0x1f8) - iVar2 * DAT_0084b264;
                iVar2 = FUN_0047a490();
                local_54 = local_54 - iVar2 * DAT_0084b264;
                iVar2 = FUN_0047a490();
                local_18 = local_18 - iVar2 * DAT_0084b264;
              }
            }
            if (DAT_00a180f5 != '\0') {
              iVar2 = FUN_0047a4b0();
              if ((DAT_0084b234 - iVar2 * DAT_0084b264) / 2 < 0) {
                local_6a0 = 0;
              }
              else {
                iVar2 = FUN_0047a4b0();
                local_6a0 = (DAT_0084b234 - iVar2 * DAT_0084b264) / 2;
              }
              if (local_2c < -local_6a0) {
                iVar2 = FUN_0047a4b0();
                *(int *)(param_1 + 0x1fc) = iVar2 * DAT_0084b264 + *(int *)(param_1 + 0x1fc);
                iVar2 = FUN_0047a4b0();
                local_2c = iVar2 * DAT_0084b264 + local_2c;
                iVar2 = FUN_0047a4b0();
                local_14 = iVar2 * DAT_0084b264 + local_14;
              }
              if (DAT_0084b234 < local_2c) {
                iVar2 = FUN_0047a4b0();
                *(int *)(param_1 + 0x1fc) = *(int *)(param_1 + 0x1fc) - iVar2 * DAT_0084b264;
                iVar2 = FUN_0047a4b0();
                local_2c = local_2c - iVar2 * DAT_0084b264;
                iVar2 = FUN_0047a4b0();
                local_14 = local_14 - iVar2 * DAT_0084b264;
              }
            }
          }
        }
        else {
          for (local_150 = 0; local_150 < 4; local_150 = local_150 + 1) {
            local_64[local_150] = local_64[local_150] - ((int)(DAT_00a17ebc + (uVar7 & 3)) >> 2);
            local_7c[local_150] = local_7c[local_150] - ((int)(DAT_00a17ec0 + (uVar8 & 3)) >> 2);
          }
        }
      }
      else {
        *(float *)(param_1 + 0x5c) =
             *(float *)(param_1 + 0x5c) -
             (float)((int)(DAT_00a17ebc * DAT_0084b248 + (DAT_00a17ebc * DAT_0084b248 >> 0x1f & 3U))
                    >> 2);
        *(float *)(param_1 + 0x60) =
             *(float *)(param_1 + 0x60) -
             (float)((int)(DAT_00a17ec0 * DAT_0084b248 + (DAT_00a17ec0 * DAT_0084b248 >> 0x1f & 3U))
                    >> 2);
        for (local_14c = 0; local_14c < 2; local_14c = local_14c + 1) {
          if (DAT_00a180f4 != '\0') {
            iVar2 = FUN_0047a490();
            if ((DAT_0084b230 - iVar2 * DAT_0084b264) / 2 < 0) {
              local_67c = 0;
            }
            else {
              iVar2 = FUN_0047a490();
              local_67c = (DAT_0084b230 - iVar2 * DAT_0084b264) / 2;
            }
            if (*(float *)(param_1 + 0x5c) < (float)-local_67c) {
              iVar2 = FUN_0047a490();
              *(int *)(param_1 + 0x1f8) = iVar2 * DAT_0084b264 + *(int *)(param_1 + 0x1f8);
              iVar2 = FUN_0047a490();
              *(float *)(param_1 + 0x5c) =
                   (float)(iVar2 * DAT_0084b264 * DAT_0084b248) + *(float *)(param_1 + 0x5c);
            }
            if ((float)DAT_0084b230 < *(float *)(param_1 + 0x5c)) {
              iVar2 = FUN_0047a490();
              *(int *)(param_1 + 0x1f8) = *(int *)(param_1 + 0x1f8) - iVar2 * DAT_0084b264;
              iVar2 = FUN_0047a490();
              *(float *)(param_1 + 0x5c) =
                   *(float *)(param_1 + 0x5c) - (float)(iVar2 * DAT_0084b264 * DAT_0084b248);
            }
          }
          if (DAT_00a180f5 != '\0') {
            iVar2 = FUN_0047a4b0();
            if ((DAT_0084b234 - iVar2 * DAT_0084b264) / 2 < 0) {
              local_68c = 0;
            }
            else {
              iVar2 = FUN_0047a4b0();
              local_68c = (DAT_0084b234 - iVar2 * DAT_0084b264) / 2;
            }
            if (*(float *)(param_1 + 0x60) < (float)-local_68c) {
              iVar2 = FUN_0047a4b0();
              *(int *)(param_1 + 0x1fc) = iVar2 * DAT_0084b264 + *(int *)(param_1 + 0x1fc);
              iVar2 = FUN_0047a4b0();
              *(float *)(param_1 + 0x60) =
                   (float)(iVar2 * DAT_0084b264 * DAT_0084b248) + *(float *)(param_1 + 0x60);
            }
            if ((float)DAT_0084b234 < *(float *)(param_1 + 0x60)) {
              iVar2 = FUN_0047a4b0();
              *(int *)(param_1 + 0x1f8) = *(int *)(param_1 + 0x1f8) - iVar2 * DAT_0084b264;
              iVar2 = FUN_0047a4b0();
              *(float *)(param_1 + 0x60) =
                   *(float *)(param_1 + 0x60) - (float)(iVar2 * DAT_0084b264 * DAT_0084b248);
            }
          }
        }
      }
    }
    if (*(char *)(param_1 + 0x264) == '\0') {
      if (*(char *)(param_1 + 0x240) == '\0') {
        local_54 = ((local_54 - local_1c) * (local_30 + -100)) / 100 + local_54 + local_6c;
        local_18 = ((local_18 - local_1c) * (local_30 + -100)) / 100 + local_18 + local_6c;
        local_2c = ((local_2c - local_34) * (local_30 + -100)) / 100 + local_2c + local_20;
        local_14 = ((local_14 - local_34) * (local_30 + -100)) / 100 + local_14 + local_20;
      }
      else {
        for (local_158 = 0; local_158 < 4; local_158 = local_158 + 1) {
          local_64[local_158] =
               ((local_64[local_158] - local_1c) * (local_30 + -100)) / 100 + local_64[local_158];
          local_7c[local_158] =
               ((local_7c[local_158] - local_34) * (local_30 + -100)) / 100 + local_7c[local_158];
          local_64[local_158] = local_64[local_158] + local_6c;
          local_7c[local_158] = local_7c[local_158] + local_20;
        }
      }
      if (*(char *)(param_1 + 0x240) != '\0') {
        if (*(char *)(param_1 + 0x266) != '\0') {
          if (DAT_00a180f4 != '\0') {
            for (local_160 = 0; local_160 < 2; local_160 = local_160 + 1) {
              iVar2 = FUN_0047a490();
              if ((DAT_0084b230 - iVar2 * DAT_0084b264) / 2 < 0) {
                local_6c4 = 0;
              }
              else {
                iVar2 = FUN_0047a490();
                local_6c4 = (DAT_0084b230 - iVar2 * DAT_0084b264) / 2;
              }
              iVar2 = local_64[0] + local_64[1] + local_64[2] + local_64[3];
              if ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2 < -local_6c4) {
                iVar2 = FUN_0047a490();
                *(int *)(param_1 + 0x1f8) = iVar2 * DAT_0084b264 + *(int *)(param_1 + 0x1f8);
                iVar2 = FUN_0047a490();
                local_64[0] = iVar2 * DAT_0084b264 + local_64[0];
                iVar2 = FUN_0047a490();
                local_64[1] = iVar2 * DAT_0084b264 + local_64[1];
                iVar2 = FUN_0047a490();
                local_64[2] = iVar2 * DAT_0084b264 + local_64[2];
                iVar2 = FUN_0047a490();
                local_64[3] = iVar2 * DAT_0084b264 + local_64[3];
              }
              iVar2 = local_64[0] + local_64[1] + local_64[2] + local_64[3];
              if (DAT_0084b230 < (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2) {
                iVar2 = FUN_0047a490();
                *(int *)(param_1 + 0x1f8) = *(int *)(param_1 + 0x1f8) - iVar2 * DAT_0084b264;
                iVar2 = FUN_0047a490();
                local_64[0] = local_64[0] - iVar2 * DAT_0084b264;
                iVar2 = FUN_0047a490();
                local_64[1] = local_64[1] - iVar2 * DAT_0084b264;
                iVar2 = FUN_0047a490();
                local_64[2] = local_64[2] - iVar2 * DAT_0084b264;
                iVar2 = FUN_0047a490();
                local_64[3] = local_64[3] - iVar2 * DAT_0084b264;
              }
            }
          }
          if (DAT_00a180f5 != '\0') {
            for (local_164 = 0; local_164 < 2; local_164 = local_164 + 1) {
              iVar2 = FUN_0047a4b0();
              if ((DAT_0084b234 - iVar2 * DAT_0084b264) / 2 < 0) {
                local_6c8 = 0;
              }
              else {
                iVar2 = FUN_0047a4b0();
                local_6c8 = (DAT_0084b234 - iVar2 * DAT_0084b264) / 2;
              }
              iVar2 = local_7c[0] + local_7c[1] + local_7c[2] + local_7c[3];
              if ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2 <= -local_6c8) {
                iVar2 = FUN_0047a4b0();
                *(int *)(param_1 + 0x1fc) = iVar2 * DAT_0084b264 + *(int *)(param_1 + 0x1fc);
                iVar2 = FUN_0047a4b0();
                local_7c[0] = iVar2 * DAT_0084b264 + local_7c[0];
                iVar2 = FUN_0047a4b0();
                local_7c[1] = iVar2 * DAT_0084b264 + local_7c[1];
                iVar2 = FUN_0047a4b0();
                local_7c[2] = iVar2 * DAT_0084b264 + local_7c[2];
                iVar2 = FUN_0047a4b0();
                local_7c[3] = iVar2 * DAT_0084b264 + local_7c[3];
              }
              iVar2 = local_7c[0] + local_7c[1] + local_7c[2] + local_7c[3];
              if (DAT_0084b234 < (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2) {
                iVar2 = FUN_0047a4b0();
                *(int *)(param_1 + 0x1fc) = *(int *)(param_1 + 0x1fc) - iVar2 * DAT_0084b264;
                iVar2 = FUN_0047a4b0();
                local_7c[0] = local_7c[0] - iVar2 * DAT_0084b264;
                iVar2 = FUN_0047a4b0();
                local_7c[1] = local_7c[1] - iVar2 * DAT_0084b264;
                iVar2 = FUN_0047a4b0();
                local_7c[2] = local_7c[2] - iVar2 * DAT_0084b264;
                iVar2 = FUN_0047a4b0();
                local_7c[3] = local_7c[3] - iVar2 * DAT_0084b264;
              }
            }
          }
        }
        *(int *)(param_1 + 0x28c) = local_64[0];
        *(int *)(param_1 + 0x29c) = local_7c[0];
        *(int *)(param_1 + 0x294) = local_64[1];
        *(int *)(param_1 + 0x2a0) = local_7c[1];
        *(int *)(param_1 + 0x290) = local_64[2];
        *(int *)(param_1 + 0x2a4) = local_7c[2];
        *(int *)(param_1 + 0x298) = local_64[3];
        *(int *)(param_1 + 0x2a8) = local_7c[3];
      }
      if ((*(char *)(param_1 + 0x265) == '\0') &&
         ((*(int *)(param_1 + 0x1b8) != *(int *)(param_1 + 0x1bc) ||
          (*(int *)(param_1 + 0x1b8) % 0xe10 != 0)))) {
        if (*(int *)(param_1 + 0x1b0) == -1) {
          if (*(short *)(param_1 + 0x268) < 3) {
            uVar3 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x27c) = uVar3;
            uVar3 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x284) = uVar3;
            uVar3 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x280) = uVar3;
            uVar3 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x288) = uVar3;
          }
          else if (2 < *(short *)(param_1 + 0x268)) {
            uVar3 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x27c) = uVar3;
            uVar3 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x284) = uVar3;
            uVar3 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x280) = uVar3;
            uVar3 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x288) = uVar3;
          }
        }
        else if (*(short *)(param_1 + 0x268) < 3) {
          uVar3 = FUN_004fe844();
          *(undefined4 *)(param_1 + 0x27c) = uVar3;
          uVar3 = FUN_004fe844();
          *(undefined4 *)(param_1 + 0x284) = uVar3;
          uVar3 = FUN_004fe844();
          *(undefined4 *)(param_1 + 0x280) = uVar3;
          if (*(short *)(param_1 + 0x268) == 1) {
            uVar3 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x288) = uVar3;
          }
          else {
            if (*(short *)(param_1 + 0x268) == 2) {
              local_768 = *(int *)(param_1 + 400) -
                          ((*(int *)(param_1 + 400) - *(int *)(param_1 + 0x194)) *
                          *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4);
            }
            else {
              local_768 = FUN_004fe844();
            }
            *(int *)(param_1 + 0x288) = local_768;
          }
        }
        else if (2 < *(short *)(param_1 + 0x268)) {
          uVar3 = FUN_004fe844();
          *(undefined4 *)(param_1 + 0x27c) = uVar3;
          uVar3 = FUN_004fe844();
          *(undefined4 *)(param_1 + 0x284) = uVar3;
          *(int *)(param_1 + 0x280) =
               *(int *)(param_1 + 0x188) -
               ((*(int *)(param_1 + 0x188) - *(int *)(param_1 + 0x18c)) * *(int *)(param_1 + 0x1b0))
               / *(int *)(param_1 + 0x1b4);
          if (*(short *)(param_1 + 0x268) == 4) {
            local_7a8 = *(int *)(param_1 + 400) -
                        ((*(int *)(param_1 + 400) - *(int *)(param_1 + 0x194)) *
                        *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4);
          }
          else {
            local_7a8 = FUN_004fe844();
          }
          *(int *)(param_1 + 0x288) = local_7a8;
        }
        *(int *)(param_1 + 0x27c) = *(int *)(param_1 + 0x27c) + local_6c;
        *(int *)(param_1 + 0x280) = *(int *)(param_1 + 0x280) + local_6c;
        *(int *)(param_1 + 0x284) = *(int *)(param_1 + 0x284) + local_20;
        *(int *)(param_1 + 0x288) = *(int *)(param_1 + 0x288) + local_20;
      }
      else {
        *(int *)(param_1 + 0x27c) = local_54;
        *(int *)(param_1 + 0x280) = local_18;
        *(int *)(param_1 + 0x284) = local_2c;
        *(int *)(param_1 + 0x288) = local_14;
      }
    }
    else {
      *(float *)(param_1 + 0x5c) =
           ((*(float *)(param_1 + 0x5c) - (float)(local_1c * DAT_0084b248)) *
           (float)(local_30 + -100)) / _DAT_007d1038 + *(float *)(param_1 + 0x5c);
      *(float *)(param_1 + 0x60) =
           ((*(float *)(param_1 + 0x60) - (float)(local_34 * DAT_0084b248)) *
           (float)(local_30 + -100)) / _DAT_007d1038 + *(float *)(param_1 + 0x60);
      *(float *)(param_1 + 0x5c) = (float)(local_6c * DAT_0084b248) + *(float *)(param_1 + 0x5c);
      *(float *)(param_1 + 0x60) = (float)(local_20 * DAT_0084b248) + *(float *)(param_1 + 0x60);
      uVar3 = FUN_004fe844();
      *(undefined4 *)(param_1 + 0x27c) = uVar3;
      uVar3 = FUN_004fe844();
      *(undefined4 *)(param_1 + 0x280) = uVar3;
      uVar3 = FUN_004fe844();
      *(undefined4 *)(param_1 + 0x284) = uVar3;
      uVar3 = FUN_004fe844();
      *(undefined4 *)(param_1 + 0x288) = uVar3;
    }
    local_28 = *(int *)(param_1 + 0x198);
    local_24 = *(undefined4 *)(param_1 + 0x19c);
    if ((*(char *)(param_1 + 0x264) == '\0') && (*(char *)(param_1 + 0x265) == '\0')) {
      if (0 < *(int *)(param_1 + 0x350)) {
        local_28 = *(int *)(param_1 + 0x358);
      }
      if (local_28 < 1) {
        return;
      }
    }
    if (*(int *)(param_1 + 0x1b0) < 0) {
      local_7bc = 0;
    }
    else {
      local_7bc = *(int *)(param_1 + 0x1b0);
    }
    if (*(int *)(param_1 + 0x1b4) < 1) {
      local_7c0 = 1;
    }
    else {
      local_7c0 = *(int *)(param_1 + 0x1b4);
    }
    if ((0 < ((*(int *)(param_1 + 0x1a4) - *(int *)(param_1 + 0x1a0)) * local_7bc) / local_7c0 +
             *(int *)(param_1 + 0x1a0)) && (param_2 != '\0')) {
      if ((*(char *)(param_1 + 0x278) != '\0') && (*(char *)(param_1 + 0x279) == '\0')) {
        uVar3 = FUN_004fe844();
        FUN_005160d0(*(undefined4 *)(&DAT_0084b250 + *(int *)(param_1 + 0x1a8) * 4),uVar3);
        iVar2 = FUN_004fe844();
        if (iVar2 + 0xff < 0x100) {
          FUN_004fe844();
        }
        iVar2 = FUN_004fe844();
        if (iVar2 + 0xff < 0x100) {
          FUN_004fe844();
        }
        iVar2 = FUN_004fe844();
        if (iVar2 + 0xff < 0x100) {
          FUN_004fe844();
        }
        FUN_005161e0();
        for (local_168 = 0; local_168 < 2; local_168 = local_168 + 1) {
          if ((*(char *)(param_1 + 0x264) == '\0') && (*(char *)(param_1 + 0x265) == '\0')) {
            if ((*(int *)(param_1 + 0x1b8) == *(int *)(param_1 + 0x1bc)) &&
               (*(int *)(param_1 + 0x1b8) % 0xe10 == 0)) {
              puVar4 = (undefined4 *)FUN_004ce990(local_28 + -1);
              FUN_0051f060(local_54 * DAT_0084b248,local_2c * DAT_0084b248,local_18 * DAT_0084b248,
                           local_14 * DAT_0084b248,*puVar4);
            }
            else {
              FUN_004ce990(local_28 + -1);
              FUN_0051f8e0(local_54 * DAT_0084b248,local_2c * DAT_0084b248);
            }
          }
          else {
            if (*(char *)(param_1 + 0x265) != '\0') break;
            FUN_00494480();
          }
          if (local_168 == 1) {
            return;
          }
          if (((((*(int *)(param_1 + 0x1e0) < 1) && (*(int *)(param_1 + 0x1ec) < 1)) &&
               (*(int *)(param_1 + 0x1e4) < 1)) &&
              ((*(int *)(param_1 + 0x1f0) < 1 && (*(int *)(param_1 + 0x1e8) < 1)))) &&
             (*(int *)(param_1 + 500) < 1)) {
            return;
          }
          iVar2 = FUN_004fe844();
          if (-1 < iVar2) {
            FUN_004fe844();
          }
          iVar2 = FUN_004fe844();
          if (-1 < iVar2) {
            FUN_004fe844();
          }
          iVar2 = FUN_004fe844();
          if (-1 < iVar2) {
            FUN_004fe844();
          }
          FUN_005161e0();
          FUN_004fe844();
          FUN_005160d0();
        }
      }
      if (*(int *)(param_1 + 0x1b0) == -1) {
        if ((*(int *)(param_1 + 0x1a0) == 0xff) && (*(int *)(param_1 + 0x1a8) == 0)) {
          FUN_005160d0(0,0xff);
        }
        else {
          FUN_005160d0(*(undefined4 *)(&DAT_0084b250 + *(int *)(param_1 + 0x1a8) * 4),
                       *(undefined4 *)(param_1 + 0x1a0));
        }
        FUN_005161e0();
        for (local_1f8 = 0; iVar2 = DAT_0084b248, local_1f8 < 2; local_1f8 = local_1f8 + 1) {
          if (*(int *)(param_1 + 0x1a0) != 0) {
            if ((*(char *)(param_1 + 0x264) == '\0') && (*(char *)(param_1 + 0x265) == '\0')) {
              if (*(char *)(param_1 + 0x240) == '\0') {
                if ((*(int *)(param_1 + 0x1b8) == *(int *)(param_1 + 0x1bc)) &&
                   (*(int *)(param_1 + 0x1b8) % 0xe10 == 0)) {
                  puVar4 = (undefined4 *)FUN_004ce990(local_28 + -1);
                  FUN_0051f060(local_54 * DAT_0084b248,local_2c * DAT_0084b248,
                               local_18 * DAT_0084b248,local_14 * DAT_0084b248,*puVar4);
                }
                else {
                  FUN_004ce990(local_28 + -1);
                  FUN_0051f8e0(local_54 * DAT_0084b248,local_2c * DAT_0084b248);
                }
              }
              else {
                FUN_004ce990(local_28 + -1);
                FUN_005205f0(local_64[0] * DAT_0084b248,local_7c[0] * DAT_0084b248);
              }
            }
            else if (*(char *)(param_1 + 0x265) == '\0') {
              FUN_00494480();
            }
            else {
              local_224 = local_54 * DAT_0084b248;
              iVar9 = local_18 * DAT_0084b248;
              local_268 = local_2c * DAT_0084b248;
              iVar5 = local_14 * DAT_0084b248;
              if (*(int *)(param_1 + 0x37c) < 0) {
                puVar4 = (undefined4 *)FUN_004ce990(0);
                FUN_0051f060(local_54 * DAT_0084b248,local_2c * DAT_0084b248,
                             (local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,*puVar4);
                puVar4 = (undefined4 *)FUN_004ce990(2);
                FUN_0051f060((local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             local_2c * DAT_0084b248,local_18 * DAT_0084b248,
                             (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,*puVar4);
                puVar4 = (undefined4 *)FUN_004ce990(6);
                FUN_0051f060(local_54 * DAT_0084b248,
                             (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                             (local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             local_14 * DAT_0084b248,*puVar4);
                puVar4 = (undefined4 *)FUN_004ce990(8);
                FUN_0051f060((local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                             local_18 * DAT_0084b248,local_14 * DAT_0084b248,*puVar4);
                if (*(char *)(param_1 + 0x267) == '\0') {
                  puVar4 = (undefined4 *)FUN_004ce990(3);
                  FUN_0051f060(local_54 * DAT_0084b248,
                               (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                               (local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                               (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,*puVar4);
                  puVar4 = (undefined4 *)FUN_004ce990(5);
                  FUN_0051f060((local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                               (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                               local_18 * DAT_0084b248,
                               (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,*puVar4);
                  puVar4 = (undefined4 *)FUN_004ce990(1);
                  FUN_0051f060((local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                               local_2c * DAT_0084b248,
                               (local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                               (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,*puVar4);
                  FUN_004ce990(4);
                  FUN_0051f060();
                  puVar4 = (undefined4 *)FUN_004ce990(7);
                  FUN_0051f060((local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                               (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                               (local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                               local_14 * DAT_0084b248,*puVar4);
                }
                else {
                  dVar1 = ((double)(*(int *)(param_1 + 0x1b8) +
                                   ((*(int *)(param_1 + 0x1bc) - *(int *)(param_1 + 0x1b8)) *
                                   *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4)) /
                          _DAT_007d1020) * _DAT_007d1028;
                  puVar4 = (undefined4 *)FUN_004ce990(3);
                  FUN_00526aa0(local_54 * DAT_0084b248,
                               (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                               (local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                               (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,0,
                               (((local_14 - local_2c) - *(int *)(param_1 + 0x1c8)) %
                               (*(int *)(param_1 + 0x1c8) << 1)) / 2,(double)DAT_0084b248,
                               _DAT_007d0a60,*puVar4);
                  puVar4 = (undefined4 *)FUN_004ce990(5);
                  FUN_00526aa0((local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                               (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                               local_18 * DAT_0084b248,
                               (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,0,
                               (((local_14 - local_2c) - *(int *)(param_1 + 0x1c8)) %
                               (*(int *)(param_1 + 0x1c8) << 1)) / 2,(double)DAT_0084b248,
                               _DAT_007d0a60,*puVar4);
                  puVar4 = (undefined4 *)FUN_004ce990(1);
                  FUN_00526aa0((local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                               local_2c * DAT_0084b248,
                               (local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                               (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                               (((local_18 - local_54) - *(int *)(param_1 + 0x1c0)) %
                               (*(int *)(param_1 + 0x1c0) << 1)) / 2,0,(double)DAT_0084b248,
                               _DAT_007d0a60,*puVar4);
                  puVar4 = (undefined4 *)FUN_004ce990(4);
                  FUN_00526aa0((local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                               (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                               (local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                               (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                               (((local_18 - local_54) - *(int *)(param_1 + 0x1c0)) %
                               (*(int *)(param_1 + 0x1c0) << 1)) / 2,
                               (((local_14 - local_2c) - *(int *)(param_1 + 0x1c8)) %
                               (*(int *)(param_1 + 0x1c8) << 1)) / 2,(double)DAT_0084b248,dVar1,
                               *puVar4);
                  FUN_004ce990(7);
                  FUN_00526aa0((local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                               (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                               (local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                               local_14 * DAT_0084b248);
                }
              }
              else {
                switch(*(undefined4 *)(param_1 + 0x37c)) {
                case 0:
                  uVar3 = FUN_00543f70(0xff,0xff,0xff);
                  FUN_00526390(local_224,local_268,iVar9,iVar5,uVar3);
                  break;
                case 1:
                  uVar3 = FUN_00543f70(0xff,0xff,0xff);
                  FUN_005287d0(local_224,local_268,iVar9,iVar5,uVar3);
                  break;
                case 2:
                  uVar10 = CONCAT44(1,*(undefined4 *)(param_1 + 900));
                  uVar3 = FUN_00543f70();
                  FUN_004febf1(iVar5 - local_268,uVar3,uVar10);
                  FUN_004febf1();
                  FUN_0051e100();
                  break;
                case 3:
                  switch(*(undefined4 *)(param_1 + 0x380)) {
                  case 1:
                    FUN_00543f70(0xff,0xff,0xff,*(undefined4 *)(param_1 + 900));
                    FUN_0051e5d0();
                    break;
                  case 2:
                    FUN_00543f70(0xff,0xff,0xff,*(undefined4 *)(param_1 + 900));
                    FUN_0051e5d0();
                    break;
                  case 3:
                    FUN_00543f70(0xff,0xff,0xff,*(undefined4 *)(param_1 + 900));
                    FUN_0051e5d0();
                    break;
                  case 4:
                    FUN_00543f70(0xff,0xff,0xff,*(undefined4 *)(param_1 + 900));
                    FUN_0051e5d0();
                  }
                  break;
                case 4:
                  if (((*(int *)(param_1 + 0x380) % 1000) / 100) * 0x1d < 0x100) {
                    local_9dc = ((*(int *)(param_1 + 0x380) % 1000) / 100) * 0x1d;
                  }
                  else {
                    local_9dc = 0xff;
                  }
                  if (local_9dc < 0) {
                    local_9e0 = 0;
                  }
                  else {
                    if (((*(int *)(param_1 + 0x380) % 1000) / 100) * 0x1d < 0x100) {
                      local_9e4 = ((*(int *)(param_1 + 0x380) % 1000) / 100) * 0x1d;
                    }
                    else {
                      local_9e4 = 0xff;
                    }
                    local_9e0 = local_9e4;
                  }
                  if (((*(int *)(param_1 + 0x380) % 100) / 10) * 0x1d < 0x100) {
                    local_9e8 = ((*(int *)(param_1 + 0x380) % 100) / 10) * 0x1d;
                  }
                  else {
                    local_9e8 = 0xff;
                  }
                  if (local_9e8 < 0) {
                    local_9ec = 0;
                  }
                  else {
                    if (((*(int *)(param_1 + 0x380) % 100) / 10) * 0x1d < 0x100) {
                      local_9f0 = ((*(int *)(param_1 + 0x380) % 100) / 10) * 0x1d;
                    }
                    else {
                      local_9f0 = 0xff;
                    }
                    local_9ec = local_9f0;
                  }
                  if ((*(int *)(param_1 + 0x380) % 10) * 0x1d < 0x100) {
                    local_9f4 = (*(int *)(param_1 + 0x380) % 10) * 0x1d;
                  }
                  else {
                    local_9f4 = 0xff;
                  }
                  if (local_9f4 < 0) {
                    local_9f8 = 0;
                  }
                  else {
                    if ((*(int *)(param_1 + 0x380) % 10) * 0x1d < 0x100) {
                      local_9fc = (*(int *)(param_1 + 0x380) % 10) * 0x1d;
                    }
                    else {
                      local_9fc = 0xff;
                    }
                    local_9f8 = local_9fc;
                  }
                  if (((*(int *)(param_1 + 0x380) % 1000000) / 100000) * 0x1d < 0x100) {
                    local_a00 = ((*(int *)(param_1 + 0x380) % 1000000) / 100000) * 0x1d;
                  }
                  else {
                    local_a00 = 0xff;
                  }
                  if (local_a00 < 0) {
                    local_a04 = 0;
                  }
                  else {
                    if (((*(int *)(param_1 + 0x380) % 1000000) / 100000) * 0x1d < 0x100) {
                      local_a08 = ((*(int *)(param_1 + 0x380) % 1000000) / 100000) * 0x1d;
                    }
                    else {
                      local_a08 = 0xff;
                    }
                    local_a04 = local_a08;
                  }
                  if (((*(int *)(param_1 + 0x380) % 100000) / 10000) * 0x1d < 0x100) {
                    local_a0c = ((*(int *)(param_1 + 0x380) % 100000) / 10000) * 0x1d;
                  }
                  else {
                    local_a0c = 0xff;
                  }
                  if (local_a0c < 0) {
                    local_a10 = 0;
                  }
                  else {
                    if (((*(int *)(param_1 + 0x380) % 100000) / 10000) * 0x1d < 0x100) {
                      local_a14 = ((*(int *)(param_1 + 0x380) % 100000) / 10000) * 0x1d;
                    }
                    else {
                      local_a14 = 0xff;
                    }
                    local_a10 = local_a14;
                  }
                  if (((*(int *)(param_1 + 0x380) % 10000) / 1000) * 0x1d < 0x100) {
                    local_a18 = ((*(int *)(param_1 + 0x380) % 10000) / 1000) * 0x1d;
                  }
                  else {
                    local_a18 = 0xff;
                  }
                  if (local_a18 < 0) {
                    local_a1c = 0;
                  }
                  else {
                    if (((*(int *)(param_1 + 0x380) % 10000) / 1000) * 0x1d < 0x100) {
                      local_a20 = ((*(int *)(param_1 + 0x380) % 10000) / 1000) * 0x1d;
                    }
                    else {
                      local_a20 = 0xff;
                    }
                    local_a1c = local_a20;
                  }
                  iVar6 = FUN_004febf1();
                  iVar6 = iVar6 / iVar2;
                  for (local_248 = 0; local_248 < iVar6; local_248 = local_248 + 1) {
                    FUN_00543f70(local_a04 - ((local_a04 - local_9e0) * local_248) / iVar6,
                                 local_a10 - ((local_a10 - local_9ec) * local_248) / iVar6,
                                 local_a1c - ((local_a1c - local_9f8) * local_248) / iVar6,1);
                    FUN_00526390();
                    local_224 = local_224 + iVar2;
                  }
                  uVar3 = FUN_00543f70(local_9e0,local_9ec,local_9f8,1);
                  FUN_00526390(local_224,local_268,iVar9,iVar5,uVar3);
                  break;
                case 5:
                  if (((*(int *)(param_1 + 0x380) % 1000) / 100) * 0x1d < 0x100) {
                    local_a24 = ((*(int *)(param_1 + 0x380) % 1000) / 100) * 0x1d;
                  }
                  else {
                    local_a24 = 0xff;
                  }
                  if (local_a24 < 0) {
                    local_a28 = 0;
                  }
                  else {
                    if (((*(int *)(param_1 + 0x380) % 1000) / 100) * 0x1d < 0x100) {
                      local_a2c = ((*(int *)(param_1 + 0x380) % 1000) / 100) * 0x1d;
                    }
                    else {
                      local_a2c = 0xff;
                    }
                    local_a28 = local_a2c;
                  }
                  if (((*(int *)(param_1 + 0x380) % 100) / 10) * 0x1d < 0x100) {
                    local_a30 = ((*(int *)(param_1 + 0x380) % 100) / 10) * 0x1d;
                  }
                  else {
                    local_a30 = 0xff;
                  }
                  if (local_a30 < 0) {
                    local_a34 = 0;
                  }
                  else {
                    if (((*(int *)(param_1 + 0x380) % 100) / 10) * 0x1d < 0x100) {
                      local_a38 = ((*(int *)(param_1 + 0x380) % 100) / 10) * 0x1d;
                    }
                    else {
                      local_a38 = 0xff;
                    }
                    local_a34 = local_a38;
                  }
                  if ((*(int *)(param_1 + 0x380) % 10) * 0x1d < 0x100) {
                    local_a3c = (*(int *)(param_1 + 0x380) % 10) * 0x1d;
                  }
                  else {
                    local_a3c = 0xff;
                  }
                  if (local_a3c < 0) {
                    local_a40 = 0;
                  }
                  else {
                    if ((*(int *)(param_1 + 0x380) % 10) * 0x1d < 0x100) {
                      local_a44 = (*(int *)(param_1 + 0x380) % 10) * 0x1d;
                    }
                    else {
                      local_a44 = 0xff;
                    }
                    local_a40 = local_a44;
                  }
                  if (((*(int *)(param_1 + 0x380) % 1000000) / 100000) * 0x1d < 0x100) {
                    local_a48 = ((*(int *)(param_1 + 0x380) % 1000000) / 100000) * 0x1d;
                  }
                  else {
                    local_a48 = 0xff;
                  }
                  if (local_a48 < 0) {
                    local_a4c = 0;
                  }
                  else {
                    if (((*(int *)(param_1 + 0x380) % 1000000) / 100000) * 0x1d < 0x100) {
                      local_a50 = ((*(int *)(param_1 + 0x380) % 1000000) / 100000) * 0x1d;
                    }
                    else {
                      local_a50 = 0xff;
                    }
                    local_a4c = local_a50;
                  }
                  if (((*(int *)(param_1 + 0x380) % 100000) / 10000) * 0x1d < 0x100) {
                    local_a54 = ((*(int *)(param_1 + 0x380) % 100000) / 10000) * 0x1d;
                  }
                  else {
                    local_a54 = 0xff;
                  }
                  if (local_a54 < 0) {
                    local_a58 = 0;
                  }
                  else {
                    if (((*(int *)(param_1 + 0x380) % 100000) / 10000) * 0x1d < 0x100) {
                      local_a5c = ((*(int *)(param_1 + 0x380) % 100000) / 10000) * 0x1d;
                    }
                    else {
                      local_a5c = 0xff;
                    }
                    local_a58 = local_a5c;
                  }
                  if (((*(int *)(param_1 + 0x380) % 10000) / 1000) * 0x1d < 0x100) {
                    local_a60 = ((*(int *)(param_1 + 0x380) % 10000) / 1000) * 0x1d;
                  }
                  else {
                    local_a60 = 0xff;
                  }
                  if (local_a60 < 0) {
                    local_a64 = 0;
                  }
                  else {
                    if (((*(int *)(param_1 + 0x380) % 10000) / 1000) * 0x1d < 0x100) {
                      local_a68 = ((*(int *)(param_1 + 0x380) % 10000) / 1000) * 0x1d;
                    }
                    else {
                      local_a68 = 0xff;
                    }
                    local_a64 = local_a68;
                  }
                  iVar6 = FUN_004febf1();
                  iVar6 = iVar6 / iVar2;
                  for (local_270 = 0; local_270 < iVar6; local_270 = local_270 + 1) {
                    FUN_00543f70(local_a4c - ((local_a4c - local_a28) * local_270) / iVar6,
                                 local_a58 - ((local_a58 - local_a34) * local_270) / iVar6,
                                 local_a64 - ((local_a64 - local_a40) * local_270) / iVar6,1);
                    FUN_00526390();
                    local_268 = local_268 + iVar2;
                  }
                  uVar3 = FUN_00543f70(local_a28,local_a34,local_a40,1);
                  FUN_00526390(local_224,local_268,iVar9,iVar5,uVar3);
                }
              }
            }
            if (((*(int *)(param_1 + 0x1e0) + local_50 < 1) &&
                (*(int *)(param_1 + 0x1e4) + local_4c < 1)) &&
               (*(int *)(param_1 + 0x1e8) + local_48 < 1)) break;
            FUN_005161e0();
            FUN_005160d0();
          }
        }
      }
      else {
        uVar3 = FUN_004fe844();
        FUN_005160d0(*(undefined4 *)(&DAT_0084b250 + *(int *)(param_1 + 0x1a8) * 4),uVar3);
        if (((*(char *)(param_1 + 0x278) != '\0') && (*(char *)(param_1 + 0x279) == '\0')) &&
           (*(char *)(param_1 + 0x265) != '\0')) {
          uVar3 = FUN_004fe844();
          FUN_005160d0(*(undefined4 *)(&DAT_0084b250 + *(int *)(param_1 + 0x1a8) * 4),uVar3);
        }
        iVar2 = FUN_004fe844();
        if (local_48 + 0xff + iVar2 < 0x100) {
          FUN_004fe844();
        }
        iVar2 = FUN_004fe844();
        if (local_4c + 0xff + iVar2 < 0x100) {
          FUN_004fe844();
        }
        iVar2 = FUN_004fe844();
        if (local_50 + 0xff + iVar2 < 0x100) {
          FUN_004fe844();
        }
        FUN_005161e0();
        for (local_174 = 0; iVar2 = DAT_0084b248, local_174 < 2; local_174 = local_174 + 1) {
          if ((*(char *)(param_1 + 0x264) == '\0') && (*(char *)(param_1 + 0x265) == '\0')) {
            if (*(char *)(param_1 + 0x240) == '\0') {
              if ((*(int *)(param_1 + 0x1b8) == *(int *)(param_1 + 0x1bc)) &&
                 (*(int *)(param_1 + 0x1b8) % 0xe10 == 0)) {
                puVar4 = (undefined4 *)FUN_004ce990(local_28 + -1);
                FUN_0051f060(local_54 * DAT_0084b248,local_2c * DAT_0084b248,local_18 * DAT_0084b248
                             ,local_14 * DAT_0084b248,*puVar4);
              }
              else {
                FUN_004ce990(local_28 + -1);
                FUN_0051f8e0(local_54 * DAT_0084b248,local_2c * DAT_0084b248);
              }
            }
            else {
              FUN_004ce990(local_28 + -1);
              FUN_005205f0(local_64[0] * DAT_0084b248,local_7c[0] * DAT_0084b248);
            }
          }
          else if (*(char *)(param_1 + 0x265) == '\0') {
            FUN_00494480();
          }
          else {
            local_1a0 = local_54 * DAT_0084b248;
            iVar5 = local_18 * DAT_0084b248;
            local_1e4 = local_2c * DAT_0084b248;
            iVar9 = local_14 * DAT_0084b248;
            if (*(int *)(param_1 + 0x37c) < 0) {
              puVar4 = (undefined4 *)FUN_004ce990(0);
              FUN_0051f060(local_54 * DAT_0084b248,local_2c * DAT_0084b248,
                           (local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                           (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,*puVar4);
              puVar4 = (undefined4 *)FUN_004ce990(2);
              FUN_0051f060((local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                           local_2c * DAT_0084b248,local_18 * DAT_0084b248,
                           (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,*puVar4);
              puVar4 = (undefined4 *)FUN_004ce990(6);
              FUN_0051f060(local_54 * DAT_0084b248,
                           (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                           (local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                           local_14 * DAT_0084b248,*puVar4);
              puVar4 = (undefined4 *)FUN_004ce990(8);
              FUN_0051f060((local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                           (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                           local_18 * DAT_0084b248,local_14 * DAT_0084b248,*puVar4);
              if (*(char *)(param_1 + 0x267) == '\0') {
                puVar4 = (undefined4 *)FUN_004ce990(3);
                FUN_0051f060(local_54 * DAT_0084b248,
                             (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                             (local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,*puVar4);
                puVar4 = (undefined4 *)FUN_004ce990(5);
                FUN_0051f060((local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                             local_18 * DAT_0084b248,
                             (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,*puVar4);
                puVar4 = (undefined4 *)FUN_004ce990(1);
                FUN_0051f060((local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             local_2c * DAT_0084b248,
                             (local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,*puVar4);
                FUN_004ce990(4);
                FUN_0051f060();
                puVar4 = (undefined4 *)FUN_004ce990(7);
                FUN_0051f060((local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                             (local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             local_14 * DAT_0084b248,*puVar4);
              }
              else {
                dVar1 = ((double)(*(int *)(param_1 + 0x1b8) +
                                 ((*(int *)(param_1 + 0x1bc) - *(int *)(param_1 + 0x1b8)) *
                                 *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4)) /
                        _DAT_007d1020) * _DAT_007d1028;
                puVar4 = (undefined4 *)FUN_004ce990(3);
                FUN_00526aa0(local_54 * DAT_0084b248,
                             (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                             (local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,0,
                             (((local_14 - local_2c) - *(int *)(param_1 + 0x1c8)) %
                             (*(int *)(param_1 + 0x1c8) << 1)) / 2,(double)DAT_0084b248,
                             _DAT_007d0a60,*puVar4);
                puVar4 = (undefined4 *)FUN_004ce990(5);
                FUN_00526aa0((local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                             local_18 * DAT_0084b248,
                             (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,0,
                             (((local_14 - local_2c) - *(int *)(param_1 + 0x1c8)) %
                             (*(int *)(param_1 + 0x1c8) << 1)) / 2,(double)DAT_0084b248,
                             _DAT_007d0a60,*puVar4);
                puVar4 = (undefined4 *)FUN_004ce990(1);
                FUN_00526aa0((local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             local_2c * DAT_0084b248,
                             (local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                             (((local_18 - local_54) - *(int *)(param_1 + 0x1c0)) %
                             (*(int *)(param_1 + 0x1c0) << 1)) / 2,0,(double)DAT_0084b248,
                             _DAT_007d0a60,*puVar4);
                puVar4 = (undefined4 *)FUN_004ce990(4);
                FUN_00526aa0((local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             (local_2c + *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                             (local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                             (((local_18 - local_54) - *(int *)(param_1 + 0x1c0)) %
                             (*(int *)(param_1 + 0x1c0) << 1)) / 2,
                             (((local_14 - local_2c) - *(int *)(param_1 + 0x1c8)) %
                             (*(int *)(param_1 + 0x1c8) << 1)) / 2,(double)DAT_0084b248,dVar1,
                             *puVar4);
                FUN_004ce990(7);
                FUN_00526aa0((local_54 + *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             (local_14 - *(int *)(param_1 + 0x1c8)) * DAT_0084b248,
                             (local_18 - *(int *)(param_1 + 0x1c0)) * DAT_0084b248,
                             local_14 * DAT_0084b248);
              }
            }
            else {
              switch(*(undefined4 *)(param_1 + 0x37c)) {
              case 0:
                uVar3 = FUN_00543f70(0xff,0xff,0xff);
                FUN_00526390(local_1a0,local_1e4,iVar5,iVar9,uVar3);
                break;
              case 1:
                uVar3 = FUN_00543f70(0xff,0xff,0xff);
                FUN_005287d0(local_1a0,local_1e4,iVar5,iVar9,uVar3);
                break;
              case 2:
                uVar10 = CONCAT44(1,*(undefined4 *)(param_1 + 900));
                uVar3 = FUN_00543f70();
                FUN_004febf1(iVar9 - local_1e4,uVar3,uVar10);
                FUN_004febf1();
                FUN_0051e100();
                break;
              case 3:
                switch(*(undefined4 *)(param_1 + 0x380)) {
                case 1:
                  FUN_00543f70(0xff,0xff,0xff,*(undefined4 *)(param_1 + 900));
                  FUN_0051e5d0();
                  break;
                case 2:
                  FUN_00543f70(0xff,0xff,0xff,*(undefined4 *)(param_1 + 900));
                  FUN_0051e5d0();
                  break;
                case 3:
                  FUN_00543f70(0xff,0xff,0xff,*(undefined4 *)(param_1 + 900));
                  FUN_0051e5d0();
                  break;
                case 4:
                  FUN_00543f70(0xff,0xff,0xff,*(undefined4 *)(param_1 + 900));
                  FUN_0051e5d0();
                }
                break;
              case 4:
                if (((*(int *)(param_1 + 0x380) % 1000) / 100) * 0x1d < 0x100) {
                  local_8e8 = ((*(int *)(param_1 + 0x380) % 1000) / 100) * 0x1d;
                }
                else {
                  local_8e8 = 0xff;
                }
                if (local_8e8 < 0) {
                  local_8ec = 0;
                }
                else {
                  if (((*(int *)(param_1 + 0x380) % 1000) / 100) * 0x1d < 0x100) {
                    local_8f0 = ((*(int *)(param_1 + 0x380) % 1000) / 100) * 0x1d;
                  }
                  else {
                    local_8f0 = 0xff;
                  }
                  local_8ec = local_8f0;
                }
                if (((*(int *)(param_1 + 0x380) % 100) / 10) * 0x1d < 0x100) {
                  local_8f4 = ((*(int *)(param_1 + 0x380) % 100) / 10) * 0x1d;
                }
                else {
                  local_8f4 = 0xff;
                }
                if (local_8f4 < 0) {
                  local_8f8 = 0;
                }
                else {
                  if (((*(int *)(param_1 + 0x380) % 100) / 10) * 0x1d < 0x100) {
                    local_8fc = ((*(int *)(param_1 + 0x380) % 100) / 10) * 0x1d;
                  }
                  else {
                    local_8fc = 0xff;
                  }
                  local_8f8 = local_8fc;
                }
                if ((*(int *)(param_1 + 0x380) % 10) * 0x1d < 0x100) {
                  local_900 = (*(int *)(param_1 + 0x380) % 10) * 0x1d;
                }
                else {
                  local_900 = 0xff;
                }
                if (local_900 < 0) {
                  local_904 = 0;
                }
                else {
                  if ((*(int *)(param_1 + 0x380) % 10) * 0x1d < 0x100) {
                    local_908 = (*(int *)(param_1 + 0x380) % 10) * 0x1d;
                  }
                  else {
                    local_908 = 0xff;
                  }
                  local_904 = local_908;
                }
                if (((*(int *)(param_1 + 0x380) % 1000000) / 100000) * 0x1d < 0x100) {
                  local_90c = ((*(int *)(param_1 + 0x380) % 1000000) / 100000) * 0x1d;
                }
                else {
                  local_90c = 0xff;
                }
                if (local_90c < 0) {
                  local_910 = 0;
                }
                else {
                  if (((*(int *)(param_1 + 0x380) % 1000000) / 100000) * 0x1d < 0x100) {
                    local_914 = ((*(int *)(param_1 + 0x380) % 1000000) / 100000) * 0x1d;
                  }
                  else {
                    local_914 = 0xff;
                  }
                  local_910 = local_914;
                }
                if (((*(int *)(param_1 + 0x380) % 100000) / 10000) * 0x1d < 0x100) {
                  local_918 = ((*(int *)(param_1 + 0x380) % 100000) / 10000) * 0x1d;
                }
                else {
                  local_918 = 0xff;
                }
                if (local_918 < 0) {
                  local_91c = 0;
                }
                else {
                  if (((*(int *)(param_1 + 0x380) % 100000) / 10000) * 0x1d < 0x100) {
                    local_920 = ((*(int *)(param_1 + 0x380) % 100000) / 10000) * 0x1d;
                  }
                  else {
                    local_920 = 0xff;
                  }
                  local_91c = local_920;
                }
                if (((*(int *)(param_1 + 0x380) % 10000) / 1000) * 0x1d < 0x100) {
                  local_924 = ((*(int *)(param_1 + 0x380) % 10000) / 1000) * 0x1d;
                }
                else {
                  local_924 = 0xff;
                }
                if (local_924 < 0) {
                  local_928 = 0;
                }
                else {
                  if (((*(int *)(param_1 + 0x380) % 10000) / 1000) * 0x1d < 0x100) {
                    local_92c = ((*(int *)(param_1 + 0x380) % 10000) / 1000) * 0x1d;
                  }
                  else {
                    local_92c = 0xff;
                  }
                  local_928 = local_92c;
                }
                iVar6 = FUN_004febf1();
                iVar6 = iVar6 / iVar2;
                for (local_1c4 = 0; local_1c4 < iVar6; local_1c4 = local_1c4 + 1) {
                  FUN_00543f70(local_910 - ((local_910 - local_8ec) * local_1c4) / iVar6,
                               local_91c - ((local_91c - local_8f8) * local_1c4) / iVar6,
                               local_928 - ((local_928 - local_904) * local_1c4) / iVar6,1);
                  FUN_00526390();
                  local_1a0 = local_1a0 + iVar2;
                }
                uVar3 = FUN_00543f70(local_8ec,local_8f8,local_904,1);
                FUN_00526390(local_1a0,local_1e4,iVar5,iVar9,uVar3);
                break;
              case 5:
                if (((*(int *)(param_1 + 0x380) % 1000) / 100) * 0x1d < 0x100) {
                  local_930 = ((*(int *)(param_1 + 0x380) % 1000) / 100) * 0x1d;
                }
                else {
                  local_930 = 0xff;
                }
                if (local_930 < 0) {
                  local_934 = 0;
                }
                else {
                  if (((*(int *)(param_1 + 0x380) % 1000) / 100) * 0x1d < 0x100) {
                    local_938 = ((*(int *)(param_1 + 0x380) % 1000) / 100) * 0x1d;
                  }
                  else {
                    local_938 = 0xff;
                  }
                  local_934 = local_938;
                }
                if (((*(int *)(param_1 + 0x380) % 100) / 10) * 0x1d < 0x100) {
                  local_93c = ((*(int *)(param_1 + 0x380) % 100) / 10) * 0x1d;
                }
                else {
                  local_93c = 0xff;
                }
                if (local_93c < 0) {
                  local_940 = 0;
                }
                else {
                  if (((*(int *)(param_1 + 0x380) % 100) / 10) * 0x1d < 0x100) {
                    local_944 = ((*(int *)(param_1 + 0x380) % 100) / 10) * 0x1d;
                  }
                  else {
                    local_944 = 0xff;
                  }
                  local_940 = local_944;
                }
                if ((*(int *)(param_1 + 0x380) % 10) * 0x1d < 0x100) {
                  local_948 = (*(int *)(param_1 + 0x380) % 10) * 0x1d;
                }
                else {
                  local_948 = 0xff;
                }
                if (local_948 < 0) {
                  local_94c = 0;
                }
                else {
                  if ((*(int *)(param_1 + 0x380) % 10) * 0x1d < 0x100) {
                    local_950 = (*(int *)(param_1 + 0x380) % 10) * 0x1d;
                  }
                  else {
                    local_950 = 0xff;
                  }
                  local_94c = local_950;
                }
                if (((*(int *)(param_1 + 0x380) % 1000000) / 100000) * 0x1d < 0x100) {
                  local_954 = ((*(int *)(param_1 + 0x380) % 1000000) / 100000) * 0x1d;
                }
                else {
                  local_954 = 0xff;
                }
                if (local_954 < 0) {
                  local_958 = 0;
                }
                else {
                  if (((*(int *)(param_1 + 0x380) % 1000000) / 100000) * 0x1d < 0x100) {
                    local_95c = ((*(int *)(param_1 + 0x380) % 1000000) / 100000) * 0x1d;
                  }
                  else {
                    local_95c = 0xff;
                  }
                  local_958 = local_95c;
                }
                if (((*(int *)(param_1 + 0x380) % 100000) / 10000) * 0x1d < 0x100) {
                  local_960 = ((*(int *)(param_1 + 0x380) % 100000) / 10000) * 0x1d;
                }
                else {
                  local_960 = 0xff;
                }
                if (local_960 < 0) {
                  local_964 = 0;
                }
                else {
                  if (((*(int *)(param_1 + 0x380) % 100000) / 10000) * 0x1d < 0x100) {
                    local_968 = ((*(int *)(param_1 + 0x380) % 100000) / 10000) * 0x1d;
                  }
                  else {
                    local_968 = 0xff;
                  }
                  local_964 = local_968;
                }
                if (((*(int *)(param_1 + 0x380) % 10000) / 1000) * 0x1d < 0x100) {
                  local_96c = ((*(int *)(param_1 + 0x380) % 10000) / 1000) * 0x1d;
                }
                else {
                  local_96c = 0xff;
                }
                if (local_96c < 0) {
                  local_970 = 0;
                }
                else {
                  if (((*(int *)(param_1 + 0x380) % 10000) / 1000) * 0x1d < 0x100) {
                    local_974 = ((*(int *)(param_1 + 0x380) % 10000) / 1000) * 0x1d;
                  }
                  else {
                    local_974 = 0xff;
                  }
                  local_970 = local_974;
                }
                iVar6 = FUN_004febf1();
                iVar6 = iVar6 / iVar2;
                for (local_1ec = 0; local_1ec < iVar6; local_1ec = local_1ec + 1) {
                  FUN_00543f70(local_958 - ((local_958 - local_934) * local_1ec) / iVar6,
                               local_964 - ((local_964 - local_940) * local_1ec) / iVar6,
                               local_970 - ((local_970 - local_94c) * local_1ec) / iVar6,1);
                  FUN_00526390();
                  local_1e4 = local_1e4 + iVar2;
                }
                uVar3 = FUN_00543f70(local_934,local_940,local_94c,1);
                FUN_00526390(local_1a0,local_1e4,iVar5,iVar9,uVar3);
              }
            }
          }
          if ((((*(int *)(param_1 + 0x1e0) + local_50 < 1) &&
               (*(int *)(param_1 + 0x1ec) + local_50 < 1)) &&
              (*(int *)(param_1 + 0x1e4) + local_4c < 1)) &&
             (((*(int *)(param_1 + 0x1f0) + local_4c < 1 &&
               (*(int *)(param_1 + 0x1e8) + local_48 < 1)) &&
              (*(int *)(param_1 + 500) + local_48 < 1)))) break;
          iVar2 = FUN_004fe844();
          if (-1 < iVar2 + local_48) {
            FUN_004fe844();
          }
          iVar2 = FUN_004fe844();
          if (-1 < iVar2 + local_4c) {
            FUN_004fe844();
          }
          iVar2 = FUN_004fe844();
          if (-1 < iVar2 + local_50) {
            FUN_004fe844();
          }
          FUN_005161e0();
          FUN_004fe844();
          FUN_005160d0();
        }
      }
      FUN_005160d0(0,0xff);
      FUN_005161e0();
    }
  }
  return;
}

