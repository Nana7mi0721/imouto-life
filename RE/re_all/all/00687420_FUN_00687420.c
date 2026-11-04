
void FUN_00687420(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  FUN_00686af0(param_1,0xda);
  FUN_00686b50(param_1,*(int *)(param_1 + 0x114) * 2 + 6);
  FUN_00686b10(param_1,*(undefined4 *)(param_1 + 0x114));
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x114)) {
    piVar5 = (int *)(param_1 + 0x118);
    do {
      puVar1 = (undefined4 *)*piVar5;
      FUN_00686b10(param_1,*puVar1);
      if ((*(int *)(param_1 + 0x15c) == 0) && (*(int *)(param_1 + 0x164) == 0)) {
        iVar2 = puVar1[5];
      }
      else {
        iVar2 = 0;
      }
      if (*(int *)(param_1 + 0x160) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = puVar1[6];
      }
      FUN_00686b10(param_1,iVar2 * 0x10 + iVar3);
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x114));
  }
  FUN_00686b10(param_1,*(undefined4 *)(param_1 + 0x15c));
  FUN_00686b10(param_1,*(undefined4 *)(param_1 + 0x160));
  FUN_00686b10(param_1,*(int *)(param_1 + 0x164) * 0x10 + *(int *)(param_1 + 0x168));
  return;
}

