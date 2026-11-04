
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005aaf00(int param_1,int param_2,float param_3,float param_4,double param_5,double param_6,
            int param_7,int param_8,uint param_9,int param_10,int param_11,int param_12)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  undefined4 *puVar6;
  bool bVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  bool bVar14;
  float fVar15;
  float fVar16;
  float *pfVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  float *pfVar21;
  uint uVar22;
  float *pfVar23;
  ushort in_FPUControlWord;
  float10 fVar24;
  float local_ec;
  float local_e0;
  float local_d8;
  float local_cc;
  float local_c8;
  float local_c0;
  float local_bc;
  float local_b4;
  float local_b0;
  float local_a8;
  float local_a4;
  uint local_98;
  float local_50;
  float local_4c;
  int local_48;
  undefined4 local_44;
  uint local_40;
  double local_3c;
  undefined8 local_34;
  float local_2c;
  float local_28;
  int local_24;
  ushort local_20;
  uint local_1c;
  int local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_4c = 0.0;
  local_50 = 1.0;
  local_44 = 0;
  local_40 = 0;
  local_34 = (double)CONCAT44(local_34._4_4_,(float)param_5);
  local_98 = 0;
  if ((DAT_00f3a04c == 0) || ((float)param_5 == 0.0)) {
    return 0xffffffff;
  }
  if (DAT_00e79688 == 0) {
    FUN_0059d430();
  }
  uVar22 = param_9 | 0x8000;
  if (*(char *)(*(int *)(param_7 + 0x4c) + 10) != '\0') {
    uVar22 = param_9 | 0x18000;
  }
  if (*(char *)(*(int *)(param_7 + 0x4c) + 0x12) != '\0') {
    uVar22 = uVar22 | 0x20000;
  }
  if (DAT_00e39a4c != *(int *)**(undefined4 **)(param_7 + 0x100)) {
    FUN_0059bcf0(*(int *)**(undefined4 **)(param_7 + 0x100));
  }
  if (((DAT_00a3d360 != 0) || (DAT_00e39a00 != 0)) || (DAT_00e399fc != uVar22)) {
    FUN_005a7f60();
  }
  if (param_6 != 0.0) {
    FUN_0056d4d0((float)param_6,&local_4c,&local_50);
  }
  fVar1 = DAT_00e79684;
  fVar16 = DAT_00a380b8;
  bVar7 = param_6 == 0.0;
  if ((param_12 == 0) && (DAT_00a380bc != 0)) {
    local_24 = param_12;
    bVar14 = true;
    fVar8 = (float)_DAT_00804a60;
    local_d8 = *(float *)(param_7 + 0x68) * fVar8;
    local_e0 = *(float *)(param_7 + 0x6c) * fVar8;
    param_3 = param_3 - fVar8;
    param_4 = param_4 - fVar8;
LAB_005ab392:
    local_48 = 0;
  }
  else {
    uVar22 = *(uint *)(param_7 + 0x60);
    bVar14 = false;
    local_40 = uVar22 & 0x80000001;
    local_24 = 0;
    if ((int)local_40 < 0) {
      local_40 = (local_40 - 1 | 0xfffffffe) + 1;
    }
    uVar5 = *(uint *)(param_7 + 100);
    local_98 = uVar5 & 0x80000001;
    if ((int)local_98 < 0) {
      local_98 = (local_98 - 1 | 0xfffffffe) + 1;
    }
    fVar8 = (float)param_1;
    fVar3 = param_3 - fVar8;
    fVar2 = (float)param_2;
    param_4 = param_4 - fVar2;
    if (fVar3 < 0.0) {
      fVar3 = -fVar3;
    }
    if (param_4 < 0.0) {
      param_4 = -param_4;
    }
    local_3c = (double)CONCAT44(local_3c._4_4_,param_4);
    param_3 = fVar8;
    if ((_DAT_007d56d8 <= fVar3) || (_DAT_007d56d8 <= param_4)) {
      local_24 = 1;
LAB_005ab252:
      local_d8 = (float)(int)uVar22 * (float)_DAT_00804a60;
      local_e0 = (float)(int)uVar5 * (float)_DAT_00804a60;
LAB_005ab277:
      param_4 = fVar2;
    }
    else {
      if (param_5 != 1.0) {
        bVar14 = true;
        fVar3 = (float)_DAT_00804a60;
        local_d8 = (float)(int)uVar22 * fVar3;
        local_e0 = (float)(int)uVar5 * fVar3;
        param_3 = fVar8 - fVar3;
        fVar2 = fVar2 - fVar3;
        goto LAB_005ab277;
      }
      if (local_40 == local_98) {
        if (local_40 != 0) {
          bVar14 = true;
          goto LAB_005ab252;
        }
        local_d8 = (float)((int)uVar22 >> 1);
        local_e0 = (float)((int)uVar5 >> 1);
        fVar2 = fVar2 - (float)_DAT_00804a60;
        param_3 = fVar8 - (float)_DAT_00804a60;
        goto LAB_005ab277;
      }
      fVar8 = (float)_DAT_00804a60;
      local_d8 = (float)(int)uVar22 * fVar8;
      local_e0 = (float)(int)uVar5 * fVar8;
      if (local_40 == 0) {
        local_d8 = local_d8 - fVar8;
      }
      param_4 = fVar2;
      if (local_98 == 0) {
        local_e0 = local_e0 - fVar8;
      }
    }
    if ((((param_12 != 1) || (local_24 != 0)) || (bVar7)) || ((local_40 != 1 && (local_98 != 1))))
    goto LAB_005ab392;
    if (((((param_6 < _DAT_007fcb98) || (_DAT_007fcb90 < param_6)) ||
         ((_DAT_007fcb98 < param_6 && (param_6 < _DAT_007fcb88)))) ||
        ((_DAT_007fcb80 < param_6 && (param_6 < _DAT_007fcb78)))) ||
       (((_DAT_007fcb70 < param_6 && (param_6 < _DAT_007fcb68)) ||
        ((_DAT_007fcb60 < param_6 && (param_6 < _DAT_007fcb58)))))) {
      local_48 = 1;
    }
    else {
      if ((param_6 <= _DAT_007fcb50) || (_DAT_007fcb90 <= param_6)) goto LAB_005ab392;
      local_48 = 1;
    }
  }
  iVar18 = *(int *)(param_7 + 0x88);
  local_1c = 0;
  if ((param_8 != 0) && (local_1c = (uint)(*(int *)(param_8 + 0x88) != iVar18), param_8 != 0)) {
    local_44 = param_8 + 0x8c;
  }
  if (param_10 == 1) {
    local_ec = _DAT_007d5340;
  }
  else {
    local_ec = 1.0;
  }
  local_ec = (float)local_34 * local_ec;
  fVar8 = _DAT_007d5340;
  if (param_11 != 1) {
    fVar8 = 1.0;
  }
  fVar8 = (float)local_34 * fVar8;
  if (DAT_00e7967c != 1) {
    if (DAT_00e7967c == 2) {
      if ((iVar18 != 1) || (!bVar14)) {
        if (0 < iVar18) {
          pfVar23 = (float *)(local_44 + 0x34);
          pfVar21 = (float *)(param_7 + 0xdc);
          local_48 = iVar18;
          do {
            FUN_0059bcf0(**(undefined4 **)pfVar21[9]);
            puVar6 = (undefined4 *)pfVar23[0x10];
            FUN_0059bd80(*(undefined4 *)*puVar6,puVar6[5],puVar6[6]);
            if (DAT_00e39a1c != 0) {
              FUN_005a0d80(0,0,1,1);
            }
            if (DAT_00dda46c != 0) {
              FUN_00584d70();
            }
            if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
               (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
              if (DAT_00e79678 != 0) {
                FUN_005a7ce0();
                if (DAT_00e79680 == 4) {
                  uVar22 = (int)DAT_00e79678 / 3;
                }
                else if (DAT_00e79680 == 2) {
                  uVar22 = (int)DAT_00e79678 / 2;
                }
                else if (DAT_00e79680 == 6) {
                  uVar22 = DAT_00e79678 - 2;
                }
                else if (DAT_00e79680 == 5) {
                  uVar22 = DAT_00e79678 - 2;
                }
                else if (DAT_00e79680 == 3) {
                  uVar22 = DAT_00e79678 - 1;
                }
                else {
                  uVar22 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
                }
                iVar18 = DAT_00e7967c + DAT_00e79674 * 3;
                FUN_005d3b40(DAT_00e79680,uVar22,*(undefined4 *)(&DAT_00e39a5c + iVar18 * 4),
                             *(undefined4 *)(&DAT_007da3e8 + iVar18 * 4));
                DAT_00a37de4 = DAT_00a37de4 + 1;
              }
              DAT_00e79678 = 0;
              DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
              DAT_00e79674 = 0;
              DAT_00e79680 = 4;
            }
            pfVar17 = DAT_00e39a58;
            DAT_00e39a58[4] = fVar1;
            pfVar17[0x22] = fVar1;
            fVar2 = local_ec * (pfVar21[-8] - local_d8);
            fVar10 = fVar8 * (pfVar21[-7] - local_e0);
            fVar3 = (pfVar21[-4] - local_d8) * local_ec;
            fVar13 = (pfVar21[-3] - local_e0) * fVar8;
            fVar4 = (*pfVar21 - local_d8) * local_ec;
            fVar12 = (pfVar21[1] - local_e0) * fVar8;
            fVar9 = (pfVar21[4] - local_d8) * local_ec;
            fVar11 = (pfVar21[5] - local_e0) * fVar8;
            fVar15 = param_3 + (local_50 * fVar2 - local_4c * fVar10);
            *pfVar17 = fVar15;
            fVar10 = param_4 + fVar2 * local_4c + fVar10 * local_50;
            pfVar17[1] = fVar10;
            fVar2 = (fVar3 * local_50 - fVar13 * local_4c) + param_3;
            pfVar17[10] = fVar2;
            fVar13 = fVar3 * local_4c + fVar13 * local_50 + param_4;
            pfVar17[0xb] = fVar13;
            fVar3 = (fVar4 * local_50 - fVar12 * local_4c) + param_3;
            local_3c = (double)CONCAT44(local_3c._4_4_,fVar3);
            pfVar17[0x14] = fVar3;
            fVar12 = fVar4 * local_4c + fVar12 * local_50 + param_4;
            pfVar17[0x15] = fVar12;
            fVar4 = (fVar9 * local_50 - fVar11 * local_4c) + param_3;
            pfVar17[0x1e] = fVar4;
            fVar9 = fVar11 * local_50 + fVar9 * local_4c + param_4;
            pfVar17[0x1f] = fVar9;
            pfVar17[0x28] = fVar3;
            pfVar17[0x29] = fVar12;
            pfVar17[0x32] = fVar2;
            pfVar17[0x33] = fVar13;
            if (DAT_00a380e8 == 1) {
              pfVar17[6] = _DAT_00e39a44 * ((fVar15 - pfVar23[-1]) - (float)_DAT_00a380e0);
              pfVar17[7] = ((fVar10 - *pfVar23) - (float)_DAT_00a380e4) * _DAT_00e39a48;
              pfVar17[0x10] = ((fVar2 - pfVar23[-1]) - (float)_DAT_00a380e0) * _DAT_00e39a44;
              pfVar17[0x11] = ((fVar13 - *pfVar23) - (float)_DAT_00a380e4) * _DAT_00e39a48;
              pfVar17[0x1a] = ((fVar3 - pfVar23[-1]) - (float)_DAT_00a380e0) * _DAT_00e39a44;
              pfVar17[0x1b] = ((fVar12 - *pfVar23) - (float)_DAT_00a380e4) * _DAT_00e39a48;
              pfVar17[0x24] = _DAT_00e39a44 * ((fVar4 - pfVar23[-1]) - (float)_DAT_00a380e0);
              pfVar17[0x25] = _DAT_00e39a48 * ((fVar9 - *pfVar23) - (float)_DAT_00a380e4);
              pfVar17[0x2e] = _DAT_00e39a44 * ((fVar3 - pfVar23[-1]) - (float)_DAT_00a380e0);
              pfVar17[0x2f] = _DAT_00e39a48 * ((fVar12 - *pfVar23) - (float)_DAT_00a380e4);
              pfVar17[0x38] = _DAT_00e39a44 * ((fVar2 - pfVar23[-1]) - (float)_DAT_00a380e0);
              fVar2 = ((fVar13 - *pfVar23) - (float)_DAT_00a380e4) * _DAT_00e39a48;
            }
            else {
              fVar2 = (float)_DAT_00a380e0;
              fVar3 = _DAT_00e39a44 * (fVar2 + (pfVar21[-8] - pfVar23[-1]));
              fVar4 = ((pfVar21[-4] - pfVar23[-1]) + fVar2) * _DAT_00e39a44;
              local_34 = (double)CONCAT44(fVar4,fVar3);
              local_2c = ((*pfVar21 - pfVar23[-1]) + fVar2) * _DAT_00e39a44;
              local_28 = ((pfVar21[4] - pfVar23[-1]) + fVar2) * _DAT_00e39a44;
              fVar2 = (float)_DAT_00a380e4;
              local_10 = _DAT_00e39a48 * (fVar2 + (pfVar21[-7] - *pfVar23));
              local_c = ((pfVar21[-3] - *pfVar23) + fVar2) * _DAT_00e39a48;
              local_8 = ((pfVar21[1] - *pfVar23) + fVar2) * _DAT_00e39a48;
              local_4 = ((pfVar21[5] - *pfVar23) + fVar2) * _DAT_00e39a48;
              pfVar17[6] = fVar3;
              pfVar17[7] = local_10;
              pfVar17[0x10] = fVar4;
              pfVar17[0x11] = local_c;
              pfVar17[0x1a] = local_2c;
              pfVar17[0x1b] = local_8;
              pfVar17[0x24] = local_28;
              pfVar17[0x25] = local_4;
              pfVar17[0x2e] = local_2c;
              pfVar17[0x2f] = local_8;
              pfVar17[0x38] = fVar4;
              fVar2 = local_c;
            }
            pfVar17[0x39] = fVar2;
            pfVar17[8] = pfVar21[-6];
            pfVar17[9] = pfVar21[-5];
            pfVar17[0x12] = pfVar21[-2];
            pfVar17[0x13] = pfVar21[-5];
            pfVar17[0x1c] = pfVar21[-6];
            pfVar17[0x1d] = pfVar21[3];
            pfVar17[0x26] = pfVar21[-2];
            pfVar17[0x27] = pfVar21[3];
            pfVar17[0x30] = pfVar21[-6];
            pfVar17[0x31] = pfVar21[3];
            pfVar17[0x3a] = pfVar21[-2];
            fVar2 = pfVar21[-5];
            pfVar17[2] = fVar16;
            pfVar17[0x3b] = fVar2;
            pfVar17[0xc] = fVar16;
            pfVar17[0x16] = fVar16;
            pfVar17[0x20] = fVar16;
            pfVar17[0x2a] = fVar16;
            pfVar17[0x34] = fVar16;
            DAT_00e39a58 = DAT_00e39a58 + 0x3c;
            DAT_00e79678 = DAT_00e79678 + 6;
            if (local_1c == 0) {
              pfVar23 = pfVar23 + 0x1e;
            }
            pfVar21 = pfVar21 + 0x1e;
            local_48 = local_48 + -1;
          } while (local_48 != 0);
          return 0;
        }
      }
      else {
        FUN_0059bcf0(*(undefined4 *)**(undefined4 **)(param_7 + 0x100));
        puVar6 = *(undefined4 **)(local_44 + 0x74);
        FUN_0059bd80(*(undefined4 *)*puVar6,puVar6[5],puVar6[6]);
        if (DAT_00e39a1c != 0) {
          FUN_005a0d80(0,0,1,1);
        }
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
           (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
          if (DAT_00e79678 != 0) {
            FUN_005a7ce0();
            if (DAT_00e79680 == 4) {
              uVar22 = (int)DAT_00e79678 / 3;
            }
            else if (DAT_00e79680 == 2) {
              uVar22 = (int)DAT_00e79678 / 2;
            }
            else if (DAT_00e79680 == 6) {
              uVar22 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 5) {
              uVar22 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 3) {
              uVar22 = DAT_00e79678 - 1;
            }
            else {
              uVar22 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
            }
            iVar18 = DAT_00e7967c + DAT_00e79674 * 3;
            FUN_005d3b40(DAT_00e79680,uVar22,*(undefined4 *)(&DAT_00e39a5c + iVar18 * 4),
                         *(undefined4 *)(&DAT_007da3e8 + iVar18 * 4));
            DAT_00a37de4 = DAT_00a37de4 + 1;
          }
          DAT_00e79678 = 0;
          DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
          DAT_00e79674 = 0;
          DAT_00e79680 = 4;
        }
        pfVar21 = DAT_00e39a58;
        DAT_00e39a58[4] = fVar1;
        pfVar21[0x22] = fVar1;
        fVar1 = local_ec * (*(float *)(param_7 + 0xbc) - local_d8);
        fVar2 = fVar8 * (*(float *)(param_7 + 0xc0) - local_e0);
        fVar3 = local_50 * fVar1 - local_4c * fVar2;
        fVar4 = fVar1 * local_4c + fVar2 * local_50;
        local_ec = (*(float *)(param_7 + 0xcc) - local_d8) * local_ec;
        fVar8 = (*(float *)(param_7 + 0xd0) - local_e0) * fVar8;
        fVar2 = local_ec * local_50 - fVar8 * local_4c;
        fVar1 = fVar8 * local_50 + local_ec * local_4c;
        fVar8 = param_3 + fVar3;
        *pfVar21 = fVar8;
        fVar10 = param_4 + fVar4;
        pfVar21[1] = fVar10;
        fVar9 = fVar2 + param_3;
        pfVar21[10] = fVar9;
        fVar11 = fVar1 + param_4;
        pfVar21[0xb] = fVar11;
        fVar2 = param_3 - fVar2;
        pfVar21[0x14] = fVar2;
        fVar1 = param_4 - fVar1;
        pfVar21[0x15] = fVar1;
        param_3 = param_3 - fVar3;
        pfVar21[0x1e] = param_3;
        param_4 = param_4 - fVar4;
        pfVar21[0x1f] = param_4;
        pfVar21[0x28] = fVar2;
        pfVar21[0x29] = fVar1;
        pfVar21[0x32] = fVar9;
        pfVar21[0x33] = fVar11;
        if (DAT_00a380e8 == 1) {
          pfVar21[6] = _DAT_00e39a44 *
                       ((fVar8 - *(float *)(local_44 + 0x30)) - (float)_DAT_00a380e0);
          pfVar21[7] = ((fVar10 - *(float *)(local_44 + 0x34)) - (float)_DAT_00a380e4) *
                       _DAT_00e39a48;
          pfVar21[0x10] =
               ((fVar9 - *(float *)(local_44 + 0x30)) - (float)_DAT_00a380e0) * _DAT_00e39a44;
          pfVar21[0x11] =
               ((fVar11 - *(float *)(local_44 + 0x34)) - (float)_DAT_00a380e4) * _DAT_00e39a48;
          pfVar21[0x1a] =
               ((fVar2 - *(float *)(local_44 + 0x30)) - (float)_DAT_00a380e0) * _DAT_00e39a44;
          pfVar21[0x1b] =
               ((fVar1 - *(float *)(local_44 + 0x34)) - (float)_DAT_00a380e4) * _DAT_00e39a48;
          pfVar21[0x24] =
               _DAT_00e39a44 * ((param_3 - *(float *)(local_44 + 0x30)) - (float)_DAT_00a380e0);
          pfVar21[0x25] =
               _DAT_00e39a48 * ((param_4 - *(float *)(local_44 + 0x34)) - (float)_DAT_00a380e4);
          pfVar21[0x2e] =
               _DAT_00e39a44 * ((fVar2 - *(float *)(local_44 + 0x30)) - (float)_DAT_00a380e0);
          pfVar21[0x2f] =
               _DAT_00e39a48 * ((fVar1 - *(float *)(local_44 + 0x34)) - (float)_DAT_00a380e4);
          pfVar21[0x38] =
               ((fVar9 - *(float *)(local_44 + 0x30)) - (float)_DAT_00a380e0) * _DAT_00e39a44;
          fVar1 = ((fVar11 - *(float *)(local_44 + 0x34)) - (float)_DAT_00a380e4) * _DAT_00e39a48;
        }
        else {
          fVar8 = (*(float *)(param_7 + 0xbc) - *(float *)(local_44 + 0x30)) +
                  (float)_DAT_00a380e0 * _DAT_00e39a44;
          fVar2 = (*(float *)(param_7 + 0xcc) - *(float *)(local_44 + 0x30)) +
                  (float)_DAT_00a380e0 * _DAT_00e39a44;
          fVar1 = (*(float *)(param_7 + 0xc0) - *(float *)(local_44 + 0x34)) +
                  (float)_DAT_00a380e4 * _DAT_00e39a48;
          fVar3 = (*(float *)(param_7 + 0xe0) - *(float *)(local_44 + 0x34)) +
                  (float)_DAT_00a380e4 * _DAT_00e39a48;
          pfVar21[6] = fVar8;
          pfVar21[7] = fVar1;
          pfVar21[0x10] = fVar2;
          pfVar21[0x11] = fVar1;
          pfVar21[0x1a] = fVar8;
          pfVar21[0x1b] = fVar3;
          pfVar21[0x25] = fVar3;
          pfVar21[0x2f] = fVar3;
          pfVar21[0x24] = fVar2;
          pfVar21[0x38] = fVar2;
          pfVar21[0x2e] = fVar8;
        }
        pfVar21[0x39] = fVar1;
        pfVar21[8] = *(float *)(param_7 + 0xc4);
        pfVar21[9] = *(float *)(param_7 + 200);
        pfVar21[0x12] = *(float *)(param_7 + 0xd4);
        pfVar21[0x13] = *(float *)(param_7 + 200);
        pfVar21[0x1c] = *(float *)(param_7 + 0xc4);
        pfVar21[0x1d] = *(float *)(param_7 + 0xe8);
        pfVar21[0x26] = *(float *)(param_7 + 0xd4);
        pfVar21[0x27] = *(float *)(param_7 + 0xe8);
        pfVar21[0x30] = *(float *)(param_7 + 0xc4);
        pfVar21[0x31] = *(float *)(param_7 + 0xe8);
        pfVar21[0x3a] = *(float *)(param_7 + 0xd4);
        fVar1 = *(float *)(param_7 + 200);
        pfVar21[2] = fVar16;
        pfVar21[0x3b] = fVar1;
        pfVar21[0xc] = fVar16;
        pfVar21[0x16] = fVar16;
        pfVar21[0x20] = fVar16;
        pfVar21[0x2a] = fVar16;
        pfVar21[0x34] = fVar16;
        DAT_00e39a58 = DAT_00e39a58 + 0x3c;
        DAT_00e79678 = DAT_00e79678 + 6;
      }
    }
    return 0;
  }
  if ((iVar18 != 1) || (!bVar14)) {
    if (bVar7) {
      iVar20 = 0;
      pfVar21 = (float *)(param_7 + 0xe8);
      while( true ) {
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
           (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
          if (DAT_00e79678 != 0) {
            FUN_005a7ce0();
            if (DAT_00e79680 == 4) {
              uVar22 = (int)DAT_00e79678 / 3;
            }
            else if (DAT_00e79680 == 2) {
              uVar22 = (int)DAT_00e79678 / 2;
            }
            else if (DAT_00e79680 == 6) {
              uVar22 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 5) {
              uVar22 = DAT_00e79678 - 2;
            }
            else if (DAT_00e79680 == 3) {
              uVar22 = DAT_00e79678 - 1;
            }
            else {
              uVar22 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
            }
            iVar19 = DAT_00e7967c + DAT_00e79674 * 3;
            FUN_005d3b40(DAT_00e79680,uVar22,*(undefined4 *)(&DAT_00e39a5c + iVar19 * 4),
                         *(undefined4 *)(&DAT_007da3e8 + iVar19 * 4));
            DAT_00a37de4 = DAT_00a37de4 + 1;
          }
          DAT_00e79678 = 0;
          DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
          DAT_00e79674 = 0;
          DAT_00e79680 = 4;
        }
        pfVar23 = DAT_00e39a58;
        DAT_00e39a58[4] = fVar1;
        pfVar23[0x19] = fVar1;
        pfVar23[5] = pfVar21[-9];
        pfVar23[6] = pfVar21[-8];
        pfVar23[0xc] = pfVar21[-5];
        pfVar23[0xd] = pfVar21[-8];
        pfVar23[0x14] = *pfVar21;
        pfVar23[0x13] = pfVar21[-9];
        pfVar23[0x1a] = pfVar21[-5];
        pfVar23[0x1b] = *pfVar21;
        pfVar23[0x21] = pfVar21[-9];
        pfVar23[0x22] = *pfVar21;
        pfVar23[0x28] = pfVar21[-5];
        pfVar23[0x29] = pfVar21[-8];
        fVar2 = pfVar21[-10];
        fVar11 = (pfVar21[-7] - local_d8) * local_ec + param_3;
        fVar9 = (pfVar21[-6] - local_e0) * fVar8 + param_4;
        fVar12 = (pfVar21[-3] - local_d8) * local_ec + param_3;
        fVar10 = (pfVar21[-2] - local_e0) * fVar8 + param_4;
        fVar3 = pfVar21[1];
        fVar4 = pfVar21[2];
        *pfVar23 = (pfVar21[-0xb] - local_d8) * local_ec + param_3;
        pfVar23[1] = (fVar2 - local_e0) * fVar8 + param_4;
        pfVar23[7] = fVar11;
        pfVar23[8] = fVar9;
        pfVar23[0xe] = fVar12;
        pfVar23[0xf] = fVar10;
        pfVar23[2] = fVar16;
        pfVar23[9] = fVar16;
        pfVar23[0x15] = (fVar3 - local_d8) * local_ec + param_3;
        pfVar23[0x10] = fVar16;
        pfVar23[0x17] = fVar16;
        pfVar23[0x16] = fVar8 * (fVar4 - local_e0) + param_4;
        pfVar23[0x1e] = fVar16;
        pfVar23[0x25] = fVar16;
        pfVar23[0x1c] = fVar12;
        iVar20 = iVar20 + 1;
        pfVar23[0x1d] = fVar10;
        pfVar23[0x23] = fVar11;
        pfVar23[0x24] = fVar9;
        DAT_00e39a58 = DAT_00e39a58 + 0x2a;
        DAT_00e79678 = DAT_00e79678 + 6;
        if (iVar18 <= iVar20) break;
        pfVar23 = pfVar21 + 0x24;
        pfVar21 = pfVar21 + 0x1e;
        FUN_0059bcf0(**(undefined4 **)*pfVar23);
        FUN_005a0d80(0,0,1,1);
      }
      return 0;
    }
    pfVar21 = (float *)(param_7 + 0xe8);
    iVar20 = 0;
    do {
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
         (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
        if (DAT_00e79678 != 0) {
          FUN_005a7ce0();
          if (DAT_00e79680 == 4) {
            uVar22 = (int)DAT_00e79678 / 3;
          }
          else if (DAT_00e79680 == 2) {
            uVar22 = (int)DAT_00e79678 / 2;
          }
          else if (DAT_00e79680 == 6) {
            uVar22 = DAT_00e79678 - 2;
          }
          else if (DAT_00e79680 == 5) {
            uVar22 = DAT_00e79678 - 2;
          }
          else if (DAT_00e79680 == 3) {
            uVar22 = DAT_00e79678 - 1;
          }
          else {
            uVar22 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
          }
          iVar19 = DAT_00e7967c + DAT_00e79674 * 3;
          FUN_005d3b40(DAT_00e79680,uVar22,*(undefined4 *)(&DAT_00e39a5c + iVar19 * 4),
                       *(undefined4 *)(&DAT_007da3e8 + iVar19 * 4));
          DAT_00a37de4 = DAT_00a37de4 + 1;
        }
        DAT_00e79678 = 0;
        DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
        DAT_00e79674 = 0;
        DAT_00e79680 = 4;
      }
      pfVar23 = DAT_00e39a58;
      DAT_00e39a58[4] = fVar1;
      pfVar23[0x19] = fVar1;
      pfVar23[5] = pfVar21[-9];
      pfVar23[6] = pfVar21[-8];
      pfVar23[0xc] = pfVar21[-5];
      pfVar23[0xd] = pfVar21[-8];
      pfVar23[0x13] = pfVar21[-9];
      pfVar23[0x14] = *pfVar21;
      pfVar23[0x1a] = pfVar21[-5];
      pfVar23[0x1b] = *pfVar21;
      pfVar23[0x21] = pfVar21[-9];
      pfVar23[0x22] = *pfVar21;
      pfVar23[0x28] = pfVar21[-5];
      pfVar23[0x29] = pfVar21[-8];
      fVar3 = (pfVar21[-0xb] - local_d8) * local_ec;
      fVar9 = (pfVar21[-10] - local_e0) * fVar8;
      local_c8 = fVar3 * local_4c + fVar9 * local_50;
      fVar2 = (pfVar21[-7] - local_d8) * local_ec;
      fVar4 = (pfVar21[-6] - local_e0) * fVar8;
      local_c0 = fVar2 * local_50 - fVar4 * local_4c;
      local_bc = fVar2 * local_4c + fVar4 * local_50;
      fVar2 = (pfVar21[-3] - local_d8) * local_ec;
      fVar4 = (pfVar21[-2] - local_e0) * fVar8;
      local_b4 = fVar2 * local_50 - fVar4 * local_4c;
      local_b0 = fVar2 * local_4c + fVar4 * local_50;
      fVar2 = (pfVar21[1] - local_d8) * local_ec;
      fVar4 = fVar8 * (pfVar21[2] - local_e0);
      local_a8 = fVar2 * local_50 - fVar4 * local_4c;
      local_a4 = fVar2 * local_4c + fVar4 * local_50;
      local_cc = param_3 + (local_50 * fVar3 - local_4c * fVar9);
      if (local_24 == 0) {
        if (local_48 != 0) {
          local_c8 = param_4 + local_c8;
          local_c0 = local_c0 + param_3;
          local_bc = local_bc + param_4;
          local_b4 = local_b4 + param_3;
          local_b0 = local_b0 + param_4;
          local_a8 = local_a8 + param_3;
          local_a4 = param_4 + local_a4;
          if (local_40 != 0) {
            local_3c = (double)local_cc;
            iVar19 = FUN_0050e270(local_cc);
            fVar24 = (float10)FUN_00550c30((float)local_3c - (float)iVar19);
            fVar2 = (float)fVar24;
            if (local_cc == local_b4) {
LAB_005ad5d5:
              if ((_DAT_007d652c <= fVar2) && (fVar2 <= (float)_DAT_007fcb48)) goto LAB_005ad57e;
            }
            else {
              fVar3 = (float)_DAT_007d5380;
              fVar4 = local_b4 - fVar3;
              if ((((!NAN(fVar4) && !NAN(local_cc)) && fVar4 < local_cc != (fVar4 == local_cc)) &&
                  (local_cc < local_b4 + fVar3)) ||
                 ((fVar4 = local_cc - fVar3,
                  (!NAN(fVar4) && !NAN(local_b4)) && fVar4 < local_b4 != (fVar4 == local_b4) &&
                  (local_b4 < local_cc + fVar3)))) goto LAB_005ad5d5;
LAB_005ad57e:
              fVar3 = (float)_DAT_007d5380;
              if (((local_cc != local_c0) &&
                  (((fVar4 = local_c0 - fVar3,
                    (NAN(fVar4) || NAN(local_cc)) || fVar4 < local_cc == (fVar4 == local_cc) ||
                    (local_c0 + fVar3 <= local_cc)) &&
                   ((fVar4 = local_cc - fVar3,
                    (NAN(fVar4) || NAN(local_c0)) || fVar4 < local_c0 == (fVar4 == local_c0) ||
                    (local_cc + fVar3 <= local_c0)))))) ||
                 ((_DAT_007d652c <= fVar2 && (fVar2 <= (float)_DAT_007fcb48)))) goto LAB_005ad631;
            }
            fVar2 = (float)_DAT_00804a60;
            local_cc = local_cc - fVar2;
            local_c0 = local_c0 - fVar2;
            local_b4 = local_b4 - fVar2;
            local_a8 = local_a8 - fVar2;
          }
LAB_005ad631:
          if (local_98 != 0) {
            local_3c = (double)local_c8;
            iVar19 = FUN_0050e270(local_c8);
            fVar24 = (float10)FUN_00550c30((float)local_3c - (float)iVar19);
            fVar2 = (float)fVar24;
            if (local_c8 == local_b0) {
LAB_005ad774:
              if ((_DAT_007d652c <= fVar2) && (fVar2 <= (float)_DAT_007fcb48)) goto LAB_005ad6e0;
            }
            else {
              fVar4 = (float)_DAT_007d5380;
              fVar3 = local_b0 - fVar4;
              if ((((!NAN(fVar3) && !NAN(local_c8)) && fVar3 < local_c8 != (fVar3 == local_c8)) &&
                  (local_c8 < local_b0 + fVar4)) ||
                 ((fVar3 = local_c8 - fVar4,
                  (!NAN(fVar3) && !NAN(local_b0)) && fVar3 < local_b0 != (fVar3 == local_b0) &&
                  (local_b0 < local_c8 + fVar4)))) goto LAB_005ad774;
LAB_005ad6e0:
              fVar3 = (float)_DAT_007d5380;
              if (((local_c8 != local_bc) &&
                  (((fVar4 = local_bc - fVar3,
                    (NAN(fVar4) || NAN(local_c8)) || fVar4 < local_c8 == (fVar4 == local_c8) ||
                    (local_bc + fVar3 <= local_c8)) &&
                   ((fVar4 = local_c8 - fVar3,
                    (NAN(fVar4) || NAN(local_bc)) || fVar4 < local_bc == (fVar4 == local_bc) ||
                    (local_c8 + fVar3 <= local_bc)))))) ||
                 ((_DAT_007d652c <= fVar2 && (fVar2 <= (float)_DAT_007fcb48)))) goto LAB_005ad7ee;
            }
            fVar2 = (float)_DAT_00804a60;
            local_c8 = local_c8 - fVar2;
            local_bc = local_bc - fVar2;
            local_b0 = local_b0 - fVar2;
            local_a4 = local_a4 - fVar2;
          }
LAB_005ad7ee:
          *pfVar23 = local_cc;
          pfVar23[1] = local_c8;
          pfVar23[7] = local_c0;
          pfVar23[8] = local_bc;
          goto LAB_005ad410;
        }
        *pfVar23 = local_cc;
        pfVar23[1] = param_4 + local_c8;
        local_c0 = local_c0 + param_3;
        pfVar23[7] = local_c0;
        local_bc = local_bc + param_4;
        pfVar23[8] = local_bc;
        local_b4 = local_b4 + param_3;
        local_3c = (double)CONCAT44(local_3c._4_4_,local_b4);
        pfVar23[0xe] = local_b4;
        pfVar23[0xf] = local_b0 + param_4;
        pfVar23[0x15] = local_a8 + param_3;
        pfVar23[0x16] = local_a4 + param_4;
        pfVar23[0x1c] = local_b4;
        pfVar23[0x1d] = local_b0 + param_4;
      }
      else {
        local_c8 = param_4 + local_c8;
        local_c0 = local_c0 + param_3;
        local_bc = local_bc + param_4;
        local_b4 = local_b4 + param_3;
        local_b0 = local_b0 + param_4;
        local_a8 = local_a8 + param_3;
        local_a4 = param_4 + local_a4;
        local_20 = in_FPUControlWord | 0xc00;
        local_14 = (int)ROUND(local_cc);
        fVar2 = local_cc - (float)local_14;
        if (fVar2 < 0.0) {
          fVar2 = -fVar2;
        }
        if (local_cc == local_b4) {
LAB_005ad204:
          if ((_DAT_007d652c <= fVar2) && (fVar2 <= (float)_DAT_007fcb48)) goto LAB_005ad1b2;
LAB_005ad22a:
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
              (local_b4 < local_cc + fVar3)))) goto LAB_005ad204;
LAB_005ad1b2:
          fVar3 = (float)_DAT_007d5380;
          if (((local_cc == local_c0) ||
              (((fVar4 = local_c0 - fVar3,
                (!NAN(fVar4) && !NAN(local_cc)) && fVar4 < local_cc != (fVar4 == local_cc) &&
                (local_cc < local_c0 + fVar3)) ||
               ((fVar4 = local_cc - fVar3,
                (!NAN(fVar4) && !NAN(local_c0)) && fVar4 < local_c0 != (fVar4 == local_c0) &&
                (local_c0 < local_cc + fVar3)))))) &&
             ((fVar2 < _DAT_007d652c || ((float)_DAT_007fcb48 < fVar2)))) goto LAB_005ad22a;
        }
        local_1c = CONCAT22(local_1c._2_2_,in_FPUControlWord);
        local_44 = CONCAT22(local_44._2_2_,in_FPUControlWord) | 0xc00;
        local_34 = (double)CONCAT44(local_34._4_4_,(int)ROUND(local_c8));
        fVar2 = local_c8 - (float)(int)ROUND(local_c8);
        if (fVar2 < 0.0) {
          fVar2 = -fVar2;
        }
        if (local_c8 == local_b0) {
LAB_005ad399:
          if ((_DAT_007d652c <= fVar2) && (fVar2 <= (float)_DAT_007fcb48)) goto LAB_005ad32e;
LAB_005ad3c3:
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
              (local_b0 < local_c8 + fVar3)))) goto LAB_005ad399;
