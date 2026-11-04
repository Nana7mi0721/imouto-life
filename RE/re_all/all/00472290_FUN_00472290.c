
undefined4 * __fastcall FUN_00472290(undefined4 *param_1)

{
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007aec09;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  basic_string<>();
  local_8._0_1_ = 1;
  basic_string<>();
  local_8._0_1_ = 2;
  basic_string<>();
  local_8._0_1_ = 3;
  basic_string<>();
  local_8._0_1_ = 4;
  basic_string<>();
  local_8._0_1_ = 5;
  basic_string<>();
  local_8._0_1_ = 6;
  basic_string<>();
  local_8._0_1_ = 7;
  _eh_vector_constructor_iterator_
            (param_1 + 0x97,0x1c,10,basic_string<>,
             std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>);
  local_8 = CONCAT31(local_8._1_3_,8);
  param_1[0x5c] = 0x94;
  GetVersionExA((LPOSVERSIONINFOA)(param_1 + 0x5c));
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 1),"");
  FUN_004725c0();
  *(undefined1 *)((int)param_1 + 0xbd) = 0;
  *(undefined1 *)((int)param_1 + 0xbe) = 0;
  *(undefined1 *)((int)param_1 + 0xbf) = 0;
  *(undefined1 *)(param_1 + 0x30) = 0;
  *(undefined1 *)((int)param_1 + 0xc1) = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  *(undefined1 *)((int)param_1 + 0xc2) = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x16),"")
  ;
  *(undefined1 *)((int)param_1 + 0xc3) = 0;
  *(undefined1 *)(param_1 + 0x31) = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  *(undefined1 *)(param_1 + 0x3c) = 0;
  *(undefined1 *)((int)param_1 + 0xf1) = 0;
  *(undefined1 *)((int)param_1 + 0xf2) = 0;
  *(undefined1 *)((int)param_1 + 0xf3) = 0;
  param_1[0x3e] = 0x14;
  param_1[0x3f] = 0x14;
  param_1[0x40] = 0;
  *(undefined1 *)(param_1 + 0x3d) = 1;
  *param_1 = 0;
  *(undefined1 *)((int)param_1 + 0x109) = 0;
  param_1[0x45] = 0;
  *(undefined1 *)(param_1 + 0x46) = 0;
  param_1[0x47] = 0;
  param_1[0x4a] = 0;
  *(undefined1 *)(param_1 + 0x4b) = 0;
  param_1[0xdd] = 0;
  for (local_14 = 0; local_14 < 5; local_14 = local_14 + 1) {
    param_1[local_14 + 0x4c] = 0;
    param_1[local_14 * 2 + 0x52] = 0;
    param_1[local_14 * 2 + 0x53] = 0;
  }
  *(undefined1 *)(param_1 + 0x96) = 0;
  *(undefined1 *)((int)param_1 + 0x3a1) = 0;
  *(undefined1 *)(param_1 + 0xe8) = 0;
  param_1[0xde] = 0xffffffff;
  *(undefined1 *)(param_1 + 0xdf) = 0;
  *(undefined1 *)(param_1 + 0x42) = 0;
  param_1[0xef] = 1;
  param_1[0xf0] = 0;
  param_1[0xf1] = 0;
  ExceptionList = local_10;
  return param_1;
}

