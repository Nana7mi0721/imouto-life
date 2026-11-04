
undefined4 FUN_0059b6b0(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (&DAT_00e39924)[param_3 + (param_2 + param_1 * 3) * 9];
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if ((DAT_00e80628 != iVar1) || (DAT_00e39a54 != 0)) {
    FUN_005d3bd0(iVar1);
    DAT_00e80628 = iVar1;
  }
  DAT_00e80614 = 0;
  DAT_00e39a00 = 1;
  return 0;
}

