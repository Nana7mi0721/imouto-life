
undefined4 __fastcall FUN_0046bbc0(void *param_1)

{
  int iVar1;
  void *_Src;
  size_t local_8;
  
  iVar1 = FUN_004e5650();
  local_8 = iVar1 + 1;
  _Src = (void *)FUN_004cbb30();
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),param_1,4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
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
    DAT_00a1179c = 1;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)((int)param_1 + 0x20),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)((int)param_1 + 0x21),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)((int)param_1 + 0x22),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)((int)param_1 + 0x23),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  return 1;
}

