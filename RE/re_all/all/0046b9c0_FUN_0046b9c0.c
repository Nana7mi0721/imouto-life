
undefined4 __fastcall FUN_0046b9c0(int param_1)

{
  undefined4 uVar1;
  void *_Src;
  size_t _Size;
  int local_14;
  int local_10;
  undefined1 local_9;
  int local_8;
  
  local_9 = 0x79;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),&local_9,1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  FUN_0046bbc0();
  FUN_0046bdc0();
  FUN_0046bee0(0);
  uVar1 = FUN_004cec90();
  *(undefined4 *)(param_1 + 100) = uVar1;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)(param_1 + 100),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  for (local_10 = 0; local_10 < *(int *)(param_1 + 100); local_10 = local_10 + 1) {
    FUN_004cecd0(local_10);
    FUN_0046c720();
  }
  local_8 = FUN_004cd730();
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),&local_8,4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  for (local_14 = 0; local_14 < local_8; local_14 = local_14 + 1) {
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _Size = 1;
      _Src = (void *)FUN_004cd7c0(local_14);
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),_Src,_Size);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
  }
  local_9 = 0x7a;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),&local_9,1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  return 1;
}

