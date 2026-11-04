
undefined4 FUN_00541150(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined2 *puVar9;
  undefined2 *puVar10;
  int iVar11;
  undefined1 *puVar12;
  undefined4 *local_8;
  
  if ((*(int *)(param_1 + 0x428) == 0) || (iVar7 = *(int *)(param_1 + 0x42c), iVar7 == 0)) {
    return 0xffffffff;
  }
  switch(*(undefined1 *)(param_1 + 4)) {
  case 1:
    iVar11 = *(int *)(param_1 + 0x434);
    iVar3 = *(int *)(param_1 + 0x430);
    local_8 = (undefined4 *)(*(int *)(param_1 + 0x428) + -1 + iVar11);
    iVar5 = *(int *)(param_1 + 0x428) / 2;
    param_1 = iVar7;
    do {
      iVar7 = 0;
      puVar8 = local_8;
      if (0 < iVar5) {
        do {
          uVar1 = *(undefined1 *)(iVar7 + iVar11);
          *(undefined1 *)(iVar7 + iVar11) = *(undefined1 *)puVar8;
          *(undefined1 *)puVar8 = uVar1;
          iVar7 = iVar7 + 1;
          puVar8 = (undefined4 *)((int)puVar8 + -1);
        } while (iVar7 < iVar5);
      }
      local_8 = (undefined4 *)((int)local_8 + iVar3);
      iVar11 = iVar11 + iVar3;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
    return 0;
  case 2:
    iVar11 = *(int *)(param_1 + 0x434);
    iVar3 = *(int *)(param_1 + 0x430);
    local_8 = (undefined4 *)(iVar11 + -2 + *(int *)(param_1 + 0x428) * 2);
    iVar5 = *(int *)(param_1 + 0x428) / 2;
    param_1 = iVar7;
    do {
      iVar7 = 0;
      if (0 < iVar5) {
        puVar8 = local_8;
        do {
          uVar2 = *(undefined2 *)(iVar11 + iVar7 * 2);
          *(undefined2 *)(iVar11 + iVar7 * 2) = *(undefined2 *)puVar8;
          *(undefined2 *)puVar8 = uVar2;
          iVar7 = iVar7 + 1;
          puVar8 = (undefined4 *)((int)puVar8 + -2);
        } while (iVar7 < iVar5);
      }
      local_8 = (undefined4 *)((int)local_8 + iVar3);
      iVar11 = iVar11 + iVar3;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
    return 0;
  case 3:
    iVar11 = *(int *)(param_1 + 0x430);
    puVar9 = (undefined2 *)(*(int *)(param_1 + 0x428) * 3 + -3 + *(int *)(param_1 + 0x434));
    iVar3 = (*(int *)(param_1 + 0x428) / 2) * 3;
    puVar12 = (undefined1 *)(*(int *)(param_1 + 0x434) + 2);
    param_1 = iVar7;
    do {
      if (0 < iVar3) {
        iVar7 = (iVar3 - 1U) / 3 + 1;
        puVar6 = puVar12;
        puVar10 = puVar9;
        do {
          uVar2 = *(undefined2 *)(puVar6 + -2);
          *(undefined2 *)(puVar6 + -2) = *puVar10;
          *puVar10 = uVar2;
          uVar1 = *puVar6;
          *puVar6 = *(undefined1 *)(puVar10 + 1);
          *(undefined1 *)(puVar10 + 1) = uVar1;
          puVar6 = puVar6 + 3;
          puVar10 = (undefined2 *)((int)puVar10 + -3);
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      puVar12 = puVar12 + iVar11;
      puVar9 = (undefined2 *)((int)puVar9 + iVar11);
      param_1 = param_1 + -1;
    } while (param_1 != 0);
    return 0;
  case 4:
    iVar11 = *(int *)(param_1 + 0x434);
    iVar3 = *(int *)(param_1 + 0x430);
    local_8 = (undefined4 *)(iVar11 + -4 + *(int *)(param_1 + 0x428) * 4);
    iVar5 = *(int *)(param_1 + 0x428) / 2;
    param_1 = iVar7;
    do {
      iVar7 = 0;
      if (0 < iVar5) {
        puVar8 = local_8;
        do {
          uVar4 = *(undefined4 *)(iVar11 + iVar7 * 4);
          *(undefined4 *)(iVar11 + iVar7 * 4) = *puVar8;
          *puVar8 = uVar4;
          iVar7 = iVar7 + 1;
          puVar8 = puVar8 + -1;
        } while (iVar7 < iVar5);
      }
      local_8 = (undefined4 *)((int)local_8 + iVar3);
      iVar11 = iVar11 + iVar3;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return 0;
}

