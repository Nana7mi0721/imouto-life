
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0061a0b0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 fVar5;
  float10 fVar6;
  
  fVar1 = *param_3;
  fVar6 = (float10)_DAT_007d589c;
  fVar5 = (float10)fsin((float10)fVar1 * fVar6);
  fVar2 = (float)(fVar5 / SQRT((float10)param_2[2] * (float10)param_2[2] +
                               (float10)param_2[1] * (float10)param_2[1] +
                               (float10)*param_2 * (float10)*param_2));
  fVar3 = param_2[2];
  fVar4 = param_2[1];
  *param_1 = fVar2 * *param_2;
  param_1[1] = fVar2 * fVar4;
  param_1[2] = fVar2 * fVar3;
  fVar6 = (float10)fcos((float10)fVar1 * fVar6);
  param_1[3] = (float)fVar6;
  return;
}

