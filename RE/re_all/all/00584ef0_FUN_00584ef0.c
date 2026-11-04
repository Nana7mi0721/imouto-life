
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00584ef0(double *param_1,double *param_2,double *param_3)

{
  double dVar1;
  double dVar2;
  float10 fVar3;
  
  dVar2 = _DAT_00805148;
  dVar1 = param_3[2] * param_3[2] + *param_3 * *param_3 + param_3[1] * param_3[1];
  if (dVar1 < _DAT_007d56d0) {
    *param_1 = _DAT_00805148;
    param_1[1] = dVar2;
    param_1[2] = dVar2;
    param_1[3] = dVar2;
    return;
  }
  fVar3 = (float10)FUN_0056d680(dVar1);
  *param_1 = (double)((float10)*param_3 / fVar3);
  param_1[1] = (double)((float10)param_3[1] / fVar3);
  dVar1 = param_3[2];
  param_1[2] = (double)((float10)dVar1 / fVar3);
  param_1[3] = (double)-((float10)*param_1 * (float10)*param_2 +
                         (float10)param_2[1] * (float10)param_1[1] +
                        (float10)param_2[2] * ((float10)dVar1 / fVar3));
  return;
}

