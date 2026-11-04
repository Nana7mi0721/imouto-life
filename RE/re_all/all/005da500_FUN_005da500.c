
undefined4 FUN_005da500(int param_1)

{
  if (*(int *)(param_1 + 0x56c) != 0) {
    FUN_0055f370(*(undefined4 *)(param_1 + 0x5e0));
    FUN_0057b670(*(undefined4 *)(param_1 + 4),0);
    return 0;
  }
  if (*(int *)(param_1 + 0x628) == 0) {
    return 0xffffffff;
  }
  (**(code **)(**(int **)(param_1 + 0x628) + 0x20))(*(int **)(param_1 + 0x628));
  return 0;
}

