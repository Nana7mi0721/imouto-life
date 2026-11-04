
void __thiscall FUN_0078e010(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (*(int *)(param_1 + 8) < param_2) {
    if (param_2 == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)FUN_00646b30(param_2 * 4,0x10);
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
    *(int *)(param_1 + 8) = param_2;
  }
  return;
}

