
void FUN_004176d0(HINSTANCE param_1)

{
  int local_20;
  tagRECT local_14;
  
  DAT_00a0f804 = (HWND)FUN_0050e7c0();
  DAT_00a0f80c = CreateDialogParamA(param_1,(LPCSTR)0x67,DAT_00a0f804,FUN_004175e0,0);
  FUN_0050eb20(DAT_00a0f80c);
  GetWindowRect(DAT_00a0f804,&local_14);
  local_20 = local_14.right + 2;
  if (DAT_00a0f83c + -200 <= local_20) {
    local_20 = DAT_00a0f83c + -200;
  }
  SetWindowPos(DAT_00a0f80c,(HWND)0x0,local_20,local_14.top,0,0,5);
  ShowWindow(DAT_00a0f80c,5);
  SetFocus(DAT_00a0f804);
  FUN_004cb9c0();
  DAT_00a11798 = 1;
  DAT_00a0f82c = 1;
  return;
}

