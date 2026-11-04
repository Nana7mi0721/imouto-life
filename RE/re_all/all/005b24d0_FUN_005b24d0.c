
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005b24d0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6,
            int param_7,int param_8)

{
  float *pfVar1;
  bool bVar2;
  float fVar3;
  float *pfVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  float fVar14;
  uint uVar15;
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
  
  uVar6 = (uint)(param_7 != 0);
  uVar12 = (uint)(param_8 != 0);
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if ((param_3 == 0) || (param_4 == 0)) {
LAB_005b3b88:
    return 0xffffffff;
  }
  iVar7 = FUN_0051c840(0,40000);
  pfVar4 = DAT_00a37f74;
  if (iVar7 < 0) goto LAB_005b3b88;
  FUN_0059d430();
  FUN_0059bcf0(0);
  if (DAT_00e39a4c != 0) {
    FUN_0059bcf0(0);
  }
  if (((DAT_00a3d360 != 0) || (DAT_00e39a00 != 0)) || (DAT_00e399fc != 0x20)) {
    FUN_005a7f60();
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
  FUN_00544000(param_5,&local_20,&local_1c,&local_18);
  fVar5 = DAT_00a380b8;
  fVar14 = (float)((((DAT_00e79684 >> 0x10 & 0xff) * local_20) / 0xff << 8 |
                   ((DAT_00e79684 >> 8 & 0xff) * local_1c) / 0xff) << 8 |
                   ((DAT_00e79684 & 0xff) * local_18) / 0xff | DAT_00e79684 & 0xff000000);
  FUN_005a7ce0();
  uVar15 = 0;
  local_50 = param_4;
  if (param_6 != 0) {
    iVar8 = FUN_0051c840(1,local_4);
    iVar7 = DAT_00a37f78;
    if (iVar8 < 0) {
      uVar9 = FUN_0056bb10(&DAT_007fcbc0);
      return uVar9;
    }
    FUN_0056d380(DAT_00a37f78,0,local_4);
    if (param_3 < param_4) {
      iVar8 = (param_4 * param_4) / param_3;
      local_4c = param_4 * -2 + 3;
      local_48 = param_4 * -4 + 3;
      local_3c = 0;
      local_44 = 0;
      if (local_4c < 0) {
        local_3c = param_3;
        if (iVar8 <= param_3) {
          local_3c = param_3 - iVar8;
        }
        local_4c = (uint)(iVar8 <= param_3) * 4;
        local_48 = local_48 + local_4c;
LAB_005b2d3a:
        local_44 = (uint)(iVar8 <= param_3);
        local_4c = param_4 * -2 + 5 + local_4c;
      }
      else {
        local_50 = param_4 + -1;
        if (local_48 < 0) {
          local_3c = param_3;
          if (iVar8 <= param_3) {
            local_3c = param_3 - iVar8;
          }
          local_4c = ((iVar8 <= param_3) - local_50) * 4;
          local_48 = param_4 * -4 + 5 + local_4c;
          goto LAB_005b2d3a;
        }
        local_4c = local_4c + local_50 * -4;
        local_48 = local_48 + local_50 * -4 + 2;
      }
      if ((int)local_50 < 0) {
        return 0;
      }
      local_24 = local_50 * 4;
      iVar13 = (local_44 - uVar6) + param_1;
      iVar10 = (local_50 - uVar12) + param_2;
      param_8 = param_1 - local_44;
      param_7 = param_2 - local_50;
      local_30 = iVar10;
      local_28 = iVar13;
      do {
        if (local_4c < 0) {
          local_3c = local_3c + param_3;
          if (iVar8 <= local_3c) {
            param_8 = param_8 + -1;
            local_44 = local_44 + 1;
            iVar13 = iVar13 + 1;
            local_3c = local_3c - iVar8;
            local_28 = iVar13;
          }
          local_48 = local_48 + local_44 * 4;
          local_4c = local_4c + 2 + local_44 * 4;
        }
        else {
          if (local_10 <= iVar13) {
            iVar11 = iVar13;
            local_40 = param_8;
            if (((param_8 < local_8) && (local_c <= param_7)) &&
               ((param_7 < local_4 && (*(char *)(param_7 + iVar7) == '\0')))) {
              if (param_8 < local_10) {
                local_40 = local_10;
              }
              if (local_8 + -1 < iVar13) {
                iVar11 = local_8 + -1;
              }
              pfVar1 = pfVar4 + uVar15 * 5;
              fVar3 = (float)local_40 + _DAT_00ddb4c4;
              pfVar1[4] = fVar14;
              pfVar1[2] = fVar5;
              *pfVar1 = fVar3;
              pfVar1[1] = (float)param_7;
              pfVar1[3] = 1.0;
              *(undefined1 *)(param_7 + iVar7) = 1;
              local_14 = iVar11 + 1;
              pfVar1 = pfVar4 + (uVar15 + 1) * 5;
              fVar3 = (float)local_14 + _DAT_00ddb4c8;
              pfVar1[4] = fVar14;
              uVar15 = uVar15 + 2;
              *pfVar1 = fVar3;
              pfVar1[2] = fVar5;
              pfVar1[1] = (float)param_7;
              pfVar1[3] = 1.0;
              if (1999 < uVar15) {
                FUN_005d3b40(2,uVar15 >> 1,pfVar4,0x14);
                DAT_00a37de4 = DAT_00a37de4 + 1;
                uVar15 = 0;
                iVar13 = local_28;
              }
            }
            if (((local_10 <= iVar11) && (local_40 < local_8)) &&
               ((local_c <= iVar10 && ((iVar10 < local_4 && (*(char *)(iVar7 + iVar10) == '\0'))))))
            {
              if (local_40 < local_10) {
                local_40 = local_10;
              }
              if (local_8 + -1 < iVar11) {
                iVar11 = local_8 + -1;
              }
              pfVar1 = pfVar4 + uVar15 * 5;
              fVar3 = (float)local_40 + _DAT_00ddb4c4;
              pfVar1[4] = fVar14;
              pfVar1[2] = fVar5;
              *pfVar1 = fVar3;
              local_14 = iVar11 + 1;
              pfVar1[1] = (float)local_30;
              pfVar1[3] = 1.0;
              *(undefined1 *)(iVar7 + iVar10) = 1;
              pfVar1 = pfVar4 + (uVar15 + 1) * 5;
              fVar3 = (float)local_14 + _DAT_00ddb4c8;
              uVar15 = uVar15 + 2;
              pfVar1[4] = fVar14;
              *pfVar1 = fVar3;
              pfVar1[2] = fVar5;
              pfVar1[1] = (float)local_30;
              pfVar1[3] = 1.0;
              if (1999 < uVar15) {
                FUN_005d3b40(2,uVar15 >> 1,pfVar4,0x14);
                DAT_00a37de4 = DAT_00a37de4 + 1;
                uVar15 = 0;
                iVar13 = local_28;
              }
            }
          }
          local_50 = local_50 + -1;
          param_7 = param_7 + 1;
          iVar10 = iVar10 + -1;
          local_30 = iVar10;
          if (local_48 < 0) {
            local_3c = local_3c + param_3;
            local_24 = local_24 + -4;
            if (iVar8 <= local_3c) {
              local_44 = local_44 + 1;
              param_8 = param_8 + -1;
              iVar13 = iVar13 + 1;
              local_3c = local_3c - iVar8;
              local_28 = iVar13;
            }
            iVar11 = (local_44 - local_50) * 4;
            local_4c = local_4c + 2 + iVar11;
            local_48 = local_48 + 2 + iVar11;
          }
          else {
            local_24 = local_24 + -4;
            local_4c = local_4c - local_24;
            local_48 = local_48 + (2 - local_24);
          }
        }
      } while (-1 < (int)local_50);
    }
    else {
      iVar10 = (param_3 * param_3) / param_4;
      local_3c = 0;
      local_50 = 0;
      iVar8 = param_3 * -2;
      iVar13 = param_3 * -4;
      local_48 = iVar13 + 3;
      if (uVar12 == 0) {
        local_40 = param_1 - param_3;
        iVar11 = (param_1 - uVar6) + param_3;
        if ((((local_10 <= iVar11) && (local_40 < local_8)) && (local_c <= param_2)) &&
           ((param_2 < local_4 && (*(char *)(iVar7 + param_2) == '\0')))) {
          if (local_40 < local_10) {
            local_40 = local_10;
          }
          if (local_8 + -1 < iVar11) {
            iVar11 = local_8 + -1;
          }
          fVar3 = (float)local_40 + _DAT_00ddb4c4;
          pfVar4[2] = fVar5;
          pfVar4[4] = fVar14;
          *pfVar4 = fVar3;
          pfVar4[1] = (float)param_2;
          pfVar4[3] = 1.0;
          *(undefined1 *)(iVar7 + param_2) = 1;
          uVar15 = 2;
          fVar3 = (float)(iVar11 + 1) + _DAT_00ddb4c8;
          pfVar4[9] = fVar14;
          pfVar4[7] = fVar5;
          pfVar4[5] = fVar3;
          pfVar4[6] = (float)param_2;
          pfVar4[8] = 1.0;
        }
      }
      if (iVar8 + 3 < 0) {
        bVar2 = iVar10 <= param_4;
        local_3c = param_4;
        if (bVar2) {
          local_3c = param_4 - iVar10;
        }
        local_50 = (uint)bVar2;
        local_4c = iVar8 + 5 + local_50 * 4;
        local_48 = local_48 + local_50 * 4;
      }
      else {
        param_3 = param_3 + -1;
        bVar2 = true;
        if (local_48 < 0) {
          local_3c = param_4;
          if (iVar10 <= param_4) {
            local_3c = param_4 - iVar10;
          }
          bVar2 = true;
          local_50 = (uint)(iVar10 <= param_4);
          local_48 = (local_50 - param_3) * 4;
          local_4c = iVar8 + 5 + local_48;
          local_48 = iVar13 + 5 + local_48;
        }
        else {
          local_4c = iVar8 + 3 + param_3 * -4;
          local_48 = local_48 + param_3 * -4 + 2;
        }
      }
      if (-1 < param_3) {
        local_30 = param_2 - local_50;
        local_28 = (local_50 - uVar12) + param_2;
        local_24 = param_3 * 4;
        local_44 = (param_3 - uVar6) + param_1;
        param_8 = param_1 - param_3;
        do {
          if ((bVar2) && (local_40 = param_8, local_10 <= (int)local_44)) {
            uVar12 = local_44;
            if ((param_8 < local_8) &&
               (((local_c <= local_28 && (local_28 < local_4)) &&
                (*(char *)(local_28 + iVar7) == '\0')))) {
              if (param_8 < local_10) {
                local_40 = local_10;
              }
              if (local_8 + -1 < (int)local_44) {
                uVar12 = local_8 + -1;
              }
              pfVar1 = pfVar4 + uVar15 * 5;
              fVar3 = (float)local_40 + _DAT_00ddb4c4;
              pfVar1[4] = fVar14;
              pfVar1[2] = fVar5;
              *pfVar1 = fVar3;
              pfVar1[1] = (float)local_28;
              pfVar1[3] = 1.0;
              *(undefined1 *)(local_28 + iVar7) = 1;
              pfVar1 = pfVar4 + (uVar15 + 1) * 5;
              local_14 = uVar12 + 1;
              uVar15 = uVar15 + 2;
              fVar3 = (float)local_14 + _DAT_00ddb4c8;
              pfVar1[4] = fVar14;
              pfVar1[2] = fVar5;
              *pfVar1 = fVar3;
              pfVar1[1] = (float)local_28;
              pfVar1[3] = 1.0;
              if (1999 < uVar15) {
                FUN_005d3b40(2,uVar15 >> 1,pfVar4,0x14);
                DAT_00a37de4 = DAT_00a37de4 + 1;
                uVar15 = 0;
              }
            }
            if (((local_10 <= (int)uVar12) && (local_40 < local_8)) &&
               ((local_c <= local_30 &&
                ((local_30 < local_4 && (*(char *)(local_30 + iVar7) == '\0')))))) {
              if (local_40 < local_10) {
                local_40 = local_10;
              }
              if (local_8 + -1 < (int)uVar12) {
                uVar12 = local_8 + -1;
              }
              fVar3 = (float)local_40 + _DAT_00ddb4c4;
              pfVar1 = pfVar4 + uVar15 * 5;
              pfVar1[4] = fVar14;
              pfVar1[2] = fVar5;
              *pfVar1 = fVar3;
              local_14 = uVar12 + 1;
              pfVar1[1] = (float)local_30;
              pfVar1[3] = 1.0;
              *(undefined1 *)(local_30 + iVar7) = 1;
              pfVar1 = pfVar4 + (uVar15 + 1) * 5;
              fVar3 = (float)local_14 + _DAT_00ddb4c8;
              pfVar1[4] = fVar14;
              uVar15 = uVar15 + 2;
              *pfVar1 = fVar3;
              pfVar1[2] = fVar5;
              pfVar1[1] = (float)local_30;
              pfVar1[3] = 1.0;
              if (1999 < uVar15) {
                FUN_005d3b40(2,uVar15 >> 1,pfVar4,0x14);
                DAT_00a37de4 = DAT_00a37de4 + 1;
                uVar15 = 0;
              }
            }
          }
          bVar2 = false;
          if (local_4c < 0) {
            local_3c = local_3c + param_4;
            bVar2 = iVar10 <= local_3c;
            if (bVar2) {
              local_50 = local_50 + 1;
              local_28 = local_28 + 1;
              local_30 = local_30 + -1;
              local_3c = local_3c - iVar10;
            }
            local_48 = local_48 + local_50 * 4;
            local_4c = local_4c + 2 + local_50 * 4;
          }
          else {
            param_8 = param_8 + 1;
            local_44 = local_44 + -1;
            param_3 = param_3 + -1;
            if (local_48 < 0) {
              local_3c = local_3c + param_4;
              local_24 = local_24 + -4;
              bVar2 = iVar10 <= local_3c;
              if (bVar2) {
                local_50 = local_50 + 1;
                local_28 = local_28 + 1;
                local_30 = local_30 + -1;
                local_3c = local_3c - iVar10;
              }
              iVar8 = (local_50 - param_3) * 4;
              local_4c = local_4c + 2 + iVar8;
              local_48 = local_48 + 2 + iVar8;
            }
            else {
              local_24 = local_24 + -4;
              local_4c = local_4c - local_24;
              local_48 = local_48 + (2 - local_24);
            }
          }
        } while (-1 < param_3);
      }
      local_40 = param_1 - param_3;
      param_1 = (param_3 - uVar6) + param_1;
      param_2 = param_2 - local_50;
      if ((((local_10 <= param_1) && (local_40 < local_8)) && (local_c <= param_2)) &&
         ((param_2 < local_4 && (*(char *)(param_2 + iVar7) == '\0')))) {
        if (local_40 < local_10) {
          local_40 = local_10;
        }
        if (local_8 + -1 < param_1) {
          param_1 = local_8 + -1;
        }
        fVar3 = (float)local_40 + _DAT_00ddb4c4;
        pfVar1 = pfVar4 + uVar15 * 5;
        pfVar1[4] = fVar14;
        pfVar1[2] = fVar5;
        *pfVar1 = fVar3;
        pfVar1[1] = (float)param_2;
        pfVar1[3] = 1.0;
        *(undefined1 *)(param_2 + iVar7) = 1;
        pfVar1 = pfVar4 + (uVar15 + 1) * 5;
        fVar3 = (float)(param_1 + 1) + _DAT_00ddb4c8;
        uVar15 = uVar15 + 2;
        pfVar1[4] = fVar14;
        *pfVar1 = fVar3;
        pfVar1[2] = fVar5;
        pfVar1[1] = (float)param_2;
        pfVar1[3] = 1.0;
        if (1999 < uVar15) {
          uVar15 = uVar15 >> 1;
          uVar9 = 2;
          goto LAB_005b3b6f;
        }
      }
    }
    if (uVar15 == 0) {
      return 0;
    }
    uVar15 = uVar15 >> 1;
    uVar9 = 2;
    goto LAB_005b3b6f;
  }
  local_3c = 0;
  if (param_3 < param_4) {
    iVar8 = (param_4 * param_4) / param_3;
    local_44 = 0;
    iVar7 = param_4 * -2;
    local_48 = param_4 * -4 + 3;
    if (uVar12 == 0) {
      iVar13 = param_2 - param_4;
      if (((local_10 <= param_1) && (param_1 < local_8)) &&
         ((local_c <= iVar13 && (iVar13 < local_4)))) {
        pfVar4[4] = fVar14;
        *pfVar4 = (float)param_1;
        pfVar4[2] = fVar5;
        uVar15 = 1;
        pfVar4[1] = (float)iVar13;
        pfVar4[3] = 1.0;
      }
      iVar13 = param_2 + param_4;
      if ((((local_10 <= param_1) && (param_1 < local_8)) && (local_c <= iVar13)) &&
         (iVar13 < local_4)) {
        pfVar1 = pfVar4 + uVar15 * 5;
        *pfVar1 = (float)param_1;
        uVar15 = uVar15 + 1;
        pfVar1[4] = fVar14;
        pfVar1[1] = (float)iVar13;
        pfVar1[2] = fVar5;
        pfVar1[3] = 1.0;
        if (1999 < uVar15) {
          FUN_005d3b40(1,uVar15,pfVar4,0x14);
          DAT_00a37de4 = DAT_00a37de4 + 1;
          uVar15 = 0;
        }
      }
    }
    if (iVar7 + 3 < 0) {
      bVar2 = iVar8 <= param_3;
      local_3c = param_3;
      if (bVar2) {
        local_3c = param_3 - iVar8;
      }
      local_44 = (uint)bVar2;
      local_48 = local_48 + local_44 * 4;
      local_4c = iVar7 + 5 + local_44 * 4;
    }
    else {
      local_50 = param_4 + -1;
      bVar2 = true;
      if (local_48 < 0) {
        local_3c = param_3;
        if (iVar8 <= param_3) {
          local_3c = param_3 - iVar8;
        }
        local_44 = (uint)(iVar8 <= param_3);
        local_48 = (local_44 - local_50) * 4;
        local_4c = iVar7 + 5 + local_48;
        local_48 = param_4 * -4 + 5 + local_48;
      }
      else {
        local_4c = iVar7 + 3 + local_50 * -4;
        local_48 = local_48 + local_50 * -4 + 2;
      }
    }
    if (0 < (int)local_50) {
      local_30 = param_1 - local_44;
      param_8 = param_2 - local_50;
      local_28 = local_50 * 4;
      iVar7 = (local_50 - uVar12) + param_2;
      local_2c = (local_44 - uVar6) + param_1;
      local_24 = iVar7;
      do {
        if (bVar2) {
          if (local_10 <= local_2c) {
            if (((local_2c < local_8) && (local_c <= param_8)) && (param_8 < local_4)) {
              pfVar1 = pfVar4 + uVar15 * 5;
              *pfVar1 = (float)local_2c;
              uVar15 = uVar15 + 1;
              pfVar1[4] = fVar14;
              pfVar1[2] = fVar5;
              pfVar1[1] = (float)param_8;
              pfVar1[3] = 1.0;
              if (1999 < uVar15) {
                FUN_005d3b40(1,uVar15,pfVar4,0x14);
                DAT_00a37de4 = DAT_00a37de4 + 1;
                uVar15 = 0;
              }
            }
            if (((local_2c < local_8) && (local_c <= iVar7)) && (iVar7 < local_4)) {
              pfVar1 = pfVar4 + uVar15 * 5;
              *pfVar1 = (float)local_2c;
              uVar15 = uVar15 + 1;
              pfVar1[4] = fVar14;
              pfVar1[1] = (float)local_24;
              pfVar1[2] = fVar5;
              pfVar1[3] = 1.0;
              if (1999 < uVar15) {
                FUN_005d3b40(1,uVar15,pfVar4,0x14);
                DAT_00a37de4 = DAT_00a37de4 + 1;
                uVar15 = 0;
              }
            }
          }
          if (local_10 <= local_30) {
            if (((local_30 < local_8) && (local_c <= param_8)) && (param_8 < local_4)) {
              pfVar1 = pfVar4 + uVar15 * 5;
              *pfVar1 = (float)local_30;
              uVar15 = uVar15 + 1;
              pfVar1[4] = fVar14;
              pfVar1[1] = (float)param_8;
              pfVar1[2] = fVar5;
              pfVar1[3] = 1.0;
              if (1999 < uVar15) {
                FUN_005d3b40(1,uVar15,pfVar4,0x14);
                DAT_00a37de4 = DAT_00a37de4 + 1;
                uVar15 = 0;
              }
            }
            if (((local_30 < local_8) && (local_c <= iVar7)) && (iVar7 < local_4)) {
              pfVar1 = pfVar4 + uVar15 * 5;
              *pfVar1 = (float)local_30;
              uVar15 = uVar15 + 1;
              pfVar1[4] = fVar14;
              pfVar1[1] = (float)local_24;
              pfVar1[2] = fVar5;
              pfVar1[3] = 1.0;
              if (1999 < uVar15) {
                FUN_005d3b40(1,uVar15,pfVar4,0x14);
                DAT_00a37de4 = DAT_00a37de4 + 1;
                uVar15 = 0;
              }
            }
          }
        }
        if (local_4c < 0) {
          local_3c = local_3c + param_3;
          bVar2 = iVar8 <= local_3c;
          if (bVar2) {
            local_44 = local_44 + 1;
            local_2c = local_2c + 1;
            local_30 = local_30 + -1;
            local_3c = local_3c - iVar8;
          }
          local_48 = local_48 + local_44 * 4;
          local_4c = local_4c + 2 + local_44 * 4;
        }
        else {
          bVar2 = true;
          local_50 = local_50 + -1;
          param_8 = param_8 + 1;
          iVar7 = iVar7 + -1;
          local_24 = iVar7;
          if (local_48 < 0) {
            local_3c = local_3c + param_3;
            local_28 = local_28 + -4;
            if (iVar8 <= local_3c) {
              local_44 = local_44 + 1;
              local_2c = local_2c + 1;
              local_30 = local_30 + -1;
              local_3c = local_3c - iVar8;
            }
            iVar13 = (local_44 - local_50) * 4;
            local_4c = local_4c + 2 + iVar13;
            local_48 = local_48 + 2 + iVar13;
          }
          else {
            local_28 = local_28 + -4;
            local_4c = local_4c - local_28;
            local_48 = local_48 + (2 - local_28);
          }
        }
      } while (0 < (int)local_50);
    }
    if (uVar6 == 0) {
      iVar7 = param_1 - local_44;
      iVar8 = local_50 + param_2;
      if (((local_10 <= iVar7) && (iVar7 < local_8)) && ((local_c <= iVar8 && (iVar8 < local_4)))) {
        pfVar1 = pfVar4 + uVar15 * 5;
        *pfVar1 = (float)iVar7;
        pfVar1[4] = fVar14;
        uVar15 = uVar15 + 1;
        pfVar1[1] = (float)iVar8;
        pfVar1[2] = fVar5;
        pfVar1[3] = 1.0;
        if (1999 < uVar15) {
          FUN_005d3b40(1,uVar15,pfVar4,0x14);
          DAT_00a37de4 = DAT_00a37de4 + 1;
          uVar15 = 0;
        }
      }
      param_2 = param_2 - local_50;
      param_1 = param_1 + local_44;
      if ((((local_10 <= param_1) && (param_1 < local_8)) && (local_c <= param_2)) &&
         (param_2 < local_4)) {
        pfVar1 = pfVar4 + uVar15 * 5;
        *pfVar1 = (float)param_1;
        uVar15 = uVar15 + 1;
        pfVar1[4] = fVar14;
        pfVar1[1] = (float)param_2;
        pfVar1[2] = fVar5;
        pfVar1[3] = 1.0;
        if (1999 < uVar15) goto LAB_005b3b69;
      }
    }
LAB_005b3b65:
    if (uVar15 == 0) {
      return 0;
    }
  }
  else {
    iVar7 = (param_3 * param_3) / param_4;
    local_50 = 0;
    local_4c = param_3 * -2 + 3;
    local_48 = param_3 * -4 + 3;
    if (uVar12 == 0) {
      iVar8 = param_1 - param_3;
      if (((local_10 <= iVar8) && (iVar8 < local_8)) &&
         ((local_c <= param_2 && (param_2 < local_4)))) {
        pfVar4[4] = fVar14;
        *pfVar4 = (float)iVar8;
        pfVar4[2] = fVar5;
        uVar15 = 1;
        pfVar4[1] = (float)param_2;
        pfVar4[3] = 1.0;
      }
      iVar8 = (param_1 - uVar6) + param_3;
      if (((local_10 <= iVar8) && (iVar8 < local_8)) &&
         ((local_c <= param_2 && (param_2 < local_4)))) {
        pfVar1 = pfVar4 + uVar15 * 5;
        *pfVar1 = (float)iVar8;
        uVar15 = uVar15 + 1;
        pfVar1[4] = fVar14;
        pfVar1[1] = (float)param_2;
        pfVar1[2] = fVar5;
        pfVar1[3] = 1.0;
        if (1999 < uVar15) {
          FUN_005d3b40(1,uVar15,pfVar4,0x14);
          DAT_00a37de4 = DAT_00a37de4 + 1;
          uVar15 = 0;
        }
      }
    }
    if (local_4c < 0) {
      bVar2 = iVar7 <= param_4;
      local_3c = param_4;
      if (bVar2) {
        local_3c = param_4 - iVar7;
      }
      local_50 = (uint)bVar2;
      local_48 = local_48 + local_50 * 4;
      local_4c = param_3 * -2 + 5 + local_50 * 4;
      local_44 = param_3;
    }
    else {
      local_44 = param_3 + -1;
      bVar2 = true;
      if (local_48 < 0) {
        local_3c = param_4;
        if (iVar7 <= param_4) {
          local_3c = param_4 - iVar7;
        }
        local_50 = (uint)(iVar7 <= param_4);
        local_48 = (local_50 - local_44) * 4;
        local_4c = local_48 + 2 + local_4c;
        local_48 = param_3 * -4 + 5 + local_48;
      }
      else {
        local_4c = local_4c + local_44 * -4;
        local_48 = local_48 + local_44 * -4 + 2;
      }
    }
    if (0 < (int)local_44) {
      local_28 = local_44 * 4;
      local_2c = (local_44 - uVar6) + param_1;
      iVar8 = param_1 - local_44;
      local_40 = param_2 - local_50;
      local_30 = (local_50 - uVar12) + param_2;
      local_24 = iVar8;
      do {
        if (bVar2) {
          if ((((local_10 <= iVar8) && (iVar8 < local_8)) && (local_c <= local_30)) &&
             (local_30 < local_4)) {
            pfVar1 = pfVar4 + uVar15 * 5;
            *pfVar1 = (float)local_24;
            uVar15 = uVar15 + 1;
            pfVar1[4] = fVar14;
            pfVar1[2] = fVar5;
            pfVar1[1] = (float)local_30;
            pfVar1[3] = 1.0;
            if (1999 < uVar15) {
              FUN_005d3b40(1,uVar15,pfVar4,0x14);
              DAT_00a37de4 = DAT_00a37de4 + 1;
              uVar15 = 0;
            }
          }
          if (((local_10 <= local_2c) && (local_2c < local_8)) &&
             ((local_c <= local_30 && (local_30 < local_4)))) {
            pfVar1 = pfVar4 + uVar15 * 5;
            *pfVar1 = (float)local_2c;
            uVar15 = uVar15 + 1;
            pfVar1[4] = fVar14;
            pfVar1[2] = fVar5;
            pfVar1[1] = (float)local_30;
            pfVar1[3] = 1.0;
            if (1999 < uVar15) {
              FUN_005d3b40(1,uVar15,pfVar4,0x14);
              DAT_00a37de4 = DAT_00a37de4 + 1;
              uVar15 = 0;
            }
          }
          if (((local_10 <= iVar8) && (iVar8 < local_8)) &&
             ((local_c <= local_40 && (local_40 < local_4)))) {
            pfVar1 = pfVar4 + uVar15 * 5;
            *pfVar1 = (float)local_24;
            uVar15 = uVar15 + 1;
            pfVar1[4] = fVar14;
            pfVar1[2] = fVar5;
            pfVar1[1] = (float)local_40;
            pfVar1[3] = 1.0;
            if (1999 < uVar15) {
              FUN_005d3b40(1,uVar15,pfVar4,0x14);
              DAT_00a37de4 = DAT_00a37de4 + 1;
              uVar15 = 0;
            }
          }
          if ((((local_10 <= local_2c) && (local_2c < local_8)) && (local_c <= local_40)) &&
             (local_40 < local_4)) {
            pfVar1 = pfVar4 + uVar15 * 5;
            *pfVar1 = (float)local_2c;
            uVar15 = uVar15 + 1;
            pfVar1[4] = fVar14;
            pfVar1[2] = fVar5;
            pfVar1[1] = (float)local_40;
            pfVar1[3] = 1.0;
            if (1999 < uVar15) {
              FUN_005d3b40(1,uVar15,pfVar4,0x14);
              DAT_00a37de4 = DAT_00a37de4 + 1;
              uVar15 = 0;
            }
          }
        }
        if (local_4c < 0) {
          local_3c = local_3c + param_4;
          bVar2 = iVar7 <= local_3c;
          if (bVar2) {
            local_50 = local_50 + 1;
            local_30 = local_30 + 1;
            local_40 = local_40 + -1;
            local_3c = local_3c - iVar7;
          }
          local_48 = local_48 + local_50 * 4;
          local_4c = local_4c + 2 + local_50 * 4;
        }
        else {
          bVar2 = true;
          local_44 = local_44 + -1;
          local_2c = local_2c + -1;
          iVar8 = iVar8 + 1;
          local_24 = iVar8;
          if (local_48 < 0) {
            local_3c = local_3c + param_4;
            local_28 = local_28 + -4;
            if (iVar7 <= local_3c) {
              local_50 = local_50 + 1;
              local_30 = local_30 + 1;
              local_40 = local_40 + -1;
              local_3c = local_3c - iVar7;
            }
            iVar13 = (local_50 - local_44) * 4;
            local_4c = local_4c + 2 + iVar13;
            local_48 = local_48 + 2 + iVar13;
          }
          else {
            local_28 = local_28 + -4;
            local_4c = local_4c - local_28;
            local_48 = local_48 + (2 - local_28);
          }
        }
      } while (0 < (int)local_44);
    }
    if (uVar6 != 0) goto LAB_005b3b65;
    iVar7 = local_44 + param_1;
    iVar8 = param_2 - local_50;
    if (((local_10 <= iVar7) && (iVar7 < local_8)) && ((local_c <= iVar8 && (iVar8 < local_4)))) {
      pfVar1 = pfVar4 + uVar15 * 5;
      *pfVar1 = (float)iVar7;
      pfVar1[4] = fVar14;
      uVar15 = uVar15 + 1;
      pfVar1[1] = (float)iVar8;
      pfVar1[2] = fVar5;
      pfVar1[3] = 1.0;
      if (1999 < uVar15) {
        FUN_005d3b40(1,uVar15,pfVar4,0x14);
        DAT_00a37de4 = DAT_00a37de4 + 1;
        uVar15 = 0;
      }
    }
    param_1 = param_1 - local_44;
    param_2 = (local_50 - uVar12) + param_2;
    if (((param_1 < local_10) || (local_8 <= param_1)) ||
       ((param_2 < local_c || (local_4 <= param_2)))) goto LAB_005b3b65;
    pfVar1 = pfVar4 + uVar15 * 5;
    *pfVar1 = (float)param_1;
    uVar15 = uVar15 + 1;
    pfVar1[4] = fVar14;
    pfVar1[1] = (float)param_2;
    pfVar1[2] = fVar5;
    pfVar1[3] = 1.0;
    if (uVar15 < 2000) goto LAB_005b3b65;
  }
LAB_005b3b69:
  uVar9 = 1;
LAB_005b3b6f:
  FUN_005d3b40(uVar9,uVar15,pfVar4,0x14);
  DAT_00a37de4 = DAT_00a37de4 + 1;
  return 0;
}

