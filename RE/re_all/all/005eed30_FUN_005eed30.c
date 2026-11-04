
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005eed30(int param_1,uint *param_2,uint *param_3)

{
  byte bVar1;
  int *piVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  undefined4 uVar11;
  char cVar12;
  int iVar13;
  bool bVar14;
  uint local_8c;
  undefined4 local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  int local_78;
  int local_74;
  float local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  int local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  int local_4;
  
  piVar9 = (int *)0x0;
  piVar7 = (int *)0x0;
  piVar8 = (int *)0x0;
  local_74 = 0;
  if ((((DAT_00cc47d0 == 0) || (local_8c = *(uint *)(param_1 + 8), (int)local_8c < 0)) ||
      ((local_8c & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(local_8c & 0xffff) ||
       (piVar8 = *(int **)(DAT_00cc47d4 + (local_8c & 0xffff) * 4), piVar8 == (int *)0x0)) ||
      ((*piVar8 * 0x10000 != (local_8c & 0x3ff0000) || (piVar8[4] != 0)))))) {
    if (DAT_00cc79c0 == 0) {
      return 0xffffffff;
    }
    local_8c = *(uint *)(param_1 + 8);
    if ((int)local_8c < 0) {
      return 0xffffffff;
    }
    if ((local_8c & 0x7c000000) != DAT_00cc79e8) {
      return 0xffffffff;
    }
    if (DAT_00cc79f0 <= (int)(local_8c & 0xffff)) {
      return 0xffffffff;
    }
    piVar7 = *(int **)(DAT_00cc79c4 + (local_8c & 0xffff) * 4);
    if (piVar7 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar7 * 0x10000 != (local_8c & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar7[4] != 0) {
      return 0xffffffff;
    }
    local_80 = piVar7[0xd];
    local_84 = 0x10;
  }
  else {
    iVar13 = piVar8[0x13];
    bVar1 = *(byte *)(iVar13 + 0xf);
    if ((bVar1 < 0x11) || (0x16 < bVar1)) {
      local_80 = (uint)*(byte *)(iVar13 + 0x13);
      local_84 = (uint)*(byte *)(iVar13 + 0x16);
    }
    else {
      local_84 = (-(uint)(0x13 < bVar1) & 0x10) + 0x10;
      local_80 = 1;
    }
  }
  if ((((DAT_00cc47d0 == 0) || (uVar5 = *(uint *)(param_1 + 0x10), (int)uVar5 < 0)) ||
      ((uVar5 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(uVar5 & 0xffff) ||
       (piVar9 = *(int **)(DAT_00cc47d4 + (uVar5 & 0xffff) * 4), piVar9 == (int *)0x0)) ||
      ((*piVar9 * 0x10000 != (uVar5 & 0x3ff0000) || (piVar9[4] != 0)))))) {
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
    piVar2 = *(int **)(DAT_00cc79c4 + (uVar5 & 0xffff) * 4);
    if (piVar2 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar2 * 0x10000 != (uVar5 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar2[4] != 0) {
      return 0xffffffff;
    }
    local_7c = piVar2[0xd];
    cVar12 = '\x10';
  }
  else {
    bVar1 = *(byte *)(piVar9[0x13] + 0xf);
    if ((bVar1 < 0x11) || (0x16 < bVar1)) {
      local_7c = (uint)*(byte *)(piVar9[0x13] + 0x13);
      cVar12 = *(char *)(piVar9[0x13] + 0x16);
    }
    else {
      local_7c = 1;
      cVar12 = (-(0x13 < bVar1) & 0x10U) + 0x10;
    }
  }
  bVar6 = false;
  local_88 = 0;
  if (DAT_00a37dc8 == 0) {
    *param_3 = uVar5;
    return 0;
  }
  if ((piVar7 == (int *)0x0) &&
     (((*(int *)(param_1 + 0x4c) == 1 && (local_8c == uVar5)) ||
      (*(char *)(piVar9[0x13] + 0xb) == '\0')))) {
    bVar6 = true;
  }
  if (*(int *)(param_1 + 0x4c) == 1) {
    uVar4 = *(uint *)(param_1 + 0x1c) & 0x80000001;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
    }
    if (uVar4 != 0) {
LAB_005eeffe:
      if (uVar4 == 1) {
        uVar4 = *(uint *)(param_1 + 0x48) & 0x80000001;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
        }
        if (uVar4 == 1) goto LAB_005ef017;
      }
      goto LAB_005ef01e;
    }
    uVar10 = *(uint *)(param_1 + 0x48) & 0x80000001;
    bVar14 = uVar10 == 0;
    if ((int)uVar10 < 0) {
      bVar14 = (uVar10 - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (!bVar14) goto LAB_005eeffe;
LAB_005ef017:
    bVar14 = true;
  }
  else {
LAB_005ef01e:
    bVar14 = false;
  }
  if (((piVar7 != (int *)0x0) || (*(int *)(param_1 + 0x1c) != 0)) ||
     ((bVar3 = true, piVar8[0x22] == 1 && ((piVar8[0x27] == 0 && (piVar8[0x28] == 0)))))) {
    bVar3 = false;
  }
  if (bVar6) {
    if (bVar14) goto LAB_005ef06c;
    local_88 = 0;
    uVar11 = 1;
  }
  else {
    if (!bVar14) {
      *param_3 = uVar5;
      goto LAB_005ef0c9;
    }
LAB_005ef06c:
    uVar11 = 0;
    local_88 = 1;
  }
  if (bVar3) {
    local_8c = piVar8[0x18];
    local_78 = piVar8[0x19];
  }
  else {
    FUN_005159a0(local_8c,&local_8c,&local_78);
  }
  uVar5 = FUN_005ee170(local_7c,cVar12,uVar11);
  *param_3 = uVar5;
  if ((int)uVar5 < 0) {
    return 0xffffffff;
  }
LAB_005ef0c9:
  if (bVar3) {
    local_8c = piVar8[0x18];
    local_78 = piVar8[0x19];
    uVar5 = FUN_005ee170(local_80,local_84,local_88);
    *param_2 = uVar5;
    if ((int)uVar5 < 0) {
      return 0xffffffff;
    }
    if ((((DAT_00cc47d0 == 0) || ((int)uVar5 < 0)) || ((uVar5 & 0x7c000000) != DAT_00cc47f8)) ||
       (DAT_00cc4800 <= (int)(uVar5 & 0xffff))) {
      iVar13 = local_74;
    }
    else {
      iVar13 = *(int *)(DAT_00cc47d4 + (uVar5 & 0xffff) * 4);
    }
    FUN_005a0bd0(*(undefined4 *)(**(int **)(iVar13 + 0x100) + 4),0);
    local_64 = 0x3f800000;
    local_48 = 0x3f800000;
    iVar13 = 0;
    local_2c = 0x3f800000;
    local_10 = 0x3f800000;
    local_60 = 0xffffffff;
    local_44 = 0xffffffff;
    local_28 = 0xffffffff;
    local_c = 0xffffffff;
    if (0 < piVar8[0x22]) {
      piVar7 = piVar8 + 0x31;
      do {
        local_18 = (float)_DAT_00804a60;
        local_70 = (float)piVar7[-2] - local_18;
        local_6c = (float)piVar7[-1] - local_18;
        local_68 = 0;
        local_5c = *piVar7;
        local_58 = piVar7[1];
        local_54 = (float)piVar7[2] - local_18;
        local_50 = (float)piVar7[3] - local_18;
        local_4c = 0;
        local_40 = piVar7[4];
        local_3c = piVar7[5];
        local_38 = (float)piVar7[6] - local_18;
        local_34 = (float)piVar7[7] - local_18;
        local_24 = piVar7[8];
        local_20 = piVar7[9];
        local_30 = 0;
        local_1c = (float)piVar7[10] - local_18;
        local_18 = (float)piVar7[0xb] - local_18;
        local_14 = 0;
        local_8 = piVar7[0xc];
        local_4 = piVar7[0xd];
        FUN_005b40c0(&local_70,4,5,piVar8,1,0,0,0,0,iVar13,0);
        iVar13 = iVar13 + 1;
        piVar7 = piVar7 + 0x1e;
      } while (iVar13 < piVar8[0x22]);
    }
  }
  return 0;
}

