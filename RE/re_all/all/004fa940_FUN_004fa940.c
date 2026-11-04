
int FUN_004fa940(int param_1,int *param_2,int *param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = 0;
  *param_2 = 0;
  *param_3 = 0;
  param_3[1] = 0;
  *param_4 = 0;
  iVar2 = FUN_00401750(param_1,*(undefined4 *)(param_1 + 0x30),
                       *(uint *)(param_1 + 0xd8) + *(uint *)(param_1 + 0x48),
                       *(int *)(param_1 + 0xdc) + *(int *)(param_1 + 0x4c) +
                       (uint)CARRY4(*(uint *)(param_1 + 0xd8),*(uint *)(param_1 + 0x48)),0);
  if (iVar2 == 0) {
    if (local_14 == 0) {
      iVar2 = FUN_004f8e60(param_1,*(undefined4 *)(param_1 + 0x30),&local_10);
      if (iVar2 == 0) {
        if (local_10 != 0x4034b50) {
          local_14 = -0x67;
        }
      }
      else {
        local_14 = -1;
      }
    }
    iVar2 = FUN_004f8d80(param_1,*(undefined4 *)(param_1 + 0x30),&local_8);
    if (iVar2 != 0) {
      local_14 = -1;
    }
    iVar2 = FUN_004f8d80(param_1,*(undefined4 *)(param_1 + 0x30),&local_1c);
    if (iVar2 != 0) {
      local_14 = -1;
    }
    iVar2 = FUN_004f8d80(param_1,*(undefined4 *)(param_1 + 0x30),&local_8);
    if (iVar2 == 0) {
      if ((local_14 == 0) && (local_8 != *(int *)(param_1 + 0x8c))) {
        local_14 = -0x67;
      }
    }
    else {
      local_14 = -1;
    }
    if ((((local_14 == 0) && (*(int *)(param_1 + 0x8c) != 0)) && (*(int *)(param_1 + 0x8c) != 0xc))
       && (*(int *)(param_1 + 0x8c) != 8)) {
      local_14 = -0x67;
    }
    iVar2 = FUN_004f8e60(param_1,*(undefined4 *)(param_1 + 0x30),&local_8);
    if (iVar2 != 0) {
      local_14 = -1;
    }
    iVar2 = FUN_004f8e60(param_1,*(undefined4 *)(param_1 + 0x30),&local_8);
    if (iVar2 == 0) {
      if (((local_14 == 0) && (local_8 != *(int *)(param_1 + 0x94))) && ((local_1c & 8) == 0)) {
        local_14 = -0x67;
      }
    }
    else {
      local_14 = -1;
    }
    iVar2 = FUN_004f8e60(param_1,*(undefined4 *)(param_1 + 0x30),&local_8);
    if (iVar2 == 0) {
      if ((local_8 != -1) && (local_14 == 0)) {
        if (((local_8 != *(int *)(param_1 + 0x98)) || (*(int *)(param_1 + 0x9c) != 0)) &&
           ((local_1c & 8) == 0)) {
          local_14 = -0x67;
        }
      }
    }
    else {
      local_14 = -1;
    }
    iVar2 = FUN_004f8e60(param_1,*(undefined4 *)(param_1 + 0x30),&local_8);
    if (iVar2 == 0) {
      if ((local_8 != -1) && (local_14 == 0)) {
        if (((local_8 != *(int *)(param_1 + 0xa0)) || (*(int *)(param_1 + 0xa4) != 0)) &&
           ((local_1c & 8) == 0)) {
          local_14 = -0x67;
        }
      }
    }
    else {
      local_14 = -1;
    }
    iVar2 = FUN_004f8d80(param_1,*(undefined4 *)(param_1 + 0x30),&local_18);
    if (iVar2 == 0) {
      if ((local_14 == 0) && (local_18 != *(uint *)(param_1 + 0xa8))) {
        local_14 = -0x67;
      }
    }
    else {
      local_14 = -1;
    }
    *param_2 = *param_2 + local_18;
    iVar2 = FUN_004f8d80(param_1,*(undefined4 *)(param_1 + 0x30),&local_c);
    if (iVar2 != 0) {
      local_14 = -1;
    }
    uVar1 = *(uint *)(param_1 + 0xd8);
    uVar3 = uVar1 + 0x1e;
    iVar2 = *(int *)(param_1 + 0xdc);
    *param_3 = uVar3 + local_18;
    param_3[1] = iVar2 + (uint)(0xffffffe1 < uVar1) + (uint)CARRY4(uVar3,local_18);
    *param_4 = local_c;
    *param_2 = *param_2 + local_c;
  }
  else {
    local_14 = -1;
  }
  return local_14;
}

