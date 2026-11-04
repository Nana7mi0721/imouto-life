
void __fastcall FUN_00604af0(int param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_007b254e;
  pvStack_c = ExceptionList;
  local_4 = 2;
  ExceptionList = &pvStack_c;
  if (*(int **)(param_1 + 0x8c) != (int *)0x0) {
    ExceptionList = &pvStack_c;
    (**(code **)(**(int **)(param_1 + 0x8c) + 0xc))(1);
  }
  if (*(int **)(param_1 + 0x90) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x90) + 0xc))(1);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x74));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5c));
  local_4 = 0xffffffff;
  FUN_005fffa0();
  ExceptionList = pvStack_c;
  return;
}

