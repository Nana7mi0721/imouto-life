
undefined4
FUN_004ec9b0(undefined4 param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  undefined1 uStack00000024;
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007b1b49;
  local_10 = ExceptionList;
  uVar1 = 0;
  local_8 = 2;
  ExceptionList = &local_10;
  FUN_004dea30(&param_2,&uStack00000024);
  uVar1 = uVar1 | 1;
  local_8._0_1_ = 1;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004b34a0(uVar1);
  ExceptionList = local_10;
  return param_1;
}

