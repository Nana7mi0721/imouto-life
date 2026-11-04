
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0047a5d0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  bool bVar6;
  undefined1 auStack_178 [4];
  undefined4 uStack_174;
  undefined1 *puStack_170;
  undefined4 uStack_16c;
  int iStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined1 auStack_15c [20];
  undefined4 uStack_148;
  undefined1 *puStack_144;
  undefined1 auStack_140 [4];
  undefined4 uStack_13c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_138;
  int iStack_134;
  int iStack_130;
  int iStack_12c;
  int local_120;
  undefined4 local_114;
  int local_f4;
  int local_e8;
  undefined4 local_dc;
  undefined4 local_d8;
  int local_d4;
  int local_cc;
  int local_c8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_b4 [28];
  undefined1 *local_98;
  undefined1 *local_94;
  undefined1 *local_90;
  undefined1 *local_8c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_88 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_6c [28];
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af144;
  local_10 = ExceptionList;
  if (((param_2 < 2) && (DAT_0084b224 != 2)) && (DAT_0084b224 != 3)) {
    if ((param_2 == 0) && (-2 < param_3)) {
      if (param_3 < -1) {
        local_c8 = -1;
      }
      else {
        local_c8 = param_3;
      }
      DAT_00a18a34 = local_c8;
    }
    if (param_2 != 1) {
      return;
    }
    if (param_3 < -1) {
      return;
    }
    if (param_3 < -1) {
      local_cc = -1;
    }
    else {
      local_cc = param_3;
    }
    DAT_00a18a38 = local_cc;
    return;
  }
  if (((param_2 == 2) && (DAT_0084b224 != 1)) && (DAT_0084b224 != 3)) {
    return;
  }
  if (param_3 == 0xffff) {
    param_3 = -1;
  }
  ExceptionList = &local_10;
  if (*(char *)(param_1 + 0x130) == '\0') {
    ExceptionList = &local_10;
    FUN_0047c920();
  }
  if (param_2 == 0) {
    if (param_3 == DAT_00a18a34) {
      if ((-1 < param_3) && (param_5 != 0)) {
        if (*(char *)(param_1 + 0x11c) == '\0') {
          if (*(char *)(param_1 + 0x11c) == '\0') {
            iStack_12c = 0x47a751;
            FUN_0055f370();
            iStack_12c = param_5;
            iStack_130 = 0x47a767;
            FUN_0055d2a0();
            iStack_12c = 3;
            iStack_130 = *(undefined4 *)(param_1 + 0x60);
            iStack_134 = 0x47a77d;
            FUN_00561a00();
          }
        }
        else {
          iStack_12c = 0x47a705;
          FUN_00401000();
          iStack_12c = 0x47a70c;
          FUN_00401470();
          iStack_12c = 0;
          iStack_130 = param_5;
          iStack_134 = *(undefined4 *)(param_1 + 0x134);
          pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x1;
          uStack_13c = 0x47a728;
          FUN_00401000();
          uStack_13c = 0x47a72f;
          FUN_00401430();
        }
      }
      if (param_3 < 0) {
        ExceptionList = local_10;
        return;
      }
      iStack_12c = 1;
      iStack_130 = param_3;
      iStack_134 = 1;
      pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x47a79f;
      local_14 = FUN_0046f7f0();
      if (local_14 == 0) {
        local_14 = 100;
      }
      DAT_00a14344 = local_14;
      ExceptionList = local_10;
      return;
    }
    if (*(int *)(param_1 + 0x5c) != 0) {
      iStack_12c = 0x47a7de;
      piVar2 = (int *)FUN_004cc020();
      if (*(int *)(param_1 + 0x5c) != *piVar2) {
        iStack_12c = 0;
        iStack_130 = 0x47a7fc;
        FUN_0055cf80();
        iStack_12c = 0;
        iStack_130 = 0x47a816;
        FUN_0047c5e0();
      }
    }
    if ((*(char *)(param_1 + 0x11d) != '\0') && (*(char *)(param_1 + 0x11c) == '\0')) {
      iStack_12c = 0x47a83f;
      FUN_00401000();
      iStack_12c = 0x47a846;
      FUN_00401470();
      iStack_12c = 0x47a84d;
      FUN_0052eb30();
    }
    *(undefined1 *)(param_1 + 0x11d) = *(undefined1 *)(param_1 + 0x11c);
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x60);
    if (param_3 == -1) {
      *(undefined1 *)(param_1 + 0x11c) = 0;
      if (*(char *)(param_1 + 0x11c) == '\0') {
        *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x80);
        *(undefined4 *)(param_1 + 0x80) = 0;
        if (param_4 == 0) {
          if (DAT_00a18a34 < DAT_00a14328) {
            iStack_12c = *(undefined4 *)(param_1 + 0x5c);
            iStack_130 = 0x47a920;
            FUN_00515700();
          }
          iStack_12c = 0x47a939;
          FUN_004cc020();
          iStack_12c = 0x47a948;
          puVar3 = (undefined4 *)FUN_004cc020();
          *puVar3 = 0;
          iStack_12c = 0x47a964;
          puVar3 = (undefined4 *)FUN_004cc020();
          *puVar3 = 0;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x80);
        *(undefined4 *)(param_1 + 0x80) = 0;
      }
      DAT_00a18a34 = 0xffffffff;
      *(undefined4 *)(param_1 + 0x60) = 0;
      *(int *)(param_1 + 0x6c) = param_4 + 1;
      *(int *)(param_1 + 0x74) = param_4 + 1;
      *(undefined4 *)(param_1 + 0xa4) = 0;
      iStack_12c = 0x47a9be;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a18b94,""
                );
      ExceptionList = local_10;
      return;
    }
    DAT_00a18a34 = param_3;
    if (param_3 < 0) {
      ExceptionList = local_10;
      return;
    }
    if (*(char *)(param_1 + 0x11d) != '\0') {
      iStack_12c = 0x47a9fc;
      FUN_004ce990();
    }
    iStack_12c = 0x47aa11;
    piVar2 = (int *)FUN_004ce990();
    if (*piVar2 == 1) {
      if (DAT_00a117b0 == 0) {
        ExceptionList = local_10;
        return;
      }
      *(undefined1 *)(param_1 + 0x11c) = 1;
      *(undefined4 *)(param_1 + 0x60) = 0;
      *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x80);
      iStack_12c = 0x47aa61;
      FUN_00401000();
      iStack_12c = 0x47aa68;
      FUN_00401510();
      DAT_00a18a34 = param_3;
      iStack_12c = 2;
      iStack_130 = param_3;
      iStack_134 = 1;
      pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x47aa8a;
      local_1c = FUN_0046f7f0();
      if (local_1c == 0) {
        local_1c = 100;
      }
      *(int *)(param_1 + 0x8c) = local_1c;
      iStack_12c = 0x47aaca;
      FUN_00401000();
      iStack_12c = 0x47aad1;
      FUN_004014e0();
      *(undefined4 *)(param_1 + 0x138) = 6;
      iStack_12c = 1;
      iStack_130 = param_3;
      iStack_134 = 1;
      pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x47aafa;
      local_20 = FUN_0046f7f0();
      if (local_20 == 0) {
        local_20 = 100;
      }
      *(int *)(param_1 + 0x80) = (local_20 * DAT_00a18b88) / 100;
      DAT_00a14344 = local_20;
      *(undefined4 *)(param_1 + 0xa4) = 0;
      *(int *)(param_1 + 0x6c) = param_4 + 1;
      *(int *)(param_1 + 0x74) = param_4 + 1;
      iStack_12c = 3;
      iStack_130 = param_3;
      iStack_134 = 1;
      pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x47ab77;
      iVar4 = FUN_0046f7f0();
      if (iVar4 < -0x18) {
        local_d4 = -0x18;
      }
      else {
        iStack_12c = 3;
        iStack_130 = param_3;
        iStack_134 = 1;
        pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x47aba1;
        local_d4 = FUN_0046f7f0();
      }
      if (local_d4 < 0x19) {
        iStack_12c = 3;
        iStack_130 = param_3;
        iStack_134 = 1;
        pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x47abd5;
        iVar4 = FUN_0046f7f0();
        if (iVar4 < -0x18) {
          local_dc = 0xffffffe8;
        }
        else {
          iStack_12c = 3;
          iStack_130 = param_3;
          iStack_134 = 1;
          pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x47abff;
          local_dc = FUN_0046f7f0();
        }
        local_d8 = local_dc;
      }
      else {
        local_d8 = 0x18;
      }
      local_18 = local_d8;
      *(int *)(param_1 + 0x134) = param_3 + 1;
      iStack_12c = 0;
      iStack_130 = param_5;
      iStack_134 = param_3 + 1;
      pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x1
      ;
      uStack_13c = 0x47ac44;
      FUN_00401000();
      uStack_13c = 0x47ac4b;
      FUN_00401430();
      bVar6 = *(int *)(param_1 + 0x80) == 0;
      if (bVar6) {
        FUN_00401000();
        FUN_004014a0();
      }
      iStack_12c = 0;
      iStack_130 = param_3;
      iStack_134 = 1;
      pbStack_138 = local_6c;
      uStack_13c = 0x47ac93;
      DAT_00a1431c = bVar6;
      FUN_0046ff30();
      local_8 = 0;
      iStack_12c = 0x47acbd;
      FUN_004cb840();
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_6c);
      iStack_12c = 1;
      iStack_130 = param_3;
      iStack_134 = 1;
      pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x47ace5;
      local_e8 = FUN_0046f7f0();
      if (local_e8 == 0) {
        local_e8 = 100;
      }
      _DAT_00a14318 = param_3 + 1;
      DAT_00a18bcc = local_e8;
      DAT_00a18bd0 = *(undefined4 *)(param_1 + 0x8c);
      DAT_00a18bd4 = 0;
      ExceptionList = local_10;
      return;
    }
    iStack_12c = 0x47ad4f;
    piVar2 = (int *)FUN_004ce990();
    if (*piVar2 != 0) {
      ExceptionList = local_10;
      return;
    }
    *(undefined1 *)(param_1 + 0x11c) = 0;
    if (*(int *)(param_1 + 0x5c) != 0) {
      iStack_12c = 1;
      iStack_130 = 0x47ad88;
      FUN_0047c5e0();
    }
    if (-1 < param_3) {
      iStack_12c = param_2;
      iStack_130 = 0x47ada5;
      cVar1 = FUN_0047bc30();
      if (cVar1 == '\0') {
        *(int *)(param_1 + 0x6c) = param_4 + 1;
        *(int *)(param_1 + 0x74) = param_4 + 1;
        iStack_12c = 1;
        iStack_130 = param_3;
        iStack_134 = 1;
        pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x47ade7;
        uVar5 = FUN_0046f7f0();
        *(undefined4 *)(param_1 + 0x80) = uVar5;
        DAT_00a18bcc = *(undefined4 *)(param_1 + 0x80);
        DAT_00a18bd0 = *(undefined4 *)(param_1 + 0x8c);
        iStack_12c = 3;
        iStack_130 = param_3;
        iStack_134 = 1;
        pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x47ae2f;
        DAT_00a18bd4 = FUN_0046f7f0();
        ExceptionList = local_10;
        return;
      }
    }
    iStack_12c = 0x47ae4e;
    piVar2 = (int *)FUN_004cc020();
    if (*piVar2 == 0) {
      local_8c = auStack_140;
      puStack_144 = &DAT_007d0621;
      uStack_148 = 0x47b21c;
      basic_string<>();
      local_8 = 2;
      local_90 = auStack_15c;
      puStack_170 = auStack_15c;
      uStack_160 = 0;
      uStack_164 = 0;
      iStack_168 = param_3;
      uStack_16c = 1;
      uStack_174 = 0x47b25a;
      FUN_0046ff30();
      local_8 = CONCAT31(local_8._1_3_,3);
      local_98 = auStack_178;
      basic_string<>(&DAT_007d0ab0);
      uVar5 = FUN_00401c50();
      local_94 = auStack_178;
      basic_string<>(uVar5);
      local_8 = 0xffffffff;
      FUN_0042bed0();
      DAT_00a18a34 = 0xffffffff;
      *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x80);
      *(undefined4 *)(param_1 + 0x80) = 0;
      *(undefined4 *)(param_1 + 0x60) = 0;
      *(undefined4 *)(param_1 + 0xa4) = 0;
      DAT_00a14344 = 0;
      iStack_12c = 0x47b32d;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a18b94,""
                );
      ExceptionList = local_10;
      return;
    }
    *(undefined4 *)(param_1 + 0xe8) = 3;
    iStack_12c = 0x47ae7c;
    puVar3 = (undefined4 *)FUN_004cc020();
    *(undefined4 *)(param_1 + 0x60) = *puVar3;
    *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x80);
    iStack_12c = 1;
    iStack_130 = param_3;
    iStack_134 = 1;
    pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x47aeb8;
    local_30 = FUN_0046f7f0();
    if (local_30 == 0) {
      local_30 = 100;
    }
    *(int *)(param_1 + 0x80) = (local_30 * DAT_00a18b88) / 100;
    DAT_00a14344 = local_30;
    *(undefined4 *)(param_1 + 0xa4) = 0;
    *(int *)(param_1 + 0x6c) = param_4 + 1;
    *(int *)(param_1 + 0x74) = param_4 + 1;
    iStack_12c = 3;
    iStack_130 = param_3;
    iStack_134 = 1;
    pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x47af35;
    local_28 = FUN_0046f7f0();
    if (local_28 == 0) {
      iStack_12c = 0x47af71;
      piVar2 = (int *)FUN_004cc020();
      if (*piVar2 == 0) {
        iStack_12c = 0;
        iStack_130 = 0x47afb6;
        FUN_00562590();
      }
      else {
        iStack_12c = param_1 + 0x60;
        iStack_130 = 0x47af98;
        puVar3 = (undefined4 *)FUN_004cc020();
        iStack_12c = *puVar3;
        iStack_130 = 0x47afa0;
        FUN_005622d0();
      }
      iStack_12c = 0x47afd1;
      piVar2 = (int *)FUN_004cc020();
      if (*piVar2 != 0) {
        iStack_12c = param_1 + 0x60;
        iStack_130 = 0x47aff8;
        puVar3 = (undefined4 *)FUN_004cc020();
        iStack_12c = *puVar3;
        iStack_130 = 0x47b000;
        FUN_00562520();
      }
    }
    else {
      iStack_130 = 0x47af51;
      iStack_12c = local_28;
      FUN_00562590();
    }
    local_2c = 100;
    iStack_12c = 2;
    iStack_130 = param_3;
    iStack_134 = 1;
    pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x47b023;
    local_2c = FUN_0046f7f0();
    if (local_2c < 1) {
      *(undefined4 *)(param_1 + 0x8c) = 100;
      iStack_12c = 0xffffffff;
      iStack_130 = 0x47b0ab;
      FUN_0055d100();
    }
    else {
      iStack_12c = 0x47b041;
      FUN_004cc020();
      iStack_12c = 0x47b050;
      piVar2 = (int *)FUN_004cc020();
      iStack_12c = (local_2c * *piVar2) / 100;
      *(int *)(param_1 + 0x8c) = local_2c;
      iStack_130 = 0x47b085;
      local_38 = iStack_12c;
      FUN_0055d100();
    }
    if (*(int *)(param_1 + 0x5c) != *(int *)(param_1 + 0x60)) {
      iStack_12c = 0;
      iStack_130 = 0x47b0d3;
      FUN_0055cf80();
    }
    if (param_5 < 1) {
      if (*(int *)(param_1 + 0x5c) != *(int *)(param_1 + 0x60)) {
        iStack_12c = 3;
        iStack_130 = *(undefined4 *)(param_1 + 0x60);
        iStack_134 = 0x47b131;
        FUN_00561a00();
      }
    }
    else {
      iStack_12c = param_5;
      iStack_130 = 0x47b0ef;
      FUN_0055d2a0();
      iStack_12c = 3;
      iStack_130 = *(undefined4 *)(param_1 + 0x60);
      iStack_134 = 0x47b105;
      FUN_00561a00();
    }
    iStack_12c = 0;
    iStack_130 = param_3;
    iStack_134 = 1;
    pbStack_138 = local_88;
    uStack_13c = 0x47b154;
    FUN_0046ff30();
    local_8 = 1;
    iStack_12c = 0x47b17e;
    FUN_004cb840();
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_88);
    iStack_12c = 1;
    iStack_130 = param_3;
    iStack_134 = 1;
    pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x47b1a9;
    local_34 = FUN_0046f7f0();
    if (local_34 == 0) {
      local_f4 = 100;
    }
    else {
      local_f4 = local_34;
    }
    DAT_00a18bcc = local_f4;
    DAT_00a18bd0 = *(undefined4 *)(param_1 + 0x8c);
    iStack_12c = 3;
    iStack_130 = param_3;
    iStack_134 = 1;
    pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x47b1fd;
    DAT_00a18bd4 = FUN_0046f7f0();
    ExceptionList = local_10;
    return;
  }
  if ((param_2 != 1) || (DAT_00a18a38 == param_3)) goto LAB_0047b999;
  if (*(int *)(param_1 + 100) != 0) {
    if (-1 < param_3) {
      iStack_12c = 0x47b37a;
      piVar2 = (int *)FUN_004cc020();
      if (*piVar2 != 0) {
        iStack_12c = 0x47b394;
        piVar2 = (int *)FUN_004cc020();
        if (*(int *)(param_1 + 100) != *piVar2) {
          iStack_12c = 0;
          iStack_130 = 0x47b3b2;
          FUN_0055cf80();
          iStack_12c = 1;
          iStack_130 = 0x47b3cc;
          FUN_0047c5e0();
        }
        goto LAB_0047b3ff;
      }
    }
    if (param_3 == -1) {
      iStack_12c = 0;
      iStack_130 = 0x47b3e5;
      FUN_0055cf80();
      iStack_12c = 1;
      iStack_130 = 0x47b3ff;
      FUN_0047c5e0();
    }
  }
