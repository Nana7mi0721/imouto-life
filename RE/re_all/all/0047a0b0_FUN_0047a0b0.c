
undefined4 * __thiscall FUN_0047a0b0(undefined4 *param_1,undefined4 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af09b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004d1f30();
  local_8 = 0;
  *param_1 = param_2;
  FUN_004d2300();
  FUN_0047a120();
  ExceptionList = local_10;
  return param_1;
}

