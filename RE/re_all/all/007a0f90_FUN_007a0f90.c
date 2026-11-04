
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a0f90(int param_1,float *param_2,int param_3,int param_4,int param_5,float *param_6,
                 int param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  float afStack_220 [128];
  int local_14;
  float *local_c;
  
  bVar4 = false;
  local_14 = 0;
  fVar1 = *param_6;
  param_1 = param_1 - (int)param_2;
  param_7 = param_7 - (int)param_2;
  do {
    local_c = afStack_220 + (0x80 - param_3);
    fVar2 = *(float *)(param_7 + (int)param_2);
    pfVar6 = *(float **)(param_1 + (int)param_2);
    if (param_5 < 2) {
      if (0 < param_3) {
        iVar7 = param_3;
        pfVar5 = param_2;
        do {
          fVar3 = *pfVar6;
          pfVar6 = pfVar6 + 1;
          fVar3 = fVar2 + fVar3 + _DAT_00838a94;
          fVar2 = fVar3 * fVar1;
          *pfVar5 = fVar3 * _DAT_008376ac;
          pfVar5 = pfVar5 + param_4;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
    }
    else {
      if (0 < param_3) {
        pfVar5 = afStack_220 + (0x80 - param_3);
        iVar7 = param_3;
        do {
          iVar7 = iVar7 + -1;
          fVar3 = fVar2 + *(float *)(((int)pfVar6 - (int)(afStack_220 + (0x80 - param_3))) +
                                    (int)pfVar5) + _DAT_00838a94;
          fVar2 = fVar3 * fVar1;
          *pfVar5 = fVar3;
          pfVar5 = pfVar5 + 1;
        } while (iVar7 != 0);
      }
      bVar4 = true;
    }
    *(float *)(param_7 + (int)param_2) = fVar2;
    if ((bVar4) && (0 < param_3 / param_5)) {
      pfVar6 = param_2;
      iVar7 = param_3 / param_5;
      do {
        fVar2 = *local_c;
        local_c = local_c + param_5;
        *pfVar6 = fVar2 * _DAT_008376ac;
        pfVar6 = pfVar6 + param_4;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    local_14 = local_14 + 1;
    param_2 = param_2 + 1;
  } while (local_14 < param_4);
  return;
}

