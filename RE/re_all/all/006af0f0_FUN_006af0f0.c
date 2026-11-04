
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006af0f0(int param_1,int param_2,int *param_3,int param_4,int param_5,int param_6,
                 undefined4 *param_7,int param_8,uint param_9)

{
  float fVar1;
  double dVar2;
  double dVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int *piVar18;
  int *piVar19;
  int *piVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  float *pfVar24;
  int iVar25;
  int iVar26;
  uint uVar27;
  undefined4 *puVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  float10 fVar32;
  undefined4 uStack_9c;
  float local_68;
  int local_40;
  uint local_3c;
  int local_38;
  int local_34;
  int local_2c;
  int local_28;
  uint local_18;
  int local_14;
  int *local_10;
  float *local_8;
  
  iVar31 = *param_3;
  piVar18 = (int *)param_3[1];
  if (piVar18[0x7d] == 0) {
    local_28 = 0x10;
  }
  else {
    local_28 = piVar18[0x7f];
  }
  iVar4 = *(int *)(param_2 + 0x84 + (param_1 + *piVar18 * 0xf) * 4);
  dVar2 = *(double *)(&DAT_00829790 + *(int *)(param_2 + 0xfc + param_1 * 4) * 8);
  iVar9 = *(int *)(param_2 + 0x138 + param_1 * 4) * 8;
  dVar3 = *(double *)(&DAT_00829790 + iVar9);
  uStack_9c = 0x6af17a;
  iVar8 = param_9 * -4;
  (&uStack_9c)[-param_9] = 0x6af189;
  piVar18 = (int *)((int)register0x00000010 + param_9 * -8 + -0x98);
  (&uStack_9c)[param_9 * -2] = 0x6af19a;
  piVar18[-1 - param_9] = 0x6af1a9;
  piVar18[param_9 * -2 + -1] = 0x6af1b8;
  iVar10 = *(int *)(param_4 + 0x484) + param_9;
  piVar18[param_9 * -3 + -1] = 0x6af1d3;
  piVar20 = piVar18 + (param_9 * -3 - iVar10);
  if (1000 < iVar31) {
    dVar3 = *(double *)(&DAT_008297d8 + iVar9);
  }
  local_68 = (float)dVar3;
  uVar27 = local_28 * param_9;
  piVar18[param_9 * -3 + (-1 - iVar10)] = 0x6af204;
  *(int **)((int)register0x00000010 + iVar8 + -0x98) = piVar18 + param_9 * -3 + (-iVar10 - uVar27);
  piVar18[param_9 * -3 + ((-1 - uVar27) - iVar10)] = 0x6af217;
  *piVar18 = (int)(piVar18 + param_9 * -3 + (uVar27 * -2 - iVar10));
  piVar18[param_9 * -3 + ((uVar27 * -2 + -1) - iVar10)] = 0x6af227;
  piVar18[-param_9] = (int)(piVar18 + param_9 * -3 + (uVar27 * -3 - iVar10));
  piVar18[param_9 * -3 + ((uVar27 * -3 + -1) - iVar10)] = 0x6af23a;
  piVar18[param_9 * -2] = (int)(piVar18 + param_9 * -3 + (uVar27 * -4 - iVar10));
  if (1 < (int)param_9) {
    iVar9 = local_28 * 4;
    local_8 = (float *)(param_9 - 1);
    piVar11 = (int *)((int)register0x00000010 + param_9 * -8 + -0x94);
    while( true ) {
      piVar19 = piVar11 + 1;
      *(int *)((int)&uStack_9c + (iVar8 - (int)piVar18) + (int)piVar19) =
           *(int *)((int)register0x00000010 + iVar8 + -0x98) + iVar9;
      *piVar11 = iVar9 + *piVar18;
      piVar19[-1 - param_9] = iVar9 + piVar18[-param_9];
      piVar19[param_9 * -2 + -1] = piVar18[param_9 * -2] + iVar9;
      iVar9 = iVar9 + local_28 * 4;
      local_8 = (float *)((int)local_8 + -1);
      if (local_8 == (float *)0x0) break;
      piVar11 = piVar19;
    }
  }
  iVar9 = 0;
  if (0 < (int)(*(int *)(param_4 + 0x484) + param_9)) {
    do {
      *piVar20 = 0;
      iVar9 = iVar9 + 1;
      piVar20 = piVar20 + 1;
    } while (iVar9 < (int)(*(int *)(param_4 + 0x484) + param_9));
  }
  local_40 = 0;
  if (0 < iVar31) {
    local_2c = 0;
    iVar9 = param_8 - iVar31;
    local_38 = iVar31;
    do {
      if (local_38 < local_28) {
        param_8 = local_38;
      }
      else {
        param_8 = local_28;
      }
      puVar28 = param_7;
      piVar20 = piVar18 + param_9 * -3;
      for (uVar21 = param_9 & 0x3fffffff; uVar21 != 0; uVar21 = uVar21 - 1) {
        *piVar20 = *puVar28;
        puVar28 = puVar28 + 1;
        piVar20 = piVar20 + 1;
      }
      for (iVar22 = 0; iVar22 != 0; iVar22 = iVar22 + -1) {
        *(undefined1 *)piVar20 = *(undefined1 *)puVar28;
        puVar28 = (undefined4 *)((int)puVar28 + 1);
        piVar20 = (undefined4 *)((int)piVar20 + 1);
      }
      local_3c = 0;
      puVar28 = (undefined4 *)piVar18[param_9 * -2];
      for (uVar21 = uVar27 & 0x3fffffff; uVar21 != 0; uVar21 = uVar21 - 1) {
        *puVar28 = 0;
        puVar28 = puVar28 + 1;
      }
      for (iVar22 = 0; iVar22 != 0; iVar22 = iVar22 + -1) {
        *(undefined1 *)puVar28 = 0;
        puVar28 = (undefined4 *)((int)puVar28 + 1);
      }
      if (0 < (int)param_9) {
        iVar22 = param_5 - (int)(piVar18 + -param_9);
        iVar26 = (int)register0x00000010 + (-0x98 - (int)piVar18);
        local_18 = param_9;
        local_3c = param_9;
        piVar20 = piVar18 + -param_9;
        do {
          piVar11 = (int *)((int)piVar20 + (int)piVar18 + iVar22 + (param_9 * -0xc - param_5));
          iVar23 = *(int *)((int)piVar11 + (param_6 - (int)(piVar18 + param_9 * -3))) + local_2c;
          if (*piVar11 == 0) {
            iVar12 = 0;
            if (0 < param_8) {
              do {
                iVar12 = iVar12 + 1;
                *(undefined4 *)(*piVar20 + -4 + iVar12 * 4) = 0x2edbe6ff;
                *(undefined4 *)(*(int *)(iVar26 + (int)piVar20) + -4 + iVar12 * 4) = 0;
                *(undefined4 *)(piVar20[param_9] + -4 + iVar12 * 4) = 0;
                *(undefined4 *)(piVar20[-param_9] + -4 + iVar12 * 4) = 0;
                *(undefined4 *)(iVar23 + -4 + iVar12 * 4) = 0;
              } while (iVar12 < param_8);
            }
            piVar20[param_9 * -2 - iVar10] = 0;
          }
          else {
            iVar12 = 0;
            if (0 < param_8) {
              do {
                iVar25 = iVar12 * 4;
                iVar12 = iVar12 + 1;
                *(undefined4 *)(*piVar20 + -4 + iVar12 * 4) =
                     *(undefined4 *)(&DAT_00a0ef68 + *(int *)(iVar23 + iVar25) * 4);
              } while (iVar12 < param_8);
            }
            iVar12 = piVar20[-param_9];
            iVar25 = *piVar20;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -1) - iVar10)] = param_8;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -2) - iVar10)] = local_40;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -3) - iVar10)] = iVar12;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -4) - iVar10)] = iVar25;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -5) - iVar10)] =
                 local_2c + *(int *)(iVar22 + (int)piVar20);
            piVar18[param_9 * -3 + ((uVar27 * -4 + -6) - iVar10)] = (int)local_68;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -7) - iVar10)] = (int)(float)dVar2;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -8) - iVar10)] = iVar4;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -9) - iVar10)] = 0x6af421;
            FUN_006af8b0();
            iVar12 = 0;
            if (0 < param_8) {
              iVar25 = local_2c;
              do {
                fVar1 = *(float *)(iVar25 + *(int *)(iVar22 + (int)piVar20));
                *(float *)(*(int *)(iVar26 + (int)piVar20) + iVar12 * 4) = fVar1 * fVar1;
                *(undefined4 *)(piVar20[param_9] + iVar12 * 4) =
                     *(undefined4 *)(*(int *)(iVar26 + (int)piVar20) + iVar12 * 4);
                if (*(float *)(iVar25 + *(int *)(iVar22 + (int)piVar20)) < _DAT_007d5344) {
                  *(float *)(*(int *)(iVar26 + (int)piVar20) + iVar12 * 4) =
                       *(float *)(*(int *)(iVar26 + (int)piVar20) + iVar12 * 4) * _DAT_007d5340;
                }
                iVar25 = iVar25 + 4;
                fVar1 = *(float *)(*piVar20 + iVar12 * 4);
                iVar13 = iVar12 * 4;
                iVar12 = iVar12 + 1;
                *(float *)(*piVar20 + iVar13) = fVar1 * fVar1;
              } while (iVar12 < param_8);
            }
            piVar18[param_9 * -3 + ((uVar27 * -4 + -1) - iVar10)] = iVar23;
            iVar23 = piVar20[param_9 * -2 - iVar10];
            iVar12 = *piVar20;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -2) - iVar10)] = param_8;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -3) - iVar10)] = local_40;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -4) - iVar10)] = iVar23;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -5) - iVar10)] = 0;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -6) - iVar10)] = iVar12;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -7) - iVar10)] = piVar20[param_9];
            piVar18[param_9 * -3 + ((uVar27 * -4 + -8) - iVar10)] =
                 *(undefined4 *)(iVar26 + (int)piVar20);
            piVar18[param_9 * -3 + ((uVar27 * -4 + -9) - iVar10)] = iVar4;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -10) - iVar10)] = (int)param_3;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -0xb) - iVar10)] = 0x6af4c7;
            fVar32 = (float10)FUN_006af920();
            piVar20[param_9 * -2 - iVar10] = (int)(float)fVar32;
          }
          piVar20 = piVar20 + 1;
          local_18 = local_18 - 1;
        } while (local_18 != 0);
      }
      local_34 = 0;
      if (0 < *(int *)(param_4 + 0x484)) {
        local_10 = (int *)(param_4 + 0x888);
        local_8 = (float *)(piVar18 + param_9 * -3 + (local_3c - iVar10));
        do {
          iVar22 = local_10[-0x100];
          iVar26 = *local_10;
          iVar29 = *(int *)(param_6 + iVar22 * 4) + local_2c;
          iVar23 = *(int *)(param_6 + iVar26 * 4);
          pfVar24 = *(float **)((int)register0x00000010 + iVar22 * 4 + iVar8 + -0x98);
          iVar12 = *(int *)((int)register0x00000010 + iVar26 * 4 + iVar8 + -0x98);
          iVar25 = piVar18[iVar22];
          iVar13 = piVar18[iVar26];
          iVar17 = piVar18[iVar22 - param_9];
          iVar16 = piVar18[iVar26 - param_9];
          iVar15 = piVar18[param_9 * -2 + iVar22];
          iVar14 = piVar18[param_9 * -2 + iVar26];
          if ((piVar18[param_9 * -3 + iVar22] != 0) || (piVar18[param_9 * -3 + iVar26] != 0)) {
            piVar18[param_9 * -3 + iVar26] = 1;
            piVar18[param_9 * -3 + iVar22] = 1;
            local_14 = 0;
            if (0 < param_8) {
              iVar12 = iVar12 - (int)pfVar24;
              iVar26 = (iVar23 + local_2c) - (int)pfVar24;
              iVar13 = iVar13 - (int)pfVar24;
              iVar23 = iVar29 - (int)pfVar24;
              iVar25 = iVar25 - (int)pfVar24;
              iVar14 = iVar14 - (int)pfVar24;
              iVar15 = iVar15 - (int)pfVar24;
              iVar16 = iVar16 - (int)pfVar24;
              iVar17 = iVar17 - (int)pfVar24;
              do {
                if (local_14 < iVar9 + local_38) {
                  if ((*(int *)(iVar15 + (int)pfVar24) == 0) &&
                     (*(int *)(iVar14 + (int)pfVar24) == 0)) {
                    fVar1 = *(float *)(iVar12 + (int)pfVar24) + *pfVar24;
                    if (local_14 < local_38 + (iVar4 - iVar31)) {
                      *pfVar24 = fVar1;
                      *(float *)(iVar25 + (int)pfVar24) = ABS(fVar1);
                    }
                    else {
                      bVar7 = fVar1 < _DAT_007d5344;
                      fVar1 = ABS(*pfVar24) + ABS(*(float *)(iVar12 + (int)pfVar24));
                      *(float *)(iVar25 + (int)pfVar24) = fVar1;
                      if (bVar7) {
                        fVar1 = -fVar1;
                      }
                      *pfVar24 = fVar1;
                    }
                    *(undefined4 *)(iVar13 + (int)pfVar24) = 0;
                    *(undefined4 *)(iVar12 + (int)pfVar24) = 0;
                    *(undefined4 *)(iVar14 + (int)pfVar24) = 1;
                    *(undefined4 *)(iVar26 + (int)pfVar24) = 0;
                  }
                  else {
                    *pfVar24 = ABS(*pfVar24) + ABS(*(float *)(iVar12 + (int)pfVar24));
                    *(float *)(iVar25 + (int)pfVar24) =
                         *(float *)(iVar13 + (int)pfVar24) + *(float *)(iVar25 + (int)pfVar24);
                    *(undefined4 *)(iVar14 + (int)pfVar24) = 1;
                    *(undefined4 *)(iVar15 + (int)pfVar24) = 1;
                    uVar21 = *(uint *)(iVar26 + (int)pfVar24);
                    uVar5 = *(uint *)(iVar23 + (int)pfVar24);
                    if ((int)((uVar21 ^ (int)uVar21 >> 0x1f) - ((int)uVar21 >> 0x1f)) <
                        (int)((uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f))) {
                      if ((int)uVar5 < 1) {
                        *(uint *)(iVar26 + (int)pfVar24) = uVar21 - uVar5;
                      }
                      else {
                        *(uint *)(iVar26 + (int)pfVar24) = uVar5 - uVar21;
                      }
                    }
                    else {
                      if ((int)uVar21 < 1) {
                        iVar30 = uVar21 - uVar5;
                      }
                      else {
                        iVar30 = uVar5 - uVar21;
                      }
                      *(int *)(iVar26 + (int)pfVar24) = iVar30;
                      *(uint *)(iVar23 + (int)pfVar24) = uVar21;
                    }
                    uVar21 = (int)*(uint *)(iVar23 + (int)pfVar24) >> 0x1f;
                    if ((int)(((*(uint *)(iVar23 + (int)pfVar24) ^ uVar21) - uVar21) * 2) <=
                        *(int *)(iVar26 + (int)pfVar24)) {
                      *(int *)(iVar26 + (int)pfVar24) = -*(int *)(iVar26 + (int)pfVar24);
                      *(int *)(iVar23 + (int)pfVar24) = -*(int *)(iVar23 + (int)pfVar24);
                    }
                  }
                }
                fVar1 = *(float *)(iVar16 + (int)pfVar24) + *(float *)(iVar17 + (int)pfVar24);
                pfVar24 = pfVar24 + 1;
                *(float *)(iVar16 + -4 + (int)pfVar24) = fVar1;
                *(float *)(iVar17 + -4 + (int)pfVar24) = fVar1;
                local_14 = local_14 + 1;
              } while (local_14 < param_8);
            }
            piVar18[param_9 * -3 + ((uVar27 * -4 + -1) - iVar10)] = iVar29;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -2) - iVar10)] = param_8;
            fVar1 = *local_8;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -3) - iVar10)] = local_40;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -4) - iVar10)] = (int)fVar1;
            iVar26 = piVar18[iVar22 - param_9];
            piVar18[param_9 * -3 + ((uVar27 * -4 + -5) - iVar10)] = piVar18[param_9 * -2 + iVar22];
            piVar18[param_9 * -3 + ((uVar27 * -4 + -6) - iVar10)] = iVar26;
            uVar6 = *(undefined4 *)((int)register0x00000010 + iVar22 * 4 + iVar8 + -0x98);
            piVar18[param_9 * -3 + ((uVar27 * -4 + -7) - iVar10)] = piVar18[iVar22];
            piVar18[param_9 * -3 + ((uVar27 * -4 + -8) - iVar10)] = uVar6;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -9) - iVar10)] = iVar4;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -10) - iVar10)] = (int)param_3;
            piVar18[param_9 * -3 + ((uVar27 * -4 + -0xb) - iVar10)] = 0x6af7ec;
            fVar32 = (float10)FUN_006af920();
            *local_8 = (float)fVar32;
            local_8 = local_8 + 1;
          }
          local_34 = local_34 + 1;
          local_10 = local_10 + 1;
        } while (local_34 < *(int *)(param_4 + 0x484));
      }
      local_40 = local_40 + local_28;
      local_2c = local_2c + local_28 * 4;
      local_38 = local_38 - local_28;
    } while (local_40 < iVar31);
  }
  iVar31 = 0;
  if (0 < *(int *)(param_4 + 0x484)) {
    piVar18 = (int *)(param_4 + 0x888);
    do {
      if ((param_7[piVar18[-0x100]] != 0) || (param_7[*piVar18] != 0)) {
        param_7[piVar18[-0x100]] = 1;
        param_7[*piVar18] = 1;
      }
      iVar31 = iVar31 + 1;
      piVar18 = piVar18 + 1;
    } while (iVar31 < *(int *)(param_4 + 0x484));
  }
  return;
}

