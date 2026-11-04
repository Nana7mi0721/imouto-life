
undefined4 FUN_005fca40(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 0x40) + 0x114)) {
    iVar1 = *(int *)(param_1 + 0x1a0) + 8;
    do {
      FUN_005fcbd0(iVar1);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x288;
    } while (iVar2 < *(int *)(*(int *)(param_1 + 0x40) + 0x114));
  }
  iVar2 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 0x40) + 0x11c)) {
    iVar1 = *(int *)(param_1 + 0x1a4) + 4;
    do {
      FUN_005fcc10(iVar1);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x44;
    } while (iVar2 < *(int *)(*(int *)(param_1 + 0x40) + 0x11c));
  }
  FUN_005fcad0(param_1 + 0x278);
  return 0;
}

