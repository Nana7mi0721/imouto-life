
bool FUN_00478010(undefined4 param_1,undefined4 param_2,undefined4 param_3,
                 basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_4)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  undefined1 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007aefb8;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_004d0120(param_1);
  piVar1 = (int *)FUN_004ce990(param_3);
  bVar3 = *piVar1 / 1000 == 2;
  if (bVar3) {
    puVar4 = &param_4;
    iVar2 = *piVar1 % 1000;
    FUN_004d0120(param_1);
    FUN_004cfcd0(param_2);
    FUN_004cc4c0(iVar2);
    FUN_004cb840(puVar4);
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_4);
  }
  else {
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_4);
  }
  ExceptionList = local_10;
  return bVar3;
}

