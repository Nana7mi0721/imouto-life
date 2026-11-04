
void __fastcall FUN_004bd6d0(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007b0a74;
  local_10 = ExceptionList;
  local_8 = 2;
  ExceptionList = &local_10;
  FUN_00476910(param_1);
  local_8._0_1_ = 1;
  FUN_004ce950();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004ce950();
  local_8 = 0xffffffff;
  FUN_0049c1c0();
  ExceptionList = local_10;
  return;
}

