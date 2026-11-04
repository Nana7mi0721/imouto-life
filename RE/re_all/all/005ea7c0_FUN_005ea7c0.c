
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ea7c0(int *param_1)

{
  uint uVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int *piVar8;
  int iVar9;
  float *pfVar10;
  undefined4 uVar11;
  int iVar12;
  float local_88;
  float local_84;
  undefined4 local_80 [16];
  float local_40 [5];
  float local_2c;
  
  local_80[0] = 0;
  _memset(local_80 + 1,0,0x3c);
  piVar8 = (int *)param_1[2];
  iVar12 = *param_1;
  iVar9 = *(int *)(iVar12 + 8);
  if ((*(int *)(*piVar8 + 8) == 1) || (bVar4 = false, *(int *)(*piVar8 + 8) == 2)) {
    bVar4 = true;
  }
  bVar3 = false;
  if (0 < piVar8[0x16]) {
    iVar6 = piVar8[0x19] * 0x74 + *(int *)(iVar9 + 0x1bc);
    fVar2 = *(float *)(iVar6 + 0x60) - 1.0;
    if (((((float)_DAT_007d6530 < fVar2) || (fVar2 < (float)_DAT_00801ee8)) ||
        (fVar2 = *(float *)(iVar6 + 100) - 1.0, (float)_DAT_007d6530 < fVar2)) ||
       (fVar2 < (float)_DAT_00801ee8)) {
      local_84 = *(float *)(iVar6 + 0x60);
      bVar3 = true;
      local_88 = *(float *)(iVar6 + 100);
    }
  }
  if ((*(int *)(iVar12 + 0x1a4) != 0) || (bVar3)) {
    DAT_00a38d34 = 0;
    if (bVar3) {
      pfVar7 = (float *)(iVar12 + 0x1a8);
      pfVar10 = local_40;
      for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *pfVar10 = *pfVar7;
        pfVar7 = pfVar7 + 1;
        pfVar10 = pfVar10 + 1;
      }
      local_40[0] = local_40[0] * local_84;
      local_2c = local_2c * local_88;
      FUN_005bad70(1,local_40);
      goto LAB_005ea8f0;
    }
    iVar12 = iVar12 + 0x1a8;
    uVar11 = 1;
  }
  else {
    if (DAT_00a38d30 != 0) {
      DAT_00a38d34 = 0;
    }
    iVar12 = 0;
    uVar11 = 0;
  }
  FUN_005bad70(uVar11,iVar12);
