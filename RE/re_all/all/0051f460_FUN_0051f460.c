
undefined4
FUN_0051f460(float param_1,float param_2,float param_3,float param_4,uint param_5,undefined4 param_6
            )

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 local_28;
  int local_10;
  int local_c;
  int local_8;
  
  iVar1 = (int)ROUND(param_1);
  iVar2 = (int)ROUND(param_2);
  iVar3 = (int)ROUND(param_3);
  iVar4 = (int)ROUND(param_4);
  if (DAT_00a37fd0 != 0) {
    return 0;
  }
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if ((((DAT_00cc47d0 == 0) || ((int)param_5 < 0)) || ((param_5 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(param_5 & 0xffff) ||
       (piVar5 = *(int **)(DAT_00cc47d4 + (param_5 & 0xffff) * 4), piVar5 == (int *)0x0)) ||
      ((*piVar5 * 0x10000 != (param_5 & 0x3ff0000) || (piVar5[4] != 0)))))) {
    return 0xffffffff;
  }
  local_28 = 0;
  if (0 < (int)DAT_00a380d4) {
    if (((-1 < (int)DAT_00a380d4) && ((DAT_00a380d4 & 0x7c000000) == DAT_00cc47f8)) &&
       ((int)(DAT_00a380d4 & 0xffff) < DAT_00cc4800)) {
      local_28 = *(undefined4 *)(DAT_00cc47d4 + (DAT_00a380d4 & 0xffff) * 4);
    }
    iVar7 = FUN_00514e90();
    if (iVar7 != 0) {
      return 0xffffffff;
    }
  }
  if (piVar5[0xd] != -1) {
    FUN_0057b670(piVar5[0xd],0);
  }
  if ((DAT_00a381c4 == 0) && (DAT_00a37d78 != 0)) {
    FUN_005198b0();
  }
  if (((DAT_00a380cc == 3) && (DAT_00a37d8c == 0)) && (*(char *)(piVar5[0x13] + 8) != '\0')) {
    bVar6 = true;
  }
  else {
    bVar6 = false;
    if (DAT_00ca39f4 == 0) {
      if (*(char *)(piVar5[0x13] + 8) == '\0') {
        uVar8 = FUN_00515310(iVar4,piVar5,param_6);
        return uVar8;
      }
      uVar8 = FUN_00568d60(iVar1,iVar2,iVar3,iVar4,param_1,param_2,param_3,param_4,piVar5,local_28,
                           param_6,0);
      return uVar8;
    }
  }
  local_10 = iVar1;
  local_8 = iVar3;
  if (iVar3 < iVar1) {
    local_10 = iVar3;
    local_8 = iVar1;
  }
  iVar7 = iVar4;
  local_c = iVar2;
  if (iVar4 < iVar2) {
    iVar7 = iVar2;
    local_c = iVar4;
  }
  if (-1 < (int)((iVar7 - DAT_00a381a0) - 1U & (DAT_00a38198 - local_c) - 1U &
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
    if (local_c < DAT_00a38198) {
      local_c = DAT_00a38198;
    }
    if (iVar7 < DAT_00a38198) {
      iVar7 = DAT_00a38198;
    }
    if (DAT_00a381a0 < local_c) {
      local_c = DAT_00a381a0;
    }
    if (DAT_00a381a0 < iVar7) {
      iVar7 = DAT_00a381a0;
    }
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057b170(local_10,local_c,local_8,iVar7);
  }
  if (bVar6) {
    FUN_00519580();
    uVar8 = FUN_00568d60(iVar1,iVar2,iVar3,iVar4,param_1,param_2,param_3,param_4,piVar5,local_28,
                         param_6,0);
    FUN_00519650();
  }
  else if (*(char *)(piVar5[0x13] + 8) == '\0') {
    uVar8 = FUN_00515310(iVar4,piVar5,param_6);
  }
  else {
    uVar8 = FUN_00568d60(iVar1,iVar2,iVar3,iVar4,param_1,param_2,param_3,param_4,piVar5,local_28,
                         param_6,0);
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057ae10(local_10,local_c,local_8,iVar7);
  }
  return uVar8;
}

