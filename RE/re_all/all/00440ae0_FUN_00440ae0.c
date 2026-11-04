
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_00440ae0(undefined4 *param_1)

{
  undefined1 auStack_38 [20];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad60b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = &PTR_FUN_007d0a68;
  uStack_20 = 0x440b12;
  local_18 = param_1;
  basic_string<>();
  local_8 = 0;
  uStack_20 = 0x440b24;
  FUN_0046d280();
  local_8._0_1_ = 1;
  uStack_20 = 0x440b36;
  FUN_0046d280();
  local_8._0_1_ = 2;
  uStack_20 = 0x440b48;
  FUN_004ce850();
  local_8._0_1_ = 3;
  uStack_20 = 0x440b5a;
  FUN_004cf7a0();
  local_8._0_1_ = 4;
  uStack_20 = 0x440b6c;
  FUN_004ce850();
  local_8 = CONCAT31(local_8._1_3_,5);
  local_18[9] = 0xfffffffe;
  local_18[10] = 0;
  local_18[0xb] = 0;
  local_18[0xe] = 0;
  local_18[0xf] = 0;
  local_18[0x10] = 0xffffffff;
  *(undefined2 *)(local_18 + 0x11) = 0xff;
  *(undefined2 *)((int)local_18 + 0x46) = 0;
  *(undefined2 *)((int)local_18 + 0x4e) = 2;
  *(undefined2 *)(local_18 + 0x12) = 2;
  *(undefined2 *)((int)local_18 + 0x4a) = 1;
  local_14 = auStack_38;
  local_1c = basic_string<>(&DAT_007ce958);
  FUN_004787b0();
  *(undefined1 *)((int)local_18 + 0x52) = 0;
  *(undefined1 *)((int)local_18 + 0x53) = 0;
  *(undefined1 *)((int)local_18 + 0x56) = 0;
  *(undefined2 *)(local_18 + 0x16) = 0;
  *(undefined2 *)((int)local_18 + 0x5a) = 3;
  *(undefined2 *)((int)local_18 + 0x5e) = 6;
  *(undefined2 *)(local_18 + 0x2a) = 0;
  *(undefined2 *)((int)local_18 + 0xaa) = 0;
  *(undefined8 *)(local_18 + 0x50) = _DAT_007d0a60;
  local_18[0x19] = 0;
  local_18[0x1a] = 0;
  local_18[0x1b] = 0;
  local_18[0x1c] = 0;
  local_18[0x1d] = 0;
  *(undefined1 *)(local_18 + 0x2b) = 1;
  *(undefined1 *)((int)local_18 + 0xad) = 0;
  *(undefined1 *)((int)local_18 + 0xae) = 0;
  *(undefined1 *)((int)local_18 + 0xaf) = 0;
  *(undefined1 *)(local_18 + 0x2c) = 0;
  if (*DAT_00a16678 == '\b') {
    *(undefined1 *)((int)local_18 + 0x55) = 1;
  }
  else {
    *(undefined1 *)((int)local_18 + 0x55) = 0;
  }
  local_18[0x2d] = 1;
  *(undefined1 *)(local_18 + 0x15) = 0;
  *(undefined2 *)(local_18 + 0x18) = 0;
  *(undefined1 *)((int)local_18 + 0x57) = 0;
  *(undefined2 *)(local_18 + 0x17) = 2;
  *(undefined1 *)((int)local_18 + 0xba) = 0;
  *(undefined1 *)((int)local_18 + 0xbb) = 0;
  uStack_20 = 1;
  uStack_24 = 0x440d20;
  FUN_004cf7d0();
  *(undefined2 *)(local_18 + 0x2f) = 0xffff;
  *(undefined1 *)((int)local_18 + 0xbf) = 0;
  *(undefined1 *)((int)local_18 + 0xc1) = 0;
  *(undefined1 *)((int)local_18 + 0xc2) = 0;
  uStack_20 = 0x440d52;
  FUN_00440e60();
  local_18[0x31] = 0;
  local_18[0x36] = 0;
  local_18[0x37] = 0;
  local_18[0x3a] = 0;
  local_18[0x38] = 0;
  local_18[0x39] = 1;
  local_18[0x3f] = 0;
  local_18[0x3e] = 1;
  local_18[0x3d] = 0;
  local_18[0x41] = 0;
  local_18[0x40] = 0;
  uStack_20 = 0x440def;
  FUN_004ce950();
  local_18[0x45] = 0;
  local_18[0x44] = 0;
  local_18[0x43] = 0;
  local_18[0x42] = 0;
  local_18[0x46] = 0;
  *(undefined2 *)(local_18 + 0x14) = 0;
  ExceptionList = local_10;
  return local_18;
}

