
void FUN_004361d0(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  char in_stack_00000020;
  int in_stack_00000024;
  undefined1 *puVar5;
  undefined1 local_90 [4];
  undefined1 local_8c [4];
  undefined1 local_88 [4];
  undefined1 local_84 [4];
  undefined1 local_80 [4];
  undefined1 local_7c [4];
  undefined1 local_78 [4];
  undefined1 local_74 [4];
  undefined1 local_70 [4];
  undefined1 local_6c [4];
  undefined1 local_68 [4];
  undefined1 local_64 [4];
  undefined1 local_60 [4];
  undefined1 local_5c [4];
  undefined1 local_58 [4];
  undefined1 local_54 [4];
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  int local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007ad09f;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  cVar1 = FUN_004ec750(&param_1,&DAT_007ce26e);
  if (cVar1 == '\0') {
    local_18 = 0;
    while (iVar2 = FUN_004d3180(), local_18 < iVar2) {
      if ((in_stack_00000020 != '\0') ||
         (iVar2 = FUN_004d31e0(local_18), *(int *)(iVar2 + 0x26c) != in_stack_00000024)) {
        puVar5 = &param_1;
        iVar2 = FUN_004d31e0(local_18);
        cVar1 = FUN_004ec8f0(iVar2 + 0x16c,puVar5);
        if (cVar1 != '\0') {
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
          ExceptionList = local_10;
          return;
        }
      }
      local_18 = local_18 + 1;
    }
    FUN_004ce060(&local_14);
    while( true ) {
      puVar5 = &param_1;
      puVar3 = (undefined4 *)FUN_004e38e0(local_24);
      puVar3 = (undefined4 *)FUN_004eca80(local_28,local_14,*puVar3,puVar5);
      local_14 = *puVar3;
      uVar4 = FUN_004e38e0(local_2c);
      cVar1 = const_iterator__operator__(uVar4);
      if (cVar1 == '\0') break;
      uVar4 = FUN_004ce060(local_30);
      local_1c = FUN_004d07b0(uVar4);
      uVar4 = 0;
      puVar3 = (undefined4 *)FUN_004ce990(local_1c);
      FUN_00515700(*puVar3,uVar4);
      local_20 = 0;
      while( true ) {
        FUN_004cde80(local_1c);
        iVar2 = FUN_004ce080();
        if (iVar2 <= local_20) break;
        uVar4 = 0;
        iVar2 = local_20;
        FUN_004cde80(local_1c);
        puVar3 = (undefined4 *)FUN_004ce990(iVar2);
        FUN_00515700(*puVar3,uVar4);
        local_20 = local_20 + 1;
      }
      puVar5 = local_38;
      uVar4 = local_1c;
      FUN_004ce060(local_34);
      puVar3 = (undefined4 *)FUN_004d0780(puVar5,uVar4);
      FUN_004cc5f0(local_3c,*puVar3);
      puVar5 = local_44;
      uVar4 = local_1c;
      FUN_004ce060(local_40);
      puVar3 = (undefined4 *)iterator__operator_(puVar5,uVar4);
      FUN_004ce2a0(local_48,*puVar3);
      puVar5 = local_50;
      uVar4 = local_1c;
      FUN_004ce060(local_4c);
      puVar3 = (undefined4 *)iterator__operator_(puVar5,uVar4);
      FUN_004ce2a0(local_54,*puVar3);
      puVar5 = local_5c;
      uVar4 = local_1c;
      FUN_004ce060(local_58);
      puVar3 = (undefined4 *)iterator__operator_(puVar5,uVar4);
      FUN_004ce2a0(local_60,*puVar3);
      puVar5 = local_68;
      uVar4 = local_1c;
      FUN_004ce060(local_64);
      puVar3 = (undefined4 *)iterator__operator_(puVar5,uVar4);
      FUN_004ce2a0(local_6c,*puVar3);
      puVar5 = local_74;
      uVar4 = local_1c;
      FUN_004ce060(local_70);
      puVar3 = (undefined4 *)FUN_004d2e90(puVar5,uVar4);
      FUN_004cd460(local_78,*puVar3);
      puVar5 = local_80;
      uVar4 = local_1c;
      FUN_004ce060(local_7c);
      puVar3 = (undefined4 *)iterator__operator_(puVar5,uVar4);
      FUN_004ce2a0(local_84,*puVar3);
      puVar5 = local_8c;
      uVar4 = local_1c;
      FUN_004ce060(local_88);
      puVar3 = (undefined4 *)iterator__operator_(puVar5,uVar4);
      FUN_004ce2a0(local_90,*puVar3);
    }
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
  }
  else {
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
  }
  ExceptionList = local_10;
  return;
}

