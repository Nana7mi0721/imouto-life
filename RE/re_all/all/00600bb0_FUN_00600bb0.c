
undefined4 * __thiscall
FUN_00600bb0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            int param_5)

{
  *param_1 = &PTR_LAB_00803380;
  FUN_00601530(param_2,param_3);
  *param_1 = &PTR_LAB_0080332c;
  param_1[6] = param_5;
  param_1[1] = &PTR_LAB_00803280;
  param_1[2] = &PTR_LAB_0080331c;
  if (param_5 == 0) {
    *param_4 = 0x80004003;
  }
  return param_1;
}

