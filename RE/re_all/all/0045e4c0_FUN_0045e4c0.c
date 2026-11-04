
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __fastcall FUN_0045e4c0(char *param_1)

{
  uint uVar1;
  char cVar2;
  uint *puVar3;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  undefined4 uStack_474;
  char *pcStack_470;
  undefined1 auStack_46c [12];
  undefined4 uStack_460;
  int iStack_45c;
  undefined1 *puStack_454;
  undefined4 uStack_450;
  undefined4 uStack_44c;
  undefined4 uStack_448;
  undefined1 *puStack_444;
  int iStack_440;
  undefined *puStack_43c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_438;
  undefined4 uStack_434;
  undefined4 uStack_430;
  undefined4 uStack_42c;
  undefined4 uStack_428;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_35c [28];
  undefined1 *local_340;
  undefined1 *local_33c;
  undefined1 *local_338;
  undefined1 *local_334;
  undefined1 *local_330;
  undefined1 *local_32c;
  undefined1 *local_328;
  undefined1 *local_324;
  undefined1 *local_320;
  undefined1 *local_31c;
  undefined1 local_315;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_30c [44];
  undefined4 local_2e0;
  undefined1 local_2c9;
  undefined1 *local_2c0;
  undefined1 *local_2bc;
  undefined1 *local_2b8;
  undefined1 *local_2b4;
  undefined1 *local_2b0;
  undefined1 local_2a9;
  undefined1 *local_2a8;
  undefined1 *local_2a4;
  undefined1 *local_2a0;
  undefined1 *local_29c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_298 [28];
  undefined1 *local_27c;
  char local_278 [512];
  int local_78;
  int local_74;
  undefined4 local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3c [28];
  undefined4 local_20;
  undefined *local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007adf9c;
  local_10 = ExceptionList;
  local_20 = DAT_0084b484;
  local_14 = 0xffffffff;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  puVar3 = (uint *)FUN_004ce990();
  if ((*puVar3 & 0x100) == 0) {
    FUN_004cc4c0();
    FUN_004cb840();
  }
  else {
    uStack_428 = 0;
    uStack_42c = 1;
    uStack_430 = DAT_00a17eb8;
    uStack_434 = *(undefined4 *)(param_1 + 0x18);
    pbStack_438 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                   (param_1 + 0x14);
    puStack_43c = (undefined *)0x0;
    iStack_440 = 0x45e55f;
    pbVar4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             FUN_004cc4c0();
    local_27c = (undefined1 *)&puStack_454;
    iStack_45c = 0x45e570;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&puStack_454,
               pbVar4);
    iStack_45c = 0x45e582;
    FUN_00424670();
    local_8._0_1_ = 1;
    FUN_004cb840();
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_298);
  }
  iVar5 = FUN_004cbbc0();
  if (iVar5 == DAT_007d0624) {
    FUN_004e9510();
    puVar6 = (undefined4 *)FUN_004ccca0();
    local_70 = *puVar6;
    FUN_004ce060();
    cVar2 = const_iterator__operator__();
    if (cVar2 != '\0') {
      local_315 = 1;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3c);
      ExceptionList = local_10;
      return local_315;
    }
    iVar5 = FUN_004d07e0();
    local_14 = *(int *)(iVar5 + 0x1c) + 500000;
  }
  else {
    if (*param_1 == '\0') {
      local_29c = (undefined1 *)&uStack_434;
      pbStack_438 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    &DAT_007cf5e4;
      puStack_43c = (undefined *)0x45e61b;
      basic_string<>();
      local_8._0_1_ = 2;
      local_2a0 = (undefined1 *)&uStack_450;
      puStack_454 = (undefined1 *)&uStack_450;
      FUN_00438b60();
      local_8._0_1_ = 3;
      local_2a8 = auStack_46c;
      pcStack_470 = &DAT_007cf5e8;
      uStack_474 = 0x45e670;
      basic_string<>();
      pcStack_470 = (char *)0x45e67b;
      pcStack_470 = (char *)FUN_00401c50();
      uStack_474 = 0x45e69b;
      local_2a4 = auStack_46c;
      basic_string<>();
      local_8 = (uint)local_8._1_3_ << 8;
      pcStack_470 = (char *)0x45e6aa;
      FUN_0042bed0();
      local_2a9 = 1;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3c);
      ExceptionList = local_10;
      return local_2a9;
    }
    if (DAT_00a117a8 == 1) {
      local_2b0 = (undefined1 *)&uStack_434;
      pbStack_438 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    &uStack_434;
      puStack_43c = (undefined *)0x45e6ec;
      FUN_00438b60();
      local_8._0_1_ = 4;
      local_2b8 = (undefined1 *)&uStack_450;
      puStack_454 = &DAT_007cf62c;
      basic_string<>();
      puStack_454 = (undefined1 *)0x45e725;
      puStack_454 = (undefined1 *)FUN_00401c50();
      local_2b4 = (undefined1 *)&uStack_450;
      basic_string<>();
      local_8._0_1_ = 5;
      local_2c0 = auStack_46c;
      pcStack_470 = &DAT_007cf658;
      uStack_474 = 0x45e770;
      basic_string<>();
      pcStack_470 = (char *)0x45e77b;
      pcStack_470 = (char *)FUN_00401c50();
      uStack_474 = 0x45e79b;
      local_2bc = auStack_46c;
      basic_string<>();
      local_8 = (uint)local_8._1_3_ << 8;
      pcStack_470 = (char *)0x45e7aa;
      FUN_0042bed0();
    }
    FUN_004e9510();
    puVar6 = (undefined4 *)FUN_004ccca0();
    local_44 = *puVar6;
    FUN_004ce060();
    cVar2 = const_iterator__operator__();
    if (cVar2 == '\0') {
      iVar5 = FUN_004d07e0();
      local_48 = *(int *)(iVar5 + 0x1c);
    }
    else {
      local_50 = FUN_004cfab0();
      FUN_004cfab0();
      FUN_004cbb30();
      uStack_428 = 0x45e821;
      local_4c = FUN_004a5a90();
      if (local_4c == -1) {
        local_2c9 = 1;
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3c);
        ExceptionList = local_10;
        return local_2c9;
      }
      local_54 = 0;
      while (iVar5 = FUN_004cfab0(), local_54 < iVar5) {
        FUN_004ce850();
        local_8._0_1_ = 6;
        FUN_004cd3f0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_004ce950();
        local_54 = local_54 + 1;
      }
      local_58 = local_50;
      while (iVar5 = FUN_004cfab0(), local_58 < iVar5) {
        for (local_5c = 0; local_5c < 100; local_5c = local_5c + 1) {
          local_2e0 = 0;
          FUN_004cde80();
          FUN_004ce160();
        }
        local_58 = local_58 + 1;
      }
      local_60 = 0;
      while (iVar5 = FUN_004cfab0(), local_60 < iVar5) {
        FUN_004cc150();
        local_8._0_1_ = 7;
        FUN_004cdec0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_004cc250();
        local_60 = local_60 + 1;
      }
      local_64 = local_50;
      while (iVar5 = FUN_004cfab0(), local_64 < iVar5) {
        for (local_68 = 0; local_68 < 5; local_68 = local_68 + 1) {
          basic_string<>();
          local_8._0_1_ = 8;
          FUN_004cde80();
          FUN_004cc500();
          local_8 = (uint)local_8._1_3_ << 8;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_30c);
        }
        local_64 = local_64 + 1;
      }
      piVar7 = (int *)FUN_004cc680();
      *piVar7 = local_50;
      for (local_6c = local_50; local_6c < local_50 + local_4c; local_6c = local_6c + 1) {
        FUN_004cfb40();
        piVar7 = (int *)FUN_004cc680();
        *piVar7 = local_6c;
      }
      local_48 = local_50;
    }
    local_14 = local_48 + 500000;
    if (*(int *)(param_1 + 0x18) != -1) {
      iVar5 = FUN_004cfb40();
      *(int *)(param_1 + 0x808) = iVar5 + 0x30;
    }
    FUN_00436d00();
  }
  if (500 < *(int *)(param_1 + 4)) {
    local_31c = (undefined1 *)&uStack_434;
    pbStack_438 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  &DAT_007cf6b7;
    puStack_43c = (undefined *)0x45eb3f;
    basic_string<>();
    local_8._0_1_ = 9;
    local_320 = (undefined1 *)&uStack_450;
    puStack_454 = (undefined1 *)&uStack_450;
    FUN_00438b60();
    local_8._0_1_ = 10;
    local_328 = auStack_46c;
    pcStack_470 = &DAT_007cf6b8;
    uStack_474 = 0x45eb94;
    basic_string<>();
    pcStack_470 = (char *)0x45eb9f;
    pcStack_470 = (char *)FUN_00401c50();
    uStack_474 = 0x45ebbf;
    local_324 = auStack_46c;
    basic_string<>();
    local_8 = (uint)local_8._1_3_ << 8;
    pcStack_470 = (char *)0x45ebce;
    FUN_0042bed0();
  }
  local_18 = 0;
  local_74 = 0;
  while (puVar3 = (uint *)FUN_004ce990(), local_74 < (int)(*puVar3 & 0xf)) {
    FUN_004ce990();
    FUN_00487080();
    uStack_428 = 0x45ec53;
    FUN_00438f70();
    local_18 = local_18 + 1;
    local_74 = local_74 + 1;
  }
  local_78 = 0;
  while (puVar3 = (uint *)FUN_004ce990(), local_78 < (int)(*puVar3 & 0xf0) >> 4) {
    puVar3 = (uint *)FUN_004ce990();
    uVar1 = *puVar3;
    uStack_428 = 0x45ecd9;
    FUN_0047eca0();
    uVar8 = FUN_004fe844();
    if (((int)(uVar1 & 0xff000) >> 0xc & uVar8) == 0) {
      local_334 = (undefined1 *)&pbStack_438;
      puStack_43c = (undefined *)0x0;
      iStack_440 = local_18 + 3;
      puStack_444 = (undefined1 *)0x45edb7;
      puVar6 = (undefined4 *)FUN_004ce990();
      iStack_440 = *puVar6;
      uStack_448 = 0x45edc6;
      puStack_444 = (undefined1 *)&pbStack_438;
      FUN_00487160();
      puStack_43c = &DAT_00e4e1c5 + local_78 + (local_14 % 100000) * 100;
      iStack_440 = 0x45edef;
      FUN_0043a2c0();
    }
    else {
      local_32c = (undefined1 *)&pbStack_438;
      puStack_43c = (undefined *)0x0;
      iStack_440 = 0;
      puStack_444 = (undefined1 *)0x0;
      uStack_448 = 0;
      uStack_44c = 0;
      uStack_450 = *(undefined4 *)(param_1 + 0x10);
      puStack_454 = *(undefined1 **)(param_1 + 0x18);
      iStack_45c = local_78 + 1;
      uStack_460 = 0x45ed39;
      pbVar4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               FUN_004cc4c0();
      local_330 = (undefined1 *)&uStack_474;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_474,
                 pbVar4);
      FUN_00424670(&pbStack_438);
      puStack_43c = &DAT_00e4e1c5 + local_78 + (local_14 % 100000) * 100;
      iStack_440 = 0x45ed8e;
      FUN_0043a2c0();
    }
    local_18 = local_18 + 1;
    local_78 = local_78 + 1;
  }
  local_40 = FUN_004cfb40();
  *(int *)(param_1 + 0x82c) = local_14 % 500000;
  FUN_004d21c0();
  uStack_428 = 0;
  uStack_42c = 0x45ee6a;
  FUN_004d2250();
  uStack_428 = 0x45ee71;
  FUN_0044ecd0();
  iVar5 = *(int *)(param_1 + 4);
  iVar9 = FUN_004d2250();
  *(int *)(iVar9 + 4) = iVar5 + 1;
  pcVar10 = (char *)FUN_004d2250();
  *pcVar10 = *param_1;
  local_1c = (undefined *)0x0;
  puVar3 = (uint *)FUN_004ce990();
  if (((*puVar3 & 0x1000000) != 0) && (iVar5 = FUN_004cfb40(), *(int *)(iVar5 + 0xbcc) != -1)) {
    puVar6 = (undefined4 *)FUN_004ce990();
    local_1c = (undefined *)*puVar6;
    if (((int)local_1c < 1600000) || (1699999 < (int)local_1c)) {
      if (((int)local_1c < 1100000) || (1199999 < (int)local_1c)) {
        if ((0x8c3a6f < (int)local_1c) && ((int)local_1c < 9200000)) {
          local_1c = &DAT_008adae0 + (int)local_1c % 10 + *(int *)(param_1 + 0x14) * 10;
        }
      }
      else {
        if (*(int *)(param_1 + 0x14) == -1) {
          local_338 = (undefined1 *)&pbStack_438;
          puStack_43c = &DAT_007cf700;
          iStack_440 = 0x45ef8d;
          basic_string<>();
          puStack_43c = (undefined *)0x45ef98;
          pcVar10 = (char *)FUN_00401c50();
          uStack_428 = 0x45efb4;
          _sprintf(local_278,pcVar10);
          local_33c = (undefined1 *)&uStack_434;
          pbStack_438 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )&DAT_007cf755;
          puStack_43c = (undefined *)0x45efcc;
          basic_string<>();
          local_8._0_1_ = 0xb;
          pbStack_438 = local_35c;
          puStack_43c = (undefined *)0x45efee;
          FUN_00438b60();
          local_8._0_1_ = 0xc;
          pbStack_438 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x45f012;
          puStack_454 = (undefined1 *)FUN_004cbb30();
          local_340 = (undefined1 *)&uStack_450;
          basic_string<>();
          local_8._0_1_ = 0xd;
          pcStack_470 = local_278;
          uStack_474 = 0x45f050;
          basic_string<>();
          local_8._0_1_ = 0xe;
          pcStack_470 = (char *)0x45f05f;
          FUN_0042bed0();
          local_8 = (uint)local_8._1_3_ << 8;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_35c);
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3c);
          ExceptionList = local_10;
          return 1;
        }
        local_1c = (undefined *)(*(int *)(param_1 + 0x14) * 10 + 1000000 + (int)local_1c % 10);
      }
    }
    else {
      local_1c = &DAT_00e4e1c0 + (int)local_1c % 100 + *(int *)(param_1 + 0x18) * 100;
    }
    iVar9 = local_14 % 500000;
    iVar5 = FUN_004cfb40();
    *(undefined **)(param_1 + 0x8a0) = &DAT_00e4e1c0 + *(int *)(iVar5 + 0xbcc) + iVar9 * 100;
  }
  *(undefined **)(param_1 + 0x89c) = local_1c;
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3c);
  ExceptionList = local_10;
  return 1;
}

