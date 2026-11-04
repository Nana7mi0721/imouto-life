
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_006af920(int param_1,int param_2,int param_3,float *param_4,int param_5,int *param_6,
                    undefined4 param_7,int param_8,int param_9,int *param_10)

{
  int iVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float *pfVar12;
  int *piVar13;
  int iVar14;
  float10 fVar15;
  float10 extraout_ST0;
  double dStack_3c;
  undefined4 uStack_30;
  int local_8;
  
  iVar5 = (int)param_10;
  iVar4 = param_9;
  pfVar3 = param_4;
  iVar1 = *(int *)(param_1 + 4);
  uStack_30 = 0x6af946;
  iVar14 = 4 - param_9;
  local_8 = 0;
  if ((*(int *)(iVar1 + 500) == 0) || (iVar6 = *(int *)(iVar1 + 0x1f8) - param_8, param_9 < iVar6))
  {
    iVar6 = param_9;
  }
  param_7 = 0.0;
  param_1 = 0;
  if (0 < iVar6) {
    iVar8 = param_5 - (int)param_4;
    iVar11 = (int)param_6 - (int)param_4;
    iVar9 = param_3 - (int)param_4;
    iVar10 = (int)param_10 - (int)param_4;
    pfVar12 = param_4;
    param_4 = (float *)iVar6;
    do {
      if ((param_6 == (int *)0x0) || (*(int *)(iVar11 + (int)pfVar12) == 0)) {
        fVar2 = SQRT(*pfVar12 / *(float *)(iVar8 + (int)pfVar12)) + (float)_DAT_00804a60;
        if (_DAT_007d5344 <= *(float *)(iVar9 + (int)pfVar12)) {
          *(double *)((int)&dStack_3c + (2 - param_9) * 4) = (double)fVar2;
          *(undefined4 *)((int)&dStack_3c + (1 - param_9) * 4) = 0x6afa05;
          FUN_006c5af0();
          *(undefined4 *)((int)&dStack_3c + (3 - param_9) * 4) = 0x6afa0d;
          uVar7 = __ftol();
          *(undefined4 *)(iVar10 + (int)pfVar12) = uVar7;
        }
        else {
          *(double *)((int)&dStack_3c + (2 - param_9) * 4) = (double)fVar2;
          *(undefined4 *)((int)&dStack_3c + (1 - param_9) * 4) = 0x6af9e8;
          FUN_006c5af0();
          *(undefined4 *)((int)&dStack_3c + (3 - param_9) * 4) = 0x6af9f2;
          uVar7 = __ftol();
          *(undefined4 *)(iVar10 + (int)pfVar12) = uVar7;
        }
      }
      pfVar12 = pfVar12 + 1;
      param_4 = (float *)((int)param_4 + -1);
      param_1 = iVar6;
    } while (param_4 != (float *)0x0);
  }
  if (param_1 < param_9) {
    iVar6 = param_3 - (int)param_10;
    iVar8 = param_5 - (int)param_10;
    piVar13 = (int *)((int)param_10 + param_1 * 4);
    iVar9 = (int)pfVar3 - (int)param_10;
    param_10 = (int *)((int)&dStack_3c + (4 - param_9) * 4);
    do {
      if ((param_6 == (int *)0x0) ||
         (*(int *)(iVar6 + ((int)param_6 - param_3) + (int)piVar13) == 0)) {
        fVar2 = *(float *)(iVar9 + (int)piVar13) / *(float *)(iVar8 + (int)piVar13);
        if ((_DAT_00829860 <= fVar2) || ((param_6 != (int *)0x0 && (param_1 < param_2 - param_8))))
        {
          if (_DAT_007d5344 <= *(float *)(iVar6 + (int)piVar13)) {
            *(double *)((int)&dStack_3c + (2 - param_9) * 4) =
                 (double)(SQRT(fVar2) + (float)_DAT_00804a60);
            *(undefined4 *)((int)&dStack_3c + (1 - param_9) * 4) = 0x6afaef;
            FUN_006c5af0();
          }
          else {
            *(double *)((int)&dStack_3c + (2 - param_9) * 4) =
                 (double)(SQRT(fVar2) + (float)_DAT_00804a60);
            *(undefined4 *)((int)&dStack_3c + (1 - param_9) * 4) = 0x6afadd;
            FUN_006c5af0();
          }
          *(undefined4 *)((int)&dStack_3c + (3 - param_9) * 4) = 0x6afaf7;
          iVar10 = __ftol();
          *piVar13 = iVar10;
          *(float *)(iVar9 + (int)piVar13) =
               (float)(iVar10 * iVar10) * *(float *)(iVar8 + (int)piVar13);
        }
        else {
          param_7 = fVar2 + param_7;
          *param_10 = iVar9 + (int)piVar13;
          local_8 = local_8 + 1;
          param_10 = param_10 + 1;
        }
      }
      param_1 = param_1 + 1;
      piVar13 = piVar13 + 1;
    } while (param_1 < param_9);
    if (local_8 != 0) {
      *(undefined1 **)((int)&dStack_3c + (3 - param_9) * 4) = &LAB_006afbf0;
      *(undefined4 *)((int)&dStack_3c + (2 - param_9) * 4) = 4;
      *(int *)((int)&dStack_3c + (1 - param_9) * 4) = local_8;
      *(int *)((int)&dStack_3c + param_9 * -4) = (int)&dStack_3c + (4 - param_9) * 4;
      *(undefined4 *)((int)&dStack_3c + (-1 - param_9) * 4) = 0x6afb43;
      _qsort(*(void **)((int)&dStack_3c + param_9 * -4),
             *(size_t *)((int)&dStack_3c + (1 - param_9) * 4),
             *(size_t *)((int)&dStack_3c + (2 - param_9) * 4),
             *(_PtFuncCompare **)((int)&dStack_3c + (3 - param_9) * 4));
      if (0 < local_8) {
        param_9 = local_8;
        fVar15 = (float10)param_7;
        param_6 = (int *)((int)&dStack_3c + iVar14 * 4);
        do {
          iVar14 = *param_6 - (int)pfVar3 >> 2;
          if (fVar15 < (float10)*(double *)(iVar1 + 0x200)) {
            *(undefined4 *)(iVar5 + iVar14 * 4) = 0;
            pfVar3[iVar14] = 0.0;
          }
          else {
            param_7 = (float)(*(uint *)(param_3 + iVar14 * 4) & 0xbf800000 | 0x3f800000);
            *(undefined4 *)((int)&dStack_3c + (3 - iVar4) * 4) = 0x6afb9c;
            uVar7 = __ftol();
            fVar15 = extraout_ST0 - (float10)_DAT_00804108;
            *(undefined4 *)(iVar5 + iVar14 * 4) = uVar7;
            pfVar3[iVar14] = *(float *)(param_5 + iVar14 * 4);
          }
          param_6 = param_6 + 1;
          param_9 = param_9 + -1;
        } while (param_9 != 0);
        return fVar15;
      }
    }
  }
  return (float10)param_7;
}

