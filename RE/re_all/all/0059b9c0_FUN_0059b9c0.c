
undefined4 FUN_0059b9c0(int param_1,int param_2,int param_3)

{
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if ((((DAT_00e39a54 != 0) || (DAT_00e39a14 != param_1)) || (DAT_00e39a08 != param_2)) ||
     (DAT_00e39a04 != param_3)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00e39a14 = param_1;
    DAT_00e39a04 = param_3;
    DAT_00e39a08 = param_2;
    DAT_00e39a00 = 1;
    DAT_00e39a18 = 1;
  }
  return 0;
}