LAB_0047b3ff:
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x68);
  if (param_3 < 0) {
    if (param_3 == -1) {
      *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x88);
      *(undefined4 *)(param_1 + 0x88) = 0;
      if (param_4 == 0) {
        if (DAT_00a18a38 < DAT_00a1432c) {
          iStack_12c = *(undefined4 *)(param_1 + 100);
          iStack_130 = 0x47b522;
          FUN_00515700();
        }
        iStack_12c = 0x47b53b;
        puVar3 = (undefined4 *)FUN_004cc020();
        *puVar3 = 0;
      }
      DAT_00a18a38 = 0xffffffff;
      *(undefined4 *)(param_1 + 0x68) = 0;
      *(int *)(param_1 + 0x70) = param_4 + 1;
      *(int *)(param_1 + 0x78) = param_4 + 1;
      *(undefined4 *)(param_1 + 0xa8) = 0;
      iStack_12c = 0x47b595;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a18bb0,""
                );
      ExceptionList = local_10;
      return;
    }
  }
  else {
    iStack_12c = param_2;
    iStack_130 = 0x47b42e;
    cVar1 = FUN_0047bc30();
    if (cVar1 == '\0') {
      *(int *)(param_1 + 0x70) = param_4 + 1;
      *(int *)(param_1 + 0x78) = param_4 + 1;
      iStack_12c = 1;
      iStack_130 = param_3;
      iStack_134 = 2;
      pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x47b470;
      uVar5 = FUN_0046f7f0();
      *(undefined4 *)(param_1 + 0x88) = uVar5;
      DAT_00a18bd8 = *(undefined4 *)(param_1 + 0x88);
      DAT_00a18bdc = *(undefined4 *)(param_1 + 0x90);
      iStack_12c = 3;
      iStack_130 = param_3;
      iStack_134 = 2;
      pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x47b4b8;
      DAT_00a18be0 = FUN_0046f7f0();
      ExceptionList = local_10;
      return;
    }
  }
  if (-1 < param_3) {
    iStack_12c = 0x47b5b9;
    piVar2 = (int *)FUN_004cc020();
    if (*piVar2 != 0) {
      DAT_00a18a38 = param_3;
      iStack_12c = 0x47b5df;
      puVar3 = (undefined4 *)FUN_004cc020();
      *(undefined4 *)(param_1 + 0x68) = *puVar3;
      *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x88);
      iStack_12c = 1;
      iStack_130 = param_3;
      iStack_134 = 2;
      pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x47b61b;
      local_44 = FUN_0046f7f0();
      if (local_44 == 0) {
        local_44 = 100;
      }
      *(int *)(param_1 + 0x88) = (local_44 * DAT_00a18b8c) / 100;
      if (*(int *)(param_1 + 0x88) < 2) {
        local_114 = 1;
      }
      else {
        local_114 = *(undefined4 *)(param_1 + 0x88);
      }
      *(undefined4 *)(param_1 + 0x88) = local_114;
      *(undefined4 *)(param_1 + 0xa8) = 0;
      *(int *)(param_1 + 0x70) = param_4 + 1;
      *(int *)(param_1 + 0x78) = param_4 + 1;
      DAT_00a14348 = local_44;
      iStack_12c = 3;
      iStack_130 = param_3;
      iStack_134 = 2;
      pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x47b6d8;
      local_3c = FUN_0046f7f0();
      if (local_3c == 0) {
        iStack_12c = 0x47b711;
        piVar2 = (int *)FUN_004cc020();
        if (*piVar2 == 0) {
          iStack_12c = 0;
          iStack_130 = 0x47b756;
          FUN_00562590();
        }
        else {
          iStack_12c = param_1 + 0x68;
          iStack_130 = 0x47b738;
          puVar3 = (undefined4 *)FUN_004cc020();
          iStack_12c = *puVar3;
          iStack_130 = 0x47b740;
          FUN_005622d0();
        }
      }
      else {
        iStack_130 = 0x47b6f4;
        iStack_12c = local_3c;
        FUN_00562590();
      }
      local_40 = 100;
      iStack_12c = 2;
      iStack_130 = param_3;
      iStack_134 = 2;
      pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x47b779;
      local_40 = FUN_0046f7f0();
      if (local_40 == 0) {
        *(undefined4 *)(param_1 + 0x90) = 100;
        iStack_12c = 0xffffffff;
        iStack_130 = 0x47b801;
        FUN_0055d100();
      }
      else {
        *(int *)(param_1 + 0x90) = local_40;
        iStack_12c = 0x47b7a6;
        FUN_004cc020();
        iStack_12c = 0x47b7b5;
        piVar2 = (int *)FUN_004cc020();
        iStack_12c = (local_40 * *piVar2) / 100;
        iStack_130 = 0x47b7db;
        local_48 = iStack_12c;
        FUN_0055d100();
      }
      if (param_5 < 1) {
        iStack_12c = 3;
        iStack_130 = *(undefined4 *)(param_1 + 0x68);
        iStack_134 = 0x47b84b;
        FUN_00561a00();
      }
      else {
        iStack_12c = param_5;
        iStack_130 = 0x47b81d;
        FUN_0055d2a0();
        iStack_12c = 3;
        iStack_130 = *(undefined4 *)(param_1 + 0x68);
        iStack_134 = 0x47b833;
        FUN_00561a00();
      }
      iStack_12c = 0;
      iStack_130 = 0x47b85f;
      FUN_0055cf80();
      iStack_12c = 0;
      iStack_130 = param_3;
      iStack_134 = 2;
      pbStack_138 = local_b4;
      uStack_13c = 0x47b882;
      FUN_0046ff30();
      local_8 = 4;
      iStack_12c = 0x47b8ac;
      FUN_004cb840();
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_b4);
      iStack_12c = 1;
      iStack_130 = param_3;
      iStack_134 = 2;
      pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x47b8d7;
      DAT_00a18bd8 = FUN_0046f7f0();
      DAT_00a18bdc = *(undefined4 *)(param_1 + 0x90);
      iStack_12c = 3;
      iStack_130 = param_3;
      iStack_134 = 2;
      pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x47b907;
      DAT_00a18be0 = FUN_0046f7f0();
      goto LAB_0047b999;
    }
  }
  DAT_00a18a38 = -1;
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(int *)(param_1 + 0x70) = param_4 + 1;
  *(int *)(param_1 + 0x78) = param_4 + 1;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  DAT_00a14348 = DAT_00a18bd8;
  iStack_12c = 0x47b999;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a18bb0,"");
