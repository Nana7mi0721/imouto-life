
undefined4 FUN_00607d40(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar3;
  _SYSTEM_INFO local_24;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  if (param_1 == 0xc) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
  }
  EnterCriticalSection(lpCriticalSection);
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  GetSystemInfo(&local_24);
  iVar1 = param_2[2];
  if ((iVar1 == 0) || ((iVar1 - 1U & local_24.dwAllocationGranularity) != 0)) {
    LeaveCriticalSection(lpCriticalSection);
    return 0x8004020e;
  }
  if (*(int *)(param_1 + 0x44) == 1) {
    LeaveCriticalSection(lpCriticalSection);
    return 0x8004020f;
  }
  if (*(int *)(param_1 + 0x20) < *(int *)(param_1 + 0x30)) {
    LeaveCriticalSection(lpCriticalSection);
    return 0x80040210;
  }
  iVar3 = param_2[1] + param_2[3];
  if (iVar3 % iVar1 != 0) {
    iVar3 = iVar3 + (iVar1 - iVar3 % iVar1);
  }
  iVar1 = param_2[3];
  *(int *)(param_1 + 0x34) = iVar3 - iVar1;
  param_3[1] = iVar3 - iVar1;
  uVar2 = *param_2;
  *(undefined4 *)(param_1 + 0x2c) = uVar2;
  *param_3 = uVar2;
  uVar2 = param_2[2];
  *(undefined4 *)(param_1 + 0x38) = uVar2;
  param_3[2] = uVar2;
  uVar2 = param_2[3];
  *(undefined4 *)(param_1 + 0x3c) = uVar2;
  param_3[3] = uVar2;
  *(undefined4 *)(param_1 + 0x40) = 1;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}

