
undefined4 FUN_005c1100(int param_1,uint param_2)

{
  int *piVar1;
  
  if (param_1 == 0) {
    if ((0xff < param_2) || (piVar1 = &DAT_00ee9b48 + param_2 * 0x20, *piVar1 == 0)) {
      return 0xffffffff;
    }
  }
  else {
    piVar1 = &DAT_00ee9b48;
    param_2 = 0;
    do {
      if ((*piVar1 != 0) && (piVar1[0xd] == param_1)) break;
      if ((piVar1[0x20] != 0) && (piVar1[0x2d] == param_1)) {
        param_2 = param_2 + 1;
        piVar1 = piVar1 + 0x20;
        break;
      }
      if ((piVar1[0x40] != 0) && (piVar1[0x4d] == param_1)) {
        param_2 = param_2 + 2;
        piVar1 = piVar1 + 0x40;
        break;
      }
      if ((piVar1[0x60] != 0) && (piVar1[0x6d] == param_1)) {
        param_2 = param_2 + 3;
        piVar1 = piVar1 + 0x60;
        break;
      }
      param_2 = param_2 + 4;
      piVar1 = piVar1 + 0x80;
    } while ((int)param_2 < 0x100);
    if (param_2 == 0x100) {
      return 0xffffffff;
    }
  }
  FUN_005b8530(param_2);
  if (piVar1[0x11] != 0) {
    FUN_005d3370(piVar1[0x11]);
    piVar1[0x11] = 0;
  }
  if (piVar1[1] != 0) {
    FUN_005d3370(piVar1[1]);
    piVar1[1] = 0;
  }
  if (*piVar1 != 0) {
    *piVar1 = 0;
    DAT_00ee9b44 = DAT_00ee9b44 + -1;
  }
  return 0;
}

