
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0065eb60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                int param_5)

{
  int iVar1;
  int iVar2;
  
  if ((double)CONCAT44(param_4,param_3) < _DAT_00805390) {
    iVar1 = FUN_0065ecc0(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  if (param_5 != 0) {
    _rand();
  }
  iVar1 = __ftol();
  if (0xa2 < iVar1) {
    iVar1 = FUN_0065ecc0(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  if ((float)(double)CONCAT44(param_2,param_1) < *(float *)(&DAT_00a0aaf8 + iVar1 * 8)) {
    iVar1 = FUN_0065ecc0(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  if (param_5 != 0) {
    _rand();
  }
  iVar2 = __ftol();
  if (iVar2 < *(short *)(&DAT_00a0aafc + iVar1 * 8)) {
    return *(short *)(&DAT_00a0aafe + iVar1 * 8) + iVar2;
  }
  iVar1 = FUN_0065ecc0(param_1,param_2,param_3,param_4);
  return iVar1;
}

