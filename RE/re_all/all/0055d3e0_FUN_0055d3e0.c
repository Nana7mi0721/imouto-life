
undefined4 FUN_0055d3e0(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    return 0xffffffff;
  }
  if (param_2 < -10000) {
    param_1[1] = -10000;
    uVar1 = FUN_00551a70(param_1);
    return uVar1;
  }
  if (10000 < param_2) {
    param_2 = 10000;
  }
  param_1[1] = param_2;
  uVar1 = FUN_00551a70(param_1);
  return uVar1;
}

