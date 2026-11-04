
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0041b530(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_1)

{
  LPCSTR lpCaption;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  UINT uType;
  char local_218 [516];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007abd81;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_004cbb30();
  _sprintf(local_218,"%s %d %d");
  uType = 0;
  basic_string<>(&DAT_007cbb48);
  lpCaption = (LPCSTR)FUN_00401c50();
  MessageBoxA((HWND)0x0,local_218,lpCaption,uType);
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
  ExceptionList = local_10;
  return;
}

