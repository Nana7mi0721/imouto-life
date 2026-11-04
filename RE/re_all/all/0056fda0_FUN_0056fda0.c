
undefined4 FUN_0056fda0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x884) == 1) {
    iVar1 = FUN_0056ef10(param_1);
    while (iVar1 == 0) {
      FUN_0056da20(0);
      iVar1 = FUN_0056ef10(param_1);
    }
  }
  if (*(int *)(param_1 + 0x864) == 0) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 0x40);
}

