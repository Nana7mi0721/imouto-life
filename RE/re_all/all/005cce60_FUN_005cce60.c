
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005cce60(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6,
            int param_7)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float fVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  float fVar14;
  int iVar15;
  uint uVar16;
  int local_58;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  uVar7 = (uint)(param_6 != 0);
  uVar12 = (uint)(param_7 != 0);
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (DAT_00f3a070 != 0) {
    iVar8 = FUN_0051c840(0,40000);
    pfVar5 = DAT_00a37f74;
    if (-1 < iVar8) {
      if (DAT_00ef7314 != 0) {
        FUN_005bc5b0(0,0);
      }
      if (((DAT_00a3d360 != 0) || (DAT_00ef72cc != 0)) || (DAT_00ef72c8 != 0x20)) {
        FUN_005bcf50();
      }
      iVar8 = DAT_00a381a0;
      fVar6 = DAT_00a380b8;
      local_10 = DAT_00a38194;
      local_c = DAT_00a38198;
      local_8 = DAT_00a3819c;
      local_4 = DAT_00a381a0;
      FUN_00544000(param_4,&local_20,&local_24,&local_28);
      uVar13 = DAT_00f07344 >> 0x10 & 0xff;
      if (DAT_00a37dcc == 0) {
        uVar13 = (uVar13 * local_28) / 0xff << 8 | ((DAT_00f07344 >> 8 & 0xff) * local_24) / 0xff;
        uVar16 = (DAT_00f07344 & 0xff) * local_20;
      }
      else {
        uVar13 = (uVar13 * local_20) / 0xff << 8 | ((DAT_00f07344 >> 8 & 0xff) * local_24) / 0xff;
        uVar16 = (DAT_00f07344 & 0xff) * local_28;
      }
      fVar14 = (float)(uVar13 << 8 | uVar16 / 0xff | DAT_00f07344 & 0xff000000);
      local_50 = param_3;
      local_44 = param_3 * -2 + 3;
      uVar13 = 0;
      if (param_5 == 0) {
        fVar2 = (float)_DAT_00829898;
        if (uVar12 == 0) {
          iVar8 = param_1 - param_3;
          if (((local_10 <= iVar8) && (iVar8 < local_8)) &&
             ((local_c <= param_2 && (param_2 < local_4)))) {
            pfVar5[4] = fVar14;
            pfVar5[2] = fVar6;
            uVar13 = 1;
            *pfVar5 = (float)iVar8 + fVar2;
            pfVar5[1] = (float)param_2 + fVar2;
            pfVar5[3] = 1.0;
          }
          iVar8 = (param_1 - uVar7) + param_3;
          if (((local_10 <= iVar8) && (iVar8 < local_8)) &&
             ((local_c <= param_2 && (param_2 < local_4)))) {
            pfVar1 = pfVar5 + uVar13 * 5;
            pfVar1[4] = fVar14;
            uVar13 = uVar13 + 1;
            *pfVar1 = (float)iVar8 + fVar2;
            pfVar1[2] = fVar6;
            pfVar1[1] = (float)param_2 + fVar2;
            pfVar1[3] = 1.0;
            if (1999 < uVar13) {
              FUN_005cba60(0,1,pfVar5,uVar13,1);
              fVar2 = (float)_DAT_00829898;
              uVar13 = 0;
            }
          }
        }
        if (uVar7 == 0) {
          iVar8 = (param_2 - uVar12) + param_3;
          if ((((local_10 <= param_1) && (param_1 < local_8)) && (local_c <= iVar8)) &&
             (iVar8 < local_4)) {
            pfVar1 = pfVar5 + uVar13 * 5;
            pfVar1[4] = fVar14;
            uVar13 = uVar13 + 1;
            *pfVar1 = (float)param_1 + fVar2;
            pfVar1[2] = fVar6;
            pfVar1[1] = (float)iVar8 + fVar2;
            pfVar1[3] = 1.0;
            if (1999 < uVar13) {
              FUN_005cba60(0,1,pfVar5,uVar13,1);
              fVar2 = (float)_DAT_00829898;
              uVar13 = 0;
            }
          }
          iVar8 = param_2 - param_3;
          if (((local_10 <= param_1) && (param_1 < local_8)) &&
             ((local_c <= iVar8 && (iVar8 < local_4)))) {
            pfVar1 = pfVar5 + uVar13 * 5;
            pfVar1[4] = fVar14;
            uVar13 = uVar13 + 1;
            *pfVar1 = (float)param_1 + fVar2;
            pfVar1[2] = fVar6;
            pfVar1[1] = (float)iVar8 + fVar2;
            pfVar1[3] = 1.0;
            if (1999 < uVar13) {
              FUN_005cba60(0,1,pfVar5,uVar13,1);
              fVar2 = (float)_DAT_00829898;
              uVar13 = 0;
            }
          }
        }
        if (-1 < local_44) {
          local_50 = param_3 + -1;
          local_44 = local_44 + local_50 * -4;
        }
        local_44 = local_44 + 6;
        if (0 < local_50) {
          local_1c = local_50 * 4;
          local_40 = param_2 - local_50;
          local_3c = param_1 - uVar7;
          local_38 = (local_50 - uVar7) + param_1;
          param_6 = (local_50 - uVar12) + param_2;
          local_34 = (param_2 - uVar12) + 1;
          iVar8 = param_2 - param_1;
          local_4c = 4;
          iVar9 = param_1 - param_2;
          do {
            local_3c = local_3c + 1;
            param_7 = param_1 + -1;
            iVar11 = local_40 + iVar9;
            local_18 = iVar11;
            if (((local_10 <= iVar11) && (iVar11 < local_8)) &&
               ((local_c <= local_34 && (local_34 < local_4)))) {
              pfVar1 = pfVar5 + uVar13 * 5;
              uVar13 = uVar13 + 1;
              *pfVar1 = (float)iVar11 + fVar2;
              pfVar1[4] = fVar14;
              pfVar1[2] = fVar6;
              pfVar1[1] = (float)local_34 + fVar2;
              pfVar1[3] = 1.0;
              if (1999 < (int)uVar13) {
                FUN_005cba60(0,1,pfVar5,uVar13,1);
                fVar2 = (float)_DAT_00829898;
                uVar13 = 0;
              }
            }
            if ((((local_10 <= local_38) && (local_38 < local_8)) && (local_c <= local_34)) &&
               (local_34 < local_4)) {
              pfVar1 = pfVar5 + uVar13 * 5;
              uVar13 = uVar13 + 1;
              *pfVar1 = (float)local_38 + fVar2;
              pfVar1[4] = fVar14;
              pfVar1[2] = fVar6;
              pfVar1[1] = (float)local_34 + fVar2;
              pfVar1[3] = 1.0;
              if (1999 < (int)uVar13) {
                FUN_005cba60(0,1,pfVar5,uVar13,1);
                fVar2 = (float)_DAT_00829898;
                uVar13 = 0;
              }
            }
            if (((local_10 <= local_3c) && (local_3c < local_8)) &&
               ((local_c <= param_6 && (param_6 < local_4)))) {
              pfVar1 = pfVar5 + uVar13 * 5;
              uVar13 = uVar13 + 1;
              *pfVar1 = (float)local_3c + fVar2;
              pfVar1[4] = fVar14;
              pfVar1[2] = fVar6;
              pfVar1[1] = (float)param_6 + fVar2;
              pfVar1[3] = 1.0;
              if (1999 < (int)uVar13) {
                FUN_005cba60(0,1,pfVar5,uVar13,1);
                fVar2 = (float)_DAT_00829898;
                uVar13 = 0;
              }
            }
            if (((local_10 <= param_7) && (param_7 < local_8)) &&
               ((local_c <= param_6 && (param_6 < local_4)))) {
              pfVar1 = pfVar5 + uVar13 * 5;
              uVar13 = uVar13 + 1;
              *pfVar1 = (float)param_7 + fVar2;
              pfVar1[4] = fVar14;
              pfVar1[2] = fVar6;
              pfVar1[1] = (float)param_6 + fVar2;
              pfVar1[3] = 1.0;
              if (1999 < (int)uVar13) {
                FUN_005cba60(0,1,pfVar5,uVar13,1);
                fVar2 = (float)_DAT_00829898;
                uVar13 = 0;
              }
            }
            if ((((local_10 <= local_38) && (local_38 < local_8)) &&
                (iVar15 = param_7 + iVar8, local_c <= iVar15)) && (iVar15 < local_4)) {
              pfVar1 = pfVar5 + uVar13 * 5;
              uVar13 = uVar13 + 1;
              *pfVar1 = (float)local_38 + fVar2;
              pfVar1[4] = fVar14;
              pfVar1[2] = fVar6;
              pfVar1[1] = (float)iVar15 + fVar2;
              pfVar1[3] = 1.0;
              if (1999 < (int)uVar13) {
                FUN_005cba60(0,1,pfVar5,uVar13,1);
                fVar2 = (float)_DAT_00829898;
                uVar13 = 0;
              }
            }
            if (((local_10 <= iVar11) && (iVar11 < local_8)) &&
               ((iVar11 = param_7 + iVar8, local_c <= iVar11 && (iVar11 < local_4)))) {
              pfVar1 = pfVar5 + uVar13 * 5;
              uVar13 = uVar13 + 1;
              *pfVar1 = (float)local_18 + fVar2;
              pfVar1[4] = fVar14;
              pfVar1[2] = fVar6;
              pfVar1[1] = (float)iVar11 + fVar2;
              pfVar1[3] = 1.0;
              if (1999 < (int)uVar13) {
                FUN_005cba60(0,1,pfVar5,uVar13,1);
                fVar2 = (float)_DAT_00829898;
                uVar13 = 0;
              }
            }
            if (((local_10 <= local_3c) && (local_3c < local_8)) &&
               ((local_c <= local_40 && (local_40 < local_4)))) {
              pfVar1 = pfVar5 + uVar13 * 5;
              uVar13 = uVar13 + 1;
              *pfVar1 = (float)local_3c + fVar2;
              pfVar1[4] = fVar14;
              pfVar1[2] = fVar6;
              pfVar1[1] = (float)local_40 + fVar2;
              pfVar1[3] = 1.0;
              if (1999 < (int)uVar13) {
                FUN_005cba60(0,1,pfVar5,uVar13,1);
                fVar2 = (float)_DAT_00829898;
                uVar13 = 0;
              }
            }
            if ((((local_10 <= param_7) && (param_7 < local_8)) && (local_c <= local_40)) &&
               (local_40 < local_4)) {
              pfVar1 = pfVar5 + uVar13 * 5;
              uVar13 = uVar13 + 1;
              *pfVar1 = (float)param_7 + fVar2;
              pfVar1[4] = fVar14;
              pfVar1[2] = fVar6;
              pfVar1[1] = (float)local_40 + fVar2;
              pfVar1[3] = 1.0;
              if (1999 < (int)uVar13) {
                FUN_005cba60(0,1,pfVar5,uVar13,1);
                fVar2 = (float)_DAT_00829898;
                uVar13 = 0;
              }
            }
            if (-1 < local_44) {
              local_50 = local_50 + -1;
              param_6 = param_6 + -1;
              local_38 = local_38 + -1;
              local_40 = local_40 + 1;
              local_1c = local_1c + -4;
              local_44 = local_44 - local_1c;
            }
            local_34 = local_34 + 1;
            local_4c = local_4c + 4;
            local_44 = local_44 + 2 + local_4c;
            param_1 = param_7;
          } while ((int)(local_34 + (uVar12 - param_2)) <= local_50);
        }
        if (uVar13 != 0) {
          FUN_005cba60(0,1,pfVar5,uVar13,1);
        }
      }
      else {
        iVar9 = FUN_0051c840(1,iVar8);
        iVar8 = DAT_00a37f78;
        if (iVar9 < 0) {
          uVar10 = FUN_0056bb10(&DAT_007fcbc0);
          return uVar10;
        }
        FUN_0056d380(DAT_00a37f78,0,local_4);
        fVar2 = (float)_DAT_00829898;
        fVar4 = (float)_DAT_007ff0d8;
        if (uVar12 == 0) {
          iVar9 = (param_1 - uVar7) + param_3;
          local_58 = param_1 - param_3;
          if (((local_10 <= iVar9) && (local_58 < local_8)) &&
             ((local_c <= param_2 && ((param_2 < local_4 && (*(char *)(iVar8 + param_2) == '\0')))))
             ) {
            if (local_58 < local_10) {
              local_58 = local_10;
            }
            if (local_8 + -1 < iVar9) {
              iVar9 = local_8 + -1;
            }
            local_18 = iVar9 + 1;
            pfVar5[2] = fVar6;
            pfVar5[4] = fVar14;
            *pfVar5 = (float)local_58 + fVar2;
            fVar3 = (float)param_2 + fVar4;
            pfVar5[1] = fVar3;
            pfVar5[3] = 1.0;
            *(undefined1 *)(iVar8 + param_2) = 1;
            pfVar5[7] = fVar6;
            pfVar5[9] = fVar14;
            uVar13 = 2;
            pfVar5[5] = (float)local_18 + fVar2;
            pfVar5[6] = fVar3;
            pfVar5[8] = 1.0;
          }
        }
        if (-1 < local_44) {
          local_1c = param_1 - uVar7;
          iVar9 = (param_2 - uVar12) + param_3;
          local_58 = param_1;
          if ((((local_10 <= local_1c) && (param_1 < local_8)) && (local_c <= iVar9)) &&
             ((iVar9 < local_4 && (*(char *)(iVar9 + iVar8) == '\0')))) {
            if (param_1 < local_10) {
              local_58 = local_10;
            }
            local_48 = local_1c;
            if (local_8 + -1 < local_1c) {
              local_48 = local_8 + -1;
            }
            pfVar1 = pfVar5 + uVar13 * 5;
            pfVar1[4] = fVar14;
            pfVar1[2] = fVar6;
            *pfVar1 = (float)local_58 + fVar2;
            fVar4 = (float)iVar9 + fVar4;
            pfVar1[1] = fVar4;
            pfVar1[3] = 1.0;
            *(undefined1 *)(iVar9 + iVar8) = 1;
            pfVar1 = pfVar5 + (uVar13 + 1) * 5;
            local_18 = local_48 + 1;
            uVar13 = uVar13 + 2;
            pfVar1[4] = fVar14;
            pfVar1[2] = fVar6;
            *pfVar1 = (float)local_18 + fVar2;
            pfVar1[1] = fVar4;
            pfVar1[3] = 1.0;
            if (1999 < uVar13) {
              FUN_005cba60(0,2,pfVar5,uVar13,1);
              fVar2 = (float)_DAT_00829898;
              uVar13 = 0;
            }
          }
          iVar9 = param_2 - param_3;
          local_48 = local_1c;
          local_58 = param_1;
          if (((local_10 <= local_1c) && (param_1 < local_8)) &&
             ((local_c <= iVar9 && ((iVar9 < local_4 && (*(char *)(iVar9 + iVar8) == '\0')))))) {
            if (param_1 < local_10) {
              local_58 = local_10;
            }
            if (local_8 + -1 < local_1c) {
              local_48 = local_8 + -1;
            }
            pfVar1 = pfVar5 + uVar13 * 5;
            pfVar1[4] = fVar14;
            pfVar1[2] = fVar6;
            *pfVar1 = (float)local_58 + fVar2;
            fVar4 = (float)_DAT_007ff0d8;
            pfVar1[1] = (float)iVar9 + fVar4;
            pfVar1[3] = 1.0;
            *(undefined1 *)(iVar9 + iVar8) = 1;
            pfVar1 = pfVar5 + (uVar13 + 1) * 5;
            local_18 = local_48 + 1;
            uVar13 = uVar13 + 2;
            pfVar1[4] = fVar14;
            pfVar1[2] = fVar6;
            *pfVar1 = (float)local_18 + fVar2;
            pfVar1[1] = (float)iVar9 + fVar4;
            pfVar1[3] = 1.0;
            if (1999 < uVar13) {
              FUN_005cba60(0,2,pfVar5,uVar13,1);
              fVar2 = (float)_DAT_00829898;
              uVar13 = 0;
            }
          }
          local_50 = param_3 + -1;
          local_44 = local_44 + local_50 * -4;
        }
        local_44 = local_44 + 6;
        if (0 < local_50) {
          local_1c = local_50 * 4;
          local_40 = param_2 - local_50;
          local_3c = param_1 - uVar7;
          param_6 = (local_50 - uVar7) + param_1;
          local_34 = (local_50 - uVar12) + param_2;
          param_7 = (param_2 - uVar12) + 1;
          local_14 = param_1 - param_2;
          iVar9 = param_2 - param_1;
          local_18 = 4;
          do {
            local_38 = param_1 + -1;
            local_3c = local_3c + 1;
            iVar11 = local_40 + local_14;
            if ((((local_10 <= param_6) && (iVar11 < local_8)) && (local_c <= param_7)) &&
               ((param_7 < local_4 && (*(char *)(param_7 + iVar8) == '\0')))) {
              local_58 = iVar11;
              if (iVar11 < local_10) {
                local_58 = local_10;
              }
              iVar15 = param_6;
              if (local_8 + -1 < param_6) {
                iVar15 = local_8 + -1;
              }
              pfVar1 = pfVar5 + uVar13 * 5;
              pfVar1[4] = fVar14;
              pfVar1[2] = fVar6;
              *pfVar1 = (float)local_58 + fVar2;
              fVar4 = (float)_DAT_007ff0d8;
              pfVar1[1] = (float)param_7 + fVar4;
              pfVar1[3] = 1.0;
              *(undefined1 *)(param_7 + iVar8) = 1;
              pfVar1 = pfVar5 + (uVar13 + 1) * 5;
              uVar13 = uVar13 + 2;
              pfVar1[4] = fVar14;
              *pfVar1 = (float)(iVar15 + 1) + fVar2;
              pfVar1[2] = fVar6;
              pfVar1[1] = (float)param_7 + fVar4;
              pfVar1[3] = 1.0;
              if (1999 < (int)uVar13) {
                FUN_005cba60(0,2,pfVar5,uVar13,1);
                fVar2 = (float)_DAT_00829898;
                uVar13 = 0;
              }
            }
            if (((local_10 <= param_6) && (iVar11 < local_8)) &&
               ((iVar15 = local_38 + iVar9, local_c <= iVar15 &&
                ((iVar15 < local_4 && (*(char *)(iVar15 + iVar8) == '\0')))))) {
              local_58 = iVar11;
              if (iVar11 < local_10) {
                local_58 = local_10;
              }
              iVar11 = local_8 + -1;
              if (param_6 <= local_8 + -1) {
                iVar11 = param_6;
              }
              pfVar1 = pfVar5 + uVar13 * 5;
              pfVar1[4] = fVar14;
              pfVar1[2] = fVar6;
              *pfVar1 = (float)local_58 + fVar2;
              fVar4 = (float)_DAT_007ff0d8;
              pfVar1[1] = (float)iVar15 + fVar4;
              pfVar1[3] = 1.0;
              *(undefined1 *)(iVar15 + iVar8) = 1;
              pfVar1 = pfVar5 + (uVar13 + 1) * 5;
              uVar13 = uVar13 + 2;
              pfVar1[4] = fVar14;
              *pfVar1 = (float)(iVar11 + 1) + fVar2;
              pfVar1[2] = fVar6;
              pfVar1[1] = (float)iVar15 + fVar4;
              pfVar1[3] = 1.0;
              if (1999 < (int)uVar13) {
                FUN_005cba60(0,2,pfVar5,uVar13,1);
                fVar2 = (float)_DAT_00829898;
                uVar13 = 0;
              }
            }
            if (-1 < local_44) {
              local_58 = local_38;
              if ((((local_10 <= local_3c) && (local_38 < local_8)) && (local_c <= local_34)) &&
                 ((local_34 < local_4 && (*(char *)(local_34 + iVar8) == '\0')))) {
                if (local_38 < local_10) {
                  local_58 = local_10;
                }
                iVar11 = local_8 + -1;
                if (local_3c <= local_8 + -1) {
                  iVar11 = local_3c;
                }
                pfVar1 = pfVar5 + uVar13 * 5;
                pfVar1[4] = fVar14;
                pfVar1[2] = fVar6;
                *pfVar1 = (float)local_58 + fVar2;
                fVar4 = (float)_DAT_007ff0d8;
                pfVar1[1] = (float)local_34 + fVar4;
                pfVar1[3] = 1.0;
                *(undefined1 *)(local_34 + iVar8) = 1;
                pfVar1 = pfVar5 + (uVar13 + 1) * 5;
                uVar13 = uVar13 + 2;
                pfVar1[4] = fVar14;
                *pfVar1 = (float)(iVar11 + 1) + fVar2;
                pfVar1[2] = fVar6;
                pfVar1[1] = (float)local_34 + fVar4;
                pfVar1[3] = 1.0;
                if (1999 < (int)uVar13) {
                  FUN_005cba60(0,2,pfVar5,uVar13,1);
                  fVar2 = (float)_DAT_00829898;
                  uVar13 = 0;
                }
              }
              local_58 = local_38;
              if (((local_10 <= local_3c) && (local_38 < local_8)) &&
                 ((local_c <= local_40 &&
                  ((local_40 < local_4 && (*(char *)(local_40 + iVar8) == '\0')))))) {
                if (local_38 < local_10) {
                  local_58 = local_10;
                }
                iVar11 = local_8 + -1;
                if (local_3c <= local_8 + -1) {
                  iVar11 = local_3c;
                }
                pfVar1 = pfVar5 + uVar13 * 5;
                pfVar1[4] = fVar14;
                pfVar1[2] = fVar6;
                *pfVar1 = (float)local_58 + fVar2;
                fVar4 = (float)_DAT_007ff0d8;
                pfVar1[1] = (float)local_40 + fVar4;
                pfVar1[3] = 1.0;
                *(undefined1 *)(local_40 + iVar8) = 1;
                pfVar1 = pfVar5 + (uVar13 + 1) * 5;
                uVar13 = uVar13 + 2;
                pfVar1[4] = fVar14;
                *pfVar1 = (float)(iVar11 + 1) + fVar2;
                pfVar1[2] = fVar6;
                pfVar1[1] = (float)local_40 + fVar4;
                pfVar1[3] = 1.0;
                if (1999 < (int)uVar13) {
                  FUN_005cba60(0,2,pfVar5,uVar13,1);
                  fVar2 = (float)_DAT_00829898;
                  uVar13 = 0;
                }
              }
              local_50 = local_50 + -1;
              param_6 = param_6 + -1;
              local_34 = local_34 + -1;
              local_40 = local_40 + 1;
              local_1c = local_1c + -4;
              local_44 = local_44 - local_1c;
            }
            local_18 = local_18 + 4;
            param_7 = param_7 + 1;
            local_44 = local_44 + 2 + local_18;
            param_1 = local_38;
          } while ((int)((uVar12 - param_2) + param_7) <= local_50);
        }
        if (uVar13 != 0) {
          FUN_005cba60(0,2,pfVar5,uVar13,1);
          return 0;
        }
      }
      return 0;
    }
  }
  return 0xffffffff;
}

