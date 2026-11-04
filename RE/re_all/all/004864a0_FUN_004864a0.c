
void __fastcall FUN_004864a0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007b191b;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (param_1 + 0x14));
  local_8 = 0xffffffff;
  FUN_004ce950();
  ExceptionList = local_10;
  return;
}

