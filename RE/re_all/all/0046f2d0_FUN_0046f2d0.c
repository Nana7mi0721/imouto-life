
void __fastcall FUN_0046f2d0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007ae76b;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_004cd870();
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (param_1 + 4));
  ExceptionList = local_10;
  return;
}

