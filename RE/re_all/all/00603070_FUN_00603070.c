
undefined4 * __thiscall FUN_00603070(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b24db;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_LAB_00803488;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = param_2;
  param_1[5] = 1;
  FUN_00603890(0);
  *param_1 = &PTR_LAB_00803468;
  local_4 = 0;
  (**(code **)(*(int *)(param_1[3] + 0xc) + 4))((int *)(param_1[3] + 0xc));
  if (param_2 == 0) {
    uVar1 = (**(code **)(*(int *)param_1[3] + 0x14))();
    param_1[4] = uVar1;
    uVar1 = (**(code **)(*(int *)param_1[3] + 0x18))();
    param_1[2] = uVar1;
  }
  else {
    param_1[1] = *(undefined4 *)(param_2 + 4);
    param_1[2] = *(undefined4 *)(param_2 + 8);
    param_1[4] = *(undefined4 *)(param_2 + 0x10);
    FUN_00603af0(param_2 + 0x18);
  }
  ExceptionList = param_1;
  return param_1;
}

