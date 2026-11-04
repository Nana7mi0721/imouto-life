
undefined4 FUN_005ca9b0(void)

{
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (((DAT_00f3a070 == 0) || (DAT_00a3819c - DAT_00a38194 == 0)) ||
     (DAT_00a381a0 - DAT_00a38198 == 0)) {
    return 0xffffffff;
  }
  local_18 = (float)DAT_00a38194;
  local_14 = (float)DAT_00a38198;
  local_10 = (float)(DAT_00a3819c - DAT_00a38194);
  local_c = (float)(DAT_00a381a0 - DAT_00a38198);
  local_8 = 0;
  local_4 = 0x3f800000;
  FUN_005c29f0(&local_18);
  FUN_005bd4e0();
  DAT_00a38418 = 1;
  FUN_005b9640(&DAT_00a386d8);
  return 0;
}

