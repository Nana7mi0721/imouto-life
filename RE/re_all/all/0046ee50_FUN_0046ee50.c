
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_0046ee50(void *param_1)

{
  int iVar1;
  void *_Src;
  void *_Dst;
  undefined1 uStack00000000;
  size_t _Size;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  undefined4 local_21c;
  int local_218;
  char local_214 [512];
  undefined4 local_14;
  size_t local_10;
  undefined1 local_c [4];
  int local_8;
  
  local_14 = DAT_0084b484;
  if (&uStack00000000 == (undefined1 *)0xc) {
    local_21c = 0xffffffff;
    __CxxThrowException_8(0xfffffdf0,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(local_c,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (param_1 == (void *)0x0) {
    local_220 = 0xffffffff;
    __CxxThrowException_8(&local_220,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(param_1,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (&uStack00000000 == (undefined1 *)0x10) {
    local_224 = 0xffffffff;
    __CxxThrowException_8(0xfffffdec,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(&local_10,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (&uStack00000000 == (undefined1 *)0x214) {
    local_228 = 0xffffffff;
    __CxxThrowException_8(0xffffffec,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = local_10;
    _memcpy(local_214,(void *)(DAT_00a0f830 + DAT_00a11790),local_10);
  }
  DAT_00a11790 = DAT_00a11790 + local_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)((int)param_1 + 4),
             local_214);
  if (param_1 == (void *)0xffffffe0) {
    local_22c = 0xffffffff;
    __CxxThrowException_8(&local_22c,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)((int)param_1 + 0x20),(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (param_1 == (void *)0xffffffdc) {
    local_230 = 0xffffffff;
    __CxxThrowException_8(&local_230,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)((int)param_1 + 0x24),(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (param_1 == (void *)0xffffffd8) {
    local_234 = 0xffffffff;
    __CxxThrowException_8(&local_234,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)((int)param_1 + 0x28),(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (&uStack00000000 == (undefined1 *)0x8) {
    local_238 = 0xffffffff;
    __CxxThrowException_8(0xfffffdd0,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(&local_8,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  iVar1 = FUN_004cd730();
  if (iVar1 < local_8) {
    FUN_004cf7d0(local_8);
  }
  for (local_218 = 0; local_218 < local_8; local_218 = local_218 + 1) {
    iVar1 = FUN_004cd7c0(local_218);
    if (iVar1 == 0) {
      local_23c = 0xffffffff;
      __CxxThrowException_8(&local_23c,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _Size = 1;
      _Src = (void *)(DAT_00a0f830 + DAT_00a11790);
      _Dst = (void *)FUN_004cd7c0(local_218);
      _memcpy(_Dst,_Src,_Size);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
  }
  return 1;
}

