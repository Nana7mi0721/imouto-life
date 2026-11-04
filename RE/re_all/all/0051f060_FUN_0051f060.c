
undefined4
FUN_0051f060(int param_1,int param_2,int param_3,int param_4,uint param_5,undefined4 param_6)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_18;
  int local_10;
  int local_8;
  
  if (DAT_00a37fd0 != 0) {
    return 0;
  }
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if ((((DAT_00cc47d0 == 0) || ((int)param_5 < 0)) || ((param_5 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(param_5 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc47d4 + (param_5 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_5 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  local_18 = 0;
  if (0 < (int)DAT_00a380d4) {
    if (((-1 < (int)DAT_00a380d4) && ((DAT_00a380d4 & 0x7c000000) == DAT_00cc47f8)) &&
       ((int)(DAT_00a380d4 & 0xffff) < DAT_00cc4800)) {
      local_18 = *(undefined4 *)(DAT_00cc47d4 + (DAT_00a380d4 & 0xffff) * 4);
    }
    iVar3 = FUN_00514e90();
    if (iVar3 != 0) {
      return 0xffffffff;
    }
  }
  if (piVar1[0xd] != -1) {
    FUN_0057b670(piVar1[0xd],0);
  }
  if ((DAT_00a381c4 == 0) && (DAT_00a37d78 != 0)) {
    FUN_005198b0();
  }
  if (((DAT_00a380cc == 3) && (DAT_00a37d8c == 0)) && (*(char *)(piVar1[0x13] + 8) != '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
    if (DAT_00ca39f4 == 0) {
      if (*(char *)(piVar1[0x13] + 8) == '\0') {
        uVar4 = FUN_00515310(param_4,piVar1,param_6);
        return uVar4;
      }
      uVar4 = FUN_00568d60(param_1,param_2,param_3,param_4,(float)param_1,(float)param_2,
                           (float)param_3,(float)param_4,piVar1,local_18,param_6,1);
      return uVar4;
    }
  }
  local_10 = param_1;
  local_8 = param_3;
  if (param_3 < param_1) {
    local_10 = param_3;
    local_8 = param_1;
  }
  iVar3 = param_2;
  iVar5 = param_4;
  if (param_4 < param_2) {
    iVar3 = param_4;
    iVar5 = param_2;
  }
  if (-1 < (int)((iVar5 - DAT_00a381a0) - 1U & (DAT_00a38198 - iVar3) - 1U &
                 (local_8 - DAT_00a3819c) - 1U & (DAT_00a38194 - local_10) - 1U)) {
    if (local_10 < DAT_00a38194) {
      local_10 = DAT_00a38194;
    }
    if (local_8 < DAT_00a38194) {
      local_8 = DAT_00a38194;
    }
    if (DAT_00a3819c < local_10) {
      local_10 = DAT_00a3819c;
    }
    if (DAT_00a3819c < local_8) {
      local_8 = DAT_00a3819c;
    }
    if (iVar3 < DAT_00a38198) {
      iVar3 = DAT_00a38198;
    }
    if (iVar5 < DAT_00a38198) {
      iVar5 = DAT_00a38198;
    }
    if (DAT_00a381a0 < iVar3) {
      iVar3 = DAT_00a381a0;
    }
    if (DAT_00a381a0 < iVar5) {
      iVar5 = DAT_00a381a0;
    }
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057b170(local_10,iVar3,local_8,iVar5);
  }
  if (bVar2) {
    FUN_00519580();
    uVar4 = FUN_00568d60(param_1,param_2,param_3,param_4,(float)param_1,(float)param_2,
                         (float)param_3,(float)param_4,piVar1,local_18,param_6,1);
    FUN_00519650();
  }
  else if (*(char *)(piVar1[0x13] + 8) == '\0') {
    uVar4 = FUN_00515310(param_4,piVar1,param_6);
  }
  else {
    uVar4 = FUN_00568d60(param_1,param_2,param_3,param_4,(float)param_1,(float)param_2,
                         (float)param_3,(float)param_4,piVar1,local_18,param_6,1);
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057ae10(local_10,iVar3,local_8,iVar5);
  }
  return uVar4;
}

