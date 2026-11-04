
int FUN_006c2650(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x18) <= param_2) {
    param_2 = *(int *)(param_1 + 0x18) + -1;
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    return *(int *)(param_1 + 0x1c) + 0x2c;
  }
  if (param_2 < 0) {
    param_2 = *(int *)(param_1 + 0x60);
  }
  return param_2 * 0x160 + 0x2c + *(int *)(param_1 + 0x1c);
}

