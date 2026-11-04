
undefined4 FUN_005a6f00(void)

{
  HANDLE hHeap;
  DWORD dwFlags;
  LPVOID lpMem;
  
  FUN_00584e10();
  FUN_0059cd60();
  FUN_0059f390();
  if (DAT_00aaf0d0 != 0) {
    DAT_00aaf0d0 = 0;
    ChangeDisplaySettingsA((DEVMODEA *)0x0,0);
  }
  if (DAT_00ddb5c8 != 0) {
    FUN_005d3370(DAT_00ddb5c8);
    DAT_00ddb5c8 = 0;
  }
  if (DAT_00ddb5c4 != 0) {
    FUN_005d3370(DAT_00ddb5c4);
    DAT_00ddb5c4 = 0;
  }
  if (DAT_00ddb5c0 != 0) {
    FUN_005d3370(DAT_00ddb5c0);
    DAT_00ddb5c0 = 0;
  }
  if (DAT_00ddb5b4 != 0) {
    FUN_005d3370(DAT_00ddb5b4);
    DAT_00ddb5b4 = 0;
  }
  if (DAT_00ddb368 != 0) {
    FUN_005d3370(DAT_00ddb368);
    DAT_00ddb368 = 0;
  }
  FUN_005d3630();
  DAT_00e79688 = 0;
  FUN_005d33e0();
  FUN_005d19e0();
  FUN_005d33b0();
  if (DAT_00a37ef8 != (LPVOID)0x0) {
    dwFlags = 0;
    lpMem = DAT_00a37ef8;
    hHeap = GetProcessHeap();
    HeapFree(hHeap,dwFlags,lpMem);
    DAT_00a37ef8 = (LPVOID)0x0;
  }
  return 0;
}

