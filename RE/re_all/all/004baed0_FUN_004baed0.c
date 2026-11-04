
void __fastcall FUN_004baed0(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007aecd5;
  local_10 = ExceptionList;
  local_8 = 0xb;
  ExceptionList = &local_10;
  FUN_00550c60(0);
  FUN_004ce950();
  FUN_004ce950();
  FUN_004ce950();
  FUN_004ccc40();
  FUN_004ccc40();
  local_8._0_1_ = 10;
  FUN_004ce950();
  local_8._0_1_ = 9;
  _eh_vector_destructor_iterator_((void *)((int)param_1 + 0x13c),0x10,2,FUN_004ce950);
  local_8._0_1_ = 8;
  FUN_004ce950();
  local_8._0_1_ = 7;
  FUN_004ce950();
  local_8._0_1_ = 6;
  FUN_004ce950();
  local_8._0_1_ = 5;
  _eh_vector_destructor_iterator_((void *)((int)param_1 + 0xb8),0x10,3,FUN_004ce950);
  local_8._0_1_ = 4;
  FUN_00471980();
  local_8._0_1_ = 3;
  FUN_004ce950();
  local_8._0_1_ = 2;
  FUN_00472a90();
  local_8._0_1_ = 1;
  FUN_00472a90();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00472a90();
  local_8 = 0xffffffff;
  _eh_vector_destructor_iterator_(param_1,0xc,3,FUN_00472a90);
  ExceptionList = local_10;
  return;
}

