
basic_streambuf<char,std::char_traits<char>_> * __fastcall
FUN_004e0520(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  locale *this;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b168b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = &PTR_FUN_007d21a8;
  FUN_0050d894();
  local_8 = 0;
  this = operator_new(4);
  if (this == (locale *)0x0) {
    local_1c = 0;
  }
  else {
    local_1c = std::locale::locale(this);
  }
  *(undefined4 *)(param_1 + 0x38) = local_1c;
  std::basic_streambuf<char,std::char_traits<char>_>::_Init(param_1);
  ExceptionList = local_10;
  return param_1;
}

