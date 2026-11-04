
undefined4 __fastcall FUN_004f7330(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b200d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  basic_string<>();
  local_8._0_1_ = 1;
  FUN_004cf7a0();
  local_8._0_1_ = 2;
  FUN_004d0ca0();
  local_8._0_1_ = 3;
  FUN_004cc150();
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004f73c0();
  ExceptionList = local_10;
  return param_1;
}

