
undefined4 FUN_00584e10(void)

{
  int iVar1;
  int iVar2;
  
  FUN_00568ca0(0);
  iVar2 = DAT_00dda46c;
  if (DAT_00dda46c != 0) {
    DAT_00dda46c = 0;
    FUN_005846f0(iVar2);
  }
  if ((DAT_00cc6b10 != 0) && (iVar2 = DAT_00cc6b48, DAT_00cc6b48 <= DAT_00cc6b4c)) {
    do {
      iVar1 = *(int *)(DAT_00cc6b14 + iVar2 * 4);
      if (iVar1 != 0) {
        FUN_005806c0(*(undefined4 *)(iVar1 + 4));
        FUN_005db6b0(*(undefined4 *)(iVar1 + 4));
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= DAT_00cc6b4c);
  }
  if ((DAT_00cc6e00 != 0) && (iVar2 = DAT_00cc6e38, DAT_00cc6e38 <= DAT_00cc6e3c)) {
    do {
      iVar1 = *(int *)(DAT_00cc6e04 + iVar2 * 4);
      if (iVar1 != 0) {
        FUN_005806c0(*(undefined4 *)(iVar1 + 4));
        FUN_005db6d0(*(undefined4 *)(iVar1 + 4));
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= DAT_00cc6e3c);
  }
  return 0;
}

