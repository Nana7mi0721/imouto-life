
void __thiscall FUN_0078c0c0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_2 + 0xbc);
  if (iVar1 != 0) {
    piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x4c) + 0x20))();
    (**(code **)(*piVar3 + 0x24))(iVar1,*(undefined4 *)(param_1 + 0x18));
    (**(code **)(**(int **)(param_1 + 0x4c) + 8))(iVar1,*(undefined4 *)(param_1 + 0x18));
    *(undefined4 *)(param_2 + 0xbc) = 0;
  }
  iVar1 = *(int *)(param_1 + 8);
  iVar4 = 0;
  iVar5 = iVar1;
  if (0 < iVar1) {
    piVar3 = *(int **)(param_1 + 0x10);
    do {
      if (*piVar3 == param_2) {
        iVar5 = iVar4;
        break;
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < iVar1);
  }
  if (iVar5 < iVar1) {
    iVar4 = *(int *)(param_1 + 0x10);
    uVar2 = *(undefined4 *)(iVar4 + iVar5 * 4);
    *(undefined4 *)(iVar4 + iVar5 * 4) = *(undefined4 *)(iVar4 + -4 + iVar1 * 4);
    *(undefined4 *)(*(int *)(param_1 + 0x10) + -4 + iVar1 * 4) = uVar2;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  return;
}

