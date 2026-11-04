
undefined4 FUN_0056da60(LPCRITICAL_SECTION param_1,undefined4 param_2,LONG param_3)

{
  HANDLE pvVar1;
  int iVar2;
  
  pvVar1 = (HANDLE)GetCurrentThreadId();
  EnterCriticalSection(param_1);
  iVar2 = FUN_0056d0a0(param_2);
  if (0x1ff < iVar2) {
    iVar2 = 0x1ff;
  }
  FUN_0056d420(param_1 + 1,param_2,iVar2);
  *(undefined1 *)((int)&param_1[1].DebugInfo + iVar2) = 0;
  param_1[0x16].OwningThread = pvVar1;
  param_1[0x16].RecursionCount = param_3;
  return 0;
}

