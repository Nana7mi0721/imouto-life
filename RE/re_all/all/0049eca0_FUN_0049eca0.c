
void __fastcall FUN_0049eca0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007afa2d;
  local_10 = ExceptionList;
  local_8 = 4;
  ExceptionList = &local_10;
  FUN_004cd4c0();
  local_8._0_1_ = 3;
  FUN_004cc250();
  local_8._0_1_ = 2;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (param_1 + 0x16c));
  local_8._0_1_ = 1;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (param_1 + 0x150));
  local_8 = (uint)local_8._1_3_ << 8;
  _eh_vector_destructor_iterator_((void *)(param_1 + 0x130),0x10,2,FUN_004ce950);
  local_8 = 0xffffffff;
  FUN_0049c1c0();
  ExceptionList = local_10;
  return;
}

