
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_007a46e0(int *param_1,float *param_2,float *param_3,int param_4,int param_5,float param_6,
                 undefined4 param_7,int param_8,undefined4 param_9,undefined4 param_10,int param_11)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float *pfVar4;
  float fVar5;
  int *piVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  float *pfVar12;
  int iVar13;
  int iVar14;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar10 = param_11;
  uVar7 = param_6;
  piVar6 = param_1;
  iVar2 = *param_1;
  iVar14 = param_1[6];
  if (param_4 == 1) {
    uVar8 = FUN_007a39f0(param_1,param_2,param_3,param_5,param_9);
    return uVar8;
  }
  FUN_007a3fe0(param_1,&local_18,param_2,param_3,param_4,&param_5,param_6,param_6,param_8,1,
               &param_11);
  fVar5 = (float)local_14 * _DAT_008376ac;
  param_6 = (float)local_10 * _DAT_008376ac;
  if (param_4 == 2) {
    uVar8 = 0;
    iVar13 = 0;
    if ((local_8 != 0) && (local_8 != 0x4000)) {
      iVar13 = 8;
    }
    iVar9 = param_5 - iVar13;
    param_1[7] = param_1[7] - (local_4 + iVar13);
    if (local_8 < 0x2001) {
      pfVar12 = param_3;
      pfVar4 = param_2;
    }
    else {
      pfVar12 = param_2;
      pfVar4 = param_3;
    }
    if (iVar13 != 0) {
      if (iVar2 == 0) {
        uVar8 = FUN_007a2250(iVar14,1);
      }
      else {
        uVar8 = (uint)(pfVar12[1] * *pfVar4 - pfVar4[1] * *pfVar12 < _DAT_007d5344);
        FUN_007a25b0(iVar14,uVar8,1);
      }
    }
    iVar14 = uVar8 * -2 + 1;
    param_1 = (int *)FUN_007a3510(param_1,pfVar4,2,iVar9,uVar7,param_7,param_8,param_9,0x3f800000,
                                  param_10,iVar10);
    param_8 = -iVar14;
    *pfVar12 = (float)param_8 * pfVar4[1];
    pfVar12[1] = (float)iVar14 * *pfVar4;
    if (iVar2 != 0) {
      return (uint)param_1;
    }
    *param_2 = fVar5 * *param_2;
    param_2[1] = param_2[1] * fVar5;
    fVar1 = *param_3;
    *param_3 = param_6 * fVar1;
    param_3[1] = param_3[1] * param_6;
    fVar3 = *param_2;
    *param_2 = fVar3 - param_6 * fVar1;
    *param_3 = fVar3 + *param_3;
    fVar1 = param_2[1];
    param_2[1] = fVar1 - param_3[1];
    param_3[1] = param_3[1] + fVar1;
  }
  else {
    iVar10 = (param_5 - local_c) / 2;
    iVar14 = param_5;
    if (iVar10 <= param_5) {
      iVar14 = iVar10;
    }
    if (iVar14 < 0) {
      iVar14 = 0;
    }
    else {
      iVar14 = param_5;
      if (iVar10 <= param_5) {
        iVar14 = iVar10;
      }
    }
    iVar13 = param_1[7] - local_4;
    iVar10 = param_5 - iVar14;
    param_1[7] = iVar13;
    if (iVar14 < iVar10) {
      uVar8 = FUN_007a3510(param_1,param_3,param_4,iVar10,uVar7,0,param_8,0,param_6,0,
                           param_11 >> ((byte)uVar7 & 0x1f));
      iVar10 = (iVar10 - iVar13) + param_1[7];
      if ((0x18 < iVar10) && (local_8 != 0x4000)) {
        iVar14 = iVar14 + -0x18 + iVar10;
      }
      uVar11 = FUN_007a3510(param_1,param_2,param_4,iVar14,uVar7,param_7,param_8,param_9,0x3f800000,
                            param_10,param_11);
      param_1 = (int *)(uVar8 | uVar11);
    }
    else {
      uVar8 = FUN_007a3510(param_1,param_2,param_4,iVar14,uVar7,param_7,param_8,param_9,0x3f800000,
                           param_10,param_11);
      iVar14 = (iVar14 - iVar13) + param_1[7];
      if ((0x18 < iVar14) && (local_8 != 0)) {
        iVar10 = iVar10 + -0x18 + iVar14;
      }
      uVar11 = FUN_007a3510(param_1,param_3,param_4,iVar10,uVar7,0,param_8,0,param_6,0,
                            param_11 >> ((byte)uVar7 & 0x1f));
      param_1 = (int *)(uVar8 | uVar11);
    }
  }
  if (iVar2 == 0) {
    if (param_4 != 2) {
      FUN_007a4ad0(param_2,param_3,fVar5,param_4,piVar6[10]);
    }
    if ((local_18 != 0) && (0 < param_4)) {
      do {
        *param_3 = -*param_3;
        param_3 = param_3 + 1;
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
  }
  return (uint)param_1;
}

