
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00798e20(int *param_1,uint param_2,int param_3,float *param_4,undefined2 *param_5,
                int param_6)

{
  short sVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  float *pfVar8;
  undefined2 *puVar9;
  short *psVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined1 *puVar14;
  uint *puVar15;
  uint uVar16;
  int iVar17;
  float10 fVar18;
  float10 fVar19;
  int *apiStack_a0 [4];
  float *pfStack_90;
  uint auStack_8c [2];
  undefined1 local_78 [4];
  int local_74;
  int local_64;
  uint local_5c;
  short *local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  undefined1 *local_2c;
  undefined1 *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  piVar3 = param_1;
  local_40 = 0;
  local_28 = (undefined1 *)0x0;
  local_24 = 0;
  local_18 = 0;
  local_20 = 0;
  local_1c = 0;
  local_30 = 0;
  local_34 = param_1[1] + (int)param_1;
  local_10 = *param_1 + (int)param_1;
  uVar13 = param_1[3] / 0x32;
  uVar16 = (int)uVar13 >> 1;
  local_14 = (int)uVar13 >> 2;
  local_8 = (int)uVar13 >> 3;
  if ((int)param_5 < local_8) {
    return -2;
  }
  uVar2 = (param_1[3] / 0x19) * 3;
  if ((int)uVar2 <= (int)param_5) {
    param_5 = (undefined2 *)uVar2;
  }
  local_44 = uVar13;
  if (param_3 < 2) {
    param_2 = 0;
    if (param_1[0xf] <= (int)param_5) {
      param_5 = (undefined2 *)param_1[0xf];
    }
LAB_00798ecd:
    local_c = param_1[0xe];
    if (local_c == 0) {
      iVar4 = 0;
      if (0 < param_1[2] * (int)param_5) {
        do {
          *param_4 = 0.0;
          iVar4 = iVar4 + 1;
          param_4 = param_4 + 1;
        } while (iVar4 < param_1[2] * (int)param_5);
      }
      return (uint)param_5;
    }
    if ((int)uVar13 < (int)param_5) {
      param_1 = (int *)param_5;
      while( true ) {
        auStack_8c[0] = (uint)param_1;
        if ((int)uVar13 <= (int)param_1) {
          auStack_8c[0] = uVar13;
        }
        auStack_8c[1] = 0;
        apiStack_a0[3] = (int *)0x0;
        apiStack_a0[2] = (int *)0x0;
        apiStack_a0[1] = piVar3;
        apiStack_a0[0] = (int *)0x798f52;
        pfStack_90 = param_4;
        iVar4 = FUN_00798e20();
        if (iVar4 < 0) break;
        param_1 = (int *)((int)param_1 - iVar4);
        param_4 = param_4 + piVar3[2] * iVar4;
        if ((int)param_1 < 1) {
          return (uint)param_5;
        }
      }
      return iVar4;
    }
    param_1 = (int *)(uint)param_5;
    if ((int)param_5 < (int)uVar13) {
      if ((int)uVar16 < (int)param_5) {
        param_1 = (int *)uVar16;
      }
      else {
        param_1 = (int *)(uint)param_5;
        if (((local_c != 1000) && (param_1 = (int *)(uint)param_5, (int)local_14 < (int)param_5)) &&
           (param_1 = (int *)(uint)param_5, (int)param_5 < (int)uVar16)) {
          param_1 = (int *)local_14;
        }
      }
    }
  }
  else {
    if (param_2 == 0) goto LAB_00798ecd;
    uVar13 = param_1[0xf];
    local_c = param_1[0xd];
    auStack_8c[1] = param_3;
    pfStack_90 = (float *)local_78;
    auStack_8c[0] = param_2;
    apiStack_a0[3] = (int *)0x798f2f;
    FUN_007a1f70();
    param_1 = (int *)uVar13;
  }
  iVar4 = 0;
  local_3c = 0;
  if ((param_2 != 0) && (iVar17 = piVar3[0xe], 0 < iVar17)) {
    if (local_c == 0x3ea) {
      if ((iVar17 != 0x3ea) && (piVar3[0x10] == 0)) goto LAB_00798fd2;
    }
    else if (iVar17 == 0x3ea) {
LAB_00798fd2:
      local_24 = 1;
      if (local_c == 0x3ea) {
        iVar4 = piVar3[2] * local_14;
      }
      else {
        local_3c = piVar3[2] * local_14;
      }
    }
  }
  auStack_8c[1] = 0x799001;
  puVar15 = auStack_8c + (2 - iVar4);
  if ((local_24 != 0) && (puVar15 = auStack_8c + (2 - iVar4), local_c == 0x3ea)) {
    uVar13 = local_14;
    if ((int)param_1 <= (int)local_14) {
      uVar13 = (uint)param_1;
    }
    local_28 = (undefined1 *)(auStack_8c + (2 - iVar4));
    auStack_8c[1 - iVar4] = 0;
    auStack_8c[-iVar4] = uVar13;
    apiStack_a0[4 - iVar4] = (int *)(auStack_8c + (2 - iVar4));
    apiStack_a0[3 - iVar4] = (int *)0x0;
    apiStack_a0[2 - iVar4] = (int *)0x0;
    apiStack_a0[1 - iVar4] = piVar3;
    apiStack_a0[-iVar4] = (int *)0x799030;
    FUN_00798e20();
    puVar15 = auStack_8c + (2 - iVar4);
  }
  if ((int)param_5 < (int)param_1) {
    return -1;
  }
  if (local_c == 0x3ea) {
    iVar4 = 0;
  }
  else {
    if ((int)uVar16 <= (int)param_1) {
      uVar16 = (uint)param_1;
    }
    iVar4 = piVar3[2] * uVar16;
  }
  *(undefined4 *)((int)puVar15 + -4) = 0x79906f;
  iVar17 = local_c;
  iVar4 = -(iVar4 * 2 + 3U & 0xfffffffc);
  local_48 = (short *)((int)puVar15 + iVar4);
  param_5 = (undefined2 *)((int)puVar15 + iVar4);
  psVar10 = (short *)((int)puVar15 + iVar4);
  if (local_c != 0x3ea) {
    puVar9 = (undefined2 *)((int)puVar15 + iVar4);
    psVar10 = (short *)((int)puVar15 + iVar4);
    if (piVar3[0xe] == 0x3ea) {
      *(int *)((int)puVar15 + iVar4 + -4) = local_34;
      *(undefined4 *)((int)puVar15 + iVar4 + -8) = 0x799099;
      FUN_00799c30();
      puVar9 = param_5;
      psVar10 = local_48;
    }
    local_48 = psVar10;
    param_5 = puVar9;
    iVar5 = ((int)param_1 * 1000) / piVar3[3];
    if (iVar5 < 10) {
      iVar5 = 10;
    }
    piVar3[8] = iVar5;
    if (param_2 == 0) {
      local_2c = (undefined1 *)0x1;
    }
    else {
      piVar3[5] = piVar3[0xb];
      if (iVar17 == 1000) {
        if (piVar3[0xc] == 0x44d) {
          piVar3[7] = 8000;
        }
        else {
          if (piVar3[0xc] != 0x44e) goto LAB_00799186;
          piVar3[7] = 12000;
        }
      }
      else {
LAB_00799186:
        piVar3[7] = 16000;
      }
      local_2c = (undefined1 *)(param_6 * 2);
    }
    iVar17 = 0;
    do {
      *(int *)((int)puVar15 + iVar4 + -4) = piVar3[0x15];
      *(uint **)((int)puVar15 + iVar4 + -8) = &local_38;
      *(undefined2 **)((int)puVar15 + iVar4 + -0xc) = param_5;
      puVar14 = local_2c;
      *(undefined1 **)((int)puVar15 + iVar4 + -0x10) = local_78;
      iVar5 = local_34;
      *(uint *)((int)puVar15 + iVar4 + -0x14) = (uint)(iVar17 == 0);
      *(undefined1 **)((int)puVar15 + iVar4 + -0x18) = puVar14;
      *(int **)((int)puVar15 + iVar4 + -0x1c) = piVar3 + 4;
      *(int *)((int)puVar15 + iVar4 + -0x20) = iVar5;
      *(undefined4 *)((int)puVar15 + iVar4 + -0x24) = 0x79911f;
      iVar5 = FUN_00799c70();
      if (iVar5 != 0) {
        if (local_2c == (undefined1 *)0x0) {
          return -3;
        }
        iVar5 = 0;
        local_38 = (uint)param_1;
        if (0 < piVar3[2] * (int)param_1) {
          puVar9 = param_5;
          do {
            *puVar9 = 0;
            iVar5 = iVar5 + 1;
            puVar9 = puVar9 + 1;
          } while (iVar5 < piVar3[2] * (int)param_1);
        }
      }
      iVar17 = iVar17 + local_38;
      param_5 = param_5 + piVar3[2] * local_38;
      psVar10 = local_48;
    } while (iVar17 < (int)param_1);
  }
  local_48 = psVar10;
  param_5 = (undefined2 *)0x0;
  if (param_6 != 0) goto LAB_007992ba;
  if (local_c != 0x3ea) {
    if (param_2 == 0) {
LAB_007992ba:
      if (local_c == 0x3ea) goto LAB_007992cd;
    }
    else {
      *(uint *)((int)puVar15 + iVar4 + -4) = local_5c;
      *(undefined4 *)((int)puVar15 + iVar4 + -8) = 0x7991e0;
      iVar5 = FUN_007a22e0();
      iVar17 = local_c;
      if (param_3 * 8 < (int)((local_64 - iVar5) + 0x11 + (uint)(piVar3[0xd] == 0x3e9) * 0x14))
      goto LAB_007992ba;
      if (local_c != 0x3e9) {
        local_18 = 1;
LAB_00799233:
        *(undefined4 *)((int)puVar15 + iVar4 + -4) = 1;
        *(undefined1 **)((int)puVar15 + iVar4 + -8) = local_78;
        *(undefined4 *)((int)puVar15 + iVar4 + -0xc) = 0x79923e;
        local_1c = FUN_007a2130();
        if (iVar17 == 0x3e9) {
          *(undefined4 *)((int)puVar15 + iVar4 + -4) = 0x100;
          *(undefined1 **)((int)puVar15 + iVar4 + -8) = local_78;
          *(undefined4 *)((int)puVar15 + iVar4 + -0xc) = 0x79925a;
          iVar17 = FUN_007a21c0();
          iVar17 = iVar17 + 2;
        }
        else {
          *(uint *)((int)puVar15 + iVar4 + -4) = local_5c;
          *(undefined4 *)((int)puVar15 + iVar4 + -8) = 0x799276;
          iVar17 = FUN_007a22e0();
          iVar17 = param_3 - ((local_64 - iVar17) + 7 >> 3);
        }
        param_3 = param_3 - iVar17;
        *(uint *)((int)puVar15 + iVar4 + -4) = local_5c;
        local_20 = iVar17;
        *(undefined4 *)((int)puVar15 + iVar4 + -8) = 0x799299;
        iVar5 = FUN_007a22e0();
        if (param_3 * 8 < local_64 - iVar5) {
          iVar17 = 0;
          param_3 = 0;
          local_20 = 0;
          local_18 = 0;
        }
        local_74 = local_74 - iVar17;
        goto LAB_007992ba;
      }
      *(undefined4 *)((int)puVar15 + iVar4 + -4) = 0xc;
      *(undefined1 **)((int)puVar15 + iVar4 + -8) = local_78;
      *(undefined4 *)((int)puVar15 + iVar4 + -0xc) = 0x799225;
      local_18 = FUN_007a2130();
      if (local_18 != 0) goto LAB_00799233;
    }
    param_5 = (undefined2 *)0x11;
  }
LAB_007992cd:
  iVar17 = local_10;
  uVar6 = 0x15;
  switch(piVar3[0xc]) {
  case 0x44d:
    uVar6 = 0xd;
    break;
  case 0x44e:
  case 0x44f:
    uVar6 = 0x11;
    break;
  case 0x450:
    uVar6 = 0x13;
    break;
  case 0x451:
    uVar6 = 0x15;
  }
  *(undefined4 *)((int)puVar15 + iVar4 + -4) = uVar6;
  *(undefined4 *)((int)puVar15 + iVar4 + -8) = 0x271c;
  *(int *)((int)puVar15 + iVar4 + -0xc) = iVar17;
  *(undefined4 *)((int)puVar15 + iVar4 + -0x10) = 0x799310;
  FUN_007a1d70();
  *(int *)((int)puVar15 + iVar4 + -0x10) = piVar3[0xb];
  *(undefined4 *)((int)puVar15 + iVar4 + -0x14) = 0x2718;
  *(int *)((int)puVar15 + iVar4 + -0x18) = iVar17;
  *(undefined4 *)((int)puVar15 + iVar4 + -0x1c) = 0x79931f;
  FUN_007a1d70();
  if (local_18 == 0) {
    iVar17 = local_3c;
  }
  else {
    local_24 = 0;
    iVar17 = 0;
  }
  *(undefined4 *)((int)puVar15 + iVar4 + -4) = 0x799340;
  uVar13 = local_14;
  iVar17 = iVar17 * -4;
  iVar5 = iVar17 + iVar4;
  if ((local_24 != 0) && (local_c != 0x3ea)) {
    uVar16 = local_14;
    if ((int)param_1 <= (int)local_14) {
      uVar16 = (uint)param_1;
    }
    local_28 = (undefined1 *)((int)puVar15 + iVar17 + iVar4);
    *(undefined4 *)((int)puVar15 + iVar17 + iVar4 + -4) = 0;
    *(uint *)((int)puVar15 + iVar17 + iVar4 + -8) = uVar16;
    *(undefined1 **)((int)puVar15 + iVar17 + iVar4 + -0xc) =
         (undefined1 *)((int)puVar15 + iVar17 + iVar4);
    *(undefined4 *)((int)puVar15 + iVar17 + iVar4 + -0x10) = 0;
    *(undefined4 *)((int)puVar15 + iVar17 + iVar4 + -0x14) = 0;
    *(int **)((int)puVar15 + iVar17 + iVar4 + -0x18) = piVar3;
    *(undefined4 *)((int)puVar15 + iVar17 + iVar4 + -0x1c) = 0x79936e;
    FUN_00798e20();
  }
  if (local_18 == 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = piVar3[2] * uVar13;
  }
  *(undefined4 *)((int)puVar15 + iVar17 + iVar4 + -4) = 0x799394;
  iVar12 = local_10;
  iVar7 = iVar7 * -4;
  local_2c = (undefined1 *)((int)puVar15 + iVar7 + iVar5);
  puVar14 = (undefined1 *)((int)puVar15 + iVar7 + iVar5);
  if ((local_18 != 0) && (puVar14 = (undefined1 *)((int)puVar15 + iVar7 + iVar5), local_1c != 0)) {
    *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -4) = 0;
    *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -8) = 0x271a;
    *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0xc) = iVar12;
    *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x10) = 0x7993b7;
    FUN_007a1d70();
    uVar13 = local_14;
    iVar5 = local_20;
    *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x10) = 0;
    *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x14) = 0;
    *(uint *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x18) = uVar13;
    *(undefined1 **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x1c) =
         (undefined1 *)((int)puVar15 + iVar7 + iVar17 + iVar4);
    *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x20) = iVar5;
    *(uint *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x24) = param_2 + param_3;
    *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x28) = iVar12;
    *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x2c) = 0x7993d3;
    FUN_007a03f0();
    *(uint **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x2c) = &local_30;
    *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x30) = 0xfbf;
    *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x34) = iVar12;
    *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x38) = 0x7993e2;
    FUN_007a1d70();
    puVar14 = local_2c;
  }
  local_2c = puVar14;
  *(undefined2 **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -4) = param_5;
  *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -8) = 0x271a;
  *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0xc) = iVar12;
  *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x10) = 0x7993f9;
  FUN_007a1d70();
  iVar5 = local_10;
  if (local_c == 1000) {
    param_5 = (undefined2 *)CONCAT13(0xff,CONCAT12(0xff,param_5._0_2_));
    iVar12 = 0;
    if (0 < piVar3[2] * (int)param_1) {
      pfVar8 = param_4;
      do {
        *pfVar8 = 0.0;
        iVar12 = iVar12 + 1;
        pfVar8 = pfVar8 + 1;
      } while (iVar12 < piVar3[2] * (int)param_1);
    }
    if ((piVar3[0xe] == 0x3e9) && (((local_18 == 0 || (local_1c == 0)) || (piVar3[0x10] == 0)))) {
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -4) = 0;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -8) = 0x271a;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0xc) = iVar5;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x10) = 0x7996a1;
      FUN_007a1d70();
      iVar12 = local_8;
      iVar5 = local_10;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x10) = 0;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x14) = 0;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x18) = iVar12;
      *(float **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x1c) = param_4;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x20) = 2;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x24) = (int)&param_5 + 2;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x28) = iVar5;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x2c) = 0x7996b9;
      FUN_007a03f0();
    }
