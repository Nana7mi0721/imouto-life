
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005b1460(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6,
            int param_7)

{
  float *pfVar1;
  float fVar2;
  float *pfVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  float fVar13;
  uint uVar14;
  int local_5c;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  uVar14 = 0;
  uVar5 = (uint)(param_6 != 0);
  uVar10 = (uint)(param_7 != 0);
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if ((DAT_00f3a04c == 0) || (iVar6 = FUN_0051c840(0,40000), pfVar3 = DAT_00a37f74, iVar6 < 0)) {
    return 0xffffffff;
  }
  iVar6 = FUN_005d35f0();
  if ((iVar6 != 0) && (DAT_00e79688 != 1)) {
    FUN_005d3930();
    DAT_00e79688 = 1;
    DAT_00e399fc = 0;
  }
  if (DAT_00e39a4c != 0) {
    FUN_0059bcf0(0);
  }
  if (((DAT_00a3d360 != 0) || (DAT_00e39a00 != 0)) || (DAT_00e399fc != 0x20)) {
    FUN_005a7f60();
  }
  iVar6 = DAT_00a381a0;
  fVar4 = DAT_00a380b8;
  local_10 = DAT_00a38194;
  local_c = DAT_00a38198;
  local_8 = DAT_00a3819c;
  local_4 = DAT_00a381a0;
  FUN_00544000(param_4,&local_1c,&local_18,&local_14);
  fVar13 = (float)((((DAT_00e79684 >> 0x10 & 0xff) * local_1c) / 0xff << 8 |
                   ((DAT_00e79684 >> 8 & 0xff) * local_18) / 0xff) << 8 |
                   ((DAT_00e79684 & 0xff) * local_14) / 0xff | DAT_00e79684 & 0xff000000);
  FUN_005a7ce0();
  local_54 = param_3;
  local_44 = param_3 * -2 + 3;
  if (param_5 == 0) {
    if (uVar10 == 0) {
      iVar6 = param_1 - param_3;
      if (((local_10 <= iVar6) && (iVar6 < local_8)) &&
         ((local_c <= param_2 && (param_2 < local_4)))) {
        pfVar3[4] = fVar13;
        pfVar3[2] = fVar4;
        *pfVar3 = (float)iVar6;
        uVar14 = 1;
        pfVar3[1] = (float)param_2;
        pfVar3[3] = 1.0;
      }
      iVar6 = (param_1 - uVar5) + param_3;
      if (((local_10 <= iVar6) && (iVar6 < local_8)) &&
         ((local_c <= param_2 && (param_2 < local_4)))) {
        pfVar1 = pfVar3 + uVar14 * 5;
        *pfVar1 = (float)iVar6;
        uVar14 = uVar14 + 1;
        pfVar1[4] = fVar13;
        pfVar1[2] = fVar4;
        pfVar1[1] = (float)param_2;
        pfVar1[3] = 1.0;
        if (1999 < uVar14) {
          FUN_005d3b40(1,uVar14,pfVar3,0x14);
          DAT_00a37de4 = DAT_00a37de4 + 1;
          uVar14 = 0;
        }
      }
    }
    if (uVar5 == 0) {
      iVar6 = (param_2 - uVar10) + param_3;
      if ((((local_10 <= param_1) && (param_1 < local_8)) && (local_c <= iVar6)) &&
         (iVar6 < local_4)) {
        pfVar1 = pfVar3 + uVar14 * 5;
        *pfVar1 = (float)param_1;
        uVar14 = uVar14 + 1;
        pfVar1[4] = fVar13;
        pfVar1[2] = fVar4;
        pfVar1[1] = (float)iVar6;
        pfVar1[3] = 1.0;
        if (1999 < uVar14) {
          FUN_005d3b40(1,uVar14,pfVar3,0x14);
          DAT_00a37de4 = DAT_00a37de4 + 1;
          uVar14 = 0;
        }
      }
      iVar6 = param_2 - param_3;
      if (((local_10 <= param_1) && (param_1 < local_8)) &&
         ((local_c <= iVar6 && (iVar6 < local_4)))) {
        pfVar1 = pfVar3 + uVar14 * 5;
        *pfVar1 = (float)param_1;
        uVar14 = uVar14 + 1;
        pfVar1[4] = fVar13;
        pfVar1[2] = fVar4;
        pfVar1[1] = (float)iVar6;
        pfVar1[3] = 1.0;
        if (1999 < uVar14) {
          FUN_005d3b40(1,uVar14,pfVar3,0x14);
          DAT_00a37de4 = DAT_00a37de4 + 1;
          uVar14 = 0;
        }
      }
    }
    if (-1 < local_44) {
      local_54 = param_3 + -1;
      local_44 = local_44 + local_54 * -4;
    }
    local_44 = local_44 + 6;
    if (0 < local_54) {
      local_24 = local_54 * 4;
      local_4c = param_2 - local_54;
      local_40 = param_1 - uVar5;
      local_38 = 4;
      local_3c = (local_54 - uVar5) + param_1;
      param_6 = (local_54 - uVar10) + param_2;
      param_7 = (param_2 - uVar10) + 1;
      iVar7 = param_2 - param_1;
      iVar6 = param_1 - param_2;
      while( true ) {
        local_40 = local_40 + 1;
        local_48 = param_1 + -1;
        iVar11 = local_4c + iVar6;
        if (((local_10 <= iVar11) && (iVar11 < local_8)) &&
           ((local_c <= param_7 && (param_7 < local_4)))) {
          pfVar1 = pfVar3 + uVar14 * 5;
          *pfVar1 = (float)iVar11;
          uVar14 = uVar14 + 1;
          pfVar1[4] = fVar13;
          pfVar1[2] = fVar4;
          pfVar1[1] = (float)param_7;
          pfVar1[3] = 1.0;
          if (1999 < uVar14) {
            FUN_005d3b40(1,uVar14,pfVar3,0x14);
            DAT_00a37de4 = DAT_00a37de4 + 1;
            uVar14 = 0;
          }
        }
        if ((((local_10 <= local_3c) && (local_3c < local_8)) && (local_c <= param_7)) &&
           (param_7 < local_4)) {
          pfVar1 = pfVar3 + uVar14 * 5;
          *pfVar1 = (float)local_3c;
          uVar14 = uVar14 + 1;
          pfVar1[4] = fVar13;
          pfVar1[2] = fVar4;
          pfVar1[1] = (float)param_7;
          pfVar1[3] = 1.0;
          if (1999 < uVar14) {
            FUN_005d3b40(1,uVar14,pfVar3,0x14);
            DAT_00a37de4 = DAT_00a37de4 + 1;
            uVar14 = 0;
          }
        }
        if (((local_10 <= local_40) && (local_40 < local_8)) &&
           ((local_c <= param_6 && (param_6 < local_4)))) {
          pfVar1 = pfVar3 + uVar14 * 5;
          *pfVar1 = (float)local_40;
          uVar14 = uVar14 + 1;
          pfVar1[4] = fVar13;
          pfVar1[2] = fVar4;
          pfVar1[1] = (float)param_6;
          pfVar1[3] = 1.0;
          if (1999 < uVar14) {
            FUN_005d3b40(1,uVar14,pfVar3,0x14);
            DAT_00a37de4 = DAT_00a37de4 + 1;
            uVar14 = 0;
          }
        }
        if (((local_10 <= local_48) && (local_48 < local_8)) &&
           ((local_c <= param_6 && (param_6 < local_4)))) {
          pfVar1 = pfVar3 + uVar14 * 5;
          *pfVar1 = (float)local_48;
          uVar14 = uVar14 + 1;
          pfVar1[4] = fVar13;
          pfVar1[2] = fVar4;
          pfVar1[1] = (float)param_6;
          pfVar1[3] = 1.0;
          if (1999 < uVar14) {
            FUN_005d3b40(1,uVar14,pfVar3,0x14);
            DAT_00a37de4 = DAT_00a37de4 + 1;
            uVar14 = 0;
          }
        }
        if ((((local_10 <= local_3c) && (local_3c < local_8)) &&
            (iVar9 = iVar7 + local_48, local_c <= iVar9)) && (iVar9 < local_4)) {
          pfVar1 = pfVar3 + uVar14 * 5;
          *pfVar1 = (float)local_3c;
          uVar14 = uVar14 + 1;
          pfVar1[4] = fVar13;
          pfVar1[2] = fVar4;
          pfVar1[1] = (float)iVar9;
          pfVar1[3] = 1.0;
          if (1999 < uVar14) {
            FUN_005d3b40(1,uVar14,pfVar3,0x14);
            DAT_00a37de4 = DAT_00a37de4 + 1;
            uVar14 = 0;
          }
        }
        if (((local_10 <= iVar11) && (iVar11 < local_8)) &&
           ((iVar9 = local_48 + iVar7, local_c <= iVar9 && (iVar9 < local_4)))) {
          pfVar1 = pfVar3 + uVar14 * 5;
          *pfVar1 = (float)iVar11;
          uVar14 = uVar14 + 1;
          pfVar1[4] = fVar13;
          pfVar1[2] = fVar4;
          pfVar1[1] = (float)iVar9;
          pfVar1[3] = 1.0;
          if (1999 < uVar14) {
            FUN_005d3b40(1,uVar14,pfVar3,0x14);
            DAT_00a37de4 = DAT_00a37de4 + 1;
            uVar14 = 0;
          }
        }
        if (((local_10 <= local_40) && (local_40 < local_8)) &&
           ((local_c <= local_4c && (local_4c < local_4)))) {
          pfVar1 = pfVar3 + uVar14 * 5;
          *pfVar1 = (float)local_40;
          uVar14 = uVar14 + 1;
          pfVar1[4] = fVar13;
          pfVar1[2] = fVar4;
          pfVar1[1] = (float)local_4c;
          pfVar1[3] = 1.0;
          if (1999 < uVar14) {
            FUN_005d3b40(1,uVar14,pfVar3,0x14);
            DAT_00a37de4 = DAT_00a37de4 + 1;
            uVar14 = 0;
          }
        }
        if ((((local_10 <= local_48) && (local_48 < local_8)) && (local_c <= local_4c)) &&
           (local_4c < local_4)) {
          pfVar1 = pfVar3 + uVar14 * 5;
          *pfVar1 = (float)local_48;
          uVar14 = uVar14 + 1;
          pfVar1[4] = fVar13;
          pfVar1[2] = fVar4;
          pfVar1[1] = (float)local_4c;
          pfVar1[3] = 1.0;
          if (1999 < uVar14) {
            FUN_005d3b40(1,uVar14,pfVar3,0x14);
            DAT_00a37de4 = DAT_00a37de4 + 1;
            uVar14 = 0;
          }
        }
        if (-1 < local_44) {
          local_54 = local_54 + -1;
          param_6 = param_6 + -1;
          local_3c = local_3c + -1;
          local_4c = local_4c + 1;
          local_24 = local_24 + -4;
          local_44 = local_44 - local_24;
        }
        param_7 = param_7 + 1;
        local_38 = local_38 + 4;
        local_44 = local_44 + 2 + local_38;
        if (local_54 < (int)(param_7 + (uVar10 - param_2))) break;
        param_1 = local_48;
      }
    }
    if (uVar14 == 0) {
      return 0;
    }
    uVar8 = 1;
  }
  else {
    iVar7 = FUN_0051c840(1,iVar6);
    iVar6 = DAT_00a37f78;
    if (iVar7 < 0) {
      uVar8 = FUN_0056bb10(&DAT_007fcbc0);
      return uVar8;
    }
    FUN_0056d380(DAT_00a37f78,0,local_4);
    if (uVar10 == 0) {
      iVar7 = (param_1 - uVar5) + param_3;
      local_5c = param_1 - param_3;
      if (((local_10 <= iVar7) && (local_5c < local_8)) &&
         ((local_c <= param_2 && ((param_2 < local_4 && (*(char *)(iVar6 + param_2) == '\0')))))) {
        if (local_5c < local_10) {
          local_5c = local_10;
        }
        if (local_8 + -1 < iVar7) {
          iVar7 = local_8 + -1;
        }
        fVar2 = (float)local_5c + _DAT_00ddb4c4;
        pfVar3[4] = fVar13;
        pfVar3[2] = fVar4;
        *pfVar3 = fVar2;
        pfVar3[1] = (float)param_2;
        uVar14 = 2;
        pfVar3[3] = 1.0;
        *(undefined1 *)(iVar6 + param_2) = 1;
        fVar2 = (float)(iVar7 + 1) + _DAT_00ddb4c8;
        pfVar3[9] = fVar13;
        pfVar3[7] = fVar4;
        pfVar3[5] = fVar2;
        pfVar3[6] = (float)param_2;
        pfVar3[8] = 1.0;
      }
    }
    if (-1 < local_44) {
      iVar11 = param_1 - uVar5;
      local_5c = param_1;
      iVar7 = (param_2 - uVar10) + param_3;
      if ((((local_10 <= iVar11) && (param_1 < local_8)) && (local_c <= iVar7)) &&
         ((iVar7 < local_4 && (*(char *)(iVar7 + iVar6) == '\0')))) {
        if (param_1 < local_10) {
          local_5c = local_10;
        }
        local_50 = iVar11;
        if (local_8 + -1 < iVar11) {
          local_50 = local_8 + -1;
        }
        pfVar1 = pfVar3 + uVar14 * 5;
        fVar2 = (float)local_5c + _DAT_00ddb4c4;
        pfVar1[4] = fVar13;
        pfVar1[2] = fVar4;
        *pfVar1 = fVar2;
        pfVar1[1] = (float)iVar7;
        pfVar1[3] = 1.0;
        *(undefined1 *)(iVar7 + iVar6) = 1;
        pfVar1 = pfVar3 + (uVar14 + 1) * 5;
        uVar14 = uVar14 + 2;
        fVar2 = (float)(local_50 + 1) + _DAT_00ddb4c8;
        pfVar1[4] = fVar13;
        pfVar1[2] = fVar4;
        *pfVar1 = fVar2;
        pfVar1[1] = (float)iVar7;
        pfVar1[3] = 1.0;
        if (1999 < uVar14) {
          FUN_005d3b40(2,uVar14 >> 1,pfVar3,0x14);
          DAT_00a37de4 = DAT_00a37de4 + 1;
          uVar14 = 0;
        }
      }
      iVar7 = param_2 - param_3;
      local_5c = param_1;
      if (((local_10 <= iVar11) && (param_1 < local_8)) &&
         ((local_c <= iVar7 && ((iVar7 < local_4 && (*(char *)(iVar7 + iVar6) == '\0')))))) {
        if (param_1 < local_10) {
          local_5c = local_10;
        }
        local_50 = iVar11;
        if (local_8 + -1 < iVar11) {
          local_50 = local_8 + -1;
        }
        pfVar1 = pfVar3 + uVar14 * 5;
        fVar2 = (float)local_5c + _DAT_00ddb4c4;
        pfVar1[4] = fVar13;
        pfVar1[2] = fVar4;
        *pfVar1 = fVar2;
        pfVar1[1] = (float)iVar7;
        pfVar1[3] = 1.0;
        *(undefined1 *)(iVar7 + iVar6) = 1;
        pfVar1 = pfVar3 + (uVar14 + 1) * 5;
        uVar14 = uVar14 + 2;
        fVar2 = (float)(local_50 + 1) + _DAT_00ddb4c8;
        pfVar1[4] = fVar13;
        pfVar1[2] = fVar4;
        *pfVar1 = fVar2;
        pfVar1[1] = (float)iVar7;
        pfVar1[3] = 1.0;
        if (1999 < uVar14) {
          FUN_005d3b40(2,uVar14 >> 1,pfVar3,0x14);
          DAT_00a37de4 = DAT_00a37de4 + 1;
          uVar14 = 0;
        }
      }
      local_54 = param_3 + -1;
      local_44 = local_44 + local_54 * -4;
    }
    local_44 = local_44 + 6;
    if (0 < local_54) {
      local_24 = local_54 * 4;
      local_40 = param_2 - local_54;
      local_20 = 4;
      local_3c = param_1 - uVar5;
      local_38 = (local_54 - uVar10) + param_2;
      param_6 = (local_54 - uVar5) + param_1;
      local_34 = (param_2 - uVar10) + 1;
      iVar7 = param_1 - param_2;
      iVar11 = param_2 - param_1;
      do {
        local_3c = local_3c + 1;
        local_48 = param_1 + -1;
        iVar9 = iVar7 + local_40;
        if ((((local_10 <= param_6) && (iVar9 < local_8)) && (local_c <= local_34)) &&
           ((local_34 < local_4 && (*(char *)(local_34 + iVar6) == '\0')))) {
          local_5c = iVar9;
          if (iVar9 < local_10) {
            local_5c = local_10;
          }
          iVar12 = param_6;
          if (local_8 + -1 < param_6) {
            iVar12 = local_8 + -1;
          }
          pfVar1 = pfVar3 + uVar14 * 5;
          fVar2 = (float)local_5c + _DAT_00ddb4c4;
          pfVar1[4] = fVar13;
          pfVar1[2] = fVar4;
          *pfVar1 = fVar2;
          pfVar1[1] = (float)local_34;
          pfVar1[3] = 1.0;
          *(undefined1 *)(iVar6 + local_34) = 1;
          pfVar1 = pfVar3 + (uVar14 + 1) * 5;
          uVar14 = uVar14 + 2;
          *pfVar1 = (float)(iVar12 + 1) + _DAT_00ddb4c8;
          pfVar1[4] = fVar13;
          pfVar1[2] = fVar4;
          pfVar1[1] = (float)local_34;
          pfVar1[3] = 1.0;
          if (1999 < uVar14) {
            FUN_005d3b40(2,uVar14 >> 1,pfVar3,0x14);
            DAT_00a37de4 = DAT_00a37de4 + 1;
            uVar14 = 0;
          }
        }
        if (((local_10 <= param_6) && (iVar9 < local_8)) &&
           ((iVar12 = iVar11 + local_48, local_c <= iVar12 &&
            ((iVar12 < local_4 && (*(char *)(iVar12 + iVar6) == '\0')))))) {
          local_5c = iVar9;
          if (iVar9 < local_10) {
            local_5c = local_10;
          }
          iVar9 = local_8 + -1;
          if (param_6 <= local_8 + -1) {
            iVar9 = param_6;
          }
          pfVar1 = pfVar3 + uVar14 * 5;
          fVar2 = (float)local_5c + _DAT_00ddb4c4;
          pfVar1[4] = fVar13;
          pfVar1[2] = fVar4;
          *pfVar1 = fVar2;
          pfVar1[1] = (float)iVar12;
          pfVar1[3] = 1.0;
          *(undefined1 *)(iVar12 + iVar6) = 1;
          pfVar1 = pfVar3 + (uVar14 + 1) * 5;
          fVar2 = (float)(iVar9 + 1) + _DAT_00ddb4c8;
          uVar14 = uVar14 + 2;
          pfVar1[4] = fVar13;
          *pfVar1 = fVar2;
          pfVar1[2] = fVar4;
          pfVar1[1] = (float)iVar12;
          pfVar1[3] = 1.0;
          if (1999 < uVar14) {
            FUN_005d3b40(2,uVar14 >> 1,pfVar3,0x14);
            DAT_00a37de4 = DAT_00a37de4 + 1;
            uVar14 = 0;
          }
        }
        if (-1 < local_44) {
          local_5c = local_48;
          if ((((local_10 <= local_3c) && (local_48 < local_8)) && (local_c <= local_38)) &&
             ((local_38 < local_4 && (*(char *)(local_38 + iVar6) == '\0')))) {
            if (local_48 < local_10) {
              local_5c = local_10;
            }
            iVar9 = local_3c;
            if (local_8 + -1 < local_3c) {
              iVar9 = local_8 + -1;
            }
            pfVar1 = pfVar3 + uVar14 * 5;
            fVar2 = (float)local_5c + _DAT_00ddb4c4;
            pfVar1[4] = fVar13;
            pfVar1[2] = fVar4;
            *pfVar1 = fVar2;
            pfVar1[1] = (float)local_38;
            pfVar1[3] = 1.0;
            *(undefined1 *)(local_38 + iVar6) = 1;
            pfVar1 = pfVar3 + (uVar14 + 1) * 5;
            fVar2 = (float)(iVar9 + 1) + _DAT_00ddb4c8;
            uVar14 = uVar14 + 2;
            pfVar1[4] = fVar13;
            *pfVar1 = fVar2;
            pfVar1[2] = fVar4;
            pfVar1[1] = (float)local_38;
            pfVar1[3] = 1.0;
            if (1999 < uVar14) {
              FUN_005d3b40(2,uVar14 >> 1,pfVar3,0x14);
              DAT_00a37de4 = DAT_00a37de4 + 1;
              uVar14 = 0;
            }
          }
          local_5c = local_48;
          if (((local_10 <= local_3c) && (local_48 < local_8)) &&
             ((local_c <= local_40 &&
              ((local_40 < local_4 && (*(char *)(local_40 + iVar6) == '\0')))))) {
            if (local_48 < local_10) {
              local_5c = local_10;
            }
            iVar9 = local_3c;
            if (local_8 + -1 < local_3c) {
              iVar9 = local_8 + -1;
            }
            pfVar1 = pfVar3 + uVar14 * 5;
            fVar2 = (float)local_5c + _DAT_00ddb4c4;
            pfVar1[4] = fVar13;
            pfVar1[2] = fVar4;
            *pfVar1 = fVar2;
            pfVar1[1] = (float)local_40;
            pfVar1[3] = 1.0;
            *(undefined1 *)(iVar6 + local_40) = 1;
            pfVar1 = pfVar3 + (uVar14 + 1) * 5;
            uVar14 = uVar14 + 2;
            *pfVar1 = (float)(iVar9 + 1) + _DAT_00ddb4c8;
            pfVar1[4] = fVar13;
            pfVar1[2] = fVar4;
            pfVar1[1] = (float)local_40;
            pfVar1[3] = 1.0;
            if (1999 < uVar14) {
              FUN_005d3b40(2,uVar14 >> 1,pfVar3,0x14);
              DAT_00a37de4 = DAT_00a37de4 + 1;
              uVar14 = 0;
            }
          }
          local_54 = local_54 + -1;
          param_6 = param_6 + -1;
          local_38 = local_38 + -1;
          local_40 = local_40 + 1;
          local_24 = local_24 + -4;
          local_44 = local_44 - local_24;
        }
        local_20 = local_20 + 4;
        local_44 = local_44 + 2 + local_20;
        local_34 = local_34 + 1;
        param_1 = local_48;
      } while ((int)((uVar10 - param_2) + local_34) <= local_54);
    }
    if (uVar14 == 0) {
      return 0;
    }
    uVar14 = uVar14 >> 1;
    uVar8 = 2;
  }
  FUN_005d3b40(uVar8,uVar14,pfVar3,0x14);
  DAT_00a37de4 = DAT_00a37de4 + 1;
  return 0;
}

