
int __thiscall
FUN_00606d60(int param_1,DWORD param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar1;
  uint uVar2;
  DWORD DVar3;
  void *_Memory;
  int iVar4;
  longlong lVar5;
  
  if (param_3 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  if (param_4 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  if (param_5 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  *param_3 = 0;
  DVar3 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x6c),param_2);
  while( true ) {
    if (DVar3 != 0) {
      return -0x7ffbfdd2;
    }
    _Memory = (void *)FUN_006071b0();
    if (_Memory != (void *)0x0) break;
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x1c);
    EnterCriticalSection(lpCriticalSection);
    if ((*(int *)(param_1 + 0x34) != 0) && (*(int *)(param_1 + 0x74) == 0)) {
      LeaveCriticalSection(lpCriticalSection);
      return -0x7ffbfdd9;
    }
    LeaveCriticalSection(lpCriticalSection);
    DVar3 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x6c),param_2);
  }
  iVar4 = *(int *)((int)_Memory + 0x24);
  if (iVar4 == 1) {
    iVar4 = *(int *)((int)_Memory + 0xc);
    uVar1 = *(uint *)((int)_Memory + 0x14);
    uVar2 = *(uint *)((int)_Memory + 8);
    lVar5 = (**(code **)(**(int **)(param_1 + 0x18) + 0xc))(0);
    if (lVar5 == CONCAT44(((int)uVar1 >> 0x1f) + iVar4 + (uint)CARRY4(uVar1,uVar2),uVar1 + uVar2)) {
      iVar4 = 0;
    }
    else {
      iVar4 = -0x7fffbffb;
    }
  }
  *param_5 = *(undefined4 *)((int)_Memory + 0x14);
  *param_3 = *(undefined4 *)((int)_Memory + 0x1c);
  *param_4 = *(undefined4 *)((int)_Memory + 0x20);
  _free(_Memory);
  return iVar4;
}

