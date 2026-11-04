
void __fastcall FUN_0046f510(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007af0b8;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_004d8fa0(param_1);
  local_8 = 0xffffffff;
  FUN_0046f2d0();
  ExceptionList = local_10;
  return;
}

