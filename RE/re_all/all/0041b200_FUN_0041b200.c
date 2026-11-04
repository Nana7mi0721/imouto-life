
basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_0041b200(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int in_stack_00000024;
  undefined *puVar4;
  int local_68;
  int local_64;
  undefined *local_60 [4];
  undefined *local_50;
  undefined *local_4c;
  undefined *local_48;
  undefined *local_44;
  undefined *local_40;
  undefined *local_3c;
  undefined *local_38;
  undefined *local_34;
  undefined *local_30;
  undefined *local_2c;
  undefined *local_28;
  undefined *local_24;
  undefined *local_20;
  undefined *local_1c;
  undefined *local_18;
  undefined *local_14;
  undefined *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_007abd5d;
  local_10 = ExceptionList;
  local_8 = 1;
  local_60[0] = &DAT_007cbad8;
  local_60[1] = &DAT_007cbadc;
  local_60[2] = &DAT_007cbae0;
  local_60[3] = &DAT_007cbae4;
  local_50 = &DAT_007cbae8;
  local_4c = &DAT_007cbaec;
  local_48 = &DAT_007cbaf0;
  local_44 = &DAT_007cbaf4;
  local_40 = &DAT_007cbaf8;
  local_3c = &DAT_007cbafc;
  local_38 = &DAT_007cbb00;
  local_34 = &DAT_007cbb04;
  local_30 = &DAT_007cbb08;
  local_2c = &DAT_007cbb0c;
  local_28 = &DAT_007cbb10;
  local_24 = &DAT_007cbb14;
  local_20 = &DAT_007cbb18;
  local_1c = &DAT_007cbb1c;
  local_18 = &DAT_007cbb20;
  local_14 = &DAT_007cbb24;
  ExceptionList = local_60 + 0x14;
  for (local_68 = 0; local_68 < 10; local_68 = local_68 + 1) {
    local_64 = 0;
    while (local_64 = FUN_004cbbc0(local_60[local_68],local_64), local_64 != DAT_007d0624) {
      uVar1 = FUN_004cbb30(local_64);
      iVar2 = FUN_0046f680(uVar1);
      if (iVar2 == 0) {
        if (in_stack_00000024 == 0) {
          FUN_004cba30(local_64,1,local_60[local_68 + 10]);
        }
        else if (in_stack_00000024 == 1) {
          FUN_004cba30(local_64,1,&DAT_007cbb27);
        }
      }
      else {
        local_64 = local_64 + 1;
      }
    }
  }
  while( true ) {
    while (iVar2 = FUN_004cbbc0(&DAT_007cbb28,0), iVar2 == 0) {
      FUN_004cba30(0,1,&DAT_007cbb2a);
    }
    iVar2 = FUN_004e5650();
    iVar2 = FUN_004cbbc0(&DAT_007cbb2c,iVar2 + -1);
    iVar3 = FUN_004e5650();
    if (iVar2 != iVar3 + -1) break;
    puVar4 = &DAT_007cbb2e;
    uVar1 = 1;
    iVar2 = FUN_004e5650(1,&DAT_007cbb2e);
    FUN_004cba30(iVar2 + -1,uVar1,puVar4);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )&param_2);
  local_8 = local_8 & 0xffffff00;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  ExceptionList = local_10;
  return param_1;
}

