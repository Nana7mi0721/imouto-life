
void __fastcall FUN_004c5fa0(char *param_1)

{
  LPCSTR lpPathName;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_34 [16];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_10;
  
  *(undefined4 *)(param_1 + 0x1794) = *(undefined4 *)(param_1 + 0x1408);
  if (*(int *)(param_1 + 0x140c) == 100000000) {
    local_10 = 0xffffffff;
  }
  else {
    local_10 = *(undefined4 *)(param_1 + 0x140c);
  }
  *(undefined4 *)(param_1 + 0x1798) = local_10;
  *(undefined4 *)(param_1 + 0x179c) = *(undefined4 *)(param_1 + 0x1410);
  *(undefined4 *)(param_1 + 0x17a0) = *(undefined4 *)(param_1 + 0x1418);
  *(undefined4 *)(param_1 + 0x17a4) = *(undefined4 *)(param_1 + 0x141c);
  *(undefined4 *)(param_1 + 0x17a8) = *(undefined4 *)(param_1 + 0x1404);
  if (*param_1 != '\0') {
    uStack_20 = 0x4c605c;
    GetExitCodeThread(*(HANDLE *)(param_1 + 0x1718),(LPDWORD)(param_1 + 0x1720));
    if (*(int *)(param_1 + 0x1720) != 0x103) {
      if (*(int *)(param_1 + 0x1404) == -1) {
        FUN_004cbb30();
        FUN_004cbb30();
        uStack_20 = 0x4c60a8;
        uStack_20 = FUN_004cbb30();
        uStack_24 = 0x4c60b1;
        FUN_00475dd0();
        return;
      }
      if (*(int *)(param_1 + 0x1404) == 1) {
        if (0 < *(int *)(param_1 + 0x144c)) {
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    (abStack_34,
                     (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )(param_1 + 0x1778));
          FUN_0043a2c0(*(undefined4 *)(param_1 + 0x144c));
        }
        *param_1 = '\0';
        if (*(int *)(param_1 + 0x14a4) != 0) {
          **(undefined4 **)(param_1 + 0x14a4) = 0;
          param_1[0x14a4] = '\0';
          param_1[0x14a5] = '\0';
          param_1[0x14a6] = '\0';
          param_1[0x14a7] = '\0';
        }
      }
      if (*(int *)(param_1 + 0x1718) != 0) {
        CloseHandle(*(HANDLE *)(param_1 + 0x1718));
      }
    }
    lpPathName = (LPCSTR)FUN_004cbb30();
    SetCurrentDirectoryA(lpPathName);
  }
  return;
}

