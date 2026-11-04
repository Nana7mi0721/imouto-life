
void FUN_0066e920(int *param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  
  iVar6 = *param_1;
  if ((char)param_1[2] == '\x06') {
    if (*(char *)((int)param_1 + 9) == '\b') {
      puVar3 = (undefined1 *)(param_1[1] + param_2);
      if (iVar6 != 0) {
        puVar5 = puVar3;
        do {
          uVar1 = puVar3[-1];
          puVar4 = puVar3 + -3;
          puVar5[-1] = puVar3[-2];
          puVar3 = puVar3 + -4;
          puVar5[-2] = *puVar4;
          puVar5[-3] = *puVar3;
          puVar5 = puVar5 + -4;
          iVar6 = iVar6 + -1;
          *puVar5 = uVar1;
        } while (iVar6 != 0);
        return;
      }
    }
    else {
      puVar3 = (undefined1 *)(param_1[1] + param_2);
      if (iVar6 != 0) {
        puVar5 = puVar3;
        do {
          uVar1 = puVar3[-1];
          uVar2 = puVar3[-2];
          puVar5[-1] = puVar3[-3];
          puVar5[-2] = puVar3[-4];
          puVar5[-3] = puVar3[-5];
          puVar4 = puVar3 + -7;
          puVar5[-4] = puVar3[-6];
          puVar3 = puVar3 + -8;
          puVar5[-5] = *puVar4;
          puVar5[-6] = *puVar3;
          puVar5[-7] = uVar1;
          puVar5 = puVar5 + -8;
          iVar6 = iVar6 + -1;
          *puVar5 = uVar2;
        } while (iVar6 != 0);
        return;
      }
    }
  }
  else if ((char)param_1[2] == '\x04') {
    if (*(char *)((int)param_1 + 9) == '\b') {
      puVar3 = (undefined1 *)(param_1[1] + param_2);
      if (iVar6 != 0) {
        puVar5 = puVar3;
        do {
          uVar1 = puVar3[-1];
          puVar3 = puVar3 + -2;
          puVar4 = puVar5 + -1;
          puVar5 = puVar5 + -2;
          iVar6 = iVar6 + -1;
          *puVar4 = *puVar3;
          *puVar5 = uVar1;
        } while (iVar6 != 0);
        return;
      }
    }
    else {
      puVar3 = (undefined1 *)(param_1[1] + param_2);
      if (iVar6 != 0) {
        puVar5 = puVar3;
        do {
          uVar1 = puVar3[-1];
          uVar2 = puVar3[-2];
          puVar4 = puVar3 + -3;
          puVar3 = puVar3 + -4;
          puVar5[-1] = *puVar4;
          puVar5[-2] = *puVar3;
          puVar5[-3] = uVar1;
          puVar5 = puVar5 + -4;
          iVar6 = iVar6 + -1;
          *puVar5 = uVar2;
        } while (iVar6 != 0);
      }
    }
  }
  return;
}

