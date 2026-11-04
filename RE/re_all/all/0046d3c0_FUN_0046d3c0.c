
int __fastcall FUN_0046d3c0(int param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae7d4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004ce850();
  local_8 = 0;
  FUN_004cc150();
  local_8._0_1_ = 1;
  FUN_004ce680();
  local_8._0_1_ = 2;
  FUN_004ce850();
  local_8._0_1_ = 3;
  FUN_004ce850();
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004ce950();
  FUN_004ce970(1);
  puVar1 = (undefined4 *)FUN_004ce990(0);
  *puVar1 = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  ExceptionList = local_10;
  return param_1;
}

