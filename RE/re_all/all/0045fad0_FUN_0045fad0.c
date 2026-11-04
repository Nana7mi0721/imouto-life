
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_0045fad0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_c8 [12];
  undefined4 uStack_bc;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_b8;
  undefined *puStack_b4;
  char *pcStack_b0;
  char local_a9;
  undefined4 local_a8;
  char local_a1;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 local_81;
  undefined1 *local_80;
  undefined1 *local_7c;
  undefined1 *local_78;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_74 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_58 [31];
  char local_39;
  int local_38;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_34 [28];
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007adff6;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_14 = 0;
  pcStack_b0 = "Save/SaveData";
  puStack_b4 = (undefined *)0x45fb10;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  pcStack_b0 = (char *)0x0;
  puStack_b4 = (undefined *)0x2;
  pbStack_b8 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x45fb2c
  ;
  puVar1 = (undefined4 *)FUN_004ce990();
  puStack_b4 = (undefined *)*puVar1;
  pbStack_b8 = local_58;
  uStack_bc = 0x45fb3e;
  puStack_b4 = (undefined *)FUN_00487160();
  local_8._0_1_ = 1;
  pcStack_b0 = "<<ERROR>>";
  pbStack_b8 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x45fb65
  ;
  local_90 = puStack_b4;
  local_8c = puStack_b4;
  local_39 = FUN_004ec750();
  local_8 = (uint)local_8._1_3_ << 8;
  pcStack_b0 = (char *)0x45fb77;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_58);
  if (local_39 == '\0') {
    pcStack_b0 = (char *)0x0;
    puStack_b4 = (undefined *)0x2;
    pbStack_b8 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x45fbbd;
    puVar1 = (undefined4 *)FUN_004ce990();
    puStack_b4 = (undefined *)*puVar1;
    pbStack_b8 = local_74;
    uStack_bc = 0x45fbcf;
    pcStack_b0 = (char *)FUN_00487160();
    local_8._0_1_ = 2;
    puStack_b4 = (undefined *)0x45fbf4;
    local_98 = pcStack_b0;
    local_94 = pcStack_b0;
    FUN_004cb840();
    local_8 = (uint)local_8._1_3_ << 8;
    pcStack_b0 = (char *)0x45fc00;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_74);
    local_38 = 0;
    while( true ) {
      pcStack_b0 = (char *)0x0;
      puStack_b4 = &DAT_007cf774;
      pbStack_b8 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   0x45fc16;
      pbStack_b8 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   FUN_004cbbc0();
      local_38 = (int)pbStack_b8;
      if (pbStack_b8 ==
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0xffffffff)
      break;
      pcStack_b0 = "\\";
      puStack_b4 = (undefined *)0x3;
      uStack_bc = 0x45fc32;
      FUN_004cba30();
    }
    while( true ) {
      pcStack_b0 = (char *)0x0;
      puStack_b4 = &DAT_007cf77c;
      pbStack_b8 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   0x45fc43;
      local_38 = FUN_004cbbc0();
      if (local_38 == -1) break;
      pcStack_b0 = "\\";
      puStack_b4 = (undefined *)0x2;
      uStack_bc = 0x45fc5f;
      pbStack_b8 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_38;
      FUN_004cba30();
    }
  }
  else {
    pcStack_b0 = (char *)0x2;
    puStack_b4 = (undefined *)0x45fb92;
    puVar1 = (undefined4 *)FUN_004ce990();
    pcStack_b0 = (char *)*puVar1;
    puStack_b4 = (undefined *)0x45fba0;
    local_14 = FUN_00487080();
  }
  pcStack_b0 = (char *)0x1;
  puStack_b4 = (undefined *)0x45fc74;
  piVar2 = (int *)FUN_004ce990();
  if (*piVar2 == 0) {
    local_78 = abStack_c8;
    local_9c = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
               basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_c8,local_34);
    FUN_004a5ca0(local_14,1);
  }
  else {
    pcStack_b0 = (char *)0x1;
    puStack_b4 = (undefined *)0x45fcb8;
    piVar2 = (int *)FUN_004ce990();
    if (*piVar2 == 1) {
      local_7c = abStack_c8;
      local_a0 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                 basic_string<char,std::char_traits<char>,std::allocator<char>_>
                           (abStack_c8,local_34);
      local_a1 = FUN_004ab7b0(local_14,1,0);
      if (local_a1 != '\0') {
        pcStack_b0 = (char *)0x45fd02;
        FUN_0045ceb0();
        DAT_00a117ae = 1;
        DAT_00a18984 = 0;
      }
    }
    else {
      pcStack_b0 = (char *)0x1;
      puStack_b4 = (undefined *)0x45fd28;
      piVar2 = (int *)FUN_004ce990();
      if (*piVar2 == 2) {
        local_80 = abStack_c8;
        local_a8 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                   basic_string<char,std::char_traits<char>,std::allocator<char>_>
                             (abStack_c8,local_34);
        local_a9 = FUN_004ab7b0(local_14,0,1);
        if (local_a9 != '\0') {
          DAT_00a117ae = 1;
        }
      }
    }
  }
  local_81 = 1;
  local_8 = 0xffffffff;
  pcStack_b0 = (char *)0x45fd81;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_34);
  ExceptionList = local_10;
  return local_81;
}

