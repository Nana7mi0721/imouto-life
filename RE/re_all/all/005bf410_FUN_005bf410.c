
undefined4 FUN_005bf410(int param_1)

{
  int iVar1;
  bool bVar2;
  undefined4 local_4;
  
  bVar2 = false;
  local_4 = 0;
  iVar1 = 0;
  do {
    if ((&DAT_00f13454)[iVar1] == param_1) {
      if (!bVar2) {
        FUN_00568ca0(0);
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        bVar2 = true;
      }
      FUN_005bba30(iVar1,1,&local_4);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x80);
  if ((bVar2) && (DAT_00f3a070 != 0)) {
    if (DAT_00ef7314 == 0) {
      if (DAT_00ef7324 == 0) goto LAB_005bf4e6;
    }
    else if ((DAT_00ef7324 == 0) && (FUN_00568ca0(0), DAT_00dda46c != 0)) {
      FUN_00584d70();
    }
    DAT_00ef72e8 = 1;
    if (DAT_00ef7314 != 0) {
      DAT_00ef72e4 = 1;
    }
    DAT_00ef7314 = 0;
    DAT_00ef7318 = 0;
    DAT_00ef72cc = 1;
  }
LAB_005bf4e6:
  FUN_005d1f20(param_1);
  return 0;
}

