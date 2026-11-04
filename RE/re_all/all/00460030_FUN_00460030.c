
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_00460030(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  uint *puVar4;
  undefined4 uVar5;
  undefined1 auStack_c4 [12];
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_a8 [12];
  undefined4 uStack_9c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_98;
  undefined *puStack_94;
  char *pcStack_90;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_58 [28];
  int local_3c;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_38 [28];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae042;
  local_10 = ExceptionList;
  local_1c = DAT_0084b484;
  local_18 = 0;
  pcStack_90 = "Save/SaveData";
  puStack_94 = (undefined *)0x46006b;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  pcStack_90 = (char *)0x2;
  puStack_94 = (undefined *)0x460082;
  puVar2 = (undefined4 *)FUN_004ce990();
  pcStack_90 = (char *)*puVar2;
  puStack_94 = (undefined *)0x46008f;
  cVar1 = FUN_00438d40();
  if (cVar1 == '\0') {
    pcStack_90 = (char *)0x0;
    puStack_94 = (undefined *)0x2;
    pbStack_98 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x4600cb;
    puVar2 = (undefined4 *)FUN_004ce990();
    puStack_94 = (undefined *)*puVar2;
    pbStack_98 = local_58;
    uStack_9c = 0x4600da;
    pcStack_90 = (char *)FUN_00487160();
    local_8._0_1_ = 1;
    puStack_94 = (undefined *)0x4600f3;
    FUN_004cb840();
    local_8 = (uint)local_8._1_3_ << 8;
    pcStack_90 = (char *)0x4600ff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_58);
    local_3c = 0;
    while( true ) {
      pcStack_90 = (char *)0x0;
      puStack_94 = &DAT_007cf7b4;
      pbStack_98 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   0x460115;
      pbStack_98 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   FUN_004cbbc0();
      local_3c = (int)pbStack_98;
      if (pbStack_98 ==
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0xffffffff)
      break;
      pcStack_90 = "\\";
      puStack_94 = (undefined *)0x3;
      uStack_9c = 0x460131;
      FUN_004cba30();
    }
    while( true ) {
      pcStack_90 = (char *)0x0;
      puStack_94 = &DAT_007cf7bc;
      pbStack_98 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   0x460142;
      local_3c = FUN_004cbbc0();
      if (local_3c == -1) break;
      pcStack_90 = "\\";
      puStack_94 = (undefined *)0x2;
      uStack_9c = 0x46015e;
      pbStack_98 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_3c;
      FUN_004cba30();
    }
  }
  else {
    pcStack_90 = (char *)0x2;
    puStack_94 = (undefined *)0x4600a6;
    puVar2 = (undefined4 *)FUN_004ce990();
    pcStack_90 = (char *)*puVar2;
    puStack_94 = (undefined *)0x4600b1;
    local_18 = FUN_00487080();
  }
  pcStack_90 = (char *)0x3;
  puStack_94 = (undefined *)0x460170;
  puVar2 = (undefined4 *)FUN_004ce990();
  local_14 = *puVar2;
  pcStack_90 = (char *)0x460183;
  iVar3 = FUN_004ce080();
  if (4 < iVar3) {
    pcStack_90 = (char *)0x4;
    puStack_94 = (undefined *)0x460198;
    puVar4 = (uint *)FUN_004ce990();
    if ((*puVar4 & 1) != 0) {
      pcStack_90 = (char *)0x3;
      puStack_94 = (undefined *)0x4601af;
      puVar2 = (undefined4 *)FUN_004ce990();
      pcStack_90 = (char *)*puVar2;
      puStack_94 = (undefined *)0x4601ba;
      local_14 = FUN_00487080();
    }
  }
  pcStack_90 = (char *)0x1;
  puStack_94 = (undefined *)0x4601cd;
  puVar2 = (undefined4 *)FUN_004ce990();
  pcStack_90 = (char *)*puVar2;
  puStack_94 = (undefined *)0x4601da;
  cVar1 = FUN_00438d40();
  if (cVar1 == '\0') {
    uStack_b0 = 0x460244;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_a8,local_38);
    local_8._0_1_ = 3;
    uVar5 = 0;
    puVar2 = (undefined4 *)FUN_004ce990(1);
    FUN_00487160(auStack_c4,*puVar2,uVar5);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_004b57d0(local_18,local_14);
  }
  else {
    uStack_b0 = 0x4601f2;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_a8,local_38);
    local_8._0_1_ = 2;
    uStack_b0 = 0x46020f;
    FUN_004ce990();
    uStack_b0 = 0x46021a;
    FUN_00487080();
    uStack_b0 = local_14;
    uStack_b4 = local_18;
    local_8 = (uint)local_8._1_3_ << 8;
    uStack_b8 = 0x460231;
    FUN_004b5390();
  }
  local_8 = 0xffffffff;
  pcStack_90 = (char *)0x4602a6;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_38);
  ExceptionList = local_10;
  return 1;
}

