
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0063ff80(int param_1,float *param_2,int param_3,int param_4,float *param_5,float *param_6,
            float *param_7,float *param_8,float *param_9,float param_10,float *param_11,
            float param_12)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  char cVar9;
  float fVar10;
  int iVar11;
  float10 fVar12;
  
  fVar5 = param_2[0xc];
  cVar9 = *(char *)(param_2 + 9);
  iVar11 = (int)param_9[6] * (int)param_10;
  if ((cVar9 == '\0') && (fVar5 == 0.0)) {
    return 0;
  }
  if (param_12 == 0.0) {
    fVar10 = param_9[2];
    param_10 = 0.0;
  }
  else {
    param_10 = param_9[5];
    fVar10 = param_9[3];
  }
  *(float *)((int)fVar10 + iVar11 * 4) = *param_11;
  *(float *)((int)fVar10 + 4 + iVar11 * 4) = param_11[1];
  *(float *)((int)fVar10 + 8 + iVar11 * 4) = param_11[2];
  if (param_12 == 0.0) {
    fVar6 = *(float *)(param_1 + 0x474) - *(float *)(param_3 + 0x30);
    fVar7 = *(float *)(param_1 + 0x478) - *(float *)(param_3 + 0x34);
    fVar8 = *(float *)(param_1 + 0x47c) - *(float *)(param_3 + 0x38);
    fVar10 = *param_11;
    fVar2 = param_11[2];
    fVar3 = param_11[1];
    fVar4 = *param_11;
    *(float *)((int)param_9[3] + iVar11 * 4) = fVar7 * param_11[2] - fVar8 * param_11[1];
    *(float *)((int)param_9[3] + 4 + iVar11 * 4) = fVar8 * fVar10 - fVar6 * fVar2;
    *(float *)((int)param_9[3] + 8 + iVar11 * 4) = fVar6 * fVar3 - fVar7 * fVar4;
    fVar4 = *(float *)(param_1 + 0x474) - *(float *)(param_4 + 0x30);
    fVar7 = *(float *)(param_1 + 0x478) - *(float *)(param_4 + 0x34);
    fVar6 = *(float *)(param_1 + 0x47c) - *(float *)(param_4 + 0x38);
    fVar2 = *param_11;
    fVar3 = param_11[2];
    fVar10 = fVar4 * param_11[1] - fVar7 * *param_11;
    *(float *)((int)param_9[5] + iVar11 * 4) = -(fVar7 * param_11[2] - fVar6 * param_11[1]);
    *(float *)((int)param_9[5] + 4 + iVar11 * 4) = -(fVar6 * fVar2 - fVar4 * fVar3);
    param_10 = param_9[5];
  }
  else {
    *(float *)((int)param_10 + iVar11 * 4) = -*param_11;
    *(float *)((int)param_10 + 4 + iVar11 * 4) = -param_11[1];
    fVar10 = param_11[2];
  }
  *(float *)((int)param_10 + 8 + iVar11 * 4) = -fVar10;
  if ((fVar5 != 0.0) && (*param_2 == param_2[1])) {
    cVar9 = '\0';
  }
  *(undefined4 *)((int)param_9[7] + iVar11 * 4) = 0;
  if (cVar9 == '\0') {
    if (fVar5 == 0.0) {
      return 1;
    }
  }
  else {
    *(undefined4 *)((int)param_9[8] + iVar11 * 4) = 0;
    if (fVar5 == 0.0) {
      if (param_12 == 0.0) {
        param_12 = -param_2[2];
      }
      else {
        param_12 = param_2[2];
      }
      fVar12 = (float10)FUN_00646980(param_2[0xb],*param_2,param_2[1],param_12,param_9[1] * *param_9
                                    );
      pfVar1 = (float *)((int)param_9[7] + iVar11 * 4);
      *pfVar1 = (float)(fVar12 * (float10)param_2[2] + (float10)*pfVar1);
      *(float *)((int)param_9[9] + iVar11 * 4) = -param_2[3];
      *(float *)((int)param_9[10] + iVar11 * 4) = param_2[3];
      return 1;
    }
  }
  fVar10 = param_2[7] * *param_9 * param_2[10];
  pfVar1 = (float *)((int)param_9[7] + iVar11 * 4);
  if (param_12 == 0.0) {
    fVar10 = fVar10 + *pfVar1;
  }
  else {
    fVar10 = *pfVar1 - fVar10;
  }
  *pfVar1 = fVar10;
  *(undefined4 *)((int)param_9[8] + iVar11 * 4) = 0;
  if (*param_2 == param_2[1]) {
    *(undefined4 *)((int)param_9[9] + iVar11 * 4) = 0xff7fffff;
    *(undefined4 *)((int)param_9[10] + iVar11 * 4) = 0x7f7fffff;
    return 1;
  }
  if (fVar5 == 1.4013e-45) {
    *(undefined4 *)((int)param_9[9] + iVar11 * 4) = 0;
    *(undefined4 *)((int)param_9[10] + iVar11 * 4) = 0x7f7fffff;
  }
  else {
    *(undefined4 *)((int)param_9[9] + iVar11 * 4) = 0xff7fffff;
    *(undefined4 *)((int)param_9[10] + iVar11 * 4) = 0;
  }
  if (_DAT_007d5344 < param_2[8]) {
    if (param_12 == 0.0) {
      fVar10 = *param_11 * *param_5 + param_5[1] * param_11[1] + param_5[2] * param_11[2];
      fVar2 = param_6[1] * param_11[1] + param_6[2] * param_11[2];
      fVar3 = *param_11 * *param_6;
    }
    else {
      fVar10 = *param_7 * *param_11 + param_7[1] * param_11[1] + param_7[2] * param_11[2];
      fVar2 = param_8[1] * param_11[1] + param_8[2] * param_11[2];
      fVar3 = *param_8 * *param_11;
    }
    fVar10 = fVar10 - (fVar3 + fVar2);
    if (fVar5 == 1.4013e-45) {
      if (fVar10 < _DAT_007d5344) {
        pfVar1 = (float *)((int)param_9[7] + iVar11 * 4);
        if (*pfVar1 < -(fVar10 * param_2[8])) {
          *pfVar1 = -(fVar10 * param_2[8]);
          return 1;
        }
      }
    }
    else if (_DAT_007d5344 < fVar10) {
      pfVar1 = (float *)((int)param_9[7] + iVar11 * 4);
      if (-(fVar10 * param_2[8]) < *pfVar1) {
        *pfVar1 = -(fVar10 * param_2[8]);
        return 1;
      }
    }
  }
  return 1;
}

