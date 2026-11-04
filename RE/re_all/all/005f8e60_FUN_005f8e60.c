
undefined4 FUN_005f8e60(int param_1)

{
  if (*(int *)(param_1 + 0x4a) == 1) {
    if (*(int *)(param_1 + 0x468) != 0) {
      FUN_005f8a20(param_1 + 0x52);
      *(undefined4 *)(param_1 + 0x4a) = 0;
      return 0;
    }
    FUN_006a8f20(param_1 + 0x52);
    *(undefined4 *)(param_1 + 0x4a) = 0;
  }
  return 0;
}

