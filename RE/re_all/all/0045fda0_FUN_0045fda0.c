
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_0045fda0(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  uint *puVar4;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_c4 [16];
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_a8 [12];
  undefined4 uStack_9c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_98;
  undefined *puStack_94;
  char *pcStack_90;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_58 [28];
  int local_3c;
  undefined4 local_38;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_34 [28];
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae018;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_14 = 0;
  pcStack_90 = "Save/SaveData";
  puStack_94 = (undefined *)0x45fddb;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  pcStack_90 = (char *)0x2;
  puStack_94 = (undefined *)0x45fdf2;
  puVar2 = (undefined4 *)FUN_004ce990();
  pcStack_90 = (char *)*puVar2;
  puStack_94 = (undefined *)0x45fdff;
  cVar1 = FUN_00438d40();
  if (cVar1 == '\0') {
    pcStack_90 = (char *)0x0;
    puStack_94 = (undefined *)0x2;
    pbStack_98 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x45fe3b;
    puVar2 = (undefined4 *)FUN_004ce990();
    puStack_94 = (undefined *)*puVar2;
    pbStack_98 = local_58;
    uStack_9c = 0x45fe4a;
    pcStack_90 = (char *)FUN_00487160();
    local_8._0_1_ = 1;
    puStack_94 = (undefined *)0x45fe63;
    FUN_004cb840();
    local_8 = (uint)local_8._1_3_ << 8;
    pcStack_90 = (char *)0x45fe6f;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_58);
    local_3c = 0;
    while( true ) {
      pcStack_90 = (char *)0x0;
      puStack_94 = &DAT_007cf794;
      pbStack_98 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   0x45fe85;
      pbStack_98 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   FUN_004cbbc0();
      local_3c = (int)pbStack_98;
      if (pbStack_98 ==
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0xffffffff)
      break;
      pcStack_90 = "\\";
      puStack_94 = (undefined *)0x3;
      uStack_9c = 0x45fea1;
      FUN_004cba30();
    }
    while( true ) {
      pcStack_90 = (char *)0x0;
      puStack_94 = &DAT_007cf79c;
      pbStack_98 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   0x45feb2;
      local_3c = FUN_004cbbc0();
      if (local_3c == -1) break;
      pcStack_90 = "\\";
      puStack_94 = (undefined *)0x2;
      uStack_9c = 0x45fece;
      pbStack_98 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_3c;
      FUN_004cba30();
    }
  }
  else {
    pcStack_90 = (char *)0x2;
    puStack_94 = (undefined *)0x45fe16;
    puVar2 = (undefined4 *)FUN_004ce990();
    pcStack_90 = (char *)*puVar2;
    puStack_94 = (undefined *)0x45fe21;
    local_14 = FUN_00487080();
  }
  pcStack_90 = (char *)0x3;
  puStack_94 = (undefined *)0x45fee0;
  puVar2 = (undefined4 *)FUN_004ce990();
  local_38 = *puVar2;
  pcStack_90 = (char *)0x45fef3;
  iVar3 = FUN_004ce080();
  if (4 < iVar3) {
    pcStack_90 = (char *)0x4;
    puStack_94 = (undefined *)0x45ff08;
    puVar4 = (uint *)FUN_004ce990();
    if ((*puVar4 & 1) != 0) {
      pcStack_90 = (char *)0x3;
      puStack_94 = (undefined *)0x45ff1f;
      puVar2 = (undefined4 *)FUN_004ce990();
      pcStack_90 = (char *)*puVar2;
      puStack_94 = (undefined *)0x45ff2a;
      local_38 = FUN_00487080();
    }
  }
  pcStack_90 = (char *)0x1;
  puStack_94 = (undefined *)0x45ff3d;
  puVar2 = (undefined4 *)FUN_004ce990();
  pcStack_90 = (char *)*puVar2;
  puStack_94 = (undefined *)0x45ff4a;
  cVar1 = FUN_00438d40();
  if (cVar1 == '\0') {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_c4,local_34);
    FUN_004b5150(abStack_a8,local_14,local_38,0);
    local_8._0_1_ = 2;
    uStack_b0 = 0x45ffec;
    FUN_004ce990();
    local_8 = (uint)local_8._1_3_ << 8;
    uStack_b0 = 0x45fffb;
    FUN_00486bf0();
  }
  else {
    uStack_b0 = 0x45ff62;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_a8,local_34);
    uStack_b0 = local_14;
    uStack_b4 = 0x45ff77;
    pcStack_90 = (char *)FUN_004b3280();
    puStack_94 = (undefined *)0x1;
    pbStack_98 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x45ff8e;
    puVar2 = (undefined4 *)FUN_004ce990();
    puStack_94 = (undefined *)*puVar2;
    pbStack_98 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x45ff99;
    FUN_00486e50();
  }
  local_8 = 0xffffffff;
  pcStack_90 = (char *)0x46000e;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_34);
  ExceptionList = local_10;
  return 1;
}

