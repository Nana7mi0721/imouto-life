
void FUN_006b3ce0(undefined4 *param_1,int param_2,int param_3,uint param_4,int param_5,uint param_6)

{
  float fVar1;
  undefined *puVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  
  param_4 = -(uint)(param_5 != 0) & param_4;
  param_6 = -(uint)(param_5 != 0) & param_6;
  pfVar4 = (float *)(&PTR_DAT_0083186c)[*(int *)(param_2 + param_4 * 4)];
  puVar2 = (&PTR_DAT_0083186c)[*(int *)(param_2 + param_6 * 4)];
  iVar8 = *(int *)(param_3 + param_5 * 4);
  iVar7 = *(int *)(param_3 + param_4 * 4);
  iVar3 = *(int *)(param_3 + param_6 * 4);
  iVar5 = (int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2;
  iVar10 = iVar5 - ((int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2);
  iVar5 = (iVar8 / 2 - ((int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2)) + iVar5;
  iVar11 = iVar7 / 2 + iVar10;
  iVar7 = iVar3 / 2 + iVar5;
  iVar6 = 0;
  if (0 < iVar10) {
    puVar12 = param_1;
    for (iVar6 = iVar10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    iVar6 = iVar10;
  }
  if (iVar6 < iVar11) {
    iVar11 = iVar11 - iVar6;
    pfVar9 = (float *)(param_1 + iVar6);
    do {
      fVar1 = *pfVar4;
      pfVar4 = pfVar4 + 1;
      iVar11 = iVar11 + -1;
      *pfVar9 = *pfVar9 * fVar1;
      pfVar9 = pfVar9 + 1;
    } while (iVar11 != 0);
  }
  if (iVar5 < iVar7) {
    iVar7 = iVar7 - iVar5;
    pfVar4 = (float *)(param_1 + iVar5);
    pfVar9 = (float *)(puVar2 + (iVar3 / 2) * 4 + -4);
    iVar5 = iVar5 + iVar7;
    do {
      fVar1 = *pfVar9;
      pfVar9 = pfVar9 + -1;
      iVar7 = iVar7 + -1;
      *pfVar4 = fVar1 * *pfVar4;
      pfVar4 = pfVar4 + 1;
    } while (iVar7 != 0);
  }
  if (iVar5 < iVar8) {
    puVar12 = param_1 + iVar5;
    for (iVar8 = iVar8 - iVar5; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
  }
  return;
}

