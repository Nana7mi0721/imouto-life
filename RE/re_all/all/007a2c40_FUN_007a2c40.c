
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a2c40(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 float param_7,int param_8,int param_9,int param_10,int param_11,int param_12,
                 uint param_13,undefined4 param_14)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  int local_28;
  int *local_24;
  int local_20;
  
  if ((int)param_7 < param_8) {
    bVar8 = (byte)param_4;
    iVar5 = 1 << (bVar8 & 0x1f);
    local_20 = param_5 * (int)param_7;
    local_24 = (int *)(param_12 + (int)param_7 * 4);
    iVar13 = (int)param_7;
    do {
      uVar11 = (int)*(short *)(*(int *)(param_1 + 0x20) + 2 + iVar13 * 2) -
               (int)*(short *)(*(int *)(param_1 + 0x20) + iVar13 * 2);
      iVar6 = uVar11 << (bVar8 & 0x1f);
      param_12 = 0;
      local_28 = 0;
      fVar16 = (float10)1.4426950408889634 *
               (float10)(int)((*local_24 + 1U) / uVar11 >> (bVar8 & 0x1f)) * (float10)_DAT_0083c5ac
               * (float10)_DAT_008376a0;
      fVar14 = ROUND(fVar16);
      fVar16 = (float10)f2xm1(fVar16 - fVar14);
      fVar16 = (float10)fscale((float10)1 + fVar16,fVar14);
      fVar14 = (float10)_DAT_007d589c;
      fVar3 = _DAT_00804108 / SQRT((float)iVar6);
      do {
        bVar4 = false;
        iVar9 = (*(int *)(param_1 + 8) * param_12 + iVar13) * 4;
        param_7 = *(float *)(iVar9 + param_10);
        fVar15 = (float10)*(float *)(iVar9 + param_11);
        if (param_5 == 1) {
          iVar10 = (*(int *)(param_1 + 8) + iVar13) * 4;
          if (param_7 <= *(float *)(iVar10 + param_10)) {
            param_7 = *(float *)(iVar10 + param_10);
          }
          if (fVar15 <= (float10)*(float *)(iVar10 + param_11)) {
            fVar15 = (float10)*(float *)(iVar10 + param_11);
          }
        }
        if ((float10)param_7 < fVar15) {
          fVar15 = (float10)param_7;
        }
        fVar15 = (float10)*(float *)(iVar9 + param_9) - fVar15;
        if (fVar15 < (float10)_DAT_007d5344) {
          fVar15 = (float10)_DAT_007d5344;
        }
        fVar17 = (float10)1.4426950408889634 * -fVar15 * (float10)_DAT_008376a0;
        fVar15 = ROUND(fVar17);
        fVar17 = (float10)f2xm1(fVar17 - fVar15);
        fVar15 = (float10)fscale((float10)1 + fVar17,fVar15);
        fVar15 = fVar15 + fVar15;
        if (param_4 == 3) {
          fVar15 = fVar15 * (float10)_DAT_008238dc;
        }
        if ((float10)(float)(fVar16 * fVar14) < fVar15) {
          fVar15 = (float10)(float)(fVar16 * fVar14);
        }
        iVar10 = 0;
        fVar1 = (float)(fVar15 * (float10)fVar3);
        iVar9 = param_2 + (((int)*(short *)(*(int *)(param_1 + 0x20) + iVar13 * 2) << (bVar8 & 0x1f)
                           ) + local_28) * 4;
        if (0 < iVar5) {
          do {
            if ((*(byte *)(local_20 + param_12 + param_3) & (byte)(1 << ((byte)iVar10 & 0x1f))) == 0
               ) {
              iVar12 = 0;
              if (0 < (int)uVar11) {
                do {
                  param_13 = FUN_007a2ae0(param_13);
                  fVar2 = fVar1;
                  if ((param_13 & 0x8000) == 0) {
                    fVar2 = -fVar1;
                  }
                  iVar7 = iVar12 << (bVar8 & 0x1f);
                  iVar12 = iVar12 + 1;
                  *(float *)(iVar9 + (iVar7 + iVar10) * 4) = fVar2;
                } while (iVar12 < (int)uVar11);
              }
              bVar4 = true;
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 < iVar5);
          if (bVar4) {
            FUN_007a6bb0(iVar9,iVar6,0x3f800000,param_14);
          }
        }
        local_28 = local_28 + param_6;
        param_12 = param_12 + 1;
      } while (param_12 < param_5);
      local_24 = local_24 + 1;
      iVar13 = iVar13 + 1;
      local_20 = local_20 + param_5;
    } while (iVar13 < param_8);
  }
  return;
}

