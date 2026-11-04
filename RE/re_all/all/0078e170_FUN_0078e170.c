
void __thiscall FUN_0078e170(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_8;
  
  iVar1 = 0;
  local_8 = 0;
  while( true ) {
    piVar2 = (int *)(**(code **)(**(int **)(param_3 + 0x4c) + 0x20))();
    iVar3 = (**(code **)(*piVar2 + 0x20))();
    if (iVar3 <= local_8) break;
    piVar2 = (int *)(**(code **)(**(int **)(param_3 + 0x4c) + 0x20))();
    iVar4 = (**(code **)(*piVar2 + 0x14))();
    iVar3 = **(int **)(iVar4 + iVar1);
    iVar4 = *(int *)((undefined4 *)(iVar4 + iVar1))[1];
    if ((((iVar3 != 0) && ((*(byte *)(iVar3 + 200) & 7) == 0)) && (iVar4 != 0)) &&
       ((*(byte *)(iVar4 + 200) & 7) == 0)) {
      iVar7 = *(int *)(iVar3 + 0xcc);
      iVar4 = *(int *)(iVar4 + 0xcc);
      iVar5 = *(int *)(param_1 + 0x10);
      iVar3 = iVar7 * 8;
      iVar6 = *(int *)(iVar5 + iVar3);
      if (iVar7 != iVar6) {
        do {
          *(undefined4 *)(iVar5 + iVar3) = *(undefined4 *)(iVar5 + iVar6 * 8);
          iVar5 = *(int *)(param_1 + 0x10);
          iVar7 = *(int *)(iVar5 + iVar3);
          iVar6 = *(int *)(iVar5 + iVar7 * 8);
          iVar3 = iVar7 * 8;
        } while (iVar7 != iVar6);
      }
      iVar5 = *(int *)(param_1 + 0x10);
      iVar3 = iVar4 * 8;
      iVar6 = *(int *)(iVar3 + iVar5);
      puVar8 = (undefined4 *)(iVar3 + iVar5);
      if (iVar4 != iVar6) {
        do {
          *puVar8 = *(undefined4 *)(iVar5 + iVar6 * 8);
          iVar5 = *(int *)(param_1 + 0x10);
          iVar4 = *(int *)(iVar3 + iVar5);
          iVar3 = iVar4 * 8;
          iVar6 = *(int *)(iVar3 + iVar5);
          puVar8 = (undefined4 *)(iVar3 + iVar5);
        } while (iVar4 != iVar6);
      }
      if (iVar7 != iVar4) {
        *(int *)(*(int *)(param_1 + 0x10) + iVar7 * 8) = iVar4;
        iVar3 = *(int *)(param_1 + 0x10);
        *(int *)(iVar3 + 4 + iVar4 * 8) =
             *(int *)(iVar3 + 4 + iVar4 * 8) + *(int *)(iVar3 + 4 + iVar7 * 8);
      }
    }
    local_8 = local_8 + 1;
    iVar1 = iVar1 + 0x10;
  }
  return;
}

