
void FUN_005fc730(float *param_1,float *param_2,float *param_3)

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
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  
  fVar1 = param_2[9];
  fVar2 = param_3[1];
  fVar3 = param_2[10];
  fVar4 = param_3[2];
  fVar5 = *param_3;
  fVar6 = param_2[8];
  fVar7 = param_2[5];
  fVar8 = param_3[1];
  fVar9 = param_2[6];
  fVar10 = param_3[2];
  fVar11 = param_2[4];
  fVar12 = *param_3;
  fVar13 = param_2[1];
  fVar14 = param_3[1];
  fVar15 = param_2[2];
  fVar16 = param_3[2];
  fVar17 = *param_2;
  fVar18 = *param_3;
  param_1[3] = 0.0;
  *param_1 = fVar17 * fVar18 + fVar15 * fVar16 + fVar13 * fVar14;
  param_1[1] = fVar11 * fVar12 + fVar9 * fVar10 + fVar7 * fVar8;
  param_1[2] = fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2;
  return;
}

