
undefined4 FUN_00595610(undefined4 *param_1,int param_2)

{
  BOOL BVar1;
  _WIN32_FIND_DATAW local_250;
  
  BVar1 = FindNextFileW((HANDLE)*param_1,&local_250);
  if (BVar1 == 0) {
    return 0xffffffff;
  }
  if (param_2 != 0) {
    FUN_00595540();
  }
  return 0;
}