LAB_0047b999:
  if ((param_2 == 2) && (0 < DAT_00a18b90)) {
    if (-1 < param_3) {
      iStack_12c = param_2;
      iStack_130 = 0x47b9ca;
      FUN_0047bc30();
    }
    if (param_3 == -1) {
      if (param_4 == 0) {
        FUN_0047ce50();
        ExceptionList = local_10;
        return;
      }
      iStack_12c = 0x47ba08;
      FUN_004ce160();
    }
    else {
      iStack_12c = 0x47ba1f;
      FUN_004cc020();
      iStack_12c = 0x47ba31;
      FUN_004ce160();
    }
    iStack_12c = 0x47ba46;
    FUN_004ce160();
    if (param_3 == -1) {
      iStack_12c = 0x47ba6e;
      FUN_004ce160();
    }
    else {
      iStack_12c = 3;
      iStack_130 = param_3;
      iStack_134 = 3;
      pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x47ba8c;
      FUN_0046f7f0();
      iStack_12c = 0x47baaa;
      FUN_004ce160();
      local_4c = 100;
      iStack_12c = 1;
      iStack_130 = param_3;
      iStack_134 = 3;
      pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x47baca;
      iVar4 = FUN_0046f7f0();
      if (iVar4 == 0) {
        local_4c = (DAT_00a18b90 * 100) / 100;
      }
      else {
        iStack_12c = 1;
        iStack_130 = param_3;
        iStack_134 = 3;
        pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x47bae7;
        iVar4 = FUN_0046f7f0();
        local_120 = (iVar4 * DAT_00a18b90) / 100;
        if (local_120 < 2) {
          local_120 = 1;
        }
        local_4c = local_120;
      }
      iStack_12c = 0x47bb47;
      FUN_004cc020();
      iStack_12c = 0x47bb5e;
      iStack_12c = FUN_004fe844();
      iStack_130 = 0x47bb64;
      FUN_0055cf80();
      iStack_12c = 2;
      iStack_130 = param_3;
      iStack_134 = 3;
      pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x47bb80;
      iVar4 = FUN_0046f7f0();
      if (iVar4 == 0) {
        iStack_12c = 0x47bc0e;
        FUN_004cc020();
        iStack_12c = 0xffffffff;
        iStack_130 = 0x47bc18;
        FUN_0055d100();
      }
      else {
        iStack_12c = 2;
        iStack_130 = param_3;
        iStack_134 = 3;
        pbStack_138 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x47bb9d;
        iVar4 = FUN_0046f7f0();
        iStack_12c = 0x47bbb4;
        FUN_004cc020();
        iStack_12c = 0x47bbc3;
        piVar2 = (int *)FUN_004cc020();
        local_50 = (iVar4 * *piVar2) / 100;
        iStack_12c = 0x47bbe8;
        FUN_004cc020();
        iStack_12c = local_50;
        iStack_130 = 0x47bbf4;
        FUN_0055d100();
      }
    }
  }
  ExceptionList = local_10;
  return;
}

