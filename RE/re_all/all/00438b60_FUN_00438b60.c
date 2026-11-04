
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_00438b60(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1)

{
  char *pcVar1;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_134 [28];
  char local_118 [260];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad158;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  ExceptionList = &local_10;
  basic_string<>();
  FUN_00401c50();
  basic_string<>();
  local_8 = 1;
  if (DAT_00a0f818 != -1) {
    basic_string<>(&DAT_007ce2ec);
    pcVar1 = (char *)FUN_00401c50();
    _sprintf(local_118,pcVar1);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              (local_134,local_118);
  }
  if (DAT_00a11794 != -1) {
    basic_string<>(&DAT_007ce2fc);
    pcVar1 = (char *)FUN_00401c50();
    _sprintf(local_118,pcVar1);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              (local_134,local_118);
  }
  basic_string<>(&DAT_007ce30c);
  pcVar1 = (char *)FUN_00401c50();
  _sprintf(local_118,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_134,local_118);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )local_134);
  local_8 = local_8 & 0xffffff00;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_134)
  ;
  ExceptionList = local_10;
  return param_1;
}

