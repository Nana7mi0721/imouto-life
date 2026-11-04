
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

basic_string<char,std::char_traits<char>,std::allocator<char>_> * __thiscall
FUN_0046ff30(int param_1,basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_2,
            int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  int *piVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;
  char local_318 [256];
  char local_218 [256];
  char local_118 [256];
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae8b2;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  ExceptionList = &local_10;
  iVar1 = FUN_004d00e0();
  if ((param_3 < iVar1) && (-1 < param_3)) {
    FUN_004d0120();
    iVar1 = FUN_004cfc90();
    if ((param_4 < iVar1) && (-1 < param_4)) {
      FUN_004d0120();
      iVar1 = FUN_004ce080();
      if ((param_5 < iVar1) && (-1 < param_5)) {
        FUN_004d0120();
        piVar4 = (int *)FUN_004ce990();
        local_14 = *piVar4;
        if (local_14 / 1000 == 2) {
          if (param_6 != 0) {
            FUN_004d0120();
            FUN_004cfcd0();
            FUN_004cc4c0();
            FUN_004cb840();
          }
          FUN_004d0120();
          FUN_004cfcd0();
          pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   FUN_004cc4c0();
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_2,pbVar5);
        }
        else {
          basic_string<>();
        }
      }
      else {
        if (*(int *)(param_1 + 4) == 0) {
          basic_string<>();
          FUN_00401c50();
        }
        else if (*(int *)(param_1 + 4) == 1) {
          basic_string<>();
          FUN_00401c50();
        }
        else if (*(int *)(param_1 + 4) == 2) {
          basic_string<>();
          FUN_00401c50();
        }
        FUN_004d0120();
        FUN_004ce080();
        basic_string<>();
        pcVar2 = (char *)FUN_00401c50();
        _sprintf(local_318,pcVar2);
        FUN_00438b60();
        local_8 = 4;
        basic_string<>();
        local_8 = CONCAT31(local_8._1_3_,5);
        basic_string<>(&DAT_007d0628);
        uVar3 = FUN_00401c50();
        basic_string<>(uVar3);
        local_8 = 0xffffffff;
        FUN_0042bed0();
        DAT_00a117cc = 1;
        basic_string<>();
      }
    }
    else {
      if (*(int *)(param_1 + 4) == 0) {
        basic_string<>();
        FUN_00401c50();
      }
      else if (*(int *)(param_1 + 4) == 1) {
        basic_string<>();
        FUN_00401c50();
      }
      else if (*(int *)(param_1 + 4) == 2) {
        basic_string<>();
        FUN_00401c50();
      }
      basic_string<>();
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_218,pcVar2);
      basic_string<>();
      local_8 = 2;
      FUN_00438b60();
      local_8 = CONCAT31(local_8._1_3_,3);
      basic_string<>(local_218);
      local_8 = 0xffffffff;
      FUN_0042bed0();
      DAT_00a117cc = 1;
      basic_string<>();
    }
  }
  else {
    if (*(int *)(param_1 + 4) == 0) {
      basic_string<>();
      FUN_00401c50();
    }
    else if (*(int *)(param_1 + 4) == 1) {
      basic_string<>();
      FUN_00401c50();
    }
    else if (*(int *)(param_1 + 4) == 2) {
      basic_string<>();
      FUN_00401c50();
    }
    basic_string<>();
    pcVar2 = (char *)FUN_00401c50();
    _sprintf(local_118,pcVar2);
    basic_string<>();
    local_8 = 0;
    FUN_00438b60();
    local_8 = CONCAT31(local_8._1_3_,1);
    basic_string<>(local_118);
    local_8 = 0xffffffff;
    FUN_0042bed0();
    DAT_00a117cc = 1;
    basic_string<>();
  }
  ExceptionList = local_10;
  return param_2;
}

