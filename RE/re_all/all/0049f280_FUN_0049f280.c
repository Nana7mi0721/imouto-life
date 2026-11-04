
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
FUN_0049f280(undefined4 *param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  int in_stack_0000002c;
  int in_stack_00000030;
  int in_stack_00000034;
  int in_stack_00000038;
  int in_stack_0000003c;
  int in_stack_00000040;
  int in_stack_00000044;
  int in_stack_00000048;
  int in_stack_0000004c;
  uint in_stack_00000050;
  undefined4 in_stack_00000054;
  int in_stack_00000058;
  int in_stack_0000005c;
  uint in_stack_00000060;
  undefined2 uStack00000064;
  uint in_stack_00000068;
  int in_stack_0000006c;
  int in_stack_00000070;
  undefined4 uStack_6a0;
  undefined1 *puStack_69c;
  undefined1 auStack_698 [4];
  undefined4 uStack_694;
  int local_5d0;
  int local_5cc;
  char local_530 [256];
  int local_430;
  int local_42c;
  int local_428;
  int local_424;
  char local_420 [512];
  char local_220 [516];
  undefined4 local_1c;
  float local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007afafb;
  local_10 = ExceptionList;
  local_1c = DAT_0084b484;
  local_8 = 0;
  if (0 < in_stack_0000006c) {
    ExceptionList = &local_10;
    FUN_004cdf50();
    local_8._0_1_ = 1;
    FUN_004cd3f0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_004ce950();
    FUN_004cc500();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce950();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
    ExceptionList = local_10;
    return;
  }
  ExceptionList = &local_10;
  *(undefined1 *)((int)param_1 + 0x27a) = 0;
  *(undefined1 *)(param_1 + 0x9e) = 0;
  *(undefined1 *)((int)param_1 + 0x279) = 0;
  *(undefined1 *)(param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x265) = 0;
  param_1[0xdf] = 0xffffffff;
  if (*(char *)(param_1 + 0x90) == '\0') {
    param_1[0x80] = param_1[0x9f];
    param_1[0x88] = param_1[0xa1];
    param_1[0x81] = param_1[0xa0];
    param_1[0x89] = param_1[0xa1];
    param_1[0x82] = param_1[0x9f];
    param_1[0x8a] = param_1[0xa2];
    param_1[0x83] = param_1[0xa0];
    param_1[0x8b] = param_1[0xa2];
  }
  if (*(char *)((int)param_1 + 0x265) == '\0') {
    if ((in_stack_00000020 < 1) || (in_stack_00000024 < 1)) {
      if (DAT_00a117a8 != 0) {
        basic_string<>();
        pcVar2 = (char *)FUN_00401c50();
        uStack_694 = 0x49f94f;
        _sprintf(local_220,pcVar2);
        puStack_69c = auStack_698;
        uStack_6a0 = 0x49f963;
        FUN_00438b60();
        local_8._0_1_ = 2;
        basic_string<>();
        FUN_00401c50();
        basic_string<>();
        local_8._0_1_ = 3;
        basic_string<>(local_220);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0042bed0();
      }
      if (in_stack_00000020 < 1) {
        local_5cc = 1;
      }
      else {
        local_5cc = in_stack_00000020;
      }
      in_stack_00000020 = local_5cc;
      if (in_stack_00000024 < 1) {
        local_5d0 = 1;
      }
      else {
        local_5d0 = in_stack_00000024;
      }
      in_stack_00000024 = local_5d0;
    }
    if (9999 < in_stack_00000020 * in_stack_00000024) {
      basic_string<>();
      pcVar2 = (char *)FUN_00401c50();
      uStack_694 = 0x49faa7;
      _sprintf(local_420,pcVar2);
      puStack_69c = auStack_698;
      uStack_6a0 = 0x49fabb;
      FUN_00438b60();
      local_8._0_1_ = 4;
      basic_string<>();
      FUN_00401c50();
      basic_string<>();
      local_8._0_1_ = 5;
      basic_string<>(local_420);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0042bed0();
      *(undefined1 *)((int)param_1 + 0x279) = 1;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
      ExceptionList = local_10;
      return;
    }
    iVar3 = FUN_00515710();
    if (31999 < iVar3 + in_stack_00000020 * in_stack_00000024) {
      puStack_69c = &DAT_007d0621;
      uStack_6a0 = 0x49fba2;
      basic_string<>();
      local_8._0_1_ = 6;
      FUN_00438b60();
      local_8._0_1_ = 7;
      basic_string<>(&DAT_007d12d0);
      uVar4 = FUN_00401c50();
      basic_string<>(uVar4);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0042bed0();
      *(undefined1 *)((int)param_1 + 0x279) = 1;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
      ExceptionList = local_10;
      return;
    }
  }
  if ((in_stack_00000050 & 0x100) != 0) {
    if ((in_stack_00000070 == 0) ||
       ((in_stack_00000070 != 0 && (*(char *)((int)param_1 + 0x266) == '\0')))) {
      uVar5 = DAT_00a17ebc >> 0x1f;
      in_stack_00000028 = ((int)(DAT_00a17ebc + (uVar5 & 3)) >> 2) + in_stack_00000028;
      uVar6 = DAT_00a17ec0 >> 0x1f;
      in_stack_0000002c = ((int)(DAT_00a17ec0 + (uVar6 & 3)) >> 2) + in_stack_0000002c;
      in_stack_00000030 = ((int)(DAT_00a17ebc + (uVar5 & 3)) >> 2) + in_stack_00000030;
      in_stack_00000034 = ((int)(DAT_00a17ec0 + (uVar6 & 3)) >> 2) + in_stack_00000034;
      in_stack_00000038 = ((int)(DAT_00a17ebc + (uVar5 & 3)) >> 2) + in_stack_00000038;
      in_stack_0000003c = ((int)(DAT_00a17ec0 + (uVar6 & 3)) >> 2) + in_stack_0000003c;
      in_stack_00000040 = ((int)(DAT_00a17ebc + (uVar5 & 3)) >> 2) + in_stack_00000040;
      in_stack_00000044 = ((int)(DAT_00a17ec0 + (uVar6 & 3)) >> 2) + in_stack_00000044;
    }
    *(undefined1 *)((int)param_1 + 0x266) = 1;
  }
  if (((*(char *)((int)param_1 + 0x266) != '\0') && ((in_stack_00000050 & 0x100) == 0)) &&
     (*(undefined1 *)((int)param_1 + 0x266) = 0, in_stack_00000070 != 0)) {
    uVar5 = DAT_00a17ebc >> 0x1f;
    in_stack_00000028 = in_stack_00000028 - ((int)(DAT_00a17ebc + (uVar5 & 3)) >> 2);
    uVar6 = DAT_00a17ec0 >> 0x1f;
    in_stack_0000002c = in_stack_0000002c - ((int)(DAT_00a17ec0 + (uVar6 & 3)) >> 2);
    in_stack_00000030 = in_stack_00000030 - ((int)(DAT_00a17ebc + (uVar5 & 3)) >> 2);
    in_stack_00000034 = in_stack_00000034 - ((int)(DAT_00a17ec0 + (uVar6 & 3)) >> 2);
    in_stack_00000038 = in_stack_00000038 - ((int)(DAT_00a17ebc + (uVar5 & 3)) >> 2);
    in_stack_0000003c = in_stack_0000003c - ((int)(DAT_00a17ec0 + (uVar6 & 3)) >> 2);
    in_stack_00000040 = in_stack_00000040 - ((int)(DAT_00a17ebc + (uVar5 & 3)) >> 2);
    in_stack_00000044 = in_stack_00000044 - ((int)(DAT_00a17ec0 + (uVar6 & 3)) >> 2);
  }
  in_stack_00000050 = in_stack_00000050 & 0xf;
  param_1[1] = *param_1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_6a0,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &param_2);
  cVar1 = FUN_00477140();
  if (cVar1 == '\0') {
    *(undefined1 *)((int)param_1 + 0x279) = 1;
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  }
  else {
    cVar1 = operator!=<>();
    if (cVar1 != '\0') {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_6a0,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 (param_1 + 0x54));
      FUN_004361d0();
    }
    FUN_004cb840();
    FUN_004cb840();
    FUN_0049ec50();
    if ((int)param_1[0x6c] < 1) {
      for (local_42c = 0; local_42c < 4; local_42c = local_42c + 1) {
        param_1[local_42c + 0x84] = param_1[local_42c + 0x80];
        param_1[local_42c + 0x8c] = param_1[local_42c + 0x88];
      }
      param_1[0x67] = param_1[0x66];
      param_1[0x69] = param_1[0x68];
      param_1[0x6b] = param_1[0x6a];
      param_1[0x75] = param_1[0x74];
      param_1[0x77] = param_1[0x76];
      param_1[0x6f] = param_1[0x6e];
      for (local_430 = 0; local_430 < 3; local_430 = local_430 + 1) {
        param_1[local_430 + 0x7b] = param_1[local_430 + 0x78];
      }
    }
    else {
      for (local_424 = 0; local_424 < 4; local_424 = local_424 + 1) {
        param_1[local_424 + 0x84] =
             (int)((param_1[local_424 + 0x84] - param_1[local_424 + 0x80]) * param_1[0x6c]) /
             (int)param_1[0x6d] + param_1[local_424 + 0x80];
        param_1[local_424 + 0x8c] =
             (int)((param_1[local_424 + 0x8c] - param_1[local_424 + 0x88]) * param_1[0x6c]) /
             (int)param_1[0x6d] + param_1[local_424 + 0x88];
      }
      param_1[0x75] =
           (int)((param_1[0x75] - param_1[0x74]) * param_1[0x6c]) / (int)param_1[0x6d] +
           param_1[0x74];
      param_1[0x77] =
           (int)((param_1[0x77] - param_1[0x76]) * param_1[0x6c]) / (int)param_1[0x6d] +
           param_1[0x76];
      iVar3 = FUN_004fe844();
      param_1[0x6f] = iVar3 + param_1[0x6e];
      for (local_428 = 0; local_428 < 3; local_428 = local_428 + 1) {
        param_1[local_428 + 0x7b] =
             (int)((param_1[local_428 + 0x7b] - param_1[local_428 + 0x78]) * param_1[0x6c]) /
             (int)param_1[0x6d] + param_1[local_428 + 0x78];
      }
    }
    *(undefined2 *)((int)param_1 + 0x26a) = *(undefined2 *)(param_1 + 0x9a);
    if (in_stack_00000070 == 0) {
      param_1[0x80] = in_stack_00000028;
      param_1[0x81] = in_stack_00000030;
      param_1[0x82] = in_stack_00000038;
      param_1[0x83] = in_stack_00000040;
      param_1[0x88] = in_stack_0000002c;
      param_1[0x89] = in_stack_00000034;
      param_1[0x8a] = in_stack_0000003c;
      param_1[0x8b] = in_stack_00000044;
    }
    else {
      param_1[0x80] = param_1[0x84] + in_stack_00000028;
      param_1[0x81] = param_1[0x85] + in_stack_00000030;
      param_1[0x82] = param_1[0x86] + in_stack_00000038;
      param_1[0x83] = param_1[0x87] + in_stack_00000040;
      param_1[0x88] = param_1[0x8c] + in_stack_0000002c;
      param_1[0x89] = param_1[0x8d] + in_stack_00000034;
      param_1[0x8a] = param_1[0x8e] + in_stack_0000003c;
      param_1[0x8b] = param_1[0x8f] + in_stack_00000044;
    }
    local_18 = 0.0;
    local_14 = 0.0;
    if (param_1[1] != 0) {
      switch(*(undefined2 *)((int)param_1 + 0x26a)) {
      case 1:
        local_18 = (float)((int)param_1[0x70] / 2) + 0.0;
        local_14 = (float)((int)param_1[0x72] / 2) + 0.0;
        break;
      case 2:
        local_14 = (float)(int)param_1[0x72] + 0.0;
        break;
      case 3:
        local_18 = (float)(int)param_1[0x70] + 0.0;
        break;
      case 4:
        local_18 = (float)(int)param_1[0x70] + 0.0;
        local_14 = (float)(int)param_1[0x72] + 0.0;
      }
      switch(_uStack00000064) {
      case 1:
        local_18 = local_18 - (float)((int)param_1[0x70] / 2);
        local_14 = local_14 - (float)((int)param_1[0x72] / 2);
        break;
      case 2:
        local_14 = local_14 - (float)(int)param_1[0x72];
        break;
      case 3:
        local_18 = local_18 - (float)(int)param_1[0x70];
        break;
      case 4:
        local_18 = local_18 - (float)(int)param_1[0x70];
        local_14 = local_14 - (float)(int)param_1[0x72];
      }
      local_18 = (float)((int)param_1[0x75] / 100) * local_18;
      local_14 = (float)((int)param_1[0x77] / 100) * local_14;
    }
    iVar3 = FUN_004fe844();
    param_1[99] = param_1[99] - iVar3;
    iVar3 = FUN_004fe844();
    param_1[0x65] = param_1[0x65] - iVar3;
    if (in_stack_00000048 != -1000000) {
      param_1[0x66] = in_stack_00000048;
    }
    if (in_stack_0000004c != -1000000) {
      param_1[0x68] = in_stack_0000004c;
    }
    if (in_stack_00000050 != 0xf) {
      param_1[0x6a] = in_stack_00000050;
    }
    if (in_stack_00000058 != -1000000) {
      param_1[0x74] = in_stack_00000058;
    }
    if (in_stack_0000005c != -1000000) {
      param_1[0x76] = in_stack_0000005c;
    }
    if (in_stack_00000060 != 0xfff0bdc0) {
      param_1[0x6e] = in_stack_00000060;
    }
    *(undefined2 *)(param_1 + 0x9a) = uStack00000064;
    if ((in_stack_00000068 & 0x1000000) == 0) {
      uVar4 = FUN_004fe844();
      param_1[0x78] = uVar4;
      uVar4 = FUN_004fe844();
      param_1[0x79] = uVar4;
      uVar4 = FUN_004fe844();
      param_1[0x7a] = uVar4;
    }
    if (param_1[1] == 0) {
      param_1[0x80] = in_stack_00000028;
      param_1[0x84] = in_stack_00000028;
      param_1[0x88] = in_stack_0000002c;
      param_1[0x8c] = in_stack_0000002c;
      param_1[0x81] = in_stack_00000030;
      param_1[0x85] = in_stack_00000030;
      param_1[0x89] = in_stack_00000034;
      param_1[0x8d] = in_stack_00000034;
      param_1[0x82] = in_stack_00000038;
      param_1[0x86] = in_stack_00000038;
      param_1[0x8a] = in_stack_0000003c;
      param_1[0x8e] = in_stack_0000003c;
      param_1[0x83] = in_stack_00000040;
      param_1[0x87] = in_stack_00000040;
      param_1[0x8b] = in_stack_00000044;
      param_1[0x8f] = in_stack_00000044;
      param_1[0x67] = in_stack_00000048;
      param_1[0x69] = 0;
      param_1[0x6b] = in_stack_00000050;
      param_1[0x75] = param_1[0x74];
      param_1[0x77] = param_1[0x76];
      param_1[0x6f] = (in_stack_00000060 == 0xfff0bdc0) - 1 & in_stack_00000060;
      param_1[0x71] = param_1[0x70];
      param_1[0x73] = param_1[0x72];
      *(undefined2 *)((int)param_1 + 0x26a) = *(undefined2 *)(param_1 + 0x9a);
      if ((in_stack_00000068 & 0x1000000) == 0) {
        uVar4 = FUN_004fe844();
        param_1[0x7b] = uVar4;
        uVar4 = FUN_004fe844();
        param_1[0x7c] = uVar4;
        uVar4 = FUN_004fe844();
        param_1[0x7d] = uVar4;
      }
    }
    else {
      *(undefined2 *)((int)param_1 + 0x26a) = *(undefined2 *)(param_1 + 0x9a);
      param_1[0x71] = param_1[0x70];
      param_1[0x73] = param_1[0x72];
    }
    iVar3 = FUN_004ce080();
    if ((iVar3 < (int)param_1[0x66]) && (iVar3 = FUN_004ce080(), iVar3 != 0)) {
      FUN_004ce080();
      basic_string<>();
      pcVar2 = (char *)FUN_00401c50();
      uStack_694 = 0x4a0b91;
      _sprintf(local_530,pcVar2);
      puStack_69c = auStack_698;
      uStack_6a0 = 0x4a0ba5;
      FUN_00438b60();
      local_8._0_1_ = 8;
      basic_string<>();
      FUN_00401c50();
      basic_string<>();
      local_8._0_1_ = 9;
      basic_string<>(local_530);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0042bed0();
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
    }
    else {
      *(undefined1 *)(param_1 + 0x90) = 1;
      param_1[0x7f] = 0;
      param_1[0x7e] = 0;
      param_1[0x6c] = in_stack_00000054;
      param_1[0x6d] = in_stack_00000054;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
    }
  }
  ExceptionList = local_10;
  return;
}

