
void __fastcall FUN_00606bd0(LPCRITICAL_SECTION param_1)

{
  void *_Memory;
  int local_14;
  LPCRITICAL_SECTION local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_007b2645;
  local_c = ExceptionList;
  local_4 = 7;
  ExceptionList = &local_c;
  local_10 = param_1;
  FUN_00606f80();
  FUN_00607100();
  local_14 = param_1[3].RecursionCount;
  while (local_14 != 0) {
    _Memory = (void *)FUN_00603940(&local_14);
    _free(_Memory);
  }
  FUN_00603900();
  FUN_00603060();
  FUN_00603060();
  FUN_00603060();
  FUN_00603060();
  local_4._0_1_ = 2;
  FUN_006038b0();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_006038b0();
  DeleteCriticalSection((LPCRITICAL_SECTION)&param_1[1].LockCount);
  DeleteCriticalSection(param_1);
  ExceptionList = local_c;
  return;
}

