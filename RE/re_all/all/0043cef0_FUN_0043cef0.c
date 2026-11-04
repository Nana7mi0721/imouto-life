
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0043dd27) */
/* WARNING: Removing unreachable block (ram,0x0043d168) */

uint FUN_0043cef0(char param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  void *pvVar13;
  uint uVar14;
  int iVar15;
  undefined4 *puVar16;
  uint3 uVar17;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *this;
  void *pvVar18;
  undefined1 auStack_164c [4];
  undefined4 uStack_1648;
  int iStack_1644;
  int iStack_1640;
  size_t sVar19;
  char *pcVar20;
  undefined4 local_1624;
  undefined4 local_160c;
  undefined4 local_15f4;
  undefined4 local_15dc;
  undefined4 local_15c4;
  undefined4 local_15ac;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1598 [28];
  undefined1 *local_157c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1578 [28];
  undefined4 local_155c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1558 [28];
  undefined1 *local_153c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1538 [28];
  undefined4 local_151c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1518 [28];
  undefined1 *local_14fc;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_14f8 [28];
  undefined4 local_14dc;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_14d8 [28];
  undefined1 *local_14bc;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_14b8 [28];
  undefined4 local_149c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1498 [28];
  undefined1 *local_147c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1478 [28];
  undefined4 local_145c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1458 [28];
  undefined1 *local_143c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1438 [28];
  undefined4 local_141c;
  short local_1418 [2];
  size_t local_1414;
  int local_1410;
  int local_140c;
  int local_1408;
  uint local_1404;
  int local_1400;
  int local_13fc;
  short local_13f8 [2];
  size_t local_13f4;
  int local_13f0;
  uint local_13ec;
  int local_13e8;
  int local_13e4;
  int local_13e0;
  int local_13dc;
  void *local_13d8;
  undefined1 local_13d4 [4];
  undefined1 local_13d0 [5032];
  undefined4 local_28;
  int local_24;
  int local_20;
  byte local_19;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad560;
  local_10 = ExceptionList;
  local_14 = 0x43cf12;
  local_28 = DAT_0084b484;
  bVar7 = false;
  bVar6 = false;
  bVar5 = false;
  bVar4 = false;
  bVar3 = false;
  bVar2 = false;
  if (DAT_00a0f828 < (int)(DAT_00a0f820 + 4)) {
    DAT_00a117e4 = 1;
    uVar14 = DAT_00a0f820 + 4 & 0xffffff00;
  }
  else {
    DAT_00a0f844 = 4;
    iStack_1640 = 0x43cf72;
    ExceptionList = &local_10;
    pvVar13 = _memcpy(local_13d4,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (param_1 != '\0') {
      pvVar13 = (void *)FUN_004174a0();
    }
    local_24 = 0;
    local_20 = 0;
    local_19 = 0;
    if (DAT_00a0f828 < (int)(DAT_00a0f820 + 4)) {
      DAT_00a117e4 = 1;
      uVar14 = (uint)pvVar13 & 0xffffff00;
    }
    else {
      DAT_00a0f844 = 4;
      iStack_1640 = 0x43cff7;
      pvVar13 = _memcpy(&local_24,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      if (local_24 < 0) {
        uVar14 = (uint)pvVar13 & 0xffffff00;
      }
      else {
        uVar14 = FUN_004cdbb0();
        for (local_13dc = 0; local_13dc < local_24; local_13dc = local_13dc + 1) {
          if (DAT_00a0f828 < (int)(DAT_00a0f820 + 4)) {
            DAT_00a117e4 = 1;
            ExceptionList = local_10;
            return DAT_00a0f820 + 4 & 0xffffff00;
          }
          DAT_00a0f844 = 4;
          iStack_1640 = 0x43d09a;
          pvVar13 = _memcpy(&local_20,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
          if (local_20 < 0) {
            ExceptionList = local_10;
            return (uint)pvVar13 & 0xffffff00;
          }
          FUN_004cde80();
          uVar14 = FUN_004cd310();
          for (local_13e0 = 0; local_13e0 < local_20; local_13e0 = local_13e0 + 1) {
            if (DAT_00a0f828 < (int)(DAT_00a0f820 + 1)) {
              DAT_00a117e4 = 1;
              ExceptionList = local_10;
              return DAT_00a0f820 + 1 & 0xffffff00;
            }
            DAT_00a0f844 = 1;
            iStack_1640 = 0x43d14b;
            _memcpy(&local_19,(void *)(DAT_00a0f824 + DAT_00a0f820),1);
            DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
            iStack_1640 = 0x43d190;
            FUN_004cde80();
            FUN_004cde80();
            FUN_004ce970();
            local_13e4 = 0;
            while( true ) {
              FUN_004cde80();
              FUN_004cde80();
              uVar14 = FUN_004ce080();
              if ((int)uVar14 <= local_13e4) break;
              if (DAT_00a0f828 < (int)(DAT_00a0f820 + 4)) {
                DAT_00a117e4 = 1;
                ExceptionList = local_10;
                return DAT_00a0f820 + 4 & 0xffffff00;
              }
              DAT_00a0f844 = 4;
              sVar19 = 4;
              pvVar18 = (void *)(DAT_00a0f824 + DAT_00a0f820);
              iStack_1640 = local_13e0;
              iStack_1644 = local_13dc;
              uStack_1648 = 0x43d24e;
              FUN_004cde80();
              iStack_1644 = 0x43d255;
              FUN_004cde80();
              iStack_1640 = 0x43d25c;
              pvVar13 = (void *)FUN_004ce990();
              iStack_1640 = 0x43d262;
              _memcpy(pvVar13,pvVar18,sVar19);
              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
              local_13e4 = local_13e4 + 1;
            }
          }
        }
        if (DAT_00a0f828 < (int)(DAT_00a0f820 + 4)) {
          DAT_00a117e4 = 1;
          uVar14 = uVar14 & 0xffffff00;
        }
        else {
          DAT_00a0f844 = 4;
          iStack_1640 = 0x43d2c9;
          pvVar13 = _memcpy(&local_14,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
          if (local_14 < 0) {
            uVar14 = (uint)pvVar13 & 0xffffff00;
          }
          else {
            uVar14 = FUN_004cd310();
            for (local_13e8 = 0; local_13e8 < local_14; local_13e8 = local_13e8 + 1) {
              local_13ec = 0;
              if (DAT_00a0f828 < (int)(DAT_00a0f820 + 4)) {
                DAT_00a117e4 = 1;
                ExceptionList = local_10;
                return DAT_00a0f820 + 4 & 0xffffff00;
              }
              DAT_00a0f844 = 4;
              iStack_1640 = 0x43d376;
              pvVar13 = _memcpy(&local_18,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
              if (local_18 < 0) {
                ExceptionList = local_10;
                return (uint)pvVar13 & 0xffffff00;
              }
              FUN_004cde80();
              iVar15 = FUN_004ce080();
              if (iVar15 < local_18) {
                FUN_004cde80();
                FUN_004ce970();
              }
              for (local_13ec = 0; (int)local_13ec < local_18; local_13ec = local_13ec + 1) {
                if (DAT_00a0f828 < (int)(DAT_00a0f820 + 4)) {
                  DAT_00a117e4 = 1;
                  ExceptionList = local_10;
                  return local_13ec & 0xffffff00;
                }
                DAT_00a0f844 = 4;
                sVar19 = 4;
                pvVar13 = (void *)(DAT_00a0f824 + DAT_00a0f820);
                iStack_1640 = local_13e8;
                iStack_1644 = 0x43d457;
                FUN_004cde80();
                iStack_1640 = 0x43d45e;
                pvVar18 = (void *)FUN_004ce990();
                iStack_1640 = 0x43d464;
                _memcpy(pvVar18,pvVar13,sVar19);
                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
              }
              while( true ) {
                FUN_004cde80();
                uVar14 = FUN_004ce080();
                if ((int)uVar14 <= (int)local_13ec) break;
                FUN_004cde80();
                puVar16 = (undefined4 *)FUN_004ce990();
                *puVar16 = 0;
                local_13ec = local_13ec + 1;
              }
            }
            if (DAT_00a0f828 < (int)(DAT_00a0f820 + 4)) {
              DAT_00a117e4 = 1;
              uVar14 = uVar14 & 0xffffff00;
            }
            else {
              DAT_00a0f844 = 4;
              iStack_1640 = 0x43d526;
              _memcpy(&local_14,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
              if (local_14 < 0) {
                uVar14 = DAT_00a0f820 & 0xffffff00;
              }
              else {
                iVar15 = FUN_004cc430();
                if (iVar15 < local_14) {
                  FUN_004cc400();
                }
                local_13f0 = 0;
                while( true ) {
                  bVar12 = false;
                  bVar11 = false;
                  bVar10 = false;
                  bVar9 = false;
                  bVar8 = false;
                  bVar1 = false;
                  if (local_14 <= local_13f0) break;
                  uVar17 = (uint3)((uint)local_13f0 >> 8);
                  if (DAT_00a0f84c < 0x6f) {
                    if (DAT_00a0f828 < (int)(DAT_00a0f820 + 2)) {
                      DAT_00a117e4 = 1;
                      ExceptionList = local_10;
                      return (uint)uVar17 << 8;
                    }
                    DAT_00a0f844 = 2;
                    iStack_1640 = 0x43d9ab;
                    _memcpy(local_13f8,(void *)(DAT_00a0f824 + DAT_00a0f820),2);
                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                    if (DAT_00a0f828 < (int)((int)local_13f8[0] + DAT_00a0f820)) {
                      DAT_00a117e4 = 1;
                      ExceptionList = local_10;
                      return (int)local_13f8[0] + DAT_00a0f820 & 0xffffff00;
                    }
                    DAT_00a0f844 = (size_t)local_13f8[0];
                    iStack_1640 = 0x43da0f;
                    _memcpy(local_13d0,(void *)(DAT_00a0f824 + DAT_00a0f820),DAT_00a0f844);
                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                    if (DAT_00a0f84c < 0x7d) {
                      local_14bc = auStack_164c;
                      basic_string<>(local_13d0);
                      local_15dc = FUN_00429250(local_14d8);
                      local_8 = 5;
                      bVar6 = true;
                    }
                    else {
                      local_15dc = basic_string<>();
                      local_8 = 4;
                      bVar7 = true;
                    }
                    local_149c = local_15dc;
                    FUN_004cc4c0();
                    FUN_004cb840();
                    local_8 = 4;
                    if (bVar6) {
                      bVar6 = false;
                      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ::~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                (local_14d8);
                    }
                    local_8 = 0xffffffff;
                    if (bVar7) {
                      bVar7 = false;
                      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ::~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                (local_14b8);
                    }
                  }
                  else {
                    if (DAT_00a0f828 < (int)(DAT_00a0f820 + 4)) {
                      DAT_00a117e4 = 1;
                      ExceptionList = local_10;
                      return (uint)uVar17 << 8;
                    }
                    DAT_00a0f844 = 4;
                    iStack_1640 = 0x43d5f7;
                    _memcpy(&local_13f4,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                    if ((int)local_13f4 < 0x1389) {
                      if (DAT_00a0f828 < (int)(DAT_00a0f820 + local_13f4)) {
                        DAT_00a117e4 = 1;
                        ExceptionList = local_10;
                        return DAT_00a0f820 & 0xffffff00;
                      }
                      DAT_00a0f844 = local_13f4;
                      iStack_1640 = 0x43d820;
                      _memcpy(local_13d0,(void *)(DAT_00a0f824 + DAT_00a0f820),local_13f4);
                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                      if (DAT_00a0f84c < 0x7d) {
                        local_147c = auStack_164c;
                        basic_string<>(local_13d0);
                        local_15c4 = FUN_00429250(local_1498);
                        local_8 = 3;
                        bVar4 = true;
                      }
                      else {
                        local_15c4 = basic_string<>();
                        local_8 = 2;
                        bVar5 = true;
                      }
                      local_145c = local_15c4;
                      FUN_004cc4c0();
                      FUN_004cb840();
                      local_8 = 2;
                      if (bVar4) {
                        bVar4 = false;
                        std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  (local_1498);
                      }
                      local_8 = 0xffffffff;
                      if (bVar5) {
                        bVar5 = false;
                        std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  (local_1478);
                      }
                    }
                    else {
                      local_13d8 = _malloc(local_13f4 + 2);
                      if (DAT_00a0f828 < (int)(DAT_00a0f820 + local_13f4)) {
                        DAT_00a117e4 = 1;
                        ExceptionList = local_10;
                        return (uint)local_13d8 & 0xffffff00;
                      }
                      DAT_00a0f844 = local_13f4;
                      iStack_1640 = 0x43d67f;
                      _memcpy(local_13d8,(void *)(DAT_00a0f824 + DAT_00a0f820),local_13f4);
                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                      bVar1 = DAT_00a0f84c < 0x7d;
                      if (bVar1) {
                        local_143c = auStack_164c;
                        basic_string<>(local_13d8);
                        local_15ac = FUN_00429250(local_1458);
                        bVar3 = true;
                      }
                      else {
                        local_15ac = basic_string<>();
                        bVar2 = true;
                      }
                      local_8 = (uint)bVar1;
                      local_141c = local_15ac;
                      FUN_004cc4c0();
                      FUN_004cb840();
                      local_8 = 0;
                      if (bVar3) {
                        bVar3 = false;
                        std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  (local_1458);
                      }
                      local_8 = 0xffffffff;
                      if (bVar2) {
                        bVar2 = false;
                        std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  (local_1438);
                      }
                      _free(local_13d8);
                    }
                  }
                  local_13f0 = local_13f0 + 1;
                }
                while (uVar14 = FUN_004cc430(), local_13f0 < (int)uVar14) {
                  pcVar20 = "";
                  this = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                         FUN_004cc4c0();
                  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                            (this,pcVar20);
                  local_13f0 = local_13f0 + 1;
                }
                if (DAT_00a0f828 < (int)(DAT_00a0f820 + 4)) {
                  DAT_00a117e4 = 1;
                  uVar14 = uVar14 & 0xffffff00;
                }
                else {
                  DAT_00a0f844 = 4;
                  iStack_1640 = 0x43dbe3;
                  _memcpy(&local_24,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                  uVar17 = (uint3)(DAT_00a0f820 >> 8);
                  if (local_24 < 0) {
                    uVar14 = (uint)uVar17 << 8;
                  }
                  else if (local_24 < 0x2711) {
                    iVar15 = FUN_004cfab0();
                    if (local_24 < iVar15) {
                      FUN_004cfab0();
                      FUN_004cd310();
                      local_13fc = local_24;
                      while (iVar15 = FUN_004cfab0(), local_13fc < iVar15) {
                        FUN_004cde80();
                        FUN_004ce970();
                        local_13fc = local_13fc + 1;
                      }
                    }
                    else {
                      FUN_004cd310();
                    }
                    for (local_1400 = 0; uVar17 = (uint3)((uint)local_1400 >> 8),
                        local_1400 < local_24; local_1400 = local_1400 + 1) {
                      if (DAT_00a0f828 < (int)(DAT_00a0f820 + 1)) {
                        DAT_00a117e4 = 1;
                        ExceptionList = local_10;
                        return (uint)uVar17 << 8;
                      }
                      DAT_00a0f844 = 1;
                      iStack_1640 = 0x43dd0a;
                      _memcpy(&local_19,(void *)(DAT_00a0f824 + DAT_00a0f820),1);
                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                      FUN_004cde80();
                      uVar14 = FUN_004ce970();
                      local_1404 = 0;
                      while ((int)local_1404 < (int)(uint)local_19) {
                        if (DAT_00a0f828 < (int)(DAT_00a0f820 + 4)) {
                          DAT_00a117e4 = 1;
                          ExceptionList = local_10;
                          return uVar14 & 0xffffff00;
                        }
                        DAT_00a0f844 = 4;
                        sVar19 = 4;
                        pvVar18 = (void *)(DAT_00a0f824 + DAT_00a0f820);
                        iStack_1640 = local_1400;
                        iStack_1644 = 0x43ddce;
                        FUN_004cde80();
                        iStack_1640 = 0x43ddd5;
                        pvVar13 = (void *)FUN_004ce990();
                        iStack_1640 = 0x43dddb;
                        _memcpy(pvVar13,pvVar18,sVar19);
                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                        uVar14 = local_1404 + 1;
                        local_1404 = uVar14;
                      }
                    }
                    if (DAT_00a0f828 < (int)(DAT_00a0f820 + 4)) {
                      DAT_00a117e4 = 1;
                      uVar14 = (uint)uVar17 << 8;
                    }
                    else {
                      DAT_00a0f844 = 4;
                      iStack_1640 = 0x43de3f;
                      _memcpy(&local_24,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                      if (local_24 < 0x2711) {
                        iVar15 = FUN_004cfab0();
                        if (local_24 < iVar15) {
                          FUN_004cfab0();
                          FUN_004cde50();
                          local_1408 = local_24;
                          while (iVar15 = FUN_004cfab0(), local_1408 < iVar15) {
                            FUN_004cde80();
                            FUN_004cc400();
                            local_1408 = local_1408 + 1;
                          }
                        }
                        else {
                          FUN_004cde50();
                        }
                        for (local_140c = 0; uVar17 = (uint3)((uint)local_140c >> 8),
                            local_140c < local_24; local_140c = local_140c + 1) {
                          if (DAT_00a0f828 < (int)(DAT_00a0f820 + 1)) {
                            DAT_00a117e4 = 1;
                            ExceptionList = local_10;
                            return (uint)uVar17 << 8;
                          }
                          DAT_00a0f844 = 1;
                          iStack_1640 = 0x43df59;
                          _memcpy(&local_19,(void *)(DAT_00a0f824 + DAT_00a0f820),1);
                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                          FUN_004cde80();
                          FUN_004cc400();
                          for (local_1410 = 0; local_1410 < (int)(uint)local_19;
                              local_1410 = local_1410 + 1) {
                            if (DAT_00a0f84c < 0x6f) {
                              if (DAT_00a0f828 < (int)(DAT_00a0f820 + 2)) {
                                DAT_00a117e4 = 1;
                                ExceptionList = local_10;
                                return 0;
                              }
                              DAT_00a0f844 = 2;
                              iStack_1640 = 0x43e3fe;
                              _memcpy(local_1418,(void *)(DAT_00a0f824 + DAT_00a0f820),2);
                              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                              if (DAT_00a0f828 < (int)((int)local_1418[0] + DAT_00a0f820)) {
                                DAT_00a117e4 = 1;
                                ExceptionList = local_10;
                                return (int)local_1418[0] + DAT_00a0f820 & 0xffffff00;
                              }
                              DAT_00a0f844 = (size_t)local_1418[0];
                              iStack_1640 = 0x43e462;
                              _memcpy(local_13d0,(void *)(DAT_00a0f824 + DAT_00a0f820),DAT_00a0f844)
                              ;
                              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                              if (DAT_00a0f84c < 0x7d) {
                                local_157c = auStack_164c;
                                basic_string<>(local_13d0);
                                local_1624 = FUN_00429250(local_1598);
                                local_8 = 0xb;
                                bVar11 = true;
                              }
                              else {
                                local_1624 = basic_string<>();
                                local_8 = 10;
                                bVar12 = true;
                              }
                              local_155c = local_1624;
                              iStack_1640 = 0x43e55f;
                              FUN_004cde80();
                              FUN_004cc4c0();
                              FUN_004cb840();
                              local_8 = 10;
                              if (bVar11) {
                                bVar11 = false;
                                std::
                                basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                ::
                                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                          (local_1598);
                              }
                              local_8 = 0xffffffff;
                              if (bVar12) {
                                bVar12 = false;
                                std::
                                basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                ::
                                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                          (local_1578);
                              }
                            }
                            else {
                              if (DAT_00a0f828 < (int)(DAT_00a0f820 + 4)) {
                                DAT_00a117e4 = 1;
                                ExceptionList = local_10;
                                return 0;
                              }
                              DAT_00a0f844 = 4;
                              iStack_1640 = 0x43e012;
                              _memcpy(&local_1414,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                              if ((int)local_1414 < 0x1389) {
                                if (DAT_00a0f828 < (int)(DAT_00a0f820 + local_1414)) {
                                  DAT_00a117e4 = 1;
                                  ExceptionList = local_10;
                                  return DAT_00a0f820 & 0xffffff00;
                                }
                                DAT_00a0f844 = local_1414;
                                iStack_1640 = 0x43e252;
                                _memcpy(local_13d0,(void *)(DAT_00a0f824 + DAT_00a0f820),local_1414)
                                ;
                                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                if (DAT_00a0f84c < 0x7d) {
                                  local_153c = auStack_164c;
                                  basic_string<>(local_13d0);
                                  local_160c = FUN_00429250(local_1558);
                                  local_8 = 9;
                                  bVar9 = true;
                                }
                                else {
                                  local_160c = basic_string<>();
                                  local_8 = 8;
                                  bVar10 = true;
                                }
                                local_151c = local_160c;
                                iStack_1640 = 0x43e350;
                                FUN_004cde80();
                                FUN_004cc4c0();
                                FUN_004cb840();
                                local_8 = 8;
                                if (bVar9) {
                                  bVar9 = false;
                                  std::
                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  ::
                                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                            (local_1558);
                                }
                                local_8 = 0xffffffff;
                                if (bVar10) {
                                  bVar10 = false;
                                  std::
                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  ::
                                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                            (local_1538);
                                }
                              }
                              else {
                                local_13d8 = _malloc(local_1414 + 2);
                                if (DAT_00a0f828 < (int)(DAT_00a0f820 + local_1414)) {
                                  DAT_00a117e4 = 1;
                                  ExceptionList = local_10;
                                  return (uint)local_13d8 & 0xffffff00;
                                }
                                DAT_00a0f844 = local_1414;
                                iStack_1640 = 0x43e09a;
                                _memcpy(local_13d8,(void *)(DAT_00a0f824 + DAT_00a0f820),local_1414)
                                ;
                                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                if (DAT_00a0f84c < 0x7d) {
                                  local_14fc = auStack_164c;
                                  basic_string<>(local_13d8);
                                  local_15f4 = FUN_00429250(local_1518);
                                  local_8 = 7;
                                  bVar1 = true;
                                }
                                else {
                                  local_15f4 = basic_string<>();
                                  local_8 = 6;
                                  bVar8 = true;
                                }
                                local_14dc = local_15f4;
                                iStack_1640 = 0x43e195;
                                FUN_004cde80();
                                FUN_004cc4c0();
                                FUN_004cb840();
                                local_8 = 6;
                                if (bVar1) {
                                  bVar1 = false;
                                  std::
                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  ::
                                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                            (local_1518);
                                }
                                local_8 = 0xffffffff;
                                if (bVar8) {
                                  bVar8 = false;
                                  std::
                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  ::
                                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                            (local_14f8);
                                }
                                _free(local_13d8);
                              }
                            }
                          }
                        }
                        uVar14 = CONCAT31(uVar17,1);
                      }
                      else {
                        uVar14 = DAT_00a0f820 & 0xffffff00;
                      }
                    }
                  }
                  else {
                    uVar14 = (uint)uVar17 << 8;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  ExceptionList = local_10;
  return uVar14;
}

