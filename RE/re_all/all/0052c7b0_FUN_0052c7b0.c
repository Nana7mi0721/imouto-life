
undefined4 FUN_0052c7b0(int param_1)

{
  if (*(int *)(param_1 + 0x30) == 0) {
    if (*(int *)(param_1 + 0x54) != 0) {
      (*(code *)PTR_FUN_0084c9d4)(*(int *)(param_1 + 0x54));
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
  }
  else if ((*(int *)(param_1 + 0x30) == 1) && (*(int *)(param_1 + 0x5c) != 0)) {
    (**(code **)(param_1 + 0x48))(*(undefined4 *)(param_1 + 0x4c));
    *(undefined4 *)(param_1 + 0x4c) = 0;
    if (*(int *)(param_1 + 0x58) != 0) {
      FUN_0056e1d0(*(undefined4 *)(param_1 + 0x5c));
    }
    *(undefined4 *)(param_1 + 0x5c) = 0;
    return 0;
  }
  return 0;
}

