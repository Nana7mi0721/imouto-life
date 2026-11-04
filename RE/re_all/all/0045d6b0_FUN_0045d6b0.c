
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0045d6b0(undefined1 *param_1)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  uint *puVar4;
  uint uVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined4 uStack_a0c;
  char *pcStack_a08;
  undefined1 auStack_a04 [12];
  undefined4 uStack_9f8;
  int iStack_9f4;
  undefined4 uStack_9f0;
  char *pcStack_9ec;
  undefined4 uStack_9e8;
  undefined4 uStack_9e4;
  undefined4 uStack_9e0;
  undefined1 *puStack_9dc;
  undefined *puStack_9d8;
  undefined *puStack_9d4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_9d0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> abStack_9cc [8];
  undefined4 uStack_9c4;
  int local_90c;
  int local_908;
  int local_904;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_8d0 [28];
  undefined1 *local_8b4;
  undefined1 *local_8b0;
  undefined1 *local_8ac;
  undefined1 *local_8a8;
  undefined1 *local_8a4;
  undefined1 *local_8a0;
  undefined1 *local_89c;
  undefined1 *local_898;
  undefined1 *local_894;
  undefined1 *local_890;
  undefined1 *local_88c;
  char local_888 [512];
  CBitmapButton local_688 [88];
  char local_630 [512];
  char local_430 [512];
  int local_230;
  int local_22c;
  char local_228 [516];
  undefined4 local_24;
  undefined *local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007adefb;
  local_10 = ExceptionList;
  local_24 = DAT_0084b484;
  ExceptionList = &local_10;
  FUN_004ce990();
  local_14 = FUN_00487080();
  if (local_14 < 500000) {
    if (local_14 == -1) {
      local_14 = *(int *)(param_1 + 0x14);
    }
    iVar2 = FUN_0046f600();
    if (iVar2 != -1) {
      FUN_0046f600();
      FUN_004d2a00();
      iVar2 = FUN_004cf130();
      FUN_004ce990();
      iVar9 = FUN_00487080();
      if (iVar9 < iVar2) {
        FUN_004d21c0();
        FUN_004ce990();
        iVar2 = FUN_00487080();
        if (iVar2 < 0) {
          FUN_0046f600();
          FUN_004d2a00();
          FUN_004d2250();
          FUN_004cead0();
          FUN_0046f600();
          FUN_004d2a00();
          iVar2 = FUN_004cec90();
          if (iVar2 == 0) {
            FUN_0046d3c0();
            local_8 = 8;
            puVar7 = (undefined4 *)FUN_004ce990();
            *puVar7 = 0xffffffff;
            FUN_004d2250();
            FUN_004ced60();
            local_8 = 0xffffffff;
            CBitmapButton::~CBitmapButton(local_688);
          }
        }
        else {
          FUN_004ce990();
          FUN_00487080();
          FUN_0046f600();
          FUN_004d2a00();
          FUN_004cf170();
          FUN_004d2250();
          FUN_004cead0();
        }
        FUN_004d2250();
        uStack_9c4 = 0x45e1dc;
        FUN_004d2250();
        FUN_0044ecd0();
        ExceptionList = local_10;
        return 1;
      }
    }
    if (DAT_00a117a8 != 0) {
      FUN_004ce990();
      FUN_00487080();
      FUN_004ce990();
      FUN_00487080();
      puStack_9d8 = &DAT_007cf588;
      puStack_9dc = (undefined1 *)0x45e251;
      basic_string<>();
      puStack_9d8 = (undefined *)0x45e25c;
      pcVar3 = (char *)FUN_00401c50();
      uStack_9c4 = 0x45e278;
      _sprintf(local_888,pcVar3);
      pbStack_9d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    &DAT_007cf5bc;
      puStack_9d4 = (undefined *)0x45e290;
      basic_string<>();
      local_8 = 9;
      pcStack_9ec = local_888;
      uStack_9f0 = 0x45e2c0;
      basic_string<>();
      local_8 = CONCAT31(local_8._1_3_,10);
      pcStack_a08 = &DAT_007cf5c0;
      uStack_a0c = 0x45e2eb;
      basic_string<>();
      pcStack_a08 = (char *)0x45e2f6;
      pcStack_a08 = (char *)FUN_00401c50();
      uStack_a0c = 0x45e316;
      basic_string<>();
      local_8 = 0xffffffff;
      pcStack_a08 = (char *)0x45e328;
      FUN_0042bed0();
    }
  }
  else {
    if (599999 < local_14) {
      if (*(int *)(param_1 + 0x18) + -0x92824 + local_14 < 0) {
        local_904 = 0;
      }
      else {
        local_904 = *(int *)(param_1 + 0x18) + -0x92824 + local_14;
      }
      iVar2 = FUN_004cfab0();
      if (local_904 < iVar2 + -1) {
        if (*(int *)(param_1 + 0x18) + -0x92824 + local_14 < 0) {
          local_908 = 0;
        }
        else {
          local_908 = *(int *)(param_1 + 0x18) + -0x92824 + local_14;
        }
        local_90c = local_908;
      }
      else {
        local_90c = FUN_004cfab0();
        local_90c = local_90c + -1;
      }
      local_14 = local_90c + 500000;
    }
    iVar9 = local_14 % 500000;
    iVar2 = FUN_004cfab0();
    if (iVar9 < iVar2) {
      if (*(int *)(param_1 + 4) < 0x1f5) {
        local_1c = 0;
        local_22c = 0;
        while (puVar4 = (uint *)FUN_004ce990(), local_22c < (int)(*puVar4 & 0xf)) {
          FUN_004ce990();
          FUN_00487080();
          FUN_00438f70();
          local_1c = local_1c + 1;
          local_22c = local_22c + 1;
        }
        local_230 = 0;
        while (puVar4 = (uint *)FUN_004ce990(), local_230 < (int)(*puVar4 & 0xf0) >> 4) {
          puVar4 = (uint *)FUN_004ce990();
          uVar1 = *puVar4;
          FUN_0047eca0();
          uVar5 = FUN_004fe844();
          if (((int)(uVar1 & 0xff000) >> 0xc & uVar5) == 0) {
            local_8a8 = (undefined1 *)&pbStack_9d0;
            puStack_9d4 = (undefined *)0x0;
            puStack_9d8 = (undefined *)(local_1c + 3);
            puStack_9dc = (undefined1 *)0x45db39;
            puVar7 = (undefined4 *)FUN_004ce990();
            puStack_9d8 = (undefined *)*puVar7;
            uStack_9e0 = 0x45db48;
            puStack_9dc = (undefined1 *)&pbStack_9d0;
            FUN_00487160();
            puStack_9d4 = &DAT_00e4e1c5 + local_230 + (local_14 % 100000) * 100;
            puStack_9d8 = (undefined *)0x45db74;
            FUN_0043a2c0();
          }
          else {
            local_8a0 = (undefined1 *)&pbStack_9d0;
            puStack_9d4 = (undefined *)0x0;
            puStack_9d8 = (undefined *)0x0;
            puStack_9dc = (undefined1 *)0x0;
            uStack_9e0 = 0;
            uStack_9e4 = 0;
            uStack_9e8 = *(undefined4 *)(param_1 + 0x10);
            pcStack_9ec = *(char **)(param_1 + 0x18);
            uStack_9f0 = *(undefined4 *)(param_1 + 0x14);
            iStack_9f4 = local_230 + 1;
            uStack_9f8 = 0x45dab8;
            pbVar6 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )FUN_004cc4c0();
            local_8a4 = (undefined1 *)&uStack_a0c;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
            basic_string<char,std::char_traits<char>,std::allocator<char>_>
                      ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                       &uStack_a0c,pbVar6);
            FUN_00424670(&pbStack_9d0);
            puStack_9d4 = &DAT_00e4e1c5 + local_230 + (local_14 % 100000) * 100;
            puStack_9d8 = (undefined *)0x45db10;
            FUN_0043a2c0();
          }
          local_1c = local_1c + 1;
          local_230 = local_230 + 1;
        }
        local_18 = FUN_004cfb40();
        *(int *)(param_1 + 0x82c) = local_14 % 500000;
        FUN_004d21c0();
        uStack_9c4 = 0x45dbef;
        FUN_004d2250();
        FUN_0044ecd0();
        iVar2 = *(int *)(param_1 + 4);
        iVar9 = FUN_004d2250();
        *(int *)(iVar9 + 4) = iVar2 + 1;
        puVar8 = (undefined1 *)FUN_004d2250();
        *puVar8 = *param_1;
        local_20 = (undefined *)0x0;
        puVar4 = (uint *)FUN_004ce990();
        if (((*puVar4 & 0x1000000) != 0) && (iVar2 = FUN_004cfb40(), *(int *)(iVar2 + 0xbcc) != -1))
        {
          puVar7 = (undefined4 *)FUN_004ce990();
          local_20 = (undefined *)*puVar7;
          if (((int)local_20 < 1600000) || (1699999 < (int)local_20)) {
            if (((int)local_20 < 1100000) || (1199999 < (int)local_20)) {
              if ((0x8c3a6f < (int)local_20) && ((int)local_20 < 9200000)) {
                local_20 = &DAT_008adae0 + (int)local_20 % 10 + *(int *)(param_1 + 0x14) * 10;
              }
            }
            else {
              if (*(int *)(param_1 + 0x14) == -1) {
                local_8ac = (undefined1 *)&pbStack_9d0;
                puStack_9d4 = &DAT_007cf4e8;
                puStack_9d8 = (undefined *)0x45dd12;
                basic_string<>();
                puStack_9d4 = (undefined *)0x45dd1d;
                pcVar3 = (char *)FUN_00401c50();
                _sprintf(local_430,pcVar3);
                local_8b0 = abStack_9cc;
                pbStack_9d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)&DAT_007cf53d;
                puStack_9d4 = (undefined *)0x45dd51;
                basic_string<>();
                local_8 = 2;
                pbStack_9d0 = local_8d0;
                puStack_9d4 = (undefined *)0x45dd76;
                FUN_00438b60();
                local_8._0_1_ = 3;
                pbStack_9d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x45dd9a;
                pcStack_9ec = (char *)FUN_004cbb30();
                local_8b4 = (undefined1 *)&uStack_9e8;
                uStack_9f0 = 0x45ddab;
                basic_string<>();
                local_8._0_1_ = 4;
                pcStack_a08 = local_430;
                uStack_a0c = 0x45ddd8;
                basic_string<>();
                local_8 = CONCAT31(local_8._1_3_,5);
                pcStack_a08 = (char *)0x45dde7;
                FUN_0042bed0();
                local_8 = 0xffffffff;
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          (local_8d0);
                ExceptionList = local_10;
                return 1;
              }
              local_20 = (undefined *)(*(int *)(param_1 + 0x14) * 10 + 1000000 + (int)local_20 % 10)
              ;
            }
          }
          else {
            local_20 = &DAT_00e4e1c0 + (int)local_20 % 100 + *(int *)(param_1 + 0x18) * 100;
          }
          iVar9 = local_14 % 500000;
          iVar2 = FUN_004cfb40();
          *(undefined **)(param_1 + 0x8a0) = &DAT_00e4e1c0 + *(int *)(iVar2 + 0xbcc) + iVar9 * 100;
        }
        *(undefined **)(param_1 + 0x89c) = local_20;
      }
      else {
        FUN_004cfb40();
        FUN_004cbb30();
        local_88c = (undefined1 *)&puStack_9d4;
        puStack_9d8 = &DAT_007cf470;
        puStack_9dc = (undefined1 *)0x45d84c;
        basic_string<>();
        puStack_9d8 = (undefined *)0x45d857;
        pcVar3 = (char *)FUN_00401c50();
        uStack_9c4 = 0x45d873;
        _sprintf(local_228,pcVar3);
        local_890 = abStack_9cc;
        pbStack_9d0 = abStack_9cc;
        puStack_9d4 = (undefined *)0x45d887;
        FUN_00438b60();
        local_8 = 0;
        local_894 = (undefined1 *)&uStack_9e8;
        pcStack_9ec = local_228;
        uStack_9f0 = 0x45d8ba;
        basic_string<>();
        local_8 = CONCAT31(local_8._1_3_,1);
        local_89c = auStack_a04;
        pcStack_a08 = &DAT_007cf488;
        uStack_a0c = 0x45d8e5;
        basic_string<>();
        pcStack_a08 = (char *)0x45d8f0;
        pcStack_a08 = (char *)FUN_00401c50();
        uStack_a0c = 0x45d910;
        local_898 = auStack_a04;
        basic_string<>();
        local_8 = 0xffffffff;
        pcStack_a08 = (char *)0x45d922;
        FUN_0042bed0();
      }
    }
    else if (DAT_00a117a8 != 0) {
      FUN_004ce990();
      FUN_00487080();
      puStack_9d4 = &DAT_007cf540;
      puStack_9d8 = (undefined *)0x45def8;
      basic_string<>();
      puStack_9d4 = (undefined *)0x45df03;
      pcVar3 = (char *)FUN_00401c50();
      _sprintf(local_630,pcVar3);
      pbStack_9d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    &DAT_007cf56b;
      puStack_9d4 = (undefined *)0x45df37;
      basic_string<>();
      local_8 = 6;
      pcStack_9ec = local_630;
      uStack_9f0 = 0x45df67;
      basic_string<>();
      local_8 = CONCAT31(local_8._1_3_,7);
      pcStack_a08 = &DAT_007cf56c;
      uStack_a0c = 0x45df92;
      basic_string<>();
      pcStack_a08 = (char *)0x45df9d;
      pcStack_a08 = (char *)FUN_00401c50();
      uStack_a0c = 0x45dfbd;
      basic_string<>();
      local_8 = 0xffffffff;
      pcStack_a08 = (char *)0x45dfcf;
      FUN_0042bed0();
    }
  }
  ExceptionList = local_10;
  return 1;
}

