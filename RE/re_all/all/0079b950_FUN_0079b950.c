
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_0079b950(uint *param_1,int *param_2,short *param_3,int *param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  undefined1 *puVar5;
  short sVar6;
  undefined4 uVar7;
  longlong lVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  short *psVar16;
  byte bVar17;
  undefined2 uVar18;
  int iVar19;
  uint uVar20;
  uint *puVar21;
  undefined4 *puVar22;
  undefined4 *puVar23;
  undefined4 *puVar24;
  int aiStack_b4 [9];
  short local_84;
  short local_82;
  short local_80;
  short local_7e;
  short local_7c;
  short local_7a;
  short local_78;
  short local_76;
  short local_74;
  short local_72;
  short local_70 [6];
  int local_64;
  int local_60;
  int local_5c;
  byte local_4c [4];
  int local_48;
  byte local_44 [4];
  int local_40;
  undefined1 *local_3c;
  uint local_38;
  int *local_34;
  int local_30;
  undefined1 *local_2c;
  int local_28;
  int *local_24;
  undefined2 *local_20;
  uint *local_1c;
  undefined2 *local_18;
  int local_14;
  undefined1 *local_10;
  uint *local_c;
  uint *local_8;
  
  iVar10 = (int)param_1;
  iVar15 = *(int *)((int)param_1 + 0x920);
  iVar11 = iVar15 + *(int *)((int)param_1 + 0x918);
  aiStack_b4[8] = 0x79b97c;
  local_10 = (undefined1 *)(aiStack_b4 + (9 - iVar11));
  aiStack_b4[8 - iVar11] = 0x79b98c;
  iVar11 = iVar11 * -4 + -0x90;
  iVar15 = -(iVar15 * 2 + 3U & 0xfffffffc);
  local_2c = (undefined1 *)((int)aiStack_b4 + iVar15 + iVar11 + 0xb4);
  local_64 = *(int *)((int)param_1 + 0x1090) >> 6;
  local_60 = *(int *)((int)param_1 + 0x1094) >> 6;
  if (*(int *)((int)param_1 + 0x948) != 0) {
    puVar23 = (undefined4 *)((int)param_1 + 0x1056);
    for (iVar19 = 8; iVar19 != 0; iVar19 = iVar19 + -1) {
      *puVar23 = 0;
      puVar23 = puVar23 + 1;
    }
  }
  iVar19 = *(int *)((int)param_1 + 0x91c);
  iVar12 = *(int *)((int)param_1 + 0x914);
  local_30 = iVar19;
  *(undefined4 *)((int)aiStack_b4 + iVar15 + iVar11 + 0xb0) = 0x79b9e0;
  iVar9 = iVar19 * -4;
  local_24 = &local_64;
  local_3c = (undefined1 *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xb4);
  local_20 = (undefined2 *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xb4);
  local_8 = (uint *)((int)param_1 + 4 + (iVar12 + -2) * iVar19 * 4);
  local_28 = 2;
  do {
    if (0 < iVar19) {
      local_18 = local_20;
      local_1c = (uint *)(int)(short)*local_24;
      local_c = local_8;
      iVar12 = (*local_24 >> 0xf) + 1 >> 1;
      local_14 = iVar19;
      do {
        local_38 = (uint)local_1c;
        uVar13 = *local_c;
        local_34 = (int *)(uVar13 & 0xffff);
        if ((int)(((int)local_1c * (int)local_34 >> 0x10) + (int)local_1c * ((int)uVar13 >> 0x10) +
                  iVar12 * uVar13 & 0xffffff00) < 0x7fff01) {
          uVar13 = ((int)local_1c * (int)local_34 >> 0x10) + (int)local_1c * ((int)uVar13 >> 0x10) +
                   iVar12 * uVar13;
          if ((int)(uVar13 & 0xffffff00) < -0x800000) {
            uVar18 = 0x8000;
          }
          else {
            uVar18 = (undefined2)(uVar13 >> 8);
          }
        }
        else {
          uVar18 = 0x7fff;
        }
        *local_18 = uVar18;
        local_14 = local_14 + -1;
        local_c = local_c + 1;
        local_18 = local_18 + 1;
      } while (local_14 != 0);
      iVar19 = local_30;
    }
    puVar5 = local_3c;
    local_24 = local_24 + 1;
    local_28 = local_28 + -1;
    local_20 = local_20 + iVar19;
    local_8 = local_8 + iVar19;
  } while (local_28 != 0);
  *(int *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xb0) = iVar19;
  *(undefined1 **)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xac) = puVar5;
  *(byte **)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xa8) = local_44;
  *(int **)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xa4) = &local_48;
  *(undefined4 *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xa0) = 0x79bafe;
  FUN_0079f490();
  *(int *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xa0) = iVar19;
  *(undefined1 **)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0x9c) = puVar5 + iVar19 * 2;
  *(byte **)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0x98) = local_4c;
  *(int **)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0x94) = &local_40;
  *(undefined4 *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0x90) = 0x79bb10;
  FUN_0079f490();
  if (local_48 >> (local_4c[0] & 0x1f) < local_40 >> (local_44[0] & 0x1f)) {
    iVar19 = (*(int *)((int)param_1 + 0x109c) + -1) * *(int *)((int)param_1 + 0x10a0);
  }
  else {
    iVar19 = *(int *)((int)param_1 + 0x10a0) * *(int *)((int)param_1 + 0x109c);
  }
  uVar13 = iVar19 - 0x80U & ((int)(iVar19 - 0x80U) < 0) - 1;
  local_30 = (int)param_1 + 4 + uVar13 * 4;
  local_8 = (uint *)CONCAT22((short)(uVar13 >> 0x10),*(undefined2 *)((int)param_1 + 0x1080));
  iVar19 = *(int *)((int)param_1 + 0x1040);
  iVar12 = 1;
  if (iVar19 < 2) {
    iVar12 = iVar19;
  }
  local_5c = (int)*(short *)(&DAT_00837870 + iVar12 * 2);
  if (*(int *)((int)param_1 + 0x1044) == 2) {
    if (1 < iVar19) {
      iVar19 = 1;
    }
    sVar6 = *(short *)(&DAT_00837874 + iVar19 * 2);
  }
  else {
    if (1 < iVar19) {
      iVar19 = 1;
    }
    sVar6 = *(short *)(&DAT_00837878 + iVar19 * 2);
  }
  local_c = (uint *)(int)sVar6;
  uVar7 = *(undefined4 *)((int)param_1 + 0x924);
  *(undefined4 *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xb0) = 0xfd71;
  *(undefined4 *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xac) = uVar7;
  *(undefined4 **)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xa8) =
       (undefined4 *)((int)param_1 + 0x1056);
  *(undefined4 *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xa4) = 0x79bbd1;
  FUN_0079f430();
  uVar13 = *(uint *)((int)param_1 + 0x924);
  puVar23 = (undefined4 *)((int)param_1 + 0x1056);
  psVar16 = &local_84;
  for (uVar20 = (uVar13 & 0x7fffffff) >> 1; uVar20 != 0; uVar20 = uVar20 - 1) {
    *(undefined4 *)psVar16 = *puVar23;
    puVar23 = puVar23 + 1;
    psVar16 = psVar16 + 2;
  }
  for (uVar20 = uVar13 * 2 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
    *(undefined1 *)psVar16 = *(undefined1 *)puVar23;
    puVar23 = (undefined4 *)((int)puVar23 + 1);
    psVar16 = (short *)((int)psVar16 + 1);
  }
  if (*(int *)((int)param_1 + 0x1040) == 0) {
    local_8 = (uint *)0x4000;
    if (*(int *)((int)param_1 + 0x1044) == 2) {
      local_8._0_2_ = 0x4000;
      psVar16 = (short *)((int)param_1 + 0x104c);
      iVar19 = 5;
      do {
        local_8._0_2_ = (short)local_8 - *psVar16;
        psVar16 = psVar16 + 1;
        iVar19 = iVar19 + -1;
      } while (iVar19 != 0);
      if ((short)local_8 < 0xccd) {
        local_8._0_2_ = 0xccd;
      }
      local_8 = (uint *)((int)*(short *)((int)param_1 + 0x108c) * (int)(short)local_8 >> 0xe);
    }
    else {
      *(uint *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xb0) = uVar13;
      *(int *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xac) = (int)param_1 + 0x1056;
      *(undefined4 *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xa8) = 0x79bc63;
      iVar19 = FUN_0079f0f0();
      if (iVar19 < 0x8000001) {
        if (iVar19 < 0x400000) {
          iVar19 = 0x400000;
        }
      }
      else {
        iVar19 = 0x8000000;
      }
      local_c = (uint *)(((int)((iVar19 << 3 & 0xffffU) * (int)(short)local_c) >> 0x10) +
                         ((iVar19 << 3) >> 0x10) * (int)(short)local_c >> 0xe);
    }
  }
  local_18 = *(undefined2 **)((int)param_1 + 0x107c);
  iVar19 = *(int *)((int)param_1 + 0x920);
  iVar12 = *(int *)((int)param_1 + 0x924);
  local_1c = (uint *)((*(int *)((int)param_1 + 0x1048) >> 7) + 1 >> 1);
  iVar14 = ((iVar19 - iVar12) - (int)local_1c) + -2;
  local_14 = iVar19;
  *(int **)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xb0) = param_4;
  *(int *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xac) = iVar12;
  *(int *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xa8) = iVar19 - iVar14;
  *(short **)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xa4) = &local_84;
  puVar5 = local_2c + iVar14 * 2;
  local_3c = (undefined1 *)iVar14;
  *(int *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xa0) = (int)param_1 + 0x544 + iVar14 * 2;
  *(undefined1 **)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0x9c) = puVar5;
  *(undefined4 *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0x98) = 0x79bcf6;
  FUN_0079efc0();
  iVar19 = *(int *)((int)param_1 + 0x1094);
  iVar12 = iVar19;
  if (iVar19 < 1) {
    iVar12 = -iVar19;
  }
  if (iVar12 == 0) {
    iVar15 = 0x20;
  }
  else {
    *(int *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xb0) = iVar12;
    *(undefined4 *)((int)aiStack_b4 + iVar9 + iVar15 + iVar11 + 0xac) = 0x79bd11;
    iVar15 = FUN_007a22e0();
    iVar15 = 0x20 - iVar15;
  }
  uVar13 = iVar19 << ((byte)(iVar15 + -1) & 0x1f);
  iVar12 = (int)uVar13 >> 0x10;
  lVar8 = 0x1fffffff / (longlong)iVar12;
  iVar11 = (int)lVar8;
  iVar19 = (int)(short)lVar8;
  uVar13 = (((int)((uVar13 & 0xffff) * iVar19) >> 0x10) + iVar19 * iVar12) * -8;
  iVar12 = 0xf - (iVar15 + -1);
  iVar15 = ((iVar11 >> 0xf) + 1 >> 1) * uVar13 + ((int)((uVar13 & 0xffff) * iVar19) >> 0x10) +
           ((int)uVar13 >> 0x10) * iVar19 + iVar11 * 0x10000;
  if (iVar12 < 1) {
    bVar17 = -(byte)iVar12;
    iVar11 = -0x80000000 >> (bVar17 & 0x1f);
    iVar19 = 0x7fffffff >> (bVar17 & 0x1f);
    if (iVar19 < iVar11) {
      if (iVar11 < iVar15) {
LAB_0079bdb2:
        iVar15 = iVar11;
      }
      else if (iVar15 < iVar19) {
        iVar15 = iVar19;
      }
    }
    else if (iVar19 < iVar15) {
      iVar15 = iVar19;
    }
    else if (iVar15 < iVar11) goto LAB_0079bdb2;
    uVar13 = iVar15 << (bVar17 & 0x1f);
  }
  else {
    if (0x1f < iVar12) {
      uVar13 = 0;
      goto LAB_0079bdc3;
    }
    uVar13 = iVar15 >> ((byte)iVar12 & 0x1f);
  }
  if (0x3ffffffe < (int)uVar13) {
    uVar13 = 0x3fffffff;
  }
