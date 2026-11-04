
undefined4 FUN_00595f80(int param_1)

{
  int iVar1;
  HGDIOBJ pvVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x30) + 0x18);
  if (iVar1 != 0) {
    FUN_0056e1d0(iVar1);
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x18) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x1c) = 0;
  }
  pvVar2 = *(HGDIOBJ *)(*(int *)(param_1 + 0x30) + 0x10);
  if (pvVar2 != (HGDIOBJ)0x0) {
    DeleteObject(pvVar2);
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x10) = 0;
  }
  pvVar2 = *(HGDIOBJ *)(*(int *)(param_1 + 0x30) + 4);
  if (pvVar2 != (HGDIOBJ)0x0) {
    DeleteObject(pvVar2);
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 4) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 8) = 0;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x30) + 0x14);
  if (iVar1 != 0) {
    FUN_0056e1d0(iVar1);
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x14) = 0;
  }
  return 0;
}

