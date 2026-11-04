
undefined4 * __thiscall FUN_004d3fe0(undefined4 *param_1,int param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af102;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004b4bb0(param_2);
  local_8 = 0;
  *param_1 = &PTR_FUN_007d0aac;
  param_1[0x52] = *(undefined4 *)(param_2 + 0x148);
  FUN_004d1f60(param_2 + 0x14c);
  local_8._0_1_ = 1;
  param_1[0x57] = *(undefined4 *)(param_2 + 0x15c);
  FUN_004d41b0(param_2 + 0x160);
  local_8._0_1_ = 2;
  param_1[0x7a] = *(undefined4 *)(param_2 + 0x1e8);
  param_1[0x7b] = *(undefined4 *)(param_2 + 0x1ec);
  *(undefined1 *)(param_1 + 0x7c) = *(undefined1 *)(param_2 + 0x1f0);
  *(undefined1 *)((int)param_1 + 0x1f1) = *(undefined1 *)(param_2 + 0x1f1);
  FUN_0047a2f0(param_2 + 500);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004cea00(param_2 + 0x240);
  param_1[0x94] = *(undefined4 *)(param_2 + 0x250);
  param_1[0x95] = *(undefined4 *)(param_2 + 0x254);
  param_1[0x96] = *(undefined4 *)(param_2 + 600);
  param_1[0x97] = *(undefined4 *)(param_2 + 0x25c);
  param_1[0x98] = *(undefined4 *)(param_2 + 0x260);
  ExceptionList = local_10;
  return param_1;
}

