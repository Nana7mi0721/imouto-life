
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_0045f180(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar4;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_178 [2];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_176 [10];
  undefined4 uStack_16c;
  int iStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined1 *puStack_148;
  undefined1 *puStack_144;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_140;
  int local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  int local_12c;
  int local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  int local_118;
  int local_114;
  undefined4 local_110;
  undefined4 local_10c;
  int local_108;
  undefined1 local_101;
  undefined4 local_100;
  int local_fc [3];
  undefined1 local_ed;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_ec [28];
  undefined1 *local_d0;
  char local_c9;
  undefined4 local_c8;
  int local_c4;
  int local_c0;
  undefined1 local_bc [4];
  undefined1 local_b8 [4];
  undefined1 local_b4 [4];
  undefined1 local_b0 [4];
  undefined4 local_ac;
  int local_a8;
  undefined1 local_a4 [4];
  undefined1 local_a0 [4];
  undefined4 local_9c;
  int local_98;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_94 [28];
  undefined1 *local_78;
  char local_71;
  int local_70;
  int local_6c;
  undefined1 *local_68;
  int local_64;
  int local_60;
  basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_> local_5c [16];
  int local_4c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_48 [28];
  undefined4 local_2c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007adfd4;
  local_10 = ExceptionList;
  local_2c = DAT_0084b484;
  pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                0x45f1c0;
  ExceptionList = &local_10;
  iVar1 = FUN_004ce080();
  if (iVar1 < 1) {
    local_18 = *(undefined4 *)(local_108 + 8);
    local_14 = 0;
    local_4c = -1;
    pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x45f2eb;
    FUN_004ce850();
    local_8 = 0;
    pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x45f2fa;
    FUN_004ce850();
    local_8._0_1_ = 1;
    pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
    puStack_144 = (undefined1 *)0x0;
    puStack_148 = (undefined1 *)0x0;
    uStack_14c = 0;
    uStack_150 = 0;
    uStack_154 = *(undefined4 *)(local_108 + 0x10);
    uStack_158 = *(undefined4 *)(local_108 + 0x18);
    uStack_15c = *(undefined4 *)(local_108 + 0x14);
    uStack_160 = 0;
    uStack_164 = 0x45f33c;
    pbVar4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             FUN_004cc4c0();
    local_68 = abStack_178;
    local_10c = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_178,pbVar4);
    local_110 = FUN_00424670();
    local_8._0_1_ = 2;
    local_18 = 0;
    while( true ) {
      pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x45f389;
      iVar1 = FUN_004cec90();
      if ((iVar1 <= local_18) || (local_14 == -100)) break;
      local_114 = local_14;
      if (local_14 == -1) {
        if (local_18 == *(int *)(local_108 + 8)) {
          local_14 = -100;
        }
        else {
          pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x0;
          puStack_144 = (undefined1 *)local_18;
          puStack_148 = (undefined1 *)0x45f5ba;
          FUN_004cecd0();
          puStack_144 = (undefined1 *)0x45f5c1;
          piVar2 = (int *)FUN_004ce990();
          local_128 = *piVar2;
          if (local_128 == 0xaa) {
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)local_18;
            puStack_144 = (undefined1 *)0x45f60f;
            iVar1 = FUN_004cecd0();
            local_98 = *(char *)(iVar1 + 0x10) * 10 + 1;
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)&local_98;
            puStack_144 = (undefined1 *)0x45f62e;
            FUN_004ce160();
            local_9c = 0xffffffff;
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)&local_9c;
            puStack_144 = local_a0;
            puStack_148 = (undefined1 *)0x45f64e;
            puVar3 = (undefined4 *)FUN_004ce060();
            puStack_144 = (undefined1 *)*puVar3;
            puStack_148 = local_a4;
            uStack_14c = 0x45f660;
            FUN_004ce220();
          }
          else if (local_128 == 0xb3) {
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)local_18;
            puStack_144 = (undefined1 *)0x45f67a;
            iVar1 = FUN_004cecd0();
            local_a8 = *(char *)(iVar1 + 0x10) * 10;
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)&local_a8;
            puStack_144 = (undefined1 *)0x45f696;
            FUN_004ce160();
            local_ac = 0xffffffff;
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)&local_ac;
            puStack_144 = local_b0;
            puStack_148 = (undefined1 *)0x45f6b6;
            puVar3 = (undefined4 *)FUN_004ce060();
            puStack_144 = (undefined1 *)*puVar3;
            puStack_148 = local_b4;
            uStack_14c = 0x45f6c8;
            FUN_004ce220();
          }
          else if (local_128 == 0x1f2) {
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x45f6d2;
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)std::
                             basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>
                             ::back(local_5c);
            puStack_144 = local_b8;
            puStack_148 = (undefined1 *)0x45f6e2;
            puVar3 = (undefined4 *)FUN_004ce060();
            puStack_144 = (undefined1 *)*puVar3;
            puStack_148 = local_bc;
            uStack_14c = 0x45f6f4;
            FUN_004ce220();
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x45f6fc;
            FUN_004ce1d0();
          }
        }
      }
      else if (local_14 == 0) {
        if (local_18 == *(int *)(local_108 + 8)) {
          local_14 = 1;
        }
        else {
          pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x0;
          puStack_144 = (undefined1 *)local_18;
          puStack_148 = (undefined1 *)0x45f3ff;
          FUN_004cecd0();
          puStack_144 = (undefined1 *)0x45f406;
          piVar2 = (int *)FUN_004ce990();
          local_118 = *piVar2;
          if (local_118 < 0xd5) {
            if (local_118 == 0xd4) {
              pbStack_140 = local_48;
              puStack_144 = (undefined1 *)0x0;
              puStack_148 = (undefined1 *)0x0;
              uStack_14c = 0;
              uStack_150 = 0;
              uStack_154 = 0;
              uStack_158 = *(undefined4 *)(local_108 + 0x10);
              uStack_15c = *(undefined4 *)(local_108 + 0x18);
              uStack_160 = *(undefined4 *)(local_108 + 0x14);
              uStack_164 = 0;
              iStack_168 = local_18;
              uStack_16c = 0x45f50b;
              FUN_004cecd0();
              iStack_168 = 0x45f515;
              pbVar4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)FUN_004cc4c0();
              local_78 = abStack_178 + -4;
              local_11c = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                    (abStack_178 + -4,pbVar4);
              puStack_144 = (undefined1 *)FUN_00424670(local_94);
              local_8._0_1_ = 3;
              puStack_148 = (undefined1 *)0x45f55a;
              local_124 = puStack_144;
              local_120 = puStack_144;
              local_71 = FUN_004ec8f0();
              local_8._0_1_ = 2;
              pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x45f56f;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_94);
              if (local_71 != '\0') {
                local_14 = -1;
                local_4c = local_18;
              }
            }
            else if (local_118 == 0xaa) {
              pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)local_18;
              puStack_144 = (undefined1 *)0x45f46d;
              iVar1 = FUN_004cecd0();
              local_6c = *(char *)(iVar1 + 0x10) * 10 + 1;
              pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)&local_6c;
              puStack_144 = (undefined1 *)0x45f486;
              FUN_004ce160();
            }
            else if (local_118 == 0xb3) {
              pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)local_18;
              puStack_144 = (undefined1 *)0x45f4a0;
              iVar1 = FUN_004cecd0();
              local_70 = *(char *)(iVar1 + 0x10) * 10;
              pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)&local_70;
              puStack_144 = (undefined1 *)0x45f4b6;
              FUN_004ce160();
            }
          }
          else if (local_118 == 0x1f2) {
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x45f4c3;
            FUN_004ce1d0();
          }
        }
      }
      else if (local_14 == 1) {
        pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x0;
        puStack_144 = (undefined1 *)local_18;
        puStack_148 = (undefined1 *)0x45f718;
        FUN_004cecd0();
        puStack_144 = (undefined1 *)0x45f71f;
        piVar2 = (int *)FUN_004ce990();
        local_12c = *piVar2;
        if (local_12c < 0xd5) {
          if (local_12c == 0xd4) {
            pbStack_140 = local_48;
            puStack_144 = (undefined1 *)0x0;
            puStack_148 = (undefined1 *)0x0;
            uStack_14c = 0;
            uStack_150 = 0;
            uStack_154 = 0;
            uStack_158 = *(undefined4 *)(local_108 + 0x10);
            uStack_15c = *(undefined4 *)(local_108 + 0x18);
            uStack_160 = *(undefined4 *)(local_108 + 0x14);
            uStack_164 = 0;
            iStack_168 = local_18;
            uStack_16c = 0x45f86f;
            FUN_004cecd0();
            iStack_168 = 0x45f879;
            pbVar4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )FUN_004cc4c0();
            local_d0 = abStack_178 + -4;
            local_130 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                  (abStack_178 + -4,pbVar4);
            puStack_144 = (undefined1 *)FUN_00424670(local_ec);
            local_8._0_1_ = 4;
            puStack_148 = (undefined1 *)0x45f8c1;
            local_138 = puStack_144;
            local_134 = puStack_144;
            local_c9 = FUN_004ec8f0();
            local_8._0_1_ = 2;
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x45f8d9;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_ec);
            if (local_c9 != '\0') {
              local_14 = -100;
              local_4c = local_18;
            }
          }
          else if (local_12c == 0xaa) {
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)local_18;
            puStack_144 = (undefined1 *)0x45f78a;
            iVar1 = FUN_004cecd0();
            local_c0 = *(char *)(iVar1 + 0x10) * 10 + 1;
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)&local_c0;
            puStack_144 = (undefined1 *)0x45f7a9;
            FUN_004ce160();
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x45f7b1;
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)std::
                             basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>
                             ::back(local_5c);
            puStack_144 = (undefined1 *)0x45f7ba;
            FUN_004ce160();
          }
          else if (local_12c == 0xb3) {
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)local_18;
            puStack_144 = (undefined1 *)0x45f7d4;
            iVar1 = FUN_004cecd0();
            local_c4 = *(char *)(iVar1 + 0x10) * 10;
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)&local_c4;
            puStack_144 = (undefined1 *)0x45f7f0;
            FUN_004ce160();
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x45f7f8;
            pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)std::
                             basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>
                             ::back(local_5c);
            puStack_144 = (undefined1 *)0x45f801;
            FUN_004ce160();
          }
        }
        else if (local_12c == 0x1f2) {
          pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x45f80e;
          FUN_004ce1d0();
          local_c8 = 0xffffffff;
          pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )&local_c8;
          puStack_144 = (undefined1 *)0x45f827;
          FUN_004ce160();
        }
      }
      local_18 = local_18 + 1;
    }
    if (local_4c == -1) {
      local_ed = 1;
      local_8._0_1_ = 1;
      pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x45f90f;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_48);
      local_8 = (uint)local_8._1_3_ << 8;
      pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x45f91b;
      FUN_004ce950();
      local_8 = 0xffffffff;
      pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x45f92a;
      FUN_004ce950();
    }
    else {
      local_64 = 0;
      while( true ) {
        pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x45f94f;
        iVar1 = FUN_004ce080();
        if (iVar1 <= local_64) break;
        pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_64;
        puStack_144 = (undefined1 *)0x45f964;
        piVar2 = (int *)FUN_004ce990();
        local_13c = *piVar2 % 10;
        if (local_13c == -1) {
          pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x45f9a9;
          FUN_004ce1d0();
          pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x45f9ba;
          FUN_004ce1d0();
        }
        else if (local_13c == 0) {
          pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )local_64;
          puStack_144 = (undefined1 *)0x45f9cb;
          piVar2 = (int *)FUN_004ce990();
          local_fc[2] = *piVar2 / 10;
          pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )(local_fc + 2);
          puStack_144 = (undefined1 *)0x45f9f3;
          FUN_004ce160();
          local_fc[1] = 0;
          pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )(local_fc + 1);
          puStack_144 = (undefined1 *)0x45fa15;
          FUN_004ce160();
        }
        else if (local_13c == 1) {
          pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )local_64;
          puStack_144 = (undefined1 *)0x45fa23;
          piVar2 = (int *)FUN_004ce990();
          local_fc[0] = *piVar2 / 10;
          pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )local_fc;
          puStack_144 = (undefined1 *)0x45fa4b;
          FUN_004ce160();
          local_100 = 2000000000;
          pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )&local_100;
          puStack_144 = (undefined1 *)0x45fa6d;
          FUN_004ce160();
        }
        local_64 = local_64 + 1;
      }
      *(int *)(local_108 + 8) = local_4c;
      local_101 = 1;
      local_8._0_1_ = 1;
      pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x45fa91;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_48);
      local_8 = (uint)local_8._1_3_ << 8;
      pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x45fa9d;
      FUN_004ce950();
      local_8 = 0xffffffff;
      pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x45faac;
      FUN_004ce950();
      local_ed = local_101;
    }
  }
  else {
    local_60 = 0;
    while( true ) {
      pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x2
      ;
      puStack_144 = (undefined1 *)0x45f1f0;
      piVar2 = (int *)FUN_004ce990();
      if (*piVar2 <= local_60) break;
      pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    (local_60 * 2 + 3);
      puStack_144 = (undefined1 *)0x45f217;
      piVar2 = (int *)FUN_004ce990();
      if (*piVar2 == -1) {
        pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x45f22d;
        FUN_004ce1d0();
        pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x45f23e;
        FUN_004ce1d0();
      }
      else {
        pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      (local_60 * 2 + 3);
        puStack_144 = (undefined1 *)0x45f25c;
        pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      FUN_004ce990();
        puStack_144 = (undefined1 *)0x45f26e;
        FUN_004ce160();
        pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      (local_60 * 2 + 4);
        puStack_144 = (undefined1 *)0x45f28a;
        pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      FUN_004ce990();
        puStack_144 = (undefined1 *)0x45f29c;
        FUN_004ce160();
      }
      local_60 = local_60 + 1;
    }
    pbStack_140 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x1;
    puStack_144 = (undefined1 *)0x45f2b7;
    puVar3 = (undefined4 *)FUN_004ce990();
    *(undefined4 *)(local_108 + 8) = *puVar3;
    local_ed = 1;
  }
  ExceptionList = local_10;
  return local_ed;
}

