
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00510df0(uint param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  HDC hDC;
  HWND pHVar2;
  uint uiParam;
  
  uiParam = (uint)((short)param_1 != 0);
  DAT_00a238d0 = 1;
  if (DAT_00a238e4 == 1) {
    DAT_00a21078 = uiParam;
    DAT_00a238d0 = 0;
    return 0;
  }
  if (param_1 >> 0x10 != 0) {
    uiParam = 0;
  }
  if (DAT_00a21078 == uiParam) {
    DAT_00a238d0 = 0;
    return 0;
  }
  DAT_00a21078 = uiParam;
  if (uiParam != 1) {
    if (DAT_00a20c40 == 0) {
      if (DAT_00a4973c == 0) {
        FUN_00567600();
      }
      if ((0x107 < DAT_00a2e8c8) || (DAT_00a37d78 == 0)) {
        ChangeDisplaySettingsA((DEVMODEA *)0x0,0);
        ShowWindow(DAT_00a20bec,6);
      }
      if (((DAT_00a20c40 != 0) || (iVar1 = FUN_005167f0(), iVar1 == 0)) ||
         (iVar1 = thunk_FUN_005d1a00(), iVar1 == 0)) goto LAB_00510f90;
      if (DAT_00a20bf8 != 0) {
        if (DAT_00aba23c != (code *)0x0) {
          (*DAT_00aba23c)(1);
        }
        DAT_00a20bf8 = 0;
      }
      iVar1 = FUN_00516090();
      if ((iVar1 == 0) && (DAT_00a20c10 == 0)) {
        FUN_0056bb10(&DAT_007d4d38);
        if (DAT_00a21064 == 0) {
          DAT_00a21064 = 1;
          PostMessageW(DAT_00a20bec,0x10,0,0);
        }
        DAT_00a238d0 = 0;
        return 0xffffffff;
      }
      FUN_0057be60();
      FUN_0055c4d0(1);
      FUN_0055ac20(1);
      _DAT_00a21088 = 1;
    }
    else {
LAB_00510f90:
      if (DAT_00a24d40 == 0) {
        FUN_0057be60();
        FUN_0055c4d0(1);
        FUN_0055ac20(1);
      }
      FUN_0056b2e0();
    }
    if (DAT_00a2d84c != 0) {
      ClipCursor((RECT *)0x0);
      DAT_00a2d854 = 0;
    }
    if (param_4 == 0) {
      if ((DAT_00a20c10 == 0) || (pHVar2 = DAT_00a20bf0, DAT_00a20bf0 == (HWND)0x0)) {
        pHVar2 = DAT_00a20bec;
      }
      hDC = GetDC(pHVar2);
      if (hDC != (HDC)0x0) {
        FUN_0050e510(hDC);
        pHVar2 = (HWND)FUN_0050eb30();
        ReleaseDC(pHVar2,hDC);
      }
    }
    goto LAB_00511007;
  }
  if ((DAT_00aa700c == 1) && (DAT_00aa7010 == 1)) {
    DAT_00aa701c = 1;
  }
  if (DAT_00a20c40 == 1) {
    FUN_00567640();
  }
  if ((DAT_00a20c40 == 0) && (DAT_00a49730 == 1)) {
    FUN_00522040();
    _DAT_00a21088 = 0;
LAB_00510e8d:
    FUN_0057b9b0();
    FUN_0055c4d0(0);
    FUN_0055ac20(0);
  }
  else if (DAT_00a24d40 == 0) goto LAB_00510e8d;
  FUN_0056b2e0();
LAB_00511007:
  FUN_0054f890();
  if ((DAT_00a23d34 != (code *)0x0) && (param_3 == 0)) {
    (*DAT_00a23d34)(uiParam,DAT_00a23d38);
  }
  if (DAT_00a2d858 == 1) {
    if (DAT_00a2e8c8 < 0x104) {
      SystemParametersInfoW(0x61,uiParam,&param_1,0);
      _DAT_00a2d868 = 1;
      DAT_00a238d0 = 0;
      return 0;
    }
    if (uiParam == 1) {
      DAT_00a2e8b8 = LoadLibraryW((LPCWSTR)&DAT_00a2d86c);
      if ((DAT_00a2e8b8 != (HMODULE)0x0) &&
         (DAT_00a2e8bc = GetProcAddress(DAT_00a2e8b8,"SetMSGHookDll"), DAT_00a2e8bc != (FARPROC)0x0)
         ) {
        (*DAT_00a2e8bc)(DAT_00a20bec,&DAT_00a2d864,1);
        _DAT_00a2d868 = 1;
        DAT_00a238d0 = 0;
        return 0;
      }
    }
    else if ((uiParam == 0) && (DAT_00a2e8b8 != (HMODULE)0x0)) {
      (*DAT_00a2e8bc)(DAT_00a20bec,&DAT_00a2d864,0);
      FreeLibrary(DAT_00a2e8b8);
      DAT_00a2e8bc = (FARPROC)0x0;
      DAT_00a2e8b8 = (HMODULE)0x0;
      _DAT_00a2d864 = 0;
    }
    _DAT_00a2d868 = 1;
  }
  DAT_00a238d0 = 0;
  return 0;
}

