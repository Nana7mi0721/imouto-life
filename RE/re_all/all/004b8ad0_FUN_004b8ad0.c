
long __thiscall FUN_004b8ad0(undefined4 *param_1,LPCVOID param_2,DWORD param_3,DWORD *param_4)

{
  long lVar1;
  DWORD local_c;
  BOOL local_8;
  
  if (param_4 == (LPDWORD)0x0) {
    param_4 = &local_c;
  }
  local_8 = WriteFile((HANDLE)*param_1,param_2,param_3,param_4,(LPOVERLAPPED)0x0);
  if (local_8 == 0) {
    lVar1 = ATL::AtlHresultFromLastError();
  }
  else {
    lVar1 = 0;
  }
  return lVar1;
}

