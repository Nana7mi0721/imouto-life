
undefined4 __fastcall FUN_0046eac0(int param_1)

{
  int iVar1;
  void *_Dst;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *this;
  void *_Src;
  undefined1 uStack00000000;
  size_t _Size;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  size_t local_10;
  char local_b;
  char local_a;
  char local_9;
  char *local_8;
  
  if (&uStack00000000 == (undefined1 *)0xa) {
    local_1c = 0xffffffff;
    __CxxThrowException_8(0xffffffee,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy(&local_a,(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  FUN_004ce970((int)local_a);
  for (local_14 = 0; local_14 < local_a; local_14 = local_14 + 1) {
    iVar1 = FUN_004ce990(local_14);
    if (iVar1 == 0) {
      local_20 = 0xffffffff;
      __CxxThrowException_8(&local_20,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _Size = 4;
      _Src = (void *)(DAT_00a0f830 + DAT_00a11790);
      _Dst = (void *)FUN_004ce990(local_14);
      _memcpy(_Dst,_Src,_Size);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
  }
  if (param_1 == -0x10) {
    local_24 = 0xffffffff;
    __CxxThrowException_8(&local_24,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)(param_1 + 0x10),(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if (&uStack00000000 == (undefined1 *)0x9) {
    local_28 = 0xffffffff;
    __CxxThrowException_8(0xffffffe1,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy(&local_9,(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  FUN_004cc400((int)local_9);
  for (local_18 = 0; local_18 < local_9; local_18 = local_18 + 1) {
    if (&uStack00000000 == (undefined1 *)0x10) {
      local_2c = 0xffffffff;
      __CxxThrowException_8(0xffffffe4,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_10,(void *)(DAT_00a0f830 + DAT_00a11790),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    local_8 = _malloc(local_10 + 3);
    if (local_8 == (char *)0x0) {
      local_30 = 0xffffffff;
      __CxxThrowException_8(&local_30,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = local_10;
      _memcpy(local_8,(void *)(DAT_00a0f830 + DAT_00a11790),local_10);
    }
    DAT_00a11790 = DAT_00a11790 + local_10;
    pcVar2 = local_8;
    this = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)FUN_004cc4c0(local_18)
    ;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(this,pcVar2);
    _free(local_8);
  }
  if (&uStack00000000 == (undefined1 *)0xb) {
    __CxxThrowException_8(0xffffffd7,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy(&local_b,(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if ('\0' < local_b) {
    FUN_004ce7a0(1);
    uVar3 = 0;
    FUN_004ce810(0);
    FUN_0046df90(uVar3);
  }
  return 1;
}

