
void FUN_004b6440(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,
                 undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1cc [28];
  int local_1b0;
  int local_1ac;
  int local_1a8;
  int local_1a4;
  int aiStack_1a0 [100];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b067b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1a4 = FUN_00477980(param_2);
  for (local_1a8 = 0; local_1a8 < local_1a4; local_1a8 = local_1a8 + 1) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(param_1,"\"");
    iVar4 = local_1a8;
    FUN_004d0570(param_2);
    uVar1 = FUN_004cc470(iVar4);
    FUN_004cb880(uVar1);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(param_1,"\",");
    iVar4 = local_1a8;
    FUN_004d0120(param_2);
    piVar2 = (int *)FUN_004ce990(iVar4);
    aiStack_1a0[local_1a8] = *piVar2 / 1000;
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(param_1,"\r\n");
  for (local_1ac = param_3; local_1ac < param_3 + param_4; local_1ac = local_1ac + 1) {
    for (local_1b0 = 0; local_1b0 < local_1a4; local_1b0 = local_1b0 + 1) {
      if (aiStack_1a0[local_1b0] == 1) {
        uVar1 = FUN_0046f7f0(param_2,local_1ac,local_1b0,0);
        pcVar3 = (char *)FUN_0041b5f0(uVar1);
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (param_1,pcVar3);
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(param_1,",")
        ;
      }
      else if (aiStack_1a0[local_1b0] == 2) {
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (param_1,"\"");
        uVar1 = FUN_0046ff30(local_1cc,param_2,local_1ac,local_1b0,0);
        local_8 = 0;
        FUN_004cb880(uVar1);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1cc);
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (param_1,"\",");
      }
    }
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(param_1,"\r\n");
  }
  ExceptionList = local_10;
  return;
}

