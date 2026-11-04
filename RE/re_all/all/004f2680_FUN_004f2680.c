
void FUN_004f2680(int param_1,int param_2,undefined4 param_3)

{
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007b1bf0;
  pvStack_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_004f3c30(param_1,param_3);
    param_1 = param_1 + 0x4c;
  }
  ExceptionList = pvStack_10;
  return;
}

