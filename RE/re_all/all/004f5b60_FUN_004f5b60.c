
int FUN_004f5b60(undefined4 param_1,undefined1 param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007b1f50;
  pvStack_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_10;
  while( true ) {
    cVar1 = const_iterator__operator__(&param_2);
    if (cVar1 == '\0') break;
    uVar2 = FUN_004e9610();
    FUN_004f3eb0(param_3,uVar2);
    param_3 = param_3 + 0x388;
    FUN_004f7020();
  }
  ExceptionList = pvStack_10;
  return param_3;
}

