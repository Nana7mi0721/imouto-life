
undefined4 FUN_005950d0(uint param_1,LPCWSTR param_2,DWORD param_3)

{
  uint uVar1;
  LPCWSTR pWVar2;
  int iVar3;
  HANDLE pvVar4;
  DWORD DVar5;
  
  pWVar2 = param_2;
  uVar1 = param_1;
  *(DWORD *)(param_1 + 0x28) = param_3;
  *(undefined4 *)(param_1 + 0xc70) = 0;
  if ((param_3 == 0) && (*(int *)(param_1 + 0x18) == 0)) {
    iVar3 = 0;
  }
  else {
    iVar3 = 1;
  }
  *(int *)(param_1 + 0x24) = iVar3;
  if (iVar3 == 1) {
    pvVar4 = CreateFileW(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    *(HANDLE *)(uVar1 + 0x20) = pvVar4;
    if (pvVar4 != (HANDLE)0xffffffff) {
      DVar5 = GetFileSize(pvVar4,&param_1);
      *(DWORD *)(uVar1 + 0x10) = DVar5;
      *(undefined4 *)(uVar1 + 0x10) = *(undefined4 *)(uVar1 + 0x10);
      *(undefined4 *)(uVar1 + 0x14) = 0;
      *(uint *)(uVar1 + 0x14) = *(uint *)(uVar1 + 0x14) | param_1;
      CloseHandle(*(HANDLE *)(uVar1 + 0x20));
      *(undefined4 *)(uVar1 + 0x20) = 0;
      if (*(int *)(uVar1 + 0x28) != 0) {
        iVar3 = FUN_0056e030(0x20000,"..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxFileWin.cpp"
                             ,0x133);
        *(int *)(uVar1 + 0xc70) = iVar3;
        if (iVar3 == 0) {
          FUN_0056e1d0(0);
          FUN_0056bb10(&DAT_007d9c58);
          return 0xffffffff;
        }
      }
      *(undefined4 *)(uVar1 + 0x38) = 0;
      *(undefined4 *)(uVar1 + 0x34) = 0;
      pvVar4 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
      *(HANDLE *)(uVar1 + 0x3c) = pvVar4;
      pvVar4 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCSTR)0x0);
      *(HANDLE *)(uVar1 + 0x40) = pvVar4;
      pvVar4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_00594db0,
                            (LPVOID)(uVar1 + 0x30),0,(LPVOID)(uVar1 + 0x30));
      *(HANDLE *)(uVar1 + 0x34) = pvVar4;
      if (pvVar4 == (HANDLE)0x0) {
        if (*(int *)(uVar1 + 0xc70) != 0) {
          FUN_0056e1d0(*(int *)(uVar1 + 0xc70));
        }
        CloseHandle(*(HANDLE *)(uVar1 + 0x3c));
        CloseHandle(*(HANDLE *)(uVar1 + 0x40));
        FUN_0056bb10(&DAT_007d9c24);
        return 0xffffffff;
      }
      SetThreadPriority(pvVar4,-2);
      *(undefined4 *)(uVar1 + 0x44) = 0;
      FUN_0056cf70(uVar1 + 0x50,0xc00,pWVar2);
      ResetEvent(*(HANDLE *)(uVar1 + 0x40));
      SetEvent(*(HANDLE *)(uVar1 + 0x3c));
      WaitForSingleObject(*(HANDLE *)(uVar1 + 0x40),0xffffffff);
      if (*(int *)(uVar1 + 0x4c) != 1) {
        return 0;
      }
      if (*(int *)(uVar1 + 0xc70) != 0) {
        FUN_0056e1d0(*(int *)(uVar1 + 0xc70));
      }
      CloseHandle(*(HANDLE *)(uVar1 + 0x3c));
      CloseHandle(*(HANDLE *)(uVar1 + 0x40));
      do {
        Sleep(0);
        GetExitCodeThread(*(HANDLE *)(uVar1 + 0x34),&param_3);
      } while (param_3 == 0x103);
      CloseHandle(*(HANDLE *)(uVar1 + 0x34));
      FUN_0056bb10(&DAT_007d9c00);
      return 0xffffffff;
    }
  }
  else {
    pvVar4 = CreateFileW(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    *(HANDLE *)(uVar1 + 0x20) = pvVar4;
    if (pvVar4 != (HANDLE)0xffffffff) {
      DVar5 = GetFileSize(pvVar4,&param_1);
      *(DWORD *)(uVar1 + 0x10) = DVar5;
      *(undefined4 *)(uVar1 + 0x10) = *(undefined4 *)(uVar1 + 0x10);
      *(undefined4 *)(uVar1 + 0x14) = 0;
      *(uint *)(uVar1 + 0x14) = *(uint *)(uVar1 + 0x14) | param_1;
      return 0;
    }
  }
  return 0xffffffff;
}

