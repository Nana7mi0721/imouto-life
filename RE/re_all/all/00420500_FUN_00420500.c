
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_00420500(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1)

{
  BOOL BVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_38 [28];
  undefined4 local_1c;
  char *local_18;
  HANDLE local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ac204;
  local_10 = ExceptionList;
  local_1c = DAT_0084b484;
  ExceptionList = &local_10;
  basic_string<>(0);
  local_8 = 1;
  FUN_004cb9c0();
  BVar1 = IsClipboardFormatAvailable(1);
  if (BVar1 == 0) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1,local_38);
    local_8 = local_8 & 0xffffff00;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_38
              );
  }
  else {
    BVar1 = OpenClipboard((HWND)0x0);
    if (BVar1 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1,local_38);
      local_8 = local_8 & 0xffffff00;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_38);
    }
    else {
      local_14 = GetClipboardData(1);
      local_18 = GlobalLock(local_14);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_38,
                 local_18);
      GlobalUnlock(local_14);
      CloseClipboard();
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1,local_38);
      local_8 = local_8 & 0xffffff00;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_38);
    }
  }
  ExceptionList = local_10;
  return param_1;
}

