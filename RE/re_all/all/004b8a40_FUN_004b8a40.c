
long FUN_004b8a40(LPCSTR param_1,DWORD param_2,DWORD param_3,DWORD param_4,DWORD param_5,
                 LPSECURITY_ATTRIBUTES param_6,HANDLE param_7)

{
  HANDLE pvVar1;
  long lVar2;
  
  pvVar1 = CreateFileA(param_1,param_2,param_3,param_6,param_4,param_5,param_7);
  if (pvVar1 == (HANDLE)0xffffffff) {
    lVar2 = ATL::AtlHresultFromLastError();
  }
  else {
    FUN_004717a0(pvVar1);
    lVar2 = 0;
  }
  return lVar2;
}

