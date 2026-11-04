
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 __fastcall FUN_00465a00(int param_1)

{
  char cVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;
  uint *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  LPCSTR lpFile;
  char *_Format;
  char *apcStack_310 [5];
  undefined4 uStack_2fc;
  char *pcStack_2f4;
  undefined4 uStack_2f0;
  undefined4 uStack_2ec;
  undefined4 uStack_2e8;
  undefined4 uStack_2e4;
  undefined4 uStack_2e0;
  undefined4 uStack_2dc;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_2d8;
  undefined4 uStack_2d4;
  LPCSTR lpParameters;
  LPCSTR lpDirectory;
  INT nShowCmd;
  int local_298;
  char local_258 [256];
  char local_158 [260];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_54 [28];
  undefined *local_38;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_34 [28];
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae3e8;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  uStack_2d4 = *(undefined4 *)(param_1 + 0x18);
  pbStack_2d8 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                 (param_1 + 0x14);
  uStack_2dc = 0;
  uStack_2e0 = 0x465a6b;
  ExceptionList = &local_10;
  pbVar2 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
           FUN_004cc4c0();
  uStack_2fc = 0x465a7c;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&pcStack_2f4,pbVar2)
  ;
  uStack_2fc = 0x465a8b;
  FUN_00424670();
  local_8 = 0;
  pbStack_2d8 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
  uStack_2dc = 0;
  uStack_2e0 = 0;
  uStack_2e4 = 0;
  uStack_2e8 = 1;
  uStack_2ec = *(undefined4 *)(param_1 + 0x10);
  uStack_2f0 = *(undefined4 *)(param_1 + 0x18);
  pcStack_2f4 = *(char **)(param_1 + 0x14);
  uStack_2fc = 0x465ae4;
  pbVar2 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
           FUN_004cc4c0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)apcStack_310,pbVar2)
  ;
  FUN_00424670(&uStack_2d4);
  pbStack_2d8 = local_54;
  uStack_2dc = 0x465b1f;
  FUN_004293c0();
  local_8._0_1_ = 1;
  puVar3 = (uint *)FUN_004ce990();
  if ((*puVar3 & 2) == 0) {
    local_298 = 0;
  }
  else {
    local_298 = param_1 + 0x890;
  }
  local_14 = local_298;
  puVar4 = (undefined4 *)FUN_004ce990();
  local_38 = (undefined *)*puVar4;
  if ((1599999 < (int)local_38) && ((int)local_38 < 1700000)) {
    local_38 = &DAT_00e4e1c0 + (int)local_38 % 100 + *(int *)(param_1 + 0x18) * 100;
  }
  piVar5 = (int *)FUN_004ce990();
  if (*piVar5 == -1) {
    if ((14999 < *DAT_00a16628) && (*DAT_00a16628 < 0x3c8c)) {
      nShowCmd = 1;
      lpDirectory = (LPCSTR)0x0;
      lpParameters = "";
      lpFile = (LPCSTR)FUN_004cbb30();
      uStack_2d4 = 0x465c0d;
      ShellExecuteA((HWND)0x0,(LPCSTR)0x0,lpFile,lpParameters,lpDirectory,nShowCmd);
    }
  }
  else {
    FUN_004ce990();
    FUN_004cbb30();
    FUN_004cbb30();
    cVar1 = FUN_004b6f20();
    if (cVar1 == '\0') {
      pbStack_2d8 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    &DAT_007cfeb0;
      uStack_2dc = 0x465c72;
      basic_string<>();
      pbStack_2d8 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x465c7d;
      _Format = (char *)FUN_00401c50();
      _sprintf(local_158,_Format);
      FUN_004cc4c0();
      FUN_004cbb30();
      _sprintf(local_258,"%s");
      pbStack_2d8 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    &DAT_007cfef7;
      uStack_2dc = 0x465ce3;
      basic_string<>();
      local_8._0_1_ = 2;
      pcStack_2f4 = local_258;
      basic_string<>();
      local_8._0_1_ = 3;
      apcStack_310[0] = local_158;
      basic_string<>();
      local_8._0_1_ = 1;
      apcStack_310[0] = (char *)0x465d4c;
      FUN_0042bed0();
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_54);
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34);
  ExceptionList = local_10;
  return 1;
}

