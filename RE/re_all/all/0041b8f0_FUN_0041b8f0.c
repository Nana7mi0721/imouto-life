
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_0041b8f0(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1)

{
  undefined4 uVar1;
  char local_838 [512];
  char local_638 [516];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_434 [28];
  char local_418 [512];
  CHAR local_218 [516];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007abe2c;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  uVar1 = 0;
  ExceptionList = &local_10;
  GetModuleFileNameA((HMODULE)0x0,local_218,0x400);
  __splitpath(local_218,local_838,local_638,(char *)0x0,(char *)0x0);
  _sprintf(local_418,"%s%s",local_838,local_638,uVar1);
  basic_string<>(local_418);
  local_8 = 1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1,local_434);
  local_8 = local_8 & 0xffffff00;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_434)
  ;
  ExceptionList = local_10;
  return param_1;
}

