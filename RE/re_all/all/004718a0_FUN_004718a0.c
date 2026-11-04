
undefined1 * __fastcall FUN_004718a0(undefined1 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae9e7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004cfe00();
  local_8 = 0;
  FUN_004d0250();
  local_8._0_1_ = 1;
  FUN_004cc650();
  local_8._0_1_ = 2;
  FUN_004ccd30();
  local_8._0_1_ = 3;
  FUN_004ccd30();
  local_8 = CONCAT31(local_8._1_3_,4);
  DAT_00a0f7f8 = 0;
  FUN_004cff00();
  FUN_004d0350();
  *param_1 = 1;
  DAT_00a0f808 = 0xc1;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 4) = 1;
  ExceptionList = local_10;
  return param_1;
}

