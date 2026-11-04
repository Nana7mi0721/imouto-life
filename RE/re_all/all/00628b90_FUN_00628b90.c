
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00628b90(float param_1,float *param_2,int param_3,int param_4,int *param_5)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  int *piVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  float local_48;
  float local_44;
  int local_40 [8];
  float local_20 [8];
  
  iVar5 = (int)param_1;
  if (param_1 == 1.4013e-45) {
    fVar9 = (float10)*param_2;
    fVar10 = (float10)param_2[1];
  }
  else if (param_1 == 2.8026e-45) {
    fVar9 = ((float10)param_2[2] + (float10)*param_2) * (float10)_DAT_007d589c;
    fVar10 = ((float10)param_2[3] + (float10)param_2[1]) * (float10)_DAT_007d589c;
  }
  else {
    iVar7 = (int)param_1 + -1;
    local_48 = _DAT_007d5344;
    local_44 = _DAT_007d5344;
    fVar2 = _DAT_007d5344;
    if (0 < iVar7) {
      pfVar6 = param_2 + 3;
      do {
        iVar7 = iVar7 + -1;
        fVar3 = pfVar6[-3] * *pfVar6 - pfVar6[-1] * pfVar6[-2];
        fVar2 = fVar3 + fVar2;
        local_48 = (pfVar6[-1] + pfVar6[-3]) * fVar3 + local_48;
        local_44 = (pfVar6[-2] + *pfVar6) * fVar3 + local_44;
        pfVar6 = pfVar6 + 2;
      } while (iVar7 != 0);
    }
    fVar3 = param_2[(int)param_1 * 2 + -2] * param_2[1] - param_2[(int)param_1 * 2 + -1] * *param_2;
    if (ABS(fVar3 + fVar2) <= _DAT_00804520) {
      param_1 = 1e+18;
    }
    else {
      param_1 = _DAT_00804108 / ((fVar3 + fVar2) * _DAT_00802730);
    }
    fVar9 = (((float10)param_2[iVar5 * 2 + -2] + (float10)*param_2) * (float10)fVar3 +
            (float10)local_48) * (float10)param_1;
    fVar10 = (((float10)param_2[iVar5 * 2 + -1] + (float10)param_2[1]) * (float10)fVar3 +
             (float10)local_44) * (float10)param_1;
  }
  if (0 < iVar5) {
    iVar7 = iVar5;
    pfVar6 = local_20;
    do {
      pfVar1 = param_2 + 1;
      fVar2 = *param_2;
      param_2 = param_2 + 2;
      fVar11 = (float10)fpatan((float10)*pfVar1 - fVar10,(float10)fVar2 - fVar9);
      iVar7 = iVar7 + -1;
      *pfVar6 = (float)fVar11;
      pfVar6 = pfVar6 + 1;
    } while (iVar7 != 0);
  }
  if (0 < iVar5) {
    piVar8 = local_40;
    for (iVar7 = iVar5; iVar7 != 0; iVar7 = iVar7 + -1) {
      *piVar8 = 1;
      piVar8 = piVar8 + 1;
    }
  }
  *param_5 = param_4;
  local_40[param_4] = 0;
  param_1 = 1.4013e-45;
  if (1 < param_3) {
    fVar2 = _DAT_00802ec0 / (float)param_3;
    do {
      param_5 = param_5 + 1;
      fVar3 = (float)(int)param_1 * fVar2 + local_20[param_4];
      if (_DAT_00802ebc < fVar3) {
        fVar3 = fVar3 - _DAT_00802ec0;
      }
      iVar7 = 0;
      param_2 = (float *)0x4e6e6b28;
      *param_5 = param_4;
      if (0 < iVar5) {
        do {
          if (local_40[iVar7] != 0) {
            fVar4 = ABS(local_20[iVar7] - fVar3);
            if (_DAT_00802ebc < fVar4) {
              fVar4 = _DAT_00802ec0 - fVar4;
            }
            if (fVar4 < (float)param_2) {
              *param_5 = iVar7;
              param_2 = (float *)fVar4;
            }
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar5);
      }
      param_1 = (float)((int)param_1 + 1);
      local_40[*param_5] = 0;
    } while ((int)param_1 < param_3);
  }
  return;
}

