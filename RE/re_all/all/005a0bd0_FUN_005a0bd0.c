
undefined4 FUN_005a0bd0(int param_1,uint param_2)

{
  undefined1 local_20 [24];
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if (7 < param_2) {
    return 0xffffffff;
  }
  if (((&DAT_00e8063c)[param_2] != param_1) || (DAT_00e39a54 != 0)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    FUN_005d38d0(param_2,param_1);
    (&DAT_00e8063c)[param_2] = param_1;
    if (param_2 == 0) {
      FUN_005d2730(param_1,local_20);
      FUN_005a0ad0(0,0,local_8,local_4);
    }
  }
  return 0;
}

