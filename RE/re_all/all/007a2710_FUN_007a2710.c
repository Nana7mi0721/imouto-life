
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a2710(void *param_1,void *param_2,int param_3,int param_4,int param_5,float param_6,
                 float param_7,float param_8,float param_9,int param_10,int param_11)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  void *pvVar11;
  int iVar12;
  float *pfVar13;
  float *pfVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  
  pvVar11 = param_2;
  if ((param_6 == _DAT_007d5344) && (param_7 == _DAT_007d5344)) {
    if (param_2 != param_1) {
      _memmove(param_1,param_2,param_5 << 2);
      return;
    }
  }
  else {
    iVar12 = (int)param_8 * 0xc;
    fVar6 = *(float *)(&DAT_0083c48c + iVar12) * param_6;
    fVar7 = *(float *)(&DAT_0083c490 + iVar12) * param_6;
    fVar8 = *(float *)(&DAT_0083c494 + iVar12) * param_6;
    iVar12 = (int)param_9 * 0xc;
    fVar1 = *(float *)(&DAT_0083c48c + iVar12);
    fVar2 = *(float *)(&DAT_0083c490 + iVar12);
    fVar3 = *(float *)(&DAT_0083c494 + iVar12);
    pfVar13 = (float *)((int)param_2 + param_4 * -4);
    pfVar14 = (float *)((int)param_2 - (param_4 * 4 + 8));
    if ((param_6 == param_7) && ((param_3 == param_4 && (param_8 == param_9)))) {
      param_11 = 0;
    }
    iVar12 = 0;
    if (0 < param_11) {
      iVar12 = 0;
      param_10 = param_10 - (int)param_2;
      iVar15 = (int)param_1 - (int)param_2;
      param_2 = (void *)*(float *)((int)param_2 - (param_4 * 4 + 4));
      param_6 = (float)param_11;
      param_8 = *pfVar13;
      param_9 = *pfVar14;
      fVar9 = pfVar13[1];
      while( true ) {
        iVar16 = iVar12 + param_3 * -4;
        fVar4 = *(float *)(iVar12 + param_4 * -4 + 8 + (int)pvVar11);
        pfVar13 = (float *)(iVar12 + (int)pvVar11);
        fVar5 = *(float *)(param_10 + (int)pfVar13);
        fVar5 = fVar5 * fVar5;
        iVar17 = iVar12 + param_3 * -4;
        fVar10 = _DAT_00804108 - fVar5;
        iVar18 = iVar12 + param_3 * -4;
        iVar19 = iVar12 + param_3 * -4;
        iVar20 = iVar12 + param_3 * -4;
        iVar12 = iVar12 + 4;
        *(float *)(iVar15 + (int)pfVar13) =
             fVar5 * fVar1 * param_7 * param_8 +
             fVar10 * fVar6 * *(float *)(iVar20 + (int)pvVar11) +
             ((float)param_2 + fVar9) * fVar5 * fVar2 * param_7 +
             fVar5 * fVar3 * param_7 * (fVar4 + param_9) +
             fVar10 * fVar7 *
             (*(float *)(iVar18 + -4 + (int)pvVar11) + *(float *)(iVar19 + 4 + (int)pvVar11)) +
             fVar10 * fVar8 *
             (*(float *)(iVar16 + -8 + (int)pvVar11) + *(float *)((int)pvVar11 + iVar17 + 8)) +
             *pfVar13;
        param_9 = (float)param_2;
        param_2 = (void *)param_8;
        param_6 = (float)((int)param_6 + -1);
        if (param_6 == 0.0) break;
        param_8 = fVar9;
        fVar9 = fVar4;
      }
      iVar12 = param_11;
    }
    if (param_7 == _DAT_007d5344) {
      if (pvVar11 != param_1) {
        _memmove((void *)((int)param_1 + param_11 * 4),(void *)((int)pvVar11 + param_11 * 4),
                 (param_11 * 0x3fffffff + param_5) * 4);
        return;
      }
    }
    else {
      FUN_007a29c0((void *)((int)param_1 + iVar12 * 4),(void *)((int)pvVar11 + iVar12 * 4),param_4,
                   param_5 - iVar12,fVar1 * param_7,fVar2 * param_7,fVar3 * param_7);
    }
  }
  return;
}

