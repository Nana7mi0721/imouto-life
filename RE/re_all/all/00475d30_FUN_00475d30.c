
void __fastcall FUN_00475d30(int param_1)

{
  LPCSTR lpPathName;
  
  GetExitCodeThread(*(HANDLE *)(param_1 + 0x1718),(LPDWORD)(param_1 + 0x1720));
  if (*(int *)(param_1 + 0x1720) == 0x103) {
    if (*(int *)(param_1 + 0x1718) != 0) {
      CloseHandle(*(HANDLE *)(param_1 + 0x1718));
      Sleep(200);
    }
    FUN_00475dd0(0,0,0);
    Sleep(200);
    *(undefined4 *)(param_1 + 0x17a8) = 0xffffffff;
  }
  lpPathName = (LPCSTR)FUN_004cbb30();
  SetCurrentDirectoryA(lpPathName);
  return;
}

