
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0057c060(void)

{
  int iVar1;
  
  if (DAT_00ca3cd8 != 0) {
    FUN_0057bed0(&DAT_007d82d8);
    if (DAT_00ca3cfc != (HANDLE)0x0) {
      _DAT_00ca3d08 = 1;
      while (DAT_00ca3d04 == 0) {
        FUN_0056da20(1);
      }
      CloseHandle(DAT_00ca3cfc);
      DAT_00ca3cfc = (HANDLE)0x0;
    }
    FUN_00581030(10);
    if (DAT_00ca3ce0 != 0) {
      FUN_0056e1d0(DAT_00ca3ce0);
      DAT_00ca3ce0 = 0;
    }
    if (DAT_00ca3cec != (HWND)0x0) {
      PostMessageW(DAT_00ca3cec,0x10,0,0);
      do {
        if (DAT_00ca3cf8 != 0) break;
        iVar1 = FUN_0057bf50(0);
      } while (0 < iVar1);
    }
    FUN_0056d380(&DAT_00ca3cd4,0,0x38);
    (*DAT_00aba0d4)();
    FUN_0057bed0(&DAT_007d82ac);
  }
  return 0;
}