LAB_00799475:
    uVar13 = 0;
    puVar14 = (undefined1 *)((int)puVar15 + iVar7 + iVar17 + iVar4);
    if (0 < piVar3[2] * (int)param_1) {
      pfVar8 = param_4;
      psVar10 = local_48;
      do {
        sVar1 = *psVar10;
        uVar13 = uVar13 + 1;
        psVar10 = psVar10 + 1;
        *pfVar8 = (float)(int)sVar1 * _DAT_008376ac + *pfVar8;
        pfVar8 = pfVar8 + 1;
      } while ((int)uVar13 < piVar3[2] * (int)param_1);
      puVar14 = local_2c;
      param_5 = (undefined2 *)uVar13;
    }
  }
  else {
    param_5 = (undefined2 *)local_44;
    if ((int)param_1 <= (int)local_44) {
      param_5 = (undefined2 *)param_1;
    }
    if (((local_c != piVar3[0xe]) && (0 < piVar3[0xe])) && (piVar3[0x10] == 0)) {
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -4) = 0xfbc;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -8) = iVar12;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0xc) = 0x799438;
      FUN_007a1d70();
    }
    *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -4) = 0;
    *(undefined1 **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -8) = local_78;
    *(undefined2 **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0xc) = param_5;
    *(float **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x10) = param_4;
    *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x14) = param_3;
    iVar5 = local_10;
    *(uint *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x18) = ~-(uint)(param_6 != 0) & param_2;
    *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x1c) = iVar5;
    *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x20) = 0x799465;
    local_40 = FUN_007a03f0();
    puVar14 = (undefined1 *)((int)puVar15 + iVar7 + iVar17 + iVar4);
    if (local_c != 0x3ea) goto LAB_00799475;
  }
  iVar5 = local_10;
  *(undefined2 ***)((int)puVar15 + iVar7 + iVar17 + iVar4 + -4) = &param_5;
  *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -8) = 0x271f;
  *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0xc) = iVar5;
  *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x10) = 0x7994c6;
  FUN_007a1d70();
  iVar5 = local_10;
  param_5 = *(undefined2 **)((int)param_5 + 0x3c);
  if (local_18 != 0) {
    if (local_1c == 0) {
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -4) = 0xfbc;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -8) = iVar5;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0xc) = 0x7994f6;
      FUN_007a1d70();
      iVar5 = local_10;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0xc) = 0;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x10) = 0x271a;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x14) = iVar5;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x18) = 0x799506;
      FUN_007a1d70();
      uVar13 = local_14;
      iVar5 = local_20;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x18) = 0;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x1c) = 0;
      *(uint *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x20) = uVar13;
      *(undefined1 **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x24) = puVar14;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x28) = iVar5;
      iVar5 = local_10;
      *(uint *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x2c) = param_2 + param_3;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x30) = iVar5;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x34) = 0x799525;
      FUN_007a03f0();
      iVar5 = local_10;
      *(uint **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x34) = &local_30;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x38) = 0xfbf;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x3c) = iVar5;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x40) = 0x799537;
      FUN_007a1d70();
      iVar5 = piVar3[2];
      iVar11 = (int)param_1 - local_8;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x40) = piVar3[3];
      *(undefined2 **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x44) = param_5;
      iVar12 = local_8;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x48) = iVar5;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x4c) = iVar12;
      *(float **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x50) = param_4 + iVar11 * iVar5;
      *(undefined1 **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x54) = puVar14 + iVar5 * iVar12 * 4
      ;
      *(float **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x58) = param_4 + iVar11 * iVar5;
      *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x5c) = 0x799563;
      FUN_007997a0();
      if (local_1c == 0) goto LAB_007995d2;
    }
    iVar5 = 0;
    if (0 < piVar3[2]) {
      do {
        iVar12 = 0;
        if (0 < local_8) {
          do {
            iVar11 = piVar3[2] * iVar12 + iVar5;
            iVar12 = iVar12 + 1;
            param_4[iVar11] = *(float *)(puVar14 + iVar11 * 4);
            puVar14 = local_2c;
          } while (iVar12 < local_8);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < piVar3[2]);
    }
    iVar5 = piVar3[2];
    iVar12 = iVar5 * local_8;
    *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -4) = piVar3[3];
    *(undefined2 **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -8) = param_5;
    *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0xc) = iVar5;
    *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x10) = local_8;
    *(float **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x14) = param_4 + iVar12;
    *(float **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x18) = param_4 + iVar12;
    *(undefined1 **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x1c) = puVar14 + iVar12 * 4;
    *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x20) = 0x7995cf;
    FUN_007997a0();
  }
