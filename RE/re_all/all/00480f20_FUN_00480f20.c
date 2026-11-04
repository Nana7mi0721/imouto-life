
void FUN_00480f20(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af38b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_004cfab0();
  if (iVar1 < param_1) {
    for (local_14 = FUN_004cfab0(); local_14 < param_1; local_14 = local_14 + 1) {
      uVar2 = FUN_00481020();
      local_8 = 0;
      FUN_004cfb80(uVar2);
      local_8 = 0xffffffff;
      FUN_00481330();
    }
  }
  else {
    iVar1 = FUN_004cfab0();
    if (param_1 < iVar1) {
      FUN_004cfa80(param_1);
    }
  }
  for (local_18 = 0; local_18 < param_1; local_18 = local_18 + 1) {
    piVar3 = (int *)FUN_004cfb40(local_18);
    *piVar3 = local_18;
  }
  ExceptionList = local_10;
  return;
}

