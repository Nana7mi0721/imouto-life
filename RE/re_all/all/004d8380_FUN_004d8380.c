
void __thiscall FUN_004d8380(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1290;
  pvStack_10 = ExceptionList;
  ExceptionList = &pvStack_10;
  cVar1 = FUN_004d88b0(param_2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar2 = FUN_004d7f30(*(undefined4 *)(param_1 + 4),param_2,param_3);
    *(undefined4 *)(param_1 + 8) = uVar2;
  }
  ExceptionList = pvStack_10;
  return;
}

