
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a5ca0(float *param_1,float *param_2,int param_3,uint param_4,uint param_5,float *param_6
                 )

{
  int iVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  undefined4 *puVar18;
  float *pfVar19;
  float *pfVar20;
  float *pfVar21;
  float *pfVar22;
  uint uVar23;
  float afStack_254 [128];
  float local_44 [8];
  uint local_24;
  float *local_20;
  uint local_18;
  int local_14;
  float local_10;
  float local_c;
  float local_8;
  
  uVar17 = param_5;
  iVar16 = (int)param_2;
  iVar8 = param_5 * -4;
  pfVar19 = local_44 + (-4 - param_5);
  iVar15 = -4 - param_5;
  iVar1 = param_4 + param_5;
  local_44[-5 - param_5] = 1.123723e-38;
  pfVar21 = local_44 + ((-4 - iVar1) - param_5);
  if (0 < (int)param_5) {
    param_2 = (float *)param_5;
    puVar18 = (undefined4 *)(iVar16 + -4 + param_5 * 4);
    do {
      uVar2 = *puVar18;
      puVar18 = puVar18 + -1;
      *pfVar19 = (float)uVar2;
      pfVar19 = pfVar19 + 1;
      param_2 = (float *)((int)param_2 - 1);
    } while (param_2 != (float *)0x0);
    if (0 < (int)param_5) {
      param_2 = (float *)param_5;
      pfVar19 = param_6 + (param_5 - 1);
      do {
        fVar3 = *pfVar19;
        pfVar19 = pfVar19 + -1;
        *pfVar21 = fVar3;
        pfVar21 = pfVar21 + 1;
        param_2 = (float *)((int)param_2 - 1);
      } while (param_2 != (float *)0x0);
    }
  }
  if (0 < (int)param_4) {
    param_2 = param_1;
    local_18 = param_4;
    pfVar19 = local_44 + (-4 - iVar1);
    do {
      *pfVar19 = *param_2;
      param_2 = param_2 + 1;
      local_18 = local_18 - 1;
      pfVar19 = pfVar19 + 1;
    } while (local_18 != 0);
  }
  if (0 < (int)param_5) {
    param_2 = (float *)param_5;
    pfVar19 = param_6;
    param_6 = param_1 + (param_4 - 1);
    do {
      *pfVar19 = *param_6;
      param_6 = param_6 + -1;
      param_2 = (float *)((int)param_2 - 1);
      pfVar19 = pfVar19 + 1;
    } while (param_2 != (float *)0x0);
  }
  local_18 = 0;
  if (0 < (int)(param_4 - 3)) {
    local_20 = param_1;
    local_24 = param_4 >> 2;
    local_18 = local_24 * 4;
    pfVar19 = local_44 + ((-2 - iVar1) - param_5);
    pfVar21 = (float *)(param_3 + 4);
    do {
      local_8 = pfVar19[-2];
      local_10 = pfVar19[-1];
      local_c = *pfVar19;
      local_44[0] = 0.0;
      local_44[1] = 0.0;
      local_44[2] = 0.0;
      param_2 = (float *)0x0;
      pfVar22 = pfVar19 + 1;
      local_14 = 0;
      pfVar20 = local_44 + (-4 - param_5);
      fVar3 = _DAT_007d5344;
      if (0 < (int)(param_5 - 3)) {
        uVar23 = param_5 >> 2;
        local_14 = uVar23 * 4;
        pfVar20 = local_44 + (-4 - param_5);
        do {
          fVar4 = *pfVar20;
          param_2 = (float *)*pfVar22;
          fVar14 = fVar4 * local_8;
          fVar5 = pfVar20[1];
          fVar9 = fVar4 * local_10;
          fVar10 = fVar4 * local_c;
          local_8 = pfVar22[1];
          fVar6 = pfVar20[2];
          fVar13 = fVar5 * local_10;
          fVar11 = fVar5 * local_c;
          local_10 = pfVar22[2];
          fVar12 = fVar6 * local_c;
          fVar7 = pfVar20[3];
          pfVar20 = pfVar20 + 4;
          local_c = pfVar22[3];
          pfVar22 = pfVar22 + 4;
          uVar23 = uVar23 - 1;
          fVar3 = fVar7 * (float)param_2 + fVar12 + fVar13 + fVar14 + fVar3;
          local_44[0] = fVar7 * local_8 + fVar6 * (float)param_2 + fVar11 + fVar9 + local_44[0];
          local_44[1] = fVar7 * local_10 +
                        fVar6 * local_8 + fVar5 * (float)param_2 + fVar10 + local_44[1];
          local_44[2] = fVar7 * local_c +
                        fVar6 * local_10 + fVar5 * local_8 + fVar4 * (float)param_2 + local_44[2];
        } while (uVar23 != 0);
      }
      if (local_14 < (int)param_5) {
        fVar4 = *pfVar20;
        param_2 = (float *)*pfVar22;
        pfVar20 = pfVar20 + 1;
        pfVar22 = pfVar22 + 1;
        fVar3 = fVar4 * local_8 + fVar3;
        local_44[0] = fVar4 * local_10 + local_44[0];
        local_44[1] = fVar4 * local_c + local_44[1];
        local_44[2] = fVar4 * (float)param_2 + local_44[2];
      }
      if (local_14 + 1 < (int)param_5) {
        fVar4 = *pfVar20;
        local_8 = *pfVar22;
        pfVar20 = pfVar20 + 1;
        pfVar22 = pfVar22 + 1;
        fVar3 = fVar4 * local_10 + fVar3;
        local_44[0] = fVar4 * local_c + local_44[0];
        local_44[1] = fVar4 * (float)param_2 + local_44[1];
        local_44[2] = fVar4 * local_8 + local_44[2];
      }
      if (local_14 + 2 < (int)param_5) {
        fVar4 = *pfVar20;
        fVar3 = fVar4 * local_c + fVar3;
        local_44[0] = fVar4 * (float)param_2 + local_44[0];
        local_44[1] = fVar4 * local_8 + local_44[1];
        local_44[2] = *pfVar22 * fVar4 + local_44[2];
      }
      pfVar19 = pfVar19 + 4;
      pfVar21[-1] = *local_20 + fVar3;
      *pfVar21 = *(float *)((int)param_1 + (-0x10 - param_3) + (int)(pfVar21 + 4)) + local_44[0];
      *(float *)((param_3 - (int)(local_44 + ((-4 - iVar1) - param_5))) + -0x10 + (int)pfVar19) =
           *(float *)((int)param_1 + (-0x10 - (int)(local_44 + ((-4 - iVar1) - param_5))) +
                     (int)pfVar19) + local_44[1];
      local_24 = local_24 - 1;
      pfVar21[2] = local_20[3] + local_44[2];
      pfVar21 = pfVar21 + 4;
      local_20 = local_20 + 4;
    } while (local_24 != 0);
  }
  if ((int)local_18 < (int)param_4) {
    pfVar19 = param_1 + local_18;
    param_5 = param_4 - local_18;
    do {
      fVar3 = _DAT_007d5344;
      if (0 < (int)uVar17) {
        pfVar21 = (float *)((int)local_44 + ((iVar1 * -4 + iVar8) - (int)param_1) + -0x10 +
                           (int)pfVar19);
        pfVar22 = local_44 + iVar15;
        uVar23 = uVar17;
        do {
          fVar4 = *pfVar21;
          fVar5 = *pfVar22;
          pfVar21 = pfVar21 + 1;
          pfVar22 = pfVar22 + 1;
          uVar23 = uVar23 - 1;
          fVar3 = fVar4 * fVar5 + fVar3;
        } while (uVar23 != 0);
      }
      fVar4 = *pfVar19;
      pfVar19 = pfVar19 + 1;
      param_5 = param_5 + -1;
      *(float *)((param_3 - (int)param_1) + -4 + (int)pfVar19) = fVar4 + fVar3;
    } while (param_5 != 0);
  }
  return;
}

