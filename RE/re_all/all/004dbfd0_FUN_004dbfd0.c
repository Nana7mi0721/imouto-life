
void __thiscall
FUN_004dbfd0(basic_streambuf<char,std::char_traits<char>_> *param_1,undefined4 param_2)

{
  char cVar1;
  void *pvVar2;
  undefined4 local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b149b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  cVar1 = FUN_004dc080();
  if (cVar1 == '\0') {
    *(undefined4 *)(param_1 + 0x3c) = param_2;
    std::basic_streambuf<char,std::char_traits<char>_>::_Init(param_1);
    if (*(int *)(param_1 + 0x48) == 0) {
      pvVar2 = operator_new(0x1c);
      local_8 = 0;
      if (pvVar2 == (void *)0x0) {
        local_20 = 0;
      }
      else {
        local_20 = basic_string<>();
      }
      *(undefined4 *)(param_1 + 0x48) = local_20;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  ExceptionList = local_10;
  return;
}

