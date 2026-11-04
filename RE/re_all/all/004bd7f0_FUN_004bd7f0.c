
undefined4 * __thiscall FUN_004bd7f0(undefined4 *param_1,undefined4 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0adb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  param_1[4] = param_2;
  param_1[0xb] = 0xffffffff;
  *param_1 = 0xffffffff;
  param_1[3] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x17) = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x10),"")
  ;
  param_1[0x1a] = 0;
  param_1[0x1b] = 6;
  *(undefined1 *)((int)param_1 + 0x5d) = 0;
  FUN_004bd8e0();
  ExceptionList = local_10;
  return param_1;
}

