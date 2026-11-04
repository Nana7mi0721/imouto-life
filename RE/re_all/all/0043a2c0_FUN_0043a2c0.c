
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
FUN_0043a2c0(int param_1,int param_2,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_3)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbVar7;
  int in_stack_00000024;
  undefined1 auStack_968 [20];
  undefined4 uStack_954;
  undefined1 *puStack_950;
  undefined1 auStack_94c [12];
  undefined4 uStack_940;
  undefined *puStack_93c;
  undefined4 uStack_938;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_930 [8];
  undefined4 uStack_928;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_7b0 [28];
  undefined1 *local_794;
  undefined1 *local_790;
  undefined1 *local_78c;
  undefined1 *local_788;
  undefined1 *local_784;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_780 [28];
  undefined1 *local_764;
  undefined1 *local_760;
  undefined1 *local_75c;
  undefined1 *local_758;
  undefined1 *local_754;
  undefined1 *local_750;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_74c [28];
  undefined1 *local_730;
  undefined1 *local_72c;
  undefined1 *local_728;
  undefined1 *local_724;
  undefined1 *local_720;
  undefined1 *local_71c;
  undefined1 *local_718;
  undefined1 *local_714;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_710 [28];
  undefined1 *local_6f4;
  undefined1 *local_6f0;
  undefined1 *local_6ec;
  undefined1 *local_6e8;
  undefined1 *local_6e4;
  undefined1 *local_6e0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_6dc [28];
  undefined1 *local_6c0;
  undefined1 *local_6bc;
  undefined1 *local_6b8;
  undefined1 *local_6b4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_6b0 [28];
  undefined1 *local_694;
  undefined1 *local_690;
  undefined1 *local_68c;
  undefined1 *local_688;
  undefined1 *local_684;
  undefined1 *local_680;
  undefined1 *local_67c;
  undefined1 *local_678;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_674 [28];
  undefined1 *local_658;
  undefined1 *local_654;
  char local_650 [256];
  char local_550 [260];
  int local_44c;
  int local_448;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *local_444;
  char local_440 [260];
  int local_33c;
  int local_338;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *local_334;
  undefined1 local_32d;
  undefined *local_32c;
  char local_328 [256];
  char local_228 [260];
  int local_124;
  int local_120;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *local_11c;
  char local_118 [256];
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007ad337;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_8 = 0;
  local_14 = DAT_00a17eb8;
  if (-1 < *(int *)(param_1 + 4)) {
    local_14 = *(undefined4 *)(param_1 + 4);
  }
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 4) = 0xffffffff;
  if ((param_2 < 1500000) || (1599999 < param_2)) {
    if ((param_2 < 15000000) || (15999999 < param_2)) {
      if ((param_2 < 4000000) && (2999999 < param_2)) {
        iVar4 = FUN_004cc430();
        if (iVar4 <= param_2 % 1000000) {
          FUN_004cc400();
        }
        uVar5 = FUN_004e5650();
        pbVar7 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)FUN_004cc4c0();
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::resize(pbVar7,uVar5);
        FUN_004cc4c0();
        FUN_004cb840();
      }
      else if ((param_2 < 9900000) || (9999999 < param_2)) {
        if ((param_2 < 1100000000) || (1199999999 < param_2)) {
          if ((param_2 < 9100000) || (0x8c3a6f < param_2)) {
            if ((param_2 < 1000000000) || (1099999999 < param_2)) {
              if ((param_2 < 1300000000) || (1399999999 < param_2)) {
                FUN_004cbb30();
                local_78c = (undefined1 *)&uStack_938;
                puStack_93c = &DAT_007ce7a8;
                uStack_940 = 0x43b1f9;
                basic_string<>();
                puStack_93c = (undefined *)0x43b204;
                pcVar3 = (char *)FUN_00401c50();
                uStack_928 = 0x43b220;
                _sprintf(local_650,pcVar3);
                local_790 = abStack_930;
                uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              *)0x43b238;
                basic_string<>();
                local_8._0_1_ = 0x17;
                uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              *)0x43b25a;
                FUN_00438b60();
                local_8._0_1_ = 0x18;
                puStack_950 = (undefined1 *)FUN_004cbb30();
                local_794 = auStack_94c;
                uStack_954 = 0x43b28f;
                basic_string<>();
                local_8._0_1_ = 0x19;
                basic_string<>(local_650);
                local_8._0_1_ = 0x1a;
                FUN_0042bed0();
                local_8 = (uint)local_8._1_3_ << 8;
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          (local_7b0);
                local_8 = 0xffffffff;
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3)
                ;
                ExceptionList = local_10;
                return;
              }
              local_44c = (param_2 % 1300000000) / 1000000;
              local_444 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)((param_2 % 1000000) / 100);
              local_448 = param_2 % 100;
              iVar4 = FUN_004717c0();
              if (iVar4 <= (int)local_444) {
                FUN_004779b0();
              }
              local_758 = abStack_930;
              uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            *)0x43b070;
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
              basic_string<char,std::char_traits<char>,std::allocator<char>_>
                        (abStack_930,
                         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                          *)&param_3);
              uStack_938 = local_444;
              puStack_93c = (undefined *)local_44c;
              uStack_940 = 0x43b095;
              cVar1 = FUN_00478010();
              if (cVar1 == '\0') {
                local_75c = abStack_930 + -4;
                uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              *)&DAT_007ce750;
                puStack_93c = (undefined *)0x43b0c3;
                basic_string<>();
                uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              *)0x43b0ce;
                pcVar3 = (char *)FUN_00401c50();
                _sprintf(local_550,pcVar3);
                local_760 = abStack_930;
                uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              *)0x43b104;
                basic_string<>();
                local_8._0_1_ = 0x13;
                uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              *)0x43b126;
                FUN_00438b60();
                local_8._0_1_ = 0x14;
                puStack_950 = (undefined1 *)FUN_004cbb30();
                local_764 = auStack_94c;
                uStack_954 = 0x43b15b;
                basic_string<>();
                local_8._0_1_ = 0x15;
                local_788 = auStack_968;
                basic_string<>(&DAT_007ce760);
                uVar2 = FUN_00401c50();
                local_784 = auStack_968;
                basic_string<>(uVar2);
                local_8._0_1_ = 0x16;
                FUN_0042bed0();
                local_8 = (uint)local_8._1_3_ << 8;
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          (local_780);
              }
            }
            else {
              local_33c = (param_2 % 1000000000) / 1000000;
              local_334 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)((param_2 % 1000000) / 100);
              local_338 = param_2 % 100;
              iVar4 = FUN_004717c0();
              if (iVar4 <= (int)local_334) {
                FUN_004779b0();
              }
              local_724 = abStack_930;
              uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            *)0x43ae60;
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
              basic_string<char,std::char_traits<char>,std::allocator<char>_>
                        (abStack_930,
                         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                          *)&param_3);
              uStack_938 = local_334;
              puStack_93c = (undefined *)local_33c;
              uStack_940 = 0x43ae85;
              cVar1 = FUN_00478010();
              if (cVar1 == '\0') {
                local_728 = abStack_930 + -4;
                uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              *)&DAT_007ce6fc;
                puStack_93c = (undefined *)0x43aeb3;
                basic_string<>();
                uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              *)0x43aebe;
                pcVar3 = (char *)FUN_00401c50();
                _sprintf(local_440,pcVar3);
                local_72c = abStack_930;
                uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              *)0x43aef4;
                basic_string<>();
                local_8._0_1_ = 0xf;
                uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              *)0x43af16;
                FUN_00438b60();
                local_8._0_1_ = 0x10;
                puStack_950 = (undefined1 *)FUN_004cbb30();
                local_730 = auStack_94c;
                uStack_954 = 0x43af4b;
                basic_string<>();
                local_8._0_1_ = 0x11;
                local_754 = auStack_968;
                basic_string<>(&DAT_007ce708);
                uVar2 = FUN_00401c50();
                local_750 = auStack_968;
                basic_string<>(uVar2);
                local_8._0_1_ = 0x12;
                FUN_0042bed0();
                local_8 = (uint)local_8._1_3_ << 8;
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          (local_74c);
              }
            }
          }
          else {
            local_32d = 0;
            if (param_2 < 0x8c1360) {
              iVar4 = FUN_0046f600();
              if (iVar4 != -1) {
                FUN_0046f600();
                local_32c = (undefined *)FUN_004d2a00();
                if (param_2 % 10 == 9) {
                  local_720 = abStack_930;
                  uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                *)0x43ad9a;
                  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                  basic_string<char,std::char_traits<char>,std::allocator<char>_>
                            (abStack_930,
                             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                              *)&param_3);
                  FUN_004787b0();
                  DAT_00a141f8 = 1;
                }
              }
            }
            else {
              if ((param_2 % 0x8c1360) / 10 == 0) {
                local_32c = &DAT_00a14438;
              }
              else {
                iVar4 = FUN_004d25e0();
                if (iVar4 < (param_2 % 0x8c1360) / 10) {
                  local_8 = 0xffffffff;
                  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            (&param_3);
                  ExceptionList = local_10;
                  return;
                }
                local_32c = (undefined *)FUN_004d2620();
              }
              if (param_2 % 10 == 9) {
                local_71c = abStack_930;
                uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              *)0x43acf7;
                std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                basic_string<char,std::char_traits<char>,std::allocator<char>_>
                          (abStack_930,
                           (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                            *)&param_3);
                FUN_004787b0();
                DAT_00a141f8 = 1;
              }
            }
          }
        }
        else {
          local_124 = (param_2 % 1100000000) / 1000000;
          local_11c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      ((param_2 % 1000000) / 100);
          local_120 = param_2 % 100;
          if (in_stack_00000024 == 0) {
            iVar4 = FUN_004717c0();
            if (iVar4 <= (int)local_11c) {
              FUN_004779b0();
            }
            local_6b4 = abStack_930;
            uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          *)0x43a8f3;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
            basic_string<char,std::char_traits<char>,std::allocator<char>_>
                      (abStack_930,
                       (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)&param_3);
            uStack_938 = local_11c;
            puStack_93c = (undefined *)local_124;
            uStack_940 = 0x43a918;
            cVar1 = FUN_00478010();
            if (cVar1 == '\0') {
              local_6b8 = abStack_930 + -4;
              uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            *)&DAT_007ce658;
              puStack_93c = (undefined *)0x43a946;
              basic_string<>();
              uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            *)0x43a951;
              pcVar3 = (char *)FUN_00401c50();
              _sprintf(local_228,pcVar3);
              local_6bc = abStack_930;
              uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            *)0x43a987;
              basic_string<>();
              local_8._0_1_ = 7;
              uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            *)0x43a9a9;
              FUN_00438b60();
              local_8._0_1_ = 8;
              puStack_950 = (undefined1 *)FUN_004cbb30();
              local_6c0 = auStack_94c;
              uStack_954 = 0x43a9de;
              basic_string<>();
              local_8._0_1_ = 9;
              local_6e4 = auStack_968;
              basic_string<>(&DAT_007ce668);
              uVar2 = FUN_00401c50();
              local_6e0 = auStack_968;
              basic_string<>(uVar2);
              local_8._0_1_ = 10;
              FUN_0042bed0();
              local_8 = (uint)local_8._1_3_ << 8;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_6dc);
            }
          }
          else {
            iVar4 = FUN_004717c0();
            if (iVar4 <= (int)local_11c) {
              FUN_004779b0();
            }
            local_6e8 = abStack_930;
            uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          *)0x43aa9e;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
            basic_string<char,std::char_traits<char>,std::allocator<char>_>
                      (abStack_930,
                       (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)&param_3);
            uStack_938 = local_11c;
            puStack_93c = (undefined *)local_124;
            uStack_940 = 0x43aac1;
            cVar1 = FUN_00478010();
            if (cVar1 == '\0') {
              local_6ec = abStack_930 + -4;
              uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            *)&DAT_007ce6ac;
              puStack_93c = (undefined *)0x43aaef;
              basic_string<>();
              uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            *)0x43aafa;
              pcVar3 = (char *)FUN_00401c50();
              _sprintf(local_328,pcVar3);
              local_6f0 = abStack_930;
              uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            *)0x43ab30;
              basic_string<>();
              local_8._0_1_ = 0xb;
              uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            *)0x43ab52;
              FUN_00438b60();
              local_8._0_1_ = 0xc;
              puStack_950 = (undefined1 *)FUN_004cbb30();
              local_6f4 = auStack_94c;
              uStack_954 = 0x43ab87;
              basic_string<>();
              local_8._0_1_ = 0xd;
              local_718 = auStack_968;
              basic_string<>(&DAT_007ce6b8);
              uVar2 = FUN_00401c50();
              local_714 = auStack_968;
              basic_string<>(uVar2);
              local_8._0_1_ = 0xe;
              FUN_0042bed0();
              local_8 = (uint)local_8._1_3_ << 8;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_710);
            }
          }
        }
      }
      else {
        local_694 = abStack_930;
        uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     0x43a806;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  (abStack_930,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &param_3);
        uStack_938 = local_6b0;
        puStack_93c = (undefined *)0x43a82a;
        FUN_00440080();
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_6b0);
      }
    }
    else {
      if ((param_2 % 100 < 5) || (10 < param_2 % 100)) {
        local_680 = abStack_930 + -4;
        uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     &DAT_007ce618;
        puStack_93c = (undefined *)0x43a4a3;
        basic_string<>();
        uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     0x43a4ae;
        pcVar3 = (char *)FUN_00401c50();
        _sprintf(local_118,pcVar3);
        local_684 = abStack_930;
        uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     0x43a4e4;
        basic_string<>();
        local_8._0_1_ = 5;
        local_688 = auStack_94c;
        puStack_950 = auStack_94c;
        uStack_954 = 0x43a50b;
        FUN_00438b60();
        local_8._0_1_ = 6;
        local_690 = auStack_968;
        basic_string<>(&DAT_007ce624);
        uVar2 = FUN_00401c50();
        local_68c = auStack_968;
        basic_string<>(uVar2);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0042bed0();
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
        ExceptionList = local_10;
        return;
      }
      iVar4 = FUN_004cd340();
      if (iVar4 <= (param_2 % 1000000) / 100) {
        FUN_004cde50();
      }
      FUN_004cde80();
      iVar4 = FUN_004cc430();
      if (iVar4 <= param_2 % 100 + -5) {
        FUN_004cde80();
        FUN_004cc400();
      }
      FUN_004cde80();
      FUN_004cc4c0();
      uVar5 = FUN_004e5650();
      uVar6 = FUN_004e5650();
      if (uVar5 < uVar6) {
        uVar5 = FUN_004e5650();
        FUN_004cde80();
        pbVar7 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)FUN_004cc4c0();
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::resize(pbVar7,uVar5);
      }
      FUN_004cde80();
      FUN_004cc4c0();
      FUN_004cb840();
    }
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
  }
  else {
    if ((1499999 < param_2) && (param_2 < 1600000)) {
      local_654 = abStack_930;
      uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   0x43a36a;
      basic_string<>();
      local_8._0_1_ = 1;
      uStack_938 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   0x43a38c;
      FUN_00438b60();
      local_8._0_1_ = 2;
      puStack_950 = (undefined1 *)FUN_004cbb30();
      local_658 = auStack_94c;
      uStack_954 = 0x43a3c1;
      basic_string<>();
      local_8._0_1_ = 3;
      local_67c = auStack_968;
      basic_string<>(&DAT_007ce5d0);
      uVar2 = FUN_00401c50();
      local_678 = auStack_968;
      basic_string<>(uVar2);
      local_8._0_1_ = 4;
      FUN_0042bed0();
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_674);
    }
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
  }
  ExceptionList = local_10;
  return;
}

