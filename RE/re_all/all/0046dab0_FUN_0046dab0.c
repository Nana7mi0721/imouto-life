
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_0046dab0(void *param_1)

{
  undefined1 uStack00000000;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  char local_20c [512];
  undefined4 local_c;
  size_t local_8;
  
  local_c = DAT_0084b484;
  if (param_1 == (void *)0x0) {
    local_210 = 0xffffffff;
    __CxxThrowException_8(&local_210,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(param_1,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (&uStack00000000 == (undefined1 *)0x8) {
    local_214 = 0xffffffff;
    __CxxThrowException_8(0xfffffdf4,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(&local_8,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (&uStack00000000 == (undefined1 *)0x20c) {
    local_218 = 0xffffffff;
    __CxxThrowException_8(0xfffffff4,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = local_8;
    _memcpy(local_20c,(void *)(DAT_00a0f830 + DAT_00a11790),local_8);
  }
  DAT_00a11790 = DAT_00a11790 + local_8;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)((int)param_1 + 4),
             local_20c);
  if (param_1 == (void *)0xffffffe0) {
    local_21c = 0xffffffff;
    __CxxThrowException_8(&local_21c,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)((int)param_1 + 0x20),(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if (param_1 == (void *)0xffffffdf) {
    local_220 = 0xffffffff;
    __CxxThrowException_8(&local_220,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)((int)param_1 + 0x21),(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if (param_1 == (void *)0xffffffde) {
    local_224 = 0xffffffff;
    __CxxThrowException_8(&local_224,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)((int)param_1 + 0x22),(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if (param_1 == (void *)0xffffffdd) {
    local_228 = 0xffffffff;
    __CxxThrowException_8(&local_228,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)((int)param_1 + 0x23),(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  return CONCAT31((int3)((uint)DAT_00a11790 >> 8),1);
}

