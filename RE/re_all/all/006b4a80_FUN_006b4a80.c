
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006b4a80(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  code *pcVar8;
  undefined4 uVar9;
  uint *puVar10;
  uint uVar11;
  int *piVar12;
  uint *puVar13;
  int iVar14;
  float *pfVar15;
  int iVar16;
  uint *puVar17;
  undefined1 *puVar18;
  uint *puVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  undefined4 *puVar24;
  int iVar25;
  undefined4 uStack_40;
  int local_28;
  int *local_24;
  uint *local_10;
  int *local_8;
  
  iVar3 = *(int *)(param_1[0x10] + 4);
  iVar4 = *(int *)(param_1[0x10] + 0x68);
  iVar25 = *(int *)(iVar3 + 0x1c);
  uVar5 = *(uint *)(iVar25 + param_1[7] * 4);
  param_1[9] = uVar5;
  iVar6 = *(int *)(iVar3 + 4);
  uStack_40 = 0x6b4ac3;
  (&uStack_40)[-iVar6] = 0x6b4ad2;
  puVar10 = (uint *)((int)register0x00000010 + iVar6 * -8 + -0x3c);
  (&uStack_40)[iVar6 * -2] = 0x6b4ae1;
  local_10 = puVar10 + -iVar6;
  puVar19 = puVar10 + iVar6 * -2;
  puVar17 = puVar10 + iVar6 * -2;
  puVar10[-1 - iVar6] = 0x6b4af0;
  iVar16 = 0;
  if (0 < iVar6) {
    local_8 = param_2;
    while( true ) {
      local_8 = local_8 + 1;
      puVar7 = (&PTR_DAT_008298c4)[*(int *)(iVar25 + 800 + param_2[*local_8 + 0x101] * 4)];
      *(undefined4 *)((int)puVar17 + -4) =
           *(undefined4 *)(*(int *)(iVar4 + 0x30) + param_2[*local_8 + 0x101] * 4);
      *(int **)((int)puVar17 + -8) = param_1;
      pcVar8 = *(code **)(puVar7 + 0x14);
      puVar18 = (undefined1 *)((int)puVar17 + -0xc);
      *(undefined4 *)((int)puVar17 + -0xc) = 0x6b4b51;
      uVar11 = (*pcVar8)();
      puVar19 = (uint *)(puVar18 + 8);
      puVar17 = (uint *)(puVar18 + 8);
      local_10[-iVar6] = uVar11;
      *local_10 = (uint)(uVar11 != 0);
      puVar24 = *(undefined4 **)(*param_1 + iVar16 * 4);
      for (uVar11 = (uVar5 & 0x3fffffff) >> 1; uVar11 != 0; uVar11 = uVar11 - 1) {
        *puVar24 = 0;
        puVar24 = puVar24 + 1;
      }
      iVar16 = iVar16 + 1;
      for (iVar14 = (uVar5 & 1) << 1; iVar14 != 0; iVar14 = iVar14 + -1) {
        *(undefined1 *)puVar24 = 0;
        puVar24 = (undefined4 *)((int)puVar24 + 1);
      }
      local_10 = local_10 + 1;
      if (*(int *)(iVar3 + 4) <= iVar16) break;
    }
  }
  local_8 = (int *)0x0;
  if (0 < param_2[0x121]) {
    piVar12 = param_2 + 0x222;
    do {
      if ((puVar10[piVar12[-0x100] - iVar6] != 0) || (puVar10[*piVar12 - iVar6] != 0)) {
        puVar10[piVar12[-0x100] - iVar6] = 1;
        puVar10[*piVar12 - iVar6] = 1;
      }
      local_8 = (int *)((int)local_8 + 1);
      piVar12 = piVar12 + 1;
    } while ((int)local_8 < param_2[0x121]);
  }
  local_8 = (int *)0x0;
  puVar23 = (undefined1 *)puVar19;
  if (0 < *param_2) {
    local_24 = param_2 + 0x111;
    do {
      iVar14 = 0;
      iVar16 = 0;
      if (0 < *(int *)(iVar3 + 4)) {
        puVar13 = puVar10;
        local_10 = (uint *)param_2;
        do {
          local_10 = local_10 + 1;
          if ((int *)*local_10 == local_8) {
            *puVar13 = (uint)(puVar10[iVar16 - iVar6] != 0);
            iVar14 = iVar14 + 1;
            puVar13 = puVar13 + 1;
            *(undefined4 *)((int)&uStack_40 + (iVar6 * -4 - (int)puVar10) + (int)puVar13) =
                 *(undefined4 *)(*param_1 + iVar16 * 4);
          }
          iVar16 = iVar16 + 1;
        } while (iVar16 < *(int *)(iVar3 + 4));
      }
      *(int *)((int)puVar19 + -4) = iVar14;
      iVar16 = *local_24;
      puVar7 = (&PTR_DAT_008298cc)[*(int *)(iVar25 + 0x520 + iVar16 * 4)];
      *(uint **)((int)puVar19 + -8) = puVar10;
      *(int *)((int)puVar19 + -0xc) = (int)register0x00000010 + iVar6 * -4 + -0x3c;
      *(undefined4 *)((int)puVar19 + -0x10) = *(undefined4 *)(*(int *)(iVar4 + 0x34) + iVar16 * 4);
      *(int **)((int)puVar19 + -0x14) = param_1;
      pcVar8 = *(code **)(puVar7 + 0x1c);
      puVar20 = (undefined1 *)((int)puVar19 + -0x18);
      *(undefined4 *)((int)puVar19 + -0x18) = 0x6b4c93;
      (*pcVar8)();
      puVar19 = (uint *)(puVar20 + 0x14);
      puVar23 = puVar20 + 0x14;
      local_8 = (int *)((int)local_8 + 1);
      local_24 = local_24 + 1;
    } while ((int)local_8 < *param_2);
  }
  local_24 = (int *)param_2[0x121];
  if (-1 < (int)local_24 + -1) {
    piVar12 = param_2 + (int)local_24 + 0x221;
    do {
      pfVar15 = *(float **)(*param_1 + piVar12[-0x100] * 4);
      if (0 < (int)uVar5 / 2) {
        iVar16 = *(int *)(*param_1 + *piVar12 * 4) - (int)pfVar15;
        local_28 = (int)uVar5 / 2;
        do {
          fVar1 = *pfVar15;
          fVar2 = *(float *)(iVar16 + (int)pfVar15);
          if (fVar1 <= _DAT_007d5344) {
            if (fVar2 <= _DAT_007d5344) {
              *(float *)(iVar16 + (int)pfVar15) = fVar1;
              fVar2 = fVar1 - fVar2;
              goto LAB_006b4d37;
            }
            *(float *)(iVar16 + (int)pfVar15) = fVar2 + fVar1;
          }
          else if (fVar2 <= _DAT_007d5344) {
            *(float *)(iVar16 + (int)pfVar15) = fVar1;
            fVar2 = fVar2 + fVar1;
LAB_006b4d37:
            *pfVar15 = fVar2;
          }
          else {
            *(float *)(iVar16 + (int)pfVar15) = fVar1 - fVar2;
          }
          pfVar15 = pfVar15 + 1;
          local_28 = local_28 + -1;
        } while (local_28 != 0);
      }
      piVar12 = piVar12 + -1;
      local_24 = (int *)((int)local_24 + -1);
    } while (local_24 != (int *)0x0);
  }
  iVar16 = 0;
  puVar21 = puVar23;
  piVar12 = param_2;
  if (0 < *(int *)(iVar3 + 4)) {
    do {
      iVar14 = param_2[piVar12[1] + 0x101];
      puVar7 = (&PTR_DAT_008298c4)[*(int *)(iVar25 + 800 + iVar14 * 4)];
      *(undefined4 *)(puVar21 + -4) = *(undefined4 *)(*param_1 + iVar16 * 4);
      *(uint *)(puVar21 + -8) = puVar10[iVar6 * -2 + iVar16];
      *(undefined4 *)(puVar21 + -0xc) = *(undefined4 *)(*(int *)(iVar4 + 0x30) + iVar14 * 4);
      *(int **)(puVar21 + -0x10) = param_1;
      pcVar8 = *(code **)(puVar7 + 0x18);
      puVar22 = puVar21 + -0x14;
      *(undefined4 *)(puVar21 + -0x14) = 0x6b4d9d;
      (*pcVar8)();
      puVar23 = puVar22 + 0x10;
      iVar16 = iVar16 + 1;
      puVar21 = puVar22 + 0x10;
      piVar12 = piVar12 + 1;
    } while (iVar16 < *(int *)(iVar3 + 4));
  }
  iVar25 = 0;
  if (0 < *(int *)(iVar3 + 4)) {
    do {
      iVar6 = param_1[7];
      uVar9 = *(undefined4 *)(*param_1 + iVar25 * 4);
      *(undefined4 *)(puVar23 + -4) = uVar9;
      *(undefined4 *)(puVar23 + -8) = uVar9;
      *(undefined4 *)(puVar23 + -0xc) = **(undefined4 **)(iVar4 + 0xc + iVar6 * 4);
      *(undefined4 *)(puVar23 + -0x10) = 0x6b4dd1;
      FUN_006b2c90();
      iVar25 = iVar25 + 1;
    } while (iVar25 < *(int *)(iVar3 + 4));
  }
  return 0;
}

