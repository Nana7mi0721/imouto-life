
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_00429250(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 uVar4;
  int local_38;
  uint local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_007acbc1;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  uVar4 = 0;
  local_8 = 1;
  ExceptionList = &local_10;
  iVar1 = FUN_004cbbc0(&DAT_007cd190,0);
  if (iVar1 == -1) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)&param_2);
    local_8 = local_8 & 0xffffff00;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  }
  else {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              (local_30,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                         *)&param_2);
    local_8._0_1_ = 2;
    local_34 = 0;
    while( true ) {
      uVar2 = FUN_004e5650(uVar4);
      if (uVar2 <= local_34) break;
      pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)local_30,local_34);
      if (*pcVar3 == '\x01') {
        for (local_38 = 0; local_38 < 0x1c; local_38 = local_38 + 1) {
          pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)local_30,local_34 + 1);
          if (*pcVar3 == (&PTR_DAT_0084b2f0)[local_38][1]) {
            FUN_004cba30(local_34,2,(&PTR_DAT_0084b280)[local_38]);
            local_34 = (int)(char)(&PTR_DAT_0084b280)[local_38][1] + local_34;
            break;
          }
        }
      }
      local_34 = local_34 + 1;
    }
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_30);
    local_8._0_1_ = 1;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_30
              );
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  }
  ExceptionList = local_10;
  return param_1;
}

