
void __fastcall FUN_004d0f80(basic_filebuf<char,std::char_traits<char>_> *param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007b10b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = &PTR_FUN_007d2174;
  local_8 = 0;
  if (param_1[0x54] != (basic_filebuf<char,std::char_traits<char>_>)0x0) {
    std::basic_filebuf<char,std::char_traits<char>_>::close(param_1);
  }
  if (*(int *)(param_1 + 0x48) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_004d3fb0(1);
  }
  local_8 = 0xffffffff;
  FUN_004d1010(uVar1);
  ExceptionList = local_10;
  return;
}

