
void FUN_0057fac0(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  if (param_1 == 0) {
    *param_2 = *param_2 + param_4 + 2;
    return;
  }
  *(short *)(param_1 + *param_2) = (short)param_4 + 2;
  FUN_0056d420(*param_2 + 2 + param_1,param_3,param_4);
  *param_2 = *param_2 + param_4 + 2;
  return;
}

