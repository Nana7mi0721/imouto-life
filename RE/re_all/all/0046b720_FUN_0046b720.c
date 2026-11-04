
undefined4 __fastcall FUN_0046b720(int param_1)

{
  void *_Src;
  int iVar1;
  size_t local_8;
  
  _Src = (void *)FUN_004cbb30();
  iVar1 = FUN_004e5650();
  local_8 = iVar1 + 1;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),&local_8,4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = local_8;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),_Src,local_8);
  }
  DAT_00a11790 = DAT_00a11790 + local_8;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)(param_1 + 0x1c),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)(param_1 + 0x20),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)(param_1 + 0x24),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)(param_1 + 0x28),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  return CONCAT31((int3)((uint)DAT_00a11790 >> 8),1);
}

