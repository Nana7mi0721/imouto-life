
void FUN_006200c0(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  if ((*(int *)(param_2 + 0x28) != 0) && (param_4 != 0)) {
    FUN_006200c0(param_1,*(undefined4 *)(param_2 + 0x24),param_3,param_4 + -1);
    FUN_006200c0(param_1,*(undefined4 *)(param_2 + 0x28),param_3,param_4 + -1);
    FUN_00646b80(*(undefined4 *)(param_1 + 4));
    *(int *)(param_1 + 4) = param_2;
    return;
  }
  iVar2 = *(int *)(param_3 + 4);
  if (iVar2 == *(int *)(param_3 + 8)) {
    iVar6 = iVar2 * 2;
    if (iVar2 == 0) {
      iVar6 = 1;
    }
    if (*(int *)(param_3 + 8) < iVar6) {
      if (iVar6 == 0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = (undefined4 *)FUN_00646b30(iVar6 * 4,0x10);
      }
      iVar2 = *(int *)(param_3 + 4);
      iVar4 = 0;
      if (0 < iVar2) {
        puVar5 = puVar3;
        do {
          if (puVar5 != (undefined4 *)0x0) {
            *puVar5 = *(undefined4 *)(*(int *)(param_3 + 0xc) + iVar4 * 4);
          }
          iVar4 = iVar4 + 1;
          puVar5 = puVar5 + 1;
        } while (iVar4 < iVar2);
      }
      if (*(int *)(param_3 + 0xc) != 0) {
        if (*(char *)(param_3 + 0x10) != '\0') {
          FUN_00646b80(*(int *)(param_3 + 0xc));
        }
        *(undefined4 *)(param_3 + 0xc) = 0;
      }
      *(undefined1 *)(param_3 + 0x10) = 1;
      *(undefined4 **)(param_3 + 0xc) = puVar3;
      *(int *)(param_3 + 8) = iVar6;
    }
  }
  piVar1 = (int *)(*(int *)(param_3 + 0xc) + *(int *)(param_3 + 4) * 4);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2;
  }
  *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + 1;
  return;
}

