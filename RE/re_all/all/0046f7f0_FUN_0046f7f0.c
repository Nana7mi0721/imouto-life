
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __thiscall
FUN_0046f7f0(int param_1,int param_2,int param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *piVar5;
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
  if ((param_2 < iVar1) && (-1 < param_2)) {
    FUN_004d0120();
    iVar1 = FUN_004cfc90();
    if ((param_3 < iVar1) && (-1 < param_3)) {
      FUN_004d0120();
      iVar1 = FUN_004ce080();
      if ((param_4 < iVar1) && (-1 < param_4)) {
        FUN_004d0120();
        piVar5 = (int *)FUN_004ce990();
        local_14 = *piVar5;
        if (local_14 / 1000 == 1) {
          if (param_5 != (undefined4 *)0x0) {
            FUN_004d0120();
            FUN_004cfcd0();
            puVar4 = (undefined4 *)FUN_004ce990();
            *param_5 = *puVar4;
          }
          FUN_004d0120();
          FUN_004cfcd0();
          puVar4 = (undefined4 *)FUN_004ce990();
          uVar3 = *puVar4;
        }
        else {
          uVar3 = 0;
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
        uVar3 = 0;
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
      FUN_004d05c0();
      puVar4 = (undefined4 *)FUN_004ce990();
      uVar3 = *puVar4;
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
    uVar3 = 0;
  }
  ExceptionList = local_10;
  return uVar3;
}

