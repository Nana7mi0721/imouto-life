
undefined4 FUN_0051ecb0(float param_1,float param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 local_20;
  int local_10;
  int local_c;
  
  iVar1 = (int)ROUND(param_1);
  iVar2 = (int)ROUND(param_2);
  if (DAT_00a37fd0 != 0) {
    return 0;
  }
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if ((((DAT_00cc47d0 == 0) || ((int)param_3 < 0)) || ((param_3 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(param_3 & 0xffff) ||
       (piVar3 = *(int **)(DAT_00cc47d4 + (param_3 & 0xffff) * 4), piVar3 == (int *)0x0)) ||
      ((*piVar3 * 0x10000 != (param_3 & 0x3ff0000) || (piVar3[4] != 0)))))) {
    return 0xffffffff;
  }
  local_20 = 0;
  if (0 < (int)DAT_00a380d4) {
    if (((-1 < (int)DAT_00a380d4) && ((DAT_00a380d4 & 0x7c000000) == DAT_00cc47f8)) &&
       ((int)(DAT_00a380d4 & 0xffff) < DAT_00cc4800)) {
      local_20 = *(undefined4 *)(DAT_00cc47d4 + (DAT_00a380d4 & 0xffff) * 4);
    }
    iVar5 = FUN_00514e90();
    if (iVar5 != 0) {
      return 0xffffffff;
    }
  }
  if (piVar3[0xd] != -1) {
    FUN_0057b670(piVar3[0xd],0);
  }
  if ((DAT_00a381c4 == 0) && (DAT_00a37d78 != 0)) {
    FUN_005198b0();
  }
  if (((DAT_00a380cc == 3) && (DAT_00a37d8c == 0)) && (*(char *)(piVar3[0x13] + 8) != '\0')) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
    if (DAT_00ca39f4 == 0) {
      if (*(char *)(piVar3[0x13] + 8) == '\0') {
        uVar6 = FUN_005152e0(iVar1,piVar3);
        return uVar6;
      }
      uVar6 = FUN_00568cd0(iVar1,iVar2,param_1,param_2,piVar3,local_20,param_4,0);
      return uVar6;
    }
  }
  iVar5 = piVar3[0x19] + iVar2;
  iVar7 = piVar3[0x18] + iVar1;
  local_10 = iVar1;
  local_c = iVar2;
  if (-1 < (int)((iVar5 - DAT_00a381a0) - 1U & (DAT_00a38198 - iVar2) - 1U &
                 (iVar7 - DAT_00a3819c) - 1U & (DAT_00a38194 - iVar1) - 1U)) {
    if (iVar1 < DAT_00a38194) {
      local_10 = DAT_00a38194;
    }
    if (iVar7 < DAT_00a38194) {
      iVar7 = DAT_00a38194;
    }
    if (DAT_00a3819c < local_10) {
      local_10 = DAT_00a3819c;
    }
    if (DAT_00a3819c < iVar7) {
      iVar7 = DAT_00a3819c;
    }
    if (iVar2 < DAT_00a38198) {
      local_c = DAT_00a38198;
    }
    if (iVar5 < DAT_00a38198) {
      iVar5 = DAT_00a38198;
    }
    if (DAT_00a381a0 < local_c) {
      local_c = DAT_00a381a0;
    }
    if (DAT_00a381a0 < iVar5) {
      iVar5 = DAT_00a381a0;
    }
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057b170(local_10,local_c,iVar7,iVar5);
  }
  if (bVar4) {
    FUN_00519580();
    uVar6 = FUN_00568cd0(iVar1,iVar2,param_1,param_2,piVar3,local_20,param_4,0);
    FUN_00519650();
  }
  else if (*(char *)(piVar3[0x13] + 8) == '\0') {
    uVar6 = FUN_005152e0(iVar1,piVar3);
  }
  else {
    uVar6 = FUN_00568cd0(iVar1,iVar2,param_1,param_2,piVar3,local_20,param_4,0);
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057ae10(local_10,local_c,iVar7,iVar5);
  }
  return uVar6;
}

