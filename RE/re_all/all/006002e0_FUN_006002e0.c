
int FUN_006002e0(int *param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2308;
  pvStack_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)param_1[0xb];
  ExceptionList = &pvStack_c;
  EnterCriticalSection(lpCriticalSection);
  param_1[5] = param_2;
  param_1[6] = param_3;
  iVar4 = 0;
  local_4 = 0;
  if ((param_1[2] == 0) && (iVar1 = (**(code **)(*param_1 + 0x14))(param_1), iVar1 < 0)) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if (param_1[2] != 2) {
      iVar1 = (**(code **)(param_1[-3] + 0x18))();
      if (0 < iVar1) {
        do {
          piVar2 = (int *)(**(code **)(param_1[-3] + 0x1c))(iVar4);
          if ((piVar2[6] != 0) &&
             (iVar3 = (**(code **)(*piVar2 + 0x1c))(param_2,param_3), iVar3 < 0)) {
            LeaveCriticalSection(lpCriticalSection);
            ExceptionList = pvStack_c;
            return iVar3;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar1);
      }
    }
    param_1[2] = 2;
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = 0;
  }
  ExceptionList = pvStack_c;
  return iVar1;
}

