
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_004010f0(void)

{
  undefined4 uVar1;
  wchar_t local_41c [4];
  WCHAR local_414 [260];
  wchar_t local_20c [258];
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  if (DAT_00a0f7f0 == (HMODULE)0x0) {
    GetModuleFileNameW((HMODULE)0x0,local_414,0x208);
    __wsplitpath(local_414,local_41c,local_20c,(wchar_t *)0x0,(wchar_t *)0x0);
    FID_conflict_swprintf(local_414,0x104,L"%s%s%s",local_41c,local_20c,L"GuruGuruSMF4.dll");
    DAT_00a0f7f0 = LoadLibraryW(local_414);
    if (DAT_00a0f7f0 == (HMODULE)0x0) {
      uVar1 = 1;
    }
    else {
      DAT_00a0f7a0 = GetProcAddress(DAT_00a0f7f0,"GGS4OpenDevice");
      DAT_00a0f7a4 = GetProcAddress(DAT_00a0f7f0,"GGS4CloseDevice");
      DAT_00a0f7a8 = GetProcAddress(DAT_00a0f7f0,"GGS4AddDlsW");
      DAT_00a0f7ac = GetProcAddress(DAT_00a0f7f0,"GGS4AddDlsA");
      DAT_00a0f7b0 = GetProcAddress(DAT_00a0f7f0,"GGS4Play");
      DAT_00a0f7b4 = GetProcAddress(DAT_00a0f7f0,"GGS4Stop");
      DAT_00a0f7b8 = GetProcAddress(DAT_00a0f7f0,"GGS4Pause");
      DAT_00a0f7bc = GetProcAddress(DAT_00a0f7f0,"GGS4Restart");
      DAT_00a0f7c0 = GetProcAddress(DAT_00a0f7f0,"GGS4SetMasterTempo");
      DAT_00a0f7c4 = GetProcAddress(DAT_00a0f7f0,"GGS4SetMasterVolume");
      DAT_00a0f7c8 = GetProcAddress(DAT_00a0f7f0,"GGS4SetMasterPitch");
      DAT_00a0f7cc = GetProcAddress(DAT_00a0f7f0,"GGS4GetPlayerStatus");
      DAT_00a0f7d0 = GetProcAddress(DAT_00a0f7f0,"GGS4AddListFromFileW");
      DAT_00a0f7d4 = GetProcAddress(DAT_00a0f7f0,"GGS4AddListFromFileA");
      DAT_00a0f7d8 = GetProcAddress(DAT_00a0f7f0,"GGS4AddListFromMemory");
      DAT_00a0f7dc = GetProcAddress(DAT_00a0f7f0,"GGS4DeleteListItem");
      DAT_00a0f7e0 = GetProcAddress(DAT_00a0f7f0,"GGS4ClearList");
      DAT_00a0f7e4 = GetProcAddress(DAT_00a0f7f0,"GGS4EnumList");
      DAT_00a0f7e8 = GetProcAddress(DAT_00a0f7f0,"GGS4GetSmfInformation");
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

