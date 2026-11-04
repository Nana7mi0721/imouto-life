
void FUN_007a59a0(int *param_1,float *param_2,float *param_3,float *param_4,int param_5,int param_6,
                 int param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  short sVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  float *pfVar11;
  int iVar12;
  float *pfVar13;
  float *pfVar14;
  int iVar15;
  float *local_14;
  
  iVar15 = param_7;
  local_14 = (float *)param_1[6];
  iVar7 = *param_1;
  iVar12 = param_6;
  if (0 < param_6) {
    do {
      iVar7 = iVar7 >> 1;
      iVar12 = iVar12 + -1;
      local_14 = local_14 + iVar7;
    } while (iVar12 != 0);
  }
  iVar12 = iVar7 >> 1;
  iVar7 = iVar7 >> 2;
  pfVar11 = param_2 + (iVar12 + -1) * param_7;
  pfVar9 = param_3 + (param_5 >> 1);
  if (0 < iVar7) {
    pfVar8 = param_2;
    pfVar10 = local_14 + iVar7;
    pfVar13 = local_14;
    param_2 = (float *)*(short **)(param_1[param_6 + 2] + 0x2c);
    param_7 = iVar7;
    do {
      fVar1 = *pfVar13;
      fVar2 = *pfVar8;
      fVar3 = *pfVar10;
      fVar4 = *pfVar11;
      sVar6 = *(short *)param_2;
      fVar5 = *pfVar13;
      param_2 = (float *)((int)param_2 + 2);
      pfVar13 = pfVar13 + 1;
      pfVar9[sVar6 * 2 + 1] = *pfVar10 * *pfVar8 + fVar5 * *pfVar11;
      pfVar9[sVar6 * 2] = fVar1 * fVar2 - fVar3 * fVar4;
      pfVar8 = pfVar8 + iVar15 * 2;
      pfVar11 = pfVar11 + iVar15 * -2;
      param_7 = param_7 + -1;
      pfVar10 = pfVar10 + 1;
    } while (param_7 != 0);
  }
  FUN_007a7720(param_1[param_6 + 2],pfVar9);
  iVar15 = iVar7 + 1 >> 1;
  if (0 < iVar15) {
    pfVar11 = local_14 + iVar7;
    pfVar10 = param_3 + (param_5 >> 1) + iVar12 + -2;
    pfVar13 = local_14;
    pfVar14 = local_14 + iVar12 + -1;
    pfVar8 = pfVar11;
    local_14 = (float *)iVar15;
    do {
      pfVar8 = pfVar8 + -1;
      fVar1 = *pfVar9;
      fVar2 = *pfVar13;
      fVar3 = *pfVar11;
      fVar4 = pfVar10[1];
      pfVar13 = pfVar13 + 1;
      fVar5 = *pfVar10;
      pfVar11 = pfVar11 + 1;
      *pfVar9 = fVar2 * pfVar9[1] + fVar3 * fVar1;
      pfVar10[1] = fVar3 * pfVar9[1] - fVar2 * fVar1;
      fVar1 = *pfVar8;
      fVar2 = *pfVar14;
      local_14 = (float *)((int)local_14 + -1);
      *pfVar10 = fVar1 * fVar4 + fVar2 * fVar5;
      pfVar9[1] = fVar2 * fVar4 - fVar1 * fVar5;
      pfVar9 = pfVar9 + 2;
      pfVar10 = pfVar10 + -2;
      pfVar14 = pfVar14 + -1;
    } while (local_14 != (float *)0x0);
  }
  iVar7 = param_5 / 2;
  if (0 < iVar7) {
    iVar15 = (int)param_4 + ((param_5 * 4 + -4) - (int)(param_3 + param_5 + -1));
    pfVar11 = param_3 + param_5 + -1;
    do {
      fVar1 = *pfVar11;
      fVar2 = *param_3;
      iVar7 = iVar7 + -1;
      *param_3 = fVar2 * *(float *)(iVar15 + (int)pfVar11) - fVar1 * *param_4;
      *pfVar11 = fVar2 * *param_4 + fVar1 * *(float *)(iVar15 + 4 + (int)(pfVar11 + -1));
      pfVar11 = pfVar11 + -1;
      param_3 = param_3 + 1;
      param_4 = param_4 + 1;
    } while (iVar7 != 0);
  }
  return;
}

