
undefined4 * __fastcall FUN_00481020(undefined4 *param_1)

{
  undefined1 *puVar1;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af440;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  FUN_004ce9d0();
  local_8._0_1_ = 1;
  FUN_004cf7a0();
  local_8._0_1_ = 2;
  basic_string<>();
  local_8._0_1_ = 3;
  FUN_004cc150();
  local_8._0_1_ = 4;
  FUN_004cf7a0();
  local_8._0_1_ = 5;
  FUN_004cd090();
  local_8._0_1_ = 6;
  FUN_004cd090();
  local_8._0_1_ = 7;
  FUN_004ce850();
  local_8._0_1_ = 8;
  _eh_vector_constructor_iterator_
            (param_1 + 0x2f,0x1c,100,basic_string<>,
             std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>);
  local_8._0_1_ = 9;
  basic_string<>();
  local_8._0_1_ = 10;
  basic_string<>();
  local_8 = CONCAT31(local_8._1_3_,0xb);
  *param_1 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 1),"");
  *(undefined1 *)(param_1 + 8) = 0x20;
  *(undefined1 *)(param_1 + 0xb) = 0;
  *(undefined1 *)((int)param_1 + 0x2d) = 0;
  param_1[9] = 2000000;
  param_1[10] = 0;
  FUN_00481260(0);
  FUN_004cf7d0(1);
  puVar1 = (undefined1 *)FUN_004cd7c0(0);
  *puVar1 = 0;
  FUN_004cb9c0();
  FUN_004cc400(10);
  FUN_004cf7d0(10);
  FUN_004cdf30();
  FUN_004cde50(10);
  FUN_004cd310(10);
  FUN_004ce970(5);
  for (local_14 = 0; local_14 < 100; local_14 = local_14 + 1) {
    FUN_004cb9c0();
  }
  param_1[0x2eb] = 0;
  param_1[0x2f3] = 0xffffffff;
  FUN_004cb9c0();
  FUN_004cb9c0();
  ExceptionList = local_10;
  return param_1;
}

