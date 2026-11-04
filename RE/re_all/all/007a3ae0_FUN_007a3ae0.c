
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_007a3ae0(int *param_1,float *param_2,int param_3,int param_4,int param_5,int param_6,
                 uint param_7,float param_8,uint param_9)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  byte bVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  float *pfVar15;
  undefined1 local_18 [4];
  int local_14;
  int local_10;
  uint local_c;
  uint local_8;
  int local_4;
  
  iVar13 = param_7;
  iVar10 = param_5;
  piVar6 = param_1;
  iVar12 = *param_1;
  iVar7 = param_1[1];
  iVar2 = param_1[4];
  iVar3 = param_1[6];
  iVar14 = param_7 + 1;
  pbVar1 = (byte *)((int)*(short *)(*(int *)(iVar7 + 0x60) +
                                   (*(int *)(iVar7 + 8) * iVar14 + param_1[2]) * 2) +
                   *(int *)(iVar7 + 100));
  if (((param_7 == -1) || (param_4 <= (int)(pbVar1[*pbVar1] + 0xc))) || (param_3 < 3)) {
    uVar8 = 0;
    param_7 = 6;
    param_1 = (int *)(uint)*pbVar1;
    iVar10 = param_4 + -1;
    do {
      uVar9 = (int)((int)param_1 + 1U + uVar8) >> 1;
      if ((int)(uint)pbVar1[uVar9] < iVar10) {
        uVar8 = uVar9;
      }
      else {
        param_1 = (int *)uVar9;
      }
      param_7 = param_7 + -1;
    } while (param_7 != 0);
    if (uVar8 == 0) {
      param_7 = 0xffffffff;
    }
    else {
      param_7 = (uint)pbVar1[uVar8];
    }
    if ((int)((uint)pbVar1[(int)param_1] - iVar10) < (int)(iVar10 - param_7)) {
      uVar8 = (uint)param_1;
    }
    if (uVar8 == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = pbVar1[uVar8] + 1;
    }
    iVar13 = piVar6[7] - iVar10;
    piVar6[7] = iVar13;
    while ((iVar13 < 0 && (0 < (int)uVar8))) {
      uVar8 = uVar8 - 1;
      piVar6[7] = iVar13 + iVar10;
      if (uVar8 == 0) {
        iVar10 = 0;
      }
      else {
        iVar10 = *(byte *)((int)*(short *)(*(int *)(iVar7 + 0x60) +
                                          (*(int *)(iVar7 + 8) * iVar14 + piVar6[2]) * 2) +
                           *(int *)(iVar7 + 100) + uVar8) + 1;
      }
      iVar13 = piVar6[7] - iVar10;
      piVar6[7] = iVar13;
    }
    if (uVar8 != 0) {
      if (7 < (int)uVar8) {
        uVar8 = (uVar8 & 7) + 8 << ((char)((int)uVar8 >> 3) - 1U & 0x1f);
      }
      if (iVar12 == 0) {
        uVar8 = FUN_007a6b00(param_2,param_3,uVar8,iVar2,param_5,iVar3,param_8);
        return uVar8;
      }
      uVar8 = FUN_007a65c0(param_2,param_3,uVar8,iVar2,param_5,iVar3);
      return uVar8;
    }
    if (iVar12 == 0) {
      uVar8 = (1 << ((byte)param_5 & 0x1f)) - 1;
      param_9 = param_9 & uVar8;
      if (param_9 != 0) {
        if (param_6 == 0) {
          if (0 < param_3) {
            iVar14 = param_3;
            pfVar15 = param_2;
            do {
              param_5 = FUN_007a2ae0(piVar6[9]);
              piVar6[9] = param_5;
              param_5 = param_5 >> 0x14;
              iVar14 = iVar14 + -1;
              *pfVar15 = (float)param_5;
              pfVar15 = pfVar15 + 1;
            } while (iVar14 != 0);
          }
        }
        else {
          if (0 < param_3) {
            iVar12 = param_6 - (int)param_2;
            iVar14 = param_3;
            pfVar15 = param_2;
            do {
              uVar8 = FUN_007a2ae0(piVar6[9]);
              fVar4 = _DAT_0083c5b4;
              piVar6[9] = uVar8;
              if ((uVar8 & 0x8000) == 0) {
                fVar4 = _DAT_0083c5b0;
              }
              iVar14 = iVar14 + -1;
              *pfVar15 = fVar4 + *(float *)(iVar12 + (int)pfVar15);
              pfVar15 = pfVar15 + 1;
            } while (iVar14 != 0);
          }
          uVar8 = param_9;
        }
        FUN_007a6bb0(param_2,param_3,param_8,piVar6[10]);
        return uVar8;
      }
      for (; param_3 != 0; param_3 = param_3 + -1) {
        *param_2 = 0.0;
        param_2 = param_2 + 1;
      }
    }
    return 0;
  }
  param_7 = 0;
  param_3 = param_3 >> 1;
  iVar13 = iVar13 + -1;
  pfVar15 = param_2 + param_3;
  if (param_5 == 1) {
    param_9 = param_9 & 1 | param_9 * 2;
  }
  iVar14 = param_5 + 1 >> 1;
  FUN_007a3fe0(param_1,local_18,param_2,pfVar15,param_3,&param_4,iVar14,param_5,iVar13,0,&param_9);
  fVar4 = (float)local_14 * _DAT_008376ac;
  fVar5 = (float)local_10 * _DAT_008376ac;
  if ((1 < iVar10) && ((local_8 & 0x3fff) != 0)) {
    if ((int)local_8 < 0x2001) {
      local_c = local_c + (param_3 * 8 >> (5U - (char)iVar13 & 0x1f));
      local_c = (0 < (int)local_c) - 1 & local_c;
    }
    else {
      local_c = local_c - ((int)local_c >> (4U - (char)iVar13 & 0x1f));
    }
  }
  iVar7 = (int)(param_4 - local_c) / 2;
  iVar12 = param_4;
  if (iVar7 <= param_4) {
    iVar12 = iVar7;
  }
  if (iVar12 < 0) {
    param_1 = (int *)0x0;
  }
  else {
    param_1 = (int *)param_4;
    if (iVar7 <= param_4) {
      param_1 = (int *)iVar7;
    }
  }
  param_5 = param_4 - (int)param_1;
  iVar12 = piVar6[7] - local_4;
  piVar6[7] = iVar12;
  if (param_6 != 0) {
    param_7 = param_6 + param_3 * 4;
  }
  bVar11 = (byte)(iVar10 >> 1);
  if ((int)param_1 < param_5) {
    iVar7 = FUN_007a3ae0(piVar6,pfVar15,param_3,param_5,iVar14,param_7,iVar13,fVar5 * param_8,
                         (int)param_9 >> ((byte)iVar14 & 0x1f));
    iVar12 = (piVar6[7] - iVar12) + param_5;
    if ((0x18 < iVar12) && (local_8 != 0x4000)) {
      param_1 = (int *)((int)param_1 + -0x18 + iVar12);
    }
    uVar8 = FUN_007a3ae0(piVar6,param_2,param_3,param_1,iVar14,param_6,iVar13,fVar4 * param_8,
                         param_9);
    return iVar7 << (bVar11 & 0x1f) | uVar8;
  }
  uVar8 = FUN_007a3ae0(piVar6,param_2,param_3,param_1,iVar14,param_6,iVar13,fVar4 * param_8,param_9)
  ;
  iVar12 = (piVar6[7] - iVar12) + (int)param_1;
  if ((0x18 < iVar12) && (local_8 != 0)) {
    param_5 = param_5 + -0x18 + iVar12;
  }
  iVar14 = FUN_007a3ae0(piVar6,pfVar15,param_3,param_5,iVar14,param_7,iVar13,fVar5 * param_8,
                        (int)param_9 >> ((byte)iVar14 & 0x1f));
  return uVar8 | iVar14 << (bVar11 & 0x1f);
}

