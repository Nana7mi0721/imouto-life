
undefined4 FUN_00563b90(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  iVar3 = *(int *)(unaff_ESI + 0x18);
  if (iVar3 != -1) {
    iVar1 = *(int *)(unaff_ESI + 0x1c);
    if (iVar1 < iVar3) {
      iVar2 = iVar3;
      iVar3 = iVar1;
    }
    else {
      iVar2 = iVar1;
    }
    *(int *)(unaff_ESI + 0x24) = iVar3;
    if (iVar2 != *(int *)(unaff_ESI + 0x10)) {
      FUN_0056d460(*(int *)(unaff_ESI + 0x28) + iVar3 * 2,*(int *)(unaff_ESI + 0x28) + iVar2 * 2,
                   (*(int *)(unaff_ESI + 0x10) - iVar2) * 2);
    }
    *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 0x10) - (iVar2 - iVar3);
    *(undefined2 *)(*(int *)(unaff_ESI + 0x28) + *(int *)(unaff_ESI + 0x10) * 2) = 0;
    *(undefined4 *)(unaff_ESI + 0x18) = 0xffffffff;
    *(undefined4 *)(unaff_ESI + 0x1c) = 0xffffffff;
    if (*(int *)(unaff_ESI + 0x10) < *(int *)(unaff_ESI + 0x20)) {
      *(int *)(unaff_ESI + 0x20) = *(int *)(unaff_ESI + 0x10);
    }
  }
  return 0;
}

