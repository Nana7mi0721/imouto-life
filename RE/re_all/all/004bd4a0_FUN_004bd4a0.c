
undefined4 __fastcall FUN_004bd4a0(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0a46;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0049bfe0(0,0);
  local_8 = 0;
  FUN_0049bfe0(0,0);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00476390();
  ExceptionList = local_10;
  return param_1;
}

