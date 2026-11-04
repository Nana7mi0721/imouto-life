
undefined4 * __thiscall FUN_0078fe60(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_00837460;
  if (*(char *)((int)param_1 + 0x39) != '\0') {
    (*(code *)**(undefined4 **)param_1[0xd])(0);
    FUN_00646b80(param_1[0xd]);
  }
  FUN_007913b0();
  if ((param_2 & 1) != 0) {
    FUN_00646b80(param_1);
  }
  return param_1;
}

