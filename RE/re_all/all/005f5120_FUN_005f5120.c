
undefined4 FUN_005f5120(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < 0) {
    return 0;
  }
  if (((*(int *)(param_1 + 0x4c) == 1) &&
      (iVar3 = *(int *)(param_1 + 0x10), *(int *)(param_1 + 8) == iVar3)) ||
     (iVar3 = *(int *)(param_1 + 0x10), param_2 != iVar3)) {
    iVar1 = *(int *)(param_1 + 0x44);
    iVar2 = *(int *)(param_1 + 0x40);
    FUN_00519140(param_2,0,0,iVar2,iVar1,
                 (*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20)) / *(int *)(param_1 + 0x30) +
                 iVar2,(*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24)) /
                       *(int *)(param_1 + 0x30) + iVar1,iVar2,iVar1,iVar3);
    return 0;
  }
  return 0;
}

