
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 __thiscall
FUN_00477140(undefined4 *param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int in_stack_00000020;
  int in_stack_00000024;
  int local_258;
  int local_254;
  char local_250 [256];
  char local_150 [260];
  void *local_4c;
  int local_48;
  size_t local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007aef27;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  local_8 = 0;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)&DAT_00a14c70);
  local_8._0_1_ = 1;
  FUN_004cb880();
  local_34 = -1;
  local_38 = 0;
  do {
    iVar2 = FUN_004cc430();
    if (iVar2 <= local_38) {
LAB_0047720e:
      if (local_34 == -1) {
        FUN_004cbb30();
        local_3c = FUN_0052e3c0();
        if (local_3c == 0) {
          cVar1 = operator!=<>();
          if ((cVar1 != '\0') || (cVar1 = operator!=<>(), cVar1 != '\0')) {
            FUN_004cbb30();
            basic_string<>();
            pcVar4 = (char *)FUN_00401c50();
            _sprintf(local_150,pcVar4);
            FUN_00438b60();
            local_8._0_1_ = 2;
            basic_string<>();
            local_8._0_1_ = 3;
            basic_string<>(&DAT_007d09c0);
            uVar5 = FUN_00401c50();
            basic_string<>(uVar5);
            local_8._0_1_ = 1;
            FUN_0042bed0();
          }
          local_8 = (uint)local_8._1_3_ << 8;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_30);
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
          ExceptionList = local_10;
          return 0;
        }
        FUN_004cbb30();
        local_44 = FUN_0052c9a0();
        local_4c = _malloc(local_44);
        FUN_0052cde0();
        thunk_FUN_00580b80();
        FUN_004cc500();
        FUN_004ce160();
        FUN_0052a200();
        FUN_004ce160();
        FUN_004ce160();
        FUN_004ce160();
        FUN_004cdf50();
        local_8._0_1_ = 4;
        FUN_004cd3f0();
        local_8._0_1_ = 1;
        FUN_004ce950();
        local_34 = FUN_004ce080();
        local_34 = local_34 + -1;
        FUN_004ce990();
        FUN_00515880();
        if ((local_40 < in_stack_00000020) || (local_48 < in_stack_00000024)) {
          basic_string<>();
          pcVar4 = (char *)FUN_00401c50();
          _sprintf(local_250,pcVar4);
          basic_string<>();
          local_8._0_1_ = 5;
          FUN_00438b60();
          local_8._0_1_ = 6;
          basic_string<>(local_250);
          local_8._0_1_ = 1;
          FUN_0042bed0();
          in_stack_00000020 = 1;
          in_stack_00000024 = 1;
        }
        FUN_004ce160();
        FUN_004ce160();
        FUN_004cde80();
        FUN_004ce950();
        for (local_254 = 0; local_254 < in_stack_00000024; local_254 = local_254 + 1) {
          for (local_258 = 0; local_258 < in_stack_00000020; local_258 = local_258 + 1) {
            FUN_004ce990();
            FUN_0052a120();
            FUN_004cde80();
            FUN_004ce160();
          }
        }
        _free(local_4c);
      }
      puVar6 = (undefined4 *)FUN_004ce990();
      *param_1 = *puVar6;
      FUN_004f09c0();
      FUN_004cde80();
      FUN_004f09c0();
      param_1[0x71] = param_1[0x70];
      param_1[0x73] = param_1[0x72];
      puVar6 = (undefined4 *)FUN_004ce990();
      param_1[0x70] = *puVar6;
      puVar6 = (undefined4 *)FUN_004ce990();
      param_1[0x72] = *puVar6;
      param_1[0xdf] = 0xffffffff;
      param_1[0xe1] = 1;
      param_1[0x9c] = in_stack_00000020;
      param_1[0x9d] = in_stack_00000024;
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_30);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
      ExceptionList = local_10;
      return 1;
    }
    FUN_004cc4c0();
    cVar1 = FUN_004ec8f0();
    if (((cVar1 != '\0') && (piVar3 = (int *)FUN_004ce990(), *piVar3 == in_stack_00000020)) &&
       (piVar3 = (int *)FUN_004ce990(), *piVar3 == in_stack_00000024)) {
      local_34 = local_38;
      goto LAB_0047720e;
    }
    local_38 = local_38 + 1;
  } while( true );
}

