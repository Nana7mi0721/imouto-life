
void FUN_007a7930(float *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float *pfVar9;
  float *pfVar10;
  float *local_60;
  float *local_5c;
  int local_58;
  int local_50;
  
  if (param_4 == 1) {
    if (0 < param_5) {
      do {
        fVar1 = *param_1;
        fVar2 = param_1[4];
        fVar3 = param_1[1];
        fVar4 = param_1[5];
        param_5 = param_5 + -1;
        *param_1 = param_1[4] + *param_1;
        param_1[1] = param_1[5] + param_1[1];
        param_1[4] = *param_1 - (param_1[2] + param_1[6]);
        param_1[5] = param_1[1] - (param_1[3] + param_1[7]);
        *param_1 = param_1[2] + param_1[6] + *param_1;
        param_1[1] = param_1[3] + param_1[7] + param_1[1];
        fVar5 = param_1[2];
        fVar6 = param_1[6];
        fVar7 = param_1[3];
        param_1[2] = (fVar7 - param_1[7]) + (fVar1 - fVar2);
        param_1[3] = (fVar3 - fVar4) - (fVar5 - fVar6);
        param_1[6] = (fVar1 - fVar2) - (fVar7 - param_1[7]);
        param_1[7] = (fVar5 - fVar6) + (fVar3 - fVar4);
        param_1 = param_1 + 8;
      } while (param_5 != 0);
      return;
    }
  }
  else if (0 < param_5) {
    local_50 = param_5;
    do {
      pfVar10 = *(float **)(param_3 + 0x30);
      if (0 < param_4) {
        local_58 = param_4;
        pfVar9 = param_1;
        local_60 = pfVar10;
        local_5c = pfVar10;
        do {
          fVar1 = *pfVar10 * pfVar9[param_4 * 2] - pfVar9[param_4 * 2 + 1] * pfVar10[1];
          fVar3 = pfVar9[param_4 * 2 + 1] * *pfVar10 + pfVar9[param_4 * 2] * pfVar10[1];
          fVar2 = pfVar9[param_4 * 4] * *local_60 - local_60[1] * pfVar9[param_4 * 4 + 1];
          fVar5 = pfVar9[param_4 * 4 + 1] * *local_60 + local_60[1] * pfVar9[param_4 * 4];
          fVar6 = *local_5c * pfVar9[param_4 * 6] - local_5c[1] * pfVar9[param_4 * 6 + 1];
          fVar7 = local_5c[1] * pfVar9[param_4 * 6] + *local_5c * pfVar9[param_4 * 6 + 1];
          pfVar10 = pfVar10 + param_2 * 2;
          local_60 = local_60 + param_2 * 4;
          fVar4 = *pfVar9 - fVar2;
          local_5c = local_5c + param_2 * 6;
          fVar8 = pfVar9[1] - fVar5;
          *pfVar9 = fVar2 + *pfVar9;
          pfVar9[1] = fVar5 + pfVar9[1];
          fVar2 = fVar6 + fVar1;
          fVar5 = fVar7 + fVar3;
          fVar1 = fVar1 - fVar6;
          fVar3 = fVar3 - fVar7;
          pfVar9[param_4 * 4] = *pfVar9 - fVar2;
          pfVar9[param_4 * 4 + 1] = pfVar9[1] - fVar5;
          *pfVar9 = fVar2 + *pfVar9;
          pfVar9[1] = fVar5 + pfVar9[1];
          pfVar9[param_4 * 2] = fVar3 + fVar4;
          pfVar9[param_4 * 2 + 1] = fVar8 - fVar1;
          pfVar9[param_4 * 6] = fVar4 - fVar3;
          pfVar9[param_4 * 6 + 1] = fVar1 + fVar8;
          local_58 = local_58 + -1;
          pfVar9 = pfVar9 + 2;
        } while (local_58 != 0);
      }
      param_1 = param_1 + param_6 * 2;
      local_50 = local_50 + -1;
    } while (local_50 != 0);
  }
  return;
}

