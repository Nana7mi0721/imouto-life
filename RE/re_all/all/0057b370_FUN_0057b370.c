
undefined4 FUN_0057b370(int param_1)

{
  if (-1 < *(int *)(param_1 + 0x528)) {
    FUN_00515700(*(int *)(param_1 + 0x528),0);
    *(undefined4 *)(param_1 + 0x528) = 0xffffffff;
  }
  if (-1 < *(int *)(param_1 + 0x52c)) {
    FUN_00515700(*(int *)(param_1 + 0x52c),0);
    *(undefined4 *)(param_1 + 0x52c) = 0xffffffff;
  }
  FUN_005da2e0(param_1);
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_005fab40(*(undefined4 *)(param_1 + 0x38));
    if (*(int *)(param_1 + 0x54) != 0) {
      if (*(int *)(param_1 + 0x58) == 0) {
        thunk_FUN_00571d20();
      }
      else {
        FUN_0052d050(*(int *)(param_1 + 0x54));
      }
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
    FUN_00515700(*(undefined4 *)(param_1 + 0x70),0);
    *(undefined4 *)(param_1 + 0x70) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  if (*(int *)(param_1 + 0x510) != 0) {
    if (*(int *)(param_1 + 0x51c) == 0) {
      FUN_0056e1d0(*(int *)(param_1 + 0x510));
    }
    *(undefined4 *)(param_1 + 0x510) = 0;
  }
  return 0;
}

