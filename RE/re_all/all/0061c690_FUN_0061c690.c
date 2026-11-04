
undefined4 * __fastcall FUN_0061c690(undefined4 *param_1)

{
  uint unaff_ESI;
  
  *param_1 = &PTR_FUN_00804558;
  param_1[3] = &PTR_FUN_00804568;
  (**(code **)(*(int *)param_1[0xf] + 0x10))(param_1[0x13]);
  (**(code **)(*(int *)param_1[0xf] + 0xc))(param_1[0x13]);
  FUN_00627fe0();
  FUN_006279e0();
  if ((unaff_ESI & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}

