
void FUN_004325e0(char param_1)

{
  int iVar1;
  undefined *puStack_224;
  undefined4 uStack_220;
  undefined *puStack_21c;
  undefined *puStack_218;
  int iStack_214;
  int iStack_210;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_20c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_208;
  int iStack_204;
  int iStack_200;
  int iStack_1fc;
  int local_1f8;
  int local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  int local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  int local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  int local_17c;
  int local_178;
  undefined4 local_174;
  undefined4 local_170;
  int local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined1 *local_158;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_154 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_138 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_11c [28];
  undefined1 *local_100;
  undefined1 *local_fc;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_f8 [28];
  undefined1 *local_dc;
  undefined1 *local_d8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_d4 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_b8 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_9c [28];
  undefined1 *local_80;
  undefined1 *local_7c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_78 [28];
  undefined1 *local_5c;
  undefined1 *local_58;
  undefined1 *local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007acf2c;
  local_10 = ExceptionList;
  if (DAT_00a117a8 != 0) {
    local_18 = 0xdc;
    local_2c = 0x294;
    local_24 = 10;
    local_38 = 0;
    if (param_1 != '\0') {
      DAT_00a1b154 = 0;
    }
    local_20 = 0;
    local_1c = 0;
    iStack_1fc = 0xff;
    iStack_200 = 0xff;
    iStack_204 = 0xff;
    pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x43266a;
    ExceptionList = &local_10;
    FUN_005161e0();
    iStack_1fc = 0xffffffff;
    local_54 = (undefined1 *)&puStack_218;
    puStack_21c = &DAT_007cdbdc;
    uStack_220 = 0x432681;
    local_15c = basic_string<>();
    puStack_21c = (undefined *)0x43268c;
    iStack_200 = FUN_00401c50();
    iStack_204 = 0x4326a1;
    local_160 = iStack_200;
    FUN_00536a20();
    iStack_1fc = 10;
    iStack_200 = 0x4326ab;
    FUN_00536900();
    iStack_1fc = 0;
    iStack_200 = 0x4326b5;
    FUN_00536af0();
    iStack_1fc = 0xbe;
    iStack_200 = 1;
    iStack_204 = 0x4326c4;
    FUN_005160d0();
    iStack_1fc = 1;
    iStack_200 = 0;
    iStack_204 = 0;
    pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
    pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x4326d4;
    iStack_200 = FUN_00543f70();
    iStack_204 = DAT_0084b234;
    pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  DAT_0084b230;
    pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
    iStack_210 = 0;
    iStack_214 = 0x4326ee;
    FUN_00526390();
    iStack_1fc = 0xff;
    iStack_200 = 0;
    iStack_204 = 0x4326fd;
    FUN_005160d0();
    iStack_1fc = DAT_00a18184;
    iStack_200 = DAT_00a18194;
    iStack_204 = DAT_00a18190;
    local_58 = (undefined1 *)&uStack_220;
    puStack_224 = &DAT_007cdbec;
    local_164 = basic_string<>();
    puStack_224 = (undefined *)0x432731;
    pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  FUN_00401c50();
    pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0xff;
    iStack_210 = 0xff;
    iStack_214 = 0xff;
    puStack_218 = (undefined *)0x432755;
    local_168 = pbStack_208;
    pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  FUN_00543f70();
    iStack_210 = local_1c;
    iStack_214 = local_20 - DAT_00a1b154;
    puStack_218 = (undefined *)0x43276c;
    FUN_00540490();
    local_1c = local_1c + local_24;
    local_34 = 0;
    local_14 = 0;
    local_28 = 0;
    local_3c = 0;
    while( true ) {
      iStack_1fc = 0x4327a9;
      iVar1 = FUN_004cd340();
      if (iVar1 <= local_3c) break;
      if (local_3c == 0) {
        local_16c = 0xe;
      }
      else {
        local_16c = local_3c + 0xe;
      }
      iStack_1fc = local_16c;
      iStack_200 = 0x4327dd;
      iVar1 = FUN_004717c0();
      local_34 = iVar1 + local_34;
      local_3c = local_3c + 1;
    }
    iStack_1fc = 4;
    iStack_200 = 0x4327f1;
    iVar1 = FUN_004717c0();
    local_34 = iVar1 + local_34;
    iStack_1fc = 6;
    iStack_200 = 0x432803;
    iVar1 = FUN_004717c0();
    local_34 = iVar1 + local_34;
    iStack_1fc = 5;
    iStack_200 = 0x432815;
    iVar1 = FUN_004717c0();
    local_34 = iVar1 + local_34;
    local_30 = 0;
    if (DAT_0084b234 + -8 <= local_1c) {
      local_20 = local_20 + local_18;
      local_1c = 0;
    }
    local_5c = (undefined1 *)&iStack_214;
    puStack_218 = &DAT_007cdc04;
    puStack_21c = (undefined *)0x432852;
    local_170 = basic_string<>();
    puStack_218 = (undefined *)0x43285d;
    iStack_1fc = FUN_00401c50();
    iStack_200 = 0x6f;
    iStack_204 = 0xff;
    pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0xff;
    pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x43287e;
    local_174 = iStack_1fc;
    iStack_200 = FUN_00543f70();
    iStack_204 = local_1c;
    pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  (local_20 - DAT_00a1b154);
    pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x432895;
    FUN_00540490();
    local_1c = local_1c + local_24;
    local_40 = 0;
    while( true ) {
      iStack_1fc = 0x4328bd;
      iVar1 = FUN_004cd340();
      if (iVar1 <= local_40) break;
      local_44 = 0;
      while( true ) {
        if (local_40 == 0) {
          local_178 = 0xe;
        }
        else {
          local_178 = local_40 + 0xe;
        }
        iStack_1fc = local_178;
        iStack_200 = 0x432907;
        iVar1 = FUN_004717c0();
        if (iVar1 <= local_44) break;
        if (DAT_0084b234 + -0x1c <= local_1c) {
          local_20 = local_20 + local_18;
          local_1c = 0;
        }
        if (local_2c <= local_20) {
          iStack_1fc = 0xbe;
          iStack_200 = 1;
          iStack_204 = 0x432945;
          FUN_005160d0();
          iStack_1fc = local_34;
          iStack_200 = local_28;
          iStack_204 = local_14;
          pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x432959;
          FUN_00432540();
          iStack_1fc = 0xff;
          iStack_200 = 1;
          iStack_204 = 0x432968;
          FUN_005160d0();
          local_14 = local_28;
          iStack_1fc = 0x432976;
          thunk_FUN_00522bc0();
          while( true ) {
            iStack_1fc = 0x432984;
            iVar1 = FUN_0052ece0();
            if (iVar1 != 0) {
              DAT_00a13fa0 = 0xffffffff;
              ExceptionList = local_10;
              return;
            }
            iStack_1fc = 0x4329a1;
            FUN_0042c8b0();
            if ((DAT_00a14670 != '\0') || (DAT_00a1461d != '\0')) break;
            if ((DAT_00a1466c == '\0') && (DAT_00a1461a == '\0')) {
              local_30 = 0;
            }
            else {
              local_30 = local_30 + 1;
              if (0x1e < local_30) break;
            }
            iStack_1fc = 0x10;
            iStack_200 = 0x4329f0;
            FUN_0052eb30();
          }
          local_20 = 0;
          iStack_1fc = 0xbe;
          iStack_200 = 1;
          iStack_204 = 0x432a08;
          FUN_005160d0();
          iStack_1fc = 1;
          iStack_200 = 0;
          iStack_204 = 0;
          pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x0;
          pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x432a18;
          iStack_200 = FUN_00543f70();
          iStack_204 = DAT_0084b234;
          pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )DAT_0084b230;
          pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x0;
          iStack_210 = 0;
          iStack_214 = 0x432a33;
          FUN_00526390();
          iStack_1fc = 0xff;
          iStack_200 = 0;
          iStack_204 = 0x432a42;
          FUN_005160d0();
        }
        if (local_40 == 0) {
          local_17c = 0xe;
        }
        else {
          local_17c = local_40 + 0xe;
        }
        iStack_1fc = 0;
        iStack_200 = local_44;
        iStack_204 = local_17c;
        pbStack_208 = local_78;
        pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x432a7e;
        local_184 = FUN_004706f0();
        local_8 = 0;
        iStack_1fc = 0x432aa2;
        local_180 = local_184;
        iStack_1fc = FUN_004cbb30();
        iStack_200 = 0;
        iStack_204 = 0;
        pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      (local_40 * 100000 + 2000000 + local_44);
        pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x432ac5;
        iStack_200 = FUN_0043b320();
        iStack_204 = local_44;
        pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_40;
        local_7c = (undefined1 *)&puStack_224;
        local_188 = basic_string<>(&DAT_007cdc14);
        pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      FUN_00401c50();
        iStack_210 = 0xff;
        iStack_214 = 0xff;
        puStack_218 = (undefined *)0xff;
        puStack_21c = (undefined *)0x432b0f;
        local_18c = pbStack_20c;
        iStack_210 = FUN_00543f70();
        iStack_214 = local_1c;
        puStack_218 = (undefined *)(local_20 - DAT_00a1b154);
        puStack_21c = (undefined *)0x432b26;
        FUN_00540490();
        local_8 = 0xffffffff;
        iStack_1fc = 0x432b38;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_78);
        local_28 = local_28 + 1;
        local_1c = local_1c + local_24;
        local_44 = local_44 + 1;
      }
      local_40 = local_40 + 1;
    }
    if (DAT_0084b234 + -8 <= local_1c) {
      local_20 = local_20 + local_18;
      local_1c = 0;
    }
    local_80 = (undefined1 *)&iStack_214;
    puStack_218 = &DAT_007cdc28;
    puStack_21c = (undefined *)0x432b83;
    local_190 = basic_string<>();
    puStack_218 = (undefined *)0x432b8e;
    iStack_1fc = FUN_00401c50();
    iStack_200 = 0x6f;
    iStack_204 = 0xff;
    pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0xff;
    pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x432baf;
    local_194 = iStack_1fc;
    iStack_200 = FUN_00543f70();
    iStack_204 = local_1c;
    pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  (local_20 - DAT_00a1b154);
    pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x432bc6;
    FUN_00540490();
    local_1c = local_1c + local_24;
    local_48 = 0;
    while( true ) {
      iStack_1fc = 4;
      iStack_200 = 0x432bf0;
      iVar1 = FUN_004717c0();
      if (iVar1 <= local_48) break;
      if (DAT_0084b234 + -0x1c <= local_1c) {
        local_20 = local_20 + local_18;
        local_1c = 0;
      }
      if (local_2c <= local_20) {
        iStack_1fc = 0xbe;
        iStack_200 = 1;
        iStack_204 = 0x432c2f;
        FUN_005160d0();
        iStack_1fc = local_34;
        iStack_200 = local_28;
        iStack_204 = local_14;
        pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x432c43;
        FUN_00432540();
        iStack_1fc = 0xff;
        iStack_200 = 1;
        iStack_204 = 0x432c52;
        FUN_005160d0();
        local_14 = local_28;
        iStack_1fc = 0x432c60;
        thunk_FUN_00522bc0();
        while( true ) {
          iStack_1fc = 0x432c6e;
          iVar1 = FUN_0052ece0();
          if (iVar1 != 0) {
            DAT_00a13fa0 = 0xffffffff;
            ExceptionList = local_10;
            return;
          }
          iStack_1fc = 0x432c8b;
          FUN_0042c8b0();
          if ((DAT_00a14670 != '\0') || (DAT_00a1461d != '\0')) break;
          if ((DAT_00a1466c == '\0') && (DAT_00a1461a == '\0')) {
            local_30 = 0;
          }
          else {
            local_30 = local_30 + 1;
            if (0x1e < local_30) break;
          }
          iStack_1fc = 0x10;
          iStack_200 = 0x432cda;
          FUN_0052eb30();
        }
        local_20 = 0;
        iStack_1fc = 0xbe;
        iStack_200 = 1;
        iStack_204 = 0x432cf2;
        FUN_005160d0();
        iStack_1fc = 1;
        iStack_200 = 0;
        iStack_204 = 0;
        pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x0;
        pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x432d02;
        iStack_200 = FUN_00543f70();
        iStack_204 = DAT_0084b234;
        pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      DAT_0084b230;
        pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x0;
        iStack_210 = 0;
        iStack_214 = 0x432d1c;
        FUN_00526390();
        iStack_1fc = 0xff;
        iStack_200 = 0;
        iStack_204 = 0x432d2b;
        FUN_005160d0();
      }
      iStack_1fc = 0;
      iStack_200 = local_48;
      iStack_204 = 4;
      pbStack_208 = local_9c;
      pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x432d47;
      local_19c = FUN_004706f0();
      local_8 = 1;
      iStack_1fc = 0x432d6b;
      local_198 = local_19c;
      iStack_1fc = FUN_004cbb30();
      iStack_200 = 0;
      iStack_204 = 0;
      pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    (local_48 + 3000000);
      pbStack_20c = local_b8;
      iStack_210 = 0x432d8b;
      local_1a4 = FUN_0043be80();
      local_8._0_1_ = 2;
      iStack_200 = 0x20;
      iStack_204 = 0;
      pbStack_208 = local_d4;
      pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x432db7;
      local_1a0 = local_1a4;
      local_1ac = FUN_004cbc20();
      local_8._0_1_ = 3;
      iStack_200 = 0x432dd8;
      local_1a8 = local_1ac;
      iStack_200 = FUN_004cbb30();
      iStack_204 = local_48;
      local_d8 = (undefined1 *)&uStack_220;
      puStack_224 = &DAT_007cdc38;
      local_1b0 = basic_string<>();
      puStack_224 = (undefined *)0x432dfd;
      pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    FUN_00401c50();
      pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0xff;
      iStack_210 = 0xff;
      iStack_214 = 0xff;
      puStack_218 = (undefined *)0x432e21;
      local_1b4 = (int)pbStack_208;
      pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    FUN_00543f70();
      iStack_210 = local_1c;
      iStack_214 = local_20 - DAT_00a1b154;
      puStack_218 = (undefined *)0x432e38;
      FUN_00540490();
      local_8._0_1_ = 2;
      iStack_1fc = 0x432e4a;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_d4);
      local_8 = CONCAT31(local_8._1_3_,1);
      iStack_1fc = 0x432e59;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_b8);
      local_8 = 0xffffffff;
      iStack_1fc = 0x432e6b;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_9c);
      local_28 = local_28 + 1;
      local_1c = local_1c + local_24;
      local_48 = local_48 + 1;
    }
    if (DAT_0084b234 + -8 <= local_1c) {
      local_20 = local_20 + local_18;
      local_1c = 0;
    }
    local_dc = (undefined1 *)&iStack_214;
    puStack_218 = &DAT_007cdc48;
    puStack_21c = (undefined *)0x432eb4;
    local_1b8 = basic_string<>();
    puStack_218 = (undefined *)0x432ebf;
    iStack_1fc = FUN_00401c50();
    iStack_200 = 0x6f;
    iStack_204 = 0xff;
    pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0xff;
    pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x432ee0;
    local_1bc = iStack_1fc;
    iStack_200 = FUN_00543f70();
    iStack_204 = local_1c;
    pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  (local_20 - DAT_00a1b154);
    pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x432ef7;
    FUN_00540490();
    local_1c = local_1c + local_24;
    local_4c = 0;
    while( true ) {
      iStack_1fc = 6;
      iStack_200 = 0x432f21;
      iVar1 = FUN_004717c0();
      if (iVar1 <= local_4c) break;
      if (DAT_0084b234 + -0x1c <= local_1c) {
        local_20 = local_20 + local_18;
        local_1c = 0;
      }
      if (local_2c <= local_20) {
        iStack_1fc = 0xbe;
        iStack_200 = 1;
        iStack_204 = 0x432f60;
        FUN_005160d0();
        iStack_1fc = local_34;
        iStack_200 = local_28;
        iStack_204 = local_14;
        pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x432f74;
        FUN_00432540();
        iStack_1fc = 0xff;
        iStack_200 = 1;
        iStack_204 = 0x432f83;
        FUN_005160d0();
        local_14 = local_28;
        iStack_1fc = 0x432f91;
        thunk_FUN_00522bc0();
        while( true ) {
          iStack_1fc = 0x432f9f;
          iVar1 = FUN_0052ece0();
          if (iVar1 != 0) {
            DAT_00a13fa0 = 0xffffffff;
            ExceptionList = local_10;
            return;
          }
          iStack_1fc = 0x432fbc;
          FUN_0042c8b0();
          if ((DAT_00a14670 != '\0') || (DAT_00a1461d != '\0')) break;
          if ((DAT_00a1466c == '\0') && (DAT_00a1461a == '\0')) {
            local_30 = 0;
          }
          else {
            local_30 = local_30 + 1;
            if (0x1e < local_30) break;
          }
          iStack_1fc = 0x10;
          iStack_200 = 0x43300b;
          FUN_0052eb30();
        }
        local_20 = 0;
        iStack_1fc = 0xbe;
        iStack_200 = 1;
        iStack_204 = 0x433023;
        FUN_005160d0();
        iStack_1fc = 1;
        iStack_200 = 0;
        iStack_204 = 0;
        pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x0;
        pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x433033;
        iStack_200 = FUN_00543f70();
        iStack_204 = DAT_0084b234;
        pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      DAT_0084b230;
        pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x0;
        iStack_210 = 0;
        iStack_214 = 0x43304d;
        FUN_00526390();
        iStack_1fc = 0xff;
        iStack_200 = 0;
        iStack_204 = 0x43305c;
        FUN_005160d0();
      }
      iStack_1fc = 0;
      iStack_200 = local_4c;
      iStack_204 = 6;
      pbStack_208 = local_f8;
      pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x433078;
      local_1c4 = FUN_004706f0();
      local_8 = 4;
      iStack_1fc = 0x43309c;
      local_1c0 = local_1c4;
      iStack_1fc = FUN_004cbb30();
      iStack_200 = 0;
      iStack_204 = 0;
      pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    (&DAT_00895440 + local_4c);
      pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4330b5;
      iStack_200 = FUN_0043b320();
      iStack_204 = local_4c;
      local_fc = (undefined1 *)&uStack_220;
      puStack_224 = &DAT_007cdc58;
      local_1c8 = basic_string<>();
      puStack_224 = (undefined *)0x4330da;
      pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    FUN_00401c50();
      pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0xff;
      iStack_210 = 0xff;
      iStack_214 = 0xff;
      puStack_218 = (undefined *)0x4330fe;
      local_1cc = (int)pbStack_208;
      pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    FUN_00543f70();
      iStack_210 = local_1c;
      iStack_214 = local_20 - DAT_00a1b154;
      puStack_218 = (undefined *)0x433115;
      FUN_00540490();
      local_8 = 0xffffffff;
      iStack_1fc = 0x43312a;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_f8);
      local_28 = local_28 + 1;
      local_1c = local_1c + local_24;
      local_4c = local_4c + 1;
    }
    if (DAT_0084b234 + -8 <= local_1c) {
      local_20 = local_20 + local_18;
      local_1c = 0;
    }
    local_100 = (undefined1 *)&iStack_214;
    puStack_218 = &DAT_007cdc6c;
    puStack_21c = (undefined *)0x433174;
    local_1d0 = basic_string<>();
    puStack_218 = (undefined *)0x43317f;
    iStack_1fc = FUN_00401c50();
    iStack_200 = 0x6f;
    iStack_204 = 0xff;
    pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0xff;
    pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x4331a0;
    local_1d4 = iStack_1fc;
    iStack_200 = FUN_00543f70();
    iStack_204 = local_1c;
    pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  (local_20 - DAT_00a1b154);
    pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x4331b7;
    FUN_00540490();
    local_1c = local_1c + local_24;
    local_50 = 0;
    while( true ) {
      iStack_1fc = 5;
      iStack_200 = 0x4331e1;
      iVar1 = FUN_004717c0();
      if (iVar1 <= local_50) break;
      if (DAT_0084b234 + -0x1c <= local_1c) {
        local_20 = local_20 + local_18;
        local_1c = 0;
      }
      if (local_2c <= local_20) {
        iStack_1fc = 0xbe;
        iStack_200 = 1;
        iStack_204 = 0x43321f;
        FUN_005160d0();
        iStack_1fc = local_34;
        iStack_200 = local_28;
        iStack_204 = local_14;
        pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x433233;
        FUN_00432540();
        iStack_1fc = 0xff;
        iStack_200 = 1;
        iStack_204 = 0x433242;
        FUN_005160d0();
        local_14 = local_28;
        iStack_1fc = 0x433250;
        thunk_FUN_00522bc0();
        while( true ) {
          iStack_1fc = 0x43325e;
          iVar1 = FUN_0052ece0();
          if (iVar1 != 0) {
            DAT_00a13fa0 = 0xffffffff;
            ExceptionList = local_10;
            return;
          }
          iStack_1fc = 0x43327b;
          FUN_0042c8b0();
          if ((DAT_00a14670 != '\0') || (DAT_00a1461d != '\0')) break;
          if ((DAT_00a1466c == '\0') && (DAT_00a1461a == '\0')) {
            local_30 = 0;
          }
          else {
            local_30 = local_30 + 1;
            if (0x1e < local_30) break;
          }
          iStack_1fc = 0x10;
          iStack_200 = 0x4332ca;
          FUN_0052eb30();
        }
        local_20 = 0;
        iStack_1fc = 0xbe;
        iStack_200 = 1;
        iStack_204 = 0x4332e2;
        FUN_005160d0();
        iStack_1fc = 1;
        iStack_200 = 0;
        iStack_204 = 0;
        pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x0;
        pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4332f2;
        iStack_200 = FUN_00543f70();
        iStack_204 = DAT_0084b234;
        pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      DAT_0084b230;
        pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x0;
        iStack_210 = 0;
        iStack_214 = 0x43330d;
        FUN_00526390();
        iStack_1fc = 0xff;
        iStack_200 = 0;
        iStack_204 = 0x43331c;
        FUN_005160d0();
      }
      iStack_1fc = 0;
      iStack_200 = local_50;
      iStack_204 = 5;
      pbStack_208 = local_11c;
      pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x433338;
      local_1dc = FUN_004706f0();
      local_8 = 5;
      iStack_1fc = 0x43335c;
      local_1d8 = local_1dc;
      iStack_1fc = FUN_004cbb30();
      iStack_200 = 0;
      iStack_204 = 0;
      pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    (&DAT_00970fe0 + local_50);
      pbStack_20c = local_138;
      iStack_210 = 0x43337b;
      local_1e4 = FUN_0043be80();
      local_8._0_1_ = 6;
      iStack_200 = 0x20;
      iStack_204 = 0;
      pbStack_208 = local_154;
      pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4333a7;
      local_1e0 = local_1e4;
      local_1ec = FUN_004cbc20();
      local_8._0_1_ = 7;
      iStack_200 = 0x4333c8;
      local_1e8 = local_1ec;
      iStack_200 = FUN_004cbb30();
      iStack_204 = local_50;
      local_158 = (undefined1 *)&uStack_220;
      puStack_224 = &DAT_007cdc8c;
      local_1f0 = basic_string<>();
      puStack_224 = (undefined *)0x4333ed;
      pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    FUN_00401c50();
      pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0xff;
      iStack_210 = 0xff;
      iStack_214 = 0xff;
      puStack_218 = (undefined *)0x433411;
      local_1f4 = (int)pbStack_208;
      pbStack_20c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    FUN_00543f70();
      iStack_210 = local_1c;
      iStack_214 = local_20 - DAT_00a1b154;
      puStack_218 = (undefined *)0x433428;
      FUN_00540490();
      local_8._0_1_ = 6;
      iStack_1fc = 0x43343a;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_154);
      local_8 = CONCAT31(local_8._1_3_,5);
      iStack_1fc = 0x433449;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_138);
      local_8 = 0xffffffff;
      iStack_1fc = 0x43345b;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_11c);
      local_28 = local_28 + 1;
      local_1c = local_1c + local_24;
      local_50 = local_50 + 1;
    }
    iStack_1fc = 0xbe;
    iStack_200 = 1;
    iStack_204 = 0x43347e;
    FUN_005160d0();
    iStack_1fc = local_34;
    iStack_200 = local_28;
    iStack_204 = local_14;
    pbStack_208 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x433492;
    FUN_00432540();
    iStack_1fc = 0xff;
    iStack_200 = 1;
    iStack_204 = 0x4334a1;
    FUN_005160d0();
    iStack_1fc = 0x4334a9;
    thunk_FUN_00522bc0();
    while( true ) {
      iStack_1fc = 0x4334b7;
      iVar1 = FUN_0052ece0();
      if (iVar1 != 0) break;
      iStack_1fc = 0x4334d4;
      FUN_0042c8b0();
      if ((DAT_00a14670 != '\0') || (DAT_00a1461d != '\0')) {
LAB_00433528:
        if (DAT_00a1b154 <= local_20 - DAT_0084b234) {
          if (DAT_0084b264 * 6 * DAT_0084b248 + local_20 < DAT_00a1b154 + local_2c) {
            local_1f8 = DAT_0084b264 * 6 * DAT_0084b248 + local_20;
          }
          else {
            local_1f8 = DAT_00a1b154 + local_2c;
          }
          DAT_00a1b154 = local_1f8;
          iStack_1fc = 0;
          iStack_200 = 0x433594;
          FUN_004325e0();
        }
        iStack_1fc = DAT_00a18a90;
        iStack_200 = 0x4335a3;
        FUN_00536900();
        ExceptionList = local_10;
        return;
      }
      if ((DAT_00a1466c == '\0') && (DAT_00a1461a == '\0')) {
        local_30 = 0;
      }
      else {
        local_30 = local_30 + 1;
        if (0x1e < local_30) goto LAB_00433528;
      }
      iStack_1fc = 0x10;
      iStack_200 = 0x433523;
      FUN_0052eb30();
    }
    DAT_00a13fa0 = 0xffffffff;
  }
  ExceptionList = local_10;
  return;
}

