
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_0041e610(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  undefined4 uStack_858;
  undefined *puStack_854;
  undefined *puStack_850;
  undefined4 uStack_84c;
  int local_5e4;
  int local_5e0;
  int local_5dc;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_5d4 [28];
  undefined1 *local_5b8;
  undefined1 *local_5b4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_5b0 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_594 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_578 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_55c [28];
  undefined1 *local_540;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_53c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_520 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_504 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_4e8 [28];
  undefined1 *local_4cc;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_4c8 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_4ac [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_490 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_474 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_458 [28];
  undefined1 *local_43c;
  undefined1 *local_438;
  undefined1 *local_434;
  undefined1 *local_430;
  undefined1 *local_42c;
  undefined1 *local_428;
  undefined1 *local_424;
  undefined1 *local_420;
  undefined1 *local_41c;
  undefined1 *local_418;
  undefined1 *local_414;
  undefined1 *local_410;
  undefined1 *local_40c;
  undefined1 *local_408;
  undefined1 *local_404;
  undefined1 *local_400;
  undefined1 *local_3fc;
  undefined1 *local_3f8;
  undefined1 *local_3f4;
  undefined1 *local_3f0;
  undefined1 *local_3ec;
  undefined1 *local_3e8;
  undefined1 *local_3e4;
  undefined1 *local_3e0;
  undefined1 *local_3dc;
  undefined1 *local_3d8;
  undefined1 *local_3d4;
  undefined1 *local_3d0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3cc [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3b0 [28];
  undefined1 *local_394;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_390 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_374 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_358 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_33c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_320 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_304 [28];
  undefined1 *local_2e8;
  undefined1 *local_2e4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2e0 [28];
  undefined1 *local_2c4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2c0 [28];
  undefined1 *local_2a4;
  undefined1 *local_2a0;
  undefined1 *local_29c;
  undefined1 *local_298;
  undefined1 *local_294;
  undefined1 *local_290;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_270 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_254 [28];
  char local_238 [520];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ac194;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  if (param_2 < -2000000000) {
    local_5dc = -2000000000;
  }
  else {
    local_5dc = param_2;
  }
  if (local_5dc < 0x77359401) {
    if (param_2 < -2000000000) {
      local_5e4 = -2000000000;
    }
    else {
      local_5e4 = param_2;
    }
    local_5e0 = local_5e4;
  }
  else {
    local_5e0 = 2000000000;
  }
  if (in_stack_00000018 == 0) {
    local_290 = (undefined1 *)&uStack_84c;
    puStack_850 = &DAT_007cc1c0;
    puStack_854 = (undefined *)0x41e6c9;
    ExceptionList = &local_10;
    basic_string<>();
    puStack_850 = (undefined *)0x41e6d4;
    pcVar2 = (char *)FUN_00401c50();
    _sprintf(local_238,pcVar2);
  }
  else if (in_stack_00000018 == 1) {
    local_294 = (undefined1 *)&uStack_84c;
    puStack_850 = &DAT_007cc1ec;
    puStack_854 = (undefined *)0x41e717;
    ExceptionList = &local_10;
    basic_string<>();
    puStack_850 = (undefined *)0x41e722;
    pcVar2 = (char *)FUN_00401c50();
    _sprintf(local_238,pcVar2);
  }
  else {
    local_298 = (undefined1 *)&uStack_84c;
    puStack_850 = &DAT_007cc218;
    puStack_854 = (undefined *)0x41e75c;
    ExceptionList = &local_10;
    basic_string<>();
    puStack_850 = (undefined *)0x41e767;
    pcVar2 = (char *)FUN_00401c50();
    _sprintf(local_238,pcVar2);
  }
  if ((in_stack_00000018 != 1) && (local_5e0 < 1000000)) {
    _sprintf(local_238,"%d");
    goto LAB_00420174;
  }
  if (((in_stack_00000018 == 1) || (local_5e0 < 1000000)) || (1099999 < local_5e0)) {
    if (((in_stack_00000018 != 1) && (1099999 < local_5e0)) && (local_5e0 < 0x10c8ea)) {
      local_2a0 = (undefined1 *)&uStack_84c;
      puStack_850 = &DAT_007cc250;
      puStack_854 = (undefined *)0x41e866;
      basic_string<>();
      puStack_850 = (undefined *)0x41e871;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_238,pcVar2);
    }
  }
  else {
    local_29c = (undefined1 *)&puStack_850;
    puStack_854 = &DAT_007cc244;
    uStack_858 = (undefined *)0x41e801;
    basic_string<>();
    puStack_854 = (undefined *)0x41e80c;
    pcVar2 = (char *)FUN_00401c50();
    _sprintf(local_238,pcVar2);
  }
  if ((1599999 < local_5e0) && (local_5e0 < 0x186a64)) {
    basic_string<>();
    local_8 = 1;
    if (in_stack_0000001c == -10) {
      local_2a4 = (undefined1 *)((int)register0x00000010 + -0x848);
      uStack_84c = &DAT_007cc264;
      puStack_850 = (undefined *)0x41e8ee;
      basic_string<>();
      uStack_84c = (undefined *)0x41e8f9;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_238,pcVar2);
    }
    else if (in_stack_0000001c == -1) {
      _sprintf(local_238,"CSelf%d");
    }
    else {
      if (in_stack_00000020 != 0) {
        FUN_004cfb40();
        FUN_004cb840();
        cVar1 = FUN_004cbb70();
        if (cVar1 == '\0') {
          FUN_004cbc20();
          local_8._0_1_ = 2;
          FUN_004cbb30();
          _sprintf(local_238,"CSelf%d[%s]");
          local_8 = CONCAT31(local_8._1_3_,1);
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2c0);
          goto LAB_0041ea12;
        }
      }
      _sprintf(local_238,"CSelf%d");
    }
LAB_0041ea12:
    local_8 = local_8 & 0xffffff00;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_254);
  }
  if ((14999999 < local_5e0) && (local_5e0 < 16000000)) {
    basic_string<>();
    local_8 = 3;
    if (in_stack_0000001c == -1) {
      local_2c4 = (undefined1 *)&puStack_850;
      puStack_854 = &DAT_007cc2b4;
      uStack_858 = (undefined *)0x41ea98;
      basic_string<>();
      puStack_854 = (undefined *)0x41eaa3;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_238,pcVar2);
    }
    else {
      if ((in_stack_00000020 != 0) &&
         (uVar3 = FUN_004cfab0(), (uint)((local_5e0 % 15000000) / 100) < uVar3)) {
        FUN_004cfb40();
        FUN_004cb840();
        cVar1 = FUN_004cbb70();
        if (cVar1 == '\0') {
          FUN_004cbc20();
          local_8._0_1_ = 4;
          FUN_004cbb30();
          local_2e4 = (undefined1 *)&puStack_854;
          uStack_858 = &DAT_007cc2c4;
          basic_string<>();
          uStack_858 = (undefined *)0x41ebc5;
          pcVar2 = (char *)FUN_00401c50();
          _sprintf(local_238,pcVar2);
          local_8 = CONCAT31(local_8._1_3_,3);
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2e0);
          goto LAB_0041ec56;
        }
      }
      local_2e8 = (undefined1 *)&puStack_850;
      puStack_854 = &DAT_007cc2d8;
      uStack_858 = (undefined *)0x41ec2c;
      basic_string<>();
      puStack_854 = (undefined *)0x41ec37;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_238,pcVar2);
    }
