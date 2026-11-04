
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e5170(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined2 uVar5;
  ushort uVar6;
  int iVar7;
  char cVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  double *pdVar13;
  float *pfVar14;
  int iVar15;
  float *pfVar16;
  undefined4 uVar17;
  uint uVar18;
  int iVar19;
  int *piVar20;
  float *pfVar21;
  int iVar22;
  float *pfVar23;
  undefined4 uVar24;
  undefined2 in_FPUControlWord;
  float10 fVar25;
  float10 fVar26;
  undefined4 uVar27;
  undefined1 *puVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  float *local_2290;
  undefined4 *local_228c;
  float *local_2288;
  float local_2280;
  float *local_227c;
  uint local_2278;
  int local_2274;
  int local_226c;
  int local_2268;
  int local_2264;
  undefined4 *local_2260;
  int local_224c;
  uint local_2248;
  uint local_2244;
  int local_2240;
  undefined4 local_223c;
  undefined1 local_2238 [4];
  int local_2234;
  undefined4 local_2230;
  undefined4 *local_222c;
  uint local_2228;
  undefined4 *local_2224;
  int local_2220;
  int local_221c;
  int local_2218;
  float local_2214;
  float local_2210;
  float fStack_220c;
  float local_2208;
  float fStack_2204;
  float local_2200;
  float fStack_21fc;
  float local_21f8;
  float fStack_21f4;
  float local_21f0;
  float fStack_21ec;
  float local_21e8;
  float fStack_21e4;
  double local_21e0;
  double local_21d8;
  double local_21d0;
  double local_21c8;
  double local_21c0;
  double local_21b8;
  int local_21ac;
  int *local_21a8;
  uint local_21a4;
  double local_21a0;
  double local_2198;
  double local_2190;
  undefined4 local_2188;
  undefined4 uStack_2184;
  undefined4 local_2180;
  undefined4 local_217c;
  undefined4 local_2178;
  undefined4 local_2174;
  undefined4 local_2170 [54];
  undefined1 local_2098 [96];
  undefined1 local_2038 [24];
  undefined1 local_2020 [440];
  undefined4 local_1e68 [648];
  undefined1 local_1448 [5180];
  undefined4 uStack_c;
  
  uStack_c = 0x5e5180;
  local_2240 = param_1[1];
  iVar7 = *param_1;
  iVar22 = *(int *)(iVar7 + 8);
  local_2214 = *(float *)(iVar7 + 0x10);
  local_2220 = *(int *)(iVar22 + 0x40);
  local_2218 = iVar22;
  iVar9 = FUN_00567b30();
  if (iVar9 != 0) {
    local_2234 = 0;
    if (DAT_00a380c4 != 0) {
      iVar9 = 0;
      do {
        if ((&DAT_00a380f8)[iVar9] != 0) break;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 3);
      if (iVar9 != 3) {
        local_2234 = 1;
      }
    }
    local_223c = DAT_00e06938;
    local_224c = DAT_00e06934;
    local_2248 = DAT_00e0693c;
    local_2244 = DAT_00e06940;
    cVar8 = FUN_005e18d0(&local_224c,&local_223c,&local_2248,&local_2244,local_2020,param_1,
                         local_2238);
    if (cVar8 != '\0') {
      if (*(int *)(iVar22 + 0x250) == 0) {
        local_226c = param_1[0x2b];
        local_2274 = *(int *)(local_2240 + 0x44);
        local_2268 = -1;
        local_221c = 0;
        if (0 < *(int *)(local_2240 + 0x40)) {
          do {
            if ((param_2 < 0) || (local_221c == param_2)) {
              switch(*(short *)(local_2274 + 4)) {
              case 0:
                if (((*(int *)(local_2274 + 0x124) == 0) ||
                    (iVar22 = *(int *)(*(int *)(local_2274 + 0x124) + 0x14),
                    *(int *)(iVar22 + 4) == 0)) || (*(int *)(iVar22 + 8) == 0)) goto LAB_005e5582;
                if (*(int *)(local_2220 + 0x44) != 0) goto switchD_005e52b4_caseD_1;
                if (DAT_00dccde4 == 0) {
                  uVar30 = CONCAT44(local_2244,local_223c);
                  uVar29 = CONCAT44(local_2248,local_224c);
LAB_005e537a:
                  iVar22 = FUN_0059f7e0(uVar29,uVar30);
                  if (iVar22 != 0) {
                    FUN_0059b6b0();
                    if (**(int **)(local_226c + 0xc) == 0) {
                      iVar22 = *(int *)(*(int *)(*(int *)(local_2274 + 0x124) + 0x14) + 4);
                    }
                    else {
                      iVar22 = **(int **)(local_226c + 0xc);
                    }
                    FUN_0059b8e0(iVar22);
                    if (local_2268 != 1) {
                      FUN_005de710();
                      local_2268 = 1;
                    }
                    FUN_0059b940();
                    if (DAT_00a380c4 == 0) {
                      puVar12 = (undefined4 *)(iVar7 + 0x100);
                    }
                    else if (local_2234 == 0) {
                      FUN_00582890(local_2098);
                      uVar29 = CONCAT44(local_2098,iVar7 + 0x100);
                      puVar28 = local_1448;
                      FUN_00582380();
                      FUN_005829a0(local_1e68,local_1448,puVar28,uVar29);
                      FUN_005a02f0(&DAT_00a05418);
                      puVar12 = local_1e68;
                    }
                    else {
                      FUN_005829a0(local_1e68);
                      puVar12 = local_1e68;
                    }
                    FUN_0059cb80(&DAT_00ddb600,0,0,0x5e,puVar12,3);
                    if (**(int **)(local_226c + 0xc) == 0) {
                      uVar24 = *(undefined4 *)(local_2274 + 0x128);
                    }
                    else {
                      uVar24 = 0;
                    }
                    FUN_005d3b10(4,uVar24,0,*(undefined4 *)(local_2274 + 0xc),
                                 *(undefined4 *)(local_2274 + 300));
                    DAT_00a37de4 = DAT_00a37de4 + 1;
                    if ((DAT_00a380c4 != 0) && (local_2234 == 0)) {
                      FUN_005a02f0();
                    }
                    goto switchD_005e52b4_default;
                  }
                }
                else if ((DAT_00a38dd8 < 1) || (iVar22 = FUN_005a0ca0(), -1 < iVar22)) {
                  if (DAT_00a38ddc < 1) {
LAB_005e5337:
                    uVar18 = local_223c;
                  }
                  else {
                    iVar22 = FUN_005a0d10();
                    if (iVar22 < 0) goto LAB_005e5582;
                    if (DAT_00a38ddc < 1) goto LAB_005e5337;
                    uVar18 = 0xffffffff;
                  }
                  if (DAT_00a38dd8 < 1) {
                    uVar30 = CONCAT44(local_2244,uVar18);
                    uVar29 = CONCAT44(local_2248,local_224c);
                  }
                  else {
                    uVar30 = CONCAT44(local_2244,uVar18);
                    uVar29 = CONCAT44(local_2248,0xffffffff);
                  }
                  goto LAB_005e537a;
                }
LAB_005e5582:
                if (*(char *)(iVar7 + 0x161) == '\0') {
                  *(undefined1 *)(iVar7 + 0x161) = 1;
                  FUN_005829f0(iVar7 + 0x164);
                }
                FUN_00519a30();
                DAT_00dda468 = 0;
                if (local_2268 != 0) {
                  FUN_005de710();
                  local_2268 = 0;
                }
                FUN_0059b780();
                FUN_0059b870(0);
                if (*(int *)(local_2274 + 0xf8) == 0) {
                  FUN_005dfb70();
                }
                if (*(char *)(local_2240 + 0x4a) != '\0') {
                  iVar9 = *(int *)(local_2274 + 0xc);
                  uVar18 = (uint)*(ushort *)(local_2274 + 8);
                  puVar12 = *(undefined4 **)(local_2274 + 0xf8);
                  puVar10 = (undefined4 *)(*(int *)(local_226c + 8) + 0xfU & 0xfffffff0);
                  iVar22 = 0;
                  if (3 < iVar9) {
                    iVar15 = (iVar9 - 4U >> 2) + 1;
                    iVar22 = iVar15 * 4;
                    puVar11 = puVar10;
                    do {
                      puVar10 = puVar11 + 0x20;
                      *puVar12 = *puVar11;
                      puVar12[1] = puVar11[1];
                      puVar12[2] = puVar11[2];
                      puVar12 = (undefined4 *)((int)puVar12 + uVar18);
                      *puVar12 = puVar11[8];
                      puVar12[1] = puVar11[9];
                      puVar12[2] = puVar11[10];
                      puVar12 = (undefined4 *)((int)puVar12 + uVar18);
                      *puVar12 = puVar11[0x10];
                      puVar12[1] = puVar11[0x11];
                      puVar12[2] = puVar11[0x12];
                      puVar12 = (undefined4 *)((int)puVar12 + uVar18);
                      *puVar12 = puVar11[0x18];
                      puVar12[1] = puVar11[0x19];
                      puVar12[2] = puVar11[0x1a];
                      puVar12 = (undefined4 *)((int)puVar12 + uVar18);
                      iVar15 = iVar15 + -1;
                      puVar11 = puVar10;
                    } while (iVar15 != 0);
                  }
                  if (iVar22 < iVar9) {
                    iVar9 = iVar9 - iVar22;
                    do {
                      *puVar12 = *puVar10;
                      puVar12[1] = puVar10[1];
                      puVar12[2] = puVar10[2];
                      puVar12 = (undefined4 *)((int)puVar12 + uVar18);
                      iVar9 = iVar9 + -1;
                      puVar10 = puVar10 + 8;
                    } while (iVar9 != 0);
                  }
                }
                if ((*(int *)(*(int *)param_1[2] + 8) == 1) ||
                   (*(int *)(*(int *)param_1[2] + 8) == 2)) {
                  FUN_005dff40(local_2274);
                }
                FUN_0059b720(0);
                FUN_0059b820(0);
                FUN_0059b940();
                FUN_0059b8e0(0);
                FUN_005a0c60(*(uint *)(&DAT_00a05460 + *(int *)(local_2240 + 0x4c) * 4) | 0xd2);
                uVar5 = *(undefined2 *)(local_2274 + 8);
                uVar24 = *(undefined4 *)(local_2274 + 0xf8);
                uVar17 = *(undefined4 *)(local_2274 + 0x114);
                break;
              case 1:
              case 2:
switchD_005e52b4_caseD_1:
                if (*(short *)(local_2274 + 4) == 2) {
                  iVar9 = local_224c + 0x280;
                  iVar22 = local_2248 + 0x10;
                }
                else {
                  iVar9 = local_224c + 0x140;
                  iVar22 = local_2248 + 8;
                }
                if (((*(int *)(local_2274 + 0x124) != 0) &&
                    (iVar15 = *(int *)(*(int *)(local_2274 + 0x124) + 0x14),
                    *(int *)(iVar15 + 4) != 0)) && (*(int *)(iVar15 + 8) != 0)) {
                  if (DAT_00dccde4 == 0) {
                    uVar30 = CONCAT44(local_2244,local_223c);
                    uVar29 = CONCAT44(iVar22,iVar9);
                  }
                  else {
                    if ((0 < DAT_00a38dd8) && (iVar15 = FUN_005a0ca0(), iVar15 < 0))
                    goto LAB_005e5e17;
                    if (DAT_00a38ddc < 1) {
LAB_005e58d5:
                      uVar18 = local_223c;
                    }
                    else {
                      iVar15 = FUN_005a0d10();
                      if (iVar15 < 0) goto LAB_005e5e17;
                      if (DAT_00a38ddc < 1) goto LAB_005e58d5;
                      uVar18 = 0xffffffff;
                    }
                    if (DAT_00a38dd8 < 1) {
                      uVar30 = CONCAT44(local_2244,uVar18);
                      uVar29 = CONCAT44(iVar22,iVar9);
                    }
                    else {
                      uVar30 = CONCAT44(local_2244,uVar18);
                      uVar29 = CONCAT44(iVar22,0xffffffff);
                    }
                  }
                  iVar22 = FUN_0059f7e0(uVar29,uVar30);
                  if (iVar22 != 0) {
                    FUN_0059b6b0();
                    if (local_2268 != 1) {
                      FUN_005de710();
                      local_2268 = 1;
                    }
                    if (**(int **)(local_226c + 0xc) == 0) {
                      iVar22 = *(int *)(*(int *)(*(int *)(local_2274 + 0x124) + 0x14) + 4);
                    }
                    else {
                      iVar22 = **(int **)(local_226c + 0xc);
                    }
                    FUN_0059b8e0(iVar22);
                    FUN_0059b940();
                    if (*(int *)(local_2220 + 0x44) == 0) {
                      if (DAT_00a380c4 == 0) {
                        iVar22 = 0;
                        if (0 < *(int *)(local_2274 + 0x14)) {
                          puVar12 = local_1e68;
                          piVar20 = (int *)(local_2274 + 0x18);
                          do {
                            puVar10 = *(undefined4 **)(*(int *)(iVar7 + 0x1e8) + *piVar20 * 4);
                            puVar11 = puVar12;
                            for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
                              *puVar11 = *puVar10;
                              puVar10 = puVar10 + 1;
                              puVar11 = puVar11 + 1;
                            }
                            iVar22 = iVar22 + 1;
                            piVar20 = piVar20 + 1;
                            puVar12 = puVar12 + 0xc;
                          } while (iVar22 < *(int *)(local_2274 + 0x14));
                        }
                      }
                      else if (local_2234 == 0) {
                        FUN_00582890(local_2098);
                        local_2280 = 0.0;
                        if (0 < *(int *)(local_2274 + 0x14)) {
                          do {
                            FUN_00582380();
                            FUN_005829a0();
                            local_2280 = (float)((int)local_2280 + 1);
                          } while ((int)local_2280 < *(int *)(local_2274 + 0x14));
                        }
                        FUN_005a02f0();
                      }
                      else {
                        iVar22 = 0;
                        if (0 < *(int *)(local_2274 + 0x14)) {
                          puVar12 = local_1e68;
                          do {
                            FUN_005829a0(puVar12);
                            iVar22 = iVar22 + 1;
                            puVar12 = puVar12 + 0xc;
                          } while (iVar22 < *(int *)(local_2274 + 0x14));
                        }
                      }
                      FUN_0059cb80(&DAT_00ddb600,0,0,0x5e,local_1e68,*(int *)(local_2274 + 0x14) * 3
                                  );
                      if (**(int **)(local_226c + 0xc) == 0) {
                        uVar24 = *(undefined4 *)(local_2274 + 0x128);
                      }
                      else {
                        uVar24 = 0;
                      }
                      FUN_005d3b10(4,uVar24,0,*(undefined4 *)(local_2274 + 0xc),
                                   *(undefined4 *)(local_2274 + 300));
                      DAT_00a37de4 = DAT_00a37de4 + 1;
                      if ((DAT_00a380c4 != 0) && (local_2234 == 0)) {
                        FUN_005a02f0();
                      }
                    }
                    else {
                      if (*(short *)(local_2274 + 4) == 0) {
                        local_2290 = (float *)(((iVar7 - *(int *)(local_2218 + 0x17c)) / 0x2b8 +
                                               *(int *)(local_2220 + 0xd8)) * 0x30 +
                                              *(int *)(local_2218 + 0x194));
                      }
                      else {
                        local_2290 = *(float **)(local_2218 + 0x194);
                      }
                      for (local_2228 = *(uint *)(local_2218 + 400); 0 < (int)local_2228;
                          local_2228 = local_2228 - local_2278) {
                        local_2278 = local_2228;
                        if ((int)*(uint *)(local_2274 + 0x120) < (int)local_2228) {
                          local_2278 = *(uint *)(local_2274 + 0x120);
                        }
                        if (*(short *)(local_2274 + 4) == 0) {
                          if (0 < (int)local_2278) {
                            puVar12 = local_1e68;
                            local_228c = (undefined4 *)local_2278;
                            do {
                              puVar10 = local_2290;
                              puVar11 = puVar12;
                              for (iVar22 = 0xc; iVar22 != 0; iVar22 = iVar22 + -1) {
                                *puVar11 = *puVar10;
                                puVar10 = puVar10 + 1;
                                puVar11 = puVar11 + 1;
                              }
                              puVar12 = puVar12 + 0xc;
                              local_2290 = local_2290 + *(int *)(local_2220 + 0x4c) * 0xc;
                              local_228c = (undefined4 *)((int)local_228c - 1);
                            } while (local_228c != (undefined4 *)0x0);
                          }
                        }
                        else {
                          local_227c = (float *)0x0;
                          if (0 < (int)local_2278) {
                            iVar22 = *(int *)(local_2274 + 0x14);
                            local_228c = (undefined4 *)local_2278;
                            do {
                              local_2280 = 0.0;
                              if (0 < iVar22) {
                                piVar20 = (int *)(local_2274 + 0x18);
                                local_2224 = local_1e68 + (int)local_227c * 0xc;
                                do {
                                  local_227c = (float *)((int)local_227c + 1);
                                  puVar12 = local_2224 + 0xc;
                                  puVar10 = local_2290 +
                                            ((*(int *)(*(int *)(iVar7 + 0x1e8) + *piVar20 * 4) -
                                             *(int *)(local_2218 + 0x18c)) / 0x60) * 0xc;
                                  for (iVar22 = 0xc; iVar22 != 0; iVar22 = iVar22 + -1) {
                                    *local_2224 = *puVar10;
                                    puVar10 = puVar10 + 1;
                                    local_2224 = local_2224 + 1;
                                  }
                                  iVar22 = *(int *)(local_2274 + 0x14);
                                  local_2280 = (float)((int)local_2280 + 1);
                                  piVar20 = piVar20 + 1;
                                  local_2224 = puVar12;
                                } while ((int)local_2280 < iVar22);
                              }
                              local_2290 = local_2290 + *(int *)(local_2220 + 0x4c) * 0xc;
                              local_228c = (undefined4 *)((int)local_228c - 1);
                            } while (local_228c != (undefined4 *)0x0);
                          }
                        }
                        iVar22 = 1;
                        if (*(short *)(local_2274 + 4) != 0) {
                          iVar22 = *(int *)(local_2274 + 0x14);
                        }
                        FUN_0059cb80(&DAT_00ddb600,0,0,0x5e,local_1e68,iVar22 * local_2278 * 3);
                        FUN_005d3b10();
                        DAT_00a37de4 = DAT_00a37de4 + 1;
                      }
                    }
                    goto switchD_005e52b4_default;
                  }
                }
LAB_005e5e17:
                if (local_2268 != 0) {
                  FUN_005de710();
                  local_2268 = 0;
                }
                FUN_0059b780();
                FUN_0059b870(0);
                if (DAT_00dda468 == 0) {
                  DAT_00dda468 = 1;
                  FUN_00519a30();
                }
                if (*(int *)(local_2274 + 0xf8) == 0) {
                  FUN_005dfb70();
                }
                uVar18 = (uint)*(ushort *)(local_2274 + 8);
                pfVar21 = *(float **)(local_2274 + 0xf8);
                local_228c = *(undefined4 **)(local_2274 + 0xc);
                iVar22 = 0;
                if (0 < *(int *)(local_2274 + 0x14)) {
                  iVar9 = *(int *)(iVar7 + 0x1e8);
                  piVar20 = (int *)(local_2274 + 0x18);
                  do {
                    local_2170[iVar22] = *(undefined4 *)(iVar9 + *piVar20 * 4);
                    iVar22 = iVar22 + 1;
                    piVar20 = piVar20 + 1;
                  } while (iVar22 < *(int *)(local_2274 + 0x14));
                }
                if (*(short *)(local_2274 + 4) == 1) {
                  if (*(char *)(local_2240 + 0x4a) == '\0') {
                    iVar22 = *(int *)(local_2274 + 0x108);
                  }
                  else {
                    iVar22 = *(int *)(local_226c + 8);
                  }
                  pfVar23 = (float *)(iVar22 + 0xfU & 0xfffffff0);
                  local_2288 = pfVar21;
                  if (DAT_00a380c4 == 0) {
                    if (0 < (int)local_228c) {
                      local_2290 = pfVar21 + 5;
                      pfVar21 = pfVar23 + 6;
                      do {
                        uVar24 = local_2170[*(byte *)(pfVar21 + 5)];
                        if (*pfVar23 == 1.0) {
                          uVar29 = CONCAT44(uVar24,pfVar21 + -2);
                          pfVar14 = local_2288;
                          FUN_005826d0();
                          FUN_00582790(local_2290 + -2,pfVar21 + 2,uVar24,pfVar14,uVar29);
                        }
                        else {
                          FUN_005824c0();
                          iVar22 = 1;
                          do {
                            if (pfVar23[iVar22] != 0.0) {
                              FUN_005825a0();
                            }
                            iVar22 = iVar22 + 1;
                          } while (iVar22 < 4);
                          *local_2288 = fStack_2204 +
                                        local_2208 * *pfVar21 +
                                        fStack_220c * pfVar21[-1] + local_2210 * pfVar21[-2];
                          local_2290[-4] =
                               fStack_21f4 +
                               local_21f8 * *pfVar21 +
                               local_2200 * pfVar21[-2] + fStack_21fc * pfVar21[-1];
                          local_2290[-3] =
                               local_21e8 * *pfVar21 +
                               local_21f0 * pfVar21[-2] + fStack_21ec * pfVar21[-1] + fStack_21e4;
                          local_2290[-2] =
                               pfVar21[2] * local_2210 + pfVar21[3] * fStack_220c +
                               pfVar21[4] * local_2208;
                          local_2290[-1] =
                               local_21f8 * pfVar21[4] +
                               local_2200 * pfVar21[2] + pfVar21[3] * fStack_21fc;
                          *local_2290 = local_21e8 * pfVar21[4] +
                                        local_21f0 * pfVar21[2] + fStack_21ec * pfVar21[3];
                        }
                        local_2290 = (float *)((int)local_2290 + uVar18);
                        local_2288 = (float *)((int)local_2288 + uVar18);
                        pfVar23 = pfVar23 + 0xc;
                        pfVar21 = pfVar21 + 0xc;
                        local_228c = (undefined4 *)((int)local_228c + -1);
                      } while (local_228c != (undefined4 *)0x0);
                    }
                  }
                  else if (0 < (int)local_228c) {
                    local_2290 = pfVar21 + 5;
                    pfVar21 = pfVar23 + 6;
                    do {
                      uVar24 = local_2170[*(byte *)(pfVar21 + 5)];
                      if (*pfVar23 == 1.0) {
                        uVar29 = CONCAT44(uVar24,pfVar21 + -2);
                        pfVar14 = local_2288;
                        FUN_00582730();
                        FUN_005827f0(local_2290 + -2,pfVar21 + 2,uVar24,pfVar14,uVar29);
                      }
                      else {
                        FUN_00582530();
                        iVar22 = 1;
                        do {
                          if (pfVar23[iVar22] != 0.0) {
                            FUN_00582640();
                          }
                          iVar22 = iVar22 + 1;
                        } while (iVar22 < 4);
                        *local_2288 = pfVar21[-2] * (float)(double)CONCAT44(fStack_220c,local_2210)
                                      + pfVar21[-1] *
                                        (float)(double)CONCAT44(fStack_2204,local_2208) +
                                      *pfVar21 * (float)(double)CONCAT44(fStack_21fc,local_2200) +
                                      (float)(double)CONCAT44(fStack_21f4,local_21f8);
                        local_2290[-4] =
                             *pfVar21 * (float)local_21e0 +
                             pfVar21[-2] * (float)(double)CONCAT44(fStack_21ec,local_21f0) +
                             pfVar21[-1] * (float)(double)CONCAT44(fStack_21e4,local_21e8) +
                             (float)local_21d8;
                        local_2290[-3] =
                             pfVar21[-1] * (float)local_21c8 + pfVar21[-2] * (float)local_21d0 +
                             *pfVar21 * (float)local_21c0 + (float)local_21b8;
                        local_2290[-2] =
                             pfVar21[2] * (float)(double)CONCAT44(fStack_220c,local_2210) +
                             pfVar21[3] * (float)(double)CONCAT44(fStack_2204,local_2208) +
                             pfVar21[4] * (float)(double)CONCAT44(fStack_21fc,local_2200);
                        local_2290[-1] =
                             pfVar21[4] * (float)local_21e0 +
                             (float)(double)CONCAT44(fStack_21e4,local_21e8) * pfVar21[3] +
                             pfVar21[2] * (float)(double)CONCAT44(fStack_21ec,local_21f0);
                        *local_2290 = pfVar21[3] * (float)local_21c8 +
                                      pfVar21[2] * (float)local_21d0 +
                                      pfVar21[4] * (float)local_21c0;
                      }
                      local_2290 = (float *)((int)local_2290 + uVar18);
                      local_2288 = (float *)((int)local_2288 + uVar18);
                      pfVar23 = pfVar23 + 0xc;
                      pfVar21 = pfVar21 + 0xc;
                      local_228c = (undefined4 *)((int)local_228c + -1);
                    } while (local_228c != (undefined4 *)0x0);
                  }
                }
                else if (*(short *)(local_2274 + 4) == 2) {
                  if (*(char *)(local_2240 + 0x4a) == '\0') {
                    iVar22 = *(int *)(local_2274 + 0x108);
                  }
                  else {
                    iVar22 = *(int *)(local_226c + 8);
                  }
                  local_2288 = (float *)(iVar22 + 0xfU & 0xfffffff0);
                  if (DAT_00a380c4 == 0) {
                    if (0 < (int)local_228c) {
                      local_2290 = pfVar21 + 5;
                      pfVar23 = local_2288 + 0xe;
                      local_222c = local_228c;
                      do {
                        uVar24 = local_2170[*(byte *)(pfVar23 + -3)];
                        if (*local_2288 == 1.0) {
                          uVar29 = CONCAT44(uVar24,pfVar23 + -2);
                          pfVar14 = pfVar21;
                          FUN_005826d0();
                          FUN_00582790(local_2290 + -2,pfVar23 + -6,uVar24,pfVar14,uVar29);
                        }
                        else {
                          FUN_005824c0();
                          iVar22 = 1;
                          do {
                            if (local_2288[iVar22] != 0.0) {
                              FUN_005825a0();
                            }
                            iVar22 = iVar22 + 1;
                          } while (iVar22 < 4);
                          pfVar14 = pfVar23 + -10;
                          local_228c = (undefined4 *)0x4;
                          do {
                            if (*pfVar14 != 0.0) {
                              FUN_005825a0();
                            }
                            pfVar14 = pfVar14 + 1;
                            local_228c = (undefined4 *)((int)local_228c + -1);
                          } while (local_228c != (undefined4 *)0x0);
                          *pfVar21 = fStack_2204 +
                                     local_2208 * *pfVar23 +
                                     fStack_220c * pfVar23[-1] + local_2210 * pfVar23[-2];
                          local_2290[-4] =
                               fStack_21f4 +
                               local_21f8 * *pfVar23 +
                               local_2200 * pfVar23[-2] + fStack_21fc * pfVar23[-1];
                          local_2290[-3] =
                               local_21e8 * *pfVar23 +
                               local_21f0 * pfVar23[-2] + fStack_21ec * pfVar23[-1] + fStack_21e4;
                          local_2290[-2] =
                               pfVar23[-5] * fStack_220c + pfVar23[-6] * local_2210 +
                               pfVar23[-4] * local_2208;
                          local_2290[-1] =
                               local_21f8 * pfVar23[-4] +
                               fStack_21fc * pfVar23[-5] + pfVar23[-6] * local_2200;
                          *local_2290 = local_21e8 * pfVar23[-4] +
                                        local_21f0 * pfVar23[-6] + fStack_21ec * pfVar23[-5];
                        }
                        local_2288 = local_2288 + 0x10;
                        local_2290 = (float *)((int)local_2290 + uVar18);
                        pfVar23 = pfVar23 + 0x10;
                        pfVar21 = (float *)((int)pfVar21 + uVar18);
                        local_222c = (undefined4 *)((int)local_222c + -1);
                      } while (local_222c != (undefined4 *)0x0);
                      local_222c = (undefined4 *)0x0;
                    }
                  }
                  else if (0 < (int)local_228c) {
                    local_2290 = pfVar21 + 5;
                    pfVar23 = local_2288 + 0xe;
                    do {
                      uVar24 = local_2170[*(byte *)(pfVar23 + -3)];
                      if (*local_2288 == 1.0) {
                        uVar29 = CONCAT44(uVar24,pfVar23 + -2);
                        pfVar14 = pfVar21;
                        FUN_00582730();
                        FUN_005827f0(local_2290 + -2,pfVar23 + -6,uVar24,pfVar14,uVar29);
                      }
                      else {
                        FUN_00582530();
                        iVar22 = 1;
                        do {
                          if (local_2288[iVar22] != 0.0) {
                            FUN_00582640();
                          }
                          iVar22 = iVar22 + 1;
                        } while (iVar22 < 4);
                        local_227c = pfVar23 + -10;
                        iVar22 = 0;
                        do {
                          if (*local_227c != 0.0) {
                            FUN_00582640();
                          }
                          local_227c = local_227c + 1;
                          iVar22 = iVar22 + 1;
                        } while (iVar22 < 4);
                        *pfVar21 = pfVar23[-2] * (float)(double)CONCAT44(fStack_220c,local_2210) +
                                   pfVar23[-1] * (float)(double)CONCAT44(fStack_2204,local_2208) +
                                   *pfVar23 * (float)(double)CONCAT44(fStack_21fc,local_2200) +
                                   (float)(double)CONCAT44(fStack_21f4,local_21f8);
                        local_2290[-4] =
                             *pfVar23 * (float)local_21e0 +
                             pfVar23[-2] * (float)(double)CONCAT44(fStack_21ec,local_21f0) +
                             pfVar23[-1] * (float)(double)CONCAT44(fStack_21e4,local_21e8) +
                             (float)local_21d8;
                        local_2290[-3] =
                             pfVar23[-1] * (float)local_21c8 + pfVar23[-2] * (float)local_21d0 +
                             *pfVar23 * (float)local_21c0 + (float)local_21b8;
                        local_2290[-2] =
                             pfVar23[-6] * (float)(double)CONCAT44(fStack_220c,local_2210) +
                             pfVar23[-5] * (float)(double)CONCAT44(fStack_2204,local_2208) +
                             pfVar23[-4] * (float)(double)CONCAT44(fStack_21fc,local_2200);
                        local_2290[-1] =
                             pfVar23[-4] * (float)local_21e0 +
                             (float)(double)CONCAT44(fStack_21e4,local_21e8) * pfVar23[-5] +
                             pfVar23[-6] * (float)(double)CONCAT44(fStack_21ec,local_21f0);
                        *local_2290 = pfVar23[-5] * (float)local_21c8 +
                                      pfVar23[-6] * (float)local_21d0 +
                                      pfVar23[-4] * (float)local_21c0;
                      }
                      local_2288 = local_2288 + 0x10;
                      local_2290 = (float *)((int)local_2290 + uVar18);
                      pfVar23 = pfVar23 + 0x10;
                      pfVar21 = (float *)((int)pfVar21 + uVar18);
                      local_228c = (undefined4 *)((int)local_228c + -1);
                    } while (local_228c != (undefined4 *)0x0);
                  }
                }
                if ((*(int *)(*(int *)param_1[2] + 8) == 1) ||
                   (*(int *)(*(int *)param_1[2] + 8) == 2)) {
                  iVar22 = *(int *)(local_2274 + 0x14);
                  iVar9 = 0;
                  if (DAT_00a380c4 == 0) {
                    if (0 < iVar22) {
                      do {
                        iVar9 = iVar9 + 1;
                      } while (iVar9 < iVar22);
                    }
                  }
                  else if (0 < iVar22) {
                    do {
                      iVar9 = iVar9 + 1;
                    } while (iVar9 < iVar22);
                  }
                  FUN_005dff40(local_2274);
                }
                FUN_0059b720(0);
                FUN_0059b820(0);
                FUN_0059b940();
                FUN_0059b8e0(0);
                FUN_005a0c60(*(uint *)(&DAT_00a05460 + *(int *)(local_2240 + 0x4c) * 4) | 0xd2);
                uVar5 = *(undefined2 *)(local_2274 + 8);
                uVar24 = *(undefined4 *)(local_2274 + 0xf8);
                uVar17 = *(undefined4 *)(local_2274 + 0x114);
                uVar6 = *(ushort *)(local_2274 + 0x110);
                uVar27 = *(undefined4 *)(local_2274 + 0xc);
                goto LAB_005e75ee;
              case 3:
                if (local_2268 != 0) {
                  FUN_005de710();
                  local_2268 = 0;
                }
                FUN_0059b780();
                FUN_0059b870(0);
                if (DAT_00dda468 == 0) {
                  DAT_00dda468 = 1;
                  FUN_00519a30();
                }
                if (*(int *)(local_2274 + 0xf8) == 0) {
                  FUN_005dfb70();
                }
                uVar18 = (uint)*(ushort *)(local_2274 + 8);
                local_2230 = (uint)*(ushort *)(local_2274 + 6);
                local_2288 = *(float **)(local_2274 + 0xf8);
                if (*(char *)(local_2240 + 0x4a) == '\0') {
                  iVar22 = *(int *)(local_2274 + 0x108);
                }
                else {
                  iVar22 = *(int *)(local_226c + 8);
                }
                iVar9 = *(int *)(local_2274 + 0x10);
                iVar15 = *(int *)((int)local_2214 + 0x188);
                pfVar21 = (float *)(iVar22 + 0xfU & 0xfffffff0);
                local_228c = *(undefined4 **)(local_2274 + 0xc);
                if (iVar15 < 0x36) {
                  if (0 < iVar15) {
                    puVar12 = *(undefined4 **)(iVar7 + 0x1e8);
                    puVar10 = local_2170;
                    for (; iVar15 != 0; iVar15 = iVar15 + -1) {
                      *puVar10 = *puVar12;
                      puVar12 = puVar12 + 1;
                      puVar10 = puVar10 + 1;
                    }
                  }
                  if (DAT_00a380c4 == 0) {
                    if (0 < (int)local_228c) {
                      local_2290 = local_2288 + 5;
                      pfVar23 = pfVar21 + 5;
                      do {
                        if (pfVar23[4] == 1.0) {
                          pfVar14 = (float *)local_2170[(int)pfVar23[3]];
                          FUN_005826d0();
                          local_2290[-2] =
                               pfVar14[2] * pfVar23[1] +
                               *pfVar14 * pfVar23[-1] + pfVar14[1] * *pfVar23;
                          local_2290[-1] =
                               pfVar14[6] * pfVar23[1] +
                               pfVar14[4] * pfVar23[-1] + pfVar14[5] * *pfVar23;
                          *local_2290 = pfVar14[10] * pfVar23[1] +
                                        pfVar14[8] * pfVar23[-1] + pfVar14[9] * *pfVar23;
                        }
                        else {
                          pfVar14 = pfVar23 + 5;
                          FUN_005824c0();
                          local_2264 = 1;
                          if (1 < iVar9) {
                            do {
                              if (*pfVar14 == -NAN) break;
                              if (pfVar14[1] != 0.0) {
                                FUN_005825a0();
                              }
                              local_2264 = local_2264 + 1;
                              pfVar14 = pfVar14 + 2;
                            } while (local_2264 < iVar9);
                          }
                          *local_2288 = fStack_2204 +
                                        local_2208 * pfVar23[-3] +
                                        fStack_220c * pfVar23[-4] + local_2210 * *pfVar21;
                          local_2290[-4] =
                               fStack_21f4 +
                               local_21f8 * pfVar23[-3] +
                               fStack_21fc * pfVar23[-4] + local_2200 * *pfVar21;
                          local_2290[-3] =
                               local_21e8 * pfVar23[-3] +
                               fStack_21ec * pfVar23[-4] + local_21f0 * *pfVar21 + fStack_21e4;
                          local_2290[-2] =
                               pfVar23[-1] * local_2210 + *pfVar23 * fStack_220c +
                               pfVar23[1] * local_2208;
                          local_2290[-1] =
                               local_21f8 * pfVar23[1] +
                               fStack_21fc * *pfVar23 + pfVar23[-1] * local_2200;
                          *local_2290 = local_21e8 * pfVar23[1] +
                                        local_21f0 * pfVar23[-1] + fStack_21ec * *pfVar23;
                        }
                        local_2288 = (float *)((int)local_2288 + uVar18);
                        local_2290 = (float *)((int)local_2290 + uVar18);
                        pfVar21 = (float *)((int)pfVar21 + local_2230);
                        pfVar23 = (float *)((int)pfVar23 + local_2230);
                        local_228c = (undefined4 *)((int)local_228c + -1);
                      } while (local_228c != (undefined4 *)0x0);
                    }
                  }
                  else if (0 < (int)local_228c) {
                    local_2290 = local_2288 + 5;
                    pfVar23 = pfVar21 + 5;
                    do {
                      if (pfVar23[4] == 1.0) {
                        pdVar13 = (double *)local_2170[(int)pfVar23[3]];
                        FUN_00582730();
                        local_2290[-2] =
                             pfVar23[1] * (float)pdVar13[2] +
                             pfVar23[-1] * (float)*pdVar13 + *pfVar23 * (float)pdVar13[1];
                        local_2290[-1] =
                             pfVar23[1] * (float)pdVar13[6] +
                             pfVar23[-1] * (float)pdVar13[4] + *pfVar23 * (float)pdVar13[5];
                        *local_2290 = pfVar23[1] * (float)pdVar13[10] +
                                      pfVar23[-1] * (float)pdVar13[8] + *pfVar23 * (float)pdVar13[9]
                        ;
                      }
                      else {
                        pfVar14 = pfVar23 + 5;
                        FUN_00582530();
                        local_2264 = 1;
                        if (1 < iVar9) {
                          do {
                            if (*pfVar14 == -NAN) break;
                            if (pfVar14[1] != 0.0) {
                              FUN_00582640();
                            }
                            local_2264 = local_2264 + 1;
                            pfVar14 = pfVar14 + 2;
                          } while (local_2264 < iVar9);
                        }
                        *local_2288 = pfVar23[-4] * (float)(double)CONCAT44(fStack_2204,local_2208)
                                      + *pfVar21 * (float)(double)CONCAT44(fStack_220c,local_2210) +
                                      pfVar23[-3] * (float)(double)CONCAT44(fStack_21fc,local_2200)
                                      + (float)(double)CONCAT44(fStack_21f4,local_21f8);
                        local_2290[-4] =
                             pfVar23[-3] * (float)local_21e0 +
                             *pfVar21 * (float)(double)CONCAT44(fStack_21ec,local_21f0) +
                             pfVar23[-4] * (float)(double)CONCAT44(fStack_21e4,local_21e8) +
                             (float)local_21d8;
                        local_2290[-3] =
                             pfVar23[-4] * (float)local_21c8 + *pfVar21 * (float)local_21d0 +
                             pfVar23[-3] * (float)local_21c0 + (float)local_21b8;
                        local_2290[-2] =
                             *pfVar23 * (float)(double)CONCAT44(fStack_2204,local_2208) +
                             pfVar23[-1] * (float)(double)CONCAT44(fStack_220c,local_2210) +
                             pfVar23[1] * (float)(double)CONCAT44(fStack_21fc,local_2200);
                        local_2290[-1] =
                             pfVar23[1] * (float)local_21e0 +
                             (float)(double)CONCAT44(fStack_21e4,local_21e8) * *pfVar23 +
                             pfVar23[-1] * (float)(double)CONCAT44(fStack_21ec,local_21f0);
                        *local_2290 = pfVar23[-1] * (float)local_21d0 + *pfVar23 * (float)local_21c8
                                      + pfVar23[1] * (float)local_21c0;
                      }
                      local_2288 = (float *)((int)local_2288 + uVar18);
                      local_2290 = (float *)((int)local_2290 + uVar18);
                      pfVar21 = (float *)((int)pfVar21 + local_2230);
                      pfVar23 = (float *)((int)pfVar23 + local_2230);
                      local_228c = (undefined4 *)((int)local_228c + -1);
                    } while (local_228c != (undefined4 *)0x0);
                  }
                }
                else if (DAT_00a380c4 == 0) {
                  if (0 < (int)local_228c) {
                    local_2290 = local_2288 + 5;
                    pfVar23 = pfVar21 + 5;
                    do {
                      if (pfVar23[4] == 1.0) {
                        uVar24 = *(undefined4 *)(*(int *)(iVar7 + 0x1e8) + (int)pfVar23[3] * 4);
                        uVar29 = CONCAT44(uVar24,pfVar21);
                        pfVar14 = local_2288;
                        FUN_005826d0();
                        FUN_00582790(local_2290 + -2,pfVar23 + -1,uVar24,pfVar14,uVar29);
                      }
                      else {
                        pfVar14 = pfVar23 + 5;
                        FUN_005824c0();
                        local_2264 = 1;
                        if (1 < iVar9) {
                          do {
                            if (*pfVar14 == -NAN) break;
                            if (pfVar14[1] != 0.0) {
                              FUN_005825a0();
                            }
                            local_2264 = local_2264 + 1;
                            pfVar14 = pfVar14 + 2;
                          } while (local_2264 < iVar9);
                        }
                        *local_2288 = fStack_2204 +
                                      local_2208 * pfVar23[-3] +
                                      fStack_220c * pfVar23[-4] + local_2210 * *pfVar21;
                        local_2290[-4] =
                             fStack_21f4 +
                             local_21f8 * pfVar23[-3] +
                             fStack_21fc * pfVar23[-4] + local_2200 * *pfVar21;
                        local_2290[-3] =
                             local_21e8 * pfVar23[-3] +
                             fStack_21ec * pfVar23[-4] + local_21f0 * *pfVar21 + fStack_21e4;
                        local_2290[-2] =
                             pfVar23[-1] * local_2210 + *pfVar23 * fStack_220c +
                             pfVar23[1] * local_2208;
                        local_2290[-1] =
                             local_21f8 * pfVar23[1] +
                             fStack_21fc * *pfVar23 + pfVar23[-1] * local_2200;
                        *local_2290 = local_21e8 * pfVar23[1] +
                                      local_21f0 * pfVar23[-1] + fStack_21ec * *pfVar23;
                      }
                      local_2288 = (float *)((int)local_2288 + uVar18);
                      local_2290 = (float *)((int)local_2290 + uVar18);
                      pfVar21 = (float *)((int)pfVar21 + local_2230);
                      pfVar23 = (float *)((int)pfVar23 + local_2230);
                      local_228c = (undefined4 *)((int)local_228c + -1);
                    } while (local_228c != (undefined4 *)0x0);
                  }
                }
                else if (0 < (int)local_228c) {
                  local_2290 = local_2288 + 5;
                  pfVar23 = pfVar21 + 5;
                  do {
                    if (pfVar23[4] == 1.0) {
                      uVar24 = *(undefined4 *)(*(int *)(iVar7 + 0x1e8) + (int)pfVar23[3] * 4);
                      uVar29 = CONCAT44(uVar24,pfVar21);
                      pfVar14 = local_2288;
                      FUN_00582730();
                      FUN_005827f0(local_2290 + -2,pfVar23 + -1,uVar24,pfVar14,uVar29);
                    }
                    else {
                      pfVar14 = pfVar23 + 5;
                      FUN_00582530();
                      local_2264 = 1;
                      if (1 < iVar9) {
                        do {
                          if (*pfVar14 == -NAN) break;
                          if (pfVar14[1] != 0.0) {
                            FUN_00582640();
                          }
                          local_2264 = local_2264 + 1;
                          pfVar14 = pfVar14 + 2;
                        } while (local_2264 < iVar9);
                      }
                      *local_2288 = pfVar23[-4] * (float)(double)CONCAT44(fStack_2204,local_2208) +
                                    *pfVar21 * (float)(double)CONCAT44(fStack_220c,local_2210) +
                                    pfVar23[-3] * (float)(double)CONCAT44(fStack_21fc,local_2200) +
                                    (float)(double)CONCAT44(fStack_21f4,local_21f8);
                      local_2290[-4] =
                           pfVar23[-3] * (float)local_21e0 +
                           *pfVar21 * (float)(double)CONCAT44(fStack_21ec,local_21f0) +
                           pfVar23[-4] * (float)(double)CONCAT44(fStack_21e4,local_21e8) +
                           (float)local_21d8;
                      local_2290[-3] =
                           pfVar23[-4] * (float)local_21c8 + *pfVar21 * (float)local_21d0 +
                           pfVar23[-3] * (float)local_21c0 + (float)local_21b8;
                      local_2290[-2] =
                           pfVar23[-1] * (float)(double)CONCAT44(fStack_220c,local_2210) +
                           *pfVar23 * (float)(double)CONCAT44(fStack_2204,local_2208) +
                           pfVar23[1] * (float)(double)CONCAT44(fStack_21fc,local_2200);
                      local_2290[-1] =
                           pfVar23[1] * (float)local_21e0 +
                           (float)(double)CONCAT44(fStack_21e4,local_21e8) * *pfVar23 +
                           pfVar23[-1] * (float)(double)CONCAT44(fStack_21ec,local_21f0);
                      *local_2290 = *pfVar23 * (float)local_21c8 + pfVar23[-1] * (float)local_21d0 +
                                    pfVar23[1] * (float)local_21c0;
                    }
                    local_2288 = (float *)((int)local_2288 + uVar18);
                    local_2290 = (float *)((int)local_2290 + uVar18);
                    pfVar21 = (float *)((int)pfVar21 + local_2230);
                    pfVar23 = (float *)((int)pfVar23 + local_2230);
                    local_228c = (undefined4 *)((int)local_228c + -1);
                  } while (local_228c != (undefined4 *)0x0);
                }
                if ((*(int *)(*(int *)param_1[2] + 8) == 1) ||
                   (*(int *)(*(int *)param_1[2] + 8) == 2)) {
                  if (DAT_00a380c4 == 0) {
                    if (0 < *(int *)(*(int *)(iVar7 + 0x10) + 0x188)) {
                      iVar22 = *(int *)(*(int *)(iVar7 + 0x10) + 0x188);
                      do {
                        iVar22 = iVar22 + -1;
                      } while (iVar22 != 0);
                    }
                  }
                  else if (0 < *(int *)(*(int *)(iVar7 + 0x10) + 0x188)) {
                    iVar22 = *(int *)(*(int *)(iVar7 + 0x10) + 0x188);
                    do {
                      iVar22 = iVar22 + -1;
                    } while (iVar22 != 0);
                  }
                  FUN_005dff40(local_2274);
                }
                FUN_0059b720(0);
                FUN_0059b820(0);
                FUN_0059b940();
                FUN_0059b8e0(0);
                FUN_005a0c60(*(uint *)(&DAT_00a05460 + *(int *)(local_2240 + 0x4c) * 4) | 0xd2);
                uVar5 = *(undefined2 *)(local_2274 + 8);
                uVar24 = *(undefined4 *)(local_2274 + 0xf8);
                uVar17 = *(undefined4 *)(local_2274 + 0x114);
                break;
              default:
                goto switchD_005e52b4_default;
              }
              uVar6 = *(ushort *)(local_2274 + 0x110);
              uVar27 = *(undefined4 *)(local_2274 + 0xc);
LAB_005e75ee:
              FUN_005d3b70(4,0,uVar27,uVar6 / 3,uVar17,0x65,uVar24,uVar5);
              DAT_00a37de4 = DAT_00a37de4 + 1;
            }
switchD_005e52b4_default:
            local_226c = local_226c + 0x18;
            local_221c = local_221c + 1;
            local_2274 = local_2274 + 0x138;
          } while (local_221c < *(int *)(local_2240 + 0x40));
          iVar22 = local_2218;
        }
      }
      if (((*(int *)(iVar22 + 0x254) == 0) && (DAT_00dccde4 == 0)) ||
         ((*(int *)(iVar22 + 600) == 0 && (DAT_00dccde4 == 1)))) {
        piVar20 = (int *)param_1[2];
        if ((*(int *)(*piVar20 + 8) == 1) || (*(int *)(*piVar20 + 8) == 2)) {
          if ((_DAT_007d5924 < (float)piVar20[0x5e]) || (_DAT_007d5924 < (float)piVar20[0x5f])) {
            local_2280 = (float)piVar20[0x5e];
            if (DAT_00a380c4 == 0) {
              local_21a0 = (double)*(float *)(iVar7 + 0x10c);
              local_2198 = (double)*(float *)(iVar7 + 0x11c);
              local_2190 = (double)*(float *)(iVar7 + 300);
            }
            else {
              local_21a0 = *(double *)(iVar7 + 0x118);
              local_2198 = *(double *)(iVar7 + 0x138);
              local_2190 = *(double *)(iVar7 + 0x158);
            }
            puVar12 = (undefined4 *)FUN_00516300(local_2038,local_21a0,local_2198,local_2190);
            local_2188 = *puVar12;
            uStack_2184 = puVar12[1];
            local_2180 = puVar12[2];
            local_217c = puVar12[3];
            local_2178 = puVar12[4];
            local_2174 = puVar12[5];
            pdVar13 = (double *)
                      FUN_00516300(local_2038,
                                   (double)((float)_DAT_00a38358 * local_2280 + (float)local_21a0),
                                   (double)(local_2280 * (float)_DAT_00a38378 + (float)local_2198),
                                   (double)(local_2280 * (float)_DAT_00a38398 + (float)local_2190));
            local_21a0 = *pdVar13;
            fVar25 = (float10)(double)CONCAT44(uStack_2184,local_2188) - (float10)local_21a0;
            local_2198 = pdVar13[1];
            local_2190 = pdVar13[2];
            if (fVar25 < (float10)0) {
              fVar25 = -fVar25;
            }
            fVar26 = (float10)*(float *)(param_1[2] + 0x17c);
            if (fVar26 < (float10)_DAT_007d9b80) {
              fVar26 = (float10)_DAT_008023e0;
            }
            if (fVar25 < fVar26) {
              if ((float10)_DAT_007d54f8 <= fVar25) {
                local_2214 = (float)(fVar26 / fVar25);
                local_2280 = local_2214 * local_2280;
              }
              else {
                local_2280 = local_2280 * (float)_DAT_007d9a90;
              }
            }
            local_224c = ((-(uint)(DAT_00e79874 != 0) & DAT_00e79878) + 0xc0) * 0x28;
            FUN_005df960();
            local_226c = param_1[0x2b];
            iVar22 = *(int *)(local_2240 + 0x44);
            local_2268 = -1;
            local_221c = 0;
            if (0 < *(int *)(local_2240 + 0x40)) {
              do {
                if (((param_2 < 0) || (local_221c == param_2)) && (*(short *)(iVar22 + 0x118) != 0))
                {
                  switch(*(short *)(iVar22 + 4)) {
                  case 0:
                    if (((*(int *)(iVar22 + 0x124) == 0) ||
                        (iVar9 = *(int *)(*(int *)(iVar22 + 0x124) + 0x14), *(int *)(iVar9 + 4) == 0
                        )) || (*(int *)(iVar9 + 8) == 0)) goto LAB_005e7b84;
                    if (*(int *)(local_2220 + 0x44) != 0) goto switchD_005e790e_caseD_1;
                    if (DAT_00dccde4 == 0) {
                      uVar24 = 0;
                      iVar9 = local_224c;
LAB_005e79b8:
                      iVar9 = FUN_0059f7e0(iVar9,uVar24);
                      if (iVar9 != 0) {
                        FUN_0059b6b0();
                        if (**(int **)(local_226c + 0xc) == 0) {
                          uVar29 = CONCAT44(*(undefined4 *)(*(int *)(iVar22 + 0x124) + 0x10),
                                            *(undefined4 *)
                                             (*(int *)(*(int *)(iVar22 + 0x124) + 0x14) + 4));
                        }
                        else {
                          uVar29 = CONCAT44(*(undefined4 *)(*(int *)(iVar22 + 0x124) + 0x10),
                                            **(int **)(local_226c + 0xc));
                        }
                        FUN_0059b8e0(uVar29);
                        if (local_2268 != 1) {
                          FUN_005e1f70();
                          local_2268 = 1;
                        }
                        FUN_0059b940();
                        if (DAT_00a380c4 == 0) {
                          puVar12 = (undefined4 *)(iVar7 + 0x100);
                        }
                        else if (local_2234 == 0) {
                          FUN_00582890(local_2098);
                          uVar29 = CONCAT44(local_2098,iVar7 + 0x100);
                          puVar28 = local_1448;
                          FUN_00582380();
                          FUN_005829a0(local_1e68,local_1448,puVar28,uVar29);
                          FUN_005a02f0(&DAT_00a05418);
                          puVar12 = local_1e68;
                        }
                        else {
                          FUN_005829a0(local_1e68);
                          puVar12 = local_1e68;
                        }
                        FUN_0059cb80(&DAT_00ddb600,0,0,0x5e,puVar12,3);
                        if (**(int **)(local_226c + 0xc) == 0) {
                          uVar24 = *(undefined4 *)(iVar22 + 0x128);
                        }
                        else {
                          uVar24 = 0;
                        }
                        FUN_005d3b10(4,uVar24,0,*(undefined4 *)(iVar22 + 0xc),
                                     *(undefined4 *)(iVar22 + 0x130));
                        goto LAB_005e83cd;
                      }
                    }
                    else if ((DAT_00a38dd8 < 1) || (iVar9 = FUN_005a0ca0(), -1 < iVar9)) {
                      if (DAT_00a38ddc < 1) {
LAB_005e7991:
                        uVar24 = 0;
                      }
                      else {
                        iVar9 = FUN_005a0d10();
                        if (iVar9 < 0) goto LAB_005e7b84;
                        if (DAT_00a38ddc < 1) goto LAB_005e7991;
                        uVar24 = 0xffffffff;
                      }
                      if (DAT_00a38dd8 < 1) {
                        iVar9 = local_224c;
                      }
                      else {
                        iVar9 = -1;
                      }
                      goto LAB_005e79b8;
                    }
LAB_005e7b84:
                    if (*(char *)(iVar7 + 0x161) == '\0') {
                      *(undefined1 *)(iVar7 + 0x161) = 1;
                      FUN_005829f0(iVar7 + 0x164);
                    }
                    FUN_00519a30();
                    DAT_00dda468 = 0;
                    if (local_2268 != 0) {
                      FUN_005e1f70();
                      local_2268 = 0;
                    }
                    FUN_0059b780();
                    FUN_0059b870(0);
                    if (*(int *)(iVar22 + 0xf8) == 0) {
                      FUN_005dfb70();
                    }
                    if (*(int *)(iVar22 + 0xfc) == 0) {
                      FUN_005e2090();
                    }
                    if (*(char *)(local_2240 + 0x4a) != '\0') {
                      iVar15 = *(int *)(iVar22 + 0xc);
                      pfVar23 = (float *)(*(int *)(iVar22 + 0xfc) + 0xfU & 0xfffffff0);
                      pfVar21 = (float *)(*(int *)(local_226c + 8) + 0xfU & 0xfffffff0);
                      iVar9 = 0;
                      if (3 < iVar15) {
                        iVar19 = (iVar15 - 4U >> 2) + 1;
                        iVar9 = iVar19 * 4;
                        pfVar14 = pfVar21;
                        pfVar16 = pfVar23;
                        do {
                          pfVar23 = pfVar16 + 0x10;
                          pfVar21 = pfVar14 + 0x20;
                          iVar19 = iVar19 + -1;
                          *pfVar16 = pfVar14[4] * local_2280 + *pfVar14;
                          pfVar16[1] = pfVar14[5] * local_2280 + pfVar14[1];
                          pfVar16[2] = pfVar14[6] * local_2280 + pfVar14[2];
                          pfVar16[4] = pfVar14[0xc] * local_2280 + pfVar14[8];
                          pfVar16[5] = pfVar14[0xd] * local_2280 + pfVar14[9];
                          pfVar16[6] = pfVar14[0xe] * local_2280 + pfVar14[10];
                          pfVar16[8] = pfVar14[0x14] * local_2280 + pfVar14[0x10];
                          pfVar16[9] = pfVar14[0x15] * local_2280 + pfVar14[0x11];
                          pfVar16[10] = pfVar14[0x16] * local_2280 + pfVar14[0x12];
                          pfVar16[0xc] = pfVar14[0x1c] * local_2280 + pfVar14[0x18];
                          pfVar16[0xd] = pfVar14[0x1d] * local_2280 + pfVar14[0x19];
                          pfVar16[0xe] = pfVar14[0x1e] * local_2280 + pfVar14[0x1a];
                          pfVar14 = pfVar21;
                          pfVar16 = pfVar23;
                        } while (iVar19 != 0);
                      }
                      if (iVar9 < iVar15) {
                        iVar15 = iVar15 - iVar9;
                        do {
                          iVar15 = iVar15 + -1;
                          *pfVar23 = pfVar21[4] * local_2280 + *pfVar21;
                          pfVar23[1] = pfVar21[5] * local_2280 + pfVar21[1];
                          pfVar23[2] = pfVar21[6] * local_2280 + pfVar21[2];
                          pfVar21 = pfVar21 + 8;
                          pfVar23 = pfVar23 + 4;
                        } while (iVar15 != 0);
                      }
                    }
                    uVar6 = *(ushort *)(iVar22 + 8);
                    pfVar21 = *(float **)(iVar22 + 0xf8);
                    pfVar23 = (float *)(*(int *)(iVar22 + 0xfc) + 0xfU & 0xfffffff0);
                    local_2244 = (uint)ROUND(*(float *)(param_1[2] + 0x180) * (float)_DAT_0081ec30);
                    local_2230 = CONCAT22(local_2230._2_2_,in_FPUControlWord) | 0xc00;
                    local_2228 = (uint)ROUND(*(float *)(param_1[2] + 0x184) * (float)_DAT_0081ec30);
                    local_21a4 = (uint)ROUND(*(float *)(param_1[2] + 0x188) * (float)_DAT_0081ec30);
                    iVar9 = *(int *)(iVar22 + 0xc);
                    if (0 < iVar9) {
                      do {
                        *pfVar23 = pfVar21[3] * local_2280 + *pfVar21;
                        pfVar23[1] = pfVar21[4] * local_2280 + pfVar21[1];
                        fVar2 = pfVar21[5];
                        fVar1 = pfVar21[2];
                        pfVar23[3] = (float)(((local_2244 | 0xffffff00) << 8 | local_2228) << 8 |
                                            local_21a4);
                        pfVar21 = (float *)((int)pfVar21 + (uint)uVar6);
                        iVar9 = iVar9 + -1;
                        pfVar23[2] = fVar2 * local_2280 + fVar1;
                        pfVar23 = pfVar23 + 4;
                      } while (iVar9 != 0);
                    }
                    break;
                  case 1:
                  case 2:
switchD_005e790e_caseD_1:
                    if (*(short *)(iVar22 + 4) == 1) {
                      iVar9 = local_224c + 0x140;
                      uVar24 = 8;
                    }
                    else {
                      iVar9 = local_224c + 0x280;
                      uVar24 = 0x10;
                    }
                    if (((*(int *)(iVar22 + 0x124) != 0) &&
                        (iVar15 = *(int *)(*(int *)(iVar22 + 0x124) + 0x14),
                        *(int *)(iVar15 + 4) != 0)) && (*(int *)(iVar15 + 8) != 0)) {
                      if (DAT_00dccde4 == 0) {
                        uVar17 = 0;
                        uVar29 = CONCAT44(uVar24,iVar9);
                      }
                      else {
                        if ((0 < DAT_00a38dd8) && (iVar15 = FUN_005a0ca0(), iVar15 < 0))
                        goto switchD_005e790e_caseD_3;
                        if (DAT_00a38ddc < 1) {
LAB_005e7edf:
                          uVar17 = 0;
                        }
                        else {
                          iVar15 = FUN_005a0d10();
                          if (iVar15 < 0) goto switchD_005e790e_caseD_3;
                          if (DAT_00a38ddc < 1) goto LAB_005e7edf;
                          uVar17 = 0xffffffff;
                        }
                        if (DAT_00a38dd8 < 1) {
                          uVar29 = CONCAT44(uVar24,iVar9);
                        }
                        else {
                          uVar29 = CONCAT44(uVar24,0xffffffff);
                        }
                      }
                      iVar9 = FUN_0059f7e0(uVar29,uVar17);
                      if (iVar9 != 0) {
                        FUN_0059b6b0();
                        if (local_2268 != 1) {
                          FUN_005e1f70();
                          local_2268 = 1;
                        }
                        if (**(int **)(local_226c + 0xc) == 0) {
                          uVar29 = CONCAT44(*(undefined4 *)(*(int *)(iVar22 + 0x124) + 0x10),
                                            *(undefined4 *)
                                             (*(int *)(*(int *)(iVar22 + 0x124) + 0x14) + 4));
                        }
                        else {
                          uVar29 = CONCAT44(*(undefined4 *)(*(int *)(iVar22 + 0x124) + 0x10),
                                            **(int **)(local_226c + 0xc));
                        }
                        FUN_0059b8e0(uVar29);
                        FUN_0059b940();
                        if (*(int *)(local_2220 + 0x44) != 0) {
                          if (*(short *)(iVar22 + 4) == 0) {
                            local_2290 = (float *)(((iVar7 - *(int *)(local_2218 + 0x17c)) / 0x2b8 +
                                                   *(int *)(local_2220 + 0xd8)) * 0x30 +
                                                  *(int *)(local_2218 + 0x194));
                          }
                          else {
                            local_2290 = *(float **)(local_2218 + 0x194);
                          }
                          local_228c = *(undefined4 **)(local_2218 + 400);
                          if (0 < (int)local_228c) {
                            do {
                              local_2224 = local_228c;
                              if ((int)*(undefined4 **)(iVar22 + 0x120) < (int)local_228c) {
                                local_2224 = *(undefined4 **)(iVar22 + 0x120);
                              }
                              puVar12 = local_2224;
                              if (*(short *)(iVar22 + 4) == 0) {
                                if (0 < (int)local_2224) {
                                  puVar10 = local_1e68;
                                  local_222c = local_2224;
                                  do {
                                    pfVar21 = local_2290;
                                    puVar11 = puVar10;
                                    for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
                                      *puVar11 = *pfVar21;
                                      pfVar21 = pfVar21 + 1;
                                      puVar11 = puVar11 + 1;
                                    }
                                    local_2290 = local_2290 + *(int *)(local_2220 + 0x4c) * 0xc;
                                    puVar10 = puVar10 + 0xc;
                                    local_222c = (undefined4 *)((int)local_222c + -1);
                                  } while (local_222c != (undefined4 *)0x0);
                                  local_222c = (undefined4 *)0x0;
                                }
                              }
                              else {
                                local_21ac = 0;
                                if (0 < (int)local_2224) {
                                  iVar9 = *(int *)(iVar22 + 0x14);
                                  local_2260 = local_2224;
                                  do {
                                    local_2278 = 0;
                                    if (0 < iVar9) {
                                      local_21a8 = (int *)(iVar22 + 0x18);
                                      local_222c = local_1e68 + local_21ac * 0xc;
                                      do {
                                        iVar9 = *local_21a8;
                                        local_21a8 = local_21a8 + 1;
                                        local_21ac = local_21ac + 1;
                                        puVar10 = local_222c + 0xc;
                                        puVar11 = local_2290 +
                                                  ((*(int *)(*(int *)(iVar7 + 0x1e8) + iVar9 * 4) -
                                                   *(int *)(local_2218 + 0x18c)) / 0x60) * 0xc;
                                        for (iVar15 = 0xc; iVar15 != 0; iVar15 = iVar15 + -1) {
                                          *local_222c = *puVar11;
                                          puVar11 = puVar11 + 1;
                                          local_222c = local_222c + 1;
                                        }
                                        iVar9 = *(int *)(iVar22 + 0x14);
                                        local_2278 = local_2278 + 1;
                                        local_222c = puVar10;
                                      } while ((int)local_2278 < iVar9);
                                    }
                                    local_2290 = local_2290 + *(int *)(local_2220 + 0x4c) * 0xc;
                                    local_2260 = (undefined4 *)((int)local_2260 + -1);
                                  } while (local_2260 != (undefined4 *)0x0);
                                }
                              }
                              iVar9 = 1;
                              if (*(short *)(iVar22 + 4) != 0) {
                                iVar9 = *(int *)(iVar22 + 0x14);
                              }
                              FUN_0059cb80(&DAT_00ddb600,0,0,0x5e,local_1e68,
                                           (int)local_2224 * iVar9 * 3);
                              FUN_005d3b10();
                              DAT_00a37de4 = DAT_00a37de4 + 1;
                              local_228c = (undefined4 *)((int)local_228c - (int)puVar12);
                            } while (0 < (int)local_228c);
                          }
                          goto switchD_005e790e_default;
                        }
                        if (DAT_00a380c4 == 0) {
                          local_2278 = 0;
                          if (0 < *(int *)(iVar22 + 0x14)) {
                            puVar12 = local_1e68;
                            piVar20 = (int *)(iVar22 + 0x18);
                            do {
                              puVar10 = *(undefined4 **)(*(int *)(iVar7 + 0x1e8) + *piVar20 * 4);
                              puVar11 = puVar12;
                              for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
                                *puVar11 = *puVar10;
                                puVar10 = puVar10 + 1;
                                puVar11 = puVar11 + 1;
                              }
                              local_2278 = local_2278 + 1;
                              piVar20 = piVar20 + 1;
                              puVar12 = puVar12 + 0xc;
                            } while ((int)local_2278 < *(int *)(iVar22 + 0x14));
                          }
                        }
                        else if (local_2234 == 0) {
                          FUN_00582890(local_2098);
                          local_2278 = 0;
                          if (0 < *(int *)(iVar22 + 0x14)) {
                            do {
                              FUN_00582380();
                              FUN_005829a0();
                              local_2278 = local_2278 + 1;
                            } while ((int)local_2278 < *(int *)(iVar22 + 0x14));
                          }
                          FUN_005a02f0();
                        }
                        else {
                          local_2278 = 0;
                          if (0 < *(int *)(iVar22 + 0x14)) {
                            puVar12 = local_1e68;
                            do {
                              FUN_005829a0(puVar12);
                              local_2278 = local_2278 + 1;
                              puVar12 = puVar12 + 0xc;
                            } while ((int)local_2278 < *(int *)(iVar22 + 0x14));
                          }
                        }
                        FUN_0059cb80(&DAT_00ddb600,0,0,0x5e,local_1e68,*(int *)(iVar22 + 0x14) * 3);
                        if (**(int **)(local_226c + 0xc) == 0) {
                          uVar24 = *(undefined4 *)(iVar22 + 0x128);
                        }
                        else {
                          uVar24 = 0;
                        }
                        FUN_005d3b10(4,uVar24,0,*(undefined4 *)(iVar22 + 0xc),
                                     *(undefined4 *)(iVar22 + 0x130));
LAB_005e83cd:
                        DAT_00a37de4 = DAT_00a37de4 + 1;
                        if ((DAT_00a380c4 != 0) && (local_2234 == 0)) {
                          FUN_005a02f0();
                        }
                        goto switchD_005e790e_default;
                      }
                    }
                  case 3:
switchD_005e790e_caseD_3:
                    if (local_2268 != 0) {
                      FUN_005e1f70();
                      local_2268 = 0;
                    }
                    FUN_0059b780();
                    FUN_0059b870(0);
                    if (DAT_00dda468 == 0) {
                      DAT_00dda468 = 1;
                      FUN_00519a30();
                    }
                    if (*(int *)(iVar22 + 0xf8) == 0) {
                      FUN_005dfb70();
                    }
                    if (*(int *)(iVar22 + 0xfc) == 0) {
                      FUN_005e2090();
                    }
                    uVar6 = *(ushort *)(iVar22 + 8);
                    pfVar21 = *(float **)(iVar22 + 0xf8);
                    iVar9 = *(int *)(iVar22 + 0xc);
                    pfVar23 = (float *)(*(int *)(iVar22 + 0xfc) + 0xfU & 0xfffffff0);
                    local_2248 = (uint)ROUND(*(float *)(param_1[2] + 0x180) * (float)_DAT_0081ec30);
                    fVar2 = *(float *)(param_1[2] + 0x184);
                    fVar1 = (float)_DAT_0081ec30;
                    local_223c = CONCAT22(local_223c._2_2_,in_FPUControlWord) | 0xc00;
                    local_2214 = (float)(int)ROUND(*(float *)(param_1[2] + 0x188) *
                                                   (float)_DAT_0081ec30);
                    if (0 < iVar9) {
                      do {
                        *pfVar23 = pfVar21[3] * local_2280 + *pfVar21;
                        pfVar23[1] = pfVar21[4] * local_2280 + pfVar21[1];
                        fVar3 = pfVar21[5];
                        fVar4 = pfVar21[2];
                        pfVar23[3] = (float)(((local_2248 | 0xffffff00) << 8 |
                                             (int)ROUND(fVar2 * fVar1)) << 8 | (uint)local_2214);
                        pfVar21 = (float *)((int)pfVar21 + (uint)uVar6);
                        iVar9 = iVar9 + -1;
                        pfVar23[2] = fVar3 * local_2280 + fVar4;
                        pfVar23 = pfVar23 + 4;
                      } while (iVar9 != 0);
                    }
                    break;
                  default:
                    goto switchD_005e790e_default;
                  }
                  FUN_0059b720(0);
                  FUN_0059b820(0);
                  FUN_0059b940();
                  FUN_0059b8e0(0);
                  FUN_005a0c60(0x42);
                  FUN_005d3b70(4,0,*(undefined4 *)(iVar22 + 0xc),*(ushort *)(iVar22 + 0x118) / 3,
                               *(undefined4 *)(iVar22 + 0x11c),0x65,
                               *(int *)(iVar22 + 0xfc) + 0xfU & 0xfffffff0,0x10);
                  DAT_00a37de4 = DAT_00a37de4 + 1;
                }
switchD_005e790e_default:
                local_226c = local_226c + 0x18;
                local_221c = local_221c + 1;
                iVar22 = iVar22 + 0x138;
              } while (local_221c < *(int *)(local_2240 + 0x40));
            }
          }
          FUN_0059b2b0();
        }
      }
    }
  }
  return;
}

