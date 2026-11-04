
void FUN_00680db0(int param_1)

{
  int iVar1;
  
  if (8 < *(int *)(param_1 + 0x16bc)) {
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         *(undefined1 *)(param_1 + 0x16b8);
    iVar1 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar1;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar1) = *(undefined1 *)(param_1 + 0x16b9);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(undefined2 *)(param_1 + 0x16b8) = 0;
    *(undefined4 *)(param_1 + 0x16bc) = 0;
    return;
  }
  if (0 < *(int *)(param_1 + 0x16bc)) {
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         *(undefined1 *)(param_1 + 0x16b8);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  *(undefined2 *)(param_1 + 0x16b8) = 0;
  *(undefined4 *)(param_1 + 0x16bc) = 0;
  return;
}

