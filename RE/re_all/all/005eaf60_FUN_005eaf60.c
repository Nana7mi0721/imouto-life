
undefined4 FUN_005eaf60(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int in_EAX;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  bool bVar15;
  int *local_4c;
  undefined4 *local_48;
  int *local_44;
  int *local_40;
  undefined4 *local_3c;
  int local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  uint local_1c;
  int local_18;
  
  piVar2 = *(int **)(in_EAX + 8);
  iVar8 = *piVar2;
  local_2c = (int *)0x0;
  local_30 = (int *)0x0;
  local_28 = (int *)0x0;
  local_40 = (int *)0x0;
  local_4c = (int *)0x0;
  local_48 = (undefined4 *)0x0;
  if ((DAT_00f29d50 == 0) && (iVar6 = FUN_005b77f0(), iVar6 == 0)) {
    return 0;
  }
  if (param_1 == 3) {
    param_1 = 0;
  }
  if (piVar2[100] == 0) {
    iVar6 = 0;
    FUN_005bb2e0(0xffffffff);
  }
  else {
    iVar6 = FUN_005b8460(piVar2[100],piVar2[0x65]);
    FUN_005bb2e0(piVar2[0x66]);
  }
  iVar3 = *(int *)(*piVar2 + 8);
  uVar10 = (uint)(DAT_00a38104 != 0);
  uVar11 = -(uint)(DAT_00f07360 != 0) & DAT_00f07364;
  if ((iVar3 == 1) || (bVar5 = false, iVar3 == 2)) {
    bVar5 = true;
  }
  uVar7 = (uint)(0 < *(int *)(iVar8 + 0x168));
  if (*(int *)(iVar8 + 0x60) < 2) {
    local_34 = 0;
  }
  else {
    local_34 = *(int *)(iVar8 + 0x80) + 1;
  }
  if (param_2 == 0) {
    if (DAT_00a3810c != 0) {
      local_44 = &DAT_00ef5544 + uVar7 + param_1 * 2;
      local_3c = (undefined4 *)(&DAT_00f2b018 + (uVar7 + param_1 * 2) * 8);
      if (bVar5) {
        if (iVar3 == 1) {
          local_4c = &DAT_00ef64bc + iVar6 + (uint)(piVar2[0x5b] == 2) * 2;
          local_48 = &DAT_00f2cf08 + (iVar6 + (uint)(piVar2[0x5b] == 2) * 2) * 2;
          goto LAB_005eb0a1;
        }
        if (iVar3 == 2) {
          iVar8 = 0;
          if (-1 < piVar2[0x5a]) {
            if (piVar2[0x5d] == 1) {
              iVar8 = 2;
            }
            else if (piVar2[0x5d] == 2) {
              iVar8 = 1;
            }
          }
          iVar6 = iVar6 + iVar8 * 4;
          local_4c = (int *)(&DAT_00ef64ec + iVar6 * 4);
          local_48 = (undefined4 *)(&DAT_00f2cf68 + iVar6 * 8);
        }
      }
      else {
        local_4c = &DAT_00ef651c + iVar6;
        local_48 = (undefined4 *)(&DAT_00f2cfc8 + iVar6 * 8);
      }
      goto LAB_005eb0a5;
    }
    if ((2 < iVar3) && (iVar3 < 9)) {
      iVar8 = uVar7 + param_1 * 2;
      local_3c = &DAT_00f2b048 + iVar8 * 8;
      local_4c = &DAT_00ef5484 + iVar6 + *(int *)(*piVar2 + 8) * 2;
      local_48 = &DAT_00f2ae98 + (iVar6 + *(int *)(*piVar2 + 8) * 2) * 2;
      local_44 = &DAT_00ef555c + iVar8 * 4;
      goto LAB_005eb0a5;
    }
    if (DAT_00f07614 == 0) {
      iVar8 = uVar11 + (uVar7 + param_1 * 2) * 4;
      local_44 = &DAT_00ef555c + iVar8;
      local_3c = &DAT_00f2b048 + iVar8 * 2;
      if (bVar5) {
        if (iVar3 == 1) {
          local_4c = &DAT_00ef6524 + iVar6 + (uint)(piVar2[0x5b] == 2) * 2;
          local_48 = (undefined4 *)(&DAT_00f2cfd8 + (iVar6 + (uint)(piVar2[0x5b] == 2) * 2) * 8);
          goto LAB_005eb0a1;
        }
        if (iVar3 == 2) {
          local_4c = (int *)(&DAT_00ef6534 + iVar6 * 4);
          local_48 = (undefined4 *)(&DAT_00f2cff8 + iVar6 * 8);
        }
      }
      else {
        local_4c = &DAT_00ef6544 + iVar6 + local_34 * 2;
        local_48 = (undefined4 *)(&DAT_00f2d018 + (iVar6 + local_34 * 2) * 8);
      }
      goto LAB_005eb0a5;
    }
    bVar15 = DAT_00f0738c == 0;
    if (bVar15) {
      local_18 = 0;
    }
    else {
      local_18 = DAT_00f073a4;
    }
    local_44 = (int *)(uint)!bVar15;
    piVar12 = (int *)(uint)!bVar15;
    if (DAT_00f07390 == 0) {
      iVar8 = 0;
    }
    else {
      piVar12 = (int *)((int)piVar12 + 1);
      iVar8 = DAT_00f0740c;
      local_44 = piVar12;
    }
    iVar13 = 0;
    if (DAT_00f07394 != 0) {
      piVar12 = (int *)((int)piVar12 + 1);
      iVar13 = DAT_00f07474;
      local_44 = piVar12;
    }
    if (DAT_00f07398 != 0) {
      piVar12 = (int *)((int)piVar12 + 1);
      local_44 = piVar12;
    }
    if (DAT_00f0739c != 0) {
      piVar12 = (int *)((int)piVar12 + 1);
      local_44 = piVar12;
    }
    if (DAT_00f073a0 != 0) {
      piVar12 = (int *)((int)piVar12 + 1);
      local_44 = piVar12;
    }
    if (local_18 == 3) {
      uVar14 = 2;
    }
    else {
      uVar14 = (uint)(local_18 != 0);
    }
    if (iVar8 == 3) {
      local_1c = 2;
    }
    else {
      local_1c = (uint)(iVar8 != 0);
      piVar12 = local_44;
    }
    if (iVar13 == 3) {
      local_2c = (int *)0x2;
      local_44 = piVar12;
    }
    else {
      local_2c = (int *)(uint)(iVar13 != 0);
    }
    iVar9 = (int)(short)(&DAT_00f22434)[(int)local_2c + (local_1c + uVar14 * 3) * 3];
    iVar4 = uVar10 * 3;
    iVar1 = uVar11 + (uVar7 + (param_1 + iVar4) * 2) * 4;
    local_2c = &DAT_00ef4be4 + iVar1;
    local_30 = &DAT_00f29d58 + iVar1 * 2;
    iVar8 = (int)(short)(&DAT_00f223b4)[iVar13 + (iVar8 + local_18 * 4) * 4] + iVar1 * 0x14;
    piVar12 = &DAT_00ef55bc + iVar8;
    local_3c = &DAT_00f2b108 + iVar8 * 2;
    if (bVar5) {
      if (iVar3 == 1) {
        if (local_44 != (int *)0x0) {
          iVar8 = (int)local_44 +
                  (uVar7 + ((uint)(piVar2[0x5c] == 1) + ((uint)(piVar2[0x5b] == 2) + uVar10 * 2) * 2
                           ) * 2) * 6;
          local_28 = (int *)(&DAT_00ef4c9c + (iVar6 + iVar8 * 2) * 4);
          local_40 = (int *)(&DAT_00f29ec8 + (iVar6 + iVar8 * 2) * 8);
        }
        iVar9 = iVar9 + (uVar7 + ((uint)(piVar2[0x5c] == 1) +
                                 ((uint)(piVar2[0x5b] == 2) + uVar10 * 2) * 2) * 2) * 10;
        local_4c = &DAT_00ef656c + iVar6 + iVar9 * 2;
        local_48 = &DAT_00f2d068 + (iVar6 + iVar9 * 2) * 2;
      }
      else if (iVar3 == 2) {
        iVar8 = 0;
        if (-1 < piVar2[0x5a]) {
          if (piVar2[0x5d] == 1) {
            iVar8 = 2;
          }
          else if (piVar2[0x5d] == 2) {
            iVar8 = 1;
          }
        }
        if (local_44 != (int *)0x0) {
          iVar3 = (int)local_44 + (iVar4 + iVar8) * 6;
          local_28 = (int *)(&DAT_00ef4f9c + (iVar6 + iVar3 * 2) * 4);
          local_40 = (int *)(&DAT_00f2a4c8 + (iVar6 + iVar3 * 2) * 8);
        }
        iVar9 = iVar9 + (iVar4 + iVar8) * 10;
        local_4c = &DAT_00ef6a6c + iVar6 + iVar9 * 2;
        local_48 = &DAT_00f2da68 + (iVar6 + iVar9 * 2) * 2;
      }
    }
    else {
      if (local_44 != (int *)0x0) {
        iVar8 = (int)local_44 + (uVar7 + (local_34 + uVar10 * 5) * 2) * 6;
        local_28 = (int *)(&DAT_00ef50bc + (iVar6 + iVar8 * 2) * 4);
        local_40 = (int *)(&DAT_00f2a708 + (iVar6 + iVar8 * 2) * 8);
      }
      iVar9 = iVar9 + (uVar7 + (local_34 + uVar10 * 5) * 2) * 10;
      local_4c = &DAT_00ef6c4c + iVar6 + iVar9 * 2;
      local_48 = &DAT_00f2de28 + (iVar6 + iVar9 * 2) * 2;
    }
    local_44 = piVar12;
    if ((((local_30 == (int *)0x0) || (*local_30 == 0)) || (local_40 == (int *)0x0)) ||
       (*local_40 == 0)) goto LAB_005eb0a5;
    bVar5 = true;
  }
  else {
    iVar8 = uVar7 + param_1 * 2;
    if (DAT_00a3810c == 0) {
      local_3c = &DAT_00f2af58 + (uVar11 + (uVar7 + param_1 * 2) * 4) * 2;
      local_4c = &DAT_00ef6544 + iVar6;
      local_48 = (undefined4 *)(&DAT_00f2d018 + iVar6 * 8);
      local_44 = &DAT_00ef54e4 + uVar11 + iVar8 * 4;
    }
    else {
      local_44 = &DAT_00ef54cc + iVar8;
      local_3c = (undefined4 *)(&DAT_00f2af28 + (uVar7 + param_1 * 2) * 8);
      local_4c = &DAT_00ef651c + iVar6;
      local_48 = (undefined4 *)(&DAT_00f2cfc8 + iVar6 * 8);
LAB_005eb0a1:
    }
LAB_005eb0a5:
    bVar5 = false;
  }
  if (DAT_00dccde4 != 0) {
    bVar15 = true;
    if ((0 < DAT_00a38dd8) && (iVar8 = FUN_005c2c70(DAT_00a38dd8), iVar8 < 0)) {
      bVar15 = false;
    }
    if (((DAT_00a38ddc < 1) || (iVar8 = FUN_005c2ce0(DAT_00a38ddc), -1 < iVar8)) && (bVar15))
    goto LAB_005eb73e;
  }
  if (((DAT_00a3ce50 < 4) && (DAT_00ee9a30 == 0)) || (!bVar5)) {
    if ((*local_44 == 0) && (iVar8 = FUN_005b83c0(local_3c,local_44,1), iVar8 != 0)) {
      FUN_0056bca0(&DAT_00802490);
      return 0;
    }
    FUN_005bb6f0(*local_44,0);
    if ((*local_4c == 0) && (iVar8 = FUN_005b8410(local_48,local_4c,1), iVar8 != 0)) {
      FUN_0056bca0(&DAT_00802430);
      return 0;
    }
    iVar8 = *local_4c;
  }
  else {
    if ((*local_2c == 0) && (iVar8 = FUN_005b83c0(local_30,local_2c,1), iVar8 != 0)) {
      FUN_0056bca0(&DAT_00802550);
      return 0;
    }
    FUN_005bb6f0(*local_2c,0);
    if ((*local_28 == 0) && (iVar8 = FUN_005b8410(local_40,local_28,1), iVar8 != 0)) {
      FUN_0056bca0(&DAT_008024f0);
      return 0;
    }
    iVar8 = *local_28;
  }
  FUN_005bb880(iVar8,0);
LAB_005eb73e:
  iVar8 = param_1 + uVar7 * 3;
  if ((&DAT_00ef72b0)[iVar8] == 0) {
    FUN_005bca00(uVar7,param_1);
  }
  FUN_005bb6a0((&DAT_00ef72b0)[iVar8]);
  return 1;
}

