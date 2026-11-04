
undefined4 FUN_00567a00(void)

{
  undefined4 uVar1;
  HANDLE hHeap;
  DWORD dwFlags;
  LPVOID lpMem;
  
  if (DAT_00aaf0dc == 1) {
    FUN_005b48d0();
  }
  else if (DAT_00aaf0dc == 2) {
    uVar1 = FUN_005cfb10();
    goto LAB_00567a20;
  }
  uVar1 = 0;
LAB_00567a20:
  if (DAT_00a37ef8 != (LPVOID)0x0) {
    dwFlags = 0;
    lpMem = DAT_00a37ef8;
    hHeap = GetProcessHeap();
    HeapFree(hHeap,dwFlags,lpMem);
    DAT_00a37ef8 = (LPVOID)0x0;
  }
  return uVar1;
}

