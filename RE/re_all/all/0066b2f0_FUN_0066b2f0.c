
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0066b2f0(uint param_1)

{
  float10 fVar1;
  
  if ((param_1 != 0) && (param_1 < 0xffff)) {
    fVar1 = (float10)FUN_006c51d0(param_1,0);
    FUN_006c5af0((double)(fVar1 * (float10)_DAT_00804a68 + (float10)_DAT_00804a60));
    __ftol();
  }
  return;
}

