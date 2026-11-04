
undefined4 FUN_005dced0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x4a);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x4a) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x4e);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x4e) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x52);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x52) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x56);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x56) = 0;
  }
  if (*(int *)(param_1 + 0x66) != 0) {
    FUN_0056e1d0(*(int *)(param_1 + 0x66));
    *(undefined4 *)(param_1 + 0x66) = 0;
  }
  return 0;
}

