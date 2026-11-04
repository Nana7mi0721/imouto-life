
int FUN_004cbe00(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 local_70 [4];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_6c [84];
  undefined1 local_18 [4];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0ed0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004d58f0(&local_14,param_1);
  uVar2 = FUN_004ce060(local_18);
  cVar1 = const_iterator__operator__(uVar2);
  if (cVar1 == '\0') {
    uVar2 = FUN_004e9610();
    uVar2 = FUN_004d52c0(uVar2);
    cVar1 = FUN_004d59a0(param_1,uVar2);
    if (cVar1 == '\0') goto LAB_004cbed8;
  }
  uVar2 = basic_string<>();
  local_8 = 0;
  uVar2 = FUN_004df080(param_1,uVar2);
  local_8._0_1_ = 1;
  puVar3 = (undefined4 *)FUN_004d5320(local_70,local_14,uVar2);
  local_14 = *puVar3;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004d3e50();
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_6c);
LAB_004cbed8:
  iVar4 = FUN_004df340();
  ExceptionList = local_10;
  return iVar4 + 0x1c;
}

