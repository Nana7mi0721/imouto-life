
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0060cca0(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *local_40;
  int *local_38;
  uint local_2c [3];
  float local_20 [4];
  float local_10;
  float local_c;
  float local_8;
  
  *(undefined4 *)(param_2 + 0x10) = *param_3;
  *(undefined4 *)(param_2 + 0x14) = param_3[1];
  *(undefined4 *)(param_2 + 0x18) = param_3[2];
  *(undefined4 *)(param_2 + 0x1c) = param_3[3];
  iVar1 = *(int *)(param_2 + 0xc);
  *(undefined4 *)(param_2 + 0x20) = *param_4;
  *(undefined4 *)(param_2 + 0x24) = param_4[1];
  *(undefined4 *)(param_2 + 0x28) = param_4[2];
  *(undefined4 *)(param_2 + 0x2c) = param_4[3];
  iVar2 = *(int *)(param_1 + 0x44);
  uVar4 = FUN_005fc590(&local_10,param_3,param_1 + 0xc,param_1 + 0x2c);
  FUN_005fc560(local_20,uVar4);
  if (_DAT_007d5344 < local_20[0]) {
    if (local_20[0] < (float)*(uint *)(param_1 + 8)) {
      local_2c[0] = __ftol();
      local_2c[0] = *(uint *)(param_1 + 4) & local_2c[0];
    }
    else {
      local_2c[0] = *(uint *)(param_1 + 4) & *(uint *)(param_1 + 8);
    }
  }
  else {
    local_2c[0] = 0;
  }
  if (_DAT_007d5344 < local_20[1]) {
    if (local_20[1] < (float)*(uint *)(param_1 + 8)) {
      local_2c[1] = __ftol();
      local_2c[1] = *(uint *)(param_1 + 4) & local_2c[1];
    }
    else {
      local_2c[1] = *(uint *)(param_1 + 4) & *(uint *)(param_1 + 8);
    }
  }
  else {
    local_2c[1] = 0;
  }
  if (_DAT_007d5344 < local_20[2]) {
    if (local_20[2] < (float)*(uint *)(param_1 + 8)) {
      local_2c[2] = __ftol();
      local_2c[2] = *(uint *)(param_1 + 4) & local_2c[2];
    }
    else {
      local_2c[2] = *(uint *)(param_1 + 4) & *(uint *)(param_1 + 8);
    }
  }
  else {
    local_2c[2] = 0;
  }
  uVar4 = FUN_005fc590(local_20,param_4,param_1 + 0xc,param_1 + 0x2c);
  FUN_005fc560(&local_10,uVar4);
  if (_DAT_007d5344 < local_10) {
    if (local_10 < (float)*(uint *)(param_1 + 8)) {
      uVar5 = __ftol();
      local_20[0] = (float)(*(uint *)(param_1 + 4) & uVar5 | 1);
    }
    else {
      local_20[0] = (float)(*(uint *)(param_1 + 4) & *(uint *)(param_1 + 8) | 1);
    }
  }
  else {
    local_20[0] = 1.4013e-45;
  }
  iVar8 = 0;
  if (_DAT_007d5344 < local_c) {
    if (local_c < (float)*(uint *)(param_1 + 8)) {
      uVar5 = __ftol();
      local_20[1] = (float)(*(uint *)(param_1 + 4) & uVar5 | 1);
    }
    else {
      local_20[1] = (float)(*(uint *)(param_1 + 4) & *(uint *)(param_1 + 8) | 1);
    }
  }
  else {
    local_20[1] = 1.4013e-45;
  }
  if (_DAT_007d5344 < local_8) {
    if (local_8 < (float)*(uint *)(param_1 + 8)) {
      uVar5 = __ftol();
      local_20[2] = (float)(*(uint *)(param_1 + 4) & uVar5 | 1);
    }
    else {
      local_20[2] = (float)(*(uint *)(param_1 + 4) & *(uint *)(param_1 + 8) | 1);
    }
  }
  else {
    local_20[2] = 1.4013e-45;
  }
  local_40 = (int *)(param_1 + 0x4c);
  local_38 = (int *)(iVar2 + iVar1 * 0x4c + 0x3c);
  do {
    iVar1 = local_38[-3];
    iVar2 = *local_38;
    iVar3 = *local_40;
    iVar7 = local_2c[iVar8] - *(int *)(iVar3 + iVar1 * 8);
    iVar6 = (int)local_20[iVar8] - *(int *)(iVar3 + iVar2 * 8);
    *(uint *)(iVar3 + iVar1 * 8) = local_2c[iVar8];
    *(float *)(*local_40 + iVar2 * 8) = local_20[iVar8];
    if (iVar7 < 0) {
      FUN_0060db30(iVar8,iVar1,param_5,1);
    }
    if (0 < iVar6) {
      FUN_0060def0(iVar8,iVar2,param_5,1);
    }
    if (0 < iVar7) {
      FUN_0060dc40(iVar8,iVar1,param_5,1);
    }
    if (iVar6 < 0) {
      FUN_0060dda0(iVar8,iVar2,param_5,1);
    }
    iVar8 = iVar8 + 1;
    local_38 = local_38 + 1;
    local_40 = local_40 + 1;
  } while (iVar8 < 3);
  if (*(int **)(param_1 + 0x74) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x74) + 0xc))
              (*(undefined4 *)(param_2 + 0x48),param_3,param_4,param_5);
  }
  return;
}

