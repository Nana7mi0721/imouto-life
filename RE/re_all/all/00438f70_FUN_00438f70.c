
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00438f70(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined1 *puVar7;
  uint uVar8;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_a38 [20];
  undefined4 uStack_a24;
  char *pcStack_a20;
  undefined1 auStack_a1c [12];
  undefined4 uStack_a10;
  undefined *puStack_a0c;
  undefined *puStack_a08;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_a04;
  undefined1 auStack_a00 [8];
  undefined4 uStack_9f8;
  undefined2 local_90c;
  undefined2 local_908;
  int local_904;
  undefined2 local_8fc;
  undefined2 local_8f8;
  int local_8f4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_894 [28];
  undefined1 *local_878;
  undefined1 *local_874;
  undefined1 *local_870;
  undefined1 *local_86c;
  undefined1 *local_868;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_864 [28];
  undefined1 *local_848;
  undefined1 *local_844;
  undefined1 *local_840;
  undefined1 *local_83c;
  undefined1 *local_838;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_834 [28];
  undefined1 *local_818;
  undefined1 *local_814;
  undefined1 *local_810;
  undefined1 *local_80c;
  undefined1 *local_808;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_804 [28];
  undefined1 *local_7e8;
  undefined1 *local_7e4;
  undefined1 *local_7e0;
  undefined1 *local_7dc;
  undefined1 *local_7d8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_7d4 [28];
  undefined1 *local_7b8;
  undefined1 *local_7b4;
  undefined1 *local_7b0;
  undefined1 *local_7ac;
  undefined1 *local_7a8;
  undefined1 *local_7a4;
  undefined1 *local_7a0;
  undefined1 *local_79c;
  undefined1 *local_798;
  undefined1 *local_794;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_790 [28];
  undefined1 *local_774;
  undefined1 *local_770;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_76c [28];
  char local_750 [256];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_650 [260];
  int local_54c;
  int local_548;
  int local_544;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_540 [260];
  int local_43c;
  int local_438;
  int local_434;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_430 [256];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_330 [260];
  int local_22c;
  int local_228;
  int local_224;
  undefined1 local_21d;
  undefined *local_21c;
  char local_218 [512];
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad249;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  if (param_2 < 1000000000) {
    local_14 = DAT_00a17eb8;
    if (-1 < *(int *)(param_1 + 4)) {
      local_14 = *(int *)(param_1 + 4);
    }
    ExceptionList = &local_10;
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
    if ((param_2 < 1000000) || (1499999 < param_2)) {
      if ((param_2 < 15000000) || (15999999 < param_2)) {
        if ((param_2 < 2000000) || (2999999 < param_2)) {
          if ((param_2 < 9000000) || (9099999 < param_2)) {
            if ((9099999 < param_2) && (param_2 < 0x8c3a70)) {
              local_21d = 0;
              uVar1 = (undefined1)param_3;
              if (param_2 < 0x8c1360) {
                iVar3 = FUN_0046f600();
                if (iVar3 != -1) {
                  FUN_0046f600();
                  local_21c = (undefined *)FUN_004d2a00();
                  switch(param_2 % 10) {
                  case 0:
                    *(int *)((int)local_21c + 0x28) = param_3 << 1;
                    break;
                  case 1:
                    *(int *)((int)local_21c + 0x2c) = param_3 << 1;
                    break;
                  case 2:
                    *(int *)((int)local_21c + 0x28) = param_3;
                    break;
                  case 3:
                    *(int *)((int)local_21c + 0x2c) = param_3;
                    break;
                  case 4:
                    *(int *)((int)local_21c + 0xc4) = param_3;
                    break;
                  case 5:
                    puVar7 = (undefined1 *)FUN_004cd7c0();
                    *puVar7 = uVar1;
                    break;
                  case 6:
                    if (param_3 < 10) {
                      local_904 = param_3;
                    }
                    else {
                      local_904 = 9;
                    }
                    if (local_904 < 1) {
                      local_908 = 1;
                    }
                    else {
                      local_90c = (undefined2)param_3;
                      if (9 < param_3) {
                        local_90c = 9;
                      }
                      local_908 = local_90c;
                    }
                    *(undefined2 *)((int)local_21c + 0x48) = local_908;
                    if (*(char *)((int)local_21c + 0x55) == '\0') {
                      uVar8 = (int)*(short *)((int)local_21c + 0x48) & 0x80000001;
                      if ((int)uVar8 < 0) {
                        uVar8 = (uVar8 - 1 | 0xfffffffe) + 1;
                      }
                      if (uVar8 != 0) {
                        *(undefined2 *)((int)local_21c + 0x48) = 2;
                        ExceptionList = local_10;
                        return;
                      }
                    }
                    if (*(short *)((int)local_21c + 0x48) == 5) {
                      *(undefined2 *)((int)local_21c + 0x48) = 2;
                    }
                  }
                }
              }
              else {
                if ((param_2 % 0x8c1360) / 10 == 0) {
                  local_21c = &DAT_00a14438;
                }
                else {
                  iVar3 = FUN_004d25e0();
                  if (iVar3 < (param_2 % 0x8c1360) / 10) {
                    ExceptionList = local_10;
                    return;
                  }
                  local_21c = (undefined *)FUN_004d2620();
                }
                switch(param_2 % 10) {
                case 0:
                  *(int *)(local_21c + 0x28) = param_3 << 1;
                  break;
                case 1:
                  *(int *)(local_21c + 0x2c) = param_3 << 1;
                  break;
                case 2:
                  *(int *)(local_21c + 0x28) = param_3;
                  break;
                case 3:
                  *(int *)(local_21c + 0x2c) = param_3;
                  break;
                case 4:
                  *(int *)(local_21c + 0xc4) = param_3;
                  break;
                case 5:
                  puVar7 = (undefined1 *)FUN_004cd7c0();
                  *puVar7 = uVar1;
                  switch((param_2 % 0x8c1360) / 10) {
                  case 0:
                    _DAT_00a18ab4 = (undefined2)param_3;
                    break;
                  case 1:
                    piVar4 = (int *)FUN_004ce990();
                    *piVar4 = param_3;
                    break;
                  case 2:
                    piVar4 = (int *)FUN_004ce990();
                    *piVar4 = param_3;
                    break;
                  case 3:
                    piVar4 = (int *)FUN_004ce990();
                    *piVar4 = param_3;
                    break;
                  case 4:
                    piVar4 = (int *)FUN_004ce990();
                    *piVar4 = param_3;
                    break;
                  case 5:
                    piVar4 = (int *)FUN_004ce990();
                    *piVar4 = param_3;
                  }
                  break;
                case 6:
                  if (param_3 < 10) {
                    local_8f4 = param_3;
                  }
                  else {
                    local_8f4 = 9;
                  }
                  if (local_8f4 < 1) {
                    local_8f8 = 1;
                  }
                  else {
                    local_8fc = (undefined2)param_3;
                    if (9 < param_3) {
                      local_8fc = 9;
                    }
                    local_8f8 = local_8fc;
                  }
                  *(undefined2 *)(local_21c + 0x48) = local_8f8;
                  if (local_21c[0x55] == '\0') {
                    uVar8 = (int)*(short *)(local_21c + 0x48) & 0x80000001;
                    if ((int)uVar8 < 0) {
                      uVar8 = (uVar8 - 1 | 0xfffffffe) + 1;
                    }
                    if (uVar8 != 0) {
                      *(undefined2 *)(local_21c + 0x48) = 2;
                      ExceptionList = local_10;
                      return;
                    }
                  }
                  if (*(short *)(local_21c + 0x48) == 5) {
                    *(undefined2 *)(local_21c + 0x48) = 2;
                  }
                }
              }
            }
          }
          else {
            FUN_0043e5f0();
          }
        }
        else {
          FUN_004cde80();
          iVar3 = FUN_004ce080();
          if (param_2 % 100000 < iVar3) {
            FUN_004cde80();
            piVar4 = (int *)FUN_004ce990();
            *piVar4 = param_3;
          }
          else {
            if ((param_2 + -2000000) / 100000 == 0) {
              local_79c = (undefined1 *)&pbStack_a04;
              puStack_a08 = &DAT_007ce370;
              puStack_a0c = (undefined *)0x439395;
              basic_string<>();
              puStack_a08 = (undefined *)0x4393a0;
              pcVar6 = (char *)FUN_00401c50();
              _sprintf(local_218,pcVar6);
            }
            else {
              local_7a0 = (undefined1 *)&puStack_a08;
              puStack_a0c = &DAT_007ce3d0;
              uStack_a10 = 0x4393f6;
              basic_string<>();
              puStack_a0c = (undefined *)0x439401;
              pcVar6 = (char *)FUN_00401c50();
              uStack_9f8 = 0x43941d;
              _sprintf(local_218,pcVar6);
            }
            pbStack_a04 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)FUN_0041b5f0();
            local_7a4 = auStack_a00;
            puStack_a08 = (undefined *)0x43943a;
            basic_string<>();
            local_8 = 4;
            local_7a8 = auStack_a1c;
            pcStack_a20 = local_218;
            uStack_a24 = 0x43946a;
            basic_string<>();
            local_8 = CONCAT31(local_8._1_3_,5);
            local_7ac = abStack_a38;
            FUN_00438b60(abStack_a38);
            local_8 = 0xffffffff;
            FUN_0042bed0();
          }
        }
      }
      else if ((param_2 % 100 < 5) || (9 < param_2 % 100)) {
        iVar3 = FUN_004cd340();
        if ((param_2 % 1000000) / 100 < iVar3) {
          FUN_004cde80();
          piVar4 = (int *)FUN_004ce990();
          *piVar4 = param_3;
        }
      }
      else {
        pbStack_a04 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      FUN_0041b5f0();
        local_770 = auStack_a00;
        puStack_a08 = (undefined *)0x4391b3;
        basic_string<>();
        local_8 = 0;
        pbStack_a04 = local_790;
        puStack_a08 = (undefined *)0x4391d8;
        FUN_00438b60();
        local_8._0_1_ = 1;
        pbStack_a04 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4391fc;
        pcStack_a20 = (char *)FUN_004cbb30();
        local_774 = auStack_a1c;
        uStack_a24 = 0x43920d;
        basic_string<>();
        local_8._0_1_ = 2;
        local_798 = abStack_a38;
        basic_string<>(&DAT_007ce33c);
        uVar5 = FUN_00401c50();
        local_794 = abStack_a38;
        basic_string<>(uVar5);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0042bed0();
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_790);
      }
    }
    else {
      iVar3 = FUN_004cd340();
      if (iVar3 <= local_14) {
        FUN_004cdbb0();
      }
      FUN_004cde80();
      iVar3 = FUN_004cd340();
      if (iVar3 <= (param_2 % 100000) / 10) {
        FUN_004cde80();
        FUN_004cd310();
      }
      FUN_004cde80();
      FUN_004cde80();
      iVar3 = FUN_004ce080();
      if (iVar3 <= param_2 % 10) {
        FUN_004cde80();
        FUN_004cde80();
        FUN_004ce970();
      }
      FUN_004cde80();
      FUN_004cde80();
      piVar4 = (int *)FUN_004ce990();
      *piVar4 = param_3;
    }
  }
  else if ((param_2 < 1100000000) || (1199999999 < param_2)) {
    if ((param_2 < 1000000000) || (1099999999 < param_2)) {
      if ((param_2 < 1300000000) || (1399999999 < param_2)) {
        ExceptionList = &local_10;
        basic_string<>();
        local_8 = 0x16;
        local_870 = (undefined1 *)&puStack_a08;
        puStack_a0c = &DAT_007ce594;
        uStack_a10 = 0x43a14d;
        basic_string<>();
        puStack_a0c = (undefined *)0x43a158;
        pcVar6 = (char *)FUN_00401c50();
        uStack_9f8 = 0x43a174;
        _sprintf(local_750,pcVar6);
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (local_76c,local_750);
        local_874 = auStack_a00;
        pbStack_a04 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      &DAT_007ce5c9;
        puStack_a08 = (undefined *)0x43a19e;
        basic_string<>();
        local_8._0_1_ = 0x17;
        pbStack_a04 = local_894;
        puStack_a08 = (undefined *)0x43a1c0;
        FUN_00438b60();
        local_8._0_1_ = 0x18;
        pbStack_a04 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x43a1e4;
        pcStack_a20 = (char *)FUN_004cbb30();
        local_878 = auStack_a1c;
        uStack_a24 = 0x43a1f5;
        basic_string<>();
        local_8._0_1_ = 0x19;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  (abStack_a38,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_76c);
        local_8._0_1_ = 0x1a;
        FUN_0042bed0();
        local_8 = CONCAT31(local_8._1_3_,0x16);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_894);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_76c);
      }
      else {
        local_54c = (param_2 % 1300000000) / 1000000;
        local_544 = (param_2 % 1000000) / 100;
        local_548 = param_2 % 100;
        ExceptionList = &local_10;
        iVar3 = FUN_004717c0();
        if (iVar3 <= local_544) {
          FUN_004779b0();
        }
        uStack_9f8 = 0x439fe0;
        cVar2 = FUN_00477f90();
        if (cVar2 == '\0') {
          local_840 = (undefined1 *)&pbStack_a04;
          puStack_a08 = &DAT_007ce53c;
          puStack_a0c = (undefined *)0x43a004;
          basic_string<>();
          puStack_a08 = (undefined *)0x43a00f;
          pcVar6 = (char *)FUN_00401c50();
          _sprintf((char *)local_650,pcVar6);
          local_844 = auStack_a00;
          pbStack_a04 = local_650;
          puStack_a08 = (undefined *)0x43a045;
          basic_string<>();
          local_8 = 0x12;
          pbStack_a04 = local_864;
          puStack_a08 = (undefined *)0x43a06a;
          FUN_00438b60();
          local_8._0_1_ = 0x13;
          pbStack_a04 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x43a08e;
          pcStack_a20 = (char *)FUN_004cbb30();
          local_848 = auStack_a1c;
          uStack_a24 = 0x43a09f;
          basic_string<>();
          local_8._0_1_ = 0x14;
          local_86c = abStack_a38;
          basic_string<>(&DAT_007ce548);
          uVar5 = FUN_00401c50();
          local_868 = abStack_a38;
          basic_string<>(uVar5);
          local_8 = CONCAT31(local_8._1_3_,0x15);
          FUN_0042bed0();
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_864);
        }
      }
    }
    else {
      local_43c = (param_2 % 1000000000) / 1000000;
      local_434 = (param_2 % 1000000) / 100;
      local_438 = param_2 % 100;
      ExceptionList = &local_10;
      iVar3 = FUN_004717c0();
      if (iVar3 <= local_434) {
        FUN_004779b0();
      }
      uStack_9f8 = 0x439dea;
      cVar2 = FUN_00477f90();
      if (cVar2 == '\0') {
        local_810 = (undefined1 *)&pbStack_a04;
        puStack_a08 = &DAT_007ce4e0;
        puStack_a0c = (undefined *)0x439e0e;
        basic_string<>();
        puStack_a08 = (undefined *)0x439e19;
        pcVar6 = (char *)FUN_00401c50();
        _sprintf((char *)local_540,pcVar6);
        local_814 = auStack_a00;
        pbStack_a04 = local_540;
        puStack_a08 = (undefined *)0x439e4f;
        basic_string<>();
        local_8 = 0xe;
        pbStack_a04 = local_834;
        puStack_a08 = (undefined *)0x439e74;
        FUN_00438b60();
        local_8._0_1_ = 0xf;
        pbStack_a04 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x439e98;
        pcStack_a20 = (char *)FUN_004cbb30();
        local_818 = auStack_a1c;
        uStack_a24 = 0x439ea9;
        basic_string<>();
        local_8._0_1_ = 0x10;
        local_83c = abStack_a38;
        basic_string<>(&DAT_007ce4f0);
        uVar5 = FUN_00401c50();
        local_838 = abStack_a38;
        basic_string<>(uVar5);
        local_8 = CONCAT31(local_8._1_3_,0x11);
        FUN_0042bed0();
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_834);
      }
    }
  }
  else {
    local_22c = (param_2 % 1100000000) / 1000000;
    local_224 = (param_2 % 1000000) / 100;
    local_228 = param_2 % 100;
    if (param_4 == 0) {
      ExceptionList = &local_10;
      iVar3 = FUN_004717c0();
      if (iVar3 <= local_224) {
        FUN_004779b0();
      }
      uStack_9f8 = 0x439a65;
      cVar2 = FUN_00477f90();
      if (cVar2 == '\0') {
        local_7b0 = (undefined1 *)&pbStack_a04;
        puStack_a08 = &DAT_007ce430;
        puStack_a0c = (undefined *)0x439a89;
        basic_string<>();
        puStack_a08 = (undefined *)0x439a94;
        pcVar6 = (char *)FUN_00401c50();
        _sprintf((char *)local_330,pcVar6);
        local_7b4 = auStack_a00;
        pbStack_a04 = local_330;
        puStack_a08 = (undefined *)0x439aca;
        basic_string<>();
        local_8 = 6;
        pbStack_a04 = local_7d4;
        puStack_a08 = (undefined *)0x439aef;
        FUN_00438b60();
        local_8._0_1_ = 7;
        pbStack_a04 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x439b13;
        pcStack_a20 = (char *)FUN_004cbb30();
        local_7b8 = auStack_a1c;
        uStack_a24 = 0x439b24;
        basic_string<>();
        local_8._0_1_ = 8;
        local_7dc = abStack_a38;
        basic_string<>(&DAT_007ce440);
        uVar5 = FUN_00401c50();
        local_7d8 = abStack_a38;
        basic_string<>(uVar5);
        local_8 = CONCAT31(local_8._1_3_,9);
        FUN_0042bed0();
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_7d4);
      }
    }
    else {
      ExceptionList = &local_10;
      iVar3 = FUN_004717c0();
      if (iVar3 <= local_224) {
        FUN_004779b0();
      }
      uStack_9f8 = 0x439bf4;
      cVar2 = FUN_00477f90();
      if (cVar2 == '\0') {
        local_7e0 = (undefined1 *)&pbStack_a04;
        puStack_a08 = &DAT_007ce488;
        puStack_a0c = (undefined *)0x439c18;
        basic_string<>();
        puStack_a08 = (undefined *)0x439c23;
        pcVar6 = (char *)FUN_00401c50();
        _sprintf((char *)local_430,pcVar6);
        local_7e4 = auStack_a00;
        pbStack_a04 = local_430;
        puStack_a08 = (undefined *)0x439c59;
        basic_string<>();
        local_8 = 10;
        pbStack_a04 = local_804;
        puStack_a08 = (undefined *)0x439c7e;
        FUN_00438b60();
        local_8._0_1_ = 0xb;
        pbStack_a04 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x439ca2;
        pcStack_a20 = (char *)FUN_004cbb30();
        local_7e8 = auStack_a1c;
        uStack_a24 = 0x439cb3;
        basic_string<>();
        local_8._0_1_ = 0xc;
        local_80c = abStack_a38;
        basic_string<>(&DAT_007ce498);
        uVar5 = FUN_00401c50();
        local_808 = abStack_a38;
        basic_string<>(uVar5);
        local_8 = CONCAT31(local_8._1_3_,0xd);
        FUN_0042bed0();
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_804);
      }
    }
  }
  ExceptionList = local_10;
  return;
}

