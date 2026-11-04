
void __fastcall
FUN_004d3e50(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007b0328;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(param_1 + 0x1c);
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(param_1);
  ExceptionList = local_10;
  return;
}

