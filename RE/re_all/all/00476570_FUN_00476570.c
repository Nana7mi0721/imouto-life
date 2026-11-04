
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00476570(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined1 auStack_104 [20];
  undefined4 uStack_f0;
  undefined *puStack_ec;
  undefined1 auStack_e8 [4];
  undefined4 uStack_e4;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_dc [8];
  undefined4 uStack_d4;
  undefined *puStack_d0;
  undefined1 auStack_cc [4];
  undefined4 uStack_c8;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbStack_c4;
  undefined4 uStack_c0;
  int iStack_bc;
  int iStack_b8;
  int iStack_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_7c;
  undefined4 local_78;
  undefined4 local_74;
  int local_70;
  undefined1 *local_6c;
  undefined1 *local_68;
  undefined1 *local_64;
  undefined1 *local_60;
  undefined1 *local_5c;
  undefined1 *local_58;
  undefined1 *local_54;
  undefined1 *local_50;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_4c [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007aee70;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  iStack_b4 = 0x4765a1;
  ExceptionList = &local_10;
  FUN_00476910();
  iStack_b4 = 0;
  iStack_b8 = 0;
  iStack_bc = 1;
  uStack_c0 = 10;
  pbStack_c4 = local_4c;
  uStack_c8 = 0x4765b7;
  FUN_0046ff30();
  local_8 = 0;
  iStack_b4 = 0;
  iStack_b8 = 0;
  iStack_bc = 2;
  uStack_c0 = 10;
  pbStack_c4 = local_30;
  uStack_c8 = 0x4765d4;
  FUN_0046ff30();
  local_8 = CONCAT31(local_8._1_3_,1);
  iStack_b4 = 0;
  iStack_b8 = 1;
  iStack_bc = 2;
  uStack_c0 = 10;
  pbStack_c4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               0x4765ea;
  iVar1 = FUN_0046f7f0();
  if (iVar1 < 1) {
    local_74 = 1;
  }
  else {
    iStack_b4 = 0;
    iStack_b8 = 1;
    iStack_bc = 2;
    uStack_c0 = 10;
    pbStack_c4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 0x47660a;
    local_74 = FUN_0046f7f0();
  }
  *(undefined4 *)(local_70 + 0x160) = local_74;
  *(undefined4 *)(local_70 + 400) = *(undefined4 *)(local_70 + 0x160);
  iStack_b4 = 0;
  iStack_b8 = local_70 + 0x130;
  iStack_bc = 3;
  uStack_c0 = 3;
  local_50 = abStack_dc;
  uStack_e4 = 0x47664c;
  local_78 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
             basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_dc,local_4c);
  local_7c = FUN_00423120();
  if (local_7c == -1) {
    *(undefined1 *)(local_70 + 0x19c) = 0;
    *(undefined4 *)(local_70 + 0x150) = 0;
    *(undefined4 *)(local_70 + 0x158) = 0;
  }
  else {
    *(undefined1 *)(local_70 + 0x19c) = 1;
    iStack_b4 = local_70 + 0x158;
    iStack_b8 = local_70 + 0x150;
    iStack_bc = 0;
    uStack_c0 = 0x4766b4;
    puVar2 = (undefined4 *)FUN_004ce990();
    iStack_bc = *puVar2;
    uStack_c0 = 0x4766bc;
    FUN_00515880();
    *(int *)(local_70 + 0x150) = *(int *)(local_70 + 0x150) / 3;
    *(int *)(local_70 + 0x158) = *(int *)(local_70 + 0x158) / 3;
  }
  iStack_b4 = 0;
  iStack_b8 = local_70 + 0x140;
  iStack_bc = *(int *)(local_70 + 400) * 3;
  uStack_c0 = 3;
  local_54 = abStack_dc;
  uStack_e4 = 0x47671e;
  local_80 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
             basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_dc,local_30);
  local_84 = FUN_00423120();
  *(undefined4 *)(local_70 + 0x168) = local_84;
  if (*(int *)(local_70 + 0x168) == -1) {
    *(undefined1 *)(local_70 + 0x19d) = 0;
    *(undefined4 *)(local_70 + 0x154) = 0;
    *(undefined4 *)(local_70 + 0x15c) = 0;
  }
  else {
    *(undefined1 *)(local_70 + 0x19d) = 1;
    iStack_b4 = local_70 + 0x15c;
    iStack_b8 = local_70 + 0x154;
    iStack_bc = 0;
    uStack_c0 = 0x47679a;
    piVar3 = (int *)FUN_004ce990();
    iStack_bc = *piVar3;
    uStack_c0 = 0x4767a2;
    FUN_00515880();
    *(int *)(local_70 + 0x154) = *(int *)(local_70 + 0x154) / 3;
    *(int *)(local_70 + 0x15c) = *(int *)(local_70 + 0x15c) / (*(int *)(local_70 + 400) * 3);
    if (*(int *)(local_70 + 0x15c) == 0) {
      local_5c = auStack_cc;
      puStack_d0 = &DAT_007d08d0;
      uStack_d4 = 0x476802;
      local_88 = basic_string<>();
      puStack_d0 = (undefined *)0x47680d;
      puStack_d0 = (undefined *)FUN_00401c50();
      uStack_d4 = 0x47682a;
      local_8c = puStack_d0;
      local_58 = auStack_cc;
      local_94 = basic_string<>();
      local_8._0_1_ = 2;
      local_64 = auStack_e8;
      puStack_ec = &DAT_007d0888;
      uStack_f0 = 0x476852;
      local_90 = local_94;
      local_98 = basic_string<>();
      puStack_ec = (undefined *)0x47685d;
      puStack_ec = (undefined *)FUN_00401c50();
      uStack_f0 = 0x47687a;
      local_9c = puStack_ec;
      local_60 = auStack_e8;
      local_a4 = basic_string<>();
      local_8._0_1_ = 3;
      local_6c = auStack_104;
      local_a0 = local_a4;
      local_a8 = basic_string<>(&DAT_007d0848);
      local_ac = FUN_00401c50();
      local_68 = auStack_104;
      local_b0 = basic_string<>(local_ac);
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_0042bed0();
    }
  }
  local_8 = local_8 & 0xffffff00;
  iStack_b4 = 0x4768e8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_30);
  local_8 = 0xffffffff;
  iStack_b4 = 0x4768f7;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_4c);
  ExceptionList = local_10;
  return;
}

