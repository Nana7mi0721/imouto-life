
undefined4 FUN_005955c0(undefined4 *param_1,LPCWSTR param_2,int param_3)

{
  HANDLE pvVar1;
  _WIN32_FIND_DATAW local_250;
  
  pvVar1 = FindFirstFileW(param_2,&local_250);
  *param_1 = pvVar1;
  if (pvVar1 == (HANDLE)0xffffffff) {
    return 0xffffffff;
  }
  if (param_3 != 0) {
    FUN_00595540();
  }
  return 0;
}

