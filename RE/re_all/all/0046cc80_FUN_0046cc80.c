
basic_string<char,std::char_traits<char>,std::allocator<char>_> * __fastcall
FUN_0046cc80(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1)

{
  char *pcVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae6d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  basic_string<>(&DAT_007d061c);
  pcVar1 = (char *)FUN_00401c50();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(param_1,pcVar1);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0x14;
  *(undefined4 *)(param_1 + 0x24) = 0xf;
  *(undefined4 *)(param_1 + 0x28) = 0;
  ExceptionList = local_10;
  return param_1;
}

