
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00520930(float *param_1,int param_2,undefined4 param_3,uint param_4,undefined4 param_5,
            int param_6)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  float *pfVar5;
  float *pfVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  int *local_20;
  uint local_18;
  int local_10;
  
  local_24 = 0.0;
  local_28 = 0.0;
  local_2c = 1.0;
  local_30 = 1.0;
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  local_20 = (int *)0x0;
  if (param_4 == 0xfffffffb) {
    local_18 = DAT_00a37d78;
    param_6 = 0;
  }
  else {
    if (DAT_00cc47d0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_4 < 0) {
      return 0xffffffff;
    }
    if ((param_4 & 0x7c000000) != DAT_00cc47f8) {
      return 0xffffffff;
    }
    if (DAT_00cc4800 <= (int)(param_4 & 0xffff)) {
      return 0xffffffff;
    }
    local_20 = *(int **)(DAT_00cc47d4 + (param_4 & 0xffff) * 4);
    if (local_20 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*local_20 * 0x10000 != (param_4 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (local_20[4] != 0) {
      return 0xffffffff;
    }
    local_18 = (uint)*(byte *)(local_20[0x13] + 8);
    if ((param_6 != 0) &&
       ((*(byte *)(local_20[0x13] + 8) == 0 ||
        (((local_20[0x22] == 1 && (*(int *)(local_20[0x40] + 0x14) == local_20[0x2b])) &&
         (*(int *)(local_20[0x40] + 0x18) == local_20[0x2c])))))) {
      param_6 = 0;
    }
    FUN_0057b670(local_20[0xd],0);
    if (param_6 != 0) {
      local_2c = (float)*(int *)(local_20[0x40] + 0x14);
      local_24 = (float)local_20[0x29] / local_2c;
      local_30 = (float)*(int *)(local_20[0x40] + 0x18);
      local_28 = (float)local_20[0x2a] / local_30;
      local_2c = (float)local_20[0x2d] / local_2c;
      local_30 = (float)local_20[0x2e] / local_30;
    }
  }
  pfVar5 = (float *)FUN_0056e030(param_2 * 0x1c,
                                 "..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp",0x3587);
  cVar4 = DAT_00a38116;
  cVar3 = DAT_00a38115;
  cVar2 = DAT_00a38114;
  if (pfVar5 == (float *)0x0) {
    return 0xffffffff;
  }
  if (((DAT_00a38116 == -1) && (DAT_00a38115 == -1)) &&
     ((DAT_00a38114 == -1 && ((DAT_00a380cc == 0 || (DAT_00a380d0 == 0xff)))))) {
    if (param_6 == 0) {
      if (0 < param_2) {
        pfVar6 = pfVar5 + 2;
        iVar8 = param_2;
        do {
          pfVar6[-2] = *param_1;
          iVar8 = iVar8 + -1;
          pfVar6[-1] = param_1[1];
          *pfVar6 = DAT_00a380b8;
          pfVar6[1] = 1.0;
          pfVar6[2] = param_1[4];
          pfVar6[3] = param_1[2];
          pfVar6[4] = param_1[3];
          pfVar6 = pfVar6 + 7;
          param_1 = param_1 + 5;
        } while (iVar8 != 0);
      }
    }
    else if (0 < param_2) {
      pfVar6 = pfVar5 + 2;
      iVar8 = param_2;
      do {
        pfVar6[-2] = *param_1;
        iVar8 = iVar8 + -1;
        pfVar6[-1] = param_1[1];
        *pfVar6 = DAT_00a380b8;
        pfVar6[1] = 1.0;
        pfVar6[2] = param_1[4];
        pfVar6[3] = param_1[2] * local_2c + local_24;
        pfVar6[4] = param_1[3] * local_30 + local_28;
        pfVar6 = pfVar6 + 7;
        param_1 = param_1 + 5;
      } while (iVar8 != 0);
    }
  }
  else {
    puVar9 = &DAT_00d0a2e0 + DAT_00a380d0 * 0x100;
    if (DAT_00a380cc == 0) {
      puVar9 = (undefined4 *)&DAT_00d49ee0;
    }
    if (param_6 == 0) {
      if (0 < param_2) {
        param_4 = param_2;
        pfVar6 = pfVar5 + 2;
        do {
          pfVar6[-2] = *param_1;
          param_4 = param_4 + -1;
          pfVar6[-1] = param_1[1];
          *pfVar6 = DAT_00a380b8;
          pfVar6[1] = 1.0;
          *(undefined1 *)(pfVar6 + 2) =
               *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar2,*(undefined1 *)(param_1 + 4)));
          *(undefined1 *)((int)pfVar6 + 9) =
               *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar3,*(undefined1 *)((int)param_1 + 0x11)))
          ;
          *(undefined1 *)((int)pfVar6 + 10) =
               *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar4,*(undefined1 *)((int)param_1 + 0x12)))
          ;
          *(undefined1 *)((int)pfVar6 + 0xb) =
               *(undefined1 *)(puVar9 + *(byte *)((int)param_1 + 0x13));
          pfVar6[3] = param_1[2];
          pfVar6[4] = param_1[3];
          pfVar6 = pfVar6 + 7;
          param_1 = param_1 + 5;
        } while (param_4 != 0);
      }
    }
    else if (0 < param_2) {
      param_4 = param_2;
      pfVar6 = pfVar5 + 2;
      do {
        pfVar6[-2] = *param_1;
        param_4 = param_4 + -1;
        pfVar6[-1] = param_1[1];
        *pfVar6 = DAT_00a380b8;
        pfVar6[1] = 1.0;
        *(undefined1 *)(pfVar6 + 2) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar2,*(undefined1 *)(param_1 + 4)));
        *(undefined1 *)((int)pfVar6 + 9) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar3,*(undefined1 *)((int)param_1 + 0x11)));
        *(undefined1 *)((int)pfVar6 + 10) =
             *(undefined1 *)(&DAT_00d0a2e0 + CONCAT11(cVar4,*(undefined1 *)((int)param_1 + 0x12)));
        *(undefined1 *)((int)pfVar6 + 0xb) =
             *(undefined1 *)(puVar9 + *(byte *)((int)param_1 + 0x13));
        pfVar6[3] = param_1[2] * local_2c + local_24;
        pfVar6[4] = param_1[3] * local_30 + local_28;
        pfVar6 = pfVar6 + 7;
        param_1 = param_1 + 5;
      } while (param_4 != 0);
    }
  }
  if ((DAT_00a381c4 == 0) && (DAT_00a37d78 != 0)) {
    FUN_005198b0();
  }
  if (((DAT_00a380cc == 3) && (DAT_00a37d8c == 0)) && (local_18 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
    if (DAT_00ca39f4 == 0) {
      if (local_18 == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = FUN_005690f0(pfVar5,param_2,param_3,local_20,param_5,0,0,0,0,0,0);
      }
      goto LAB_0052125e;
    }
  }
  local_30 = _DAT_007d5564;
  local_2c = _DAT_007d5564;
  iVar8 = 0;
  local_28 = _DAT_007d5560;
  local_24 = _DAT_007d5560;
  pfVar6 = pfVar5;
  if (3 < param_2) {
    iVar10 = (param_2 - 4U >> 2) + 1;
    iVar8 = iVar10 * 4;
    do {
      if (*pfVar6 - 1.0 < local_30) {
        local_30 = *pfVar6 - 1.0;
      }
      if (local_28 < *pfVar6 + 1.0) {
        local_28 = *pfVar6 + 1.0;
      }
      if (pfVar6[1] - 1.0 < local_2c) {
        local_2c = pfVar6[1] - 1.0;
      }
      if (local_24 < pfVar6[1] + 1.0) {
        local_24 = pfVar6[1] + 1.0;
      }
      if (pfVar6[7] - 1.0 < local_30) {
        local_30 = pfVar6[7] - 1.0;
      }
      if (local_28 < pfVar6[7] + 1.0) {
        local_28 = pfVar6[7] + 1.0;
      }
      if (pfVar6[8] - 1.0 < local_2c) {
        local_2c = pfVar6[8] - 1.0;
      }
      if (local_24 < pfVar6[8] + 1.0) {
        local_24 = pfVar6[8] + 1.0;
      }
      if (pfVar6[0xe] - 1.0 < local_30) {
        local_30 = pfVar6[0xe] - 1.0;
      }
      if (local_28 < pfVar6[0xe] + 1.0) {
        local_28 = pfVar6[0xe] + 1.0;
      }
      if (pfVar6[0xf] - 1.0 < local_2c) {
        local_2c = pfVar6[0xf] - 1.0;
      }
      if (local_24 < pfVar6[0xf] + 1.0) {
        local_24 = pfVar6[0xf] + 1.0;
      }
      if (pfVar6[0x15] - 1.0 < local_30) {
        local_30 = pfVar6[0x15] - 1.0;
      }
      if (local_28 < pfVar6[0x15] + 1.0) {
        local_28 = pfVar6[0x15] + 1.0;
      }
      if (pfVar6[0x16] - 1.0 < local_2c) {
        local_2c = pfVar6[0x16] - 1.0;
      }
      if (local_24 < pfVar6[0x16] + 1.0) {
        local_24 = pfVar6[0x16] + 1.0;
      }
      pfVar6 = pfVar6 + 0x1c;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  if (iVar8 < param_2) {
    iVar8 = param_2 - iVar8;
    do {
      if (*pfVar6 - 1.0 < local_30) {
        local_30 = *pfVar6 - 1.0;
      }
      if (local_28 < *pfVar6 + 1.0) {
        local_28 = *pfVar6 + 1.0;
      }
      if (pfVar6[1] - 1.0 < local_2c) {
        local_2c = pfVar6[1] - 1.0;
      }
      if (local_24 < pfVar6[1] + 1.0) {
        local_24 = pfVar6[1] + 1.0;
      }
      pfVar6 = pfVar6 + 7;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  local_10 = (int)ROUND(local_30);
  iVar8 = (int)ROUND(local_2c);
  iVar10 = (int)ROUND(local_28);
  iVar12 = (int)ROUND(local_24);
  if (-1 < (int)((DAT_00a38198 - iVar8) - 1U & (DAT_00a38194 - local_10) - 1U &
                 (iVar12 - DAT_00a381a0) - 1U & (iVar10 - DAT_00a3819c) - 1U)) {
    if (local_10 < DAT_00a38194) {
      local_10 = DAT_00a38194;
    }
    if (iVar10 < DAT_00a38194) {
      iVar10 = DAT_00a38194;
    }
    if (DAT_00a3819c < local_10) {
      local_10 = DAT_00a3819c;
    }
    if (DAT_00a3819c < iVar10) {
      iVar10 = DAT_00a3819c;
    }
    if (iVar8 < DAT_00a38198) {
      iVar8 = DAT_00a38198;
    }
    iVar11 = DAT_00a38198;
    if (DAT_00a38198 <= iVar12) {
      iVar11 = iVar12;
    }
    if (DAT_00a381a0 < iVar8) {
      iVar8 = DAT_00a381a0;
    }
    iVar12 = iVar11;
    if (DAT_00a381a0 < iVar11) {
      iVar12 = DAT_00a381a0;
    }
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057b170(local_10,iVar8,iVar10,iVar12);
  }
  if (bVar1) {
    FUN_00519580();
    uVar7 = FUN_005690f0(pfVar5,param_2,param_3,local_20,param_5,0,0,0,0,0,0);
    FUN_00519650();
  }
  else if (local_18 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = FUN_005690f0(pfVar5,param_2,param_3,local_20,param_5,0,0,0,0,0,0);
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057ae10(local_10,iVar8,iVar10,iVar12);
  }
LAB_0052125e:
  FUN_0056e1d0(pfVar5);
  return uVar7;
}

