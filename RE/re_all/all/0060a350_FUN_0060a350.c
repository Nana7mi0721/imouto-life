
undefined4 __thiscall
FUN_0060a350(int param_1,undefined4 *param_2,uint param_3,undefined4 param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2308;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  local_4 = 0;
  iVar1 = (*DAT_00aba168)();
  iVar2 = *(int *)(param_1 + 0x2c) + (uint)CARRY4(param_3,*(uint *)(param_1 + 0x28));
  if ((*(int *)(param_1 + 0x24) <= iVar2) &&
     ((*(int *)(param_1 + 0x24) < iVar2 ||
      (*(uint *)(param_1 + 0x20) < param_3 + *(uint *)(param_1 + 0x28))))) {
    param_3 = *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x28);
  }
  uVar3 = (*(int *)(param_1 + 0x28) + param_3) / *(uint *)(param_1 + 0x30);
  if ((uint)(iVar1 - *(int *)(param_1 + 0x34)) < uVar3) {
    Sleep((*(int *)(param_1 + 0x34) - iVar1) + uVar3);
  }
  puVar4 = (undefined4 *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x28));
  for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *param_2 = *puVar4;
    puVar4 = puVar4 + 1;
    param_2 = param_2 + 1;
  }
  for (uVar3 = param_3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)param_2 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  uVar3 = *(uint *)(param_1 + 0x28);
  *(uint *)(param_1 + 0x28) = uVar3 + param_3;
  *(uint *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (uint)CARRY4(uVar3,param_3);
  *param_5 = param_3;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  ExceptionList = pvStack_c;
  return 0;
}

