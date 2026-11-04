
void FUN_00511110(HWND param_1,int param_2)

{
  HWND hWnd;
  DWORD idAttachTo;
  DWORD idAttach;
  LPDWORD lpdwProcessId;
  undefined4 local_4;
  
  lpdwProcessId = (LPDWORD)0x0;
  hWnd = GetForegroundWindow();
  idAttachTo = GetWindowThreadProcessId(hWnd,lpdwProcessId);
  idAttach = GetWindowThreadProcessId(param_1,(LPDWORD)0x0);
  AttachThreadInput(idAttach,idAttachTo,1);
  SystemParametersInfoW(0x2000,0,&local_4,0);
  SystemParametersInfoW(0x2001,0,(PVOID)0x0,0);
  SetForegroundWindow(param_1);
  SystemParametersInfoW(0x2001,0,&local_4,0);
  AttachThreadInput(idAttach,idAttachTo,0);
  if (param_2 == 1) {
    SetWindowPos(DAT_00a20bec,(HWND)0xffffffff,0,0,0,0,0xb);
  }
  return;
}

