
int * FUN_00577900(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_8 [2];
  
  local_8[1] = 0;
  iVar1 = FUN_00572ac0(param_1);
  if (iVar1 == 1) {
    iVar1 = 0;
    if ((char)*param_2 != '\0') {
      do {
        iVar2 = FUN_00572c90((char *)(iVar1 + (int)param_2),param_1,local_8,local_8 + 1);
        if (iVar2 == param_3) {
          return (int *)(iVar1 + (int)param_2);
        }
        if (1 < local_8[0]) {
          iVar1 = iVar1 + 1;
        }
        iVar1 = iVar1 + 1;
      } while (*(char *)(iVar1 + (int)param_2) != '\0');
      return (int *)0x0;
    }
  }
  else if (iVar1 == 2) {
    iVar1 = 0;
    piVar3 = param_2;
    if ((short)*param_2 != 0) {
      do {
        iVar2 = FUN_00572c90(piVar3,param_1,local_8,local_8 + 1);
        if (iVar2 == param_3) {
          return (int *)((int)param_2 + iVar1 * 2);
        }
        if (2 < local_8[0]) {
          iVar1 = iVar1 + 1;
          piVar3 = (int *)((int)piVar3 + 2);
        }
        piVar3 = (int *)((int)piVar3 + 2);
        iVar1 = iVar1 + 1;
      } while (*(short *)piVar3 != 0);
      return (int *)0x0;
    }
  }
  else if ((iVar1 == 4) && (iVar1 = 0, *param_2 != 0)) {
    piVar3 = param_2;
    do {
      iVar2 = FUN_00572c90(piVar3,param_1,local_8,local_8 + 1);
      if (iVar2 == param_3) {
        return param_2 + iVar1;
      }
      iVar1 = iVar1 + 1;
      piVar3 = param_2 + iVar1;
    } while (param_2[iVar1] != 0);
  }
  return (int *)0x0;
}

