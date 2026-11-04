
undefined4 FUN_005e2320(int param_1)

{
  if (*(int *)(param_1 + 0xf8) != 0) {
    FUN_0056e1d0(*(int *)(param_1 + 0xf8));
    *(undefined4 *)(param_1 + 0xf8) = 0;
  }
  if (*(int *)(param_1 + 0xfc) != 0) {
    FUN_0056e1d0(*(int *)(param_1 + 0xfc));
    *(undefined4 *)(param_1 + 0xfc) = 0;
  }
  return 0;
}

