
/* WARNING: Removing unreachable block (ram,0x005a2208) */
/* WARNING: Removing unreachable block (ram,0x005a19cd) */
/* WARNING: Removing unreachable block (ram,0x005a1ac6) */
/* WARNING: Removing unreachable block (ram,0x005a1b4d) */
/* WARNING: Removing unreachable block (ram,0x005a1a67) */
/* WARNING: Removing unreachable block (ram,0x005a196e) */
/* WARNING: Removing unreachable block (ram,0x005a1b9c) */
/* WARNING: Removing unreachable block (ram,0x005a2810) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005a0d80(int param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  uint *puVar13;
  int iVar14;
  undefined4 *puVar15;
  int *piVar16;
  uint *puVar17;
  uint local_3b0;
  uint local_3ac;
  int local_3a4;
  uint *local_3a0;
  float local_39c;
  float local_398;
  float local_394;
  float local_390;
  int local_38c;
  float local_384;
  float local_380;
  float local_37c;
  float local_378;
  uint local_374 [23];
  int local_318;
  int local_314;
  int local_310;
  int local_30c;
  int local_308;
  uint local_300 [3];
  undefined2 local_2f4;
  undefined2 local_2f2;
  undefined2 local_2f0;
  short local_2ee [5];
  undefined4 local_2e4;
  undefined2 local_2dc;
  undefined2 local_2da;
  undefined2 local_2d8;
  short local_2d6 [79];
  undefined4 local_238 [46];
  uint local_180 [4];
  short local_16e;
  
  local_3a0 = (uint *)0x0;
  local_374[0] = 0;
  local_374[1] = 0;
  local_374[2] = 0;
  local_374[3] = 0;
  local_374[4] = 0;
  local_374[5] = 0;
  local_374[6] = 0;
  local_374[7] = 0;
  local_374[8] = 0;
  local_374[9] = 0;
  local_374[10] = 0;
  local_374[0xb] = 0;
  local_374[0xc] = 0;
  local_374[0xd] = 0;
  local_374[0xe] = 0;
  local_374[0xf] = 0;
  local_3a4 = 0;
  bVar6 = false;
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if (((DAT_00a37dc8 == 0) || (DAT_00ddb360 != 0)) || (param_4 == 0)) {
    bVar2 = false;
    bVar5 = false;
  }
  else {
    bVar2 = true;
    bVar5 = true;
  }
  if (DAT_00e39a50 != 0) {
    bVar2 = false;
    bVar5 = false;
  }
  puVar17 = local_300 + 2;
  iVar9 = 0x10;
  do {
    *puVar17 = 0;
    puVar17 = puVar17 + 6;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  fVar3 = (float)_DAT_0081ec30;
  local_374[0x14] = 0;
  local_310 = -1;
  local_30c = -1;
  local_308 = -1;
  local_38c = 0;
  if (param_1 != 0) {
    local_3ac = *(uint *)(param_1 + 0x30);
    FUN_0056d420(local_374 + 0x10,param_1,0x34);
    local_3a0 = (uint *)(param_1 + 0x34);
    local_38c = param_2;
    if (param_3 == 0) {
      uVar11 = 0;
      puVar17 = local_3a0;
      if (local_3ac != 0) {
        do {
          local_374[uVar11] = *puVar17;
          uVar11 = uVar11 + 1;
          puVar17 = puVar17 + 6;
        } while (uVar11 < local_3ac);
      }
    }
    else {
      uVar11 = 0;
      if (local_3ac != 0) {
        puVar17 = local_3a0;
        do {
          if ((((DAT_00cc47d0 == 0) || (uVar8 = *puVar17, (int)uVar8 < 0)) ||
              (((uVar8 & 0x7c000000) != DAT_00cc47f8 ||
               ((DAT_00cc4800 <= (int)(uVar8 & 0xffff) ||
                (piVar12 = *(int **)(DAT_00cc47d4 + (uVar8 & 0xffff) * 4), piVar12 == (int *)0x0))))
              )) || ((*piVar12 * 0x10000 != (uVar8 & 0x3ff0000) || (piVar12[4] != 0)))) {
            if (((((DAT_00cc79c0 == 0) || (uVar8 = *puVar17, (int)uVar8 < 0)) ||
                 ((uVar8 & 0x7c000000) != DAT_00cc79e8)) ||
                ((DAT_00cc79f0 <= (int)(uVar8 & 0xffff) ||
                 (piVar12 = *(int **)(DAT_00cc79c4 + (uVar8 & 0xffff) * 4), piVar12 == (int *)0x0)))
                ) || ((*piVar12 * 0x10000 != (uVar8 & 0x3ff0000) || (piVar12[4] != 0)))) {
              local_374[uVar11] = 0;
            }
            else {
              local_374[uVar11] = *(uint *)piVar12[0x114];
            }
          }
          else {
            local_374[uVar11] = **(uint **)piVar12[0x40];
          }
          uVar11 = uVar11 + 1;
          puVar17 = puVar17 + 6;
        } while (uVar11 < local_3ac);
        uVar11 = local_374[0x15];
        goto LAB_005a20d2;
      }
    }
    uVar11 = local_374[0x15];
    goto LAB_005a20d2;
  }
  if ((DAT_00e39a54 == 0) && (DAT_00e39a18 == 0)) {
    if (DAT_00e39a1c == 0) {
      return 0xffffffff;
    }
    if (DAT_00e39a1c == 1) {
      if (DAT_00e39a50 == 0) {
        FUN_005d3a90(0,DAT_00e39a4c);
        FUN_005d3a90(0x101,DAT_00e39a4c);
        DAT_00e796c4 = DAT_00e39a4c;
        DAT_00e39a00 = 1;
        DAT_00e39a1c = 0;
        return 0;
      }
      if (!bVar2) {
        if (DAT_00e39a2c == 0) {
          FUN_005d3a90(0,DAT_00e39a50);
          FUN_005d3a90(0x101,DAT_00e39a50);
          DAT_00e796c4 = DAT_00e39a50;
          FUN_005d3a90(1,DAT_00e39a4c);
          FUN_005d3a90(0x102,DAT_00e39a4c);
          DAT_00e796dc = DAT_00e39a4c;
          FUN_005d3a90(3,DAT_00e39a4c);
          FUN_005d3a90(0x104,DAT_00e39a4c);
          DAT_00e39a00 = 1;
          DAT_00e39a1c = 0;
          _DAT_00e7970c = DAT_00e39a4c;
          return 0;
        }
        if (DAT_00e39a2c == 1) {
          FUN_005d3a90(0,DAT_00e39a50);
          FUN_005d3a90(0x101,DAT_00e39a50);
          DAT_00e796c4 = DAT_00e39a50;
          if (DAT_00e39a04 == 1) {
            FUN_005d3a90(2,DAT_00e39a4c);
            FUN_005d3a90(0x103,DAT_00e39a4c);
            DAT_00e39a00 = 1;
            DAT_00e39a1c = 0;
            DAT_00e796f4 = DAT_00e39a4c;
            return 0;
          }
          FUN_005d3a90(1,DAT_00e39a4c);
          FUN_005d3a90(0x102,DAT_00e39a4c);
          DAT_00e39a00 = 1;
          DAT_00e39a1c = 0;
          DAT_00e796dc = DAT_00e39a4c;
          return 0;
        }
        if (DAT_00e39a2c != 2) {
          DAT_00e39a00 = 1;
          DAT_00e39a1c = 0;
          return 0;
        }
      }
      FUN_005d3a90(0,DAT_00e39a4c);
      FUN_005d3a90(0x101,DAT_00e39a4c);
      DAT_00e796c4 = DAT_00e39a4c;
      FUN_005d3a90(1,DAT_00e39a50);
      FUN_005d3a90(0x102,DAT_00e39a50);
      DAT_00e39a00 = 1;
      DAT_00e39a1c = 0;
      DAT_00e796dc = DAT_00e39a50;
      return 0;
    }
  }
  DAT_00e39a1c = 0;
  DAT_00e39a00 = 1;
  DAT_00e39a18 = 0;
  iVar9 = DAT_00e39a14;
  if (DAT_00e39a14 == 0) {
    if (DAT_00a380c8 != 0) {
      iVar9 = 0xe;
    }
    if (DAT_00e39a4c != 0) {
      if (DAT_00e39a50 == 0) {
LAB_005a127c:
        if (DAT_00e39a04 != 1) goto LAB_005a1282;
      }
      else if (DAT_00e39a2c == 0) {
LAB_005a1274:
        if (DAT_00e39a08 != 1) goto LAB_005a127c;
      }
      else if (DAT_00e39a2c != 1) {
        if (DAT_00e39a2c != 2) goto LAB_005a1282;
        goto LAB_005a1274;
      }
      iVar9 = 1;
    }
  }
  else if ((DAT_00e39a14 == 3) && (DAT_00ddb4bc != 0)) {
    iVar9 = 0x10;
  }
LAB_005a1282:
  iVar7 = iVar9 * 0x1c;
  local_318 = *(int *)(&DAT_007da400 + iVar9 * 0x1c);
  local_374[0x16] = *(int *)(&DAT_007da404 + iVar9 * 0x1c);
  local_314 = *(int *)(&DAT_007da40c + iVar7);
  local_374[0x13] = *(uint *)(&DAT_007da410 + iVar7);
  local_374[0x15] = 0xffffffff;
  if (DAT_00e39a4c != 0) {
    if (DAT_00e39a50 == 0) {
      iVar9 = 0;
    }
    else {
      iVar9 = DAT_00e39a2c + 1;
    }
    iVar14 = 0;
    if ((DAT_00e39a04 == 0) && (DAT_00e39a08 == 0)) {
      if (DAT_00e80b78 == 0) goto LAB_005a1632;
      if (iVar9 == 0) goto LAB_005a1629;
LAB_005a163a:
      iVar7 = *(int *)(&UNK_007da408 + iVar7);
      if (bVar5) {
        local_374[0] = DAT_00e39a4c;
        local_374[1] = DAT_00e39a50;
        local_374[2] = 0;
        local_3ac = 2;
      }
      else {
        local_3a0 = local_300;
        puVar17 = (uint *)(&DAT_007da808 +
                          (iVar14 + (DAT_00e39a28 + (DAT_00e39a24 + (iVar9 + iVar7 * 4) * 2) * 2) *
                                    3) * 0x180);
        puVar13 = local_300;
        for (iVar10 = 0x60; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar13 = *puVar17;
          puVar17 = puVar17 + 1;
          puVar13 = puVar13 + 1;
        }
        local_3ac = local_300[0];
      }
      local_374[2] = 0;
      uVar11 = 0xffffffff;
      DAT_00e7967c = 2;
      DAT_00e39a58 = *(undefined4 *)(&DAT_00e39a64 + DAT_00e79674 * 0xc);
      if (DAT_00e39a2c == 0) {
        DAT_00e7968c = 0;
        if (((DAT_00e39a08 == 1) || (local_374[0x13] == 1)) || (DAT_00e39a04 == 1)) {
          local_374[0x10] = 1;
          local_374[0x11] = 0;
          local_374[0x12] = 5;
        }
        else {
          local_374[0x11] = DAT_00e79694;
          local_374[0x10] = 0;
          local_374[0x12] = DAT_00e79698;
        }
        local_374[0x15] = DAT_00e39a30 << 0x18 | 0xffffff;
        uVar11 = local_374[0x15];
        if (bVar5) {
          local_3a4 = *(int *)(&DAT_00e02e98 +
                              ((uint)(iVar14 == 0) + ((uint)(DAT_00e39a20 != 0) + iVar7 * 2) * 2) *
                              8);
        }
        else {
          local_374[0] = DAT_00e39a50;
          local_374[1] = DAT_00e39a4c;
          local_374[2] = 0;
          if (DAT_00e39a20 != 0) {
            local_2ee[0] = 0;
            local_2ee[1] = 0xffff;
            local_2ee[2] = 2;
            local_2d6[0] = 1;
            local_2d6[1] = 0xffff;
            local_2d6[2] = 2;
            if (local_3ac == 3) {
              local_2d6[0xc] = 1;
              local_2d6[0xd] = 0xffff;
              local_2d6[0xe] = 2;
            }
          }
        }
      }
      else if (DAT_00e39a2c == 1) {
        DAT_00e7968c = (uint)(DAT_00e39a34 == 0xff);
        if (bVar5) {
          local_39c = 0.0;
          local_398 = 0.0;
          local_394 = 0.0;
          local_390 = 0.0;
          bVar6 = true;
          local_3a4 = *(int *)(&DAT_00e02f78 +
                              ((uint)(iVar14 == 0) + ((uint)(DAT_00e39a20 != 0) + iVar7 * 2) * 2) *
                              8);
        }
        else {
          local_374[0] = DAT_00e39a50;
          if (DAT_00e39a04 == 1) {
            local_374[1] = 0;
            local_374[2] = DAT_00e39a4c;
          }
          else {
            local_374[1] = DAT_00e39a4c;
          }
        }
        if (DAT_00e39a38 < 2) {
          local_374[0x10] = 1;
          local_374[0x11] = DAT_00e39a34;
          local_374[0x12] = 7;
          local_374[0x13] = 0;
          if (bVar5) {
            local_390 = 0.0;
            local_394 = 1.0;
          }
          else {
            uVar11 = 0xffffff;
            local_374[0x15] = 0xffffff;
          }
          if (((DAT_00e39a04 != 0) || (DAT_00e39a08 != 0)) && (DAT_00e39a34 == 0)) {
            local_374[0x11] = 1;
          }
LAB_005a1bae:
          if (bVar5) goto LAB_005a1f0c;
        }
        else {
          local_374[0x11] = DAT_00e79694;
          local_374[0x12] = DAT_00e79698;
          local_374[0x10] = 0;
          local_374[0x13] = 1;
          if (DAT_00e39a38 < 0x41) {
            iVar9 = -((DAT_00e39a34 * 0x500) / 0xff);
            iVar7 = iVar9 + 0x500;
            local_2d8 = 6;
            if (iVar7 < 0x400) {
              iVar7 = iVar7 * 0xff;
              uVar8 = -((int)((iVar7 >> 0x1f & 0x3ffU) + iVar7) >> 10) - 1;
              local_374[0x15] = uVar8 * 0x1000000 | 0xffffff;
              local_2f0 = 10;
              uVar11 = local_374[0x15];
              if (bVar5) {
                local_390 = -(float)(uVar8 & 0xff) / fVar3;
                local_394 = _DAT_008298e4;
LAB_005a1baa:
                uVar11 = local_374[0x15];
                goto LAB_005a1bae;
              }
            }
            else {
              iVar9 = (iVar9 + 0x100) * 0x40;
              uVar8 = (int)(iVar9 + (iVar9 >> 0x1f & 0xffU)) >> 8;
              local_374[0x15] = uVar8 << 0x18 | 0xffffff;
              local_2f0 = 7;
              uVar11 = local_374[0x15];
              if (bVar5) {
                local_390 = (float)(uVar8 & 0xff) / fVar3;
                local_394 = _DAT_008298e4;
                goto LAB_005a1baa;
              }
            }
          }
          else if (DAT_00e39a38 < 0x81) {
            iVar9 = -((DAT_00e39a34 * 0x300) / 0xff);
            iVar7 = iVar9 + 0x300;
            local_2d8 = 5;
            if (iVar7 < 0x200) {
              iVar7 = iVar7 * 0xff;
              uVar8 = -((int)((iVar7 >> 0x1f & 0x1ffU) + iVar7) >> 9) - 1;
              local_374[0x15] = uVar8 * 0x1000000 | 0xffffff;
              local_2f0 = 10;
              uVar11 = local_374[0x15];
              if (bVar5) {
                local_390 = -(float)(uVar8 & 0xff) / fVar3;
                local_394 = _DAT_007d103c;
                goto LAB_005a1baa;
              }
            }
            else {
              iVar9 = (iVar9 + 0x100) * 0x80;
              uVar8 = (int)(iVar9 + (iVar9 >> 0x1f & 0xffU)) >> 8;
              local_374[0x15] = uVar8 << 0x18 | 0xffffff;
              local_2f0 = 7;
              uVar11 = local_374[0x15];
              if (bVar5) {
                local_390 = (float)(uVar8 & 0xff) / fVar3;
                local_394 = _DAT_007d103c;
                goto LAB_005a1baa;
              }
            }
          }
          else {
            iVar9 = -((DAT_00e39a34 * 0x200) / 0xff);
            iVar7 = iVar9 + 0x200;
            local_2d8 = 4;
            if (iVar7 < 0x100) {
              iVar7 = iVar7 * 0xff;
              uVar8 = -((int)((iVar7 >> 0x1f & 0xffU) + iVar7) >> 8) - 1;
              local_374[0x15] = uVar8 * 0x1000000 | 0xffffff;
              local_2f0 = 10;
              uVar11 = local_374[0x15];
              if (bVar5) {
                fVar4 = -(float)(uVar8 & 0xff);
LAB_005a1ba2:
                local_390 = fVar4 / fVar3;
                local_394 = 1.0;
                goto LAB_005a1baa;
              }
            }
            else {
              iVar9 = (iVar9 + 0x100) * 0xff;
              uVar8 = (int)(iVar9 + (iVar9 >> 0x1f & 0xffU)) >> 8;
              local_374[0x15] = uVar8 << 0x18 | 0xffffff;
              local_2f0 = 7;
              uVar11 = local_374[0x15];
              if (bVar5) {
                fVar4 = (float)(uVar8 & 0xff);
                goto LAB_005a1ba2;
              }
            }
          }
        }
        if (DAT_00e39a20 != 0) {
          iVar9 = 2 - (uint)(DAT_00e39a04 != 1);
          sVar1 = local_2ee[iVar9 * 0xc];
          if ((sVar1 == 2) && (local_2ee[iVar9 * 0xc + 2] == 2)) {
            local_2ee[iVar9 * 0xc] = 1;
            uVar11 = local_374[0x15];
          }
          else if ((sVar1 == 0x12) && (local_2ee[iVar9 * 0xc + 2] == 2)) {
            local_2ee[iVar9 * 0xc] = 0x11;
            uVar11 = local_374[0x15];
          }
          else if (sVar1 == 2) {
            sVar1 = local_2ee[iVar9 * 0xc + 2];
            if (((sVar1 == 4) || (sVar1 == 5)) || (sVar1 == 6)) {
              local_2ee[iVar9 * 0xc + 2] = 3;
              uVar11 = local_374[0x15];
            }
          }
        }
      }
      else if (DAT_00e39a2c == 2) {
        DAT_00e7968c = 0;
        if (local_374[0x13] != 1) {
          local_374[0x11] = DAT_00e79694;
          local_374[0x12] = DAT_00e79698;
        }
        else {
          local_374[0x11] = 0;
          local_374[0x12] = 5;
        }
        local_374[0x10] = (uint)(local_374[0x13] == 1);
        if (bVar5) {
          local_3a4 = *(int *)(&DAT_00e03058 +
                              ((uint)(iVar14 == 0) + ((uint)(DAT_00e39a20 != 0) + iVar7 * 2) * 2) *
                              8);
        }
        else {
          local_374[0] = DAT_00e39a4c;
          local_374[1] = DAT_00e39a50;
          local_374[2] = 0;
          if (DAT_00e39a20 != 0) {
            local_2ee[0] = 0;
          }
        }
      }
    }
    else {
LAB_005a1629:
      iVar14 = 2 - (uint)(DAT_00e39a04 != 0);
LAB_005a1632:
      if (iVar9 != 0) goto LAB_005a163a;
      DAT_00e7968c = 0;
      DAT_00e7967c = 1;
      DAT_00e39a58 = (&DAT_00e39a60)[DAT_00e79674 * 3];
      if (bVar5) {
        local_3ac = 1;
        local_3a4 = (&DAT_00e02db8)
                    [((uint)(iVar14 == 0) +
                     ((uint)(DAT_00e39a20 != 0) + *(int *)(&UNK_007da408 + iVar7) * 2) * 2) * 2];
      }
      else {
        local_3a0 = (uint *)(&DAT_007da808 +
                            (iVar14 + (DAT_00e39a28 +
                                      (DAT_00e39a24 + *(int *)(&UNK_007da408 + iVar7) * 8) * 2) * 3)
                            * 0x180);
        local_3ac = *local_3a0;
        if (DAT_00e39a20 != 0) {
          FUN_0056d420(local_180,local_3a0,(local_3ac * 3 + 3) * 8);
          if (local_16e == 2) {
            local_16e = 3;
          }
          else if (local_16e == 0x12) {
            local_16e = 0x13;
          }
          local_3a0 = local_180;
        }
      }
      if (DAT_00e39a08 == 1) {
        local_374[0x10] = 1;
        local_374[0x11] = 0x10;
        local_374[0x12] = 5;
      }
      else if ((local_374[0x13] == 1) && (*(int *)(&UNK_007da418 + iVar7) == 1)) {
        local_374[0x10] = 1;
        local_374[0x11] = 0;
        local_374[0x12] = 5;
      }
      else {
        local_374[0x10] = 0;
        local_374[0x11] = DAT_00e79694;
        local_374[0x12] = DAT_00e79698;
      }
      local_374[0] = DAT_00e39a4c;
      uVar11 = local_374[0x15];
    }
    goto LAB_005a1f0c;
  }
  DAT_00e7968c = 0;
  if (bVar5) {
    local_3a4 = (&DAT_00e02d80)[*(int *)(&UNK_007da408 + iVar7) * 2];
    local_3ac = 0;
    goto LAB_005a15b8;
  }
  if (iVar9 == 3) {
    local_3a0 = (uint *)&DAT_007da688;
    local_3ac = 1;
    goto LAB_005a15b8;
  }
  iVar9 = 0;
  local_300[1] = 0;
  local_2e4 = 0;
  local_2dc = 0;
  local_2da = 0;
  local_2d8 = 1;
  local_2d6[0] = 0;
  local_2d6[1] = 0;
  local_2d6[2] = 1;
  local_3ac = 1;
  switch(*(undefined4 *)(&UNK_007da408 + iVar7)) {
  case 0:
    local_2ee[1] = 0;
    local_2ee[2] = 3;
    break;
  case 1:
    local_2ee[1] = 3;
    local_2ee[2] = 0xc;
    break;
  case 2:
    local_2ee[0] = 0x10;
    local_2ee[1] = 0;
    local_2ee[2] = 2;
    goto LAB_005a159d;
  case 3:
    if (((DAT_00cc47d0 != 0) && (iVar7 = FUN_0052ad00(), -1 < iVar7)) &&
       ((uVar11 = FUN_0052ad00(), (uVar11 & 0x7c000000) == DAT_00cc47f8 &&
        (uVar11 = FUN_0052ad00(), (int)(uVar11 & 0xffff) < DAT_00cc4800)))) {
      uVar11 = FUN_0052ad00();
      iVar9 = *(int *)(DAT_00cc47d4 + (uVar11 & 0xffff) * 4);
      if (iVar9 != 0) {
        FUN_0052ad00();
      }
    }
    FUN_0059d430();
    local_374[0] = **(uint **)(*(int *)(iVar9 + 0x4c) + 0x3c);
    goto LAB_005a157a;
  case 4:
    local_2ee[1] = 0x20;
    local_2ee[2] = 4;
    break;
  case 5:
    local_2ee[0] = 0x10;
    local_2ee[1] = 0x20;
    local_2ee[2] = 4;
    goto LAB_005a159d;
  case 6:
    if (((DAT_00cc47d0 != 0) && (iVar7 = FUN_0052ad00(), -1 < iVar7)) &&
       ((uVar11 = FUN_0052ad00(), (uVar11 & 0x7c000000) == DAT_00cc47f8 &&
        (uVar11 = FUN_0052ad00(), (int)(uVar11 & 0xffff) < DAT_00cc4800)))) {
      uVar11 = FUN_0052ad00();
      iVar9 = *(int *)(DAT_00cc47d4 + (uVar11 & 0xffff) * 4);
      if (iVar9 != 0) {
        FUN_0052ad00();
      }
    }
    FUN_0059d430();
    local_374[0] = **(uint **)(*(int *)(iVar9 + 0x4c) + 0x3c);
    local_2dc = 1;
    local_2da = 0;
    local_2d8 = 2;
    local_2d6[0] = 1;
    local_2d6[1] = 0x20;
    local_2d6[2] = 4;
    local_2d6[9] = 0;
    local_2d6[10] = 0;
    local_2d6[0xb] = 1;
    local_2d6[0xc] = 0;
    local_2d6[0xd] = 0;
    local_2d6[0xe] = 1;
    local_3ac = 2;
LAB_005a157a:
    local_2ee[1] = 2;
    local_2ee[2] = 6;
    break;
  default:
    goto switchD_005a1375_default;
  }
  local_2ee[0] = 0;
LAB_005a159d:
  local_2f0 = 3;
  local_2f4 = 0;
  local_2f2 = 0;
switchD_005a1375_default:
  local_3a0 = local_300;
LAB_005a15b8:
  local_374[0x12] = DAT_00e79698;
  local_374[0x11] = DAT_00e79694;
  DAT_00e7967c = 0;
  DAT_00e39a58 = *(undefined4 *)(&DAT_00e39a5c + DAT_00e79674 * 0xc);
  local_374[0x10] = 0;
  uVar11 = local_374[0x15];
LAB_005a1f0c:
  iVar9 = DAT_00e39a54;
  if (local_3ac != DAT_00e796c0) {
    DAT_00e796c0 = local_3ac;
    DAT_00e39a54 = 1;
    FUN_0059b3f0(DAT_00e7984c);
    FUN_0059b300(DAT_00e80500,0xffffffff);
    uVar11 = local_374[0x15];
  }
  if (local_3ac < 0x10) {
    local_3ac = local_3ac + 1;
  }
  if (DAT_00e39a0c != -1) {
    local_374[0x10] = 1;
    local_374[0x12] = DAT_00e39a0c;
    local_374[0x11] = DAT_00e39a10;
  }
  DAT_00e39a54 = iVar9;
  if (0 < DAT_00a38104) {
    uVar11 = 8;
    puVar15 = local_238;
    iVar9 = 0;
    local_3b0 = 3;
    do {
      puVar15[-1] = 0;
      *puVar15 = 0;
      if ((((((DAT_00cc79c0 == 0) || (uVar8 = *(uint *)((int)&DAT_00a380f8 + iVar9), (int)uVar8 < 0)
             ) || ((uVar8 & 0x7c000000) != DAT_00cc79e8)) ||
           ((DAT_00cc79f0 <= (int)(uVar8 & 0xffff) ||
            (piVar12 = *(int **)(DAT_00cc79c4 + (uVar8 & 0xffff) * 4), piVar12 == (int *)0x0)))) ||
          (*piVar12 * 0x10000 != (uVar8 & 0x3ff0000))) || (piVar12[4] != 0)) {
        *(undefined4 *)((int)local_374 + iVar9 + 0x20) = 0;
      }
      else {
        *(undefined4 *)((int)local_374 + iVar9 + 0x20) = *(undefined4 *)piVar12[0x114];
        FUN_0059b0e0(3,3,3,uVar11);
        FUN_0059a650(uVar11,0x11,2);
        FUN_0059a650(uVar11,0x10,2);
        if ((DAT_00f3a04c != 0) && (uVar11 < 0x10)) {
          DAT_00e7984c = 3;
          DAT_00e39a00 = 1;
          if (*(int *)((int)&DAT_00e805e4 + iVar9) != 2) {
            FUN_005d3ad0(uVar11,7,2);
            *(undefined4 *)((int)&DAT_00e805e4 + iVar9) = 2;
          }
        }
        if (local_3ac < uVar11 + 1) {
          local_3ac = uVar11 + 1;
        }
      }
      puVar15 = puVar15 + 6;
      uVar11 = uVar11 + 1;
      iVar9 = iVar9 + 4;
      local_3b0 = local_3b0 + -1;
    } while (local_3b0 != 0);
    uVar11 = local_374[0x15];
  }
LAB_005a20d2:
  if (DAT_00e39a54 == 1) {
    FUN_005d3a70(0x19,local_374[0x12]);
    DAT_00e79698 = local_374[0x12];
    FUN_005d3a70(0x18,local_374[0x11]);
    DAT_00e79694 = local_374[0x11];
    FUN_005d3a70(0xf,local_374[0x10]);
    DAT_00e79690 = local_374[0x10];
    FUN_005d3a70(0x1b,local_374[0x13]);
    DAT_00e7969c = local_374[0x13];
    if (!bVar5) {
      FUN_005d3a70(0x3c,local_374[0x15]);
    }
    DAT_00e796a4 = local_374[0x15];
    if (bVar6) {
      _DAT_00e79850 = local_39c;
      _DAT_00e79854 = local_398;
      _DAT_00e79858 = local_394;
      _DAT_00e7985c = local_390;
    }
    else {
      _DAT_00e7985c = (float)_DAT_0081ec30;
      _DAT_00e79850 = (float)(local_374[0x15] & 0xff) / _DAT_00e7985c;
      _DAT_00e79854 = (float)(local_374[0x15] >> 8 & 0xff) / _DAT_00e7985c;
      _DAT_00e79858 = (float)(local_374[0x15] >> 0x10 & 0xff) / _DAT_00e7985c;
      _DAT_00e7985c = (float)(local_374[0x15] >> 0x18) / _DAT_00e7985c;
    }
    FUN_0059cb80(&DAT_00ddb600,3,0,5,&DAT_00e79850,1,1);
    if (local_374[0x16] == -1) {
      if (1 < DAT_00e796a8) {
        FUN_005d3a70(0x13,DAT_00e796a8);
      }
    }
    else {
      FUN_005d3a70(0x13,local_374[0x16]);
      DAT_00e796a8 = local_374[0x16];
    }
    if (local_318 == -1) {
      if (1 < DAT_00e796ac) {
        FUN_005d3a70(0x14,DAT_00e796ac);
      }
    }
    else {
      FUN_005d3a70(0x14,local_318);
      DAT_00e796ac = local_318;
    }
    if (local_314 == -1) {
      if (1 < DAT_00e796b0) {
        FUN_005d3a70(0xab,DAT_00e796b0);
      }
    }
    else {
      FUN_005d3a70(0xab,local_314);
      DAT_00e796b0 = local_314;
    }
    FUN_005d3a70(0xce,local_374[0x14]);
    DAT_00e796a0 = local_374[0x14];
    if (local_310 == -1) {
      if (1 < DAT_00e796b4) {
        FUN_005d3a70(0xcf,DAT_00e796b4);
      }
    }
    else {
      FUN_005d3a70(0xcf,local_310);
      DAT_00e796b4 = local_310;
    }
    if (local_30c == -1) {
      if (1 < DAT_00e796b8) {
        FUN_005d3a70(0xd0,DAT_00e796b8);
      }
    }
    else {
      FUN_005d3a70(0xd0,local_30c);
      DAT_00e796b8 = local_30c;
    }
    if (local_308 == -1) {
      if (1 < DAT_00e796bc) {
        FUN_005d3a70(0xd1,DAT_00e796bc);
      }
    }
    else {
      FUN_005d3a70(0xd1,local_308);
      DAT_00e796bc = local_308;
    }
    uVar11 = 0;
    piVar16 = &DAT_00e796cc;
    piVar12 = (int *)((~-(uint)bVar5 & (uint)local_3a0) + 8);
    do {
      if (uVar11 < local_3ac) {
        uVar8 = local_374[uVar11];
        FUN_005d3a90(uVar11,uVar8);
        piVar16[-2] = uVar8;
        if (uVar11 < 4) {
          FUN_005d3a90(uVar11 + 0x101,uVar8);
        }
        if (((!bVar5) && (piVar12[-1] != -1)) && (uVar11 < DAT_00ddb4b4)) {
          FUN_005d3ab0(uVar11,0xb,piVar12[-1]);
          piVar16[-1] = piVar12[-1];
        }
      }
      else {
        FUN_005d3a90(uVar11,0);
        piVar16[-2] = 0;
        if (uVar11 < 4) {
          FUN_005d3a90(uVar11 + 0x101,0);
        }
        if ((!bVar5) && (uVar11 < DAT_00ddb4b4)) {
          FUN_005d3ab0(uVar11,0xb,0);
          piVar16[-1] = 0;
        }
      }
      if (local_38c == 0) {
        if (bVar5) {
          if ((uVar11 == 0) &&
             (((DAT_00e80624 != local_3a4 || (DAT_00e39a54 != 0)) && (DAT_00f3a04c != 0)))) {
            FUN_005d3d20(local_3a4);
            DAT_00e80624 = local_3a4;
            DAT_00e80620 = 1;
          }
        }
        else {
          if (((DAT_00e39a54 != 0) || (DAT_00e80624 != 0)) && (DAT_00f3a04c != 0)) {
            if ((DAT_00e39a54 != 0) || (DAT_00e80624 != 0)) {
              FUN_005d3d20(0);
              DAT_00e80624 = 0;
            }
            DAT_00e80620 = 0;
            DAT_00e39a00 = 1;
          }
          if ((uVar11 < local_3ac) && (uVar11 < DAT_00ddb4b4)) {
            if ((DAT_00ddb4b8 != 0) && (*piVar12 != -1)) {
              FUN_005d3ab0(uVar11,0x1c,(*piVar12 != 0) * '\x04' + '\x01');
              *piVar16 = *piVar12;
            }
            if ((short)piVar12[2] != -1) {
              FUN_005d3ab0(uVar11,4,(int)(short)piVar12[2]);
              *(short *)(piVar16 + 2) = (short)piVar12[2];
            }
            if ((short)piVar12[1] != -1) {
              FUN_005d3ab0(uVar11,5,(int)(short)piVar12[1]);
              *(short *)(piVar16 + 1) = (short)piVar12[1];
            }
            if (*(short *)((int)piVar12 + 6) != -1) {
              FUN_005d3ab0(uVar11,6,(int)*(short *)((int)piVar12 + 6));
              *(undefined2 *)((int)piVar16 + 6) = *(undefined2 *)((int)piVar12 + 6);
            }
            if (*(short *)((int)piVar12 + 0xe) != -1) {
              FUN_005d3ab0(uVar11,1,(int)*(short *)((int)piVar12 + 0xe));
              *(undefined2 *)((int)piVar16 + 0xe) = *(undefined2 *)((int)piVar12 + 0xe);
            }
            if (*(short *)((int)piVar12 + 10) != -1) {
              FUN_005d3ab0(uVar11,2,(int)*(short *)((int)piVar12 + 10));
              *(undefined2 *)((int)piVar16 + 10) = *(undefined2 *)((int)piVar12 + 10);
            }
            if ((short)piVar12[3] != -1) {
              FUN_005d3ab0(uVar11,3,(int)(short)piVar12[3]);
              *(short *)(piVar16 + 3) = (short)piVar12[3];
            }
          }
          else {
            if (DAT_00ddb4b8 != 0) {
              FUN_005d3ab0(uVar11,0x1c,1);
              *piVar16 = 0;
            }
            FUN_005d3ab0(uVar11,4,1);
            *(undefined2 *)(piVar16 + 2) = 1;
            FUN_005d3ab0(uVar11,5,0);
            *(undefined2 *)(piVar16 + 1) = 0;
            FUN_005d3ab0(uVar11,6,0);
            *(undefined2 *)((int)piVar16 + 6) = 0;
            FUN_005d3ab0(uVar11,1,1);
            *(undefined2 *)((int)piVar16 + 0xe) = 1;
            FUN_005d3ab0(uVar11,2,0);
            *(undefined2 *)((int)piVar16 + 10) = 0;
            FUN_005d3ab0(uVar11,3,0);
            *(undefined2 *)(piVar16 + 3) = 0;
          }
        }
      }
      uVar11 = uVar11 + 1;
      piVar12 = piVar12 + 6;
      piVar16 = piVar16 + 6;
    } while (uVar11 < 0x10);
    return 0;
  }
  if (local_374[0x12] != DAT_00e79698) {
    FUN_005d3a70(0x19,local_374[0x12]);
    DAT_00e79698 = local_374[0x12];
    uVar11 = local_374[0x15];
  }
  if (local_374[0x11] != DAT_00e79694) {
    FUN_005d3a70(0x18,local_374[0x11]);
    DAT_00e79694 = local_374[0x11];
    uVar11 = local_374[0x15];
  }
  if (local_374[0x10] != DAT_00e79690) {
    FUN_005d3a70(0xf,local_374[0x10]);
    DAT_00e79690 = local_374[0x10];
    uVar11 = local_374[0x15];
  }
  if (local_374[0x13] != DAT_00e7969c) {
    FUN_005d3a70(0x1b,local_374[0x13]);
    DAT_00e7969c = local_374[0x13];
    uVar11 = local_374[0x15];
  }
  if (uVar11 != DAT_00e796a4) {
    if (!bVar5) {
      FUN_005d3a70(0x3c,uVar11);
      uVar11 = local_374[0x15];
    }
    DAT_00e796a4 = uVar11;
  }
  if (bVar6) {
    local_384 = local_39c;
    local_380 = local_398;
    local_37c = local_394;
    local_378 = local_390;
  }
  else {
    local_378 = (float)_DAT_0081ec30;
    local_384 = (float)(local_374[0x15] & 0xff) / local_378;
    local_380 = (float)(uVar11 >> 8 & 0xff) / local_378;
    local_37c = (float)(uVar11 >> 0x10 & 0xff) / local_378;
    local_378 = (float)(uVar11 >> 0x18) / local_378;
  }
  iVar9 = FUN_0056d3d0(&DAT_00e79850,&local_384,0x10);
  if (iVar9 != 0) {
    FUN_0056d420(&DAT_00e79850,&local_384,0x10);
    FUN_0059cb80(&DAT_00ddb600,3,0,5,&local_384,1,1);
  }
  if ((local_374[0x16] != -1) && (local_374[0x16] != DAT_00e796a8)) {
    FUN_005d3a70(0x13,local_374[0x16]);
    DAT_00e796a8 = local_374[0x16];
  }
  if ((local_318 != -1) && (local_318 != DAT_00e796ac)) {
    FUN_005d3a70(0x14,local_318);
    DAT_00e796ac = local_318;
  }
  if ((local_314 != -1) && (local_314 != DAT_00e796b0)) {
    FUN_005d3a70(0xab,local_314);
    DAT_00e796b0 = local_314;
  }
  if (local_374[0x14] != DAT_00e796a0) {
    FUN_005d3a70(0xce,local_374[0x14]);
    DAT_00e796a0 = local_374[0x14];
  }
  if ((local_310 != -1) && (local_310 != DAT_00e796b4)) {
    FUN_005d3a70(0xcf,local_310);
    DAT_00e796b4 = local_310;
  }
  if ((local_30c != -1) && (local_30c != DAT_00e796b8)) {
    FUN_005d3a70(0xd0,local_30c);
    DAT_00e796b8 = local_30c;
  }
  if ((local_308 != -1) && (local_308 != DAT_00e796bc)) {
    FUN_005d3a70(0xd1,local_308);
    DAT_00e796bc = local_308;
  }
  if (DAT_00a38104 == 0) {
    local_3b0 = 2;
  }
  else {
    local_3b0 = local_3ac;
  }
  uVar11 = 0;
  puVar17 = &DAT_00e796c4;
  if (local_3ac != 0) {
    puVar13 = (uint *)((~-(uint)bVar5 & (uint)local_3a0) + 4);
    do {
      if ((local_3b0 <= uVar11) &&
         (((bVar5 || ((uVar11 != 0 && ((short)puVar13[-3] == 1)))) && (local_38c == 0)))) break;
      uVar8 = local_374[uVar11];
      if (uVar8 != *puVar17) {
        FUN_005d3a90(uVar11,uVar8);
        *puVar17 = uVar8;
        if (uVar11 < 4) {
          FUN_005d3a90(uVar11 + 0x101,uVar8);
        }
      }
      if ((((!bVar5) && (uVar8 = *puVar13, uVar8 != 0xffffffff)) && (uVar8 != puVar17[1])) &&
         (uVar11 < DAT_00ddb4b4)) {
        FUN_005d3ab0(uVar11,0xb,uVar8);
        puVar17[1] = *puVar13;
      }
      if (local_38c == 0) {
        if (bVar5) {
          if ((uVar11 == 0) &&
             (((DAT_00e80624 != local_3a4 || (DAT_00e39a54 != 0)) && (DAT_00f3a04c != 0)))) {
            FUN_005d3d20(local_3a4);
            DAT_00e80624 = local_3a4;
            DAT_00e80620 = 1;
          }
        }
        else {
          if (((DAT_00e39a54 != 0) || (DAT_00e80624 != 0)) && (DAT_00f3a04c != 0)) {
            if ((DAT_00e39a54 != 0) || (DAT_00e80624 != 0)) {
              FUN_005d3d20(0);
              DAT_00e80624 = 0;
            }
            DAT_00e80620 = 0;
            DAT_00e39a00 = 1;
          }
          if (uVar11 < DAT_00ddb4b4) {
            if (((DAT_00ddb4b8 != 0) && (uVar8 = puVar13[1], uVar8 != 0xffffffff)) &&
               (uVar8 != puVar17[2])) {
              FUN_005d3ab0(uVar11,0x1c,(uVar8 != 0) * '\x04' + '\x01');
              puVar17[2] = puVar13[1];
            }
            sVar1 = (short)puVar13[3];
            if ((sVar1 != -1) && (sVar1 != (short)puVar17[4])) {
              FUN_005d3ab0(uVar11,4,(int)sVar1);
              *(short *)(puVar17 + 4) = (short)puVar13[3];
            }
            sVar1 = (short)puVar13[2];
            if ((sVar1 != -1) && (sVar1 != (short)puVar17[3])) {
              FUN_005d3ab0(uVar11,5,(int)sVar1);
              *(short *)(puVar17 + 3) = (short)puVar13[2];
            }
            sVar1 = *(short *)((int)puVar13 + 10);
            if ((sVar1 != -1) && (sVar1 != *(short *)((int)puVar17 + 0xe))) {
              FUN_005d3ab0(uVar11,6,(int)sVar1);
              *(undefined2 *)((int)puVar17 + 0xe) = *(undefined2 *)((int)puVar13 + 10);
            }
            sVar1 = *(short *)((int)puVar13 + 0x12);
            if ((sVar1 != -1) && (sVar1 != *(short *)((int)puVar17 + 0x16))) {
              FUN_005d3ab0(uVar11,1,(int)sVar1);
              *(undefined2 *)((int)puVar17 + 0x16) = *(undefined2 *)((int)puVar13 + 0x12);
            }
            sVar1 = *(short *)((int)puVar13 + 0xe);
            if ((sVar1 != -1) && (sVar1 != *(short *)((int)puVar17 + 0x12))) {
              FUN_005d3ab0(uVar11,2,(int)sVar1);
              *(undefined2 *)((int)puVar17 + 0x12) = *(undefined2 *)((int)puVar13 + 0xe);
            }
            sVar1 = (short)puVar13[4];
            if ((sVar1 != -1) && (sVar1 != (short)puVar17[5])) {
              FUN_005d3ab0(uVar11,3,(int)sVar1);
              *(short *)(puVar17 + 5) = (short)puVar13[4];
            }
          }
        }
      }
      uVar11 = uVar11 + 1;
      puVar13 = puVar13 + 6;
      puVar17 = puVar17 + 6;
    } while (uVar11 < local_3ac);
    if (0xf < uVar11) {
      return 0;
    }
  }
  do {
    if (*puVar17 != 0) {
      FUN_005d3a90(uVar11,0);
      *puVar17 = 0;
    }
    if (uVar11 < 4) {
      FUN_005d3a90(uVar11 + 0x101,0);
    }
    uVar11 = uVar11 + 1;
    puVar17 = puVar17 + 6;
  } while (uVar11 < 0x10);
  return 0;
}

