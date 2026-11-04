
void __thiscall FUN_00621c70(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == *(int *)(param_1 + 8)) {
    iVar5 = iVar1 * 2;
    if (iVar1 == 0) {
      iVar5 = 1;
    }
    if (*(int *)(param_1 + 8) < iVar5) {
      if (iVar5 == 0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = (undefined4 *)FUN_00646b30(iVar5 * 4,0x10);
      }
      iVar1 = *(int *)(param_1 + 4);
      iVar3 = 0;
      if (0 < iVar1) {
        puVar4 = puVar2;
        do {
          if (puVar4 != (undefined4 *)0x0) {
            *puVar4 = *(undefined4 *)(*(int *)(param_1 + 0xc) + iVar3 * 4);
          }
          iVar3 = iVar3 + 1;
          puVar4 = puVar4 + 1;
        } while (iVar3 < iVar1);
      }
      if (*(int *)(param_1 + 0xc) != 0) {
        if (*(char *)(param_1 + 0x10) != '\0') {
          FUN_00646b80(*(int *)(param_1 + 0xc));
        }
        *(undefined4 *)(param_1 + 0xc) = 0;
      }
      *(undefined4 **)(param_1 + 0xc) = puVar2;
      *(undefined1 *)(param_1 + 0x10) = 1;
      *(int *)(param_1 + 8) = iVar5;
    }
  }
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 4) * 4);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = *param_2;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return;
}

