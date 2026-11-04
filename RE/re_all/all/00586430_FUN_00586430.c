
undefined4 FUN_00586430(double *param_1,double *param_2,double *param_3,double *param_4)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  
  dVar1 = *param_3 - *param_2;
  dVar9 = param_3[1] - param_2[1];
  dVar8 = param_3[2] - param_2[2];
  dVar6 = param_4[1] * dVar8 - param_4[2] * dVar9;
  dVar7 = -(*param_4 * dVar8 - param_4[2] * dVar1);
  dVar5 = *param_4 * dVar9 - param_4[1] * dVar1;
  dVar3 = dVar5 * dVar9 - dVar7 * dVar8;
  dVar4 = -(dVar5 * dVar1 - dVar6 * dVar8);
  dVar2 = dVar7 * dVar1 - dVar6 * dVar9;
  fVar10 = (float10)FUN_0056d680(dVar6 * dVar6 + dVar7 * dVar7 + dVar5 * dVar5);
  fVar11 = (float10)FUN_0056d680(dVar2 * dVar2 + dVar3 * dVar3 + dVar4 * dVar4);
  fVar12 = (float10)FUN_0056d680(dVar8 * dVar8 + dVar9 * dVar9 + dVar1 * dVar1);
  *param_1 = (double)((float10)dVar6 / fVar10);
  param_1[1] = (double)((float10)dVar3 / fVar11);
  param_1[2] = (double)((float10)dVar1 / fVar12);
  param_1[3] = 0.0;
  param_1[4] = (double)((float10)dVar7 / fVar10);
  param_1[5] = (double)((float10)dVar4 / fVar11);
  param_1[6] = (double)((float10)dVar9 / fVar12);
  param_1[7] = 0.0;
  param_1[8] = (double)((float10)dVar5 / fVar10);
  param_1[9] = (double)((float10)dVar2 / fVar11);
  param_1[10] = (double)((float10)dVar8 / fVar12);
  param_1[0xb] = 0.0;
  param_1[0xf] = 1.0;
  param_1[0xc] = -((double)((float10)dVar5 / fVar10) * param_2[2] +
                  param_2[1] * (double)((float10)dVar7 / fVar10) +
                  *param_2 * (double)((float10)dVar6 / fVar10));
  param_1[0xd] = -((double)((float10)dVar2 / fVar11) * param_2[2] +
                  param_2[1] * (double)((float10)dVar4 / fVar11) +
                  *param_2 * (double)((float10)dVar3 / fVar11));
  param_1[0xe] = (double)-((float10)param_2[2] * (float10)(double)((float10)dVar8 / fVar12) +
                          (float10)param_2[1] * (float10)(double)((float10)dVar9 / fVar12) +
                          (float10)*param_2 * ((float10)dVar1 / fVar12));
  return 0;
}

