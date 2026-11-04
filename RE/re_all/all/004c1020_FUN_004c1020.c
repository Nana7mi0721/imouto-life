
void __fastcall FUN_004c1020(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007b0c93;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  _eh_vector_destructor_iterator_((void *)((int)param_1 + 0x40),0x10,3,FUN_004ce950);
  local_8 = 0xffffffff;
  _eh_vector_destructor_iterator_(param_1,0x10,3,FUN_004cd4c0);
  ExceptionList = local_10;
  return;
}

