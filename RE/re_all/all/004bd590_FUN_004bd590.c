
int __fastcall FUN_004bd590(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0a74;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0049bfe0(0,0);
  local_8 = 0;
  FUN_004ce850();
  local_8._0_1_ = 1;
  FUN_004ce850();
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined1 *)(param_1 + 0xe0) = 1;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 0x194) = 0;
  *(undefined4 *)(param_1 + 0x198) = 0;
  *(undefined1 *)(param_1 + 300) = 0;
  *(undefined1 *)(param_1 + 0x12d) = 0;
  *(undefined1 *)(param_1 + 0x12e) = 0;
  *(undefined4 *)(param_1 + 0x17c) = 0;
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined4 *)(param_1 + 0x184) = 0;
  *(undefined4 *)(param_1 + 0x16c) = 0;
  *(undefined4 *)(param_1 + 0x170) = 0;
  *(undefined4 *)(param_1 + 0x174) = 0;
  *(undefined4 *)(param_1 + 0x178) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 400) = 1;
  FUN_00476570();
  ExceptionList = local_10;
  return param_1;
}

