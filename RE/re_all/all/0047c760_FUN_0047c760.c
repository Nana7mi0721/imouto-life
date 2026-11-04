
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __thiscall FUN_0047c760(int param_1,int param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_38 [28];
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007afdf8;
  local_10 = ExceptionList;
  local_1c = DAT_0084b484;
  if (param_3 < 0) {
    uVar3 = 0;
  }
  else {
    ExceptionList = &local_10;
    piVar2 = (int *)FUN_004cc020(&param_3);
    local_14 = *piVar2;
    if (((local_14 == 0) || (local_14 == *(int *)(param_1 + 0x60))) ||
       (local_14 == *(int *)(param_1 + 0x68))) {
      uVar3 = 0;
    }
    else {
      FUN_0055f370(local_14);
      FUN_00515700(local_14,0);
      uVar3 = FUN_004cc020(&param_3);
      puVar4 = (undefined4 *)FUN_004cc020(uVar3);
      *puVar4 = 0;
      puVar4 = (undefined4 *)FUN_004cc020(&param_3);
      *puVar4 = 0;
      if ((int)(&DAT_00a14328)[param_2] <= param_3) {
        FUN_0046ff30(local_38,param_2 + 1,param_3,0,0);
        local_8 = 0;
        FUN_004ccca0(&local_18,local_38);
        uVar3 = FUN_004ce060(local_3c);
        cVar1 = const_iterator__operator__(uVar3);
        if (cVar1 != '\0') {
          iVar5 = FUN_004d07e0();
          FUN_0055f370(*(undefined4 *)(iVar5 + 0x1c));
          iVar5 = FUN_004d07e0(0);
          FUN_00515700(*(undefined4 *)(iVar5 + 0x1c));
          FUN_004e7cd0(local_40,local_18);
        }
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_38);
      }
      uVar3 = 1;
    }
  }
  ExceptionList = local_10;
  return uVar3;
}

