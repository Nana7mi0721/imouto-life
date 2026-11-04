
int FUN_004f4180(int param_1,int param_2,int param_3)

{
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007b1d20;
  pvStack_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_10;
  for (; param_1 != param_2; param_1 = param_1 + 0xc) {
    FUN_004f3a30(param_3,param_1);
    param_3 = param_3 + 0xc;
  }
  ExceptionList = pvStack_10;
  return param_3;
}

