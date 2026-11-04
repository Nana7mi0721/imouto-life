
undefined4 * __thiscall FUN_004e9690(undefined4 *param_1,undefined4 *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b19aa;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *param_2;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 1),
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_2 + 1));
  local_8 = 0;
  *(undefined1 *)(param_1 + 8) = *(undefined1 *)(param_2 + 8);
  param_1[9] = param_2[9];
  param_1[10] = param_2[10];
  *(undefined1 *)(param_1 + 0xb) = *(undefined1 *)(param_2 + 0xb);
  *(undefined1 *)((int)param_1 + 0x2d) = *(undefined1 *)((int)param_2 + 0x2d);
  FUN_004cea00(param_2 + 0xc);
  local_8._0_1_ = 1;
  FUN_004e4390(param_2 + 0x10);
  local_8._0_1_ = 2;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x14),
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_2 + 0x14));
  local_8._0_1_ = 3;
  FUN_004cc180(param_2 + 0x1b);
  local_8._0_1_ = 4;
  FUN_004e4390(param_2 + 0x1f);
  local_8._0_1_ = 5;
  FUN_004cdc00(param_2 + 0x23);
  local_8._0_1_ = 6;
  FUN_004cd0c0(param_2 + 0x27);
  local_8._0_1_ = 7;
  FUN_004cdf90(param_2 + 0x2b);
  local_8._0_1_ = 8;
  _eh_vector_copy_constructor_iterator_
            (param_1 + 0x2f,param_2 + 0x2f,0x1c,100,
             std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
             basic_string<char,std::char_traits<char>,std::allocator<char>_>,
             std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>);
  param_1[0x2eb] = param_2[0x2eb];
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x2ec),
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_2 + 0x2ec));
  local_8 = CONCAT31(local_8._1_3_,9);
  param_1[0x2f3] = param_2[0x2f3];
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x2f4),
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_2 + 0x2f4));
  ExceptionList = local_10;
  return param_1;
}

