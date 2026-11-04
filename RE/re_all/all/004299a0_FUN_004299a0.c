
basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_004299a0(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,int param_2,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *local_78;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_54 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_38 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *local_1c;
  int local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_007acca7;
  local_10 = ExceptionList;
  local_8 = 1;
  ExceptionList = &local_10;
  while (iVar2 = FUN_004cbbc0(&DAT_007cd2e4,0), iVar2 != DAT_007d0624) {
    puVar5 = &DAT_007cd2e6;
    uVar4 = 1;
    uVar3 = FUN_004cbbc0(&DAT_007cd2e8,0);
    FUN_004cba30(uVar3,uVar4,puVar5);
  }
  local_18 = 0;
  local_11 = '\0';
  if (param_2 == 0) {
    iVar2 = FUN_004cbbc0(&DAT_007cd2ec,0);
    if (iVar2 != DAT_007d0624) {
      local_18 = FUN_004cbbc0(&DAT_007cd2f0,1);
      local_11 = '\x01';
    }
    iVar2 = FUN_004cbbc0(&DAT_007cd2f4,0);
    if (iVar2 != DAT_007d0624) {
      if (local_11 == '\0') {
        local_60 = FUN_004cbbc0(&DAT_007cd300,0);
      }
      else {
        iVar2 = FUN_004cbbc0(&DAT_007cd2f8,0);
        if (local_18 < iVar2) {
          local_5c = local_18;
        }
        else {
          local_5c = FUN_004cbbc0(&DAT_007cd2fc,0);
        }
        local_60 = local_5c;
      }
      local_18 = local_60;
    }
    if (local_18 < 1) {
      local_64 = FUN_004e5650();
    }
    else {
      local_64 = local_18;
    }
    FUN_004cbc20(param_1,0,local_64);
    local_8 = local_8 & 0xffffff00;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
  }
  else if (param_2 == 1) {
    iVar2 = FUN_004cbbc0(&DAT_007cd304,0);
    if (iVar2 != DAT_007d0624) {
      local_18 = FUN_004cbbc0(&DAT_007cd308,0);
      local_18 = local_18 + 1;
      local_11 = '\x01';
    }
    iVar2 = FUN_004cbbc0(&DAT_007cd30c,0);
    if (iVar2 != DAT_007d0624) {
      if (local_11 == '\0') {
        local_6c = FUN_004cbbc0(&DAT_007cd318,0);
        local_6c = local_6c + 2;
      }
      else {
        iVar2 = FUN_004cbbc0(&DAT_007cd310,0);
        if (local_18 < iVar2 + 2) {
          local_68 = local_18;
        }
        else {
          local_68 = FUN_004cbbc0(&DAT_007cd314,0);
          local_68 = local_68 + 2;
        }
        local_6c = local_68;
      }
      local_18 = local_6c;
    }
    bVar1 = 0 < local_18;
    if (bVar1) {
      uVar3 = FUN_004e5650();
      local_78 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 FUN_004cbc20(local_54,local_18,uVar3);
      local_8 = 3;
    }
    else {
      local_78 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 basic_string<>(&DAT_007cd31b);
      local_8 = CONCAT31(local_8._1_3_,2);
    }
    local_1c = local_78;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1,local_78);
    local_8 = 2;
    if (bVar1) {
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_54);
    }
    local_8 = 1;
    if (!bVar1) {
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_38);
    }
    local_8 = local_8 & 0xffffff00;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
  }
  else {
    basic_string<>(&DAT_007cd31c);
    local_8 = local_8 & 0xffffff00;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
  }
  ExceptionList = local_10;
  return param_1;
}

