
undefined4 FUN_00586200(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  *param_1 = fVar2 * param_3[4] + fVar1 * *param_3 + fVar3 * param_3[8];
  param_1[1] = param_3[9] * fVar3 + param_3[1] * fVar1 + param_3[5] * fVar2;
  param_1[2] = fVar3 * param_3[10] + param_3[6] * fVar2 + param_3[2] * fVar1;
  return 0;
}

