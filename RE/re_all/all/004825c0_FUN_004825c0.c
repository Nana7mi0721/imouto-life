
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_004825c0(char *param_1)

{
  char *pcVar1;
  LPCSTR pCVar2;
  size_t sVar3;
  undefined1 uStack00000000;
  UINT UVar4;
  undefined1 local_a55;
  undefined1 local_a3d;
  undefined1 local_a2d;
  int local_a14;
  char local_a10 [1024];
  char local_610 [400];
  int local_480;
  int local_47c;
  char local_478 [1024];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_78 [28];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_5c [28];
  char local_40;
  char local_3f;
  char local_3e;
  undefined4 local_3c;
  undefined4 local_38;
  byte local_31;
  char local_30;
  char local_2f;
  char local_2e;
  undefined4 local_2c;
  undefined1 auStack_28 [12];
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af570;
  local_10 = ExceptionList;
  local_1c = DAT_0084b484;
  ExceptionList = &local_10;
  FUN_004cbb30();
  basic_string<>();
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_78,param_1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_78,".dat");
  local_38 = FUN_004cbb30();
  local_14 = FUN_0052e3c0();
  if (local_14 == 0) {
    basic_string<>();
    pcVar1 = (char *)FUN_00401c50();
    _sprintf(local_478,pcVar1);
    UVar4 = 0;
    basic_string<>();
    pCVar2 = (LPCSTR)FUN_00401c50();
    MessageBoxA((HWND)0x0,local_478,pCVar2,UVar4);
    FUN_0052ec70();
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  local_2c = FUN_0052c9a0();
  DAT_00a11790 = 0;
  if (DAT_00a117ec == 0) {
    sVar3 = FUN_0052c9a0();
    DAT_00a0f830 = _malloc(sVar3);
    sVar3 = FUN_0052c9a0();
    _memset(DAT_00a0f830,0,sVar3);
  }
  FUN_0052c9a0();
  FUN_0052cde0();
  thunk_FUN_00580b80();
  for (local_47c = 0; local_47c < 10; local_47c = local_47c + 1) {
    if (auStack_28 + local_47c == (undefined1 *)0x0) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy(auStack_28 + local_47c,DAT_00a0f830 + DAT_00a11790,1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
  }
  local_30 = *DAT_00a0f830;
  local_2f = DAT_00a0f830[3];
  local_2e = DAT_00a0f830[9];
  local_40 = DAT_00a0f830[2];
  local_3f = DAT_00a0f830[6];
  local_3e = DAT_00a0f830[8];
  if ((((DAT_00a0f830[1] != 'W') || (DAT_00a0f830[4] != 'O')) || (DAT_00a0f830[5] != 'L')) ||
     ((DAT_00a0f830[7] != 'F' || (DAT_00a0f830[8] != 'M')))) {
    basic_string<>(local_38);
    FUN_0041b9e0();
  }
  DAT_00a0f808 = 0xc0;
  if (&uStack00000000 == (undefined1 *)0x31) {
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy(&local_31,DAT_00a0f830 + DAT_00a11790,1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if ((local_31 == 0xc0) || (local_31 == 0xc1)) {
    DAT_00a0f808 = (uint)local_31;
    if (&uStack00000000 == (undefined1 *)0x18) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_18,DAT_00a0f830 + DAT_00a11790,4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    FUN_004d00b0();
    for (local_480 = 0; local_480 < local_18; local_480 = local_480 + 1) {
      FUN_004d0120();
      FUN_00483c70();
    }
    if (&uStack00000000 == (undefined1 *)0x31) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy(&local_31,DAT_00a0f830 + DAT_00a11790,1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if ((local_31 == 0xc0) || (local_31 == 0xc1)) {
      if ((local_30 != '\0') || ((local_2f != '\0' || (local_2e != '\0')))) {
        basic_string<>(local_38);
        FUN_0041b9e0();
      }
      if (DAT_00a117ec == 0) {
        _free(DAT_00a0f830);
      }
      FUN_004cbb30();
      basic_string<>();
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (local_5c,param_1);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (local_5c,".project");
      local_3c = FUN_004cbb30();
      local_14 = FUN_0052e3c0();
      if (local_14 == 0) {
        basic_string<>();
        pcVar1 = (char *)FUN_00401c50();
        _sprintf(local_a10,pcVar1);
        UVar4 = 0;
        basic_string<>();
        pCVar2 = (LPCSTR)FUN_00401c50();
        MessageBoxA((HWND)0x0,local_a10,pCVar2,UVar4);
        FUN_0052ec70();
                    /* WARNING: Subroutine does not return */
        _exit(1);
      }
      local_2c = FUN_0052c9a0();
      DAT_00a11790 = 0;
      if (DAT_00a117ec == 0) {
        sVar3 = FUN_0052c9a0();
        DAT_00a0f830 = _malloc(sVar3);
        sVar3 = FUN_0052c9a0();
        _memset(DAT_00a0f830,0,sVar3);
      }
      FUN_0052c9a0();
      FUN_0052cde0();
      thunk_FUN_00580b80();
      if (&uStack00000000 == (undefined1 *)0x18) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        _memcpy(&local_18,DAT_00a0f830 + DAT_00a11790,4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      FUN_004d0500();
      for (local_a14 = 0; local_a14 < local_18; local_a14 = local_a14 + 1) {
        FUN_004d05c0();
        FUN_00482e20();
      }
      if (DAT_00a117ec == 0) {
        _free(DAT_00a0f830);
      }
      local_a55 = 1;
      local_8 = local_8 & 0xffffff00;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_5c);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_78);
      local_a2d = local_a55;
    }
    else {
      basic_string<>();
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_610,pcVar1);
      MessageBoxA((HWND)0x0,local_610,"MsgBox",0);
      local_a3d = 0;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_78);
      local_a2d = local_a3d;
    }
  }
  else {
    local_a2d = 0;
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_78
              );
  }
  ExceptionList = local_10;
  return local_a2d;
}

