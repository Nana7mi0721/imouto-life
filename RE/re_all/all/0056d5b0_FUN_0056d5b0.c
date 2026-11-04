
void FUN_0056d5b0(float *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *param_1;
  fVar2 = param_1[1];
  fVar3 = param_1[2];
  param_2[3] = (int)ROUND(param_1[3]);
  param_2[2] = (int)ROUND(fVar3);
  param_2[1] = (int)ROUND(fVar2);
  *param_2 = (int)ROUND(fVar1);
  return;
}

