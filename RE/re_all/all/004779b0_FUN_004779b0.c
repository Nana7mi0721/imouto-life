
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_004779b0(char *param_1,int param_2,int param_3)

{
  int iVar1;
  char *_Format;
  int *piVar2;
  undefined4 *puVar3;
  undefined1 auStack_208 [20];
  undefined4 uStack_1f4;
  undefined1 *puStack_1f0;
  undefined1 auStack_1ec [16];
  undefined4 uStack_1dc;
  undefined *puStack_1d8;
  undefined1 *puStack_1d4;
  undefined1 auStack_1d0 [8];
  undefined4 uStack_1c8;
  int iStack_1c4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_18c [60];
  undefined1 *local_150;
  undefined1 *local_14c;
  undefined1 *local_148;
  undefined1 *local_144;
  undefined4 local_140;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  char local_128 [260];
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007aef6c;
  local_10 = ExceptionList;
  local_24 = DAT_0084b484;
  ExceptionList = &local_10;
  iVar1 = FUN_004d00e0();
  if (param_2 < iVar1) {
    FUN_004d0120();
    local_14 = FUN_004cfc90();
    if (local_14 < param_3) {
      for (local_12c = local_14; local_12c < param_3; local_12c = local_12c + 1) {
        FUN_00477ec0();
        local_8 = 2;
        FUN_004d0120();
        FUN_004cfd10();
        local_8 = 0xffffffff;
        FUN_00477f40();
        if (*param_1 != '\0') {
          basic_string<>();
          local_8 = 3;
          FUN_004d05c0();
          FUN_004cc500();
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_18c);
        }
      }
    }
    else {
      FUN_004d0120();
      FUN_004cfc60();
      if (*param_1 != '\0') {
        FUN_004d05c0();
        FUN_004cc400();
      }
    }
    local_1c = 0;
    local_20 = 0;
    local_18 = 0;
    local_130 = 0;
    while( true ) {
      FUN_004d0120();
      iVar1 = FUN_004ce080();
      if (iVar1 <= local_130) break;
      FUN_004d0120();
      piVar2 = (int *)FUN_004ce990();
      if (*piVar2 / 1000 == 1) {
        local_1c = local_1c + 1;
      }
      FUN_004d0120();
      piVar2 = (int *)FUN_004ce990();
      if (*piVar2 / 1000 == 2) {
        local_20 = local_20 + 1;
      }
      local_130 = local_130 + 1;
    }
    local_134 = 0;
    while( true ) {
      FUN_004d0120();
      iVar1 = FUN_004cfc90();
      if (iVar1 <= local_134) break;
      iStack_1c4 = 0x477d3b;
      FUN_004d0120();
      FUN_004cfcd0();
      FUN_004ce970();
      iStack_1c4 = 0x477d69;
      FUN_004d0120();
      FUN_004cfcd0();
      FUN_004cc400();
      local_134 = local_134 + 1;
    }
    if (local_14 < param_3) {
      for (local_138 = local_14; local_138 < param_3; local_138 = local_138 + 1) {
        for (local_13c = 0; local_13c < local_1c + local_20; local_13c = local_13c + 1) {
          FUN_004d0120();
          piVar2 = (int *)FUN_004ce990();
          if (*piVar2 / 1000 == 1) {
            local_140 = 0;
            FUN_004d05c0();
            iVar1 = FUN_004ce080();
            if (local_13c < iVar1) {
              FUN_004d05c0();
              puVar3 = (undefined4 *)FUN_004ce990();
              local_140 = *puVar3;
            }
            iStack_1c4 = param_2;
            uStack_1c8 = 0x477e98;
            FUN_00477f90();
          }
        }
      }
    }
  }
  else {
    local_144 = (undefined1 *)&puStack_1d4;
    puStack_1d8 = &DAT_007d0a00;
    uStack_1dc = 0x477a0c;
    basic_string<>();
    puStack_1d8 = (undefined *)0x477a17;
    _Format = (char *)FUN_00401c50();
    iStack_1c4 = 0x477a33;
    _sprintf(local_128,_Format);
    local_148 = auStack_1d0;
    puStack_1d4 = &DAT_007d0621;
    puStack_1d8 = (undefined *)0x477a4b;
    basic_string<>();
    local_8 = 0;
    local_14c = auStack_1ec;
    puStack_1f0 = auStack_1ec;
    uStack_1f4 = 0x477a75;
    FUN_00438b60();
    local_8 = CONCAT31(local_8._1_3_,1);
    local_150 = auStack_208;
    basic_string<>(local_128);
    local_8 = 0xffffffff;
    FUN_0042bed0();
  }
  ExceptionList = local_10;
  return;
}

