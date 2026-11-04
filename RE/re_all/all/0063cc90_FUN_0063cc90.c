
void __thiscall FUN_0063cc90(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 0x1f0);
  iVar3 = 0;
  iVar5 = iVar1;
  if (0 < iVar1) {
    piVar4 = *(int **)(param_1 + 0x1f8);
    do {
      if (*piVar4 == param_2) {
        iVar5 = iVar3;
        break;
      }
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < iVar1);
  }
  if (iVar5 < iVar1) {
    iVar3 = *(int *)(param_1 + 0x1f8);
    uVar2 = *(undefined4 *)(iVar3 + iVar5 * 4);
    *(undefined4 *)(iVar3 + iVar5 * 4) = *(undefined4 *)(iVar3 + -4 + iVar1 * 4);
    *(undefined4 *)(*(int *)(param_1 + 0x1f8) + -4 + iVar1 * 4) = uVar2;
    *(int *)(param_1 + 0x1f0) = *(int *)(param_1 + 0x1f0) + -1;
  }
  *(bool *)(param_1 + 0xf8) = 0 < *(int *)(param_1 + 0x1f0);
  return;
}

