
undefined4 FUN_005860f0(double *param_1,double *param_2,double *param_3)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  
  dVar1 = *param_2;
  dVar2 = param_2[1];
  dVar3 = param_2[2];
  dVar4 = *param_3;
  dVar5 = param_3[1];
  dVar6 = param_3[2];
  *param_1 = dVar6 * dVar2 - dVar5 * dVar3;
  param_1[1] = dVar4 * dVar3 - dVar6 * dVar1;
  param_1[2] = dVar1 * dVar5 - dVar4 * dVar2;
  return 0;
}

