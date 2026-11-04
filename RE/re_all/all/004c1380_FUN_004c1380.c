
void __fastcall FUN_004c1380(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007b0ccf;
  local_10 = ExceptionList;
  local_8 = 3;
  ExceptionList = &local_10;
  FUN_004c1020(param_1);
  local_8._0_1_ = 2;
  FUN_004d3cb0();
  local_8._0_1_ = 1;
  FUN_004c0fa0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004d3cb0();
  local_8 = 0xffffffff;
  FUN_004c0f80();
  ExceptionList = local_10;
  return;
}

