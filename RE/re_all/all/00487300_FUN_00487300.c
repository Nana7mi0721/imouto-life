
int __thiscall FUN_00487300(int param_1,int param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af749;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004cdf90(param_2);
  local_8 = 0;
  *(undefined1 *)(param_1 + 0x10) = *(undefined1 *)(param_2 + 0x10);
  FUN_004cc180(param_2 + 0x14);
  local_8._0_1_ = 1;
  FUN_004ce6b0(param_2 + 0x24);
  local_8._0_1_ = 2;
  FUN_004cdf90(param_2 + 0x34);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004ce880(param_2 + 0x44);
  ExceptionList = local_10;
  return param_1;
}

