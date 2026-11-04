
undefined1 * __thiscall FUN_004b46e0(undefined1 *param_1,undefined1 *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b030b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *param_2;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  param_1[8] = param_2[8];
  FUN_004cd4e0(param_2 + 0xc);
  local_8 = 0;
  FUN_004cd890(param_2 + 0x1c);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 0x2c);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 0x30);
  ExceptionList = local_10;
  return param_1;
}

