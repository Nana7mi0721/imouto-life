
undefined4 FUN_0059d240(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 0;
  if (0 < DAT_00ecfb18) {
    piVar2 = &DAT_00ec3b2c;
    do {
      if (((char)piVar2[-5] != '\0') &&
         ((iVar3 = iVar3 + 1, param_1 == 0 || (*(char *)((int)piVar2 + -0x13) == '\0')))) {
        if (*piVar2 != 0) {
          FUN_005d3370(*piVar2);
          *piVar2 = 0;
        }
        *(undefined1 *)(piVar2 + -5) = 0;
        piVar2[-2] = 0;
        *(undefined1 *)((int)piVar2 + -0x13) = 0;
        iVar1 = iVar1 + 1;
      }
      piVar2 = piVar2 + 6;
    } while (iVar3 < DAT_00ecfb18);
  }
  DAT_00ecfb18 = DAT_00ecfb18 - iVar1;
  return 0;
}

