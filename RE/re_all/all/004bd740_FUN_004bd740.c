
undefined4 __fastcall FUN_004bd740(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0abd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004bd7f0(0);
  local_8 = 0;
  FUN_004d3ba0();
  local_8._0_1_ = 1;
  FUN_004c0290();
  local_8._0_1_ = 2;
  FUN_004c0bb0();
  FUN_004c0c10();
  FUN_004d3ba0();
  local_8._0_1_ = 3;
  FUN_004c0c70();
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004c0d40();
  ExceptionList = local_10;
  return param_1;
}

