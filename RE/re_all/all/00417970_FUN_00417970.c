
undefined4 FUN_00417970(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int *param_4)

{
  if (param_4[1] < param_4[2]) {
    *(undefined4 *)(*param_4 + 0xc + param_4[1] * 0x10) = param_3[3];
    *(undefined4 *)(param_4[1] * 0x10 + *param_4) = *param_3;
    *(undefined4 *)(*param_4 + 4 + param_4[1] * 0x10) = param_3[1];
    *(undefined4 *)(*param_4 + 8 + param_4[1] * 0x10) = param_3[2];
    param_4[1] = param_4[1] + 1;
  }
  return 1;
}

