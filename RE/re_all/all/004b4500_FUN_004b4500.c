
undefined4 * __thiscall FUN_004b4500(undefined4 *param_1,int param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0418;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004b4bb0(param_2);
  local_8 = 0;
  *param_1 = &PTR_FUN_007d0aa8;
  *(undefined1 *)(param_1 + 0x52) = *(undefined1 *)(param_2 + 0x148);
  *(undefined1 *)((int)param_1 + 0x149) = *(undefined1 *)(param_2 + 0x149);
  param_1[0x53] = *(undefined4 *)(param_2 + 0x14c);
  FUN_004d2350(param_2 + 0x150);
  ExceptionList = local_10;
  return param_1;
}

