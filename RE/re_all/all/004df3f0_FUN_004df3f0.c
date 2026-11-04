
basic_string<char,std::char_traits<char>,std::allocator<char>_> * __thiscall
FUN_004df3f0(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b15e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1,param_2);
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1 + 0x1c,param_2 + 0x1c);
  local_8._0_1_ = 1;
  FUN_004cc180(param_2 + 0x38);
  local_8._0_1_ = 2;
  FUN_004cc180(param_2 + 0x48);
  local_8._0_1_ = 3;
  FUN_004e4390(param_2 + 0x58);
  local_8._0_1_ = 4;
  FUN_004cc180(param_2 + 0x68);
  local_8._0_1_ = 5;
  FUN_004cdc00(param_2 + 0x78);
  local_8._0_1_ = 6;
  FUN_004cd0c0(param_2 + 0x88);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004cdf90(param_2 + 0x98);
  ExceptionList = local_10;
  return param_1;
}

