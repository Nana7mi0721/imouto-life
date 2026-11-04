
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ad5b0(int *param_1,int param_2,int *param_3,int param_4,int param_5)

{
  size_t _Size;
  float *pfVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  float *pfVar13;
  int *piVar14;
  float10 fVar15;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float10 fVar16;
  float10 extraout_ST1_00;
  int local_24;
  int local_20;
  int local_1c;
  
  iVar6 = param_5;
  iVar5 = param_4;
  piVar4 = param_1;
  piVar14 = param_1;
  for (iVar11 = 0xd; iVar11 != 0; iVar11 = iVar11 + -1) {
    *piVar14 = 0;
    piVar14 = piVar14 + 1;
  }
  local_24 = -99;
  local_20 = 1;
  param_1[9] = *param_3;
  fVar15 = (float10)log2((float10)*param_3 * (float10)_DAT_00829870);
  fVar16 = (float10)log2((float10)_DAT_00829868);
  FUN_006c5af0((double)(((float10)0.6931471805599453 * fVar15) /
                        ((float10)0.6931471805599453 * fVar16) + (float10)_DAT_00804a60));
  iVar11 = __ftol();
  fVar15 = (float10)param_4;
  param_1[8] = iVar11;
  log2(((float10)param_5 * (float10)_DAT_00829860 * (float10)_DAT_00804a60) / fVar15);
  iVar11 = __ftol();
  param_1[7] = iVar11;
  log2((((float10)param_4 + (float10)_DAT_00829860) * fVar15 * (float10)_DAT_00804a60) /
       extraout_ST1);
  iVar7 = __ftol();
  _Size = param_4 * 4;
  param_1[10] = (iVar7 - iVar11) + 1;
  pvVar8 = _malloc(_Size);
  param_1[4] = (int)pvVar8;
  pvVar8 = _malloc(_Size);
  param_1[5] = (int)pvVar8;
  pvVar8 = _malloc(_Size);
  param_1[6] = (int)pvVar8;
  param_1[1] = param_2;
  *param_1 = param_4;
  param_1[0xb] = param_5;
  param_1[0xc] = 0x3f800000;
  if (param_5 < 26000) {
    param_1[0xc] = 0;
  }
  else if (param_5 < 38000) {
    param_1[0xc] = 0x3f70a3d7;
  }
  else if (46000 < param_5) {
    param_1[0xc] = 0x3fa33333;
  }
  iVar7 = 0;
  iVar11 = 0;
  pfVar13 = (float *)&DAT_00823cf4;
  do {
    iVar7 = iVar7 + 1;
    fVar16 = (float10)1.4426950408889634 *
             (((float10)iVar7 * (float10)_DAT_00823528 - (float10)_DAT_00829868) +
             (float10)_DAT_00829850) * (float10)_DAT_00829848;
    fVar15 = ROUND(fVar16);
    fVar16 = (float10)f2xm1(fVar16 - fVar15);
    fVar15 = (float10)fscale((float10)1 + fVar16,fVar15);
    FUN_006c5af0((double)((fVar15 * (float10)param_4 + fVar15 * (float10)param_4) / (float10)param_5
                         + (float10)_DAT_00804a60));
    iVar9 = __ftol();
    fVar2 = pfVar13[-1];
    if (iVar11 < iVar9) {
      iVar12 = iVar9 - iVar11;
      fVar3 = *pfVar13 - fVar2;
      do {
        if (param_4 <= iVar11) break;
        iVar11 = iVar11 + 1;
        *(float *)(param_1[4] + -4 + iVar11 * 4) = fVar2 + (float)_DAT_00829840;
        fVar2 = fVar2 + fVar3 / (float)iVar12;
      } while (iVar11 < iVar9);
    }
    pfVar13 = pfVar13 + 1;
  } while ((int)pfVar13 < 0x823e50);
  for (; iVar11 < param_4; iVar11 = iVar11 + 1) {
    *(undefined4 *)(param_1[4] + iVar11 * 4) = *(undefined4 *)(param_1[4] + -4 + iVar11 * 4);
  }
  iVar11 = 0;
  if (0 < param_4) {
    param_3 = (int *)0x0;
    param_1 = (int *)0x0;
    iVar7 = param_5 / (param_4 * 2);
    iVar9 = iVar7 * iVar7;
    do {
      local_1c = *(int *)(param_2 + 0x78) + local_24;
      fVar15 = (float10)fpatan((float10)((int)param_1 * iVar11) * (float10)_DAT_00829838,(float10)1)
      ;
      fVar16 = (float10)fpatan((float10)(int)param_3 * (float10)_DAT_00829828,(float10)1);
      fVar2 = (float)((float10)(int)param_3 * (float10)_DAT_008298b0 +
                     fVar16 * (float10)_DAT_00829820 + fVar15 * (float10)_DAT_00829830);
      if (local_1c < iVar11) {
        param_5 = iVar7 * local_24;
        iVar12 = iVar9 * local_24;
        do {
          fVar15 = (float10)fpatan((float10)(iVar12 * local_24) * (float10)_DAT_00829838,(float10)1)
          ;
          fVar16 = (float10)fpatan((float10)param_5 * (float10)_DAT_00829828,(float10)1);
          if ((float10)(fVar2 - *(float *)(param_2 + 0x70)) <=
              (float10)param_5 * (float10)_DAT_008298b0 +
              fVar16 * (float10)_DAT_00829820 + fVar15 * (float10)_DAT_00829830) break;
          iVar12 = iVar12 + iVar9;
          local_24 = local_24 + 1;
          param_5 = param_5 + iVar7;
          local_1c = local_1c + 1;
        } while (local_1c < iVar11);
      }
      if (local_20 <= param_4) {
        param_5 = iVar7 * local_20;
        iVar12 = iVar9 * local_20;
        do {
          if (*(int *)(param_2 + 0x7c) + iVar11 <= local_20) {
            fVar15 = (float10)fpatan((float10)(iVar12 * local_20) * (float10)_DAT_00829838,
                                     (float10)1);
            fVar16 = (float10)fpatan((float10)param_5 * (float10)_DAT_00829828,(float10)1);
            if ((float10)fVar2 + (float10)*(float *)(param_2 + 0x74) <=
                (float10)param_5 * (float10)_DAT_008298b0 +
                fVar16 * (float10)_DAT_00829820 + fVar15 * (float10)_DAT_00829830) break;
          }
          local_20 = local_20 + 1;
          param_5 = param_5 + iVar7;
          iVar12 = iVar12 + iVar9;
        } while (local_20 <= param_4);
      }
      iVar11 = iVar11 + 1;
      *(int *)(piVar4[6] + -4 + iVar11 * 4) = local_24 * 0x10000 + -0x10001 + local_20;
      param_1 = (int *)((int)param_1 + iVar9);
      param_3 = (int *)((int)param_3 + iVar7);
    } while (iVar11 < param_4);
  }
  param_4 = 0;
  if (0 < iVar5) {
    do {
      log2((((float10)param_4 + (float10)_DAT_00829860) * (float10)iVar6 * (float10)_DAT_00804a60) /
           (float10)iVar5);
      uVar10 = __ftol();
      param_4 = param_4 + 1;
      *(undefined4 *)(piVar4[5] + -4 + param_4 * 4) = uVar10;
    } while (param_4 < iVar5);
  }
  iVar11 = FUN_006adb60(param_2 + 0x24,((float)iVar6 * (float)_DAT_00804a60) / (float)iVar5,iVar5,
                        *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c));
  piVar4[2] = iVar11;
  pvVar8 = _malloc(0xc);
  piVar4[3] = (int)pvVar8;
  iVar11 = 0;
  do {
    pvVar8 = _malloc(iVar5 * 4);
    iVar7 = iVar11 + 4;
    *(void **)(iVar11 + piVar4[3]) = pvVar8;
    iVar11 = iVar7;
  } while (iVar7 < 0xc);
  param_4 = 0;
  if (0 < iVar5) {
    fVar15 = (float10)iVar5 + (float10)iVar5;
    do {
      log2((((float10)param_4 + (float10)_DAT_00804a60) * (float10)iVar6) / fVar15);
      iVar9 = __ftol();
      iVar11 = iVar9 * 4 + 0x88;
      fVar15 = (float10)_DAT_00802e18;
      iVar7 = 0;
      do {
        iVar12 = iVar7 + 4;
        pfVar1 = (float *)(piVar4[1] + -4 + iVar11);
        pfVar13 = (float *)(piVar4[1] + iVar11);
        iVar11 = iVar11 + 0x44;
        *(float *)(*(int *)(iVar7 + piVar4[3]) + param_4 * 4) =
             (float)((extraout_ST0 - (float10)iVar9) * (float10)*pfVar13 +
                    (float10)*pfVar1 * (fVar15 - (extraout_ST0 - (float10)iVar9)));
        iVar7 = iVar12;
      } while (iVar12 < 0xc);
      param_4 = param_4 + 1;
      fVar15 = extraout_ST1_00;
    } while (param_4 < iVar5);
  }
  return;
}

