
undefined4 FUN_0052ee10(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  FUN_0056d380(param_1 + 0xfd80,0,0x80000);
  iVar4 = param_1 + 0x60;
  FUN_0056d380(iVar4,0,0xfd20);
  FUN_0056d380(param_1 + 0x8fd84,0,0x1000);
  iVar1 = 0;
  *(undefined4 *)(param_1 + 0x8fd80) = 0;
  iVar3 = iVar4;
  if (0 < *(int *)(param_1 + 0x90d88)) {
    do {
      *(int *)(iVar3 + 0x10) = iVar1;
      iVar4 = iVar3 + 0x20;
      *(int *)(iVar3 + 0x14) = iVar1 / *(int *)(param_1 + 0x93194);
      iVar2 = iVar1 % *(int *)(param_1 + 0x93194);
      iVar1 = iVar1 + 1;
      *(int *)(iVar3 + 0x18) = iVar2;
      iVar3 = iVar4;
    } while (iVar1 < *(int *)(param_1 + 0x90d88));
  }
  *(undefined4 *)(iVar4 + 0x10) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x90d84) = 0;
  return 0;
}

