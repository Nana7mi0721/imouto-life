
void __fastcall FUN_0047a040(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_007af07c;
  local_10 = ExceptionList;
  local_8 = 1;
  ExceptionList = &local_10;
  FUN_004cf3a0(param_1);
  local_8 = local_8 & 0xffffff00;
  FUN_004cdbe0();
  local_8 = 0xffffffff;
  FUN_004d4160();
  ExceptionList = local_10;
  return;
}

