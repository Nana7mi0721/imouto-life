
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a2af0(int param_1,int param_2,float *param_3,int param_4,int param_5,int param_6,
                 float *param_7,int param_8,int param_9)

{
  float fVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  int iVar10;
  short *psVar11;
  float10 fVar12;
  float10 fVar13;
  
  iVar3 = (int)param_7;
  iVar5 = *(int *)(param_1 + 0x20);
  iVar4 = *(int *)(param_1 + 0x2c) * (int)param_7;
  param_1 = (int)*(short *)(iVar5 + param_6 * 2) * (int)param_7;
  if (param_8 != 1) {
    param_8 = iVar4 / param_8;
    if (param_8 <= param_1) {
      param_1 = param_8;
    }
  }
  if (param_9 != 0) {
    param_6 = 0;
    param_1 = 0;
    param_5 = 0;
  }
  psVar11 = (short *)(iVar5 + param_5 * 2);
  iVar5 = (int)*(short *)(iVar5 + param_5 * 2) * (int)param_7;
  iVar10 = 0;
  pfVar7 = param_3;
  if (0 < iVar5) {
    do {
      *pfVar7 = 0.0;
      pfVar7 = pfVar7 + 1;
      iVar10 = iVar10 + 1;
    } while (iVar10 < (int)*psVar11 * (int)param_7);
  }
  if (param_5 < param_6) {
    pfVar9 = (float *)(param_4 + param_5 * 4);
    param_6 = param_6 - param_5;
    param_7 = (float *)(param_2 + iVar5 * 4);
    do {
      iVar5 = *psVar11 * iVar3;
      sVar2 = psVar11[1];
      fVar13 = (float10)1.4426950408889634 *
               ((float10)*(float *)(((int)&DAT_0083c5d4 - param_4) + (int)pfVar9) + (float10)*pfVar9
               ) * (float10)_DAT_008376a0;
      fVar12 = ROUND(fVar13);
      fVar13 = (float10)f2xm1(fVar13 - fVar12);
      fVar12 = (float10)fscale((float10)1 + fVar13,fVar12);
      pfVar8 = pfVar7;
      do {
        fVar1 = *param_7;
        pfVar7 = pfVar8 + 1;
        param_7 = param_7 + 1;
        iVar5 = iVar5 + 1;
        *pfVar8 = (float)(fVar12 * (float10)fVar1);
        pfVar8 = pfVar7;
      } while (iVar5 < sVar2 * iVar3);
      psVar11 = psVar11 + 1;
      pfVar9 = pfVar9 + 1;
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  pfVar7 = param_3 + param_1;
  for (uVar6 = iVar4 - param_1 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pfVar7 = 0.0;
    pfVar7 = pfVar7 + 1;
  }
  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)pfVar7 = 0;
    pfVar7 = (float *)((int)pfVar7 + 1);
  }
  return;
}

