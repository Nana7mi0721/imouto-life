
undefined4 FUN_006005c0(int param_1,undefined4 *param_2,LPCWSTR param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2308;
  pvStack_c = ExceptionList;
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
  ExceptionList = &pvStack_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  *(undefined4 **)(param_1 + 0x34) = param_2;
  if (param_2 == (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  else {
    iVar2 = (**(code **)*param_2)(param_2,&DAT_0085e9f4,(undefined4 *)(param_1 + 0x38));
    if (-1 < iVar2) {
      piVar1 = *(int **)(param_1 + 0x38);
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  if (*(void **)(param_1 + 0x30) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x30));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (param_3 != (LPCWSTR)0x0) {
    iVar2 = lstrlenW(param_3);
    uVar5 = (iVar2 + 1U) * 2;
    puVar3 = operator_new(uVar5);
    *(undefined4 **)(param_1 + 0x30) = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      for (uVar4 = (iVar2 + 1U & 0x7fffffff) >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar3 = *(undefined4 *)param_3;
        param_3 = param_3 + 2;
        puVar3 = puVar3 + 1;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(char *)puVar3 = (char)*param_3;
        param_3 = (LPCWSTR)((int)param_3 + 1);
        puVar3 = (undefined4 *)((int)puVar3 + 1);
      }
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = pvStack_c;
  return 0;
}