LAB_005ad32e:
          fVar3 = (float)_DAT_007d5380;
          if (((local_c8 == local_bc) ||
              (((fVar4 = local_bc - fVar3,
                (!NAN(fVar4) && !NAN(local_c8)) && fVar4 < local_c8 != (fVar4 == local_c8) &&
                (local_c8 < local_bc + fVar3)) ||
               ((fVar4 = local_c8 - fVar3,
                (!NAN(fVar4) && !NAN(local_bc)) && fVar4 < local_bc != (fVar4 == local_bc) &&
                (local_bc < local_c8 + fVar3)))))) &&
             ((fVar2 < _DAT_007d652c || ((float)_DAT_007fcb48 < fVar2)))) goto LAB_005ad3c3;
        }
        *pfVar23 = local_cc;
        pfVar23[1] = local_c8;
        pfVar23[7] = local_c0;
        pfVar23[8] = local_bc;
LAB_005ad410:
        pfVar23[0xe] = local_b4;
        pfVar23[0xf] = local_b0;
        pfVar23[0x15] = local_a8;
        pfVar23[0x16] = local_a4;
        pfVar23[0x1c] = local_b4;
        pfVar23[0x1d] = local_b0;
      }
      pfVar23[0x23] = local_c0;
      pfVar23[2] = fVar16;
      pfVar23[9] = fVar16;
      pfVar23[0x24] = local_bc;
      pfVar23[0x10] = fVar16;
      pfVar23[0x17] = fVar16;
      pfVar23[0x1e] = fVar16;
      pfVar23[0x25] = fVar16;
      DAT_00e39a58 = DAT_00e39a58 + 0x2a;
      DAT_00e79678 = DAT_00e79678 + 6;
      iVar20 = iVar20 + 1;
      if (iVar18 <= iVar20) {
        return 0;
      }
      pfVar23 = pfVar21 + 0x24;
      pfVar21 = pfVar21 + 0x1e;
      FUN_0059bcf0(**(undefined4 **)*pfVar23);
      FUN_005a0d80(0,0,1,1);
    } while( true );
  }
  if (bVar7) {
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
       (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
      if (DAT_00e79678 != 0) {
        FUN_005a7ce0();
        if (DAT_00e79680 == 4) {
          uVar22 = (int)DAT_00e79678 / 3;
        }
        else if (DAT_00e79680 == 2) {
          uVar22 = (int)DAT_00e79678 / 2;
        }
        else if ((DAT_00e79680 == 6) || (DAT_00e79680 == 5)) {
          uVar22 = DAT_00e79678 - 2;
        }
        else if (DAT_00e79680 == 3) {
          uVar22 = DAT_00e79678 - 1;
        }
        else {
          uVar22 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
        }
        iVar18 = DAT_00e7967c + DAT_00e79674 * 3;
        FUN_005d3b40(DAT_00e79680,uVar22,*(undefined4 *)(&DAT_00e39a5c + iVar18 * 4),
                     *(undefined4 *)(&DAT_007da3e8 + iVar18 * 4));
        DAT_00a37de4 = DAT_00a37de4 + 1;
      }
      DAT_00e79678 = 0;
      DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
      DAT_00e79674 = 0;
      DAT_00e79680 = 4;
    }
    pfVar21 = DAT_00e39a58;
    DAT_00e39a58[4] = fVar1;
    pfVar21[0x19] = fVar1;
    pfVar21[5] = *(float *)(param_7 + 0xc4);
    pfVar21[6] = *(float *)(param_7 + 200);
    pfVar21[0xc] = *(float *)(param_7 + 0xd4);
    pfVar21[0xd] = *(float *)(param_7 + 200);
    pfVar21[0x13] = *(float *)(param_7 + 0xc4);
    pfVar21[0x14] = *(float *)(param_7 + 0xe8);
    pfVar21[0x1a] = *(float *)(param_7 + 0xd4);
    pfVar21[0x1b] = *(float *)(param_7 + 0xe8);
    pfVar21[0x21] = *(float *)(param_7 + 0xc4);
    pfVar21[0x22] = *(float *)(param_7 + 0xe8);
    pfVar21[0x28] = *(float *)(param_7 + 0xd4);
    pfVar21[0x29] = *(float *)(param_7 + 200);
    fVar1 = local_ec * (*(float *)(param_7 + 0xbc) - local_d8);
    fVar2 = fVar8 * (*(float *)(param_7 + 0xc0) - local_e0);
    local_ec = (*(float *)(param_7 + 0xcc) - local_d8) * local_ec;
    fVar8 = (*(float *)(param_7 + 0xd0) - local_e0) * fVar8;
    *pfVar21 = param_3 + fVar1;
    pfVar21[1] = param_4 + fVar2;
    fVar3 = local_ec + param_3;
    pfVar21[7] = fVar3;
    fVar4 = fVar8 + param_4;
    pfVar21[8] = fVar4;
    local_ec = param_3 - local_ec;
    pfVar21[2] = fVar16;
    pfVar21[9] = fVar16;
    pfVar21[0x10] = fVar16;
    pfVar21[0x17] = fVar16;
    pfVar21[0xe] = local_ec;
    pfVar21[0x1e] = fVar16;
    pfVar21[0x25] = fVar16;
    fVar8 = param_4 - fVar8;
    pfVar21[0xf] = fVar8;
    pfVar21[0x15] = param_3 - fVar1;
    pfVar21[0x16] = param_4 - fVar2;
    pfVar21[0x1c] = local_ec;
    pfVar21[0x1d] = fVar8;
    pfVar21[0x23] = fVar3;
    pfVar21[0x24] = fVar4;
    DAT_00e39a58 = DAT_00e39a58 + 0x2a;
    DAT_00e79678 = DAT_00e79678 + 6;
    return 0;
  }
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  fVar2 = (float)_DAT_00804a60;
  if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
     (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
    if (DAT_00e79678 != 0) {
      FUN_005a7ce0();
      if (DAT_00e79680 == 4) {
        uVar22 = (int)DAT_00e79678 / 3;
      }
      else if (DAT_00e79680 == 2) {
        uVar22 = (int)DAT_00e79678 / 2;
      }
      else if (DAT_00e79680 == 6) {
        uVar22 = DAT_00e79678 - 2;
      }
      else if (DAT_00e79680 == 5) {
        uVar22 = DAT_00e79678 - 2;
      }
      else if (DAT_00e79680 == 3) {
        uVar22 = DAT_00e79678 - 1;
      }
      else {
        uVar22 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
      }
      iVar18 = DAT_00e7967c + DAT_00e79674 * 3;
      FUN_005d3b40(DAT_00e79680,uVar22,*(undefined4 *)(&DAT_00e39a5c + iVar18 * 4),
                   *(undefined4 *)(&DAT_007da3e8 + iVar18 * 4));
      fVar2 = (float)_DAT_00804a60;
      DAT_00a37de4 = DAT_00a37de4 + 1;
    }
    DAT_00e79678 = 0;
    DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
    DAT_00e79674 = 0;
    DAT_00e79680 = 4;
  }
  pfVar21 = DAT_00e39a58;
  DAT_00e39a58[4] = fVar1;
  pfVar21[0x19] = fVar1;
  pfVar21[5] = *(float *)(param_7 + 0xc4);
  pfVar21[6] = *(float *)(param_7 + 200);
  pfVar21[0xc] = *(float *)(param_7 + 0xd4);
  pfVar21[0xd] = *(float *)(param_7 + 200);
  pfVar21[0x14] = *(float *)(param_7 + 0xe8);
  pfVar21[0x13] = *(float *)(param_7 + 0xc4);
  pfVar21[0x1a] = *(float *)(param_7 + 0xd4);
  pfVar21[0x1b] = *(float *)(param_7 + 0xe8);
  pfVar21[0x21] = *(float *)(param_7 + 0xc4);
  pfVar21[0x22] = *(float *)(param_7 + 0xe8);
  pfVar21[0x28] = *(float *)(param_7 + 0xd4);
  pfVar21[0x29] = *(float *)(param_7 + 200);
  fVar1 = local_ec * (*(float *)(param_7 + 0xbc) - local_d8);
  fVar3 = (*(float *)(param_7 + 0xc0) - local_e0) * fVar8;
  local_a8 = local_50 * fVar1 - local_4c * fVar3;
  local_a4 = fVar1 * local_4c + fVar3 * local_50;
  local_ec = (*(float *)(param_7 + 0xcc) - local_d8) * local_ec;
  fVar8 = (*(float *)(param_7 + 0xd0) - local_e0) * fVar8;
  local_b4 = local_ec * local_50 - fVar8 * local_4c;
  local_b0 = fVar8 * local_50 + local_ec * local_4c;
  if (local_24 == 0) {
    if (local_48 == 0) {
      *pfVar21 = param_3 + local_a8;
      pfVar21[1] = param_4 + local_a4;
      local_c0 = local_b4 + param_3;
      pfVar21[7] = local_c0;
      local_bc = local_b0 + param_4;
      pfVar21[8] = local_bc;
      local_b4 = param_3 - local_b4;
      pfVar21[0xe] = local_b4;
      local_b0 = param_4 - local_b0;
      pfVar21[0xf] = local_b0;
      pfVar21[0x15] = param_3 - local_a8;
      pfVar21[0x16] = param_4 - local_a4;
    }
    else {
      fVar1 = param_3 + local_a8;
      local_c8 = param_4 + local_a4;
      local_a8 = param_3 - local_a8;
      local_a4 = param_4 - local_a4;
      local_c0 = local_b4 + param_3;
      local_bc = local_b0 + param_4;
      local_b4 = param_3 - local_b4;
      local_b0 = param_4 - local_b0;
      fVar8 = (float)_DAT_007d5380;
      if ((local_40 != 0) &&
         (((((fVar1 == local_b4 || ((local_b4 - fVar8 < fVar1 && (fVar1 < local_b4 + fVar8)))) ||
            ((fVar1 - fVar8 < local_b4 && (local_b4 < fVar1 + fVar8)))) ||
           ((fVar1 == local_c0 || ((local_c0 - fVar8 < fVar1 && (fVar1 < local_c0 + fVar8)))))) ||
          ((fVar1 - fVar8 < local_c0 && (local_c0 < fVar1 + fVar8)))))) {
        fVar1 = fVar1 - fVar2;
        local_c0 = local_c0 - fVar2;
        local_b4 = local_b4 - fVar2;
        local_a8 = local_a8 - fVar2;
      }
      if ((local_98 != 0) &&
         ((((local_c8 == local_bc ||
            ((local_bc - fVar8 < local_c8 && (local_c8 < local_bc + fVar8)))) ||
           ((local_c8 - fVar8 < local_bc && (local_bc < local_c8 + fVar8)))) ||
          (((local_c8 == local_b0 ||
            ((local_b0 - fVar8 < local_c8 && (local_c8 < local_b0 + fVar8)))) ||
           ((local_c8 - fVar8 < local_b0 && (local_b0 < local_c8 + fVar8)))))))) {
        local_c8 = local_c8 - fVar2;
        local_bc = local_bc - fVar2;
        local_b0 = local_b0 - fVar2;
        local_a4 = local_a4 - fVar2;
      }
      *pfVar21 = fVar1;
      pfVar21[1] = local_c8;
      pfVar21[7] = local_c0;
      pfVar21[8] = local_bc;
      pfVar21[0xe] = local_b4;
      pfVar21[0xf] = local_b0;
      pfVar21[0x15] = local_a8;
      pfVar21[0x16] = local_a4;
    }
    pfVar21[0x1c] = local_b4;
    pfVar21[0x1d] = local_b0;
    goto LAB_005aca52;
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
    local_34 = (double)local_cc;
    iVar18 = FUN_0050e270(local_cc);
    fVar24 = (float10)FUN_00550c30((float)local_34 - (float)iVar18);
    if ((float10)_DAT_007d6530 <= fVar24) {
      fVar1 = (float)_DAT_007d5380;
      goto LAB_005ac49f;
    }
LAB_005ac526:
    fVar1 = (float)_DAT_00804a60;
    local_cc = local_cc - fVar1;
    local_c0 = local_c0 - fVar1;
    local_b4 = local_b4 - fVar1;
    local_a8 = local_a8 - fVar1;
    fVar1 = (float)_DAT_007d5380;
  }
  else {
LAB_005ac49f:
    if (((local_cc == local_c0) || ((local_c0 < local_cc && (local_cc < local_c0 + fVar1)))) ||
       ((local_cc < local_c0 && (local_c0 < local_cc + fVar1)))) {
      local_34 = (double)local_cc;
      iVar18 = FUN_0050e270(local_cc);
      fVar24 = (float10)FUN_00550c30((float)local_34 - (float)iVar18);
      if (fVar24 < (float10)_DAT_007d6530) goto LAB_005ac526;
      fVar1 = (float)_DAT_007d5380;
    }
  }
  if (((local_c8 == local_b0) || ((local_b0 < local_c8 && (local_c8 < local_b0 + fVar1)))) ||
     ((local_c8 < local_b0 && (local_b0 < local_c8 + fVar1)))) {
    local_34 = (double)local_c8;
    iVar18 = FUN_0050e270(local_c8);
    fVar24 = (float10)FUN_00550c30((float)local_34 - (float)iVar18);
    if ((float10)_DAT_007d6530 <= fVar24) {
      fVar1 = (float)_DAT_007d5380;
      goto LAB_005ac615;
    }
LAB_005ac69e:
    fVar1 = (float)_DAT_00804a60;
    local_c8 = local_c8 - fVar1;
    local_bc = local_bc - fVar1;
    local_b0 = local_b0 - fVar1;
    local_a4 = local_a4 - fVar1;
  }
  else {
LAB_005ac615:
    if (((local_c8 == local_bc) || ((local_bc < local_c8 && (local_c8 < local_bc + fVar1)))) ||
       ((local_c8 < local_bc && (local_bc < local_c8 + fVar1)))) {
      local_34 = (double)local_c8;
      iVar18 = FUN_0050e270(local_c8);
      fVar24 = (float10)FUN_00550c30((float)local_34 - (float)iVar18);
      if (fVar24 < (float10)_DAT_007d6530) goto LAB_005ac69e;
    }
  }
  *pfVar21 = local_cc;
  pfVar21[1] = local_c8;
  pfVar21[7] = local_c0;
  pfVar21[8] = local_bc;
  pfVar21[0xe] = local_b4;
  pfVar21[0xf] = local_b0;
  pfVar21[0x15] = local_a8;
  pfVar21[0x16] = local_a4;
  pfVar21[0x1c] = local_b4;
  pfVar21[0x1d] = local_b0;
LAB_005aca52:
  pfVar21[0x23] = local_c0;
  pfVar21[2] = fVar16;
  pfVar21[9] = fVar16;
  pfVar21[0x10] = fVar16;
  pfVar21[0x24] = local_bc;
  pfVar21[0x17] = fVar16;
  pfVar21[0x1e] = fVar16;
  pfVar21[0x25] = fVar16;
  DAT_00e39a58 = DAT_00e39a58 + 0x2a;
  DAT_00e79678 = DAT_00e79678 + 6;
  return 0;
}

