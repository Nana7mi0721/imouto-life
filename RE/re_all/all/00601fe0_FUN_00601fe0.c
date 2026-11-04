
void __fastcall FUN_00601fe0(int param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_007b2483;
  local_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &local_c;
  _free(*(void **)(param_1 + 0x14));
  local_4 = local_4 & 0xffffff00;
  FUN_006034c0();
  local_4 = 0xffffffff;
  FUN_00602f20();
  ExceptionList = local_c;
  return;
}

