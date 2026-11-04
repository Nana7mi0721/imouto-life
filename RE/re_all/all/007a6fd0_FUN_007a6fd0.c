
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a6fd0(float *param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float *pfVar12;
  float *pfVar13;
  float *pfVar14;
  int iVar15;
  float *pfVar16;
  uint uVar17;
  int iVar18;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  uint local_1c;
  float local_c;
  float local_8;
  float local_4;
  
  iVar15 = 0;
  if (0 < (int)(param_5 - 3)) {
    local_1c = param_5 >> 2;
    pfVar16 = (float *)(param_3 + 0xc);
    pfVar13 = (float *)(param_2 + 8);
    iVar15 = local_1c << 2;
    do {
      local_28 = pfVar13[-2];
      local_20 = pfVar13[-1];
      local_24 = *pfVar13;
      iVar18 = 0;
      local_c = 0.0;
      local_8 = 0.0;
      local_4 = 0.0;
      local_2c = 0.0;
      pfVar14 = pfVar13 + 1;
      pfVar12 = param_1;
      fVar8 = _DAT_007d5344;
      if (0 < (int)(param_4 - 3)) {
        uVar17 = param_4 >> 2;
        iVar18 = uVar17 * 4;
        do {
          fVar1 = *pfVar12;
          local_2c = *pfVar14;
          fVar11 = fVar1 * local_28;
          fVar2 = pfVar12[1];
          fVar5 = fVar1 * local_20;
          fVar6 = fVar1 * local_24;
          local_28 = pfVar14[1];
          fVar3 = pfVar12[2];
          fVar10 = fVar2 * local_20;
          fVar7 = fVar2 * local_24;
          local_20 = pfVar14[2];
          fVar9 = fVar3 * local_24;
          fVar4 = pfVar12[3];
          pfVar12 = pfVar12 + 4;
          local_24 = pfVar14[3];
          pfVar14 = pfVar14 + 4;
          uVar17 = uVar17 - 1;
          fVar8 = fVar4 * local_2c + fVar9 + fVar10 + fVar11 + fVar8;
          local_c = fVar4 * local_28 + fVar3 * local_2c + fVar7 + fVar5 + local_c;
          local_8 = fVar4 * local_20 + fVar3 * local_28 + fVar2 * local_2c + fVar6 + local_8;
          local_4 = fVar4 * local_24 +
                    fVar3 * local_20 + fVar2 * local_28 + fVar1 * local_2c + local_4;
        } while (uVar17 != 0);
      }
      if (iVar18 < (int)param_4) {
        fVar1 = *pfVar12;
        local_2c = *pfVar14;
        pfVar12 = pfVar12 + 1;
        pfVar14 = pfVar14 + 1;
        fVar8 = fVar1 * local_28 + fVar8;
        local_c = fVar1 * local_20 + local_c;
        local_8 = fVar1 * local_24 + local_8;
        local_4 = fVar1 * local_2c + local_4;
      }
      if (iVar18 + 1 < (int)param_4) {
        fVar1 = *pfVar12;
        local_28 = *pfVar14;
        pfVar12 = pfVar12 + 1;
        pfVar14 = pfVar14 + 1;
        fVar8 = fVar1 * local_20 + fVar8;
        local_c = fVar1 * local_24 + local_c;
        local_8 = fVar1 * local_2c + local_8;
        local_4 = fVar1 * local_28 + local_4;
      }
      if (iVar18 + 2 < (int)param_4) {
        fVar1 = *pfVar12;
        fVar8 = fVar1 * local_24 + fVar8;
        local_c = fVar1 * local_2c + local_c;
        local_8 = fVar1 * local_28 + local_8;
        local_4 = *pfVar14 * fVar1 + local_4;
      }
      pfVar16[-3] = fVar8;
      pfVar16[-2] = local_c;
      *(float *)((param_3 - param_2) + (int)pfVar13) = local_8;
      *pfVar16 = local_4;
      pfVar13 = pfVar13 + 4;
      pfVar16 = pfVar16 + 4;
      local_1c = local_1c - 1;
    } while (local_1c != 0);
  }
  if (iVar15 < (int)param_5) {
    iVar18 = param_5 - iVar15;
    pfVar16 = (float *)(param_3 + iVar15 * 4);
    do {
      fVar8 = _DAT_007d5344;
      if (0 < (int)param_4) {
        pfVar13 = (float *)((int)pfVar16 + (param_2 - param_3));
        pfVar14 = param_1;
        uVar17 = param_4;
        do {
          fVar1 = *pfVar13;
          fVar2 = *pfVar14;
          pfVar13 = pfVar13 + 1;
          pfVar14 = pfVar14 + 1;
          uVar17 = uVar17 - 1;
          fVar8 = fVar1 * fVar2 + fVar8;
        } while (uVar17 != 0);
      }
      *pfVar16 = fVar8;
      pfVar16 = pfVar16 + 1;
      iVar18 = iVar18 + -1;
    } while (iVar18 != 0);
  }
  return;
}

