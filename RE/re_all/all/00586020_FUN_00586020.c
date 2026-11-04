
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00586020(double *param_1,double param_2,double param_3,double param_4,double param_5)

{
  FUN_0056d380(param_1,0,0x80);
  *param_1 = param_4 * _DAT_00804a60;
  param_1[5] = param_5 * _DAT_007d9b88;
  param_1[10] = 1.0;
  param_1[0xf] = 1.0;
  param_1[0xc] = param_2;
  param_1[0xd] = param_3;
  param_1[0xe] = 0.0;
  return 0;
}

