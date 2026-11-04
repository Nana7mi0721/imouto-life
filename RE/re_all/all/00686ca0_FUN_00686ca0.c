
void FUN_00686ca0(int param_1)

{
  FUN_00686af0(param_1,0xee);
  FUN_00686b50(param_1,0xe);
  FUN_00686b10(param_1,0x41);
  FUN_00686b10(param_1,100);
  FUN_00686b10(param_1,0x6f);
  FUN_00686b10(param_1,0x62);
  FUN_00686b10(param_1,0x65);
  FUN_00686b50(param_1,100);
  FUN_00686b50(param_1,0);
  FUN_00686b50(param_1,0);
  if (*(int *)(param_1 + 0x50) == 3) {
    FUN_00686b10(param_1,1);
    return;
  }
  if (*(int *)(param_1 + 0x50) == 5) {
    FUN_00686b10(param_1,2);
    return;
  }
  FUN_00686b10(param_1,0);
  return;
}

