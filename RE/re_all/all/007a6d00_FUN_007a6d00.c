
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a6d00(int *param_1,float *param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  float local_50;
  float local_4c [4];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10 [4];
  
  iVar7 = 1;
  local_50 = 1.0;
  iVar8 = param_3 >> 1;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  pfVar6 = param_2;
  if (1 < iVar8) {
    do {
      iVar4 = *param_1;
      iVar2 = iVar7 * 8;
      iVar3 = iVar7 * 8;
      iVar1 = iVar7 * 8;
      iVar7 = iVar7 + 1;
      pfVar6[1] = ((*(float *)(iVar4 + -4 + iVar2) + *(float *)(iVar4 + 4 + iVar3)) * _DAT_007d589c
                  + *(float *)(iVar4 + iVar1)) * _DAT_007d589c;
      pfVar6 = pfVar6 + 1;
    } while (iVar7 < iVar8);
  }
  *param_2 = (((float *)*param_1)[1] * _DAT_007d589c + *(float *)*param_1) * _DAT_007d589c;
  if (param_4 == 2) {
    iVar7 = 1;
    pfVar6 = param_2;
    if (1 < iVar8) {
      do {
        pfVar6 = pfVar6 + 1;
        iVar4 = param_1[1];
        iVar2 = iVar7 * 8;
        iVar3 = iVar7 * 8;
        iVar1 = iVar7 * 8;
        iVar7 = iVar7 + 1;
        *pfVar6 = ((*(float *)(iVar4 + -4 + iVar2) + *(float *)(iVar4 + 4 + iVar3)) * _DAT_007d589c
                  + *(float *)(iVar4 + iVar1)) * _DAT_007d589c + *pfVar6;
      } while (iVar7 < iVar8);
    }
    *param_2 = (((float *)param_1[1])[1] * _DAT_007d589c + *(float *)param_1[1]) * _DAT_007d589c +
               *param_2;
  }
  FUN_007a64a0(param_2,&local_14,0,0,4,iVar8,param_5);
  param_3 = 1;
  local_14 = local_14 * _DAT_00838aa0;
  pfVar6 = local_10;
  do {
    fVar5 = (float)param_3;
    param_3 = param_3 + 1;
    *pfVar6 = *pfVar6 - fVar5 * _DAT_0083c87c * fVar5 * _DAT_0083c87c * *pfVar6;
    pfVar6 = pfVar6 + 1;
  } while (param_3 < 5);
  FUN_007a5bc0(local_4c,&local_14,4);
  iVar7 = 4;
  pfVar6 = local_4c;
  do {
    local_50 = local_50 * _DAT_00804854;
    iVar7 = iVar7 + -1;
    *pfVar6 = *pfVar6 * local_50;
    pfVar6 = pfVar6 + 1;
  } while (iVar7 != 0);
  local_28 = local_4c[0] + _DAT_007d5914;
  local_24 = local_4c[0] * _DAT_007d5914 + local_4c[1];
  local_20 = local_4c[1] * _DAT_007d5914 + local_4c[2];
  local_1c = local_4c[2] * _DAT_007d5914 + local_4c[3];
  local_18 = local_4c[3] * _DAT_007d5914;
  FUN_007a6ee0(param_2,&local_28,param_2,iVar8,&local_3c);
  return;
}

