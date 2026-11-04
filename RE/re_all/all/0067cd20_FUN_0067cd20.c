
undefined4 FUN_0067cd20(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((param_1 == 0) || (iVar1 = *(int *)(param_1 + 0x1c), iVar1 == 0)) ||
      (*(int *)(param_1 + 0x20) == 0)) || (*(int *)(param_1 + 0x24) == 0)) {
    return 0xfffffffe;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 2;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 8);
  if (*(int *)(iVar1 + 0x18) < 0) {
    *(int *)(iVar1 + 0x18) = -*(int *)(iVar1 + 0x18);
  }
  *(uint *)(iVar1 + 4) = (-(uint)(*(int *)(iVar1 + 0x18) != 0) & 0xffffffb9) + 0x71;
  if (*(int *)(iVar1 + 0x18) == 2) {
    uVar2 = FUN_0067c560();
  }
  else {
    uVar2 = FUN_0067c870(0,0,0);
  }
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  FUN_0067f450(iVar1);
  return 0;
}

