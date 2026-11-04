
undefined4 FUN_0059e750(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x450) + 8);
  if (iVar1 != 0) {
    FUN_005d3370(iVar1);
    *(undefined4 *)(*(int *)(param_1 + 0x450) + 8) = 0;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x450) + 4);
  if (iVar1 != 0) {
    FUN_005d3370(iVar1);
    *(undefined4 *)(*(int *)(param_1 + 0x450) + 4) = 0;
  }
  if (**(int **)(param_1 + 0x450) != 0) {
    FUN_005d3370(**(int **)(param_1 + 0x450));
    **(undefined4 **)(param_1 + 0x450) = 0;
  }
  return 0;
}

