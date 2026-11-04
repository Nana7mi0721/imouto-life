
void FUN_006b9d60(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  uint local_28;
  int *local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int local_14;
  
  iVar1 = *(int *)(param_1 + 0xd8);
  iVar2 = *(int *)(param_1 + 0xa8);
  iVar3 = *(int *)(param_1 + 0xb8);
  local_18 = (int *)(param_1 + 0xdc);
  iVar4 = *(int *)(param_1 + 0xbc);
  uVar8 = 0;
  local_24 = (int *)(param_1 + 100);
  local_1c = 0;
  uVar6 = 0;
  local_28 = 0;
  local_14 = 3;
  do {
    uVar6 = uVar6 + *local_24;
    iVar11 = local_1c;
    while (uVar8 < uVar6) {
      iVar7 = 0;
      do {
        if ((byte)((byte)(1 << ((byte)iVar7 & 0x1f)) &
                  (byte)((*(byte *)(uVar8 + iVar4) & 0x3c) >> 2)) != 0) {
          local_20 = 4;
          piVar10 = (int *)(iVar1 + iVar11 * 4);
          piVar9 = (int *)((iVar7 + local_28 * 4) * 0x10 + iVar3);
          do {
            iVar5 = *piVar9;
            if (-1 < iVar5) {
              iVar11 = iVar11 + 1;
              *(uint *)(iVar2 + iVar5 * 4) = *(uint *)(iVar2 + iVar5 * 4) & 0xfffff9bf | 0x181;
              *piVar10 = iVar5;
              piVar10 = piVar10 + 1;
            }
            piVar9 = piVar9 + 1;
            local_20 = local_20 + -1;
          } while (local_20 != 0);
        }
        iVar7 = iVar7 + 1;
        uVar8 = local_28;
      } while (iVar7 < 4);
      uVar8 = local_28 + 1;
      local_28 = uVar8;
    }
    *local_18 = iVar11 - local_1c;
    local_18 = local_18 + 1;
    local_24 = local_24 + 8;
    local_14 = local_14 + -1;
    local_1c = iVar11;
  } while (local_14 != 0);
  *(int *)(param_1 + 0xe8) = iVar11;
  return;
}

