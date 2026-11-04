
undefined4 __thiscall FUN_004b3710(undefined4 param_1,int param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b02ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004b3800(param_2);
  local_8 = 0;
  FUN_004b3c10(param_2 + 0x1918);
  local_8._0_1_ = 1;
  FUN_004b4440(param_2 + 0x2458);
  local_8._0_1_ = 2;
  FUN_004b4500(param_2 + 0x24b0);
  local_8._0_1_ = 3;
  FUN_004b45a0(param_2 + 0x2610);
  local_8._0_1_ = 4;
  FUN_004b4600(param_2 + 0x26a8);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004b46e0(param_2 + 0x2708);
  ExceptionList = local_10;
  return param_1;
}

