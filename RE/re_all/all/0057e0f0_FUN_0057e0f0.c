
undefined4 FUN_0057e0f0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x78))(piVar1,DAT_00aa4250);
    (**(code **)(*DAT_00aa424c + 0x34))(DAT_00aa424c,*(undefined4 *)(param_1 + 0x48));
    (**(code **)(**(int **)(param_1 + 0x48) + 8))(*(int **)(param_1 + 0x48));
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  return 0;
}

