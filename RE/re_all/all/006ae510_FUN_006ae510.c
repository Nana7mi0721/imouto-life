
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ae510(int param_1,float *param_2,float *param_3,float *param_4,float param_5,
                 float *param_6)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float *pfVar12;
  int iVar13;
  int iVar14;
  float *pfVar15;
  float *pfVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  undefined4 uStack_48;
  int local_28;
  uint *local_24;
  int local_20;
  float local_10;
  float local_c;
  float local_8;
  
  iVar13 = (int)param_6;
  pfVar12 = param_3;
  iVar1 = (int)register0x00000010 + -0x44;
  iVar3 = param_1 * -4;
  (&uStack_48)[-param_1] = 0x6ae53d;
  pfVar2 = (float *)((int)register0x00000010 + param_1 * -8 + -0x44);
  (&uStack_48)[param_1 * -2] = 0x6ae553;
  iVar4 = param_1 * -4;
  pfVar2[-1 - param_1] = 9.816857e-39;
  pfVar2[param_1 * -2 + -1] = 9.816885e-39;
  param_3 = (float *)(param_5 + *param_3);
  local_c = 0.0;
  local_8 = 0.0;
  local_10 = 1.0;
  if ((float)param_3 < _DAT_00804108) {
    param_3 = (float *)0x3f800000;
  }
  fVar5 = (float)param_3 * (float)param_3 * (float)_DAT_00804a60;
  fVar11 = fVar5 * (float)param_3;
  param_3 = (float *)0x3f800000;
  *(float *)(iVar1 + iVar3) = fVar5;
  *pfVar2 = fVar5;
  pfVar2[-param_1] = 0.0;
  (pfVar2 + -param_1)[-param_1] = fVar11;
  (pfVar2 + -param_1)[param_1 * -2] = 0.0;
  if (1 < param_1) {
    local_24 = (uint *)(param_1 + -1);
    pfVar15 = (float *)((int)register0x00000010 + iVar3 + -0x40);
    fVar6 = _DAT_007d5344;
    fVar8 = _DAT_007d5344;
    fVar7 = fVar5;
    do {
      fVar9 = param_5 + *(float *)(((int)pfVar12 - (iVar1 + iVar3)) + (int)pfVar15);
      if (fVar9 < _DAT_00804108) {
        fVar9 = _DAT_00804108;
      }
      fVar10 = fVar9 * fVar9;
      pfVar16 = pfVar15 + 1;
      fVar7 = fVar10 + fVar7;
      fVar5 = (float)param_3 * fVar10 + fVar5;
      fVar8 = (float)param_3 * (float)param_3 * fVar10 + fVar8;
      fVar11 = fVar10 * fVar9 + fVar11;
      fVar6 = (float)param_3 * fVar10 * fVar9 + fVar6;
      *pfVar15 = fVar7;
      *(float *)((int)pfVar2 + (-4 - (iVar1 + iVar3)) + (int)pfVar16) = fVar5;
      *(float *)((int)pfVar2 + (-4 - iVar1) + (int)pfVar16) = fVar8;
      *(float *)((int)pfVar2 + (-4 - iVar1) + iVar4 + (int)pfVar16) = fVar11;
      *(float *)((int)pfVar2 + (-4 - iVar1) + param_1 * -8 + (int)pfVar16) = fVar6;
      param_3 = (float *)((float)param_3 + _DAT_00804108);
      local_24 = (uint *)((int)local_24 + -1);
      pfVar15 = pfVar16;
    } while (local_24 != (uint *)0x0);
  }
  uVar17 = (uint)*param_2;
  param_3 = (float *)0x0;
  iVar14 = (int)uVar17 >> 0x10;
  fVar11 = _DAT_007d5344;
  if (iVar14 < 0) {
    local_24 = (uint *)param_2;
    param_3 = (float *)0x0;
    do {
      uVar17 = uVar17 & 0xffff;
      fVar5 = *(float *)(iVar14 * -4 + iVar1 + iVar3) + *(float *)(iVar1 + iVar3 + uVar17 * 4);
      fVar6 = pfVar2[uVar17] - pfVar2[-iVar14];
      local_c = ((pfVar2 + -param_1)[-param_1 - iVar14] + (pfVar2 + -param_1)[uVar17 - param_1]) *
                (pfVar2[-param_1 - iVar14] + pfVar2[uVar17 - param_1]) -
                ((pfVar2 + -param_1)[param_1 * -2 + uVar17] -
                (pfVar2 + -param_1)[param_1 * -2 - iVar14]) * fVar6;
      local_8 = ((pfVar2 + -param_1)[param_1 * -2 + uVar17] -
                (pfVar2 + -param_1)[param_1 * -2 - iVar14]) * fVar5 -
                ((pfVar2 + -param_1)[-param_1 - iVar14] + (pfVar2 + -param_1)[uVar17 - param_1]) *
                fVar6;
      local_10 = (pfVar2[-param_1 - iVar14] + pfVar2[uVar17 - param_1]) * fVar5 - fVar6 * fVar6;
      fVar5 = (fVar11 * local_8 + local_c) / local_10;
      if (fVar5 < _DAT_007d5344) {
        fVar5 = _DAT_007d5344;
      }
      local_24 = local_24 + 1;
      param_3 = (float *)((int)param_3 + 1);
      *(float *)((int)param_4 + (-4 - (int)param_2) + (int)local_24) = fVar5 - param_5;
      uVar17 = *local_24;
      fVar11 = fVar11 + _DAT_00804108;
      iVar14 = (int)uVar17 >> 0x10;
    } while (iVar14 < 0);
  }
  uVar17 = (uint)param_2[(int)param_3];
  uVar18 = uVar17 & 0xffff;
  if ((int)uVar18 < param_1) {
    local_24 = (uint *)(param_2 + (int)param_3);
    do {
      iVar14 = (int)uVar17 >> 0x10;
      fVar5 = *(float *)(iVar1 + iVar3 + uVar18 * 4) - *(float *)(iVar1 + iVar3 + iVar14 * 4);
      fVar6 = pfVar2[uVar18] - pfVar2[iVar14];
      local_c = ((pfVar2 + -param_1)[uVar18 - param_1] - (pfVar2 + -param_1)[iVar14 - param_1]) *
                (pfVar2[uVar18 - param_1] - pfVar2[iVar14 - param_1]) -
                ((pfVar2 + -param_1)[param_1 * -2 + uVar18] -
                (pfVar2 + -param_1)[param_1 * -2 + iVar14]) * fVar6;
      local_8 = ((pfVar2 + -param_1)[param_1 * -2 + uVar18] -
                (pfVar2 + -param_1)[param_1 * -2 + iVar14]) * fVar5 -
                ((pfVar2 + -param_1)[uVar18 - param_1] - (pfVar2 + -param_1)[iVar14 - param_1]) *
                fVar6;
      local_10 = (pfVar2[uVar18 - param_1] - pfVar2[iVar14 - param_1]) * fVar5 - fVar6 * fVar6;
      fVar5 = (fVar11 * local_8 + local_c) / local_10;
      if (fVar5 < _DAT_007d5344) {
        fVar5 = _DAT_007d5344;
      }
      param_3 = (float *)((int)param_3 + 1);
      *(float *)((int)local_24 + ((int)param_4 - (int)param_2)) = fVar5 - param_5;
      uVar17 = local_24[1];
      fVar11 = fVar11 + _DAT_00804108;
      uVar18 = uVar17 & 0xffff;
      local_24 = local_24 + 1;
    } while ((int)uVar18 < param_1);
  }
  if ((int)param_3 < param_1) {
    iVar14 = param_1 - (int)param_3;
    param_2 = param_4 + (int)param_3;
    do {
      fVar5 = (fVar11 * local_8 + local_c) / local_10;
      if (fVar5 < _DAT_007d5344) {
        fVar5 = _DAT_007d5344;
      }
      iVar14 = iVar14 + -1;
      *param_2 = fVar5 - param_5;
      fVar11 = fVar11 + _DAT_00804108;
      param_2 = param_2 + 1;
    } while (iVar14 != 0);
  }
  if (0 < (int)param_6) {
    local_28 = (int)param_6 / 2;
    param_3 = (float *)0x0;
    fVar11 = _DAT_007d5344;
    if (local_28 - (int)param_6 < 0) {
      iVar14 = local_28 * 4;
      param_2 = param_4;
      iVar19 = (local_28 - (int)param_6) * -4;
      iVar20 = ((int)param_6 / 2) * -4;
      local_24 = (uint *)(local_28 << 2);
      local_20 = local_28;
      while( true ) {
        fVar5 = *(float *)(iVar14 + iVar1 + iVar3) + *(float *)(iVar19 + iVar1 + iVar3);
        fVar6 = *(float *)(iVar14 + (int)pfVar2) - *(float *)(iVar19 + (int)pfVar2);
        fVar8 = *(float *)((int)pfVar2 + iVar14 + iVar4) + *(float *)((int)pfVar2 + iVar19 + iVar4);
        fVar9 = *(float *)((int)pfVar2 + iVar14 + param_1 * -8) +
                *(float *)((int)pfVar2 + iVar19 + param_1 * -8);
        fVar7 = *(float *)((int)pfVar2 + iVar14 + param_1 * -0xc) -
                *(float *)((int)pfVar2 + iVar19 + param_1 * -0xc);
        local_c = fVar9 * fVar8 - fVar7 * fVar6;
        local_8 = fVar7 * fVar5 - fVar9 * fVar6;
        local_10 = fVar8 * fVar5 - fVar6 * fVar6;
        fVar5 = (fVar11 * local_8 + local_c) / local_10 - param_5;
        if (fVar5 < *param_2) {
          *param_2 = fVar5;
        }
        param_3 = (float *)((int)param_3 + 1);
        param_2 = param_2 + 1;
        iVar20 = iVar20 + -4;
        iVar14 = (int)local_24 + 4;
        local_20 = local_20 + 1;
        fVar11 = fVar11 + _DAT_00804108;
        iVar19 = iVar20 + (int)param_6 * 4;
        if (-1 < local_20 - (int)param_6) break;
        local_24 = (uint *)iVar14;
      }
    }
    local_28 = local_28 + (int)param_3;
    if (local_28 < param_1) {
      iVar14 = (local_28 - (int)param_6) * 4;
      param_2 = (float *)(local_28 * 4);
      param_6 = param_4 + (int)param_3;
      do {
        fVar5 = *(float *)((int)param_2 + iVar1 + iVar3) - *(float *)(iVar14 + iVar1 + iVar3);
        fVar6 = *(float *)((int)param_2 + (int)pfVar2) - *(float *)(iVar14 + (int)pfVar2);
        fVar8 = *(float *)((int)pfVar2 + (int)param_2 + iVar4) -
                *(float *)((int)pfVar2 + iVar14 + iVar4);
        fVar9 = *(float *)((int)pfVar2 + (int)param_2 + param_1 * -8) -
                *(float *)((int)pfVar2 + iVar14 + param_1 * -8);
        fVar7 = *(float *)((int)pfVar2 + (int)param_2 + param_1 * -0xc) -
                *(float *)((int)pfVar2 + iVar14 + param_1 * -0xc);
        local_c = fVar9 * fVar8 - fVar7 * fVar6;
        local_8 = fVar7 * fVar5 - fVar9 * fVar6;
        local_10 = fVar8 * fVar5 - fVar6 * fVar6;
        fVar5 = (fVar11 * local_8 + local_c) / local_10 - param_5;
        if (fVar5 < *param_6) {
          *param_6 = fVar5;
        }
        param_3 = (float *)((int)param_3 + 1);
        param_6 = param_6 + 1;
        fVar11 = fVar11 + _DAT_00804108;
        param_2 = (float *)((int)param_2 + 4);
        local_28 = local_28 + 1;
        iVar14 = (int)param_2 + iVar13 * -4;
      } while (local_28 < param_1);
    }
    if ((int)param_3 < param_1) {
      param_1 = param_1 - (int)param_3;
      param_4 = param_4 + (int)param_3;
      do {
        fVar5 = (fVar11 * local_8 + local_c) / local_10 - param_5;
        if (fVar5 < *param_4) {
          *param_4 = fVar5;
        }
        fVar11 = fVar11 + _DAT_00804108;
        param_4 = param_4 + 1;
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
  }
  return;
}

