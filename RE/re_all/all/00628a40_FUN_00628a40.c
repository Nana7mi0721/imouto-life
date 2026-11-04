
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00628a40(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar4 = _DAT_00804108 /
          SQRT(param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1);
  fVar1 = param_1[2];
  fVar2 = param_1[1];
  fVar3 = *param_1;
  param_2[3] = 0.0;
  *param_2 = fVar4 * fVar3;
  param_2[1] = fVar4 * fVar2;
  param_2[2] = fVar4 * fVar1;
  return;
}

