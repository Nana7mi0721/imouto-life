
undefined1 * __fastcall FUN_0046d220(undefined1 *param_1)

{
  int local_8;
  
  *param_1 = 0;
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    param_1[local_8 + 1] = 0x20;
    *(undefined4 *)(param_1 + local_8 * 4 + 8) = 0;
    *(undefined4 *)(param_1 + local_8 * 4 + 0x18) = 0;
  }
  return param_1;
}

