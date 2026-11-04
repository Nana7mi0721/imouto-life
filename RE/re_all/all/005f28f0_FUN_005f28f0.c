
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005f28f0(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int *local_c0;
  int *local_bc;
  int *local_b8;
  int *local_b4;
  float local_b0;
  float local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int *local_9c;
  int local_98;
  int *local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  undefined1 local_80 [128];
  
  iVar8 = 0;
  local_c0 = (int *)0x0;
  local_bc = (int *)0x0;
  local_b8 = (int *)0x0;
  local_b4 = (int *)0x0;
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((((DAT_00cc47d0 == 0) || (uVar4 = *(uint *)(param_1 + 8), (int)uVar4 < 0)) ||
      ((uVar4 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(uVar4 & 0xffff) ||
       (local_c0 = *(int **)(DAT_00cc47d4 + (uVar4 & 0xffff) * 4), local_c0 == (int *)0x0)) ||
      ((*local_c0 * 0x10000 != (uVar4 & 0x3ff0000) || (local_c0[4] != 0)))))) {
    if (DAT_00cc79c0 == 0) {
      return 0xffffffff;
    }
    uVar4 = *(uint *)(param_1 + 8);
    if ((int)uVar4 < 0) {
      return 0xffffffff;
    }
    if ((uVar4 & 0x7c000000) != DAT_00cc79e8) {
      return 0xffffffff;
    }
    if (DAT_00cc79f0 <= (int)(uVar4 & 0xffff)) {
      return 0xffffffff;
    }
    local_bc = *(int **)(DAT_00cc79c4 + (uVar4 & 0xffff) * 4);
    if (local_bc == (int *)0x0) {
      return 0xffffffff;
    }
    if (*local_bc * 0x10000 != (uVar4 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (local_bc[4] != 0) {
      return 0xffffffff;
    }
  }
  if (param_2 == 8) {
    iVar8 = 0;
  }
  else if (param_2 == 0x10) {
    iVar8 = 1;
  }
  else if (param_2 == 0x20) {
    iVar8 = 2;
  }
  FUN_005159a0(uVar4,&local_a4,&local_a8);
  local_b0 = (float)local_a4;
  piVar6 = &DAT_00dda478 + iVar8;
  local_ac = (float)local_a8;
  if (*piVar6 < 0) {
    iVar3 = FUN_005f2360(0);
    *piVar6 = iVar3;
    if (iVar3 < 0) {
      FUN_005764b0((&PTR_s_Gauss_08Pixel_PS_pso_008026e7_1_00a057b4)[iVar8],0xffffffff,0x7ffd,
                   local_80,0x80,0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(iVar3,piVar6);
  }
  puVar1 = *(undefined4 **)(DAT_00ef1ba8 + 8);
  *puVar1 = *param_4;
  puVar1[1] = param_4[1];
  puVar1[2] = param_4[2];
  puVar1[3] = param_4[3];
  puVar1[4] = param_4[4];
  puVar1[5] = param_4[5];
  puVar1[6] = param_4[6];
  puVar1[7] = param_4[7];
  puVar1[8] = param_4[8];
  puVar1[9] = param_4[9];
  puVar1[10] = param_4[10];
  puVar1[0xb] = param_4[0xb];
  puVar1[0xc] = param_4[0xc];
  puVar1[0xd] = param_4[0xd];
  puVar1[0xe] = param_4[0xe];
  puVar1[0xf] = param_4[0xf];
  if (*(int *)(param_1 + 0x1c) == 0) {
    puVar1[0x10] = 0.0 / local_b0;
    fVar2 = 0.0;
    puVar1[0x11] = 0;
    puVar1[0x12] = (float)_DAT_00805398 / local_b0;
    puVar1[0x13] = 0;
    puVar1[0x14] = (float)_DAT_008026e0 / local_b0;
    puVar1[0x15] = 0;
    puVar1[0x16] = (float)_DAT_007d0800 / local_b0;
    puVar1[0x17] = 0;
    puVar1[0x18] = (float)_DAT_007d0a48 / local_b0;
    puVar1[0x19] = 0;
    puVar1[0x1a] = (float)_DAT_007d0a58 / local_b0;
    puVar1[0x1b] = 0;
    puVar1[0x1c] = (float)_DAT_008026d8 / local_b0;
    puVar1[0x1d] = 0;
    puVar1[0x1e] = (float)_DAT_008026d0 / local_b0;
    puVar1[0x1f] = 0;
    puVar1[0x20] = (float)_DAT_008026c8 / local_b0;
    puVar1[0x21] = 0;
    puVar1[0x22] = (float)_DAT_008026c0 / local_b0;
    puVar1[0x23] = 0;
    puVar1[0x24] = (float)_DAT_008026b8 / local_b0;
    puVar1[0x25] = 0;
    puVar1[0x26] = (float)_DAT_008026b0 / local_b0;
    puVar1[0x27] = 0;
    puVar1[0x28] = (float)_DAT_008026a8 / local_b0;
    puVar1[0x29] = 0;
    puVar1[0x2a] = (float)_DAT_008026a0 / local_b0;
    puVar1[0x2b] = 0;
    puVar1[0x2c] = (float)_DAT_00802698 / local_b0;
    puVar1[0x2d] = 0;
    puVar1[0x2e] = (float)_DAT_00802690 / local_b0;
  }
  else {
    if (*(int *)(param_1 + 0x1c) != 1) goto LAB_005f2cf6;
    puVar1[0x10] = 0.0;
    puVar1[0x11] = 0.0 / local_ac;
    puVar1[0x12] = 0;
    puVar1[0x13] = (float)_DAT_00805398 / local_ac;
    puVar1[0x14] = 0;
    puVar1[0x15] = (float)_DAT_008026e0 / local_ac;
    puVar1[0x16] = 0;
    puVar1[0x17] = (float)_DAT_007d0800 / local_ac;
    puVar1[0x18] = 0;
    puVar1[0x19] = (float)_DAT_007d0a48 / local_ac;
    puVar1[0x1a] = 0;
    puVar1[0x1b] = (float)_DAT_007d0a58 / local_ac;
    puVar1[0x1c] = 0;
    puVar1[0x1d] = (float)_DAT_008026d8 / local_ac;
    puVar1[0x1e] = 0;
    puVar1[0x1f] = (float)_DAT_008026d0 / local_ac;
    puVar1[0x20] = 0;
    puVar1[0x21] = (float)_DAT_008026c8 / local_ac;
    puVar1[0x22] = 0;
    puVar1[0x23] = (float)_DAT_008026c0 / local_ac;
    puVar1[0x24] = 0;
    puVar1[0x25] = (float)_DAT_008026b8 / local_ac;
    puVar1[0x26] = 0;
    puVar1[0x27] = (float)_DAT_008026b0 / local_ac;
    puVar1[0x28] = 0;
    puVar1[0x29] = (float)_DAT_008026a8 / local_ac;
    puVar1[0x2a] = 0;
    puVar1[0x2b] = (float)_DAT_008026a0 / local_ac;
    puVar1[0x2c] = 0;
    puVar1[0x2d] = (float)_DAT_00802698 / local_ac;
    puVar1[0x2e] = 0;
    fVar2 = (float)_DAT_00802690 / local_ac;
  }
  puVar1[0x2f] = fVar2;
LAB_005f2cf6:
  *(undefined4 *)(DAT_00ef1ba8 + 0xc) = 1;
  FUN_005bc8e0(DAT_00ef1ba8);
  FUN_005f23c0(*piVar6,1,1,0xffffffff,0);
  if (*(int *)(param_1 + 0x1c) != 0) {
    return 0;
  }
  if (((DAT_00cc47d0 == 0) || (uVar4 = *(uint *)(param_1 + 8), (int)uVar4 < 0)) ||
     (((uVar4 & 0x7c000000) != DAT_00cc47f8 ||
      ((((DAT_00cc4800 <= (int)(uVar4 & 0xffff) ||
         (local_c0 = *(int **)(DAT_00cc47d4 + (uVar4 & 0xffff) * 4), local_c0 == (int *)0x0)) ||
        (*local_c0 * 0x10000 != (uVar4 & 0x3ff0000))) || (local_c0[4] != 0)))))) {
    if (DAT_00cc79c0 == 0) {
      return 0xffffffff;
    }
    uVar4 = *(uint *)(param_1 + 8);
    if ((int)uVar4 < 0) {
      return 0xffffffff;
    }
    if ((uVar4 & 0x7c000000) != DAT_00cc79e8) {
      return 0xffffffff;
    }
    if (DAT_00cc79f0 <= (int)(uVar4 & 0xffff)) {
      return 0xffffffff;
    }
    local_bc = *(int **)(DAT_00cc79c4 + (uVar4 & 0xffff) * 4);
    if (local_bc == (int *)0x0) {
      return 0xffffffff;
    }
    if (*local_bc * 0x10000 != (uVar4 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (local_bc[4] != 0) {
      return 0xffffffff;
    }
  }
  if (((((DAT_00cc47d0 == 0) || (uVar4 = *(uint *)(param_1 + 0x10), (int)uVar4 < 0)) ||
       (((uVar4 & 0x7c000000) != DAT_00cc47f8 ||
        ((DAT_00cc4800 <= (int)(uVar4 & 0xffff) ||
         (local_b8 = *(int **)(DAT_00cc47d4 + (uVar4 & 0xffff) * 4), local_b8 == (int *)0x0)))))) ||
      (*local_b8 * 0x10000 != (uVar4 & 0x3ff0000))) || (local_b8[4] != 0)) {
    if (((((DAT_00cc79c0 == 0) || (uVar4 = *(uint *)(param_1 + 0x10), (int)uVar4 < 0)) ||
         ((uVar4 & 0x7c000000) != DAT_00cc79e8)) ||
        ((DAT_00cc79f0 <= (int)(uVar4 & 0xffff) ||
         (piVar6 = *(int **)(DAT_00cc79c4 + (uVar4 & 0xffff) * 4), piVar6 == (int *)0x0)))) ||
       ((*piVar6 * 0x10000 != (uVar4 & 0x3ff0000) || (piVar6[4] != 0)))) {
      return 0xffffffff;
    }
  }
  else {
    piVar6 = local_b4;
  }
  if (local_bc == (int *)0x0) {
    uVar9 = *(undefined4 *)(*(int *)local_c0[0x40] + 4);
    uVar5 = *(undefined4 *)(*(int *)local_c0[0x40] + 8);
  }
  else {
    uVar9 = *(undefined4 *)local_bc[0x114];
    uVar5 = ((undefined4 *)local_bc[0x114])[1];
  }
  if (piVar6 == (int *)0x0) {
    uVar10 = *(undefined4 *)(*(int *)local_b8[0x40] + 4);
    uVar7 = **(undefined4 **)(*(int *)local_b8[0x40] + 0xc);
  }
  else {
    uVar10 = *(undefined4 *)piVar6[0x114];
    uVar7 = ((undefined4 *)piVar6[0x114])[2];
  }
  FUN_005159a0(uVar4,&local_b0,&local_b4);
  local_84 = *(int *)(param_1 + 0x2c);
  local_90 = *(int *)(param_1 + 0x20);
  local_88 = *(int *)(param_1 + 0x28);
  local_8c = local_84 + -1;
  local_a0 = *(int *)(param_1 + 0x40);
  local_98 = (local_a0 - local_90) + local_88;
  local_9c = (int *)((*(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x24)) + local_84);
  local_94 = local_b4;
  if (local_9c != local_b4) {
    FUN_005caf30(uVar9,uVar5,&local_90,uVar10,uVar7,&local_a0,0,0,0,0,0,0,0,0);
  }
  return 0;
}

