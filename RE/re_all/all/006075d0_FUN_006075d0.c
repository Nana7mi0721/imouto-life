
void __fastcall FUN_006075d0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_007b269c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_00803a8c;
  param_1[3] = &PTR_LAB_00803a50;
  param_1[4] = &PTR_LAB_00803db0;
  local_4 = 3;
  FUN_006034c0();
  local_4._0_1_ = 2;
  FUN_006062b0();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00606bd0();
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  local_4 = 0xffffffff;
  FUN_005fffa0();
  ExceptionList = local_c;
  return;
}

