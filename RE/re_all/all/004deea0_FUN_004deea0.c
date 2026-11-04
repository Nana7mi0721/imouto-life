
int __thiscall FUN_004deea0(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1578;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004e90c0(param_2);
  local_8 = 0;
  cVar1 = FUN_004def50();
  if (cVar1 != '\0') {
    iVar3 = FUN_004e0490();
    if (iVar3 != 0) {
      FUN_004e0490();
      flush();
    }
  }
  uVar2 = FUN_004def50();
  *(undefined1 *)(param_1 + 4) = uVar2;
  ExceptionList = local_10;
  return param_1;
}

