
undefined4
FUN_004ea530(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 param_5)

{
  undefined4 uVar1;
  int iVar2;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1a31;
  pvStack_10 = ExceptionList;
  ExceptionList = &pvStack_10;
  uVar1 = FUN_004e4140(1);
  local_8 = 0;
  iVar2 = FUN_004e22e0(0x18,uVar1);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (iVar2 != 0) {
    FUN_004ebeb0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = pvStack_10;
  return uVar1;
}

