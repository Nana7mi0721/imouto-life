
void __fastcall FUN_0047a350(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007af102;
  local_10 = ExceptionList;
  local_8 = 3;
  ExceptionList = &local_10;
  FUN_004cee50(param_1);
  local_8._0_1_ = 2;
  FUN_0046f510();
  local_8._0_1_ = 1;
  FUN_0046f320();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004d2300();
  local_8 = 0xffffffff;
  FUN_004788e0();
  ExceptionList = local_10;
  return;
}

