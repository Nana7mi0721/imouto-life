
undefined4 FUN_0060b000(int param_1,int param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  int iVar12;
  undefined1 *local_2c;
  int local_20;
  int local_18;
  int local_8;
  undefined1 *local_4;
  
  iVar2 = param_2;
  local_8 = 0;
  local_4 = (undefined1 *)0x0;
  iVar12 = 0;
  while (((*(int *)(param_1 + 0x934) == 0 || (*(int *)(param_1 + 0x938) != 0)) ||
         (iVar5 = FUN_005d5f00(**(undefined4 **)(param_1 + 0x954),&local_8,0,0,param_3),
         iVar3 = local_8, iVar5 != 0))) {
    FUN_005fb1b0(param_1,param_3);
    iVar12 = iVar12 + 1;
    if (2 < iVar12) {
      return 0;
    }
  }
  puVar9 = *(undefined1 **)(param_2 + 8);
  local_2c = *(undefined1 **)(param_2 + 0xc);
  if (*(int *)(param_1 + 0x93c) == 0x32315659) {
    if ((*(int *)(param_2 + 0x10) == *(int *)(param_2 + 0x1c) * 2) &&
       (*(int *)(param_2 + 0x14) == *(int *)(param_2 + 0x20) * 2)) {
      puVar8 = local_2c + 1;
      param_2 = 0;
      puVar11 = local_4;
      if (0 < *(int *)(iVar2 + 0x14)) {
        do {
          FUN_0056d420(puVar11,puVar9,*(undefined4 *)(iVar2 + 0x10));
          param_2 = param_2 + 1;
          puVar11 = puVar11 + iVar3;
          puVar9 = puVar9 + *(int *)(iVar2 + 0x18);
        } while (param_2 < *(int *)(iVar2 + 0x14));
      }
      param_2 = 0;
      if (0 < *(int *)(iVar2 + 0x20)) {
        do {
          iVar12 = 0;
          if (0 < *(int *)(iVar2 + 0x1c)) {
            puVar9 = puVar8;
            do {
              uVar1 = *puVar9;
              puVar9 = puVar9 + 2;
              puVar11[iVar12] = uVar1;
              iVar12 = iVar12 + 1;
            } while (iVar12 < *(int *)(iVar2 + 0x1c));
          }
          param_2 = param_2 + 1;
          puVar11 = puVar11 + iVar3 / 2;
          puVar8 = puVar8 + *(int *)(iVar2 + 0x24);
        } while (param_2 < *(int *)(iVar2 + 0x20));
      }
      iVar12 = 0;
      if (0 < *(int *)(iVar2 + 0x20)) {
        do {
          iVar5 = 0;
          if (0 < *(int *)(iVar2 + 0x1c)) {
            puVar9 = local_2c;
            do {
              uVar1 = *puVar9;
              puVar9 = puVar9 + 2;
              puVar11[iVar5] = uVar1;
              iVar5 = iVar5 + 1;
            } while (iVar5 < *(int *)(iVar2 + 0x1c));
          }
          iVar12 = iVar12 + 1;
          puVar11 = puVar11 + iVar3 / 2;
          local_2c = local_2c + *(int *)(iVar2 + 0x24);
        } while (iVar12 < *(int *)(iVar2 + 0x20));
      }
    }
  }
  else if (*(int *)(param_1 + 0x93c) == 0x32595559) {
    if ((*(int *)(param_2 + 0x10) == *(int *)(param_2 + 0x1c) * 2) &&
       (*(int *)(param_2 + 0x14) == *(int *)(param_2 + 0x20) * 2)) {
      iVar2 = *(int *)(param_2 + 0x18);
      iVar12 = *(int *)(param_2 + 0x10);
      iVar3 = *(int *)(param_2 + 0x1c);
      iVar5 = *(int *)(param_2 + 0x24);
      iVar4 = *(int *)(param_2 + 0x10);
      iVar6 = *(int *)(param_2 + 0x10) / 2;
      local_18 = *(int *)(param_2 + 0x14) / 2;
      if (0 < local_18) {
        puVar11 = local_4;
        do {
          if (0 < iVar6) {
            puVar10 = puVar11 + local_8;
            puVar8 = local_2c;
            local_20 = iVar6;
            do {
              *puVar11 = *puVar9;
              puVar10[2 - local_8] = puVar9[1];
              *puVar10 = puVar9[*(int *)(param_2 + 0x18)];
              puVar11 = puVar11 + 4;
              puVar10[2] = puVar9[*(int *)(param_2 + 0x18) + 1];
              puVar9 = puVar9 + 2;
              puVar10[1 - local_8] = *puVar8;
              puVar10[1] = *puVar8;
              local_2c = puVar8 + 2;
              puVar10[3 - local_8] = puVar8[1];
              puVar10[3] = puVar8[1];
              puVar10 = puVar10 + 4;
              local_20 = local_20 + -1;
              puVar8 = local_2c;
            } while (local_20 != 0);
          }
          puVar11 = puVar11 + (local_8 - iVar4) * 2;
          puVar9 = puVar9 + (iVar2 * 2 - iVar12);
          local_2c = local_2c + iVar5 + iVar3 * -2;
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
    }
  }
  else if (((*(int *)(param_1 + 0x93c) == 0x59565955) &&
           (*(int *)(param_2 + 0x10) == *(int *)(param_2 + 0x1c) * 2)) &&
          (*(int *)(param_2 + 0x14) == *(int *)(param_2 + 0x20) * 2)) {
    iVar2 = *(int *)(param_2 + 0x18);
    iVar12 = *(int *)(param_2 + 0x10);
    iVar3 = *(int *)(param_2 + 0x1c);
    iVar5 = *(int *)(param_2 + 0x24);
    iVar4 = *(int *)(param_2 + 0x10);
    iVar6 = *(int *)(param_2 + 0x10) / 2;
    local_18 = *(int *)(param_2 + 0x14) / 2;
    if (0 < local_18) {
      puVar11 = local_4;
      do {
        iVar7 = iVar6;
        if (0 < iVar6) {
          do {
            puVar11[1] = *puVar9;
            puVar11[3] = puVar9[1];
            puVar11[local_8 + 1] = puVar9[*(int *)(param_2 + 0x18)];
            puVar8 = puVar9 + *(int *)(param_2 + 0x18) + 1;
            puVar9 = puVar9 + 2;
            puVar11[local_8 + 3] = *puVar8;
            *puVar11 = *local_2c;
            puVar11[local_8] = *local_2c;
            puVar11[2] = local_2c[1];
            puVar11[local_8 + 2] = local_2c[1];
            puVar11 = puVar11 + 4;
            local_2c = local_2c + 2;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
        puVar11 = puVar11 + (local_8 - iVar4) * 2;
        puVar9 = puVar9 + (iVar2 * 2 - iVar12);
        local_2c = local_2c + iVar5 + iVar3 * -2;
        local_18 = local_18 + -1;
      } while (local_18 != 0);
    }
  }
  FUN_005d5f60(**(undefined4 **)(param_1 + 0x954),param_3);
  *(undefined4 *)(param_1 + 0x940) = 1;
  return 0;
}

