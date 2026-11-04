
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 __fastcall FUN_0045abb0(int param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar4;
  undefined4 uVar5;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_d4 [20];
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbStack_9c;
  undefined1 auStack_98 [4];
  int iStack_94;
  undefined4 uStack_90;
  int iStack_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_48 [28];
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ade14;
  local_10 = ExceptionList;
  local_2c = DAT_0084b484;
  local_18 = -1;
  local_14 = 0;
  iStack_80 = 1;
  iStack_84 = 0x45abf5;
  ExceptionList = &local_10;
  puVar1 = (uint *)FUN_004ce990();
  if ((int)(*puVar1 & 0xf000000) >> 0x18 == 0) {
    iStack_80 = 1;
    iStack_84 = 0x45ac1c;
    puVar1 = (uint *)FUN_004ce990();
    local_18 = (int)(*puVar1 & 0xffff00) >> 8;
  }
  iStack_80 = 0x45ac40;
  iVar2 = FUN_004ce080();
  if (4 < iVar2) {
    iStack_80 = 4;
    iStack_84 = 0x45ac55;
    puVar3 = (undefined4 *)FUN_004ce990();
    iStack_80 = *puVar3;
    iStack_84 = 0x45ac60;
    local_14 = FUN_00487080();
  }
  iStack_80 = 1;
  iStack_84 = 0x45ac73;
  puVar1 = (uint *)FUN_004ce990();
  if ((int)(*puVar1 & 0xf000000) >> 0x18 == 1) {
    iStack_80 = 3;
    iStack_84 = 0x45ac9b;
    puVar3 = (undefined4 *)FUN_004ce990();
    iStack_80 = *puVar3;
    iStack_84 = 0x45aca6;
    local_18 = FUN_00487080();
    iStack_80 = 1;
    iStack_84 = 0x45acb9;
    puVar1 = (uint *)FUN_004ce990();
    if (((*puVar1 & 0xf) == 2) && (local_18 == -1)) {
      ExceptionList = local_10;
      return 1;
    }
  }
  iStack_80 = 1;
  iStack_84 = 0x45ace0;
  puVar1 = (uint *)FUN_004ce990();
  if ((int)(*puVar1 & 0xf000000) >> 0x18 == 2) {
    iStack_80 = 1;
    iStack_84 = 0x45ad0c;
    puVar1 = (uint *)FUN_004ce990();
    local_28 = (int)(*puVar1 & 0xf0) >> 4;
    pbStack_9c = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x0
    ;
    uStack_a0 = 0;
    uStack_a4 = 0;
    uStack_a8 = 0;
    uStack_ac = 1;
    uStack_b0 = DAT_00a17eb8;
    uStack_b8 = *(undefined4 *)(param_1 + 0x14);
    uStack_bc = 0;
    uStack_c0 = 0x45ad58;
    pbVar4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             FUN_004cc4c0();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_d4,pbVar4);
    FUN_00424670(auStack_98);
    pbStack_9c = local_48;
    uStack_a0 = 0x45ad84;
    FUN_004293c0();
    local_8 = 0;
    iStack_80 = 2;
    iStack_84 = 0x45ada1;
    puVar3 = (undefined4 *)FUN_004ce990();
    iStack_80 = *puVar3;
    iStack_84 = 0x45adac;
    uVar5 = FUN_00487080();
    iStack_80 = 5;
    iStack_84 = 0x45adbf;
    puVar3 = (undefined4 *)FUN_004ce990();
    iStack_80 = *puVar3;
    iStack_84 = 0x45adca;
    local_1c = FUN_00487080();
    iStack_80 = 6;
    iStack_84 = 0x45addd;
    puVar3 = (undefined4 *)FUN_004ce990();
    iStack_80 = *puVar3;
    iStack_84 = 0x45ade8;
    local_24 = FUN_00487080();
    if (local_1c == 0) {
      local_1c = 100;
    }
    if (local_24 == 0) {
      local_24 = 100;
    }
    local_20 = 0;
    if (local_28 < 2) {
      iStack_80 = 7;
      iStack_84 = 0x45ae22;
      puVar3 = (undefined4 *)FUN_004ce990();
      iStack_80 = *puVar3;
      iStack_84 = 0x45ae2d;
      local_20 = FUN_00487080();
    }
    iStack_80 = local_14;
    iStack_84 = local_24;
    iStack_88 = local_1c;
    iStack_8c = local_20;
    iStack_94 = local_28;
    uStack_b8 = 0x45ae59;
    uStack_90 = uVar5;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_b0,
               local_48);
    local_18 = FUN_0047cf40();
    if (local_18 == -10) {
      local_8 = 0xffffffff;
      iStack_80 = 0x45ae88;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_48);
      ExceptionList = local_10;
      return 1;
    }
    local_8 = 0xffffffff;
    iStack_80 = 0x45ae9f;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_48
              );
  }
  iStack_80 = 1;
  iStack_84 = 0x45aeaf;
  puVar1 = (uint *)FUN_004ce990();
  if (((*puVar1 & 0xf) == 0) && (local_18 != -2)) {
    iStack_80 = local_14;
    iStack_84 = 2;
    iStack_88 = 0x45aed0;
    puVar3 = (undefined4 *)FUN_004ce990();
    iStack_84 = *puVar3;
    iStack_88 = 0x45aedb;
    iStack_84 = FUN_00487080();
    iStack_88 = local_18;
    iStack_8c = 1;
    uStack_90 = 0x45aef0;
    puVar1 = (uint *)FUN_004ce990();
    iStack_8c = (int)(*puVar1 & 0xf0) >> 4;
    uStack_90 = 0x45af0b;
    FUN_0047a5d0();
  }
  iStack_80 = 1;
  iStack_84 = 0x45af1b;
  puVar1 = (uint *)FUN_004ce990();
  if (((*puVar1 & 0xf) == 1) && (local_18 != -2)) {
    iStack_80 = local_18;
    iStack_84 = 1;
    iStack_88 = 0x45af3f;
    puVar1 = (uint *)FUN_004ce990();
    iStack_84 = (int)(*puVar1 & 0xf0) >> 4;
    iStack_88 = 0x45af5a;
    FUN_0047bc30();
  }
  iStack_80 = 1;
  iStack_84 = 0x45af6a;
  puVar1 = (uint *)FUN_004ce990();
  if ((*puVar1 & 0xf) == 2) {
    iStack_80 = local_18;
    iStack_84 = 1;
    iStack_88 = 0x45af88;
    puVar1 = (uint *)FUN_004ce990();
    iStack_84 = (int)(*puVar1 & 0xf0) >> 4;
    iStack_88 = 0x45afa3;
    FUN_0047c760();
  }
  iStack_80 = 1;
  iStack_84 = 0x45afb3;
  puVar1 = (uint *)FUN_004ce990();
  if ((*puVar1 & 0xf) == 3) {
    iStack_80 = 0;
    iStack_84 = 0x45afc9;
    FUN_0047dcf0();
  }
  ExceptionList = local_10;
  return 1;
}

