
void __thiscall FUN_004ad670(char *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007aff93;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = FUN_004d00e0();
  if (local_18 < param_2) {
    for (; local_18 < param_2; local_18 = local_18 + 1) {
      uVar1 = FUN_004ad980();
      local_8 = 0;
      FUN_004d0160(uVar1);
      local_8 = 0xffffffff;
      FUN_004ada40();
      if (*param_1 != '\0') {
        uVar1 = FUN_004ad7e0();
        local_8 = 1;
        FUN_004d0600(uVar1);
        local_8 = 0xffffffff;
        FUN_004ada90();
      }
      uVar1 = 1;
      iVar2 = FUN_004d00e0(1);
      FUN_004779b0(iVar2 + -1,uVar1);
    }
  }
  else {
    FUN_004d00b0(param_2);
    if (*param_1 != '\0') {
      FUN_004d0500(param_2);
    }
  }
  ExceptionList = local_10;
  return;
}

