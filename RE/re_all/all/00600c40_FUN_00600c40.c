
void FUN_00600c40(void)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_007b2438;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_006016b0();
  local_4 = 0xffffffff;
  FUN_00602f20();
  ExceptionList = local_c;
  return;
}

