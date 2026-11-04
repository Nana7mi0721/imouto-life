
undefined4 __fastcall FUN_00471820(undefined4 param_1)

{
  int *piVar1;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae998;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004cf7f0();
  local_8 = 0;
  FUN_004cfa80(1);
  for (local_14 = 0; local_14 < 1; local_14 = local_14 + 1) {
    piVar1 = (int *)FUN_004cfb40(local_14);
    *piVar1 = local_14;
  }
  ExceptionList = local_10;
  return param_1;
}

