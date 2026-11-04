
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

int FUN_007a4f10(int param_1,int *param_2,int param_3,int param_4,int param_5,int *param_6,
                int *param_7,int *param_8,uint param_9,uint *param_10,int param_11,int param_12,
                int param_13,int param_14,int param_15,undefined4 param_16,int param_17,int param_18
                ,int param_19)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint *puVar16;
  int aiStack_64 [4];
  short *local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  uint local_28;
  int local_24;
  uint local_18;
  int local_10;
  int local_8;
  
  iVar8 = (int)param_2;
  iVar15 = *(int *)(param_1 + 8);
  param_9 = param_9 & ((int)param_9 < 1) - 1;
  local_34 = 0;
  uVar10 = ((int)param_9 < 8) - 1 & 8;
  local_28 = 0;
  param_9 = param_9 - uVar10;
  local_30 = (int)param_2;
  if (param_14 == 2) {
    local_28 = (uint)(byte)(&DAT_0083c7cc)[param_3 - (int)param_2];
    if ((int)param_9 < (int)local_28) {
      local_28 = 0;
    }
    else {
      local_34 = ((int)(param_9 - local_28) < 8) - 1 & 8;
      param_9 = (param_9 - local_28) - local_34;
    }
  }
  aiStack_64[3] = 0x7a4f9f;
  piVar9 = aiStack_64 + 4;
  aiStack_64[3 - iVar15] = 0x7a4fae;
  iVar7 = iVar15 * -4 + -0x54;
  aiStack_64[iVar15 * -2 + 3] = 0x7a4fbd;
  aiStack_64[iVar15 * -3 + 3] = 0x7a4fcc;
  bVar3 = (byte)param_15;
  if ((int)param_2 < param_3) {
    iVar4 = (int)param_6 - param_15;
    iVar14 = param_3 - (int)param_2;
    iVar12 = (int)param_2;
    param_6 = aiStack_64 + iVar15 * -4 + (int)param_2 + 4;
    do {
      iVar14 = iVar14 + -1;
      iVar5 = ((((int)*(short *)(*(int *)(param_1 + 0x20) + 2 + iVar12 * 2) -
                (int)*(short *)(*(int *)(param_1 + 0x20) + iVar12 * 2)) * 3 << (bVar3 & 0x1f)) << 3)
              >> 4;
      if (iVar5 < param_14 * 8) {
        iVar5 = param_14 * 8;
      }
      param_6[iVar15] = iVar5;
      iVar5 = ((int)*(short *)(*(int *)(param_1 + 0x20) + 2 + iVar12 * 2) -
              (int)*(short *)(*(int *)(param_1 + 0x20) + iVar12 * 2)) * iVar14 * (iVar4 + -5) *
              (1 << (bVar3 + 3 & 0x1f)) * param_14 >> 6;
      *param_6 = iVar5;
      if ((int)*(short *)(*(int *)(param_1 + 0x20) + 2 + iVar12 * 2) -
          (int)*(short *)(*(int *)(param_1 + 0x20) + iVar12 * 2) << (bVar3 & 0x1f) == 1) {
        *param_6 = iVar5 + param_14 * -8;
      }
      iVar12 = iVar12 + 1;
      param_6 = param_6 + 1;
    } while (iVar12 < param_3);
  }
  iVar4 = 1;
  local_10 = 1;
  iVar12 = *(int *)(param_1 + 0x30) + -1;
  local_8 = iVar12;
  do {
    bVar2 = false;
    param_6 = (int *)0x0;
    iVar14 = iVar12 + iVar4 >> 1;
    if ((int)param_2 < param_3) {
      local_3c = (short *)(*(int *)(param_1 + 0x20) + (param_3 + -1) * 2);
      piVar11 = aiStack_64 + iVar15 * -4 + param_3 + 3;
      iVar12 = param_3 + -1;
      do {
        uVar6 = (int)(((int)local_3c[1] - (int)*local_3c) *
                      (uint)*(byte *)(iVar14 * iVar15 + *(int *)(param_1 + 0x34) + iVar12) *
                      param_14 << (bVar3 & 0x1f)) >> 2;
        if (0 < (int)uVar6) {
          uVar6 = uVar6 + *piVar11 & ((int)(uVar6 + *piVar11) < 0) - 1;
        }
        iVar4 = uVar6 + *(int *)((param_4 - (int)(aiStack_64 + iVar15 * -4 + 4)) + (int)piVar11);
        if ((piVar11[iVar15] <= iVar4) || (bVar2)) {
          bVar2 = true;
          iVar5 = *(int *)((param_5 - (int)(aiStack_64 + iVar15 * -4 + 4)) + (int)piVar11);
          if (iVar5 <= iVar4) {
            iVar4 = iVar5;
          }
LAB_007a517b:
          param_6 = (int *)((int)param_6 + iVar4);
        }
        else if (param_14 * 8 <= iVar4) {
          iVar4 = param_14 * 8;
          goto LAB_007a517b;
        }
        local_3c = local_3c + -1;
        piVar11 = piVar11 + -1;
        bVar1 = (int)param_2 < iVar12;
        iVar12 = iVar12 + -1;
      } while (bVar1);
      iVar4 = local_10;
      iVar12 = local_8;
    }
    if ((int)param_9 < (int)param_6) {
      iVar12 = iVar14 + -1;
      local_8 = iVar12;
    }
    else {
      iVar4 = iVar14 + 1;
      local_10 = iVar4;
    }
  } while (iVar4 <= iVar12);
  if ((int)param_2 < param_3) {
    piVar11 = aiStack_64 + iVar15 * -4 + (int)param_2 + 4;
    iVar12 = (int)param_2;
    do {
      iVar14 = (int)*(short *)(*(int *)(param_1 + 0x20) + 2 + iVar12 * 2) -
               (int)*(short *)(*(int *)(param_1 + 0x20) + iVar12 * 2);
      uVar6 = (int)((uint)*(byte *)((iVar4 + -1) * iVar15 + *(int *)(param_1 + 0x34) + iVar12) *
                    iVar14 * param_14 << (bVar3 & 0x1f)) >> 2;
      if (iVar4 < *(int *)(param_1 + 0x30)) {
        uVar13 = (int)((uint)*(byte *)(iVar4 * iVar15 + *(int *)(param_1 + 0x34) + iVar12) * iVar14
                       * param_14 << (bVar3 & 0x1f)) >> 2;
      }
      else {
        uVar13 = *(uint *)((param_5 - (int)(aiStack_64 + iVar15 * -4 + 4)) + (int)piVar11);
      }
      if (0 < (int)uVar6) {
        uVar6 = ((int)(*piVar11 + uVar6) < 0) - 1 & *piVar11 + uVar6;
      }
      if (0 < (int)uVar13) {
        uVar13 = ((int)(*piVar11 + uVar13) < 0) - 1 & *piVar11 + uVar13;
      }
      if (0 < iVar4 + -1) {
        uVar6 = uVar6 + *(int *)((param_4 - (int)(aiStack_64 + iVar15 * -4 + 4)) + (int)piVar11);
      }
      iVar14 = *(int *)((param_4 - (int)(aiStack_64 + iVar15 * -4 + 4)) + (int)piVar11);
      if (0 < iVar14) {
        local_30 = iVar12;
      }
      uVar13 = (uVar13 + iVar14) - uVar6;
      *(uint *)(((int)piVar9 - (int)(aiStack_64 + iVar15 * -3 + 4)) + (int)piVar11) = uVar6;
      iVar12 = iVar12 + 1;
      piVar11[iVar15 * 2] = ((int)uVar13 < 0) - 1 & uVar13;
      piVar11 = piVar11 + 1;
    } while (iVar12 < param_3);
  }
  local_10 = param_9;
  local_18 = local_28;
  bVar2 = 1 < param_14;
  local_24 = 0;
  local_38 = 0x40;
  local_8 = 6;
  do {
    param_4 = 0;
    bVar1 = false;
    iVar12 = local_24 + local_38 >> 1;
    if ((int)param_2 < param_3) {
      piVar11 = piVar9 + ((param_3 + -1) - iVar15);
      iVar4 = ((param_3 + -1) - (int)param_2) + 1;
      do {
        iVar14 = (*(int *)((int)aiStack_64 + (iVar7 - (int)piVar9) + 100 + (int)piVar11) * iVar12 >>
                 6) + *piVar11;
        if ((*(int *)((int)aiStack_64 + ((iVar15 * -4 + iVar7) - (int)piVar9) + 100 + (int)piVar11)
             <= iVar14) || (bVar1)) {
          bVar1 = true;
          iVar5 = *(int *)((param_5 - (int)(piVar9 + -iVar15)) + (int)piVar11);
          if (iVar5 <= iVar14) {
            iVar14 = iVar5;
          }
          param_4 = param_4 + iVar14;
        }
        else if (param_14 * 8 <= iVar14) {
          param_4 = param_4 + param_14 * 8;
        }
        iVar4 = iVar4 + -1;
        piVar11 = piVar11 + -1;
      } while (iVar4 != 0);
    }
    if ((int)param_9 < param_4) {
      local_38 = iVar12;
    }
    else {
      local_24 = iVar12;
    }
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  param_4 = 0;
  bVar1 = false;
  if ((int)param_2 < param_3) {
    piVar11 = piVar9 + ((param_3 + -1) - iVar15);
    iVar12 = ((param_3 + -1) - (int)param_2) + 1;
    do {
      uVar6 = (*(int *)((int)piVar11 + (int)aiStack_64 + (iVar7 - (int)piVar9) + 100) * local_24 >>
              6) + *piVar11;
      if ((*(int *)((int)piVar11 + (int)aiStack_64 + ((iVar15 * -4 + iVar7) - (int)piVar9) + 100) <=
           (int)uVar6) || (bVar1)) {
        bVar1 = true;
      }
      else {
        uVar6 = ((int)uVar6 < param_14 * 8) - 1 & param_14 * 8;
      }
      uVar13 = *(uint *)((int)piVar11 + (param_5 - (int)(piVar9 + -iVar15)));
      if ((int)uVar13 <= (int)uVar6) {
        uVar6 = uVar13;
      }
      *(uint *)((param_11 - (int)(piVar9 + -iVar15)) + (int)piVar11) = uVar6;
      param_4 = param_4 + uVar6;
      iVar12 = iVar12 + -1;
      piVar11 = piVar11 + -1;
    } while (iVar12 != 0);
  }
  local_8 = param_3;
  if (local_30 < param_3 + -1) {
    iVar7 = param_14 * 8 + 8;
    local_2c = param_3 + -1;
    do {
      iVar14 = (int)*(short *)(*(int *)(param_1 + 0x20) + local_8 * 2);
      iVar12 = (int)*(short *)(*(int *)(param_1 + 0x20) + (int)param_2 * 2);
      uVar13 = iVar14 - iVar12;
      uVar6 = (param_9 - param_4) / uVar13;
      iVar4 = (int)*(short *)(*(int *)(param_1 + 0x20) + local_2c * 2);
      uVar13 = ((param_9 - param_4) - uVar13 * uVar6) + (iVar12 - iVar4);
      iVar14 = iVar14 - iVar4;
      iVar4 = iVar14 * uVar6 + (uVar13 & ((int)uVar13 < 1) - 1) + *(int *)(param_11 + local_2c * 4);
      iVar12 = aiStack_64[iVar15 * -3 + local_2c + 4];
      if (aiStack_64[iVar15 * -3 + local_2c + 4] <= iVar7) {
        iVar12 = iVar7;
      }
      if (iVar12 <= iVar4) {
        if (param_17 == 0) {
          aiStack_64[iVar15 * -4 + 3] = 1;
          aiStack_64[iVar15 * -4 + 2] = param_16;
          aiStack_64[iVar15 * -4 + 1] = 0x7a553f;
          iVar12 = FUN_007a2130();
          if (iVar12 != 0) goto LAB_007a55fe;
        }
        else {
          if ((local_8 <= (int)param_2 + 2) ||
             (((int)(((((param_18 <= local_2c) - 1 & 0xfffffffe) + 9) * iVar14 << (bVar3 & 0x1f)) <<
                    3) >> 4 < iVar4 && (local_2c <= param_19)))) {
            aiStack_64[iVar15 * -4 + 3] = 1;
            aiStack_64[iVar15 * -4 + 2] = 1;
            aiStack_64[iVar15 * -4 + 1] = param_16;
            aiStack_64[iVar15 * -4] = 0x7a55f0;
            FUN_007a24d0();
            goto LAB_007a55fe;
          }
          aiStack_64[iVar15 * -4 + 3] = 1;
          aiStack_64[iVar15 * -4 + 2] = 0;
          aiStack_64[iVar15 * -4 + 1] = param_16;
          aiStack_64[iVar15 * -4] = 0x7a552f;
          FUN_007a24d0();
        }
        param_4 = param_4 + 8;
        iVar4 = iVar4 + -8;
      }
      iVar12 = local_18 + *(int *)(param_11 + local_2c * 4);
      if (local_18 != 0) {
        local_18 = (uint)(byte)(&DAT_0083c7cc)[local_2c - (int)param_2];
      }
      param_4 = (param_4 - iVar12) + local_18;
      iVar12 = param_14 * 8;
      if (iVar4 < iVar12) {
        *(undefined4 *)(param_11 + local_2c * 4) = 0;
      }
      else {
        *(int *)(param_11 + local_2c * 4) = iVar12;
        param_4 = param_4 + iVar12;
      }
      local_8 = local_8 + -1;
      local_2c = local_2c + -1;
    } while (local_30 < local_2c);
  }
  local_10 = uVar10 + param_9;
LAB_007a55fe:
  if (local_18 == 0) {
    *param_7 = 0;
  }
  else if (param_17 == 0) {
    aiStack_64[iVar15 * -4 + 3] = (local_8 - (int)param_2) + 1;
    aiStack_64[iVar15 * -4 + 2] = param_16;
    aiStack_64[iVar15 * -4 + 1] = 0x7a563f;
    iVar7 = FUN_007a21c0();
    *param_7 = iVar7 + (int)param_2;
  }
  else {
    iVar7 = *param_7;
    if (local_8 <= *param_7) {
      iVar7 = local_8;
    }
    *param_7 = iVar7;
    aiStack_64[iVar15 * -4 + 3] = (local_8 - (int)param_2) + 1;
    aiStack_64[iVar15 * -4 + 2] = iVar7 - (int)param_2;
    aiStack_64[iVar15 * -4 + 1] = param_16;
    aiStack_64[iVar15 * -4] = 0x7a562b;
    FUN_007a2540();
  }
  if ((int)param_2 < *param_7) {
    if (local_34 != 0) {
      aiStack_64[iVar15 * -4 + 3] = 1;
      if (param_17 == 0) {
        aiStack_64[iVar15 * -4 + 2] = param_16;
        aiStack_64[iVar15 * -4 + 1] = 0x7a5692;
        iVar15 = FUN_007a2130();
        *param_8 = iVar15;
      }
      else {
        aiStack_64[iVar15 * -4 + 2] = *param_8;
        aiStack_64[iVar15 * -4 + 1] = param_16;
        aiStack_64[iVar15 * -4] = 0x7a5681;
        FUN_007a24d0();
      }
      goto LAB_007a56ab;
    }
  }
  else {
    local_10 = local_10 + local_34;
  }
  *param_8 = 0;
LAB_007a56ab:
  uVar6 = (int)*(short *)(*(int *)(param_1 + 0x20) + local_8 * 2) -
          (int)*(short *)(*(int *)(param_1 + 0x20) + (int)param_2 * 2);
  uVar10 = (uint)(local_10 - param_4) / uVar6;
  iVar15 = (local_10 - param_4) - uVar6 * uVar10;
  if ((int)param_2 < local_8) {
    iVar7 = (int)param_2;
    piVar9 = (int *)(param_11 + (int)param_2 * 4);
    do {
      iVar4 = iVar7 * 2;
      iVar12 = iVar7 * 2;
      iVar7 = iVar7 + 1;
      *piVar9 = *piVar9 + ((int)*(short *)(*(int *)(param_1 + 0x20) + 2 + iVar4) -
                          (int)*(short *)(*(int *)(param_1 + 0x20) + iVar12)) * uVar10;
      piVar9 = piVar9 + 1;
    } while (iVar7 < local_8);
  }
  if ((int)param_2 < local_8) {
    iVar7 = (int)param_2;
    param_2 = (int *)(param_11 + (int)param_2 * 4);
    do {
      iVar12 = (int)*(short *)(*(int *)(param_1 + 0x20) + 2 + iVar7 * 2) -
               (int)*(short *)(*(int *)(param_1 + 0x20) + iVar7 * 2);
      if (iVar15 < iVar12) {
        iVar12 = iVar15;
      }
      iVar15 = iVar15 - iVar12;
      *param_2 = *param_2 + iVar12;
      iVar7 = iVar7 + 1;
      param_2 = param_2 + 1;
    } while (iVar7 < local_8);
  }
  param_9 = 0;
  if (iVar8 < local_8) {
    puVar16 = (uint *)(param_12 + iVar8 * 4);
    iVar15 = param_13 - param_12;
    do {
      piVar9 = (int *)((param_11 - param_12) + (int)puVar16);
      iVar12 = (int)*(short *)(*(int *)(param_1 + 0x20) + 2 + iVar8 * 2) -
               (int)*(short *)(*(int *)(param_1 + 0x20) + iVar8 * 2) << (bVar3 & 0x1f);
      iVar7 = *piVar9 + param_9;
      if (iVar12 < 2) {
        uVar10 = iVar7 + param_14 * -8;
        param_2 = (int *)(uVar10 & ((int)uVar10 < 0) - 1);
        *piVar9 = iVar7 - (int)param_2;
        *puVar16 = 0;
        *(undefined4 *)(iVar15 + (int)puVar16) = 1;
      }
      else {
        uVar10 = iVar7 - *(int *)((int)piVar9 + (param_5 - param_11));
        param_2 = (int *)(uVar10 & ((int)uVar10 < 1) - 1);
        iVar7 = iVar7 - (int)param_2;
        *piVar9 = iVar7;
        if ((((param_14 == 2) && (2 < iVar12)) && (*param_8 == 0)) && (iVar8 < *param_7)) {
          iVar4 = 1;
        }
        else {
          iVar4 = 0;
        }
        uVar10 = iVar12 * param_14 + iVar4;
        iVar4 = ((int)*(short *)(*(int *)(param_1 + 0x38) + iVar8 * 2) + param_15 * 8) * uVar10;
        iVar14 = (iVar4 >> 1) + uVar10 * -0x15;
        if (iVar12 == 2) {
          iVar14 = iVar14 + ((int)(uVar10 * 8) >> 2);
        }
        if (iVar7 + iVar14 < (int)(uVar10 * 0x10)) {
          iVar4 = iVar4 >> 2;
LAB_007a5845:
          iVar14 = iVar14 + iVar4;
        }
        else if (iVar7 + iVar14 < (int)(uVar10 * 0x18)) {
          iVar4 = iVar4 >> 3;
          goto LAB_007a5845;
        }
        uVar6 = iVar7 + uVar10 * 4 + iVar14;
        uVar6 = (uVar6 & ((int)uVar6 < 0) - 1) / uVar10 >> 3;
        *puVar16 = uVar6;
        if (*piVar9 >> 3 < (int)(uVar6 * param_14)) {
          *puVar16 = (*piVar9 >> bVar2) >> 3;
        }
        uVar6 = *puVar16;
        if (7 < (int)uVar6) {
          uVar6 = 8;
        }
        *puVar16 = uVar6;
        *(uint *)(iVar15 + (int)puVar16) = (uint)(*piVar9 + iVar14 <= (int)(uVar10 * 8 * uVar6));
        *piVar9 = *piVar9 + param_14 * *puVar16 * -8;
      }
      if (0 < (int)param_2) {
        iVar12 = (int)param_2 >> bVar2 + 3;
        iVar7 = 8 - *puVar16;
        if (iVar12 < (int)(8 - *puVar16)) {
          iVar7 = iVar12;
        }
        *puVar16 = *puVar16 + iVar7;
        iVar12 = (int)param_2 - param_9;
        param_2 = (int *)((int)param_2 + iVar7 * param_14 * -8);
        *(uint *)(iVar15 + (int)puVar16) = (uint)(iVar12 <= iVar7 * param_14 * 8);
      }
      iVar8 = iVar8 + 1;
      puVar16 = puVar16 + 1;
      param_9 = (uint)param_2;
    } while (iVar8 < local_8);
  }
  *param_10 = param_9;
  if (iVar8 < param_3) {
    piVar9 = (int *)(param_12 + iVar8 * 4);
    param_3 = param_3 - iVar8;
    do {
      *piVar9 = (*(int *)((int)piVar9 + (param_11 - param_12)) >> bVar2) >> 3;
      *(undefined4 *)((int)piVar9 + (param_11 - param_12)) = 0;
      *(uint *)((int)piVar9 + (param_13 - param_12)) = (uint)(*piVar9 < 1);
      piVar9 = piVar9 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return local_8;
}

