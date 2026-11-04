
void __fastcall FUN_00477f40(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007b0068;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_004cc250(param_1);
  local_8 = 0xffffffff;
  FUN_004ce950();
  ExceptionList = local_10;
  return;
}

