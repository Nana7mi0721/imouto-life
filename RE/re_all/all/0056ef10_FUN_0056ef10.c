
undefined4 FUN_0056ef10(int *param_1)

{
  int iVar1;
  
  if (param_1[0x221] != 0) {
    iVar1 = thunk_FUN_005954e0(param_1[0x222]);
    if (iVar1 == 0) {
      return 0;
    }
    FUN_0052dbe0(param_1[0x222]);
    param_1[0x222] = 0;
    if (*param_1 == 0) {
      FUN_0056e7c0(param_1,param_1[0x13]);
      param_1[0x221] = 0;
      return 1;
    }
    if (4 < *(ushort *)((int)param_1 + 10)) {
      FUN_0056e8a0(param_1,param_1[0x13]);
      param_1[0x221] = 0;
      return 1;
    }
    FUN_0056e590(param_1[0x21c],param_1[0x21d],0,0,param_1 + 0x216);
    param_1[0x221] = 0;
  }
  return 1;
}

