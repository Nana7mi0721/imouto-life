
int __fastcall FUN_004a66a0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b02ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00447840();
  local_8 = 0;
  FUN_00471bd0();
  local_8._0_1_ = 1;
  FUN_00436790();
  local_8._0_1_ = 2;
  FUN_004441f0();
  local_8._0_1_ = 3;
  FUN_00472ab0(0);
  local_8._0_1_ = 4;
  FUN_004718a0();
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004a6770();
  *(int *)(param_1 + 0x2458) = param_1 + 0x1918;
  *(undefined4 *)(param_1 + 0x2228) = 0;
  ExceptionList = local_10;
  return param_1;
}

