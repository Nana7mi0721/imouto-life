
undefined4 FUN_005506d0(void)

{
  int iVar1;
  HWND pHVar2;
  
  if (DAT_00a49730 != 0) {
    DAT_00a21098 = 1;
    FUN_00594c60();
    FUN_0056c090();
    FUN_0057c060();
    FUN_0055f780();
    FUN_00584010();
    FUN_005222f0();
    FUN_00541fc0();
    FUN_00594c10();
    FUN_0057b300();
    FUN_0054f3a0();
    FUN_0055e710();
    FUN_00596830();
    FUN_00514a70();
    FUN_0050e2f0();
    FUN_005e2310();
    DAT_00a49730 = 0;
    iVar1 = DAT_00a49738;
    do {
      if ((iVar1 != 0) || (iVar1 = FUN_005501a0(), iVar1 != 0)) break;
      iVar1 = DAT_00a21068;
    } while (DAT_00a21060 == 0);
    UnregisterClassW(&DAT_00a24b40,DAT_00a20be8);
    while ((DAT_00a49738 == 0 &&
           (pHVar2 = FindWindowW(&DAT_00a24b40,(LPCWSTR)0x0), pHVar2 == DAT_00a20bec))) {
      DestroyWindow(DAT_00a20bec);
      Sleep(100);
    }
    thunk_FUN_005700d0(&DAT_00a23d3c);
    FUN_00571570();
    FUN_0056ddd0();
    FUN_00563a30();
    FUN_0056dc70();
    FUN_0056c9d0();
  }
  return 0;
}

