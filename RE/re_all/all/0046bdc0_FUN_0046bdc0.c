
undefined4 __fastcall FUN_0046bdc0(void *param_1)

{
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),param_1,1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)((int)param_1 + 1),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 0x10;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)((int)param_1 + 8),0x10);
  }
  DAT_00a11790 = DAT_00a11790 + 0x10;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 0x10;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)((int)param_1 + 0x18),0x10);
  }
  DAT_00a11790 = DAT_00a11790 + 0x10;
  return CONCAT31((int3)((uint)DAT_00a11790 >> 8),1);
}

