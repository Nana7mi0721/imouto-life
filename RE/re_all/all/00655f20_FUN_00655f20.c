
undefined4 FUN_00655f20(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  
  if (param_2 == 0 && param_3 == 0) {
    return 0;
  }
  uVar3 = 0;
  uVar1 = *(ushort *)(param_1 + 0x26);
  if (uVar1 != 0) {
    iVar2 = *(int *)(param_1 + 0x20);
    do {
      if (iVar2 == 0) break;
      if ((*(int *)(iVar2 + (uint)uVar3 * 8) == param_2) &&
         (*(int *)(iVar2 + (uint)uVar3 * 8 + 4) == param_3)) {
        return 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  uVar1 = uVar1 + 1;
  *(ushort *)(param_1 + 0x26) = uVar1;
  if (*(ushort *)(param_1 + 0x24) < uVar1) {
    iVar2 = FUN_00650ba0(param_1,*(undefined4 *)(param_1 + 0x20),uVar1,0x10,s_for_IFD_list_00a0a308)
    ;
    if (iVar2 == 0) {
      return 0;
    }
    *(int *)(param_1 + 0x20) = iVar2;
    *(short *)(param_1 + 0x24) = *(short *)(param_1 + 0x26) << 1;
  }
  iVar2 = *(int *)(param_1 + 0x20);
  uVar1 = *(ushort *)(param_1 + 0x26);
  *(int *)(iVar2 + -8 + (uint)uVar1 * 8) = param_2;
  *(int *)(iVar2 + -4 + (uint)uVar1 * 8) = param_3;
  return 1;
}

