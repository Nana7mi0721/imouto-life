
void FUN_005ee470(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_00567b30();
  if (iVar2 != 0) {
    FUN_005d38f0(*(undefined4 *)(param_1 + 0x20));
    FUN_005d3370(*(undefined4 *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  iVar2 = 0;
  if (0 < DAT_00a37da8) {
    do {
      iVar1 = *(int *)(param_1 + iVar2 * 4);
      if (iVar1 != 0) {
        FUN_005a0bd0(iVar1,iVar2);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_00a37da8);
  }
  DAT_00e39a54 = 1;
  FUN_005a0ad0(DAT_00a38194,DAT_00a38198,DAT_00a3819c,DAT_00a381a0);
  DAT_00e39a54 = 0;
  FUN_00516dc0(*(undefined4 *)(param_1 + 0x40));
  FUN_00516400(*(undefined4 *)(param_1 + 0x3c));
  FUN_00516160(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x30));
  FUN_005160a0(*(undefined4 *)(param_1 + 0x38));
  FUN_005160d0(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28));
  FUN_00516290();
  return;
}

