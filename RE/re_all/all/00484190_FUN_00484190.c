
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_00484190(int param_1,int param_2)

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
  void *pvVar10;
  int iVar11;
  uint3 uVar12;
  void *pvVar13;
  undefined1 uStack00000000;
  undefined1 auStack_1554 [12];
  undefined4 uStack_1548;
  size_t sVar14;
  undefined4 local_152c;
  undefined4 local_1514;
  undefined4 local_14fc;
  undefined4 local_14e4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_14d0 [28];
  undefined1 *local_14b4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_14b0 [28];
  undefined4 local_1494;
  undefined4 local_1490;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_148c [28];
  undefined1 *local_1470;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_146c [28];
  undefined4 local_1450;
  undefined4 local_144c;
  undefined4 local_1448;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1444 [28];
  undefined1 *local_1428;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1424 [28];
  undefined4 local_1408;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1404 [28];
  undefined1 *local_13e8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_13e4 [28];
  undefined4 local_13c8;
  undefined4 local_13c4;
  int local_13c0;
  uint local_13bc;
  void *local_13b8;
  size_t local_13b4;
  undefined1 local_13b0 [5020];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af695;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  bVar9 = false;
  bVar8 = false;
  bVar7 = false;
  bVar6 = false;
  bVar5 = false;
  bVar4 = false;
  bVar3 = false;
  bVar2 = false;
  local_13b4 = 0;
  ExceptionList = &local_10;
  FUN_004ce970();
  FUN_004cc400();
  for (local_13bc = 0; (int)local_13bc < param_1; local_13bc = local_13bc + 1) {
    if (DAT_00a0f7f8 == '\0') {
      iVar11 = FUN_004ce990();
      if (iVar11 == 0) {
        local_13c4 = 0xffffffff;
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        sVar14 = 4;
        pvVar13 = (void *)(DAT_00a0f830 + DAT_00a11790);
        uStack_1548 = 0x484304;
        pvVar10 = (void *)FUN_004ce990();
        uStack_1548 = 0x48430a;
        _memcpy(pvVar10,pvVar13,sVar14);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
    }
    else {
      if (DAT_00a0f828 < (int)(DAT_00a0f820 + 4)) {
        DAT_00a117e4 = 1;
        ExceptionList = local_10;
        return local_13bc & 0xffffff00;
      }
      DAT_00a0f844 = 4;
      sVar14 = 4;
      pvVar13 = (void *)(DAT_00a0f824 + DAT_00a0f820);
      uStack_1548 = 0x484278;
      pvVar10 = (void *)FUN_004ce990();
      uStack_1548 = 0x48427e;
      _memcpy(pvVar10,pvVar13,sVar14);
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    }
  }
  local_13c0 = 0;
  do {
    uVar12 = (uint3)((uint)local_13c0 >> 8);
    if (param_2 <= local_13c0) {
      ExceptionList = local_10;
      return CONCAT31(uVar12,1);
    }
    if (DAT_00a0f7f8 == '\0') {
      if (&uStack00000000 == (undefined1 *)0x13b4) {
        local_1448 = 0xffffffff;
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        uStack_1548 = 0x48476a;
        _memcpy(&local_13b4,(void *)(DAT_00a0f830 + DAT_00a11790),4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      if ((int)local_13b4 < 0x1389) {
        if (&uStack00000000 == (undefined1 *)0x13b0) {
          local_1490 = 0xffffffff;
          __CxxThrowException_8();
        }
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = local_13b4;
          uStack_1548 = 0x4849bb;
          _memcpy(local_13b0,(void *)(DAT_00a0f830 + DAT_00a11790),local_13b4);
        }
        DAT_00a11790 = DAT_00a11790 + local_13b4;
        if (DAT_00a0f84c < 0x7d) {
          local_14b4 = auStack_1554;
          basic_string<>(local_13b0);
          local_152c = FUN_00429250(local_14d0);
          local_8 = 7;
          bVar8 = true;
        }
        else {
          local_152c = basic_string<>();
          local_8 = 6;
          bVar9 = true;
        }
        local_1494 = local_152c;
        FUN_004cc4c0();
        FUN_004cb840();
        local_8 = 6;
        if (bVar8) {
          bVar8 = false;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_14d0);
        }
        local_8 = 0xffffffff;
        if (bVar9) {
          bVar9 = false;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_14b0);
        }
      }
      else {
        local_13b8 = _malloc(local_13b4 + 2);
        if (local_13b8 == (void *)0x0) {
          local_144c = 0xffffffff;
          __CxxThrowException_8();
        }
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = local_13b4;
          uStack_1548 = 0x484805;
          _memcpy(local_13b8,(void *)(DAT_00a0f830 + DAT_00a11790),local_13b4);
        }
        DAT_00a11790 = DAT_00a11790 + local_13b4;
        if (DAT_00a0f84c < 0x7d) {
          local_1470 = auStack_1554;
          basic_string<>(local_13b8);
          local_1514 = FUN_00429250(local_148c);
          local_8 = 5;
          bVar6 = true;
        }
        else {
          local_1514 = basic_string<>();
          local_8 = 4;
          bVar7 = true;
        }
        local_1450 = local_1514;
        FUN_004cc4c0();
        FUN_004cb840();
        local_8 = 4;
        if (bVar6) {
          bVar6 = false;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_148c);
        }
        local_8 = 0xffffffff;
        if (bVar7) {
          bVar7 = false;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_146c);
        }
        _free(local_13b8);
      }
    }
    else {
      if (DAT_00a0f828 < (int)(DAT_00a0f820 + 4)) {
        DAT_00a117e4 = 1;
        ExceptionList = local_10;
        return (uint)uVar12 << 8;
      }
      DAT_00a0f844 = 4;
      uStack_1548 = 0x4843a2;
      _memcpy(&local_13b4,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      if ((int)local_13b4 < 0x1389) {
        if (DAT_00a0f828 < (int)(DAT_00a0f820 + local_13b4)) {
          DAT_00a117e4 = 1;
          ExceptionList = local_10;
          return DAT_00a0f820 & 0xffffff00;
        }
        DAT_00a0f844 = local_13b4;
        uStack_1548 = 0x4845cb;
        _memcpy(local_13b0,(void *)(DAT_00a0f824 + DAT_00a0f820),local_13b4);
        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
        if (DAT_00a0f84c < 0x7d) {
          local_1428 = auStack_1554;
          basic_string<>(local_13b0);
          local_14fc = FUN_00429250(local_1444);
          local_8 = 3;
          bVar4 = true;
        }
        else {
          local_14fc = basic_string<>();
          local_8 = 2;
          bVar5 = true;
        }
        local_1408 = local_14fc;
        FUN_004cc4c0();
        FUN_004cb840();
        local_8 = 2;
        if (bVar4) {
          bVar4 = false;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1444);
        }
        local_8 = 0xffffffff;
        if (bVar5) {
          bVar5 = false;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1424);
        }
      }
      else {
        local_13b8 = _malloc(local_13b4 + 2);
        if (DAT_00a0f828 < (int)(DAT_00a0f820 + local_13b4)) {
          DAT_00a117e4 = 1;
          ExceptionList = local_10;
          return (uint)local_13b8 & 0xffffff00;
        }
        DAT_00a0f844 = local_13b4;
        uStack_1548 = 0x48442a;
        _memcpy(local_13b8,(void *)(DAT_00a0f824 + DAT_00a0f820),local_13b4);
        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
        bVar1 = DAT_00a0f84c < 0x7d;
        if (bVar1) {
          local_13e8 = auStack_1554;
          basic_string<>(local_13b8);
          local_14e4 = FUN_00429250(local_1404);
          bVar3 = true;
        }
        else {
          local_14e4 = basic_string<>();
          bVar2 = true;
        }
        local_8 = (uint)bVar1;
        local_13c8 = local_14e4;
        FUN_004cc4c0();
        FUN_004cb840();
        local_8 = 0;
        if (bVar3) {
          bVar3 = false;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1404);
        }
        local_8 = 0xffffffff;
        if (bVar2) {
          bVar2 = false;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_13e4);
        }
        _free(local_13b8);
      }
    }
    local_13c0 = local_13c0 + 1;
  } while( true );
}

