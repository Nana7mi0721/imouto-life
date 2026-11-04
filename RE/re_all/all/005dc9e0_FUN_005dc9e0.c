
undefined4 FUN_005dc9e0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x56);
  if (*(int *)(param_1 + 0x52) == iVar1) {
    return 0xffffffff;
  }
  iVar2 = *(int *)(param_1 + 0x52) - iVar1;
  if (*(int *)(param_1 + 0x450) < iVar2) {
    iVar2 = *(int *)(param_1 + 0x450);
  }
  FUN_0056d420(*(undefined4 *)(param_1 + 0x44c),*(int *)(param_1 + 0x4a) + iVar1,iVar2);
  *(int *)(param_1 + 0x454) = iVar2;
  *(int *)(param_1 + 0x56) = *(int *)(param_1 + 0x56) + iVar2;
  return 0;
}

