
int __fastcall FUN_00471bd0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007aeb7f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0044e840();
  local_8 = 0;
  FUN_004cc150();
  local_8._0_1_ = 1;
  FUN_004ce850();
  local_8._0_1_ = 2;
  basic_string<>();
  local_8._0_1_ = 3;
  basic_string<>();
  local_8._0_1_ = 4;
  basic_string<>();
  local_8._0_1_ = 5;
  basic_string<>();
  local_8._0_1_ = 6;
  basic_string<>();
  local_8._0_1_ = 7;
  basic_string<>();
  local_8._0_1_ = 8;
  basic_string<>();
  local_8._0_1_ = 9;
  basic_string<>();
  local_8._0_1_ = 10;
  basic_string<>();
  local_8._0_1_ = 0xb;
  FUN_004cc150();
  local_8._0_1_ = 0xc;
  FUN_004ce850();
  local_8._0_1_ = 0xd;
  FUN_004ce850();
  local_8 = CONCAT31(local_8._1_3_,0xe);
  FUN_0044ea60(0,1);
  *(undefined1 *)(param_1 + 0x8ac) = 0;
  *(undefined1 *)(param_1 + 0x8ad) = 0;
  *(undefined1 *)(param_1 + 0x8ae) = 0;
  *(undefined4 *)(param_1 + 0x8b0) = 0;
  *(undefined4 *)(param_1 + 0x8b4) = 0;
  *(undefined4 *)(param_1 + 0x8cc) = 0;
  *(undefined4 *)(param_1 + 0x8d0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x8d4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x8d8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x8dc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x8e0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x8e4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x8e8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x8ec) = 0;
  *(undefined2 *)(param_1 + 0x93c) = 0;
  for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
    for (local_18 = 0; local_18 < 3; local_18 = local_18 + 1) {
      *(undefined2 *)(param_1 + 0x8f0 + local_14 * 6 + local_18 * 2) = 0;
    }
    *(undefined2 *)(param_1 + 0x906 + local_14 * 2) = 0;
  }
  *(undefined2 *)(param_1 + 0x902) = 0xffff;
  *(undefined2 *)(param_1 + 0x904) = 0xffff;
  *(undefined2 *)(param_1 + 0x90c) = 0xffff;
  *(undefined2 *)(param_1 + 0x90e) = 0xffff;
  *(undefined4 *)(param_1 + 0x910) = 0;
  *(undefined4 *)(param_1 + 0x8c4) = 0;
  *(undefined4 *)(param_1 + 0x8b0) = 0;
  *(undefined4 *)(param_1 + 0x8b8) = 0;
  *(undefined4 *)(param_1 + 0x91c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x920) = 0;
  *(undefined4 *)(param_1 + 0x924) = 0;
  *(undefined4 *)(param_1 + 0x928) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x92c) = 0;
  *(undefined4 *)(param_1 + 0x930) = 0;
  *(undefined4 *)(param_1 + 0x934) = 0;
  *(undefined4 *)(param_1 + 0x938) = 0xff;
  *(undefined1 *)(param_1 + 0x94c) = 0;
  *(undefined4 *)(param_1 + 0x940) = 0x10;
  *(undefined4 *)(param_1 + 0x944) = 5;
  *(undefined4 *)(param_1 + 0x948) = 0xffffffff;
  *(undefined1 *)(param_1 + 0x952) = 1;
  *(undefined2 *)(param_1 + 0x954) = 2;
  *(undefined4 *)(param_1 + 0x958) = 0;
  *(undefined4 *)(param_1 + 0x960) = 0x78;
  *(undefined4 *)(param_1 + 0x964) = 1000000;
  *(undefined4 *)(param_1 + 0x968) = 1;
  *(undefined4 *)(param_1 + 0x8c8) = 0;
  *(undefined1 *)(param_1 + 0x96c) = 1;
  *(undefined4 *)(param_1 + 0x8bc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x8c0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x974) = 0;
  *(undefined4 *)(param_1 + 0x970) = 0;
  *(undefined4 *)(param_1 + 0x978) = 0;
  *(undefined4 *)(param_1 + 0x97c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x980) = 0x14;
  *(undefined1 *)(param_1 + 0x984) = 0;
  FUN_004ce970(5);
  local_1c = 0;
  while( true ) {
    iVar1 = FUN_004ce080();
    if (iVar1 <= local_1c) break;
    puVar2 = (undefined4 *)FUN_004ce990(local_1c);
    *puVar2 = 0xffffffff;
    local_1c = local_1c + 1;
  }
  *(undefined4 *)(param_1 + 0x9a8) = 0;
  *(undefined4 *)(param_1 + 0x9b0) = 0;
  *(undefined4 *)(param_1 + 0x9ac) = 0;
  *(undefined4 *)(param_1 + 0x9b8) = 0;
  *(undefined4 *)(param_1 + 0x9b4) = 0;
  *(undefined4 *)(param_1 + 0x9bc) = 0x90;
  *(undefined4 *)(param_1 + 0x9c0) = 0x91;
  *(undefined4 *)(param_1 + 0x9c4) = 0x92;
  *(undefined4 *)(param_1 + 0x9c8) = 0x10;
  *(undefined4 *)(param_1 + 0x9cc) = 0x20;
  *(undefined4 *)(param_1 + 0x9d0) = 0x40;
  *(undefined1 *)(param_1 + 0xaf8) = 1;
  *(undefined1 *)(param_1 + 0xaf9) = 1;
  *(undefined4 *)(param_1 + 0xb00) = 1;
  *(undefined4 *)(param_1 + 0xb04) = 0;
  *(undefined4 *)(param_1 + 0xb0c) = 0;
  FUN_004cc250();
  FUN_004ce950();
  FUN_00472140();
  ExceptionList = local_10;
  return param_1;
}

