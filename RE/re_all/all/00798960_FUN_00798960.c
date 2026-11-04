
int FUN_00798960(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1;
  if ((0 < (int)param_1) && ((int)param_1 < 3)) {
    iVar1 = FUN_00799c20(&param_1);
    if (iVar1 == 0) {
      param_1 = param_1 + 3 & 0xfffffffc;
      iVar2 = FUN_007a02f0(iVar2);
      return iVar2 + 0x58 + param_1;
    }
  }
  return 0;
}

