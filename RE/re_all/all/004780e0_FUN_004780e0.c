
undefined1 __fastcall FUN_004780e0(int param_1)

{
  undefined1 local_c;
  
  if ((*(int *)(param_1 + 0x38) == DAT_0084b264 * 2 * *(int *)(param_1 + 0x28)) &&
     (*(int *)(param_1 + 0x3c) == DAT_0084b264 * 2 * *(int *)(param_1 + 0x2c))) {
    local_c = 0;
  }
  else {
    local_c = 1;
  }
  *(undefined1 *)(param_1 + 0xc1) = local_c;
  return *(undefined1 *)(param_1 + 0xc1);
}

