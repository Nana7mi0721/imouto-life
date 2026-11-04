
void __fastcall FUN_004bd510(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_007b0a46;
  local_10 = ExceptionList;
  local_8 = 1;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 600) != -1) {
    ExceptionList = &local_10;
    FUN_00515700(*(undefined4 *)(param_1 + 600),0);
  }
  local_8 = local_8 & 0xffffff00;
  FUN_0049c1c0();
  local_8 = 0xffffffff;
  FUN_0049c1c0();
  ExceptionList = local_10;
  return;
}

