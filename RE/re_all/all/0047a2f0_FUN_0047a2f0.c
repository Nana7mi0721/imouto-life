
undefined4 __thiscall FUN_0047a2f0(undefined4 param_1,int param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af0b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0047a400(param_2);
  local_8 = 0;
  FUN_004ceed0(param_2 + 0x3c);
  ExceptionList = local_10;
  return param_1;
}

