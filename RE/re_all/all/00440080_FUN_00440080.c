
undefined4 __thiscall
FUN_00440080(undefined4 param_1,undefined4 param_2,int param_3,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_4)

{
  void **ppvVar1;
  void **ppvVar2;
  void **ppvVar3;
  void **ppvVar4;
  void **ppvVar5;
  void **ppvVar6;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_94 [12];
  undefined4 uStack_88;
  int iStack_84;
  undefined *puStack_80;
  undefined *puStack_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  uint local_44;
  undefined1 *local_40;
  undefined1 *local_3c;
  undefined1 *local_38;
  undefined1 *local_34;
  undefined1 *local_30;
  undefined1 *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_007ad5b3;
  local_10 = ExceptionList;
  local_44 = 0;
  local_8 = 1;
  local_4c = param_3 + -10;
  ExceptionList = &local_10;
  ppvVar1 = &local_10;
  ppvVar2 = &local_10;
  ppvVar3 = &local_10;
  ppvVar4 = &local_10;
  ppvVar5 = &local_10;
  ppvVar6 = &local_10;
  local_48 = param_1;
  switch(param_3) {
  case 10:
    while( true ) {
      ExceptionList = ppvVar1;
      puStack_7c = (undefined *)0x0;
      puStack_80 = &DAT_007ce8f8;
      iStack_84 = 0x4400e5;
      iStack_84 = FUN_004cbbc0();
      local_14 = iStack_84;
      if (iStack_84 == -1) break;
      puStack_7c = &DAT_007ce8fc;
      puStack_80 = (undefined *)0x3;
      uStack_88 = 0x440101;
      FUN_004cba30();
      ppvVar1 = ExceptionList;
    }
    while( true ) {
      puStack_7c = (undefined *)0x0;
      puStack_80 = &DAT_007ce900;
      iStack_84 = 0x440112;
      local_14 = FUN_004cbbc0();
      if (local_14 == -1) break;
      puStack_7c = &DAT_007ce904;
      puStack_80 = (undefined *)0x2;
      uStack_88 = 0x44012e;
      iStack_84 = local_14;
      FUN_004cba30();
    }
    local_2c = abStack_94;
    local_50 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
               basic_string<char,std::char_traits<char>,std::allocator<char>_>
                         (abStack_94,
                          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)&param_4);
    FUN_004787b0();
    break;
  case 0xb:
    while( true ) {
      ExceptionList = ppvVar2;
      puStack_7c = (undefined *)0x0;
      puStack_80 = &DAT_007ce908;
      iStack_84 = 0x440162;
      iStack_84 = FUN_004cbbc0();
      local_18 = iStack_84;
      if (iStack_84 == -1) break;
      puStack_7c = &DAT_007ce90c;
      puStack_80 = (undefined *)0x3;
      uStack_88 = 0x44017e;
      FUN_004cba30();
      ppvVar2 = ExceptionList;
    }
    while( true ) {
      puStack_7c = (undefined *)0x0;
      puStack_80 = &DAT_007ce910;
      iStack_84 = 0x44018f;
      local_18 = FUN_004cbbc0();
      if (local_18 == -1) break;
      puStack_7c = &DAT_007ce914;
      puStack_80 = (undefined *)0x2;
      uStack_88 = 0x4401ab;
      iStack_84 = local_18;
      FUN_004cba30();
    }
    local_30 = abStack_94;
    local_58 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
               basic_string<char,std::char_traits<char>,std::allocator<char>_>
                         (abStack_94,
                          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)&param_4);
    local_8._0_1_ = 2;
    local_54 = local_58;
    FUN_004d2620(0);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_004787b0();
    break;
  case 0xc:
    while( true ) {
      ExceptionList = ppvVar3;
      puStack_7c = (undefined *)0x0;
      puStack_80 = &DAT_007ce918;
      iStack_84 = 0x4401f6;
      iStack_84 = FUN_004cbbc0();
      local_1c = iStack_84;
      if (iStack_84 == -1) break;
      puStack_7c = &DAT_007ce91c;
      puStack_80 = (undefined *)0x3;
      uStack_88 = 0x440212;
      FUN_004cba30();
      ppvVar3 = ExceptionList;
    }
    while( true ) {
      puStack_7c = (undefined *)0x0;
      puStack_80 = &DAT_007ce920;
      iStack_84 = 0x440223;
      local_1c = FUN_004cbbc0();
      if (local_1c == -1) break;
      puStack_7c = &DAT_007ce924;
      puStack_80 = (undefined *)0x2;
      uStack_88 = 0x44023f;
      iStack_84 = local_1c;
      FUN_004cba30();
    }
    local_34 = abStack_94;
    local_60 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
               basic_string<char,std::char_traits<char>,std::allocator<char>_>
                         (abStack_94,
                          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)&param_4);
    local_8._0_1_ = 3;
    local_5c = local_60;
    FUN_004d2620(1);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_004787b0();
    break;
  case 0xd:
    while( true ) {
      ExceptionList = ppvVar4;
      puStack_7c = (undefined *)0x0;
      puStack_80 = &DAT_007ce928;
      iStack_84 = 0x44028a;
      iStack_84 = FUN_004cbbc0();
      local_20 = iStack_84;
      if (iStack_84 == -1) break;
      puStack_7c = &DAT_007ce92c;
      puStack_80 = (undefined *)0x3;
      uStack_88 = 0x4402a6;
      FUN_004cba30();
      ppvVar4 = ExceptionList;
    }
    while( true ) {
      puStack_7c = (undefined *)0x0;
      puStack_80 = &DAT_007ce930;
      iStack_84 = 0x4402b7;
      local_20 = FUN_004cbbc0();
      if (local_20 == -1) break;
      puStack_7c = &DAT_007ce934;
      puStack_80 = (undefined *)0x2;
      uStack_88 = 0x4402d3;
      iStack_84 = local_20;
      FUN_004cba30();
    }
    local_38 = abStack_94;
    local_68 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
               basic_string<char,std::char_traits<char>,std::allocator<char>_>
                         (abStack_94,
                          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)&param_4);
    local_8._0_1_ = 4;
    local_64 = local_68;
    FUN_004d2620(2);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_004787b0();
    break;
  case 0xe:
    while( true ) {
      ExceptionList = ppvVar5;
      puStack_7c = (undefined *)0x0;
      puStack_80 = &DAT_007ce938;
      iStack_84 = 0x44031e;
      iStack_84 = FUN_004cbbc0();
      local_24 = iStack_84;
      if (iStack_84 == -1) break;
      puStack_7c = &DAT_007ce93c;
      puStack_80 = (undefined *)0x3;
      uStack_88 = 0x44033a;
      FUN_004cba30();
      ppvVar5 = ExceptionList;
    }
    while( true ) {
      puStack_7c = (undefined *)0x0;
      puStack_80 = &DAT_007ce940;
      iStack_84 = 0x44034b;
      local_24 = FUN_004cbbc0();
      if (local_24 == -1) break;
      puStack_7c = &DAT_007ce944;
      puStack_80 = (undefined *)0x2;
      uStack_88 = 0x440367;
      iStack_84 = local_24;
      FUN_004cba30();
    }
    local_3c = abStack_94;
    local_70 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
               basic_string<char,std::char_traits<char>,std::allocator<char>_>
                         (abStack_94,
                          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)&param_4);
    local_8._0_1_ = 5;
    local_6c = local_70;
    FUN_004d2620(3);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_004787b0();
    break;
  case 0xf:
    while( true ) {
      ExceptionList = ppvVar6;
      puStack_7c = (undefined *)0x0;
      puStack_80 = &DAT_007ce948;
      iStack_84 = 0x4403b2;
      iStack_84 = FUN_004cbbc0();
      local_28 = iStack_84;
      if (iStack_84 == -1) break;
      puStack_7c = &DAT_007ce94c;
      puStack_80 = (undefined *)0x3;
      uStack_88 = 0x4403ce;
      FUN_004cba30();
      ppvVar6 = ExceptionList;
    }
    while( true ) {
      puStack_7c = (undefined *)0x0;
      puStack_80 = &DAT_007ce950;
      iStack_84 = 0x4403df;
      local_28 = FUN_004cbbc0();
      if (local_28 == -1) break;
      puStack_7c = &DAT_007ce954;
      puStack_80 = (undefined *)0x2;
      uStack_88 = 0x4403fb;
      iStack_84 = local_28;
      FUN_004cba30();
    }
    local_40 = abStack_94;
    local_78 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
               basic_string<char,std::char_traits<char>,std::allocator<char>_>
                         (abStack_94,
                          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)&param_4);
    local_8._0_1_ = 6;
    local_74 = local_78;
    FUN_004d2620(4);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_004787b0();
    break;
  case 0x14:
    puStack_7c = &param_4;
    puStack_80 = (undefined *)0x440445;
    ExceptionList = &local_10;
    FUN_004cb840();
    break;
  case 0x15:
    puStack_7c = &param_4;
    puStack_80 = (undefined *)0x440458;
    ExceptionList = &local_10;
    FUN_004cb840();
    break;
  case 0x1a:
    puStack_7c = &param_4;
    puStack_80 = (undefined *)0x440468;
    ExceptionList = &local_10;
    FUN_004cb840();
    break;
  case 0x1b:
    puStack_7c = &param_4;
    puStack_80 = (undefined *)0x440478;
    ExceptionList = &local_10;
    FUN_004cb840();
    break;
  case 0x1e:
    DAT_00a14340 = 1;
    puStack_7c = &param_4;
    puStack_80 = (undefined *)0x44048f;
    ExceptionList = &local_10;
    FUN_004cb840();
    break;
  case 0x1f:
    DAT_00a14341 = 1;
    puStack_7c = &param_4;
    puStack_80 = (undefined *)0x4404a6;
    ExceptionList = &local_10;
    FUN_004cb840();
    break;
  case 0x33:
    ExceptionList = &local_10;
    if ((14999 < *DAT_00a16628) && (ExceptionList = &local_10, *DAT_00a16628 < 0x3c8c)) {
      puStack_7c = &param_4;
      puStack_80 = (undefined *)0x4404d7;
      ExceptionList = &local_10;
      FUN_004cb840();
    }
  }
  puStack_7c = &DAT_007ce956;
  puStack_80 = (undefined *)0x4404e4;
  basic_string<>();
  local_44 = local_44 | 1;
  local_8 = local_8 & 0xffffff00;
  puStack_7c = (undefined *)0x4404f9;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_4);
  ExceptionList = local_10;
  return param_2;
}

