
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_00481430(char *param_1)

{
  LPCSTR lpCaption;
  LPCSTR lpText;
  undefined1 uStack00000000;
  UINT uType;
  undefined1 local_8d;
  undefined1 local_85;
  undefined1 local_71;
  undefined1 local_61;
  int local_60;
  int local_5c;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_58 [28];
  char local_3c;
  char local_3b;
  char local_3a;
  int local_38;
  undefined4 local_34;
  char local_2d;
  char local_2c;
  char local_2b;
  char local_2a;
  size_t local_28;
  undefined1 auStack_24 [12];
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af518;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_58,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)&DAT_00a14c70);
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_58,param_1);
  local_34 = FUN_004cbb30();
  local_14 = FUN_0052e3c0();
  if (local_14 == 0) {
    local_61 = 0;
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_58
              );
  }
  else {
    local_28 = FUN_0052c9a0();
    DAT_00a11790 = 0;
    if (DAT_00a117ec == 0) {
      DAT_00a0f830 = _malloc(local_28);
      _memset(DAT_00a0f830,0,local_28);
    }
    FUN_0052cde0();
    thunk_FUN_00580b80();
    for (local_5c = 0; local_5c < 10; local_5c = local_5c + 1) {
      if (auStack_24 + local_5c == (undefined1 *)0x0) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 1;
        _memcpy(auStack_24 + local_5c,DAT_00a0f830 + DAT_00a11790,1);
      }
      DAT_00a11790 = DAT_00a11790 + 1;
    }
    local_2c = *DAT_00a0f830;
    local_2b = DAT_00a0f830[3];
    local_2a = DAT_00a0f830[9];
    local_3c = DAT_00a0f830[2];
    local_3b = DAT_00a0f830[6];
    local_3a = DAT_00a0f830[8];
    if ((((DAT_00a0f830[1] != 'W') || (DAT_00a0f830[4] != 'O')) || (DAT_00a0f830[5] != 'L')) ||
       ((DAT_00a0f830[7] != 'F' || (DAT_00a0f830[8] != 'M')))) {
      basic_string<>(local_34);
      FUN_0041b9e0();
    }
    if (&uStack00000000 == (undefined1 *)0x2d) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy(&local_2d,DAT_00a0f830 + DAT_00a11790,1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (((local_2d == -0x31) || (local_2d == -0x30)) || (local_2d == -0x2f)) {
      if (local_2d == -0x31) {
        DAT_0084b26c = 1;
      }
      if (local_2d == -0x30) {
        DAT_0084b26c = 2;
      }
      if (local_2d == -0x2f) {
        DAT_0084b26c = 3;
      }
      if (&uStack00000000 == (undefined1 *)0x38) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        _memcpy(&local_38,DAT_00a0f830 + DAT_00a11790,4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      FUN_004d0b20();
      for (local_60 = 0; local_60 < local_38; local_60 = local_60 + 1) {
        FUN_004d0b90();
        FUN_00481990();
      }
      if (&uStack00000000 == (undefined1 *)0x2d) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 1;
        _memcpy(&local_2d,DAT_00a0f830 + DAT_00a11790,1);
      }
      DAT_00a11790 = DAT_00a11790 + 1;
      if (local_2d == -0x31) {
        if (((local_2c != '\0') || (local_2b != '\0')) || (local_2a != '\0')) {
          basic_string<>(local_34);
          FUN_0041b9e0();
        }
        if (DAT_00a117ec == 0) {
          _free(DAT_00a0f830);
        }
        local_8d = 1;
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_58);
        local_61 = local_8d;
      }
      else {
        uType = 1;
        basic_string<>();
        lpCaption = (LPCSTR)FUN_00401c50();
        basic_string<>();
        lpText = (LPCSTR)FUN_00401c50();
        MessageBoxA((HWND)0x0,lpText,lpCaption,uType);
        local_85 = 0;
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_58);
        local_61 = local_85;
      }
    }
    else {
      local_71 = 0;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_58);
      local_61 = local_71;
    }
  }
  ExceptionList = local_10;
  return local_61;
}

