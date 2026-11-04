
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006b28a0(int param_1,int param_2,int *param_3)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  float *pfVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  int *local_14;
  int local_10;
  int local_c;
  
  local_14 = param_3;
  iVar9 = 0;
  iVar10 = 0;
  piVar7 = (int *)0xa0f364;
  iVar2 = param_1;
  do {
    do {
      piVar7 = piVar7 + 1;
      if ((int)piVar7 < 0xa0f378) {
        iVar9 = *piVar7;
      }
      else {
        iVar9 = iVar9 + 2;
      }
    } while (iVar2 != (iVar2 / iVar9) * iVar9);
    iVar5 = iVar2 / iVar9;
    piVar8 = param_3 + iVar10;
    local_c = iVar10;
    do {
      iVar2 = iVar5;
      iVar10 = local_c + 1;
      piVar8[2] = iVar9;
      if ((iVar9 == 2) && (iVar10 != 1)) {
        if (1 < iVar10) {
          piVar3 = piVar8 + 1;
          iVar5 = local_c;
          do {
            piVar3[1] = *piVar3;
            piVar3 = piVar3 + -1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        param_3[2] = 2;
      }
      if (iVar2 == 1) {
        *param_3 = param_1;
        param_3[1] = iVar10;
        param_3 = (int *)0x0;
        fVar1 = _DAT_00a0f378 / (float)param_1;
        if ((local_c != 0) && (0 < local_c)) {
          local_14 = local_14 + 2;
          iVar9 = 1;
          do {
            iVar10 = 0;
            iVar5 = *local_14 * iVar9;
            iVar2 = param_1 / iVar5;
            local_10 = *local_14 + -1;
            if (0 < local_10) {
              pfVar11 = (float *)(param_2 + (int)param_3 * 4);
              param_3 = (int *)((int)param_3 + local_10 * iVar2);
              do {
                iVar10 = iVar10 + iVar9;
                fVar12 = (float10)_DAT_007d5344;
                if (2 < iVar2) {
                  uVar6 = iVar2 - 1U >> 1;
                  pfVar4 = pfVar11;
                  do {
                    fVar12 = fVar12 + (float10)_DAT_00804108;
                    uVar6 = uVar6 - 1;
                    fVar13 = fVar12 * (float10)((float)iVar10 * fVar1);
                    fVar14 = (float10)fcos(fVar13);
                    *pfVar4 = (float)fVar14;
                    fVar13 = (float10)fsin(fVar13);
                    pfVar4[1] = (float)fVar13;
                    pfVar4 = pfVar4 + 2;
                  } while (uVar6 != 0);
                }
                pfVar11 = pfVar11 + iVar2;
                local_10 = local_10 + -1;
              } while (local_10 != 0);
            }
            local_14 = local_14 + 1;
            local_c = local_c + -1;
            iVar9 = iVar5;
          } while (local_c != 0);
        }
        return;
      }
      iVar5 = iVar2 / iVar9;
      piVar8 = piVar8 + 1;
      local_c = iVar10;
    } while (iVar2 == (iVar2 / iVar9) * iVar9);
  } while( true );
}

