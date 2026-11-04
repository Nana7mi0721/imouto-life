
void __thiscall FUN_00646660(float *param_1,float *param_2)

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
  
  fVar1 = param_2[3];
  fVar2 = *param_2;
  fVar3 = *param_1;
  fVar4 = param_1[1];
  fVar5 = param_2[1];
  fVar6 = param_1[2];
  fVar7 = param_2[2];
  fVar8 = param_2[2];
  fVar9 = param_2[3];
  fVar10 = param_2[1];
  fVar11 = *param_1;
  fVar12 = param_1[1];
  fVar13 = *param_2;
  fVar14 = param_2[1];
  fVar15 = param_2[3];
  fVar16 = *param_2;
  fVar17 = param_2[2];
  fVar18 = *param_1;
  *param_1 = (param_1[1] * param_2[2] + *param_1 * param_2[3] + param_1[3] * *param_2) -
             param_1[2] * param_2[1];
  param_1[1] = (param_1[2] * fVar16 + param_1[1] * fVar15 + fVar14 * param_1[3]) - fVar17 * fVar18;
  param_1[2] = (fVar10 * fVar11 + param_1[2] * fVar9 + fVar8 * param_1[3]) - fVar12 * fVar13;
  param_1[3] = ((param_1[3] * fVar1 - fVar2 * fVar3) - fVar4 * fVar5) - fVar6 * fVar7;
  return;
}

