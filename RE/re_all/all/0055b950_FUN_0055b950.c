
undefined4 FUN_0055b950(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0057e0e0();
  if ((iVar1 == 0) || (DAT_00cc5390 == 0)) {
    return 0xffffffff;
  }
  iVar1 = DAT_00cc53c8;
  if (DAT_00cc53c8 <= DAT_00cc53cc) {
    do {
      iVar2 = *(int *)(DAT_00cc5394 + iVar1 * 4);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0x30) != 0)) {
        iVar2 = FUN_0057e250(iVar2);
        if (iVar2 < 0) {
          return 0xffffffff;
        }
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 <= DAT_00cc53cc);
  }
  return 0;
}

