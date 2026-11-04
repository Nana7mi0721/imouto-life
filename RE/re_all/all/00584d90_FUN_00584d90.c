
undefined4 FUN_00584d90(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_00cc6b10 == 0) {
    return 0xffffffff;
  }
  FUN_00568ca0(0);
  iVar2 = DAT_00dda46c;
  if (DAT_00dda46c != 0) {
    DAT_00dda46c = 0;
    FUN_005846f0(iVar2);
  }
  iVar2 = DAT_00cc6b48;
  if (DAT_00cc6b48 <= DAT_00cc6b4c) {
    do {
      iVar1 = *(int *)(DAT_00cc6b14 + iVar2 * 4);
      if (iVar1 != 0) {
        FUN_005db670(*(undefined4 *)(iVar1 + 4),1,param_1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= DAT_00cc6b4c);
  }
  return 0;
}

