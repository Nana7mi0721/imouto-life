
undefined4 FUN_005c11f0(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (DAT_00ef1b64 != 0) {
    FUN_005d1ee0(DAT_00ef1b64);
    DAT_00ef1b64 = 0;
  }
  if (DAT_00ef1b68 != 0) {
    FUN_005d1f60(DAT_00ef1b68);
    DAT_00ef1b68 = 0;
  }
  FUN_0056bb10(&DAT_007fdf80);
  DAT_00ef1b6c = DAT_00a37e60;
  DAT_00ef1b70 = DAT_00a37e64;
  if ((DAT_00ee9a4c == 0) || (DAT_00ef1b74 == 0)) {
    DAT_00ef1b74 = 0x10;
    iVar2 = 0;
  }
  else if (DAT_00ef1b74 == 0x18) {
    iVar2 = 1;
  }
  else if (DAT_00ef1b74 == 0x20) {
    iVar2 = 2;
  }
  else {
    iVar2 = 0;
  }
  FUN_0056d380(&local_2c,0,0x2c);
  local_1c = (&DAT_00ee9b1c)[iVar2];
  local_2c = DAT_00a37e60;
  local_28 = DAT_00a37e64;
  local_24 = 1;
  local_20 = 1;
  local_18 = DAT_00a37d84;
  local_14 = DAT_00a37d88;
  local_10 = 0;
  local_c = 0x40;
  local_8 = 0;
  local_4 = 0;
  iVar1 = FUN_005d27e0(&local_2c,0,&DAT_00ef1b64);
  if (iVar1 < 0) {
    FUN_0056bb10(&DAT_007fdf44);
    return 0xffffffff;
  }
  FUN_0056d380(&local_2c,0,0x18);
  local_2c = (&DAT_00ee9b28)[iVar2];
  if (DAT_00a37d84 < 2) {
    local_28 = 3;
    local_20 = 0;
  }
  else {
    local_28 = 5;
  }
  iVar2 = FUN_005d2870(DAT_00ef1b64,&local_2c,&DAT_00ef1b68);
  if (iVar2 < 0) {
    FUN_0056bb10(&DAT_007fdef8);
    return 0xffffffff;
  }
  FUN_005bb610(DAT_00ef1b64,DAT_00ef1b68);
  FUN_005d2e20(DAT_00ef1b68,1,0x3f800000,0);
  FUN_0056bb10(&DAT_007d4974);
  return 0;
}

