
undefined1 * __thiscall FUN_004b4600(undefined1 *param_1,undefined1 *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b045c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *param_2;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  FUN_004cfe30(param_2 + 0x14);
  local_8 = 0;
  FUN_004d0280(param_2 + 0x24);
  local_8._0_1_ = 1;
  FUN_004b50e0(param_2 + 0x34);
  local_8._0_1_ = 2;
  FUN_004ccd60(param_2 + 0x40);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004ccd60(param_2 + 0x50);
  ExceptionList = local_10;
  return param_1;
}

