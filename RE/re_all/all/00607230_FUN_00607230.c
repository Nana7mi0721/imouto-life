
undefined4 __thiscall FUN_00607230(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2308;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  local_4 = 0;
  if (*(int *)(param_1 + 0x34) == 0) {
    iVar1 = FUN_00603a60(param_2);
    if (iVar1 == 0) {
      uVar2 = 0x8007000e;
    }
    else {
      SetEvent(*(HANDLE *)(param_1 + 0x68));
      uVar2 = FUN_00607090();
    }
  }
  else {
    uVar2 = 0x80040227;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  ExceptionList = local_c;
  return uVar2;
}

