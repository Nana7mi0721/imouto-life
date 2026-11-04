
undefined4 * __fastcall FUN_00436790(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad10a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004cd090();
  local_8 = 0;
  FUN_004cd090();
  local_8._0_1_ = 1;
  FUN_004cc150();
  local_8._0_1_ = 2;
  FUN_004cd090();
  local_8._0_1_ = 3;
  FUN_004cd090();
  local_8 = CONCAT31(local_8._1_3_,4);
  *param_1 = &DAT_00a18178;
  FUN_00436830();
  ExceptionList = local_10;
  return param_1;
}

