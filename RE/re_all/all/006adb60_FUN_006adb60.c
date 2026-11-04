
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * FUN_006adb60(float *param_1,float param_2,int param_3,float *param_4,float *param_5)

{
  int iVar1;
  float fVar2;
  void *pvVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  undefined4 extraout_ECX;
  int iVar9;
  uint uVar10;
  undefined1 *puVar11;
  undefined4 *puVar12;
  float10 fVar13;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 fVar14;
  double adStack_7f2c [2];
  undefined4 uStack_7f1c;
  float local_7f0c [55];
  float afStack_7e30 [7561];
  float local_80c [56];
  undefined1 local_72c [1568];
  float local_10c [56];
  float *local_2c;
  undefined8 local_28;
  int local_20;
  undefined4 *local_1c;
  float *local_18;
  float *local_14;
  float *local_10;
  void *local_c;
  float *local_8;
  
  local_8 = (float *)0x6adb6d;
  uStack_7f1c = 0x6adb80;
  local_1c = (undefined4 *)((int)adStack_7f2c + (5 - param_3) * 4);
  *(undefined4 *)((int)adStack_7f2c + (4 - param_3) * 4) = 0x44;
  *(undefined4 *)((int)adStack_7f2c + (3 - param_3) * 4) = 0x6adb8a;
  local_c = _malloc(*(size_t *)((int)adStack_7f2c + (4 - param_3) * 4));
  pfVar4 = local_7f0c;
  for (iVar6 = 0x1dc0; iVar6 != 0; iVar6 = iVar6 + -1) {
    *pfVar4 = 0.0;
    pfVar4 = pfVar4 + 1;
  }
  local_8 = local_7f0c;
  local_10 = param_1;
  local_14 = (float *)&DAT_00823e50;
  local_18 = (float *)&DAT_00823cf0;
  do {
    pfVar4 = local_10c;
    iVar6 = 0x38;
    pfVar8 = local_18;
    do {
      iVar9 = 4;
      pfVar7 = pfVar8;
      fVar2 = _DAT_00829890;
      do {
        if ((int)pfVar7 < 0x823e50) {
          if (*pfVar7 < fVar2) {
            fVar2 = *pfVar7;
          }
        }
        else if (_DAT_00823e4c < fVar2) {
          fVar2 = _DAT_00823e4c;
        }
        pfVar7 = pfVar7 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      *pfVar4 = fVar2;
      pfVar8 = pfVar8 + 1;
      pfVar4 = pfVar4 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    pfVar4 = local_14;
    pfVar8 = local_8 + 0x70;
    for (iVar6 = 0x150; iVar6 != 0; iVar6 = iVar6 + -1) {
      *pfVar8 = *pfVar4;
      pfVar4 = pfVar4 + 1;
      pfVar8 = pfVar8 + 1;
    }
    pfVar4 = local_14;
    pfVar8 = local_8;
    for (iVar6 = 0x38; iVar6 != 0; iVar6 = iVar6 + -1) {
      *pfVar8 = *pfVar4;
      pfVar4 = pfVar4 + 1;
      pfVar8 = pfVar8 + 1;
    }
    local_2c = local_8 + 0x38;
    pfVar4 = local_14;
    pfVar8 = local_2c;
    for (iVar6 = 0x38; iVar6 != 0; iVar6 = iVar6 + -1) {
      *pfVar8 = *pfVar4;
      pfVar4 = pfVar4 + 1;
      pfVar8 = pfVar8 + 1;
    }
    iVar6 = 8;
    pfVar4 = local_8;
    do {
      uVar10 = 0x10;
      pfVar8 = pfVar4;
      do {
        fVar2 = (float)(int)((uVar10 ^ (int)uVar10 >> 0x1f) - ((int)uVar10 >> 0x1f)) *
                (float)param_5 + (float)param_4;
        if ((fVar2 < (float)_DAT_007d0a60) && (_DAT_007d5344 < (float)param_4)) {
          fVar2 = _DAT_007d5344;
        }
        if (((float)_DAT_007d0a60 < fVar2) && ((float)param_4 < _DAT_007d5344)) {
          fVar2 = _DAT_007d5344;
        }
        pfVar4 = pfVar8 + 1;
        uVar10 = uVar10 - 1;
        *pfVar8 = fVar2 + *pfVar8;
        pfVar8 = pfVar4;
      } while (-0x28 < (int)uVar10);
      iVar6 = iVar6 + -1;
      local_28 = (double)CONCAT44(pfVar4,(undefined4)local_28);
    } while (iVar6 != 0);
    param_1 = (float *)0x0;
    pfVar4 = local_80c;
    do {
      local_20 = 2;
      if (1 < (int)param_1) {
        local_20 = (int)param_1;
      }
      *(float **)((int)adStack_7f2c + (4 - param_3) * 4) = local_10;
      *(float *)((int)adStack_7f2c + (4 - param_3) * 4) =
           ((*local_10 + (float)_DAT_00829840) - (float)local_20 * (float)_DAT_0081ec08) -
           (float)_DAT_00829888;
      *(float **)((int)adStack_7f2c + (3 - param_3) * 4) = local_8;
      *(undefined4 *)((int)adStack_7f2c + (2 - param_3) * 4) = 0x6add11;
      FUN_006ae340();
      pfVar8 = local_10c;
      pfVar7 = pfVar4;
      for (iVar6 = 0x38; iVar6 != 0; iVar6 = iVar6 + -1) {
        *pfVar7 = *pfVar8;
        pfVar8 = pfVar8 + 1;
        pfVar7 = pfVar7 + 1;
      }
      *(float *)((int)adStack_7f2c + (4 - param_3) * 4) =
           ((float)_DAT_00829840 - (float)(int)param_1 * _DAT_007d52d8) - (float)_DAT_00829888;
      *(float **)((int)adStack_7f2c + (3 - param_3) * 4) = pfVar4;
      *(undefined4 *)((int)adStack_7f2c + (2 - param_3) * 4) = 0x6add41;
      FUN_006ae340();
      pfVar8 = local_8;
      *(float **)((int)adStack_7f2c + (2 - param_3) * 4) = local_8;
      *(float **)((int)adStack_7f2c + (1 - param_3) * 4) = pfVar4;
      *(undefined4 *)((int)adStack_7f2c + param_3 * -4) = 0x6add4b;
      FUN_006ae310();
      param_1 = (float *)((int)param_1 + 1);
      local_8 = pfVar8 + 0x38;
      pfVar4 = pfVar4 + 0x38;
    } while ((int)param_1 < 8);
    puVar11 = local_72c;
    iVar6 = 7;
    pfVar4 = local_2c;
    do {
      *(undefined1 **)((int)adStack_7f2c + (4 - param_3) * 4) = puVar11 + -0xe0;
      *(undefined1 **)((int)adStack_7f2c + (3 - param_3) * 4) = puVar11;
      *(undefined4 *)((int)adStack_7f2c + (2 - param_3) * 4) = 0x6add88;
      FUN_006ae2e0();
      *(undefined1 **)((int)adStack_7f2c + (2 - param_3) * 4) = puVar11;
      *(float **)((int)adStack_7f2c + (1 - param_3) * 4) = pfVar4;
      *(undefined4 *)((int)adStack_7f2c + param_3 * -4) = 0x6add8f;
      FUN_006ae2e0();
      puVar11 = puVar11 + 0xe0;
      pfVar4 = pfVar4 + 0x38;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    local_18 = local_18 + 4;
    local_14 = local_14 + 0x150;
    local_10 = local_10 + 1;
    local_8 = local_28._4_4_;
  } while ((int)local_18 < 0x823e00);
  param_4 = (float *)0x0;
  do {
    *(undefined4 *)((int)adStack_7f2c + (4 - param_3) * 4) = 0x20;
    *(undefined4 *)((int)adStack_7f2c + (3 - param_3) * 4) = 0x6addde;
    pvVar3 = _malloc(*(size_t *)((int)adStack_7f2c + (4 - param_3) * 4));
    *(undefined4 *)((int)adStack_7f2c + (3 - param_3) * 4) = extraout_ECX;
    fVar13 = (float10)_DAT_00804a60;
    *(void **)((int)local_c + (int)param_4 * 4) = pvVar3;
    local_28 = (double)((float10)(int)param_4 * fVar13);
    fVar14 = (float10)1.4426950408889634 *
             ((float10)(int)param_4 * fVar13 + (float10)_DAT_00829850) * (float10)_DAT_00829848;
    fVar13 = ROUND(fVar14);
    fVar14 = (float10)f2xm1(fVar14 - fVar13);
    fVar13 = (float10)fscale((float10)1 + fVar14,fVar13);
    *(double *)((int)adStack_7f2c + (3 - param_3) * 4) = (double)(fVar13 / (float10)param_2);
    *(undefined4 *)((int)adStack_7f2c + (2 - param_3) * 4) = 0x6ade21;
    FUN_006c5af0();
    *(undefined4 *)((int)adStack_7f2c + (2 - param_3) * 4) = 0x6ade26;
    iVar6 = __ftol();
    fVar13 = (float10)log2((float10)iVar6 * (float10)param_2 + (float10)_DAT_00804108);
    fVar13 = (float10)0.6931471805599453 * fVar13 * (float10)_DAT_00829858 - (float10)_DAT_00829850;
    *(double *)((int)adStack_7f2c + (3 - param_3) * 4) = (double)(fVar13 + fVar13);
    *(undefined4 *)((int)adStack_7f2c + (2 - param_3) * 4) = 0x6ade53;
    FUN_006c60f0();
    *(undefined4 *)((int)adStack_7f2c + (2 - param_3) * 4) = 0x6ade58;
    pfVar4 = (float *)__ftol();
    fVar13 = (float10)log2((float10)(iVar6 + 1) * (float10)param_2);
    fVar13 = (float10)0.6931471805599453 * fVar13 * (float10)_DAT_00829858 - (float10)_DAT_00829850;
    *(double *)((int)adStack_7f2c + (3 - param_3) * 4) = (double)(fVar13 + fVar13);
    *(undefined4 *)((int)adStack_7f2c + (2 - param_3) * 4) = 0x6ade83;
    local_10 = pfVar4;
    FUN_006c5af0();
    *(undefined4 *)((int)adStack_7f2c + (4 - param_3) * 4) = 0x6ade8b;
    local_8 = (float *)__ftol();
    if ((int)param_4 < (int)pfVar4) {
      local_10 = param_4;
      pfVar4 = param_4;
    }
    if ((int)pfVar4 < 0) {
      local_10 = (float *)0x0;
    }
    if (0x10 < (int)local_8) {
      local_8 = (float *)0x10;
    }
    local_20 = 0;
    do {
      iVar6 = local_20;
      *(undefined4 *)((int)adStack_7f2c + (4 - param_3) * 4) = 0xe8;
      *(undefined4 *)((int)adStack_7f2c + (3 - param_3) * 4) = 0x6adeb9;
      pvVar3 = _malloc(*(size_t *)((int)adStack_7f2c + (4 - param_3) * 4));
      *(void **)(*(int *)((int)local_c + (int)param_4 * 4) + iVar6 * 4) = pvVar3;
      if (0 < param_3) {
        puVar12 = local_1c;
        for (iVar9 = param_3; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar12 = 0x4479c000;
          puVar12 = puVar12 + 1;
        }
      }
      param_5 = local_10;
      if ((int)local_10 <= (int)local_8) {
        iVar6 = iVar6 + (int)local_10 * 8;
        local_18 = (float *)(iVar6 * 0x38);
        local_14 = afStack_7e30 + iVar6 * 0x38;
        do {
          iVar6 = 0;
          param_1 = (float *)0x0;
          fVar13 = (float10)(int)param_5 * (float10)_DAT_00804a60;
          do {
            fVar14 = (float10)1.4426950408889634 *
                     ((((float10)(int)param_1 * (float10)_DAT_00823528 + fVar13) -
                      (float10)_DAT_00829880) + (float10)_DAT_00829850) * (float10)_DAT_00829848;
            fVar13 = ROUND(fVar14);
            fVar14 = (float10)f2xm1(fVar14 - fVar13);
            fscale((float10)1 + fVar14,fVar13);
            *(undefined4 *)((int)adStack_7f2c + (4 - param_3) * 4) = 0x6adf5d;
            iVar5 = __ftol();
            fVar14 = (float10)1.4426950408889634 *
                     ((extraout_ST0 - (float10)_DAT_00829878) + (float10)_DAT_00829850) *
                     (float10)_DAT_00829848;
            fVar13 = ROUND(fVar14);
            fVar14 = (float10)f2xm1(fVar14 - fVar13);
            fscale((float10)1 + fVar14,fVar13);
            *(undefined4 *)((int)adStack_7f2c + (4 - param_3) * 4) = 0x6adf95;
            iVar9 = __ftol();
            if (iVar5 < 0) {
              iVar5 = 0;
            }
            if (param_3 < iVar5) {
              iVar5 = param_3;
            }
            if (iVar5 < iVar6) {
              iVar6 = iVar5;
            }
            if (iVar9 < 0) {
              iVar9 = 0;
            }
            if (param_3 < iVar9) {
              iVar9 = param_3;
            }
            if (iVar6 < iVar9) {
              pfVar4 = (float *)(local_1c + iVar6);
              do {
                if (param_3 <= iVar6) break;
                if (local_7f0c[(int)local_18 + (int)param_1] < *pfVar4) {
                  *pfVar4 = local_7f0c[(int)local_18 + (int)param_1];
                }
                iVar6 = iVar6 + 1;
                pfVar4 = pfVar4 + 1;
              } while (iVar6 < iVar9);
            }
            param_1 = (float *)((int)param_1 + 1);
            fVar13 = extraout_ST0_00;
          } while ((int)param_1 < 0x38);
          if (iVar6 < param_3) {
            iVar9 = param_3 - iVar6;
            pfVar4 = (float *)(local_1c + iVar6);
            do {
              if (*local_14 < *pfVar4) {
                *pfVar4 = *local_14;
              }
              pfVar4 = pfVar4 + 1;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
          param_5 = (float *)((int)param_5 + 1);
          local_18 = local_18 + 0x70;
          local_14 = local_14 + 0x1c0;
        } while ((int)param_5 <= (int)local_8);
        iVar6 = local_20;
      }
      if ((int)param_4 + 1 < 0x11) {
        iVar9 = 0;
        param_1 = (float *)0x0;
        do {
          fVar14 = (float10)1.4426950408889634 *
                   ((((float10)(int)param_1 * (float10)_DAT_00823528 + (float10)local_28) -
                    (float10)_DAT_00829880) + (float10)_DAT_00829850) * (float10)_DAT_00829848;
          fVar13 = ROUND(fVar14);
          fVar14 = (float10)f2xm1(fVar14 - fVar13);
          fscale((float10)1 + fVar14,fVar13);
          *(undefined4 *)((int)adStack_7f2c + (4 - param_3) * 4) = 0x6ae0a9;
          iVar5 = __ftol();
          fVar14 = (float10)1.4426950408889634 *
                   ((extraout_ST0_01 - (float10)_DAT_00829878) + (float10)_DAT_00829850) *
                   (float10)_DAT_00829848;
          fVar13 = ROUND(fVar14);
          fVar14 = (float10)f2xm1(fVar14 - fVar13);
          fscale((float10)1 + fVar14,fVar13);
          *(undefined4 *)((int)adStack_7f2c + (4 - param_3) * 4) = 0x6ae0e1;
          param_5 = (float *)__ftol();
          if (iVar5 < 0) {
            iVar5 = 0;
          }
          if (param_3 < iVar5) {
            iVar5 = param_3;
          }
          if (iVar5 < iVar9) {
            iVar9 = iVar5;
          }
          if ((int)param_5 < 0) {
            param_5 = (float *)0x0;
          }
          if (param_3 < (int)param_5) {
            param_5 = (float *)param_3;
          }
          if (iVar9 < (int)param_5) {
            pfVar4 = (float *)(local_1c + iVar9);
            do {
              if (param_3 <= iVar9) break;
              iVar5 = (int)param_1 + (iVar6 + ((int)param_4 + 1) * 8) * 0x38;
              if (local_7f0c[iVar5] < *pfVar4) {
                *pfVar4 = local_7f0c[iVar5];
              }
              iVar9 = iVar9 + 1;
              pfVar4 = pfVar4 + 1;
            } while (iVar9 < (int)param_5);
          }
          param_1 = (float *)((int)param_1 + 1);
        } while ((int)param_1 < 0x38);
        if (iVar9 < param_3) {
          iVar5 = param_3 - iVar9;
          pfVar4 = (float *)(local_1c + iVar9);
          do {
            if (afStack_7e30[(iVar6 + ((int)param_4 + 1) * 8) * 0x38] < *pfVar4) {
              *pfVar4 = afStack_7e30[(iVar6 + ((int)param_4 + 1) * 8) * 0x38];
            }
            pfVar4 = pfVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
      }
      param_1 = (float *)0x0;
      iVar9 = 8;
      do {
        fVar14 = (float10)1.4426950408889634 *
                 ((((float10)(int)param_1 * (float10)_DAT_00823528 + (float10)local_28) -
                  (float10)_DAT_00829868) + (float10)_DAT_00829850) * (float10)_DAT_00829848;
        fVar13 = ROUND(fVar14);
        fVar14 = (float10)f2xm1(fVar14 - fVar13);
        fscale((float10)1 + fVar14,fVar13);
        *(undefined4 *)((int)adStack_7f2c + (4 - param_3) * 4) = 0x6ae1f6;
        iVar5 = __ftol();
        if (iVar5 < 0) {
          *(undefined4 *)(*(int *)(*(int *)((int)local_c + (int)param_4 * 4) + iVar6 * 4) + iVar9) =
               0xc479c000;
        }
        else {
          iVar1 = *(int *)((int)local_c + (int)param_4 * 4);
          if (iVar5 < param_3) {
            *(undefined4 *)(*(int *)(iVar1 + iVar6 * 4) + iVar9) = local_1c[iVar5];
          }
          else {
            *(undefined4 *)(*(int *)(iVar1 + iVar6 * 4) + iVar9) = 0xc479c000;
          }
        }
        iVar9 = iVar9 + 4;
        param_1 = (float *)((int)param_1 + 1);
      } while (iVar9 < 0xe8);
      iVar9 = 0;
      pfVar8 = *(float **)(*(int *)((int)local_c + (int)param_4 * 4) + iVar6 * 4);
      pfVar4 = pfVar8 + 2;
      do {
        if (_DAT_00829874 < *pfVar4) break;
        iVar9 = iVar9 + 1;
        pfVar4 = pfVar4 + 1;
      } while (iVar9 < 0x10);
      iVar5 = 0x37;
      *pfVar8 = (float)iVar9;
      iVar9 = *(int *)(*(int *)((int)local_c + (int)param_4 * 4) + iVar6 * 4);
      pfVar4 = (float *)(iVar9 + 0xe4);
      do {
        if (_DAT_00829874 < *pfVar4) break;
        iVar5 = iVar5 + -1;
        pfVar4 = pfVar4 + -1;
      } while (0x11 < iVar5);
      local_20 = iVar6 + 1;
      *(float *)(iVar9 + 4) = (float)iVar5;
    } while (iVar6 + 1 < 8);
    param_4 = (float *)((int)param_4 + 1);
    if (0x10 < (int)param_4) {
      return local_c;
    }
  } while( true );
}

