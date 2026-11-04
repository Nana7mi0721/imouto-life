
void __thiscall FUN_004cbc60(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0ea8;
  pvStack_10 = ExceptionList;
  ExceptionList = &pvStack_10;
  FUN_004deea0(param_1);
  local_8 = 0;
  cVar1 = FUN_004df060();
  if (cVar1 == '\0') {
    FUN_004cbd12();
    return;
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004cbdb0();
  FUN_004d5060(param_2,param_3);
  FUN_004cbd12();
  return;
}

