
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_007a6090(int param_1,float *param_2,float *param_3,int param_4,uint param_5,float *param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  int iVar11;
  float *pfVar12;
  float *pfVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  float afStack_4c [4];
  int local_3c;
  float *local_38;
  float *local_34;
  float *local_30;
  float *local_2c;
  float *local_28;
  int local_24;
  int local_20;
  float *local_1c;
  float *local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  pfVar9 = afStack_4c + (-3 - param_5);
  iVar7 = param_4 + param_5;
  local_34 = afStack_4c + (-3 - param_5);
  afStack_4c[-4 - param_5] = 1.1238646e-38;
  pfVar10 = afStack_4c + ((-3 - iVar7) - param_5);
  if (0 < (int)param_5) {
    pfVar8 = param_2 + (param_5 - 1);
    uVar17 = param_5;
    do {
      fVar1 = *pfVar8;
      pfVar8 = pfVar8 + -1;
      *pfVar9 = fVar1;
      pfVar9 = pfVar9 + 1;
      uVar17 = uVar17 - 1;
    } while (uVar17 != 0);
  }
  uVar17 = 0;
  if (0 < (int)param_5) {
    pfVar9 = param_6 + (param_5 - 1);
    uVar15 = param_5;
    do {
      *pfVar10 = -*pfVar9;
      pfVar9 = pfVar9 + -1;
      pfVar10 = pfVar10 + 1;
      uVar15 = uVar15 - 1;
      uVar17 = param_5;
    } while (uVar15 != 0);
  }
  if ((int)uVar17 < (int)(param_4 + param_5)) {
    pfVar9 = afStack_4c + (((uVar17 - 3) - iVar7) - param_5);
    for (iVar11 = (param_4 + param_5) - uVar17; iVar11 != 0; iVar11 = iVar11 + -1) {
      *pfVar9 = 0.0;
      pfVar9 = pfVar9 + 1;
    }
  }
  iVar11 = 0;
  local_28 = (float *)0x0;
  if (0 < param_4 + -3) {
    local_1c = param_3;
    local_18 = afStack_4c + (-3 - iVar7);
    local_20 = param_1 - (int)(afStack_4c + ((-3 - iVar7) - param_5));
    local_30 = (float *)(param_1 + 0xc);
    local_24 = (int)param_3 - (int)(afStack_4c + ((-3 - iVar7) - param_5));
    pfVar9 = afStack_4c + ((-1 - iVar7) - param_5);
    local_2c = pfVar9;
    local_3c = (int)param_3 - param_1;
    do {
      pfVar8 = local_18;
      pfVar10 = local_1c;
      pfVar13 = pfVar9 + 1;
      fVar1 = local_30[-3];
      afStack_4c[1] = local_30[-2];
      local_38 = (float *)0x0;
      local_8 = 0.0;
      local_c = pfVar9[-2];
      afStack_4c[2] = *(float *)(local_20 + -4 + (int)pfVar13);
      local_14 = pfVar9[-1];
      local_10 = *pfVar9;
      afStack_4c[3] = *local_30;
      pfVar9 = local_34;
      if (0 < (int)(param_5 - 3)) {
        uVar17 = param_5 >> 2;
        local_38 = (float *)(uVar17 * 4);
        do {
          fVar2 = *pfVar9;
          local_8 = *pfVar13;
          fVar6 = fVar2 * local_c;
          fVar3 = pfVar9[1];
          afStack_4c[1] = fVar2 * local_14 + afStack_4c[1];
          pfVar12 = pfVar13 + 3;
          afStack_4c[2] = fVar2 * local_10 + afStack_4c[2];
          local_c = pfVar13[1];
          fVar4 = pfVar9[2];
          afStack_4c[3] = fVar2 * local_8 + afStack_4c[3];
          fVar5 = fVar3 * local_14;
          afStack_4c[1] = fVar3 * local_10 + afStack_4c[1];
          afStack_4c[2] = fVar3 * local_8 + afStack_4c[2];
          local_14 = pfVar13[2];
          afStack_4c[3] = fVar3 * local_c + afStack_4c[3];
          fVar3 = fVar4 * local_10;
          afStack_4c[1] = fVar4 * local_8 + afStack_4c[1];
          afStack_4c[2] = fVar4 * local_c + afStack_4c[2];
          fVar2 = pfVar9[3];
          pfVar9 = pfVar9 + 4;
          local_10 = *pfVar12;
          pfVar13 = pfVar13 + 4;
          uVar17 = uVar17 - 1;
          fVar1 = fVar2 * local_8 + fVar3 + fVar5 + fVar6 + fVar1;
          afStack_4c[1] = fVar2 * local_c + afStack_4c[1];
          afStack_4c[2] = fVar2 * local_14 + afStack_4c[2];
          afStack_4c[3] = fVar2 * *pfVar12 + fVar4 * local_14 + afStack_4c[3];
        } while (uVar17 != 0);
      }
      if ((int)local_38 < (int)param_5) {
        fVar2 = *pfVar9;
        local_8 = *pfVar13;
        pfVar9 = pfVar9 + 1;
        pfVar13 = pfVar13 + 1;
        fVar1 = fVar2 * local_c + fVar1;
        afStack_4c[1] = fVar2 * local_14 + afStack_4c[1];
        afStack_4c[2] = fVar2 * local_10 + afStack_4c[2];
        afStack_4c[3] = fVar2 * local_8 + afStack_4c[3];
      }
      if ((int)local_38 + 1 < (int)param_5) {
        fVar2 = *pfVar9;
        local_c = *pfVar13;
        pfVar9 = pfVar9 + 1;
        pfVar13 = pfVar13 + 1;
        fVar1 = fVar2 * local_14 + fVar1;
        afStack_4c[1] = fVar2 * local_10 + afStack_4c[1];
        afStack_4c[2] = fVar2 * local_8 + afStack_4c[2];
        afStack_4c[3] = fVar2 * local_c + afStack_4c[3];
      }
      if ((int)local_38 + 2 < (int)param_5) {
        fVar2 = *pfVar9;
        fVar1 = fVar2 * local_10 + fVar1;
        afStack_4c[1] = fVar2 * local_8 + afStack_4c[1];
        afStack_4c[2] = fVar2 * local_c + afStack_4c[2];
        afStack_4c[3] = *pfVar13 * fVar2 + afStack_4c[3];
      }
      *local_18 = -fVar1;
      pfVar13 = local_28;
      *pfVar10 = fVar1;
      fVar1 = *pfVar8 * *param_2 + afStack_4c[1];
      pfVar9 = afStack_4c + (((int)local_28 + -2) - iVar7);
      *pfVar9 = -fVar1;
      iVar11 = local_24;
      local_28 = pfVar9;
      pfVar10[1] = fVar1;
      fVar1 = *local_18 * param_2[1] + *pfVar9 * *param_2 + afStack_4c[2];
      pfVar10 = afStack_4c + (((int)pfVar13 + -1) - iVar7);
      *pfVar10 = -fVar1;
      iVar14 = local_3c;
      local_38 = pfVar10;
      *(float *)(iVar11 + (int)local_2c) = fVar1;
      pfVar9 = local_2c + 4;
      local_2c = pfVar9;
      iVar11 = (int)pfVar13 + 4;
      fVar1 = param_2[2] * *local_18 + *local_28 * param_2[1] + *pfVar10 * *param_2 + afStack_4c[3];
      afStack_4c[(int)pfVar13 - iVar7] = -fVar1;
      local_28 = (float *)iVar11;
      *(float *)(iVar14 + (int)local_30) = fVar1;
      local_1c = local_1c + 4;
      local_18 = local_18 + 4;
      local_30 = local_30 + 4;
    } while (iVar11 < param_4 + -3);
  }
  if (iVar11 < param_4) {
    local_20 = param_1 - (int)(afStack_4c + ((-3 - iVar7) - param_5));
    param_2 = afStack_4c + ((iVar11 + -3) - iVar7);
    iVar14 = (int)param_3 - (int)(afStack_4c + ((-3 - iVar7) - param_5));
    iVar16 = param_4 - iVar11;
    local_24 = iVar14;
    pfVar9 = afStack_4c + (((iVar11 + -3) - iVar7) - param_5);
    do {
      fVar1 = *(float *)((int)pfVar9 + local_20);
      if (0 < (int)param_5) {
        pfVar10 = pfVar9;
        pfVar8 = local_34;
        uVar17 = param_5;
        do {
          fVar2 = *pfVar10;
          fVar3 = *pfVar8;
          pfVar10 = pfVar10 + 1;
          pfVar8 = pfVar8 + 1;
          uVar17 = uVar17 - 1;
          fVar1 = fVar1 - fVar2 * fVar3;
        } while (uVar17 != 0);
        iVar14 = local_24;
      }
      *param_2 = fVar1;
      param_2 = param_2 + 1;
      iVar16 = iVar16 + -1;
      *(float *)((int)pfVar9 + iVar14) = fVar1;
      pfVar9 = pfVar9 + 1;
    } while (iVar16 != 0);
  }
  if (0 < (int)param_5) {
    param_3 = param_3 + param_4 + -1;
    do {
      fVar1 = *param_3;
      param_3 = param_3 + -1;
      *param_6 = fVar1;
      param_6 = param_6 + 1;
      param_5 = param_5 - 1;
    } while (param_5 != 0);
  }
  return;
}

