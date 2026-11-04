
void __thiscall FUN_0063abf0(float *param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  float fVar2;
  
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  *param_1 = param_4 * *param_2 + *param_1;
  param_1[1] = param_4 * fVar1 + param_1[1];
  param_1[2] = param_4 * fVar2 + param_1[2];
  fVar1 = param_3[1];
  fVar2 = param_3[2];
  param_1[4] = param_4 * param_1[8] * *param_3 + param_1[4];
  param_1[5] = param_4 * param_1[9] * fVar1 + param_1[5];
  param_1[6] = param_4 * param_1[10] * fVar2 + param_1[6];
  return;
}