LAB_0079bdc3:
  iVar15 = (int)local_3c + *(int *)((int)param_1 + 0x924);
  if (iVar15 < *(int *)((int)param_1 + 0x920)) {
    local_38 = uVar13 & 0xffff;
    param_4 = (int *)(local_10 + iVar15 * 4);
    local_3c = (undefined1 *)((int)uVar13 >> 0x10);
    psVar16 = (short *)(local_2c + iVar15 * 2);
    do {
      sVar6 = *psVar16;
      psVar16 = psVar16 + 1;
      iVar15 = iVar15 + 1;
      *param_4 = ((int)(local_38 * (int)sVar6) >> 0x10) + (int)local_3c * (int)sVar6;
      param_4 = param_4 + 1;
    } while (iVar15 < *(int *)((int)param_1 + 0x920));
  }
  local_38 = 0;
  if (0 < *(int *)((int)param_1 + 0x914)) {
    do {
      param_4 = (int *)0x0;
      puVar21 = (uint *)(local_10 + (local_14 - (int)local_1c) * 4 + 8);
      if (0 < *(int *)((int)param_1 + 0x91c)) {
        local_34 = (int *)(local_10 + local_14 * 4);
        local_1c = puVar21;
        do {
          puVar1 = puVar21 + -4;
          puVar2 = puVar21 + -3;
          puVar3 = puVar21 + -1;
          puVar4 = puVar21 + -2;
          uVar13 = *puVar21;
          puVar21 = local_1c + 1;
          local_18 = (undefined2 *)((int)local_18 * 0xbb38435 + 0x3619636b);
          uVar20 = *(uint *)(local_30 + ((int)local_18 >> 0x19 & 0x7fU) * 4);
          iVar15 = local_14 + 1;
          local_1c = puVar21;
          *local_34 = (((int)uVar20 >> 0x10) * (int)(short)local_8 +
                      ((int)((uVar13 & 0xffff) * (int)*(short *)((int)param_1 + 0x104c)) >> 0x10) +
                      ((int)((*puVar3 & 0xffff) * (int)*(short *)((int)param_1 + 0x104e)) >> 0x10) +
                      ((int)((*puVar4 & 0xffff) * (int)*(short *)((int)param_1 + 0x1050)) >> 0x10) +
                      ((int)((*puVar2 & 0xffff) * (int)*(short *)((int)param_1 + 0x1052)) >> 0x10) +
                      ((int)((*puVar1 & 0xffff) * (int)*(short *)((int)param_1 + 0x1054)) >> 0x10) +
                      ((int)uVar13 >> 0x10) * (int)*(short *)((int)param_1 + 0x104c) +
                      ((int)*puVar3 >> 0x10) * (int)*(short *)((int)param_1 + 0x104e) +
                      ((int)*puVar4 >> 0x10) * (int)*(short *)((int)param_1 + 0x1050) +
                      ((int)*puVar2 >> 0x10) * (int)*(short *)((int)param_1 + 0x1052) + 2 +
                      ((int)*puVar1 >> 0x10) * (int)*(short *)((int)param_1 + 0x1054) +
                      ((int)((uVar20 & 0xffff) * (int)(short)local_8) >> 0x10)) * 4;
          local_34 = local_34 + 1;
          param_4 = (int *)((int)param_4 + 1);
          local_14 = iVar15;
        } while ((int)param_4 < *(int *)((int)param_1 + 0x91c));
      }
      psVar16 = (short *)((int)param_1 + 0x104c);
      iVar15 = 5;
      do {
        *psVar16 = (short)((int)*psVar16 * (int)(short)local_5c >> 0xf);
        psVar16 = psVar16 + 1;
        iVar15 = iVar15 + -1;
      } while (iVar15 != 0);
      uVar13 = *(uint *)((int)param_1 + 0x1048);
      local_8 = (uint *)((int)(short)local_c * (int)(short)local_8 >> 0xf);
      iVar11 = uVar13 + ((int)((uVar13 & 0xffff) * 0x28f) >> 0x10) + ((int)uVar13 >> 0x10) * 0x28f;
      *(int *)((int)param_1 + 0x1048) = iVar11;
      iVar15 = *(short *)((int)param_1 + 0x90c) * 0x1200;
      if (iVar11 < iVar15) {
        iVar15 = iVar11;
      }
      *(int *)((int)param_1 + 0x1048) = iVar15;
      local_1c = (uint *)((iVar15 >> 7) + 1 >> 1);
      local_38 = local_38 + 1;
    } while ((int)local_38 < *(int *)((int)param_1 + 0x914));
  }
  param_4 = (int *)0x0;
  puVar23 = (undefined4 *)(local_10 + *(int *)((int)param_1 + 0x920) * 4 + -0x40);
  puVar22 = (undefined4 *)((int)param_1 + 0x504);
  puVar24 = puVar23;
  for (iVar15 = 0x10; iVar15 != 0; iVar15 = iVar15 + -1) {
    *puVar24 = *puVar22;
    puVar22 = puVar22 + 1;
    puVar24 = puVar24 + 1;
  }
  if (0 < *(int *)((int)param_1 + 0x918)) {
    puVar21 = puVar23 + 7;
    local_24 = (int *)param_3;
    do {
      iVar11 = *(int *)(iVar10 + 0x924);
      iVar15 = ((int)((puVar21[8] & 0xffff) * (int)local_84) >> 0x10) +
               ((int)((puVar21[7] & 0xffff) * (int)local_82) >> 0x10) +
               ((int)((puVar21[6] & 0xffff) * (int)local_80) >> 0x10) +
               ((int)((puVar21[5] & 0xffff) * (int)local_7e) >> 0x10) +
               ((int)((puVar21[4] & 0xffff) * (int)local_7c) >> 0x10) +
               ((int)((puVar21[3] & 0xffff) * (int)local_7a) >> 0x10) +
               ((int)((puVar21[2] & 0xffff) * (int)local_78) >> 0x10) +
               ((int)((puVar21[1] & 0xffff) * (int)local_76) >> 0x10) +
               ((int)((puVar21[-1] & 0xffff) * (int)local_72) >> 0x10) +
               ((int)((*puVar21 & 0xffff) * (int)local_74) >> 0x10) +
               ((int)puVar21[8] >> 0x10) * (int)local_84 + ((int)puVar21[7] >> 0x10) * (int)local_82
               + ((int)puVar21[6] >> 0x10) * (int)local_80 +
               ((int)puVar21[5] >> 0x10) * (int)local_7e + ((int)puVar21[4] >> 0x10) * (int)local_7c
               + ((int)puVar21[3] >> 0x10) * (int)local_7a +
               ((int)puVar21[2] >> 0x10) * (int)local_78 + ((int)puVar21[1] >> 0x10) * (int)local_76
               + ((int)puVar21[-1] >> 0x10) * (int)local_72 +
               ((int)*puVar21 >> 0x10) * (int)local_74 + (iVar11 >> 1);
      if (10 < iVar11) {
        param_3 = local_70;
        local_38 = iVar11 + -10;
        param_1 = puVar21 + -2;
        do {
          sVar6 = *param_3;
          param_3 = param_3 + 1;
          iVar15 = ((int)*param_1 >> 0x10) * (int)sVar6 + iVar15 +
                   ((int)((*param_1 & 0xffff) * (int)sVar6) >> 0x10);
          param_1 = param_1 + -1;
          local_38 = local_38 + -1;
        } while (local_38 != 0);
      }
      uVar13 = iVar15 * 0x10 + puVar21[9];
      puVar21[9] = uVar13;
      uVar13 = ((int)(((local_60 >> 0xf) + 1 >> 1) * uVar13 +
                      ((int)((uVar13 & 0xffff) * (int)(short)local_60) >> 0x10) +
                     ((int)uVar13 >> 0x10) * (int)(short)local_60) >> 7) + 1;
      uVar20 = uVar13 & 0xfffffffe;
      if ((int)uVar20 < 0xffff) {
        if (((int)uVar20 < -0x10000) || ((int)(uVar13 & 0xfffffffe) < 0xffff)) {
          if (0xfffe < (int)uVar20) goto LAB_0079c30d;
          if (((int)uVar20 < -0x10000) || (-0x10001 < (int)(uVar13 & 0xfffffffe))) {
            if (0xfffe < (int)uVar20) goto LAB_0079c30d;
            if ((int)uVar20 < -0x10000) {
              uVar18 = 0x8000;
            }
            else {
              uVar18 = (undefined2)((int)uVar13 >> 1);
            }
          }
          else {
            uVar18 = 0x8000;
          }
        }
        else {
          uVar18 = 0x7fff;
        }
      }
      else {
LAB_0079c30d:
        uVar18 = 0x7fff;
      }
      param_4 = (int *)((int)param_4 + 1);
      puVar21 = puVar21 + 1;
      *(undefined2 *)local_24 = uVar18;
      local_24 = (int *)((int)local_24 + 2);
    } while ((int)param_4 < *(int *)(iVar10 + 0x918));
  }
  puVar23 = puVar23 + *(int *)(iVar10 + 0x918);
  puVar22 = (undefined4 *)(iVar10 + 0x504);
  for (iVar15 = 0x10; iVar15 != 0; iVar15 = iVar15 + -1) {
    *puVar22 = *puVar23;
    puVar23 = puVar23 + 1;
    puVar22 = puVar22 + 1;
  }
  *(short *)(iVar10 + 0x1080) = (short)local_8;
  *(undefined2 **)(iVar10 + 0x107c) = local_18;
  *param_2 = (int)local_1c;
  param_2[1] = (int)local_1c;
  param_2[2] = (int)local_1c;
  param_2[3] = (int)local_1c;
  return;
}

