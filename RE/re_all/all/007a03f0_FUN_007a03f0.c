
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_007a03f0(int *param_1,float *param_2,float *param_3,int param_4,int param_5,int *param_6,
                int *param_7)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  float *pfVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  float *pfVar13;
  float *pfVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int *piVar19;
  undefined1 *puVar20;
  int *piVar21;
  int aiStack_108 [2];
  int *piStack_100;
  float *pfStack_fc;
  int *apiStack_f8 [2];
  int aiStack_f0 [2];
  int local_dc [12];
  int local_ac [3];
  float *local_a0;
  undefined4 local_9c;
  undefined1 *local_98;
  int local_94 [7];
  int local_78;
  int local_74;
  int local_70;
  float *local_6c;
  int local_68;
  float local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  undefined1 *local_50;
  short *local_4c;
  int local_48;
  int local_44;
  int local_40;
  float *local_3c;
  int local_38;
  int *local_34;
  undefined1 *local_30;
  int *local_2c;
  undefined1 *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  float *local_10;
  int local_c;
  int local_8;
  
  iVar17 = *param_1;
  local_94[5] = 0;
  local_94[3] = 0;
  local_5c = *(int *)(iVar17 + 4);
  local_20 = *(int *)(iVar17 + 0x20);
  local_94[4] = 0;
  local_c = param_1[5];
  local_14 = param_1[3];
  uVar3 = *(uint *)(iVar17 + 8);
  local_44 = param_1[2];
  local_18 = param_1[6];
  param_5 = param_1[4] * param_5;
  local_10 = (float *)(param_1 + (local_5c + 0x818) * param_1[2] + 0x15);
  local_ac[2] = iVar17;
  local_3c = local_10 + uVar3 * 2;
  local_6c = local_3c + uVar3 * 2;
  iVar8 = *(int *)(iVar17 + 0x24);
  local_a0 = local_3c + uVar3 * 2 + uVar3 * 2;
  local_8 = 0;
  if (-1 < iVar8) {
    do {
      if (*(int *)(iVar17 + 0x2c) << ((byte)local_8 & 0x1f) == param_5) break;
      local_8 = local_8 + 1;
    } while (local_8 <= iVar8);
  }
  if (iVar8 < local_8) {
    return -1;
  }
  local_54 = 1 << ((byte)local_8 & 0x1f);
  if ((int)param_3 < 0) {
    return -1;
  }
  if (0x4fb < (int)param_3) {
    return -1;
  }
  if (param_4 == 0) {
    return -1;
  }
  iVar18 = local_54 * *(int *)(iVar17 + 0x2c);
  local_24 = iVar18;
  iVar8 = 0;
  local_68 = local_5c * 4 + 0x2000;
  piVar19 = param_1 + 0x15;
  do {
    local_ac[iVar8] = (int)piVar19;
    local_94[iVar8] = (int)(piVar19 + (0x800 - iVar18));
    iVar4 = local_24;
    piVar19 = (int *)((int)piVar19 + local_68);
    iVar8 = iVar8 + 1;
  } while (iVar8 < local_44);
  local_68 = local_18;
  if (*(int *)(iVar17 + 0xc) < local_18) {
    local_68 = *(int *)(iVar17 + 0xc);
  }
  if ((param_2 == (float *)0x0) || ((int)param_3 < 2)) {
    aiStack_f0[1] = local_8;
    aiStack_f0[0] = local_24;
    apiStack_f8[1] = param_1;
    apiStack_f8[0] = (int *)0x7a0f3a;
    FUN_007a1580();
    aiStack_108[1] = param_1[4];
    pfStack_fc = (float *)(param_1 + 0x13);
    apiStack_f8[0] = param_7;
    piStack_100 = (int *)(iVar17 + 0x10);
    aiStack_108[0] = local_44;
    FUN_007a0f90(local_94,param_4,iVar4);
    return param_5 / param_1[4];
  }
  if (param_6 == (int *)0x0) {
    aiStack_f0[1] = (int)param_3;
    apiStack_f8[1] = local_dc;
    aiStack_f0[0] = (int)param_2;
    apiStack_f8[0] = (int *)0x7a053e;
    FUN_007a1f70();
    param_6 = local_dc;
  }
  if ((local_14 == 1) && (0 < (int)uVar3)) {
    pfVar13 = local_10 + uVar3;
    pfVar14 = local_10;
    param_2 = (float *)uVar3;
    do {
      if (*pfVar14 <= *pfVar13) {
        fVar1 = *pfVar13;
      }
      else {
        fVar1 = *pfVar14;
      }
      pfVar13 = pfVar13 + 1;
      *pfVar14 = fVar1;
      pfVar14 = pfVar14 + 1;
      param_2 = (float *)((int)param_2 - 1);
    } while (param_2 != (float *)0x0);
  }
  aiStack_f0[1] = param_6[7];
  local_94[6] = (int)param_3 << 3;
  aiStack_f0[0] = 0x7a059b;
  local_1c = local_94[6];
  iVar8 = FUN_007a22e0();
  param_2 = (float *)(param_6[5] - iVar8);
  if ((int)param_2 < local_1c) {
    if (param_2 == (float *)0x1) {
      aiStack_f0[1] = 0xf;
      apiStack_f8[1] = (int *)0x7a05c8;
      aiStack_f0[0] = (int)param_6;
      local_48 = FUN_007a2130();
      if (local_48 != 0) goto LAB_007a05d2;
    }
    else {
      local_48 = 0;
    }
  }
  else {
    local_48 = 1;
LAB_007a05d2:
    iVar8 = local_94[6];
    aiStack_f0[1] = param_6[7];
    local_60 = param_6[5];
    param_2 = (float *)local_94[6];
    aiStack_f0[0] = 0x7a05e7;
    iVar18 = FUN_007a22e0();
    param_6[5] = iVar8 + iVar18;
  }
  local_64 = 0.0;
  local_74 = 0;
  local_78 = 0;
  if ((local_c == 0) && ((int)param_2 + 0x10 <= local_1c)) {
    aiStack_f0[1] = 1;
    apiStack_f8[1] = (int *)0x7a062e;
    aiStack_f0[0] = (int)param_6;
    iVar8 = FUN_007a2130();
    if (iVar8 != 0) {
      aiStack_f0[1] = 6;
      apiStack_f8[1] = (int *)0x7a063d;
      aiStack_f0[0] = (int)param_6;
      iVar8 = FUN_007a21c0();
      apiStack_f8[1] = (int *)(iVar8 + 4);
      pfStack_fc = (float *)0x7a064a;
      apiStack_f8[0] = param_6;
      iVar18 = FUN_007a2250();
      pfStack_fc = (float *)0x3;
      local_74 = iVar18 + -1 + (0x10 << ((byte)iVar8 & 0x1f));
      aiStack_108[1] = 0x7a0663;
      piStack_100 = param_6;
      iVar8 = FUN_007a2250();
      aiStack_108[1] = param_6[7];
      aiStack_108[0] = 0x7a066f;
      iVar18 = FUN_007a22e0();
      if ((param_6[5] - iVar18) + 2 <= local_1c) {
        aiStack_f0[1] = 2;
        aiStack_f0[0] = (int)&DAT_00838a8c;
        apiStack_f8[0] = (int *)0x7a068e;
        apiStack_f8[1] = param_6;
        local_78 = FUN_007a2170();
      }
      local_64 = (float)(iVar8 + 1) * _DAT_00838a90;
    }
    aiStack_f0[1] = param_6[7];
    aiStack_f0[0] = 0x7a06b0;
    iVar8 = FUN_007a22e0();
    param_2 = (float *)(param_6[5] - iVar8);
  }
  if ((local_8 < 1) || (local_1c < (int)param_2 + 3)) {
    local_38 = 0;
  }
  else {
    aiStack_f0[1] = 3;
    apiStack_f8[1] = (int *)0x7a06d7;
    aiStack_f0[0] = (int)param_6;
    local_38 = FUN_007a2130();
    apiStack_f8[1] = (int *)param_6[7];
    apiStack_f8[0] = (int *)0x7a06e3;
    iVar8 = FUN_007a22e0();
    param_2 = (float *)(param_6[5] - iVar8);
    if (local_38 != 0) {
      local_60 = local_54;
      goto LAB_007a070a;
    }
  }
  local_60 = 0;
