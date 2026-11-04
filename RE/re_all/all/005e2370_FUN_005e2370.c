
undefined4 FUN_005e2370(uint param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  char cVar14;
  int *piVar15;
  int iVar16;
  undefined *puVar17;
  short *psVar18;
  undefined4 *puVar19;
  int iVar20;
  int *piVar21;
  undefined4 *puVar22;
  short *psVar23;
  uint uVar24;
  bool bVar25;
  undefined4 uVar26;
  int local_104;
  int *local_100;
  int local_fc;
  int local_f8;
  int *local_f4;
  int *local_f0;
  int local_e0;
  int local_d8 [54];
  
  if ((DAT_00a37d78 == 0) || ((DAT_00ddb4b0 == 0 && (DAT_00ddb5f0 == 0)))) {
    return 0;
  }
  if ((((((DAT_00cc6b10 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc6b38)) ||
       ((DAT_00cc6b40 <= (int)(param_1 & 0xffff) ||
        (piVar3 = *(int **)(DAT_00cc6b14 + (param_1 & 0xffff) * 4), piVar3 == (int *)0x0)))) ||
      (*piVar3 * 0x10000 != (param_1 & 0x3ff0000))) || (piVar3[4] != 0)) {
    return 0xffffffff;
  }
  if (piVar3[0x78] != 0) {
    return 0;
  }
  piVar9 = piVar3 + 0xaf;
  piVar3[0x11b] = param_2;
  FUN_0056d380(piVar9,0,0xd8);
  FUN_0056d380(piVar3 + 0xe5,0,0xd8);
  FUN_0056d380(piVar3 + 0x79,0,0xd8);
  piVar3[0x77] = 0;
  FUN_0056d380(local_d8,0,0xd8);
  piVar15 = (int *)piVar3[0x4a];
  local_e0 = 0;
  if (0 < piVar3[0x49]) {
    do {
      sVar2 = (short)piVar15[1];
      if (sVar2 == 0) {
        uVar24 = (uint)(piVar3[0x11] != 0);
LAB_005e24cd:
        local_fc = piVar15[3];
        local_100 = (int *)((uint)*(ushort *)(piVar15 + 0x46) + (uint)*(ushort *)(piVar15 + 0x44));
        if (piVar3[0x11] != 0) {
          local_fc = piVar15[0x48] * local_fc;
          local_100 = (int *)(piVar15[0x48] * (int)local_100);
        }
        iVar16 = *(int *)(*piVar15 + 0x4c) +
                 ((uint)(*(int *)(*(int *)(*piVar15 + 4) + 0x168) != 0) + uVar24 * 2) * 9;
        piVar1 = local_d8 + iVar16;
        if (local_d8[iVar16] == 0) {
          piVar3[0x77] = piVar3[0x77] + 1;
          piVar3[iVar16 + 0x79] = piVar3[iVar16 + 0x79] + 1;
          iVar6 = FUN_0056e030(0x2c,
                               "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D9.cpp",
                               0x90a);
          *piVar1 = iVar6;
          FUN_0056d380(iVar6,0,0x2c);
          *(int *)(*piVar1 + 0x14) = *piVar1 + 0x20;
          piVar3[iVar16 + 0xaf] = *piVar1;
          piVar3[iVar16 + 0xe5] = *piVar1;
        }
        piVar21 = (int *)*piVar1;
        if ((0xbffff < piVar21[1] + (int)local_100) || (0x5ffff < *piVar21 + local_fc)) {
          piVar3[0x77] = piVar3[0x77] + 1;
          piVar3[iVar16 + 0x79] = piVar3[iVar16 + 0x79] + 1;
          iVar6 = FUN_0056e030(0x2c,
                               "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D9.cpp",
                               0x918);
          piVar21[6] = iVar6;
          FUN_0056d380(iVar6,0,0x2c);
          *(int *)(piVar21[6] + 0x14) = piVar21[6] + 0x20;
          *(int **)(piVar21[6] + 0x1c) = piVar21;
          piVar3[iVar16 + 0xe5] = piVar21[6];
          piVar21 = (int *)piVar21[6];
          *piVar1 = (int)piVar21;
        }
        piVar15[0x49] = (int)piVar21;
        piVar15[0x4a] = *piVar21;
        iVar16 = piVar21[1];
        piVar15[0x4b] = iVar16;
        if (piVar3[0x11] == 0) {
          piVar15[0x4c] = (uint)*(ushort *)(piVar15 + 0x44) + iVar16;
        }
        else {
          piVar15[0x4c] = (uint)*(ushort *)(piVar15 + 0x44) * piVar15[0x48] + iVar16;
        }
        *piVar21 = *piVar21 + local_fc;
        piVar21[1] = piVar21[1] + (int)local_100;
      }
      else {
        if (sVar2 == 1) {
          uVar24 = 1;
          goto LAB_005e24cd;
        }
        if (sVar2 == 2) {
          uVar24 = 2;
          goto LAB_005e24cd;
        }
      }
      local_e0 = local_e0 + 1;
      piVar15 = piVar15 + 0x4e;
    } while (local_e0 < piVar3[0x49]);
  }
  iVar16 = 0;
  piVar15 = piVar3 + 0xe5;
  do {
    local_100 = (int *)0x2;
    do {
      iVar6 = 0;
      do {
        iVar7 = *piVar15;
        if ((iVar7 != 0) && (*(int *)(iVar7 + 4) == 0)) {
          *piVar15 = *(int *)(iVar7 + 0x1c);
          if (*(int *)(iVar7 + 0x1c) != 0) {
            *(undefined4 *)(*(int *)(iVar7 + 0x1c) + 0x18) = 0;
          }
          FUN_0056e1d0(iVar7);
          piVar3[0x77] = piVar3[0x77] + -1;
          piVar3[iVar16 + iVar6 + 0x79] = piVar3[iVar16 + iVar6 + 0x79] + -1;
        }
        iVar6 = iVar6 + 1;
        piVar15 = piVar15 + 1;
      } while (iVar6 < 9);
      iVar16 = iVar16 + 9;
      local_100 = (int *)((int)local_100 + -1);
    } while (local_100 != (int *)0x0);
  } while (iVar16 < 0x36);
  local_e0 = 0;
  do {
    local_104 = 0;
    do {
      iVar16 = local_104 + local_e0 * 2;
      local_f0 = local_d8 + iVar16 * 9;
      local_100 = piVar3 + iVar16 * 9 + 0xaf;
      local_f4 = (int *)0xffffffff;
      iVar16 = 0x34;
      do {
        puVar17 = (undefined *)0x0;
        switch(local_f4) {
        case (int *)0x0:
          puVar17 = (undefined *)0x20100;
          break;
        case (int *)0x1:
          puVar17 = (undefined *)0xa0200;
          break;
        case (int *)0x2:
          puVar17 = (undefined *)0x2a0300;
          break;
        case (int *)0x3:
          puVar17 = &DAT_00aa0400;
          break;
        case (int *)0x4:
          puVar17 = (undefined *)0x2aa0500;
          break;
        case (int *)0x5:
          puVar17 = (undefined *)0xaaa0600;
          break;
        case (int *)0x6:
          puVar17 = (undefined *)0x2aaa0700;
          break;
        case (int *)0x7:
          puVar17 = (undefined *)0xaaaa0800;
        }
        piVar15 = (int *)*local_100;
        *local_f0 = (int)piVar15;
        for (; piVar15 != (int *)0x0; piVar15 = (int *)piVar15[6]) {
          if (local_e0 == 0) {
            if (local_104 == 0) {
              piVar15[4] = iVar16 + 0xc;
              *(uint *)piVar15[5] = (uint)puVar17 | 0xd2;
              puVar10 = (undefined4 *)piVar15[5];
              uVar26 = *puVar10;
            }
            else {
              if (DAT_00a37dc8 == 0) goto LAB_005e2a94;
              piVar15[4] = iVar16 + 4;
              *(undefined4 *)piVar15[5] = 0;
              puVar10 = (undefined4 *)piVar15[5];
              uVar26 = 0;
            }
            iVar6 = FUN_005d5ba0(*piVar15 * piVar15[4],8,uVar26,0,puVar10 + 1,param_3);
            if (((iVar6 < 0) ||
                (iVar6 = FUN_005d5fa0(*(undefined4 *)(piVar15[5] + 4),0,0,piVar15 + 2,0,param_3),
                iVar6 != 0)) ||
               (iVar6 = FUN_005d5c30(piVar15[1] * 2,8,0x65,0,piVar15[5] + 8,param_3), iVar6 < 0))
            goto LAB_005e2bd7;
            uVar26 = *(undefined4 *)(piVar15[5] + 8);
            goto LAB_005e2a84;
          }
          if (local_e0 == 1) {
            if (local_104 == 0) {
              if (DAT_00a37dc8 != 0) {
                piVar15[4] = iVar16;
                goto LAB_005e2921;
              }
            }
            else if (DAT_00a37dc8 != 0) {
              piVar15[4] = iVar16 + 0x18;
LAB_005e2921:
              *(undefined4 *)piVar15[5] = 0;
              iVar6 = FUN_005d5ba0(*piVar15 * piVar15[4],8,0,0,piVar15[5] + 4,param_3);
              if (((iVar6 < 0) ||
                  (iVar6 = FUN_005d5fa0(*(undefined4 *)(piVar15[5] + 4),0,0,piVar15 + 2,0,param_3),
                  iVar6 != 0)) ||
                 (iVar6 = FUN_005d5c30(piVar15[1] * 2,8,0x65,0,piVar15[5] + 8,param_3), iVar6 < 0))
              goto LAB_005e2bd7;
              uVar26 = *(undefined4 *)(piVar15[5] + 8);
LAB_005e2a84:
              iVar6 = FUN_005d5fa0(uVar26,0,0,piVar15 + 3,0,param_3);
              if (iVar6 != 0) {
LAB_005e2bd7:
                local_f4 = (int *)0x3;
                do {
                  local_f0 = (int *)0x2;
                  do {
                    local_100 = (int *)0x9;
                    do {
                      iVar16 = *piVar9;
                      while (iVar16 != 0) {
                        iVar6 = *(int *)(*(int *)(iVar16 + 0x14) + 4);
                        if (iVar6 != 0) {
                          FUN_005d6010(iVar6,param_3);
                          FUN_005d5640(*(undefined4 *)(*(int *)(iVar16 + 0x14) + 4),param_3);
                        }
                        iVar6 = *(int *)(*(int *)(iVar16 + 0x14) + 8);
                        if (iVar6 != 0) {
                          FUN_005d6010(iVar6,param_3);
                          FUN_005d5640(*(undefined4 *)(*(int *)(iVar16 + 0x14) + 8),param_3);
                        }
                        iVar6 = *(int *)(iVar16 + 0x18);
                        FUN_0056e1d0(iVar16);
                        iVar16 = iVar6;
                      }
                      *piVar9 = 0;
                      piVar9[0x36] = 0;
                      piVar9[-0x36] = 0;
                      piVar9 = piVar9 + 1;
                      local_100 = (int *)((int)local_100 + -1);
                    } while (local_100 != (int *)0x0);
                    local_f0 = (int *)((int)local_f0 + -1);
                  } while (local_f0 != (int *)0x0);
                  local_f4 = (int *)((int)local_f4 + -1);
                } while (local_f4 != (int *)0x0);
                piVar3[0x77] = 0;
                return 0xffffffff;
              }
            }
          }
          else if (local_e0 == 2) {
            if (local_104 == 0) {
              if (DAT_00a37dc8 != 0) {
                piVar15[4] = iVar16 + 0x14;
                *(undefined4 *)piVar15[5] = 0;
                iVar6 = FUN_005d5ba0(*piVar15 * piVar15[4],8,0,0,piVar15[5] + 4,param_3);
                if (((iVar6 < 0) ||
                    (iVar6 = FUN_005d5fa0(*(undefined4 *)(piVar15[5] + 4),0,0,piVar15 + 2,0,param_3)
                    , iVar6 != 0)) ||
                   (iVar6 = FUN_005d5c30(piVar15[1] * 2,8,0x65,0,piVar15[5] + 8,param_3), iVar6 < 0)
                   ) goto LAB_005e2bd7;
                uVar26 = *(undefined4 *)(piVar15[5] + 8);
                goto LAB_005e2a84;
              }
            }
            else if (DAT_00a37dc8 != 0) {
              piVar15[4] = iVar16 + 0x2c;
              *(undefined4 *)piVar15[5] = 0;
              iVar6 = FUN_005d5ba0(*piVar15 * piVar15[4],8,0,0,piVar15[5] + 4,param_3);
              if (((iVar6 < 0) ||
                  (iVar6 = FUN_005d5fa0(*(undefined4 *)(piVar15[5] + 4),0,0,piVar15 + 2,0,param_3),
                  iVar6 != 0)) ||
                 (iVar6 = FUN_005d5c30(piVar15[1] * 2,8,0x65,0,piVar15[5] + 8,param_3), iVar6 < 0))
              goto LAB_005e2bd7;
              uVar26 = *(undefined4 *)(piVar15[5] + 8);
              goto LAB_005e2a84;
            }
          }
LAB_005e2a94:
        }
        local_100 = local_100 + 1;
        local_f0 = local_f0 + 1;
        local_f4 = (int *)((int)local_f4 + 1);
        iVar16 = iVar16 + 0x10;
      } while ((int)local_f4 < 8);
      local_104 = local_104 + 1;
    } while (local_104 < 2);
    local_e0 = local_e0 + 1;
    if (2 < local_e0) {
      piVar9 = (int *)piVar3[0x4a];
      local_e0 = 0;
      if (0 < piVar3[0x49]) {
        do {
          iVar16 = piVar9[0x49];
          if (((iVar16 != 0) && (*(int *)(*(int *)(iVar16 + 0x14) + 4) != 0)) &&
             (*(int *)(*(int *)(iVar16 + 0x14) + 8) != 0)) {
            piVar15 = (int *)*piVar9;
            iVar6 = piVar15[0x13];
            bVar25 = *(int *)(piVar15[1] + 0x168) == 0;
            local_100 = (int *)piVar9[0x3c];
            iVar7 = *(int *)(*piVar15 + 0x1b0);
            iVar4 = piVar15[0x16];
            iVar5 = piVar15[0x17];
            sVar2 = (short)piVar9[1];
            iVar12 = piVar9[3];
            local_f8 = iVar12;
            if (sVar2 == 0) {
              if (piVar3[0x11] == 0) {
                if (bVar25) {
                  local_f0 = (int *)(piVar9[0x42] + 0xfU & 0xfffffff0);
                  puVar10 = (undefined4 *)
                            (*(int *)(iVar16 + 0x10) * piVar9[0x4a] + *(int *)(iVar16 + 8));
                  if (0 < iVar12) {
                    do {
                      iVar12 = *local_100 * iVar4 + iVar5;
                      puVar22 = (undefined4 *)(iVar7 + *(int *)(iVar12 + 4) * 0x24);
                      *puVar10 = *local_f0;
                      puVar10[1] = local_f0[1];
                      puVar10[2] = local_f0[2];
                      puVar10[3] = *puVar22;
                      puVar10[4] = puVar22[1];
                      puVar10[5] = puVar22[2];
                      puVar10[6] = *(undefined4 *)(iVar12 + 8);
                      puVar10[7] = *(undefined4 *)(iVar12 + 0xc);
                      if (0 < iVar6) {
                        puVar22 = (undefined4 *)(iVar12 + 0x18);
                        iVar12 = iVar6;
                        puVar19 = puVar10 + 9;
                        do {
                          puVar19[-1] = puVar22[-1];
                          iVar12 = iVar12 + -1;
                          *puVar19 = *puVar22;
                          puVar19[1] = 0x3f800000;
                          puVar19[2] = 0x3f800000;
                          puVar22 = puVar22 + 2;
                          puVar19 = puVar19 + 4;
                        } while (iVar12 != 0);
                      }
                      puVar10 = (undefined4 *)((int)puVar10 + *(int *)(piVar9[0x49] + 0x10));
                      local_f0 = local_f0 + 8;
                      local_100 = local_100 + 1;
                      local_f8 = local_f8 + -1;
                    } while (local_f8 != 0);
                  }
                }
                else {
                  puVar10 = (undefined4 *)
                            (*(int *)(iVar16 + 0x10) * piVar9[0x4a] + *(int *)(iVar16 + 8));
                  puVar22 = (undefined4 *)(piVar9[0x42] + 0xfU & 0xfffffff0);
                  if (0 < iVar12) {
                    do {
                      iVar12 = *local_100 * iVar4 + iVar5;
                      puVar19 = (undefined4 *)(iVar7 + *(int *)(iVar12 + 4) * 0x24);
                      *puVar10 = *puVar22;
                      puVar10[1] = puVar22[1];
                      puVar10[2] = puVar22[2];
                      puVar10[9] = *puVar19;
                      puVar10[10] = puVar19[1];
                      puVar10[0xb] = puVar19[2];
                      puVar10[6] = puVar19[6];
                      puVar10[7] = puVar19[7];
                      puVar10[8] = puVar19[8];
                      puVar10[3] = puVar19[3];
                      puVar10[4] = puVar19[4];
                      puVar10[5] = puVar19[5];
                      puVar10[0xc] = *(undefined4 *)(iVar12 + 8);
                      puVar10[0xd] = *(undefined4 *)(iVar12 + 0xc);
                      if (0 < iVar6) {
                        puVar19 = (undefined4 *)(iVar12 + 0x18);
                        iVar12 = iVar6;
                        puVar8 = puVar10 + 0xf;
                        do {
                          puVar8[-1] = puVar19[-1];
                          iVar12 = iVar12 + -1;
                          *puVar8 = *puVar19;
                          puVar8[1] = 0x3f800000;
                          puVar8[2] = 0x3f800000;
                          puVar19 = puVar19 + 2;
                          puVar8 = puVar8 + 4;
                        } while (iVar12 != 0);
                      }
                      puVar10 = (undefined4 *)((int)puVar10 + *(int *)(piVar9[0x49] + 0x10));
                      puVar22 = puVar22 + 8;
                      local_100 = local_100 + 1;
                      local_f8 = local_f8 + -1;
                    } while (local_f8 != 0);
                  }
                }
              }
              else {
                puVar10 = (undefined4 *)
                          (*(int *)(iVar16 + 0x10) * piVar9[0x4a] + *(int *)(iVar16 + 8));
                if (bVar25) {
                  puVar19 = (undefined4 *)(piVar9[0x42] + 0xfU & 0xfffffff0);
                  puVar22 = puVar10;
                  if (0 < iVar12) {
                    do {
                      iVar20 = *local_100 * iVar4 + iVar5;
                      puVar8 = (undefined4 *)(iVar7 + *(int *)(iVar20 + 4) * 0x24);
                      *puVar22 = *puVar19;
                      puVar22[1] = puVar19[1];
                      puVar22[2] = puVar19[2];
                      puVar22[4] = 0x3f800000;
                      *(undefined1 *)(puVar22 + 3) = 0;
                      *(undefined1 *)((int)puVar22 + 0xd) = 0;
                      puVar22[5] = 0;
                      *(undefined1 *)((int)puVar22 + 0xe) = 0;
                      puVar22[6] = 0;
                      *(undefined1 *)((int)puVar22 + 0xf) = 0;
                      puVar22[7] = 0;
                      puVar22[8] = *puVar8;
                      puVar22[9] = puVar8[1];
                      puVar22[10] = puVar8[2];
                      puVar22[0xb] = *(undefined4 *)(iVar20 + 8);
                      puVar22[0xc] = *(undefined4 *)(iVar20 + 0xc);
                      if (0 < iVar6) {
                        puVar8 = (undefined4 *)(iVar20 + 0x18);
                        puVar11 = puVar22 + 0xe;
                        iVar20 = iVar6;
                        do {
                          puVar11[-1] = puVar8[-1];
                          iVar20 = iVar20 + -1;
                          *puVar11 = *puVar8;
                          puVar11[1] = 0x3f800000;
                          puVar11[2] = 0x3f800000;
                          puVar8 = puVar8 + 2;
                          puVar11 = puVar11 + 4;
                        } while (iVar20 != 0);
                      }
                      puVar22 = (undefined4 *)((int)puVar22 + *(int *)(piVar9[0x49] + 0x10));
                      puVar19 = puVar19 + 8;
                      local_100 = local_100 + 1;
                      local_f8 = local_f8 + -1;
                    } while (local_f8 != 0);
                  }
                  cVar14 = '\x03';
                  local_104 = 1;
                  if (1 < piVar9[0x48]) {
                    do {
                      FUN_0056d420(puVar22,puVar10,*(int *)(piVar9[0x49] + 0x10) * iVar12);
                      if (0 < iVar12) {
                        iVar6 = iVar12;
                        do {
                          *(char *)(puVar22 + 3) = cVar14;
                          puVar22 = (undefined4 *)((int)puVar22 + *(int *)(piVar9[0x49] + 0x10));
                          iVar6 = iVar6 + -1;
                        } while (iVar6 != 0);
                      }
                      local_104 = local_104 + 1;
                      cVar14 = cVar14 + '\x03';
                    } while (local_104 < piVar9[0x48]);
                  }
                }
                else {
                  puVar19 = (undefined4 *)(piVar9[0x42] + 0xfU & 0xfffffff0);
                  puVar22 = puVar10;
                  if (0 < iVar12) {
                    do {
                      iVar20 = *local_100 * iVar4 + iVar5;
                      puVar8 = (undefined4 *)(iVar7 + *(int *)(iVar20 + 4) * 0x24);
                      *puVar22 = *puVar19;
                      puVar22[1] = puVar19[1];
                      puVar22[2] = puVar19[2];
                      puVar22[4] = 0x3f800000;
                      *(undefined1 *)(puVar22 + 3) = 0;
                      *(undefined1 *)((int)puVar22 + 0xd) = 0;
                      puVar22[5] = 0;
                      *(undefined1 *)((int)puVar22 + 0xe) = 0;
                      puVar22[6] = 0;
                      *(undefined1 *)((int)puVar22 + 0xf) = 0;
                      puVar22[7] = 0;
                      puVar22[0xe] = *puVar8;
                      puVar22[0xf] = puVar8[1];
                      puVar22[0x10] = puVar8[2];
                      puVar22[0xb] = puVar8[6];
                      puVar22[0xc] = puVar8[7];
                      puVar22[0xd] = puVar8[8];
                      puVar22[8] = puVar8[3];
                      puVar22[9] = puVar8[4];
                      puVar22[10] = puVar8[5];
                      puVar22[0x11] = *(undefined4 *)(iVar20 + 8);
                      puVar22[0x12] = *(undefined4 *)(iVar20 + 0xc);
                      if (0 < iVar6) {
                        puVar8 = (undefined4 *)(iVar20 + 0x18);
                        puVar11 = puVar22 + 0x14;
                        iVar20 = iVar6;
                        do {
                          puVar11[-1] = puVar8[-1];
                          iVar20 = iVar20 + -1;
                          *puVar11 = *puVar8;
                          puVar11[1] = 0x3f800000;
                          puVar11[2] = 0x3f800000;
                          puVar8 = puVar8 + 2;
                          puVar11 = puVar11 + 4;
                        } while (iVar20 != 0);
                      }
                      puVar22 = (undefined4 *)((int)puVar22 + *(int *)(piVar9[0x49] + 0x10));
                      puVar19 = puVar19 + 8;
                      local_100 = local_100 + 1;
                      local_f8 = local_f8 + -1;
                    } while (local_f8 != 0);
                  }
                  cVar14 = '\x03';
                  local_104 = 1;
                  if (1 < piVar9[0x48]) {
                    do {
                      FUN_0056d420(puVar22,puVar10,*(int *)(piVar9[0x49] + 0x10) * iVar12);
                      if (0 < iVar12) {
                        iVar6 = iVar12;
                        do {
                          *(char *)(puVar22 + 3) = cVar14;
                          puVar22 = (undefined4 *)((int)puVar22 + *(int *)(piVar9[0x49] + 0x10));
                          iVar6 = iVar6 + -1;
                        } while (iVar6 != 0);
                      }
                      local_104 = local_104 + 1;
                      cVar14 = cVar14 + '\x03';
                    } while (local_104 < piVar9[0x48]);
                  }
                }
              }
            }
            else if (sVar2 == 1) {
              puVar10 = (undefined4 *)(piVar9[0x42] + 0xfU & 0xfffffff0);
              if (bVar25) {
                puVar19 = (undefined4 *)
                          (*(int *)(iVar16 + 0x10) * piVar9[0x4a] + *(int *)(iVar16 + 8));
                puVar22 = puVar19;
                if (0 < iVar12) {
                  do {
                    iVar20 = *local_100 * iVar4 + iVar5;
                    puVar8 = (undefined4 *)(iVar7 + *(int *)(iVar20 + 4) * 0x24);
                    *puVar22 = puVar10[4];
                    puVar22[1] = puVar10[5];
                    puVar22[2] = puVar10[6];
                    *(char *)(puVar22 + 3) = *(char *)(puVar10 + 0xb) * '\x03';
                    *(char *)((int)puVar22 + 0xd) = *(char *)((int)puVar10 + 0x2d) * '\x03';
                    *(char *)((int)puVar22 + 0xe) = *(char *)((int)puVar10 + 0x2e) * '\x03';
                    *(char *)((int)puVar22 + 0xf) = *(char *)((int)puVar10 + 0x2f) * '\x03';
                    puVar22[4] = *puVar10;
                    puVar22[5] = puVar10[1];
                    puVar22[6] = puVar10[2];
                    puVar22[7] = puVar10[3];
                    puVar22[8] = *puVar8;
                    puVar22[9] = puVar8[1];
                    puVar22[10] = puVar8[2];
                    puVar22[0xb] = *(undefined4 *)(iVar20 + 8);
                    puVar22[0xc] = *(undefined4 *)(iVar20 + 0xc);
                    if (0 < iVar6) {
                      puVar8 = puVar22 + 0xe;
                      iVar13 = iVar6;
                      puVar11 = (undefined4 *)(iVar20 + 0x18);
                      do {
                        puVar8[-1] = puVar11[-1];
                        iVar13 = iVar13 + -1;
                        *puVar8 = *puVar11;
                        puVar8[1] = 0x3f800000;
                        puVar8[2] = 0x3f800000;
                        puVar8 = puVar8 + 4;
                        puVar11 = puVar11 + 2;
                      } while (iVar13 != 0);
                    }
                    puVar22 = (undefined4 *)((int)puVar22 + *(int *)(piVar9[0x49] + 0x10));
                    puVar10 = puVar10 + 0xc;
                    local_100 = local_100 + 1;
                    local_f8 = local_f8 + -1;
                  } while (local_f8 != 0);
                }
                if (piVar3[0x11] != 0) {
                  iVar6 = piVar9[5] * 3;
                  local_104 = 1;
                  if (1 < piVar9[0x48]) {
                    do {
                      FUN_0056d420(puVar22,puVar19,*(int *)(piVar9[0x49] + 0x10) * iVar12);
                      if (0 < iVar12) {
                        iVar7 = iVar12;
                        do {
                          cVar14 = (char)iVar6;
                          *(char *)(puVar22 + 3) = *(char *)(puVar22 + 3) + cVar14;
                          *(char *)((int)puVar22 + 0xd) = *(char *)((int)puVar22 + 0xd) + cVar14;
                          *(char *)((int)puVar22 + 0xe) = *(char *)((int)puVar22 + 0xe) + cVar14;
                          *(char *)((int)puVar22 + 0xf) = *(char *)((int)puVar22 + 0xf) + cVar14;
                          puVar22 = (undefined4 *)((int)puVar22 + *(int *)(piVar9[0x49] + 0x10));
                          iVar7 = iVar7 + -1;
                        } while (iVar7 != 0);
                      }
                      local_104 = local_104 + 1;
                      iVar6 = piVar9[5] * 3 + iVar6;
                    } while (local_104 < piVar9[0x48]);
                  }
                }
              }
              else {
                puVar19 = (undefined4 *)
                          (*(int *)(iVar16 + 0x10) * piVar9[0x4a] + *(int *)(iVar16 + 8));
                puVar22 = puVar19;
                if (0 < iVar12) {
                  do {
                    iVar20 = *local_100 * iVar4 + iVar5;
                    puVar8 = (undefined4 *)(iVar7 + *(int *)(iVar20 + 4) * 0x24);
                    *puVar22 = puVar10[4];
                    puVar22[1] = puVar10[5];
                    puVar22[2] = puVar10[6];
                    *(char *)(puVar22 + 3) = *(char *)(puVar10 + 0xb) * '\x03';
                    *(char *)((int)puVar22 + 0xd) = *(char *)((int)puVar10 + 0x2d) * '\x03';
                    *(char *)((int)puVar22 + 0xe) = *(char *)((int)puVar10 + 0x2e) * '\x03';
                    *(char *)((int)puVar22 + 0xf) = *(char *)((int)puVar10 + 0x2f) * '\x03';
                    puVar22[4] = *puVar10;
                    puVar22[5] = puVar10[1];
                    puVar22[6] = puVar10[2];
                    puVar22[7] = puVar10[3];
                    puVar22[0xe] = *puVar8;
                    puVar22[0xf] = puVar8[1];
                    puVar22[0x10] = puVar8[2];
                    puVar22[0xb] = puVar8[6];
                    puVar22[0xc] = puVar8[7];
                    puVar22[0xd] = puVar8[8];
                    puVar22[8] = puVar8[3];
                    puVar22[9] = puVar8[4];
                    puVar22[10] = puVar8[5];
                    puVar22[0x11] = *(undefined4 *)(iVar20 + 8);
                    puVar22[0x12] = *(undefined4 *)(iVar20 + 0xc);
                    if (0 < iVar6) {
                      puVar8 = puVar22 + 0x14;
                      iVar13 = iVar6;
                      puVar11 = (undefined4 *)(iVar20 + 0x18);
                      do {
                        puVar8[-1] = puVar11[-1];
                        iVar13 = iVar13 + -1;
                        *puVar8 = *puVar11;
                        puVar8[1] = 0x3f800000;
                        puVar8[2] = 0x3f800000;
                        puVar8 = puVar8 + 4;
                        puVar11 = puVar11 + 2;
                      } while (iVar13 != 0);
                    }
                    puVar22 = (undefined4 *)((int)puVar22 + *(int *)(piVar9[0x49] + 0x10));
                    local_100 = local_100 + 1;
                    puVar10 = puVar10 + 0xc;
                    local_f8 = local_f8 + -1;
                  } while (local_f8 != 0);
                }
                if (piVar3[0x11] != 0) {
                  iVar6 = piVar9[5] * 3;
                  local_104 = 1;
                  if (1 < piVar9[0x48]) {
                    do {
                      FUN_0056d420(puVar22,puVar19,*(int *)(piVar9[0x49] + 0x10) * iVar12);
                      if (0 < iVar12) {
                        iVar7 = iVar12;
                        do {
                          cVar14 = (char)iVar6;
                          *(char *)(puVar22 + 3) = *(char *)(puVar22 + 3) + cVar14;
                          *(char *)((int)puVar22 + 0xd) = *(char *)((int)puVar22 + 0xd) + cVar14;
                          *(char *)((int)puVar22 + 0xe) = *(char *)((int)puVar22 + 0xe) + cVar14;
                          *(char *)((int)puVar22 + 0xf) = *(char *)((int)puVar22 + 0xf) + cVar14;
                          puVar22 = (undefined4 *)((int)puVar22 + *(int *)(piVar9[0x49] + 0x10));
                          iVar7 = iVar7 + -1;
                        } while (iVar7 != 0);
                      }
                      local_104 = local_104 + 1;
                      iVar6 = piVar9[5] * 3 + iVar6;
                    } while (local_104 < piVar9[0x48]);
                  }
                }
              }
            }
            else if (sVar2 == 2) {
              puVar10 = (undefined4 *)(piVar9[0x42] + 0xfU & 0xfffffff0);
              if (bVar25) {
                puVar19 = (undefined4 *)
                          (*(int *)(iVar16 + 0x10) * piVar9[0x4a] + *(int *)(iVar16 + 8));
                puVar22 = puVar19;
                if (0 < iVar12) {
                  do {
                    iVar20 = *local_100 * iVar4 + iVar5;
                    puVar8 = (undefined4 *)(iVar7 + *(int *)(iVar20 + 4) * 0x24);
                    *puVar22 = puVar10[0xc];
                    puVar22[1] = puVar10[0xd];
                    puVar22[2] = puVar10[0xe];
                    *(char *)(puVar22 + 3) = *(char *)(puVar10 + 0xb) * '\x03';
                    *(char *)((int)puVar22 + 0xd) = *(char *)((int)puVar10 + 0x2d) * '\x03';
                    *(char *)((int)puVar22 + 0xe) = *(char *)((int)puVar10 + 0x2e) * '\x03';
                    *(char *)((int)puVar22 + 0xf) = *(char *)((int)puVar10 + 0x2f) * '\x03';
                    *(char *)(puVar22 + 4) = *(char *)(puVar10 + 0xf) * '\x03';
                    *(char *)((int)puVar22 + 0x11) = *(char *)((int)puVar10 + 0x3d) * '\x03';
                    *(char *)((int)puVar22 + 0x12) = *(char *)((int)puVar10 + 0x3e) * '\x03';
                    *(char *)((int)puVar22 + 0x13) = *(char *)((int)puVar10 + 0x3f) * '\x03';
                    puVar22[5] = *puVar10;
                    puVar22[6] = puVar10[1];
                    puVar22[7] = puVar10[2];
                    puVar22[8] = puVar10[3];
                    puVar22[9] = puVar10[4];
                    puVar22[10] = puVar10[5];
                    puVar22[0xb] = puVar10[6];
                    puVar22[0xc] = puVar10[7];
                    puVar22[0xd] = *puVar8;
                    puVar22[0xe] = puVar8[1];
                    puVar22[0xf] = puVar8[2];
                    puVar22[0x10] = *(undefined4 *)(iVar20 + 8);
                    puVar22[0x11] = *(undefined4 *)(iVar20 + 0xc);
                    if (0 < iVar6) {
                      puVar8 = puVar22 + 0x13;
                      iVar13 = iVar6;
                      puVar11 = (undefined4 *)(iVar20 + 0x18);
                      do {
                        puVar8[-1] = puVar11[-1];
                        iVar13 = iVar13 + -1;
                        *puVar8 = *puVar11;
                        puVar8[1] = 0x3f800000;
                        puVar8[2] = 0x3f800000;
                        puVar8 = puVar8 + 4;
                        puVar11 = puVar11 + 2;
                      } while (iVar13 != 0);
                    }
                    puVar22 = (undefined4 *)((int)puVar22 + *(int *)(piVar9[0x49] + 0x10));
                    puVar10 = puVar10 + 0x10;
                    local_100 = local_100 + 1;
                    local_f8 = local_f8 + -1;
                  } while (local_f8 != 0);
                }
                if (piVar3[0x11] != 0) {
                  iVar6 = piVar9[5] * 3;
                  local_104 = 1;
                  if (1 < piVar9[0x48]) {
                    do {
                      FUN_0056d420(puVar22,puVar19,*(int *)(piVar9[0x49] + 0x10) * iVar12);
                      if (0 < iVar12) {
                        iVar7 = iVar12;
                        do {
                          cVar14 = (char)iVar6;
                          *(char *)(puVar22 + 3) = *(char *)(puVar22 + 3) + cVar14;
                          *(char *)((int)puVar22 + 0xd) = *(char *)((int)puVar22 + 0xd) + cVar14;
                          *(char *)((int)puVar22 + 0xe) = *(char *)((int)puVar22 + 0xe) + cVar14;
                          *(char *)((int)puVar22 + 0xf) = *(char *)((int)puVar22 + 0xf) + cVar14;
                          *(char *)(puVar22 + 4) = *(char *)(puVar22 + 4) + cVar14;
                          *(char *)((int)puVar22 + 0x11) = *(char *)((int)puVar22 + 0x11) + cVar14;
                          *(char *)((int)puVar22 + 0x12) = *(char *)((int)puVar22 + 0x12) + cVar14;
                          *(char *)((int)puVar22 + 0x13) = *(char *)((int)puVar22 + 0x13) + cVar14;
                          puVar22 = (undefined4 *)((int)puVar22 + *(int *)(piVar9[0x49] + 0x10));
                          iVar7 = iVar7 + -1;
                        } while (iVar7 != 0);
                      }
                      local_104 = local_104 + 1;
                      iVar6 = piVar9[5] * 3 + iVar6;
                    } while (local_104 < piVar9[0x48]);
                  }
                }
              }
              else {
                puVar19 = (undefined4 *)
                          (*(int *)(iVar16 + 0x10) * piVar9[0x4a] + *(int *)(iVar16 + 8));
                puVar22 = puVar19;
                if (0 < iVar12) {
                  do {
                    iVar20 = *local_100 * iVar4 + iVar5;
                    puVar8 = (undefined4 *)(iVar7 + *(int *)(iVar20 + 4) * 0x24);
                    *puVar22 = puVar10[0xc];
                    puVar22[1] = puVar10[0xd];
                    puVar22[2] = puVar10[0xe];
                    *(char *)(puVar22 + 3) = *(char *)(puVar10 + 0xb) * '\x03';
                    *(char *)((int)puVar22 + 0xd) = *(char *)((int)puVar10 + 0x2d) * '\x03';
                    *(char *)((int)puVar22 + 0xe) = *(char *)((int)puVar10 + 0x2e) * '\x03';
                    *(char *)((int)puVar22 + 0xf) = *(char *)((int)puVar10 + 0x2f) * '\x03';
                    *(char *)(puVar22 + 4) = *(char *)(puVar10 + 0xf) * '\x03';
                    *(char *)((int)puVar22 + 0x11) = *(char *)((int)puVar10 + 0x3d) * '\x03';
                    *(char *)((int)puVar22 + 0x12) = *(char *)((int)puVar10 + 0x3e) * '\x03';
                    *(char *)((int)puVar22 + 0x13) = *(char *)((int)puVar10 + 0x3f) * '\x03';
                    puVar22[5] = *puVar10;
                    puVar22[6] = puVar10[1];
                    puVar22[7] = puVar10[2];
                    puVar22[8] = puVar10[3];
                    puVar22[9] = puVar10[4];
                    puVar22[10] = puVar10[5];
                    puVar22[0xb] = puVar10[6];
                    puVar22[0xc] = puVar10[7];
                    puVar22[0x13] = *puVar8;
                    puVar22[0x14] = puVar8[1];
                    puVar22[0x15] = puVar8[2];
                    puVar22[0x10] = puVar8[6];
                    puVar22[0x11] = puVar8[7];
                    puVar22[0x12] = puVar8[8];
                    puVar22[0xd] = puVar8[3];
                    puVar22[0xe] = puVar8[4];
                    puVar22[0xf] = puVar8[5];
                    puVar22[0x16] = *(undefined4 *)(iVar20 + 8);
                    puVar22[0x17] = *(undefined4 *)(iVar20 + 0xc);
                    if (0 < iVar6) {
                      puVar8 = puVar22 + 0x19;
                      iVar13 = iVar6;
                      puVar11 = (undefined4 *)(iVar20 + 0x18);
                      do {
                        puVar8[-1] = puVar11[-1];
                        iVar13 = iVar13 + -1;
                        *puVar8 = *puVar11;
                        puVar8[1] = 0x3f800000;
                        puVar8[2] = 0x3f800000;
                        puVar8 = puVar8 + 4;
                        puVar11 = puVar11 + 2;
                      } while (iVar13 != 0);
                    }
                    puVar22 = (undefined4 *)((int)puVar22 + *(int *)(piVar9[0x49] + 0x10));
                    local_100 = local_100 + 1;
                    puVar10 = puVar10 + 0x10;
                    local_f8 = local_f8 + -1;
                  } while (local_f8 != 0);
                }
                if (piVar3[0x11] != 0) {
                  iVar6 = piVar9[5] * 3;
                  local_104 = 1;
                  if (1 < piVar9[0x48]) {
                    do {
                      FUN_0056d420(puVar22,puVar19,*(int *)(piVar9[0x49] + 0x10) * iVar12);
                      if (0 < iVar12) {
                        iVar7 = iVar12;
                        do {
                          cVar14 = (char)iVar6;
                          *(char *)(puVar22 + 3) = *(char *)(puVar22 + 3) + cVar14;
                          *(char *)((int)puVar22 + 0xd) = *(char *)((int)puVar22 + 0xd) + cVar14;
                          *(char *)((int)puVar22 + 0xe) = *(char *)((int)puVar22 + 0xe) + cVar14;
                          *(char *)((int)puVar22 + 0xf) = *(char *)((int)puVar22 + 0xf) + cVar14;
                          *(char *)(puVar22 + 4) = *(char *)(puVar22 + 4) + cVar14;
                          *(char *)((int)puVar22 + 0x11) = *(char *)((int)puVar22 + 0x11) + cVar14;
                          *(char *)((int)puVar22 + 0x12) = *(char *)((int)puVar22 + 0x12) + cVar14;
                          *(char *)((int)puVar22 + 0x13) = *(char *)((int)puVar22 + 0x13) + cVar14;
                          puVar22 = (undefined4 *)((int)puVar22 + *(int *)(piVar9[0x49] + 0x10));
                          iVar7 = iVar7 + -1;
                        } while (iVar7 != 0);
                      }
                      local_104 = local_104 + 1;
                      iVar6 = piVar9[5] * 3 + iVar6;
                    } while (local_104 < piVar9[0x48]);
                  }
                }
              }
            }
            iVar6 = *(int *)(iVar16 + 0xc) + piVar9[0x4b] * 2;
            iVar16 = *(int *)(iVar16 + 0xc) + piVar9[0x4c] * 2;
            FUN_0056d420(iVar6,piVar9[0x45],(uint)*(ushort *)(piVar9 + 0x44) * 2);
            if (*(ushort *)(piVar9 + 0x46) != 0) {
              FUN_0056d420(iVar16,piVar9[0x47],(uint)*(ushort *)(piVar9 + 0x46) * 2);
            }
            if (piVar3[0x11] != 0) {
              iVar7 = piVar9[3];
              psVar23 = (short *)(iVar16 + (uint)*(ushort *)(piVar9 + 0x46) * 2);
              psVar18 = (short *)(iVar6 + (uint)*(ushort *)(piVar9 + 0x44) * 2);
              local_104 = 1;
              local_100 = (int *)iVar7;
              if (1 < piVar9[0x48]) {
                do {
                  FUN_0056d420(psVar18,piVar9[0x45],(uint)*(ushort *)(piVar9 + 0x44) * 2);
                  iVar16 = 0;
                  if ((short)piVar9[0x44] != 0) {
                    do {
                      *psVar18 = *psVar18 + (short)iVar7;
                      iVar16 = iVar16 + 1;
                      psVar18 = psVar18 + 1;
                    } while (iVar16 < (int)(uint)*(ushort *)(piVar9 + 0x44));
                  }
                  iVar7 = iVar7 + piVar9[3];
                  if (*(ushort *)(piVar9 + 0x46) != 0) {
                    FUN_0056d420(psVar23,piVar9[0x47],(uint)*(ushort *)(piVar9 + 0x46) * 2);
                    iVar16 = 0;
                    if ((short)piVar9[0x46] != 0) {
                      do {
                        *psVar23 = *psVar23 + (short)local_100;
                        iVar16 = iVar16 + 1;
                        psVar23 = psVar23 + 1;
                      } while (iVar16 < (int)(uint)*(ushort *)(piVar9 + 0x46));
                    }
                    local_100 = (int *)((int)local_100 + piVar9[3]);
                  }
                  local_104 = local_104 + 1;
                } while (local_104 < piVar9[0x48]);
              }
            }
          }
          local_e0 = local_e0 + 1;
          piVar9 = piVar9 + 0x4e;
        } while (local_e0 < piVar3[0x49]);
      }
      local_f4 = piVar3 + 0x79;
      local_f0 = (int *)0x3;
      do {
        local_100 = (int *)0x2;
        do {
          local_f8 = 9;
          do {
            iVar16 = local_f4[0x36];
            while (iVar16 != 0) {
              iVar6 = *(int *)(*(int *)(iVar16 + 0x14) + 4);
              iVar7 = *(int *)(iVar16 + 0x18);
              if ((iVar6 == 0) || (*(int *)(*(int *)(iVar16 + 0x14) + 8) == 0)) {
                if (*(int *)(iVar16 + 0x1c) == 0) {
                  local_f4[0x36] = iVar7;
                }
                else {
                  *(int *)(*(int *)(iVar16 + 0x1c) + 0x18) = iVar7;
                }
                if (*(int *)(iVar16 + 0x18) == 0) {
                  local_f4[0x6c] = *(int *)(iVar16 + 0x1c);
                }
                else {
                  *(undefined4 *)(*(int *)(iVar16 + 0x18) + 0x1c) = *(undefined4 *)(iVar16 + 0x1c);
                }
                iVar6 = *(int *)(*(int *)(iVar16 + 0x14) + 4);
                if (iVar6 != 0) {
                  FUN_005d5640(iVar6,param_3);
                  *(undefined4 *)(*(int *)(iVar16 + 0x14) + 4) = 0;
                }
                iVar6 = *(int *)(*(int *)(iVar16 + 0x14) + 8);
                if (iVar6 != 0) {
                  FUN_005d5640(iVar6,param_3);
                  *(undefined4 *)(*(int *)(iVar16 + 0x14) + 8) = 0;
                }
                iVar6 = 0;
                if (0 < piVar3[0x49]) {
                  piVar9 = (int *)(piVar3[0x4a] + 0x124);
                  do {
                    if (*piVar9 == iVar16) {
                      *piVar9 = 0;
                    }
                    iVar6 = iVar6 + 1;
                    piVar9 = piVar9 + 0x4e;
                  } while (iVar6 < piVar3[0x49]);
                }
                FUN_0056e1d0(iVar16);
                *local_f4 = *local_f4 + -1;
                piVar3[0x77] = piVar3[0x77] + -1;
                iVar16 = iVar7;
              }
              else {
                FUN_005d6010(iVar6,param_3);
                iVar6 = *(int *)(*(int *)(iVar16 + 0x14) + 8);
                iVar16 = iVar7;
                if (iVar6 != 0) {
                  FUN_005d6010(iVar6,param_3);
                }
              }
            }
            local_f4 = local_f4 + 1;
            local_f8 = local_f8 + -1;
          } while (local_f8 != 0);
          local_100 = (int *)((int)local_100 + -1);
        } while (local_100 != (int *)0x0);
        local_f0 = (int *)((int)local_f0 + -1);
      } while (local_f0 != (int *)0x0);
      piVar3[0x78] = 1;
      if ((DAT_00cc6e00 != 0) && (iVar16 = DAT_00cc6e38, DAT_00cc6e38 <= DAT_00cc6e3c)) {
        do {
          iVar6 = *(int *)(DAT_00cc6e04 + iVar16 * 4);
          if ((iVar6 != 0) && ((*(int *)(iVar6 + 0x10) == 0 && (*(int **)(iVar6 + 0x40) == piVar3)))
             ) {
            FUN_005db690(*(undefined4 *)(iVar6 + 4),param_3);
          }
          iVar16 = iVar16 + 1;
        } while (iVar16 <= DAT_00cc6e3c);
      }
      return 0;
    }
  } while( true );
}

