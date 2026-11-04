
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00517880(uint param_1,int param_2,int param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined *puVar13;
  int local_118;
  int local_10c;
  char acStack_100 [256];
  
  if (param_3 == 0) {
    if (DAT_00cc47d0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_1 < 0) {
      return 0xffffffff;
    }
    if ((param_1 & 0x7c000000) != DAT_00cc47f8) {
      return 0xffffffff;
    }
    if (DAT_00cc4800 <= (int)(param_1 & 0xffff)) {
      return 0xffffffff;
    }
    piVar8 = *(int **)(DAT_00cc47d4 + (param_1 & 0xffff) * 4);
    if (piVar8 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar8 * 0x10000 != (param_1 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar8[4] != 0) {
      return 0xffffffff;
    }
  }
  else if (((((DAT_00cc47d0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc47f8)
            ) || ((DAT_00cc4800 <= (int)(param_1 & 0xffff) ||
                  (piVar8 = *(int **)(DAT_00cc47d4 + (param_1 & 0xffff) * 4), piVar8 == (int *)0x0))
                 )) || (*piVar8 * 0x10000 != (param_1 & 0x3ff0000))) {
    return 0xffffffff;
  }
  local_10c = piVar8[0x13];
  iVar12 = piVar8[1];
  if (*(char *)(local_10c + 8) == '\0') {
    FUN_00581340(piVar8 + 0x22,local_10c + 0x34,piVar8[0x14],piVar8[0x15],piVar8[0x18],piVar8[0x19])
    ;
    return 0;
  }
  iVar7 = *(int *)(local_10c + 0x38);
  iVar11 = 0;
  iVar10 = 0;
  if (0 < iVar7) {
    piVar9 = (int *)(local_10c + 0x40);
    do {
      if (param_2 == 0) {
        iVar2 = *piVar9;
        iVar3 = piVar8[0x14];
        if (iVar3 < iVar2) {
LAB_00517aa0:
          if (piVar8[0x18] + iVar3 <= iVar2) goto LAB_005179d6;
        }
        else if (piVar9[2] + iVar2 <= iVar3) {
          if (iVar2 < iVar3) goto LAB_005179d6;
          goto LAB_00517aa0;
        }
        iVar2 = piVar9[1];
        iVar3 = piVar8[0x15];
        if (iVar3 < iVar2) {
LAB_00517ac8:
          if (piVar8[0x19] + iVar3 <= iVar2) goto LAB_005179d6;
        }
        else if (piVar9[3] + iVar2 <= iVar3) {
          if (iVar2 < iVar3) goto LAB_005179d6;
          goto LAB_00517ac8;
        }
        iVar11 = iVar11 + 1;
        acStack_100[iVar10] = '\x01';
      }
      else {
        fVar4 = (float)*piVar9;
        if (((fVar4 <= (float)piVar8[0x16]) && ((float)piVar8[0x16] < (float)(piVar9[2] + *piVar9)))
           || ((fVar1 = (float)piVar8[0x16],
               (!NAN(fVar1) && !NAN(fVar4)) && fVar1 < fVar4 != (fVar1 == fVar4) &&
               (fVar4 < (float)piVar8[0x1a] + (float)piVar8[0x16])))) {
          fVar4 = (float)piVar9[1];
          if (((float)piVar8[0x17] < fVar4) ||
             ((float)(piVar9[3] + piVar9[1]) <= (float)piVar8[0x17])) {
            fVar1 = (float)piVar8[0x17];
            if (((NAN(fVar1) || NAN(fVar4)) || fVar1 < fVar4 == (fVar1 == fVar4)) ||
               ((float)piVar8[0x1b] + (float)piVar8[0x17] <= fVar4)) goto LAB_005179d6;
            iVar11 = iVar11 + 1;
            acStack_100[iVar10] = '\x01';
          }
          else {
            iVar11 = iVar11 + 1;
            acStack_100[iVar10] = '\x01';
          }
        }
        else {
LAB_005179d6:
          acStack_100[iVar10] = '\0';
        }
      }
      iVar10 = iVar10 + 1;
      piVar9 = piVar9 + 7;
    } while (iVar10 < iVar7);
    if (iVar11 != 0) {
      if (iVar11 < 5) {
LAB_00517b2c:
        fVar4 = (float)piVar8[0x1b] / (float)piVar8[0x1a];
        piVar8[0x22] = iVar11;
        iVar12 = local_10c + 0x3c;
        piVar9 = piVar8 + 0x23;
        local_118 = 0;
        if (*(int *)(local_10c + 0x38) < 1) {
          return 0;
        }
        do {
          if (acStack_100[local_118] != '\0') {
            piVar9[0x1d] = iVar12;
            if (param_2 == 0) {
              if (piVar8[0x14] < *(int *)(iVar12 + 4)) {
                *piVar9 = *(int *)(iVar12 + 4) - piVar8[0x14];
                piVar9[4] = 0;
                if (piVar8[0x14] + piVar8[0x18] < *(int *)(iVar12 + 4) + *(int *)(iVar12 + 0xc)) {
                  piVar9[8] = (piVar8[0x18] - *(int *)(iVar12 + 4)) + piVar8[0x14];
                }
                else {
                  piVar9[8] = *(int *)(iVar12 + 0xc);
                }
              }
              else {
                *piVar9 = 0;
                piVar9[4] = piVar8[0x14] - *(int *)(iVar12 + 4);
                if (piVar8[0x18] + piVar8[0x14] < *(int *)(iVar12 + 4) + *(int *)(iVar12 + 0xc)) {
                  piVar9[8] = piVar8[0x18];
                }
                else {
                  piVar9[8] = (*(int *)(iVar12 + 4) - piVar8[0x14]) + *(int *)(iVar12 + 0xc);
                }
              }
              if (piVar8[0x15] < *(int *)(iVar12 + 8)) {
                piVar9[1] = *(int *)(iVar12 + 8) - piVar8[0x15];
                piVar9[5] = 0;
                if (piVar8[0x15] + piVar8[0x19] < *(int *)(iVar12 + 8) + *(int *)(iVar12 + 0x10)) {
                  piVar9[9] = (piVar8[0x19] - *(int *)(iVar12 + 8)) + piVar8[0x15];
                }
                else {
                  piVar9[9] = *(int *)(iVar12 + 0x10);
                }
              }
              else {
                piVar9[1] = 0;
                piVar9[5] = piVar8[0x15] - *(int *)(iVar12 + 8);
                if (piVar8[0x19] + piVar8[0x15] < *(int *)(iVar12 + 8) + *(int *)(iVar12 + 0x10)) {
                  piVar9[9] = piVar8[0x19];
                }
                else {
                  piVar9[9] = (*(int *)(iVar12 + 8) - piVar8[0x15]) + *(int *)(iVar12 + 0x10);
                }
              }
              piVar9[2] = (int)(float)*piVar9;
              piVar9[3] = (int)(float)piVar9[1];
              piVar9[6] = (int)(float)piVar9[4];
              piVar9[7] = (int)(float)piVar9[5];
              piVar9[10] = (int)(float)piVar9[8];
              piVar9[0xb] = (int)(float)piVar9[9];
            }
            else {
              if ((float)*(int *)(iVar12 + 4) <= (float)piVar8[0x16]) {
                piVar9[2] = 0;
                piVar9[6] = (int)((float)piVar8[0x16] - (float)*(int *)(iVar12 + 4));
                if ((float)(*(int *)(iVar12 + 4) + *(int *)(iVar12 + 0xc)) <=
                    (float)piVar8[0x1a] + (float)piVar8[0x16]) {
                  fVar1 = (float)(*(int *)(iVar12 + 4) + *(int *)(iVar12 + 0xc)) -
                          (float)piVar8[0x16];
                }
                else {
                  fVar1 = (float)piVar8[0x1a];
                }
              }
              else {
                piVar9[2] = (int)((float)*(int *)(iVar12 + 4) - (float)piVar8[0x16]);
                piVar9[6] = 0;
                if ((float)(*(int *)(iVar12 + 4) + *(int *)(iVar12 + 0xc)) <=
                    (float)piVar8[0x1a] + (float)piVar8[0x16]) {
                  fVar1 = (float)*(int *)(iVar12 + 0xc);
                }
                else {
                  fVar1 = ((float)piVar8[0x1a] + (float)piVar8[0x16]) - (float)*(int *)(iVar12 + 4);
                }
              }
              piVar9[10] = (int)fVar1;
              if ((float)*(int *)(iVar12 + 8) <= (float)piVar8[0x17]) {
                piVar9[3] = 0;
                piVar9[7] = (int)((float)piVar8[0x17] - (float)*(int *)(iVar12 + 8));
                if ((float)(*(int *)(iVar12 + 8) + *(int *)(iVar12 + 0x10)) <=
                    (float)piVar8[0x1b] + (float)piVar8[0x17]) {
                  fVar1 = (float)(*(int *)(iVar12 + 8) + *(int *)(iVar12 + 0x10)) -
                          (float)piVar8[0x17];
                }
                else {
                  fVar1 = (float)piVar8[0x1b];
                }
              }
              else {
                piVar9[3] = (int)((float)*(int *)(iVar12 + 8) - (float)piVar8[0x17]);
                piVar9[7] = 0;
                if ((float)(*(int *)(iVar12 + 8) + *(int *)(iVar12 + 0x10)) <=
                    (float)piVar8[0x1b] + (float)piVar8[0x17]) {
                  fVar1 = (float)*(int *)(iVar12 + 0x10);
                }
                else {
                  fVar1 = ((float)piVar8[0x1b] + (float)piVar8[0x17]) - (float)*(int *)(iVar12 + 8);
                }
              }
              piVar9[0xb] = (int)fVar1;
              iVar7 = FUN_0050e270(piVar9[2]);
              *piVar9 = iVar7;
              iVar7 = FUN_0050e270(piVar9[3]);
              piVar9[1] = iVar7;
              iVar7 = FUN_0050e270(piVar9[6]);
              piVar9[4] = iVar7;
              iVar7 = FUN_0050e270(piVar9[7]);
              piVar9[5] = iVar7;
              fVar1 = ((float)piVar9[10] + (float)piVar9[6]) - (float)piVar9[4];
              fVar5 = ((float)piVar9[0xb] + (float)piVar9[7]) - (float)iVar7;
              iVar7 = FUN_0050e270(fVar1);
              piVar9[8] = iVar7;
              iVar7 = FUN_0050e270(fVar5);
              piVar9[9] = iVar7;
              fVar6 = (float)_DAT_007d5380;
              if (fVar6 < fVar1 - (float)piVar9[8]) {
                iVar10 = piVar9[8] + 1;
                piVar9[8] = iVar10;
                if (*(int *)(iVar12 + 0xc) < iVar10 + piVar9[4]) {
                  piVar9[8] = (*(int *)(iVar12 + 0xc) - iVar10) - piVar9[4];
                }
              }
              if (fVar6 < fVar5 - (float)iVar7) {
                iVar7 = iVar7 + 1;
                piVar9[9] = iVar7;
                if (*(int *)(iVar12 + 0x10) < iVar7 + piVar9[5]) {
                  piVar9[9] = (*(int *)(iVar12 + 0x10) - iVar7) - piVar9[5];
                }
              }
            }
            piVar9[0xc] = piVar9[2];
            fVar1 = (float)piVar9[2] + (float)piVar9[10];
            piVar9[0x10] = (int)fVar1;
            piVar9[0x14] = piVar9[2];
            piVar9[0x18] = (int)fVar1;
            piVar9[0xd] = piVar9[3];
            piVar9[0x11] = piVar9[3];
            fVar5 = (float)piVar9[3] + (float)piVar9[0xb];
            piVar9[0x15] = (int)fVar5;
            piVar9[0x19] = (int)fVar5;
            piVar9[0xe] = (int)((float)piVar9[6] / (float)*(int *)(iVar12 + 0x14));
            piVar9[0x12] = (int)(((float)piVar9[10] + (float)piVar9[6]) /
                                (float)*(int *)(iVar12 + 0x14));
            piVar9[0x16] = (int)((float)piVar9[6] / (float)*(int *)(iVar12 + 0x14));
            piVar9[0x1a] = (int)(((float)piVar9[10] + (float)piVar9[6]) /
                                (float)*(int *)(iVar12 + 0x14));
            piVar9[0xf] = (int)((float)piVar9[7] / (float)*(int *)(iVar12 + 0x18));
            piVar9[0x13] = (int)((float)piVar9[7] / (float)*(int *)(iVar12 + 0x18));
            piVar9[0x17] = (int)(((float)piVar9[0xb] + (float)piVar9[7]) /
                                (float)*(int *)(iVar12 + 0x18));
            piVar9[0x1b] = (int)(((float)piVar9[0xb] + (float)piVar9[7]) /
                                (float)*(int *)(iVar12 + 0x18));
            *(bool *)(piVar9 + 0x1c) =
                 (float)piVar9[0xd] <= (float)piVar8[0x1b] - (float)piVar9[0xc] * fVar4;
            *(bool *)((int)piVar9 + 0x71) =
                 (float)piVar9[0x11] <= (float)piVar8[0x1b] - fVar4 * fVar1;
            *(bool *)((int)piVar9 + 0x72) =
                 fVar5 <= (float)piVar8[0x1b] - (float)piVar9[0x14] * fVar4;
            fVar1 = (float)piVar8[0x1b] - fVar4 * fVar1;
            *(bool *)((int)piVar9 + 0x73) =
                 (!NAN(fVar5) && !NAN(fVar1)) && fVar5 < fVar1 != (fVar5 == fVar1);
            piVar9 = piVar9 + 0x1e;
          }
          local_118 = local_118 + 1;
          iVar12 = iVar12 + 0x1c;
        } while (local_118 < *(int *)(local_10c + 0x38));
        return 0;
      }
      iVar7 = FUN_00580da0(iVar12,(iVar11 + -4) * 0x78 + 0x26c);
      if (-1 < iVar7) {
        piVar8 = (int *)FUN_00580500(iVar12);
        local_10c = piVar8[0x13];
        goto LAB_00517b2c;
      }
      puVar13 = &DAT_007d5388;
      goto LAB_005179f4;
    }
  }
  puVar13 = &DAT_007d53b8;
LAB_005179f4:
  FUN_0056bb10(puVar13);
  return 0xffffffff;
}

