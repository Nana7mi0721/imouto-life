
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 __thiscall FUN_0047bc30(int param_1,int param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_2a4 [8];
  undefined4 uStack_29c;
  undefined *puStack_298;
  undefined *puStack_294;
  undefined4 uStack_290;
  undefined1 *puStack_28c;
  undefined1 auStack_288 [4];
  undefined4 uStack_284;
  undefined1 local_1da;
  undefined1 local_1c5;
  undefined1 local_1b1;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_188 [28];
  int local_16c;
  int local_168;
  int local_164;
  char local_160 [260];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_5c [28];
  void *local_40;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_3c [28];
  undefined4 local_20;
  size_t local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af1c3;
  local_10 = ExceptionList;
  local_20 = DAT_0084b484;
  if (param_3 == -1) {
    local_1b1 = 1;
  }
  else if (((param_2 < 2) && (DAT_0084b224 != 2)) && (DAT_0084b224 != 3)) {
    local_1b1 = 1;
  }
  else if (((param_2 == 2) && (DAT_0084b224 != 1)) && (DAT_0084b224 != 3)) {
    local_1b1 = 1;
  }
  else {
    ExceptionList = &local_10;
    if ((param_2 == 0) && (ExceptionList = &local_10, piVar2 = (int *)FUN_004ce990(), *piVar2 == 1))
    {
      local_1b1 = 0;
    }
    else if (param_3 < (int)(&DAT_00a14328)[param_2]) {
      if (param_2 == 0) {
        *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x124) + 1;
        iVar3 = FUN_004ce080();
        if (iVar3 <= param_3) {
          FUN_004717c0();
          FUN_004ce970();
        }
        puVar4 = (undefined4 *)FUN_004ce990();
        *puVar4 = *(undefined4 *)(param_1 + 0x124);
      }
      if (param_2 < 2) {
        FUN_00551400();
        FUN_005513d0();
      }
      else {
        FUN_00551400();
        FUN_005513d0();
      }
      piVar2 = (int *)FUN_004cc020();
      if (*piVar2 == 0) {
        uStack_284 = 0x47bdcb;
        FUN_0046ff30();
        local_8 = 0;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>(local_3c,local_5c);
        local_8._0_1_ = 1;
        FUN_004ec790();
        local_8._0_1_ = 2;
        FUN_004cb840();
        local_8._0_1_ = 1;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_188);
        FUN_004cbb30();
        local_14 = FUN_0052e3c0();
        if (local_14 == 0) {
          FUN_004cbb30();
          puStack_298 = &DAT_007d0bd8;
          uStack_29c = 0x47be77;
          basic_string<>();
          puStack_298 = (undefined *)0x47be82;
          pcVar5 = (char *)FUN_00401c50();
          uStack_284 = 0x47be9e;
          _sprintf(local_160,pcVar5);
          cVar1 = FUN_004ec750();
          if (cVar1 == '\0') {
            cVar1 = operator!=<>();
            if (cVar1 != '\0') {
              puStack_28c = auStack_288;
              uStack_290 = 0x47bfe2;
              FUN_00438b60();
              local_8._0_1_ = 5;
              basic_string<>();
              local_8._0_1_ = 6;
              basic_string<>(&DAT_007d0b5c);
              uVar6 = FUN_00401c50();
              basic_string<>(uVar6);
              local_8._0_1_ = 1;
              FUN_0042bed0();
            }
          }
          else {
            puStack_294 = &DAT_007d0b78;
            puStack_298 = (undefined *)0x47bedd;
            basic_string<>();
            puStack_294 = (undefined *)0x47bee8;
            pcVar5 = (char *)FUN_00401c50();
            _sprintf(local_160,pcVar5);
            puStack_28c = auStack_288;
            uStack_290 = 0x47bf18;
            FUN_00438b60();
            local_8._0_1_ = 3;
            basic_string<>();
            local_8._0_1_ = 4;
            basic_string<>(&DAT_007d0b5c);
            uVar6 = FUN_00401c50();
            basic_string<>(uVar6);
            local_8._0_1_ = 1;
            FUN_0042bed0();
          }
          local_1b1 = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_3c);
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_5c);
        }
        else {
          FUN_004cbb30();
          local_1c = FUN_0052c9a0();
          local_40 = _malloc(local_1c);
          FUN_0052cde0();
          thunk_FUN_00580b80();
          FUN_004cb840();
          if ((param_2 == 1) &&
             ((iVar3 = FUN_004cbbc0(), iVar3 != DAT_007d0624 ||
              (iVar3 = FUN_004cbbc0(), iVar3 != DAT_007d0624)))) {
            puStack_28c = auStack_288;
            uStack_290 = 0x47c143;
            FUN_00438b60();
            local_8._0_1_ = 7;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
            basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_2a4,local_5c);
            local_8._0_1_ = 8;
            basic_string<>(&DAT_007d0b14);
            uVar6 = FUN_00401c50();
            basic_string<>(uVar6);
            local_8._0_1_ = 1;
            FUN_0042bed0();
            _free(local_40);
            local_1c5 = 0;
            local_8 = (uint)local_8._1_3_ << 8;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                       local_3c);
            local_8 = 0xffffffff;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                       local_5c);
            local_1b1 = local_1c5;
          }
          else {
            local_18 = 1;
            if (param_2 == 2) {
              iVar3 = FUN_004cbbc0();
              if ((iVar3 != DAT_007d0624) || (iVar3 = FUN_004cbbc0(), iVar3 != DAT_007d0624)) {
                puStack_28c = auStack_288;
                uStack_290 = 0x47c265;
                FUN_00438b60();
                local_8._0_1_ = 9;
                puStack_28c = (undefined1 *)0x47c286;
                FUN_004cbb30();
                basic_string<>();
                local_8._0_1_ = 10;
                basic_string<>(&DAT_007d0adc);
                uVar6 = FUN_00401c50();
                basic_string<>(uVar6);
                local_8._0_1_ = 1;
                FUN_0042bed0();
                _free(local_40);
                local_8 = (uint)local_8._1_3_ << 8;
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            *)local_3c);
                local_8 = 0xffffffff;
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            *)local_5c);
                ExceptionList = local_10;
                return 0;
              }
              uVar6 = FUN_00563040();
              puVar4 = (undefined4 *)FUN_004cc020();
              *puVar4 = uVar6;
              FUN_004cc020();
              uVar6 = FUN_005611b0();
              FUN_004cc020();
              puVar4 = (undefined4 *)FUN_004cc020();
              *puVar4 = uVar6;
            }
            else {
              uVar6 = FUN_00563040();
              puVar4 = (undefined4 *)FUN_004cc020();
              *puVar4 = uVar6;
              FUN_004cc020();
              uVar6 = FUN_005611b0();
              FUN_004cc020();
              puVar4 = (undefined4 *)FUN_004cc020();
              *puVar4 = uVar6;
              FUN_004cc020();
              FUN_0047e980();
            }
            if (param_2 == 2) {
              *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + 1;
              while (0x1e < *(int *)(param_1 + 0x128)) {
                local_164 = 100000;
                local_168 = -1;
                local_16c = 0;
                while (iVar3 = FUN_004ce080(), local_16c < iVar3) {
                  piVar2 = (int *)FUN_004ce990();
                  if ((local_164 < *piVar2) && (piVar2 = (int *)FUN_004cc020(), *piVar2 != 0)) {
                    piVar2 = (int *)FUN_004ce990();
                    local_164 = *piVar2;
                    local_168 = local_16c;
                  }
                  local_16c = local_16c + 1;
                }
                if ((local_168 == -1) || (cVar1 = FUN_0047c760(), cVar1 == '\0')) break;
                *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + -1;
              }
            }
            _free(local_40);
            local_1da = 1;
            local_8 = (uint)local_8._1_3_ << 8;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                       local_3c);
            local_8 = 0xffffffff;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                       local_5c);
            local_1b1 = local_1da;
          }
        }
      }
      else {
        local_1b1 = 1;
      }
    }
    else {
      local_1b1 = 1;
    }
  }
  ExceptionList = local_10;
  return local_1b1;
}

