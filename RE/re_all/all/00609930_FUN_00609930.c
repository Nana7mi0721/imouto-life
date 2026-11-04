
int FUN_00609930(undefined4 param_1,undefined4 *param_2)

{
  void *pvVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b281b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x110);
  local_4 = 0;
  if ((pvVar1 != (void *)0x0) && (iVar2 = FUN_006099a0(param_1,param_2,0), iVar2 != 0)) {
    ExceptionList = local_c;
    return iVar2;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0x8007000e;
  }
  ExceptionList = local_c;
  return 0;
}

