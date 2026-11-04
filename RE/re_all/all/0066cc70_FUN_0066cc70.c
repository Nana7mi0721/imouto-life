
void FUN_0066cc70(int param_1,byte *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  
  if (*(char *)(param_1 + 8) == '\0') {
    iVar4 = *(int *)(param_1 + 4);
    if (iVar4 != 0) {
      do {
        *param_2 = ~*param_2;
        iVar4 = iVar4 + -1;
        param_2 = param_2 + 1;
      } while (iVar4 != 0);
      return;
    }
  }
  else if (*(char *)(param_1 + 8) == '\x04') {
    if (*(char *)(param_1 + 9) == '\b') {
      if (*(int *)(param_1 + 4) != 0) {
        uVar5 = *(int *)(param_1 + 4) + 1U >> 1;
        do {
          *param_2 = ~*param_2;
          uVar5 = uVar5 - 1;
          param_2 = param_2 + 2;
        } while (uVar5 != 0);
        return;
      }
    }
    else if ((*(char *)(param_1 + 9) == '\x10') &&
            (pbVar1 = *(byte **)(param_1 + 4), pbVar1 != (byte *)0x0)) {
      pbVar2 = param_2 + 1;
      do {
        pbVar3 = pbVar2 + 4;
        pbVar2[-1] = ~pbVar2[-1];
        *pbVar2 = ~*pbVar2;
        pbVar2 = pbVar3;
      } while (pbVar3 + (-1 - (int)param_2) < pbVar1);
    }
  }
  return;
}

