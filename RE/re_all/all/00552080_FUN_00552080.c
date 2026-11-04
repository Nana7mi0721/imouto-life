
undefined4 FUN_00552080(int param_1)

{
  if (*(int *)(param_1 + 0x30) == 1) {
    FUN_005973b0(param_1 + 0x5c);
    FUN_005517a0(param_1 + 0x78);
    FUN_00580810(param_1 + 0x48);
    return 0;
  }
  if (*(int *)(param_1 + 0x4c) != 0) {
    FUN_0056e1d0(*(int *)(param_1 + 0x4c));
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  return 0;
}

