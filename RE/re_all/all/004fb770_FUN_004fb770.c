
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x004fb7a2) */

undefined1 FUN_004fb770(void)

{
  char cVar1;
  undefined4 uVar2;
  LPCSTR lpPathName;
  BOOL BVar3;
  byte *pbVar4;
  LPSECURITY_ATTRIBUTES lpSecurityAttributes;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_54 [31];
  char local_35;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_34 [28];
  undefined4 local_18;
  byte *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b20f0;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  ExceptionList = &local_10;
  local_14 = (byte *)FUN_004cbb30();
  do {
    if (*local_14 == 0) {
      ExceptionList = local_10;
      return 1;
    }
    if (*local_14 == 0x5c) {
      pbVar4 = local_14;
      uVar2 = FUN_004cbb30(local_14);
      FUN_004fbb80(uVar2,pbVar4);
      local_8 = 0;
      uVar2 = FUN_004cbb30();
      basic_string<>(uVar2);
      local_8._0_1_ = 1;
      cVar1 = FUN_004fb750(local_54);
      local_35 = '\x01' - (cVar1 != '\0');
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_54);
      if (local_35 != '\0') {
        lpSecurityAttributes = (LPSECURITY_ATTRIBUTES)0x0;
        lpPathName = (LPCSTR)FUN_004cbb30();
        BVar3 = CreateDirectoryA(lpPathName,lpSecurityAttributes);
        if (BVar3 == 0) {
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34);
          ExceptionList = local_10;
          return 0;
        }
      }
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34);
    }
    local_14 = local_14 + ((byte)((*local_14 ^ 0x20) + 0x5f) < 0x3c) + 1;
  } while( true );
}

