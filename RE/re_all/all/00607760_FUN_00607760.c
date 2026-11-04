
void __fastcall FUN_00607760(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_007b26df;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  if (*(HANDLE *)(param_1 + 0x30) != (HANDLE)0x0) {
    ExceptionList = &pvStack_c;
    CloseHandle(*(HANDLE *)(param_1 + 0x30));
  }
  piVar1 = *(int **)(param_1 + 0x58);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (param_1 == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x10);
  }
  DeleteCriticalSection(lpCriticalSection);
  FUN_00602f20();
  ExceptionList = pvStack_c;
  return;
}

