
undefined4 FUN_004f0d30(int *param_1)

{
  void *this;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b149b;
  local_10 = ExceptionList;
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    ExceptionList = &local_10;
    this = operator_new(8);
    local_8 = 0;
    if (this == (void *)0x0) {
      local_1c = 0;
    }
    else {
      local_1c = FID_conflict_messages<wchar_t>(this,0);
    }
    *param_1 = local_1c;
  }
  ExceptionList = local_10;
  return 2;
}

