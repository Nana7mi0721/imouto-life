
undefined4 FUN_005185c0(int param_1,int param_2,int param_3,int *param_4,int *param_5)

{
  if (0 < param_3) {
    do {
      param_1 = param_1 / 2;
      param_2 = param_2 / 2;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  if (param_1 < 1) {
    param_1 = 1;
  }
  if (param_2 < 1) {
    param_2 = 1;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = param_1;
  }
  if (param_5 != (int *)0x0) {
    *param_5 = param_2;
  }
  return 0;
}

