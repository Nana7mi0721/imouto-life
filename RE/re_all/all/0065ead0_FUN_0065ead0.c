
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0065ead0(double param_1,int param_2)

{
  undefined4 uVar1;
  
  if (_DAT_00805380 <= param_1) {
    return 0x3ff;
  }
  if (param_1 <= _DAT_00805378) {
    return 0;
  }
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

