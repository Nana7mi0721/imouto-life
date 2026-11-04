
void FUN_0067a7e0(int *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  
  if ((char)param_1[2] == '\x06') {
    if (*(char *)((int)param_1 + 9) == '\b') {
      iVar5 = *param_1;
      if (iVar5 != 0) {
        puVar4 = param_2;
        do {
          uVar1 = *param_2;
          *puVar4 = param_2[1];
          puVar3 = param_2 + 3;
          puVar4[1] = param_2[2];
          param_2 = param_2 + 4;
          puVar4[2] = *puVar3;
          puVar4[3] = uVar1;
          puVar4 = puVar4 + 4;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        return;
      }
    }
    else {
      iVar5 = *param_1;
      puVar4 = param_2;
      if (iVar5 != 0) {
        do {
          uVar1 = *param_2;
          uVar2 = param_2[1];
          *puVar4 = param_2[2];
          puVar4[1] = param_2[3];
          puVar4[2] = param_2[4];
          puVar4[3] = param_2[5];
          puVar3 = param_2 + 7;
          puVar4[4] = param_2[6];
          param_2 = param_2 + 8;
          puVar4[5] = *puVar3;
          puVar4[6] = uVar1;
          puVar4[7] = uVar2;
          puVar4 = puVar4 + 8;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        return;
      }
    }
  }
  else if ((char)param_1[2] == '\x04') {
    if (*(char *)((int)param_1 + 9) == '\b') {
      iVar5 = *param_1;
      if (iVar5 != 0) {
        puVar4 = param_2;
        do {
          uVar1 = *param_2;
          *puVar4 = param_2[1];
          param_2 = param_2 + 2;
          puVar4[1] = uVar1;
          puVar4 = puVar4 + 2;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        return;
      }
    }
    else {
      puVar4 = param_2;
      for (iVar5 = *param_1; iVar5 != 0; iVar5 = iVar5 + -1) {
        uVar1 = *param_2;
        uVar2 = param_2[1];
        puVar3 = param_2 + 3;
        *puVar4 = param_2[2];
        param_2 = param_2 + 4;
        puVar4[1] = *puVar3;
        puVar4[2] = uVar1;
        puVar4[3] = uVar2;
        puVar4 = puVar4 + 4;
      }
    }
  }
  return;
}

