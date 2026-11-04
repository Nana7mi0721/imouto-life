
void FUN_00582730(float *param_1,float *param_2,double *param_3)

{
  *param_1 = param_2[2] * (float)param_3[2] +
             *param_2 * (float)*param_3 + param_2[1] * (float)param_3[1] + (float)param_3[3];
  param_1[1] = param_2[2] * (float)param_3[6] +
               param_2[1] * (float)param_3[5] + *param_2 * (float)param_3[4] + (float)param_3[7];
  param_1[2] = param_2[2] * (float)param_3[10] +
               param_2[1] * (float)param_3[9] + *param_2 * (float)param_3[8] + (float)param_3[0xb];
  return;
}

