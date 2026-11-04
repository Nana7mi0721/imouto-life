
void * __fastcall FUN_004f7a40(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b206b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _eh_vector_constructor_iterator_(param_1,0x10,0x3c,FUN_004ce850,FUN_004ce950);
  local_8 = 0;
  basic_string<>();
  local_8._0_1_ = 1;
  FUN_004cc150();
  local_8._0_1_ = 2;
  FUN_004ce850();
  local_8._0_1_ = 3;
  FUN_004ce850();
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004ce850();
  ExceptionList = local_10;
  return param_1;
}

