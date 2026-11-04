
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_004209c0(char *param_1)

{
  bool bVar1;
  char *_Format;
  LPCSTR lpCaption;
  UINT uType;
  char local_2b0 [516];
  undefined4 local_ac;
  int local_a8 [38];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ac243;
  local_10 = ExceptionList;
  local_ac = DAT_0084b484;
  ExceptionList = &local_10;
  FUN_004d0de0();
  local_8 = 0;
  bVar1 = std::ios_base::fail((ios_base *)((int)local_a8 + *(int *)(local_a8[0] + 4)));
  if (!bVar1) {
    _strlen(param_1);
    FUN_004cbc60();
    FUN_004d0f50();
    local_8 = 0xffffffff;
    std::strstream::_vbase_destructor_((strstream *)local_a8);
  }
  else {
    basic_string<>(&DAT_007cc5f0);
    _Format = (char *)FUN_00401c50();
    _sprintf(local_2b0,_Format);
    uType = 0;
    basic_string<>(&DAT_007cc630);
    lpCaption = (LPCSTR)FUN_00401c50();
    MessageBoxA((HWND)0x0,local_2b0,lpCaption,uType);
    FUN_004d0f50();
    local_8 = 0xffffffff;
    std::strstream::_vbase_destructor_((strstream *)local_a8);
  }
  ExceptionList = local_10;
  return !bVar1;
}

