
undefined4
FUN_00526aa0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6,
            undefined8 param_7,undefined8 param_8,uint param_9,undefined4 param_10)

{
  int *piVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if ((((DAT_00cc47d0 == 0) || ((int)param_9 < 0)) || ((param_9 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(param_9 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc47d4 + (param_9 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_9 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  if ((param_1 == param_3) || (param_2 == param_4)) {
    return 0;
  }
  local_54 = 0;
  if ((((0 < (int)DAT_00a380d4) && (-1 < (int)DAT_00a380d4)) &&
      ((DAT_00a380d4 & 0x7c000000) == DAT_00cc47f8)) &&
     ((int)(DAT_00a380d4 & 0xffff) < DAT_00cc4800)) {
    local_54 = *(undefined4 *)(DAT_00cc47d4 + (DAT_00a380d4 & 0xffff) * 4);
  }
  uVar5 = (undefined4)param_8;
  uVar6 = (undefined4)((ulonglong)param_8 >> 0x20);
  uVar3 = (undefined4)param_7;
  uVar4 = (undefined4)((ulonglong)param_7 >> 0x20);
  if (((DAT_00a380cc == 3) && (DAT_00a37d8c == 0)) && (*(char *)(piVar1[0x13] + 8) != '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
    if (DAT_00ca39f4 == 0) {
      if (*(char *)(piVar1[0x13] + 8) == '\0') {
        uVar3 = FUN_005256b0(param_1,param_2,param_3,param_4,param_5,param_6,uVar3,uVar4,uVar5,uVar6
                             ,param_10);
        return uVar3;
      }
      uVar3 = FUN_005252a0(param_1,param_2,param_3,param_4,param_5,param_6,uVar3,uVar4,uVar5,uVar6,
                           local_54);
      return uVar3;
    }
  }
  local_48 = param_3;
  local_50 = param_1;
  local_4c = param_2;
  local_44 = param_4;
  if (-1 < (int)((param_4 - DAT_00a381a0) - 1U & (param_3 - DAT_00a3819c) - 1U &
                 (DAT_00a38198 - param_2) - 1U & (DAT_00a38194 - param_1) - 1U)) {
    if (param_1 < DAT_00a38194) {
      local_50 = DAT_00a38194;
    }
    if (param_3 < DAT_00a38194) {
      local_48 = DAT_00a38194;
    }
    if (DAT_00a3819c < local_50) {
      local_50 = DAT_00a3819c;
    }
    if (DAT_00a3819c < local_48) {
      local_48 = DAT_00a3819c;
    }
    if (param_2 < DAT_00a38198) {
      local_4c = DAT_00a38198;
    }
    if (param_4 < DAT_00a38198) {
      local_44 = DAT_00a38198;
    }
    if (DAT_00a381a0 < local_4c) {
      local_4c = DAT_00a381a0;
    }
    if (DAT_00a381a0 < local_44) {
      local_44 = DAT_00a381a0;
    }
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057b170(local_50,local_4c,local_48,local_44);
  }
  if (bVar2) {
    FUN_00519580();
    uVar3 = FUN_005252a0(param_1,param_2,param_3,param_4,param_5,param_6,uVar3,uVar4,uVar5,uVar6,
                         local_54,param_10);
    FUN_00519650();
  }
  else if (*(char *)(piVar1[0x13] + 8) == '\0') {
    uVar3 = FUN_005256b0(param_1,param_2,param_3,param_4,param_5,param_6,uVar3,uVar4,uVar5,uVar6,
                         param_10);
  }
  else {
    uVar3 = FUN_005252a0(param_1,param_2,param_3,param_4,param_5,param_6,uVar3,uVar4,uVar5,uVar6,
                         local_54,param_10);
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057ae10(local_50,local_4c,local_48,local_44);
  }
  return uVar3;
}

