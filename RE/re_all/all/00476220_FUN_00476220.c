
void __thiscall FUN_00476220(int param_1,int param_2,undefined4 param_3,undefined1 param_4)

{
  char cVar1;
  undefined4 uVar2;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2c [28];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007aee38;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00515700(*(undefined4 *)(param_1 + 0x100),0);
  *(undefined4 *)(param_1 + 0x100) = 0;
  if (param_2 < 0) {
    if (param_2 == -2) {
      cVar1 = operator!=<>(param_1 + 0x58,&DAT_007d0621);
      if (cVar1 != '\0') {
        uVar2 = FUN_004cbb30();
        uVar2 = FUN_0052bbd0(uVar2);
        *(undefined4 *)(param_1 + 0x100) = uVar2;
      }
    }
    else {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x58)
                 ,"");
      *(undefined1 *)(param_1 + 0xf4) = 1;
      *(undefined4 *)(param_1 + 0xfc) = param_3;
      *(undefined1 *)(param_1 + 0xf3) = param_4;
    }
  }
  else {
    FUN_004cb840(&DAT_00a14c70);
    uVar2 = FUN_0046ff30(local_2c,0xb,param_2,0,0);
    local_8 = 0;
    FUN_004cb880(uVar2);
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2c);
    uVar2 = FUN_004cbb30();
    uVar2 = FUN_0052bbd0(uVar2);
    *(undefined4 *)(param_1 + 0x100) = uVar2;
    *(undefined1 *)(param_1 + 0xf4) = 0;
    *(undefined4 *)(param_1 + 0xfc) = param_3;
    *(undefined1 *)(param_1 + 0xf3) = param_4;
  }
  ExceptionList = local_10;
  return;
}

