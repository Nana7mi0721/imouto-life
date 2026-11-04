
void __fastcall FUN_004c0fa0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007b0c6f;
  local_10 = ExceptionList;
  local_8 = 2;
  ExceptionList = &local_10;
  FUN_004ce950();
  local_8._0_1_ = 1;
  FUN_004cd870();
  local_8 = (uint)local_8._1_3_ << 8;
  _eh_vector_destructor_iterator_
            ((void *)(param_1 + 0x20),0x1c,0xf,
             std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>);
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (param_1 + 4));
  ExceptionList = local_10;
  return;
}

