
undefined4 __fastcall FUN_004719a0(undefined4 param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007aea16;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004d0890();
  local_8 = 0;
  uVar1 = FUN_00471a40();
  local_8._0_1_ = 1;
  FUN_004d0bd0(uVar1);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00471b50();
  ExceptionList = local_10;
  return param_1;
}

