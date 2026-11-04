
undefined4 FUN_005b9270(int param_1)

{
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((DAT_00f13218 != (param_1 != 0)) || (DAT_00ef7324 != 0)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00f13210 = 1;
    DAT_00ef72cc = 1;
    DAT_00f13218 = (uint)(param_1 != 0);
  }
  return 0;
}

