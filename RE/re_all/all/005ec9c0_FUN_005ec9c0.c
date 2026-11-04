
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ec9c0(int *param_1,int param_2)

{
  float fVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  char cVar12;
  int iVar13;
  int iVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  undefined1 *puVar17;
  int iVar18;
  undefined4 *puVar19;
  int iVar20;
  int *piVar21;
  short sVar22;
  undefined8 uVar23;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_54;
  int local_50;
  double local_48;
  double local_40;
  undefined1 local_18 [24];
  
  iVar3 = *param_1;
  iVar4 = *(int *)(iVar3 + 8);
  iVar5 = *(int *)(iVar4 + 0x40);
  iVar6 = param_1[1];
  iVar13 = FUN_00567b30();
  if (iVar13 != 0) {
    bVar11 = false;
    if (DAT_00a380c4 != 0) {
      iVar13 = 0;
      do {
        if ((&DAT_00a380f8)[iVar13] != 0) break;
        iVar13 = iVar13 + 1;
      } while (iVar13 < 3);
      if (iVar13 != 3) {
        bVar11 = true;
      }
    }
    FUN_005bb3b0();
    cVar12 = FUN_005ea280();
    if (cVar12 != '\0') {
      FUN_005ea7c0();
      iVar13 = 0;
      if (0 < *(int *)(iVar6 + 0x40)) {
        puVar17 = (undefined1 *)(*(int *)(iVar6 + 0x44) + 0xf8);
        do {
          *puVar17 = 0;
          iVar13 = iVar13 + 1;
          puVar17 = puVar17 + 0x138;
        } while (iVar13 < *(int *)(iVar6 + 0x40));
      }
      if (*(int *)(iVar4 + 0x250) == 0) {
        local_68 = param_1[0x2b];
        iVar13 = *(int *)(iVar6 + 0x44);
        local_6c = 0;
        if (0 < *(int *)(iVar6 + 0x40)) {
          do {
            if ((param_2 < 0) || (local_6c == param_2)) {
              sVar22 = *(short *)(iVar13 + 4);
              if ((sVar22 == 0) && (*(int *)(iVar5 + 0x44) != 0)) {
                sVar22 = 1;
              }
              iVar14 = FUN_005eaf60(sVar22);
              if (iVar14 != 0) {
                FUN_005bb9e0(*(undefined4 *)(*(int *)(*(int *)(iVar13 + 0x124) + 0x14) + 4));
                iVar14 = *(int *)(*(int *)(local_68 + 0xc) + 4);
                if (iVar14 == 0) {
                  uVar23 = CONCAT44(*(undefined4 *)(*(int *)(iVar13 + 0x124) + 0x10),
                                    **(undefined4 **)(*(int *)(iVar13 + 0x124) + 0x14));
                }
                else {
                  uVar23 = CONCAT44(*(undefined4 *)(*(int *)(iVar13 + 0x124) + 0x10),iVar14);
                }
                FUN_005bb970(uVar23);
                switch(*(short *)(iVar13 + 4)) {
                case 0:
                  if (*(int *)(iVar5 + 0x44) != 0) goto switchD_005ecb41_caseD_1;
                  FUN_005eb780();
                  FUN_005c2e80();
LAB_005ecb91:
                  FUN_005d2bd0();
                  DAT_00a37de4 = DAT_00a37de4 + 1;
                  if ((DAT_00a380c4 != 0) && (!bVar11)) {
                    FUN_005b9490();
                  }
                  break;
                case 1:
                case 2:
switchD_005ecb41_caseD_1:
                  if (*(int *)(iVar5 + 0x44) == 0) {
                    FUN_005eb960();
                    FUN_005c2e80();
                    goto LAB_005ecb91;
                  }
                  puVar7 = *(undefined4 **)(DAT_00ef1b9c + 8);
                  if (*(short *)(iVar13 + 4) == 0) {
                    puVar19 = (undefined4 *)
                              (((iVar3 - *(int *)(iVar4 + 0x17c)) / 0x2b8 + *(int *)(iVar5 + 0xd8))
                               * 0x30 + *(int *)(iVar4 + 0x194));
                  }
                  else {
                    puVar19 = *(undefined4 **)(iVar4 + 0x194);
                  }
                  for (iVar14 = *(int *)(iVar4 + 400); 0 < iVar14; iVar14 = iVar14 - local_64) {
                    local_64 = iVar14;
                    if (*(int *)(iVar13 + 0x120) < iVar14) {
                      local_64 = *(int *)(iVar13 + 0x120);
                    }
                    iVar18 = 0;
                    if (*(short *)(iVar13 + 4) == 0) {
                      puVar16 = puVar7;
                      if (3 < local_64) {
                        iVar20 = (local_64 - 4U >> 2) + 1;
                        iVar18 = iVar20 * 4;
                        puVar15 = puVar7;
                        do {
                          *puVar15 = *puVar19;
                          puVar15[1] = puVar19[1];
                          puVar15[2] = puVar19[2];
                          puVar15[3] = puVar19[3];
                          puVar15[4] = puVar19[4];
                          puVar15[5] = puVar19[5];
                          puVar15[6] = puVar19[6];
                          puVar15[7] = puVar19[7];
                          puVar15[8] = puVar19[8];
                          puVar15[9] = puVar19[9];
                          puVar15[10] = puVar19[10];
                          puVar15[0xb] = puVar19[0xb];
                          iVar8 = *(int *)(iVar5 + 0x4c);
                          puVar15[0xc] = puVar19[iVar8 * 0xc];
                          puVar15[0xd] = puVar19[iVar8 * 0xc + 1];
                          puVar15[0xe] = puVar19[iVar8 * 0xc + 2];
                          puVar15[0xf] = puVar19[iVar8 * 0xc + 3];
                          puVar15[0x10] = puVar19[iVar8 * 0xc + 4];
                          puVar15[0x11] = puVar19[iVar8 * 0xc + 5];
                          puVar15[0x12] = puVar19[iVar8 * 0xc + 6];
                          puVar15[0x13] = puVar19[iVar8 * 0xc + 7];
                          puVar15[0x14] = puVar19[iVar8 * 0xc + 8];
                          puVar15[0x15] = puVar19[iVar8 * 0xc + 9];
                          puVar15[0x16] = puVar19[iVar8 * 0xc + 10];
                          puVar15[0x17] = puVar19[iVar8 * 0xc + 0xb];
                          iVar9 = *(int *)(iVar5 + 0x4c);
                          puVar15[0x18] = puVar19[iVar8 * 0xc + iVar9 * 0xc];
                          puVar15[0x19] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 1];
                          puVar15[0x1a] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 2];
                          puVar15[0x1b] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 3];
                          puVar15[0x1c] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 4];
                          puVar15[0x1d] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 5];
                          puVar15[0x1e] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 6];
                          puVar15[0x1f] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 7];
                          puVar15[0x20] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 8];
                          puVar15[0x21] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 9];
                          puVar15[0x22] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 10];
                          puVar15[0x23] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 0xb];
                          iVar10 = *(int *)(iVar5 + 0x4c);
                          puVar15[0x24] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc];
                          puVar16 = puVar15 + 0x30;
                          puVar15[0x25] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 1];
                          puVar15[0x26] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 2];
                          puVar15[0x27] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 3];
                          puVar15[0x28] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 4];
                          puVar15[0x29] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 5];
                          puVar15[0x2a] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 6];
                          puVar15[0x2b] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 7];
                          puVar15[0x2c] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 8];
                          puVar15[0x2d] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 9];
                          puVar15[0x2e] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 10];
                          puVar15[0x2f] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 0xb];
                          puVar19 = puVar19 + iVar8 * 0xc +
                                              iVar9 * 0xc +
                                              iVar10 * 0xc + *(int *)(iVar5 + 0x4c) * 0xc;
                          iVar20 = iVar20 + -1;
                          puVar15 = puVar16;
                        } while (iVar20 != 0);
                      }
                      if (iVar18 < local_64) {
                        iVar18 = local_64 - iVar18;
                        do {
                          *puVar16 = *puVar19;
                          puVar16[1] = puVar19[1];
                          puVar16[2] = puVar19[2];
                          puVar16[3] = puVar19[3];
                          puVar16[4] = puVar19[4];
                          puVar16[5] = puVar19[5];
                          puVar16[6] = puVar19[6];
                          puVar16[7] = puVar19[7];
                          puVar16[8] = puVar19[8];
                          puVar16[9] = puVar19[9];
                          puVar16[10] = puVar19[10];
                          puVar16[0xb] = puVar19[0xb];
                          puVar19 = puVar19 + *(int *)(iVar5 + 0x4c) * 0xc;
                          iVar18 = iVar18 + -1;
                          puVar16 = puVar16 + 0xc;
                        } while (iVar18 != 0);
                      }
                    }
                    else {
                      local_60 = 0;
                      if (0 < local_64) {
                        iVar18 = *(int *)(iVar13 + 0x14);
                        local_50 = local_64;
                        do {
                          iVar20 = 0;
                          if (0 < iVar18) {
                            piVar21 = (int *)(iVar13 + 0x18);
                            puVar16 = puVar7 + local_60 * 0xc + 2;
                            do {
                              puVar15 = puVar19 + ((*(int *)(*(int *)(iVar3 + 0x1e8) + *piVar21 * 4)
                                                   - *(int *)(iVar4 + 0x18c)) / 0x60) * 0xc;
                              local_60 = local_60 + 1;
                              iVar20 = iVar20 + 1;
                              piVar21 = piVar21 + 1;
                              puVar16[-2] = *puVar15;
                              puVar16[-1] = puVar15[1];
                              *puVar16 = puVar15[2];
                              puVar16[1] = puVar15[3];
                              puVar16[2] = puVar15[4];
                              puVar16[3] = puVar15[5];
                              puVar16[4] = puVar15[6];
                              puVar16[5] = puVar15[7];
                              puVar16[6] = puVar15[8];
                              puVar16[7] = puVar15[9];
                              puVar16[8] = puVar15[10];
                              puVar16[9] = puVar15[0xb];
                              iVar18 = *(int *)(iVar13 + 0x14);
                              puVar16 = puVar16 + 0xc;
                            } while (iVar20 < iVar18);
                          }
                          puVar19 = puVar19 + *(int *)(iVar5 + 0x4c) * 0xc;
                          local_50 = local_50 + -1;
                        } while (local_50 != 0);
                      }
                    }
                    *(undefined4 *)(DAT_00ef1b9c + 0xc) = 1;
                    FUN_005c2e80();
                    FUN_005d2bd0();
                    DAT_00a37de4 = DAT_00a37de4 + 1;
                  }
                  break;
                case 3:
                  FUN_005b93f0();
                  FUN_005ebb70();
                  FUN_005c2e80();
                  FUN_005d2bd0();
                  DAT_00a37de4 = DAT_00a37de4 + 1;
                }
              }
            }
            local_6c = local_6c + 1;
            local_68 = local_68 + 0x18;
            iVar13 = iVar13 + 0x138;
          } while (local_6c < *(int *)(iVar6 + 0x40));
        }
      }
      if (((*(int *)(iVar4 + 0x254) == 0) && (DAT_00dccde4 == 0)) ||
         ((*(int *)(iVar4 + 600) == 0 && (DAT_00dccde4 == 1)))) {
        piVar21 = (int *)param_1[2];
        if (((*(int *)(*piVar21 + 8) == 1) || (*(int *)(*piVar21 + 8) == 2)) &&
           ((_DAT_007d5924 < (float)piVar21[0x5e] || (_DAT_007d5924 < (float)piVar21[0x5f])))) {
          fVar1 = (float)piVar21[0x5e];
          if (DAT_00a380c4 == 0) {
            local_48 = (double)*(float *)(iVar3 + 0x10c);
            local_40 = (double)*(float *)(iVar3 + 0x11c);
            dVar2 = (double)*(float *)(iVar3 + 300);
          }
          else {
            local_48 = *(double *)(iVar3 + 0x118);
            local_40 = *(double *)(iVar3 + 0x138);
            dVar2 = *(double *)(iVar3 + 0x158);
          }
          FUN_00516300(local_18,local_48,local_40,dVar2);
          FUN_00516300(local_18,(double)((float)_DAT_00a38358 * fVar1 + (float)local_48),
                       (double)(fVar1 * (float)_DAT_00a38378 + (float)local_40),
                       (double)(fVar1 * (float)_DAT_00a38398 + (float)dVar2));
          FUN_005ea580();
          FUN_005eaef0();
          local_68 = param_1[0x2b];
          iVar13 = *(int *)(iVar6 + 0x44);
          local_6c = 0;
          if (0 < *(int *)(iVar6 + 0x40)) {
            do {
              if (((param_2 < 0) || (local_6c == param_2)) && (*(short *)(iVar13 + 0x118) != 0)) {
                if ((*(ushort *)(iVar13 + 4) == 0) && (*(int *)(iVar5 + 0x44) != 0)) {
                  uVar23 = 0x100000001;
                }
                else {
                  uVar23 = CONCAT44(1,(uint)*(ushort *)(iVar13 + 4));
                }
                iVar14 = FUN_005eaf60(uVar23);
                if (iVar14 != 0) {
                  FUN_005bb9e0(*(undefined4 *)(*(int *)(*(int *)(iVar13 + 0x124) + 0x14) + 4));
                  iVar14 = *(int *)(*(int *)(local_68 + 0xc) + 4);
                  if (iVar14 == 0) {
                    uVar23 = CONCAT44(*(undefined4 *)(*(int *)(iVar13 + 0x124) + 0x10),
                                      **(undefined4 **)(*(int *)(iVar13 + 0x124) + 0x14));
                  }
                  else {
                    uVar23 = CONCAT44(*(undefined4 *)(*(int *)(iVar13 + 0x124) + 0x10),iVar14);
                  }
                  FUN_005bb970(uVar23);
                  switch(*(short *)(iVar13 + 4)) {
                  case 0:
                    if (*(int *)(iVar5 + 0x44) != 0) goto switchD_005ed371_caseD_1;
                    FUN_005eb780();
                    FUN_005c2e80();
LAB_005ed3bd:
                    FUN_005d2bd0();
                    DAT_00a37de4 = DAT_00a37de4 + 1;
                    if ((DAT_00a380c4 != 0) && (!bVar11)) {
                      FUN_005b9490();
                    }
                    break;
                  case 1:
                  case 2:
switchD_005ed371_caseD_1:
                    if (*(int *)(iVar5 + 0x44) == 0) {
                      FUN_005eb960();
                      FUN_005c2e80();
                      goto LAB_005ed3bd;
                    }
                    puVar7 = *(undefined4 **)(DAT_00ef1b9c + 8);
                    if (*(short *)(iVar13 + 4) == 0) {
                      puVar19 = (undefined4 *)
                                (((iVar3 - *(int *)(iVar4 + 0x17c)) / 0x2b8 + *(int *)(iVar5 + 0xd8)
                                 ) * 0x30 + *(int *)(iVar4 + 0x194));
                    }
                    else {
                      puVar19 = *(undefined4 **)(iVar4 + 0x194);
                    }
                    for (iVar14 = *(int *)(iVar4 + 400); 0 < iVar14; iVar14 = iVar14 - local_64) {
                      local_64 = iVar14;
                      if (*(int *)(iVar13 + 0x120) < iVar14) {
                        local_64 = *(int *)(iVar13 + 0x120);
                      }
                      iVar18 = 0;
                      if (*(short *)(iVar13 + 4) == 0) {
                        puVar16 = puVar7;
                        if (3 < local_64) {
                          iVar20 = (local_64 - 4U >> 2) + 1;
                          iVar18 = iVar20 * 4;
                          puVar15 = puVar7;
                          do {
                            *puVar15 = *puVar19;
                            puVar15[1] = puVar19[1];
                            puVar15[2] = puVar19[2];
                            puVar15[3] = puVar19[3];
                            puVar15[4] = puVar19[4];
                            puVar15[5] = puVar19[5];
                            puVar15[6] = puVar19[6];
                            puVar15[7] = puVar19[7];
                            puVar15[8] = puVar19[8];
                            puVar15[9] = puVar19[9];
                            puVar15[10] = puVar19[10];
                            puVar15[0xb] = puVar19[0xb];
                            iVar8 = *(int *)(iVar5 + 0x4c);
                            puVar15[0xc] = puVar19[iVar8 * 0xc];
                            puVar15[0xd] = puVar19[iVar8 * 0xc + 1];
                            puVar15[0xe] = puVar19[iVar8 * 0xc + 2];
                            puVar15[0xf] = puVar19[iVar8 * 0xc + 3];
                            puVar15[0x10] = puVar19[iVar8 * 0xc + 4];
                            puVar15[0x11] = puVar19[iVar8 * 0xc + 5];
                            puVar15[0x12] = puVar19[iVar8 * 0xc + 6];
                            puVar15[0x13] = puVar19[iVar8 * 0xc + 7];
                            puVar15[0x14] = puVar19[iVar8 * 0xc + 8];
                            puVar15[0x15] = puVar19[iVar8 * 0xc + 9];
                            puVar15[0x16] = puVar19[iVar8 * 0xc + 10];
                            puVar15[0x17] = puVar19[iVar8 * 0xc + 0xb];
                            iVar9 = *(int *)(iVar5 + 0x4c);
                            puVar15[0x18] = puVar19[iVar8 * 0xc + iVar9 * 0xc];
                            puVar15[0x19] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 1];
                            puVar15[0x1a] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 2];
                            puVar15[0x1b] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 3];
                            puVar15[0x1c] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 4];
                            puVar15[0x1d] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 5];
                            puVar15[0x1e] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 6];
                            puVar15[0x1f] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 7];
                            puVar15[0x20] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 8];
                            puVar15[0x21] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 9];
                            puVar15[0x22] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 10];
                            puVar15[0x23] = puVar19[iVar8 * 0xc + iVar9 * 0xc + 0xb];
                            iVar10 = *(int *)(iVar5 + 0x4c);
                            puVar15[0x24] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc];
                            puVar16 = puVar15 + 0x30;
                            puVar15[0x25] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 1];
                            puVar15[0x26] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 2];
                            puVar15[0x27] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 3];
                            puVar15[0x28] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 4];
                            puVar15[0x29] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 5];
                            puVar15[0x2a] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 6];
                            puVar15[0x2b] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 7];
                            puVar15[0x2c] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 8];
                            puVar15[0x2d] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 9];
                            puVar15[0x2e] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 10];
                            puVar15[0x2f] = puVar19[iVar8 * 0xc + iVar9 * 0xc + iVar10 * 0xc + 0xb];
                            puVar19 = puVar19 + iVar8 * 0xc +
                                                iVar9 * 0xc +
                                                iVar10 * 0xc + *(int *)(iVar5 + 0x4c) * 0xc;
                            iVar20 = iVar20 + -1;
                            puVar15 = puVar16;
                          } while (iVar20 != 0);
                        }
                        if (iVar18 < local_64) {
                          iVar18 = local_64 - iVar18;
                          do {
                            *puVar16 = *puVar19;
                            puVar16[1] = puVar19[1];
                            puVar16[2] = puVar19[2];
                            puVar16[3] = puVar19[3];
                            puVar16[4] = puVar19[4];
                            puVar16[5] = puVar19[5];
                            puVar16[6] = puVar19[6];
                            puVar16[7] = puVar19[7];
                            puVar16[8] = puVar19[8];
                            puVar16[9] = puVar19[9];
                            puVar16[10] = puVar19[10];
                            puVar16[0xb] = puVar19[0xb];
                            puVar19 = puVar19 + *(int *)(iVar5 + 0x4c) * 0xc;
                            iVar18 = iVar18 + -1;
                            puVar16 = puVar16 + 0xc;
                          } while (iVar18 != 0);
                        }
                      }
                      else {
                        local_5c = 0;
                        if (0 < local_64) {
                          iVar18 = *(int *)(iVar13 + 0x14);
                          local_54 = local_64;
                          do {
                            iVar20 = 0;
                            if (0 < iVar18) {
                              piVar21 = (int *)(iVar13 + 0x18);
                              puVar16 = puVar7 + local_5c * 0xc + 2;
                              do {
                                puVar15 = puVar19 + ((*(int *)(*(int *)(iVar3 + 0x1e8) +
                                                              *piVar21 * 4) -
                                                     *(int *)(iVar4 + 0x18c)) / 0x60) * 0xc;
                                local_5c = local_5c + 1;
                                iVar20 = iVar20 + 1;
                                piVar21 = piVar21 + 1;
                                puVar16[-2] = *puVar15;
                                puVar16[-1] = puVar15[1];
                                *puVar16 = puVar15[2];
                                puVar16[1] = puVar15[3];
                                puVar16[2] = puVar15[4];
                                puVar16[3] = puVar15[5];
                                puVar16[4] = puVar15[6];
                                puVar16[5] = puVar15[7];
                                puVar16[6] = puVar15[8];
                                puVar16[7] = puVar15[9];
                                puVar16[8] = puVar15[10];
                                puVar16[9] = puVar15[0xb];
                                iVar18 = *(int *)(iVar13 + 0x14);
                                puVar16 = puVar16 + 0xc;
                              } while (iVar20 < iVar18);
                            }
                            puVar19 = puVar19 + *(int *)(iVar5 + 0x4c) * 0xc;
                            local_54 = local_54 + -1;
                          } while (local_54 != 0);
                        }
                      }
                      *(undefined4 *)(DAT_00ef1b9c + 0xc) = 1;
                      FUN_005c2e80();
                      FUN_005d2bd0();
                      DAT_00a37de4 = DAT_00a37de4 + 1;
                    }
                    break;
                  case 3:
                    FUN_005b93f0();
                    FUN_005ebb70();
                    FUN_005c2e80();
                    FUN_005d2bd0();
                    DAT_00a37de4 = DAT_00a37de4 + 1;
                  }
                }
              }
              local_6c = local_6c + 1;
              local_68 = local_68 + 0x18;
              iVar13 = iVar13 + 0x138;
            } while (local_6c < *(int *)(iVar6 + 0x40));
          }
        }
      }
    }
  }
  return;
}

