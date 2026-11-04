
void FUN_0079fe40(short *param_1,short *param_2,int param_3)

{
  short *psVar1;
  short *psVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  uint uVar8;
  short *psVar9;
  int iVar10;
  int iVar11;
  int local_c;
  
  psVar2 = param_2;
  psVar1 = param_1;
  local_c = 0;
  do {
    iVar11 = 1;
    iVar5 = (int)*psVar1 - (int)*param_2;
    iVar3 = 0;
    if (0 < param_3 + -1) {
      psVar6 = psVar1;
      do {
        psVar9 = psVar6 + 1;
        iVar10 = ((int)*psVar9 - (int)*(short *)(((int)param_2 - (int)psVar1) + (int)psVar9)) -
                 (int)*psVar6;
        if (iVar10 < iVar5) {
          iVar3 = iVar11;
          iVar5 = iVar10;
        }
        iVar11 = iVar11 + 1;
        psVar6 = psVar9;
      } while (iVar11 <= param_3 + -1);
    }
    param_1 = param_2 + param_3;
    iVar11 = (0x8000 - psVar1[param_3 + -1]) - (int)param_2[param_3];
    if (iVar11 < iVar5) {
      iVar3 = param_3;
      iVar5 = iVar11;
    }
    if (-1 < iVar5) {
      return;
    }
    if (iVar3 == 0) {
      *psVar1 = *param_2;
    }
    else if (iVar3 == param_3) {
      psVar1[param_3 + -1] = -0x8000 - param_2[param_3];
    }
    else {
      iVar5 = 0;
      if (0 < iVar3) {
        psVar6 = param_2;
        iVar11 = iVar3;
        do {
          iVar5 = iVar5 + *psVar6;
          psVar6 = psVar6 + 1;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
      iVar11 = 0x8000;
      iVar10 = (int)param_2[iVar3] >> 1;
      iVar5 = iVar5 + iVar10;
      if (iVar3 < param_3) {
        iVar7 = param_3 - iVar3;
        do {
          iVar11 = iVar11 - *param_1;
          param_1 = param_1 + -1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      iVar11 = iVar11 - iVar10;
      if (iVar11 < iVar5) {
        uVar8 = (int)psVar1[iVar3 + -1] + (int)psVar1[iVar3];
        iVar10 = (uVar8 & 1) + ((int)uVar8 >> 1);
        if (iVar5 < iVar10) {
          iVar11 = iVar5;
        }
        else if (iVar11 <= iVar10) goto LAB_0079ff99;
      }
      else {
        uVar8 = (int)psVar1[iVar3 + -1] + (int)psVar1[iVar3];
        iVar10 = (uVar8 & 1) + ((int)uVar8 >> 1);
        if ((iVar10 <= iVar11) && (iVar11 = iVar5, iVar5 <= iVar10)) {
LAB_0079ff99:
          iVar11 = iVar10;
        }
      }
      sVar4 = (short)iVar11 - (param_2[iVar3] >> 1);
      psVar1[iVar3 + -1] = sVar4;
      psVar1[iVar3] = sVar4 + param_2[iVar3];
    }
    local_c = local_c + 1;
    if (0x13 < local_c) {
      if (local_c == 0x14) {
        FUN_007a0290(psVar1,param_3);
        sVar4 = *param_2;
        if (*param_2 < *psVar1) {
          sVar4 = *psVar1;
        }
        *psVar1 = sVar4;
        if (1 < param_3) {
          iVar3 = (int)param_2 - (int)psVar1;
          psVar6 = psVar1;
          param_2 = (short *)(param_3 + -1);
          do {
            psVar9 = psVar6 + 1;
            iVar5 = (int)*(short *)((int)psVar9 + iVar3) + (int)*psVar6;
            if (iVar5 < *psVar9) {
              iVar5 = (int)*psVar9;
            }
            *psVar9 = (short)iVar5;
            param_2 = (short *)((int)param_2 + -1);
            psVar6 = psVar9;
          } while (param_2 != (short *)0x0);
        }
        iVar3 = 0x8000 - psVar2[param_3];
        if ((int)psVar1[param_3 + -1] < 0x8000 - psVar2[param_3]) {
          iVar3 = (int)psVar1[param_3 + -1];
        }
        psVar1[param_3 + -1] = (short)iVar3;
        if (-1 < param_3 + -2) {
          iVar3 = param_3 + -1;
          psVar6 = psVar1 + param_3 + -2;
          psVar9 = psVar2 + iVar3;
          do {
            iVar5 = (int)*(short *)(((int)psVar1 - (int)psVar2) + (int)psVar9) - (int)*psVar9;
            if (*psVar6 < iVar5) {
              iVar5 = (int)*psVar6;
            }
            *psVar6 = (short)iVar5;
            psVar9 = psVar9 + -1;
            psVar6 = psVar6 + -1;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
      }
      return;
    }
  } while( true );
}

