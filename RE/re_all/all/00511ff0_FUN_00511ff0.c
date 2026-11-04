
undefined4 FUN_00511ff0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (((DAT_00a238e8 != 1) || (DAT_00a238e4 != 0)) || (0x1ff < DAT_00a218c4)) {
    FUN_00510df0(param_1,param_2,param_3,param_4);
    return 0;
  }
  *(undefined4 *)(&DAT_00a218d0 + DAT_00a218cc * 4) = param_1;
  *(undefined4 *)(&DAT_00a220d0 + DAT_00a218cc * 4) = param_2;
  *(undefined4 *)(&DAT_00a228d0 + DAT_00a218cc * 4) = param_3;
  *(undefined4 *)(&DAT_00a230d0 + DAT_00a218cc * 4) = param_4;
  DAT_00a218cc = DAT_00a218cc + 1 & 0x800001ff;
  if ((int)DAT_00a218cc < 0) {
    DAT_00a218cc = (DAT_00a218cc - 1 | 0xfffffe00) + 1;
  }
  DAT_00a218c4 = DAT_00a218c4 + 1;
  return 0;
}

