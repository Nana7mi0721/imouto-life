
undefined1 * __fastcall FUN_0044e840(undefined1 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad89d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004d1f30();
  local_8 = 0;
  FUN_004ce9d0();
  local_8._0_1_ = 1;
  FUN_004cf7f0();
  local_8._0_1_ = 2;
  FUN_004ce850();
  local_8._0_1_ = 3;
  FUN_004ce850();
  local_8 = CONCAT31(local_8._1_3_,4);
  basic_string<>();
  *(undefined4 *)(param_1 + 4) = 0;
  *param_1 = 0;
  param_1[0x850] = 1;
  *(undefined4 *)(param_1 + 0x85c) = 0;
  *(undefined4 *)(param_1 + 0x884) = 0;
  *(undefined4 *)(param_1 + 0x88c) = 0;
  *(undefined4 *)(param_1 + 0x888) = 0;
  param_1[0x8a4] = 0;
  *(undefined4 *)(param_1 + 0x890) = 0;
  *(undefined4 *)(param_1 + 0x894) = 0xfffffc18;
  *(undefined4 *)(param_1 + 0x880) = 0;
  ExceptionList = local_10;
  return param_1;
}

