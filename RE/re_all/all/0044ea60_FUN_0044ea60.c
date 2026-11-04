
void __thiscall FUN_0044ea60(char *param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  undefined1 auStack_bc [20];
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined1 auStack_a0 [20];
  undefined4 uStack_8c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_88;
  undefined1 auStack_84 [20];
  undefined4 uStack_70;
  int iStack_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  char *local_44;
  undefined1 *local_40;
  undefined1 *local_3c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_38 [28];
  undefined1 *local_1c;
  undefined1 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad91a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[0x85c] = '\0';
  param_1[0x85d] = '\0';
  param_1[0x85e] = '\0';
  param_1[0x85f] = '\0';
  *(undefined4 *)(param_1 + 4) = param_2;
  *param_1 = param_3;
  local_44 = param_1;
  if (*(int *)(param_1 + 4) < 0x1f5) {
    if ((*param_1 != '\0') && (*(int *)(param_1 + 4) == 0)) {
      iStack_6c = 0x44eb87;
      FUN_004cfbf0();
      local_14 = 0;
      while( true ) {
        iStack_6c = 0x44eba3;
        iVar1 = FUN_004cfab0();
        if (iVar1 <= local_14) break;
        iStack_6c = local_14;
        uStack_70 = 0x44ebb6;
        iVar1 = FUN_004cfb40();
        if ((*(byte *)(iVar1 + 0x20) & 0xf) == 1) {
          iStack_6c = local_14;
          uStack_70 = 0x44ebd0;
          iStack_6c = FUN_004cfb40();
          uStack_70 = 0x44ebdf;
          FUN_004cfb80();
        }
        local_14 = local_14 + 1;
      }
    }
    iStack_6c = 0x44ebe9;
    FUN_0044ec00();
  }
  else {
    local_18 = auStack_84;
    pbStack_88 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 &DAT_007cec0d;
    uStack_8c = 0x44eabe;
    local_4c = basic_string<>();
    local_8 = 0;
    pbStack_88 = local_38;
    uStack_8c = 0x44ead7;
    local_48 = local_4c;
    local_54 = FUN_00438b60();
    local_8._0_1_ = 1;
    pbStack_88 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x44eaef;
    local_50 = local_54;
    uStack_a4 = FUN_004cbb30();
    local_1c = auStack_a0;
    uStack_a8 = 0x44eafd;
    local_5c = basic_string<>();
    local_8._0_1_ = 2;
    local_40 = auStack_bc;
    local_58 = local_5c;
    local_60 = basic_string<>(&DAT_007cec10);
    local_64 = FUN_00401c50();
    local_3c = auStack_bc;
    local_68 = basic_string<>(local_64);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_0042bed0();
    local_8 = 0xffffffff;
    iStack_6c = 0x44eb59;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_38);
    iStack_6c = 0x44eb61;
    FUN_00452450();
  }
  ExceptionList = local_10;
  return;
}

