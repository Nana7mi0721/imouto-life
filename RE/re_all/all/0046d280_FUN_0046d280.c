
undefined1 * __fastcall FUN_0046d280(undefined1 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae78b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004ce300();
  local_8 = 0;
  param_1[1] = 3;
  param_1[2] = 3;
  param_1[3] = 3;
  *param_1 = 0;
  param_1[4] = 3;
  param_1[5] = 2;
  FUN_004ce660();
  ExceptionList = local_10;
  return param_1;
}

