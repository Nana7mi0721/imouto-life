
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a72f0(float *param_1,undefined4 *param_2,int param_3,int param_4,int *param_5,
                 undefined4 param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  float *pfVar6;
  undefined4 *puVar7;
  uint uVar8;
  float *pfVar9;
  float *pfVar10;
  float *pfVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 auStack_58 [2];
  undefined1 auStack_50 [4];
  int aiStack_4c [4];
  float afStack_3c [4];
  undefined4 uStack_2c;
  int local_1c;
  int local_18;
  float *local_14;
  float *local_10;
  int local_c;
  int local_8;
  
  local_1c = 0;
  local_18 = 0;
  iVar14 = param_3 >> 2;
  uStack_2c = 0x7a731e;
  local_10 = afStack_3c + (5 - iVar14);
  iVar15 = param_3 + param_4 >> 2;
  afStack_3c[4 - iVar14] = 1.1245259e-38;
  pfVar10 = afStack_3c + ((5 - iVar15) - iVar14);
  iVar5 = param_4 >> 1;
  local_8 = iVar5;
  afStack_3c[(4 - iVar15) - iVar14] = 1.1245291e-38;
  local_14 = afStack_3c + (((5 - iVar5) - iVar15) - iVar14);
  if (0 < iVar14) {
    pfVar6 = param_1;
    pfVar11 = local_10;
    local_c = iVar14;
    do {
      fVar3 = *pfVar6;
      pfVar6 = pfVar6 + 2;
      *pfVar11 = fVar3;
      pfVar11 = pfVar11 + 1;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  if (0 < iVar15) {
    puVar7 = param_2;
    iVar16 = iVar15;
    local_14 = afStack_3c + (((5 - iVar5) - iVar15) - iVar14);
    do {
      uVar4 = *puVar7;
      puVar7 = puVar7 + 2;
      *pfVar10 = (float)uVar4;
      pfVar10 = pfVar10 + 1;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
  }
  pfVar6 = local_10;
  pfVar10 = local_14;
  afStack_3c[((4 - iVar5) - iVar15) - iVar14] = (float)param_6;
  afStack_3c[((3 - iVar5) - iVar15) - iVar14] = (float)(param_4 >> 2);
  afStack_3c[((2 - iVar5) - iVar15) - iVar14] = (float)iVar14;
  afStack_3c[((1 - iVar5) - iVar15) - iVar14] = (float)pfVar10;
  afStack_3c[(-iVar15 - iVar5) - iVar14] = (float)(afStack_3c + ((5 - iVar15) - iVar14));
  aiStack_4c[((3 - iVar5) - iVar15) - iVar14] = (int)pfVar6;
  aiStack_4c[((2 - iVar5) - iVar15) - iVar14] = 0x7a739f;
  FUN_007a6fd0();
  aiStack_4c[((2 - iVar5) - iVar15) - iVar14] = (int)&local_1c;
  aiStack_4c[((1 - iVar5) - iVar15) - iVar14] = param_4 >> 2;
  aiStack_4c[(-iVar15 - iVar5) - iVar14] = iVar14;
  *(float **)(auStack_50 + iVar5 * -4 + iVar15 * -4 + iVar14 * -4) =
       afStack_3c + ((5 - iVar15) - iVar14);
  pfVar10 = local_14;
  auStack_58[((1 - iVar5) - iVar15) - iVar14] = local_14;
  auStack_58[(-iVar15 - iVar5) - iVar14] = 0x7a73af;
  FUN_007a74f0();
  iVar16 = local_8;
  iVar17 = 0;
  param_3 = param_3 >> 1;
  if (0 < local_8) {
    pfVar6 = pfVar10;
    do {
      *pfVar6 = 0.0;
      uVar8 = iVar17 + local_1c * -2;
      uVar12 = (int)uVar8 >> 0x1f;
      if (((int)((uVar8 ^ uVar12) - uVar12) < 3) ||
         (uVar8 = iVar17 + local_18 * -2, uVar12 = (int)uVar8 >> 0x1f,
         (int)((uVar8 ^ uVar12) - uVar12) < 3)) {
        fVar3 = _DAT_007d5344;
        if (0 < param_3) {
          pfVar9 = (float *)(((int)param_2 - (int)pfVar10) + (int)pfVar6);
          pfVar11 = param_1;
          iVar13 = param_3;
          do {
            fVar1 = *pfVar9;
            fVar2 = *pfVar11;
            pfVar9 = pfVar9 + 1;
            pfVar11 = pfVar11 + 1;
            iVar13 = iVar13 + -1;
            fVar3 = fVar1 * fVar2 + fVar3;
          } while (iVar13 != 0);
          if (fVar3 < _DAT_007d5340) {
            fVar3 = _DAT_007d5340;
          }
        }
        *pfVar6 = fVar3;
      }
      iVar17 = iVar17 + 1;
      pfVar6 = pfVar6 + 1;
    } while (iVar17 < local_8);
  }
  afStack_3c[((4 - iVar5) - iVar15) - iVar14] = (float)&local_1c;
  afStack_3c[((3 - iVar5) - iVar15) - iVar14] = (float)iVar16;
  afStack_3c[((2 - iVar5) - iVar15) - iVar14] = (float)param_3;
  afStack_3c[((1 - iVar5) - iVar15) - iVar14] = (float)param_2;
  afStack_3c[(-iVar15 - iVar5) - iVar14] = (float)pfVar10;
  aiStack_4c[((3 - iVar5) - iVar15) - iVar14] = 0x7a7458;
  FUN_007a74f0();
  if ((0 < local_1c) && (local_1c < local_8 + -1)) {
    fVar3 = pfVar10[local_1c + -1];
    fVar1 = pfVar10[local_1c + 1];
    if ((pfVar10[local_1c] - fVar3) * _DAT_0083c880 < fVar1 - fVar3) {
      *param_5 = local_1c * 2 + -1;
      return;
    }
    if ((pfVar10[local_1c] - fVar1) * _DAT_0083c880 < fVar3 - fVar1) {
      *param_5 = local_1c * 2 + 1;
      return;
    }
  }
  *param_5 = local_1c * 2;
  return;
}

