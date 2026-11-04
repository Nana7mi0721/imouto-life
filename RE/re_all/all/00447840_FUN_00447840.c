
int __fastcall FUN_00447840(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad753;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00471a40();
  local_8 = 0;
  FUN_00479f30();
  local_8._0_1_ = 1;
  FUN_00471820();
  local_8._0_1_ = 2;
  basic_string<>();
  local_8._0_1_ = 3;
  _eh_vector_constructor_iterator_
            ((void *)(param_1 + 0x1698),0x1c,0xf,basic_string<>,
             std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>);
  local_8._0_1_ = 4;
  FUN_004cf7a0();
  local_8._0_1_ = 5;
  FUN_004ce850();
  local_8._0_1_ = 6;
  FUN_004ce850();
  local_8._0_1_ = 7;
  FUN_004d2660();
  local_8._0_1_ = 8;
  FUN_004d2ad0();
  local_8._0_1_ = 9;
  FUN_004ce850();
  local_8._0_1_ = 10;
  FUN_004719a0();
  local_8 = CONCAT31(local_8._1_3_,0xb);
  FUN_00447960();
  ExceptionList = local_10;
  return param_1;
}

