
void FUN_004ad3b0(undefined4 param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbVar5;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_44 [28];
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007aff68;
  local_10 = ExceptionList;
  local_18 = 0;
  local_1c = 0;
  ExceptionList = &local_10;
  FUN_004d0120(param_1);
  local_14 = FUN_004ce080();
  iVar2 = param_3;
  FUN_004d0120(param_1);
  FUN_004ce970(iVar2);
  iVar2 = param_3;
  FUN_004d05c0(param_1);
  FUN_004cc400(iVar2);
  iVar2 = param_3;
  FUN_004d05c0(param_1);
  FUN_004cde50(iVar2);
  iVar2 = param_3;
  FUN_004d05c0(param_1);
  FUN_004cd310(iVar2);
  iVar2 = param_3;
  FUN_004d05c0(param_1);
  FUN_004cc400(iVar2);
  iVar2 = param_3;
  FUN_004d05c0(param_1);
  FUN_004ce970(iVar2);
  for (local_20 = 0; local_20 < param_3; local_20 = local_20 + 1) {
    if (*(char *)(param_2 + local_20) == '\x01') {
      iVar4 = local_18 + 1000;
      iVar2 = local_20;
      FUN_004d0120(param_1);
      piVar1 = (int *)FUN_004ce990(iVar2);
      *piVar1 = iVar4;
      local_18 = local_18 + 1;
    }
    if (*(char *)(param_2 + local_20) == '\x02') {
      iVar4 = local_1c + 2000;
      iVar2 = local_20;
      FUN_004d0120(param_1);
      piVar1 = (int *)FUN_004ce990(iVar2);
      *piVar1 = iVar4;
      local_1c = local_1c + 1;
    }
  }
  local_24 = 0;
  while( true ) {
    FUN_004d0120(param_1);
    iVar2 = FUN_004cfc90();
    if (iVar2 <= local_24) break;
    for (local_28 = local_14; local_28 < param_3; local_28 = local_28 + 1) {
      iVar2 = local_28;
      FUN_004d0120(param_1);
      piVar1 = (int *)FUN_004ce990(iVar2);
      if (*piVar1 / 1000 == 1) {
        uVar3 = FUN_004ce0e0(local_28);
        iVar2 = local_24;
        FUN_004d0120(param_1);
        FUN_004cfcd0(iVar2);
        FUN_004ce160(uVar3);
      }
      else if (*piVar1 / 1000 == 2) {
        basic_string<>(&DAT_007d0621);
        local_8 = 0;
        pbVar5 = local_44;
        iVar2 = local_24;
        FUN_004d0120(param_1);
        FUN_004cfcd0(iVar2);
        FUN_004cc500(pbVar5);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_44);
      }
    }
    local_24 = local_24 + 1;
  }
  ExceptionList = local_10;
  return;
}