LAB_007a070a:
  if (local_1c < (int)param_2 + 3) {
    apiStack_f8[0] = (int *)0x0;
  }
  else {
    aiStack_f0[1] = 3;
    apiStack_f8[1] = (int *)0x7a071f;
    aiStack_f0[0] = (int)param_6;
    apiStack_f8[0] = (int *)FUN_007a2130();
  }
  aiStack_f0[1] = local_8;
  aiStack_f0[0] = local_14;
  pfStack_fc = local_10;
  piStack_100 = (int *)local_18;
  aiStack_108[1] = local_c;
  aiStack_108[0] = iVar17;
  apiStack_f8[1] = param_6;
  FUN_007a4be0();
  iVar18 = local_8;
  iVar8 = local_38;
  aiStack_f0[1] = 0x7a0764;
  aiStack_f0[1 - uVar3] = (int)param_6;
  aiStack_f0[-uVar3] = iVar18;
  iVar4 = local_c;
  local_98 = (undefined1 *)(aiStack_f0 + (2 - uVar3));
  aiStack_f0[-1 - uVar3] = (int)(aiStack_f0 + (2 - uVar3));
  iVar18 = local_18;
  apiStack_f8[-uVar3] = (int *)iVar8;
  aiStack_108[3 - uVar3] = iVar18;
  aiStack_108[2 - uVar3] = iVar4;
  aiStack_108[1 - uVar3] = 0x7a0783;
  FUN_007a1430();
  local_94[2] = 2;
  aiStack_108[1 - uVar3] = param_6[7];
  aiStack_108[-uVar3] = 0x7a0796;
  iVar8 = FUN_007a22e0();
  piVar21 = aiStack_f0 + (2 - uVar3);
  if ((param_6[5] - iVar8) + 4 <= local_1c) {
    aiStack_f0[1 - uVar3] = 5;
    aiStack_f0[-uVar3] = (int)&DAT_00838a88;
    aiStack_f0[-1 - uVar3] = (int)param_6;
    apiStack_f8[-uVar3] = (int *)0x7a07b5;
    local_94[2] = FUN_007a2170();
    piVar21 = aiStack_f0 + (2 - uVar3);
  }
  *(undefined4 *)((int)piVar21 + -4) = 0x7a07d2;
  iVar18 = local_8;
  iVar8 = uVar3 * -4;
  *(int *)((int)piVar21 + iVar8 + -4) = local_14;
  *(int *)((int)piVar21 + iVar8 + -8) = iVar18;
  *(undefined1 **)((int)piVar21 + iVar8 + -0xc) = (undefined1 *)((int)piVar21 + iVar8);
  *(int *)((int)piVar21 + iVar8 + -0x10) = iVar17;
  local_50 = (undefined1 *)((int)piVar21 + iVar8);
  *(undefined4 *)((int)piVar21 + iVar8 + -0x14) = 0x7a07e6;
  FUN_007a2a70();
  *(undefined4 *)((int)piVar21 + iVar8 + -4) = 0x7a07f9;
  local_2c = (int *)((int)piVar21 + uVar3 * -8);
  *(int **)((int)piVar21 + uVar3 * -8 + -4) = param_6;
  local_58 = 6;
  local_1c = local_1c << 3;
  *(undefined4 *)((int)piVar21 + uVar3 * -8 + -8) = 0x7a0812;
  param_2 = (float *)FUN_007a2340();
  if (local_c < local_18) {
    local_34 = (int *)((int)local_2c + local_c * 4);
    local_4c = (short *)(local_20 + local_c * 2);
    local_70 = (int)local_50 - (int)local_2c;
    local_20 = local_18 - local_c;
    do {
      iVar18 = ((int)local_4c[1] - (int)*local_4c) * local_14 << ((byte)local_8 & 0x1f);
      iVar8 = 0x30;
      if (0x2f < iVar18) {
        iVar8 = iVar18;
      }
      if (iVar18 * 8 < iVar8) {
        local_30 = (undefined1 *)(iVar18 * 8);
      }
      else {
        local_30 = (undefined1 *)0x30;
        if (0x2f < iVar18) {
          local_30 = (undefined1 *)iVar18;
        }
      }
      local_40 = local_58;
      local_28 = (undefined1 *)0x0;
      puVar20 = (undefined1 *)0;
      if ((int)param_2 + local_58 * 8 < local_1c) {
        do {
          puVar20 = local_28;
          if (*(int *)(local_70 + (int)local_34) <= (int)local_28) break;
          *(int *)((int)piVar21 + uVar3 * -8 + -4) = local_40;
          *(int **)((int)piVar21 + uVar3 * -8 + -8) = param_6;
          *(undefined4 *)((int)piVar21 + uVar3 * -8 + -0xc) = 0x7a08b5;
          iVar8 = FUN_007a2130();
          *(int **)((int)piVar21 + uVar3 * -8 + -0xc) = param_6;
          local_40 = iVar8;
          *(undefined4 *)((int)piVar21 + uVar3 * -8 + -0x10) = 0x7a08be;
          param_2 = (float *)FUN_007a2340();
          puVar20 = local_28;
          if (local_40 == 0) break;
          puVar20 = (undefined1 *)((int)local_28 + (int)local_30);
          local_1c = local_1c - (int)local_30;
          local_40 = 1;
          local_28 = puVar20;
        } while ((int)param_2 + 8 < local_1c);
      }
      *local_34 = (int)puVar20;
      iVar8 = local_58;
      if (0 < (int)puVar20) {
        local_58 = 2;
        if (1 < iVar8 + -1) {
          local_58 = iVar8 + -1;
        }
      }
      local_4c = local_4c + 1;
      local_34 = local_34 + 1;
      local_20 = local_20 + -1;
    } while (local_20 != 0);
  }
  *(undefined4 *)((int)piVar21 + uVar3 * -8 + -4) = 0x7a093c;
  local_28 = (undefined1 *)((int)piVar21 + uVar3 * -0xc);
  iVar8 = uVar3 * -0xc;
  if (local_1c < (int)param_2 + 0x30) {
    local_20 = 5;
    local_28 = (undefined1 *)((int)piVar21 + uVar3 * -0xc);
  }
  else {
    *(undefined4 *)((int)piVar21 + uVar3 * -0xc + -4) = 7;
    *(undefined **)((int)piVar21 + uVar3 * -0xc + -8) = &DAT_00838a7c;
    *(int **)((int)piVar21 + uVar3 * -0xc + -0xc) = param_6;
    *(undefined4 *)((int)piVar21 + uVar3 * -0xc + -0x10) = 0x7a0959;
    local_20 = FUN_007a2170();
  }
  *(int **)((int)piVar21 + uVar3 * -0xc + -4) = param_6;
  local_4c = (short *)((int)param_3 << 6);
  *(undefined4 *)((int)piVar21 + uVar3 * -0xc + -8) = 0x7a0977;
  iVar18 = FUN_007a2340();
  iVar18 = ((int)local_4c - iVar18) + -1;
  if (((local_38 == 0) || (local_8 < 2)) || (param_2 = (float *)0x8, iVar18 < local_8 * 8 + 0x10)) {
    param_2 = (float *)0x0;
  }
  *(undefined4 *)((int)piVar21 + uVar3 * -0xc + -4) = 0x7a09c4;
  local_30 = (undefined1 *)((int)piVar21 + uVar3 * -0x10);
  *(undefined4 *)((int)piVar21 + uVar3 * -0x10 + -4) = 0x7a09db;
  iVar12 = local_8;
  iVar10 = local_14;
  iVar4 = uVar3 * -8;
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -4) = 0;
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -8) = 0;
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0xc) = 0;
  *(int **)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x10) = param_6;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x14) = iVar12;
  puVar20 = local_30;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x18) = iVar10;
  local_34 = (int *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8);
  *(undefined1 **)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x1c) =
       (undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8;
  *(undefined1 **)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x20) = local_28;
  *(undefined1 **)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x24) = puVar20;
  *(undefined4 **)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x28) = &local_9c;
  iVar10 = local_20;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x2c) = iVar18 - (int)param_2;
  *(int **)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x30) = local_94 + 3;
  puVar20 = local_50;
  *(int **)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x34) = local_94 + 5;
  piVar19 = local_2c;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x38) = iVar10;
  iVar18 = local_18;
  *(undefined1 **)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x3c) = puVar20;
  iVar10 = local_c;
  *(int **)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x40) = piVar19;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x44) = iVar18;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x48) = iVar10;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x4c) = iVar17;
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x50) = 0x7a0a2d;
  local_40 = FUN_007a4f10();
  pfVar13 = local_10;
  puVar20 = local_28;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x50) = local_14;
  iVar18 = local_18;
  *(int **)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x54) = param_6;
  *(undefined1 **)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x58) = puVar20;
  iVar10 = local_c;
  *(float **)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x5c) = pfVar13;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x60) = iVar18;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -100) = iVar10;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x68) = iVar17;
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x6c) = 0x7a0a4b;
  FUN_007a4d90();
  param_3 = (float *)0x0;
  local_70 = (local_5c / 2 + local_24 * 0x3fffffff) * 4 + 0x2000;
  local_2c = local_ac;
  do {
    piVar19 = local_2c;
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -4) = local_70;
    iVar18 = *piVar19;
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -8) = iVar18 + local_24 * 4;
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0xc) = iVar18;
    *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0x10) = 0x7a0a94;
    _memmove(*(void **)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -0xc),
             *(void **)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -8),
             *(size_t *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -4));
    param_3 = (float *)((int)param_3 + 1);
    local_2c = local_2c + 1;
  } while ((int)param_3 < local_44);
  local_20 = uVar3 * local_14;
  uVar9 = local_20 + 3;
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + uVar3 * -8 + -4) = 0x7a0ac2;
  iVar18 = -(uVar9 & 0xfffffffc);
  local_50 = (undefined1 *)((int)piVar21 + iVar8) + iVar18 + uVar3 * -8;
  iVar12 = iVar18 + iVar4;
  iVar10 = local_24 * local_14;
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar18 + uVar3 * -8 + -4) = 0x7a0ad9;
  iVar10 = iVar10 * -4;
  if (local_14 == 2) {
    puVar20 = (undefined1 *)((int)piVar21 + local_24 * 4 + iVar10 + iVar18 + uVar3 * -0x14);
  }
  else {
    puVar20 = (undefined1 *)0x0;
  }
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -4) = param_1[8];
  iVar16 = local_8;
  *(int **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -8) = param_1 + 9;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0xc) = local_40;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x10) = iVar16;
  *(int **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x14) = param_6;
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x18) = local_9c
  ;
  puVar5 = local_98;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x1c) =
       (int)local_4c - (int)param_2;
  iVar16 = local_94[5];
  *(undefined1 **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x20) = puVar5;
  iVar15 = local_94[3];
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x24) = iVar16;
  iVar16 = local_94[2];
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x28) = iVar15;
  iVar15 = local_60;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x2c) = iVar16;
  puVar6 = local_30;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x30) = iVar15;
  puVar5 = local_50;
  *(undefined1 **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x34) = puVar6;
  iVar16 = local_18;
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x38) = 0;
  *(undefined1 **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x3c) = puVar5;
  iVar15 = local_c;
  *(undefined1 **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x40) = puVar20
  ;
  *(undefined1 **)((int)piVar21 + iVar10 + iVar18 + -0x44 + uVar3 * -0x14) =
       (undefined1 *)((int)piVar21 + iVar10 + iVar12 + iVar8);
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x48) = iVar16;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x4c) = iVar15;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x50) = iVar17;
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x54) = 0;
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x58) = 0x7a0b4d
  ;
  FUN_007a2f60();
  if (param_2 != (float *)0x0) {
    *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -4) = 1;
    *(int **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -8) = param_6;
    *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0xc) =
         0x7a0b5f;
    local_94[4] = FUN_007a2250();
  }
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -4) = param_6[7];
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -8) = 0x7a0b6e;
  FUN_007a22e0();
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -8) = param_6[7];
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0xc) = 0x7a0b77;
  iVar11 = FUN_007a22e0();
  iVar15 = local_94[6];
  iVar16 = param_6[5];
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0xc) = local_14;
  puVar20 = local_28;
  piVar19 = local_34;
  *(int **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x10) = param_6;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x14) =
       iVar15 - (iVar16 - iVar11);
  pfVar13 = local_10;
  *(int **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x18) = piVar19;
  iVar16 = local_18;
  *(undefined1 **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x1c) = puVar20
  ;
  iVar15 = local_c;
  *(float **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x20) = pfVar13;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x24) = iVar16;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x28) = iVar15;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x2c) = iVar17;
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x30) = 0x7a0ba1
  ;
  FUN_007a4e30();
  puVar20 = local_30;
  if (local_94[4] != 0) {
    iVar16 = param_1[9];
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -4) = param_1[8];
    pfVar13 = local_6c;
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -8) = iVar16;
    pfVar14 = local_3c;
    *(undefined1 **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0xc) =
         puVar20;
    pfVar7 = local_10;
    *(float **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x10) = pfVar13;
    iVar15 = local_18;
    *(float **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x14) = pfVar14;
    iVar11 = local_c;
    *(float **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x18) = pfVar7;
    iVar16 = local_24;
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x1c) = iVar15;
    iVar15 = local_14;
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x20) = iVar11;
    iVar11 = local_8;
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x24) = iVar16;
    puVar20 = local_50;
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x28) = iVar15;
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x2c) = iVar11;
    *(undefined1 **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x30) =
         puVar20;
    *(undefined1 **)((int)piVar21 + iVar10 + iVar18 + -0x34 + uVar3 * -0x14) =
         (undefined1 *)((int)piVar21 + iVar10 + iVar12 + iVar8);
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x38) = iVar17;
    *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x3c) =
         0x7a0be5;
    FUN_007a2c40();
  }
  iVar16 = local_48;
  if ((local_48 != 0) && (0 < local_20)) {
    pfVar13 = local_10;
    for (iVar15 = local_20; iVar15 != 0; iVar15 = iVar15 + -1) {
      *pfVar13 = -28.0;
      pfVar13 = pfVar13 + 1;
    }
  }
  iVar15 = param_1[4];
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -4) = param_1[8];
  iVar11 = local_8;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -8) = iVar16;
  iVar16 = local_38;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0xc) = iVar15;
  iVar15 = local_44;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x10) = iVar11;
  iVar11 = local_14;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x14) = iVar16;
  iVar16 = local_68;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x18) = iVar15;
  iVar15 = local_c;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x1c) = iVar11;
  pfVar13 = local_10;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x20) = iVar16;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x24) = iVar15;
  *(float **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x28) = pfVar13;
  *(int **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x2c) = local_94;
  *(undefined1 **)((int)piVar21 + iVar10 + iVar18 + -0x30 + uVar3 * -0x14) =
       (undefined1 *)((int)piVar21 + iVar10 + iVar12 + iVar8);
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x34) = iVar17;
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x38) = 0x7a0c3b
  ;
  FUN_007a10c0();
  param_3 = (float *)0x0;
  piVar19 = local_94;
  do {
    iVar12 = param_1[0xd];
    if (iVar12 < 0x10) {
      iVar12 = 0xf;
    }
    iVar16 = param_1[0xe];
    param_1[0xd] = iVar12;
    if (iVar16 < 0x10) {
      iVar16 = 0xf;
    }
    param_1[0xe] = iVar16;
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -4) = param_1[8];
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -8) = local_5c;
    *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0xc) =
         *(undefined4 *)(iVar17 + 0x3c);
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x10) = param_1[0x11]
    ;
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x14) = param_1[0x12]
    ;
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x18) = param_1[0xf];
    iVar15 = *piVar19;
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x1c) = param_1[0x10]
    ;
    *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x20) =
         *(undefined4 *)(iVar17 + 0x2c);
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x24) = iVar12;
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x28) = iVar16;
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x2c) = iVar15;
    *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x30) = iVar15;
    *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x34) =
         0x7a0c9c;
    FUN_007a2710();
    if (local_8 != 0) {
      iVar16 = *(int *)(iVar17 + 0x2c);
      *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -4) = param_1[8];
      *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -8) = local_5c;
      *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0xc) =
           *(undefined4 *)(iVar17 + 0x3c);
      *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x10) = local_78;
      iVar12 = *piVar19;
      *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x14) =
           param_1[0x11];
      *(float *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x18) = local_64;
      *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x1c) =
           param_1[0xf];
      iVar15 = local_74;
      iVar12 = iVar12 + iVar16 * 4;
      *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x20) =
           local_24 - iVar16;
      iVar16 = param_1[0xd];
      *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x24) = iVar15;
      *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x28) = iVar16;
      *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x2c) = iVar12;
      *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x30) = iVar12;
      *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x34) =
           0x7a0cdf;
      FUN_007a2710();
    }
    param_3 = (float *)((int)param_3 + 1);
    piVar19 = piVar19 + 1;
  } while ((int)param_3 < local_44);
  param_1[0xe] = param_1[0xd];
  param_1[0x12] = param_1[0x11];
  param_1[0x10] = param_1[0xf];
  param_1[0xf] = (int)local_64;
  param_1[0xd] = local_74;
  param_1[0x11] = local_78;
  if (local_8 != 0) {
    param_1[0xe] = local_74;
    param_1[0x10] = (int)local_64;
    param_1[0x12] = local_78;
  }
  if (local_14 == 1) {
    pfVar13 = local_10;
    pfVar14 = local_10 + uVar3;
    for (uVar9 = uVar3 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pfVar14 = *pfVar13;
      pfVar13 = pfVar13 + 1;
      pfVar14 = pfVar14 + 1;
    }
    for (iVar17 = 0; iVar17 != 0; iVar17 = iVar17 + -1) {
      *(undefined1 *)pfVar14 = *(undefined1 *)pfVar13;
      pfVar13 = (float *)((int)pfVar13 + 1);
      pfVar14 = (float *)((int)pfVar14 + 1);
    }
  }
  if (local_38 == 0) {
    pfVar13 = local_3c;
    pfVar14 = local_6c;
    for (iVar17 = (uVar3 & 0x1fffffff) << 1; iVar17 != 0; iVar17 = iVar17 + -1) {
      *pfVar14 = *pfVar13;
      pfVar13 = pfVar13 + 1;
      pfVar14 = pfVar14 + 1;
    }
    for (iVar17 = 0; iVar17 != 0; iVar17 = iVar17 + -1) {
      *(undefined1 *)pfVar14 = *(undefined1 *)pfVar13;
      pfVar13 = (float *)((int)pfVar13 + 1);
      pfVar14 = (float *)((int)pfVar14 + 1);
    }
    pfVar13 = local_10;
    pfVar14 = local_3c;
    for (iVar17 = (uVar3 & 0x1fffffff) << 1; iVar17 != 0; iVar17 = iVar17 + -1) {
      *pfVar14 = *pfVar13;
      pfVar13 = pfVar13 + 1;
      pfVar14 = pfVar14 + 1;
    }
    for (iVar17 = 0; iVar17 != 0; iVar17 = iVar17 + -1) {
      *(undefined1 *)pfVar14 = *(undefined1 *)pfVar13;
      pfVar13 = (float *)((int)pfVar13 + 1);
      pfVar14 = (float *)((int)pfVar14 + 1);
    }
    iVar17 = uVar3 * 2;
    if (0 < iVar17) {
      fVar1 = (float)local_54 * _DAT_007d652c;
      pfVar13 = local_a0;
      do {
        fVar2 = fVar1 + *pfVar13;
        if (*(float *)(((int)local_10 - (int)local_a0) + (int)pfVar13) <= fVar2) {
          fVar2 = *(float *)(((int)local_10 - (int)local_a0) + (int)pfVar13);
        }
        *pfVar13 = fVar2;
        pfVar13 = pfVar13 + 1;
        iVar17 = iVar17 + -1;
      } while (iVar17 != 0);
    }
  }
  else {
    iVar17 = uVar3 * 2;
    if (0 < iVar17) {
      pfVar13 = local_3c;
      do {
        if (*(float *)(((int)local_10 - (int)local_3c) + (int)pfVar13) <= *pfVar13) {
          fVar1 = *(float *)(((int)local_10 - (int)local_3c) + (int)pfVar13);
        }
        else {
          fVar1 = *pfVar13;
        }
        *pfVar13 = fVar1;
        pfVar13 = pfVar13 + 1;
        iVar17 = iVar17 + -1;
      } while (iVar17 != 0);
    }
  }
  param_3 = local_6c;
  local_54 = 2;
  param_2 = local_6c + local_18;
  do {
    if (0 < local_c) {
      pfVar13 = param_3;
      iVar17 = local_c;
      do {
        *(undefined4 *)(((int)local_10 - (int)local_6c) + (int)pfVar13) = 0;
        *pfVar13 = -28.0;
        *(undefined4 *)(((int)local_3c - (int)local_6c) + (int)pfVar13) = 0xc1e00000;
        pfVar13 = pfVar13 + 1;
        iVar17 = iVar17 + -1;
      } while (iVar17 != 0);
    }
    if (local_18 < (int)uVar3) {
      iVar17 = uVar3 - local_18;
      pfVar13 = param_2;
      do {
        *(undefined4 *)((int)pfVar13 + ((int)local_10 - (int)local_6c)) = 0;
        *pfVar13 = -28.0;
        *(undefined4 *)((int)pfVar13 + ((int)local_3c - (int)local_6c)) = 0xc1e00000;
        pfVar13 = pfVar13 + 1;
        iVar17 = iVar17 + -1;
      } while (iVar17 != 0);
    }
    param_3 = param_3 + uVar3;
    param_2 = param_2 + uVar3;
    local_54 = local_54 + -1;
  } while (local_54 != 0);
  *(int **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -4) = param_7;
  iVar17 = param_1[4];
  param_1[9] = param_6[7];
  iVar16 = local_ac[2] + 0x10;
  *(int **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -8) = param_1 + 0x13;
  iVar12 = local_44;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0xc) = iVar16;
  iVar16 = local_24;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x10) = iVar17;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x14) = iVar12;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x18) = iVar16;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x1c) = param_4;
  *(int **)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x20) = local_94;
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x24) = 0x7a0ed9
  ;
  FUN_007a0f90();
  param_1[0xc] = 0;
  *(int *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x24) = param_6[7];
  *(undefined4 *)((undefined1 *)((int)piVar21 + iVar8) + iVar10 + iVar18 + iVar4 + -0x28) = 0x7a0ee9
  ;
  iVar17 = FUN_007a22e0();
  if (local_94[6] < param_6[5] - iVar17) {
    return -3;
  }
  if (param_6[0xb] != 0) {
    param_1[10] = 1;
  }
  return param_5 / param_1[4];
}

