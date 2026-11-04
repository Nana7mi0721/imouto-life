
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_0045b100(int param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar4;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_2d0 [12];
  undefined4 uStack_2c4;
  undefined1 **ppuStack_2c0;
  undefined1 **ppuStack_2bc;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_2b8;
  undefined4 *puStack_2b4;
  undefined1 **ppuStack_2b0;
  undefined1 **ppuStack_2ac;
  undefined1 **ppuStack_2a8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_2a4;
  undefined1 **ppuStack_2a0;
  undefined1 **ppuStack_29c;
  undefined1 **ppuStack_298;
  undefined1 **ppuStack_294;
  undefined4 *puStack_290;
  undefined4 *puStack_28c;
  int *piStack_288;
  int *piStack_284;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_280;
  undefined1 **ppuStack_27c;
  undefined1 **ppuStack_278;
  undefined1 **ppuStack_274;
  undefined1 **ppuStack_270;
  undefined1 **ppuStack_26c;
  undefined1 **ppuStack_268;
  undefined1 **ppuStack_264;
  undefined1 *local_230;
  undefined1 *local_22c;
  int local_224;
  int local_220;
  int local_21c;
  int local_218;
  int local_214;
  int local_210;
  int local_20c;
  int local_208;
  int local_204;
  undefined1 *local_1fc;
  undefined1 *local_1f8;
  undefined4 local_1f4;
  undefined1 *local_1f0;
  undefined1 *local_1ec;
  undefined1 *local_1e8;
  undefined1 *local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  int local_1d8;
  int local_1d4;
  int local_1d0;
  undefined1 *local_1cc;
  undefined1 *local_1c8;
  undefined1 *local_1c4;
  undefined1 *local_1c0;
  undefined1 local_1b9;
  undefined4 local_1b8;
  undefined4 local_1b4;
  int local_1b0;
  int local_1ac;
  int local_1a8;
  undefined1 *local_1a4;
  undefined1 *local_1a0;
  undefined1 local_199;
  undefined1 *local_198;
  undefined1 *local_194;
  undefined1 *local_190;
  undefined1 *local_18c;
  undefined4 local_188;
  undefined4 local_184;
  int local_180;
  int local_17c;
  undefined1 *local_178;
  undefined1 *local_174;
  undefined1 local_16d;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_16c [28];
  undefined1 *local_150;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_14c [28];
  undefined1 *local_130;
  undefined1 *local_12c;
  undefined4 local_128;
  undefined4 local_124;
  int local_120;
  int local_11c;
  undefined4 local_118;
  undefined1 *local_114;
  undefined1 *local_110;
  undefined1 local_109;
  undefined4 local_108;
  undefined1 *local_104;
  undefined1 *local_100;
  undefined1 *local_fc;
  undefined4 local_f8;
  undefined1 *local_f4;
  undefined1 *local_f0;
  undefined1 *local_ec;
  undefined1 *local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  int local_dc;
  int local_d8;
  undefined4 local_d4;
  undefined1 *local_d0;
  undefined1 *local_cc;
  undefined1 *local_c8;
  undefined1 *local_c4;
  undefined1 local_bd;
  undefined1 *local_bc;
  undefined1 *local_b8;
  undefined1 *local_b4;
  undefined1 *local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  int local_a4;
  int local_a0;
  undefined1 *local_9c;
  undefined1 *local_98;
  undefined1 local_91;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_90 [28];
  undefined1 *local_74;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_70 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_54 [28];
  undefined4 local_38;
  int local_34;
  char local_2d;
  undefined1 *local_2c;
  undefined1 *local_28;
  undefined1 *local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ade69;
  local_10 = ExceptionList;
  local_38 = DAT_0084b484;
  local_28 = &LAB_00646464;
  local_1c = (undefined1 *)0x0;
  local_14 = (undefined1 *)0x64;
  local_18 = (undefined1 *)0x64;
  ppuStack_264 = (undefined1 **)0x1;
  ppuStack_268 = (undefined1 **)0x45b15b;
  ExceptionList = &local_10;
  puVar1 = (uint *)FUN_004ce990();
  if ((*puVar1 & 0xf) < 2) {
    ppuStack_264 = (undefined1 **)0x45b17a;
    iVar2 = FUN_004ce080();
    if (0xd < iVar2) {
      ppuStack_264 = (undefined1 **)0xd;
      ppuStack_268 = (undefined1 **)0x45b196;
      puVar1 = (uint *)FUN_004ce990();
      if ((*puVar1 & 0x2000000) == 0) {
        ppuStack_264 = (undefined1 **)0xd;
        ppuStack_268 = (undefined1 **)0x45b452;
        puVar3 = (undefined4 *)FUN_004ce990();
        local_28 = (undefined1 *)*puVar3;
      }
      else {
        ppuStack_264 = (undefined1 **)0x10;
        ppuStack_268 = (undefined1 **)0x45b1b7;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45b1c5;
        iVar2 = FUN_00487080();
        if (iVar2 < 0) {
          local_204 = 0;
        }
        else {
          ppuStack_264 = (undefined1 **)0x10;
          ppuStack_268 = (undefined1 **)0x45b1e8;
          puVar3 = (undefined4 *)FUN_004ce990();
          ppuStack_264 = (undefined1 **)*puVar3;
          ppuStack_268 = (undefined1 **)0x45b1f6;
          local_204 = FUN_00487080();
        }
        if (local_204 < 0xc9) {
          ppuStack_264 = (undefined1 **)0x10;
          ppuStack_268 = (undefined1 **)0x45b227;
          puVar3 = (undefined4 *)FUN_004ce990();
          ppuStack_264 = (undefined1 **)*puVar3;
          ppuStack_268 = (undefined1 **)0x45b235;
          iVar2 = FUN_00487080();
          if (iVar2 < 0) {
            local_20c = 0;
          }
          else {
            ppuStack_264 = (undefined1 **)0x10;
            ppuStack_268 = (undefined1 **)0x45b258;
            puVar3 = (undefined4 *)FUN_004ce990();
            ppuStack_264 = (undefined1 **)*puVar3;
            ppuStack_268 = (undefined1 **)0x45b266;
            local_20c = FUN_00487080();
          }
          local_208 = local_20c;
        }
        else {
          local_208 = 200;
        }
        ppuStack_264 = (undefined1 **)0x11;
        ppuStack_268 = (undefined1 **)0x45b28b;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45b299;
        iVar2 = FUN_00487080();
        if (iVar2 < 0) {
          local_210 = 0;
        }
        else {
          ppuStack_264 = (undefined1 **)0x11;
          ppuStack_268 = (undefined1 **)0x45b2bc;
          puVar3 = (undefined4 *)FUN_004ce990();
          ppuStack_264 = (undefined1 **)*puVar3;
          ppuStack_268 = (undefined1 **)0x45b2ca;
          local_210 = FUN_00487080();
        }
        if (local_210 < 0xc9) {
          ppuStack_264 = (undefined1 **)0x11;
          ppuStack_268 = (undefined1 **)0x45b2fb;
          puVar3 = (undefined4 *)FUN_004ce990();
          ppuStack_264 = (undefined1 **)*puVar3;
          ppuStack_268 = (undefined1 **)0x45b309;
          iVar2 = FUN_00487080();
          if (iVar2 < 0) {
            local_218 = 0;
          }
          else {
            ppuStack_264 = (undefined1 **)0x11;
            ppuStack_268 = (undefined1 **)0x45b32c;
            puVar3 = (undefined4 *)FUN_004ce990();
            ppuStack_264 = (undefined1 **)*puVar3;
            ppuStack_268 = (undefined1 **)0x45b33a;
            local_218 = FUN_00487080();
          }
          local_214 = local_218;
        }
        else {
          local_214 = 200;
        }
        ppuStack_264 = (undefined1 **)0x12;
        ppuStack_268 = (undefined1 **)0x45b35f;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45b36d;
        iVar2 = FUN_00487080();
        if (iVar2 < 0) {
          local_21c = 0;
        }
        else {
          ppuStack_264 = (undefined1 **)0x12;
          ppuStack_268 = (undefined1 **)0x45b390;
          puVar3 = (undefined4 *)FUN_004ce990();
          ppuStack_264 = (undefined1 **)*puVar3;
          ppuStack_268 = (undefined1 **)0x45b39e;
          local_21c = FUN_00487080();
        }
        if (local_21c < 0xc9) {
          ppuStack_264 = (undefined1 **)0x12;
          ppuStack_268 = (undefined1 **)0x45b3cf;
          puVar3 = (undefined4 *)FUN_004ce990();
          ppuStack_264 = (undefined1 **)*puVar3;
          ppuStack_268 = (undefined1 **)0x45b3dd;
          iVar2 = FUN_00487080();
          if (iVar2 < 0) {
            local_224 = 0;
          }
          else {
            ppuStack_264 = (undefined1 **)0x12;
            ppuStack_268 = (undefined1 **)0x45b400;
            puVar3 = (undefined4 *)FUN_004ce990();
            ppuStack_264 = (undefined1 **)*puVar3;
            ppuStack_268 = (undefined1 **)0x45b40e;
            local_224 = FUN_00487080();
          }
          local_220 = local_224;
        }
        else {
          local_220 = 200;
        }
        local_28 = (undefined1 *)(local_214 * 0x100 + local_208 * 0x10000 + local_220);
      }
    }
    ppuStack_264 = (undefined1 **)0x45b468;
    iVar2 = FUN_004ce080();
    if (0xe < iVar2) {
      ppuStack_264 = (undefined1 **)0xe;
      ppuStack_268 = (undefined1 **)0x45b480;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45b48e;
      local_1c = (undefined1 *)FUN_00487080();
    }
    ppuStack_264 = (undefined1 **)0x1;
    ppuStack_268 = (undefined1 **)0x45b4a4;
    puVar1 = (uint *)FUN_004ce990();
    switch((int)(*puVar1 & 0xf00000) >> 0x14) {
    case 0:
      ppuStack_264 = (undefined1 **)0xa;
      ppuStack_268 = (undefined1 **)0x45b4ea;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45b4f8;
      local_18 = (undefined1 *)FUN_00487080();
      local_14 = local_18;
      break;
    case 1:
      local_18 = (undefined1 *)0x64;
      ppuStack_264 = (undefined1 **)0xa;
      ppuStack_268 = (undefined1 **)0x45b520;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45b52e;
      local_14 = (undefined1 *)FUN_00487080();
      break;
    case 2:
      ppuStack_264 = (undefined1 **)0xa;
      ppuStack_268 = (undefined1 **)0x45b549;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45b557;
      local_18 = (undefined1 *)FUN_00487080();
      local_14 = (undefined1 *)0x64;
      break;
    case 3:
      ppuStack_264 = (undefined1 **)0xa;
      ppuStack_268 = (undefined1 **)0x45b576;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45b584;
      local_18 = (undefined1 *)FUN_00487080();
      ppuStack_264 = (undefined1 **)0x13;
      ppuStack_268 = (undefined1 **)0x45b59a;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45b5a8;
      local_14 = (undefined1 *)FUN_00487080();
      break;
    case 4:
      local_14 = (undefined1 *)0xfff0bdc0;
      local_18 = (undefined1 *)0xfff0bdc0;
    }
  }
  ppuStack_264 = (undefined1 **)0x1;
  ppuStack_268 = (undefined1 **)0x45b5cd;
  puVar1 = (uint *)FUN_004ce990();
  if ((*puVar1 & 0xf) == 2) {
    ppuStack_264 = (undefined1 **)0x45b5e8;
    iVar2 = FUN_004ce080();
    if (4 < iVar2) {
      ppuStack_264 = (undefined1 **)0x4;
      ppuStack_268 = (undefined1 **)0x45b600;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45b60e;
      local_1c = (undefined1 *)FUN_00487080();
    }
    local_28 = (undefined1 *)0x1000000;
  }
  ppuStack_264 = (undefined1 **)0x2;
  ppuStack_268 = (undefined1 **)0x45b62b;
  puVar3 = (undefined4 *)FUN_004ce990();
  ppuStack_264 = (undefined1 **)*puVar3;
  ppuStack_268 = (undefined1 **)0x45b639;
  local_24 = (undefined1 *)FUN_00487080();
  ppuStack_264 = (undefined1 **)0x2;
  ppuStack_268 = (undefined1 **)0x45b64f;
  puVar3 = (undefined4 *)FUN_004ce990();
  ppuStack_264 = (undefined1 **)*puVar3;
  ppuStack_268 = (undefined1 **)0x45b65d;
  local_20 = (undefined1 *)FUN_00487080();
  ppuStack_264 = (undefined1 **)0x1;
  ppuStack_268 = (undefined1 **)0x45b673;
  puVar1 = (uint *)FUN_004ce990();
  if ((*puVar1 & 0x1000000) == 0) goto LAB_0045b872;
  local_2c = (undefined1 *)0x0;
  local_2d = '\0';
  ppuStack_264 = (undefined1 **)0x1;
  ppuStack_268 = (undefined1 **)0x45b69f;
  puVar1 = (uint *)FUN_004ce990();
  if ((*puVar1 & 0xf) < 2) {
    ppuStack_264 = (undefined1 **)0x45b6ba;
    iVar2 = FUN_004ce080();
    if (iVar2 < 0x10) goto LAB_0045b6ec;
    local_2d = '\x01';
    ppuStack_264 = (undefined1 **)0xf;
    ppuStack_268 = (undefined1 **)0x45b6d6;
    puVar3 = (undefined4 *)FUN_004ce990();
    ppuStack_264 = (undefined1 **)*puVar3;
    ppuStack_268 = (undefined1 **)0x45b6e4;
    local_2c = (undefined1 *)FUN_00487080();
  }
  else {
LAB_0045b6ec:
    ppuStack_264 = (undefined1 **)0x1;
    ppuStack_268 = (undefined1 **)0x45b6ff;
    puVar1 = (uint *)FUN_004ce990();
    if ((*puVar1 & 0xf) == 2) {
      ppuStack_264 = (undefined1 **)0x45b71a;
      iVar2 = FUN_004ce080();
      if (6 < iVar2) {
        local_2d = '\x01';
        ppuStack_264 = (undefined1 **)0x6;
        ppuStack_268 = (undefined1 **)0x45b736;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45b744;
        local_2c = (undefined1 *)FUN_00487080();
        goto LAB_0045b7a4;
      }
    }
    ppuStack_264 = (undefined1 **)0x1;
    ppuStack_268 = (undefined1 **)0x45b75c;
    puVar1 = (uint *)FUN_004ce990();
    if ((*puVar1 & 0xf) == 3) {
      ppuStack_264 = (undefined1 **)0x45b777;
      iVar2 = FUN_004ce080();
      if (3 < iVar2) {
        local_2d = '\x01';
        ppuStack_264 = (undefined1 **)0x3;
        ppuStack_268 = (undefined1 **)0x45b793;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45b7a1;
        local_2c = (undefined1 *)FUN_00487080();
      }
    }
  }
LAB_0045b7a4:
  if (local_2d != '\0') {
    ppuStack_264 = (undefined1 **)0x2;
    ppuStack_268 = (undefined1 **)0x45b7c3;
    puVar3 = (undefined4 *)FUN_004ce990();
    ppuStack_264 = (undefined1 **)*puVar3;
    ppuStack_268 = (undefined1 **)0x45b7d1;
    iVar2 = FUN_00487080();
    if (iVar2 < (int)local_2c) {
      ppuStack_264 = (undefined1 **)0x2;
      ppuStack_268 = (undefined1 **)0x45b7e9;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45b7f7;
      local_22c = (undefined1 *)FUN_00487080();
    }
    else {
      local_22c = local_2c;
    }
    local_24 = local_22c;
    ppuStack_264 = (undefined1 **)0x2;
    ppuStack_268 = (undefined1 **)0x45b824;
    puVar3 = (undefined4 *)FUN_004ce990();
    ppuStack_264 = (undefined1 **)*puVar3;
    ppuStack_268 = (undefined1 **)0x45b832;
    iVar2 = FUN_00487080();
    if ((int)local_2c < iVar2) {
      ppuStack_264 = (undefined1 **)0x2;
      ppuStack_268 = (undefined1 **)0x45b84a;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45b858;
      local_230 = (undefined1 *)FUN_00487080();
    }
    else {
      local_230 = local_2c;
    }
    local_20 = local_230;
  }
LAB_0045b872:
  ppuStack_264 = (undefined1 **)0x1;
  ppuStack_268 = (undefined1 **)0x45b885;
  puVar1 = (uint *)FUN_004ce990();
  if ((*puVar1 & 0xf) == 0) {
    local_34 = 0;
    ppuStack_264 = (undefined1 **)0x1;
    ppuStack_268 = (undefined1 **)0x45b8aa;
    puVar1 = (uint *)FUN_004ce990();
    if ((*puVar1 & 0x2000000) != 0) {
      local_34 = 0x100;
    }
    ppuStack_264 = (undefined1 **)0x1;
    ppuStack_268 = (undefined1 **)0x45b8cd;
    puVar1 = (uint *)FUN_004ce990();
    if ((*puVar1 & 0x8000000) != 0) {
      local_34 = 0x200;
    }
    ppuStack_264 = (undefined1 **)0x1;
    ppuStack_268 = (undefined1 **)0x45b8f1;
    puVar1 = (uint *)FUN_004ce990();
    switch((int)(*puVar1 & 0xf0) >> 4) {
    case 0:
    case 1:
      ppuStack_264 = (undefined1 **)0x45b929;
      basic_string<>();
      local_8 = 0;
      ppuStack_264 = (undefined1 **)0x1;
      ppuStack_268 = (undefined1 **)0x45b943;
      puVar1 = (uint *)FUN_004ce990();
      if ((int)(*puVar1 & 0xf0) >> 4 == 0) {
        ppuStack_264 = (undefined1 **)0x0;
        ppuStack_268 = (undefined1 **)0x45b96d;
        ppuStack_264 = (undefined1 **)FUN_004cc4c0();
        ppuStack_268 = (undefined1 **)0x45b976;
        FUN_004cb840();
      }
      else {
        local_74 = (undefined1 *)&ppuStack_27c;
        pbStack_280 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x0;
        piStack_284 = (int *)0xc;
        piStack_288 = (int *)0x45b995;
        puVar3 = (undefined4 *)FUN_004ce990();
        piStack_284 = (int *)*puVar3;
        puStack_28c = (undefined4 *)0x45b9a4;
        piStack_288 = (int *)&ppuStack_27c;
        FUN_00487160();
        pbStack_280 = local_90;
        piStack_284 = (int *)0x45b9b6;
        ppuStack_264 = (undefined1 **)FUN_004297d0();
        local_8._0_1_ = 1;
        ppuStack_268 = (undefined1 **)0x45b9de;
        FUN_004cb840();
        local_8 = (uint)local_8._1_3_ << 8;
        ppuStack_264 = (undefined1 **)0x45b9ed;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_90);
      }
      ppuStack_264 = (undefined1 **)0x1;
      ppuStack_268 = (undefined1 **)0x45ba00;
      puVar1 = (uint *)FUN_004ce990();
      if ((*puVar1 & 0x4000000) == 0) {
        ppuStack_264 = (undefined1 **)0x1;
        ppuStack_268 = (undefined1 **)0x45ba21;
        puVar1 = (uint *)FUN_004ce990();
        local_91 = (*puVar1 & 0xf0000) == 0x10000;
        ppuStack_264 = (undefined1 **)0x1;
        ppuStack_268 = (undefined1 **)0x45ba49;
        puVar1 = (uint *)FUN_004ce990();
        local_98 = (undefined1 *)((int)(*puVar1 & 0xf000) >> 0xc);
        ppuStack_264 = (undefined1 **)0xb;
        ppuStack_268 = (undefined1 **)0x45ba75;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45ba83;
        local_9c = (undefined1 *)FUN_00487080();
        ppuStack_264 = (undefined1 **)0x3;
        ppuStack_268 = (undefined1 **)0x45ba9c;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45baaa;
        local_a0 = FUN_00487080();
        ppuStack_264 = (undefined1 **)0x1;
        ppuStack_268 = (undefined1 **)0x45bac3;
        puVar1 = (uint *)FUN_004ce990();
        local_a4 = ((int)(*puVar1 & 0xf00) >> 8) + local_34;
        ppuStack_264 = (undefined1 **)0x7;
        ppuStack_268 = (undefined1 **)0x45baf2;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45bb00;
        local_a8 = FUN_00487080();
        ppuStack_264 = (undefined1 **)0x6;
        ppuStack_268 = (undefined1 **)0x45bb19;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45bb27;
        local_ac = FUN_00487080();
        ppuStack_264 = (undefined1 **)0x9;
        ppuStack_268 = (undefined1 **)0x45bb40;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45bb4e;
        local_b0 = (undefined1 *)FUN_00487080();
        ppuStack_264 = (undefined1 **)0x8;
        ppuStack_268 = (undefined1 **)0x45bb67;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45bb75;
        local_b4 = (undefined1 *)FUN_00487080();
        ppuStack_264 = (undefined1 **)0x5;
        ppuStack_268 = (undefined1 **)0x45bb8e;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45bb9c;
        local_b8 = (undefined1 *)FUN_00487080();
        ppuStack_264 = (undefined1 **)0x4;
        ppuStack_268 = (undefined1 **)0x45bbb5;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45bbc3;
        local_bc = (undefined1 *)FUN_00487080();
        ppuStack_264 = (undefined1 **)0x0;
        ppuStack_268 = (undefined1 **)&local_91;
        ppuStack_26c = &local_1c;
        ppuStack_270 = &local_28;
        ppuStack_274 = &local_98;
        ppuStack_278 = &local_9c;
        ppuStack_27c = &local_14;
        pbStack_280 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      &local_18;
        piStack_284 = &local_a0;
        piStack_288 = &local_a4;
        puStack_28c = &local_a8;
        puStack_290 = &local_ac;
        ppuStack_294 = &local_b0;
        ppuStack_298 = &local_b4;
        ppuStack_29c = &local_b8;
        ppuStack_2a0 = &local_bc;
        pbStack_2a4 = local_54;
        ppuStack_2a8 = &local_20;
        ppuStack_2ac = &local_24;
        ppuStack_2b0 = (undefined1 **)0x45bc3e;
        FUN_0049ba80();
      }
      else {
        ppuStack_264 = (undefined1 **)0x1;
        ppuStack_268 = (undefined1 **)0x45bc56;
        puVar1 = (uint *)FUN_004ce990();
        local_bd = (*puVar1 & 0xf0000) == 0x10000;
        ppuStack_264 = (undefined1 **)0x1;
        ppuStack_268 = (undefined1 **)0x45bc7e;
        puVar1 = (uint *)FUN_004ce990();
        local_c4 = (undefined1 *)((int)(*puVar1 & 0xf000) >> 0xc);
        local_c8 = (undefined1 *)0xfff0bdc0;
        local_cc = (undefined1 *)0xfff0bdc0;
        local_d0 = (undefined1 *)0xfff0bdc0;
        ppuStack_264 = (undefined1 **)0x3;
        ppuStack_268 = (undefined1 **)0x45bcc8;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45bcd6;
        local_d4 = FUN_00487080();
        ppuStack_264 = (undefined1 **)0x1;
        ppuStack_268 = (undefined1 **)0x45bcef;
        puVar1 = (uint *)FUN_004ce990();
        local_d8 = ((int)(*puVar1 & 0xf00) >> 8) + local_34;
        ppuStack_264 = (undefined1 **)0x7;
        ppuStack_268 = (undefined1 **)0x45bd1e;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45bd2c;
        local_dc = FUN_00487080();
        ppuStack_264 = (undefined1 **)0x6;
        ppuStack_268 = (undefined1 **)0x45bd45;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45bd53;
        local_e0 = FUN_00487080();
        ppuStack_264 = (undefined1 **)0x19;
        ppuStack_268 = (undefined1 **)0x45bd6c;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45bd7a;
        local_e4 = FUN_00487080();
        ppuStack_264 = (undefined1 **)0x18;
        ppuStack_268 = (undefined1 **)0x45bd93;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45bda1;
        local_e8 = (undefined1 *)FUN_00487080();
        ppuStack_264 = (undefined1 **)0x17;
        ppuStack_268 = (undefined1 **)0x45bdba;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45bdc8;
        local_ec = (undefined1 *)FUN_00487080();
        ppuStack_264 = (undefined1 **)0x16;
        ppuStack_268 = (undefined1 **)0x45bde1;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45bdef;
        local_f0 = (undefined1 *)FUN_00487080();
        ppuStack_264 = (undefined1 **)0x15;
        ppuStack_268 = (undefined1 **)0x45be08;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45be16;
        local_f4 = (undefined1 *)FUN_00487080();
        ppuStack_264 = (undefined1 **)0x14;
        ppuStack_268 = (undefined1 **)0x45be2f;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45be3d;
        local_f8 = FUN_00487080();
        ppuStack_264 = (undefined1 **)0x9;
        ppuStack_268 = (undefined1 **)0x45be56;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45be64;
        local_fc = (undefined1 *)FUN_00487080();
        ppuStack_264 = (undefined1 **)0x8;
        ppuStack_268 = (undefined1 **)0x45be7d;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45be8b;
        local_100 = (undefined1 *)FUN_00487080();
        ppuStack_264 = (undefined1 **)0x5;
        ppuStack_268 = (undefined1 **)0x45bea4;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45beb2;
        local_104 = (undefined1 *)FUN_00487080();
        ppuStack_264 = (undefined1 **)0x4;
        ppuStack_268 = (undefined1 **)0x45becb;
        puVar3 = (undefined4 *)FUN_004ce990();
        ppuStack_264 = (undefined1 **)*puVar3;
        ppuStack_268 = (undefined1 **)0x45bed9;
        local_108 = FUN_00487080();
        ppuStack_264 = (undefined1 **)&local_bd;
        ppuStack_268 = &local_1c;
        ppuStack_26c = &local_28;
        ppuStack_270 = &local_c4;
        ppuStack_274 = &local_c8;
        ppuStack_278 = &local_cc;
        ppuStack_27c = &local_d0;
        pbStack_280 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      &local_d4;
        piStack_284 = &local_d8;
        piStack_288 = &local_dc;
        puStack_28c = &local_e0;
        puStack_290 = &local_e4;
        ppuStack_294 = &local_e8;
        ppuStack_298 = &local_ec;
        ppuStack_29c = &local_f0;
        ppuStack_2a0 = &local_f4;
        pbStack_2a4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      &local_f8;
        ppuStack_2a8 = &local_fc;
        ppuStack_2ac = &local_100;
        ppuStack_2b0 = &local_104;
        puStack_2b4 = &local_108;
        pbStack_2b8 = local_54;
        ppuStack_2bc = &local_20;
        ppuStack_2c0 = &local_24;
        uStack_2c4 = 0x45bf82;
        FUN_0049edc0();
      }
      local_8 = 0xffffffff;
      ppuStack_264 = (undefined1 **)0x45bf91;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_54);
      break;
    case 2:
      ppuStack_264 = (undefined1 **)0x1;
      ppuStack_268 = (undefined1 **)0x45bfa9;
      puVar1 = (uint *)FUN_004ce990();
      local_109 = (*puVar1 & 0xf0000) == 0x10000;
      ppuStack_264 = (undefined1 **)0x1;
      ppuStack_268 = (undefined1 **)0x45bfd3;
      puVar1 = (uint *)FUN_004ce990();
      local_110 = (undefined1 *)((int)(*puVar1 & 0xf000) >> 0xc);
      ppuStack_264 = (undefined1 **)0xb;
      ppuStack_268 = (undefined1 **)0x45bfff;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c00d;
      local_114 = (undefined1 *)FUN_00487080();
      ppuStack_264 = (undefined1 **)0x3;
      ppuStack_268 = (undefined1 **)0x45c026;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c034;
      local_118 = FUN_00487080();
      ppuStack_264 = (undefined1 **)0x1;
      ppuStack_268 = (undefined1 **)0x45c04d;
      puVar1 = (uint *)FUN_004ce990();
      local_11c = ((int)(*puVar1 & 0xf00) >> 8) + local_34;
      ppuStack_264 = (undefined1 **)0x7;
      ppuStack_268 = (undefined1 **)0x45c07c;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c08a;
      local_120 = FUN_00487080();
      ppuStack_264 = (undefined1 **)0x6;
      ppuStack_268 = (undefined1 **)0x45c0a3;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c0b1;
      local_124 = FUN_00487080();
      ppuStack_264 = (undefined1 **)0x9;
      ppuStack_268 = (undefined1 **)0x45c0ca;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c0d8;
      local_128 = FUN_00487080();
      ppuStack_264 = (undefined1 **)0x8;
      ppuStack_268 = (undefined1 **)0x45c0f1;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c0ff;
      local_12c = (undefined1 *)FUN_00487080();
      ppuStack_264 = (undefined1 **)&local_109;
      ppuStack_268 = &local_1c;
      ppuStack_26c = &local_28;
      ppuStack_270 = &local_110;
      ppuStack_274 = &local_114;
      ppuStack_278 = &local_14;
      ppuStack_27c = &local_18;
      pbStack_280 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    &local_118;
      piStack_284 = &local_11c;
      piStack_288 = &local_120;
      puStack_28c = &local_124;
      puStack_290 = &local_128;
      ppuStack_294 = &local_12c;
      ppuStack_298 = (undefined1 **)0x0;
      ppuStack_29c = (undefined1 **)0x0;
      ppuStack_2a0 = (undefined1 **)0x0;
      pbStack_2a4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0
      ;
      ppuStack_2a8 = (undefined1 **)0x0;
      ppuStack_2ac = *(undefined1 ***)(param_1 + 0x10);
      ppuStack_2b0 = *(undefined1 ***)(param_1 + 0x18);
      puStack_2b4 = *(undefined4 **)(param_1 + 0x14);
      pbStack_2b8 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0
      ;
      ppuStack_2bc = (undefined1 **)0x45c192;
      pbVar4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               FUN_004cc4c0();
      local_130 = abStack_2d0;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_2d0,pbVar4);
      ppuStack_298 = (undefined1 **)FUN_00424670(local_14c);
      local_8 = 2;
      ppuStack_29c = &local_20;
      ppuStack_2a0 = &local_24;
      pbStack_2a4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x45c1ea;
      FUN_004a0cf0();
      local_8 = 0xffffffff;
      ppuStack_264 = (undefined1 **)0x45c1fc;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_14c);
      break;
    case 3:
    case 4:
      ppuStack_264 = (undefined1 **)0x45c209;
      basic_string<>();
      local_8 = 3;
      ppuStack_264 = (undefined1 **)0x1;
      ppuStack_268 = (undefined1 **)0x45c223;
      puVar1 = (uint *)FUN_004ce990();
      iVar2 = (int)(*puVar1 & 0xf0) >> 4;
      if (iVar2 == 3) {
        ppuStack_264 = (undefined1 **)0x0;
        ppuStack_268 = (undefined1 **)0x45c266;
        ppuStack_264 = (undefined1 **)FUN_004cc4c0();
        ppuStack_268 = (undefined1 **)0x45c26f;
        FUN_004cb840();
      }
      else if (iVar2 == 4) {
        local_150 = (undefined1 *)&ppuStack_27c;
        pbStack_280 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x0;
        piStack_284 = (int *)0xc;
        piStack_288 = (int *)0x45c291;
        puVar3 = (undefined4 *)FUN_004ce990();
        piStack_284 = (int *)*puVar3;
        puStack_28c = (undefined4 *)0x45c2a0;
        piStack_288 = (int *)&ppuStack_27c;
        FUN_00487160();
        pbStack_280 = local_16c;
        piStack_284 = (int *)0x45c2b2;
        ppuStack_264 = (undefined1 **)FUN_004293c0();
        local_8._0_1_ = 4;
        ppuStack_268 = (undefined1 **)0x45c2da;
        FUN_004cb840();
        local_8 = CONCAT31(local_8._1_3_,3);
        ppuStack_264 = (undefined1 **)0x45c2e9;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_16c);
      }
      ppuStack_264 = (undefined1 **)0x1;
      ppuStack_268 = (undefined1 **)0x45c2fc;
      puVar1 = (uint *)FUN_004ce990();
      local_16d = (*puVar1 & 0xf0000) == 0x10000;
      ppuStack_264 = (undefined1 **)0x1;
      ppuStack_268 = (undefined1 **)0x45c326;
      puVar1 = (uint *)FUN_004ce990();
      local_174 = (undefined1 *)((int)(*puVar1 & 0xf000) >> 0xc);
      ppuStack_264 = (undefined1 **)0xb;
      ppuStack_268 = (undefined1 **)0x45c352;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c360;
      local_178 = (undefined1 *)FUN_00487080();
      ppuStack_264 = (undefined1 **)0x3;
      ppuStack_268 = (undefined1 **)0x45c379;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c387;
      local_17c = FUN_00487080();
      ppuStack_264 = (undefined1 **)0x1;
      ppuStack_268 = (undefined1 **)0x45c3a0;
      puVar1 = (uint *)FUN_004ce990();
      local_180 = ((int)(*puVar1 & 0xf00) >> 8) + local_34;
      ppuStack_264 = (undefined1 **)0x7;
      ppuStack_268 = (undefined1 **)0x45c3cf;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c3dd;
      local_184 = FUN_00487080();
      ppuStack_264 = (undefined1 **)0x6;
      ppuStack_268 = (undefined1 **)0x45c3f6;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c404;
      local_188 = FUN_00487080();
      ppuStack_264 = (undefined1 **)0x9;
      ppuStack_268 = (undefined1 **)0x45c41d;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c42b;
      local_18c = (undefined1 *)FUN_00487080();
      ppuStack_264 = (undefined1 **)0x8;
      ppuStack_268 = (undefined1 **)0x45c444;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c452;
      local_190 = (undefined1 *)FUN_00487080();
      ppuStack_264 = (undefined1 **)0x5;
      ppuStack_268 = (undefined1 **)0x45c46b;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c479;
      local_194 = (undefined1 *)FUN_00487080();
      ppuStack_264 = (undefined1 **)0x4;
      ppuStack_268 = (undefined1 **)0x45c492;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c4a0;
      local_198 = (undefined1 *)FUN_00487080();
      ppuStack_264 = (undefined1 **)0x1;
      ppuStack_268 = (undefined1 **)&local_16d;
      ppuStack_26c = &local_1c;
      ppuStack_270 = &local_28;
      ppuStack_274 = &local_174;
      ppuStack_278 = &local_178;
      ppuStack_27c = &local_14;
      pbStack_280 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    &local_18;
      piStack_284 = &local_17c;
      piStack_288 = &local_180;
      puStack_28c = &local_184;
      puStack_290 = &local_188;
      ppuStack_294 = &local_18c;
      ppuStack_298 = &local_190;
      ppuStack_29c = &local_194;
      ppuStack_2a0 = &local_198;
      pbStack_2a4 = local_70;
      ppuStack_2a8 = &local_20;
      ppuStack_2ac = &local_24;
      ppuStack_2b0 = (undefined1 **)0x45c51b;
      FUN_0049ba80();
      local_8 = 0xffffffff;
      ppuStack_264 = (undefined1 **)0x45c52a;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_70);
    }
  }
  ppuStack_264 = (undefined1 **)0x1;
  ppuStack_268 = (undefined1 **)0x45c53d;
  puVar1 = (uint *)FUN_004ce990();
  if ((*puVar1 & 0xf) == 1) {
    ppuStack_264 = (undefined1 **)0x1;
    ppuStack_268 = (undefined1 **)0x45c55e;
    puVar1 = (uint *)FUN_004ce990();
    if ((*puVar1 & 0x4000000) == 0) {
      ppuStack_264 = (undefined1 **)0x1;
      ppuStack_268 = (undefined1 **)0x45c57f;
      puVar1 = (uint *)FUN_004ce990();
      local_199 = (*puVar1 & 0xf0000) == 0x10000;
      ppuStack_264 = (undefined1 **)0xb;
      ppuStack_268 = (undefined1 **)0x45c5a7;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c5b5;
      local_1a0 = (undefined1 *)FUN_00487080();
      ppuStack_264 = (undefined1 **)0x3;
      ppuStack_268 = (undefined1 **)0x45c5ce;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c5dc;
      local_1a4 = (undefined1 *)FUN_00487080();
      ppuStack_264 = (undefined1 **)0x1;
      ppuStack_268 = (undefined1 **)0x45c5f5;
      puVar1 = (uint *)FUN_004ce990();
      local_1a8 = (int)(*puVar1 & 0xf00) >> 8;
      ppuStack_264 = (undefined1 **)0x7;
      ppuStack_268 = (undefined1 **)0x45c621;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c62f;
      local_1ac = FUN_00487080();
      ppuStack_264 = (undefined1 **)0x6;
      ppuStack_268 = (undefined1 **)0x45c648;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c656;
      local_1b0 = FUN_00487080();
      ppuStack_264 = (undefined1 **)0x9;
      ppuStack_268 = (undefined1 **)0x45c66f;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c67d;
      local_1b4 = FUN_00487080();
      ppuStack_264 = (undefined1 **)0x8;
      ppuStack_268 = (undefined1 **)0x45c696;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c6a4;
      local_1b8 = FUN_00487080();
      ppuStack_264 = (undefined1 **)&local_199;
      ppuStack_268 = &local_1c;
      ppuStack_26c = &local_28;
      ppuStack_270 = &local_1a0;
      ppuStack_274 = &local_14;
      ppuStack_278 = &local_18;
      ppuStack_27c = &local_1a4;
      pbStack_280 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    &local_1a8;
      piStack_284 = &local_1ac;
      piStack_288 = &local_1b0;
      puStack_28c = &local_1b4;
      puStack_290 = &local_1b8;
      ppuStack_294 = &local_20;
      ppuStack_298 = &local_24;
      ppuStack_29c = (undefined1 **)0x45c704;
      FUN_004a1d80();
    }
    else {
      ppuStack_264 = (undefined1 **)0x1;
      ppuStack_268 = (undefined1 **)0x45c71c;
      puVar1 = (uint *)FUN_004ce990();
      local_1b9 = (*puVar1 & 0xf0000) == 0x10000;
      local_1c0 = (undefined1 *)0xfff0bdc0;
      local_1c4 = (undefined1 *)0xfff0bdc0;
      local_1c8 = (undefined1 *)0xfff0bdc0;
      ppuStack_264 = (undefined1 **)0x3;
      ppuStack_268 = (undefined1 **)0x45c762;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c770;
      local_1cc = (undefined1 *)FUN_00487080();
      ppuStack_264 = (undefined1 **)0x1;
      ppuStack_268 = (undefined1 **)0x45c789;
      puVar1 = (uint *)FUN_004ce990();
      local_1d0 = (int)(*puVar1 & 0xf00) >> 8;
      ppuStack_264 = (undefined1 **)0x7;
      ppuStack_268 = (undefined1 **)0x45c7b5;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c7c3;
      local_1d4 = FUN_00487080();
      ppuStack_264 = (undefined1 **)0x6;
      ppuStack_268 = (undefined1 **)0x45c7dc;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c7ea;
      local_1d8 = FUN_00487080();
      ppuStack_264 = (undefined1 **)0x19;
      ppuStack_268 = (undefined1 **)0x45c803;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c811;
      local_1dc = FUN_00487080();
      ppuStack_264 = (undefined1 **)0x18;
      ppuStack_268 = (undefined1 **)0x45c82a;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c838;
      local_1e0 = FUN_00487080();
      ppuStack_264 = (undefined1 **)0x17;
      ppuStack_268 = (undefined1 **)0x45c851;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c85f;
      local_1e4 = (undefined1 *)FUN_00487080();
      ppuStack_264 = (undefined1 **)0x16;
      ppuStack_268 = (undefined1 **)0x45c878;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c886;
      local_1e8 = (undefined1 *)FUN_00487080();
      ppuStack_264 = (undefined1 **)0x15;
      ppuStack_268 = (undefined1 **)0x45c89f;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c8ad;
      local_1ec = (undefined1 *)FUN_00487080();
      ppuStack_264 = (undefined1 **)0x14;
      ppuStack_268 = (undefined1 **)0x45c8c6;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c8d4;
      local_1f0 = (undefined1 *)FUN_00487080();
      ppuStack_264 = (undefined1 **)0x9;
      ppuStack_268 = (undefined1 **)0x45c8ed;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c8fb;
      local_1f4 = FUN_00487080();
      ppuStack_264 = (undefined1 **)0x8;
      ppuStack_268 = (undefined1 **)0x45c914;
      puVar3 = (undefined4 *)FUN_004ce990();
      ppuStack_264 = (undefined1 **)*puVar3;
      ppuStack_268 = (undefined1 **)0x45c922;
      local_1f8 = (undefined1 *)FUN_00487080();
      ppuStack_264 = (undefined1 **)&local_1b9;
      ppuStack_268 = &local_1c;
      ppuStack_26c = &local_28;
      ppuStack_270 = &local_1c0;
      ppuStack_274 = &local_1c4;
      ppuStack_278 = &local_1c8;
      ppuStack_27c = &local_1cc;
      pbStack_280 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    &local_1d0;
      piStack_284 = &local_1d4;
      piStack_288 = &local_1d8;
      puStack_28c = &local_1dc;
      puStack_290 = &local_1e0;
      ppuStack_294 = &local_1e4;
      ppuStack_298 = &local_1e8;
      ppuStack_29c = &local_1ec;
      ppuStack_2a0 = &local_1f0;
      pbStack_2a4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    &local_1f4;
      ppuStack_2a8 = &local_1f8;
      ppuStack_2ac = &local_20;
      ppuStack_2b0 = &local_24;
      puStack_2b4 = (undefined4 *)0x45c9b2;
      FUN_004a2fb0();
    }
  }
  ppuStack_264 = (undefined1 **)0x1;
  ppuStack_268 = (undefined1 **)0x45c9c5;
  puVar1 = (uint *)FUN_004ce990();
  if ((*puVar1 & 0xf) == 2) {
    ppuStack_264 = (undefined1 **)0x3;
    ppuStack_268 = (undefined1 **)0x45c9e2;
    puVar3 = (undefined4 *)FUN_004ce990();
    ppuStack_264 = (undefined1 **)*puVar3;
    ppuStack_268 = (undefined1 **)0x45c9f0;
    local_1fc = (undefined1 *)FUN_00487080();
    ppuStack_264 = &local_28;
    ppuStack_268 = &local_1c;
    ppuStack_26c = &local_1fc;
    ppuStack_270 = &local_20;
    ppuStack_274 = &local_24;
    ppuStack_278 = (undefined1 **)0x45ca17;
    FUN_004a5370();
  }
  ppuStack_264 = (undefined1 **)0x1;
  ppuStack_268 = (undefined1 **)0x45ca2a;
  puVar1 = (uint *)FUN_004ce990();
  if ((*puVar1 & 0xf) == 3) {
    ppuStack_264 = &local_20;
    ppuStack_268 = &local_24;
    ppuStack_26c = (undefined1 **)0x45ca46;
    FUN_004a5700();
  }
  ExceptionList = local_10;
  return 1;
}

