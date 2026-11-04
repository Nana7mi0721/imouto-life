
undefined4 FUN_0057be60(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_00ca3a18 == 0) {
    return 0xffffffff;
  }
  iVar2 = DAT_00cc56b8;
  if (DAT_00cc56b8 <= DAT_00cc56bc) {
    do {
      iVar1 = *(int *)(DAT_00cc5684 + iVar2 * 4);
      if (iVar1 != 0) {
        FUN_0057bda0(*(undefined4 *)(iVar1 + 4),1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= DAT_00cc56bc);
  }
  return 0;
}

