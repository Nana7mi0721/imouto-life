
undefined4 FUN_005f4d10(int param_1,uint *param_2,uint *param_3)

{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  uint uVar11;
  bool bVar12;
  uint local_38;
  int local_34;
  undefined4 local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  piVar9 = (int *)0x0;
  piVar6 = (int *)0x0;
  piVar8 = (int *)0x0;
  local_24 = 0;
  if ((((DAT_00cc47d0 == 0) || (local_38 = *(uint *)(param_1 + 8), (int)local_38 < 0)) ||
      ((local_38 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(local_38 & 0xffff) ||
       (piVar8 = *(int **)(DAT_00cc47d4 + (local_38 & 0xffff) * 4), piVar8 == (int *)0x0)) ||
      ((*piVar8 * 0x10000 != (local_38 & 0x3ff0000) || (piVar8[4] != 0)))))) {
    if (DAT_00cc79c0 == 0) {
      return 0xffffffff;
    }
    local_38 = *(uint *)(param_1 + 8);
    if ((int)local_38 < 0) {
      return 0xffffffff;
    }
    if ((local_38 & 0x7c000000) != DAT_00cc79e8) {
      return 0xffffffff;
    }
    if (DAT_00cc79f0 <= (int)(local_38 & 0xffff)) {
      return 0xffffffff;
    }
    piVar6 = *(int **)(DAT_00cc79c4 + (local_38 & 0xffff) * 4);
    if (piVar6 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar6 * 0x10000 != (local_38 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar6[4] != 0) {
      return 0xffffffff;
    }
    local_28 = piVar6[0xd];
  }
  else {
    local_28 = (uint)*(byte *)(piVar8[0x13] + 0x13);
  }
  if (((DAT_00cc47d0 == 0) || (uVar5 = *(uint *)(param_1 + 0x10), (int)uVar5 < 0)) ||
     ((((uVar5 & 0x7c000000) != DAT_00cc47f8 ||
       (((DAT_00cc4800 <= (int)(uVar5 & 0xffff) ||
         (piVar9 = *(int **)(DAT_00cc47d4 + (uVar5 & 0xffff) * 4), piVar9 == (int *)0x0)) ||
        (*piVar9 * 0x10000 != (uVar5 & 0x3ff0000))))) || (piVar9[4] != 0)))) {
    if (DAT_00cc79c0 == 0) {
      return 0xffffffff;
    }
    uVar5 = *(uint *)(param_1 + 0x10);
    if ((int)uVar5 < 0) {
      return 0xffffffff;
    }
    if ((uVar5 & 0x7c000000) != DAT_00cc79e8) {
      return 0xffffffff;
    }
    if (DAT_00cc79f0 <= (int)(uVar5 & 0xffff)) {
      return 0xffffffff;
    }
    piVar1 = *(int **)(DAT_00cc79c4 + (uVar5 & 0xffff) * 4);
    if (piVar1 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar1 * 0x10000 != (uVar5 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar1[4] != 0) {
      return 0xffffffff;
    }
    local_2c = piVar1[0xd];
  }
  else {
    local_2c = (uint)*(byte *)(piVar9[0x13] + 0x13);
  }
  local_30 = 0;
  if ((piVar6 == (int *)0x0) && ((local_38 == uVar5 || (*(char *)(piVar9[0x13] + 0xb) == '\0')))) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (*(int *)(param_1 + 0x4c) == 1) {
    uVar4 = *(uint *)(param_1 + 0x1c) & 0x80000001;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
    }
    if (uVar4 != 0) {
LAB_005f4f31:
      if (uVar4 == 1) {
        uVar4 = *(uint *)(param_1 + 0x48) & 0x80000001;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
        }
        if (uVar4 == 1) goto LAB_005f4f48;
      }
      goto LAB_005f4f4c;
    }
    uVar11 = *(uint *)(param_1 + 0x48) & 0x80000001;
    bVar12 = uVar11 == 0;
    if ((int)uVar11 < 0) {
      bVar12 = (uVar11 - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (!bVar12) goto LAB_005f4f31;
LAB_005f4f48:
    bVar12 = true;
  }
  else {
LAB_005f4f4c:
    bVar12 = false;
  }
  if (((piVar6 == (int *)0x0) && (*(int *)(param_1 + 0x1c) == 0)) &&
     ((piVar8[0x22] != 1 || ((piVar8[0x27] != 0 || (piVar8[0x28] != 0)))))) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (bVar2) {
    if (bVar12) goto LAB_005f4f95;
    uVar10 = 1;
    local_30 = 0;
  }
  else {
    if (!bVar12) {
      *param_3 = uVar5;
      goto LAB_005f4fe9;
    }
LAB_005f4f95:
    uVar10 = 0;
    local_30 = 1;
  }
  if (bVar3) {
    local_38 = piVar8[0x18];
    local_34 = piVar8[0x19];
  }
  else {
    FUN_005159a0(local_38,&local_38,&local_34);
  }
  uVar5 = FUN_005f2200(uVar10);
  *param_3 = uVar5;
  if ((int)uVar5 < 0) {
    return 0xffffffff;
  }
LAB_005f4fe9:
  if (bVar3) {
    local_38 = piVar8[0x18];
    local_34 = piVar8[0x19];
    uVar5 = FUN_005f2200(local_30);
    *param_2 = uVar5;
    if ((int)uVar5 < 0) {
      return 0xffffffff;
    }
    if ((((DAT_00cc47d0 != 0) && (-1 < (int)uVar5)) && ((uVar5 & 0x7c000000) == DAT_00cc47f8)) &&
       ((int)(uVar5 & 0xffff) < DAT_00cc4800)) {
      local_24 = *(int *)(DAT_00cc47d4 + (uVar5 & 0xffff) * 4);
    }
    iVar7 = 0;
    if (0 < piVar8[0x22]) {
      piVar6 = piVar8 + 0x28;
      do {
        local_10 = piVar6[-1];
        local_c = *piVar6;
        local_1c = piVar6[-4];
        local_8 = local_10 + piVar6[3];
        local_4 = local_c + piVar6[4];
        local_20 = piVar6[-5];
        local_18 = local_20 + piVar6[3];
        local_14 = local_1c + piVar6[4];
        FUN_005caf30(*(undefined4 *)(*(int *)piVar6[0x18] + 4),
                     *(undefined4 *)(*(int *)piVar6[0x18] + 8),&local_10,
                     *(undefined4 *)(**(int **)(local_24 + 0x100) + 4),
                     **(undefined4 **)(**(int **)(local_24 + 0x100) + 0xc),&local_20,0,0,0,0,0,0,0,0
                    );
        iVar7 = iVar7 + 1;
        piVar6 = piVar6 + 0x1e;
      } while (iVar7 < piVar8[0x22]);
    }
  }
  return 0;
}

