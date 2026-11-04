
undefined4 FUN_005953c0(int param_1,LONG param_2,LONG param_3)

{
  undefined4 *puVar1;
  int iVar2;
  DWORD DVar3;
  
  iVar2 = param_1;
  if (*(int *)(param_1 + 0x24) == 1) {
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x40),0xffffffff);
    *(undefined4 *)(iVar2 + 0x44) = 3;
    *(LONG *)(iVar2 + 0xc68) = param_2;
    *(LONG *)(iVar2 + 0xc6c) = param_3;
    ResetEvent(*(HANDLE *)(iVar2 + 0x40));
    SetEvent(*(HANDLE *)(iVar2 + 0x3c));
  }
  else {
    puVar1 = (undefined4 *)(param_1 + 0x20);
    param_1 = param_3;
    DVar3 = SetFilePointer((HANDLE)*puVar1,param_2,&param_1,0);
    if (DVar3 == 0xffffffff) {
      DVar3 = GetLastError();
      if (DVar3 != 0) {
        return 0xffffffff;
      }
    }
  }
  return 0;
}

