
void FUN_00690d50(int param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_00690e20(param_1);
  if (*(char *)(param_1 + 0x6c) == '\0') {
    FUN_00690e00(param_1);
    **(undefined1 **)(param_1 + 0x70) = 0xff;
    iVar1 = *(int *)(param_1 + 0x74) + -1;
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
    *(int *)(param_1 + 0x74) = iVar1;
    if (iVar1 == 0) {
      FUN_00690cc0(param_1);
    }
    **(char **)(param_1 + 0x70) = param_2 + -0x30;
    iVar1 = *(int *)(param_1 + 0x74) + -1;
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
    *(int *)(param_1 + 0x74) = iVar1;
    if (iVar1 == 0) {
      FUN_00690cc0(param_1);
    }
  }
  if (*(int *)(*(int *)(param_1 + 0x78) + 0x15c) == 0) {
    iVar1 = 0;
    if (0 < *(int *)(*(int *)(param_1 + 0x78) + 0x114)) {
      puVar2 = (undefined4 *)(param_1 + 0x14);
      do {
        *puVar2 = 0;
        iVar1 = iVar1 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar1 < *(int *)(*(int *)(param_1 + 0x78) + 0x114));
      return;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x80) = 0;
    *(undefined4 *)(param_1 + 0x84) = 0;
  }
  return;
}

