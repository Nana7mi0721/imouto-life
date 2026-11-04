
undefined4 FUN_00605b90(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b281b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0xa0);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_00605a30(param_1,param_2);
  ExceptionList = local_c;
  return uVar2;
}

