
void FUN_00761d30(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined1 uVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int local_80;
  int local_7c;
  int local_78;
  undefined4 local_74;
  int local_6c;
  
  uVar12 = param_6;
  iVar15 = DAT_00dca3f8;
  if (param_2 < param_4) {
    local_78 = param_2;
    iVar14 = param_4;
  }
  else {
    local_78 = param_4;
    iVar14 = param_2;
  }
  if (param_3 < param_5) {
    iVar7 = param_5;
    iVar11 = param_3;
  }
  else {
    iVar7 = param_3;
    iVar11 = param_5;
  }
  if ((int)((DAT_00dca3f0 - iVar11) - 1U | (DAT_00dca3ec - local_78) - 1U | iVar7 - DAT_00dca3e8 |
           iVar14 - DAT_00dca3e4) < 0) {
    return;
  }
  dVar4 = 0.0;
  dVar1 = dVar4;
  if (param_5 != param_3) {
    dVar1 = (double)(param_4 - param_2) / (double)(param_5 - param_3);
  }
  if (param_4 != param_2) {
    dVar4 = (double)(param_5 - param_3) / (double)(param_4 - param_2);
  }
  dVar2 = (double)param_2 - (double)param_3 * dVar1;
  dVar3 = (double)param_3 - (double)param_2 * dVar4;
  if (param_2 < DAT_00dca3e4) {
    param_2 = DAT_00dca3e4;
    param_3 = (int)ROUND(dVar3 + (double)DAT_00dca3e4 * dVar4);
  }
  else if (DAT_00dca3ec <= param_2) {
    param_2 = DAT_00dca3ec + -1;
    param_3 = (int)ROUND(dVar3 + (double)param_2 * dVar4);
  }
  if (param_4 < DAT_00dca3e4) {
    local_78 = DAT_00dca3e4 + -1;
    param_5 = (int)ROUND(dVar4 * (double)local_78 + dVar3);
  }
  else {
    local_78 = param_4;
    if (DAT_00dca3ec <= param_4) {
      param_5 = (int)ROUND(dVar4 * (double)DAT_00dca3ec + dVar3);
      local_78 = DAT_00dca3ec;
    }
  }
  if (param_3 < DAT_00dca3e8) {
    param_3 = DAT_00dca3e8;
    param_2 = (int)ROUND((double)DAT_00dca3e8 * dVar1 + dVar2);
  }
  else if (DAT_00dca3f0 <= param_3) {
    param_3 = DAT_00dca3f0 + -1;
    param_2 = (int)ROUND((double)param_3 * dVar1 + dVar2);
  }
  if (param_5 < DAT_00dca3e8) {
    param_5 = DAT_00dca3e8 + -1;
LAB_007620b5:
    local_78 = (int)ROUND((double)param_5 * dVar1 + dVar2);
  }
  else if (DAT_00dca3f0 <= param_5) {
    param_5 = DAT_00dca3f0;
    goto LAB_007620b5;
  }
  if (param_2 < DAT_00dca3e4) {
    param_2 = DAT_00dca3e4;
  }
  else if (DAT_00dca3ec <= param_2) {
    param_2 = DAT_00dca3ec + -1;
  }
  if (local_78 < DAT_00dca3e4) {
    local_78 = DAT_00dca3e4 + -1;
  }
  else if (DAT_00dca3ec <= local_78) {
    local_78 = DAT_00dca3ec;
  }
  if (param_3 < DAT_00dca3e8) {
    param_3 = DAT_00dca3e8;
  }
  else if (DAT_00dca3f0 <= param_3) {
    param_3 = DAT_00dca3f0 + -1;
  }
  if (param_5 < DAT_00dca3e8) {
    param_5 = DAT_00dca3e8 + -1;
  }
  else if (DAT_00dca3f0 <= param_5) {
    param_5 = DAT_00dca3f0;
  }
  local_78 = local_78 - param_2;
  param_5 = param_5 - param_3;
  if (local_78 == 0) {
    if (param_5 == 0) {
      return;
    }
LAB_00762130:
    iVar14 = 1;
  }
  else {
    if (-1 < local_78) goto LAB_00762130;
    iVar14 = -1;
    local_78 = -local_78;
  }
  if (param_5 < 0) {
    local_6c = -1;
    param_5 = -param_5;
  }
  else {
    local_6c = 1;
  }
  iVar7 = *(int *)(param_1 + 0x14);
  uVar8 = (uint)*(byte *)(*(int *)(iVar7 + 0x14) + 4);
  iVar14 = uVar8 * iVar14;
  local_6c = *(int *)(iVar7 + 0xc) * local_6c;
  puVar10 = (uint *)(*(int *)(iVar7 + 0xc) * param_3 + uVar8 * param_2 + *(int *)(param_1 + 0xc));
  local_80 = local_78;
  if (*(int *)(iVar7 + 0x20) == 0) {
    if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
      param_6 = ((param_6 >> 5 & 0x3f) * (DAT_00dca3fc >> 8 & 0xff) & 0xffffff07 |
                (param_6 & 0x1f) * (DAT_00dca3fc & 0xff) >> 5) >> 3 |
                (param_6 >> 8 & 0xfffff8) * (DAT_00dca3fc >> 0x10 & 0xff) & 0xfffff800;
    }
    switch(DAT_00dca3f4) {
    case 0:
switchD_00762aef_caseD_0:
      if (local_78 < param_5) {
        iVar15 = param_5 / 2;
        local_80 = param_5;
        do {
          *(ushort *)puVar10 = (ushort)param_6;
          iVar15 = iVar15 + local_78;
          puVar10 = (uint *)((int)puVar10 + local_6c);
          if (param_5 <= iVar15) {
            puVar10 = (uint *)((int)puVar10 + iVar14);
            iVar15 = iVar15 - param_5;
          }
          local_80 = local_80 + -1;
        } while (local_80 != 0);
        return;
      }
      iVar15 = local_78 / 2;
      do {
        *(ushort *)puVar10 = (ushort)param_6;
        iVar15 = iVar15 + param_5;
        puVar10 = (uint *)((int)puVar10 + iVar14);
        if (local_78 <= iVar15) {
          puVar10 = (uint *)((int)puVar10 + local_6c);
          iVar15 = iVar15 - local_78;
        }
        local_80 = local_80 + -1;
      } while (local_80 != 0);
      return;
    case 1:
      if (DAT_00dca3f8 == 0xff) goto switchD_00762aef_caseD_0;
      if (DAT_00dca3f8 != 0) {
        if (local_78 < param_5) {
          local_7c = param_5 / 2;
          local_80 = param_5;
          do {
            uVar6 = (ushort)*puVar10;
            local_7c = local_7c + local_78;
            *(ushort *)puVar10 =
                 ((uVar6 >> 5 & 0x3f) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((param_6 >> 5 & 0x3f) - (uVar6 >> 5 & 0x3f)) * 4 + iVar15 * 0x800)) *
                 0x20 | ((uVar6 >> 0xb) +
                        *(short *)(&DAT_00d4a6e0 +
                                  ((param_6 >> 0xb) - (uint)(uVar6 >> 0xb)) * 4 + iVar15 * 0x800)) *
                        0x800 |
                 (uVar6 & 0x1f) +
                 *(short *)(&DAT_00d4a6e0 + ((param_6 & 0x1f) - (uVar6 & 0x1f)) * 4 + iVar15 * 0x800
                           );
            puVar10 = (uint *)((int)puVar10 + local_6c);
            if (param_5 <= local_7c) {
              puVar10 = (uint *)((int)puVar10 + iVar14);
              local_7c = local_7c - param_5;
            }
            local_80 = local_80 + -1;
          } while (local_80 != 0);
          return;
        }
        local_7c = local_78 / 2;
        do {
          uVar6 = (ushort)*puVar10;
          local_7c = local_7c + param_5;
          *(ushort *)puVar10 =
               ((uVar6 >> 5 & 0x3f) +
               *(short *)(&DAT_00d4a6e0 +
                         ((param_6 >> 5 & 0x3f) - (uVar6 >> 5 & 0x3f)) * 4 + iVar15 * 0x800)) * 0x20
               | ((uVar6 >> 0xb) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((param_6 >> 0xb) - (uint)(uVar6 >> 0xb)) * 4 + iVar15 * 0x800)) * 0x800
               | (uVar6 & 0x1f) +
                 *(short *)(&DAT_00d4a6e0 + ((param_6 & 0x1f) - (uVar6 & 0x1f)) * 4 + iVar15 * 0x800
                           );
          puVar10 = (uint *)((int)puVar10 + iVar14);
          if (local_78 <= local_7c) {
            puVar10 = (uint *)((int)puVar10 + local_6c);
            local_7c = local_7c - local_78;
          }
          local_80 = local_80 + -1;
        } while (local_80 != 0);
        return;
      }
      break;
    case 2:
      if (DAT_00dca3f8 != 0) {
        if (local_78 < param_5) {
          local_7c = param_5 / 2;
          iVar15 = DAT_00dca3f8 * 0x100;
          iVar7 = DAT_00dca3f8 * 0x100;
          iVar11 = DAT_00dca3f8 * 0x100;
          local_80 = param_5;
          do {
            uVar6 = (*(short *)(&DAT_00d0a2e0 + iVar15 + (param_6 >> 0xb)) * 0x40 +
                    *(short *)(&DAT_00d0a2e0 + iVar7 + (param_6 >> 5 & 0x3f))) * 0x20 +
                    *(short *)(&DAT_00d0a2e0 + iVar11 + (param_6 & 0x1f));
            uVar8 = ((ushort)*puVar10 & 0xf7def7df) + (uVar6 & 0xf7def7df);
            uVar12 = uVar8 & 0x8210820;
            local_7c = local_7c + local_78;
            *(ushort *)puVar10 =
                 (short)uVar12 - (short)(uVar12 >> 5) | ((ushort)*puVar10 | uVar6) & 0x820 |
                 (ushort)uVar8;
            puVar10 = (uint *)((int)puVar10 + local_6c);
            if (param_5 <= local_7c) {
              puVar10 = (uint *)((int)puVar10 + iVar14);
              local_7c = local_7c - param_5;
            }
            local_80 = local_80 + -1;
          } while (local_80 != 0);
          return;
        }
        local_7c = local_78 / 2;
        iVar15 = DAT_00dca3f8 * 0x100;
        iVar7 = DAT_00dca3f8 * 0x100;
        iVar11 = DAT_00dca3f8 * 0x100;
        do {
          uVar6 = (*(short *)(&DAT_00d0a2e0 + iVar15 + (param_6 >> 0xb)) * 0x40 +
                  *(short *)(&DAT_00d0a2e0 + iVar7 + (param_6 >> 5 & 0x3f))) * 0x20 +
                  *(short *)(&DAT_00d0a2e0 + iVar11 + (param_6 & 0x1f));
          uVar8 = ((ushort)*puVar10 & 0xf7def7df) + (uVar6 & 0xf7def7df);
          uVar12 = uVar8 & 0x8210820;
          local_7c = local_7c + param_5;
          *(ushort *)puVar10 =
               (short)uVar12 - (short)(uVar12 >> 5) | ((ushort)*puVar10 | uVar6) & 0x820 |
               (ushort)uVar8;
          puVar10 = (uint *)((int)puVar10 + iVar14);
          if (local_78 <= local_7c) {
            puVar10 = (uint *)((int)puVar10 + local_6c);
            local_7c = local_7c - local_78;
          }
          local_80 = local_80 + -1;
        } while (local_80 != 0);
        return;
      }
      break;
    case 3:
      if (DAT_00dca3f8 != 0) {
        if (local_78 < param_5) {
          iVar15 = DAT_00dca3f8 * 0x100;
          iVar9 = param_5 / 2;
          iVar7 = DAT_00dca3f8 * 0x100;
          iVar11 = DAT_00dca3f8 * 0x100;
          local_80 = param_5;
          do {
            uVar8 = ((ushort)*puVar10 | 0x8210820) -
                    ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar15 + (param_6 >> 0xb)) * 0x40 +
                              *(short *)(&DAT_00d0a2e0 + iVar7 + (param_6 >> 5 & 0x3f))) * 0x20 +
                             *(short *)(&DAT_00d0a2e0 + iVar11 + (param_6 & 0x1f))) & 0xf7def7df);
            uVar12 = uVar8 & 0x8210820;
            *(ushort *)puVar10 = (short)uVar12 - (short)(uVar12 >> 5) & (ushort)uVar8;
            puVar10 = (uint *)((int)puVar10 + local_6c);
            iVar9 = iVar9 + local_78;
            if (param_5 <= iVar9) {
              puVar10 = (uint *)((int)puVar10 + iVar14);
              iVar9 = iVar9 - param_5;
            }
            local_80 = local_80 + -1;
          } while (local_80 != 0);
          return;
        }
        iVar15 = DAT_00dca3f8 * 0x100;
        iVar9 = local_78 / 2;
        iVar7 = DAT_00dca3f8 * 0x100;
        iVar11 = DAT_00dca3f8 * 0x100;
        do {
          uVar8 = ((ushort)*puVar10 | 0x8210820) -
                  ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar15 + (param_6 >> 0xb)) * 0x40 +
                            *(short *)(&DAT_00d0a2e0 + iVar7 + (param_6 >> 5 & 0x3f))) * 0x20 +
                           *(short *)(&DAT_00d0a2e0 + iVar11 + (param_6 & 0x1f))) & 0xf7def7df);
          uVar12 = uVar8 & 0x8210820;
          *(ushort *)puVar10 = (short)uVar12 - (short)(uVar12 >> 5) & (ushort)uVar8;
          puVar10 = (uint *)((int)puVar10 + iVar14);
          iVar9 = iVar9 + param_5;
          if (local_78 <= iVar9) {
            puVar10 = (uint *)((int)puVar10 + local_6c);
            iVar9 = iVar9 - local_78;
          }
          local_80 = local_80 + -1;
        } while (local_80 != 0);
        return;
      }
      break;
    case 4:
      if (local_78 < param_5) {
        local_7c = param_5 / 2;
        local_80 = param_5;
        do {
          uVar12 = (uint)(ushort)*puVar10;
          local_7c = local_7c + local_78;
          *(ushort *)puVar10 =
               (ushort)((uVar12 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
               (ushort)((uVar12 & 0xf800) * (param_6 & 0xf800) >> 0x10) & 0xf800 |
               (ushort)((uVar12 & 0x1f) * (param_6 & 0x1f) >> 5);
          puVar10 = (uint *)((int)puVar10 + local_6c);
          if (param_5 <= local_7c) {
            puVar10 = (uint *)((int)puVar10 + iVar14);
            local_7c = local_7c - param_5;
          }
          local_80 = local_80 + -1;
        } while (local_80 != 0);
        return;
      }
      local_7c = local_78 / 2;
      do {
        uVar12 = (uint)(ushort)*puVar10;
        local_7c = local_7c + param_5;
        *(ushort *)puVar10 =
             (ushort)((uVar12 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
             (ushort)((uVar12 & 0xf800) * (param_6 & 0xf800) >> 0x10) & 0xf800 |
             (ushort)((uVar12 & 0x1f) * (param_6 & 0x1f) >> 5);
        puVar10 = (uint *)((int)puVar10 + iVar14);
        if (local_78 <= local_7c) {
          puVar10 = (uint *)((int)puVar10 + local_6c);
          local_7c = local_7c - local_78;
        }
        local_80 = local_80 + -1;
      } while (local_80 != 0);
      return;
    case 10:
      param_6 = ~param_6;
      if (param_5 <= local_78) {
        local_7c = local_78 / 2;
        do {
          uVar6 = (ushort)*puVar10;
          local_7c = local_7c + param_5;
          *(ushort *)puVar10 =
               ((uVar6 >> 5 & 0x3f) +
               *(short *)(&DAT_00d4a6e0 +
                         (((param_6 & 0xffff) >> 5 & 0x3f) - (uVar6 >> 5 & 0x3f)) * 4 +
                         iVar15 * 0x800)) * 0x20 |
               ((uVar6 >> 0xb) +
               *(short *)(&DAT_00d4a6e0 +
                         (((param_6 & 0xffff) >> 0xb) - (uint)(uVar6 >> 0xb)) * 4 + iVar15 * 0x800))
               * 0x800 | (uVar6 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_6 & 0x1f) - (uVar6 & 0x1f)) * 4 + iVar15 * 0x800);
          puVar10 = (uint *)((int)puVar10 + iVar14);
          if (local_78 <= local_7c) {
            puVar10 = (uint *)((int)puVar10 + local_6c);
            local_7c = local_7c - local_78;
          }
          local_80 = local_80 + -1;
        } while (local_80 != 0);
        return;
      }
      local_7c = param_5 / 2;
      local_80 = param_5;
      do {
        uVar6 = (ushort)*puVar10;
        local_7c = local_7c + local_78;
        *(ushort *)puVar10 =
             ((uVar6 >> 5 & 0x3f) +
             *(short *)(&DAT_00d4a6e0 +
                       (((param_6 & 0xffff) >> 5 & 0x3f) - (uVar6 >> 5 & 0x3f)) * 4 + iVar15 * 0x800
                       )) * 0x20 |
             ((uVar6 >> 0xb) +
             *(short *)(&DAT_00d4a6e0 +
                       (((param_6 & 0xffff) >> 0xb) - (uint)(uVar6 >> 0xb)) * 4 + iVar15 * 0x800)) *
             0x800 | (uVar6 & 0x1f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((param_6 & 0x1f) - (uVar6 & 0x1f)) * 4 + iVar15 * 0x800);
        puVar10 = (uint *)((int)puVar10 + local_6c);
        if (param_5 <= local_7c) {
          puVar10 = (uint *)((int)puVar10 + iVar14);
          local_7c = local_7c - param_5;
        }
        local_80 = local_80 + -1;
      } while (local_80 != 0);
      break;
    case 0xb:
      if (local_78 < param_5) {
        local_7c = param_5 / 2;
        local_80 = param_5;
        do {
          uVar6 = (ushort)*puVar10;
          uVar12 = uVar6 >> 5 & 0x3f;
          local_7c = local_7c + local_78;
          *(ushort *)puVar10 =
               ((uVar6 >> 5 & 0x3f) +
               *(short *)(&DAT_00d4a6e0 +
                         ((uVar12 * (param_6 >> 5 & 0x3f) >> 6) - uVar12) * 4 + iVar15 * 0x800)) *
               0x20 | ((uVar6 >> 0xb) +
                      *(short *)(&DAT_00d4a6e0 +
                                (((uint)(uVar6 >> 0xb) * (param_6 >> 0xb) >> 5) -
                                (uint)(uVar6 >> 0xb)) * 4 + iVar15 * 0x800)) * 0x800 |
               (uVar6 & 0x1f) +
               *(short *)(&DAT_00d4a6e0 +
                         (((uVar6 & 0x1f) * (param_6 & 0x1f) >> 5) - (uVar6 & 0x1f)) * 4 +
                         iVar15 * 0x800);
          puVar10 = (uint *)((int)puVar10 + local_6c);
          if (param_5 <= local_7c) {
            puVar10 = (uint *)((int)puVar10 + iVar14);
            local_7c = local_7c - param_5;
          }
          local_80 = local_80 + -1;
        } while (local_80 != 0);
        return;
      }
      local_7c = local_78 / 2;
      do {
        uVar6 = (ushort)*puVar10;
        uVar12 = uVar6 >> 5 & 0x3f;
        local_7c = local_7c + param_5;
        *(ushort *)puVar10 =
             ((uVar6 >> 5 & 0x3f) +
             *(short *)(&DAT_00d4a6e0 +
                       ((uVar12 * (param_6 >> 5 & 0x3f) >> 6) - uVar12) * 4 + iVar15 * 0x800)) *
             0x20 | ((uVar6 >> 0xb) +
                    *(short *)(&DAT_00d4a6e0 +
                              (((uint)(uVar6 >> 0xb) * (param_6 >> 0xb) >> 5) - (uint)(uVar6 >> 0xb)
                              ) * 4 + iVar15 * 0x800)) * 0x800 |
             (uVar6 & 0x1f) +
             *(short *)(&DAT_00d4a6e0 +
                       (((uVar6 & 0x1f) * (param_6 & 0x1f) >> 5) - (uVar6 & 0x1f)) * 4 +
                       iVar15 * 0x800);
        puVar10 = (uint *)((int)puVar10 + iVar14);
        if (local_78 <= local_7c) {
          puVar10 = (uint *)((int)puVar10 + local_6c);
          local_7c = local_7c - local_78;
        }
        local_80 = local_80 + -1;
      } while (local_80 != 0);
      return;
    }
  }
  else if (*(int *)(iVar7 + 0x20) == 1) {
    if ((DAT_00dca3fc & 0xffffff) == 0xffffff) {
      uVar8 = param_6 >> 0x10 & 0xff;
    }
    else {
      iVar15 = (param_6 >> 0x10 & 0xff) * (DAT_00dca3fc >> 0x10 & 0xff);
      uVar5 = (undefined1)((param_6 >> 8 & 0xff) * (DAT_00dca3fc >> 8 & 0xff) >> 8);
      param_6._0_2_ = CONCAT11(uVar5,(byte)param_6);
      uVar13 = (uint)(ushort)param_6;
      uVar8 = iVar15 >> 8;
      param_6._3_1_ = SUB41(uVar12,3);
      param_6._0_3_ =
           CONCAT12((char)((uint)iVar15 >> 8),
                    CONCAT11(uVar5,(char)((uVar13 & 0xff) * (DAT_00dca3fc & 0xff) >> 8)));
    }
    switch(DAT_00dca3f4) {
    case 0:
switchD_0076224f_caseD_0:
      if (local_78 < param_5) {
        iVar15 = param_5 / 2;
        local_80 = param_5;
        do {
          *puVar10 = param_6;
          iVar15 = iVar15 + local_78;
          puVar10 = (uint *)((int)puVar10 + local_6c);
          if (param_5 <= iVar15) {
            puVar10 = (uint *)((int)puVar10 + iVar14);
            iVar15 = iVar15 - param_5;
          }
          local_80 = local_80 + -1;
        } while (local_80 != 0);
        return;
      }
      iVar15 = local_78 / 2;
      do {
        *puVar10 = param_6;
        iVar15 = iVar15 + param_5;
        puVar10 = (uint *)((int)puVar10 + iVar14);
        if (local_78 <= iVar15) {
          puVar10 = (uint *)((int)puVar10 + local_6c);
          iVar15 = iVar15 - local_78;
        }
        local_80 = local_80 + -1;
      } while (local_80 != 0);
      return;
    case 1:
      if (DAT_00dca3f8 == 0xff) goto switchD_0076224f_caseD_0;
      if (DAT_00dca3f8 != 0) {
        if (local_78 < param_5) {
          iVar15 = param_5 / 2;
          local_80 = param_5;
          do {
            *(byte *)puVar10 =
                 (byte)(((param_6 & 0xff) - (uint)(byte)*puVar10) * DAT_00dca3f8 +
                        (uint)(byte)*puVar10 * 0x100 >> 8);
            *(byte *)((int)puVar10 + 1) =
                 (byte)(((uint)param_6._1_1_ - (uint)*(byte *)((int)puVar10 + 1)) * DAT_00dca3f8 +
                        (uint)*(byte *)((int)puVar10 + 1) * 0x100 >> 8);
            *(byte *)((int)puVar10 + 2) =
                 (byte)((uVar8 - *(byte *)((int)puVar10 + 2)) * DAT_00dca3f8 +
                        (uint)*(byte *)((int)puVar10 + 2) * 0x100 >> 8);
            puVar10 = (uint *)((int)puVar10 + local_6c);
            iVar15 = iVar15 + local_78;
            if (param_5 <= iVar15) {
              puVar10 = (uint *)((int)puVar10 + iVar14);
              iVar15 = iVar15 - param_5;
            }
            local_80 = local_80 + -1;
          } while (local_80 != 0);
          return;
        }
        iVar15 = local_78 / 2;
        do {
          *(byte *)puVar10 =
               (byte)(((param_6 & 0xff) - (uint)(byte)*puVar10) * DAT_00dca3f8 +
                      (uint)(byte)*puVar10 * 0x100 >> 8);
          *(byte *)((int)puVar10 + 1) =
               (byte)(((uint)param_6._1_1_ - (uint)*(byte *)((int)puVar10 + 1)) * DAT_00dca3f8 +
                      (uint)*(byte *)((int)puVar10 + 1) * 0x100 >> 8);
          *(byte *)((int)puVar10 + 2) =
               (byte)((uVar8 - *(byte *)((int)puVar10 + 2)) * DAT_00dca3f8 +
                      (uint)*(byte *)((int)puVar10 + 2) * 0x100 >> 8);
          puVar10 = (uint *)((int)puVar10 + iVar14);
          iVar15 = iVar15 + param_5;
          if (local_78 <= iVar15) {
            puVar10 = (uint *)((int)puVar10 + local_6c);
            iVar15 = iVar15 - local_78;
          }
          local_80 = local_80 + -1;
        } while (local_80 != 0);
        return;
      }
      break;
    case 2:
      if (DAT_00dca3f8 != 0) {
        if (local_78 < param_5) {
          local_7c = param_5 / 2;
          iVar15 = DAT_00dca3f8 * 0x100;
          iVar7 = DAT_00dca3f8 * 0x100;
          iVar11 = DAT_00dca3f8 * 0x100;
          local_80 = param_5;
          do {
            local_74._0_2_ =
                 CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar7 + (uint)param_6._1_1_),
                          *(undefined1 *)(&DAT_00d0a2e0 + iVar15 + (param_6 & 0xff)));
            local_74._0_3_ =
                 CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar11 + uVar8),(undefined2)local_74);
            local_74 = (uint)(uint3)local_74;
            uVar12 = (*puVar10 & 0xfefeff) + (local_74 & 0xfefeff);
            uVar13 = uVar12 & 0x1010100;
            local_7c = local_7c + local_78;
            *puVar10 = uVar13 - (uVar13 >> 8) | (*puVar10 | local_74) & 0x10100 | uVar12;
            puVar10 = (uint *)((int)puVar10 + local_6c);
            if (param_5 <= local_7c) {
              puVar10 = (uint *)((int)puVar10 + iVar14);
              local_7c = local_7c - param_5;
            }
            local_80 = local_80 + -1;
          } while (local_80 != 0);
          return;
        }
        local_7c = local_78 / 2;
        iVar15 = DAT_00dca3f8 * 0x100;
        iVar7 = DAT_00dca3f8 * 0x100;
        iVar11 = DAT_00dca3f8 * 0x100;
        do {
          local_74._0_2_ =
               CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar7 + (uint)param_6._1_1_),
                        *(undefined1 *)(&DAT_00d0a2e0 + iVar15 + (param_6 & 0xff)));
          local_74._0_3_ =
               CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar11 + uVar8),(undefined2)local_74);
          local_74 = (uint)(uint3)local_74;
          uVar12 = (*puVar10 & 0xfefeff) + (local_74 & 0xfefeff);
          uVar13 = uVar12 & 0x1010100;
          local_7c = local_7c + param_5;
          *puVar10 = uVar13 - (uVar13 >> 8) | (*puVar10 | local_74) & 0x10100 | uVar12;
          puVar10 = (uint *)((int)puVar10 + iVar14);
          if (local_78 <= local_7c) {
            puVar10 = (uint *)((int)puVar10 + local_6c);
            local_7c = local_7c - local_78;
          }
          local_80 = local_80 + -1;
        } while (local_80 != 0);
        return;
      }
      break;
    case 3:
      if (DAT_00dca3f8 != 0) {
        if (local_78 < param_5) {
          iVar15 = DAT_00dca3f8 * 0x100;
          iVar7 = DAT_00dca3f8 * 0x100;
          iVar11 = DAT_00dca3f8 * 0x100;
          iVar9 = param_5 / 2;
          local_80 = param_5;
          do {
            uVar12 = local_74;
            local_74._0_2_ =
                 CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar7 + (uint)param_6._1_1_),
                          *(undefined1 *)(&DAT_00d0a2e0 + iVar15 + (param_6 & 0xff)));
            local_74._3_1_ = SUB41(uVar12,3);
            local_74._0_3_ =
                 CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar11 + uVar8),(undefined2)local_74);
            uVar13 = (*puVar10 | 0x1010100) - (local_74 & 0xfefefeff);
            uVar12 = uVar13 & 0x1010100;
            *puVar10 = uVar12 - (uVar12 >> 8) & uVar13;
            puVar10 = (uint *)((int)puVar10 + local_6c);
            iVar9 = iVar9 + local_78;
            if (param_5 <= iVar9) {
              puVar10 = (uint *)((int)puVar10 + iVar14);
              iVar9 = iVar9 - param_5;
            }
            local_80 = local_80 + -1;
          } while (local_80 != 0);
          return;
        }
        iVar15 = DAT_00dca3f8 * 0x100;
        iVar7 = DAT_00dca3f8 * 0x100;
        iVar11 = DAT_00dca3f8 * 0x100;
        iVar9 = local_78 / 2;
        do {
          uVar12 = local_74;
          local_74._0_2_ =
               CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar7 + (uint)param_6._1_1_),
                        *(undefined1 *)(&DAT_00d0a2e0 + iVar15 + (param_6 & 0xff)));
          local_74._3_1_ = SUB41(uVar12,3);
          local_74._0_3_ =
               CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar11 + uVar8),(undefined2)local_74);
          uVar13 = (*puVar10 | 0x1010100) - (local_74 & 0xfefefeff);
          uVar12 = uVar13 & 0x1010100;
          *puVar10 = uVar12 - (uVar12 >> 8) & uVar13;
          puVar10 = (uint *)((int)puVar10 + iVar14);
          iVar9 = iVar9 + param_5;
          if (local_78 <= iVar9) {
            puVar10 = (uint *)((int)puVar10 + local_6c);
            iVar9 = iVar9 - local_78;
          }
          local_80 = local_80 + -1;
        } while (local_80 != 0);
        return;
      }
      break;
    case 4:
      if (local_78 < param_5) {
        iVar15 = param_5 / 2;
        local_80 = param_5;
        do {
          *(byte *)puVar10 = (byte)((uint)(byte)*puVar10 * (param_6 & 0xff) >> 8);
          *(byte *)((int)puVar10 + 1) =
               (byte)((uint)*(byte *)((int)puVar10 + 1) * (uint)param_6._1_1_ >> 8);
          *(byte *)((int)puVar10 + 2) = (byte)(*(byte *)((int)puVar10 + 2) * uVar8 >> 8);
          puVar10 = (uint *)((int)puVar10 + local_6c);
          iVar15 = iVar15 + local_78;
          if (param_5 <= iVar15) {
            puVar10 = (uint *)((int)puVar10 + iVar14);
            iVar15 = iVar15 - param_5;
          }
          local_80 = local_80 + -1;
        } while (local_80 != 0);
        return;
      }
      iVar15 = local_78 / 2;
      do {
        *(byte *)puVar10 = (byte)((uint)(byte)*puVar10 * (param_6 & 0xff) >> 8);
        *(byte *)((int)puVar10 + 1) =
             (byte)((uint)*(byte *)((int)puVar10 + 1) * (uint)param_6._1_1_ >> 8);
        *(byte *)((int)puVar10 + 2) = (byte)(*(byte *)((int)puVar10 + 2) * uVar8 >> 8);
        puVar10 = (uint *)((int)puVar10 + iVar14);
        iVar15 = iVar15 + param_5;
        if (local_78 <= iVar15) {
          puVar10 = (uint *)((int)puVar10 + local_6c);
          iVar15 = iVar15 - local_78;
        }
        local_80 = local_80 + -1;
      } while (local_80 != 0);
      return;
    case 10:
      if (local_78 < param_5) {
        iVar15 = param_5 / 2;
        local_80 = param_5;
        do {
          *(byte *)puVar10 =
               (byte)(((uint)(byte)~(byte)param_6 - (uint)(byte)*puVar10) * DAT_00dca3f8 +
                      (uint)(byte)*puVar10 * 0x100 >> 8);
          *(byte *)((int)puVar10 + 1) =
               (byte)(((uint)(byte)~param_6._1_1_ - (uint)*(byte *)((int)puVar10 + 1)) *
                      DAT_00dca3f8 + (uint)*(byte *)((int)puVar10 + 1) * 0x100 >> 8);
          *(byte *)((int)puVar10 + 2) =
               (byte)(((uint)(byte)~(byte)uVar8 - (uint)*(byte *)((int)puVar10 + 2)) * DAT_00dca3f8
                      + (uint)*(byte *)((int)puVar10 + 2) * 0x100 >> 8);
          puVar10 = (uint *)((int)puVar10 + local_6c);
          iVar15 = iVar15 + local_78;
          if (param_5 <= iVar15) {
            puVar10 = (uint *)((int)puVar10 + iVar14);
            iVar15 = iVar15 - param_5;
          }
          local_80 = local_80 + -1;
        } while (local_80 != 0);
        return;
      }
      iVar15 = local_78 / 2;
      do {
        *(byte *)puVar10 =
             (byte)(((uint)(byte)~(byte)param_6 - (uint)(byte)*puVar10) * DAT_00dca3f8 +
                    (uint)(byte)*puVar10 * 0x100 >> 8);
        *(byte *)((int)puVar10 + 1) =
             (byte)(((uint)(byte)~param_6._1_1_ - (uint)*(byte *)((int)puVar10 + 1)) * DAT_00dca3f8
                    + (uint)*(byte *)((int)puVar10 + 1) * 0x100 >> 8);
        *(byte *)((int)puVar10 + 2) =
             (byte)(((uint)(byte)~(byte)uVar8 - (uint)*(byte *)((int)puVar10 + 2)) * DAT_00dca3f8 +
                    (uint)*(byte *)((int)puVar10 + 2) * 0x100 >> 8);
        puVar10 = (uint *)((int)puVar10 + iVar14);
        iVar15 = iVar15 + param_5;
        if (local_78 <= iVar15) {
          puVar10 = (uint *)((int)puVar10 + local_6c);
          iVar15 = iVar15 - local_78;
        }
        local_80 = local_80 + -1;
      } while (local_80 != 0);
      return;
    case 0xb:
      if (local_78 < param_5) {
        iVar15 = param_5 / 2;
        local_80 = param_5;
        do {
          uVar12 = (uint)(byte)*puVar10;
          uVar13 = (uint)*(byte *)((int)puVar10 + 1);
          *(byte *)puVar10 =
               (byte)((((int)(uVar12 * (param_6 & 0xff)) >> 8) - uVar12) * DAT_00dca3f8 +
                      uVar12 * 0x100 >> 8);
          uVar12 = (uint)*(byte *)((int)puVar10 + 2);
          *(byte *)((int)puVar10 + 1) =
               (byte)((((int)(uVar13 * param_6._1_1_) >> 8) - uVar13) * DAT_00dca3f8 +
                      uVar13 * 0x100 >> 8);
          *(byte *)((int)puVar10 + 2) =
               (byte)((((int)(uVar12 * uVar8) >> 8) - uVar12) * DAT_00dca3f8 + uVar12 * 0x100 >> 8);
          puVar10 = (uint *)((int)puVar10 + local_6c);
          iVar15 = iVar15 + local_78;
          if (param_5 <= iVar15) {
            puVar10 = (uint *)((int)puVar10 + iVar14);
            iVar15 = iVar15 - param_5;
          }
          local_80 = local_80 + -1;
        } while (local_80 != 0);
        return;
      }
      iVar15 = local_78 / 2;
      do {
        uVar12 = (uint)(byte)*puVar10;
        uVar13 = (uint)*(byte *)((int)puVar10 + 1);
        *(byte *)puVar10 =
             (byte)((((int)(uVar12 * (param_6 & 0xff)) >> 8) - uVar12) * DAT_00dca3f8 +
                    uVar12 * 0x100 >> 8);
        uVar12 = (uint)*(byte *)((int)puVar10 + 2);
        *(byte *)((int)puVar10 + 1) =
             (byte)((((int)(uVar13 * param_6._1_1_) >> 8) - uVar13) * DAT_00dca3f8 + uVar13 * 0x100
                   >> 8);
        *(byte *)((int)puVar10 + 2) =
             (byte)((((int)(uVar12 * uVar8) >> 8) - uVar12) * DAT_00dca3f8 + uVar12 * 0x100 >> 8);
        puVar10 = (uint *)((int)puVar10 + iVar14);
        iVar15 = iVar15 + param_5;
        if (local_78 <= iVar15) {
          puVar10 = (uint *)((int)puVar10 + local_6c);
          iVar15 = iVar15 - local_78;
        }
        local_80 = local_80 + -1;
      } while (local_80 != 0);
      return;
    }
  }
  return;
}

