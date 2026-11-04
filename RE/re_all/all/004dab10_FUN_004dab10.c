
int __thiscall FUN_004dab10(int param_1,int param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0068;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004cdf90(param_2);
  local_8 = 0;
  FUN_004dab90(param_2 + 0x10);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_2 + 0x24);
  ExceptionList = local_10;
  return param_1;
}

