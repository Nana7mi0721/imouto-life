
undefined4 * __thiscall FUN_00609450(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2738;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_006087f0(s_SampleGrabberInputPin_00a060fc,param_2,param_3,u_Input_00a06114);
  local_4 = 0;
  param_1[0x3a] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  *param_1 = &PTR_LAB_00803d10;
  param_1[3] = &PTR_LAB_00803cc8;
  param_1[4] = &PTR_LAB_0080304c;
  param_1[0x26] = &PTR_LAB_00803ca4;
  FUN_0056d380(param_1 + 0x3b,0,0x10);
  ExceptionList = local_c;
  return param_1;
}

