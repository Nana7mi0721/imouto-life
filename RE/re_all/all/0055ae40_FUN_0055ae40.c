
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0055ae40(uint param_1,uint param_2)

{
  short sVar1;
  int *piVar2;
  int *piVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  short *psVar7;
  short *psVar8;
  byte *pbVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  if (((((((DAT_00cc50a0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc50c8))
        || ((DAT_00cc50d0 <= (int)(param_1 & 0xffff) ||
            (piVar2 = *(int **)(DAT_00cc50a4 + (param_1 & 0xffff) * 4), piVar2 == (int *)0x0)))) ||
       ((*piVar2 * 0x10000 != (param_1 & 0x3ff0000) || ((piVar2[0xc] == 1 || ((int)param_2 < 0))))))
      || ((param_2 & 0x7c000000) != DAT_00cc50c8)) ||
     ((((DAT_00cc50d0 <= (int)(param_2 & 0xffff) ||
        (piVar3 = *(int **)(DAT_00cc50a4 + (param_2 & 0xffff) * 4), piVar3 == (int *)0x0)) ||
       (*piVar3 * 0x10000 != (param_2 & 0x3ff0000))) ||
      (((piVar3[0xc] == 1 || (iVar12 = piVar2[0x12], iVar12 != piVar3[0x12])) ||
       ((sVar1 = *(short *)((int)piVar2 + 0x36), sVar1 != *(short *)((int)piVar3 + 0x36) ||
        (((short)piVar2[0xd] == 3 || ((short)piVar3[0xd] != 3)))))))))) {
    return 0xffffffff;
  }
  pfVar6 = (float *)piVar3[0x13];
  if (*(short *)((int)piVar2 + 0x42) == 8) {
    fVar4 = (float)_DAT_007d62a0;
    pbVar10 = (byte *)piVar2[0x13];
    if (sVar1 == 1) {
      iVar11 = 0;
      if (3 < iVar12) {
        iVar13 = iVar11;
        pfVar5 = pfVar6 + 2;
        do {
          iVar11 = iVar13 + 4;
          pfVar5[-2] = (float)(int)(pbVar10[iVar13] - 0x7f) * fVar4;
          pfVar5[-1] = (float)(int)(pbVar10[iVar13 + 1] - 0x7f) * fVar4;
          *pfVar5 = (float)(int)(pbVar10[iVar13 + 2] - 0x7f) * fVar4;
          pfVar5[1] = (float)(int)(pbVar10[iVar13 + 3] - 0x7f) * fVar4;
          iVar13 = iVar11;
          pfVar5 = pfVar5 + 4;
        } while (iVar11 < iVar12 + -3);
      }
      if (iVar11 < iVar12) {
        do {
          iVar13 = iVar11 + 1;
          pfVar6[iVar11] = (float)(int)(pbVar10[iVar11] - 0x7f) * fVar4;
          iVar11 = iVar13;
        } while (iVar13 < iVar12);
        return 0;
      }
    }
    else {
      iVar11 = 0;
      if (3 < iVar12) {
        iVar13 = (iVar12 - 4U >> 2) + 1;
        iVar11 = iVar13 * 4;
        pfVar5 = pfVar6;
        pbVar9 = pbVar10;
        do {
          pfVar6 = pfVar5 + 8;
          pbVar10 = pbVar9 + 8;
          *pfVar5 = (float)(int)(*pbVar9 - 0x7f) * fVar4;
          pfVar5[1] = (float)(int)(pbVar9[1] - 0x7f) * fVar4;
          pfVar5[2] = (float)(int)(pbVar9[2] - 0x7f) * fVar4;
          pfVar5[3] = (float)(int)(pbVar9[3] - 0x7f) * fVar4;
          pfVar5[4] = (float)(int)(pbVar9[4] - 0x7f) * fVar4;
          pfVar5[5] = (float)(int)(pbVar9[5] - 0x7f) * fVar4;
          pfVar5[6] = (float)(int)(pbVar9[6] - 0x7f) * fVar4;
          iVar13 = iVar13 + -1;
          pfVar5[7] = (float)(int)(pbVar9[7] - 0x7f) * fVar4;
          pfVar5 = pfVar6;
          pbVar9 = pbVar10;
        } while (iVar13 != 0);
      }
      if (iVar11 < iVar12) {
        iVar12 = iVar12 - iVar11;
        do {
          *pfVar6 = (float)(int)(*pbVar10 - 0x7f) * fVar4;
          iVar12 = iVar12 + -1;
          pfVar6[1] = (float)(int)(pbVar10[1] - 0x7f) * fVar4;
          pfVar6 = pfVar6 + 2;
          pbVar10 = pbVar10 + 2;
        } while (iVar12 != 0);
      }
    }
  }
  else if (*(short *)((int)piVar2 + 0x42) == 0x10) {
    fVar4 = (float)_DAT_00805410;
    psVar8 = (short *)piVar2[0x13];
    if (sVar1 == 1) {
      iVar11 = 0;
      if (3 < iVar12) {
        iVar13 = (iVar12 - 4U >> 2) + 1;
        iVar11 = iVar13 * 4;
        psVar7 = psVar8 + 2;
        pfVar5 = pfVar6 + 2;
        do {
          iVar13 = iVar13 + -1;
          pfVar5[-2] = (float)(int)psVar7[-2] * fVar4;
          pfVar5[-1] = (float)(int)psVar7[-1] * fVar4;
          *pfVar5 = (float)(int)*psVar7 * fVar4;
          pfVar5[1] = (float)(int)psVar7[1] * fVar4;
          psVar7 = psVar7 + 4;
          pfVar5 = pfVar5 + 4;
        } while (iVar13 != 0);
      }
      if (iVar11 < iVar12) {
        do {
          iVar13 = iVar11 + 1;
          pfVar6[iVar11] = (float)(int)psVar8[iVar11] * fVar4;
          iVar11 = iVar13;
        } while (iVar13 < iVar12);
        return 0;
      }
    }
    else {
      iVar11 = 0;
      if (3 < iVar12) {
        iVar13 = (iVar12 - 4U >> 2) + 1;
        iVar11 = iVar13 * 4;
        pfVar5 = pfVar6;
        psVar7 = psVar8;
        do {
          pfVar6 = pfVar5 + 8;
          psVar8 = psVar7 + 8;
          iVar13 = iVar13 + -1;
          *pfVar5 = (float)(int)*psVar7 * fVar4;
          pfVar5[1] = (float)(int)psVar7[1] * fVar4;
          pfVar5[2] = (float)(int)psVar7[2] * fVar4;
          pfVar5[3] = (float)(int)psVar7[3] * fVar4;
          pfVar5[4] = (float)(int)psVar7[4] * fVar4;
          pfVar5[5] = (float)(int)psVar7[5] * fVar4;
          pfVar5[6] = (float)(int)psVar7[6] * fVar4;
          pfVar5[7] = (float)(int)psVar7[7] * fVar4;
          pfVar5 = pfVar6;
          psVar7 = psVar8;
        } while (iVar13 != 0);
      }
      if (iVar11 < iVar12) {
        iVar12 = iVar12 - iVar11;
        do {
          iVar12 = iVar12 + -1;
          *pfVar6 = (float)(int)*psVar8 * fVar4;
          pfVar6[1] = (float)(int)psVar8[1] * fVar4;
          pfVar6 = pfVar6 + 2;
          psVar8 = psVar8 + 2;
        } while (iVar12 != 0);
        return 0;
      }
    }
  }
  return 0;
}

