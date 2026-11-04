
undefined4 FUN_006a8d00(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_006a8470(param_1);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x154) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x158) = 0;
    *(undefined4 *)(param_1 + 0x160) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x144) = 0;
    *(undefined4 *)(param_1 + 0x148) = 0;
    *(undefined4 *)(param_1 + 0x14c) = 0;
    *(undefined4 *)(param_1 + 0x15c) = 0;
    *(undefined4 *)(param_1 + 0x164) = 0;
    return 0;
  }
  return 0xffffffff;
}

