
void __fastcall FUN_004df000(undefined4 param_1)

{
  char cVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007b1578;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  cVar1 = thunk_FUN_005000ec(param_1);
  if (cVar1 == '\0') {
    FUN_004e0440();
  }
  local_8 = 0xffffffff;
  FUN_004e9130();
  ExceptionList = local_10;
  return;
}

