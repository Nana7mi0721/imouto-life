
void FUN_0066cee0(int *param_1,undefined1 *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  
  bVar1 = *(byte *)(param_1 + 2);
  if ((bVar1 & 2) != 0) {
    iVar3 = *param_1;
    if (*(char *)((int)param_1 + 9) == '\b') {
      if (bVar1 == 2) {
        if (iVar3 != 0) {
          do {
            uVar2 = *param_2;
            *param_2 = param_2[2];
            param_2[2] = uVar2;
            param_2 = param_2 + 3;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          return;
        }
      }
      else if ((bVar1 == 6) && (iVar3 != 0)) {
        do {
          uVar2 = *param_2;
          *param_2 = param_2[2];
          param_2[2] = uVar2;
          param_2 = param_2 + 4;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        return;
      }
    }
    else if (*(char *)((int)param_1 + 9) == '\x10') {
      if (bVar1 == 2) {
        if (iVar3 != 0) {
          param_2 = param_2 + 1;
          do {
            uVar2 = param_2[-1];
            param_2[-1] = param_2[3];
            param_2[3] = uVar2;
            uVar2 = *param_2;
            *param_2 = param_2[4];
            param_2[4] = uVar2;
            param_2 = param_2 + 6;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          return;
        }
      }
      else if ((bVar1 == 6) && (iVar3 != 0)) {
        param_2 = param_2 + 1;
        do {
          uVar2 = param_2[-1];
          param_2[-1] = param_2[3];
          param_2[3] = uVar2;
          uVar2 = *param_2;
          *param_2 = param_2[4];
          param_2[4] = uVar2;
          param_2 = param_2 + 8;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
  }
  return;
}

