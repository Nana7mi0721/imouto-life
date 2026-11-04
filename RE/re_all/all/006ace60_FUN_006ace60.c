
undefined4 FUN_006ace60(int param_1,int *param_2)

{
  float *pfVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  int iVar12;
  float *pfVar13;
  undefined4 *puVar14;
  int iVar15;
  uint uVar16;
  byte bVar17;
  float *pfVar18;
  int iVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  uint local_3c;
  float *local_30;
  uint local_2c;
  uint local_24;
  int local_20;
  
  iVar15 = *(int *)(param_1 + 4);
  iVar20 = *(int *)(param_1 + 0x68);
  piVar3 = *(int **)(iVar15 + 0x1c);
  iVar4 = piVar3[0x392];
  if (param_2 == (int *)0x0) {
    return 0xffffff7d;
  }
  if ((*(int *)(param_1 + 0x18) < *(int *)(param_1 + 0x14)) && (*(int *)(param_1 + 0x18) != -1)) {
    return 0xffffff7d;
  }
  uVar5 = *(uint *)(param_1 + 0x40);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x28);
  *(int *)(param_1 + 0x28) = param_2[7];
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  if ((((uVar5 & *(uint *)(param_1 + 0x44)) == 0xffffffff) || (uVar5 + 1 != param_2[0xe])) ||
     (*(uint *)(param_1 + 0x44) + (uint)(0xfffffffe < uVar5) != param_2[0xf])) {
    *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
    *(undefined4 *)(iVar20 + 0x80) = 0xffffffff;
    *(undefined4 *)(iVar20 + 0x84) = 0xffffffff;
  }
  *(int *)(param_1 + 0x40) = param_2[0xe];
  *(int *)(param_1 + 0x44) = param_2[0xf];
  bVar7 = (byte)iVar4;
  if (*param_2 != 0) {
    bVar17 = bVar7 + 1;
    iVar9 = piVar3[*(int *)(param_1 + 0x28)] >> (bVar17 & 0x1f);
    iVar22 = *piVar3 >> (bVar17 & 0x1f);
    uVar21 = piVar3[1] >> (bVar17 & 0x1f);
    uVar5 = *(uint *)(param_1 + 0x48);
    uVar16 = param_2[0x16];
    *(uint *)(param_1 + 0x48) = uVar5 + uVar16;
    uVar6 = *(uint *)(param_1 + 0x50);
    *(uint *)(param_1 + 0x4c) =
         *(int *)(param_1 + 0x4c) + ((int)uVar16 >> 0x1f) + (uint)CARRY4(uVar5,uVar16);
    uVar5 = param_2[0x17];
    *(uint *)(param_1 + 0x50) = uVar6 + uVar5;
    uVar16 = *(uint *)(param_1 + 0x58);
    *(uint *)(param_1 + 0x54) =
         *(int *)(param_1 + 0x54) + ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar6,uVar5);
    uVar5 = param_2[0x18];
    *(uint *)(param_1 + 0x58) = uVar16 + uVar5;
    uVar6 = *(uint *)(param_1 + 0x60);
    *(uint *)(param_1 + 0x5c) =
         *(int *)(param_1 + 0x5c) + ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar16,uVar5);
    uVar5 = param_2[0x19];
    *(uint *)(param_1 + 0x60) = uVar6 + uVar5;
    *(uint *)(param_1 + 100) =
         *(int *)(param_1 + 100) + ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar6,uVar5);
    if (*(int *)(param_1 + 0x30) == 0) {
      local_2c = 0;
      local_3c = uVar21;
    }
    else {
      local_3c = 0;
      local_2c = uVar21;
    }
    local_30 = (float *)0x0;
    if (0 < *(int *)(iVar15 + 4)) {
      do {
        pfVar8 = local_30;
        local_24 = iVar22;
        if (*(int *)(param_1 + 0x24) == 0) {
          if (*(int *)(param_1 + 0x28) == 0) {
            iVar10 = FUN_006b3cd0(*(int *)(iVar20 + 4) - iVar4);
            pfVar1 = (float *)(*(int *)(*(int *)(param_1 + 8) + (int)local_30 * 4) + local_3c * 4);
            iVar19 = *(int *)(*param_2 + (int)local_30 * 4);
            if (0 < iVar22) {
              pfVar13 = pfVar1;
              pfVar11 = (float *)(iVar10 + -4 + iVar22 * 4);
              local_20 = iVar22;
              while( true ) {
                pfVar18 = (float *)((iVar10 - (int)pfVar1) + (int)pfVar13);
                local_20 = local_20 + -1;
                *pfVar13 = *pfVar11 * *pfVar13 +
                           *(float *)((int)pfVar18 + (iVar19 - iVar10)) * *pfVar18;
                if (local_20 == 0) break;
                pfVar13 = pfVar13 + 1;
                pfVar11 = pfVar11 + -1;
              }
            }
          }
          else {
            iVar12 = FUN_006b3cd0(*(int *)(iVar20 + 4) - iVar4);
            pfVar1 = (float *)(*(int *)(*(int *)(param_1 + 8) + (int)local_30 * 4) + local_3c * 4);
            iVar19 = *(int *)(*param_2 + (int)local_30 * 4) + ((int)uVar21 / 2 - iVar22 / 2) * 4;
            iVar10 = 0;
            if (0 < iVar22) {
              pfVar13 = (float *)(iVar12 + -4 + iVar22 * 4);
              pfVar11 = pfVar1;
              while( true ) {
                pfVar18 = (float *)((iVar12 - (int)pfVar1) + (int)pfVar11);
                local_24 = local_24 + -1;
                *pfVar11 = *pfVar13 * *pfVar11 +
                           *(float *)((int)pfVar18 + (iVar19 - iVar12)) * *pfVar18;
                if (local_24 == 0) break;
                pfVar13 = pfVar13 + -1;
                pfVar11 = pfVar11 + 1;
              }
              iVar10 = iVar22;
            }
            iVar12 = (int)uVar21 / 2 + iVar22 / 2;
            if (iVar10 < iVar12) {
              pfVar13 = pfVar1 + iVar10;
              iVar12 = iVar12 - iVar10;
              do {
                *pfVar13 = *(float *)((iVar19 - (int)pfVar1) + (int)pfVar13);
                pfVar13 = pfVar13 + 1;
                iVar12 = iVar12 + -1;
              } while (iVar12 != 0);
            }
          }
        }
        else if (*(int *)(param_1 + 0x28) == 0) {
          iVar10 = FUN_006b3cd0(*(int *)(iVar20 + 4) - iVar4);
          pfVar1 = (float *)(*(int *)(*(int *)(param_1 + 8) + (int)local_30 * 4) +
                            (((int)uVar21 / 2 - iVar22 / 2) + local_3c) * 4);
          iVar19 = *(int *)(*param_2 + (int)local_30 * 4);
          if (0 < iVar22) {
            pfVar13 = pfVar1;
            pfVar11 = (float *)(iVar10 + -4 + iVar22 * 4);
            while( true ) {
              pfVar18 = (float *)((iVar10 - (int)pfVar1) + (int)pfVar13);
              local_24 = local_24 + -1;
              *pfVar13 = *pfVar11 * *pfVar13 +
                         *(float *)((int)pfVar18 + (iVar19 - iVar10)) * *pfVar18;
              if (local_24 == 0) break;
              pfVar13 = pfVar13 + 1;
              pfVar11 = pfVar11 + -1;
            }
          }
        }
        else {
          iVar10 = FUN_006b3cd0(*(int *)(iVar20 + 8) - iVar4);
          pfVar1 = (float *)(*(int *)(*(int *)(param_1 + 8) + (int)local_30 * 4) + local_3c * 4);
          iVar19 = *(int *)(*param_2 + (int)local_30 * 4);
          if (0 < (int)uVar21) {
            local_30 = (float *)(iVar10 + -4 + uVar21 * 4);
            pfVar13 = pfVar1;
            local_24 = uVar21;
            while( true ) {
              pfVar11 = (float *)((iVar10 - (int)pfVar1) + (int)pfVar13);
              fVar2 = *local_30;
              local_30 = local_30 + -1;
              local_24 = local_24 - 1;
              *pfVar13 = fVar2 * *pfVar13 + *(float *)((int)pfVar11 + (iVar19 - iVar10)) * *pfVar11;
              if (local_24 == 0) break;
              pfVar13 = pfVar13 + 1;
            }
          }
        }
        puVar14 = (undefined4 *)(*(int *)(*(int *)(param_1 + 8) + (int)pfVar8 * 4) + local_2c * 4);
        if (0 < iVar9) {
          iVar19 = (*(int *)(*param_2 + (int)pfVar8 * 4) + iVar9 * 4) - (int)puVar14;
          local_20 = iVar9;
          do {
            *puVar14 = *(undefined4 *)(iVar19 + (int)puVar14);
            puVar14 = puVar14 + 1;
            local_20 = local_20 + -1;
          } while (local_20 != 0);
        }
        local_30 = (float *)((int)pfVar8 + 1);
      } while ((int)local_30 < *(int *)(iVar15 + 4));
    }
    *(uint *)(param_1 + 0x30) = ~-(uint)(*(int *)(param_1 + 0x30) != 0) & uVar21;
    if (*(int *)(param_1 + 0x18) == -1) {
      *(uint *)(param_1 + 0x18) = local_2c;
      *(uint *)(param_1 + 0x14) = local_2c;
    }
    else {
      *(uint *)(param_1 + 0x18) = local_3c;
      *(uint *)(param_1 + 0x14) =
           (((int)(piVar3[*(int *)(param_1 + 0x24)] +
                  (piVar3[*(int *)(param_1 + 0x24)] >> 0x1f & 3U)) >> 2) +
            ((int)(piVar3[*(int *)(param_1 + 0x28)] +
                  (piVar3[*(int *)(param_1 + 0x28)] >> 0x1f & 3U)) >> 2) >> (bVar7 & 0x1f)) +
           local_3c;
    }
  }
  if ((*(uint *)(iVar20 + 0x80) & *(uint *)(iVar20 + 0x84)) == 0xffffffff) {
    *(undefined4 *)(iVar20 + 0x80) = 0;
    *(undefined4 *)(iVar20 + 0x84) = 0;
  }
  else {
    uVar16 = ((int)(piVar3[*(int *)(param_1 + 0x28)] +
                   (piVar3[*(int *)(param_1 + 0x28)] >> 0x1f & 3U)) >> 2) +
             ((int)(piVar3[*(int *)(param_1 + 0x24)] +
                   (piVar3[*(int *)(param_1 + 0x24)] >> 0x1f & 3U)) >> 2);
    uVar5 = *(uint *)(iVar20 + 0x80);
    *(uint *)(iVar20 + 0x80) = uVar16 + uVar5;
    *(uint *)(iVar20 + 0x84) =
         ((int)uVar16 >> 0x1f) + *(int *)(iVar20 + 0x84) + (uint)CARRY4(uVar16,uVar5);
  }
  uVar5 = *(uint *)(param_1 + 0x38);
  if ((uVar5 & *(uint *)(param_1 + 0x3c)) == 0xffffffff) {
    uVar5 = param_2[0xd];
    if ((param_2[0xc] & uVar5) != 0xffffffff) {
      *(int *)(param_1 + 0x38) = param_2[0xc];
      *(uint *)(param_1 + 0x3c) = uVar5;
      if (((int)uVar5 <= *(int *)(iVar20 + 0x84)) &&
         (((int)uVar5 < *(int *)(iVar20 + 0x84) ||
          (*(uint *)(param_1 + 0x38) < *(uint *)(iVar20 + 0x80))))) {
        iVar15 = *(int *)(iVar20 + 0x80) - param_2[0xc];
        if (iVar15 < 0) {
          iVar15 = 0;
        }
        if (param_2[0xb] == 0) {
          iVar15 = *(int *)(param_1 + 0x18) + (iVar15 >> (bVar7 & 0x1f));
          *(int *)(param_1 + 0x18) = iVar15;
          if (*(int *)(param_1 + 0x14) < iVar15) {
            *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x14);
          }
        }
        else {
          iVar20 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x18) << (bVar7 & 0x1f);
          if (iVar20 < iVar15) {
            iVar15 = iVar20;
          }
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - (iVar15 >> (bVar7 & 0x1f));
        }
      }
    }
  }
  else {
    uVar16 = ((int)(piVar3[*(int *)(param_1 + 0x28)] +
                   (piVar3[*(int *)(param_1 + 0x28)] >> 0x1f & 3U)) >> 2) +
             ((int)(piVar3[*(int *)(param_1 + 0x24)] +
                   (piVar3[*(int *)(param_1 + 0x24)] >> 0x1f & 3U)) >> 2);
    *(uint *)(param_1 + 0x38) = uVar16 + uVar5;
    *(uint *)(param_1 + 0x3c) =
         ((int)uVar16 >> 0x1f) + *(int *)(param_1 + 0x3c) + (uint)CARRY4(uVar16,uVar5);
    uVar5 = param_2[0xc];
    uVar16 = param_2[0xd];
    if ((uVar5 & uVar16) != 0xffffffff) {
      uVar6 = *(uint *)(param_1 + 0x3c);
      if ((*(uint *)(param_1 + 0x38) != uVar5) || (uVar6 != uVar16)) {
        if (((((int)uVar16 <= (int)uVar6) &&
             (((int)uVar16 < (int)uVar6 || (uVar5 < *(uint *)(param_1 + 0x38))))) &&
            (iVar15 = *(int *)(param_1 + 0x38) - param_2[0xc], iVar15 != 0)) && (param_2[0xb] != 0))
        {
          iVar20 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x18) << (bVar7 & 0x1f);
          if (iVar20 < iVar15) {
            iVar15 = iVar20;
          }
          if (iVar15 < 0) {
            iVar15 = 0;
          }
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - (iVar15 >> (bVar7 & 0x1f));
        }
        *(int *)(param_1 + 0x38) = param_2[0xc];
        *(int *)(param_1 + 0x3c) = param_2[0xd];
      }
    }
  }
  if (param_2[0xb] != 0) {
    *(undefined4 *)(param_1 + 0x20) = 1;
  }
  return 0;
}

