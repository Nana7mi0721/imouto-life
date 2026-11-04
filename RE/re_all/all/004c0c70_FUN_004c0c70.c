
void * __fastcall FUN_004c0c70(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0be9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _eh_vector_constructor_iterator_(param_1,0x10,3,FUN_004cd090,FUN_004cd4c0);
  local_8 = 0;
  _eh_vector_constructor_iterator_((void *)((int)param_1 + 0x40),0x10,3,FUN_004ce850,FUN_004ce950);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004cd4c0();
  FUN_004cd4c0();
  FUN_004cd4c0();
  *(undefined4 *)((int)param_1 + 0x70) = 8;
  if (*DAT_00a16674 == '(') {
    *(undefined4 *)((int)param_1 + 0x70) = 10;
  }
  *(undefined4 *)((int)param_1 + 0x74) = *(undefined4 *)((int)param_1 + 0x70);
  *(undefined4 *)((int)param_1 + 0x78) = 0;
  ExceptionList = local_10;
  return param_1;
}

