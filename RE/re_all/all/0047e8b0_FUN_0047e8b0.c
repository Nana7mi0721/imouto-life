
void __thiscall
FUN_0047e8b0(undefined4 param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007af318;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
    FUN_004ccca0(&local_18,&param_2);
    uVar2 = FUN_004ce060(local_1c);
    cVar1 = const_iterator__operator__(uVar2);
    if (cVar1 != '\0') {
      iVar3 = FUN_004d07e0(0,param_1);
      FUN_00515700(*(undefined4 *)(iVar3 + 0x1c));
      FUN_004e7cd0(local_20,local_18);
    }
  }
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  ExceptionList = local_10;
  return;
}

