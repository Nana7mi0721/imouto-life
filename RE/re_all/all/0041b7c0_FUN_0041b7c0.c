
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0041b7c0(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  BOOL BVar1;
  uint uVar2;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_388 [28];
  HANDLE local_36c;
  CHAR local_368 [512];
  _WIN32_FIND_DATAA local_168;
  undefined4 local_24;
  undefined1 local_20 [16];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007abdf8;
  local_10 = ExceptionList;
  local_24 = DAT_0084b484;
  uVar2 = 0;
  ExceptionList = &local_10;
  FUN_004cc150(0);
  local_8 = 1;
  GetCurrentDirectoryA(0x200,local_368);
  SetCurrentDirectoryA(param_2);
  local_36c = FindFirstFileA(param_3,&local_168);
  if (local_36c != (HANDLE)0xffffffff) {
    do {
      basic_string<>(local_168.cFileName);
      local_8._0_1_ = 2;
      FUN_004cc500(local_388);
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_388);
      BVar1 = FindNextFileA(local_36c,&local_168);
    } while (BVar1 != 0);
    FindClose(local_36c);
  }
  SetCurrentDirectoryA(local_368);
  FUN_004cc180(local_20);
  local_8 = local_8 & 0xffffff00;
  FUN_004cc250(uVar2 | 1);
  ExceptionList = local_10;
  return param_1;
}

