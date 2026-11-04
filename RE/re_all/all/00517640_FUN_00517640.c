
undefined4 FUN_00517640(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_00cc47d0 == 0) {
    return 0;
  }
  iVar2 = DAT_00cc4808;
  if (DAT_00cc4808 <= DAT_00cc480c) {
    do {
      iVar1 = *(int *)(DAT_00cc47d4 + iVar2 * 4);
      if (((iVar1 != 0) && (*(int *)(iVar1 + 0x4c) != 0)) && (*(int *)(iVar1 + 0x84) != 0)) {
        FUN_00580b80(*(undefined4 *)(iVar1 + 4));
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= DAT_00cc480c);
  }
  return 0;
}

