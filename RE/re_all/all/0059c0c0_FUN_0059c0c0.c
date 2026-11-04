
undefined4 FUN_0059c0c0(int param_1,int param_2,undefined1 param_3)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x400)) {
    puVar2 = (ushort *)(param_1 + 2);
    do {
      uVar1 = (uint)puVar2[-1];
      if (uVar1 < *puVar2) {
        do {
          *(undefined1 *)(uVar1 + param_2) = param_3;
          uVar1 = uVar1 + 1;
        } while ((int)uVar1 < (int)(uint)*puVar2);
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 2;
    } while (iVar3 < *(int *)(param_1 + 0x400));
  }
  return 0;
}

