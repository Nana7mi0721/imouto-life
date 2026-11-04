
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_0041c530(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  undefined4 uStack_808;
  undefined *puStack_800;
  undefined *puStack_7fc;
  undefined4 uStack_7f8;
  undefined1 auStack_7ea [2];
  int local_520;
  int local_51c;
  int local_518;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_508 [28];
  undefined1 *local_4ec;
  undefined1 *local_4e8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_4e4 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_4c8 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_4ac [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_490 [28];
  undefined1 *local_474;
  undefined1 *local_470;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_46c [28];
  undefined1 *local_450;
  undefined1 *local_44c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_448 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_42c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_410 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3f4 [28];
  undefined1 *local_3d8;
  undefined1 *local_3d4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3d0 [28];
  undefined1 *local_3b4;
  undefined1 *local_3b0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3ac [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_390 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_374 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_358 [28];
  undefined1 *local_33c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_338 [28];
  undefined1 *local_31c;
  undefined1 *local_318;
  undefined1 *local_314;
  undefined1 *local_310;
  undefined1 *local_30c;
  undefined1 *local_308;
  undefined1 *local_304;
  undefined1 *local_300;
  undefined1 *local_2fc;
  undefined1 *local_2f8;
  undefined1 *local_2f4;
  undefined1 *local_2f0;
  undefined1 *local_2ec;
  undefined1 *local_2e8;
  undefined1 *local_2e4;
  undefined1 *local_2e0;
  undefined1 *local_2dc;
  undefined1 *local_2d8;
  undefined1 *local_2d4;
  undefined1 *local_2d0;
  undefined1 *local_2cc;
  undefined1 *local_2c8;
  undefined1 *local_2c4;
  undefined1 *local_2c0;
  undefined1 *local_2bc;
  undefined1 *local_2b8;
  undefined1 *local_2b4;
  undefined1 *local_2b0;
  undefined1 *local_2ac;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2a8 [28];
  undefined1 *local_28c;
  undefined1 *local_288;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_284 [28];
  undefined1 *local_268;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_264 [28];
  undefined1 *local_248;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_244 [28];
  undefined1 *local_228;
  undefined1 *local_224;
  undefined1 *local_220;
  undefined1 *local_21c;
  undefined1 *local_218;
  undefined1 *local_214;
  undefined1 *local_210;
  undefined1 *local_20c;
  undefined1 *local_208;
  undefined1 *local_204;
  undefined1 *local_200;
  undefined1 *local_1fc;
  undefined1 *local_1f8;
  undefined1 *local_1f4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_1f0 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_1d4 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_1b8 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_19c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_180 [28];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_164 [28];
  char local_148 [308];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ac03a;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  if (param_2 < -2000000000) {
    local_518 = -2000000000;
  }
  else {
    local_518 = param_2;
  }
  if (local_518 < 0x77359401) {
    if (param_2 < -2000000000) {
      local_520 = -2000000000;
    }
    else {
      local_520 = param_2;
    }
    local_51c = local_520;
  }
  else {
    local_51c = 2000000000;
  }
  ExceptionList = &local_10;
  __itoa(local_51c,local_148,10);
  basic_string<>();
  local_8 = 1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_164," = ");
  local_1f4 = auStack_7ea + -6;
  uStack_7f8 = (undefined *)0x41c61d;
  basic_string<>();
  pcVar2 = (char *)FUN_00401c50();
  _sprintf(local_148,pcVar2);
  if ((local_51c < 1000000) || (in_stack_00000018 != '\0')) {
    if (in_stack_00000018 == '\0') {
      uStack_7f8 = (undefined *)0x41c6b0;
      local_1fc = auStack_7ea + -6;
      basic_string<>();
      FUN_00401c50();
    }
    else {
      uStack_7f8 = (undefined *)0x41c679;
      local_1f8 = auStack_7ea + -6;
      basic_string<>();
      FUN_00401c50();
    }
    local_200 = auStack_7ea + -10;
    uStack_7f8 = &DAT_007cbc84;
    puStack_7fc = (undefined *)0x41c6ec;
    basic_string<>();
    uStack_7f8 = (undefined *)0x41c6f7;
    pcVar2 = (char *)FUN_00401c50();
    _sprintf(local_148,pcVar2);
    goto LAB_0041e50b;
  }
  if ((local_51c < 1000000) || (1099999 < local_51c)) {
    if ((1099999 < local_51c) && (local_51c < 0x10c8ea)) {
      local_208 = auStack_7ea + -10;
      uStack_7f8 = &DAT_007cbca8;
      puStack_7fc = (undefined *)0x41c7c3;
      basic_string<>();
      uStack_7f8 = (undefined *)0x41c7ce;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
    }
  }
  else {
    local_204 = (undefined1 *)&uStack_7f8;
    puStack_7fc = &DAT_007cbc94;
    puStack_800 = (undefined *)0x41c764;
    basic_string<>();
    puStack_7fc = (undefined *)0x41c76f;
    pcVar2 = (char *)FUN_00401c50();
    _sprintf(local_148,pcVar2);
  }
  if ((1599999 < local_51c) && (local_51c < 0x186a64)) {
    basic_string<>();
    local_8 = CONCAT31(local_8._1_3_,2);
    if (in_stack_0000001c == -10) {
      local_20c = auStack_7ea + -6;
      uStack_7f8 = (undefined *)0x41c84b;
      basic_string<>();
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
    }
    else if (in_stack_0000001c == -1) {
      local_210 = auStack_7ea + -10;
      uStack_7f8 = &DAT_007cbcf8;
      puStack_7fc = (undefined *)0x41c89b;
      basic_string<>();
      uStack_7f8 = (undefined *)0x41c8a6;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
    }
    else {
      if (in_stack_00000020 != 0) {
        FUN_004cfb40();
        FUN_004cb840();
        cVar1 = FUN_004cbb70();
        if (cVar1 == '\0') {
          FUN_004cbb30();
          local_214 = (undefined1 *)&uStack_7f8;
          puStack_7fc = &DAT_007cbd08;
          puStack_800 = (undefined *)0x41c93e;
          basic_string<>();
          puStack_7fc = (undefined *)0x41c949;
          pcVar2 = (char *)FUN_00401c50();
          _sprintf(local_148,pcVar2);
          goto LAB_0041c9b5;
        }
      }
      local_218 = auStack_7ea + -10;
      uStack_7f8 = &DAT_007cbd1c;
      puStack_7fc = (undefined *)0x41c98b;
      basic_string<>();
      uStack_7f8 = (undefined *)0x41c996;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
    }
LAB_0041c9b5:
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_180);
  }
  if ((14999999 < local_51c) && (local_51c < 16000000)) {
    iVar3 = (local_51c % 15000000) / 100;
    basic_string<>();
    local_8 = CONCAT31(local_8._1_3_,3);
    if (iVar3 == -10) {
      local_21c = auStack_7ea + -6;
      uStack_7f8 = (undefined *)0x41ca3a;
      basic_string<>();
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
    }
    else if (iVar3 == -1) {
      local_220 = (undefined1 *)&uStack_7f8;
      puStack_7fc = &DAT_007cbd64;
      puStack_800 = (undefined *)0x41caa0;
      basic_string<>();
      puStack_7fc = (undefined *)0x41caab;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
    }
    else {
      if ((in_stack_00000020 != 0) &&
         (uVar4 = FUN_004cfab0(), (uint)((local_51c % 15000000) / 100) < uVar4)) {
        FUN_004cfb40();
        FUN_004cb840();
        cVar1 = FUN_004cbb70();
        if (cVar1 == '\0') {
          FUN_004cbb30();
          local_224 = (undefined1 *)&puStack_7fc;
          puStack_800 = &DAT_007cbd74;
          basic_string<>();
          puStack_800 = (undefined *)0x41cb8b;
          pcVar2 = (char *)FUN_00401c50();
          _sprintf(local_148,pcVar2);
          goto LAB_0041cc0d;
        }
      }
      local_228 = (undefined1 *)&uStack_7f8;
      puStack_7fc = &DAT_007cbd88;
      puStack_800 = (undefined *)0x41cbe3;
      basic_string<>();
      puStack_7fc = (undefined *)0x41cbee;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
    }
LAB_0041cc0d:
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_19c);
  }
  if ((1999999 < local_51c) && (local_51c < 3000000)) {
    if ((local_51c % 2000000) / 100000 == 0) {
      FUN_004706f0();
      local_8._0_1_ = 4;
      FUN_004cbb30();
      local_248 = (undefined1 *)&uStack_7f8;
      puStack_7fc = &DAT_007cbd98;
      puStack_800 = (undefined *)0x41ccb5;
      basic_string<>();
      puStack_7fc = (undefined *)0x41ccc0;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_244);
    }
    else if ((local_51c % 2000000) / 100000 < 10) {
      FUN_004706f0();
      local_8._0_1_ = 5;
      FUN_004cbb30();
      local_268 = (undefined1 *)&puStack_7fc;
      puStack_800 = &DAT_007cbdb0;
      basic_string<>();
      puStack_800 = (undefined *)0x41cdab;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_264);
    }
  }
  if ((2999999 < local_51c) && (local_51c < 4000000)) {
    FUN_004706f0();
    local_8._0_1_ = 6;
    FUN_004cbb30();
    local_288 = (undefined1 *)&uStack_7f8;
    puStack_7fc = &DAT_007cbdc8;
    puStack_800 = (undefined *)0x41ce55;
    basic_string<>();
    puStack_7fc = (undefined *)0x41ce60;
    pcVar2 = (char *)FUN_00401c50();
    _sprintf(local_148,pcVar2);
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_284);
  }
  if ((7999999 < local_51c) && (local_51c < 9000000)) {
    local_28c = auStack_7ea + -10;
    uStack_7f8 = &DAT_007cbde4;
    puStack_7fc = (undefined *)0x41cec1;
    basic_string<>();
    uStack_7f8 = (undefined *)0x41cecc;
    pcVar2 = (char *)FUN_00401c50();
    _sprintf(local_148,pcVar2);
  }
  if ((8999999 < local_51c) && (local_51c < 9100000)) {
    FUN_004706f0();
    local_8._0_1_ = 7;
    FUN_004cbb30();
    local_2ac = (undefined1 *)&uStack_7f8;
    puStack_7fc = &DAT_007cbdf8;
    puStack_800 = (undefined *)0x41cf67;
    basic_string<>();
    puStack_7fc = (undefined *)0x41cf72;
    pcVar2 = (char *)FUN_00401c50();
    _sprintf(local_148,pcVar2);
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2a8);
  }
  if ((9099999 < local_51c) && (local_51c < 0x8c1360)) {
    switch(local_51c % 10) {
    case 0:
    case 1:
    case 2:
    case 3:
      if ((local_51c % 10) / 2 == 0) {
        local_2b0 = auStack_7ea + -6;
        uStack_7f8 = (undefined *)0x41d010;
        basic_string<>();
        FUN_00401c50();
      }
      else {
        local_2b4 = auStack_7ea + -6;
        uStack_7f8 = (undefined *)0x41d047;
        basic_string<>();
        FUN_00401c50();
      }
      local_2b8 = (undefined1 *)&puStack_7fc;
      puStack_800 = &DAT_007cbe60;
      basic_string<>();
      puStack_800 = (undefined *)0x41d0d5;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
      break;
    case 4:
      local_2bc = auStack_7ea + -10;
      uStack_7f8 = &DAT_007cbe78;
      puStack_7fc = (undefined *)0x41d124;
      basic_string<>();
      uStack_7f8 = (undefined *)0x41d12f;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
      break;
    case 5:
      local_2c0 = auStack_7ea + -10;
      uStack_7f8 = &DAT_007cbe8c;
      puStack_7fc = (undefined *)0x41d17e;
      basic_string<>();
      uStack_7f8 = (undefined *)0x41d189;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
      break;
    case 6:
      local_2c4 = auStack_7ea + -10;
      uStack_7f8 = &DAT_007cbea0;
      puStack_7fc = (undefined *)0x41d1d8;
      basic_string<>();
      uStack_7f8 = (undefined *)0x41d1e3;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
      break;
    case 9:
      local_2c8 = auStack_7ea + -10;
      uStack_7f8 = &DAT_007cbeb4;
      puStack_7fc = (undefined *)0x41d22f;
      basic_string<>();
      uStack_7f8 = (undefined *)0x41d23a;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
    }
  }
  if ((0x8c135f < local_51c) && (local_51c < 0x8c3a70)) {
    if ((local_51c < 0x8c1360) || (0x8c1369 < local_51c)) {
      if ((0x8c1369 < local_51c) && (local_51c < 0x8c139c)) {
        switch(local_51c % 10) {
        case 0:
        case 1:
        case 2:
        case 3:
          if ((local_51c % 10) / 2 == 0) {
            local_2e8 = auStack_7ea + -6;
            uStack_7f8 = (undefined *)0x41d533;
            basic_string<>();
            FUN_00401c50();
          }
          else {
            local_2ec = auStack_7ea + -6;
            uStack_7f8 = (undefined *)0x41d56a;
            basic_string<>();
            FUN_00401c50();
          }
          local_2f0 = (undefined1 *)&puStack_7fc;
          puStack_800 = &DAT_007cbfbc;
          basic_string<>();
          puStack_800 = (undefined *)0x41d5f8;
          pcVar2 = (char *)FUN_00401c50();
          _sprintf(local_148,pcVar2);
          break;
        case 4:
          local_2f4 = auStack_7ea + -10;
          uStack_7f8 = &DAT_007cbfd0;
          puStack_7fc = (undefined *)0x41d647;
          basic_string<>();
          uStack_7f8 = (undefined *)0x41d652;
          pcVar2 = (char *)FUN_00401c50();
          _sprintf(local_148,pcVar2);
          break;
        case 5:
          local_2f8 = auStack_7ea + -10;
          uStack_7f8 = &DAT_007cbfe0;
          puStack_7fc = (undefined *)0x41d6a1;
          basic_string<>();
          uStack_7f8 = (undefined *)0x41d6ac;
          pcVar2 = (char *)FUN_00401c50();
          _sprintf(local_148,pcVar2);
          break;
        case 6:
          local_2fc = auStack_7ea + -10;
          uStack_7f8 = &DAT_007cbff0;
          puStack_7fc = (undefined *)0x41d6fb;
          basic_string<>();
          uStack_7f8 = (undefined *)0x41d706;
          pcVar2 = (char *)FUN_00401c50();
          _sprintf(local_148,pcVar2);
          break;
        case 9:
          local_300 = auStack_7ea + -10;
          uStack_7f8 = &DAT_007cc000;
          puStack_7fc = (undefined *)0x41d752;
          basic_string<>();
          uStack_7f8 = (undefined *)0x41d75d;
          pcVar2 = (char *)FUN_00401c50();
          _sprintf(local_148,pcVar2);
        }
      }
    }
    else {
      switch(local_51c % 10) {
      case 0:
      case 1:
      case 2:
      case 3:
        if ((local_51c % 10) / 2 == 0) {
          local_2cc = auStack_7ea + -6;
          uStack_7f8 = (undefined *)0x41d2e3;
          basic_string<>();
          FUN_00401c50();
        }
        else {
          local_2d0 = auStack_7ea + -6;
          uStack_7f8 = (undefined *)0x41d31a;
          basic_string<>();
          FUN_00401c50();
        }
        local_2d4 = (undefined1 *)&uStack_7f8;
        puStack_7fc = &DAT_007cbf18;
        puStack_800 = (undefined *)0x41d387;
        basic_string<>();
        puStack_7fc = (undefined *)0x41d392;
        pcVar2 = (char *)FUN_00401c50();
        _sprintf(local_148,pcVar2);
        break;
      case 4:
        local_2d8 = auStack_7ea + -6;
        uStack_7f8 = (undefined *)0x41d3cb;
        basic_string<>();
        pcVar2 = (char *)FUN_00401c50();
        _sprintf(local_148,pcVar2);
        break;
      case 5:
        local_2dc = auStack_7ea + -6;
        uStack_7f8 = (undefined *)0x41d40f;
        basic_string<>();
        pcVar2 = (char *)FUN_00401c50();
        _sprintf(local_148,pcVar2);
        break;
      case 6:
        local_2e0 = auStack_7ea + -6;
        uStack_7f8 = (undefined *)0x41d453;
        basic_string<>();
        pcVar2 = (char *)FUN_00401c50();
        _sprintf(local_148,pcVar2);
        break;
      case 9:
        local_2e4 = auStack_7ea + -6;
        uStack_7f8 = (undefined *)0x41d494;
        basic_string<>();
        pcVar2 = (char *)FUN_00401c50();
        _sprintf(local_148,pcVar2);
      }
    }
  }
  if ((0x8c3a6f < local_51c) && (local_51c < 9200000)) {
    switch(local_51c % 10) {
    case 0:
    case 1:
    case 2:
    case 3:
      if ((local_51c % 10) / 2 == 0) {
        local_304 = auStack_7ea + -6;
        uStack_7f8 = (undefined *)0x41d7ec;
        basic_string<>();
        FUN_00401c50();
      }
      else {
        local_308 = auStack_7ea + -6;
        uStack_7f8 = (undefined *)0x41d823;
        basic_string<>();
        FUN_00401c50();
      }
      local_30c = (undefined1 *)&uStack_7f8;
      puStack_7fc = &DAT_007cc060;
      puStack_800 = (undefined *)0x41d890;
      basic_string<>();
      puStack_7fc = (undefined *)0x41d89b;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
      break;
    case 4:
      local_310 = auStack_7ea + -6;
      uStack_7f8 = (undefined *)0x41d8d4;
      basic_string<>();
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
      break;
    case 5:
      local_314 = auStack_7ea + -6;
      uStack_7f8 = (undefined *)0x41d918;
      basic_string<>();
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
      break;
    case 6:
      local_318 = auStack_7ea + -6;
      uStack_7f8 = (undefined *)0x41d95c;
      basic_string<>();
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
      break;
    case 9:
      local_31c = auStack_7ea + -6;
      uStack_7f8 = (undefined *)0x41d99d;
      basic_string<>();
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
    }
  }
  if ((9899999 < local_51c) && (local_51c < 10000000)) {
    FUN_004706f0();
    local_8._0_1_ = 8;
    FUN_004cbb30();
    local_33c = (undefined1 *)&uStack_7f8;
    puStack_7fc = &DAT_007cc0c0;
    puStack_800 = (undefined *)0x41da43;
    basic_string<>();
    puStack_7fc = (undefined *)0x41da4e;
    pcVar2 = (char *)FUN_00401c50();
    _sprintf(local_148,pcVar2);
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_338);
  }
  if ((999999999 < local_51c) && (local_51c < 1100000000)) {
    FUN_00471030();
    local_8._0_1_ = 9;
    FUN_004cbb30();
    FUN_004706f0();
    local_8._0_1_ = 10;
    FUN_004cbc20();
    local_8._0_1_ = 0xb;
    FUN_004cbb30();
    FUN_00470f50();
    local_8._0_1_ = 0xc;
    FUN_004cbb30();
    local_3b0 = (undefined1 *)&uStack_808;
    basic_string<>(&DAT_007cc0dc);
    pcVar2 = (char *)FUN_00401c50();
    uStack_7f8 = (undefined *)0x41dc2f;
    _sprintf(local_148,pcVar2);
    local_8._0_1_ = 0xb;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3ac);
    local_8._0_1_ = 10;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_390);
    local_8._0_1_ = 9;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_374);
    local_8._0_1_ = 1;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_358);
    basic_string<>();
    local_8._0_1_ = 0xd;
    local_3b4 = (undefined1 *)&puStack_800;
    uStack_808 = 0x41dcb3;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&puStack_800,
               local_1b8);
    uStack_808 = 0x41dcc5;
    FUN_0041be20();
    local_8._0_1_ = 0xe;
    FUN_004cbb30();
    FUN_004fd700();
    local_8 = CONCAT31(local_8._1_3_,0xd);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3d0);
    iVar3 = FUN_00470ee0();
    if (iVar3 == 1) {
      local_3d4 = auStack_7ea + -10;
      uStack_7f8 = &DAT_007cc110;
      puStack_7fc = (undefined *)0x41dd53;
      basic_string<>();
      uStack_7f8 = (undefined *)0x41dd5e;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
    }
    iVar3 = FUN_00470ee0();
    if (iVar3 == 2) {
      local_3d8 = auStack_7ea + -10;
      uStack_7f8 = &DAT_007cc11c;
      puStack_7fc = (undefined *)0x41ddc8;
      basic_string<>();
      uStack_7f8 = (undefined *)0x41ddd3;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
               local_1b8);
  }
  if ((1099999999 < local_51c) && (local_51c < 1200000000)) {
    FUN_00471030();
    local_8._0_1_ = 0xf;
    FUN_004cbb30();
    FUN_004706f0();
    local_8._0_1_ = 0x10;
    FUN_004cbc20();
    local_8._0_1_ = 0x11;
    FUN_004cbb30();
    FUN_00470f50();
    local_8._0_1_ = 0x12;
    FUN_004cbb30();
    local_44c = (undefined1 *)&uStack_808;
    basic_string<>(&DAT_007cc128);
    pcVar2 = (char *)FUN_00401c50();
    uStack_7f8 = (undefined *)0x41dfb4;
    _sprintf(local_148,pcVar2);
    local_8._0_1_ = 0x11;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_448);
    local_8._0_1_ = 0x10;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_42c);
    local_8._0_1_ = 0xf;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_410);
    local_8._0_1_ = 1;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3f4);
    basic_string<>();
    local_8._0_1_ = 0x13;
    local_450 = (undefined1 *)&puStack_800;
    uStack_808 = 0x41e038;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&puStack_800,
               local_1d4);
    uStack_808 = 0x41e04a;
    FUN_0041be20();
    local_8._0_1_ = 0x14;
    FUN_004cbb30();
    FUN_004fd700();
    local_8 = CONCAT31(local_8._1_3_,0x13);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_46c);
    iVar3 = FUN_00470ee0();
    if (iVar3 == 1) {
      local_470 = auStack_7ea + -10;
      uStack_7f8 = &DAT_007cc15c;
      puStack_7fc = (undefined *)0x41e0d8;
      basic_string<>();
      uStack_7f8 = (undefined *)0x41e0e3;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
    }
    iVar3 = FUN_00470ee0();
    if (iVar3 == 2) {
      local_474 = auStack_7ea + -10;
      uStack_7f8 = &DAT_007cc168;
      puStack_7fc = (undefined *)0x41e14d;
      basic_string<>();
      uStack_7f8 = (undefined *)0x41e158;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
               local_1d4);
  }
  if ((1299999999 < local_51c) && (local_51c < 1400000000)) {
    FUN_00471030();
    local_8._0_1_ = 0x15;
    FUN_004cbb30();
    FUN_004706f0();
    local_8._0_1_ = 0x16;
    FUN_004cbc20();
    local_8._0_1_ = 0x17;
    FUN_004cbb30();
    FUN_00470f50();
    local_8._0_1_ = 0x18;
    FUN_004cbb30();
    local_4e8 = (undefined1 *)&uStack_808;
    basic_string<>(&DAT_007cc174);
    pcVar2 = (char *)FUN_00401c50();
    uStack_7f8 = (undefined *)0x41e339;
    _sprintf(local_148,pcVar2);
    local_8._0_1_ = 0x17;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4e4);
    local_8._0_1_ = 0x16;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4c8);
    local_8._0_1_ = 0x15;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4ac);
    local_8._0_1_ = 1;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_490);
    basic_string<>();
    local_8._0_1_ = 0x19;
    local_4ec = (undefined1 *)&puStack_800;
    uStack_808 = 0x41e3bd;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&puStack_800,
               local_1f0);
    uStack_808 = 0x41e3cf;
    FUN_0041be20();
    local_8._0_1_ = 0x1a;
    FUN_004cbb30();
    FUN_004fd700();
    local_8 = CONCAT31(local_8._1_3_,0x19);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_508);
    iVar3 = FUN_00470ee0();
    if (iVar3 == 1) {
      uStack_7f8 = &DAT_007cc1a8;
      puStack_7fc = (undefined *)0x41e45d;
      basic_string<>();
      uStack_7f8 = (undefined *)0x41e468;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
    }
    iVar3 = FUN_00470ee0();
    if (iVar3 == 2) {
      uStack_7f8 = &DAT_007cc1b4;
      puStack_7fc = (undefined *)0x41e4d2;
      basic_string<>();
      uStack_7f8 = (undefined *)0x41e4dd;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_148,pcVar2);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
               local_1f0);
  }
LAB_0041e50b:
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_164,local_148);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )local_164);
  local_8 = local_8 & 0xffffff00;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_164)
  ;
  ExceptionList = local_10;
  return param_1;
}

