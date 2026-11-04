
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005ee5d0(int param_1,float *param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  int iVar8;
  int *unaff_ESI;
  undefined4 uVar9;
  float local_dc;
  int local_d8;
  float local_c4;
  float local_c0;
  float local_bc;
  int *local_ac;
  int local_a8;
  int local_a4;
  float local_a0;
  float local_9c;
  undefined4 local_98;
  undefined4 local_94;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  undefined4 local_70;
  undefined4 local_6c;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_ac = (int *)0x0;
  if (((((DAT_00cc47d0 == 0) || (uVar1 = unaff_ESI[2], (int)uVar1 < 0)) ||
       ((uVar1 & 0x7c000000) != DAT_00cc47f8)) ||
      ((DAT_00cc4800 <= (int)(uVar1 & 0xffff) ||
       (piVar2 = *(int **)(DAT_00cc47d4 + (uVar1 & 0xffff) * 4), piVar2 == (int *)0x0)))) ||
     ((*piVar2 * 0x10000 != (uVar1 & 0x3ff0000) || (piVar2[4] != 0)))) {
    if (DAT_00cc79c0 == 0) {
      return 0xffffffff;
    }
    uVar1 = unaff_ESI[2];
    if ((int)uVar1 < 0) {
      return 0xffffffff;
    }
    if ((uVar1 & 0x7c000000) != DAT_00cc79e8) {
      return 0xffffffff;
    }
    if (DAT_00cc79f0 <= (int)(uVar1 & 0xffff)) {
      return 0xffffffff;
    }
    piVar2 = *(int **)(DAT_00cc79c4 + (uVar1 & 0xffff) * 4);
    if (piVar2 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar2 * 0x10000 != (uVar1 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar2[4] != 0) {
      return 0xffffffff;
    }
  }
  if ((((DAT_00cc47d0 == 0) || (uVar1 = unaff_ESI[4], (int)uVar1 < 0)) ||
      (((uVar1 & 0x7c000000) != DAT_00cc47f8 ||
       (((DAT_00cc4800 <= (int)(uVar1 & 0xffff) ||
         (local_ac = *(int **)(DAT_00cc47d4 + (uVar1 & 0xffff) * 4), local_ac == (int *)0x0)) ||
        (*local_ac * 0x10000 != (uVar1 & 0x3ff0000))))))) || (local_ac[4] != 0)) {
    if (DAT_00cc79c0 == 0) {
      return 0xffffffff;
    }
    uVar1 = unaff_ESI[4];
    if ((int)uVar1 < 0) {
      return 0xffffffff;
    }
    if ((uVar1 & 0x7c000000) != DAT_00cc79e8) {
      return 0xffffffff;
    }
    if (DAT_00cc79f0 <= (int)(uVar1 & 0xffff)) {
      return 0xffffffff;
    }
    piVar2 = *(int **)(DAT_00cc79c4 + (uVar1 & 0xffff) * 4);
    if (piVar2 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar2 * 0x10000 != (uVar1 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar2[4] != 0) {
      return 0xffffffff;
    }
    uVar9 = *(undefined4 *)(piVar2[0x114] + 4);
  }
  else {
    iVar8 = FUN_005176a0(uVar1);
    if (iVar8 == 0) {
      uVar9 = *(undefined4 *)(*(int *)local_ac[0x40] + 4);
    }
    else {
      uVar9 = *(undefined4 *)(*(int *)local_ac[0x40] + 0x1c);
    }
  }
  FUN_005a0bd0(uVar9,0);
  if (param_2 == (float *)0x0) {
    iVar3 = unaff_ESI[8];
    iVar4 = unaff_ESI[10];
    iVar5 = unaff_ESI[9];
    iVar6 = unaff_ESI[0xb];
    local_d8 = iVar4 - iVar3;
    iVar8 = iVar6 - iVar5;
    if (param_1 == 1) {
      fVar7 = (float)_DAT_00804a60;
      local_c4 = (float)unaff_ESI[0x10] - fVar7;
      local_bc = (float)(unaff_ESI[0x10] + local_d8) - fVar7;
      local_c0 = (float)unaff_ESI[0x11] - fVar7;
      fVar7 = (float)(unaff_ESI[0x11] + iVar8) - fVar7;
    }
    else {
      fVar7 = (float)_DAT_00804a60;
      local_c4 = (float)unaff_ESI[0x10] - fVar7;
      local_bc = (float)(local_d8 / param_1 + unaff_ESI[0x10]) - fVar7;
      local_c0 = (float)unaff_ESI[0x11] - fVar7;
      fVar7 = (float)(iVar8 / param_1 + unaff_ESI[0x11]) - fVar7;
    }
    FUN_005159a0(unaff_ESI[2],&local_a8,&local_a4);
    local_88 = (float)iVar3 / (float)local_a8;
    local_60 = (float)iVar4 / (float)local_a8;
    local_84 = (float)iVar5 / (float)local_a4;
    local_34 = (float)iVar6 / (float)local_a4;
    local_a0 = local_c4;
    local_9c = local_c0;
    local_98 = 0;
    local_78 = local_bc;
    local_74 = local_c0;
    local_70 = 0;
    local_50 = local_c4;
    local_48 = 0;
    local_28 = local_bc;
    local_20 = 0;
    local_94 = 0x3f800000;
    local_6c = 0x3f800000;
    local_44 = 0x3f800000;
    local_1c = 0x3f800000;
    local_5c = local_84;
    local_4c = fVar7;
    local_38 = local_88;
    local_24 = fVar7;
    local_10 = local_60;
    local_c = local_34;
  }
  else {
    iVar8 = local_d8;
  }
  if (*unaff_ESI != 0) {
    if ((((DAT_00cc47d0 == 0) || (uVar1 = unaff_ESI[3], (int)uVar1 < 0)) ||
        (((uVar1 & 0x7c000000) != DAT_00cc47f8 ||
         ((DAT_00cc4800 <= (int)(uVar1 & 0xffff) ||
          (piVar2 = *(int **)(DAT_00cc47d4 + (uVar1 & 0xffff) * 4), piVar2 == (int *)0x0)))))) ||
       ((*piVar2 * 0x10000 != (uVar1 & 0x3ff0000) || (piVar2[4] != 0)))) {
      return 0xffffffff;
    }
    if (param_2 == (float *)0x0) {
      if (unaff_ESI[0xf] == 0) {
        local_dc = (float)piVar2[0x31];
        local_c0 = (float)piVar2[0x35];
        local_bc = (float)piVar2[0x32];
        local_2c = (float)piVar2[0x3a];
      }
      else {
        local_c0 = (float)*(int *)(piVar2[0x13] + 0x50);
        local_dc = (float)unaff_ESI[0xd] / local_c0;
        local_c0 = (float)(unaff_ESI[0xd] + local_d8) / local_c0;
        local_2c = (float)*(int *)(piVar2[0x13] + 0x54);
        local_bc = (float)unaff_ESI[0xe] / local_2c;
        local_2c = (float)(unaff_ESI[0xe] + iVar8) / local_2c;
      }
      local_80 = local_dc;
      local_7c = local_bc;
      local_58 = local_c0;
      local_54 = local_bc;
      local_30 = local_dc;
      local_8 = local_c0;
      local_4 = local_2c;
    }
    FUN_00516bd0(1,uVar1);
  }
  FUN_00516bd0(0,unaff_ESI[2]);
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  FUN_0059d430();
  FUN_005b45e0(0,0,1,1);
  if (param_2 == (float *)0x0) {
    FUN_005a0c60(0x2c4);
    uVar9 = 0x28;
    param_2 = &local_a0;
  }
  else {
    FUN_005a0c60(0x844);
    uVar9 = 0x54;
  }
  FUN_005d3b40(5,2,param_2,uVar9);
  DAT_00a37de4 = DAT_00a37de4 + 1;
  iVar8 = FUN_005176a0(unaff_ESI[4]);
  if (iVar8 != 0) {
    FUN_0059d460();
    FUN_00598650(local_ac[0x40],0);
  }
  return 0;
}

