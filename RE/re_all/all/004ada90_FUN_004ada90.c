
void __fastcall
FUN_004ada90(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007b15e8;
  local_10 = ExceptionList;
  local_8 = 7;
  ExceptionList = &local_10;
  FUN_004ce950();
  local_8._0_1_ = 6;
  FUN_004cd4c0();
  local_8._0_1_ = 5;
  FUN_004cdf30();
  local_8._0_1_ = 4;
  FUN_004cc250();
  local_8._0_1_ = 3;
  FUN_004cd870();
  local_8._0_1_ = 2;
  FUN_004cc250();
  local_8._0_1_ = 1;
  FUN_004cc250();
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(param_1 + 0x1c);
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(param_1);
  ExceptionList = local_10;
  return;
}

