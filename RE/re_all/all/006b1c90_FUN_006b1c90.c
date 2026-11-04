
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006b1c90(uint param_1,float *param_2,int param_3,int param_4,float *param_5,float *param_6,
                 float *param_7,float *param_8,float *param_9,float *param_10)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float *pfVar12;
  int iVar13;
  float *pfVar14;
  float *pfVar15;
  float *pfVar16;
  int iVar17;
  float *pfVar18;
  float *pfVar19;
  float *pfVar20;
  float *pfVar21;
  int iVar22;
  float *pfVar23;
  int iVar24;
  uint uVar25;
  float *pfVar26;
  int iVar27;
  float10 fVar28;
  float10 fVar29;
  float *local_34;
  float *local_2c;
  float *local_28;
  float *local_20;
  float *local_1c;
  float *local_18;
  int local_c;
  
  iVar6 = param_1;
  iVar7 = (int)param_2 + 1 >> 1;
  iVar8 = (int)(param_1 + -1) >> 1;
  iVar9 = param_1 * param_3;
  fVar28 = (float10)fcos((float10)_DAT_00a0f380 / (float10)(int)param_2);
  iVar10 = param_1 * (int)param_2;
  fVar29 = (float10)fsin((float10)_DAT_00a0f380 / (float10)(int)param_2);
  if (param_1 != 1) {
    if (0 < param_4) {
      pfVar15 = param_9;
      iVar24 = param_4;
      do {
        *pfVar15 = *(float *)(((int)param_7 - (int)param_9) + (int)pfVar15);
        pfVar15 = pfVar15 + 1;
        iVar24 = iVar24 + -1;
      } while (iVar24 != 0);
    }
    if (1 < (int)param_2) {
      local_28 = (float *)((int)param_2 + -1);
      pfVar15 = param_8;
      do {
        pfVar15 = pfVar15 + iVar9;
        if (0 < param_3) {
          pfVar20 = pfVar15;
          iVar24 = param_3;
          do {
            *pfVar20 = *(float *)(((int)param_6 - (int)param_8) + (int)pfVar20);
            pfVar20 = pfVar20 + param_1;
            iVar24 = iVar24 + -1;
          } while (iVar24 != 0);
        }
        local_28 = (float *)((int)local_28 + -1);
      } while (local_28 != (float *)0x0);
    }
    if (param_3 < iVar8) {
      if (1 < (int)param_2) {
        iVar24 = 0;
        local_34 = (float *)((int)param_2 + -1);
        param_10 = (float *)((int)param_10 + -4 + param_1 * -4);
        do {
          iVar24 = iVar24 + iVar9 * 4;
          param_10 = param_10 + param_1;
          iVar11 = iVar24 + param_1 * -4;
          if (0 < param_3) {
            pfVar15 = (float *)(iVar11 + (int)param_8);
            local_2c = (float *)(iVar11 + -4 + (int)param_6);
            local_28 = (float *)param_3;
            do {
              pfVar15 = pfVar15 + param_1;
              local_2c = local_2c + param_1;
              if (2 < (int)param_1) {
                uVar25 = param_1 - 1 >> 1;
                pfVar20 = local_2c;
                pfVar21 = param_10;
                pfVar16 = pfVar15;
                do {
                  pfVar14 = pfVar20 + 2;
                  pfVar16 = pfVar16 + 2;
                  uVar25 = uVar25 - 1;
                  *(float *)(((int)param_8 - (int)param_6) + (int)pfVar14) =
                       pfVar20[2] * pfVar21[1] + pfVar20[3] * pfVar21[2];
                  *pfVar16 = pfVar21[1] * pfVar20[3] - *pfVar14 * pfVar21[2];
                  pfVar20 = pfVar14;
                  pfVar21 = pfVar21 + 2;
                } while (uVar25 != 0);
              }
              local_28 = (float *)((int)local_28 + -1);
            } while (local_28 != (float *)0x0);
          }
          local_34 = (float *)((int)local_34 + -1);
        } while (local_34 != (float *)0x0);
      }
    }
    else if (1 < (int)param_2) {
      pfVar20 = (float *)((int)param_10 + -4 + param_1 * -4);
      pfVar15 = param_6 + -1;
      local_28 = (float *)((int)param_2 + -1);
      pfVar21 = param_8;
      do {
        pfVar20 = pfVar20 + param_1;
        pfVar21 = pfVar21 + iVar9;
        pfVar15 = pfVar15 + iVar9;
        if (2 < (int)param_1) {
          param_10 = (float *)(param_1 - 1 >> 1);
          pfVar16 = pfVar15;
          pfVar14 = pfVar20;
          pfVar18 = pfVar21;
          do {
            pfVar23 = pfVar14 + 2;
            pfVar18 = pfVar18 + 2;
            pfVar16 = pfVar16 + 2;
            if (0 < param_3) {
              pfVar12 = pfVar16;
              iVar24 = param_3;
              pfVar26 = pfVar18;
              do {
                *(float *)((int)pfVar12 + ((int)param_8 - (int)param_6)) =
                     pfVar12[1] * *pfVar23 + *pfVar12 * pfVar14[1];
                pfVar19 = pfVar12 + 1;
                fVar1 = *pfVar12;
                pfVar12 = pfVar12 + param_1;
                *pfVar26 = *pfVar19 * pfVar14[1] - *pfVar23 * fVar1;
                pfVar26 = pfVar26 + param_1;
                iVar24 = iVar24 + -1;
              } while (iVar24 != 0);
            }
            param_10 = (float *)((int)param_10 - 1);
            pfVar14 = pfVar23;
          } while (param_10 != (float *)0x0);
        }
        local_28 = (float *)((int)local_28 + -1);
      } while (local_28 != (float *)0x0);
    }
    iVar11 = iVar9 * (int)param_2;
    iVar24 = 0;
    if (iVar8 < param_3) {
      if (1 < iVar7) {
        local_18 = (float *)(iVar7 + -1);
        do {
          iVar24 = iVar24 + iVar9;
          iVar11 = iVar11 - iVar9;
          if (2 < (int)param_1) {
            local_1c = (float *)(param_1 - 1 >> 1);
            iVar27 = iVar24 * 4;
            iVar22 = iVar24;
            do {
              iVar22 = iVar22 + 2;
              iVar27 = iVar27 + 8;
              iVar13 = iVar27 + param_1 * -4;
              if (0 < param_3) {
                iVar17 = (iVar22 - param_1) + (iVar11 - iVar24);
                pfVar15 = (float *)(iVar13 + (int)param_6);
                local_28 = param_6 + iVar17;
                pfVar20 = (float *)(iVar13 + -4 + (int)param_8);
                pfVar21 = param_8 + iVar17 + -1;
                local_20 = (float *)param_3;
                do {
                  pfVar16 = pfVar20 + param_1;
                  pfVar14 = pfVar21 + param_1;
                  pfVar20 = pfVar20 + param_1;
                  pfVar21 = pfVar21 + param_1;
                  pfVar15 = pfVar15 + param_1;
                  local_28 = local_28 + param_1;
                  *(float *)(((int)param_6 - (int)param_8) + (int)pfVar20) = *pfVar16 + *pfVar14;
                  *(float *)((int)pfVar21 + ((int)param_6 - (int)param_8)) = pfVar20[1] - pfVar21[1]
                  ;
                  *pfVar15 = pfVar21[1] + pfVar20[1];
                  *local_28 = *pfVar21 - *pfVar20;
                  local_20 = (float *)((int)local_20 + -1);
                } while (local_20 != (float *)0x0);
              }
              local_1c = (float *)((int)local_1c - 1);
            } while (local_1c != (float *)0x0);
          }
          local_18 = (float *)((int)local_18 + -1);
        } while (local_18 != (float *)0x0);
      }
    }
    else if (1 < iVar7) {
      pfVar20 = param_6 + iVar11;
      pfVar21 = param_8 + iVar11 + -1;
      pfVar15 = param_8 + -1;
      local_2c = (float *)(iVar7 + -1);
      pfVar16 = param_6;
      do {
        pfVar16 = pfVar16 + iVar9;
        pfVar15 = pfVar15 + iVar9;
        pfVar20 = pfVar20 + -iVar9;
        pfVar21 = pfVar21 + -iVar9;
        if (0 < param_3) {
          local_28 = (float *)param_3;
          param_10 = pfVar15;
          local_20 = pfVar21;
          local_1c = pfVar20;
          local_18 = pfVar16;
          do {
            if (2 < (int)param_1) {
              uVar25 = param_1 - 1 >> 1;
              pfVar14 = param_10;
              pfVar18 = local_20;
              pfVar23 = local_18;
              pfVar12 = local_1c;
              do {
                pfVar19 = pfVar18 + 2;
                pfVar26 = pfVar14 + 2;
                pfVar23 = pfVar23 + 2;
                pfVar12 = pfVar12 + 2;
                uVar25 = uVar25 - 1;
                *(float *)(((int)param_6 - (int)param_8) + (int)pfVar26) = pfVar18[2] + pfVar14[2];
                *(float *)((int)pfVar19 + ((int)param_6 - (int)param_8)) = pfVar14[3] - pfVar18[3];
                *pfVar23 = pfVar18[3] + pfVar14[3];
                *pfVar12 = *pfVar19 - *pfVar26;
                pfVar14 = pfVar26;
                pfVar18 = pfVar19;
              } while (uVar25 != 0);
            }
            param_10 = param_10 + param_1;
            local_18 = local_18 + param_1;
            local_1c = local_1c + param_1;
            local_20 = local_20 + param_1;
            local_28 = (float *)((int)local_28 + -1);
          } while (local_28 != (float *)0x0);
        }
        local_2c = (float *)((int)local_2c + -1);
      } while (local_2c != (float *)0x0);
    }
  }
  if (0 < param_4) {
    pfVar15 = param_7;
    iVar24 = param_4;
    do {
      *pfVar15 = *(float *)(((int)param_9 - (int)param_7) + (int)pfVar15);
      pfVar15 = pfVar15 + 1;
      iVar24 = iVar24 + -1;
    } while (iVar24 != 0);
  }
  if (1 < iVar7) {
    iVar24 = 0;
    local_1c = (float *)(iVar7 + -1);
    param_10 = (float *)((int)param_2 * param_4);
    do {
      iVar24 = iVar24 + iVar9 * 4;
      param_10 = (float *)((int)param_10 - iVar9);
      if (0 < param_3) {
        pfVar20 = (float *)(iVar24 + param_1 * -4 + (int)param_8);
        pfVar15 = param_8 + ((int)param_10 - param_1);
        local_18 = (float *)param_3;
        do {
          pfVar15 = pfVar15 + param_1;
          pfVar20 = pfVar20 + param_1;
          local_18 = (float *)((int)local_18 + -1);
          *(float *)((int)pfVar20 + ((int)param_6 - (int)param_8)) = *pfVar15 + *pfVar20;
          *(float *)((int)pfVar15 + ((int)param_6 - (int)param_8)) = *pfVar15 - *pfVar20;
        } while (local_18 != (float *)0x0);
      }
      local_1c = (float *)((int)local_1c + -1);
    } while (local_1c != (float *)0x0);
  }
  iVar24 = ((int)param_2 + -1) * param_4;
  if (1 < iVar7) {
    local_c = iVar7 + -1;
    param_10 = param_9 + (int)param_2 * param_4;
    local_34 = param_9;
    fVar1 = 1.0;
    fVar3 = _DAT_007d5344;
    do {
      fVar4 = fVar1 * (float)fVar28 - fVar3 * (float)fVar29;
      local_34 = local_34 + param_4;
      param_10 = param_10 + -param_4;
      fVar3 = fVar3 * (float)fVar28 + fVar1 * (float)fVar29;
      if (0 < param_4) {
        pfVar14 = param_7 + param_4;
        pfVar15 = local_34;
        pfVar20 = param_7;
        iVar11 = param_4;
        pfVar21 = param_7 + iVar24;
        pfVar16 = param_10;
        do {
          fVar1 = *pfVar14;
          pfVar14 = pfVar14 + 1;
          fVar2 = *pfVar20;
          pfVar20 = pfVar20 + 1;
          iVar11 = iVar11 + -1;
          *pfVar15 = fVar4 * fVar1 + fVar2;
          *pfVar16 = fVar3 * *pfVar21;
          pfVar15 = pfVar15 + 1;
          pfVar21 = pfVar21 + 1;
          pfVar16 = pfVar16 + 1;
        } while (iVar11 != 0);
      }
      if (2 < iVar7) {
        local_20 = (float *)(iVar7 + -2);
        local_28 = param_7 + param_4;
        local_2c = param_7 + iVar24;
        fVar1 = fVar4;
        fVar2 = fVar3;
        do {
          fVar5 = fVar1 * fVar4 - fVar2 * fVar3;
          local_28 = local_28 + param_4;
          local_2c = local_2c + -param_4;
          fVar2 = fVar1 * fVar3 + fVar2 * fVar4;
          if (0 < param_4) {
            pfVar15 = local_34;
            pfVar20 = param_10;
            iVar11 = param_4;
            pfVar21 = local_28;
            pfVar16 = local_2c;
            do {
              fVar1 = *pfVar21;
              pfVar21 = pfVar21 + 1;
              iVar11 = iVar11 + -1;
              *pfVar15 = fVar5 * fVar1 + *pfVar15;
              *pfVar20 = fVar2 * *pfVar16 + *pfVar20;
              pfVar15 = pfVar15 + 1;
              pfVar20 = pfVar20 + 1;
              pfVar16 = pfVar16 + 1;
            } while (iVar11 != 0);
          }
          local_20 = (float *)((int)local_20 + -1);
          fVar1 = fVar5;
        } while (local_20 != (float *)0x0);
      }
      local_c = local_c + -1;
      fVar1 = fVar4;
    } while (local_c != 0);
  }
  if (1 < iVar7) {
    param_6 = (float *)(iVar7 + -1);
    do {
      param_7 = param_7 + param_4;
      if (0 < param_4) {
        pfVar15 = param_9;
        pfVar20 = param_7;
        iVar24 = param_4;
        do {
          fVar1 = *pfVar20;
          pfVar20 = pfVar20 + 1;
          iVar24 = iVar24 + -1;
          *pfVar15 = fVar1 + *pfVar15;
          pfVar15 = pfVar15 + 1;
        } while (iVar24 != 0);
      }
      param_6 = (float *)((int)param_6 + -1);
    } while (param_6 != (float *)0x0);
  }
  if ((int)param_1 < param_3) {
    if (0 < (int)param_1) {
      param_6 = (float *)param_1;
      pfVar15 = param_8;
      do {
        if (0 < param_3) {
          pfVar21 = (float *)(((int)param_5 - (int)param_8) + (int)pfVar15);
          pfVar20 = pfVar15;
          iVar24 = param_3;
          do {
            *pfVar21 = *pfVar20;
            pfVar20 = pfVar20 + param_1;
            pfVar21 = pfVar21 + iVar10;
            iVar24 = iVar24 + -1;
          } while (iVar24 != 0);
        }
        pfVar15 = pfVar15 + 1;
        param_6 = (float *)((int)param_6 + -1);
      } while (param_6 != (float *)0x0);
    }
  }
  else if (0 < param_3) {
    param_4 = param_3;
    param_6 = param_8;
    pfVar15 = param_5;
    do {
      if (0 < (int)param_1) {
        pfVar20 = param_6;
        pfVar21 = pfVar15;
        iVar24 = param_1;
        do {
          fVar1 = *pfVar20;
          pfVar20 = pfVar20 + 1;
          *pfVar21 = fVar1;
          pfVar21 = pfVar21 + 1;
          iVar24 = iVar24 + -1;
        } while (iVar24 != 0);
      }
      param_6 = param_6 + param_1;
      pfVar15 = pfVar15 + iVar10;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  iVar24 = iVar9 * (int)param_2;
  if (1 < iVar7) {
    pfVar15 = param_8 + iVar24;
    param_2 = (float *)(iVar7 + -1);
    pfVar20 = param_5;
    pfVar21 = param_8;
    do {
      pfVar20 = pfVar20 + param_1 * 2;
      pfVar21 = pfVar21 + iVar9;
      pfVar15 = pfVar15 + -iVar9;
      if (0 < param_3) {
        param_6 = (float *)param_3;
        pfVar16 = pfVar20;
        pfVar14 = pfVar21;
        pfVar18 = pfVar15;
        do {
          fVar1 = *pfVar14;
          pfVar14 = pfVar14 + param_1;
          pfVar16[-1] = fVar1;
          *pfVar16 = *pfVar18;
          pfVar16 = pfVar16 + iVar10;
          pfVar18 = pfVar18 + param_1;
          param_6 = (float *)((int)param_6 + -1);
        } while (param_6 != (float *)0x0);
      }
      param_2 = (float *)((int)param_2 + -1);
    } while (param_2 != (float *)0x0);
  }
  if (param_1 != 1) {
    if (iVar8 < param_3) {
      iVar8 = -param_1;
      local_34 = (float *)0x0;
      if (1 < iVar7) {
        iVar11 = 0;
        param_6 = (float *)(iVar24 * 4);
        iVar24 = -2;
        local_c = iVar7 + -1;
        pfVar15 = param_5 + -2;
        do {
          iVar7 = iVar6 * 2;
          iVar11 = iVar11 + iVar9 * 4;
          iVar8 = iVar8 + iVar7;
          iVar24 = iVar24 + iVar7;
          pfVar15 = pfVar15 + iVar6 * 2;
          local_34 = (float *)((int)local_34 + iVar7);
          param_6 = (float *)((int)param_6 + iVar9 * -4);
          if (2 < iVar6) {
            param_7 = (float *)0x4;
            param_1 = iVar6 - 1U >> 1;
            param_2 = (float *)iVar24;
            param_10 = pfVar15;
            param_9 = (float *)iVar11;
            do {
              param_9 = (float *)((int)param_9 + 8);
              if (0 < param_3) {
                pfVar20 = (float *)((int)param_9 + (int)param_8);
                pfVar14 = (float *)(((int)param_9 - iVar11) + (int)param_6 + (int)param_8);
                pfVar21 = param_5 + (((int)param_2 - iVar8) - iVar6) + (int)param_7 + (int)local_34;
                param_4 = param_3;
                pfVar16 = param_10;
                do {
                  pfVar21[-1] = pfVar20[-1] + pfVar14[-1];
                  pfVar16[-1] = pfVar20[-1] - pfVar14[-1];
                  *pfVar21 = *pfVar14 + *pfVar20;
                  fVar1 = *pfVar14;
                  fVar3 = *pfVar20;
                  pfVar14 = pfVar14 + iVar6;
                  pfVar20 = pfVar20 + iVar6;
                  pfVar21 = pfVar21 + iVar10;
                  *pfVar16 = fVar1 - fVar3;
                  pfVar16 = pfVar16 + iVar10;
                  param_4 = param_4 + -1;
                } while (param_4 != 0);
              }
              param_10 = param_10 + -2;
              param_2 = (float *)((int)param_2 + -2);
              param_7 = (float *)((int)param_7 + 4);
              param_1 = param_1 - 1;
            } while (param_1 != 0);
          }
          local_c = local_c + -1;
        } while (local_c != 0);
        return;
      }
    }
    else if (1 < iVar7) {
      pfVar20 = param_8 + 2;
      pfVar15 = param_5 + 2;
      param_5 = param_5 + -2;
      param_9 = (float *)(iVar7 + -1);
      param_8 = param_8 + iVar24 + 2;
      do {
        pfVar20 = pfVar20 + iVar9;
        param_5 = param_5 + param_1 * 2;
        pfVar15 = pfVar15 + param_1 * 2;
        param_8 = param_8 + -iVar9;
        if (0 < param_3) {
          pfVar21 = pfVar15;
          param_2 = pfVar20;
          param_4 = param_3;
          param_6 = param_5;
          param_7 = param_8;
          do {
            if (2 < (int)param_1) {
              uVar25 = param_1 - 1 >> 1;
              pfVar16 = param_7;
              pfVar14 = param_2;
              pfVar18 = pfVar21;
              pfVar23 = param_6;
              do {
                uVar25 = uVar25 - 1;
                pfVar18[-1] = pfVar14[-1] + pfVar16[-1];
                pfVar23[-1] = pfVar14[-1] - pfVar16[-1];
                *pfVar18 = *pfVar14 + *pfVar16;
                *pfVar23 = *pfVar16 - *pfVar14;
                pfVar16 = pfVar16 + 2;
                pfVar14 = pfVar14 + 2;
                pfVar18 = pfVar18 + 2;
                pfVar23 = pfVar23 + -2;
              } while (uVar25 != 0);
            }
            pfVar21 = pfVar21 + iVar10;
            param_6 = param_6 + iVar10;
            param_2 = param_2 + param_1;
            param_7 = param_7 + param_1;
            param_4 = param_4 + -1;
          } while (param_4 != 0);
        }
        param_9 = (float *)((int)param_9 + -1);
      } while (param_9 != (float *)0x0);
    }
  }
  return;
}

