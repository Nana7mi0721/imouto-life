
undefined4 FUN_005e88a0(uint param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  char cVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  short *psVar10;
  uint uVar11;
  int iVar12;
  short *psVar13;
  int *local_168;
  int *local_164;
  int *local_160;
  int *local_15c;
  int *local_158;
  int local_154;
  undefined4 local_150;
  int *local_14c;
  int *local_148;
  int *local_144;
  char local_140;
  char local_13f;
  char local_13e;
  char local_13d;
  int *local_13c;
  int local_138;
  int *local_134;
  int *local_130;
  int *local_12c;
  int local_128;
  int local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  int local_114;
  undefined4 local_110;
  undefined4 local_10c;
  int local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  int local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  int local_d8 [54];
  
  if ((((DAT_00cc6b10 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc6b38)) ||
     (((DAT_00cc6b40 <= (int)(param_1 & 0xffff) ||
       (piVar3 = *(int **)(DAT_00cc6b14 + (param_1 & 0xffff) * 4), piVar3 == (int *)0x0)) ||
      ((*piVar3 * 0x10000 != (param_1 & 0x3ff0000) || (piVar3[4] != 0)))))) {
    return 0xffffffff;
  }
  if (piVar3[0x78] != 0) {
    return 0;
  }
  piVar3[0x11b] = param_2;
  local_148 = piVar3;
  FUN_0056d380(piVar3 + 0xaf,0,0xd8);
  FUN_0056d380(piVar3 + 0xe5,0,0xd8);
  FUN_0056d380(piVar3 + 0x79,0,0xd8);
  piVar3[0x77] = 0;
  FUN_0056d380(local_d8,0,0xd8);
  piVar8 = (int *)piVar3[0x4a];
  local_124 = 0;
  if (0 < piVar3[0x49]) {
    do {
      switch((short)piVar8[1]) {
      case 0:
        uVar11 = (uint)(piVar3[0x11] != 0);
        break;
      case 1:
        uVar11 = 1;
        break;
      case 2:
        uVar11 = 2;
        break;
      case 3:
        uVar11 = 0;
        break;
      default:
        goto switchD_005e89bd_default;
      }
      local_154 = piVar8[3];
      local_150 = (int *)((uint)*(ushort *)(piVar8 + 0x46) + (uint)*(ushort *)(piVar8 + 0x44));
      if (piVar3[0x11] != 0) {
        local_154 = piVar8[0x48] * local_154;
        local_150 = (int *)(piVar8[0x48] * (int)local_150);
      }
      iVar9 = ((uint)(*(int *)(*(int *)(*piVar8 + 4) + 0x168) != 0) + uVar11 * 2) * 9;
      piVar1 = local_d8 + iVar9 + 2;
      if (local_d8[iVar9 + 2] == 0) {
        piVar3[0x77] = piVar3[0x77] + 1;
        piVar3[iVar9 + 0x7b] = piVar3[iVar9 + 0x7b] + 1;
        iVar12 = FUN_0056e030(0x2c,
                              "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D11.cpp",
                              0x1ca);
        *piVar1 = iVar12;
        FUN_0056d380(iVar12,0,0x2c);
        *(int *)(*piVar1 + 0x14) = *piVar1 + 0x20;
        piVar3[iVar9 + 0xb1] = *piVar1;
        piVar3[iVar9 + 0xe7] = *piVar1;
      }
      piVar3 = (int *)*piVar1;
      if ((0xbffff < piVar3[1] + (int)local_150) || (0x5ffff < *piVar3 + local_154)) {
        local_148[0x77] = local_148[0x77] + 1;
        local_148[iVar9 + 0x7b] = local_148[iVar9 + 0x7b] + 1;
        iVar12 = FUN_0056e030(0x2c,
                              "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D11.cpp",
                              0x1da);
        piVar3[6] = iVar12;
        FUN_0056d380(iVar12,0,0x2c);
        *(int *)(piVar3[6] + 0x14) = piVar3[6] + 0x20;
        *(int **)(piVar3[6] + 0x1c) = piVar3;
        local_148[iVar9 + 0xe7] = piVar3[6];
        piVar3 = (int *)piVar3[6];
        *piVar1 = (int)piVar3;
      }
      piVar8[0x49] = (int)piVar3;
      piVar8[0x4a] = *piVar3;
      iVar9 = piVar3[1];
      piVar8[0x4b] = iVar9;
      if (local_148[0x11] == 0) {
        piVar8[0x4c] = (uint)*(ushort *)(piVar8 + 0x44) + iVar9;
      }
      else {
        piVar8[0x4c] = (uint)*(ushort *)(piVar8 + 0x44) * piVar8[0x48] + iVar9;
      }
      *piVar3 = *piVar3 + local_154;
      piVar3[1] = piVar3[1] + (int)local_150;
      piVar3 = local_148;
switchD_005e89bd_default:
      local_124 = local_124 + 1;
      piVar8 = piVar8 + 0x4e;
    } while (local_124 < piVar3[0x49]);
  }
  iVar9 = 0;
  piVar3 = piVar3 + 0xe5;
  do {
    piVar8 = local_148;
    local_150 = (int *)0x2;
    do {
      iVar12 = 0;
      do {
        iVar5 = *piVar3;
        if ((iVar5 != 0) && (*(int *)(iVar5 + 4) == 0)) {
          *piVar3 = *(int *)(iVar5 + 0x1c);
          if (*(int *)(iVar5 + 0x1c) != 0) {
            *(undefined4 *)(*(int *)(iVar5 + 0x1c) + 0x18) = 0;
          }
          FUN_0056e1d0(iVar5);
          piVar8[0x77] = piVar8[0x77] + -1;
          piVar8[iVar12 + iVar9 + 0x79] = piVar8[iVar12 + iVar9 + 0x79] + -1;
        }
        iVar12 = iVar12 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar12 < 9);
      iVar9 = iVar9 + 9;
      local_150 = (int *)((int)local_150 + -1);
    } while (local_150 != (int *)0x0);
  } while (iVar9 < 0x36);
  FUN_0056d380(&local_f0,0,0x18);
  local_f0 = 0;
  local_ec = 0;
  local_e8 = 1;
  local_e4 = 0;
  FUN_0056d380(&local_108,0,0x18);
  local_134 = local_d8;
  local_12c = piVar8 + 0xaf;
  local_108 = 0;
  local_104 = 0;
  local_100 = 2;
  local_fc = 0;
  local_124 = 0;
  do {
    local_160 = (int *)0x0;
    local_130 = local_134;
    local_13c = local_12c;
    do {
      local_15c = (int *)0x0;
      local_14c = local_130;
      local_150 = local_13c;
      do {
        piVar3 = (int *)*local_150;
        *local_14c = (int)piVar3;
        if (piVar3 != (int *)0x0) {
          iVar9 = FUN_005e8870(local_160);
          do {
            local_f0 = *piVar3 * iVar9;
            piVar3[4] = iVar9;
            iVar12 = FUN_005d4e80(&local_f0,0,piVar3[5],param_3);
            if (iVar12 < 0) {
LAB_005e8e76:
              piVar3 = local_148 + 0xaf;
              local_14c = (int *)0x3;
              do {
                local_160 = (int *)0x2;
                do {
                  local_150 = (int *)0x9;
                  do {
                    iVar9 = *piVar3;
                    while (iVar9 != 0) {
                      if (*(int *)(iVar9 + 8) != 0) {
                        FUN_0056e1d0(*(int *)(iVar9 + 8));
                        *(undefined4 *)(iVar9 + 8) = 0;
                      }
                      if (*(int *)(iVar9 + 0xc) != 0) {
                        FUN_0056e1d0(*(int *)(iVar9 + 0xc));
                        *(undefined4 *)(iVar9 + 0xc) = 0;
                      }
                      if (**(int **)(iVar9 + 0x14) != 0) {
                        FUN_005d4d00(**(int **)(iVar9 + 0x14),param_3);
                      }
                      iVar12 = *(int *)(*(int *)(iVar9 + 0x14) + 4);
                      if (iVar12 != 0) {
                        FUN_005d4d00(iVar12,param_3);
                      }
                      iVar12 = *(int *)(iVar9 + 0x18);
                      FUN_0056e1d0(iVar9);
                      iVar9 = iVar12;
                    }
                    *piVar3 = 0;
                    piVar3[0x36] = 0;
                    piVar3[-0x36] = 0;
                    piVar3 = piVar3 + 1;
                    local_150 = (int *)((int)local_150 + -1);
                  } while (local_150 != (int *)0x0);
                  local_160 = (int *)((int)local_160 + -1);
                } while (local_160 != (int *)0x0);
                local_14c = (int *)((int)local_14c + -1);
              } while (local_14c != (int *)0x0);
              local_148[0x77] = 0;
              return 0xffffffff;
            }
            iVar12 = FUN_0056e030(local_f0,
                                  "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D11.cpp"
                                  ,0x231);
            piVar3[2] = iVar12;
            if (iVar12 == 0) goto LAB_005e8e76;
            local_108 = piVar3[1] * 2;
            iVar12 = FUN_005d4e80(&local_108,0,piVar3[5] + 4,param_3);
            if (iVar12 < 0) goto LAB_005e8e76;
            iVar12 = FUN_0056e030(local_108,
                                  "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D11.cpp"
                                  ,0x240);
            piVar3[3] = iVar12;
            if (iVar12 == 0) goto LAB_005e8e76;
            piVar3 = (int *)piVar3[6];
          } while (piVar3 != (int *)0x0);
        }
        local_150 = local_150 + 1;
        local_14c = local_14c + 1;
        local_15c = (int *)((int)local_15c + 1);
      } while ((int)local_15c < 9);
      local_130 = local_130 + 9;
      local_13c = local_13c + 9;
      local_160 = (int *)((int)local_160 + 1);
    } while ((int)local_160 < 2);
    local_134 = local_134 + 0x12;
    local_124 = local_124 + 1;
    local_12c = local_12c + 0x12;
    if (2 < local_124) {
      local_160 = (int *)local_148[0x4a];
      local_124 = 0;
      if (0 < local_148[0x49]) {
        do {
          piVar3 = local_160;
          local_14c = (int *)local_160[0x49];
          if (((local_14c != (int *)0x0) && (*(int *)local_14c[5] != 0)) &&
             (((int *)local_14c[5])[1] != 0)) {
            piVar8 = (int *)*local_160;
            piVar1 = (int *)local_160[3];
            local_13c = *(int **)(*piVar8 + 0x1b0);
            piVar7 = (int *)(uint)(*(int *)(piVar8[1] + 0x168) != 0);
            local_128 = piVar8[0x13];
            local_12c = (int *)piVar8[0x16];
            local_134 = (int *)piVar8[0x17];
            if (2 < local_128) {
              local_128 = 2;
            }
            local_130 = piVar7;
            local_158 = piVar1;
            switch((short)local_160[1]) {
            case 0:
              uVar11 = local_160[0x42] + 0xfU & 0xfffffff0;
              if (local_148[0x11] == 0) {
                local_138 = local_14c[4] * local_160[0x4a] + local_14c[2];
                piVar8 = (int *)local_160[0x3c];
                if (0 < (int)piVar1) {
                  do {
                    iVar9 = *piVar8 * (int)local_12c;
                    piVar1 = local_13c + *(int *)((int)local_134 + iVar9 + 4) * 9;
                    if (local_130 == (int *)0x0) {
                      piVar7 = (int *)0x0;
                      local_168 = (int *)0x0;
                    }
                    else {
                      local_168 = piVar1 + 3;
                      piVar7 = piVar1 + 6;
                    }
                    if (local_128 < 2) {
                      local_164 = (int *)0x0;
                    }
                    else {
                      local_164 = (int *)((int)local_134 + iVar9 + 0x1c);
                    }
                    if (local_128 < 1) {
                      iVar12 = 0;
                    }
                    else {
                      iVar12 = (int)local_134 + iVar9 + 0x14;
                    }
                    FUN_005e86d0(&local_138,uVar11,piVar1,(int)local_134 + iVar9 + 8,
                                 (int)local_134 + iVar9 + 0xc,iVar12,local_164,local_168,piVar7,0,0,
                                 0,0);
                    uVar11 = uVar11 + 0x20;
                    piVar8 = piVar8 + 1;
                    local_158 = (int *)((int)local_158 + -1);
                  } while (local_158 != (int *)0x0);
                }
              }
              else {
                local_120 = 0x3f800000;
                local_11c = 0;
                local_118 = 0;
                local_114 = 0;
                local_138 = local_14c[4] * local_160[0x4a] + local_14c[2];
                local_15c = (int *)local_160[0x3c];
                local_140 = '\0';
                local_13f = '\0';
                local_13e = '\0';
                local_13d = '\0';
                if (0 < (int)piVar1) {
                  local_168 = piVar1;
                  do {
                    iVar9 = *local_15c * (int)local_12c;
                    piVar8 = local_13c + *(int *)((int)local_134 + iVar9 + 4) * 9;
                    if (piVar7 == (int *)0x0) {
                      local_160 = (int *)0x0;
                      local_158 = (int *)0x0;
                    }
                    else {
                      local_160 = piVar8 + 6;
                      local_158 = piVar8 + 3;
                    }
                    if (local_128 < 2) {
                      local_164 = (int *)0x0;
                    }
                    else {
                      local_164 = (int *)((int)local_134 + iVar9 + 0x1c);
                    }
                    if (local_128 < 1) {
                      iVar12 = 0;
                    }
                    else {
                      iVar12 = (int)local_134 + iVar9 + 0x14;
                    }
                    FUN_005e86d0(&local_138,uVar11,piVar8,(int)local_134 + iVar9 + 8,
                                 (int)local_134 + iVar9 + 0xc,iVar12,local_164,local_158,local_160,
                                 &local_140,&local_120,0,0);
                    local_15c = local_15c + 1;
                    uVar11 = uVar11 + 0x20;
                    local_168 = (int *)((int)local_168 + -1);
                  } while (local_168 != (int *)0x0);
                }
                local_15c = (int *)0x1;
                if (1 < piVar3[0x48]) {
                  do {
                    piVar8 = (int *)piVar3[0x3c];
                    uVar11 = piVar3[0x42] + 0xfU & 0xfffffff0;
                    if (0 < (int)piVar1) {
                      local_160 = piVar1;
                      do {
                        iVar9 = *piVar8 * (int)local_12c;
                        piVar2 = local_13c + *(int *)((int)local_134 + iVar9 + 4) * 9;
                        local_140 = (char)local_15c;
                        if (piVar7 == (int *)0x0) {
                          piVar7 = (int *)0x0;
                          local_168 = (int *)0x0;
                        }
                        else {
                          local_168 = piVar2 + 6;
                          piVar7 = piVar2 + 3;
                        }
                        if (local_128 < 2) {
                          local_158 = (int *)0x0;
                        }
                        else {
                          local_158 = (int *)((int)local_134 + iVar9 + 0x1c);
                        }
                        if (local_128 < 1) {
                          iVar12 = 0;
                        }
                        else {
                          iVar12 = (int)local_134 + iVar9 + 0x14;
                        }
                        FUN_005e86d0(&local_138,uVar11,piVar2,(int)local_134 + iVar9 + 8,
                                     (int)local_134 + iVar9 + 0xc,iVar12,local_158,piVar7,local_168,
                                     &local_140,&local_120,0,0);
                        uVar11 = uVar11 + 0x20;
                        piVar8 = piVar8 + 1;
                        local_160 = (int *)((int)local_160 + -1);
                        piVar7 = local_130;
                      } while (local_160 != (int *)0x0);
                    }
                    local_15c = (int *)((int)local_15c + 1);
                  } while ((int)local_15c < piVar3[0x48]);
                }
              }
              break;
            case 1:
              local_138 = local_14c[4] * local_160[0x4a] + local_14c[2];
              piVar8 = (int *)local_160[0x3c];
              uVar11 = local_160[0x42] + 0xfU & 0xfffffff0;
              if (0 < (int)piVar1) {
                local_15c = piVar1;
                do {
                  iVar12 = *piVar8 * (int)local_12c;
                  piVar7 = local_13c + *(int *)((int)local_134 + iVar12 + 4) * 9;
                  iVar9 = 0;
                  if (local_130 == (int *)0x0) {
                    local_168 = (int *)0x0;
                    local_164 = (int *)0x0;
                  }
                  else {
                    local_168 = piVar7 + 6;
                    local_164 = piVar7 + 3;
                  }
                  if (1 < local_128) {
                    iVar9 = (int)local_134 + iVar12 + 0x1c;
                  }
                  if (local_128 < 1) {
                    iVar5 = 0;
                  }
                  else {
                    iVar5 = (int)local_134 + iVar12 + 0x14;
                  }
                  FUN_005e86d0(&local_138,uVar11 + 0x10,piVar7,(int)local_134 + iVar12 + 8,
                               (int)local_134 + iVar12 + 0xc,iVar5,iVar9,local_164,local_168,
                               uVar11 + 0x2c,uVar11,0,0);
                  uVar11 = uVar11 + 0x30;
                  piVar8 = piVar8 + 1;
                  local_15c = (int *)((int)local_15c + -1);
                } while (local_15c != (int *)0x0);
              }
              if (local_148[0x11] != 0) {
                iVar9 = local_160[5];
                local_15c = (int *)0x1;
                if (1 < local_160[0x48]) {
                  do {
                    piVar8 = (int *)local_160[0x3c];
                    uVar11 = local_160[0x42] + 0xfU & 0xfffffff0;
                    if (0 < (int)piVar1) {
                      local_144 = piVar1;
                      do {
                        iVar12 = *piVar8 * (int)local_12c;
                        piVar7 = local_13c + *(int *)((int)local_134 + iVar12 + 4) * 9;
                        local_13d = (char)iVar9;
                        local_140 = *(char *)(uVar11 + 0x2c) + local_13d;
                        local_13f = *(char *)(uVar11 + 0x2d) + local_13d;
                        local_13e = *(char *)(uVar11 + 0x2e) + local_13d;
                        local_13d = *(char *)(uVar11 + 0x2f) + local_13d;
                        if (local_130 == (int *)0x0) {
                          local_168 = (int *)0x0;
                          local_164 = (int *)0x0;
                        }
                        else {
                          local_168 = piVar7 + 6;
                          local_164 = piVar7 + 3;
                        }
                        if (local_128 < 2) {
                          local_158 = (int *)0x0;
                        }
                        else {
                          local_158 = (int *)((int)local_134 + iVar12 + 0x1c);
                        }
                        iVar5 = 0;
                        if (0 < local_128) {
                          iVar5 = (int)local_134 + iVar12 + 0x14;
                        }
                        FUN_005e86d0(&local_138,uVar11 + 0x10,piVar7,(int)local_134 + iVar12 + 8,
                                     (int)local_134 + iVar12 + 0xc,iVar5,local_158,local_164,
                                     local_168,&local_140,uVar11,0,0);
                        uVar11 = uVar11 + 0x30;
                        piVar8 = piVar8 + 1;
                        local_144 = (int *)((int)local_144 + -1);
                      } while (local_144 != (int *)0x0);
                    }
                    iVar9 = iVar9 + local_160[5];
                    local_15c = (int *)((int)local_15c + 1);
                  } while ((int)local_15c < local_160[0x48]);
                }
              }
              break;
            case 2:
              local_138 = local_14c[4] * local_160[0x4a] + local_14c[2];
              local_15c = (int *)local_160[0x3c];
              uVar11 = local_160[0x42] + 0xfU & 0xfffffff0;
              if (0 < (int)piVar1) {
                do {
                  iVar12 = *local_15c * (int)local_12c;
                  piVar8 = local_13c + *(int *)((int)local_134 + iVar12 + 4) * 9;
                  iVar9 = 0;
                  if (piVar7 == (int *)0x0) {
                    local_144 = (int *)0x0;
                    local_168 = (int *)0x0;
                  }
                  else {
                    local_144 = piVar8 + 6;
                    local_168 = piVar8 + 3;
                  }
                  if (1 < local_128) {
                    iVar9 = (int)local_134 + iVar12 + 0x1c;
                  }
                  if (local_128 < 1) {
                    iVar5 = 0;
                  }
                  else {
                    iVar5 = (int)local_134 + iVar12 + 0x14;
                  }
                  FUN_005e86d0(&local_138,uVar11 + 0x30,piVar8,(int)local_134 + iVar12 + 8,
                               (int)local_134 + iVar12 + 0xc,iVar5,iVar9,local_168,local_144,
                               uVar11 + 0x2c,uVar11,uVar11 + 0x3c,uVar11 + 0x10);
                  local_15c = local_15c + 1;
                  uVar11 = uVar11 + 0x40;
                  local_158 = (int *)((int)local_158 + -1);
                } while (local_158 != (int *)0x0);
              }
              if (local_148[0x11] != 0) {
                iVar9 = local_160[5];
                local_15c = (int *)0x1;
                if (1 < local_160[0x48]) {
                  do {
                    piVar8 = (int *)local_160[0x3c];
                    uVar11 = local_160[0x42] + 0xfU & 0xfffffff0;
                    if (0 < (int)piVar1) {
                      local_158 = piVar1;
                      do {
                        iVar12 = *piVar8 * (int)local_12c;
                        piVar7 = local_13c + *(int *)((int)local_134 + iVar12 + 4) * 9;
                        cVar6 = (char)iVar9;
                        local_140 = *(char *)(uVar11 + 0x2c) + cVar6;
                        local_13f = *(char *)(uVar11 + 0x2d) + cVar6;
                        local_13e = *(char *)(uVar11 + 0x2e) + cVar6;
                        local_13d = *(char *)(uVar11 + 0x2f) + cVar6;
                        local_150 = (int *)CONCAT13(*(char *)(uVar11 + 0x3f) + cVar6,
                                                    CONCAT12(*(char *)(uVar11 + 0x3e) + cVar6,
                                                             CONCAT11(*(char *)(uVar11 + 0x3d) +
                                                                      cVar6,*(char *)(uVar11 + 0x3c)
                                                                            + cVar6)));
                        if (local_130 == (int *)0x0) {
                          local_144 = (int *)0x0;
                          local_168 = (int *)0x0;
                        }
                        else {
                          local_144 = piVar7 + 6;
                          local_168 = piVar7 + 3;
                        }
                        if (local_128 < 2) {
                          local_164 = (int *)0x0;
                        }
                        else {
                          local_164 = (int *)((int)local_134 + iVar12 + 0x1c);
                        }
                        iVar5 = 0;
                        if (0 < local_128) {
                          iVar5 = (int)local_134 + iVar12 + 0x14;
                        }
                        FUN_005e86d0(&local_138,uVar11 + 0x30,piVar7,(int)local_134 + iVar12 + 8,
                                     (int)local_134 + iVar12 + 0xc,iVar5,local_164,local_168,
                                     local_144,&local_140,uVar11,&local_150,uVar11 + 0x10);
                        uVar11 = uVar11 + 0x40;
                        piVar8 = piVar8 + 1;
                        local_158 = (int *)((int)local_158 + -1);
                      } while (local_158 != (int *)0x0);
                    }
                    iVar9 = iVar9 + local_160[5];
                    local_15c = (int *)((int)local_15c + 1);
                  } while ((int)local_15c < local_160[0x48]);
                }
              }
              break;
            case 3:
              if (local_148[0x11] == 0) {
                local_138 = local_14c[4] * local_160[0x4a] + local_14c[2];
                piVar8 = (int *)local_160[0x3c];
                uVar11 = local_160[0x42] + 0xfU & 0xfffffff0;
                if (0 < (int)piVar1) {
                  local_164 = piVar1;
                  do {
                    iVar9 = *piVar8 * (int)local_12c;
                    piVar1 = local_13c + *(int *)((int)local_134 + iVar9 + 4) * 9;
                    if (local_130 == (int *)0x0) {
                      piVar7 = (int *)0x0;
                      local_144 = (int *)0x0;
                    }
                    else {
                      local_144 = piVar1 + 3;
                      piVar7 = piVar1 + 6;
                    }
                    if (local_128 < 2) {
                      local_168 = (int *)0x0;
                    }
                    else {
                      local_168 = (int *)((int)local_134 + iVar9 + 0x1c);
                    }
                    if (local_128 < 1) {
                      iVar12 = 0;
                    }
                    else {
                      iVar12 = (int)local_134 + iVar9 + 0x14;
                    }
                    FUN_005e86d0(&local_138,uVar11,piVar1,(int)local_134 + iVar9 + 8,
                                 (int)local_134 + iVar9 + 0xc,iVar12,local_168,local_144,piVar7,0,0,
                                 0,0);
                    uVar11 = uVar11 + *(ushort *)((int)local_160 + 6);
                    piVar8 = piVar8 + 1;
                    local_164 = (int *)((int)local_164 + -1);
                  } while (local_164 != (int *)0x0);
                }
              }
            }
            iVar9 = local_14c[3] + piVar3[0x4b] * 2;
            iVar12 = local_14c[3] + piVar3[0x4c] * 2;
            FUN_0056d420(iVar9,piVar3[0x45],(uint)*(ushort *)(piVar3 + 0x44) * 2);
            if (*(ushort *)(piVar3 + 0x46) != 0) {
              FUN_0056d420(iVar12,piVar3[0x47],(uint)*(ushort *)(piVar3 + 0x46) * 2);
            }
            if (local_148[0x11] != 0) {
              piVar8 = (int *)piVar3[3];
              psVar10 = (short *)(iVar12 + (uint)*(ushort *)(piVar3 + 0x46) * 2);
              psVar13 = (short *)(iVar9 + (uint)*(ushort *)(piVar3 + 0x44) * 2);
              local_160 = (int *)0x1;
              local_14c = piVar8;
              if (1 < piVar3[0x48]) {
                do {
                  FUN_0056d420(psVar13,piVar3[0x45],(uint)*(ushort *)(piVar3 + 0x44) * 2);
                  iVar9 = 0;
                  if ((short)piVar3[0x44] != 0) {
                    do {
                      *psVar13 = *psVar13 + (short)piVar8;
                      iVar9 = iVar9 + 1;
                      psVar13 = psVar13 + 1;
                    } while (iVar9 < (int)(uint)*(ushort *)(piVar3 + 0x44));
                  }
                  piVar8 = (int *)((int)piVar8 + piVar3[3]);
                  if (*(ushort *)(piVar3 + 0x46) != 0) {
                    FUN_0056d420(psVar10,piVar3[0x47],(uint)*(ushort *)(piVar3 + 0x46) * 2);
                    iVar9 = 0;
                    if ((short)piVar3[0x46] != 0) {
                      do {
                        *psVar10 = *psVar10 + (short)local_14c;
                        iVar9 = iVar9 + 1;
                        psVar10 = psVar10 + 1;
                      } while (iVar9 < (int)(uint)*(ushort *)(piVar3 + 0x46));
                    }
                    local_14c = (int *)((int)local_14c + piVar3[3]);
                  }
                  local_160 = (int *)((int)local_160 + 1);
                } while ((int)local_160 < piVar3[0x48]);
              }
            }
          }
          local_124 = local_124 + 1;
          local_160 = piVar3 + 0x4e;
        } while (local_124 < local_148[0x49]);
      }
      piVar8 = local_148;
      piVar3 = local_148 + 0x79;
      local_164 = (int *)0x3;
      do {
        local_168 = (int *)0x2;
        do {
          local_144 = (int *)0x9;
          do {
            piVar1 = (int *)piVar3[0x36];
            while (piVar7 = piVar1, piVar7 != (int *)0x0) {
              piVar2 = (int *)piVar7[5];
              piVar1 = (int *)piVar7[6];
              if ((*piVar2 == 0) || (piVar2[1] == 0)) {
                if (piVar7[7] == 0) {
                  piVar3[0x36] = (int)piVar1;
                }
                else {
                  *(int **)(piVar7[7] + 0x18) = piVar1;
                }
                if (piVar7[6] == 0) {
                  piVar3[0x6c] = piVar7[7];
                }
                else {
                  *(int *)(piVar7[6] + 0x1c) = piVar7[7];
                }
                if (piVar7[2] != 0) {
                  FUN_0056e1d0(piVar7[2]);
                  piVar7[2] = 0;
                }
                if (piVar7[3] != 0) {
                  FUN_0056e1d0(piVar7[3]);
                  piVar7[3] = 0;
                }
                if (*(int *)piVar7[5] != 0) {
                  FUN_005d4d00(*(int *)piVar7[5],param_3);
                  *(undefined4 *)piVar7[5] = 0;
                }
                if (*(int *)(piVar7[5] + 4) != 0) {
                  FUN_005d4d00(*(int *)(piVar7[5] + 4),param_3);
                  *(undefined4 *)(piVar7[5] + 4) = 0;
                }
                iVar9 = 0;
                if (0 < piVar8[0x49]) {
                  puVar4 = (undefined4 *)(piVar8[0x4a] + 0x124);
                  do {
                    if ((int *)*puVar4 == piVar7) {
                      *puVar4 = 0;
                    }
                    iVar9 = iVar9 + 1;
                    puVar4 = puVar4 + 0x4e;
                  } while (iVar9 < piVar8[0x49]);
                }
                FUN_0056e1d0(piVar7);
                *piVar3 = *piVar3 + -1;
                piVar8[0x77] = piVar8[0x77] + -1;
              }
              else {
                local_120 = 0;
                local_11c = 0;
                local_118 = 0;
                local_110 = 1;
                local_10c = 1;
                if (*piVar2 != 0) {
                  local_114 = piVar7[4] * *piVar7;
                  FUN_005d52f0(*piVar2,0,&local_120,piVar7[2],0,0,param_3);
                }
                if (*(int *)(piVar7[5] + 4) != 0) {
                  local_114 = piVar7[1] * 2;
                  FUN_005d52f0(*(undefined4 *)(piVar7[5] + 4),0,&local_120,piVar7[3],0,0,param_3);
                }
              }
            }
            piVar3 = piVar3 + 1;
            local_144 = (int *)((int)local_144 + -1);
          } while (local_144 != (int *)0x0);
          local_168 = (int *)((int)local_168 + -1);
        } while (local_168 != (int *)0x0);
        local_164 = (int *)((int)local_164 + -1);
      } while (local_164 != (int *)0x0);
      piVar8 = piVar8 + 0xaf;
      local_168 = (int *)0x3;
      do {
        local_144 = (int *)0x2;
        do {
          iVar9 = 9;
          do {
            for (iVar12 = *piVar8; iVar12 != 0; iVar12 = *(int *)(iVar12 + 0x18)) {
              if (*(int *)(iVar12 + 8) != 0) {
                FUN_0056e1d0(*(int *)(iVar12 + 8));
                *(undefined4 *)(iVar12 + 8) = 0;
              }
              if (*(int *)(iVar12 + 0xc) != 0) {
                FUN_0056e1d0(*(int *)(iVar12 + 0xc));
                *(undefined4 *)(iVar12 + 0xc) = 0;
              }
            }
            piVar8 = piVar8 + 1;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
          local_144 = (int *)((int)local_144 + -1);
        } while (local_144 != (int *)0x0);
        local_168 = (int *)((int)local_168 + -1);
      } while (local_168 != (int *)0x0);
      local_148[0x78] = 1;
      if ((DAT_00cc6e00 != 0) && (DAT_00cc6e38 <= DAT_00cc6e3c)) {
        local_144 = (int *)0x0;
        iVar9 = DAT_00cc6e38;
        do {
          iVar12 = *(int *)(DAT_00cc6e04 + iVar9 * 4);
          if (((iVar12 != 0) && (*(int *)(iVar12 + 0x10) == 0)) &&
             (*(int **)(iVar12 + 0x40) == local_148)) {
            FUN_005db690(*(undefined4 *)(iVar12 + 4),param_3);
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 <= DAT_00cc6e3c);
      }
      return 0;
    }
  } while( true );
}

