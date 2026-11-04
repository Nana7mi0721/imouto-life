
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005674f0(uint param_1)

{
  uint uVar1;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  if (0 < (int)param_1) {
    if ((((int)param_1 < 0) || ((param_1 & 0x7c000000) != 0x24000000)) ||
       (uVar1 = param_1 & 0xffff, 0xff < uVar1)) {
      return 0xffffffff;
    }
    piVar2 = &DAT_00aa84b8 + uVar1 * 0x17;
    if (*piVar2 == 0) {
      return 0xffffffff;
    }
    if ((&DAT_00aa84bc)[uVar1 * 0x17] * 0x10000 != (param_1 & 0x3ff0000)) {
      return 0xffffffff;
    }
  }
  _DAT_00aa84a4 = FUN_00550060(0);
  DAT_00aa84ac = 1;
  if (param_1 == DAT_00aa84b0) {
    if (piVar2 == (int *)0x0) {
      if (-1 < (int)param_1) {
        DAT_00aa84ac = 1;
        return 0;
      }
    }
    else if (piVar2[2] == 0) {
      DAT_00aa84ac = 1;
      return 0;
    }
  }
  if (DAT_00aa84b0 != 0xffffffff) {
    if ((int)DAT_00aa84b0 < 0) {
      DAT_00aa84ac = 1;
      return 0xffffffff;
    }
    if ((DAT_00aa84b0 & 0x7c000000) != 0x24000000) {
      DAT_00aa84ac = 1;
      return 0xffffffff;
    }
    uVar1 = DAT_00aa84b0 & 0xffff;
    if (0xff < uVar1) {
      DAT_00aa84ac = 1;
      return 0xffffffff;
    }
    if ((&DAT_00aa84b8)[uVar1 * 0x17] == 0) {
      DAT_00aa84ac = 1;
      return 0xffffffff;
    }
    if ((&DAT_00aa84bc)[uVar1 * 0x17] * 0x10000 != (DAT_00aa84b0 & 0x3ff0000)) {
      DAT_00aa84ac = 1;
      return 0xffffffff;
    }
    *(undefined4 *)(&DAT_00aa84d0 + uVar1 * 0x5c) = 0xffffffff;
    *(undefined4 *)(&DAT_00aa84d4 + uVar1 * 0x5c) = 0xffffffff;
  }
  if ((int)param_1 < 0) {
    DAT_00aa84b0 = 0xffffffff;
    return 0;
  }
  FUN_00567320();
  DAT_00aa84b0 = param_1;
  piVar2[2] = 0;
  piVar2[3] = 0;
  return 0;
}

