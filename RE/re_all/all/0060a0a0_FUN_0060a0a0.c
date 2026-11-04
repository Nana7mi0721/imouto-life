
undefined4 * FUN_0060a0a0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2803;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = operator_new(0x1e8);
  local_4 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_006074e0(s_Mem_Reader_00a0614c,0,param_1,param_3);
    local_4 = CONCAT31(local_4._1_3_,1);
    *puVar1 = &PTR_FUN_00803e44;
    puVar1[3] = &PTR_LAB_00803a50;
    puVar1[4] = &PTR_LAB_00803e30;
    FUN_00603500(param_2);
    ExceptionList = local_c;
    return puVar1;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0x8007000e;
  }
  ExceptionList = local_c;
  return (undefined4 *)0x0;
}

