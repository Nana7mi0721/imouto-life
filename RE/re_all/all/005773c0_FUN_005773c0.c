
int FUN_005773c0(undefined4 param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_00572ac0(param_1);
  if (iVar2 == 1) {
    iVar2 = 0;
    cVar1 = (char)*param_2;
    while (cVar1 != '\0') {
      iVar2 = iVar2 + 1;
      cVar1 = *(char *)(iVar2 + (int)param_2);
    }
  }
  else if (iVar2 == 2) {
    iVar2 = 0;
    if ((short)*param_2 != 0) {
      do {
        iVar2 = iVar2 + 1;
      } while (*(short *)((int)param_2 + iVar2 * 2) != 0);
      return iVar2;
    }
  }
  else {
    if (iVar2 != 4) {
      return 0;
    }
    iVar2 = 0;
    if (*param_2 != 0) {
      do {
        iVar2 = iVar2 + 1;
      } while (param_2[iVar2] != 0);
      return iVar2;
    }
  }
  return iVar2;
}

