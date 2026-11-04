
void __fastcall FUN_00603bf0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_007b2518;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_LAB_0080352c;
  param_1[3] = &PTR_LAB_008034f0;
  param_1[4] = &PTR_LAB_008034dc;
  param_1[0x38] = &PTR_LAB_008034b8;
  param_1[0x39] = &PTR_LAB_008034a4;
  local_4 = 0;
  if (param_1[0x5f] != 0) {
    FUN_0056e1d0(param_1[0x5f]);
    param_1[0x5f] = 0;
  }
  if (param_1[0x60] != 0) {
    FUN_0056e1d0(param_1[0x60]);
    param_1[0x60] = 0;
    param_1[0x61] = 0;
  }
  if (param_1[0x5d] != 0) {
    FUN_005421c0(param_1[0x5d]);
    _free((void *)param_1[0x5d]);
    param_1[0x5d] = 0;
  }
  local_4 = 0xffffffff;
  FUN_005fec90();
  ExceptionList = local_c;
  return;
}

