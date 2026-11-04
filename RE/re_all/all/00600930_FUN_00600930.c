
void __fastcall FUN_00600930(int param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2438;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  local_4 = 0;
  FUN_006016b0();
  local_4 = 0xffffffff;
  FUN_00602f20();
  ExceptionList = local_c;
  return;
}

