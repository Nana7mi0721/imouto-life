
undefined4 __thiscall FUN_0063d590(float *param_1,float param_2)

{
  if (*param_1 <= param_1[1]) {
    if (param_2 < *param_1) {
      param_1[0xc] = 1.4013e-45;
      param_1[10] = param_2 - *param_1;
      return 1;
    }
    if (param_1[1] < param_2) {
      param_1[0xc] = 2.8026e-45;
      param_1[10] = param_2 - param_1[1];
      return 2;
    }
  }
  param_1[0xc] = 0.0;
  return 0;
}

