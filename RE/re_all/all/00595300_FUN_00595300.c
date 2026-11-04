
int FUN_00595300(DWORD param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  
  DVar1 = param_1;
  if (*(int *)(param_1 + 0x24) != 1) {
    BVar2 = CloseHandle(*(HANDLE *)(param_1 + 0x20));
    return (BVar2 != 0) - 1;
  }
  WaitForSingleObject(*(HANDLE *)(param_1 + 0x40),0xffffffff);
  *(undefined4 *)(DVar1 + 0x44) = 4;
  ResetEvent(*(HANDLE *)(DVar1 + 0x40));
  SetEvent(*(HANDLE *)(DVar1 + 0x3c));
  WaitForSingleObject(*(HANDLE *)(DVar1 + 0x40),0xffffffff);
  do {
    Sleep(1);
    GetExitCodeThread(*(HANDLE *)(DVar1 + 0x34),&param_1);
  } while (param_1 == 0x103);
  if (*(int *)(DVar1 + 0xc70) != 0) {
    FUN_0056e1d0(*(int *)(DVar1 + 0xc70));
  }
  CloseHandle(*(HANDLE *)(DVar1 + 0x34));
  CloseHandle(*(HANDLE *)(DVar1 + 0x40));
  CloseHandle(*(HANDLE *)(DVar1 + 0x3c));
  return -1;
}

