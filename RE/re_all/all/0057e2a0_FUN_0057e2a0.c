
void FUN_0057e2a0(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int local_30;
  undefined4 local_24;
  uint local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  iVar2 = param_1;
  iVar7 = *(int *)(*(int *)(param_1 + 4) + 0x58);
  iVar5 = *(int *)(param_1 + 4);
  iVar1 = *(int *)(iVar5 + 0x5c);
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  local_24 = 0;
  uVar6 = *(uint *)(iVar5 + 0x34) / 0x3c;
  if (*(int *)(*(int *)(iVar5 + 0x4c) + 4) == 0) {
    local_30 = **(int **)(iVar5 + 0x4c);
  }
  else {
    local_30 = *(int *)(*(int *)(iVar5 + 0x4c) + 4);
  }
  iVar3 = (uint)*(ushort *)(iVar5 + 0x3e) * *(int *)(iVar5 + 0x110);
  uVar8 = (int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3;
  param_1 = 0;
  if (param_2 != 0) {
    do {
      iVar5 = *(int *)(iVar2 + 4);
      if (*(int *)(iVar5 + 0x2c) <= iVar7) {
        if (iVar1 == 0) {
          FUN_00551830(iVar5,0);
          *(int *)(*(int *)(iVar2 + 4) + 0x58) = iVar7;
          return;
        }
        iVar7 = 0;
      }
      local_1c = uVar8 * iVar7 + local_30;
      uVar4 = *(int *)(iVar5 + 0x2c) - iVar7;
      if (uVar6 < uVar4) {
        uVar4 = uVar6;
      }
      local_20 = uVar4 * uVar8;
      if (param_2 < local_20) {
        uVar4 = param_2 / uVar8;
        local_20 = uVar4 * uVar8;
      }
      param_1 = param_1 + local_20;
      iVar7 = iVar7 + uVar4;
      local_4 = iVar5;
      if (DAT_00aa4254 == 0) {
        (**(code **)(**(int **)(iVar5 + 200) + 0x54))(*(int **)(iVar5 + 200),&local_24,0);
      }
      else {
        (**(code **)(**(int **)(iVar5 + 200) + 0x54))(*(int **)(iVar5 + 200),&local_24);
      }
    } while (param_1 < param_2);
    iVar5 = *(int *)(iVar2 + 4);
  }
  *(int *)(iVar5 + 0x58) = iVar7;
  return;
}

