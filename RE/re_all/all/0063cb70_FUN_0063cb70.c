
void __thiscall FUN_0063cb70(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  iVar4 = 0;
  iVar1 = *(int *)(param_1 + 0x1f0);
  if (0 < iVar1) {
    piVar6 = *(int **)(param_1 + 0x1f8);
    do {
      if (*piVar6 == param_2) {
        iVar1 = iVar4;
        break;
      }
      iVar4 = iVar4 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar4 < iVar1);
  }
  if (iVar1 == *(int *)(param_1 + 0x1f0)) {
    iVar1 = *(int *)(param_1 + 0x1f0);
    if (iVar1 == *(int *)(param_1 + 500)) {
      iVar4 = iVar1 * 2;
      if (iVar1 == 0) {
        iVar4 = 1;
      }
      if (*(int *)(param_1 + 500) < iVar4) {
        if (iVar4 == 0) {
          puVar2 = (undefined4 *)0x0;
        }
        else {
          puVar2 = (undefined4 *)FUN_00646b30(iVar4 * 4,0x10);
        }
        iVar1 = *(int *)(param_1 + 0x1f0);
        iVar3 = 0;
        if (0 < iVar1) {
          puVar5 = puVar2;
          do {
            if (puVar5 != (undefined4 *)0x0) {
              *puVar5 = *(undefined4 *)(*(int *)(param_1 + 0x1f8) + iVar3 * 4);
            }
            iVar3 = iVar3 + 1;
            puVar5 = puVar5 + 1;
          } while (iVar3 < iVar1);
        }
        if (*(int *)(param_1 + 0x1f8) != 0) {
          if (*(char *)(param_1 + 0x1fc) != '\0') {
            FUN_00646b80(*(int *)(param_1 + 0x1f8));
          }
          *(undefined4 *)(param_1 + 0x1f8) = 0;
        }
        *(undefined4 **)(param_1 + 0x1f8) = puVar2;
        *(undefined1 *)(param_1 + 0x1fc) = 1;
        *(int *)(param_1 + 500) = iVar4;
      }
    }
    piVar6 = (int *)(*(int *)(param_1 + 0x1f8) + *(int *)(param_1 + 0x1f0) * 4);
    if (piVar6 != (int *)0x0) {
      *piVar6 = param_2;
    }
    *(int *)(param_1 + 0x1f0) = *(int *)(param_1 + 0x1f0) + 1;
  }
  *(undefined1 *)(param_1 + 0xf8) = 1;
  return;
}

