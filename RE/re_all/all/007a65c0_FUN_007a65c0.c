
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a65c0(float *param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  float fVar1;
  double *pdVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  int iVar12;
  int iVar13;
  float *pfVar14;
  double adStack_430 [127];
  undefined4 uStack_34;
  int local_18;
  float local_14;
  float local_c;
  
  iVar7 = param_2;
  pfVar6 = param_1;
  uStack_34 = 0x7a65df;
  iVar13 = param_2 * -4;
  *(undefined4 *)((int)adStack_430 + iVar13 + 0x3fc) = 0x7a65f0;
  pdVar2 = adStack_430 + (0x80 - param_2);
  *(undefined4 *)((int)adStack_430 + param_2 * -8 + 0x3fc) = 0x7a65ff;
  pfVar11 = (float *)((int)pdVar2 + param_2 * -4);
  iVar5 = param_2 * -4;
  *(int *)((int)pdVar2 + (-1 - param_2) * 4) = param_4;
  *(int *)((int)pdVar2 + (-2 - param_2) * 4) = param_3;
  *(undefined4 *)((int)pdVar2 + (-3 - param_2) * 4) = param_5;
  *(undefined4 *)((int)pdVar2 + (-4 - param_2) * 4) = 1;
  *(int *)((int)pdVar2 + (-5 - param_2) * 4) = param_2;
  *(float **)((int)pdVar2 + (-6 - param_2) * 4) = param_1;
  *(undefined4 *)((int)pdVar2 + (-7 - param_2) * 4) = 0x7a661a;
  FUN_007a68d0();
  fVar1 = _DAT_007d5344;
  iVar8 = (int)pdVar2 + (param_2 * -4 - (int)param_1);
  iVar12 = (int)pdVar2 - (int)param_1;
  iVar9 = iVar13 - (int)param_1;
  param_2 = 0;
  do {
    if (*param_1 <= _DAT_007d5344) {
      *(undefined4 *)(iVar8 + (int)param_1) = 0xbf800000;
      *param_1 = -*param_1;
    }
    else {
      *(undefined4 *)(iVar8 + (int)param_1) = 0x3f800000;
    }
    *(undefined4 *)(iVar12 + (int)param_1) = 0;
    *(undefined4 *)((int)adStack_430 + iVar9 + 0x400 + (int)param_1) = 0;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  } while (param_2 < iVar7);
  local_c = 0.0;
  param_1 = (float *)0x0;
  param_4 = param_3;
  if (iVar7 >> 1 < param_3) {
    iVar9 = 0;
    pfVar10 = pfVar6;
    do {
      fVar1 = fVar1 + *pfVar10;
      iVar9 = iVar9 + 1;
      pfVar10 = pfVar10 + 1;
    } while (iVar9 < iVar7);
    if ((fVar1 <= _DAT_0083c5b8) || (_DAT_0083c818 <= fVar1)) {
      *pfVar6 = 1.0;
      iVar9 = 1;
      pfVar10 = pfVar6;
      do {
        pfVar10 = pfVar10 + 1;
        *pfVar10 = 0.0;
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar7);
      fVar1 = _DAT_00804108;
    }
    fVar1 = _DAT_00804108 / fVar1;
    iVar9 = (int)pfVar6 - ((int)adStack_430 + iVar13 + 0x400);
    iVar8 = (int)pdVar2 - ((int)adStack_430 + iVar13 + 0x400);
    param_2 = 0;
    pfVar10 = (float *)((int)adStack_430 + iVar13 + 0x400);
    do {
      *(double *)((int)pdVar2 + (-2 - iVar7) * 4) =
           (double)(fVar1 * (float)(param_3 + -1) * *(float *)(iVar9 + (int)pfVar10));
      *(undefined4 *)((int)pdVar2 + (-3 - iVar7) * 4) = 0x7a6738;
      FUN_006c5af0();
      *(undefined4 *)((int)pdVar2 + (-1 - iVar7) * 4) = 0x7a6740;
      iVar12 = __ftol();
      fVar3 = (float)iVar12;
      *(int *)(iVar8 + (int)pfVar10) = iVar12;
      *pfVar10 = fVar3;
      pfVar14 = pfVar10 + 1;
      local_c = fVar3 * fVar3 + local_c;
      param_1 = (float *)(*(float *)(iVar9 + -4 + (int)pfVar14) * fVar3 + (float)param_1);
      *pfVar10 = fVar3 + fVar3;
      param_4 = param_4 - *(int *)(iVar8 + -4 + (int)pfVar14);
      param_2 = param_2 + 1;
      pfVar10 = pfVar14;
    } while (param_2 < iVar7);
  }
  pfVar10 = (float *)((int)adStack_430 + iVar13 + 0x400);
  if (iVar7 + 3 < param_4) {
    fVar3 = (float)param_4;
    iVar13 = *(int *)pdVar2 + param_4;
    param_4 = 0;
    fVar1 = *pfVar10;
    *(int *)pdVar2 = iVar13;
    local_c = fVar3 * fVar1 + fVar3 * fVar3 + local_c;
  }
  if (0 < param_4) {
    local_18 = param_4;
    do {
      fVar1 = local_c + _DAT_00804108;
      iVar13 = 0;
      local_c = -1e+15;
      local_14 = 0.0;
      param_2 = 0;
      pfVar14 = pfVar10;
      do {
        fVar3 = *(float *)((int)pfVar14 + ((int)pfVar6 - (int)pfVar10)) + (float)param_1;
        fVar4 = *pfVar14 + fVar1;
        fVar3 = fVar3 * fVar3;
        if (fVar4 * local_c < fVar3 * local_14) {
          iVar13 = param_2;
          local_14 = fVar4;
          local_c = fVar3;
        }
        pfVar14 = pfVar14 + 1;
        param_2 = param_2 + 1;
      } while (param_2 < iVar7);
      param_1 = (float *)(pfVar6[iVar13] + (float)param_1);
      local_c = fVar1 + pfVar10[iVar13];
      pfVar10[iVar13] = pfVar10[iVar13] + _DAT_007d103c;
      *(int *)((int)pdVar2 + iVar13 * 4) = *(int *)((int)pdVar2 + iVar13 * 4) + 1;
      local_18 = local_18 + -1;
    } while (local_18 != 0);
  }
  iVar13 = 0;
  iVar9 = (int)pfVar6 - (int)((int)pdVar2 + iVar5);
  do {
    *(float *)(iVar9 + (int)pfVar11) = *(float *)(iVar9 + (int)pfVar11) * *pfVar11;
    if (*pfVar11 < _DAT_007d5344) {
      pfVar11[iVar7] = (float)-(int)pfVar11[iVar7];
    }
    iVar13 = iVar13 + 1;
    pfVar11 = pfVar11 + 1;
  } while (iVar13 < iVar7);
  *(undefined4 *)((int)pdVar2 + (-1 - iVar7) * 4) = param_6;
  *(int *)((int)pdVar2 + (-2 - iVar7) * 4) = param_3;
  *(int *)((int)pdVar2 + (-3 - iVar7) * 4) = iVar7;
  *(double **)((int)pdVar2 + (-4 - iVar7) * 4) = pdVar2;
  *(undefined4 *)((int)pdVar2 + (-5 - iVar7) * 4) = 0x7a68ad;
  FUN_007a8110();
  *(undefined4 *)((int)pdVar2 + (-5 - iVar7) * 4) = param_5;
  *(int *)((int)pdVar2 + (-6 - iVar7) * 4) = iVar7;
  *(double **)((int)pdVar2 + (-7 - iVar7) * 4) = pdVar2;
  *(undefined4 *)((int)pdVar2 + (-8 - iVar7) * 4) = 0x7a68bb;
  FUN_007a6a90();
  return;
}

