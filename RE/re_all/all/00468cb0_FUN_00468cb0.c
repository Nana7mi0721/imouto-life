
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_00468cb0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  LPCSTR pCVar4;
  LPCSTR pCVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar6;
  char *pcVar7;
  long lVar8;
  uint uVar9;
  int *piVar10;
  undefined4 uVar11;
  undefined1 auStack_490 [16];
  undefined4 uStack_480;
  undefined1 *puStack_478;
  undefined1 auStack_474 [16];
  undefined4 uStack_464;
  undefined4 uStack_460;
  undefined *puStack_45c;
  undefined4 uStack_458;
  DWORD fl;
  PVOID pdv;
  INT nShowCmd;
  LPSECURITY_ATTRIBUTES lpSecurityAttributes;
  BOOL bFailIfExists;
  int local_400;
  int local_3fc;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_35c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_340 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_324 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_308 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2ec [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2d0 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2b4 [28];
  undefined1 *local_298;
  undefined1 *local_294;
  undefined1 *local_290;
  undefined1 *local_28c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_288 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_26c [28];
  undefined1 *local_250;
  undefined1 *local_24c;
  uint local_248;
  int local_244;
  undefined1 local_240 [112];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1d0 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1b4 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_198 [28];
  int local_17c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_178 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_15c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_140 [28];
  int local_124;
  CHAR local_120 [268];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae5c8;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  if ((14999 < *DAT_00a16628) && (*DAT_00a16628 < 0x3c8c)) {
    ExceptionList = &local_10;
    puVar2 = (undefined4 *)FUN_004ce990();
    switch(*puVar2) {
    case 0xe:
      if (DAT_00a0f82c != 0) {
        FUN_00417950();
      }
      FUN_005157a0();
      FUN_00550c60();
      FUN_00536610();
      FUN_0052ec70();
      if (*DAT_00a16680 == '\x01') {
        FUN_00401080();
      }
      FUN_0042baa0();
      pCVar4 = (LPCSTR)FUN_004cbb30();
      SetCurrentDirectoryA(pCVar4);
      local_124 = 0;
      while (iVar3 = FUN_004cc430(), local_124 < iVar3) {
        pdv = (PVOID)0x0;
        fl = 0x10;
        FUN_004cc4c0();
        pCVar4 = (LPCSTR)FUN_004cbb30();
        RemoveFontResourceExA(pCVar4,fl,pdv);
        local_124 = local_124 + 1;
      }
      FUN_004b9e50();
      GetModuleFileNameA((HMODULE)0x0,local_120,0x104);
      nShowCmd = 1;
      pCVar5 = "";
      pCVar4 = (LPCSTR)FUN_004cbb30();
      uStack_458 = 0x468e43;
      ShellExecuteA((HWND)0x0,(LPCSTR)0x0,local_120,pCVar4,pCVar5,nShowCmd);
                    /* WARNING: Subroutine does not return */
      _exit(0);
    default:
      puStack_45c = &DAT_007d00e2;
      uStack_460 = 0x4696da;
      basic_string<>();
      local_8 = 0x14;
      puStack_478 = &DAT_007d00e4;
      basic_string<>();
      puStack_478 = (undefined1 *)0x469713;
      puStack_478 = (undefined1 *)FUN_00401c50();
      basic_string<>();
      local_8 = CONCAT31(local_8._1_3_,0x15);
      basic_string<>(&DAT_007d0118);
      uVar11 = FUN_00401c50();
      basic_string<>(uVar11);
      local_8 = 0xffffffff;
      FUN_0042bed0();
      break;
    case 0x10:
      lpSecurityAttributes = (LPSECURITY_ATTRIBUTES)0x0;
      FUN_004cc4c0();
      pCVar4 = (LPCSTR)FUN_004cbb30();
      CreateDirectoryA(pCVar4,lpSecurityAttributes);
      break;
    case 0x11:
      uStack_458 = *(undefined4 *)(param_1 + 0x18);
      puStack_45c = *(undefined **)(param_1 + 0x14);
      uStack_460 = 0;
      uStack_464 = 0x468eb3;
      pbVar6 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               FUN_004cc4c0();
      local_24c = (undefined1 *)&puStack_478;
      uStack_480 = 0x468ec4;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&puStack_478,
                 pbVar6);
      uStack_480 = 0x468ed6;
      FUN_00424670();
      local_8 = 0;
      FUN_004cbb30();
      uStack_458 = 0;
      puStack_45c = (undefined *)0x468f0d;
      FUN_00528cc0();
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_140);
      break;
    case 0x12:
      basic_string<>();
      local_8 = 1;
      basic_string<>();
      local_8._0_1_ = 2;
      uStack_458 = *(undefined4 *)(param_1 + 0x18);
      puStack_45c = *(undefined **)(param_1 + 0x14);
      uStack_460 = 0;
      uStack_464 = 0x468f86;
      pbVar6 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               FUN_004cc4c0();
      local_250 = (undefined1 *)&puStack_478;
      uStack_480 = 0x468f97;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&puStack_478,
                 pbVar6);
      uStack_480 = 0x468fa9;
      FUN_00424670();
      local_8._0_1_ = 3;
      local_17c = FUN_004cbbc0();
      if (local_17c == -1) {
        local_28c = (undefined1 *)&uStack_458;
        puStack_45c = &DAT_007d0087;
        uStack_460 = 0x4690cd;
        basic_string<>();
        local_8._0_1_ = 6;
        local_290 = auStack_474;
        puStack_478 = auStack_474;
        FUN_00438b60();
        local_8._0_1_ = 7;
        local_294 = auStack_490;
        basic_string<>("[Copy Error] Not found \">>\"");
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0042bed0();
      }
      else {
        FUN_004cbc20();
        local_8._0_1_ = 4;
        FUN_004cb840();
        local_8._0_1_ = 3;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_26c);
        FUN_004cbc20();
        local_8._0_1_ = 5;
        FUN_004cb840();
        local_8 = CONCAT31(local_8._1_3_,3);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_288);
        FUN_004cbb30();
        FUN_004fd29b();
        bFailIfExists = 0;
        pCVar4 = (LPCSTR)FUN_004cbb30();
        pCVar5 = (LPCSTR)FUN_004cbb30();
        CopyFileA(pCVar5,pCVar4,bFailIfExists);
      }
      local_8._0_1_ = 2;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_15c);
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_198);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_178);
      break;
    case 0x13:
      break;
    case 0x14:
      basic_string<>();
      local_8 = 8;
      _eh_vector_constructor_iterator_
                (local_240,0x1c,4,basic_string<>,
                 std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>);
      local_8._0_1_ = 9;
      uStack_458 = *(undefined4 *)(param_1 + 0x18);
      puStack_45c = *(undefined **)(param_1 + 0x14);
      uStack_460 = 0;
      uStack_464 = 0x4691dc;
      pbVar6 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               FUN_004cc4c0();
      local_298 = (undefined1 *)&puStack_478;
      uStack_480 = 0x4691ed;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&puStack_478,
                 pbVar6);
      uStack_480 = 0x4691ff;
      FUN_00424670();
      local_8._0_1_ = 10;
      cVar1 = FUN_004ec750();
      if (cVar1 == '\0') {
        local_244 = FUN_004cbbc0();
        if (local_244 == -1) {
          puStack_45c = &DAT_007d00be;
          uStack_460 = 0x46961f;
          basic_string<>();
          local_8._0_1_ = 0x12;
          puStack_478 = auStack_474;
          FUN_00438b60();
          local_8._0_1_ = 0x13;
          basic_string<>("[MapSetting Error] Not found \"=>\"");
          local_8._0_1_ = 10;
          FUN_0042bed0();
        }
        else {
          FUN_004cbc20();
          local_8._0_1_ = 0xb;
          FUN_004cb840();
          local_8._0_1_ = 10;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2b4);
          FUN_004cbc20();
          local_8._0_1_ = 0xc;
          FUN_004cb840();
          local_8._0_1_ = 10;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2d0);
          FUN_004cbbc0();
          FUN_004cbc20();
          local_8._0_1_ = 0xd;
          FUN_004cb840();
          local_8._0_1_ = 10;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2ec);
          FUN_004cbbc0();
          FUN_004cbc20();
          local_8._0_1_ = 0xe;
          FUN_004cb840();
          local_8._0_1_ = 10;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_308);
          FUN_004cbbc0();
          FUN_004cbc20();
          local_8._0_1_ = 0xf;
          FUN_004cb840();
          local_8._0_1_ = 10;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_324);
          FUN_004cbbc0();
          FUN_004cbc20();
          local_8._0_1_ = 0x10;
          FUN_004cb840();
          local_8._0_1_ = 10;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_340);
          FUN_004cbc20();
          local_8._0_1_ = 0x11;
          FUN_004cb840();
          local_8._0_1_ = 10;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_35c);
          pcVar7 = (char *)FUN_004cbb30();
          lVar8 = _atol(pcVar7);
          local_248 = lVar8 + 1;
          if (1 < (int)local_248) {
            uVar9 = FUN_004cc430();
            if (uVar9 <= local_248) {
              FUN_004cc400();
              FUN_004ce970();
            }
            FUN_004cc4c0();
            FUN_004cb840();
            pcVar7 = (char *)FUN_004cbb30();
            lVar8 = _atol(pcVar7);
            if (lVar8 < 10000) {
              pcVar7 = (char *)FUN_004cbb30();
              local_3fc = _atol(pcVar7);
            }
            else {
              local_3fc = 9999;
            }
            pcVar7 = (char *)FUN_004cbb30();
            lVar8 = _atol(pcVar7);
            if (lVar8 < 10000) {
              pcVar7 = (char *)FUN_004cbb30();
              local_400 = _atol(pcVar7);
            }
            else {
              local_400 = 9999;
            }
            piVar10 = (int *)FUN_004ce990();
            *piVar10 = local_3fc * 10000 + local_400;
            DAT_00a140cc = 1;
          }
        }
      }
      else {
        FUN_004cc250();
        FUN_004ce950();
      }
      local_8._0_1_ = 9;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1b4);
      local_8 = CONCAT31(local_8._1_3_,8);
      _eh_vector_destructor_iterator_
                (local_240,0x1c,4,
                 std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1d0);
    }
  }
  ExceptionList = local_10;
  return 1;
}

