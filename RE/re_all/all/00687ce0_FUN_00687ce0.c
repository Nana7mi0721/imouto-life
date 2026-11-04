
void FUN_00687ce0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *local_1c;
  int local_18;
  int local_14;
  int *local_10;
  
  iVar2 = *(int *)(param_1 + 0x124);
  iVar3 = *(int *)(param_1 + 0x19c);
  local_14 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    local_10 = (int *)(*(int *)(param_1 + 0xc4) + 0xc);
    do {
      iVar6 = (local_10[7] * *local_10) / *(int *)(param_1 + 0x124);
      iVar4 = *(int *)(*(int *)(iVar3 + 0x38) + local_14 * 4);
      iVar5 = *(int *)(*(int *)(iVar3 + 0x3c) + local_14 * 4);
      if (0 < iVar6) {
        iVar7 = 0;
        iVar8 = iVar4 - iVar5;
        puVar9 = (undefined4 *)(iVar5 + (iVar2 + 1) * iVar6 * 4);
        local_1c = (undefined4 *)(iVar5 + (iVar2 + 2) * iVar6 * 4);
        local_18 = iVar6;
        while( true ) {
          *(undefined4 *)(iVar7 + iVar6 * -4 + iVar4) = *(undefined4 *)(iVar8 + (int)puVar9);
          *(undefined4 *)(iVar7 + iVar6 * -4 + iVar5) = *puVar9;
          puVar1 = (undefined4 *)(iVar7 + iVar5);
          iVar7 = iVar7 + 4;
          *(undefined4 *)(iVar8 + -4 + (int)(local_1c + 1)) = *(undefined4 *)(iVar8 + (int)puVar1);
          *local_1c = *puVar1;
          local_18 = local_18 + -1;
          if (local_18 == 0) break;
          puVar9 = puVar9 + 1;
          local_1c = local_1c + 1;
        }
      }
      local_14 = local_14 + 1;
      local_10 = local_10 + 0x16;
    } while (local_14 < *(int *)(param_1 + 0x24));
  }
  return;
}

