
undefined4 __fastcall FUN_0049ec50(int param_1)

{
  int local_c;
  
  if (*(int *)(param_1 + 0x1b0) - DAT_0084b244 < 0) {
    local_c = -1;
  }
  else {
    local_c = *(int *)(param_1 + 0x1b0) - DAT_0084b244;
  }
  *(int *)(param_1 + 0x1b0) = local_c;
  return 1;
}

