
void FUN_0066ea20(int *param_1,int param_2)

{
  char *pcVar1;
  char *pcVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  
  iVar6 = *param_1;
  if ((char)param_1[2] == '\x06') {
    if (*(char *)((int)param_1 + 9) == '\b') {
      param_2 = param_1[1] + param_2;
      if (iVar6 != 0) {
        do {
          pcVar1 = (char *)(param_2 + -1);
          pcVar2 = (char *)(param_2 + -1);
          param_2 = param_2 + -4;
          iVar6 = iVar6 + -1;
          *pcVar2 = -1 - *pcVar1;
        } while (iVar6 != 0);
        return;
      }
    }
    else if (iVar6 != 0) {
      iVar4 = param_1[1] + param_2;
      do {
        *(char *)(iVar4 + -1) = -1 - *(char *)(iVar4 + -1);
        iVar6 = iVar6 + -1;
        *(char *)(iVar4 + -2) = -1 - *(char *)(iVar4 + -2);
        iVar4 = iVar4 + -8;
      } while (iVar6 != 0);
      return;
    }
  }
  else if ((char)param_1[2] == '\x04') {
    if (*(char *)((int)param_1 + 9) == '\b') {
      puVar3 = (undefined1 *)(param_1[1] + param_2);
      if (iVar6 != 0) {
        puVar5 = puVar3;
        do {
          pcVar1 = puVar3 + -1;
          puVar3 = puVar3 + -2;
          puVar5[-1] = -1 - *pcVar1;
          puVar5 = puVar5 + -2;
          iVar6 = iVar6 + -1;
          *puVar5 = *puVar3;
        } while (iVar6 != 0);
        return;
      }
    }
    else if (iVar6 != 0) {
      iVar4 = param_1[1] + param_2;
      do {
        *(char *)(iVar4 + -1) = -1 - *(char *)(iVar4 + -1);
        iVar6 = iVar6 + -1;
        *(char *)(iVar4 + -2) = -1 - *(char *)(iVar4 + -2);
        iVar4 = iVar4 + -4;
      } while (iVar6 != 0);
    }
  }
  return;
}

