
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006b8530(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  int local_18;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  if (*(int *)(param_3[2] + iVar2 * 4) == 0) {
    iVar9 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 4) + 0x1c) + iVar2 * 4) / 2;
    fVar10 = (float10)*(int *)(param_2 + 4) * (float10)_DAT_007d589c;
    iVar1 = *param_3;
    fVar12 = (float10)fpatan(fVar10 * fVar10 * (float10)_DAT_00829838,(float10)1);
    fVar4 = (float10)_DAT_00829830;
    fVar13 = (float10)fpatan(fVar10 * (float10)_DAT_00829828,(float10)1);
    fVar5 = (float10)_DAT_00829820;
    fVar3 = (float10)_DAT_008298b0;
    pvVar6 = _malloc(iVar9 * 4 + 4);
    *(void **)(param_3[2] + iVar2 * 4) = pvVar6;
    iVar8 = 0;
    local_18 = 0;
    if (0 < iVar9) {
      do {
        fVar11 = (((float10)*(int *)(param_2 + 4) * (float10)_DAT_007d589c) / (float10)iVar9) *
                 (float10)local_18;
        fVar14 = (float10)fpatan(fVar11 * fVar11 * (float10)_DAT_00829838,(float10)1);
        fVar15 = (float10)fpatan(fVar11 * (float10)_DAT_00829828,(float10)1);
        FUN_006c5af0((double)((float10)(float)((float10)iVar1 /
                                              (fVar10 * fVar3 + fVar13 * fVar5 + fVar12 * fVar4)) *
                             (fVar11 * (float10)_DAT_008298b0 +
                             fVar15 * (float10)_DAT_00829820 + fVar14 * (float10)_DAT_00829830)));
        iVar7 = __ftol();
        if (*param_3 <= iVar7) {
          iVar7 = *param_3 + -1;
        }
        iVar8 = local_18 + 1;
        *(int *)(*(int *)(param_3[2] + iVar2 * 4) + -4 + iVar8 * 4) = iVar7;
        local_18 = iVar8;
      } while (iVar8 < iVar9);
    }
    *(undefined4 *)(*(int *)(param_3[2] + iVar2 * 4) + iVar8 * 4) = 0xffffffff;
    param_3[iVar2 + 3] = iVar9;
  }
  return;
}

