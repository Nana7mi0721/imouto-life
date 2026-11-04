
int __fastcall FUN_004ad980(int param_1)

{
  undefined4 uVar1;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b004b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004ce850();
  local_8 = 0;
  FUN_004cfc10();
  local_8._0_1_ = 1;
  FUN_004ce950();
  local_14 = 2000;
  FUN_004ce160(&local_14);
  uVar1 = FUN_00477ec0();
  local_8._0_1_ = 2;
  FUN_004cfd10(uVar1);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00477f40();
  *(undefined4 *)(param_1 + 0x20) = 0xfffffffe;
  *(undefined4 *)(param_1 + 0x24) = 0;
  ExceptionList = local_10;
  return param_1;
}

