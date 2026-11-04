
void __thiscall FUN_0061a8b0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  if ((param_1[1] - param_3[1]) * (param_1[1] - param_3[1]) +
      (*param_1 - *param_3) * (*param_1 - *param_3) +
      (param_1[2] - param_3[2]) * (param_1[2] - param_3[2]) +
      (param_1[3] - param_3[3]) * (param_1[3] - param_3[3]) <
      (*param_3 + *param_1) * (*param_3 + *param_1) +
      (param_3[3] + param_1[3]) * (param_3[3] + param_1[3]) +
      (param_3[1] + param_1[1]) * (param_3[1] + param_1[1]) +
      (param_1[2] + param_3[2]) * (param_1[2] + param_3[2])) {
    *param_2 = *param_3;
    param_2[1] = param_3[1];
    param_2[2] = param_3[2];
    param_2[3] = param_3[3];
    return;
  }
  fVar1 = param_3[3];
  fVar2 = param_3[2];
  fVar3 = param_3[1];
  *param_2 = -*param_3;
  param_2[1] = -fVar3;
  param_2[2] = -fVar2;
  param_2[3] = -fVar1;
  return;
}

