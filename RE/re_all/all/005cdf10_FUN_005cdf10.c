
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005cdf10(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6,
            int param_7,int param_8)

{
  float *pfVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float fVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  float fVar17;
  uint local_50;
  int local_4c;
  int local_48;
  uint local_44;
  int local_40;
  int local_3c;
  int local_30;
  int local_2c;
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
  
  uVar7 = (uint)(param_7 != 0);
  uVar13 = (uint)(param_8 != 0);
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((param_3 == 0) || (param_4 == 0)) {
LAB_005cf697:
    return 0xffffffff;
  }
  iVar8 = FUN_0051c840(0,40000);
  pfVar5 = DAT_00a37f74;
  if (iVar8 < 0) goto LAB_005cf697;
  if (DAT_00ef7314 != 0) {
    FUN_005bc5b0(0,0);
  }
  if (((DAT_00a3d360 != 0) || (DAT_00ef72cc != 0)) || (DAT_00ef72c8 != 0x20)) {
    FUN_005bcf50();
  }
  if (param_3 < 0) {
    param_3 = -param_3;
  }
  if (param_4 < 0) {
    param_4 = -param_4;
  }
  local_c = DAT_00a38198;
  local_10 = DAT_00a38194;
  local_8 = DAT_00a3819c;
  local_4 = DAT_00a381a0;
  FUN_00544000(param_5,&local_14,&local_18,&local_1c);
  fVar6 = DAT_00a380b8;
  uVar14 = DAT_00f07344 >> 0x10 & 0xff;
  if (DAT_00a37dcc == 0) {
    uVar16 = (uVar14 * local_1c) / 0xff << 8 | ((DAT_00f07344 >> 8 & 0xff) * local_18) / 0xff;
    uVar14 = (DAT_00f07344 & 0xff) * local_14;
  }
  else {
    uVar16 = (uVar14 * local_14) / 0xff << 8 | ((DAT_00f07344 >> 8 & 0xff) * local_18) / 0xff;
    uVar14 = (DAT_00f07344 & 0xff) * local_1c;
  }
  fVar17 = (float)(uVar16 << 8 | uVar14 / 0xff | DAT_00f07344 & 0xff000000);
  uVar14 = 0;
  local_50 = param_4;
  if (param_6 == 0) {
    fVar3 = (float)_DAT_00829898;
    if (param_3 < param_4) {
      iVar15 = (param_4 * param_4) / param_3;
      iVar9 = 0;
      local_44 = 0;
      iVar8 = param_4 * -2;
      local_4c = param_4 * -4 + 3;
      if (uVar13 == 0) {
        iVar11 = param_2 - param_4;
        if (((local_10 <= param_1) && (param_1 < local_8)) &&
           ((local_c <= iVar11 && (iVar11 < local_4)))) {
          pfVar5[4] = fVar17;
          pfVar5[2] = fVar6;
          uVar14 = 1;
          *pfVar5 = (float)param_1 + fVar3;
          pfVar5[1] = (float)iVar11 + fVar3;
          pfVar5[3] = 1.0;
        }
        iVar11 = param_2 + param_4;
        if (((local_10 <= param_1) && (param_1 < local_8)) &&
           ((local_c <= iVar11 && (iVar11 < local_4)))) {
          pfVar1 = pfVar5 + uVar14 * 5;
          uVar14 = uVar14 + 1;
          *pfVar1 = (float)param_1 + fVar3;
          pfVar1[4] = fVar17;
          pfVar1[2] = fVar6;
          pfVar1[1] = (float)iVar11 + fVar3;
          pfVar1[3] = 1.0;
          if (1999 < uVar14) {
            FUN_005cba60(0,1,pfVar5,uVar14,1);
            fVar3 = (float)_DAT_00829898;
            uVar14 = 0;
          }
        }
      }
      if (iVar8 + 3 < 0) {
        bVar2 = iVar15 <= param_3;
        iVar9 = param_3;
        if (bVar2) {
          iVar9 = param_3 - iVar15;
        }
        local_44 = (uint)bVar2;
        local_4c = local_4c + local_44 * 4;
        local_48 = iVar8 + 5 + local_44 * 4;
      }
      else {
        local_50 = param_4 + -1;
        bVar2 = true;
        if (local_4c < 0) {
          iVar9 = param_3;
          if (iVar15 <= param_3) {
            iVar9 = param_3 - iVar15;
          }
          local_44 = (uint)(iVar15 <= param_3);
          local_4c = (local_44 - local_50) * 4;
          local_48 = iVar8 + 5 + local_4c;
          local_4c = param_4 * -4 + 5 + local_4c;
        }
        else {
          local_48 = iVar8 + 3 + local_50 * -4;
          local_4c = local_4c + local_50 * -4 + 2;
        }
      }
      if (0 < (int)local_50) {
        local_30 = param_1 - local_44;
        param_8 = param_2 - local_50;
        local_24 = local_50 * 4;
        iVar8 = (local_50 - uVar13) + param_2;
        local_2c = (local_44 - uVar7) + param_1;
        local_20 = iVar8;
        do {
          if (bVar2) {
            if (local_10 <= local_2c) {
              if (((local_2c < local_8) && (local_c <= param_8)) && (param_8 < local_4)) {
                pfVar1 = pfVar5 + uVar14 * 5;
                uVar14 = uVar14 + 1;
                *pfVar1 = (float)local_2c + fVar3;
                pfVar1[4] = fVar17;
                pfVar1[2] = fVar6;
                pfVar1[1] = (float)param_8 + fVar3;
                pfVar1[3] = 1.0;
                if (1999 < (int)uVar14) {
                  FUN_005cba60(0,1,pfVar5,uVar14,1);
                  fVar3 = (float)_DAT_00829898;
                  uVar14 = 0;
                }
              }
              if (((local_2c < local_8) && (local_c <= iVar8)) && (iVar8 < local_4)) {
                pfVar1 = pfVar5 + uVar14 * 5;
                uVar14 = uVar14 + 1;
                *pfVar1 = (float)local_2c + fVar3;
                pfVar1[4] = fVar17;
                pfVar1[2] = fVar6;
                pfVar1[1] = (float)local_20 + fVar3;
                pfVar1[3] = 1.0;
                if (1999 < (int)uVar14) {
                  FUN_005cba60(0,1,pfVar5,uVar14,1);
                  fVar3 = (float)_DAT_00829898;
                  uVar14 = 0;
                }
              }
            }
            if (local_10 <= local_30) {
              if (((local_30 < local_8) && (local_c <= param_8)) && (param_8 < local_4)) {
                pfVar1 = pfVar5 + uVar14 * 5;
                uVar14 = uVar14 + 1;
                *pfVar1 = (float)local_30 + fVar3;
                pfVar1[4] = fVar17;
                pfVar1[2] = fVar6;
                pfVar1[1] = (float)param_8 + fVar3;
                pfVar1[3] = 1.0;
                if (1999 < (int)uVar14) {
                  FUN_005cba60(0,1,pfVar5,uVar14,1);
                  fVar3 = (float)_DAT_00829898;
                  uVar14 = 0;
                }
              }
              if (((local_30 < local_8) && (local_c <= iVar8)) && (iVar8 < local_4)) {
                pfVar1 = pfVar5 + uVar14 * 5;
                uVar14 = uVar14 + 1;
                *pfVar1 = (float)local_30 + fVar3;
                pfVar1[4] = fVar17;
                pfVar1[2] = fVar6;
                pfVar1[1] = (float)local_20 + fVar3;
                pfVar1[3] = 1.0;
                if (1999 < (int)uVar14) {
                  FUN_005cba60(0,1,pfVar5,uVar14,1);
                  fVar3 = (float)_DAT_00829898;
                  uVar14 = 0;
                }
              }
            }
          }
          if (local_48 < 0) {
            iVar9 = iVar9 + param_3;
            bVar2 = iVar15 <= iVar9;
            if (bVar2) {
              local_44 = local_44 + 1;
              local_2c = local_2c + 1;
              local_30 = local_30 + -1;
              iVar9 = iVar9 - iVar15;
            }
            local_4c = local_4c + local_44 * 4;
            local_48 = local_48 + 2 + local_44 * 4;
          }
          else {
            bVar2 = true;
            if (local_4c < 0) {
              iVar9 = iVar9 + param_3;
              local_24 = local_24 + -4;
              local_50 = local_50 + -1;
              param_8 = param_8 + 1;
              iVar8 = iVar8 + -1;
              if (iVar15 <= iVar9) {
                local_44 = local_44 + 1;
                local_2c = local_2c + 1;
                local_30 = local_30 + -1;
                iVar9 = iVar9 - iVar15;
              }
              iVar11 = (local_44 - local_50) * 4;
              local_48 = local_48 + 2 + iVar11;
              local_4c = local_4c + 2 + iVar11;
              local_20 = iVar8;
            }
            else {
              local_50 = local_50 + -1;
              param_8 = param_8 + 1;
              local_24 = local_24 + -4;
              local_48 = local_48 - local_24;
              iVar8 = iVar8 + -1;
              local_4c = local_4c + (2 - local_24);
              local_20 = iVar8;
            }
          }
        } while (0 < (int)local_50);
      }
      if (uVar7 == 0) {
        iVar8 = param_1 - local_44;
        iVar9 = local_50 + param_2;
        if (((local_10 <= iVar8) && (iVar8 < local_8)) && ((local_c <= iVar9 && (iVar9 < local_4))))
        {
          pfVar1 = pfVar5 + uVar14 * 5;
          pfVar1[4] = fVar17;
          uVar14 = uVar14 + 1;
          *pfVar1 = (float)iVar8 + fVar3;
          pfVar1[2] = fVar6;
          pfVar1[1] = (float)iVar9 + fVar3;
          pfVar1[3] = 1.0;
          if (1999 < (int)uVar14) {
            FUN_005cba60(0,1,pfVar5,uVar14,1);
            fVar3 = (float)_DAT_00829898;
            uVar14 = 0;
          }
        }
        param_2 = param_2 - local_50;
        param_1 = param_1 + local_44;
        if (((local_10 <= param_1) && (param_1 < local_8)) &&
           ((local_c <= param_2 && (param_2 < local_4)))) {
          pfVar1 = pfVar5 + uVar14 * 5;
          *pfVar1 = (float)param_1 + fVar3;
          pfVar1[4] = fVar17;
          pfVar1[2] = fVar6;
          pfVar1[1] = (float)param_2 + fVar3;
          pfVar1[3] = 1.0;
          goto joined_r0x005cf671;
        }
      }
    }
    else {
      iVar8 = (param_3 * param_3) / param_4;
      local_3c = 0;
      local_50 = 0;
      local_48 = param_3 * -2 + 3;
      local_4c = param_3 * -4 + 3;
      if (uVar13 == 0) {
        iVar9 = param_1 - param_3;
        if ((((local_10 <= iVar9) && (iVar9 < local_8)) && (local_c <= param_2)) &&
           (param_2 < local_4)) {
          pfVar5[4] = fVar17;
          pfVar5[2] = fVar6;
          uVar14 = 1;
          *pfVar5 = (float)iVar9 + fVar3;
          pfVar5[1] = (float)param_2 + fVar3;
          pfVar5[3] = 1.0;
        }
        iVar9 = (param_1 - uVar7) + param_3;
        if (((local_10 <= iVar9) && (iVar9 < local_8)) &&
           ((local_c <= param_2 && (param_2 < local_4)))) {
          pfVar1 = pfVar5 + uVar14 * 5;
          uVar14 = uVar14 + 1;
          *pfVar1 = (float)iVar9 + fVar3;
          pfVar1[4] = fVar17;
          pfVar1[2] = fVar6;
          pfVar1[1] = (float)param_2 + fVar3;
          pfVar1[3] = 1.0;
          if (1999 < uVar14) {
            FUN_005cba60(0,1,pfVar5,uVar14,1);
            fVar3 = (float)_DAT_00829898;
            uVar14 = 0;
          }
        }
      }
      if (local_48 < 0) {
        bVar2 = iVar8 <= param_4;
        local_3c = param_4;
        if (bVar2) {
          local_3c = param_4 - iVar8;
        }
        local_50 = (uint)bVar2;
        local_4c = local_4c + local_50 * 4;
        local_48 = param_3 * -2 + 5 + local_50 * 4;
        local_44 = param_3;
      }
      else {
        local_44 = param_3 + -1;
        bVar2 = true;
        if (local_4c < 0) {
          local_3c = param_4;
          if (iVar8 <= param_4) {
            local_3c = param_4 - iVar8;
          }
          local_50 = (uint)(iVar8 <= param_4);
          local_4c = (local_50 - local_44) * 4;
          local_48 = local_4c + 2 + local_48;
          local_4c = param_3 * -4 + 5 + local_4c;
        }
        else {
          local_48 = local_48 + local_44 * -4;
          local_4c = local_4c + local_44 * -4 + 2;
        }
      }
      if (0 < (int)local_44) {
        local_24 = local_44 * 4;
        local_30 = (local_44 - uVar7) + param_1;
        iVar9 = param_1 - local_44;
        local_2c = param_2 - local_50;
        local_40 = (local_50 - uVar13) + param_2;
        local_20 = iVar9;
        do {
          if (bVar2) {
            if (((local_10 <= iVar9) && (iVar9 < local_8)) &&
               ((local_c <= local_40 && (local_40 < local_4)))) {
              pfVar1 = pfVar5 + uVar14 * 5;
              uVar14 = uVar14 + 1;
              *pfVar1 = (float)local_20 + fVar3;
              pfVar1[4] = fVar17;
              pfVar1[2] = fVar6;
              pfVar1[1] = (float)local_40 + fVar3;
              pfVar1[3] = 1.0;
              if (1999 < (int)uVar14) {
                FUN_005cba60(0,1,pfVar5,uVar14,1);
                fVar3 = (float)_DAT_00829898;
                uVar14 = 0;
              }
            }
            if ((((local_10 <= local_30) && (local_30 < local_8)) && (local_c <= local_40)) &&
               (local_40 < local_4)) {
              pfVar1 = pfVar5 + uVar14 * 5;
              uVar14 = uVar14 + 1;
              *pfVar1 = (float)local_30 + fVar3;
              pfVar1[4] = fVar17;
              pfVar1[2] = fVar6;
              pfVar1[1] = (float)local_40 + fVar3;
              pfVar1[3] = 1.0;
              if (1999 < (int)uVar14) {
                FUN_005cba60(0,1,pfVar5,uVar14,1);
                fVar3 = (float)_DAT_00829898;
                uVar14 = 0;
              }
            }
            if (((local_10 <= iVar9) && (iVar9 < local_8)) &&
               ((local_c <= local_2c && (local_2c < local_4)))) {
              pfVar1 = pfVar5 + uVar14 * 5;
              uVar14 = uVar14 + 1;
              *pfVar1 = (float)local_20 + fVar3;
              pfVar1[4] = fVar17;
              pfVar1[2] = fVar6;
              pfVar1[1] = (float)local_2c + fVar3;
              pfVar1[3] = 1.0;
              if (1999 < (int)uVar14) {
                FUN_005cba60(0,1,pfVar5,uVar14,1);
                fVar3 = (float)_DAT_00829898;
                uVar14 = 0;
              }
            }
            if (((local_10 <= local_30) && (local_30 < local_8)) &&
               ((local_c <= local_2c && (local_2c < local_4)))) {
              pfVar1 = pfVar5 + uVar14 * 5;
              uVar14 = uVar14 + 1;
              *pfVar1 = (float)local_30 + fVar3;
              pfVar1[4] = fVar17;
              pfVar1[2] = fVar6;
              pfVar1[1] = (float)local_2c + fVar3;
              pfVar1[3] = 1.0;
              if (1999 < (int)uVar14) {
                FUN_005cba60(0,1,pfVar5,uVar14,1);
                fVar3 = (float)_DAT_00829898;
                uVar14 = 0;
              }
            }
          }
          if (local_48 < 0) {
            local_3c = local_3c + param_4;
            bVar2 = iVar8 <= local_3c;
            if (bVar2) {
              local_50 = local_50 + 1;
              local_40 = local_40 + 1;
              local_2c = local_2c + -1;
              local_3c = local_3c - iVar8;
            }
            local_4c = local_4c + local_50 * 4;
            local_48 = local_48 + 2 + local_50 * 4;
          }
          else {
            bVar2 = true;
            local_44 = local_44 + -1;
            local_30 = local_30 + -1;
            iVar9 = iVar9 + 1;
            local_20 = iVar9;
            if (local_4c < 0) {
              local_3c = local_3c + param_4;
              local_24 = local_24 + -4;
              if (iVar8 <= local_3c) {
                local_50 = local_50 + 1;
                local_40 = local_40 + 1;
                local_2c = local_2c + -1;
                local_3c = local_3c - iVar8;
              }
              iVar15 = (local_50 - local_44) * 4;
              local_48 = local_48 + 2 + iVar15;
              local_4c = local_4c + 2 + iVar15;
            }
            else {
              local_24 = local_24 + -4;
              local_48 = local_48 - local_24;
              local_4c = local_4c + (2 - local_24);
            }
          }
        } while (0 < (int)local_44);
      }
      if (uVar7 == 0) {
        iVar8 = local_44 + param_1;
        iVar9 = param_2 - local_50;
        if ((((local_10 <= iVar8) && (iVar8 < local_8)) && (local_c <= iVar9)) && (iVar9 < local_4))
        {
          pfVar1 = pfVar5 + uVar14 * 5;
          pfVar1[4] = fVar17;
          uVar14 = uVar14 + 1;
          *pfVar1 = (float)iVar8 + fVar3;
          pfVar1[2] = fVar6;
          pfVar1[1] = (float)iVar9 + fVar3;
          pfVar1[3] = 1.0;
          if (1999 < (int)uVar14) {
            FUN_005cba60(0,1,pfVar5,uVar14,1);
            fVar3 = (float)_DAT_00829898;
            uVar14 = 0;
          }
        }
        param_1 = param_1 - local_44;
        param_2 = (local_50 - uVar13) + param_2;
        if (((local_10 <= param_1) && (param_1 < local_8)) &&
           ((local_c <= param_2 && (param_2 < local_4)))) {
          pfVar1 = pfVar5 + uVar14 * 5;
          *pfVar1 = (float)param_1 + fVar3;
          pfVar1[4] = fVar17;
          pfVar1[2] = fVar6;
          pfVar1[1] = (float)param_2 + fVar3;
          pfVar1[3] = 1.0;
joined_r0x005cf671:
          uVar14 = uVar14 + 1;
          if (1999 < (int)uVar14) goto LAB_005cf67d;
        }
      }
    }
    if (uVar14 == 0) {
      return 0;
    }
LAB_005cf67d:
    FUN_005cba60(0,1,pfVar5,uVar14,1);
    return 0;
  }
  iVar9 = FUN_0051c840(1,local_4);
  iVar8 = DAT_00a37f78;
  if (iVar9 < 0) {
    uVar10 = FUN_0056bb10(&DAT_007fcbc0);
    return uVar10;
  }
  FUN_0056d380(DAT_00a37f78,0,local_4);
  if (param_4 <= param_3) {
    fVar3 = (float)_DAT_00829898;
    fVar4 = (float)_DAT_007ff0d8;
    iVar11 = (param_3 * param_3) / param_4;
    local_3c = 0;
    local_50 = 0;
    iVar9 = param_3 * -2;
    iVar15 = param_3 * -4;
    local_4c = iVar15 + 3;
    if (uVar13 == 0) {
      local_40 = param_1 - param_3;
      iVar12 = (param_1 - uVar7) + param_3;
      if (((local_10 <= iVar12) && (local_40 < local_8)) &&
         ((local_c <= param_2 && ((param_2 < local_4 && (*(char *)(iVar8 + param_2) == '\0')))))) {
        if (local_40 < local_10) {
          local_40 = local_10;
        }
        if (local_8 + -1 < iVar12) {
          iVar12 = local_8 + -1;
        }
        pfVar5[4] = fVar17;
        pfVar5[2] = fVar6;
        *pfVar5 = (float)local_40 + fVar3;
        pfVar5[1] = (float)param_2 + fVar4;
        pfVar5[3] = 1.0;
        *(undefined1 *)(iVar8 + param_2) = 1;
        pfVar5[9] = fVar17;
        pfVar5[7] = fVar6;
        uVar14 = 2;
        pfVar5[5] = (float)(iVar12 + 1) + fVar3;
        pfVar5[6] = (float)param_2 + fVar4;
        pfVar5[8] = 1.0;
      }
    }
    if (iVar9 + 3 < 0) {
      bVar2 = iVar11 <= param_4;
      local_3c = param_4;
      if (bVar2) {
        local_3c = param_4 - iVar11;
      }
      local_50 = (uint)bVar2;
      local_48 = iVar9 + 5 + local_50 * 4;
      local_4c = local_4c + local_50 * 4;
    }
    else {
      param_3 = param_3 + -1;
      bVar2 = true;
      if (local_4c < 0) {
        local_3c = param_4;
        if (iVar11 <= param_4) {
          local_3c = param_4 - iVar11;
        }
        bVar2 = true;
        local_50 = (uint)(iVar11 <= param_4);
        local_4c = (local_50 - param_3) * 4;
        local_48 = iVar9 + 5 + local_4c;
        local_4c = iVar15 + 5 + local_4c;
      }
      else {
        local_48 = iVar9 + 3 + param_3 * -4;
        local_4c = local_4c + param_3 * -4 + 2;
      }
    }
    if (-1 < param_3) {
      local_44 = param_2 - local_50;
      local_24 = (local_50 - uVar13) + param_2;
      local_20 = param_3 * 4;
      local_28 = (param_3 - uVar7) + param_1;
      param_8 = param_1 - param_3;
      do {
        if ((bVar2) && (local_40 = param_8, local_10 <= local_28)) {
          iVar9 = local_28;
          if ((param_8 < local_8) &&
             (((local_c <= local_24 && (local_24 < local_4)) &&
              (*(char *)(local_24 + iVar8) == '\0')))) {
            if (param_8 < local_10) {
              local_40 = local_10;
            }
            if (local_8 + -1 < local_28) {
              iVar9 = local_8 + -1;
            }
            pfVar1 = pfVar5 + uVar14 * 5;
            pfVar1[4] = fVar17;
            pfVar1[2] = fVar6;
            *pfVar1 = (float)local_40 + fVar3;
            pfVar1[1] = (float)local_24 + fVar4;
            pfVar1[3] = 1.0;
            *(undefined1 *)(local_24 + iVar8) = 1;
            pfVar1 = pfVar5 + (uVar14 + 1) * 5;
            uVar14 = uVar14 + 2;
            pfVar1[4] = fVar17;
            pfVar1[2] = fVar6;
            *pfVar1 = (float)(iVar9 + 1) + fVar3;
            pfVar1[1] = (float)local_24 + fVar4;
            pfVar1[3] = 1.0;
            if (1999 < (int)uVar14) {
              FUN_005cba60(0,2,pfVar5,uVar14,1);
              fVar4 = (float)_DAT_007ff0d8;
              fVar3 = (float)_DAT_00829898;
              uVar14 = 0;
            }
          }
          if (((local_10 <= iVar9) && (local_40 < local_8)) &&
             ((local_c <= (int)local_44 &&
              (((int)local_44 < local_4 && (*(char *)(local_44 + iVar8) == '\0')))))) {
            if (local_40 < local_10) {
              local_40 = local_10;
            }
            if (local_8 + -1 < iVar9) {
              iVar9 = local_8 + -1;
            }
            pfVar1 = pfVar5 + uVar14 * 5;
            pfVar1[4] = fVar17;
            pfVar1[2] = fVar6;
            *pfVar1 = (float)local_40 + fVar3;
            pfVar1[1] = (float)(int)local_44 + fVar4;
            pfVar1[3] = 1.0;
            *(undefined1 *)(local_44 + iVar8) = 1;
            pfVar1 = pfVar5 + (uVar14 + 1) * 5;
            uVar14 = uVar14 + 2;
            *pfVar1 = (float)(iVar9 + 1) + fVar3;
            pfVar1[4] = fVar17;
            pfVar1[2] = fVar6;
            pfVar1[1] = (float)(int)local_44 + fVar4;
            pfVar1[3] = 1.0;
            if (1999 < (int)uVar14) {
              FUN_005cba60(0,2,pfVar5,uVar14,1);
              fVar4 = (float)_DAT_007ff0d8;
              fVar3 = (float)_DAT_00829898;
              uVar14 = 0;
            }
          }
        }
        bVar2 = false;
        if (local_48 < 0) {
          local_3c = local_3c + param_4;
          bVar2 = iVar11 <= local_3c;
          if (bVar2) {
            local_50 = local_50 + 1;
            local_24 = local_24 + 1;
            local_44 = local_44 + -1;
            local_3c = local_3c - iVar11;
          }
          local_4c = local_4c + local_50 * 4;
          local_48 = local_48 + 2 + local_50 * 4;
        }
        else {
          param_8 = param_8 + 1;
          local_28 = local_28 + -1;
          param_3 = param_3 + -1;
          if (local_4c < 0) {
            local_3c = local_3c + param_4;
            local_20 = local_20 + -4;
            bVar2 = iVar11 <= local_3c;
            if (bVar2) {
              local_50 = local_50 + 1;
              local_24 = local_24 + 1;
              local_44 = local_44 + -1;
              local_3c = local_3c - iVar11;
            }
            iVar9 = (local_50 - param_3) * 4;
            local_48 = local_48 + 2 + iVar9;
            local_4c = local_4c + 2 + iVar9;
          }
          else {
            local_20 = local_20 + -4;
            local_48 = local_48 - local_20;
            local_4c = local_4c + (2 - local_20);
          }
        }
      } while (-1 < param_3);
    }
    local_40 = param_1 - param_3;
    param_1 = (param_3 - uVar7) + param_1;
    param_2 = param_2 - local_50;
    if ((((local_10 <= param_1) && (local_40 < local_8)) && (local_c <= param_2)) &&
       ((param_2 < local_4 && (*(char *)(param_2 + iVar8) == '\0')))) {
      if (local_40 < local_10) {
        local_40 = local_10;
      }
      if (local_8 + -1 < param_1) {
        param_1 = local_8 + -1;
      }
      pfVar1 = pfVar5 + uVar14 * 5;
      pfVar1[4] = fVar17;
      pfVar1[2] = fVar6;
      *pfVar1 = (float)local_40 + fVar3;
      pfVar1[1] = (float)param_2 + fVar4;
      pfVar1[3] = 1.0;
      *(undefined1 *)(param_2 + iVar8) = 1;
      pfVar1 = pfVar5 + (uVar14 + 1) * 5;
      uVar14 = uVar14 + 2;
      pfVar1[4] = fVar17;
      *pfVar1 = (float)(param_1 + 1) + fVar3;
      pfVar1[2] = fVar6;
      pfVar1[1] = (float)param_2 + fVar4;
      pfVar1[3] = 1.0;
      if (1999 < (int)uVar14) {
        FUN_005cba60(0,2,pfVar5,uVar14,1);
        return 0;
      }
    }
    goto LAB_005ceb0a;
  }
  iVar9 = (param_4 * param_4) / param_3;
  local_48 = param_4 * -2 + 3;
  local_4c = param_4 * -4 + 3;
  local_3c = 0;
  local_44 = 0;
  if (local_48 < 0) {
    local_3c = param_3;
    if (iVar9 <= param_3) {
      local_3c = param_3 - iVar9;
    }
    local_48 = (uint)(iVar9 <= param_3) * 4;
    local_4c = local_4c + local_48;
LAB_005ce7c6:
    local_44 = (uint)(iVar9 <= param_3);
    local_48 = param_4 * -2 + 5 + local_48;
  }
  else {
    local_50 = param_4 + -1;
    if (local_4c < 0) {
      local_3c = param_3;
      if (iVar9 <= param_3) {
        local_3c = param_3 - iVar9;
      }
      local_48 = ((iVar9 <= param_3) - local_50) * 4;
      local_4c = param_4 * -4 + 5 + local_48;
      goto LAB_005ce7c6;
    }
    local_48 = local_48 + local_50 * -4;
    local_4c = local_4c + local_50 * -4 + 2;
  }
  if ((int)local_50 < 0) {
    return 0;
  }
  fVar3 = (float)_DAT_00829898;
  local_20 = local_50 * 4;
  iVar15 = (local_44 - uVar7) + param_1;
  iVar11 = (local_50 - uVar13) + param_2;
  param_8 = param_1 - local_44;
  param_7 = param_2 - local_50;
  local_28 = iVar11;
  local_24 = iVar15;
  do {
    if (local_48 < 0) {
      local_3c = local_3c + param_3;
      if (iVar9 <= local_3c) {
        param_8 = param_8 + -1;
        local_44 = local_44 + 1;
        iVar15 = iVar15 + 1;
        local_3c = local_3c - iVar9;
        local_24 = iVar15;
      }
      local_4c = local_4c + local_44 * 4;
      local_48 = local_48 + 2 + local_44 * 4;
    }
    else {
      if (local_10 <= iVar15) {
        iVar12 = iVar15;
        local_40 = param_8;
        if (((param_8 < local_8) && (local_c <= param_7)) &&
           ((param_7 < local_4 && (*(char *)(param_7 + iVar8) == '\0')))) {
          if (param_8 < local_10) {
            local_40 = local_10;
          }
          if (local_8 + -1 < iVar15) {
            iVar12 = local_8 + -1;
          }
          pfVar1 = pfVar5 + uVar14 * 5;
          pfVar1[4] = fVar17;
          pfVar1[2] = fVar6;
          *pfVar1 = (float)local_40 + fVar3;
          fVar4 = (float)_DAT_007ff0d8;
          pfVar1[1] = (float)param_7 + fVar4;
          pfVar1[3] = 1.0;
          *(undefined1 *)(param_7 + iVar8) = 1;
          pfVar1 = pfVar5 + (uVar14 + 1) * 5;
          pfVar1[4] = fVar17;
          uVar14 = uVar14 + 2;
          *pfVar1 = (float)(iVar12 + 1) + fVar3;
          pfVar1[2] = fVar6;
          pfVar1[1] = (float)param_7 + fVar4;
          pfVar1[3] = 1.0;
          if (1999 < (int)uVar14) {
            FUN_005cba60(0,2,pfVar5,uVar14,1);
            fVar3 = (float)_DAT_00829898;
            uVar14 = 0;
            iVar15 = local_24;
          }
        }
        if ((((local_10 <= iVar12) && (local_40 < local_8)) && (local_c <= iVar11)) &&
           ((iVar11 < local_4 && (*(char *)(iVar8 + iVar11) == '\0')))) {
          if (local_40 < local_10) {
            local_40 = local_10;
          }
          if (local_8 + -1 < iVar12) {
            iVar12 = local_8 + -1;
          }
          pfVar1 = pfVar5 + uVar14 * 5;
          pfVar1[4] = fVar17;
          pfVar1[2] = fVar6;
          *pfVar1 = (float)local_40 + fVar3;
          fVar4 = (float)_DAT_007ff0d8;
          pfVar1[1] = (float)local_28 + fVar4;
          pfVar1[3] = 1.0;
          *(undefined1 *)(iVar8 + iVar11) = 1;
          pfVar1 = pfVar5 + (uVar14 + 1) * 5;
          uVar14 = uVar14 + 2;
          pfVar1[4] = fVar17;
          *pfVar1 = (float)(iVar12 + 1) + fVar3;
          pfVar1[2] = fVar6;
          pfVar1[1] = (float)local_28 + fVar4;
          pfVar1[3] = 1.0;
          if (1999 < (int)uVar14) {
            FUN_005cba60(0,2,pfVar5,uVar14,1);
            fVar3 = (float)_DAT_00829898;
            uVar14 = 0;
            iVar15 = local_24;
          }
        }
      }
      local_50 = local_50 + -1;
      param_7 = param_7 + 1;
      iVar11 = iVar11 + -1;
      local_28 = iVar11;
      if (local_4c < 0) {
        local_3c = local_3c + param_3;
        local_20 = local_20 + -4;
        if (iVar9 <= local_3c) {
          local_44 = local_44 + 1;
          param_8 = param_8 + -1;
          iVar15 = iVar15 + 1;
          local_3c = local_3c - iVar9;
          local_24 = iVar15;
        }
        iVar12 = (local_44 - local_50) * 4;
        local_48 = local_48 + 2 + iVar12;
        local_4c = local_4c + 2 + iVar12;
      }
      else {
        local_20 = local_20 + -4;
        local_48 = local_48 - local_20;
        local_4c = local_4c + (2 - local_20);
      }
    }
  } while (-1 < (int)local_50);
LAB_005ceb0a:
  if (uVar14 == 0) {
    return 0;
  }
  FUN_005cba60(0,2,pfVar5,uVar14,1);
  return 0;
}