LAB_0041ec56:
    local_8 = local_8 & 0xffffff00;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_270);
  }
  if (((in_stack_00000018 != 1) && (1999999 < local_5e0)) && (local_5e0 < 3000000)) {
    if ((local_5e0 % 2000000) / 100000 == 0) {
      FUN_004706f0();
      local_8 = 5;
      FUN_004cbc20();
      local_8._0_1_ = 6;
      FUN_004cbb30();
      _sprintf(local_238,"V%d[%s]");
      local_8._0_1_ = 5;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_320);
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_304);
    }
    else if ((local_5e0 % 2000000) / 100000 < 10) {
      FUN_004706f0();
      local_8 = 7;
      FUN_004cbc20();
      local_8._0_1_ = 8;
      FUN_004cbb30();
      _sprintf(local_238,"V%d-%d[%s]");
      local_8._0_1_ = 7;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_358);
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_33c);
    }
  }
  if (((in_stack_00000018 != 0) && (2999999 < local_5e0)) && (local_5e0 < 4000000)) {
    FUN_004706f0();
    local_8 = 9;
    FUN_004cbc20();
    local_8._0_1_ = 10;
    FUN_004cbb30();
    _sprintf(local_238,"S%d[%s]");
    local_8._0_1_ = 9;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_390);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_374);
  }
  if (((in_stack_00000018 != 1) && (7999999 < local_5e0)) && (local_5e0 < 9000000)) {
    local_394 = (undefined1 *)&uStack_84c;
    puStack_850 = &DAT_007cc304;
    puStack_854 = (undefined *)0x41ef5d;
    basic_string<>();
    puStack_850 = (undefined *)0x41ef68;
    pcVar2 = (char *)FUN_00401c50();
    _sprintf(local_238,pcVar2);
  }
  if (((in_stack_00000018 != 1) && (8999999 < local_5e0)) && (local_5e0 < 9100000)) {
    FUN_004706f0();
    local_8 = 0xb;
    FUN_004cbc20();
    local_8._0_1_ = 0xc;
    FUN_004cbb30();
    _sprintf(local_238,"Sys%d:%s");
    local_8._0_1_ = 0xb;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3cc);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3b0);
  }
  if (((in_stack_00000018 != 1) && (9099999 < local_5e0)) && (local_5e0 < 0x8c1360)) {
    switch(local_5e0 % 10) {
    case 0:
    case 1:
    case 2:
    case 3:
      if ((local_5e0 % 10) / 2 == 0) {
        local_3d0 = (undefined1 *)((int)register0x00000010 + -0x848);
        uStack_84c = &DAT_007cc320;
        puStack_850 = (undefined *)0x41f0d3;
        basic_string<>();
        uStack_84c = (undefined *)0x41f0de;
        FUN_00401c50();
      }
      else {
        local_3d4 = (undefined1 *)((int)register0x00000010 + -0x848);
        uStack_84c = &DAT_007cc328;
        puStack_850 = (undefined *)0x41f10a;
        basic_string<>();
        uStack_84c = (undefined *)0x41f115;
        FUN_00401c50();
      }
      local_3d8 = (undefined1 *)&puStack_854;
      uStack_858 = &DAT_007cc338;
      basic_string<>();
      uStack_858 = (undefined *)0x41f198;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_238,pcVar2);
      break;
    case 4:
      local_3dc = (undefined1 *)&uStack_84c;
      puStack_850 = &DAT_007cc348;
      puStack_854 = (undefined *)0x41f1e7;
      basic_string<>();
      puStack_850 = (undefined *)0x41f1f2;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_238,pcVar2);
      break;
    case 5:
      local_3e0 = (undefined1 *)&uStack_84c;
      puStack_850 = &DAT_007cc360;
      puStack_854 = (undefined *)0x41f241;
      basic_string<>();
      puStack_850 = (undefined *)0x41f24c;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_238,pcVar2);
      break;
    case 6:
      local_3e4 = (undefined1 *)&uStack_84c;
      puStack_850 = &DAT_007cc370;
      puStack_854 = (undefined *)0x41f29b;
      basic_string<>();
      puStack_850 = (undefined *)0x41f2a6;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_238,pcVar2);
      break;
    case 9:
      local_3e8 = (undefined1 *)&uStack_84c;
      puStack_850 = &DAT_007cc37c;
      puStack_854 = (undefined *)0x41f2f2;
      basic_string<>();
      puStack_850 = (undefined *)0x41f2fd;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_238,pcVar2);
    }
  }
  if (((in_stack_00000018 != 1) && (0x8c135f < local_5e0)) && (local_5e0 < 0x8c3a70)) {
    if ((local_5e0 < 0x8c1360) || (0x8c1369 < local_5e0)) {
      if ((0x8c1369 < local_5e0) && (local_5e0 < 0x8c139c)) {
        switch(local_5e0 % 10) {
        case 0:
        case 1:
        case 2:
        case 3:
          if ((local_5e0 % 10) / 2 == 0) {
            local_408 = (undefined1 *)((int)register0x00000010 + -0x848);
            uStack_84c = &DAT_007cc41c;
            puStack_850 = (undefined *)0x41f600;
            basic_string<>();
            uStack_84c = (undefined *)0x41f60b;
            FUN_00401c50();
          }
          else {
            local_40c = (undefined1 *)((int)register0x00000010 + -0x848);
            uStack_84c = &DAT_007cc424;
            puStack_850 = (undefined *)0x41f637;
            basic_string<>();
            uStack_84c = (undefined *)0x41f642;
            FUN_00401c50();
          }
          local_410 = (undefined1 *)&puStack_854;
          uStack_858 = &DAT_007cc434;
          basic_string<>();
          uStack_858 = (undefined *)0x41f6c5;
          pcVar2 = (char *)FUN_00401c50();
          _sprintf(local_238,pcVar2);
          break;
        case 4:
          local_414 = (undefined1 *)&uStack_84c;
          puStack_850 = &DAT_007cc448;
          puStack_854 = (undefined *)0x41f714;
          basic_string<>();
          puStack_850 = (undefined *)0x41f71f;
          pcVar2 = (char *)FUN_00401c50();
          _sprintf(local_238,pcVar2);
          break;
        case 5:
          local_418 = (undefined1 *)&uStack_84c;
          puStack_850 = &DAT_007cc460;
          puStack_854 = (undefined *)0x41f76e;
          basic_string<>();
          puStack_850 = (undefined *)0x41f779;
          pcVar2 = (char *)FUN_00401c50();
          _sprintf(local_238,pcVar2);
          break;
        case 6:
          local_41c = (undefined1 *)&uStack_84c;
          puStack_850 = &DAT_007cc470;
          puStack_854 = (undefined *)0x41f7c8;
          basic_string<>();
          puStack_850 = (undefined *)0x41f7d3;
          pcVar2 = (char *)FUN_00401c50();
          _sprintf(local_238,pcVar2);
          break;
        case 9:
          local_420 = (undefined1 *)&uStack_84c;
          puStack_850 = &DAT_007cc480;
          puStack_854 = (undefined *)0x41f81f;
          basic_string<>();
          puStack_850 = (undefined *)0x41f82a;
          pcVar2 = (char *)FUN_00401c50();
          _sprintf(local_238,pcVar2);
        }
      }
    }
    else {
      switch(local_5e0 % 10) {
      case 0:
      case 1:
      case 2:
      case 3:
        if ((local_5e0 % 10) / 2 == 0) {
          local_3ec = (undefined1 *)((int)register0x00000010 + -0x848);
          uStack_84c = &DAT_007cc394;
          puStack_850 = (undefined *)0x41f3b0;
          basic_string<>();
          uStack_84c = (undefined *)0x41f3bb;
          FUN_00401c50();
        }
        else {
          local_3f0 = (undefined1 *)((int)register0x00000010 + -0x848);
          uStack_84c = &DAT_007cc39c;
          puStack_850 = (undefined *)0x41f3e7;
          basic_string<>();
          uStack_84c = (undefined *)0x41f3f2;
          FUN_00401c50();
        }
        local_3f4 = (undefined1 *)&puStack_850;
        puStack_854 = &DAT_007cc3ac;
        uStack_858 = (undefined *)0x41f454;
        basic_string<>();
        puStack_854 = (undefined *)0x41f45f;
        pcVar2 = (char *)FUN_00401c50();
        _sprintf(local_238,pcVar2);
        break;
      case 4:
        local_3f8 = (undefined1 *)((int)register0x00000010 + -0x848);
        uStack_84c = &DAT_007cc3c0;
        puStack_850 = (undefined *)0x41f498;
        basic_string<>();
        uStack_84c = (undefined *)0x41f4a3;
        pcVar2 = (char *)FUN_00401c50();
        _sprintf(local_238,pcVar2);
        break;
      case 5:
        local_3fc = (undefined1 *)((int)register0x00000010 + -0x848);
        uStack_84c = &DAT_007cc3d8;
        puStack_850 = (undefined *)0x41f4dc;
        basic_string<>();
        uStack_84c = (undefined *)0x41f4e7;
        pcVar2 = (char *)FUN_00401c50();
        _sprintf(local_238,pcVar2);
        break;
      case 6:
        local_400 = (undefined1 *)((int)register0x00000010 + -0x848);
        uStack_84c = &DAT_007cc3e8;
        puStack_850 = (undefined *)0x41f520;
        basic_string<>();
        uStack_84c = (undefined *)0x41f52b;
        pcVar2 = (char *)FUN_00401c50();
        _sprintf(local_238,pcVar2);
        break;
      case 9:
        local_404 = (undefined1 *)((int)register0x00000010 + -0x848);
        uStack_84c = &DAT_007cc3f8;
        puStack_850 = (undefined *)0x41f561;
        basic_string<>();
        uStack_84c = (undefined *)0x41f56c;
        pcVar2 = (char *)FUN_00401c50();
        _sprintf(local_238,pcVar2);
      }
    }
  }
  if (((in_stack_00000018 != 1) && (0x8c3a6f < local_5e0)) && (local_5e0 < 9200000)) {
    switch(local_5e0 % 10) {
    case 0:
    case 1:
    case 2:
    case 3:
      if ((local_5e0 % 10) / 2 == 0) {
        local_424 = (undefined1 *)((int)register0x00000010 + -0x848);
        uStack_84c = &DAT_007cc4a4;
        puStack_850 = (undefined *)0x41f8c3;
        basic_string<>();
        uStack_84c = (undefined *)0x41f8ce;
        FUN_00401c50();
      }
      else {
        local_428 = (undefined1 *)((int)register0x00000010 + -0x848);
        uStack_84c = &DAT_007cc4ac;
        puStack_850 = (undefined *)0x41f8fa;
        basic_string<>();
        uStack_84c = (undefined *)0x41f905;
        FUN_00401c50();
      }
      local_42c = (undefined1 *)&puStack_850;
      puStack_854 = &DAT_007cc4bc;
      uStack_858 = (undefined *)0x41f967;
      basic_string<>();
      puStack_854 = (undefined *)0x41f972;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_238,pcVar2);
      break;
    case 4:
      local_430 = (undefined1 *)((int)register0x00000010 + -0x848);
      uStack_84c = &DAT_007cc4d0;
      puStack_850 = (undefined *)0x41f9ab;
      basic_string<>();
      uStack_84c = (undefined *)0x41f9b6;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_238,pcVar2);
      break;
    case 5:
      local_434 = (undefined1 *)((int)register0x00000010 + -0x848);
      uStack_84c = &DAT_007cc4ec;
      puStack_850 = (undefined *)0x41f9ef;
      basic_string<>();
      uStack_84c = (undefined *)0x41f9fa;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_238,pcVar2);
      break;
    case 6:
      local_438 = (undefined1 *)((int)register0x00000010 + -0x848);
      uStack_84c = &DAT_007cc4fc;
      puStack_850 = (undefined *)0x41fa33;
      basic_string<>();
      uStack_84c = (undefined *)0x41fa3e;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_238,pcVar2);
      break;
    case 9:
      local_43c = (undefined1 *)((int)register0x00000010 + -0x848);
      uStack_84c = &DAT_007cc50c;
      puStack_850 = (undefined *)0x41fa74;
      basic_string<>();
      uStack_84c = (undefined *)0x41fa7f;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_238,pcVar2);
    }
  }
  if (((in_stack_00000018 != 0) && (9899999 < local_5e0)) && (local_5e0 < 10000000)) {
    FUN_004706f0();
    local_8 = 0xd;
    FUN_004cbb30();
    _sprintf(local_238,"SysS%d[%s]");
    local_8 = local_8 & 0xffffff00;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_458);
  }
  if ((999999999 < local_5e0) && (local_5e0 < 1100000000)) {
    FUN_00471030();
    local_8 = 0xe;
    FUN_004cbc20();
    local_8._0_1_ = 0xf;
    FUN_004cbb30();
    FUN_004706f0();
    local_8._0_1_ = 0x10;
    FUN_004cbc20();
    local_8._0_1_ = 0x11;
    FUN_004cbb30();
    local_4cc = (undefined1 *)((int)register0x00000010 + -0x85c);
    basic_string<>(&DAT_007cc534);
    pcVar2 = (char *)FUN_00401c50();
    uStack_84c = (undefined *)0x41fcd5;
    _sprintf(local_238,pcVar2);
    local_8._0_1_ = 0x10;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4c8);
    local_8._0_1_ = 0xf;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4ac);
    local_8._0_1_ = 0xe;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_490);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_474);
  }
  if ((1099999999 < local_5e0) && (local_5e0 < 1200000000)) {
    FUN_00471030();
    local_8 = 0x12;
    FUN_004cbc20();
    local_8._0_1_ = 0x13;
    FUN_004cbb30();
    FUN_004706f0();
    local_8._0_1_ = 0x14;
    FUN_004cbc20();
    local_8._0_1_ = 0x15;
    FUN_004cbb30();
    local_540 = (undefined1 *)((int)register0x00000010 + -0x85c);
    basic_string<>(&DAT_007cc550);
    pcVar2 = (char *)FUN_00401c50();
    uStack_84c = (undefined *)0x41feaf;
    _sprintf(local_238,pcVar2);
    local_8._0_1_ = 0x14;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_53c);
    local_8._0_1_ = 0x13;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_520);
    local_8._0_1_ = 0x12;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_504);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4e8);
  }
  if ((1299999999 < local_5e0) && (local_5e0 < 1400000000)) {
    FUN_00471030();
    local_8 = 0x16;
    FUN_004cbc20();
    local_8._0_1_ = 0x17;
    FUN_004cbb30();
    FUN_004706f0();
    local_8._0_1_ = 0x18;
    FUN_004cbc20();
    local_8._0_1_ = 0x19;
    FUN_004cbb30();
    local_5b4 = (undefined1 *)((int)register0x00000010 + -0x85c);
    basic_string<>(&DAT_007cc56c);
    pcVar2 = (char *)FUN_00401c50();
    uStack_84c = (undefined *)0x420089;
    _sprintf(local_238,pcVar2);
    local_8._0_1_ = 0x18;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_5b0);
    local_8._0_1_ = 0x17;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_594);
    local_8._0_1_ = 0x16;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_578);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_55c);
  }
  basic_string<>();
  local_8 = 0x1a;
  local_5b8 = (undefined1 *)&uStack_858;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_858,
             local_28c);
  FUN_0041be20();
  local_8._0_1_ = 0x1b;
  FUN_004cbb30();
  FUN_004fd700();
  local_8._0_1_ = 0x1a;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_5d4);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_28c)
  ;
LAB_00420174:
  basic_string<>();
  local_8 = 0x1c;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1,local_30);
  local_8 = local_8 & 0xffffff00;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_30);
  ExceptionList = local_10;
  return param_1;
}

