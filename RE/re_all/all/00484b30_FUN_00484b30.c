
void __fastcall FUN_00484b30(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007b045c;
  local_10 = ExceptionList;
  local_8 = 3;
  ExceptionList = &local_10;
  FUN_004cd070(param_1);
  local_8._0_1_ = 2;
  FUN_004cd070();
  local_8._0_1_ = 1;
  FUN_00471980();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004d0350();
  local_8 = 0xffffffff;
  FUN_004cff00();
  ExceptionList = local_10;
  return;
}

