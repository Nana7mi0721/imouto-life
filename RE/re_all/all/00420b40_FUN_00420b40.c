
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_00420b40(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1)

{
  char *_Format;
  LPCSTR lpCaption;
  UINT uType;
  char local_258 [516];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_54 [28];
  int local_38;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_34 [28];
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ac27c;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 1;
  basic_string<>();
  local_8._0_1_ = 2;
  local_14 = FUN_0052e3c0();
  if (local_14 == 0) {
    basic_string<>(&DAT_007cc640);
    _Format = (char *)FUN_00401c50();
    _sprintf(local_258,_Format);
    uType = 0;
    basic_string<>(&DAT_007cc698);
    lpCaption = (LPCSTR)FUN_00401c50();
    MessageBoxA((HWND)0x0,local_258,lpCaption,uType);
    basic_string<>();
    local_8._0_1_ = 1;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_54);
  }
  else {
    local_38 = FUN_0052c9a0();
    DAT_00a11790 = 0;
    if (DAT_00a117ec == 0) {
      DAT_00a0f830 = _malloc(local_38 + 1);
      _memset(DAT_00a0f830,0,local_38 + 1);
    }
    FUN_0052cde0();
    thunk_FUN_00580b80();
    DAT_00a0f830[local_38] = '\0';
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_34,
               DAT_00a0f830);
    if (DAT_00a117ec == 0) {
      _free(DAT_00a0f830);
    }
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_34);
    local_8._0_1_ = 1;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_54);
  }
  ExceptionList = local_10;
  return param_1;
}

