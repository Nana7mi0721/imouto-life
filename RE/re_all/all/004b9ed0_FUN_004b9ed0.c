
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __thiscall FUN_004b9ed0(int param_1,undefined4 param_2,char param_3)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  char *pcVar5;
  LPCSTR pCVar6;
  size_t sVar7;
  int iVar8;
  undefined1 *puVar9;
  void *pvVar10;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *this;
  short *psVar11;
  ushort *puVar12;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *this_00;
  undefined4 uVar13;
  undefined1 uStack00000000;
  UINT UVar14;
  uint uVar15;
  int local_6c4;
  uint local_6c0;
  int local_6bc;
  int local_6b8;
  int local_6b4;
  char local_6b0 [256];
  char local_5b0 [256];
  char local_4b0 [260];
  int local_3ac;
  char local_3a8 [516];
  size_t local_1a4;
  int local_1a0;
  int local_19c;
  char local_198 [308];
  undefined4 local_64;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  int local_4c;
  uint local_48;
  uint local_44;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined4 local_2c;
  uint local_28;
  int local_24;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b07ae;
  local_10 = ExceptionList;
  local_64 = DAT_0084b484;
  ExceptionList = &local_10;
  local_24 = FUN_0052e3c0();
  if (local_24 == 0) {
    if (param_3 != '\0') {
      basic_string<>();
      pcVar5 = (char *)FUN_00401c50();
      _sprintf(local_198,pcVar5);
      UVar14 = 1;
      basic_string<>();
      pCVar6 = (LPCSTR)FUN_00401c50();
      MessageBoxA((HWND)0x0,local_198,pCVar6,UVar14);
    }
    uVar13 = 0;
  }
  else {
    DAT_00a11790 = 0;
    if (DAT_00a117ec == 0) {
      sVar7 = FUN_0052c9a0();
      DAT_00a0f830 = _malloc(sVar7);
      sVar7 = FUN_0052c9a0();
      _memset(DAT_00a0f830,0,sVar7);
    }
    local_2c = FUN_0052c9a0();
    FUN_0052cde0();
    thunk_FUN_00580b80();
    local_40 = *DAT_00a0f830;
    local_3f = DAT_00a0f830[8];
    local_3e = DAT_00a0f830[6];
    local_50 = DAT_00a0f830[2];
    local_4f = DAT_00a0f830[3];
    local_4e = DAT_00a0f830[4];
    if ((((DAT_00a0f830[1] != 'W') || (DAT_00a0f830[4] != 'O')) || (DAT_00a0f830[5] != 'L')) ||
       ((DAT_00a0f830[7] != 'F' || (DAT_00a0f830[8] != 'M')))) {
      basic_string<>();
      FUN_0041b9e0();
    }
    DAT_00a11790 = DAT_00a11790 + 10;
    if (&uStack00000000 == (undefined1 *)0x48) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_48,DAT_00a0f830 + DAT_00a11790,4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    iVar8 = FUN_004cd730();
    if (iVar8 < (int)local_48) {
      FUN_004cf7d0();
    }
    for (local_19c = 0; local_19c < (int)local_48; local_19c = local_19c + 1) {
      iVar8 = FUN_004cd7c0();
      if (iVar8 == 0) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 1;
        sVar7 = 1;
        puVar9 = DAT_00a0f830 + DAT_00a11790;
        pvVar10 = (void *)FUN_004cd7c0();
        _memcpy(pvVar10,puVar9,sVar7);
      }
      DAT_00a11790 = DAT_00a11790 + 1;
    }
    local_48 = FUN_004cc430();
    if (&uStack00000000 == (undefined1 *)0x48) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_48,DAT_00a0f830 + DAT_00a11790,4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    iVar8 = FUN_004cc430();
    if (iVar8 < (int)local_48) {
      FUN_004cc400();
    }
    for (local_1a0 = 0; local_1a0 < (int)local_48; local_1a0 = local_1a0 + 1) {
      if (&uStack00000000 == (undefined1 *)0x1a4) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        _memcpy(&local_1a4,DAT_00a0f830 + DAT_00a11790,4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      if (&uStack00000000 == (undefined1 *)0x3a8) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = local_1a4;
        _memcpy(local_3a8,DAT_00a0f830 + DAT_00a11790,local_1a4);
      }
      DAT_00a11790 = DAT_00a11790 + local_1a4;
      pcVar5 = local_3a8;
      this = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)FUN_004cc4c0();
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(this,pcVar5);
    }
    local_48 = DAT_00a11790;
    FUN_004d0ca0();
    local_8 = 0;
    FUN_004d0ca0();
    local_8._0_1_ = 1;
    FUN_004d0ca0();
    local_8 = CONCAT31(local_8._1_3_,2);
    if (&uStack00000000 == (undefined1 *)0x4c) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_4c,DAT_00a0f830 + DAT_00a11790,4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    if (&uStack00000000 == (undefined1 *)0x48) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_48,DAT_00a0f830 + DAT_00a11790,4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::resize
              (*(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)
                (param_1 + 0x114),local_48);
    FUN_004d0c40();
    if (&uStack00000000 == (undefined1 *)0x48) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_48,DAT_00a0f830 + DAT_00a11790,4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    iVar8 = FUN_004d0c60();
    if (iVar8 < (int)local_48) {
      FUN_004d0c40();
    }
    for (local_3ac = 0; local_3ac < (int)local_48; local_3ac = local_3ac + 1) {
      iVar8 = FUN_004d0cd0();
      if (iVar8 == 0) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 2;
        sVar7 = 2;
        puVar9 = DAT_00a0f830 + DAT_00a11790;
        pvVar10 = (void *)FUN_004d0cd0();
        _memcpy(pvVar10,puVar9,sVar7);
      }
      DAT_00a11790 = DAT_00a11790 + 2;
    }
    DAT_0084b218 = (int)**(char **)(param_1 + 0x9c);
    if ('\x01' < **(char **)(param_1 + 0x90)) {
      DAT_0084b218 = 1;
    }
    if ((param_3 != '\0') && (0xde < **(short **)(param_1 + 0xf8))) {
      _sprintf(local_6b0,"%d.%02d");
      _sprintf(local_4b0,"%d.%02d");
      basic_string<>();
      pcVar5 = (char *)FUN_00401c50();
      _sprintf(local_5b0,pcVar5);
      UVar14 = 0;
      basic_string<>();
      pCVar6 = (LPCSTR)FUN_00401c50();
      MessageBoxA((HWND)0x0,local_5b0,pCVar6,UVar14);
    }
    DAT_0084b268 = (int)**(char **)(param_1 + 0x90);
    if (&uStack00000000 == (undefined1 *)0x48) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_48,DAT_00a0f830 + DAT_00a11790,4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    local_28 = local_48;
    if (&uStack00000000 == (undefined1 *)0x48) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_48,DAT_00a0f830 + DAT_00a11790,4);
    }
    local_44 = local_48;
    DAT_00a11790 = local_28;
    FUN_004d0c60();
    FUN_004d0c40();
    FUN_004d0c60();
    FUN_004d0c40();
    for (local_6b4 = 0; iVar8 = FUN_004d0c60(), local_6b4 < iVar8; local_6b4 = local_6b4 + 1) {
      iVar8 = FUN_004d0cd0();
      if (iVar8 == 0) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 2;
        sVar7 = 2;
        puVar9 = DAT_00a0f830 + DAT_00a11790;
        pvVar10 = (void *)FUN_004d0cd0();
        _memcpy(pvVar10,puVar9,sVar7);
      }
      DAT_00a11790 = DAT_00a11790 + 2;
    }
    DAT_00a11790 = local_44;
    for (local_6b8 = 0; iVar8 = FUN_004d0c60(), local_6b8 < iVar8; local_6b8 = local_6b8 + 1) {
      iVar8 = FUN_004d0cd0();
      if (iVar8 == 0) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 2;
        sVar7 = 2;
        puVar9 = DAT_00a0f830 + DAT_00a11790;
        pvVar10 = (void *)FUN_004d0cd0();
        _memcpy(pvVar10,puVar9,sVar7);
      }
      DAT_00a11790 = DAT_00a11790 + 2;
    }
    for (local_6bc = 0; iVar8 = FUN_004d0c60(), local_6bc < iVar8; local_6bc = local_6bc + 1) {
      psVar11 = (short *)FUN_004d0cd0();
      sVar1 = *psVar11;
      psVar11 = (short *)FUN_004d0cd0();
      sVar2 = *psVar11;
      psVar11 = (short *)FUN_004d0cd0();
      *psVar11 = sVar1 + sVar2;
    }
    for (local_6c0 = 0; iVar8 = FUN_004d0c60(), (int)local_6c0 < iVar8; local_6c0 = local_6c0 + 1) {
      puVar12 = (ushort *)FUN_004d0cd0();
      uVar3 = *puVar12;
      uVar15 = local_6c0;
      this_00 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                FUN_004cc4c0();
      pcVar5 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               operator[](this_00,uVar15);
      *pcVar5 = DAT_00a0f830[uVar3];
    }
    local_48 = (uint)(byte)DAT_00a0f830[local_4c];
    if (local_48 != 0xc2) {
      basic_string<>();
      local_8._0_1_ = 3;
      basic_string<>();
      local_8._0_1_ = 4;
      basic_string<>(&DAT_007d1a30);
      uVar13 = FUN_00401c50();
      basic_string<>(uVar13);
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_0042bed0();
    }
    if (DAT_00a117ec == 0) {
      _free(DAT_00a0f830);
    }
    **(undefined1 **)(param_1 + 0x58) = 1;
    for (local_6c4 = 0; local_6c4 < 7; local_6c4 = local_6c4 + 1) {
      if (**(short **)(param_1 + 0xb4 + local_6c4 * 4) < 1) {
        uVar4 = 1;
      }
      else {
        uVar4 = **(undefined2 **)(param_1 + 0xb4 + local_6c4 * 4);
      }
      **(undefined2 **)(param_1 + 0xb4 + local_6c4 * 4) = uVar4;
      if (**(short **)(param_1 + 0xd0 + local_6c4 * 4) < 1) {
        uVar4 = 1;
      }
      else {
        uVar4 = **(undefined2 **)(param_1 + 0xd0 + local_6c4 * 4);
      }
      **(undefined2 **)(param_1 + 0xd0 + local_6c4 * 4) = uVar4;
    }
    if (**(char **)(param_1 + 0xa0) == '\0') {
      **(short **)(param_1 + 0xf0) = **(char **)(param_1 + 0x4c) * 0x14;
      **(short **)(param_1 + 0xf4) = **(char **)(param_1 + 0x4c) * 0xf;
    }
    local_8._0_1_ = 1;
    FUN_004f7a10();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_004f7a10();
    local_8 = 0xffffffff;
    FUN_004f7a10();
    uVar13 = 1;
  }
  ExceptionList = local_10;
  return uVar13;
}

