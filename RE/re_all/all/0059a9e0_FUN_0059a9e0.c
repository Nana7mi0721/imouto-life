
int FUN_0059a9e0(int param_1)

{
  int iVar1;
  
  if (DAT_00f3a04c == 0) {
    return 0;
  }
  if ((DAT_00e80638 == param_1) && (DAT_00e39a54 == 0)) {
    return 0;
  }
  DAT_00e80638 = param_1;
  DAT_00e39a00 = 1;
  if (DAT_00e39a54 == 0) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
  }
  iVar1 = FUN_005d3a70(9,param_1);
  return -(uint)(iVar1 != 0);
}

