
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0047df80(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_1)

{
  void *pvVar1;
  void *pvVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  int *piVar8;
  size_t sVar9;
  int in_stack_00000020;
  undefined4 in_stack_00000024;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_258 [28];
  int local_23c;
  int local_238;
  char *local_234;
  void *local_230;
  char *local_22c;
  char local_228 [256];
  char local_128 [256];
  undefined4 local_28;
  void *local_1c;
  size_t local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007af2ff;
  local_10 = ExceptionList;
  local_28 = DAT_0084b484;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_004cbb30();
  FUN_004ec870();
  local_8._0_1_ = 1;
  FUN_004cb840();
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_258);
  if (1 < in_stack_00000020) {
    FUN_004ccca0();
    FUN_004ce060();
    cVar3 = const_iterator__operator__();
    if (cVar3 != '\0') {
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
      ExceptionList = local_10;
      return;
    }
    goto LAB_0047e1d7;
  }
  FUN_004e5650();
  iVar4 = FUN_004cbbc0();
  if (iVar4 == DAT_007d0624) {
    FUN_004e5650();
    iVar4 = FUN_004cbbc0();
    if (iVar4 == DAT_007d0624) {
      puVar5 = (undefined4 *)FUN_004ce990();
      *puVar5 = 0;
      puVar5 = (undefined4 *)FUN_004ce990();
      *puVar5 = 0;
      FUN_004e5650();
      iVar4 = FUN_004cbbc0();
      if (iVar4 == DAT_007d0624) {
        FUN_004e5650();
        iVar4 = FUN_004cbbc0();
        if (iVar4 != DAT_007d0624) goto LAB_0047e0f1;
      }
      else {
LAB_0047e0f1:
        puVar5 = (undefined4 *)FUN_004ce990();
        *puVar5 = 1;
      }
      FUN_004ccca0();
      FUN_004ce060();
      cVar3 = const_iterator__operator__();
      if (cVar3 != '\0') {
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
        ExceptionList = local_10;
        return;
      }
      goto LAB_0047e1d7;
    }
  }
  puVar5 = (undefined4 *)FUN_004ce990();
  *puVar5 = 1;
LAB_0047e1d7:
  iVar4 = FUN_004cbbc0();
  if ((((iVar4 != -1) || (iVar4 = FUN_004cbbc0(), iVar4 != -1)) ||
      (iVar4 = FUN_004cbbc0(), iVar4 != -1)) || (iVar4 = FUN_004cbbc0(), iVar4 != -1)) {
    FUN_004cbb30();
    basic_string<>();
    pcVar6 = (char *)FUN_00401c50();
    _sprintf(local_128,pcVar6);
    FUN_00438b60();
    local_8._0_1_ = 2;
    basic_string<>();
    local_8._0_1_ = 3;
    basic_string<>(&DAT_007d0c98);
    uVar7 = FUN_00401c50();
    basic_string<>(uVar7);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0042bed0();
  }
  FUN_004cbb30();
  local_14 = FUN_0052e3c0();
  if (local_14 == 0) {
    FUN_004cbb30();
    basic_string<>();
    pcVar6 = (char *)FUN_00401c50();
    _sprintf(local_228,pcVar6);
    cVar3 = operator!=<>();
    if (cVar3 != '\0') {
      basic_string<>();
      local_8._0_1_ = 4;
      basic_string<>();
      local_8._0_1_ = 5;
      basic_string<>(&DAT_007d0b5c);
      uVar7 = FUN_00401c50();
      basic_string<>(uVar7);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0042bed0();
    }
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
  }
  else {
    FUN_004cbb30();
    local_18 = FUN_0052c9a0();
    local_1c = _malloc(local_18);
    FUN_0052cde0();
    thunk_FUN_00580b80();
    if (in_stack_00000020 < 2) {
      FUN_00551400();
      FUN_005513d0();
    }
    else {
      FUN_00551400();
      FUN_005513d0();
    }
    if (in_stack_00000020 == 2) {
      FUN_005513d0();
      uVar7 = FUN_00563040();
      puVar5 = (undefined4 *)FUN_004cc680();
      *puVar5 = uVar7;
      FUN_004cc680();
      uVar7 = FUN_005611b0();
      FUN_004cc680();
      puVar5 = (undefined4 *)FUN_004cc020();
      *puVar5 = uVar7;
    }
    else {
      FUN_005513d0();
      if (in_stack_00000020 == 0) {
        piVar8 = (int *)FUN_004ce990();
        if (*piVar8 == 1) {
          FUN_00401000();
          FUN_00401600();
        }
        else {
          FUN_00401000();
          FUN_00401640();
          uVar7 = FUN_00563040();
          puVar5 = (undefined4 *)FUN_004cc680();
          *puVar5 = uVar7;
          FUN_004cc680();
          uVar7 = FUN_005611b0();
          FUN_004cc680();
          puVar5 = (undefined4 *)FUN_004cc020();
          *puVar5 = uVar7;
          FUN_004cc680();
          FUN_0047e980();
        }
      }
      if (in_stack_00000020 == 1) {
        uVar7 = FUN_00563040();
        puVar5 = (undefined4 *)FUN_004cc680();
        *puVar5 = uVar7;
        FUN_004cc680();
        uVar7 = FUN_005611b0();
        FUN_004cc680();
        puVar5 = (undefined4 *)FUN_004cc020();
        *puVar5 = uVar7;
      }
      piVar8 = (int *)FUN_004ce990();
      if (*piVar8 != 1) {
        local_230 = local_1c;
        local_22c = "LOOPSTART=";
        local_234 = "LOOPSTART=";
        while (local_230 = _memchr(local_230,0x4c,(1000 - (int)local_230) + (int)local_1c),
              local_230 != (void *)0x0) {
          sVar9 = _strlen(local_22c);
          iVar4 = _memcmp(local_230,local_22c,sVar9);
          pvVar2 = local_1c;
          pvVar1 = local_230;
          if (iVar4 == 0) {
            sVar9 = _strlen(local_22c);
            local_238 = 0;
            for (local_23c = (int)pvVar1 + (sVar9 - (int)pvVar2);
                (0x2f < *(byte *)((int)local_1c + local_23c) &&
                (*(byte *)((int)local_1c + local_23c) < 0x3a)); local_23c = local_23c + 1) {
              local_238 = local_238 * 10 + -0x30 + (uint)*(byte *)((int)local_1c + local_23c);
            }
            FUN_004cc680();
            piVar8 = (int *)FUN_004cc020();
            *piVar8 = local_238;
          }
          local_230 = (void *)((int)local_230 + 1);
        }
      }
    }
    _free(local_1c);
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
  }
  ExceptionList = local_10;
  return;
}

