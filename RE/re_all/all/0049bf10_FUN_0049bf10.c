
int __thiscall FUN_0049bf10(int param_1,undefined4 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af88b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0049bfe0(0,0);
  local_8 = 0;
  _eh_vector_constructor_iterator_((void *)(param_1 + 0x130),0x10,2,FUN_004ce850,FUN_004ce950);
  local_8._0_1_ = 1;
  basic_string<>();
  local_8._0_1_ = 2;
  basic_string<>();
  local_8._0_1_ = 3;
  FUN_004cc150();
  local_8._0_1_ = 4;
  FUN_004cd090();
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_0049c250();
  *(undefined4 *)(param_1 + 0x26c) = param_2;
  ExceptionList = local_10;
  return param_1;
}

