
int __thiscall FUN_006009b0(int param_1,int *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 local_1c;
  void *pvStack_18;
  undefined1 local_14 [8];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b23f8;
  pvStack_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x1c);
  ExceptionList = &pvStack_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  iVar1 = (**(code **)(*param_2 + 0x14))(param_2,&local_1c,local_14);
  if (iVar1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = pvStack_18;
    return iVar1;
  }
  *(undefined4 *)(param_1 + 0x38) = unaff_ESI;
  *(LPCRITICAL_SECTION *)(param_1 + 0x40) = lpCriticalSection;
  *(undefined4 *)(param_1 + 0x3c) = unaff_EBX;
  *(undefined4 *)(param_1 + 0x44) = local_1c;
  *(undefined4 *)(param_1 + 0x48) = 0;
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = pvStack_18;
  return 0;
}

