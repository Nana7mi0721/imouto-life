
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006aefe0(int *param_1,int param_2,float *param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
  iVar6 = 0;
  iVar3 = *param_1;
  fVar4 = (float)param_1[0xc];
  fVar1 = *(float *)(param_1[1] + 0xc + param_4 * 4);
  if (0 < iVar3) {
    param_5 = param_5 - (int)param_3;
    param_2 = param_2 - (int)param_3;
    param_7 = param_7 - (int)param_3;
    param_6 = param_6 - (int)param_3;
    do {
      fVar2 = *(float *)(*(int *)(param_1[3] + param_4 * 4) + iVar6 * 4) +
              *(float *)((int)param_3 + param_2);
      if (*(float *)(param_1[1] + 0x6c) < fVar2) {
        fVar2 = *(float *)(param_1[1] + 0x6c);
      }
      fVar5 = fVar1 + *param_3;
      if (fVar5 < fVar2) {
        fVar5 = fVar2;
      }
      *(float *)(param_5 + (int)param_3) = fVar5;
      if (param_4 == 1) {
        fVar2 = fVar2 - *(float *)(param_7 + (int)param_3);
        fVar5 = (fVar2 - _DAT_008298c0) * fVar4;
        if (fVar2 <= _DAT_008298c0) {
          fVar2 = (float)_DAT_00802e18 - fVar5 * (float)_DAT_008298a8;
        }
        else {
          fVar2 = (float)_DAT_00802e18 - fVar5 * (float)_DAT_008298b8;
          if (fVar2 < _DAT_007d5344) {
            *(float *)(param_6 + (int)param_3) = _DAT_008298b0 * *(float *)(param_6 + (int)param_3);
            goto LAB_006af0da;
          }
        }
        *(float *)(param_6 + (int)param_3) = fVar2 * *(float *)(param_6 + (int)param_3);
      }
LAB_006af0da:
      iVar6 = iVar6 + 1;
      param_3 = param_3 + 1;
    } while (iVar6 < iVar3);
  }
  return;
}

