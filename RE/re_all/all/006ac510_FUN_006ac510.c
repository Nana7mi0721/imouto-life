
undefined4 FUN_006ac510(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_14 [20];
  
  iVar1 = *(int *)(param_1 + 0x1c);
  FUN_007976d0(local_14,*param_2,param_2[1]);
  iVar2 = FUN_00797830(local_14,1);
  if (iVar2 != 0) {
    return 0xffffff79;
  }
  iVar3 = 0;
  for (iVar2 = *(int *)(iVar1 + 8); 1 < iVar2; iVar2 = iVar2 >> 1) {
    iVar3 = iVar3 + 1;
  }
  iVar2 = FUN_00797830(local_14,iVar3);
  if (iVar2 == -1) {
    return 0xffffff78;
  }
  return *(undefined4 *)(iVar1 + **(int **)(iVar1 + 0x20 + iVar2 * 4) * 4);
}

