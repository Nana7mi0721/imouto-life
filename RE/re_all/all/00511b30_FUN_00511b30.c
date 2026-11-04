
undefined4 FUN_00511b30(int param_1)

{
  int iVar1;
  HWND hWnd;
  
  if (((DAT_00a24d60 != 0) && (DAT_00a24d70 = (uint)(param_1 == 0), DAT_00a20bec != (HWND)0x0)) &&
     (iVar1 = FUN_0050efe0(), iVar1 != DAT_00a24d74)) {
    if (iVar1 == 1) {
      if (DAT_00a24d5c == 0) {
        SetMenu(hWnd,DAT_00a24d58);
        DAT_00a24d5c = 1;
      }
    }
    else if (DAT_00a24d5c == 1) {
      SetMenu(hWnd,(HMENU)0x0);
      DAT_00a24d5c = 0;
    }
    if (DAT_00a20c40 != 0) {
      FUN_00511210(0);
    }
    UpdateWindow(DAT_00a20bec);
    DAT_00a24d74 = iVar1;
  }
  return 0;
}

