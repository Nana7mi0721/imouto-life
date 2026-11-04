
undefined4 FUN_0059baa0(int param_1,int param_2)

{
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if (((DAT_00e39a54 != 0) || (DAT_00e39a0c != param_1)) || (DAT_00e39a10 != param_2)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00e39a0c = param_1;
    DAT_00e39a10 = param_2;
    DAT_00e39a00 = 1;
    DAT_00e39a18 = 1;
  }
  return 0;
}

