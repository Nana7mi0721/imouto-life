
LPCRITICAL_SECTION __thiscall
FUN_00606b60(LPCRITICAL_SECTION param_1,PRTL_CRITICAL_SECTION_DEBUG param_2)

{
  InitializeCriticalSection(param_1);
  param_1[1].DebugInfo = param_2;
  InitializeCriticalSection((LPCRITICAL_SECTION)&param_1[1].LockCount);
  param_1[2].LockCount = 0;
  FUN_00603890(0);
  FUN_00603890(0);
  FUN_00603040(1);
  FUN_00603040(1);
  param_1[4].LockSemaphore = (HANDLE)0x0;
  param_1[4].SpinCount = 0;
  FUN_00603040(0);
  FUN_00603040(1);
  param_1[5].RecursionCount = 0;
  return param_1;
}

