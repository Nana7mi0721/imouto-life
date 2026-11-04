
void __fastcall FUN_00609ae0(int param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_007b27b8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf0));
  FUN_006034c0();
  local_4 = 0xffffffff;
  FUN_00604af0();
  ExceptionList = local_c;
  return;
}

