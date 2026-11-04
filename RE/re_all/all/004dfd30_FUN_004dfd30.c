
basic_string<char,std::char_traits<char>,std::allocator<char>_> * __thiscall
FUN_004dfd30(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b165e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1,param_2);
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1 + 0x1c,param_2 + 0x1c);
  local_8._0_1_ = 1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1 + 0x38,param_2 + 0x38);
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_2 + 0x54);
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_2 + 0x58);
  *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_2 + 0x5c);
  *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_2 + 0x60);
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_2 + 100);
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_2 + 0x68);
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_2 + 0x6c);
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_2 + 0x70);
  *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_2 + 0x74);
  *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_2 + 0x78);
  *(undefined8 *)(param_1 + 0x80) = *(undefined8 *)(param_2 + 0x80);
  *(undefined8 *)(param_1 + 0x88) = *(undefined8 *)(param_2 + 0x88);
  *(undefined8 *)(param_1 + 0x90) = *(undefined8 *)(param_2 + 0x90);
  param_1[0x98] =
       *(basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_2 + 0x98);
  _eh_vector_copy_constructor_iterator_
            (param_1 + 0x9c,param_2 + 0x9c,0x10,4,FUN_004cdf90,FUN_004ce950);
  *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(param_2 + 0xdc);
  param_1[0xe0] =
       *(basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_2 + 0xe0);
  param_1[0xe1] =
       *(basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_2 + 0xe1);
  param_1[0xe2] =
       *(basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_2 + 0xe2);
  param_1[0xe3] =
       *(basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_2 + 0xe3);
  *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_2 + 0xe4);
  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_2 + 0xe8);
  *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_2 + 0xec);
  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_2 + 0xf0);
  *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(param_2 + 0xf4);
  *(undefined4 *)(param_1 + 0xf8) = *(undefined4 *)(param_2 + 0xf8);
  *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)(param_2 + 0xfc);
  *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(param_2 + 0x100);
  param_1[0x104] =
       *(basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_2 + 0x104);
  *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_2 + 0x108);
  *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(param_2 + 0x10c);
  FUN_004cdf90(param_2 + 0x110);
  *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(param_2 + 0x120);
  ExceptionList = local_10;
  return param_1;
}

