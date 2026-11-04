
int FUN_0059b2b0(int param_1)

{
  int iVar1;
  
  if (DAT_00f3a04c == 0) {
    return 0;
  }
  if ((param_1 == DAT_00e804a0) && (DAT_00e39a54 == 0)) {
    return 0;
  }
  DAT_00e804a0 = param_1;
  DAT_00e39a00 = 1;
  FUN_00597e70();
  iVar1 = FUN_005d3a70(0x89,param_1);
  return -(uint)(iVar1 != 0);
}

