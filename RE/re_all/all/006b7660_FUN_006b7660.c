
undefined4
FUN_006b7660(undefined4 param_1,int param_2,int param_3,uint *param_4,undefined4 *param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  uint *puVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  int local_170;
  int *local_16c;
  int local_168;
  int *local_164;
  int local_160;
  int local_15c;
  int *local_158;
  int *local_154;
  int local_144 [16];
  uint local_104 [65];
  
  piVar14 = *(int **)(param_3 + 0x510);
  local_15c = *(int *)(param_3 + 0x504);
  iVar9 = *(int *)(*(int *)(*(int *)(param_2 + 0x40) + 4) + 0x1c);
  iVar15 = *(int *)(iVar9 + 0xb20);
  if (param_4 == (uint *)0x0) {
    FUN_00797570(param_1,0,1);
    for (uVar7 = *(int *)(param_2 + 0x24) / 2 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
      *param_5 = 0;
      param_5 = param_5 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)param_5 = 0;
      param_5 = (undefined4 *)((int)param_5 + 1);
    }
    return 0;
  }
  if (0 < local_15c) {
    puVar12 = param_4;
    local_16c = (int *)local_15c;
    do {
      uVar7 = *puVar12 & 0x7fff;
      switch(piVar14[0xd0]) {
      case 1:
        uVar7 = (int)uVar7 >> 2;
        break;
      case 2:
        uVar7 = (int)uVar7 >> 3;
        break;
      case 3:
        uVar7 = uVar7 / 0xc;
        break;
      case 4:
        uVar7 = (int)uVar7 >> 4;
      }
      *puVar12 = *puVar12 & 0x8000 | uVar7;
      puVar12 = puVar12 + 1;
      local_16c = (int *)((int)local_16c + -1);
    } while (local_16c != (int *)0x0);
  }
  local_104[0] = *param_4;
  local_104[1] = param_4[1];
  if (2 < local_15c) {
    local_164 = piVar14 + 0xd3;
    puVar12 = param_4 + 2;
    local_158 = (int *)(param_3 + 0x30c);
    local_15c = local_15c + -2;
    do {
      iVar2 = local_158[0x3f];
      iVar6 = *local_158;
      uVar1 = FUN_006b6eb0(piVar14[iVar2 + 0xd1],piVar14[iVar6 + 0xd1],param_4[iVar2],param_4[iVar6]
                           ,*local_164);
      uVar7 = *puVar12;
      if (((uVar7 & 0x8000) == 0) && (uVar1 != uVar7)) {
        uVar10 = *(int *)(param_3 + 0x50c) - uVar1;
        if ((int)uVar1 <= (int)uVar10) {
          uVar10 = uVar1;
        }
        iVar8 = uVar7 - uVar1;
        if (iVar8 < 0) {
          if (iVar8 < (int)-uVar10) {
            iVar8 = (uVar10 - iVar8) + -1;
          }
          else {
            iVar8 = iVar8 * -2 + -1;
          }
        }
        else if (iVar8 < (int)uVar10) {
          iVar8 = iVar8 * 2;
        }
        else {
          iVar8 = iVar8 + uVar10;
        }
        *(int *)(((int)local_104 - (int)param_4) + (int)puVar12) = iVar8;
        param_4[iVar2] = param_4[iVar2] & 0x7fff;
        param_4[iVar6] = param_4[iVar6] & 0x7fff;
      }
      else {
        *puVar12 = uVar1 | 0x8000;
        *(undefined4 *)(((int)local_104 - (int)param_4) + (int)puVar12) = 0;
      }
      local_158 = local_158 + 1;
      local_164 = local_164 + 1;
      puVar12 = puVar12 + 1;
      local_15c = local_15c + -1;
    } while (local_15c != 0);
  }
  FUN_00797570(param_1,1,1);
  *(int *)(param_3 + 0x51c) = *(int *)(param_3 + 0x51c) + 1;
  iVar2 = FUN_006afc40(*(int *)(param_3 + 0x50c) + -1);
  *(int *)(param_3 + 0x518) = *(int *)(param_3 + 0x518) + iVar2 * 2;
  uVar3 = FUN_006afc40(*(int *)(param_3 + 0x50c) + -1);
  FUN_00797570(param_1,local_104[0],uVar3);
  uVar3 = FUN_006afc40(*(int *)(param_3 + 0x50c) + -1);
  FUN_00797570(param_1,local_104[1],uVar3);
  local_160 = 0;
  local_170 = 2;
  if (0 < *piVar14) {
    local_16c = piVar14;
    do {
      local_16c = local_16c + 1;
      iVar2 = *local_16c;
      local_144[0] = 0;
      iVar6 = piVar14[iVar2 + 0x30];
      iVar8 = piVar14[iVar2 + 0x20];
      iVar13 = 1 << ((byte)iVar6 & 0x1f);
      local_144[1] = 0;
      local_144[2] = 0;
      local_144[3] = 0;
      local_144[4] = 0;
      local_144[5] = 0;
      local_144[6] = 0;
      local_144[7] = 0;
      local_158 = (int *)0x0;
      local_15c = 0;
      if (iVar6 != 0) {
        if (0 < iVar13) {
          piVar11 = local_144 + 8;
          piVar4 = piVar14 + (iVar2 + 10) * 8;
          local_168 = iVar13;
          do {
            if (*piVar4 < 0) {
              *piVar11 = 1;
            }
            else {
              *piVar11 = *(int *)(*(int *)(iVar9 + 0x720 + *piVar4 * 4) + 4);
            }
            piVar4 = piVar4 + 1;
            piVar11 = piVar11 + 1;
            local_168 = local_168 + -1;
          } while (local_168 != 0);
        }
        if (0 < iVar8) {
          piVar11 = local_144;
          puVar12 = local_104 + local_170;
          local_168 = iVar8;
          do {
            iVar5 = 0;
            if (0 < iVar13) {
              piVar4 = local_144 + 8;
              do {
                if ((int)*puVar12 < *piVar4) {
                  *piVar11 = iVar5;
                  break;
                }
                iVar5 = iVar5 + 1;
                piVar4 = piVar4 + 1;
              } while (iVar5 < iVar13);
            }
            iVar5 = *piVar11;
            puVar12 = puVar12 + 1;
            piVar11 = piVar11 + 1;
            local_158 = (int *)((uint)local_158 | iVar5 << ((byte)local_15c & 0x1f));
            local_15c = local_15c + iVar6;
            local_168 = local_168 + -1;
          } while (local_168 != 0);
        }
        iVar6 = FUN_006b0940(iVar15 + piVar14[iVar2 + 0x40] * 0x38,local_158,param_1);
        *(int *)(param_3 + 0x514) = *(int *)(param_3 + 0x514) + iVar6;
      }
      if (0 < iVar8) {
        piVar11 = local_144;
        puVar12 = local_104 + local_170;
        local_168 = iVar8;
        do {
          if (-1 < piVar14[*piVar11 + iVar2 * 8 + 0x50]) {
            iVar6 = iVar15 + piVar14[*piVar11 + iVar2 * 8 + 0x50] * 0x38;
            if ((int)*puVar12 < *(int *)(iVar6 + 4)) {
              iVar6 = FUN_006b0940(iVar6,*puVar12,param_1);
              *(int *)(param_3 + 0x518) = *(int *)(param_3 + 0x518) + iVar6;
            }
          }
          piVar11 = piVar11 + 1;
          puVar12 = puVar12 + 1;
          local_168 = local_168 + -1;
        } while (local_168 != 0);
      }
      local_170 = local_170 + iVar8;
      local_160 = local_160 + 1;
    } while (local_160 < *piVar14);
  }
  iVar15 = 0;
  iVar2 = piVar14[0xd0] * *param_4;
  local_160 = 0;
  iVar9 = *(int *)(iVar9 + *(int *)(param_2 + 0x1c) * 4);
  local_170 = 1;
  if (1 < *(int *)(param_3 + 0x504)) {
    local_154 = (int *)(param_3 + 0x108);
    iVar6 = iVar2;
    do {
      uVar7 = param_4[*local_154] & 0x7fff;
      iVar2 = iVar6;
      if (uVar7 == param_4[*local_154]) {
        iVar15 = piVar14[*local_154 + 0xd1];
        iVar2 = piVar14[0xd0] * uVar7;
        FUN_006b7c40(iVar9 / 2,local_160,iVar15,iVar6,iVar2,param_5);
        local_160 = iVar15;
      }
      local_170 = local_170 + 1;
      local_154 = local_154 + 1;
      iVar6 = iVar2;
    } while (local_170 < *(int *)(param_3 + 0x504));
  }
  if (iVar15 < *(int *)(param_2 + 0x24) / 2) {
    piVar14 = param_5 + iVar15;
    do {
      *piVar14 = iVar2;
      iVar15 = iVar15 + 1;
      piVar14 = piVar14 + 1;
    } while (iVar15 < *(int *)(param_2 + 0x24) / 2);
  }
  return 1;
}

