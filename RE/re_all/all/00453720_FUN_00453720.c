
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __fastcall FUN_00453720(int param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint *puVar7;
  int iVar8;
  undefined4 uVar9;
  char *pcVar10;
  uint uVar11;
  undefined1 auStack_638 [16];
  undefined4 uStack_628;
  undefined1 *puStack_620;
  undefined1 auStack_61c [4];
  undefined4 uStack_618;
  undefined *puStack_614;
  undefined4 uStack_60c;
  undefined4 uStack_608;
  undefined4 uStack_600;
  uint local_54c;
  char local_4b8;
  int local_480;
  int local_47c;
  int local_478;
  undefined4 local_474;
  undefined4 local_470;
  uint local_454;
  uint local_450;
  uint local_44c;
  int local_430;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_40c [28];
  undefined1 *local_3f0;
  undefined1 *local_3ec;
  undefined1 *local_3e8;
  undefined1 *local_3e4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3e0 [28];
  undefined1 *local_3c4;
  undefined1 *local_3c0;
  undefined1 *local_3bc;
  undefined1 *local_3b8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3b4 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_398 [31];
  undefined1 local_379;
  undefined1 *local_378;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_374 [28];
  undefined1 *local_358;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_354 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_338 [30];
  char local_31a;
  undefined1 local_319;
  undefined1 *local_318;
  undefined1 *local_314;
  undefined1 *local_310;
  undefined1 *local_30c;
  undefined1 *local_308;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_304 [28];
  int local_2e8;
  int local_2e4;
  double local_2e0;
  int local_2d8;
  uint local_2d4;
  char local_2d0 [200];
  char local_208 [200];
  char local_140 [200];
  int local_78;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_74 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_58 [28];
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined1 local_2a;
  undefined1 local_29;
  uint local_28;
  int local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007adb1a;
  local_10 = ExceptionList;
  local_3c = DAT_0084b484;
  bVar1 = false;
  ExceptionList = &local_10;
  iVar3 = FUN_004ce080();
  if (iVar3 == 0) {
LAB_004543b3:
    local_14 = 0;
    puVar7 = (uint *)FUN_004ce990();
    if ((*puVar7 & 0x10000) != 0) {
      piVar4 = (int *)FUN_004ce990();
      if (*piVar4 < 0) {
        local_47c = 0;
      }
      else {
        piVar4 = (int *)FUN_004ce990();
        local_47c = *piVar4;
      }
      local_14 = local_47c;
    }
    local_1c = 0;
    do {
      if (local_14 < local_1c) {
        ExceptionList = local_10;
        return 1;
      }
      piVar4 = (int *)FUN_004ce990();
      local_34 = *piVar4 + local_1c;
      piVar4 = (int *)FUN_004ce990();
      if (*piVar4 == 1100000000) {
        FUN_004ce990();
        iVar3 = FUN_00487080();
        FUN_004ce990();
        iVar8 = FUN_00487080();
        FUN_004ce990();
        local_34 = FUN_00487080();
        local_34 = iVar3 * 1000000 + 1100000000 + iVar8 * 100 + local_34;
      }
      puVar7 = (uint *)FUN_004ce990();
      if ((*puVar7 & 0x10) != 0) {
        local_34 = FUN_00487080();
      }
      cVar2 = FUN_00438d40();
      if (cVar2 == '\0') {
        if (local_14 == 0) {
          basic_string<>();
          local_8 = 0;
          basic_string<>();
          local_8 = CONCAT31(local_8._1_3_,1);
          puVar7 = (uint *)FUN_004ce990();
          if ((*puVar7 & 0x10) == 0) {
            local_480 = local_34;
          }
          else {
            FUN_004ce990();
            local_480 = FUN_00487080();
          }
          local_34 = local_480;
          puVar7 = (uint *)FUN_004ce990();
          if ((*puVar7 & 0xf00) == 0x100) {
            FUN_00487160();
            local_8._0_1_ = 2;
            FUN_004cb840();
            local_8 = CONCAT31(local_8._1_3_,1);
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_304);
          }
          piVar4 = (int *)FUN_004ce990();
          local_38 = *piVar4;
          piVar4 = (int *)FUN_004ce990();
          local_78 = *piVar4;
          puVar7 = (uint *)FUN_004ce990();
          if ((*puVar7 & 0x20) != 0) {
            local_38 = FUN_00487080();
          }
          puVar7 = (uint *)FUN_004ce990();
          if ((*puVar7 & 0x40) != 0) {
            local_78 = FUN_00487080();
          }
          if ((local_38 != 0) &&
             ((cVar2 = FUN_00438d40(), cVar2 != '\0' ||
              (puVar7 = (uint *)FUN_004ce990(), (*puVar7 & 4) != 0)))) {
            local_308 = (undefined1 *)&uStack_600;
            uStack_608 = (undefined *)0x4546ff;
            FUN_00438b60();
            local_8._0_1_ = 3;
            local_310 = auStack_61c;
            puStack_620 = &DAT_007cee08;
            basic_string<>();
            puStack_620 = (undefined1 *)0x454738;
            puStack_620 = (undefined1 *)FUN_00401c50();
            local_30c = auStack_61c;
            basic_string<>();
            local_8._0_1_ = 4;
            local_318 = auStack_638;
            basic_string<>(&DAT_007cee48);
            uVar9 = FUN_00401c50();
            local_314 = auStack_638;
            basic_string<>(uVar9);
            local_8._0_1_ = 1;
            FUN_0042bed0();
            local_319 = 1;
            local_8 = (uint)local_8._1_3_ << 8;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_58);
            local_8 = 0xffffffff;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_74);
            ExceptionList = local_10;
            return local_319;
          }
          puVar7 = (uint *)FUN_004ce990();
          if (((int)(*puVar7 & 0xf000) >> 0xc == 0) && (local_78 != 0)) {
            FUN_00487160();
            local_8 = CONCAT31(local_8._1_3_,5);
            bVar1 = true;
            cVar2 = operator!=<>();
            if (cVar2 != '\0') {
              local_4b8 = '\x01';
              goto LAB_0045488b;
            }
          }
          local_4b8 = '\0';
LAB_0045488b:
          local_31a = local_4b8;
          local_8 = 1;
          if (bVar1) {
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_338);
          }
          if (local_31a != '\0') {
            FUN_00487160();
            local_8._0_1_ = 6;
            FUN_004cb880();
            local_8 = CONCAT31(local_8._1_3_,1);
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_354);
          }
          uStack_600 = *(undefined4 *)(param_1 + 0x18);
          local_358 = (undefined1 *)&puStack_620;
          uStack_628 = 0x45494e;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&puStack_620
                     ,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)local_58);
          uStack_628 = 0x454960;
          FUN_00424670();
          local_8._0_1_ = 7;
          FUN_004cb840();
          local_8._0_1_ = 1;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_374);
          FUN_004cb880();
          local_378 = (undefined1 *)&uStack_600;
          uStack_608 = (undefined *)0x4549b7;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_600,
                     (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )local_74);
          uStack_608 = (undefined *)0x4549cc;
          FUN_00486bf0();
          local_379 = 1;
          local_8 = (uint)local_8._1_3_ << 8;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_58);
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_74);
          ExceptionList = local_10;
          return local_379;
        }
      }
      else {
        piVar4 = (int *)FUN_004ce990();
        if (*piVar4 == 1100000000) {
          FUN_004ce990();
          FUN_00487080();
          FUN_004ce990();
          FUN_00487080();
          FUN_004ce990();
          FUN_00487080();
          local_30 = FUN_00487080();
        }
        else {
          FUN_004ce990();
          local_30 = FUN_00487080();
        }
        puVar7 = (uint *)FUN_004ce990();
        if ((*puVar7 & 4) == 0) {
          FUN_004ce990();
          cVar2 = FUN_00438d40();
          if (cVar2 == '\0') {
            FUN_004ce990();
            FUN_00487160();
            local_8 = 8;
            pcVar10 = (char *)FUN_004cbb30();
            local_20 = _atol(pcVar10);
            local_8 = 0xffffffff;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_398);
          }
          else {
            FUN_004ce990();
            local_20 = FUN_00487080();
          }
        }
        else {
          puVar7 = (uint *)FUN_004ce990();
          local_20 = *puVar7;
        }
        puVar7 = (uint *)FUN_004ce990();
        if ((*puVar7 & 8) == 0) {
          FUN_004ce990();
          cVar2 = FUN_00438d40();
          if (cVar2 == '\0') {
            FUN_004ce990();
            FUN_00487160();
            local_8 = 9;
            pcVar10 = (char *)FUN_004cbb30();
            local_28 = _atol(pcVar10);
            local_8 = 0xffffffff;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3b4);
          }
          else {
            FUN_004ce990();
            local_28 = FUN_00487080();
          }
        }
        else {
          puVar7 = (uint *)FUN_004ce990();
          local_28 = *puVar7;
        }
        puVar7 = (uint *)FUN_004ce990();
        if ((*puVar7 & 0x20) != 0) {
          if ((int)local_20 < 1000000) {
            local_3b8 = auStack_61c + 0x18;
            uStack_608 = &DAT_007ceea0;
            uStack_60c = 0x454ceb;
            basic_string<>();
            uStack_608 = (undefined *)0x454cf6;
            pcVar10 = (char *)FUN_00401c50();
            _sprintf(local_140,pcVar10);
            local_3bc = (undefined1 *)&uStack_600;
            uStack_608 = (undefined *)0x454d2a;
            basic_string<>();
            local_8 = 10;
            local_3c0 = auStack_61c;
            puStack_620 = auStack_61c;
            FUN_00438b60();
            local_8 = CONCAT31(local_8._1_3_,0xb);
            local_3c4 = auStack_638;
            basic_string<>(local_140);
            local_8 = 0xffffffff;
            FUN_0042bed0();
            ExceptionList = local_10;
            return 1;
          }
          cVar2 = FUN_00438d40();
          if (cVar2 == '\0') {
            FUN_00487160();
            local_8 = 0xc;
            pcVar10 = (char *)FUN_004cbb30();
            local_20 = _atol(pcVar10);
            local_8 = 0xffffffff;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3e0);
          }
          else {
            local_20 = FUN_00487080();
          }
        }
        puVar7 = (uint *)FUN_004ce990();
        if ((*puVar7 & 0x40) != 0) {
          if ((int)local_28 < 1000000) {
            local_3e4 = auStack_61c + 0x18;
            uStack_608 = &DAT_007ceee8;
            uStack_60c = 0x454e67;
            basic_string<>();
            uStack_608 = (undefined *)0x454e72;
            pcVar10 = (char *)FUN_00401c50();
            _sprintf(local_208,pcVar10);
            local_3e8 = (undefined1 *)&uStack_600;
            uStack_608 = (undefined *)0x454ea6;
            basic_string<>();
            local_8 = 0xd;
            local_3ec = auStack_61c;
            puStack_620 = auStack_61c;
            FUN_00438b60();
            local_8 = CONCAT31(local_8._1_3_,0xe);
            local_3f0 = auStack_638;
            basic_string<>(local_208);
            local_8 = 0xffffffff;
            FUN_0042bed0();
            ExceptionList = local_10;
            return 1;
          }
          cVar2 = FUN_00438d40();
          if (cVar2 == '\0') {
            FUN_00487160();
            local_8 = 0xf;
            pcVar10 = (char *)FUN_004cbb30();
            local_28 = _atol(pcVar10);
            local_8 = 0xffffffff;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_40c);
          }
          else {
            local_28 = FUN_00487080();
          }
        }
        local_2a = 0;
        puVar7 = (uint *)FUN_004ce990();
        local_29 = (*puVar7 & 1) != 0;
        local_24 = 0;
        puVar7 = (uint *)FUN_004ce990();
        if ((*puVar7 & 0x10) != 0) {
          local_24 = local_30;
          if (local_30 < 1000000) {
            puStack_614 = &DAT_007cef30;
            uStack_618 = 0x455033;
            basic_string<>();
            puStack_614 = (undefined *)0x45503e;
            pcVar10 = (char *)FUN_00401c50();
            uStack_600 = 0x45505a;
            _sprintf(local_2d0,pcVar10);
            uStack_608 = (undefined *)0x455072;
            basic_string<>();
            local_8 = 0x10;
            puStack_620 = auStack_61c;
            FUN_00438b60();
            local_8 = CONCAT31(local_8._1_3_,0x11);
            basic_string<>(local_2d0);
            local_8 = 0xffffffff;
            FUN_0042bed0();
            ExceptionList = local_10;
            return 1;
          }
          local_30 = FUN_00487080();
          local_2a = 1;
        }
        DAT_00a1809c = 1;
        puVar7 = (uint *)FUN_004ce990();
        if ((*puVar7 & 2) == 0) {
          puVar7 = (uint *)FUN_004ce990();
          switch((int)(*puVar7 & 0xf000) >> 0xc) {
          case 0:
            local_2d4 = FUN_004873b0();
            break;
          case 1:
            local_2d4 = FUN_004873b0();
            break;
          case 2:
            __allmul();
            local_2d4 = FUN_004873b0();
            break;
          case 3:
            if (local_28 == 0) {
              local_28 = 1;
            }
            local_2d4 = (int)local_20 / (int)local_28;
            break;
          case 4:
            if (local_28 == 0) {
              local_28 = 1;
            }
            local_2d4 = (int)local_20 % (int)local_28;
            break;
          case 5:
            local_2d4 = local_20 & local_28;
            break;
          case 6:
            if ((int)local_20 < (int)local_28) {
              local_54c = local_20;
            }
            else {
              local_54c = local_28;
            }
            uVar11 = FUN_004174a0();
            iVar3 = FUN_004febf1();
            local_2d4 = uVar11 % (iVar3 + 1U) + local_54c;
          }
          puVar7 = (uint *)FUN_004ce990();
          switch((int)(*puVar7 & 0xf00) >> 8) {
          case 0:
            FUN_00487450();
            FUN_00486e50();
            break;
          case 1:
            FUN_004873b0();
            FUN_00487450();
            FUN_00486e50();
            break;
          case 2:
            FUN_004873b0();
            FUN_00487450();
            FUN_00486e50();
            break;
          case 3:
            __allmul();
            FUN_004873b0();
            FUN_00487450();
            FUN_00486e50();
            break;
          case 4:
            if (local_2d4 == 0) {
              local_2d4 = 1;
            }
            FUN_00487450();
            FUN_00486e50();
            break;
          case 5:
            if (local_2d4 == 0) {
              local_2d4 = 1;
            }
            FUN_00487450();
            FUN_00486e50();
            break;
          case 6:
            FUN_00487450();
            FUN_00486e50();
            break;
          case 7:
            FUN_00487450();
            FUN_00486e50();
            break;
          case 8:
            FUN_00487450();
            FUN_00486e50();
            break;
          case 9:
            FUN_004feff0();
            FUN_004fe844();
            FUN_00486e50();
            break;
          case 10:
            FUN_004fef54();
            FUN_004fe844();
            FUN_00487450();
            FUN_00486e50();
            break;
          case 0xb:
            FUN_004feea4();
            FUN_004fe844();
            FUN_00487450();
            FUN_00486e50();
          }
        }
        else {
          local_2e0 = _DAT_007d0a60;
          local_2d8 = 0;
          puVar7 = (uint *)FUN_004ce990();
          switch((int)(*puVar7 & 0xf000) >> 0xc) {
          case 0:
            local_2e0 = (double)(int)local_20 + (double)(int)local_28;
            break;
          case 1:
            local_2e0 = (double)(int)local_20 - (double)(int)local_28;
            break;
          case 2:
            __allmul();
            local_2d8 = FUN_004873b0();
            local_2d8 = local_2d8 / 2000000000;
            local_2e0 = (double)(int)local_20 * (double)(int)local_28;
            if (local_2d8 != 0) {
              local_2e0 = (double)(local_2d8 * 2000000000);
            }
            break;
          case 3:
            if (local_28 == 0) {
              local_28 = 1;
            }
            local_2e0 = (double)(int)local_20 / (double)(int)local_28;
            break;
          case 4:
            if (local_28 == 0) {
              local_28 = 1;
            }
            local_2e0 = (double)((int)local_20 % (int)local_28);
            break;
          case 5:
            local_2e0 = (double)(int)(local_20 & local_28);
          }
          puVar7 = (uint *)FUN_004ce990();
          switch((int)(*puVar7 & 0xf00) >> 8) {
          case 0:
            FUN_004fe844();
            FUN_004873b0();
            FUN_00487450();
            FUN_00486e50();
            break;
          case 1:
            FUN_004fe844();
            FUN_004873b0();
            FUN_00487450();
            FUN_00486e50();
            break;
          case 2:
            FUN_004fe844();
            FUN_004873b0();
            FUN_00487450();
            FUN_00486e50();
            break;
          case 3:
            FUN_004fe844();
            __allmul();
            local_2e8 = FUN_004873b0();
            local_2e4 = local_2e8 >> 0x1f;
            if ((local_2e8 == 2000000000) || (local_2e8 == -2000000000)) {
              local_2e0 = _DAT_00802e18;
              local_30 = local_2e8;
            }
            FUN_004fe844();
            FUN_004873b0();
            FUN_00487450();
            FUN_00486e50();
            break;
          case 4:
            if (local_2e0 == _DAT_007d0a60) {
              local_2e0 = _DAT_00802e18;
            }
            FUN_004fe844();
            FUN_004873b0();
            FUN_00487450();
            FUN_00486e50();
            break;
          case 5:
            if (local_2e0 == _DAT_007d0a60) {
              local_2e0 = _DAT_00802e18;
            }
            FUN_004fe844();
            FUN_004873b0();
            FUN_00487450();
            FUN_00486e50();
            break;
          case 6:
            if ((double)local_30 < local_2e0) {
              FUN_004fe844();
              FUN_004873b0();
            }
            FUN_00487450();
            FUN_00486e50();
            break;
          case 7:
            if (local_2e0 < (double)local_30) {
              FUN_004fe844();
              FUN_004873b0();
            }
            FUN_00487450();
            FUN_00486e50();
            break;
          case 8:
            if (_DAT_007d0a60 <= local_2e0) {
              FUN_004fe844();
              FUN_004873b0();
            }
            else {
              FUN_004fe844();
              FUN_004873b0();
            }
            FUN_00487450();
            FUN_00486e50();
            break;
          case 9:
            FUN_004feff0();
            FUN_004fe844();
            FUN_00486e50();
            break;
          case 10:
            FUN_004fef54();
            FUN_004fe844();
            FUN_004873b0();
            FUN_00487450();
            FUN_00486e50();
            break;
          case 0xb:
            FUN_004feea4();
            FUN_004fe844();
            FUN_004873b0();
            FUN_00487450();
            FUN_00486e50();
          }
        }
      }
      local_1c = local_1c + 1;
    } while( true );
  }
  piVar4 = (int *)FUN_004ce990();
  if (*piVar4 == 1) {
    puVar5 = (undefined4 *)FUN_004ce990();
    switch(*puVar5) {
    case 0:
      puVar5 = (undefined4 *)FUN_004ce990();
      piVar4 = (int *)*puVar5;
      puVar5 = (undefined4 *)FUN_004ce990();
      local_18 = *piVar4 + *(int *)*puVar5;
      break;
    case 1:
      puVar5 = (undefined4 *)FUN_004ce990();
      piVar4 = (int *)*puVar5;
      puVar5 = (undefined4 *)FUN_004ce990();
      local_18 = *piVar4 - *(int *)*puVar5;
      break;
    case 2:
      puVar5 = (undefined4 *)FUN_004ce990();
      piVar4 = (int *)*puVar5;
      puVar5 = (undefined4 *)FUN_004ce990();
      local_18 = *piVar4 * *(int *)*puVar5;
      break;
    case 3:
      puVar5 = (undefined4 *)FUN_004ce990();
      if (*(int *)*puVar5 == 0) {
        puVar5 = (undefined4 *)FUN_004ce990();
        local_18 = *(uint *)*puVar5;
      }
      else {
        puVar5 = (undefined4 *)FUN_004ce990();
        piVar4 = (int *)*puVar5;
        puVar5 = (undefined4 *)FUN_004ce990();
        local_18 = *piVar4 / *(int *)*puVar5;
      }
      break;
    case 4:
      puVar5 = (undefined4 *)FUN_004ce990();
      if (*(int *)*puVar5 == 0) {
        local_18 = 0;
      }
      else {
        puVar5 = (undefined4 *)FUN_004ce990();
        piVar4 = (int *)*puVar5;
        puVar5 = (undefined4 *)FUN_004ce990();
        local_18 = *piVar4 % *(int *)*puVar5;
      }
      break;
    case 5:
      puVar5 = (undefined4 *)FUN_004ce990();
      puVar7 = (uint *)*puVar5;
      puVar5 = (undefined4 *)FUN_004ce990();
      local_18 = *puVar7 & *(uint *)*puVar5;
      break;
    case 6:
      puVar5 = (undefined4 *)FUN_004ce990();
      piVar4 = (int *)*puVar5;
      puVar5 = (undefined4 *)FUN_004ce990();
      if (*piVar4 < *(int *)*puVar5) {
        puVar5 = (undefined4 *)FUN_004ce990();
        local_430 = *(int *)*puVar5;
      }
      else {
        puVar5 = (undefined4 *)FUN_004ce990();
        local_430 = *(int *)*puVar5;
      }
      uVar11 = FUN_004174a0();
      FUN_004ce990();
      FUN_004ce990();
      iVar3 = FUN_004febf1();
      local_18 = uVar11 % (iVar3 + 1U) + local_430;
    }
    puVar5 = (undefined4 *)FUN_004ce990();
    switch(*puVar5) {
    case 0:
      puVar5 = (undefined4 *)FUN_004ce990();
      *(uint *)*puVar5 = local_18;
      break;
    case 1:
      puVar5 = (undefined4 *)FUN_004ce990();
      *(uint *)*puVar5 = *(int *)*puVar5 + local_18;
      break;
    case 2:
      puVar5 = (undefined4 *)FUN_004ce990();
      *(uint *)*puVar5 = *(int *)*puVar5 - local_18;
      break;
    case 3:
      puVar5 = (undefined4 *)FUN_004ce990();
      *(uint *)*puVar5 = *(int *)*puVar5 * local_18;
      break;
    case 4:
      if (local_18 != 0) {
        puVar5 = (undefined4 *)FUN_004ce990();
        *(int *)*puVar5 = *(int *)*puVar5 / (int)local_18;
      }
      break;
    case 5:
      if (local_18 == 0) {
        local_18 = 1;
      }
      puVar5 = (undefined4 *)FUN_004ce990();
      *(int *)*puVar5 = *(int *)*puVar5 % (int)local_18;
      break;
    case 6:
      puVar5 = (undefined4 *)FUN_004ce990();
      if (*(int *)*puVar5 < (int)local_18) {
        local_44c = local_18;
      }
      else {
        puVar5 = (undefined4 *)FUN_004ce990();
        local_44c = *(uint *)*puVar5;
      }
      puVar5 = (undefined4 *)FUN_004ce990();
      *(uint *)*puVar5 = local_44c;
      break;
    case 7:
      puVar5 = (undefined4 *)FUN_004ce990();
      if ((int)local_18 < *(int *)*puVar5) {
        local_450 = local_18;
      }
      else {
        puVar5 = (undefined4 *)FUN_004ce990();
        local_450 = *(uint *)*puVar5;
      }
      puVar5 = (undefined4 *)FUN_004ce990();
      *(uint *)*puVar5 = local_450;
      break;
    case 8:
      if ((int)local_18 < 0) {
        local_454 = -local_18;
      }
      else {
        local_454 = local_18;
      }
      puVar5 = (undefined4 *)FUN_004ce990();
      *(uint *)*puVar5 = local_454;
      break;
    case 9:
      FUN_004ce990();
      FUN_004ce990();
      FUN_004feff0();
      iVar3 = FUN_004fe844();
      puVar5 = (undefined4 *)FUN_004ce990();
      *(int *)*puVar5 = iVar3 % 0xe10;
      break;
    case 10:
      FUN_004fef54();
      uVar9 = FUN_004fe844();
      puVar5 = (undefined4 *)FUN_004ce990();
      *(undefined4 *)*puVar5 = uVar9;
      break;
    case 0xb:
      FUN_004feea4();
      uVar9 = FUN_004fe844();
      puVar5 = (undefined4 *)FUN_004ce990();
      *(undefined4 *)*puVar5 = uVar9;
    }
    ExceptionList = local_10;
    return 1;
  }
  if (*piVar4 != 2) goto LAB_004543b3;
  puVar5 = (undefined4 *)FUN_004ce990();
  switch(*puVar5) {
  case 0:
    puVar5 = (undefined4 *)FUN_004ce990();
    puVar5 = (undefined4 *)*puVar5;
    puVar6 = (undefined4 *)FUN_004ce990();
    *(undefined4 *)*puVar6 = *puVar5;
    break;
  case 1:
    puVar5 = (undefined4 *)FUN_004ce990();
    piVar4 = (int *)*puVar5;
    puVar6 = (undefined4 *)FUN_004ce990();
    *(int *)*puVar5 = *piVar4 + *(int *)*puVar6;
    break;
  case 2:
    puVar5 = (undefined4 *)FUN_004ce990();
    piVar4 = (int *)*puVar5;
    puVar6 = (undefined4 *)FUN_004ce990();
    *(int *)*puVar5 = *piVar4 - *(int *)*puVar6;
    break;
  case 3:
    puVar5 = (undefined4 *)FUN_004ce990();
    piVar4 = (int *)*puVar5;
    puVar6 = (undefined4 *)FUN_004ce990();
    *(int *)*puVar5 = *piVar4 * *(int *)*puVar6;
    break;
  case 4:
    puVar5 = (undefined4 *)FUN_004ce990();
    if (*(int *)*puVar5 != 0) {
      puVar5 = (undefined4 *)FUN_004ce990();
      piVar4 = (int *)*puVar5;
      puVar6 = (undefined4 *)FUN_004ce990();
      *(int *)*puVar5 = *piVar4 / *(int *)*puVar6;
      ExceptionList = local_10;
      return 1;
    }
  default:
switchD_00453e80_default:
    break;
  case 5:
    puVar5 = (undefined4 *)FUN_004ce990();
    if (*(int *)*puVar5 == 0) {
      puVar5 = (undefined4 *)FUN_004ce990();
      *(undefined4 *)*puVar5 = 0;
    }
    else {
      puVar5 = (undefined4 *)FUN_004ce990();
      piVar4 = (int *)*puVar5;
      puVar6 = (undefined4 *)FUN_004ce990();
      *(int *)*puVar5 = *piVar4 % *(int *)*puVar6;
    }
    break;
  case 6:
    puVar5 = (undefined4 *)FUN_004ce990();
    piVar4 = (int *)*puVar5;
    puVar5 = (undefined4 *)FUN_004ce990();
    if (*(int *)*puVar5 < *piVar4) {
      puVar5 = (undefined4 *)FUN_004ce990();
      local_470 = *(undefined4 *)*puVar5;
    }
    else {
      puVar5 = (undefined4 *)FUN_004ce990();
      local_470 = *(undefined4 *)*puVar5;
    }
    puVar5 = (undefined4 *)FUN_004ce990();
    *(undefined4 *)*puVar5 = local_470;
    break;
  case 7:
    puVar5 = (undefined4 *)FUN_004ce990();
    piVar4 = (int *)*puVar5;
    puVar5 = (undefined4 *)FUN_004ce990();
    if (*piVar4 < *(int *)*puVar5) {
      puVar5 = (undefined4 *)FUN_004ce990();
      local_474 = *(undefined4 *)*puVar5;
    }
    else {
      puVar5 = (undefined4 *)FUN_004ce990();
      local_474 = *(undefined4 *)*puVar5;
    }
    puVar5 = (undefined4 *)FUN_004ce990();
    *(undefined4 *)*puVar5 = local_474;
    break;
  case 8:
    puVar5 = (undefined4 *)FUN_004ce990();
    if (*(int *)*puVar5 < 0) {
      puVar5 = (undefined4 *)FUN_004ce990();
      local_478 = -*(int *)*puVar5;
    }
    else {
      puVar5 = (undefined4 *)FUN_004ce990();
      local_478 = *(int *)*puVar5;
    }
    puVar5 = (undefined4 *)FUN_004ce990();
    *(int *)*puVar5 = local_478;
    break;
  case 9:
    FUN_004ce990();
    FUN_004feff0();
    iVar3 = FUN_004fe844();
    puVar5 = (undefined4 *)FUN_004ce990();
    *(int *)*puVar5 = iVar3 % 0xe10;
    goto switchD_00453e80_default;
  case 10:
    FUN_004ce990();
    FUN_004fef54();
    uVar9 = FUN_004fe844();
    puVar5 = (undefined4 *)FUN_004ce990();
    *(undefined4 *)*puVar5 = uVar9;
    goto switchD_00453e80_default;
  case 0xb:
    FUN_004ce990();
    FUN_004feea4();
    uVar9 = FUN_004fe844();
    puVar5 = (undefined4 *)FUN_004ce990();
    *(undefined4 *)*puVar5 = uVar9;
    goto switchD_00453e80_default;
  }
  ExceptionList = local_10;
  return 1;
}

