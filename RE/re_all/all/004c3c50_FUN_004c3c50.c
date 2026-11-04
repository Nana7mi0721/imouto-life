
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_004c3c50(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0658;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  ExceptionList = &local_10;
  if ((param_1 == 2) && (ExceptionList = &local_10, -1 < param_2)) {
    ExceptionList = &local_10;
    FUN_0046ff30(local_30,3,param_2,0,0);
    local_8 = 0;
    cVar1 = FUN_004cbb70();
    if (cVar1 != '\0') {
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_30);
      ExceptionList = local_10;
      return;
    }
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_30);
  }
  if ((param_1 != 2) || (-1 < param_2)) {
    FUN_0047a5d0(param_1,param_2,param_3,param_4);
  }
  ExceptionList = local_10;
  return;
}

