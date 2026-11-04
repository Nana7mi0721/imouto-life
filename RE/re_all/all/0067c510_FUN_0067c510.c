
undefined4 FUN_0067c510(int param_1)

{
  int iVar1;
  
  if (((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) ||
     (*(code **)(param_1 + 0x24) == (code *)0x0)) {
    return 0xfffffffe;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 0x34);
  if (iVar1 != 0) {
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),iVar1);
  }
  (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x1c));
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return 0;
}

