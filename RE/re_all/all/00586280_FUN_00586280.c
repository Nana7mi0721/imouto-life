
undefined4
FUN_00586280(double *param_1,double *param_2,double *param_3,double *param_4,double *param_5)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar1 = *param_3;
  dVar2 = param_3[1];
  dVar3 = param_3[2];
  dVar4 = *param_4;
  *param_1 = param_5[0xc] * dVar4 + param_5[8] * dVar3 + *param_5 * dVar1 + param_5[4] * dVar2;
  param_1[1] = param_5[0xd] * dVar4 + param_5[9] * dVar3 + param_5[1] * dVar1 + param_5[5] * dVar2;
  param_1[2] = param_5[0xe] * dVar4 + param_5[10] * dVar3 + param_5[2] * dVar1 + param_5[6] * dVar2;
  *param_2 = dVar4 * param_5[0xf] + dVar3 * param_5[0xb] + param_5[7] * dVar2 + param_5[3] * dVar1;
  return 0;
}

