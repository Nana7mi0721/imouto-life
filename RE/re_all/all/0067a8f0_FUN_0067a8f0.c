
void FUN_0067a8f0(int *param_1,undefined1 *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  
  if ((char)param_1[2] == '\x06') {
    iVar1 = *param_1;
    if (*(char *)((int)param_1 + 9) == '\b') {
      if (iVar1 != 0) {
        do {
          param_2[3] = -1 - param_2[3];
          param_2 = param_2 + 4;
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
        return;
      }
    }
    else if (iVar1 != 0) {
      do {
        param_2[6] = -1 - param_2[6];
        param_2[7] = -1 - param_2[7];
        param_2 = param_2 + 8;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      return;
    }
  }
  else if ((char)param_1[2] == '\x04') {
    if (*(char *)((int)param_1 + 9) == '\b') {
      iVar1 = *param_1;
      if (iVar1 != 0) {
        puVar2 = param_2;
        do {
          *param_2 = *puVar2;
          param_2[1] = -1 - puVar2[1];
          param_2 = param_2 + 2;
          puVar2 = puVar2 + 2;
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
        return;
      }
    }
    else {
      for (iVar1 = *param_1; iVar1 != 0; iVar1 = iVar1 + -1) {
        param_2[2] = -1 - param_2[2];
        param_2[3] = -1 - param_2[3];
        param_2 = param_2 + 4;
      }
    }
  }
  return;
}

