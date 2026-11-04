
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005119d0(double param_1,double param_2)

{
  if (!NAN(param_2) && param_2 < 0.0 != (param_2 == 0.0)) {
    param_2 = param_1;
  }
  if ((param_1 == _DAT_00a2d7a0) && (param_2 == _DAT_00a2d7a8)) {
    return 0;
  }
  _DAT_00a2d7a0 = param_1;
  if (!NAN(param_1) && param_1 < 0.0 != (param_1 == 0.0)) {
    _DAT_00a2d7a0 = 1.0;
  }
  _DAT_00a2d7a8 = param_2;
  if (!NAN(param_2) && param_2 < 0.0 != (param_2 == 0.0)) {
    _DAT_00a2d7a8 = 1.0;
  }
  DAT_00a2d7bc = 0;
  if (DAT_00a20c40 == 1) {
    FUN_00511210(1);
  }
  return 0;
}

