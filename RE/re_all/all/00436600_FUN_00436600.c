
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00436600(void)

{
  undefined4 uVar1;
  undefined *puStack_ac;
  undefined4 uStack_a8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_54 [28];
  undefined1 *local_38;
  int local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad0c9;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)&DAT_00a164c4);
  local_8 = 0;
  local_34 = 0;
  while( true ) {
    local_34 = FUN_004cbbc0();
    if (local_34 == -1) break;
    FUN_004cba30();
  }
  local_38 = (undefined1 *)&puStack_ac;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&puStack_ac,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_30);
  FUN_004298c0();
  local_8._0_1_ = 1;
  FUN_004cbb30();
  FUN_004209c0();
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_54);
  uStack_a8 = 0x4366d7;
  ShellExecuteA(DAT_00a0f804,(LPCSTR)0x0,"DebugLog.txt","",(LPCSTR)0x0,1);
  puStack_ac = &DAT_007ce295;
  basic_string<>();
  local_8._0_1_ = 2;
  basic_string<>();
  local_8._0_1_ = 3;
  basic_string<>(&DAT_007ce298);
  uVar1 = FUN_00401c50();
  basic_string<>(uVar1);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0042bed0();
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_30);
  ExceptionList = local_10;
  return;
}

