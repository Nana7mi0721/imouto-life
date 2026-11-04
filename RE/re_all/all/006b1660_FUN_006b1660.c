
void FUN_006b1660(float *param_1,int param_2,float *param_3,float *param_4,int param_5)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  uint uVar9;
  int iVar10;
  float *pfVar11;
  float *pfVar12;
  float *local_14;
  float *local_10;
  float *local_c;
  int local_8;
  
  uVar4 = (uint)param_1;
  iVar10 = (int)param_1 * param_2;
  if (0 < param_2) {
    local_10 = param_4;
    pfVar6 = param_3 + iVar10;
    param_1 = param_4 + (int)param_1 * 2 + -1;
    local_14 = (float *)param_2;
    pfVar5 = param_3;
    do {
      *local_10 = *pfVar5 + *pfVar6;
      *param_1 = *pfVar5 - *pfVar6;
      local_10 = local_10 + uVar4 * 2;
      pfVar5 = pfVar5 + uVar4;
      pfVar6 = pfVar6 + uVar4;
      param_1 = param_1 + uVar4 * 2;
      local_14 = (float *)((int)local_14 + -1);
    } while (local_14 != (float *)0x0);
  }
  if (1 < (int)uVar4) {
    if (uVar4 != 2) {
      if (0 < param_2) {
        local_14 = param_3 + iVar10;
        local_10 = param_4;
        param_1 = param_3;
        local_c = param_4 + uVar4 * 2;
        local_8 = param_2;
        do {
          if (2 < (int)uVar4) {
            pfVar8 = (float *)(param_5 + 4);
            uVar9 = uVar4 - 1 >> 1;
            pfVar6 = local_14;
            pfVar5 = param_1;
            pfVar11 = local_c;
            pfVar12 = local_10;
            do {
              pfVar7 = pfVar5 + 2;
              fVar3 = pfVar6[2] * *pfVar8 + pfVar8[-1] * pfVar6[1];
              pfVar1 = pfVar8 + -1;
              fVar2 = *pfVar8;
              pfVar8 = pfVar8 + 2;
              uVar9 = uVar9 - 1;
              fVar2 = *pfVar1 * pfVar6[2] - fVar2 * pfVar6[1];
              pfVar12[2] = fVar2 + *pfVar7;
              pfVar11[-2] = fVar2 - *pfVar7;
              pfVar12[1] = fVar3 + pfVar5[1];
              pfVar11[-3] = pfVar5[1] - fVar3;
              pfVar6 = pfVar6 + 2;
              pfVar5 = pfVar7;
              pfVar11 = pfVar11 + -2;
              pfVar12 = pfVar12 + 2;
            } while (uVar9 != 0);
          }
          param_1 = param_1 + uVar4;
          local_c = local_c + uVar4 * 2;
          local_14 = local_14 + uVar4;
          local_10 = local_10 + uVar4 * 2;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
      }
      uVar9 = uVar4 & 0x80000001;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;
      }
      if (uVar9 == 1) {
        return;
      }
    }
    if (0 < param_2) {
      pfVar6 = param_3 + (uVar4 - 1);
      param_4 = param_4 + uVar4;
      param_3 = param_3 + (uVar4 - 1) + iVar10;
      do {
        *param_4 = -*param_3;
        param_3 = param_3 + uVar4;
        param_4[-1] = *pfVar6;
        param_4 = param_4 + uVar4 * 2;
        pfVar6 = pfVar6 + uVar4;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
  }
  return;
}

