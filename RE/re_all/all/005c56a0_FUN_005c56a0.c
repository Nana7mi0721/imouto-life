
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005c56a0(int param_1,int param_2,float param_3,float param_4,double param_5,double param_6,
            int param_7,int param_8,uint param_9,int param_10,int param_11,int param_12)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  int *piVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  bool bVar13;
  float fVar14;
  bool bVar15;
  float fVar16;
  float *pfVar17;
  int iVar18;
  float *pfVar19;
  float *pfVar20;
  uint uVar21;
  ushort in_FPUControlWord;
  float10 fVar22;
  float local_ec;
  uint local_e8;
  uint local_e0;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c0;
  float local_bc;
  float local_b4;
  float local_b0;
  float local_a8;
  float local_a4;
  float local_58;
  int local_54;
  float local_50;
  uint local_4c;
  undefined4 local_48;
  double local_44;
  undefined8 local_3c;
  float local_34;
  float local_30;
  uint local_28;
  ushort local_24;
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_50 = 0.0;
  local_58 = 1.0;
  local_48 = 0;
  local_1c = 0;
  local_3c = (double)CONCAT44(local_3c._4_4_,(float)param_5);
  local_4c = 0;
  if ((DAT_00f3a070 == 0) || ((float)param_5 == 0.0)) {
    return 0xffffffff;
  }
  uVar21 = param_9 | 0x8000;
  if (*(char *)(*(int *)(param_7 + 0x4c) + 10) != '\0') {
    uVar21 = param_9 | 0x18000;
  }
  if (*(char *)(*(int *)(param_7 + 0x4c) + 0x12) != '\0') {
    uVar21 = uVar21 | 0x20000;
  }
  if (DAT_00ef7314 != *(int *)(**(int **)(param_7 + 0x100) + 4)) {
    iVar18 = **(int **)(param_7 + 0x100);
    FUN_005bc5b0(*(undefined4 *)(iVar18 + 4),*(undefined4 *)(iVar18 + 8));
  }
  if (((DAT_00a3d360 != 0) || (DAT_00ef72cc != 0)) || (DAT_00ef72c8 != uVar21)) {
    FUN_005bcf50();
  }
  if (param_6 != 0.0) {
    FUN_0056d4d0((float)param_6,&local_50,&local_58);
  }
  fVar1 = DAT_00f07344;
  fVar16 = DAT_00a380b8;
  local_e8 = (uint)(param_6 == 0.0);
  if ((param_12 == 0) && (DAT_00a380bc != 0)) {
    local_20 = 0;
    bVar15 = true;
    local_d0 = *(float *)(param_7 + 0x68) * (float)_DAT_00804a60;
    local_d4 = *(float *)(param_7 + 0x6c) * (float)_DAT_00804a60;
LAB_005c5b17:
    local_18 = 0;
  }
  else {
    uVar21 = *(uint *)(param_7 + 0x60);
    bVar13 = false;
    local_1c = uVar21 & 0x80000001;
    local_20 = 0;
    bVar15 = false;
    if ((int)local_1c < 0) {
      local_1c = (local_1c - 1 | 0xfffffffe) + 1;
    }
    uVar5 = *(uint *)(param_7 + 100);
    local_4c = uVar5 & 0x80000001;
    if ((int)local_4c < 0) {
      local_4c = (local_4c - 1 | 0xfffffffe) + 1;
    }
    fVar7 = (float)param_1;
    param_3 = param_3 - fVar7;
    fVar2 = (float)param_2;
    param_4 = param_4 - fVar2;
    if (param_3 < 0.0) {
      param_3 = -param_3;
    }
    if (param_4 < 0.0) {
      param_4 = -param_4;
    }
    local_44 = (double)CONCAT44(local_44._4_4_,param_4);
    fVar3 = (float)_DAT_00804a60;
    if ((_DAT_007d56d8 <= param_3) || (_DAT_007d56d8 <= param_4)) {
      bVar13 = true;
      local_20 = 1;
      local_d0 = (float)(int)uVar21 * fVar3;
      local_d4 = (float)(int)uVar5 * fVar3;
      param_3 = fVar7 + fVar3;
      fVar2 = fVar2 + fVar3;
LAB_005c5a0e:
      param_4 = fVar2;
    }
    else {
      param_3 = fVar7;
      if (param_5 != 1.0) {
        bVar15 = true;
        local_d0 = (float)(int)uVar21 * fVar3;
        local_d4 = (float)(int)uVar5 * fVar3;
        goto LAB_005c5a0e;
      }
      if (local_1c == local_4c) {
        if (local_1c == 0) {
          local_d0 = (float)((int)uVar21 >> 1);
          local_d4 = (float)((int)uVar5 >> 1);
        }
        else {
          bVar15 = true;
          local_d0 = (float)(int)uVar21 * fVar3;
          local_d4 = (float)(int)uVar5 * fVar3;
          fVar2 = fVar2 - fVar3;
          param_3 = fVar7 - fVar3;
        }
        goto LAB_005c5a0e;
      }
      local_d0 = (float)(int)uVar21 * fVar3;
      local_d4 = (float)(int)uVar5 * fVar3;
      if (local_1c != 0) {
        local_d0 = local_d0 - fVar3;
      }
      param_4 = fVar2;
      if (local_4c != 0) {
        local_d4 = local_d4 - fVar3;
      }
    }
    if ((((param_12 != 1) || (bVar13)) || (local_e8 != 0)) || ((local_1c != 1 && (local_4c != 1))))
    goto LAB_005c5b17;
    if (((((param_6 < _DAT_007fcb98) || (_DAT_007fcb90 < param_6)) ||
         ((_DAT_007fcb98 < param_6 && (param_6 < _DAT_007fcb88)))) ||
        ((_DAT_007fcb80 < param_6 && (param_6 < _DAT_007fcb78)))) ||
       (((_DAT_007fcb70 < param_6 && (param_6 < _DAT_007fcb68)) ||
        ((_DAT_007fcb60 < param_6 && (param_6 < _DAT_007fcb58)))))) {
      local_18 = 1;
    }
    else {
      if ((param_6 <= _DAT_007fcb50) || (_DAT_007fcb90 <= param_6)) goto LAB_005c5b17;
      local_18 = 1;
    }
  }
  local_54 = *(int *)(param_7 + 0x88);
  local_28 = 0;
  if ((param_8 != 0) && (local_28 = (uint)(*(int *)(param_8 + 0x88) != local_54), param_8 != 0)) {
    local_48 = param_8 + 0x8c;
  }
  if (param_10 == 1) {
    local_ec = _DAT_007d5340;
  }
  else {
    local_ec = 1.0;
  }
  fVar7 = (float)local_3c * local_ec;
  if (param_11 == 1) {
    local_ec = _DAT_007d5340;
  }
  else {
    local_ec = 1.0;
  }
  local_ec = (float)local_3c * local_ec;
  if (DAT_00f0733c != 1) {
    if (DAT_00f0733c == 2) {
      if ((local_54 != 1) || (!bVar15)) {
        if (0 < local_54) {
          pfVar19 = (float *)(local_48 + 0x34);
          pfVar20 = (float *)(param_7 + 0xdc);
          do {
            FUN_005bc5b0(*(undefined4 *)(*(int *)pfVar20[9] + 4),
                         *(undefined4 *)(*(int *)pfVar20[9] + 8));
            piVar6 = (int *)pfVar19[0x10];
            FUN_005bc640(*(undefined4 *)(*piVar6 + 4),*(undefined4 *)(*piVar6 + 8),piVar6[5],
                         piVar6[6]);
            if (DAT_00ef72e8 != 0) {
              FUN_005bbac0();
            }
            if (DAT_00dda46c != 0) {
              FUN_00584d70();
            }
            if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
               (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <=
                DAT_00f07334 + 6)) {
              FUN_005c3310(0,0);
              DAT_00f07340 = 4;
            }
            pfVar17 = DAT_00f0732c;
            DAT_00f0732c[4] = fVar1;
            pfVar17[0xe] = fVar1;
            pfVar17[0x18] = fVar1;
            pfVar17[0x22] = fVar1;
            pfVar17[0x2c] = fVar1;
            pfVar17[0x36] = fVar1;
            fVar2 = fVar7 * (pfVar20[-8] - local_d0);
            fVar9 = local_ec * (pfVar20[-7] - local_d4);
            fVar3 = (pfVar20[-4] - local_d0) * fVar7;
            fVar12 = (pfVar20[-3] - local_d4) * local_ec;
            fVar4 = (*pfVar20 - local_d0) * fVar7;
            fVar11 = (pfVar20[1] - local_d4) * local_ec;
            fVar8 = (pfVar20[4] - local_d0) * fVar7;
            fVar10 = (pfVar20[5] - local_d4) * local_ec;
            fVar14 = param_3 + (local_58 * fVar2 - local_50 * fVar9);
            *pfVar17 = fVar14;
            fVar9 = param_4 + fVar2 * local_50 + fVar9 * local_58;
            pfVar17[1] = fVar9;
            fVar2 = (fVar3 * local_58 - fVar12 * local_50) + param_3;
            pfVar17[10] = fVar2;
            fVar12 = fVar3 * local_50 + fVar12 * local_58 + param_4;
            pfVar17[0xb] = fVar12;
            fVar3 = (fVar4 * local_58 - fVar11 * local_50) + param_3;
            local_44 = (double)CONCAT44(local_44._4_4_,fVar3);
            pfVar17[0x14] = fVar3;
            fVar11 = fVar4 * local_50 + fVar11 * local_58 + param_4;
            pfVar17[0x15] = fVar11;
            fVar4 = (fVar8 * local_58 - fVar10 * local_50) + param_3;
            pfVar17[0x1e] = fVar4;
            fVar8 = fVar10 * local_58 + fVar8 * local_50 + param_4;
            pfVar17[0x1f] = fVar8;
            pfVar17[0x28] = fVar3;
            pfVar17[0x29] = fVar11;
            pfVar17[0x32] = fVar2;
            pfVar17[0x33] = fVar12;
            if (DAT_00a380e8 == 1) {
              pfVar17[6] = _DAT_00ef730c * ((fVar14 - pfVar19[-1]) - (float)_DAT_00a380e0);
              pfVar17[7] = ((fVar9 - *pfVar19) - (float)_DAT_00a380e4) * _DAT_00ef7310;
              pfVar17[0x10] = ((fVar2 - pfVar19[-1]) - (float)_DAT_00a380e0) * _DAT_00ef730c;
              pfVar17[0x11] = ((fVar12 - *pfVar19) - (float)_DAT_00a380e4) * _DAT_00ef7310;
              pfVar17[0x1a] = ((fVar3 - pfVar19[-1]) - (float)_DAT_00a380e0) * _DAT_00ef730c;
              pfVar17[0x1b] = ((fVar11 - *pfVar19) - (float)_DAT_00a380e4) * _DAT_00ef7310;
              pfVar17[0x24] = _DAT_00ef730c * ((fVar4 - pfVar19[-1]) - (float)_DAT_00a380e0);
              pfVar17[0x25] = _DAT_00ef7310 * ((fVar8 - *pfVar19) - (float)_DAT_00a380e4);
              pfVar17[0x2e] = _DAT_00ef730c * ((fVar3 - pfVar19[-1]) - (float)_DAT_00a380e0);
              pfVar17[0x2f] = _DAT_00ef7310 * ((fVar11 - *pfVar19) - (float)_DAT_00a380e4);
              pfVar17[0x38] = _DAT_00ef730c * ((fVar2 - pfVar19[-1]) - (float)_DAT_00a380e0);
              fVar2 = ((fVar12 - *pfVar19) - (float)_DAT_00a380e4) * _DAT_00ef7310;
            }
            else {
              fVar2 = (float)_DAT_00a380e0;
              fVar3 = _DAT_00ef730c * (fVar2 + (pfVar20[-8] - pfVar19[-1]));
              fVar4 = ((pfVar20[-4] - pfVar19[-1]) + fVar2) * _DAT_00ef730c;
              local_3c = (double)CONCAT44(fVar4,fVar3);
              local_34 = ((*pfVar20 - pfVar19[-1]) + fVar2) * _DAT_00ef730c;
              local_30 = ((pfVar20[4] - pfVar19[-1]) + fVar2) * _DAT_00ef730c;
              fVar2 = (float)_DAT_00a380e4;
              local_10 = _DAT_00ef7310 * (fVar2 + (pfVar20[-7] - *pfVar19));
              local_c = ((pfVar20[-3] - *pfVar19) + fVar2) * _DAT_00ef7310;
              local_8 = ((pfVar20[1] - *pfVar19) + fVar2) * _DAT_00ef7310;
              local_4 = ((pfVar20[5] - *pfVar19) + fVar2) * _DAT_00ef7310;
              pfVar17[6] = fVar3;
              pfVar17[7] = local_10;
              pfVar17[0x10] = fVar4;
              pfVar17[0x11] = local_c;
              pfVar17[0x1a] = local_34;
              pfVar17[0x1b] = local_8;
              pfVar17[0x24] = local_30;
              pfVar17[0x25] = local_4;
              pfVar17[0x2e] = local_34;
              pfVar17[0x2f] = local_8;
              pfVar17[0x38] = fVar4;
              fVar2 = local_c;
            }
            pfVar17[0x39] = fVar2;
            pfVar17[8] = pfVar20[-6];
            pfVar17[9] = pfVar20[-5];
            pfVar17[0x12] = pfVar20[-2];
            pfVar17[0x13] = pfVar20[-5];
            pfVar17[0x1c] = pfVar20[-6];
            pfVar17[0x1d] = pfVar20[3];
            pfVar17[0x26] = pfVar20[-2];
            pfVar17[0x27] = pfVar20[3];
            pfVar17[0x30] = pfVar20[-6];
            pfVar17[0x31] = pfVar20[3];
            pfVar17[0x3a] = pfVar20[-2];
            fVar2 = pfVar20[-5];
            pfVar17[2] = fVar16;
            pfVar17[0x3b] = fVar2;
            pfVar17[0xc] = fVar16;
            pfVar17[0x16] = fVar16;
            pfVar17[3] = 1.0;
            pfVar17[0x20] = fVar16;
            pfVar17[0xd] = 1.0;
            pfVar17[0x2a] = fVar16;
            pfVar17[0x17] = 1.0;
            pfVar17[0x34] = fVar16;
            pfVar17[0x21] = 1.0;
            pfVar17[0x2b] = 1.0;
            pfVar17[0x35] = 1.0;
            DAT_00f0732c = DAT_00f0732c + 0x3c;
            DAT_00f07334 = DAT_00f07334 + 6;
            if (local_28 == 0) {
              pfVar19 = pfVar19 + 0x1e;
            }
            pfVar20 = pfVar20 + 0x1e;
            local_54 = local_54 + -1;
          } while (local_54 != 0);
          return 0;
        }
      }
      else {
        FUN_005bc5b0(*(undefined4 *)(**(int **)(param_7 + 0x100) + 4),
                     *(undefined4 *)(**(int **)(param_7 + 0x100) + 8));
        uVar21 = local_48;
        piVar6 = *(int **)(local_48 + 0x74);
        FUN_005bc640(*(undefined4 *)(*piVar6 + 4),*(undefined4 *)(*piVar6 + 8),piVar6[5],piVar6[6]);
        if (DAT_00ef72e8 != 0) {
          FUN_005bbac0();
        }
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
           (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <=
            DAT_00f07334 + 6)) {
          FUN_005c3310(0,0);
          DAT_00f07340 = 4;
        }
        pfVar19 = DAT_00f0732c;
        DAT_00f0732c[4] = fVar1;
        pfVar19[0xe] = fVar1;
        pfVar19[0x18] = fVar1;
        pfVar19[0x22] = fVar1;
        pfVar19[0x2c] = fVar1;
        pfVar19[0x36] = fVar1;
        fVar1 = fVar7 * (*(float *)(param_7 + 0xbc) - local_d0);
        fVar2 = local_ec * (*(float *)(param_7 + 0xc0) - local_d4);
        fVar3 = local_58 * fVar1 - local_50 * fVar2;
        fVar4 = fVar1 * local_50 + fVar2 * local_58;
        fVar7 = (*(float *)(param_7 + 0xcc) - local_d0) * fVar7;
        local_ec = (*(float *)(param_7 + 0xd0) - local_d4) * local_ec;
        fVar2 = fVar7 * local_58 - local_ec * local_50;
        fVar1 = local_ec * local_58 + fVar7 * local_50;
        fVar7 = param_3 + fVar3;
        *pfVar19 = fVar7;
        fVar9 = param_4 + fVar4;
        pfVar19[1] = fVar9;
        fVar8 = fVar2 + param_3;
        pfVar19[10] = fVar8;
        fVar10 = fVar1 + param_4;
        pfVar19[0xb] = fVar10;
        fVar2 = param_3 - fVar2;
        pfVar19[0x14] = fVar2;
        fVar1 = param_4 - fVar1;
        pfVar19[0x15] = fVar1;
        param_3 = param_3 - fVar3;
        pfVar19[0x1e] = param_3;
        param_4 = param_4 - fVar4;
        pfVar19[0x1f] = param_4;
        pfVar19[0x28] = fVar2;
        pfVar19[0x29] = fVar1;
        pfVar19[0x32] = fVar8;
        pfVar19[0x33] = fVar10;
        if (DAT_00a380e8 == 1) {
          pfVar19[6] = _DAT_00ef730c * ((fVar7 - *(float *)(uVar21 + 0x30)) - (float)_DAT_00a380e0);
          pfVar19[7] = ((fVar9 - *(float *)(uVar21 + 0x34)) - (float)_DAT_00a380e4) * _DAT_00ef7310;
          pfVar19[0x10] =
               ((fVar8 - *(float *)(uVar21 + 0x30)) - (float)_DAT_00a380e0) * _DAT_00ef730c;
          pfVar19[0x11] =
               ((fVar10 - *(float *)(uVar21 + 0x34)) - (float)_DAT_00a380e4) * _DAT_00ef7310;
          pfVar19[0x1a] =
               ((fVar2 - *(float *)(uVar21 + 0x30)) - (float)_DAT_00a380e0) * _DAT_00ef730c;
          pfVar19[0x1b] =
               ((fVar1 - *(float *)(uVar21 + 0x34)) - (float)_DAT_00a380e4) * _DAT_00ef7310;
          pfVar19[0x24] =
               _DAT_00ef730c * ((param_3 - *(float *)(uVar21 + 0x30)) - (float)_DAT_00a380e0);
          pfVar19[0x25] =
               _DAT_00ef7310 * ((param_4 - *(float *)(uVar21 + 0x34)) - (float)_DAT_00a380e4);
          pfVar19[0x2e] =
               _DAT_00ef730c * ((fVar2 - *(float *)(uVar21 + 0x30)) - (float)_DAT_00a380e0);
          pfVar19[0x2f] =
               _DAT_00ef7310 * ((fVar1 - *(float *)(uVar21 + 0x34)) - (float)_DAT_00a380e4);
          pfVar19[0x38] =
               ((fVar8 - *(float *)(uVar21 + 0x30)) - (float)_DAT_00a380e0) * _DAT_00ef730c;
          fVar1 = ((fVar10 - *(float *)(uVar21 + 0x34)) - (float)_DAT_00a380e4) * _DAT_00ef7310;
        }
        else {
          fVar7 = (*(float *)(param_7 + 0xbc) - *(float *)(uVar21 + 0x30)) +
                  (float)_DAT_00a380e0 * _DAT_00ef730c;
          fVar2 = (*(float *)(param_7 + 0xcc) - *(float *)(uVar21 + 0x30)) +
                  (float)_DAT_00a380e0 * _DAT_00ef730c;
          fVar1 = (*(float *)(param_7 + 0xc0) - *(float *)(uVar21 + 0x34)) +
                  (float)_DAT_00a380e4 * _DAT_00ef7310;
          fVar3 = (*(float *)(param_7 + 0xe0) - *(float *)(uVar21 + 0x34)) +
                  (float)_DAT_00a380e4 * _DAT_00ef7310;
          pfVar19[6] = fVar7;
          pfVar19[7] = fVar1;
          pfVar19[0x10] = fVar2;
          pfVar19[0x11] = fVar1;
          pfVar19[0x1a] = fVar7;
          pfVar19[0x1b] = fVar3;
          pfVar19[0x25] = fVar3;
          pfVar19[0x2f] = fVar3;
          pfVar19[0x24] = fVar2;
          pfVar19[0x38] = fVar2;
          pfVar19[0x2e] = fVar7;
        }
        pfVar19[0x39] = fVar1;
        pfVar19[8] = *(float *)(param_7 + 0xc4);
        pfVar19[9] = *(float *)(param_7 + 200);
        pfVar19[0x12] = *(float *)(param_7 + 0xd4);
        pfVar19[0x13] = *(float *)(param_7 + 200);
        pfVar19[0x1c] = *(float *)(param_7 + 0xc4);
        pfVar19[0x1d] = *(float *)(param_7 + 0xe8);
        pfVar19[0x26] = *(float *)(param_7 + 0xd4);
        pfVar19[0x27] = *(float *)(param_7 + 0xe8);
        pfVar19[0x30] = *(float *)(param_7 + 0xc4);
        pfVar19[0x31] = *(float *)(param_7 + 0xe8);
        pfVar19[0x3a] = *(float *)(param_7 + 0xd4);
        fVar1 = *(float *)(param_7 + 200);
        pfVar19[2] = fVar16;
        pfVar19[0x3b] = fVar1;
        pfVar19[0xc] = fVar16;
        pfVar19[0x16] = fVar16;
        pfVar19[3] = 1.0;
        pfVar19[0x20] = fVar16;
        pfVar19[0xd] = 1.0;
        pfVar19[0x2a] = fVar16;
        pfVar19[0x17] = 1.0;
        pfVar19[0x34] = fVar16;
        pfVar19[0x21] = 1.0;
        pfVar19[0x2b] = 1.0;
        pfVar19[0x35] = 1.0;
        DAT_00f0732c = DAT_00f0732c + 0x3c;
        DAT_00f07334 = DAT_00f07334 + 6;
      }
    }
    return 0;
  }
  if ((local_54 != 1) || (!bVar15)) {
    if (local_e8 != 0) {
      iVar18 = 0;
      pfVar19 = (float *)(param_7 + 0xe8);
      while( true ) {
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
           (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <=
            DAT_00f07334 + 6)) {
          FUN_005c3310(0,0);
          DAT_00f07340 = 4;
        }
        pfVar20 = DAT_00f0732c;
        DAT_00f0732c[4] = fVar1;
        pfVar20[0xb] = fVar1;
        pfVar20[0x12] = fVar1;
        pfVar20[0x19] = fVar1;
        pfVar20[0x20] = fVar1;
        pfVar20[0x27] = fVar1;
        pfVar20[5] = pfVar19[-9];
        pfVar20[6] = pfVar19[-8];
        pfVar20[0xc] = pfVar19[-5];
        pfVar20[0xd] = pfVar19[-8];
        pfVar20[0x14] = *pfVar19;
        pfVar20[0x13] = pfVar19[-9];
        pfVar20[0x1a] = pfVar19[-5];
        pfVar20[0x1b] = *pfVar19;
        pfVar20[0x21] = pfVar19[-9];
        pfVar20[0x22] = *pfVar19;
        pfVar20[0x28] = pfVar19[-5];
        pfVar20[0x29] = pfVar19[-8];
        fVar2 = pfVar19[-10];
        fVar10 = (pfVar19[-7] - local_d0) * fVar7 + param_3;
        fVar8 = (pfVar19[-6] - local_d4) * local_ec + param_4;
        fVar11 = (pfVar19[-3] - local_d0) * fVar7 + param_3;
        fVar9 = (pfVar19[-2] - local_d4) * local_ec + param_4;
        fVar3 = pfVar19[1];
        fVar4 = pfVar19[2];
        *pfVar20 = (pfVar19[-0xb] - local_d0) * fVar7 + param_3;
        pfVar20[1] = (fVar2 - local_d4) * local_ec + param_4;
        pfVar20[7] = fVar10;
        pfVar20[8] = fVar8;
        pfVar20[0xe] = fVar11;
        pfVar20[2] = fVar16;
        pfVar20[9] = fVar16;
        pfVar20[0xf] = fVar9;
        pfVar20[0x10] = fVar16;
        pfVar20[0x17] = fVar16;
        pfVar20[0x15] = fVar7 * (fVar3 - local_d0) + param_3;
        pfVar20[0x1e] = fVar16;
        pfVar20[0x25] = fVar16;
        pfVar20[0x16] = (fVar4 - local_d4) * local_ec + param_4;
        iVar18 = iVar18 + 1;
        pfVar20[0x1c] = fVar11;
        pfVar20[0x1d] = fVar9;
        pfVar20[0x23] = fVar10;
        pfVar20[0x24] = fVar8;
        pfVar20[3] = 1.0;
        pfVar20[10] = 1.0;
        pfVar20[0x11] = 1.0;
        pfVar20[0x18] = 1.0;
        pfVar20[0x1f] = 1.0;
        pfVar20[0x26] = 1.0;
        DAT_00f0732c = DAT_00f0732c + 0x2a;
        DAT_00f07334 = DAT_00f07334 + 6;
        if (local_54 <= iVar18) break;
        pfVar20 = pfVar19 + 0x24;
        pfVar19 = pfVar19 + 0x1e;
        FUN_005bc5b0(*(undefined4 *)(*(int *)*pfVar20 + 4),*(undefined4 *)(*(int *)*pfVar20 + 8));
        FUN_005bbac0();
      }
      return 0;
    }
    local_e0 = local_e8;
    pfVar19 = (float *)(param_7 + 0xe8);
    do {
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
         (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <=
          DAT_00f07334 + 6)) {
        FUN_005c3310(0,0);
        DAT_00f07340 = 4;
      }
      pfVar20 = DAT_00f0732c;
      DAT_00f0732c[4] = fVar1;
      pfVar20[0xb] = fVar1;
      pfVar20[0x12] = fVar1;
      pfVar20[0x19] = fVar1;
      pfVar20[0x20] = fVar1;
      pfVar20[0x27] = fVar1;
      pfVar20[5] = pfVar19[-9];
      pfVar20[6] = pfVar19[-8];
      pfVar20[0xc] = pfVar19[-5];
      pfVar20[0xd] = pfVar19[-8];
      pfVar20[0x13] = pfVar19[-9];
      pfVar20[0x14] = *pfVar19;
      pfVar20[0x1a] = pfVar19[-5];
      pfVar20[0x1b] = *pfVar19;
      pfVar20[0x21] = pfVar19[-9];
      pfVar20[0x22] = *pfVar19;
      pfVar20[0x28] = pfVar19[-5];
      pfVar20[0x29] = pfVar19[-8];
      fVar3 = (pfVar19[-0xb] - local_d0) * fVar7;
      fVar8 = (pfVar19[-10] - local_d4) * local_ec;
      local_c8 = fVar3 * local_50 + fVar8 * local_58;
      fVar2 = (pfVar19[-7] - local_d0) * fVar7;
      fVar4 = (pfVar19[-6] - local_d4) * local_ec;
      local_c0 = fVar2 * local_58 - fVar4 * local_50;
      local_bc = fVar2 * local_50 + fVar4 * local_58;
      fVar2 = (pfVar19[-3] - local_d0) * fVar7;
      fVar4 = (pfVar19[-2] - local_d4) * local_ec;
      local_b4 = fVar2 * local_58 - fVar4 * local_50;
      local_b0 = fVar2 * local_50 + fVar4 * local_58;
      fVar2 = (pfVar19[1] - local_d0) * fVar7;
      fVar4 = local_ec * (pfVar19[2] - local_d4);
      local_a8 = fVar2 * local_58 - fVar4 * local_50;
      local_a4 = fVar2 * local_50 + fVar4 * local_58;
      local_cc = param_3 + (local_58 * fVar3 - local_50 * fVar8);
      if (local_20 == 0) {
        if (local_18 != 0) {
          local_c8 = param_4 + local_c8;
          local_c0 = local_c0 + param_3;
          local_bc = local_bc + param_4;
          local_b4 = local_b4 + param_3;
          local_b0 = local_b0 + param_4;
          local_a8 = local_a8 + param_3;
          local_a4 = param_4 + local_a4;
          if (local_1c != 0) {
            local_44 = (double)local_cc;
            iVar18 = FUN_0050e270(local_cc);
            fVar22 = (float10)FUN_00550c30((float)local_44 - (float)iVar18);
            fVar2 = (float)fVar22;
            if (local_cc == local_b4) {
LAB_005c7a7e:
              if ((_DAT_007d652c <= fVar2) && (fVar2 <= (float)_DAT_007fcb48)) goto LAB_005c7a27;
            }
            else {
              fVar3 = (float)_DAT_007d5380;
              fVar4 = local_b4 - fVar3;
              if ((((!NAN(fVar4) && !NAN(local_cc)) && fVar4 < local_cc != (fVar4 == local_cc)) &&
                  (local_cc < local_b4 + fVar3)) ||
                 ((fVar4 = local_cc - fVar3,
                  (!NAN(fVar4) && !NAN(local_b4)) && fVar4 < local_b4 != (fVar4 == local_b4) &&
                  (local_b4 < local_cc + fVar3)))) goto LAB_005c7a7e;
LAB_005c7a27:
              fVar3 = (float)_DAT_007d5380;
              if (((local_cc != local_c0) &&
                  (((fVar4 = local_c0 - fVar3,
                    (NAN(fVar4) || NAN(local_cc)) || fVar4 < local_cc == (fVar4 == local_cc) ||
                    (local_c0 + fVar3 <= local_cc)) &&
                   ((fVar4 = local_cc - fVar3,
                    (NAN(fVar4) || NAN(local_c0)) || fVar4 < local_c0 == (fVar4 == local_c0) ||
                    (local_cc + fVar3 <= local_c0)))))) ||
                 ((_DAT_007d652c <= fVar2 && (fVar2 <= (float)_DAT_007fcb48)))) goto LAB_005c7ada;
            }
            fVar2 = (float)_DAT_00804a60;
            local_cc = local_cc - fVar2;
            local_c0 = local_c0 - fVar2;
            local_b4 = local_b4 - fVar2;
            local_a8 = local_a8 - fVar2;
          }
LAB_005c7ada:
          if (local_4c != 0) {
            local_44 = (double)local_c8;
            iVar18 = FUN_0050e270(local_c8);
            fVar22 = (float10)FUN_00550c30((float)local_44 - (float)iVar18);
            fVar2 = (float)fVar22;
            if (local_c8 == local_b0) {
LAB_005c7c20:
              if ((_DAT_007d652c <= fVar2) && (fVar2 <= (float)_DAT_007fcb48)) goto LAB_005c7b8c;
            }
            else {
              fVar4 = (float)_DAT_007d5380;
              fVar3 = local_b0 - fVar4;
              if ((((!NAN(fVar3) && !NAN(local_c8)) && fVar3 < local_c8 != (fVar3 == local_c8)) &&
                  (local_c8 < local_b0 + fVar4)) ||
                 ((fVar3 = local_c8 - fVar4,
                  (!NAN(fVar3) && !NAN(local_b0)) && fVar3 < local_b0 != (fVar3 == local_b0) &&
                  (local_b0 < local_c8 + fVar4)))) goto LAB_005c7c20;
LAB_005c7b8c:
              fVar3 = (float)_DAT_007d5380;
              if (((local_c8 != local_bc) &&
                  (((fVar4 = local_bc - fVar3,
                    (NAN(fVar4) || NAN(local_c8)) || fVar4 < local_c8 == (fVar4 == local_c8) ||
                    (local_bc + fVar3 <= local_c8)) &&
                   ((fVar4 = local_c8 - fVar3,
                    (NAN(fVar4) || NAN(local_bc)) || fVar4 < local_bc == (fVar4 == local_bc) ||
                    (local_c8 + fVar3 <= local_bc)))))) ||
                 ((_DAT_007d652c <= fVar2 && (fVar2 <= (float)_DAT_007fcb48)))) goto LAB_005c7c9a;
            }
            fVar2 = (float)_DAT_00804a60;
            local_c8 = local_c8 - fVar2;
            local_bc = local_bc - fVar2;
            local_b0 = local_b0 - fVar2;
            local_a4 = local_a4 - fVar2;
          }
LAB_005c7c9a:
          *pfVar20 = local_cc;
          pfVar20[1] = local_c8;
          pfVar20[7] = local_c0;
          pfVar20[8] = local_bc;
          goto LAB_005c78b9;
        }
        *pfVar20 = local_cc;
        pfVar20[1] = param_4 + local_c8;
        local_c0 = local_c0 + param_3;
        pfVar20[7] = local_c0;
        local_bc = local_bc + param_4;
        pfVar20[8] = local_bc;
        local_b4 = local_b4 + param_3;
        local_44 = (double)CONCAT44(local_44._4_4_,local_b4);
        pfVar20[0xe] = local_b4;
        pfVar20[0xf] = local_b0 + param_4;
        pfVar20[0x15] = local_a8 + param_3;
        pfVar20[0x16] = local_a4 + param_4;
        pfVar20[0x1c] = local_b4;
        pfVar20[0x1d] = local_b0 + param_4;
      }
      else {
        local_c8 = param_4 + local_c8;
        local_c0 = local_c0 + param_3;
        local_bc = local_bc + param_4;
        local_b4 = local_b4 + param_3;
        local_b0 = local_b0 + param_4;
        local_a8 = local_a8 + param_3;
        local_a4 = param_4 + local_a4;
        local_24 = in_FPUControlWord | 0xc00;
        local_14 = (int)ROUND(local_cc);
        fVar2 = local_cc - (float)local_14;
        if (fVar2 < 0.0) {
          fVar2 = -fVar2;
        }
        if (local_cc == local_b4) {
LAB_005c76ad:
          if ((_DAT_007d652c <= fVar2) && (fVar2 <= (float)_DAT_007fcb48)) goto LAB_005c765b;
LAB_005c76d3:
          fVar2 = (float)_DAT_00804a60;
          local_cc = local_cc - fVar2;
          local_c0 = local_c0 - fVar2;
          local_b4 = local_b4 - fVar2;
          local_a8 = local_a8 - fVar2;
        }
        else {
          fVar3 = (float)_DAT_007d5380;
          fVar4 = local_b4 - fVar3;
          if ((((!NAN(fVar4) && !NAN(local_cc)) && fVar4 < local_cc != (fVar4 == local_cc)) &&
              (local_cc < local_b4 + fVar3)) ||
             ((fVar4 = local_cc - fVar3,
              (!NAN(fVar4) && !NAN(local_b4)) && fVar4 < local_b4 != (fVar4 == local_b4) &&
              (local_b4 < local_cc + fVar3)))) goto LAB_005c76ad;
LAB_005c765b:
          fVar3 = (float)_DAT_007d5380;
          if (((local_cc == local_c0) ||
              (((fVar4 = local_c0 - fVar3,
                (!NAN(fVar4) && !NAN(local_cc)) && fVar4 < local_cc != (fVar4 == local_cc) &&
                (local_cc < local_c0 + fVar3)) ||
               ((fVar4 = local_cc - fVar3,
                (!NAN(fVar4) && !NAN(local_c0)) && fVar4 < local_c0 != (fVar4 == local_c0) &&
                (local_c0 < local_cc + fVar3)))))) &&
             ((fVar2 < _DAT_007d652c || ((float)_DAT_007fcb48 < fVar2)))) goto LAB_005c76d3;
        }
        local_28 = CONCAT22(local_28._2_2_,in_FPUControlWord);
        local_48 = CONCAT22(local_48._2_2_,in_FPUControlWord) | 0xc00;
        local_3c = (double)CONCAT44(local_3c._4_4_,(int)ROUND(local_c8));
        fVar2 = local_c8 - (float)(int)ROUND(local_c8);
        if (fVar2 < 0.0) {
          fVar2 = -fVar2;
        }
        if (local_c8 == local_b0) {
LAB_005c7842:
          if ((_DAT_007d652c <= fVar2) && (fVar2 <= (float)_DAT_007fcb48)) goto LAB_005c77d7;
LAB_005c786c:
          fVar2 = (float)_DAT_00804a60;
          local_c8 = local_c8 - fVar2;
          local_bc = local_bc - fVar2;
          local_b0 = local_b0 - fVar2;
          local_a4 = local_a4 - fVar2;
        }
        else {
          fVar3 = (float)_DAT_007d5380;
          fVar4 = local_b0 - fVar3;
          if ((((!NAN(fVar4) && !NAN(local_c8)) && fVar4 < local_c8 != (fVar4 == local_c8)) &&
              (local_c8 < local_b0 + fVar3)) ||
             ((fVar4 = local_c8 - fVar3,
              (!NAN(fVar4) && !NAN(local_b0)) && fVar4 < local_b0 != (fVar4 == local_b0) &&
              (local_b0 < local_c8 + fVar3)))) goto LAB_005c7842;
LAB_005c77d7:
          fVar3 = (float)_DAT_007d5380;
          if (((local_c8 == local_bc) ||
              (((fVar4 = local_bc - fVar3,
                (!NAN(fVar4) && !NAN(local_c8)) && fVar4 < local_c8 != (fVar4 == local_c8) &&
                (local_c8 < local_bc + fVar3)) ||
               ((fVar4 = local_c8 - fVar3,
                (!NAN(fVar4) && !NAN(local_bc)) && fVar4 < local_bc != (fVar4 == local_bc) &&
                (local_bc < local_c8 + fVar3)))))) &&
             ((fVar2 < _DAT_007d652c || ((float)_DAT_007fcb48 < fVar2)))) goto LAB_005c786c;
        }
        *pfVar20 = local_cc;
        pfVar20[1] = local_c8;
        pfVar20[7] = local_c0;
        pfVar20[8] = local_bc;
LAB_005c78b9:
        pfVar20[0xe] = local_b4;
        pfVar20[0xf] = local_b0;
        pfVar20[0x15] = local_a8;
        pfVar20[0x16] = local_a4;
        pfVar20[0x1c] = local_b4;
        pfVar20[0x1d] = local_b0;
      }
      pfVar20[0x23] = local_c0;
      pfVar20[2] = fVar16;
      pfVar20[0x24] = local_bc;
      pfVar20[9] = fVar16;
      pfVar20[0x10] = fVar16;
      pfVar20[3] = 1.0;
      pfVar20[0x17] = fVar16;
      pfVar20[10] = 1.0;
      pfVar20[0x1e] = fVar16;
      pfVar20[0x11] = 1.0;
      pfVar20[0x25] = fVar16;
      pfVar20[0x18] = 1.0;
      local_e0 = local_e0 + 1;
      pfVar20[0x1f] = 1.0;
      pfVar20[0x26] = 1.0;
      DAT_00f0732c = DAT_00f0732c + 0x2a;
      DAT_00f07334 = DAT_00f07334 + 6;
      if (local_54 <= (int)local_e0) {
        return 0;
      }
      pfVar20 = pfVar19 + 0x24;
      pfVar19 = pfVar19 + 0x1e;
      FUN_005bc5b0(*(undefined4 *)(*(int *)*pfVar20 + 4),*(undefined4 *)(*(int *)*pfVar20 + 8));
      FUN_005bbac0();
    } while( true );
  }
  if (local_e8 != 0) {
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
       (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <= DAT_00f07334 + 6
       )) {
      FUN_005c3310(0,0);
      DAT_00f07340 = 4;
    }
    pfVar19 = DAT_00f0732c;
    DAT_00f0732c[4] = fVar1;
    pfVar19[0xb] = fVar1;
    pfVar19[0x12] = fVar1;
    pfVar19[0x19] = fVar1;
    pfVar19[0x20] = fVar1;
    pfVar19[0x27] = fVar1;
    pfVar19[5] = *(float *)(param_7 + 0xc4);
    pfVar19[6] = *(float *)(param_7 + 200);
    pfVar19[0xc] = *(float *)(param_7 + 0xd4);
    pfVar19[0xd] = *(float *)(param_7 + 200);
    pfVar19[0x13] = *(float *)(param_7 + 0xc4);
    pfVar19[0x14] = *(float *)(param_7 + 0xe8);
    pfVar19[0x1a] = *(float *)(param_7 + 0xd4);
    pfVar19[0x1b] = *(float *)(param_7 + 0xe8);
    pfVar19[0x21] = *(float *)(param_7 + 0xc4);
    pfVar19[0x22] = *(float *)(param_7 + 0xe8);
    pfVar19[0x28] = *(float *)(param_7 + 0xd4);
    pfVar19[0x29] = *(float *)(param_7 + 200);
    fVar1 = fVar7 * (*(float *)(param_7 + 0xbc) - local_d0);
    fVar2 = local_ec * (*(float *)(param_7 + 0xc0) - local_d4);
    fVar7 = (*(float *)(param_7 + 0xcc) - local_d0) * fVar7;
    local_ec = (*(float *)(param_7 + 0xd0) - local_d4) * local_ec;
    *pfVar19 = param_3 + fVar1;
    pfVar19[1] = param_4 + fVar2;
    fVar3 = fVar7 + param_3;
    pfVar19[7] = fVar3;
    fVar4 = local_ec + param_4;
    pfVar19[2] = fVar16;
    pfVar19[8] = fVar4;
    pfVar19[9] = fVar16;
    pfVar19[0x10] = fVar16;
    fVar7 = param_3 - fVar7;
    pfVar19[0x17] = fVar16;
    pfVar19[0x1e] = fVar16;
    pfVar19[0x25] = fVar16;
    pfVar19[0xe] = fVar7;
    local_ec = param_4 - local_ec;
    pfVar19[0xf] = local_ec;
    pfVar19[0x15] = param_3 - fVar1;
    pfVar19[0x16] = param_4 - fVar2;
    pfVar19[0x1c] = fVar7;
    pfVar19[0x1d] = local_ec;
    pfVar19[0x23] = fVar3;
    pfVar19[0x24] = fVar4;
    pfVar19[3] = 1.0;
    pfVar19[10] = 1.0;
    pfVar19[0x11] = 1.0;
    pfVar19[0x18] = 1.0;
    pfVar19[0x1f] = 1.0;
    pfVar19[0x26] = 1.0;
    DAT_00f0732c = DAT_00f0732c + 0x2a;
    DAT_00f07334 = DAT_00f07334 + 6;
    return 0;
  }
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
     (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <= DAT_00f07334 + 6))
  {
    FUN_005c3310(0,0);
    DAT_00f07340 = 4;
  }
  pfVar19 = DAT_00f0732c;
  fVar3 = (float)_DAT_00804a60;
  DAT_00f0732c[4] = fVar1;
  pfVar19[0xb] = fVar1;
  pfVar19[0x12] = fVar1;
  pfVar19[0x19] = fVar1;
  pfVar19[0x20] = fVar1;
  pfVar19[0x27] = fVar1;
  pfVar19[5] = *(float *)(param_7 + 0xc4);
  pfVar19[6] = *(float *)(param_7 + 200);
  pfVar19[0xc] = *(float *)(param_7 + 0xd4);
  pfVar19[0xd] = *(float *)(param_7 + 200);
  pfVar19[0x14] = *(float *)(param_7 + 0xe8);
  pfVar19[0x13] = *(float *)(param_7 + 0xc4);
  pfVar19[0x1a] = *(float *)(param_7 + 0xd4);
  pfVar19[0x1b] = *(float *)(param_7 + 0xe8);
  pfVar19[0x21] = *(float *)(param_7 + 0xc4);
  pfVar19[0x22] = *(float *)(param_7 + 0xe8);
  pfVar19[0x28] = *(float *)(param_7 + 0xd4);
  pfVar19[0x29] = *(float *)(param_7 + 200);
  fVar1 = fVar7 * (*(float *)(param_7 + 0xbc) - local_d0);
  fVar2 = (*(float *)(param_7 + 0xc0) - local_d4) * local_ec;
  local_a8 = local_58 * fVar1 - local_50 * fVar2;
  local_a4 = fVar1 * local_50 + fVar2 * local_58;
  fVar7 = fVar7 * (*(float *)(param_7 + 0xcc) - local_d0);
  local_ec = (*(float *)(param_7 + 0xd0) - local_d4) * local_ec;
  local_b4 = fVar7 * local_58 - local_ec * local_50;
  local_b0 = fVar7 * local_50 + local_ec * local_58;
  if (local_20 == 0) {
    if (local_18 == 0) {
      *pfVar19 = param_3 + local_a8;
      pfVar19[1] = param_4 + local_a4;
      local_c0 = local_b4 + param_3;
      pfVar19[7] = local_c0;
      local_bc = local_b0 + param_4;
      pfVar19[8] = local_bc;
      pfVar19[0xe] = param_3 - local_b4;
      pfVar19[0xf] = param_4 - local_b0;
      pfVar19[0x15] = param_3 - local_a8;
      pfVar19[0x16] = param_4 - local_a4;
      pfVar19[0x1c] = param_3 - local_b4;
      pfVar19[0x1d] = param_4 - local_b0;
    }
    else {
      local_cc = param_3 + local_a8;
      local_c8 = param_4 + local_a4;
      local_a8 = param_3 - local_a8;
      local_a4 = param_4 - local_a4;
      local_c0 = local_b4 + param_3;
      local_bc = local_b0 + param_4;
      local_b4 = param_3 - local_b4;
      local_b0 = param_4 - local_b0;
      fVar1 = (float)_DAT_007d5380;
      if ((local_1c != 0) &&
         (((((local_cc == local_b4 ||
             ((local_b4 - fVar1 < local_cc && (local_cc < local_b4 + fVar1)))) ||
            ((local_cc - fVar1 < local_b4 && (local_b4 < local_cc + fVar1)))) ||
           ((local_cc == local_c0 ||
            ((local_c0 - fVar1 < local_cc && (local_cc < local_c0 + fVar1)))))) ||
          ((local_cc - fVar1 < local_c0 && (local_c0 < local_cc + fVar1)))))) {
        local_cc = local_cc - fVar3;
        local_c0 = local_c0 - fVar3;
        local_b4 = local_b4 - fVar3;
        local_a8 = local_a8 - fVar3;
      }
      if ((local_4c != 0) &&
         ((((local_c8 == local_bc ||
            ((local_bc - fVar1 < local_c8 && (local_c8 < local_bc + fVar1)))) ||
           ((local_c8 - fVar1 < local_bc && (local_bc < local_c8 + fVar1)))) ||
          (((local_c8 == local_b0 ||
            ((local_b0 - fVar1 < local_c8 && (local_c8 < local_b0 + fVar1)))) ||
           ((local_c8 - fVar1 < local_b0 && (local_b0 < local_c8 + fVar1)))))))) {
        local_c8 = local_c8 - fVar3;
        local_bc = local_bc - fVar3;
        local_b0 = local_b0 - fVar3;
        local_a4 = local_a4 - fVar3;
      }
      *pfVar19 = local_cc;
      pfVar19[1] = local_c8;
      pfVar19[7] = local_c0;
      pfVar19[8] = local_bc;
      pfVar19[0xe] = local_b4;
      pfVar19[0xf] = local_b0;
      pfVar19[0x15] = local_a8;
      pfVar19[0x16] = local_a4;
      pfVar19[0x1c] = local_b4;
      pfVar19[0x1d] = local_b0;
    }
    goto LAB_005c703a;
  }
  local_cc = param_3 + local_a8;
  local_c8 = param_4 + local_a4;
  local_c0 = local_b4 + param_3;
  local_bc = local_b0 + param_4;
  local_b4 = param_3 - local_b4;
  local_b0 = param_4 - local_b0;
  local_a8 = param_3 - local_a8;
  local_a4 = param_4 - local_a4;
  fVar1 = (float)_DAT_007d5380;
  if (((local_cc == local_b4) || ((local_b4 < local_cc && (local_cc < local_b4 + fVar1)))) ||
     ((local_cc < local_b4 && (local_b4 < local_cc + fVar1)))) {
    local_3c = (double)local_cc;
    iVar18 = FUN_0050e270(local_cc);
    fVar22 = (float10)FUN_00550c30((float)local_3c - (float)iVar18);
    if ((float10)_DAT_007d6530 <= fVar22) {
      fVar1 = (float)_DAT_007d5380;
      goto LAB_005c6a17;
    }
LAB_005c6aa0:
    fVar1 = (float)_DAT_00804a60;
    local_cc = local_cc - fVar1;
    local_c0 = local_c0 - fVar1;
    local_b4 = local_b4 - fVar1;
    local_a8 = local_a8 - fVar1;
    fVar1 = (float)_DAT_007d5380;
  }
  else {
LAB_005c6a17:
    if (((local_cc == local_c0) || ((local_c0 < local_cc && (local_cc < local_c0 + fVar1)))) ||
       ((local_cc < local_c0 && (local_c0 < local_cc + fVar1)))) {
      local_3c = (double)local_cc;
      iVar18 = FUN_0050e270(local_cc);
      fVar22 = (float10)FUN_00550c30((float)local_3c - (float)iVar18);
      if (fVar22 < (float10)_DAT_007d6530) goto LAB_005c6aa0;
      fVar1 = (float)_DAT_007d5380;
    }
  }
  if (((local_c8 == local_b0) || ((local_b0 < local_c8 && (local_c8 < local_b0 + fVar1)))) ||
     ((local_c8 < local_b0 && (local_b0 < local_c8 + fVar1)))) {
    local_3c = (double)local_c8;
    iVar18 = FUN_0050e270(local_c8);
    fVar22 = (float10)FUN_00550c30((float)local_3c - (float)iVar18);
    if ((float10)_DAT_007d6530 <= fVar22) {
      fVar1 = (float)_DAT_007d5380;
      goto LAB_005c6bd2;
    }
LAB_005c6c5d:
    fVar1 = (float)_DAT_00804a60;
    local_c8 = local_c8 - fVar1;
    local_bc = local_bc - fVar1;
    local_b0 = local_b0 - fVar1;
    local_a4 = local_a4 - fVar1;
  }
  else {
LAB_005c6bd2:
    if (((local_c8 == local_bc) || ((local_bc < local_c8 && (local_c8 < local_bc + fVar1)))) ||
       ((local_c8 < local_bc && (local_bc < local_c8 + fVar1)))) {
      local_3c = (double)local_c8;
      iVar18 = FUN_0050e270(local_c8);
      fVar22 = (float10)FUN_00550c30((float)local_3c - (float)iVar18);
      if (fVar22 < (float10)_DAT_007d6530) goto LAB_005c6c5d;
    }
  }
  *pfVar19 = local_cc;
  pfVar19[1] = local_c8;
  pfVar19[7] = local_c0;
  pfVar19[8] = local_bc;
  pfVar19[0xe] = local_b4;
  pfVar19[0xf] = local_b0;
  pfVar19[0x15] = local_a8;
  pfVar19[0x16] = local_a4;
  pfVar19[0x1c] = local_b4;
  pfVar19[0x1d] = local_b0;
LAB_005c703a:
  pfVar19[0x23] = local_c0;
  pfVar19[2] = fVar16;
  pfVar19[9] = fVar16;
  pfVar19[0x24] = local_bc;
  pfVar19[0x10] = fVar16;
  pfVar19[0x17] = fVar16;
  pfVar19[3] = 1.0;
  pfVar19[0x1e] = fVar16;
  pfVar19[10] = 1.0;
  pfVar19[0x25] = fVar16;
  pfVar19[0x11] = 1.0;
  pfVar19[0x18] = 1.0;
  pfVar19[0x1f] = 1.0;
  pfVar19[0x26] = 1.0;
  DAT_00f0732c = DAT_00f0732c + 0x2a;
  DAT_00f07334 = DAT_00f07334 + 6;
  return 0;
}

