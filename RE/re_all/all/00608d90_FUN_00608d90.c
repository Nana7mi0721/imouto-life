
undefined4 __thiscall FUN_00608d90(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2576;
  local_c = ExceptionList;
  local_14 = 0;
  ExceptionList = &local_c;
  if (*(int *)(param_1 + 0x8c) == 0) {
    ExceptionList = &local_c;
    local_10 = operator_new(0xe8);
    local_4 = 0;
    if (local_10 == (void *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_006087f0(0,param_1,&local_14,u_Input_00a060f0);
    }
    *(int *)(param_1 + 0x8c) = iVar1;
    if (iVar1 == 0) goto LAB_00608e70;
  }
  local_4 = 0xffffffff;
  if (*(int *)(param_1 + 0x90) == 0) {
    local_10 = operator_new(0xb0);
    local_4 = 1;
    if (local_10 == (void *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_00608bd0(0,param_1,&local_14,u_Output_00a060e0);
    }
    local_4 = 0xffffffff;
    *(int *)(param_1 + 0x90) = iVar1;
    if (iVar1 == 0) {
      if (*(int **)(param_1 + 0x8c) != (int *)0x0) {
        (**(code **)(**(int **)(param_1 + 0x8c) + 0xc))(1);
      }
      *(undefined4 *)(param_1 + 0x8c) = 0;
    }
  }
LAB_00608e70:
  if (param_2 == 0) {
    ExceptionList = local_c;
    return *(undefined4 *)(param_1 + 0x8c);
  }
  if (param_2 == 1) {
    ExceptionList = local_c;
    return *(undefined4 *)(param_1 + 0x90);
  }
  ExceptionList = local_c;
  return 0;
}

