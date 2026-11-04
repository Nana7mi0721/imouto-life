
basic_string<char,std::char_traits<char>,std::allocator<char>_> * __thiscall
FUN_004b4780(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0486;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1,param_2);
  local_8 = 0;
  _eh_vector_copy_constructor_iterator_
            (param_1 + 0x1c,param_2 + 0x1c,0x1c,0x10,
             std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
             basic_string<char,std::char_traits<char>,std::allocator<char>_>,
             std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>);
  FUN_004cd4e0(param_2 + 0x1dc);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004cd890(param_2 + 0x1ec);
  ExceptionList = local_10;
  return param_1;
}

