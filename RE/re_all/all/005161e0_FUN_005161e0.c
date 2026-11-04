
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005161e0(uint param_1,uint param_2,uint param_3)

{
  if ((((_DAT_00a38114 >> 0x10 & 0xff) != param_1) || ((_DAT_00a38114 >> 8 & 0xff) != param_2)) ||
     ((_DAT_00a38114 & 0xff) != param_3)) {
    if (0xff < param_1) {
      if ((int)param_1 < 0x100) {
        if ((int)param_1 < 0) {
          param_1 = 0;
        }
      }
      else {
        param_1 = 0xff;
      }
    }
    if (0xff < param_2) {
      if ((int)param_2 < 0x100) {
        if ((int)param_2 < 0) {
          param_2 = 0;
        }
      }
      else {
        param_2 = 0xff;
      }
    }
    if (0xff < param_3) {
      if ((int)param_3 < 0x100) {
        if ((int)param_3 < 0) {
          param_3 = 0;
        }
      }
      else {
        param_3 = 0xff;
      }
    }
    _DAT_00a38114 =
         CONCAT22(CONCAT11(DAT_00a38114_3,(char)param_1),CONCAT11((char)param_2,(char)param_3));
    if (DAT_00a37d78 != 0) {
      FUN_00567b70(param_1,param_2,param_3);
      return 0;
    }
    FUN_00581200(_DAT_00a38114);
  }
  return 0;
}

