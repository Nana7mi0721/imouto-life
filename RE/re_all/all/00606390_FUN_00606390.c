
undefined4 __thiscall FUN_00606390(int param_1,int *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  bool bVar5;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x20);
  EnterCriticalSection(lpCriticalSection);
  iVar2 = 4;
  bVar5 = true;
  piVar1 = (int *)(*(int *)(param_1 + 0x98) + 0x1a0);
  piVar3 = param_2;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *piVar1 == *piVar3;
    piVar1 = piVar1 + 1;
    piVar3 = piVar3 + 1;
  } while (bVar5);
  if (bVar5) {
    piVar1 = (int *)(*(int *)(param_1 + 0x98) + 0x1b0);
    iVar2 = 4;
    bVar5 = true;
    piVar3 = piVar1;
    piVar4 = &DAT_00ddb33c;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *piVar3 == *piVar4;
      piVar3 = piVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      iVar2 = 4;
      bVar5 = true;
      piVar3 = param_2 + 4;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *piVar1 == *piVar3;
        piVar1 = piVar1 + 1;
        piVar3 = piVar3 + 1;
      } while (bVar5);
      if (!bVar5) goto LAB_006063f4;
    }
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
LAB_006063f4:
  LeaveCriticalSection(lpCriticalSection);
  return 1;
}

