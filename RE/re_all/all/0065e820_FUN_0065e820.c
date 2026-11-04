
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0065e820(double param_1,int param_2)

{
  uint uVar1;
  
  if (_DAT_00805310 <= param_1) {
    return 0x7fff;
  }
  if (param_1 <= _DAT_00805308) {
    return 0xffff;
  }
  if (_DAT_00805300 < param_1) {
    if (param_2 == 0) {
      log2((float10)param_1);
      uVar1 = __ftol();
      return uVar1;
    }
    _rand();
    log2((float10)param_1);
    uVar1 = __ftol();
    return uVar1;
  }
  if (_DAT_008052d8 <= param_1) {
    return 0;
  }
  if (param_2 == 0) {
    log2(-(float10)param_1);
    uVar1 = __ftol();
    return uVar1 | 0xffff8000;
  }
  _rand();
  log2(-(float10)param_1);
  uVar1 = __ftol();
  return uVar1 | 0xffff8000;
}

