
undefined1 * __fastcall FUN_00484e90(undefined1 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b191b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004ce850();
  local_8 = 0;
  basic_string<>();
  *param_1 = 0;
  ExceptionList = local_10;
  return param_1;
}

