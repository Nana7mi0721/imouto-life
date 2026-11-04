
void __thiscall FUN_007944a0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_38;
  int local_34;
  undefined4 local_20 [8];
  
  puVar5 = (undefined2 *)(param_2 * 0x10 + *(int *)(param_1 + 0x88));
  if (*(int *)(puVar5 + 6) < 0) {
    local_38 = -*(int *)(puVar5 + 6);
  }
  else {
    local_38 = 1;
  }
  puVar4 = (undefined2 *)(param_3 * 0x10 + *(int *)(param_1 + 0x88));
  if (*(int *)(puVar4 + 6) < 0) {
    local_34 = -*(int *)(puVar4 + 6);
  }
  else {
    local_34 = 1;
  }
  if (local_38 * 0x10 < 0x801) {
    iVar1 = *(int *)(param_1 + 0x98);
    if (iVar1 == *(int *)(param_1 + 0x9c)) {
      iVar7 = iVar1 * 2;
      if (iVar1 == 0) {
        iVar7 = 1;
      }
      if (*(int *)(param_1 + 0x9c) < iVar7) {
        uVar2 = FUN_007974e0(iVar7);
        FUN_00797490(0,*(undefined4 *)(param_1 + 0x98),uVar2);
        FUN_0060b970(0,*(undefined4 *)(param_1 + 0x98));
        FUN_007932e0();
        *(undefined1 *)(param_1 + 0xa4) = 1;
        *(undefined4 *)(param_1 + 0xa0) = uVar2;
        *(int *)(param_1 + 0x9c) = iVar7;
      }
    }
    *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
    puVar8 = (undefined4 *)(iVar1 * 0x20 + *(int *)(param_1 + 0xa0));
    if (puVar8 != (undefined4 *)0x0) {
      puVar6 = local_20;
      for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
    }
    puVar3 = (undefined2 *)(iVar1 * 0x20 + *(int *)(param_1 + 0xa0));
    *puVar3 = *puVar5;
    puVar3[1] = puVar5[1];
    puVar3[2] = puVar5[2];
    puVar3[3] = puVar5[3];
    puVar3[4] = puVar5[4];
    puVar3[5] = puVar5[5];
    *(int *)(puVar3 + 6) = param_2;
    *(int *)(puVar3 + 8) = local_38;
  }
  if (0x800 < local_34 << 4) {
    *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0x98);
    return;
  }
  iVar1 = *(int *)(param_1 + 0x98);
  if (iVar1 == *(int *)(param_1 + 0x9c)) {
    iVar7 = iVar1 * 2;
    if (iVar1 == 0) {
      iVar7 = 1;
    }
    if (*(int *)(param_1 + 0x9c) < iVar7) {
      uVar2 = FUN_007974e0(iVar7);
      FUN_00797490(0,*(undefined4 *)(param_1 + 0x98),uVar2);
      FUN_0060b970(0,*(undefined4 *)(param_1 + 0x98));
      FUN_007932e0();
      *(undefined1 *)(param_1 + 0xa4) = 1;
      *(undefined4 *)(param_1 + 0xa0) = uVar2;
      *(int *)(param_1 + 0x9c) = iVar7;
    }
  }
  *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
  puVar8 = (undefined4 *)(*(int *)(param_1 + 0xa0) + iVar1 * 0x20);
  if (puVar8 != (undefined4 *)0x0) {
    puVar6 = local_20;
    for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
  }
  puVar5 = (undefined2 *)(*(int *)(param_1 + 0xa0) + iVar1 * 0x20);
  *puVar5 = *puVar4;
  puVar5[1] = puVar4[1];
  puVar5[2] = puVar4[2];
  puVar5[3] = puVar4[3];
  puVar5[4] = puVar4[4];
  puVar5[5] = puVar4[5];
  *(int *)(puVar5 + 6) = param_3;
  *(int *)(puVar5 + 8) = local_34;
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0x98);
  return;
}

