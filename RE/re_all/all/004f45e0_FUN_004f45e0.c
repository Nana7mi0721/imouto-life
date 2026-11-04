
int FUN_004f45e0(int param_1,int param_2,int param_3)

{
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007b1d80;
  pvStack_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x10) {
    FUN_004f3ab0(param_3,param_1);
    param_3 = param_3 + 0x10;
  }
  ExceptionList = pvStack_10;
  return param_3;
}

