
void FUN_004f6980(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1fc1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_004e22e0(0x14,param_1);
  local_8 = 0;
  if (iVar1 != 0) {
    <>(param_2);
  }
  ExceptionList = local_10;
  return;
}

