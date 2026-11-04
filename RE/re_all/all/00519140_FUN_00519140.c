
undefined4
FUN_00519140(uint param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,int param_9,uint param_10)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (((((DAT_00cc47d0 == 0) || ((int)param_10 < 0)) || ((param_10 & 0x7c000000) != DAT_00cc47f8))
      || ((DAT_00cc4800 <= (int)(param_10 & 0xffff) ||
          (piVar1 = *(int **)(DAT_00cc47d4 + (param_10 & 0xffff) * 4), piVar1 == (int *)0x0)))) ||
     ((*piVar1 * 0x10000 != (param_10 & 0x3ff0000) || (piVar1[4] != 0)))) {
    return 0xffffffff;
  }
  if (((((int)param_1 < 0) || ((param_1 & 0x7c000000) != DAT_00cc47f8)) ||
      (DAT_00cc4800 <= (int)(param_1 & 0xffff))) ||
     (((piVar3 = *(int **)(DAT_00cc47d4 + (param_1 & 0xffff) * 4), piVar3 == (int *)0x0 ||
       (*piVar3 * 0x10000 != (param_1 & 0x3ff0000))) || (piVar3[4] != 0)))) {
    piVar3 = (int *)0x0;
    iVar2 = DAT_00a381b4;
    iVar4 = DAT_00a381b8;
  }
  else {
    iVar2 = piVar3[0x18];
    iVar4 = piVar3[0x19];
  }
  if ((((param_4 < 0) || (param_6 <= param_4)) ||
      ((param_5 < 0 || ((param_7 <= param_5 || (iVar2 < param_6)))))) ||
     ((iVar4 < param_7 ||
      ((piVar1[0x18] < (param_6 - param_4) + param_8 ||
       (piVar1[0x19] < (param_7 - param_5) + param_9)))))) {
    return 0xffffffff;
  }
  if (*(char *)(piVar1[0x13] + 8) == '\0') {
    local_10 = param_4;
    local_c = param_5;
    local_8 = param_6;
    local_4 = param_7;
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)&DAT_00a37df8;
    }
    else {
      piVar3 = piVar3 + 0x22;
    }
    FUN_005812b0(piVar1 + 0x22,piVar3,&local_10,param_8,param_9);
  }
  else {
    iVar2 = FUN_00568a20(piVar1,piVar3,param_1,param_2,param_3,iVar2,iVar4,param_4,param_5,param_6,
                         param_7,param_8,param_9);
    if (iVar2 < 0) {
      return 0xffffffff;
    }
  }
  return 0;
}

