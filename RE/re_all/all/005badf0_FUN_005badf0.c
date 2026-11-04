
undefined4 FUN_005badf0(int param_1)

{
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((param_1 != DAT_00f07360) || (DAT_00ef7324 != 0)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00f07360 = param_1;
    DAT_00ef72cc = 1;
  }
  return 0;
}

