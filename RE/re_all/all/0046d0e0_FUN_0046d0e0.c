
int __fastcall FUN_0046d0e0(int param_1)

{
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae749;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0046d1a0();
  local_8 = 0;
  FUN_0046d220();
  FUN_0046d280();
  local_8._0_1_ = 1;
  FUN_004ce9d0();
  local_8._0_1_ = 2;
  FUN_004cf7a0();
  local_8 = CONCAT31(local_8._1_3_,3);
  *(undefined4 *)(param_1 + 100) = 0;
  local_11 = 0;
  FUN_004cd800(&local_11);
  FUN_004cf7d0(3);
  FUN_0046d300(0);
  ExceptionList = local_10;
  return param_1;
}

