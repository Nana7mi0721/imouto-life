
undefined4 FUN_005b9d00(int param_1)

{
  int iVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (param_1 == 1) {
    iVar1 = 3;
  }
  else if (param_1 == 2) {
    iVar1 = 2;
  }
  else {
    iVar1 = 1;
  }
  if ((DAT_00f130e4 != iVar1) || (DAT_00ef7324 != 0)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00f130dc = 1;
    DAT_00ef72cc = 1;
    DAT_00f130e4 = iVar1;
  }
  return 0;
}

