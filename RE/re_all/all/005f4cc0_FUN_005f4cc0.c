
undefined4 FUN_005f4cc0(int *param_1)

{
  param_1[0x12] = -1;
  if ((*param_1 == 0) && (param_1[1] == 1)) {
    param_1[0x13] = 1;
    param_1[0x12] = 2;
  }
  else {
    param_1[0x12] = 1;
    param_1[0x13] = 0;
  }
  if ((param_1[8] != param_1[0x10]) || (param_1[9] != param_1[0x11])) {
    param_1[0x13] = 1;
  }
  return 0;
}

