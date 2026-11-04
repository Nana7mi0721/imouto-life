
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4
FUN_00518060(int *param_1,uint param_2,int param_3,undefined4 param_4,HANDLE param_5,HANDLE param_6,
            int param_7,int param_8,int param_9,int param_10,undefined1 *param_11,
            undefined1 *param_12,undefined4 param_13,undefined4 param_14,uint param_15,int param_16)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined *puVar5;
  int local_10b8;
  int local_10b4;
  undefined1 local_10b0 [4];
  undefined4 local_10ac;
  undefined4 local_10a8;
  undefined4 local_109c;
  undefined1 local_1098 [4];
  undefined4 local_1094;
  undefined4 local_1090;
  undefined4 local_1084;
  undefined1 local_1080 [1064];
  undefined4 local_c58;
  undefined4 local_c54;
  int local_c50;
  undefined4 local_c4c;
  undefined1 local_c40 [1064];
  undefined4 local_818;
  undefined4 local_814;
  int local_810;
  undefined4 local_80c;
  undefined1 local_800 [2044];
  undefined4 uStack_4;
  
  uStack_4 = 0x51806a;
  local_10b8 = 0;
  if (param_16 == 0) {
    if (DAT_00cc47d0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_2 < 0) {
      return 0xffffffff;
    }
    if ((param_2 & 0x7c000000) != DAT_00cc47f8) {
      return 0xffffffff;
    }
    if (DAT_00cc4800 <= (int)(param_2 & 0xffff)) {
      return 0xffffffff;
    }
    piVar4 = *(int **)(DAT_00cc47d4 + (param_2 & 0xffff) * 4);
    if (piVar4 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar4 * 0x10000 != (param_2 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar4[4] != 0) {
      return 0xffffffff;
    }
  }
  else {
    if (DAT_00cc47d0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_2 < 0) {
      return 0xffffffff;
    }
    if ((param_2 & 0x7c000000) != DAT_00cc47f8) {
      return 0xffffffff;
    }
    if (DAT_00cc4800 <= (int)(param_2 & 0xffff)) {
      return 0xffffffff;
    }
    piVar4 = *(int **)(DAT_00cc47d4 + (param_2 & 0xffff) * 4);
    if (piVar4 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar4 * 0x10000 != (param_2 & 0x3ff0000)) {
      return 0xffffffff;
    }
  }
  if (((-1 < (int)param_15) && ((param_15 & 0x7c000000) == DAT_00cc47f8)) &&
     ((int)(param_15 & 0xffff) < DAT_00cc4800)) {
    local_10b8 = *(int *)(DAT_00cc47d4 + (param_15 & 0xffff) * 4);
  }
  if (piVar4[0xe] != 0) {
    piVar1 = (int *)(piVar4[0xe] + 0x28);
    *piVar1 = *piVar1 + -1;
    if (*(int *)(piVar4[0xe] + 0x28) == 0) {
      FUN_0056e1d0(piVar4[0xe]);
      piVar4[0xe] = 0;
    }
  }
  if (param_5 != (HANDLE)0x0) {
    GetObjectA(param_5,0x18,local_1098);
    FUN_0056d380(local_1080,0,0x440);
    local_c4c = local_1084;
    local_c54 = local_1090;
    local_c50 = ((int)(local_c50 + 3 + (local_c50 + 3 >> 0x1f & 3U)) >> 2) * 4;
    local_c58 = local_1094;
    FUN_0056d420(local_1080,param_4,0x428);
    param_11 = local_1080;
    if (param_6 != (HANDLE)0x0) {
      GetObjectA(param_6,0x18,local_10b0);
      FUN_0056d380(local_c40,0,0x440);
      local_80c = local_109c;
      local_814 = local_10a8;
      local_810 = ((int)(local_810 + 3 + (local_810 + 3 >> 0x1f & 3U)) >> 2) * 4;
      local_818 = local_10ac;
      FUN_0056d420(local_c40,param_4,0x428);
      param_12 = local_c40;
    }
  }
  if (*param_1 == 0) {
    if (((param_3 == 0) && (param_7 == 0)) && (param_11 == (undefined1 *)0x0)) {
      if (local_10b8 == 0) goto LAB_005182ff;
    }
    else if (local_10b8 == 0) {
      if (param_3 == 0) {
        if (param_7 == 0) {
          if (param_11 != (undefined1 *)0x0) {
            local_10b4 = 0;
            iVar2 = FUN_00542060(param_11);
            local_10b8 = iVar2 + 0x440;
            if (param_12 != (undefined1 *)0x0) {
              local_10b4 = FUN_00542060(param_12);
              local_10b8 = iVar2 + 0x880 + local_10b4;
            }
            iVar3 = FUN_0056e030(local_10b8 + 0x2c,
                                 "..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp",0x67f4);
            piVar4[0xe] = iVar3;
            if (iVar3 == 0) {
              puVar5 = &DAT_007d53e8;
              goto LAB_0051838d;
            }
            FUN_0056d380(iVar3,0,0x2c);
            *(int *)(piVar4[0xe] + 8) = piVar4[0xe] + 0x2c;
            FUN_0056d420(*(undefined4 *)(piVar4[0xe] + 8),param_11,0x440);
            *(int *)(*(int *)(piVar4[0xe] + 8) + 0x434) = *(int *)(piVar4[0xe] + 8) + 0x440;
            FUN_0056d420(*(undefined4 *)(*(int *)(piVar4[0xe] + 8) + 0x434),
                         *(undefined4 *)(param_11 + 0x434),iVar2);
            if (param_12 != (undefined1 *)0x0) {
              *(int *)(piVar4[0xe] + 0xc) = *(int *)(*(int *)(piVar4[0xe] + 8) + 0x434) + iVar2;
              FUN_0056d420(*(undefined4 *)(piVar4[0xe] + 0xc),param_12,0x440);
              *(int *)(*(int *)(piVar4[0xe] + 0xc) + 0x434) = *(int *)(piVar4[0xe] + 0xc) + 0x440;
              FUN_0056d420(*(undefined4 *)(*(int *)(piVar4[0xe] + 0xc) + 0x434),
                           *(undefined4 *)(param_12 + 0x434),local_10b4);
            }
          }
        }
        else {
          iVar2 = FUN_0056e030(param_8 + 0x2c + param_10,
                               "..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp",0x67d0);
          piVar4[0xe] = iVar2;
          if (iVar2 == 0) {
            puVar5 = &DAT_007d5428;
            goto LAB_0051838d;
          }
          FUN_0056d380(iVar2,0,0x2c);
          *(int *)(piVar4[0xe] + 0x10) = piVar4[0xe] + 0x2c;
          *(int *)(piVar4[0xe] + 0x14) = param_8;
          FUN_0056d420(*(undefined4 *)(piVar4[0xe] + 0x10),param_7,param_8);
          if (param_9 != 0) {
            *(int *)(piVar4[0xe] + 0x18) = *(int *)(piVar4[0xe] + 0x10) + param_8;
            *(int *)(piVar4[0xe] + 0x1c) = param_10;
            FUN_0056d420(*(undefined4 *)(piVar4[0xe] + 0x18),param_9,param_10);
          }
        }
      }
      else {
        FUN_0052d510(param_3,local_800,0x800,0);
        iVar2 = FUN_0050e220(local_800);
        iVar3 = FUN_0056e050(iVar2 * 2 + 0x2e,
                             "..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp",0x67c0);
        piVar4[0xe] = iVar3;
        if (iVar3 == 0) {
          puVar5 = &DAT_007d5468;
LAB_0051838d:
          FUN_0056bb10(puVar5);
          return 0xffffffff;
        }
        *(int *)(iVar3 + 4) = iVar3 + 0x2c;
        FUN_0056d420(*(undefined4 *)(piVar4[0xe] + 4),local_800,iVar2 * 2 + 2);
      }
      *(undefined4 *)(piVar4[0xe] + 0x20) = param_13;
      *(undefined4 *)(piVar4[0xe] + 0x24) = param_14;
      *(undefined4 *)(piVar4[0xe] + 0x28) = 1;
      return 0;
    }
    piVar4[0xe] = *(int *)(local_10b8 + 0x38);
    if (*(int *)(local_10b8 + 0x38) != 0) {
      piVar4 = (int *)(*(int *)(local_10b8 + 0x38) + 0x28);
      *piVar4 = *piVar4 + 1;
      return 0;
    }
  }
  else {
LAB_005182ff:
    piVar4[0xe] = 0;
  }
  return 0;
}

