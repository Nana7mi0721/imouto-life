
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0066b6f0(int param_1,int param_2)

{
  undefined4 uVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_006c5af0((double)param_1 * _DAT_0081ec38 * (double)param_2 + _DAT_00804a60);
  if ((fVar2 <= (float10)_DAT_0081ec18) && ((float10)_DAT_0081ec10 <= fVar2)) {
    uVar1 = __ftol();
    return uVar1;
  }
  return 0;
}

