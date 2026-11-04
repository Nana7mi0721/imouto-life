
void FUN_007a7d30(float *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  float *pfVar1;
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
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  int iVar20;
  float *pfVar21;
  float *pfVar22;
  float *pfVar23;
  float *pfVar24;
  float *pfVar25;
  float *local_b0;
  float *local_ac;
  float *local_a8;
  float *local_a4;
  float *local_a0;
  float *local_9c;
  int local_98;
  int local_94;
  
  iVar20 = param_2 * param_4;
  pfVar1 = *(float **)(param_3 + 0x30);
  fVar2 = pfVar1[iVar20 * 2];
  fVar3 = pfVar1[iVar20 * 2 + 1];
  fVar4 = pfVar1[iVar20 * 4];
  fVar5 = pfVar1[iVar20 * 4 + 1];
  if (0 < param_5) {
    local_b0 = param_1;
    local_a0 = param_1 + param_4 * 4;
    local_94 = param_5;
    do {
      pfVar22 = local_a0 + param_4 * -2;
      pfVar25 = local_a0 + param_4 * 4;
      if (0 < param_4) {
        local_98 = param_4;
        pfVar21 = local_b0;
        pfVar23 = local_a0;
        pfVar24 = local_a0 + param_4 * 2;
        local_ac = pfVar1;
        local_a8 = pfVar1;
        local_a4 = pfVar1;
        local_9c = pfVar1;
        while( true ) {
          fVar6 = *pfVar21;
          fVar7 = pfVar21[1];
          fVar8 = *pfVar22 * *local_a4 - local_a4[1] * pfVar22[1];
          fVar11 = *pfVar22 * local_a4[1] + *local_a4 * pfVar22[1];
          fVar12 = *pfVar23 * *local_9c - local_9c[1] * pfVar23[1];
          fVar13 = local_9c[1] * *pfVar23 + pfVar23[1] * *local_9c;
          fVar14 = *pfVar24 * *local_a8 - local_a8[1] * pfVar24[1];
          fVar15 = *pfVar24 * local_a8[1] + *local_a8 * pfVar24[1];
          fVar10 = *local_ac * *pfVar25 - local_ac[1] * pfVar25[1];
          fVar16 = pfVar25[1] * *local_ac + local_ac[1] * *pfVar25;
          fVar9 = fVar10 + fVar8;
          fVar17 = fVar16 + fVar11;
          fVar8 = fVar8 - fVar10;
          fVar11 = fVar11 - fVar16;
          fVar16 = fVar14 + fVar12;
          fVar18 = fVar15 + fVar13;
          fVar12 = fVar12 - fVar14;
          fVar13 = fVar13 - fVar15;
          *pfVar21 = fVar16 + *pfVar21 + fVar9;
          pfVar21[1] = fVar18 + fVar17 + pfVar21[1];
          fVar15 = fVar2 * fVar9 + fVar4 * fVar16 + fVar6;
          fVar19 = fVar2 * fVar17 + fVar4 * fVar18 + fVar7;
          fVar14 = fVar3 * fVar11 + fVar5 * fVar13;
          fVar10 = -(fVar3 * fVar8) - fVar5 * fVar12;
          *pfVar22 = fVar15 - fVar14;
          pfVar22[1] = fVar19 - fVar10;
          *pfVar25 = fVar14 + fVar15;
          pfVar25[1] = fVar10 + fVar19;
          fVar6 = fVar4 * fVar9 + fVar2 * fVar16 + fVar6;
          fVar7 = fVar4 * fVar17 + fVar2 * fVar18 + fVar7;
          fVar9 = fVar3 * fVar13 - fVar5 * fVar11;
          fVar8 = fVar8 * fVar5 - fVar3 * fVar12;
          pfVar25 = pfVar25 + 2;
          *pfVar23 = fVar9 + fVar6;
          local_a4 = local_a4 + param_2 * 2;
          local_9c = local_9c + param_2 * 4;
          pfVar23[1] = fVar8 + fVar7;
          local_a8 = local_a8 + param_2 * 6;
          local_ac = local_ac + param_2 * 8;
          *pfVar24 = fVar6 - fVar9;
          pfVar21 = pfVar21 + 2;
          pfVar22 = pfVar22 + 2;
          pfVar23 = pfVar23 + 2;
          local_98 = local_98 + -1;
          pfVar24[1] = fVar7 - fVar8;
          if (local_98 == 0) break;
          pfVar24 = pfVar24 + 2;
        }
      }
      local_a0 = local_a0 + param_6 * 2;
      local_b0 = local_b0 + param_6 * 2;
      local_94 = local_94 + -1;
    } while (local_94 != 0);
  }
  return;
}

