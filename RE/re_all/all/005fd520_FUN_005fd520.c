
void __fastcall FUN_005fd520(int param_1)

{
  int iVar1;
  DWORD DVar2;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  tagMSG local_1c;
  
  iVar1 = *(int *)(param_1 + 0xb4);
  while (iVar1 != 0) {
    PeekMessageW(&local_1c,(HWND)0x0,0,0,0);
    Sleep(1);
    iVar1 = *(int *)(param_1 + 0xb4);
  }
  DVar2 = GetQueueStatus(8);
  if ((DVar2 >> 0x10 & 8) != 0) {
    lParam = 0;
    wParam = 0;
    Msg = 0;
    DVar2 = GetCurrentThreadId();
    PostThreadMessageA(DVar2,Msg,wParam,lParam);
  }
  return;
}