LAB_005ea8f0:
  if (*(int *)(param_1[2] + 0x58) == 0) {
    if (DAT_00dda458 < 0) {
      FUN_00582be0();
    }
    iVar12 = FUN_00519300(DAT_00dda458,0);
    if (iVar12 == 0) {
      local_80[0] = 0;
    }
    else {
      local_80[0] = *(undefined4 *)(**(int **)(iVar12 + 0x100) + 8);
    }
  }
  else {
    piVar8 = (int *)(*(int *)(param_1[2] + 100) * 0x74 + *(int *)(iVar9 + 0x1bc));
    iVar12 = *piVar8;
    if (piVar8[0x11] == 0) {
      if (piVar8[0xe] == 0) {
        if (*(int *)(iVar12 + 0x50) == 0) {
          iVar12 = *(int *)(iVar12 + 0x48);
        }
        else {
          iVar12 = *(int *)(iVar12 + 0x54);
        }
      }
      else {
        iVar12 = piVar8[0xf];
      }
    }
    else {
      iVar12 = piVar8[0x12];
    }
    iVar12 = FUN_00519300(iVar12,0);
    if (iVar12 == 0) {
      local_80[0] = 0;
    }
    else {
      local_80[0] = *(undefined4 *)(**(int **)(iVar12 + 0x100) + 8);
    }
    FUN_005bac90(piVar8[0x16],piVar8[0x17],3,0);
    FUN_005b90c0(*(undefined4 *)(&DAT_00a05500 + piVar8[0x1a] * 4),0);
  }
  if (*(int *)(*(int *)(param_1[1] + 4) + 0x168) != 0) {
    piVar8 = (int *)(*(int *)(*(int *)(param_1[1] + 4) + 0x174) * 0x74 + *(int *)(iVar9 + 0x1bc));
    iVar12 = *piVar8;
    if (piVar8[0x11] == 0) {
      if (piVar8[0xe] == 0) {
        if (*(int *)(iVar12 + 0x50) == 0) {
          iVar12 = *(int *)(iVar12 + 0x48);
        }
        else {
          iVar12 = *(int *)(iVar12 + 0x54);
        }
      }
      else {
        iVar12 = piVar8[0xf];
      }
    }
    else {
      iVar12 = piVar8[0x12];
    }
    iVar12 = FUN_00519300(iVar12,0);
    if (iVar12 == 0) {
      local_80[1] = 0;
    }
    else {
      local_80[1] = *(undefined4 *)(**(int **)(iVar12 + 0x100) + 8);
    }
    FUN_005bac90(piVar8[0x16],piVar8[0x17],3,1);
    FUN_005b90c0(*(undefined4 *)(&DAT_00a05500 + piVar8[0x1a] * 4),1);
  }
  if (*(int *)(param_1[2] + 0xdc) == 0) {
    if (DAT_00dda458 < 0) {
      FUN_00582be0();
    }
    iVar12 = FUN_00519300(DAT_00dda458,0);
    if (iVar12 == 0) {
      local_80[2] = 0;
    }
    else {
      local_80[2] = *(undefined4 *)(**(int **)(iVar12 + 0x100) + 8);
    }
  }
  else {
    piVar8 = (int *)(*(int *)(param_1[2] + 0xe8) * 0x74 + *(int *)(iVar9 + 0x1bc));
    iVar12 = *piVar8;
    if (piVar8[0x11] == 0) {
      if (piVar8[0xe] == 0) {
        if (*(int *)(iVar12 + 0x50) == 0) {
          iVar12 = *(int *)(iVar12 + 0x48);
        }
        else {
          iVar12 = *(int *)(iVar12 + 0x54);
        }
      }
      else {
        iVar12 = piVar8[0xf];
      }
    }
    else {
      iVar12 = piVar8[0x12];
    }
    iVar12 = FUN_00519300(iVar12,0);
    if (iVar12 == 0) {
      local_80[2] = 0;
    }
    else {
      local_80[2] = *(undefined4 *)(**(int **)(iVar12 + 0x100) + 8);
    }
    FUN_005bac90(piVar8[0x16],piVar8[0x17],3,2);
    FUN_005b90c0(*(undefined4 *)(&DAT_00a05500 + piVar8[0x1a] * 4),2);
  }
  if (bVar4) {
    iVar12 = ((int *)param_1[2])[0x58];
    if (iVar12 < 0) {
      if (*(int *)(*(int *)param_1[2] + 8) == 1) {
        uVar11 = FUN_00582b00(iVar12);
        iVar12 = FUN_00519300(uVar11,0);
        if (iVar12 == 0) {
          local_80[3] = 0;
        }
        else {
          local_80[3] = *(undefined4 *)(**(int **)(iVar12 + 0x100) + 8);
        }
      }
      else {
        local_80[3] = FUN_005ea790();
      }
    }
    else {
      iVar12 = iVar12 * 0x74 + *(int *)(iVar9 + 0x1bc);
      local_80[3] = FUN_005ea740();
      FUN_005bac90(*(undefined4 *)(iVar12 + 0x58),*(undefined4 *)(iVar12 + 0x5c),3,3);
      FUN_005b90c0(*(undefined4 *)(&DAT_00a05500 + *(int *)(iVar12 + 0x68) * 4),3);
    }
    iVar12 = *(int *)(param_1[2] + 0x164);
    if (iVar12 < 0) {
      uVar11 = FUN_00582b00(iVar12);
      iVar12 = FUN_00519300(uVar11,0);
      if (iVar12 == 0) {
        local_80[4] = 0;
      }
      else {
        local_80[4] = *(undefined4 *)(**(int **)(iVar12 + 0x100) + 8);
      }
    }
    else {
      iVar12 = iVar12 * 0x74 + *(int *)(iVar9 + 0x1bc);
      local_80[4] = FUN_005ea740();
      FUN_005bac90(*(undefined4 *)(iVar12 + 0x58),*(undefined4 *)(iVar12 + 0x5c),3,4);
      FUN_005b90c0(*(undefined4 *)(&DAT_00a05500 + *(int *)(iVar12 + 0x68) * 4),4);
    }
    if (-1 < *(int *)(param_1[2] + 0x168)) {
      piVar8 = (int *)(*(int *)(param_1[2] + 0x168) * 0x74 + *(int *)(iVar9 + 0x1bc));
      if (piVar8[0x11] == 0) {
        if (((piVar8[0xe] == 0) || (piVar8[0x10] != 0)) &&
           ((*(int *)(*piVar8 + 0x50) == 0 &&
            ((*(int *)(*piVar8 + 0x4c) != 0 && (DAT_00dda458 < 0)))))) {
          FUN_00582be0();
        }
        local_80[5] = FUN_005ea720();
      }
      else {
        iVar12 = FUN_00519300(piVar8[0x12],0);
        if (iVar12 == 0) {
          local_80[5] = 0;
        }
        else {
          local_80[5] = *(undefined4 *)(**(int **)(iVar12 + 0x100) + 8);
        }
      }
      FUN_005bac90(piVar8[0x16],piVar8[0x17],3,5);
      FUN_005b90c0(*(undefined4 *)(&DAT_00a05500 + piVar8[0x1a] * 4),5);
    }
    local_80[6] = DAT_00ee9a38;
    FUN_005bac90(3,3,3,6);
    FUN_005b90c0(0x15,6);
  }
  if (1 < *(int *)(param_1[2] + 0x58)) {
    piVar8 = (int *)(*(int *)(param_1[2] + 0x74) * 0x74 + *(int *)(iVar9 + 0x1bc));
    iVar12 = *piVar8;
    if (piVar8[0x11] == 0) {
      if (piVar8[0xe] == 0) {
        if (*(int *)(iVar12 + 0x50) == 0) {
          iVar12 = *(int *)(iVar12 + 0x48);
        }
        else {
          iVar12 = *(int *)(iVar12 + 0x54);
        }
      }
      else {
        iVar12 = piVar8[0xf];
      }
    }
    else {
      iVar12 = piVar8[0x12];
    }
    iVar12 = FUN_00519300(iVar12,0);
    if (iVar12 == 0) {
      local_80[7] = 0;
    }
    else {
      local_80[7] = *(undefined4 *)(**(int **)(iVar12 + 0x100) + 8);
    }
    FUN_005bac90(piVar8[0x16],piVar8[0x17],3,7);
    FUN_005b90c0(*(undefined4 *)(&DAT_00a05500 + piVar8[0x1a] * 4),7);
  }
  iVar6 = 8;
  iVar9 = 0;
  iVar12 = 3;
  do {
    if (*(int *)((int)&DAT_00a380f8 + iVar9) < 1) {
      *(undefined4 *)((int)local_80 + iVar9 + 0x20) = 0;
    }
    else {
      iVar5 = FUN_0051c790(*(int *)((int)&DAT_00a380f8 + iVar9),0);
      if (iVar5 == 0) {
        uVar11 = 0;
      }
      else {
        uVar11 = *(undefined4 *)(*(int *)(iVar5 + 0x450) + 4);
      }
      *(undefined4 *)((int)local_80 + iVar9 + 0x20) = uVar11;
      FUN_005bac90(3,3,3,iVar6);
      FUN_005b90c0(0x15,iVar6);
    }
    iVar6 = iVar6 + 1;
    iVar9 = iVar9 + 4;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  iVar12 = 0xb;
  if (DAT_00dccde4 != 0) {
    iVar9 = -1;
    iVar12 = 0;
    do {
      if (((((DAT_00cc47d0 == 0) || (uVar1 = (&DAT_00a38d78)[iVar12], (int)uVar1 < 0)) ||
           ((uVar1 & 0x7c000000) != DAT_00cc47f8)) ||
          ((DAT_00cc4800 <= (int)(uVar1 & 0xffff) ||
           (piVar8 = *(int **)(DAT_00cc47d4 + (uVar1 & 0xffff) * 4), piVar8 == (int *)0x0)))) ||
         ((*piVar8 * 0x10000 != (uVar1 & 0x3ff0000) || (piVar8[4] != 0)))) {
        if ((((DAT_00cc79c0 != 0) && (uVar1 = (&DAT_00a38d78)[iVar12], -1 < (int)uVar1)) &&
            (((uVar1 & 0x7c000000) == DAT_00cc79e8 &&
             ((((int)(uVar1 & 0xffff) < DAT_00cc79f0 &&
               (piVar8 = *(int **)(DAT_00cc79c4 + (uVar1 & 0xffff) * 4), piVar8 != (int *)0x0)) &&
              (*piVar8 * 0x10000 == (uVar1 & 0x3ff0000))))))) && (piVar8[4] == 0)) {
          local_80[iVar12] = *(undefined4 *)(piVar8[0x114] + 4);
          goto LAB_005eae7c;
        }
      }
      else {
        local_80[iVar12] = *(undefined4 *)(*(int *)piVar8[0x40] + 8);
LAB_005eae7c:
        FUN_005bac90((&DAT_00a37fe0)[iVar12],(&DAT_00a38020)[iVar12],(&DAT_00a38060)[iVar12],iVar12)
        ;
        FUN_005b90c0(*(undefined4 *)(&DAT_00a05500 + DAT_00a380bc * 4),iVar12);
        iVar9 = iVar12;
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < 0x10);
    iVar12 = 0xb;
    if ((0 < iVar9) && (0xb < iVar9 + 1)) {
      iVar12 = iVar9 + 1;
    }
  }
  FUN_005bba30(0,iVar12,local_80);
  return;
}

