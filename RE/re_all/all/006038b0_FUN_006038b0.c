
void FUN_006038b0(void)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_007b24fb;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00603900();
  local_4 = 0xffffffff;
  FUN_006037d0();
  ExceptionList = local_c;
  return;
}

