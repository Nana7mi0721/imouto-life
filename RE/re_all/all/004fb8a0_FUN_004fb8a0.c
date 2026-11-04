
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x004fb92e) */

undefined4 FUN_004fb8a0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  size_t sVar3;
  LPCSTR lpFileName;
  DWORD dwDesiredAccess;
  DWORD dwShareMode;
  LPSECURITY_ATTRIBUTES lpSecurityAttributes;
  DWORD dwCreationDisposition;
  DWORD dwFlagsAndAttributes;
  HANDLE pvVar4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> abStack_142d4 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> abStack_142b8 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> abStack_1429c [28];
  int iStack_14280;
  undefined4 uStack_1427c;
  char acStack_14278 [512];
  undefined1 auStack_14078 [81936];
  undefined1 local_68 [84];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b211b;
  local_10 = ExceptionList;
  local_14 = 0x4fb8c2;
  ExceptionList = &local_10;
  uVar1 = FUN_004cbb30();
  local_14 = FUN_004f9700(uVar1);
  if (local_14 == 0) {
    uVar1 = 0;
  }
  else {
    do {
      iVar2 = FUN_004fa010(local_14,local_68,acStack_14278,0x200,0,0,0,0);
      if (iVar2 != 0) break;
      sVar3 = _strlen(acStack_14278);
      for (iStack_14280 = 0; iStack_14280 < (int)sVar3; iStack_14280 = iStack_14280 + 1) {
        if (acStack_14278[iStack_14280] == '/') {
          acStack_14278[iStack_14280] = '\\';
        }
      }
      if ((((int)sVar3 < 2) || ((byte)((acStack_14278[sVar3 - 2] ^ 0x20U) + 0x5f) < 0x3c)) ||
         (acStack_14278[sVar3 - 1] != '\\')) {
        iVar2 = FUN_004fac90(local_14);
        if (iVar2 != 0) break;
        uVar1 = FUN_004ec910(abStack_142b8,param_2,acStack_14278);
        local_8 = 1;
        FUN_004fb770(uVar1);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(abStack_142b8);
        uVar1 = FUN_004ec910(abStack_142d4,param_2,acStack_14278);
        local_8 = 2;
        pvVar4 = (HANDLE)0x0;
        dwFlagsAndAttributes = 0;
        dwCreationDisposition = 2;
        lpSecurityAttributes = (LPSECURITY_ATTRIBUTES)0x0;
        dwShareMode = 0;
        dwDesiredAccess = 0xc0000000;
        lpFileName = (LPCSTR)FUN_004cbb30();
        pvVar4 = CreateFileA(lpFileName,dwDesiredAccess,dwShareMode,lpSecurityAttributes,
                             dwCreationDisposition,dwFlagsAndAttributes,pvVar4);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(abStack_142d4);
        while (uStack_1427c = FUN_004fad50(local_14,auStack_14078,0x14000,uVar1), uStack_1427c != 0)
        {
          WriteFile(pvVar4,auStack_14078,uStack_1427c,&uStack_1427c,(LPOVERLAPPED)0x0);
        }
        FlushFileBuffers(pvVar4);
        CloseHandle(pvVar4);
        FUN_004fb420(local_14);
      }
      else {
        uVar1 = FUN_004ec910(abStack_1429c,param_2,acStack_14278);
        local_8 = 0;
        FUN_004fb770(uVar1);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(abStack_1429c);
      }
      iVar2 = FUN_004fa190(local_14);
    } while (iVar2 != -100);
    FUN_004f9740(local_14);
    uVar1 = 1;
  }
  ExceptionList = local_10;
  return uVar1;
}

