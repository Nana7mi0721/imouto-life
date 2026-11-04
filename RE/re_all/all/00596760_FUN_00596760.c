
undefined4 FUN_00596760(int param_1,int param_2,int param_3)

{
  HDC hdc;
  code *lpProc;
  tagLOGFONTW local_5c;
  
  hdc = GetDC((HWND)0x0);
  FUN_0056d380(&local_5c,0,0x3c);
  if ((param_2 == 0) || (param_3 < 0)) {
    local_5c.lfCharSet = '\x01';
  }
  else {
    local_5c.lfCharSet = (&DAT_0085e584)[param_3 * 4];
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    local_5c.lfFaceName[0] = L'\0';
  }
  else {
    FUN_0056cfa0(local_5c.lfFaceName,0x40,*(int *)(param_1 + 0x14),0x1f);
  }
  local_5c.lfPitchAndFamily = '\0';
  lpProc = FUN_005966b0;
  if (param_2 == 0) {
    lpProc = FUN_005965e0;
  }
  EnumFontFamiliesExW(hdc,&local_5c,lpProc,param_1,0);
  ReleaseDC((HWND)0x0,hdc);
  return 0;
}

