
undefined4 FUN_005da2e0(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x640) == 1) {
    DeleteFileW((LPCWSTR)(param_1 + 0x644));
    *(undefined4 *)(param_1 + 0x640) = 0;
  }
  if (0 < *(int *)(param_1 + 0x5e0)) {
    FUN_00515700(*(int *)(param_1 + 0x5e0),0);
    *(undefined4 *)(param_1 + 0x5e0) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x56c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x56c) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x570);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x570) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x574);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x574) = 0;
  }
  if (*(int *)(param_1 + 0x5bc) != 0) {
    FUN_0056e1d0(*(int *)(param_1 + 0x5bc));
    *(undefined4 *)(param_1 + 0x5bc) = 0;
  }
  if (*(int *)(param_1 + 0x5f8) != 0) {
    FUN_0056e1d0(*(int *)(param_1 + 0x5f8));
    *(undefined4 *)(param_1 + 0x5f8) = 0;
  }
  if (*(int *)(param_1 + 0x5fc) != 0) {
    FUN_0056e1d0(*(int *)(param_1 + 0x5fc));
    *(undefined4 *)(param_1 + 0x5fc) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x630);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x630) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x62c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x62c) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x628);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x628) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x624);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x624) = 0;
  }
  if (*(int **)(param_1 + 0x634) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x634) + 0xc))(1);
    *(undefined4 *)(param_1 + 0x634) = 0;
  }
  return 0;
}

