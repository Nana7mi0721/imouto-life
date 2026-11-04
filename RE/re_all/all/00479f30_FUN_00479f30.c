
undefined4 __fastcall FUN_00479f30(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af04a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0046cc80();
  local_8 = 0;
  FUN_004cd090();
  local_8._0_1_ = 1;
  FUN_004cf2a0();
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00479fb0();
  ExceptionList = local_10;
  return param_1;
}

