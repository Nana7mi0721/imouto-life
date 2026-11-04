
void __fastcall FUN_004f84f0(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007b206b;
  local_10 = ExceptionList;
  local_8 = 4;
  ExceptionList = &local_10;
  FUN_004ce950();
  local_8._0_1_ = 3;
  FUN_004ce950();
  local_8._0_1_ = 2;
  FUN_004ce950();
  local_8._0_1_ = 1;
  FUN_004cc250();
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             ((int)param_1 + 0x3e0));
  local_8 = 0xffffffff;
  _eh_vector_destructor_iterator_(param_1,0x10,0x3c,FUN_004ce950);
  ExceptionList = local_10;
  return;
}

