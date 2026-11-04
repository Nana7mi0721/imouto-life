
undefined4 __fastcall FUN_005fddd0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[0x2b];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[0x2b] = 0;
  }
  if (*(int *)(param_1[0x1e] + 0x18) == 0) {
    return 1;
  }
  if ((param_1[5] != 0) && (*(char *)(param_1[0x1e] + 0x25) == '\0')) {
    return 0x80040224;
  }
  FUN_005fe750(0);
  (**(code **)(*param_1 + 100))();
  (**(code **)(*param_1 + 0x70))();
  param_1[0x18] = 0;
  if (param_1[5] == 2) {
    (**(code **)(*param_1 + 0x80))();
  }
  return 0;
}

