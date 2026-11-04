
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006b2c90(int *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  float *pfVar11;
  byte bVar12;
  float *pfVar13;
  float *pfVar14;
  float *pfVar15;
  int *piVar16;
  float *pfVar17;
  int iVar18;
  uint uVar19;
  int local_1c;
  
  iVar18 = *param_1 >> 1;
  iVar6 = *param_1 >> 2;
  iVar7 = iVar6 * 4;
  pfVar11 = (float *)(param_3 + (iVar6 + iVar18) * 4);
  pfVar15 = (float *)(iVar7 + param_1[2]);
  pfVar9 = param_2 + iVar18 + -7;
  pfVar8 = pfVar11;
  do {
    pfVar14 = pfVar9 + -8;
    pfVar8[-4] = -(pfVar9[2] * pfVar15[3]) - *pfVar9 * pfVar15[2];
    pfVar8[-3] = *pfVar9 * pfVar15[3] - pfVar9[2] * pfVar15[2];
    pfVar8[-2] = -(pfVar15[1] * pfVar9[6]) - pfVar9[4] * *pfVar15;
    pfVar8[-1] = pfVar15[1] * pfVar9[4] - *pfVar15 * pfVar9[6];
    pfVar15 = pfVar15 + 4;
    pfVar9 = pfVar14;
    pfVar8 = pfVar8 + -4;
  } while (param_2 <= pfVar14);
  pfVar15 = (float *)(iVar7 + param_1[2]);
  pfVar9 = param_2 + iVar18 + -8;
  pfVar8 = pfVar11;
  do {
    pfVar14 = pfVar15 + -4;
    pfVar17 = pfVar9 + -8;
    *pfVar8 = pfVar15[-2] * pfVar9[6] + pfVar9[4] * pfVar15[-1];
    pfVar8[1] = pfVar9[4] * pfVar15[-2] - pfVar15[-1] * pfVar9[6];
    pfVar8[2] = *pfVar9 * pfVar15[-3] + pfVar9[2] * *pfVar14;
    pfVar8[3] = *pfVar9 * *pfVar14 - pfVar15[-3] * pfVar9[2];
    pfVar15 = pfVar14;
    pfVar9 = pfVar17;
    pfVar8 = pfVar8 + 4;
  } while (param_2 <= pfVar17);
  iVar5 = param_1[2];
  pfVar15 = (float *)(iVar18 * 4 + param_3);
  local_1c = param_1[1];
  if (0 < local_1c + -6) {
    pfVar9 = pfVar15 + iVar6 + -8 + (iVar18 - iVar6) + 7;
    pfVar8 = pfVar15 + iVar6 + -8;
    pfVar14 = (float *)(iVar5 + 0x10);
    do {
      fVar1 = pfVar9[-1];
      fVar2 = pfVar8[6];
      fVar3 = *pfVar9;
      fVar4 = pfVar8[7];
      pfVar9[-1] = pfVar9[-1] + pfVar8[6];
      *pfVar9 = pfVar8[7] + *pfVar9;
      pfVar8[6] = (fVar1 - fVar2) * pfVar14[-4] + (fVar3 - fVar4) * pfVar14[-3];
      pfVar8[7] = (fVar3 - fVar4) * pfVar14[-4] - (fVar1 - fVar2) * pfVar14[-3];
      fVar1 = pfVar9[-3];
      fVar2 = pfVar8[4];
      fVar3 = pfVar9[-2];
      fVar4 = pfVar8[5];
      pfVar9[-3] = pfVar8[4] + pfVar9[-3];
      pfVar9[-2] = pfVar9[-2] + pfVar8[5];
      pfVar8[4] = (fVar1 - fVar2) * *pfVar14 + (fVar3 - fVar4) * pfVar14[1];
      pfVar8[5] = (fVar3 - fVar4) * *pfVar14 - (fVar1 - fVar2) * pfVar14[1];
      fVar1 = pfVar9[-5];
      fVar2 = pfVar8[2];
      fVar3 = pfVar9[-4];
      fVar4 = pfVar8[3];
      pfVar9[-5] = pfVar8[2] + pfVar9[-5];
      pfVar9[-4] = pfVar9[-4] + pfVar8[3];
      pfVar8[2] = (fVar1 - fVar2) * pfVar14[4] + (fVar3 - fVar4) * pfVar14[5];
      pfVar8[3] = (fVar3 - fVar4) * pfVar14[4] - (fVar1 - fVar2) * pfVar14[5];
      fVar1 = pfVar9[-7];
      fVar2 = *pfVar8;
      fVar3 = pfVar9[-6];
      fVar4 = pfVar8[1];
      pfVar9[-7] = pfVar9[-7] + *pfVar8;
      pfVar9[-6] = pfVar8[1] + pfVar9[-6];
      pfVar17 = pfVar8 + -8;
      pfVar9 = pfVar9 + -8;
      *pfVar8 = (fVar1 - fVar2) * pfVar14[8] + (fVar3 - fVar4) * pfVar14[9];
      pfVar8[1] = (fVar3 - fVar4) * pfVar14[8] - (fVar1 - fVar2) * pfVar14[9];
      pfVar8 = pfVar17;
      pfVar14 = pfVar14 + 0x10;
    } while (pfVar15 <= pfVar17);
  }
  local_1c = local_1c + -7;
  bVar12 = 1;
  if (0 < local_1c) {
    do {
      param_2 = (float *)(1 << (bVar12 & 0x1f));
      if (0 < (int)param_2) {
        iVar6 = iVar18 >> (bVar12 & 0x1f);
        pfVar9 = pfVar15;
        do {
          FUN_006b3730(iVar5,pfVar9,iVar6,4 << (bVar12 & 0x1f));
          pfVar9 = pfVar9 + iVar6;
          param_2 = (float *)((int)param_2 + -1);
        } while (param_2 != (float *)0x0);
      }
      bVar12 = bVar12 + 1;
      local_1c = local_1c + -1;
    } while (local_1c != 0);
  }
  if (0 < iVar18) {
    uVar19 = iVar18 + 0x1fU >> 5;
    pfVar9 = pfVar15;
    do {
      FUN_006b31a0(pfVar9);
      pfVar9 = pfVar9 + 0x20;
      uVar19 = uVar19 - 1;
    } while (uVar19 != 0);
  }
  piVar16 = (int *)param_1[3];
  iVar6 = param_3 + (*param_1 >> 1) * 4;
  pfVar9 = (float *)(param_1[2] + *param_1 * 4);
  pfVar8 = (float *)(iVar6 + 0xc);
  pfVar14 = (float *)(param_3 + 8);
  do {
    iVar5 = piVar16[1];
    fVar1 = *(float *)(iVar6 + 4 + *piVar16 * 4) - *(float *)(iVar6 + 4 + iVar5 * 4);
    pfVar17 = (float *)(iVar6 + *piVar16 * 4);
    pfVar10 = (float *)(iVar6 + iVar5 * 4);
    fVar2 = *(float *)(iVar6 + iVar5 * 4) + *pfVar17;
    fVar3 = fVar1 * pfVar9[1] + fVar2 * *pfVar9;
    fVar1 = fVar2 * pfVar9[1] - fVar1 * *pfVar9;
    fVar2 = (pfVar10[1] + pfVar17[1]) * _DAT_007d589c;
    fVar4 = (*pfVar17 - *pfVar10) * _DAT_007d589c;
    pfVar14[-2] = fVar3 + fVar2;
    pfVar8[-5] = fVar2 - fVar3;
    pfVar14[-1] = fVar1 + fVar4;
    pfVar8[-4] = fVar1 - fVar4;
    iVar5 = piVar16[3];
    fVar1 = *(float *)(iVar6 + 4 + piVar16[2] * 4) - *(float *)(iVar6 + 4 + iVar5 * 4);
    pfVar17 = (float *)(iVar6 + piVar16[2] * 4);
    pfVar10 = (float *)(iVar6 + iVar5 * 4);
    fVar2 = *(float *)(iVar6 + iVar5 * 4) + *pfVar17;
    fVar3 = fVar1 * pfVar9[3] + fVar2 * pfVar9[2];
    fVar1 = fVar2 * pfVar9[3] - fVar1 * pfVar9[2];
    fVar2 = (pfVar10[1] + pfVar17[1]) * _DAT_007d589c;
    fVar4 = (*pfVar17 - *pfVar10) * _DAT_007d589c;
    *pfVar14 = fVar3 + fVar2;
    pfVar8[-7] = fVar2 - fVar3;
    pfVar14[1] = fVar1 + fVar4;
    pfVar17 = pfVar8 + -7;
    pfVar9 = pfVar9 + 4;
    piVar16 = piVar16 + 4;
    pfVar10 = pfVar14 + 2;
    pfVar8[-6] = fVar1 - fVar4;
    pfVar8 = pfVar8 + -4;
    pfVar14 = pfVar14 + 4;
  } while (pfVar10 < pfVar17);
  pfVar9 = (float *)(param_3 + 0xc);
  pfVar8 = (float *)(iVar18 * 4 + param_1[2]);
  pfVar14 = pfVar11;
  pfVar17 = pfVar11;
  do {
    pfVar13 = pfVar14 + -4;
    pfVar10 = pfVar9 + 5;
    pfVar14[-1] = pfVar8[1] * pfVar9[-3] - pfVar9[-2] * *pfVar8;
    *pfVar17 = -(pfVar9[-3] * *pfVar8 + pfVar8[1] * pfVar9[-2]);
    pfVar14[-2] = pfVar9[-1] * pfVar8[3] - *pfVar9 * pfVar8[2];
    pfVar17[1] = -(pfVar9[-1] * pfVar8[2] + *pfVar9 * pfVar8[3]);
    pfVar14[-3] = pfVar9[1] * pfVar8[5] - pfVar9[2] * pfVar8[4];
    pfVar17[2] = -(pfVar9[1] * pfVar8[4] + pfVar9[2] * pfVar8[5]);
    *pfVar13 = pfVar9[3] * pfVar8[7] - pfVar9[4] * pfVar8[6];
    pfVar17[3] = -(pfVar9[3] * pfVar8[6] + pfVar9[4] * pfVar8[7]);
    pfVar9 = pfVar9 + 8;
    pfVar8 = pfVar8 + 8;
    pfVar14 = pfVar13;
    pfVar17 = pfVar17 + 4;
  } while (pfVar10 < pfVar13);
  pfVar9 = pfVar11;
  pfVar8 = (float *)(iVar7 + 8 + param_3);
  pfVar14 = pfVar11 + (2 - iVar18);
  do {
    fVar1 = pfVar9[-1];
    pfVar10 = pfVar9 + -4;
    pfVar14[-3] = fVar1;
    pfVar8[-2] = -fVar1;
    fVar1 = pfVar9[-2];
    pfVar17 = pfVar8 + 2;
    pfVar14[-4] = fVar1;
    pfVar8[-1] = -fVar1;
    fVar1 = pfVar9[-3];
    pfVar14[-5] = fVar1;
    *pfVar8 = -fVar1;
    fVar1 = *pfVar10;
    pfVar14[-6] = fVar1;
    pfVar8[1] = -fVar1;
    pfVar9 = pfVar10;
    pfVar8 = pfVar8 + 4;
    pfVar14 = pfVar14 + -4;
  } while (pfVar17 < pfVar10);
  pfVar9 = pfVar11;
  do {
    pfVar8 = pfVar11 + -4;
    *pfVar8 = pfVar9[3];
    pfVar11[-3] = pfVar9[2];
    pfVar11[-2] = pfVar9[1];
    pfVar11[-1] = *pfVar9;
    pfVar11 = pfVar8;
    pfVar9 = pfVar9 + 4;
  } while (pfVar15 < pfVar8);
  return;
}

