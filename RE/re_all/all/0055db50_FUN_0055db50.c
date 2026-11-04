
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0055db50(uint param_1,uint param_2)

{
  short sVar1;
  ushort uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  float *pfVar13;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_14;
  int local_c;
  int local_4;
  
  if (((((DAT_00cc50a0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc50c8)) ||
      ((DAT_00cc50d0 <= (int)(param_1 & 0xffff) ||
       (piVar3 = *(int **)(DAT_00cc50a4 + (param_1 & 0xffff) * 4), piVar3 == (int *)0x0)))) ||
     (*piVar3 * 0x10000 != (param_1 & 0x3ff0000))) {
    return 0xffffffff;
  }
  if ((((piVar3[0xc] != 1) && (-1 < (int)param_2)) &&
      (((param_2 & 0x7c000000) == DAT_00cc50c8 &&
       ((((int)(param_2 & 0xffff) < DAT_00cc50d0 &&
         (piVar4 = *(int **)(DAT_00cc50a4 + (param_2 & 0xffff) * 4), piVar4 != (int *)0x0)) &&
        (*piVar4 * 0x10000 == (param_2 & 0x3ff0000))))))) && (piVar4[0xc] != 1)) {
    iVar8 = piVar4[0x12];
    iVar9 = piVar3[0x12];
    if ((iVar9 != iVar8) && (sVar1 = (short)piVar3[0xd], sVar1 == (short)piVar4[0xd])) {
      uVar2 = *(ushort *)((int)piVar3 + 0x36);
      if ((uVar2 == *(ushort *)((int)piVar4 + 0x36)) &&
         ((piVar3[0xe] == piVar4[0xe] &&
          (*(short *)((int)piVar3 + 0x42) == *(short *)((int)piVar4 + 0x42))))) {
        local_20 = 0;
        local_24 = 0;
        if (sVar1 != 1) {
          if (sVar1 == 3) {
            pfVar10 = (float *)piVar4[0x13];
            iVar5 = piVar3[0x13];
            FUN_0056d380(pfVar10,0,(uint)uVar2 * iVar8 * 4);
            local_4 = iVar8;
            if (*(short *)((int)piVar3 + 0x36) == 1) {
              if (0 < iVar8) {
                fVar7 = (float)_DAT_007d6538;
                local_20 = 0;
                do {
                  local_30 = local_24;
                  if (local_20 != 0) {
                    local_30 = local_24 + 1;
                  }
                  local_30 = local_30 + -0x40;
                  local_2c = local_24 + 0x40;
                  if (local_30 < 0) {
                    local_30 = 0;
                  }
                  if (iVar9 <= local_30) {
                    local_30 = iVar9 + -1;
                  }
                  if (local_2c < 0) {
                    local_2c = 0;
                  }
                  if (iVar9 <= local_2c) {
                    local_2c = iVar9 + -1;
                  }
                  local_20 = local_20 + iVar9;
                  if (iVar8 <= local_20) {
                    do {
                      local_20 = local_20 - iVar8;
                      local_24 = local_24 + 1;
                    } while (iVar8 <= local_20);
                  }
                  local_28 = (local_24 - local_30) * 0x80 + (local_20 << 7) / iVar8;
                  local_1c = local_30;
                  if (3 < (local_2c - local_30) + 1) {
                    local_c = ((local_2c - local_30) - 3U >> 2) + 1;
                    iVar11 = local_28 + -0x100;
                    iVar12 = iVar11 * 0x192;
                    local_14 = iVar11 * 0x8000;
                    iVar11 = iVar11 * 0x10000;
                    local_28 = local_28 + local_c * -0x200;
                    local_1c = local_30 + local_c * 4;
                    pfVar13 = (float *)(iVar5 + 8 + local_30 * 4);
                    do {
                      if (iVar12 == -0x19200) {
                        local_30 = 0x4000;
                      }
                      else {
                        local_30 = ((int)(short)(&DAT_00a8424c)
                                                [(int)(local_14 + 0x800000 +
                                                      (local_14 + 0x800000 >> 0x1f & 0x7fU)) >> 7 &
                                                 0xffff] << 0xe) / (iVar12 + 0x19200);
                      }
                      local_30 = (((int)((short)(&DAT_00a8424c)
                                                [(iVar11 + 0x1000000) / 0x8080 + 0x4000U & 0xffff] *
                                         0x2000 + ((short)(&DAT_00a8424c)
                                                          [(iVar11 + 0x1000000) / 0x8080 + 0x4000U &
                                                           0xffff] * 0x2000 >> 0x1f & 0x3fffU)) >>
                                  0xe) + 0x2000) * local_30;
                      *pfVar10 = (float)((int)(local_30 + (local_30 >> 0x1f & 0x3fffU)) >> 0xe) *
                                 pfVar13[-2] * fVar7 + *pfVar10;
                      if (iVar12 == -0xc900) {
                        local_30 = 0x4000;
                      }
                      else {
                        local_30 = ((int)(short)(&DAT_00a8424c)
                                                [(int)(local_14 + 0x400000 +
                                                      (local_14 + 0x400000 >> 0x1f & 0x7fU)) >> 7 &
                                                 0xffff] << 0xe) / (iVar12 + 0xc900);
                      }
                      local_30 = (((int)((short)(&DAT_00a8424c)
                                                [(iVar11 + 0x800000) / 0x8080 + 0x4000U & 0xffff] *
                                         0x2000 + ((short)(&DAT_00a8424c)
                                                          [(iVar11 + 0x800000) / 0x8080 + 0x4000U &
                                                           0xffff] * 0x2000 >> 0x1f & 0x3fffU)) >>
                                  0xe) + 0x2000) * local_30;
                      *pfVar10 = (float)((int)(local_30 + (local_30 >> 0x1f & 0x3fffU)) >> 0xe) *
                                 pfVar13[-1] * fVar7 + *pfVar10;
                      if (iVar12 == 0) {
                        local_30 = 0x4000;
                      }
                      else {
                        local_30 = ((int)(short)(&DAT_00a8424c)
                                                [(int)(local_14 + (local_14 >> 0x1f & 0x7fU)) >> 7 &
                                                 0xffff] << 0xe) / iVar12;
                      }
                      local_30 = (((int)((short)(&DAT_00a8424c)[iVar11 / 0x8080 + 0x4000U & 0xffff]
                                         * 0x2000 +
                                        ((short)(&DAT_00a8424c)[iVar11 / 0x8080 + 0x4000U & 0xffff]
                                         * 0x2000 >> 0x1f & 0x3fffU)) >> 0xe) + 0x2000) * local_30;
                      *pfVar10 = (float)((int)(local_30 + (local_30 >> 0x1f & 0x3fffU)) >> 0xe) *
                                 *pfVar13 * fVar7 + *pfVar10;
                      if (iVar12 == 0xc900) {
                        local_30 = 0x4000;
                      }
                      else {
                        local_30 = ((int)(short)(&DAT_00a8424c)
                                                [(int)(local_14 + -0x400000 +
                                                      (local_14 + -0x400000 >> 0x1f & 0x7fU)) >> 7 &
                                                 0xffff] << 0xe) / (iVar12 + -0xc900);
                      }
                      local_30 = (((int)((short)(&DAT_00a8424c)
                                                [(iVar11 + -0x800000) / 0x8080 + 0x4000U & 0xffff] *
                                         0x2000 + ((short)(&DAT_00a8424c)
                                                          [(iVar11 + -0x800000) / 0x8080 + 0x4000U &
                                                           0xffff] * 0x2000 >> 0x1f & 0x3fffU)) >>
                                  0xe) + 0x2000) * local_30;
                      local_14 = local_14 + -0x1000000;
                      iVar12 = iVar12 + -0x32400;
                      iVar11 = iVar11 + -0x2000000;
                      local_c = local_c + -1;
                      *pfVar10 = (float)((int)(local_30 + (local_30 >> 0x1f & 0x3fffU)) >> 0xe) *
                                 pfVar13[1] * fVar7 + *pfVar10;
                      pfVar13 = pfVar13 + 4;
                    } while (local_c != 0);
                  }
                  if (local_1c <= local_2c) {
                    iVar12 = local_28 << 0x10;
                    iVar11 = local_28 << 0xf;
                    local_28 = local_28 * 0x192;
                    do {
                      if (local_28 == 0) {
                        local_30 = 0x4000;
                      }
                      else {
                        local_30 = ((int)(short)(&DAT_00a8424c)
                                                [(int)(iVar11 + (iVar11 >> 0x1f & 0x7fU)) >> 7 &
                                                 0xffff] << 0xe) / local_28;
                      }
                      local_30 = (((int)((short)(&DAT_00a8424c)[iVar12 / 0x8080 + 0x4000U & 0xffff]
                                         * 0x2000 +
                                        ((short)(&DAT_00a8424c)[iVar12 / 0x8080 + 0x4000U & 0xffff]
                                         * 0x2000 >> 0x1f & 0x3fffU)) >> 0xe) + 0x2000) * local_30;
                      local_1c = local_1c + 1;
                      local_28 = local_28 + -0xc900;
                      iVar11 = iVar11 + -0x400000;
                      iVar12 = iVar12 + -0x800000;
                      *pfVar10 = (float)((int)(local_30 + (local_30 >> 0x1f & 0x3fffU)) >> 0xe) *
                                 *(float *)(iVar5 + -4 + local_1c * 4) * fVar7 + *pfVar10;
                    } while (local_1c <= local_2c);
                  }
                  pfVar10 = pfVar10 + 1;
                  local_4 = local_4 + -1;
                } while (local_4 != 0);
                return 0;
              }
            }
            else if ((*(short *)((int)piVar3 + 0x36) == 2) && (0 < iVar8)) {
              fVar7 = (float)_DAT_007d6538;
              do {
                local_30 = local_24;
                if (local_20 != 0) {
                  local_30 = local_24 + 1;
                }
                local_30 = local_30 + -0x40;
                local_2c = local_24 + 0x40;
                if (local_30 < 0) {
                  local_30 = 0;
                }
                if (iVar9 <= local_30) {
                  local_30 = iVar9 + -1;
                }
                if (local_2c < 0) {
                  local_2c = 0;
                }
                if (iVar9 <= local_2c) {
                  local_2c = iVar9 + -1;
                }
                local_20 = local_20 + iVar9;
                if (iVar8 <= local_20) {
                  do {
                    local_20 = local_20 - iVar8;
                    local_24 = local_24 + 1;
                  } while (iVar8 <= local_20);
                }
                local_28 = (local_24 - local_30) * 0x80 + (local_20 << 7) / iVar8;
                local_1c = local_30;
                if (3 < (local_2c - local_30) + 1) {
                  local_c = ((local_2c - local_30) - 3U >> 2) + 1;
                  iVar11 = local_28 + -0x100;
                  iVar12 = iVar11 * 0x192;
                  local_14 = iVar11 * 0x8000;
                  iVar11 = iVar11 * 0x10000;
                  local_28 = local_28 + local_c * -0x200;
                  local_1c = local_30 + local_c * 4;
                  pfVar13 = (float *)(iVar5 + 8 + local_30 * 8);
                  do {
                    if (iVar12 == -0x19200) {
                      local_30 = 0x4000;
                    }
                    else {
                      local_30 = ((int)(short)(&DAT_00a8424c)
                                              [(int)(local_14 + 0x800000 +
                                                    (local_14 + 0x800000 >> 0x1f & 0x7fU)) >> 7 &
                                               0xffff] << 0xe) / (iVar12 + 0x19200);
                    }
                    local_30 = (((int)((short)(&DAT_00a8424c)
                                              [(iVar11 + 0x1000000) / 0x8080 + 0x4000U & 0xffff] *
                                       0x2000 + ((short)(&DAT_00a8424c)
                                                        [(iVar11 + 0x1000000) / 0x8080 + 0x4000U &
                                                         0xffff] * 0x2000 >> 0x1f & 0x3fffU)) >> 0xe
                                ) + 0x2000) * local_30;
                    fVar6 = (float)((int)(local_30 + (local_30 >> 0x1f & 0x3fffU)) >> 0xe);
                    *pfVar10 = fVar6 * pfVar13[-2] * fVar7 + *pfVar10;
                    pfVar10[1] = fVar6 * pfVar13[-1] * fVar7 + pfVar10[1];
                    if (iVar12 == -0xc900) {
                      local_30 = 0x4000;
                    }
                    else {
                      local_30 = ((int)(short)(&DAT_00a8424c)
                                              [(int)(local_14 + 0x400000 +
                                                    (local_14 + 0x400000 >> 0x1f & 0x7fU)) >> 7 &
                                               0xffff] << 0xe) / (iVar12 + 0xc900);
                    }
                    local_30 = (((int)((short)(&DAT_00a8424c)
                                              [(iVar11 + 0x800000) / 0x8080 + 0x4000U & 0xffff] *
                                       0x2000 + ((short)(&DAT_00a8424c)
                                                        [(iVar11 + 0x800000) / 0x8080 + 0x4000U &
                                                         0xffff] * 0x2000 >> 0x1f & 0x3fffU)) >> 0xe
                                ) + 0x2000) * local_30;
                    fVar6 = (float)((int)(local_30 + (local_30 >> 0x1f & 0x3fffU)) >> 0xe);
                    *pfVar10 = fVar6 * *pfVar13 * fVar7 + *pfVar10;
                    pfVar10[1] = fVar6 * pfVar13[1] * fVar7 + pfVar10[1];
                    if (iVar12 == 0) {
                      local_30 = 0x4000;
                    }
                    else {
                      local_30 = ((int)(short)(&DAT_00a8424c)
                                              [(int)(local_14 + (local_14 >> 0x1f & 0x7fU)) >> 7 &
                                               0xffff] << 0xe) / iVar12;
                    }
                    local_30 = (((int)((short)(&DAT_00a8424c)[iVar11 / 0x8080 + 0x4000U & 0xffff] *
                                       0x2000 + ((short)(&DAT_00a8424c)
                                                        [iVar11 / 0x8080 + 0x4000U & 0xffff] *
                                                 0x2000 >> 0x1f & 0x3fffU)) >> 0xe) + 0x2000) *
                               local_30;
                    fVar6 = (float)((int)(local_30 + (local_30 >> 0x1f & 0x3fffU)) >> 0xe);
                    *pfVar10 = fVar6 * pfVar13[2] * fVar7 + *pfVar10;
                    pfVar10[1] = fVar6 * pfVar13[3] * fVar7 + pfVar10[1];
                    if (iVar12 == 0xc900) {
                      local_30 = 0x4000;
                    }
                    else {
                      local_30 = ((int)(short)(&DAT_00a8424c)
                                              [(int)(local_14 + -0x400000 +
                                                    (local_14 + -0x400000 >> 0x1f & 0x7fU)) >> 7 &
                                               0xffff] << 0xe) / (iVar12 + -0xc900);
                    }
                    local_30 = (((int)((short)(&DAT_00a8424c)
                                              [(iVar11 + -0x800000) / 0x8080 + 0x4000U & 0xffff] *
                                       0x2000 + ((short)(&DAT_00a8424c)
                                                        [(iVar11 + -0x800000) / 0x8080 + 0x4000U &
                                                         0xffff] * 0x2000 >> 0x1f & 0x3fffU)) >> 0xe
                                ) + 0x2000) * local_30;
                    local_14 = local_14 + -0x1000000;
                    iVar12 = iVar12 + -0x32400;
                    fVar6 = (float)((int)(local_30 + (local_30 >> 0x1f & 0x3fffU)) >> 0xe);
                    iVar11 = iVar11 + -0x2000000;
                    local_c = local_c + -1;
                    *pfVar10 = fVar6 * pfVar13[4] * fVar7 + *pfVar10;
                    pfVar10[1] = fVar6 * pfVar13[5] * fVar7 + pfVar10[1];
                    pfVar13 = pfVar13 + 8;
                  } while (local_c != 0);
                }
                if (local_1c <= local_2c) {
                  iVar12 = local_28 << 0x10;
                  iVar11 = local_28 << 0xf;
                  local_28 = local_28 * 0x192;
                  do {
                    if (local_28 == 0) {
                      local_30 = 0x4000;
                    }
                    else {
                      local_30 = ((int)(short)(&DAT_00a8424c)
                                              [(int)(iVar11 + (iVar11 >> 0x1f & 0x7fU)) >> 7 &
                                               0xffff] << 0xe) / local_28;
                    }
                    local_30 = (((int)((short)(&DAT_00a8424c)[iVar12 / 0x8080 + 0x4000U & 0xffff] *
                                       0x2000 + ((short)(&DAT_00a8424c)
                                                        [iVar12 / 0x8080 + 0x4000U & 0xffff] *
                                                 0x2000 >> 0x1f & 0x3fffU)) >> 0xe) + 0x2000) *
                               local_30;
                    local_1c = local_1c + 1;
                    fVar6 = (float)((int)(local_30 + (local_30 >> 0x1f & 0x3fffU)) >> 0xe);
                    local_28 = local_28 + -0xc900;
                    iVar11 = iVar11 + -0x400000;
                    iVar12 = iVar12 + -0x800000;
                    *pfVar10 = fVar6 * *(float *)(iVar5 + -8 + local_1c * 8) * fVar7 + *pfVar10;
                    pfVar10[1] = fVar6 * *(float *)(iVar5 + -4 + local_1c * 8) * fVar7 + pfVar10[1];
                  } while (local_1c <= local_2c);
                }
                pfVar10 = pfVar10 + 2;
                local_4 = local_4 + -1;
              } while (local_4 != 0);
              return 0;
            }
          }
          return 0;
        }
        iVar8 = FUN_0055db20(uVar2,0x20,piVar3[0xe],iVar9,1);
        if (-1 < iVar8) {
          iVar9 = FUN_0055db20(*(undefined2 *)((int)piVar4 + 0x36),0x20,piVar4[0xe],piVar4[0x12],1);
          if (-1 < iVar9) {
            FUN_0055ae40(param_1,iVar8);
            FUN_0055db50(iVar8,iVar9);
            FUN_0055b2d0(iVar9,param_2);
            FUN_005525d0(iVar8);
            FUN_005525d0(iVar9);
            return 0;
          }
          FUN_005525d0();
        }
      }
    }
  }
  return 0xffffffff;
}

