
void __fastcall FUN_00609510(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_007b2738;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_LAB_00803d10;
  param_1[3] = &PTR_LAB_00803cc8;
  param_1[4] = &PTR_LAB_0080304c;
  param_1[0x26] = &PTR_LAB_00803ca4;
  local_4 = 0;
  if ((int *)param_1[0x3a] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x3a] + 0xc))(1);
  }
  local_4 = 0xffffffff;
  FUN_006018c0();
  ExceptionList = pvStack_c;
  return;
}

