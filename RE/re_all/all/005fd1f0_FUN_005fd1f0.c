
void __fastcall FUN_005fd1f0(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_007b22b0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_00802f74;
  param_1[3] = &PTR_LAB_00802f38;
  param_1[4] = &PTR_LAB_00803db0;
  local_4 = 6;
  FUN_005fe6e0();
  FUN_005fe360();
  if (param_1[0x14] != 0) {
    (**(code **)(*(int *)(param_1[0x14] + 8) + 0xc))(1);
    param_1[0x14] = 0;
  }
  if ((int *)param_1[0x1e] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x1e] + 0xc))(1);
    param_1[0x1e] = 0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x31));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x25));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1f));
  local_4._0_1_ = 2;
  FUN_00603060();
  local_4._0_1_ = 1;
  FUN_00603060();
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00603060();
  local_4 = 0xffffffff;
  FUN_005fffa0();
  ExceptionList = pvStack_c;
  return;
}

