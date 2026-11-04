
undefined4 FUN_005bfa30(int param_1)

{
  int iVar1;
  
  if (**(int **)(param_1 + 0x450) != 0) {
    FUN_005d1ee0(**(int **)(param_1 + 0x450));
    **(undefined4 **)(param_1 + 0x450) = 0;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x450) + 4);
  if (iVar1 != 0) {
    FUN_005d1f20(iVar1);
    *(undefined4 *)(*(int *)(param_1 + 0x450) + 4) = 0;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x450) + 8);
  if (iVar1 != 0) {
    FUN_005d1f40(iVar1);
    *(undefined4 *)(*(int *)(param_1 + 0x450) + 8) = 0;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x450) + 0xc);
  if (iVar1 != 0) {
    FUN_005d1ee0(iVar1);
    *(undefined4 *)(*(int *)(param_1 + 0x450) + 0xc) = 0;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x450) + 0x10);
  if (iVar1 != 0) {
    FUN_005d1f60(iVar1);
    *(undefined4 *)(*(int *)(param_1 + 0x450) + 0x10) = 0;
  }
  return 0;
}

