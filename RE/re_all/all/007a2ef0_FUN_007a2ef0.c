
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a2ef0(float *param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  
  iVar3 = param_3;
  if (0 < param_3) {
    pfVar6 = param_1 + param_3;
    do {
      if (0 < param_2 >> 1) {
        pfVar4 = param_1;
        pfVar5 = pfVar6;
        iVar7 = param_2 >> 1;
        do {
          fVar1 = *pfVar4 * _DAT_0080451c;
          fVar2 = *pfVar5 * _DAT_0080451c;
          *pfVar4 = fVar2 + fVar1;
          pfVar4 = pfVar4 + iVar3 * 2;
          *pfVar5 = fVar1 - fVar2;
          pfVar5 = pfVar5 + iVar3 * 2;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      param_1 = param_1 + 1;
      pfVar6 = pfVar6 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

