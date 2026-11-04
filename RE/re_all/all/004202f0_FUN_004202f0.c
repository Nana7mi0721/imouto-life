
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_004202f0(undefined4 param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  char *pcVar1;
  size_t sVar2;
  wchar_t *_Dest;
  size_t sVar3;
  uint uVar4;
  undefined1 local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007ac1c7;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  uVar4 = 0;
  local_8 = 1;
  ExceptionList = &local_10;
  _setlocale(0,"");
  sVar3 = 0;
  pcVar1 = (char *)FUN_004cbb30();
  sVar2 = _mbstowcs((wchar_t *)0x0,pcVar1,sVar3);
  _Dest = operator_new(sVar2 << 1);
  sVar3 = sVar2;
  pcVar1 = (char *)FUN_004cbb30();
  _mbstowcs(_Dest,pcVar1,sVar3);
  basic_string<>(_Dest,sVar2);
  local_8._0_1_ = 2;
  _free(_Dest);
  FID_conflict_operator__(local_30,L'\0');
  basic_string<>(local_30);
  local_8._0_1_ = 1;
  ~basic_string<>(uVar4 | 1);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  ExceptionList = local_10;
  return param_1;
}

