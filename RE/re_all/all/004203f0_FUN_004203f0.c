
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_004203f0(undefined4 param_1)

{
  char cVar1;
  BOOL BVar2;
  int iVar3;
  LPCSTR lpString2;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3c [28];
  undefined4 local_20;
  SIZE_T local_1c;
  LPSTR local_18;
  LPSTR local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ac1d9;
  local_10 = ExceptionList;
  local_20 = DAT_0084b484;
  ExceptionList = &local_10;
  basic_string<>(param_1);
  local_8 = 0;
  cVar1 = FUN_004cbb70();
  if (cVar1 == '\0') {
    BVar2 = OpenClipboard((HWND)0x0);
    if (BVar2 == 0) {
      local_44 = 0;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3c);
      local_40 = local_44;
    }
    else {
      iVar3 = FUN_004e5650();
      local_1c = iVar3 + 1;
      local_18 = GlobalAlloc(0,local_1c);
      local_14 = local_18;
      lpString2 = (LPCSTR)FUN_004cbb30();
      lstrcpyA(local_18,lpString2);
      EmptyClipboard();
      SetClipboardData(1,local_14);
      CloseClipboard();
      local_48 = 1;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3c);
      local_40 = local_48;
    }
  }
  else {
    local_40 = 0;
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3c);
  }
  ExceptionList = local_10;
  return local_40;
}

