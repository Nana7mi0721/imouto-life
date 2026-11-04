
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_0049bfe0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af8e4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  basic_string<>();
  local_8._0_1_ = 1;
  basic_string<>();
  local_8._0_1_ = 2;
  _eh_vector_constructor_iterator_((void *)(param_1 + 0x9c),0x10,4,FUN_004ce850,FUN_004ce950);
  local_8._0_1_ = 3;
  FUN_004ce850();
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_00536af0(0x22);
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(float *)(param_1 + 0x54) = (float)param_2;
  *(float *)(param_1 + 0x58) = (float)param_3;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0x18;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined8 *)(param_1 + 0x88) = _DAT_007d0a60;
  *(undefined8 *)(param_1 + 0x80) = _DAT_007d1100;
  *(undefined1 *)(param_1 + 0x98) = 0;
  FUN_00536940(5);
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined1 *)(param_1 + 0xe0) = 0;
  *(undefined1 *)(param_1 + 0xe1) = 0;
  *(undefined1 *)(param_1 + 0xe2) = 0;
  *(undefined1 *)(param_1 + 0xe3) = 0;
  *(undefined4 *)(param_1 + 0xe4) = 0;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x100) = 1;
  *(undefined1 *)(param_1 + 0x104) = 1;
  *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x10c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x120) = 0;
  ExceptionList = local_10;
  return param_1;
}

