
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a7ba0(float *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float *pfVar9;
  float *pfVar10;
  float *pfVar11;
  int local_50;
  int local_48;
  
  fVar3 = *(float *)(*(int *)(param_3 + 0x30) + 4 + param_2 * param_4 * 8);
  if (0 < param_5) {
    local_48 = param_5;
    do {
      local_50 = param_4;
      pfVar10 = *(float **)(param_3 + 0x30);
      pfVar9 = param_1;
      pfVar11 = pfVar10;
      do {
        fVar4 = pfVar9[param_4 * 2] * *pfVar11 - pfVar11[1] * pfVar9[param_4 * 2 + 1];
        fVar2 = *pfVar11;
        pfVar1 = pfVar11 + 1;
        pfVar11 = pfVar11 + param_2 * 2;
        fVar6 = pfVar9[param_4 * 2] * *pfVar1 + fVar2 * pfVar9[param_4 * 2 + 1];
        fVar5 = *pfVar10 * pfVar9[param_4 * 4] - pfVar10[1] * pfVar9[param_4 * 4 + 1];
        pfVar1 = pfVar10 + 1;
        fVar2 = *pfVar10;
        pfVar10 = pfVar10 + param_2 * 4;
        local_50 = local_50 + -1;
        fVar7 = fVar2 * pfVar9[param_4 * 4 + 1] + pfVar9[param_4 * 4] * *pfVar1;
        fVar2 = fVar5 + fVar4;
        fVar8 = fVar7 + fVar6;
        pfVar9[param_4 * 2] = *pfVar9 - fVar2 * _DAT_007d589c;
        pfVar9[param_4 * 2 + 1] = pfVar9[1] - fVar8 * _DAT_007d589c;
        fVar4 = (fVar4 - fVar5) * fVar3;
        fVar5 = fVar3 * (fVar6 - fVar7);
        *pfVar9 = fVar2 + *pfVar9;
        pfVar9[1] = fVar8 + pfVar9[1];
        pfVar9[param_4 * 4] = fVar5 + pfVar9[param_4 * 2];
        pfVar9[param_4 * 4 + 1] = pfVar9[param_4 * 2 + 1] - fVar4;
        pfVar9[param_4 * 2] = pfVar9[param_4 * 2] - fVar5;
        pfVar9[param_4 * 2 + 1] = fVar4 + pfVar9[param_4 * 2 + 1];
        pfVar9 = pfVar9 + 2;
      } while (local_50 != 0);
      param_1 = param_1 + param_6 * 2;
      local_48 = local_48 + -1;
    } while (local_48 != 0);
  }
  return;
}

