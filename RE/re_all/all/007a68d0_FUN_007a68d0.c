
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a68d0(int param_1,uint param_2,int param_3,uint param_4,int param_5,uint param_6)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  float fVar7;
  float fVar8;
  
  iVar3 = 0;
  if ((param_5 * 2 < (int)param_2) && (param_6 != 0)) {
    fVar6 = (float10)(int)param_2 /
            (float10)(int)(*(int *)(&DAT_0083c808 + param_6 * 4) * param_5 + param_2);
    fVar6 = fVar6 * fVar6 * (float10)_DAT_007d589c;
    fVar5 = (float10)fcos(fVar6 * (float10)_DAT_00804864);
    fVar1 = (float)fVar5;
    fVar6 = (float10)fcos(((float10)_DAT_00804108 - fVar6) * (float10)_DAT_00804864);
    fVar2 = (float)fVar6;
    if ((int)(param_4 * 8) <= (int)param_2) {
      iVar4 = param_4 * 2;
      iVar3 = 1;
      while (((int)param_4 >> 2) + iVar4 < (int)param_2) {
        iVar4 = (iVar3 + 2) * (iVar3 + 1) * param_4;
        iVar3 = iVar3 + 1;
      }
    }
    param_2 = param_2 / param_4;
    if (0 < (int)param_4) {
      param_6 = param_4;
      do {
        if (param_3 < 0) {
          if (iVar3 != 0) {
            FUN_007a6a00(param_1,param_2,iVar3,fVar2,fVar1);
          }
          iVar4 = 1;
          fVar7 = fVar1;
          fVar8 = fVar2;
LAB_007a69d1:
          FUN_007a6a00(param_1,param_2,iVar4,fVar7,fVar8);
        }
        else {
          FUN_007a6a00(param_1,param_2,1,fVar1,-fVar2);
          if (iVar3 != 0) {
            fVar8 = -fVar1;
            iVar4 = iVar3;
            fVar7 = fVar2;
            goto LAB_007a69d1;
          }
        }
        param_1 = param_1 + param_2 * 4;
        param_6 = param_6 - 1;
      } while (param_6 != 0);
    }
  }
  return;
}

