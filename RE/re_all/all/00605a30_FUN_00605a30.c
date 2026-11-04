
undefined4 * __thiscall FUN_00605a30(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  void *pvVar1;
  int *piVar2;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b25de;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00604aa0(0,param_2,&DAT_00802ed0);
  *param_1 = &PTR_FUN_0080383c;
  param_1[3] = &PTR_LAB_00803800;
  param_1[4] = &PTR_LAB_00803db0;
  local_4 = 0;
  if (-1 < *param_3) {
    pvVar1 = operator_new(0xa8);
    local_4._0_1_ = 1;
    if (pvVar1 == (void *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)FUN_00606100(param_1,param_3);
    }
    local_4 = (uint)local_4._1_3_ << 8;
    if (piVar2 == (int *)0x0) {
      *param_3 = -0x7ff8fff2;
    }
    else if (*param_3 < 0) {
      (**(code **)(*piVar2 + 0xc))(1);
    }
    else {
      param_1[0x24] = piVar2;
    }
    pvVar1 = operator_new(0xe0);
    local_4._0_1_ = 2;
    if (pvVar1 == (void *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)FUN_00605210(0,param_1,param_3,&DAT_00a06030);
    }
    local_4 = (uint)local_4._1_3_ << 8;
    if (piVar2 == (int *)0x0) {
      *param_3 = -0x7ff8fff2;
    }
    else if (*param_3 < 0) {
      (**(code **)(*piVar2 + 0xc))(1);
    }
    else {
      param_1[0x23] = piVar2;
    }
  }
  ExceptionList = local_c;
  return param_1;
}