LAB_007995d2:
  if (local_24 != 0) {
    if ((int)param_1 < (int)local_14) {
      iVar5 = piVar3[2];
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -4) = piVar3[3];
      iVar12 = local_8;
      *(undefined2 **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -8) = param_5;
      puVar14 = local_28;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0xc) = iVar5;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x10) = iVar12;
      *(float **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x14) = param_4;
      *(float **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x18) = param_4;
      *(undefined1 **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x1c) = puVar14;
    }
    else {
      iVar5 = 0;
      if (0 < piVar3[2] * local_8) {
        pfVar8 = param_4;
        do {
          iVar5 = iVar5 + 1;
          *pfVar8 = *(float *)(((int)local_28 - (int)param_4) + (int)pfVar8);
          pfVar8 = pfVar8 + 1;
        } while (iVar5 < piVar3[2] * local_8);
      }
      iVar5 = piVar3[2];
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -4) = piVar3[3];
      iVar12 = iVar5 * local_8;
      *(undefined2 **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -8) = param_5;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0xc) = iVar5;
      *(int *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x10) = local_8;
      *(float **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x14) = param_4 + iVar12;
      *(float **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x18) = param_4 + iVar12;
      *(undefined1 **)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x1c) = local_28 + iVar12 * 4;
    }
    *(undefined4 *)((int)puVar15 + iVar7 + iVar17 + iVar4 + -0x20) = 0x7996dc;
    FUN_007997a0();
  }
  if (piVar3[10] != 0) {
    iVar4 = 0;
    fVar19 = (float10)1.4426950408889634 *
             (float10)piVar3[10] * (float10)_DAT_008376a8 * (float10)_DAT_008376a0;
    fVar18 = ROUND(fVar19);
    fVar19 = (float10)f2xm1(fVar19 - fVar18);
    fVar18 = (float10)fscale((float10)1 + fVar19,fVar18);
    if (0 < piVar3[2] * (int)param_1) {
      do {
        iVar4 = iVar4 + 1;
        *param_4 = *param_4 * (float)fVar18;
        param_4 = param_4 + 1;
      } while (iVar4 < piVar3[2] * (int)param_1);
    }
  }
  iVar4 = 1;
  if (param_3 < 2) {
    piVar3[0x14] = 0;
  }
  else {
    piVar3[0x14] = local_5c ^ local_30;
  }
  piVar3[0xe] = local_c;
  if ((local_18 == 0) || (local_1c != 0)) {
    iVar4 = 0;
  }
  piVar3[0x10] = iVar4;
  if (-1 < (int)local_40) {
    local_40 = (uint)param_1;
  }
  return local_40;
}

