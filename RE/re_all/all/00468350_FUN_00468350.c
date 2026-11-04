
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 __thiscall FUN_00468350(undefined1 *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar6;
  int iVar7;
  undefined1 *puVar8;
  char *_Format;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> bStack00000028;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_ef8 [8];
  undefined4 uStack_ef0;
  undefined4 uStack_eec;
  char local_e40 [512];
  int local_c40;
  int local_c3c;
  int local_c38;
  int local_c34;
  int local_c30;
  undefined4 local_c2c;
  int local_c28;
  int local_c24;
  int local_c20;
  undefined4 local_c1c;
  int local_c18;
  undefined4 local_c14;
  int local_c10;
  undefined *local_c0c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007ae4c1;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_8 = 2;
  local_14 = param_2;
  ExceptionList = &local_10;
  FUN_00481020();
  local_8._0_1_ = 3;
  iVar2 = FUN_004cfab0();
  if (local_14 < iVar2) {
    local_c0c = &DAT_00a1817c;
    while (iVar2 = FUN_004d21f0(), 0 < iVar2) {
      local_c0c = (undefined *)FUN_004d2250();
    }
    if (param_2 == -1) {
      iVar2 = FUN_004cbbc0();
      if (iVar2 == DAT_007d0624) {
        FUN_004e9510();
        puVar3 = (undefined4 *)FUN_004ccca0();
        local_c2c = *puVar3;
        FUN_004ce060();
        cVar1 = const_iterator__operator__();
        if (cVar1 == '\0') {
          local_8._0_1_ = 2;
          FUN_00481330();
          local_8._0_1_ = 1;
          FUN_004ce950();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_004cc250();
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    (&bStack00000028);
          ExceptionList = local_10;
          return 1;
        }
        iVar2 = FUN_004d07e0();
        local_c18 = *(int *)(iVar2 + 0x1c);
      }
      else {
        FUN_004e9510();
        puVar3 = (undefined4 *)FUN_004ccca0();
        local_c1c = *puVar3;
        FUN_004ce060();
        cVar1 = const_iterator__operator__();
        if (cVar1 == '\0') {
          iVar2 = FUN_004d07e0();
          local_c18 = *(int *)(iVar2 + 0x1c);
        }
        else {
          local_c24 = FUN_004cfab0();
          FUN_004cfab0();
          FUN_004cbb30();
          uStack_eec = 0x468493;
          local_c20 = FUN_004a5a90();
          if (local_c20 == -1) {
            local_8._0_1_ = 2;
            FUN_00481330();
            local_8._0_1_ = 1;
            FUN_004ce950();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_004cc250();
            local_8 = 0xffffffff;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      (&bStack00000028);
            ExceptionList = local_10;
            return 1;
          }
          piVar4 = (int *)FUN_004cc680();
          *piVar4 = local_c24;
          for (local_c28 = local_c24; local_c28 < local_c24 + local_c20; local_c28 = local_c28 + 1)
          {
            FUN_004cfb40();
            piVar4 = (int *)FUN_004cc680();
            *piVar4 = local_c28;
          }
          local_c18 = local_c24;
        }
      }
      local_14 = local_c18 + 500000;
      if (500 < *(int *)(param_1 + 4)) {
        basic_string<>();
        local_8._0_1_ = 4;
        FUN_00438b60();
        local_8._0_1_ = 5;
        basic_string<>(&DAT_007cffe8);
        uVar5 = FUN_00401c50();
        basic_string<>(uVar5);
        local_8._0_1_ = 3;
        FUN_0042bed0();
      }
      local_c10 = 0;
      local_c30 = 0;
      while (iVar2 = FUN_004ce080(), local_c30 < iVar2) {
        if (local_c10 < 5) {
          FUN_004ce990();
          FUN_00487080();
          FUN_00486e50();
        }
        else {
          FUN_004ce990();
          FUN_00487080();
          FUN_00486e50();
        }
        local_c10 = local_c10 + 1;
        local_c30 = local_c30 + 1;
      }
      local_c34 = 0;
      while (iVar2 = FUN_004cc430(), local_c34 < iVar2) {
        pbVar6 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 FUN_004cc4c0();
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_ef8,pbVar6);
        FUN_00486bf0();
        local_c10 = local_c10 + 1;
        local_c34 = local_c34 + 1;
      }
      local_c14 = FUN_004cfb40();
      *(int *)(param_1 + 0x82c) = local_14 % 500000;
      FUN_004d21c0();
      uStack_eec = 0;
      uStack_ef0 = 0x4688e1;
      FUN_004d2250();
      uStack_eec = 0x4688e8;
      FUN_0044ecd0();
      iVar2 = *(int *)(param_1 + 4);
      iVar7 = FUN_004d2250();
      *(int *)(iVar7 + 4) = iVar2 + 1;
      puVar8 = (undefined1 *)FUN_004d2250();
      *puVar8 = *param_1;
      local_8._0_1_ = 2;
      FUN_00481330();
      local_8._0_1_ = 1;
      FUN_004ce950();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_004cc250();
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000028);
      ExceptionList = local_10;
      return 1;
    }
    local_c38 = 0;
    local_c3c = 0;
    while (iVar2 = FUN_004ce080(), local_c3c < iVar2) {
      if (local_c38 < 5) {
        FUN_004ce990();
        FUN_00487080();
        FUN_00486e50();
      }
      else {
        FUN_004ce990();
        FUN_00487080();
        FUN_00486e50();
      }
      local_c38 = local_c38 + 1;
      local_c3c = local_c3c + 1;
    }
    local_c40 = 0;
    while (iVar2 = FUN_004cc430(), local_c40 < iVar2) {
      pbVar6 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               FUN_004cc4c0();
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_ef8,pbVar6);
      FUN_00486bf0();
      local_c38 = local_c38 + 1;
      local_c40 = local_c40 + 1;
    }
    *(int *)(param_1 + 0x82c) = local_14;
    FUN_004d21c0();
    uStack_eec = 0x468b0f;
    FUN_004cfb40();
    uStack_eec = 0;
    uStack_ef0 = 0x468b23;
    FUN_004d2250();
    uStack_eec = 0x468b2a;
    FUN_0044ecd0();
  }
  else if (DAT_00a117a8 != 0) {
    FUN_004ce990();
    FUN_00487080();
    basic_string<>();
    _Format = (char *)FUN_00401c50();
    uStack_eec = 0x468ba2;
    _sprintf(local_e40,_Format);
    basic_string<>();
    local_8._0_1_ = 6;
    basic_string<>();
    local_8._0_1_ = 7;
    basic_string<>(&DAT_007d005c);
    uVar5 = FUN_00401c50();
    basic_string<>(uVar5);
    local_8._0_1_ = 3;
    FUN_0042bed0();
  }
  local_8._0_1_ = 2;
  FUN_00481330();
  local_8._0_1_ = 1;
  FUN_004ce950();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004cc250();
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000028);
  ExceptionList = local_10;
  return 1;
}

