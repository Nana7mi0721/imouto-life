
void FUN_006879e0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  int local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  
  local_20 = 0;
  iVar1 = *(int *)(param_1 + 0x124);
  iVar2 = *(int *)(param_1 + 0x19c);
  if (0 < *(int *)(param_1 + 0x24)) {
    local_18 = (int *)(*(int *)(param_1 + 0xc4) + 0xc);
    local_1c = (int *)(iVar2 + 8);
    do {
      iVar6 = (local_18[7] * *local_18) / *(int *)(param_1 + 0x124);
      puVar3 = *(undefined4 **)(*(int *)(iVar2 + 0x38) + local_20 * 4);
      puVar4 = *(undefined4 **)(*(int *)(iVar2 + 0x3c) + local_20 * 4);
      iVar9 = *local_1c;
      local_14 = (iVar1 + 2) * iVar6;
      if (0 < local_14) {
        puVar8 = puVar4;
        do {
          uVar5 = *(undefined4 *)((int)puVar8 + (iVar9 - (int)puVar4));
          *puVar8 = uVar5;
          *(undefined4 *)(((int)puVar3 - (int)puVar4) + (int)puVar8) = uVar5;
          puVar8 = puVar8 + 1;
          local_14 = local_14 + -1;
        } while (local_14 != 0);
      }
      if (0 < iVar6 * 2) {
        puVar8 = (undefined4 *)(iVar9 + (iVar1 + -2) * iVar6 * 4);
        iVar11 = iVar6 * 2;
        puVar10 = puVar4 + iVar6 * iVar1;
        do {
          *(undefined4 *)(((int)puVar4 - iVar9) + (int)puVar8) =
               *(undefined4 *)((int)puVar10 + (iVar9 - (int)puVar4));
          *puVar10 = *puVar8;
          puVar8 = puVar8 + 1;
          iVar11 = iVar11 + -1;
          puVar10 = puVar10 + 1;
        } while (iVar11 != 0);
      }
      if (0 < iVar6) {
        iVar11 = 0;
        iVar9 = iVar6;
        do {
          iVar7 = iVar11 + iVar6 * -4;
          iVar11 = iVar11 + 4;
          iVar9 = iVar9 + -1;
          *(undefined4 *)(iVar7 + (int)puVar3) = *puVar3;
        } while (iVar9 != 0);
      }
      local_20 = local_20 + 1;
      local_1c = local_1c + 1;
      local_18 = local_18 + 0x16;
    } while (local_20 < *(int *)(param_1 + 0x24));
  }
  return;
}

