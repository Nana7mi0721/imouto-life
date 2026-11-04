
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00514a70(void)

{
  int iVar1;
  undefined4 unaff_EBX;
  undefined1 auStack_8 [8];
  
  if (DAT_00a20bec != (HWND)0x0) {
    SystemParametersInfoW(0x11,1,(PVOID)0x0,2);
    if (DAT_00a49738 == 0) {
      if (DAT_00aba1bc != (code *)0x0) {
        (*DAT_00aba1bc)(DAT_00a20bec,1);
      }
      DAT_00a210ac = 1;
      if (DAT_00a210b0 != 1) {
        do {
          iVar1 = ShowCursor(1);
        } while (iVar1 < 0);
        PostMessageW(DAT_00a20bec,0x20,(WPARAM)DAT_00a20bec,0);
        DAT_00a210b0 = 1;
      }
      if (DAT_00a2d85c != (HHOOK)0x0) {
        UnhookWindowsHookEx(DAT_00a2d85c);
        DAT_00a2d85c = (HHOOK)0x0;
      }
      if (DAT_00a2e8b8 != (HMODULE)0x0) {
        (*DAT_00a2e8bc)(DAT_00a20bec,&DAT_00a2d864,0);
        FreeLibrary(DAT_00a2e8b8);
        DAT_00a2e8bc = (code *)0x0;
        DAT_00a2e8b8 = (HMODULE)0x0;
        _DAT_00a2d864 = 0;
      }
      if (DAT_00a2e46c != 0) {
        DeleteFileW((LPCWSTR)&DAT_00a2d86c);
        DAT_00a2e46c = 0;
      }
      FUN_0050ee50(0);
      if (DAT_00a24d60 != 0) {
        if (DAT_00a24d58 != (HMENU)0x0) {
          FUN_00511b30(0);
          DestroyMenu(DAT_00a24d58);
          DAT_00a24d58 = (HMENU)0x0;
        }
        DAT_00a24d60 = 0;
        DAT_00a24e80 = 0;
        DAT_00a2d284 = 0;
      }
      if (((DAT_00aba154 != 0) && (DAT_00a2d288 != 0)) && (DAT_00a20c40 != 0)) {
        FUN_0050ef90();
        SendMessageW(DAT_00a2d28c,0x10,0,0);
        DAT_00a2d28c = (HWND)0x0;
        DeleteObject(DAT_00a2d290);
        DAT_00a2d290 = (HGDIOBJ)0x0;
        DAT_00a2d288 = 0;
        FUN_00511c90();
      }
      if (DAT_00a20c10 == 1) {
        SetWindowLongW(DAT_00a20bec,-4,DAT_00a20c18);
        DAT_00a21060 = 1;
        FUN_0052ea30();
      }
      else {
        if (DAT_00a21064 == 0) {
          DAT_00a21064 = 1;
          PostMessageW(DAT_00a20bec,0x10,0,0);
        }
        do {
          iVar1 = FUN_005501a0();
          if (iVar1 != 0) break;
        } while (DAT_00a21068 == 0);
        UnregisterClassW(&DAT_00a24b40,DAT_00a20be8);
      }
      FUN_00565a40();
      if (DAT_00a23d24 != 0) {
        FUN_005421c0(&DAT_00a238f0);
        FUN_00515700(DAT_00a23d30,0);
        DAT_00a23d30 = 0;
      }
      FUN_0050ec70();
    }
    else {
      DAT_00a21060 = 1;
      FUN_0052ea30();
    }
    FUN_00580200();
    FUN_0052c5b0();
    FUN_0057fa50();
    (*DAT_00aba16c)(auStack_8,8);
    (*DAT_00aba164)(unaff_EBX);
    if (DAT_00a2e480 != (HGDIOBJ)0x0) {
      DeleteObject(DAT_00a2e480);
      DAT_00a2e480 = (HGDIOBJ)0x0;
    }
  }
  return 0;
}

