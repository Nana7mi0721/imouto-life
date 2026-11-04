
undefined4 * __thiscall
FUN_00600880(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  FUN_00600bb0(param_2,param_3,param_4,param_5);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
  param_1[0x12] = 1;
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  param_1[0xf] = 0;
  param_1[0x11] = 0;
  *param_1 = &PTR_LAB_008032c8;
  param_1[1] = &PTR_LAB_00803280;
  param_1[2] = &PTR_LAB_00803270;
  return param_1;
}

