
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_004190e0(undefined4 param_1,char *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbVar3;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_c46c [44];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_c440 [44];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_c414 [44];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_c3e8 [44];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_c3bc [44];
  undefined1 local_c390 [16];
  char local_c380 [50000];
  undefined4 local_30;
  uint local_2c;
  size_t local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007abc47;
  local_10 = ExceptionList;
  local_14 = 0x419102;
  local_30 = DAT_0084b484;
  ExceptionList = &local_10;
  FUN_004cd090();
  local_8 = 1;
  local_1c = 0;
  local_28 = _strlen(param_2);
  local_18 = 0;
  local_2c = 0;
  local_14 = 0;
  local_20 = 0;
  local_24 = 0;
  do {
    if (param_2[local_1c] == '\0') {
      if ((local_18 == 0) && (local_14 == 0)) {
        local_2c = local_2c - 1;
      }
      FUN_004cdc00(local_c390);
      local_8 = local_8 & 0xffffff00;
      FUN_004cdf30();
      ExceptionList = local_10;
      return param_1;
    }
    switch(param_2[local_1c]) {
    case '\n':
      switch(local_18) {
      case 1:
        local_c380[local_24] = '\n';
        local_24 = local_24 + 1;
        break;
      case 2:
        local_c380[local_24] = '\0';
        uVar1 = FUN_004cd340();
        if (uVar1 <= local_14) {
          uVar2 = FUN_004cc150();
          local_8._0_1_ = 8;
          FUN_004cdec0(uVar2);
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_004cc250();
          local_20 = local_14 + 1;
        }
        basic_string<>(local_c380);
        local_8._0_1_ = 9;
        pbVar3 = local_c440;
        FUN_004cde80(local_14);
        FUN_004cc500(pbVar3);
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_c440);
      case 0:
      case 3:
        local_24 = 0;
        uVar1 = FUN_004cd340();
        if (uVar1 <= local_14) {
          uVar2 = FUN_004cc150();
          local_8._0_1_ = 10;
          FUN_004cdec0(uVar2);
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_004cc250();
          local_20 = local_14 + 1;
        }
        FUN_004cde80(local_14);
        uVar1 = FUN_004cc430();
        if (uVar1 <= local_2c) {
          local_c380[local_24] = '\0';
          basic_string<>(local_c380);
          local_8._0_1_ = 0xb;
          pbVar3 = local_c46c;
          FUN_004cde80(local_14);
          FUN_004cc500(pbVar3);
          local_8 = CONCAT31(local_8._1_3_,1);
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_c46c);
        }
        local_2c = local_2c + 1;
        local_14 = 0;
        local_18 = 0;
      }
      break;
    default:
      if (local_18 == 0) {
        local_18 = 2;
        local_c380[local_24] = param_2[local_1c];
        local_24 = local_24 + 1;
      }
      else if ((0 < local_18) && (local_18 < 3)) {
        local_c380[local_24] = param_2[local_1c];
        local_24 = local_24 + 1;
      }
      break;
    case '\r':
      break;
    case '\"':
      if (local_18 == 0) {
        local_18 = 1;
      }
      else if (local_18 == 1) {
        if (param_2[local_1c + 1] == '\"') {
          if (param_2[local_1c + 1] == '\"') {
            local_c380[local_24] = '\"';
            local_1c = local_1c + 1;
            local_24 = local_24 + 1;
          }
        }
        else {
          local_c380[local_24] = '\0';
          uVar1 = FUN_004cd340();
          if (uVar1 <= local_14) {
            uVar2 = FUN_004cc150();
            local_8._0_1_ = 2;
            FUN_004cdec0(uVar2);
            local_8 = CONCAT31(local_8._1_3_,1);
            FUN_004cc250();
            local_20 = local_14 + 1;
          }
          basic_string<>(local_c380);
          local_8._0_1_ = 3;
          pbVar3 = local_c3bc;
          FUN_004cde80(local_14);
          FUN_004cc500(pbVar3);
          local_8 = CONCAT31(local_8._1_3_,1);
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_c3bc);
          local_24 = 0;
          local_18 = 3;
        }
      }
      break;
    case ',':
      switch(local_18) {
      case 0:
        local_c380[local_24] = '\0';
        uVar1 = FUN_004cd340();
        if (uVar1 <= local_14) {
          uVar2 = FUN_004cc150();
          local_8._0_1_ = 4;
          FUN_004cdec0(uVar2);
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_004cc250();
          local_20 = local_14 + 1;
        }
        basic_string<>(local_c380);
        local_8._0_1_ = 5;
        pbVar3 = local_c3e8;
        FUN_004cde80(local_14);
        FUN_004cc500(pbVar3);
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_c3e8);
        local_24 = 0;
        local_14 = local_14 + 1;
        break;
      case 1:
        local_c380[local_24] = ',';
        local_24 = local_24 + 1;
        break;
      case 2:
        local_c380[local_24] = '\0';
        uVar1 = FUN_004cd340();
        if (uVar1 <= local_14) {
          uVar2 = FUN_004cc150();
          local_8._0_1_ = 6;
          FUN_004cdec0(uVar2);
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_004cc250();
          local_20 = local_14 + 1;
        }
        basic_string<>(local_c380);
        local_8._0_1_ = 7;
        pbVar3 = local_c414;
        FUN_004cde80(local_14);
        FUN_004cc500(pbVar3);
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_c414);
        local_24 = 0;
        local_18 = 0;
        local_14 = local_14 + 1;
        break;
      case 3:
        local_18 = 0;
        local_14 = local_14 + 1;
      }
    }
    local_1c = local_1c + 1;
  } while( true );
}

