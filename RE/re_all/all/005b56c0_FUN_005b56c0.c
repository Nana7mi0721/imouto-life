
undefined4
FUN_005b56c0(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6,
            float param_7,float param_8,int param_9,undefined4 param_10,uint param_11,
            undefined4 param_12)

{
  double dVar1;
  double dVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  float *pfVar7;
  uint uVar8;
  int iVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  float10 fVar18;
  float10 fVar19;
  float10 fVar20;
  float10 fVar21;
  float10 fVar22;
  float10 fVar23;
  float10 fVar24;
  
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if (0 < DAT_00a380d4) {
    uVar5 = FUN_005adcf0((int)ROUND(param_1),(int)ROUND(param_2),(int)ROUND(param_3),
                         (int)ROUND(param_4),(int)ROUND(param_5),(int)ROUND(param_6),
                         (int)ROUND(param_7),(int)ROUND(param_8),param_9,param_10,param_11,param_12)
    ;
    return uVar5;
  }
  if (DAT_00e79688 == 0) {
    FUN_0059d430();
  }
  uVar8 = param_11 | 0x8000;
  if (*(char *)(*(int *)(param_9 + 0x4c) + 10) != '\0') {
    uVar8 = param_11 | 0x18000;
  }
  if (*(char *)(*(int *)(param_9 + 0x4c) + 0x12) != '\0') {
    uVar8 = uVar8 | 0x20000;
  }
  if (DAT_00e39a4c != *(int *)**(undefined4 **)(param_9 + 0x100)) {
    FUN_0059bcf0(*(int *)**(undefined4 **)(param_9 + 0x100));
  }
  if (((DAT_00a3d360 != 0) || (DAT_00e39a00 != 0)) || (DAT_00e399fc != uVar8)) {
    FUN_005a7f60();
  }
  iVar6 = *(int *)(param_9 + 0x88);
  if (iVar6 == 1) {
    FUN_005af1c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9 + 0x8c,0);
    return 0;
  }
  iVar9 = param_9 + 0x8c;
  fVar21 = (float10)param_5 - (float10)param_1;
  dVar1 = (double)fVar21;
  fVar22 = (float10)param_7 - (float10)param_3;
  dVar2 = (double)fVar22;
  param_6 = param_6 - param_2;
  param_8 = param_8 - param_4;
  fVar3 = 1.0 / *(float *)(param_9 + 0x68);
  fVar4 = 1.0 / *(float *)(param_9 + 0x6c);
  if (iVar6 < 1) {
    return 0;
  }
  pfVar7 = (float *)(param_9 + 0xd0);
  while( true ) {
    fVar24 = (float10)param_1;
    fVar23 = (float10)param_3;
    fVar20 = (float10)param_2;
    fVar10 = (float10)pfVar7[-4] * (float10)fVar4;
    fVar11 = (float10)(double)(fVar10 * fVar21 + fVar24);
    fVar12 = (float10)(double)((float10)param_6 * fVar10 + fVar20);
    fVar13 = (float10)*pfVar7 * (float10)fVar4;
    fVar14 = (float10)(double)(fVar13 * fVar21 + fVar24);
    fVar15 = (float10)(double)((float10)param_6 * fVar13 + fVar20);
    fVar16 = (float10)pfVar7[4] * (float10)fVar4;
    fVar17 = (float10)(double)(fVar16 * fVar21 + fVar24);
    fVar18 = (float10)(double)((float10)param_6 * fVar16 + fVar20);
    fVar19 = (float10)pfVar7[8] * (float10)fVar4;
    fVar24 = fVar19 * fVar21 + fVar24;
    fVar20 = fVar19 * (float10)param_6 + fVar20;
    FUN_005af1c0((float)(((fVar10 * fVar22 + fVar23) - fVar11) *
                         (float10)pfVar7[-5] * (float10)fVar3 + fVar11),
                 (float)(fVar12 + ((float10)(double)(fVar10 * (float10)param_8 + (float10)param_4) -
                                  fVar12) * (float10)pfVar7[-5] * (float10)fVar3),
                 (float)(((fVar13 * fVar22 + fVar23) - fVar14) *
                         (float10)pfVar7[-1] * (float10)fVar3 + fVar14),
                 (float)(fVar15 + ((float10)(double)(fVar13 * (float10)param_8 + (float10)param_4) -
                                  fVar15) * (float10)pfVar7[-1] * (float10)fVar3),
                 (float)(((fVar16 * fVar22 + fVar23) - fVar17) * (float10)pfVar7[3] * (float10)fVar3
                        + fVar17),
                 (float)(fVar18 + ((float10)(double)(fVar16 * (float10)param_8 + (float10)param_4) -
                                  fVar18) * (float10)pfVar7[3] * (float10)fVar3),
                 (float)(((fVar19 * fVar22 + fVar23) - fVar24) * (float10)pfVar7[7] * (float10)fVar3
                        + fVar24),
                 (float)(fVar20 + ((fVar19 * (float10)param_8 + (float10)param_4) - fVar20) *
                                  (float10)pfVar7[7] * (float10)fVar3),iVar9,0);
    iVar9 = iVar9 + 0x78;
    pfVar7 = pfVar7 + 0x1e;
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) break;
    fVar21 = (float10)dVar1;
    fVar22 = (float10)dVar2;
  }
  return 0;
}

