
void __fastcall FUN_00603150(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_007b24db;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_LAB_00803468;
  local_4 = 0;
  (**(code **)(*(int *)(param_1[3] + 0xc) + 8))((int *)(param_1[3] + 0xc));
  puStack_8 = (undefined1 *)0xffffffff;
  FUN_006038b0();
  ExceptionList = param_1;
  return;
}

