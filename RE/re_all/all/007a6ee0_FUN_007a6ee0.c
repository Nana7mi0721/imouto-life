
void FUN_007a6ee0(float *param_1,float *param_2,int param_3,int param_4,float *param_5)

{
  float *pfVar1;
  float *pfVar2;
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
  float *pfVar13;
  float *pfVar14;
  float local_1c;
  float local_18;
  
  pfVar13 = param_5;
  fVar4 = param_2[1];
  fVar5 = *param_2;
  fVar6 = param_2[3];
  fVar7 = param_2[2];
  fVar8 = param_2[4];
  param_2 = (float *)*param_5;
  pfVar1 = param_5 + 1;
  fVar3 = param_5[3];
  local_1c = param_5[2];
  pfVar2 = param_5 + 4;
  param_5 = (float *)*pfVar1;
  local_18 = *pfVar2;
  if (0 < param_4) {
    pfVar14 = param_1;
    do {
      fVar9 = fVar3;
      fVar3 = local_1c;
      fVar10 = (float)param_2 * fVar5;
      param_4 = param_4 + -1;
      fVar11 = (float)param_5 * fVar4;
      fVar12 = local_1c * fVar7;
      local_1c = (float)param_5;
      param_5 = param_2;
      param_2 = (float *)*pfVar14;
      *(float *)((param_3 - (int)param_1) + -4 + (int)(pfVar14 + 1)) =
           local_18 * fVar8 + fVar9 * fVar6 + fVar12 + fVar11 + fVar10 + *pfVar14;
      pfVar14 = pfVar14 + 1;
      local_18 = fVar9;
    } while (param_4 != 0);
  }
  pfVar13[3] = fVar3;
  *pfVar13 = (float)param_2;
  pfVar13[1] = (float)param_5;
  pfVar13[2] = local_1c;
  pfVar13[4] = local_18;
  return;
}

