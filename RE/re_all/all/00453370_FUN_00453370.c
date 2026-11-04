
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 __fastcall FUN_00453370(int param_1)

{
  char cVar1;
  uint *puVar2;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_124 [20];
  undefined4 uStack_110;
  int iStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_f4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_f0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_ec;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_b8 [28];
  undefined1 *local_9c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_98 [28];
  undefined1 *local_7c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_78 [28];
  int local_5c;
  int local_58;
  int local_54;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_50 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_34 [28];
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ada39;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_54 = 0;
  pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x1;
  pbStack_f0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x4533b7
  ;
  ExceptionList = &local_10;
  puVar2 = (uint *)FUN_004ce990();
  local_14 = *puVar2 & 0xf;
  pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x4533c7
  ;
  basic_string<>();
  local_8 = 0;
  pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x4533d6
  ;
  basic_string<>();
  local_8._0_1_ = 1;
  for (local_58 = 0; local_58 < (int)local_14; local_58 = local_58 + 1) {
    pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
    pbStack_f0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 (local_58 + 2);
    pbStack_f4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x453412;
    puVar2 = (uint *)FUN_004ce990();
    pbStack_f0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 (*puVar2 & 0xffffff);
    pbStack_f4 = local_78;
    uStack_f8 = 0x453429;
    pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 FUN_00487160();
    local_8._0_1_ = 2;
    pbStack_f0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x45344e;
    FUN_004cb840();
    local_8._0_1_ = 1;
    pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x45345a;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_78);
    pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 (local_58 + 2);
    pbStack_f0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x453472;
    puVar2 = (uint *)FUN_004ce990();
    if ((*puVar2 & 0xf000000) == 0) {
      pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
      pbStack_f0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
      pbStack_f4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
      uStack_f8 = 0;
      uStack_fc = 0;
      uStack_100 = *(undefined4 *)(param_1 + 0x10);
      uStack_104 = *(undefined4 *)(param_1 + 0x18);
      uStack_108 = *(undefined4 *)(param_1 + 0x14);
      iStack_10c = local_58;
      uStack_110 = 0x4534bf;
      pbVar3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               FUN_004cc4c0();
      local_7c = abStack_124;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_124,pbVar3);
      pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   FUN_00424670(local_98);
      local_8._0_1_ = 3;
      pbStack_f0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   0x453507;
      FUN_004cb840();
      local_8._0_1_ = 1;
      pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   0x453516;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_98);
    }
    else {
      pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
      pbStack_f0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
      pbStack_f4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
      uStack_f8 = 0;
      uStack_fc = 0;
      uStack_100 = *(undefined4 *)(param_1 + 0x10);
      uStack_104 = *(undefined4 *)(param_1 + 0x18);
      uStack_108 = *(undefined4 *)(param_1 + 0x14);
      local_9c = abStack_124;
      uVar6 = 0;
      puVar4 = (undefined4 *)FUN_004ce990(local_14 + 2 + local_58);
      FUN_00487160(abStack_124,*puVar4,uVar6);
      pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   FUN_00424670(local_b8);
      local_8._0_1_ = 4;
      pbStack_f0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   0x4535b5;
      FUN_004cb840();
      local_8._0_1_ = 1;
      pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   0x4535c4;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_b8);
    }
    pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 (local_58 + 2);
    pbStack_f0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x4535dc;
    puVar2 = (uint *)FUN_004ce990();
    switch(*puVar2 >> 0x1c) {
    case 0:
      pbStack_ec = local_50;
      pbStack_f0 = local_34;
      pbStack_f4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   0x453614;
      cVar1 = FUN_004ec8f0();
      if (cVar1 != '\0') {
        local_54 = local_58 + 1;
      }
      break;
    case 1:
      pbStack_ec = local_50;
      pbStack_f0 = local_34;
      pbStack_f4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   0x453636;
      cVar1 = operator!=<>();
      if (cVar1 != '\0') {
        local_54 = local_58 + 1;
      }
      break;
    case 2:
      local_5c = 0;
      pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
      pbStack_f0 = local_50;
      pbStack_f4 = local_34;
      uStack_f8 = 0x453661;
      local_5c = FUN_00419790();
      if (local_5c != DAT_007d0624) {
        local_54 = local_58 + 1;
      }
      break;
    case 3:
      pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
      pbStack_f0 = local_50;
      pbStack_f4 = local_34;
      uStack_f8 = 0x45368c;
      iVar5 = FUN_00419790();
      if (iVar5 == 0) {
        local_54 = local_58 + 1;
      }
    }
    if (local_54 != 0) break;
  }
  *(int *)(param_1 + 0x38 + *(char *)(*(int *)(param_1 + 0x898) + 0x10) * 4) = local_54;
  local_8 = (uint)local_8._1_3_ << 8;
  pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x4536d9
  ;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_50);
  local_8 = 0xffffffff;
  pbStack_ec = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x4536e8
  ;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34);
  ExceptionList = local_10;
  return 1;
}

