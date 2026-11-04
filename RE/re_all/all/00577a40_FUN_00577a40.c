
int * FUN_00577a40(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_4;
  
  local_4 = 0;
  iVar2 = FUN_00572ac0(param_1);
  piVar1 = param_2;
  if (iVar2 == 1) {
    if ((char)*param_2 != '\0') {
      piVar4 = param_2;
      do {
        iVar2 = FUN_00572c90(piVar4,param_1,&param_2,&local_4);
        if (iVar2 - 0x61U < 0x1a) {
          FUN_00572ff0(iVar2 + -0x20,param_1,piVar4);
        }
        if (1 < (int)param_2) {
          piVar4 = (int *)((int)piVar4 + 1);
        }
        piVar4 = (int *)((int)piVar4 + 1);
      } while (*(char *)piVar4 != '\0');
    }
    return piVar1;
  }
  if (iVar2 == 2) {
    if ((short)*param_2 != 0) {
      piVar4 = param_2;
      do {
        iVar2 = FUN_00572c90(piVar4,param_1,&param_2,&local_4);
        if (iVar2 - 0x61U < 0x1a) {
          FUN_00572ff0(iVar2 + -0x20,param_1,piVar4);
        }
        if (2 < (int)param_2) {
          piVar4 = (int *)((int)piVar4 + 2);
        }
        piVar4 = (int *)((int)piVar4 + 2);
      } while (*(short *)piVar4 != 0);
      return piVar1;
    }
  }
  else {
    if (iVar2 != 4) {
      return param_2;
    }
    if (*param_2 != 0) {
      iVar2 = 0;
      piVar4 = param_2;
      do {
        iVar3 = FUN_00572c90(piVar4,param_1,&param_2,&local_4);
        if (iVar3 - 0x61U < 0x1a) {
          FUN_00572ff0(iVar3 + -0x20,param_1,piVar4);
        }
        iVar2 = iVar2 + 1;
        piVar4 = piVar1 + iVar2;
      } while (piVar1[iVar2] != 0);
    }
  }
  return piVar1;
}

