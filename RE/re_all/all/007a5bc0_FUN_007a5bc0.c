
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a5bc0(float *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  
  fVar1 = *param_2;
  if (0 < param_3) {
    pfVar8 = param_1;
    for (iVar7 = param_3; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pfVar8 = 0.0;
      pfVar8 = pfVar8 + 1;
    }
  }
  if ((*param_2 != _DAT_007d5344) && (iVar7 = 0, 0 < param_3)) {
    pfVar8 = param_1;
    do {
      fVar4 = _DAT_007d5344;
      if (0 < iVar7) {
        pfVar5 = (float *)(((int)param_2 - (int)param_1) + (int)pfVar8);
        pfVar6 = param_1;
        iVar9 = iVar7;
        do {
          fVar2 = *pfVar5;
          fVar3 = *pfVar6;
          pfVar5 = pfVar5 + -1;
          pfVar6 = pfVar6 + 1;
          iVar9 = iVar9 + -1;
          fVar4 = fVar2 * fVar3 + fVar4;
        } while (iVar9 != 0);
      }
      iVar7 = iVar7 + 1;
      iVar9 = iVar7 >> 1;
      fVar4 = -((fVar4 + *(float *)(((int)param_2 - (int)param_1) + 4 + (int)pfVar8)) / fVar1);
      *pfVar8 = fVar4;
      if (0 < iVar9) {
        pfVar6 = param_1;
        pfVar5 = pfVar8;
        do {
          pfVar5 = pfVar5 + -1;
          fVar2 = *pfVar6;
          fVar3 = *pfVar5;
          iVar9 = iVar9 + -1;
          *pfVar6 = fVar3 * fVar4 + fVar2;
          *pfVar5 = fVar2 * fVar4 + fVar3;
          pfVar6 = pfVar6 + 1;
        } while (iVar9 != 0);
      }
      fVar1 = fVar1 - fVar4 * fVar4 * fVar1;
    } while ((*param_2 * _DAT_007d652c <= fVar1) && (pfVar8 = pfVar8 + 1, iVar7 < param_3));
  }
  return;
}

