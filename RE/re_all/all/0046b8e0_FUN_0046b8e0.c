
undefined4 __fastcall FUN_0046b8e0(int param_1)

{
  int local_c;
  undefined1 local_5;
  
  local_5 = 0x6f;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),&local_5,1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  FUN_0046c9c0();
  for (local_c = 0; local_c < *(int *)(param_1 + 0x28); local_c = local_c + 1) {
    FUN_004cf170(local_c);
    FUN_0046b9c0();
  }
  local_5 = 0x70;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),&local_5,1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  return 1;
}

