
void __thiscall FUN_00794e90(int param_1,undefined4 param_2,float *param_3,float *param_4)

{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ushort local_20;
  ushort local_1e;
  ushort local_1c;
  ushort local_18;
  ushort local_16;
  ushort local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(char *)(param_1 + 0x3c) == '\0') {
    FUN_00795190(param_2,param_3,param_4);
  }
  else {
    local_10 = *param_3;
    local_c = param_3[1];
    local_8 = param_3[2];
    local_4 = param_3[3];
    if (local_10 < *(float *)(param_1 + 4)) {
      local_10 = *(float *)(param_1 + 4);
    }
    if (local_c < *(float *)(param_1 + 8)) {
      local_c = *(float *)(param_1 + 8);
    }
    if (local_8 < *(float *)(param_1 + 0xc)) {
      local_8 = *(float *)(param_1 + 0xc);
    }
    if (local_4 < *(float *)(param_1 + 0x10)) {
      local_4 = *(float *)(param_1 + 0x10);
    }
    if (*(float *)(param_1 + 0x14) < local_10) {
      local_10 = *(float *)(param_1 + 0x14);
    }
    if (*(float *)(param_1 + 0x18) < local_c) {
      local_c = *(float *)(param_1 + 0x18);
    }
    if (*(float *)(param_1 + 0x1c) < local_8) {
      local_8 = *(float *)(param_1 + 0x1c);
    }
    if (*(float *)(param_1 + 0x20) < local_4) {
      local_4 = *(float *)(param_1 + 0x20);
    }
    FUN_00793100(&local_18,&local_10,0);
    local_10 = *param_4;
    local_c = param_4[1];
    local_8 = param_4[2];
    local_4 = param_4[3];
    if (local_10 < *(float *)(param_1 + 4)) {
      local_10 = *(float *)(param_1 + 4);
    }
    if (local_c < *(float *)(param_1 + 8)) {
      local_c = *(float *)(param_1 + 8);
    }
    if (local_8 < *(float *)(param_1 + 0xc)) {
      local_8 = *(float *)(param_1 + 0xc);
    }
    if (local_4 < *(float *)(param_1 + 0x10)) {
      local_4 = *(float *)(param_1 + 0x10);
    }
    if (*(float *)(param_1 + 0x14) < local_10) {
      local_10 = *(float *)(param_1 + 0x14);
    }
    if (*(float *)(param_1 + 0x18) < local_c) {
      local_c = *(float *)(param_1 + 0x18);
    }
    if (*(float *)(param_1 + 0x1c) < local_8) {
      local_8 = *(float *)(param_1 + 0x1c);
    }
    if (*(float *)(param_1 + 0x20) < local_4) {
      local_4 = *(float *)(param_1 + 0x20);
    }
    FUN_00793100(&local_20,&local_10,1);
    iVar3 = *(int *)(param_1 + 0x90);
    if (iVar3 == 0) {
      FUN_00795ee0(param_2,&local_18,&local_20,0,*(undefined4 *)(param_1 + 0x38));
      return;
    }
    if (iVar3 == 1) {
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0x98)) {
        iVar4 = 0;
        do {
          puVar1 = (ushort *)(*(int *)(param_1 + 0xa0) + iVar4);
          uVar2 = (uint)(((((local_16 <= puVar1[4] && puVar1[1] <= local_1e) &&
                           local_14 <= puVar1[5]) && puVar1[2] <= local_1c) && *puVar1 <= local_20)
                        && local_18 <= puVar1[3]);
          if (((int)(-uVar2 | uVar2) >> 0x1f & 1U) != 0) {
            FUN_00795ee0(param_2,&local_18,&local_20,*(int *)(puVar1 + 6),
                         *(int *)(puVar1 + 8) + *(int *)(puVar1 + 6));
          }
          iVar3 = iVar3 + 1;
          iVar4 = iVar4 + 0x20;
        } while (iVar3 < *(int *)(param_1 + 0x98));
        return;
      }
    }
    else if (iVar3 == 2) {
      FUN_00795290(*(undefined4 *)(param_1 + 0x88),param_2,&local_18,&local_20);
      return;
    }
  }
  return;
}

