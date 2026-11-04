
undefined1 * __thiscall FUN_004e9620(undefined1 *param_1,undefined1 *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b191b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *param_2;
  FUN_004cdf90(param_2 + 4);
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x14),
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_2 + 0x14));
  ExceptionList = local_10;
  return param_1;
}

