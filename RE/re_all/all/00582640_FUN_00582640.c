
void FUN_00582640(double *param_1,double *param_2,float param_3)

{
  *param_1 = (double)(param_3 * (float)*param_2 + (float)*param_1);
  param_1[1] = (double)(param_3 * (float)param_2[1] + (float)param_1[1]);
  param_1[2] = (double)(param_3 * (float)param_2[2] + (float)param_1[2]);
  param_1[3] = (double)(param_3 * (float)param_2[3] + (float)param_1[3]);
  param_1[4] = (double)(param_3 * (float)param_2[4] + (float)param_1[4]);
  param_1[5] = (double)(param_3 * (float)param_2[5] + (float)param_1[5]);
  param_1[6] = (double)(param_3 * (float)param_2[6] + (float)param_1[6]);
  param_1[7] = (double)(param_3 * (float)param_2[7] + (float)param_1[7]);
  param_1[8] = (double)(param_3 * (float)param_2[8] + (float)param_1[8]);
  param_1[9] = (double)(param_3 * (float)param_2[9] + (float)param_1[9]);
  param_1[10] = (double)(param_3 * (float)param_2[10] + (float)param_1[10]);
  param_1[0xb] = (double)(param_3 * (float)param_2[0xb] + (float)param_1[0xb]);
  return;
}

