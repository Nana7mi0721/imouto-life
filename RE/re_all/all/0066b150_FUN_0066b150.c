
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0066b150(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  float10 fVar2;
  
  if (param_4 != 0) {
    if ((param_2 == 0) || (param_3 == 0)) {
      *param_1 = 0;
      return 1;
    }
    fVar2 = (float10)FUN_006c5af0(((double)param_2 * (double)param_3) / (double)param_4 +
                                  _DAT_00804a60);
    if ((fVar2 <= (float10)_DAT_0081ec18) && ((float10)_DAT_0081ec10 <= fVar2)) {
      uVar1 = __ftol();
      *param_1 = uVar1;
      return 1;
    }
  }
  return 0;
}

