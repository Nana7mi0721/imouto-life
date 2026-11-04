
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00570010(short *param_1)

{
  DAT_00b22d88 = 0;
  if (*param_1 != 0) {
    do {
      DAT_00b22d88 = DAT_00b22d88 + 1;
    } while (param_1[DAT_00b22d88] != 0);
    if ((DAT_00b22d88 < 0x40) && (*param_1 != 0)) {
      FUN_0056cf70(&DAT_00b22d08,0x80,param_1);
      return 0;
    }
  }
  _DAT_00b22d08 = 0;
  DAT_00b22d88 = 0;
  return 0;
}

