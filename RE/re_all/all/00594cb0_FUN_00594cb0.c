
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

HANDLE FUN_00594cb0(int param_1,undefined4 param_2)

{
  int iVar1;
  DWORD DVar2;
  UINT UVar3;
  HANDLE pvVar4;
  WCHAR local_1800;
  WCHAR local_17fe [1535];
  WCHAR local_c00 [1534];
  undefined4 uStack_4;
  
  uStack_4 = 0x594cba;
  DVar2 = GetTempPathW(0x600,&local_1800);
  if (DVar2 != 0) {
    iVar1 = 0;
    while (local_1800 != L'\0') {
      local_1800 = local_17fe[iVar1];
      iVar1 = iVar1 + 1;
    }
    if (local_17fe[iVar1 + -2] != L'\\') {
      FUN_0056d040(&local_1800,0xc00,&DAT_007d5a78);
    }
    UVar3 = GetTempFileNameW(&local_1800,L"tmp",0,local_c00);
    if (UVar3 != 0) {
      FUN_0052d510(local_c00,&local_1800,0xc00,0);
      DeleteFileW(&local_1800);
      pvVar4 = CreateFileW(&local_1800,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,1,0x80,(HANDLE)0x0);
      if (pvVar4 == (HANDLE)0x0) {
        return (HANDLE)0x0;
      }
      if (param_1 != 0) {
        FUN_0056cf70(param_1,param_2,&local_1800);
      }
      return pvVar4;
    }
  }
  return (HANDLE)0x0;
}

