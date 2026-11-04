
double * FUN_00516300(double *param_1,undefined1 param_2)

{
  double local_8;
  
  local_8 = 1.0;
  FUN_00586280(param_1,&local_8,&param_2,&local_8,&DAT_00a387e0);
  local_8 = 1.0 / local_8;
  *param_1 = *param_1 * local_8;
  param_1[1] = local_8 * param_1[1];
  param_1[2] = local_8 * param_1[2];
  return param_1;
}

