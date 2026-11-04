
undefined4 FUN_00586070(double *param_1,double *param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_0056d680(param_2[2] * param_2[2] +
                                *param_2 * *param_2 + param_2[1] * param_2[1]);
  *param_1 = (double)((float10)*param_2 / fVar1);
  param_1[1] = (double)((float10)param_2[1] / fVar1);
  param_1[2] = (double)((float10)param_2[2] / fVar1);
  return 0;
}

