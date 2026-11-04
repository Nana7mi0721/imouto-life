
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006b8690(int param_1,int param_2,int param_3,float param_4,float *param_5,uint param_6,
                 float param_7,float param_8)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  float *pfVar6;
  float *pfVar7;
  uint uVar8;
  int iVar9;
  float10 fVar10;
  float10 fVar11;
  
  fVar3 = _DAT_00802ebc / (float)(int)param_4;
  if (0 < (int)param_6) {
    pfVar6 = param_5;
    uVar8 = param_6;
    do {
      fVar10 = (float10)fcos((float10)*pfVar6);
      uVar8 = uVar8 - 1;
      *pfVar6 = (float)(fVar10 + fVar10);
      pfVar6 = pfVar6 + 1;
    } while (uVar8 != 0);
  }
  iVar9 = 0;
  if (0 < param_3) {
    do {
      iVar2 = *(int *)(param_2 + iVar9 * 4);
      uVar8 = 1;
      fVar10 = (float10)_DAT_007d589c;
      param_4 = 0.5;
      fVar11 = (float10)fcos((float10)iVar2 * (float10)fVar3);
      fVar1 = (float)(fVar11 + fVar11);
      if (1 < (int)param_6) {
        param_4 = 0.5;
        uVar5 = param_6 >> 1;
        uVar8 = uVar5 * 2 + 1;
        pfVar6 = param_5 + 1;
        do {
          uVar5 = uVar5 - 1;
          fVar10 = ((float10)fVar1 - (float10)pfVar6[-1]) * fVar10;
          param_4 = (fVar1 - *pfVar6) * param_4;
          pfVar6 = pfVar6 + 2;
        } while (uVar5 != 0);
      }
      if (uVar8 == param_6) {
        fVar11 = ((float10)fVar1 - (float10)param_5[uVar8 - 1]) * fVar10;
        fVar4 = _DAT_008298e4 - fVar1 * fVar1;
        fVar10 = fVar11;
      }
      else {
        fVar4 = _DAT_007d103c - fVar1;
        fVar11 = ((float10)fVar1 + (float10)_DAT_007d103c) * fVar10;
      }
      param_4 = fVar4 * param_4 * param_4;
      iVar9 = iVar9 + 1;
      fVar11 = (float10)1.4426950408889634 *
               ((float10)param_7 / SQRT(fVar11 * fVar10 + (float10)param_4) - (float10)param_8) *
               (float10)_DAT_00831d58;
      fVar10 = ROUND(fVar11);
      fVar11 = (float10)f2xm1(fVar11 - fVar10);
      fVar10 = (float10)fscale((float10)1 + fVar11,fVar10);
      *(float *)(param_1 + -4 + iVar9 * 4) = (float)fVar10 * *(float *)(param_1 + -4 + iVar9 * 4);
      if (*(int *)(param_2 + iVar9 * 4) == iVar2) {
        pfVar6 = (float *)(param_1 + iVar9 * 4);
        do {
          pfVar7 = pfVar6 + 1;
          iVar9 = iVar9 + 1;
          *pfVar6 = (float)fVar10 * *pfVar6;
          pfVar6 = pfVar7;
        } while (*(int *)((param_2 - param_1) + (int)pfVar7) == iVar2);
      }
    } while (iVar9 < param_3);
  }
  return;
}

