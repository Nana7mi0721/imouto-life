
void __fastcall FUN_00478430(int param_1)

{
  int local_c;
  
  if (*(int *)(param_1 + 0x68) - DAT_0084b244 < 0) {
    local_c = 0;
  }
  else {
    local_c = *(int *)(param_1 + 0x68) - DAT_0084b244;
  }
  *(int *)(param_1 + 0x68) = local_c;
  *(int *)(param_1 + 0x38) =
       (*(int *)(param_1 + 0x38) * *(int *)(param_1 + 0x68) +
       DAT_0084b264 * 2 * *(int *)(param_1 + 0x28)) / (*(int *)(param_1 + 0x68) + 1);
  *(int *)(param_1 + 0x3c) =
       (*(int *)(param_1 + 0x3c) * *(int *)(param_1 + 0x68) +
       DAT_0084b264 * 2 * *(int *)(param_1 + 0x2c)) / (*(int *)(param_1 + 0x68) + 1);
  return;
}

