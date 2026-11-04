
undefined4 * __thiscall FUN_004ab5b0(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  FUN_004cda30(param_2 + 2);
  FUN_004cd190(param_2 + 6);
  FUN_004cc270(param_2 + 10);
  FUN_004cd190(param_2 + 0xe);
  FUN_004cdcd0(param_2 + 0x12);
  return param_1;
}

