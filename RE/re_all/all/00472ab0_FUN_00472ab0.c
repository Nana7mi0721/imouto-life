
undefined4 __thiscall FUN_00472ab0(undefined4 param_1,undefined1 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007aece8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004d2ec0();
  local_8 = 0;
  FUN_00472b10(param_2);
  ExceptionList = local_10;
  return param_1;
}

