
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 __thiscall
FUN_004b62b0(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  void *_Src;
  FILE *_File;
  size_t _Size;
  undefined1 local_36;
  undefined1 local_35;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0658;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  ExceptionList = &local_10;
  basic_string<>(param_1);
  local_8 = 0;
  FUN_004b6440(local_30,param_3,param_4,param_5);
  DAT_00a11790 = 0;
  if (DAT_00a117ec == 0) {
    iVar1 = FUN_004e5650();
    DAT_00a0f830 = _malloc(iVar1 + 1);
    iVar1 = FUN_004e5650();
    _memset(DAT_00a0f830,0,iVar1 + 1);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = FUN_004e5650();
    _Size = DAT_00a1179c;
    _Src = (void *)FUN_004cbb30();
    _memcpy((void *)((int)DAT_00a0f830 + DAT_00a11790),_Src,_Size);
  }
  iVar1 = FUN_004e5650();
  DAT_00a11790 = iVar1 + DAT_00a11790;
  _File = _fopen(param_2,"wb");
  if (_File == (FILE *)0x0) {
    local_35 = 0;
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_30);
  }
  else {
    _fwrite(DAT_00a0f830,DAT_00a11790,1,_File);
    _fclose(_File);
    if (DAT_00a117ec == 0) {
      _free(DAT_00a0f830);
    }
    local_36 = 1;
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_30);
    local_35 = local_36;
  }
  ExceptionList = local_10;
  return local_35;
}

