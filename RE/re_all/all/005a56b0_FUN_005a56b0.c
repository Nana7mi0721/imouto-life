
undefined4 FUN_005a56b0(void)

{
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  if (((DAT_00f3a04c == 0) || (DAT_00a3819c == DAT_00a38194)) || (DAT_00a381a0 == DAT_00a38198)) {
    return 0xffffffff;
  }
  FUN_0056d380(&local_98,0,0x18);
  local_88 = 0;
  local_84 = 0x3f800000;
  local_90 = DAT_00a3819c - DAT_00a38194;
  local_98 = DAT_00a38194;
  local_8c = DAT_00a381a0 - DAT_00a38198;
  local_94 = DAT_00a38198;
  FUN_005a09f0(&local_98);
  FUN_005a0b10(&DAT_00a38194);
  if (DAT_00a381c4 == 0) {
    FUN_005850a0(local_80,&DAT_00a384a0,&DAT_00a38798);
    FUN_005850a0(local_80,local_80,&DAT_00a386d8);
  }
  else {
    FUN_005850a0(local_80,&DAT_00a38248,&DAT_00a386d8);
  }
  if (DAT_00f3a04c != 0) {
    FUN_005d39b0(3,local_80);
    FUN_00585710(local_40,local_80);
    FUN_0059cb80(&DAT_00ddb600,0,0,2,local_40,4,1);
  }
  DAT_00a38418 = 1;
  return 0;
}

