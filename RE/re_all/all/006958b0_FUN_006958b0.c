
void FUN_006958b0(int *param_1)

{
  if (param_1[0x42] == param_1[0x43]) {
    param_1[0x5b] = param_1[0x42];
    return;
  }
  *(undefined4 *)(*param_1 + 0x14) = 7;
  *(int *)(*param_1 + 0x18) = param_1[0x42];
  *(int *)(*param_1 + 0x1c) = param_1[0x43];
  (**(code **)*param_1)(param_1);
  param_1[0x5b] = param_1[0x42];
  return;
}

