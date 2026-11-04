
undefined4 __fastcall FUN_0046c9c0(void *param_1)

{
  int iVar1;
  void *pvVar2;
  size_t _Size;
  int local_18;
  size_t local_10 [3];
  
  iVar1 = FUN_004e5650();
  local_10[0] = iVar1 + 1;
  pvVar2 = (void *)FUN_004cbb30();
  local_10[1] = 0x3039;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),local_10 + 1,4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),param_1,4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),local_10,4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = local_10[0];
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),pvVar2,local_10[0]);
  }
  DAT_00a11790 = DAT_00a11790 + local_10[0];
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)((int)param_1 + 0x20),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)((int)param_1 + 0x24),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)((int)param_1 + 0x28),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  local_10[2] = FUN_004cd730();
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),local_10 + 2,4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  for (local_18 = 0; local_18 < (int)local_10[2]; local_18 = local_18 + 1) {
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _Size = 1;
      pvVar2 = (void *)FUN_004cd7c0(local_18);
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),pvVar2,_Size);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
  }
  return 1;
}

