
undefined4 FUN_00551d60(void)

{
  undefined1 local_30 [4];
  int local_2c;
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined4 local_20;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined4 local_18;
  undefined4 local_14;
  ushort local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined1 local_a [4];
  int local_6;
  
  if (DAT_00a83c68 == 0) {
    return 0xffffffff;
  }
  local_1c = 1;
  local_1a = 2;
  local_18 = 0xac44;
  local_e = 0x10;
  local_10 = 4;
  local_14 = 0x2b110;
  local_c = 0;
  FUN_0056d420(local_30,&DAT_007d6168,4);
  local_2c = (uint)local_10 * DAT_00a83c6c + 0x26;
  FUN_0056d420(local_28,&DAT_007d6160,4);
  FUN_0056d420(local_24,&DAT_007d6158,4);
  local_20 = 0x12;
  FUN_0056d420(local_a,&DAT_007d6150,4);
  local_6 = (uint)local_10 * DAT_00a83c6c;
  FUN_0052de60(DAT_00a83c70,0,0,0);
  thunk_FUN_00595750(DAT_00a83c70,local_30,0x2e,0);
  thunk_FUN_005956d0(DAT_00a83c70);
  DAT_00a83c70 = 0;
  DAT_00a83c68 = 0;
  return 0;
}

