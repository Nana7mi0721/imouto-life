
undefined4 FUN_005bff60(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x3c);
  if (*(int *)(param_1 + 0x30) == 0) {
    if (*piVar1 != 0) {
      FUN_005d1fc0(*piVar1);
      **(undefined4 **)(param_1 + 0x3c) = 0;
    }
  }
  else if (*piVar1 != 0) {
    FUN_005d1fa0(*piVar1);
    **(undefined4 **)(param_1 + 0x3c) = 0;
    return 0;
  }
  return 0;
}

