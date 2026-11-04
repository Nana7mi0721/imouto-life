
void __fastcall FUN_006072f0(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  code *pcVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pcVar1 = EnterCriticalSection_exref;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2660;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x1c);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  iVar2 = FUN_00607140();
  while (iVar2 != 0) {
    local_4 = 0xffffffff;
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
    LeaveCriticalSection(lpCriticalSection);
    FUN_00606ac0();
    (*pcVar1)(lpCriticalSection);
    local_4 = 1;
    FUN_006072c0(iVar2);
    iVar2 = *(int *)(param_1 + 0x70) + -1;
    *(int *)(param_1 + 0x70) = iVar2;
    if ((iVar2 == 0) && (*(int *)(param_1 + 0x74) != 0)) {
      SetEvent(*(HANDLE *)(param_1 + 0x78));
    }
    LeaveCriticalSection(lpCriticalSection);
    pcVar1 = EnterCriticalSection_exref;
    EnterCriticalSection(lpCriticalSection);
    local_4 = 0;
    iVar2 = FUN_00607140();
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return;
}

