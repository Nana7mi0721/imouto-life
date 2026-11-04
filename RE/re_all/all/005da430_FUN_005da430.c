
undefined4 FUN_005da430(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x56c) == 0) {
    piVar1 = *(int **)(param_1 + 0x628);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x1c))(piVar1);
    }
    return 0;
  }
  FUN_005d9250(DAT_00a37dc8 == 0,DAT_00a37dc8 != 0,0);
  if (*(int *)(param_1 + 0x5d8) != 1) {
    param_2 = 1;
  }
  FUN_00561a00(*(undefined4 *)(param_1 + 0x5e0),param_2,0);
  uVar2 = FUN_00550090(0);
  *(undefined8 *)(param_1 + 0x5c8) = uVar2;
  uVar2 = __allmul(*(int *)(param_1 + 0x5c0),*(int *)(param_1 + 0x5c0) >> 0x1f,
                   *(undefined4 *)(param_1 + 0x584),0);
  uVar2 = __allmul(uVar2,1000000,0);
  uVar2 = __alldiv(uVar2,*(undefined4 *)(param_1 + 0x580),0);
  *(undefined8 *)(param_1 + 0x5d0) = uVar2;
  return 0;
}

