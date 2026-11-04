
void __fastcall FUN_004a6940(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007afd0e;
  local_10 = ExceptionList;
  local_8 = 10;
  ExceptionList = &local_10;
  FUN_0047a020();
  local_8._0_1_ = 9;
  FUN_004ce950();
  local_8._0_1_ = 8;
  FUN_004d2e70();
  local_8._0_1_ = 7;
  FUN_004d2ab0();
  local_8._0_1_ = 6;
  FUN_004ce950();
  local_8._0_1_ = 5;
  FUN_004ce950();
  local_8._0_1_ = 4;
  FUN_004cd870();
  local_8._0_1_ = 3;
  _eh_vector_destructor_iterator_
            ((void *)(param_1 + 0x1698),0x1c,0xf,
             std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>);
  local_8._0_1_ = 2;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (param_1 + 0x167c));
  local_8._0_1_ = 1;
  FUN_0047a000();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0047a040();
  local_8 = 0xffffffff;
  FUN_00471b50();
  ExceptionList = local_10;
  return;
}

