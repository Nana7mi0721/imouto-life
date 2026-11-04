
void __thiscall FUN_00475dd0(undefined1 *param_1,char *param_2,char *param_3,char *param_4)

{
  int iVar1;
  LPCSTR lpPathName;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007aee20;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 == (char *)0x0) {
LAB_00475e16:
    if (param_3 != (char *)0x0) {
      iVar1 = _strcmp(param_3,"");
      if (iVar1 != 0) goto LAB_00475e54;
    }
    if (param_4 == (char *)0x0) goto LAB_00475f96;
    iVar1 = _strcmp(param_4,"");
    if (iVar1 == 0) goto LAB_00475f96;
  }
  else {
    ExceptionList = &local_10;
    iVar1 = _strcmp(param_2,"");
    if (iVar1 == 0) goto LAB_00475e16;
  }
LAB_00475e54:
  if (param_4 == (char *)0x0) {
    if (param_3 == (char *)0x0) {
      if (param_2 != (char *)0x0) {
        basic_string<>();
        local_8 = 4;
        basic_string<>();
        local_8 = CONCAT31(local_8._1_3_,5);
        basic_string<>(param_2);
        local_8 = 0xffffffff;
        FUN_0042bed0();
      }
    }
    else {
      basic_string<>();
      local_8 = 2;
      basic_string<>();
      local_8 = CONCAT31(local_8._1_3_,3);
      basic_string<>(param_2);
      local_8 = 0xffffffff;
      FUN_0042bed0();
    }
  }
  else {
    basic_string<>();
    local_8 = 0;
    basic_string<>();
    local_8 = CONCAT31(local_8._1_3_,1);
    basic_string<>(param_2);
    local_8 = 0xffffffff;
    FUN_0042bed0();
  }
LAB_00475f96:
  FUN_00476080();
  FUN_00472e80();
  if (*(int *)(param_1 + 0x14f8) != 0) {
    InternetCloseHandle();
  }
  if (*(int *)(param_1 + 0x14fc) != 0) {
    InternetCloseHandle();
  }
  lpPathName = (LPCSTR)FUN_004cbb30();
  SetCurrentDirectoryA(lpPathName);
  FUN_004cbb30();
  FUN_004fd29b();
  *(undefined4 *)(param_1 + 0x140c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1408) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1404) = 0xffffffff;
  *param_1 = 0;
  if (*(int *)(param_1 + 0x14a4) != 0) {
    **(undefined4 **)(param_1 + 0x14a4) = 0;
    *(undefined4 *)(param_1 + 0x14a4) = 0;
  }
  ExceptionList = local_10;
  return;
}

