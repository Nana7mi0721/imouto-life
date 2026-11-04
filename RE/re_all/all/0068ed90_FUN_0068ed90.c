
void FUN_0068ed90(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  int iVar9;
  int iVar10;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  ushort *local_1c;
  int local_18;
  int local_14;
  
  iVar10 = 0;
  local_2c = 0;
  piVar1 = param_2 + 3;
  iVar6 = param_2[2];
  iVar3 = param_2[4];
  piVar2 = param_2 + 5;
  iVar7 = *param_2;
  local_28 = 0;
  local_24 = 0;
  if (iVar7 <= param_2[1]) {
    local_30 = iVar7 * 8 + 4;
    local_14 = (param_2[1] - iVar7) + 1;
    param_2 = (int *)(*(int *)(*(int *)(param_1 + 0x1c0) + 0x18) + iVar7 * 4);
    do {
      if (iVar6 <= *piVar1) {
        iVar7 = iVar6 * 4 + 2;
        local_1c = (ushort *)(*param_2 + (iVar6 * 0x20 + iVar3) * 2);
        local_18 = (*piVar1 - iVar6) + 1;
        do {
          if (iVar3 <= *piVar2) {
            iVar5 = iVar3 * 8 + 4;
            iVar9 = (*piVar2 - iVar3) + 1;
            puVar8 = local_1c;
            do {
              uVar4 = (uint)*puVar8;
              puVar8 = puVar8 + 1;
              if (uVar4 != 0) {
                local_2c = local_2c + local_30 * uVar4;
                local_28 = local_28 + iVar7 * uVar4;
                iVar10 = iVar10 + uVar4;
                local_24 = local_24 + iVar5 * uVar4;
              }
              iVar5 = iVar5 + 8;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
          iVar7 = iVar7 + 4;
          local_1c = local_1c + 0x20;
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
      param_2 = param_2 + 1;
      local_30 = local_30 + 8;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
  }
  iVar6 = iVar10 >> 1;
  *(char *)(**(int **)(param_1 + 0x74) + param_3) = (char)((iVar6 + local_2c) / iVar10);
  *(char *)(*(int *)(*(int *)(param_1 + 0x74) + 4) + param_3) = (char)((local_28 + iVar6) / iVar10);
  *(char *)(*(int *)(*(int *)(param_1 + 0x74) + 8) + param_3) = (char)((local_24 + iVar6) / iVar10);
  return;
}

