
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * __fastcall FUN_00472810(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007aecd5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _eh_vector_constructor_iterator_(param_1,0xc,3,FUN_004cbff0,FUN_00472a90);
  local_8 = 0;
  FUN_004cbff0();
  local_8._0_1_ = 1;
  FUN_004cbff0();
  local_8._0_1_ = 2;
  FUN_004cbff0();
  local_8._0_1_ = 3;
  FUN_004ce850();
  local_8._0_1_ = 4;
  FUN_004cc650();
  local_8._0_1_ = 5;
  _eh_vector_constructor_iterator_((void *)((int)param_1 + 0xb8),0x10,3,FUN_004ce850,FUN_004ce950);
  local_8._0_1_ = 6;
  FUN_004ce850();
  local_8._0_1_ = 7;
  FUN_004ce850();
  local_8._0_1_ = 8;
  FUN_004ce850();
  local_8._0_1_ = 9;
  _eh_vector_constructor_iterator_((void *)((int)param_1 + 0x13c),0x10,2,FUN_004ce850,FUN_004ce950);
  local_8._0_1_ = 10;
  FUN_004ce850();
  local_8 = CONCAT31(local_8._1_3_,0xb);
  *(undefined4 *)((int)param_1 + 0x5c) = 0;
  *(undefined4 *)((int)param_1 + 0x60) = 0;
  *(undefined4 *)((int)param_1 + 100) = 0;
  *(undefined4 *)((int)param_1 + 0x68) = 0;
  *(undefined4 *)((int)param_1 + 0x6c) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x70) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x74) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x78) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x88) = 100;
  *(undefined4 *)((int)param_1 + 0x80) = 100;
  *(undefined4 *)((int)param_1 + 0xe8) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x120) = 0;
  *(undefined4 *)((int)param_1 + 0x124) = 0;
  *(undefined4 *)((int)param_1 + 0x128) = 0;
  *(undefined4 *)((int)param_1 + 300) = 0;
  *(undefined4 *)((int)param_1 + 0x8c) = 100;
  *(undefined4 *)((int)param_1 + 0x90) = 100;
  *(undefined1 *)((int)param_1 + 0x130) = 0;
  *(undefined4 *)((int)param_1 + 0x138) = 0xffffffff;
  *(undefined1 *)((int)param_1 + 0x11c) = 0;
  *(undefined1 *)((int)param_1 + 0x58) = 0;
  FUN_004ccc40();
  FUN_004ccc40();
  FUN_004ce950();
  FUN_004ce950();
  FUN_004ce950();
  FUN_004ce950();
  FUN_004ce950();
  *(undefined8 *)((int)param_1 + 0x170) = _DAT_007d07d0;
  ExceptionList = local_10;
  return param_1;
}

