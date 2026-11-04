
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005fb220(int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  uint uStack_38;
  uint uStack_34;
  undefined1 *puStack_30;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  uint uStack_18;
  uint uStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  FUN_0056da60(param_1,s_D__DxLib_Develop_Source_Library__00a05f80,0xfff);
  if (*(int *)(param_1 + 0x228) == 1) {
    *(undefined4 *)(param_1 + 0x220) = 3;
    FUN_0056dac0(param_1);
    return 2;
  }
  if (*(int *)(param_1 + 0x224) == 1) {
    *(undefined4 *)(param_1 + 0x220) = 4;
    FUN_0056dac0(param_1);
    FUN_0056da20(1);
    return 0;
  }
  if (*(int *)(param_1 + 0x22c) != 1) {
    if (*(int *)(param_1 + 0x230) == 0) {
      FUN_0056dac0(param_1);
      if (*(int *)(param_1 + 0x220) == 0) {
        FUN_0056da20(1);
        return 0;
      }
    }
    else {
      if (*(int *)(param_1 + 0x238) == 0) {
        piVar2 = *(int **)(param_1 + 0x4e4);
        iVar9 = 0;
        if (0 < *(int *)(param_1 + 0x4e8)) {
          do {
            if (*piVar2 != 0) {
              uVar4 = *(int *)(param_1 + 0x4d8) + *(int *)(param_1 + 0x4e8);
              iVar10 = (int)uVar4 >> 0x1f;
              if (piVar2[1] < *(int *)(param_1 + 0x4d8)) {
                iVar3 = *(int *)(param_1 + 0x4cc);
                uVar1 = *(uint *)(param_1 + 0x4c8);
                if ((iVar3 <= iVar10) && ((iVar3 < iVar10 || (uVar1 <= uVar4)))) {
                  iVar10 = (iVar10 - iVar3) - (uint)(uVar4 < uVar1);
                  iVar3 = piVar2[1] >> 0x1f;
                  if ((iVar3 < iVar10) || ((iVar3 <= iVar10 && ((uint)piVar2[1] <= uVar4 - uVar1))))
                  goto LAB_005fb4cf;
                }
              }
              else if ((piVar2[1] <= *(int *)(param_1 + 0x4dc)) ||
                      (piVar2[1] <= *(int *)(param_1 + 0x4d8) + *(int *)(param_1 + 0x4e8)))
              goto LAB_005fb4cf;
              *piVar2 = 0;
            }
LAB_005fb4cf:
            iVar9 = iVar9 + 1;
            piVar2 = piVar2 + 10;
          } while (iVar9 < *(int *)(param_1 + 0x4e8));
        }
      }
      piVar2 = *(int **)(param_1 + 0x4e4);
      iVar9 = 0;
      if (0 < *(int *)(param_1 + 0x4e8)) {
        do {
          iVar9 = iVar9 + 1;
        } while (iVar9 < *(int *)(param_1 + 0x4e8));
      }
      iVar9 = 0;
      piVar6 = piVar2;
      if (0 < *(int *)(param_1 + 0x4e8)) {
        do {
          if (*piVar6 == 0) break;
          iVar9 = iVar9 + 1;
          piVar6 = piVar6 + 10;
        } while (iVar9 < *(int *)(param_1 + 0x4e8));
      }
      if (*(int *)(param_1 + 0x4e8) == iVar9) {
        iVar9 = 0;
        piVar6 = piVar2;
        if (0 < *(int *)(param_1 + 0x4e8)) {
          do {
            if ((*piVar6 != 0) && (piVar6[1] == *(int *)(param_1 + 0x4d8))) break;
            iVar9 = iVar9 + 1;
            piVar6 = piVar6 + 10;
          } while (iVar9 < *(int *)(param_1 + 0x4e8));
        }
        if (*(int *)(param_1 + 0x4e8) == iVar9) {
          iVar9 = 0;
          if (0 < *(int *)(param_1 + 0x4e8)) {
            do {
              if (*piVar2 != 0) {
                *piVar2 = 0;
              }
              iVar9 = iVar9 + 1;
              piVar2 = piVar2 + 10;
            } while (iVar9 < *(int *)(param_1 + 0x4e8));
          }
        }
        else if (*(int *)(param_1 + 0x220) != 0) {
          *(undefined4 *)(param_1 + 0x220) = 0;
          uVar5 = FUN_00550060(0);
          *(undefined4 *)(param_1 + 0x23c) = uVar5;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x220) = 1;
        iVar9 = 0;
        piVar6 = piVar2;
        if (0 < *(int *)(param_1 + 0x4e8)) {
          do {
            if ((*piVar6 != 0) && (piVar6[1] == *(int *)(param_1 + 0x4dc))) break;
            iVar9 = iVar9 + 1;
            piVar6 = piVar6 + 10;
          } while (iVar9 < *(int *)(param_1 + 0x4e8));
        }
        iVar10 = 0;
        piVar6 = piVar2;
        if (0 < *(int *)(param_1 + 0x4e8)) {
          do {
            if ((*piVar6 != 0) && (piVar6[1] == *(int *)(param_1 + 0x4d8))) break;
            iVar10 = iVar10 + 1;
            piVar6 = piVar6 + 10;
          } while (iVar10 < *(int *)(param_1 + 0x4e8));
        }
        iVar3 = 0;
        if (0 < *(int *)(param_1 + 0x4e8)) {
          do {
            if (*piVar2 == 0) break;
            iVar3 = iVar3 + 1;
            piVar2 = piVar2 + 10;
          } while (iVar3 < *(int *)(param_1 + 0x4e8));
        }
        if (iVar3 != *(int *)(param_1 + 0x4e8)) {
          if ((iVar9 != *(int *)(param_1 + 0x4e8)) ||
             (*(int *)(param_1 + 0x4dc) < *(int *)(param_1 + 0x4d8))) {
            if ((iVar10 != *(int *)(param_1 + 0x4e8)) ||
               ((*(int *)(param_1 + 0x4d8) <= *(int *)(param_1 + 0x4dc) ||
                (iVar9 = *(int *)(param_1 + 0x4d8) - *(int *)(param_1 + 0x4dc), iVar9 < 0)))) {
              iVar9 = 1;
            }
            uVar4 = *(int *)(param_1 + 0x4dc) + iVar9;
            iVar10 = (int)uVar4 >> 0x1f;
            if ((iVar10 < *(int *)(param_1 + 0x4cc)) ||
               ((iVar10 <= *(int *)(param_1 + 0x4cc) && (uVar4 < *(uint *)(param_1 + 0x4c8))))) {
              FUN_0056dac0(param_1);
              iVar9 = FUN_005fbab0(param_1,iVar9);
              FUN_0056da60(param_1,s_D__DxLib_Develop_Source_Library__00a05f80,0x1116);
              if (iVar9 == -1) {
                *(undefined4 *)(param_1 + 0x238) = 1;
                FUN_0056dac0(param_1);
                FUN_0056da20(1);
                return 0;
              }
            }
            else {
              FUN_0056dac0(param_1);
              iVar9 = iVar9 + (*(int *)(param_1 + 0x4dc) - *(int *)(param_1 + 0x4c8));
              FUN_006a8cd0(param_1 + 0x26c);
              FUN_006a8d00(param_1 + 0x298);
              (**(code **)(param_1 + 0x254))
                        (*(undefined4 *)(param_1 + 0x268),**(int **)(param_1 + 0x4b4),
                         **(int **)(param_1 + 0x4b4) >> 0x1f,0);
              *(undefined4 *)(param_1 + 0x4dc) = 0;
              if (iVar9 != 0) {
                FUN_005fbab0(param_1,iVar9);
              }
              FUN_0056da60(param_1,s_D__DxLib_Develop_Source_Library__00a05f80,0x1109);
            }
          }
          if (iVar3 != *(int *)(param_1 + 0x4e8)) {
            FUN_0056dac0(param_1);
            FUN_006b8d30(param_1 + 0x498,&iStack_24);
            if ((((piVar2[6] != iStack_1c) || (piVar2[4] != iStack_24)) || (piVar2[5] != iStack_20))
               && (piVar2[2] != 0)) {
              FUN_0056e1d0(piVar2[2]);
              piVar2[2] = 0;
            }
            if ((((piVar2[9] != iStack_10 * 2) || (piVar2[7] != uStack_18)) ||
                (piVar2[8] != uStack_14)) && (piVar2[3] != 0)) {
              FUN_0056e1d0(piVar2[3]);
              piVar2[3] = 0;
            }
            piVar2[6] = iStack_1c;
            piVar2[4] = iStack_24;
            piVar2[5] = iStack_20;
            piVar2[9] = iStack_10 * 2;
            piVar2[7] = uStack_18;
            piVar2[8] = uStack_14;
            if (piVar2[2] == 0) {
              iVar9 = FUN_0056e030(piVar2[6] * piVar2[5],s_D__DxLib_Develop_Source_Library__00a05f80
                                   ,0x1161);
              piVar2[2] = iVar9;
              if (piVar2[2] == 0) {
                _DAT_00000000 = 0xffffffff;
              }
            }
            if (piVar2[3] == 0) {
              iVar9 = FUN_0056e030(piVar2[9] * piVar2[8],s_D__DxLib_Develop_Source_Library__00a05f80
                                   ,0x1169);
              piVar2[3] = iVar9;
              if (piVar2[3] == 0) {
                _DAT_00000000 = 0xffffffff;
              }
            }
            FUN_0056d420(piVar2[2],uStack_c,iStack_20 * iStack_1c);
            iVar9 = (int)(uStack_18 + ((int)uStack_18 >> 0x1f & 7U)) >> 3;
            uStack_18 = uStack_18 & 0x80000007;
            if ((int)uStack_18 < 0) {
              uStack_18 = (uStack_18 - 1 | 0xfffffff8) + 1;
            }
            puStack_30 = (undefined1 *)piVar2[3];
            uStack_34 = 0;
            if (uStack_14 != 0) {
              do {
                puVar7 = puStack_30;
                puVar8 = puStack_4;
                puVar12 = puStack_8;
                if (iVar9 != 0) {
                  puVar11 = puStack_8;
                  uStack_38 = iVar9;
                  do {
                    puVar12 = puVar11 + 8;
                    *puVar7 = *puVar11;
                    puVar7[1] = *puVar8;
                    puVar7[2] = puVar8[(int)(puStack_8 + (1 - (int)puStack_4))];
                    puVar7[3] = puVar8[1];
                    puVar7[4] = puVar11[2];
                    puVar7[5] = puVar8[2];
                    puVar7[6] = puVar11[3];
                    puVar7[7] = puVar8[3];
                    puVar7[8] = puVar11[4];
                    puVar7[9] = puVar8[4];
                    puVar7[10] = puVar11[5];
                    puVar7[0xb] = puVar8[5];
                    puVar7[0xc] = puVar11[6];
                    puVar7[0xd] = puVar8[6];
                    puVar7[0xe] = puVar11[7];
                    puVar7[0xf] = puVar8[7];
                    puVar7 = puVar7 + 0x10;
                    puVar8 = puVar8 + 8;
                    uStack_38 = uStack_38 + -1;
                    puVar11 = puVar12;
                  } while (uStack_38 != 0);
                }
                if (uStack_18 != 0) {
                  uStack_38 = uStack_18;
                  do {
                    *puVar7 = *puVar12;
                    puVar7[1] = *puVar8;
                    puVar7 = puVar7 + 2;
                    puVar12 = puVar12 + 1;
                    puVar8 = puVar8 + 1;
                    uStack_38 = uStack_38 - 1;
                  } while (uStack_38 != 0);
                }
                uStack_34 = uStack_34 + 1;
                puStack_30 = puStack_30 + piVar2[9];
                puStack_8 = puStack_8 + iStack_10;
                puStack_4 = puStack_4 + iStack_10;
              } while (uStack_34 < uStack_14);
            }
            FUN_0056da60(param_1,s_D__DxLib_Develop_Source_Library__00a05f80,0x119b);
            *piVar2 = 1;
            piVar2[1] = *(int *)(param_1 + 0x4dc);
          }
        }
      }
      FUN_0056dac0(param_1);
      if (*(int *)(param_1 + 0x220) == 0) {
        FUN_0056da20(1);
        return 0;
      }
    }
    FUN_0056da20(0);
    return 0;
  }
  *(undefined4 *)(param_1 + 0x220) = 2;
  FUN_0056dac0(param_1);
  iVar9 = *(int *)(param_1 + 0x4b8);
  iVar10 = 0;
  if (0 < iVar9) {
    piVar2 = (int *)(*(int *)(param_1 + 0x4b4) + 4);
    do {
      if (*(int *)(param_1 + 0x234) < piVar2[2] + *piVar2) break;
      iVar10 = iVar10 + 1;
      piVar2 = piVar2 + 4;
    } while (iVar10 < iVar9);
  }
  if (iVar10 == iVar9) {
    return 0xffffffff;
  }
  if (iVar10 != 0) {
    iVar10 = iVar10 + -1;
    if (0 < iVar10) {
      piVar2 = (int *)(*(int *)(param_1 + 0x4b4) + 8 + iVar10 * 0x10);
      do {
        if (*piVar2 != 0) break;
        iVar10 = iVar10 + -1;
        piVar2 = piVar2 + -4;
      } while (0 < iVar10);
    }
    if (iVar10 != 0) {
      iVar10 = iVar10 + -1;
    }
  }
  FUN_006a8cd0(param_1 + 0x26c);
  FUN_006a8d00(param_1 + 0x298);
  iVar9 = *(int *)(*(int *)(param_1 + 0x4b4) + iVar10 * 0x10);
  (**(code **)(param_1 + 0x254))(*(undefined4 *)(param_1 + 0x268),iVar9,iVar9 >> 0x1f,0);
  iVar9 = *(int *)(*(int *)(param_1 + 0x4b4) + 4 + iVar10 * 0x10);
  if (iVar10 != 0) {
    iVar10 = param_1 + 0x288;
    do {
      FUN_005fad70(param_1,0x1000);
      iVar3 = FUN_006a8940(param_1 + 0x26c,iVar10);
    } while (iVar3 != 1);
    iVar3 = FUN_006a8250(iVar10);
    if (iVar3 != 0) {
      iVar9 = iVar9 + 1;
    }
    FUN_006a89a0(param_1 + 0x298,iVar10);
  }
  FUN_005fbab0(param_1,(1 - iVar9) + *(int *)(param_1 + 0x234));
  FUN_0056da60(param_1,s_D__DxLib_Develop_Source_Library__00a05f80,0x1056);
  iVar9 = 0;
  if (0 < *(int *)(param_1 + 0x4e8)) {
    iVar10 = 0;
    do {
      *(undefined4 *)(*(int *)(param_1 + 0x4e4) + iVar10) = 0;
      iVar9 = iVar9 + 1;
      iVar10 = iVar10 + 0x28;
    } while (iVar9 < *(int *)(param_1 + 0x4e8));
  }
  *(undefined4 *)(param_1 + 0x4dc) = *(undefined4 *)(param_1 + 0x234);
  *(undefined4 *)(param_1 + 0x22c) = 0;
  *(undefined4 *)(param_1 + 0x238) = 0;
  FUN_0056dac0(param_1);
  return 0;
}

