
void FUN_00576e80(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  
  iVar1 = FUN_00572ac0(param_1);
  if (iVar1 == 1) {
    cVar3 = (char)*param_3;
    iVar1 = 0;
    if (cVar3 != '\0') {
      iVar2 = param_2 - (int)param_3;
      do {
        *(char *)(iVar2 + (int)param_3) = cVar3;
        cVar3 = *(char *)((int)param_3 + 1);
        param_3 = (int *)((int)param_3 + 1);
        iVar1 = iVar1 + 1;
      } while (cVar3 != '\0');
    }
    *(undefined1 *)(iVar1 + param_2) = 0;
  }
  else {
    if (iVar1 == 2) {
      sVar4 = (short)*param_3;
      iVar1 = 0;
      if (sVar4 != 0) {
        iVar2 = 0;
        do {
          iVar1 = iVar1 + 1;
          *(short *)(iVar2 + param_2) = sVar4;
          iVar2 = iVar1 * 2;
          sVar4 = *(short *)(iVar2 + (int)param_3);
        } while (sVar4 != 0);
      }
      *(undefined2 *)(param_2 + iVar1 * 2) = 0;
      return;
    }
    if (iVar1 == 4) {
      iVar5 = 0;
      iVar1 = 0;
      iVar2 = *param_3;
      while (iVar2 != 0) {
        iVar5 = iVar5 + 1;
        *(int *)(iVar1 + param_2) = iVar2;
        iVar1 = iVar5 * 4;
        iVar2 = param_3[iVar5];
      }
      *(undefined4 *)(param_2 + iVar5 * 4) = 0;
      return;
    }
  }
  return;
}

