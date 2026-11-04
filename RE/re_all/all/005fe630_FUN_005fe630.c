
undefined4 __fastcall FUN_005fe630(int *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar1;
  int iVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2308;
  pvStack_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x25);
  ExceptionList = &pvStack_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  if (param_1[0x19] != 1) {
    param_1[0x19] = 1;
    (*DAT_00aba160)(1);
    (**(code **)(*param_1 + 0x40))();
    if (param_1[0x1b] == 0) {
      uVar1 = (**(code **)(*param_1 + 0x60))();
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = lpCriticalSection;
      return uVar1;
    }
    iVar2 = (**(code **)(*param_1 + 0x54))(param_1[0x1b]);
    if (iVar2 == 0) {
      SetEvent((HANDLE)param_1[0x15]);
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = pvStack_c;
  return 0;
}

