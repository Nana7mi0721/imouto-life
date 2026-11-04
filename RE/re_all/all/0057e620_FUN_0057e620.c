
undefined4 FUN_0057e620(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 200);
  if (DAT_00aa4fa0 == 0) {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(param_1 + 200) = 0;
    }
  }
  else {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x48))(piVar1);
      *(undefined4 *)(param_1 + 200) = 0;
    }
    piVar1 = *(int **)(param_1 + 0xcc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x48))(piVar1);
      *(undefined4 *)(param_1 + 0xcc) = 0;
    }
    if (*(void **)(param_1 + 0xd4) != (void *)0x0) {
      _free(*(void **)(param_1 + 0xd4));
      *(undefined4 *)(param_1 + 0xd4) = 0;
      return 0;
    }
  }
  return 0;
}

