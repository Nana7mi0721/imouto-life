
undefined4 * __fastcall FUN_004c0290(undefined4 *param_1)

{
  undefined4 uVar1;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0b6d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  _eh_vector_constructor_iterator_
            (param_1 + 8,0x1c,0xf,basic_string<>,
             std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>);
  local_8._0_1_ = 1;
  FUN_004cf7a0();
  local_8._0_1_ = 2;
  FUN_004ce850();
  local_8 = CONCAT31(local_8._1_3_,3);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 1),"");
  param_1[0x71] = 0xffffffff;
  for (local_14 = 0; local_14 < 0xf; local_14 = local_14 + 1) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
               (param_1 + local_14 * 7 + 8),"");
    *(undefined1 *)((int)param_1 + local_14 + 0x250) = 0;
  }
  *param_1 = &DAT_00a17e88;
  FUN_004cd870();
  uVar1 = FUN_004ce080();
  FUN_004cf7d0(uVar1);
  FUN_004ce950();
  FUN_004c03f0();
  param_1[0x27ad] = 0;
  param_1[0x27ae] = 0;
  param_1[0x98] = 0;
  ExceptionList = local_10;
  return param_1;
}

