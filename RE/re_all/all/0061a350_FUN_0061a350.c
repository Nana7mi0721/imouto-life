
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0061a350(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float10 fVar11;
  float10 fVar12;
  
  fVar11 = (float10)FUN_0061a2f0(param_2);
  fVar11 = (float10)_DAT_007d103c / fVar11;
  fVar1 = (float)(fVar11 * (float10)param_2[1]);
  fVar12 = fVar11 * (float10)param_2[2];
  fVar9 = (float)(fVar11 * (float10)*param_2) * param_2[3];
  fVar2 = param_2[3];
  fVar3 = param_2[3];
  fVar10 = (float)(fVar11 * (float10)*param_2) * *param_2;
  fVar4 = *param_2;
  fVar5 = *param_2;
  fVar6 = param_2[1];
  fVar7 = param_2[1];
  fVar8 = param_2[2];
  param_1[3] = 0.0;
  *param_1 = (float)((float10)_DAT_00804108 - (fVar12 * (float10)fVar8 + (float10)(fVar1 * fVar6)));
  param_1[1] = fVar1 * fVar4 - (float)(fVar12 * (float10)fVar3);
  param_1[2] = (float)(fVar12 * (float10)fVar5) + fVar1 * fVar2;
  param_1[7] = 0.0;
  param_1[4] = fVar1 * fVar4 + (float)(fVar12 * (float10)fVar3);
  param_1[5] = (float)((float10)_DAT_00804108 - (fVar12 * (float10)fVar8 + (float10)fVar10));
  param_1[6] = (float)(fVar12 * (float10)fVar7) - fVar9;
  param_1[8] = (float)(fVar12 * (float10)fVar5) - fVar1 * fVar2;
  param_1[9] = (float)(fVar12 * (float10)fVar7) + fVar9;
  fVar1 = _DAT_00804108 - (fVar1 * fVar6 + fVar10);
  param_1[0xb] = 0.0;
  param_1[10] = fVar1;
  return;
}

