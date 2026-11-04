
DWORD FUN_005fd5e0(HANDLE param_1,uint param_2,HWND param_3,uint param_4,int param_5)

{
  bool bVar1;
  DWORD DVar2;
  int iVar3;
  HANDLE pvVar4;
  DWORD DVar5;
  uint nCount;
  uint dwMilliseconds;
  UINT UVar6;
  WPARAM wParam;
  LPARAM lParam;
  HANDLE local_24;
  int local_20;
  tagMSG local_1c;
  
  UVar6 = param_4;
  bVar1 = false;
  local_24 = param_1;
  local_20 = param_5;
  if ((param_2 != 0xffffffff) && (param_2 != 0)) {
    param_1 = (HANDLE)GetTickCount();
  }
  nCount = (param_5 != 0) + 1;
  DVar2 = WaitForMultipleObjects(nCount,&local_24,0,0);
  if (nCount <= DVar2) {
    do {
      dwMilliseconds = param_2;
      if (10 < param_2) {
        dwMilliseconds = 10;
      }
      DVar2 = MsgWaitForMultipleObjects
                        (nCount,&local_24,0,dwMilliseconds,
                         (-(uint)(param_3 != (HWND)0x0) & 8) + 0x40);
      if ((DVar2 != nCount) && ((DVar2 != 0x102 || (dwMilliseconds == param_2)))) break;
      if (param_3 != (HWND)0x0) {
        iVar3 = PeekMessageW(&local_1c,param_3,UVar6,UVar6,1);
        while (iVar3 != 0) {
          DispatchMessageW(&local_1c);
          iVar3 = PeekMessageW(&local_1c,param_3,UVar6,UVar6,1);
        }
      }
      PeekMessageW(&local_1c,(HWND)0x0,0,0,0);
      if ((param_2 != 0xffffffff) && (param_2 != 0)) {
        pvVar4 = (HANDLE)GetTickCount();
        if (param_2 < (uint)((int)pvVar4 - (int)param_1)) {
          param_2 = 0;
        }
        else {
          param_2 = param_2 - ((int)pvVar4 - (int)param_1);
        }
        param_1 = pvVar4;
      }
      if (!bVar1) {
        pvVar4 = GetCurrentThread();
        param_4 = GetThreadPriority(pvVar4);
        if (param_4 < 2) {
          iVar3 = 2;
          pvVar4 = GetCurrentThread();
          SetThreadPriority(pvVar4,iVar3);
        }
        bVar1 = true;
      }
      DVar2 = WaitForMultipleObjects(nCount,&local_24,0,0);
    } while (nCount <= DVar2);
    if (bVar1) {
      pvVar4 = GetCurrentThread();
      SetThreadPriority(pvVar4,param_4);
      DVar5 = GetQueueStatus(8);
      if ((DVar5 >> 0x10 & 8) != 0) {
        if ((DAT_00f3f2f0 != 0) ||
           (DAT_00f3f2f0 = RegisterWindowMessageA(s_AMUnblock_00a06024), DAT_00f3f2f0 != 0)) {
          iVar3 = PeekMessageW(&local_1c,(HWND)0xffffffff,DAT_00f3f2f0,DAT_00f3f2f0,1);
          while (iVar3 != 0) {
            iVar3 = PeekMessageW(&local_1c,(HWND)0xffffffff,DAT_00f3f2f0,DAT_00f3f2f0,1);
          }
        }
        lParam = 0;
        wParam = 0;
        UVar6 = DAT_00f3f2f0;
        DVar5 = GetCurrentThreadId();
        PostThreadMessageA(DVar5,UVar6,wParam,lParam);
      }
    }
  }
  return DVar2;
}

