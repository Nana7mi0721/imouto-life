
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006b3850(int *param_1,int param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  byte bVar10;
  float *pfVar11;
  int iVar12;
  uint uVar13;
  float *pfVar14;
  int iVar15;
  int *piVar16;
  int iVar17;
  float *pfVar18;
  float afStack_44 [5];
  float local_24 [4];
  uint local_14;
  float *local_10;
  int local_c;
  
  iVar5 = *param_1;
  iVar12 = iVar5 >> 2;
  iVar15 = iVar5 >> 1;
  iVar17 = iVar5 >> 3;
  afStack_44[4] = 9.846665e-39;
  pfVar14 = afStack_44 + ((iVar15 + 5) - iVar5);
  pfVar18 = (float *)(param_2 + (iVar12 + iVar15) * 4);
  local_c = 0;
  pfVar7 = (float *)(iVar15 * 4 + param_1[2]);
  pfVar11 = pfVar18 + 1;
  if (0 < iVar17) {
    local_14 = iVar17 + 1U >> 1;
    local_c = local_14 * 2;
    pfVar8 = pfVar7;
    local_10 = pfVar14;
    do {
      fVar1 = pfVar18[-2];
      fVar2 = *pfVar11;
      fVar3 = pfVar11[2];
      pfVar18 = pfVar18 + -4;
      pfVar7 = pfVar8 + -2;
      pfVar11 = pfVar11 + 4;
      fVar4 = *pfVar18;
      *local_10 = (fVar1 + fVar2) * *pfVar7 + (fVar3 + fVar4) * pfVar8[-1];
      local_10[1] = (fVar3 + fVar4) * *pfVar7 - (fVar1 + fVar2) * pfVar8[-1];
      local_14 = local_14 - 1;
      pfVar8 = pfVar7;
      local_10 = local_10 + 2;
    } while (local_14 != 0);
  }
  pfVar11 = (float *)(param_2 + 4);
  if (local_c < iVar15 - iVar17) {
    pfVar8 = pfVar14 + local_c;
    uVar13 = ((iVar15 - iVar17) - local_c) + 1U >> 1;
    local_c = local_c + uVar13 * 2;
    pfVar9 = pfVar7;
    do {
      fVar1 = pfVar18[-2];
      fVar2 = *pfVar11;
      fVar3 = pfVar18[-4];
      pfVar18 = pfVar18 + -4;
      pfVar7 = pfVar9 + -2;
      fVar4 = pfVar11[2];
      pfVar11 = pfVar11 + 4;
      uVar13 = uVar13 - 1;
      *pfVar8 = (fVar1 - fVar2) * *pfVar7 + (fVar3 - fVar4) * pfVar9[-1];
      pfVar8[1] = (fVar3 - fVar4) * *pfVar7 - (fVar1 - fVar2) * pfVar9[-1];
      pfVar9 = pfVar7;
      pfVar8 = pfVar8 + 2;
    } while (uVar13 != 0);
  }
  pfVar18 = (float *)(param_2 + iVar5 * 4);
  if (local_c < iVar15) {
    uVar13 = (iVar15 - local_c) + 1U >> 1;
    pfVar8 = pfVar14 + local_c;
    do {
      fVar1 = pfVar18[-2];
      pfVar18 = pfVar18 + -4;
      pfVar9 = pfVar7 + -2;
      fVar2 = *pfVar11;
      fVar3 = *pfVar18;
      fVar4 = pfVar11[2];
      pfVar11 = pfVar11 + 4;
      uVar13 = uVar13 - 1;
      *pfVar8 = (-fVar1 - fVar2) * *pfVar9 + (-fVar3 - fVar4) * pfVar7[-1];
      pfVar8[1] = (-fVar3 - fVar4) * *pfVar9 - (-fVar1 - fVar2) * pfVar7[-1];
      pfVar7 = pfVar9;
      pfVar8 = pfVar8 + 2;
    } while (uVar13 != 0);
  }
  iVar17 = param_1[1];
  iVar6 = param_1[2];
  if (0 < iVar17 + -6) {
    pfVar11 = pfVar14 + iVar12 + -8 + (iVar15 - iVar12) + 7;
    pfVar18 = pfVar14 + iVar12 + -8;
    pfVar7 = (float *)(iVar6 + 0x10);
    do {
      fVar1 = pfVar11[-1];
      fVar2 = pfVar18[6];
      fVar3 = *pfVar11;
      fVar4 = pfVar18[7];
      pfVar11[-1] = pfVar18[6] + pfVar11[-1];
      *pfVar11 = pfVar18[7] + *pfVar11;
      pfVar18[6] = (fVar3 - fVar4) * pfVar7[-3] + (fVar1 - fVar2) * pfVar7[-4];
      pfVar18[7] = (fVar3 - fVar4) * pfVar7[-4] - (fVar1 - fVar2) * pfVar7[-3];
      fVar1 = pfVar11[-3];
      fVar2 = pfVar18[4];
      fVar3 = pfVar11[-2];
      fVar4 = pfVar18[5];
      pfVar11[-3] = pfVar18[4] + pfVar11[-3];
      pfVar11[-2] = pfVar11[-2] + pfVar18[5];
      pfVar18[4] = (fVar1 - fVar2) * *pfVar7 + (fVar3 - fVar4) * pfVar7[1];
      pfVar18[5] = (fVar3 - fVar4) * *pfVar7 - (fVar1 - fVar2) * pfVar7[1];
      fVar1 = pfVar11[-5];
      fVar2 = pfVar18[2];
      fVar3 = pfVar11[-4];
      fVar4 = pfVar18[3];
      pfVar11[-5] = pfVar18[2] + pfVar11[-5];
      pfVar11[-4] = pfVar18[3] + pfVar11[-4];
      pfVar18[2] = (fVar1 - fVar2) * pfVar7[4] + (fVar3 - fVar4) * pfVar7[5];
      pfVar18[3] = (fVar3 - fVar4) * pfVar7[4] - (fVar1 - fVar2) * pfVar7[5];
      fVar1 = pfVar11[-7];
      fVar2 = *pfVar18;
      fVar3 = pfVar11[-6];
      fVar4 = pfVar18[1];
      pfVar11[-7] = pfVar11[-7] + *pfVar18;
      pfVar11[-6] = pfVar18[1] + pfVar11[-6];
      pfVar8 = pfVar18 + -8;
      pfVar11 = pfVar11 + -8;
      *pfVar18 = (fVar1 - fVar2) * pfVar7[8] + (fVar3 - fVar4) * pfVar7[9];
      pfVar18[1] = (fVar3 - fVar4) * pfVar7[8] - (fVar1 - fVar2) * pfVar7[9];
      pfVar18 = pfVar8;
      pfVar7 = pfVar7 + 0x10;
    } while (pfVar14 <= pfVar8);
  }
  local_10 = (float *)(iVar17 + -7);
  bVar10 = 1;
  if (0 < (int)local_10) {
    do {
      param_2 = 1 << (bVar10 & 0x1f);
      if (0 < param_2) {
        iVar17 = iVar15 >> (bVar10 & 0x1f);
        pfVar11 = pfVar14;
        do {
          afStack_44[4 - iVar5] = (float)(4 << (bVar10 & 0x1f));
          afStack_44[3 - iVar5] = (float)iVar17;
          afStack_44[2 - iVar5] = (float)pfVar11;
          afStack_44[1 - iVar5] = (float)iVar6;
          afStack_44[-iVar5] = 9.847603e-39;
          FUN_006b3730();
          pfVar11 = pfVar11 + iVar17;
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
      bVar10 = bVar10 + 1;
      local_10 = (float *)((int)local_10 + -1);
    } while (local_10 != (float *)0x0);
  }
  if (0 < iVar15) {
    uVar13 = iVar15 + 0x1fU >> 5;
    do {
      afStack_44[4 - iVar5] = (float)pfVar14;
      afStack_44[3 - iVar5] = 9.847685e-39;
      FUN_006b31a0();
      pfVar14 = pfVar14 + 0x20;
      uVar13 = uVar13 - 1;
    } while (uVar13 != 0);
  }
  piVar16 = (int *)param_1[3];
  iVar17 = *param_1 >> 1;
  pfVar11 = (float *)(param_1[2] + *param_1 * 4);
  pfVar18 = local_24 + (iVar17 - iVar5);
  pfVar7 = local_24 + (-1 - iVar5);
  while( true ) {
    pfVar14 = afStack_44 + ((iVar17 + *piVar16 + 5) - iVar5);
    pfVar8 = afStack_44 + ((iVar17 + piVar16[1] + 5) - iVar5);
    fVar2 = (*pfVar8 + *pfVar14) * *pfVar11 + (pfVar14[1] - pfVar8[1]) * pfVar11[1];
    fVar1 = (*pfVar8 + *pfVar14) * pfVar11[1] - (pfVar14[1] - pfVar8[1]) * *pfVar11;
    fVar3 = (pfVar8[1] + pfVar14[1]) * _DAT_007d589c;
    fVar4 = (*pfVar14 - *pfVar8) * _DAT_007d589c;
    pfVar7[-2] = fVar2 + fVar3;
    pfVar18[-5] = fVar3 - fVar2;
    pfVar7[-1] = fVar1 + fVar4;
    pfVar18[-4] = fVar1 - fVar4;
    pfVar14 = afStack_44 + ((iVar17 + piVar16[2] + 5) - iVar5);
    pfVar8 = afStack_44 + ((iVar17 + piVar16[3] + 5) - iVar5);
    fVar2 = (pfVar14[1] - pfVar8[1]) * pfVar11[3] + (*pfVar8 + *pfVar14) * pfVar11[2];
    fVar1 = (*pfVar8 + *pfVar14) * pfVar11[3] - (pfVar14[1] - pfVar8[1]) * pfVar11[2];
    fVar3 = (pfVar8[1] + pfVar14[1]) * _DAT_007d589c;
    fVar4 = (*pfVar14 - *pfVar8) * _DAT_007d589c;
    *pfVar7 = fVar2 + fVar3;
    pfVar11 = pfVar11 + 4;
    piVar16 = piVar16 + 4;
    pfVar18[-7] = fVar3 - fVar2;
    pfVar7[1] = fVar1 + fVar4;
    pfVar18[-6] = fVar1 - fVar4;
    if (pfVar18 + -7 <= pfVar7 + 2) break;
    pfVar18 = pfVar18 + -4;
    pfVar7 = pfVar7 + 4;
  }
  pfVar11 = param_3 + iVar15;
  if (0 < iVar12) {
    pfVar18 = (float *)(iVar15 * 4 + param_1[2]);
    pfVar7 = afStack_44 + (5 - iVar5);
    do {
      pfVar11 = pfVar11 + -1;
      iVar12 = iVar12 + -1;
      *param_3 = (pfVar18[1] * pfVar7[1] + *pfVar18 * *pfVar7) * (float)param_1[4];
      *pfVar11 = (pfVar18[1] * *pfVar7 - *pfVar18 * pfVar7[1]) * (float)param_1[4];
      pfVar18 = pfVar18 + 2;
      pfVar7 = pfVar7 + 2;
      param_3 = param_3 + 1;
    } while (iVar12 != 0);
  }
  return;
}

