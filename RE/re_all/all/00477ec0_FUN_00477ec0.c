
undefined4 __fastcall FUN_00477ec0(undefined4 param_1)

{
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2c [28];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007aef9b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004ce850();
  local_8 = 0;
  FUN_004cc150();
  local_8._0_1_ = 1;
  basic_string<>(&DAT_007d0621);
  local_8._0_1_ = 2;
  FUN_004cc500(local_2c);
  local_8 = CONCAT31(local_8._1_3_,1);
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2c);
  ExceptionList = local_10;
  return param_1;
}

