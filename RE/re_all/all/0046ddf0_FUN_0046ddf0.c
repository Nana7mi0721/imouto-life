
undefined4 __fastcall FUN_0046ddf0(void *param_1)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_1 == (void *)0x0) {
    local_8 = 0xffffffff;
    __CxxThrowException_8(&local_8,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy(param_1,(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if (param_1 == (void *)0xffffffff) {
    local_c = 0xffffffff;
    __CxxThrowException_8(&local_c,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)((int)param_1 + 1),(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (param_1 == (void *)0xfffffff8) {
    local_10 = 0xffffffff;
    __CxxThrowException_8(&local_10,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 0x10;
    _memcpy((void *)((int)param_1 + 8),(void *)(DAT_00a0f830 + DAT_00a11790),0x10);
  }
  DAT_00a11790 = DAT_00a11790 + 0x10;
  if (param_1 == (void *)0xffffffe8) {
    local_14 = 0xffffffff;
    __CxxThrowException_8(&local_14,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 0x10;
    _memcpy((void *)((int)param_1 + 0x18),(void *)(DAT_00a0f830 + DAT_00a11790),0x10);
  }
  DAT_00a11790 = DAT_00a11790 + 0x10;
  return 1;
}

