
void FUN_0056d610(double *param_1,int *param_2)

{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar1 = *param_1;
  dVar2 = param_1[1];
  dVar3 = param_1[2];
  param_2[3] = (int)ROUND(param_1[3]);
  param_2[2] = (int)ROUND(dVar3);
  param_2[1] = (int)ROUND(dVar2);
  *param_2 = (int)ROUND(dVar1);
  return;
}

