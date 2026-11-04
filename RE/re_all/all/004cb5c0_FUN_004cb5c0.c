
void __fastcall FUN_004cb5c0(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_007b0e96;
  local_10 = ExceptionList;
  local_8 = 1;
  ExceptionList = &local_10;
  FUN_004bd6d0(param_1);
  local_8 = local_8 & 0xffffff00;
  FUN_004bd510();
  local_8 = 0xffffffff;
  FUN_004c1380();
  ExceptionList = local_10;
  return;
}

