
void __fastcall FUN_00608040(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_007b26f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_LAB_00803ae0;
  param_1[3] = &PTR_LAB_00803ab4;
  local_4 = 0;
  FUN_00607bf0(param_1 + 3);
  FUN_00607ff0();
  local_4 = 0xffffffff;
  FUN_00607760();
  ExceptionList = local_c;
  return;
}

