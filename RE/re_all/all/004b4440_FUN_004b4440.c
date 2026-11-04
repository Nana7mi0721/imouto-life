
undefined4 * __thiscall FUN_004b4440(undefined4 *param_1,undefined4 *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b03fc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  FUN_004cd960(param_2 + 2);
  local_8 = 0;
  FUN_004cd0c0(param_2 + 6);
  local_8._0_1_ = 1;
  FUN_004cc180(param_2 + 10);
  local_8._0_1_ = 2;
  FUN_004cd0c0(param_2 + 0xe);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004cdc00(param_2 + 0x12);
  ExceptionList = local_10;
  return param_1;
}

