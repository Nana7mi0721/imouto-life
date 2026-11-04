
undefined4 __fastcall FUN_004bd130(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0958;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004d3360();
  local_8 = 0;
  FUN_004d3540();
  local_8._0_1_ = 1;
  FUN_004d39c0();
  local_8._0_1_ = 2;
  FUN_004d39c0();
  local_8._0_1_ = 3;
  FUN_00447840();
  local_8._0_1_ = 4;
  FUN_00471bd0();
  local_8._0_1_ = 5;
  FUN_00436790();
  local_8._0_1_ = 6;
  FUN_004441f0();
  local_8._0_1_ = 7;
  FUN_00472ab0(0);
  local_8._0_1_ = 8;
  FUN_004718a0();
  local_8._0_1_ = 9;
  basic_string<>();
  local_8 = CONCAT31(local_8._1_3_,10);
  FUN_004b2e30();
  ExceptionList = local_10;
  return param_1;
}

