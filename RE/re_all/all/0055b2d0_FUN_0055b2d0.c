
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0055b2d0(uint param_1,uint param_2)

{
  short sVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  undefined2 *puVar8;
  undefined1 *puVar9;
  
  if (((DAT_00cc50a0 != 0) && (-1 < (int)param_1)) && ((param_1 & 0x7c000000) == DAT_00cc50c8)) {
    if ((int)(param_1 & 0xffff) < DAT_00cc50d0) {
      piVar2 = *(int **)(DAT_00cc50a4 + (param_1 & 0xffff) * 4);
      if ((piVar2 != (int *)0x0) && (*piVar2 * 0x10000 == (param_1 & 0x3ff0000))) {
        if (((((piVar2[0xc] == 1) || ((int)param_2 < 0)) ||
             (((param_2 & 0x7c000000) != DAT_00cc50c8 ||
              ((((DAT_00cc50d0 <= (int)(param_2 & 0xffff) ||
                 (piVar3 = *(int **)(DAT_00cc50a4 + (param_2 & 0xffff) * 4), piVar3 == (int *)0x0))
                || (*piVar3 * 0x10000 != (param_2 & 0x3ff0000))) ||
               ((piVar3[0xc] == 1 || (iVar6 = piVar2[0x12], iVar6 != piVar3[0x12])))))))) ||
            (sVar1 = *(short *)((int)piVar2 + 0x36), sVar1 != *(short *)((int)piVar3 + 0x36))) ||
           (((short)piVar2[0xd] == 1 || ((short)piVar3[0xd] != 1)))) {
          return 0xffffffff;
        }
        pfVar5 = (float *)piVar2[0x13];
        if (*(short *)((int)piVar3 + 0x42) == 8) {
          puVar9 = (undefined1 *)piVar3[0x13];
          if (sVar1 == 1) {
            iVar7 = 0;
            if (0 < iVar6) {
              do {
                iVar4 = FUN_0050e270(pfVar5[iVar7] * (float)_DAT_007d62a8 + (float)_DAT_007d1b70);
                if (iVar4 < 0x100) {
                  if (iVar4 < 0) {
                    iVar4 = 0;
                  }
                }
                else {
                  iVar4 = 0xff;
                }
                puVar9[iVar7] = (char)iVar4;
                iVar7 = iVar7 + 1;
              } while (iVar7 < iVar6);
              return 0;
            }
          }
          else if (0 < iVar6) {
            do {
              iVar7 = FUN_0050e270(*pfVar5 * (float)_DAT_007d62a8 + (float)_DAT_007d1b70);
              if (iVar7 < 0x100) {
                if (iVar7 < 0) {
                  iVar7 = 0;
                }
              }
              else {
                iVar7 = 0xff;
              }
              *puVar9 = (char)iVar7;
              iVar7 = FUN_0050e270(pfVar5[1] * (float)_DAT_007d62a8 + (float)_DAT_007d1b70);
              if (iVar7 < 0x100) {
                if (iVar7 < 0) {
                  iVar7 = 0;
                }
              }
              else {
                iVar7 = 0xff;
              }
              puVar9[1] = (char)iVar7;
              pfVar5 = pfVar5 + 2;
              puVar9 = puVar9 + 2;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
        }
        else if (*(short *)((int)piVar3 + 0x42) == 0x10) {
          puVar8 = (undefined2 *)piVar3[0x13];
          if (sVar1 == 1) {
            iVar7 = 0;
            if (0 < iVar6) {
              do {
                iVar4 = FUN_0050e270(pfVar5[iVar7] * (float)_DAT_00805408);
                if (iVar4 < 0x8000) {
                  if (iVar4 < -0x8000) {
                    iVar4 = -0x8000;
                  }
                }
                else {
                  iVar4 = 0x7fff;
                }
                puVar8[iVar7] = (short)iVar4;
                iVar7 = iVar7 + 1;
              } while (iVar7 < iVar6);
              return 0;
            }
          }
          else if (0 < iVar6) {
            do {
              iVar7 = FUN_0050e270(*pfVar5 * (float)_DAT_00805408);
              if (iVar7 < 0x8000) {
                if (iVar7 < -0x8000) {
                  iVar7 = -0x8000;
                }
              }
              else {
                iVar7 = 0x7fff;
              }
              *puVar8 = (short)iVar7;
              iVar7 = FUN_0050e270(pfVar5[1] * (float)_DAT_00805408);
              if (iVar7 < 0x8000) {
                if (iVar7 < -0x8000) {
                  iVar7 = -0x8000;
                }
              }
              else {
                iVar7 = 0x7fff;
              }
              puVar8[1] = (short)iVar7;
              pfVar5 = pfVar5 + 2;
              puVar8 = puVar8 + 2;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            return 0;
          }
        }
        return 0;
      }
    }
  }
  return 0xffffffff;
}

