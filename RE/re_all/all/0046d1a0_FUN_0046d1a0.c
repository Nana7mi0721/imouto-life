
undefined4 * __fastcall FUN_0046d1a0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae76b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  *param_1 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 1),"");
  *(undefined1 *)(param_1 + 8) = 2;
  *(undefined1 *)((int)param_1 + 0x21) = 1;
  *(undefined1 *)((int)param_1 + 0x22) = 0xff;
  *(undefined1 *)((int)param_1 + 0x23) = 0;
  ExceptionList = local_10;
  return param_1;
}

