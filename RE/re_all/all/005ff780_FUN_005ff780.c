
undefined4 FUN_005ff780(int param_1,undefined4 *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + -100);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + -200) == 0) {
    *param_2 = 0;
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  if (*(int *)(param_1 + 0x44) < 2) {
    *param_2 = 0;
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x44) + -1;
  uVar2 = __alldiv(*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x4c),iVar1,
                   iVar1 >> 0x1f);
  *param_2 = uVar2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}

