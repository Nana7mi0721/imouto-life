
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007981c0(float *param_1,int param_2,int param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  int iVar10;
  float *pfVar11;
  float *pfVar12;
  int iVar13;
  int iVar14;
  int local_10;
  
  if ((((0 < param_3) && (0 < param_2)) && (param_1 != (float *)0x0)) && (param_4 != (float *)0x0))
  {
    iVar7 = param_2 * param_3;
    if (0 < iVar7) {
      pfVar8 = param_1;
      do {
        if ((_DAT_007d103c < *pfVar8) || (_DAT_00837684 <= *pfVar8)) {
          if (*pfVar8 <= _DAT_007d103c) {
            fVar1 = *pfVar8;
          }
          else {
            fVar1 = _DAT_007d103c;
          }
        }
        else {
          fVar1 = _DAT_00837684;
        }
        *pfVar8 = fVar1;
        pfVar8 = pfVar8 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    if (0 < param_3) {
      iVar7 = (int)param_1 - (int)param_4;
      local_10 = param_3;
      pfVar8 = param_4;
      do {
        pfVar12 = (float *)(iVar7 + (int)pfVar8);
        fVar1 = *pfVar8;
        iVar10 = 0;
        if (0 < param_2) {
          pfVar9 = pfVar12;
          do {
            if (_DAT_007d5344 <= fVar1 * *pfVar9) break;
            iVar10 = iVar10 + 1;
            *pfVar9 = (fVar1 * *pfVar9 + _DAT_00804108) * *pfVar9;
            pfVar9 = pfVar9 + param_3;
          } while (iVar10 < param_2);
        }
        fVar1 = *pfVar12;
        param_4 = (float *)0x0;
        do {
          iVar10 = (int)param_4;
          if ((int)param_4 < param_2) {
            pfVar9 = pfVar12 + (int)param_4 * param_3;
            do {
              if ((_DAT_00804108 < *pfVar9) || (*pfVar9 < _DAT_007d5340)) break;
              iVar10 = iVar10 + 1;
              pfVar9 = pfVar9 + param_3;
            } while (iVar10 < param_2);
          }
          if (iVar10 == param_2) {
            fVar5 = _DAT_007d5344;
            goto LAB_007984dd;
          }
          fVar5 = ABS(pfVar12[iVar10 * param_3]);
          pfVar9 = pfVar12 + iVar10 * param_3;
          iVar14 = iVar10;
          if (0 < iVar10) {
            pfVar11 = (float *)((iVar10 * 4 + -4) * param_3 + (int)pfVar12);
            do {
              if (*pfVar11 * *pfVar9 < _DAT_007d5344) break;
              iVar14 = iVar14 + -1;
              pfVar11 = pfVar11 + -param_3;
            } while (0 < iVar14);
          }
          iVar13 = iVar10;
          param_1 = (float *)iVar10;
          if (iVar10 < param_2) {
            pfVar11 = pfVar9;
            do {
              if (*pfVar11 * *pfVar9 < _DAT_007d5344) break;
              if (fVar5 < ABS(*pfVar11)) {
                iVar13 = iVar10;
                param_1 = (float *)iVar10;
                fVar5 = ABS(*pfVar11);
              }
              iVar10 = iVar10 + 1;
              pfVar11 = pfVar11 + param_3;
            } while (iVar10 < param_2);
          }
          if ((iVar14 != 0) || (bVar6 = true, *pfVar12 * *pfVar9 < _DAT_007d5344)) {
            bVar6 = false;
          }
          fVar5 = (fVar5 - _DAT_00804108) / (fVar5 * fVar5);
          if (_DAT_007d5344 < *pfVar9) {
            fVar5 = -fVar5;
          }
          if (iVar14 < iVar10) {
            pfVar9 = pfVar12 + iVar14 * param_3;
            iVar14 = iVar10 - iVar14;
            do {
              *pfVar9 = (fVar5 * *pfVar9 + _DAT_00804108) * *pfVar9;
              pfVar9 = pfVar9 + param_3;
              iVar14 = iVar14 + -1;
            } while (iVar14 != 0);
          }
          if ((bVar6) && (1 < iVar13)) {
            fVar2 = fVar1 - *pfVar12;
            fVar3 = fVar2 / (float)(int)param_1;
            if ((int)param_4 < iVar13) {
              iVar13 = iVar13 - (int)param_4;
              pfVar9 = pfVar12 + (int)param_4 * param_3;
              do {
                fVar2 = fVar2 - fVar3;
                fVar4 = fVar2 + *pfVar9;
                *pfVar9 = fVar4;
                if ((_DAT_00804108 < fVar4) || (_DAT_007d5340 <= fVar4)) {
                  if (_DAT_00804108 < fVar4) {
                    fVar4 = _DAT_00804108;
                  }
                }
                else {
                  fVar4 = _DAT_007d5340;
                }
                *pfVar9 = fVar4;
                pfVar9 = pfVar9 + param_3;
                iVar13 = iVar13 + -1;
              } while (iVar13 != 0);
            }
          }
          param_4 = (float *)iVar10;
        } while (iVar10 != param_2);
LAB_007984dd:
        *pfVar8 = fVar5;
        pfVar8 = pfVar8 + 1;
        local_10 = local_10 + -1;
        if (local_10 == 0) {
          return;
        }
      } while( true );
    }
  }
  return;
}

