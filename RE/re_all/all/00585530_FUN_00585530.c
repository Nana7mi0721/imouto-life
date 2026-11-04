
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00585530(double *param_1,double param_2,double param_3,double param_4,double param_5)

{
  double dVar1;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  
  if (param_5 < 0.0) {
    if ((DAT_00dda470 == 0) || (DAT_00dda474 == 0)) {
      param_5 = _DAT_007d0a70;
    }
    else {
      param_5 = (double)DAT_00dda474 / (double)DAT_00dda470;
    }
  }
  FUN_0056d4a0(param_2 * _DAT_00804a60,&local_68,&local_60);
  local_48 = param_4 - param_3;
  dVar1 = local_48;
  if (local_48 < 0.0) {
    dVar1 = -local_48;
  }
  if (_DAT_00804678 <= dVar1) {
    dVar1 = local_68;
    if (local_68 < 0.0) {
      dVar1 = -local_68;
    }
    if (_DAT_00804678 <= dVar1) {
      local_50 = local_60 / local_68;
      local_58 = param_5 * local_50;
      local_48 = param_4 / local_48;
      FUN_0056d380();
      *param_1 = local_58;
      param_1[5] = local_50;
      param_1[10] = local_48;
      param_1[0xe] = -(local_48 * param_3);
      param_1[0xb] = 1.0;
      param_1[0xf] = 0.0;
      return 0;
    }
    return 0xffffffff;
  }
  return 0xffffffff;
}

