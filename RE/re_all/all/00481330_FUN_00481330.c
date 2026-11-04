
void __fastcall FUN_00481330(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007af502;
  local_10 = ExceptionList;
  local_8 = 10;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (param_1 + 0xbd0));
  local_8._0_1_ = 9;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (param_1 + 0xbb0));
  local_8._0_1_ = 8;
  _eh_vector_destructor_iterator_
            ((void *)(param_1 + 0xbc),0x1c,100,
             std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>);
  local_8._0_1_ = 7;
  FUN_004ce950();
  local_8._0_1_ = 6;
  FUN_004cd4c0();
  local_8._0_1_ = 5;
  FUN_004cdf30();
  local_8._0_1_ = 4;
  FUN_004cd870();
  local_8._0_1_ = 3;
  FUN_004cc250();
  local_8._0_1_ = 2;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (param_1 + 0x50));
  local_8._0_1_ = 1;
  FUN_004cd870();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004cee50();
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (param_1 + 4));
  ExceptionList = local_10;
  return;
}

