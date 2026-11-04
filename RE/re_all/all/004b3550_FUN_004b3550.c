
void __fastcall FUN_004b3550(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007b030b;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_004ce950(param_1);
  local_8 = 0xffffffff;
  FUN_004cd870();
  ExceptionList = local_10;
  return;
}

