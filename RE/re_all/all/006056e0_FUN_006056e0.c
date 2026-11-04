
void __fastcall FUN_006056e0(undefined4 *param_1)

{
  int *piVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_007b25a8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_LAB_008037a0;
  param_1[3] = &PTR_LAB_00803758;
  param_1[4] = &PTR_LAB_008038a4;
  piVar1 = (int *)param_1[0x29];
  local_4 = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_4 = 0xffffffff;
  FUN_00601fe0();
  ExceptionList = pvStack_c;
  return;
}

