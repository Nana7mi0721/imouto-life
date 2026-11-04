
uint FUN_0067d7a0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (((param_1 == 0) || (iVar1 = *(int *)(param_1 + 0x1c), iVar1 == 0)) ||
     (((iVar2 = *(int *)(iVar1 + 4), iVar2 != 0x2a &&
       (((iVar2 != 0x45 && (iVar2 != 0x49)) && (iVar2 != 0x5b)))) &&
      (((iVar2 != 0x67 && (iVar2 != 0x71)) && (iVar2 != 0x29a)))))) {
    return 0xfffffffe;
  }
  if (*(int *)(iVar1 + 8) != 0) {
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(int *)(iVar1 + 8));
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 0x44);
  if (iVar1 != 0) {
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),iVar1);
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 0x40);
  if (iVar1 != 0) {
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),iVar1);
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 0x38);
  if (iVar1 != 0) {
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),iVar1);
  }
  (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x1c));
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return (iVar2 != 0x71) - 1 & 0xfffffffd;
}

