
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00585650(double *param_1,double param_2,double param_3,double param_4,double param_5)

{
  double dVar1;
  double dVar2;
  
  if (param_5 < 0.0) {
    if ((DAT_00dda470 == 0) || (DAT_00dda474 == 0)) {
      param_5 = _DAT_007d0a70;
    }
    else {
      param_5 = (double)DAT_00dda474 / (double)DAT_00dda470;
    }
  }
  dVar1 = param_3 - param_4;
  dVar2 = dVar1;
  if (dVar1 < 0.0) {
    dVar2 = -dVar1;
  }
  if (_DAT_00804678 <= dVar2) {
    FUN_0056d380(param_1,0,0x80);
    dVar2 = _DAT_00829868;
    *param_1 = _DAT_00829868 / (param_2 / param_5);
    param_1[5] = dVar2 / param_2;
    param_1[10] = 1.0 / (param_4 - param_3);
    param_1[0xe] = param_3 / dVar1;
    param_1[0xf] = 1.0;
    return 0;
  }
  return 0xffffffff;
}

