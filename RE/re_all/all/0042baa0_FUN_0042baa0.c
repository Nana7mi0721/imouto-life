
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_0042baa0(undefined4 param_1,int param_2)

{
  bool bVar1;
  char *_Format;
  LPCSTR lpCaption;
  LPCSTR lpText;
  UINT uType;
  int local_76e8 [38];
  char local_7650 [30240];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007acd97;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  ExceptionList = &local_10;
  if (param_2 == -1) {
    ExceptionList = &local_10;
    FUN_0042b1d0();
  }
  FUN_004cbb30();
  FUN_004cbb30();
  basic_string<>(
                "Start=%d\nSoftModeFlag=%d\nWindowModeFlag=%d\nSEandBGM=%d\nFrameSkip=%d\nProxy=%s\nProxyPort=%s\nScreenShotFlag=%d\nF12_Reset=%d\nDisplay_Number=%d\nOld_DirectX_Use=%d\n"
                );
  _Format = (char *)FUN_00401c50();
  _sprintf(local_7650,_Format);
  FUN_0041b8f0();
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_30,"Game.ini");
  FUN_004cbb30();
  FUN_004d0de0();
  local_8._0_1_ = 1;
  bVar1 = std::ios_base::fail((ios_base *)((int)local_76e8 + *(int *)(local_76e8[0] + 4)));
  if (!bVar1) {
    _strlen(local_7650);
    FUN_004cbc60();
    FUN_004d0f50();
    local_8 = (uint)local_8._1_3_ << 8;
    std::strstream::_vbase_destructor_((strstream *)local_76e8);
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_30
              );
  }
  else {
    uType = 0;
    basic_string<>();
    lpCaption = (LPCSTR)FUN_00401c50();
    basic_string<>();
    lpText = (LPCSTR)FUN_00401c50();
    MessageBoxA((HWND)0x0,lpText,lpCaption,uType);
    FUN_004d0f50();
    local_8 = (uint)local_8._1_3_ << 8;
    std::strstream::_vbase_destructor_((strstream *)local_76e8);
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_30
              );
  }
  ExceptionList = local_10;
  return !bVar1;
}

