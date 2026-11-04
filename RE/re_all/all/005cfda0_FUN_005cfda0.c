
undefined4 FUN_005cfda0(void)

{
  int iVar1;
  undefined4 local_78;
  undefined4 local_74;
  int local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  undefined4 local_44;
  int local_40;
  undefined4 local_38;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (DAT_00ef1b58 != 0) {
    return 0;
  }
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  DAT_00ef1b50 = DAT_00a37e60;
  DAT_00ef1b54 = DAT_00a37e64;
  FUN_0056d380(&local_2c,0,0x2c);
  local_2c = DAT_00ef1b50;
  local_10 = 0;
  local_1c = 0x1c;
  local_c = 0x28;
  local_28 = DAT_00ef1b54;
  local_8 = 0;
  local_24 = 1;
  local_20 = 1;
  if (((int)DAT_00a37d84 < 2) || (DAT_00ee9a3c < 0xa000)) {
    local_14 = 0;
    local_18 = 1;
  }
  else {
    local_18 = DAT_00a37d84;
    local_14 = DAT_00a37d88;
    FUN_005d2a20(0x1c,&local_18,&local_14,0);
  }
  iVar1 = FUN_005d27e0(&local_2c,0,&DAT_00ef1b58);
  if (iVar1 < 0) {
    FUN_0056bca0(&DAT_007fca80,local_1c,DAT_00ef1b50,DAT_00ef1b54);
    return 0xffffffff;
  }
  FUN_0056d380(&local_58,0,0x14);
  local_58 = local_1c;
  local_54 = (-(uint)(1 < local_18) & 2) + 4;
  iVar1 = FUN_005d2840(DAT_00ef1b58,&local_58,&DAT_00ef1b5c);
  if (iVar1 < 0) {
    FUN_0056bca0(&DAT_007ff168,local_1c,DAT_00ef1b50,DAT_00ef1b54);
    return 0xffffffff;
  }
  FUN_0056d380(&local_44,0,0x18);
  local_44 = local_1c;
  local_40 = (-(uint)(1 < local_18) & 2) + 4;
  local_38 = 1;
  iVar1 = FUN_005d2810(DAT_00ef1b58,&local_44,&DAT_00ef1b60);
  if (iVar1 < 0) {
    FUN_0056bca0(&DAT_007ff0e0,local_1c,DAT_00ef1b50,DAT_00ef1b54);
    return 0xffffffff;
  }
  local_78 = 0;
  local_74 = 0;
  local_70 = DAT_00ef1b50;
  local_6c = DAT_00ef1b54;
  if (DAT_00ee9b94 < DAT_00ef1b50) {
    local_70 = DAT_00ee9b94;
  }
  if (DAT_00ee9b98 < DAT_00ef1b54) {
    local_6c = DAT_00ee9b98;
  }
  FUN_005caf30(DAT_00ee9b90,DAT_00ee9bc0,&local_78,DAT_00ef1b58,DAT_00ef1b5c,&local_78,0,0,0,0,0,0,0
               ,0);
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  FUN_005d2e00(DAT_00ee9bc4,&local_68);
  DAT_00ef7324 = 1;
  FUN_005c2b20(DAT_00ef1b58,DAT_00ef1b5c,0);
  DAT_00ef7324 = 0;
  return 0;
}

