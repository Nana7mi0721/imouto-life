
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint __thiscall FUN_0043b320(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  uint *puVar4;
  char *_Format;
  uint uVar5;
  byte *pbVar6;
  undefined1 auStack_218 [20];
  undefined4 uStack_204;
  undefined4 uStack_200;
  undefined1 auStack_1fc [16];
  undefined4 uStack_1ec;
  undefined *puStack_1e8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_1e4;
  undefined1 auStack_1e0 [8];
  undefined4 uStack_1d8;
  int iStack_1d4;
  uint local_1b8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_160 [28];
  undefined1 *local_144;
  undefined1 *local_140;
  undefined1 *local_13c;
  undefined1 *local_138;
  undefined1 *local_134;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_130 [28];
  undefined1 *local_114;
  undefined1 *local_110;
  int local_10c;
  int local_108;
  int local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  undefined *local_e8;
  undefined1 local_e1;
  char local_e0 [200];
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pvVar1 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad383;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  if ((int)param_2 < 1000000000) {
    local_14 = DAT_00a17eb8;
    if (-1 < *(int *)(param_1 + 4)) {
      local_14 = *(int *)(param_1 + 4);
    }
    ExceptionList = &local_10;
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
    if ((1499999 < (int)param_2) && ((int)param_2 < 1600000)) {
      if ((1499999 < (int)param_2) && ((int)param_2 < 1600000)) {
        local_110 = auStack_1e0;
        pbStack_1e4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      &DAT_007ce808;
        puStack_1e8 = (undefined *)0x43b3d0;
        basic_string<>();
        local_8 = 0;
        pbStack_1e4 = local_130;
        puStack_1e8 = (undefined *)0x43b3f5;
        FUN_00438b60();
        local_8._0_1_ = 1;
        pbStack_1e4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x43b419;
        uStack_200 = FUN_004cbb30();
        local_114 = auStack_1fc;
        uStack_204 = 0x43b42a;
        basic_string<>();
        local_8._0_1_ = 2;
        local_138 = auStack_218;
        basic_string<>(&DAT_007ce810);
        uVar2 = FUN_00401c50();
        local_134 = auStack_218;
        basic_string<>(uVar2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0042bed0();
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_130);
      }
      ExceptionList = local_10;
      return 0;
    }
    if ((int)param_2 < 1000000) {
      ExceptionList = pvVar1;
      return param_2;
    }
    if (((999999 < (int)param_2) && ((int)param_2 < 1500000)) &&
       (iVar3 = FUN_004cd340(), local_14 < iVar3)) {
      FUN_004cde80();
      iVar3 = FUN_004cd340();
      if (((int)param_2 % 100000) / 10 < iVar3) {
        FUN_004cde80();
        FUN_004cde80();
        iVar3 = FUN_004ce080();
        if ((int)param_2 % 10 < iVar3) {
          iStack_1d4 = 0x43b5a0;
          FUN_004cde80();
          FUN_004cde80();
          puVar4 = (uint *)FUN_004ce990();
          ExceptionList = local_10;
          return *puVar4;
        }
      }
    }
    if (((14999999 < (int)param_2) && ((int)param_2 < 16000000)) &&
       (((int)param_2 % 100 < 5 || (9 < (int)param_2 % 100)))) {
      iVar3 = FUN_004cd340();
      if (((int)param_2 % 1000000) / 100 < iVar3) {
        FUN_004cde80();
        puVar4 = (uint *)FUN_004ce990();
        ExceptionList = local_10;
        return *puVar4;
      }
      ExceptionList = local_10;
      return 0;
    }
    if (((1999999 < (int)param_2) && ((int)param_2 < 3000000)) &&
       (iVar3 = FUN_004cd340(), (int)(param_2 - 2000000) / 100000 < iVar3)) {
      FUN_004cde80();
      iVar3 = FUN_004ce080();
      if ((int)param_2 % 100000 < iVar3) {
        FUN_004cde80();
        puVar4 = (uint *)FUN_004ce990();
        ExceptionList = local_10;
        return *puVar4;
      }
    }
    if ((2999999 < (int)param_2) && ((int)param_2 < 4000000)) {
      local_13c = (undefined1 *)&pbStack_1e4;
      puStack_1e8 = &DAT_007ce854;
      uStack_1ec = 0x43b73e;
      basic_string<>();
      puStack_1e8 = (undefined *)0x43b749;
      _Format = (char *)FUN_00401c50();
      iStack_1d4 = 0x43b765;
      _sprintf(local_e0,_Format);
      local_140 = auStack_1e0;
      pbStack_1e4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    &DAT_007ce888;
      puStack_1e8 = (undefined *)0x43b77d;
      basic_string<>();
      local_8 = 4;
      pbStack_1e4 = local_160;
      puStack_1e8 = (undefined *)0x43b7a2;
      FUN_00438b60();
      local_8._0_1_ = 5;
      pbStack_1e4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x43b7c6;
      uStack_200 = FUN_004cbb30();
      local_144 = auStack_1fc;
      uStack_204 = 0x43b7d7;
      basic_string<>();
      local_8._0_1_ = 6;
      basic_string<>(local_e0);
      local_8 = CONCAT31(local_8._1_3_,7);
      FUN_0042bed0();
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_160);
      ExceptionList = local_10;
      return 0xffffffff;
    }
    if ((7999999 < (int)param_2) && ((int)param_2 < 9000000)) {
      uVar5 = FUN_004174a0();
      ExceptionList = local_10;
      return uVar5 % ((int)param_2 % 8000000 + 1U);
    }
    if ((8999999 < (int)param_2) && ((int)param_2 < 9100000)) {
      uVar5 = FUN_0043f460();
      ExceptionList = local_10;
      return uVar5;
    }
    if (((int)param_2 < 9100000) || (0x8c135f < (int)param_2)) {
      if ((0x8c135f < (int)param_2) && ((int)param_2 < 0x8c3a70)) {
        if (((int)param_2 % 0x8c1360) / 10 == 0) {
          local_e8 = &DAT_00a14438;
        }
        else {
          iVar3 = FUN_004d25e0();
          if (iVar3 < ((int)param_2 % 0x8c1360) / 10) {
            ExceptionList = local_10;
            return 0xffffffff;
          }
          local_e8 = (undefined *)FUN_004d2620();
        }
        switch((int)param_2 % 10) {
        case 0:
          ExceptionList = local_10;
          return *(int *)(local_e8 + 0x28) / 2;
        case 1:
          ExceptionList = local_10;
          return *(int *)(local_e8 + 0x2c) / 2;
        case 2:
          ExceptionList = local_10;
          return *(uint *)(local_e8 + 0x28);
        case 3:
          ExceptionList = local_10;
          return *(uint *)(local_e8 + 0x2c);
        case 4:
          ExceptionList = local_10;
          return *(uint *)(local_e8 + 0xc4);
        case 5:
          pbVar6 = (byte *)FUN_004cd770();
          ExceptionList = local_10;
          return (uint)*pbVar6;
        case 6:
          ExceptionList = local_10;
          return (int)*(short *)(local_e8 + 0x48);
        }
      }
    }
    else {
      local_e1 = 0;
      iVar3 = FUN_0046f600();
      if ((iVar3 != -1) && ((int)param_2 % 10 < 10)) {
        switch((int)param_2 % 10) {
        case 0:
          FUN_0046f600();
          iVar3 = FUN_004d2a00();
          ExceptionList = local_10;
          return *(int *)(iVar3 + 0x28) / 2;
        case 1:
          FUN_0046f600();
          iVar3 = FUN_004d2a00();
          ExceptionList = local_10;
          return *(int *)(iVar3 + 0x2c) / 2;
        case 2:
          FUN_0046f600();
          iVar3 = FUN_004d2a00();
          ExceptionList = local_10;
          return *(uint *)(iVar3 + 0x28);
        case 3:
          FUN_0046f600();
          iVar3 = FUN_004d2a00();
          ExceptionList = local_10;
          return *(uint *)(iVar3 + 0x2c);
        case 4:
          FUN_0046f600();
          iVar3 = FUN_004d2a00();
          ExceptionList = local_10;
          return *(uint *)(iVar3 + 0xc4);
        case 5:
          FUN_0046f600();
          FUN_004d2a00();
          iVar3 = FUN_004cd730();
          if (iVar3 == 0) {
            local_1b8 = 0;
          }
          else {
            FUN_0046f600();
            FUN_004d2a00();
            pbVar6 = (byte *)FUN_004cd7c0();
            local_1b8 = (uint)*pbVar6;
          }
          ExceptionList = local_10;
          return local_1b8;
        case 6:
          FUN_0046f600();
          iVar3 = FUN_004d2a00();
          ExceptionList = local_10;
          return (int)*(short *)(iVar3 + 0x48);
        }
      }
    }
  }
  else {
    if ((999999999 < (int)param_2) && ((int)param_2 < 1100000000)) {
      iStack_1d4 = ((int)param_2 % 1000000000) / 1000000;
      local_f4 = ((int)param_2 % 1000000) / 100;
      local_ec = (int)param_2 % 100;
      uStack_1d8 = 0x43bcc8;
      ExceptionList = &local_10;
      local_f0 = iStack_1d4;
      uVar5 = FUN_0046f7f0();
      ExceptionList = local_10;
      return uVar5;
    }
    if ((1099999999 < (int)param_2) && ((int)param_2 < 1200000000)) {
      iStack_1d4 = ((int)param_2 % 1100000000) / 1000000;
      local_100 = ((int)param_2 % 1000000) / 100;
      local_f8 = (int)param_2 % 100;
      local_fc = iStack_1d4;
      if (param_4 != 0) {
        uStack_1d8 = 0x43bdad;
        ExceptionList = &local_10;
        uVar5 = FUN_0046f7f0();
        ExceptionList = local_10;
        return uVar5;
      }
      ExceptionList = &local_10;
      iVar3 = FUN_004717c0();
      if (iVar3 <= local_100) {
        FUN_004779b0();
      }
      iStack_1d4 = local_fc;
      uStack_1d8 = 0x43bd89;
      uVar5 = FUN_0046f7f0();
      ExceptionList = local_10;
      return uVar5;
    }
    if ((1299999999 < (int)param_2) && ((int)param_2 < 1400000000)) {
      iStack_1d4 = ((int)param_2 % 1300000000) / 1000000;
      local_10c = ((int)param_2 % 1000000) / 100;
      local_104 = (int)param_2 % 100;
      uStack_1d8 = 0x43be29;
      ExceptionList = &local_10;
      local_108 = iStack_1d4;
      uVar5 = FUN_0046f7f0();
      ExceptionList = local_10;
      return uVar5;
    }
  }
  ExceptionList = local_10;
  return 0;
}

