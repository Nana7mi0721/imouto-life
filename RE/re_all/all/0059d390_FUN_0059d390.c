
undefined4 __fastcall FUN_0059d390(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = FUN_0057fce0(param_1);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  iVar1 = FUN_00550060(0);
  iVar2 = 0;
  iVar4 = 0;
  if (0 < DAT_00edbb1c) {
    piVar3 = &DAT_00ecfb30;
    do {
      if ((((char)piVar3[-5] != '\0') && (iVar4 = iVar4 + 1, *(char *)((int)piVar3 + -0x13) == '\0')
          ) && (1999 < iVar1 - piVar3[-1])) {
        if (*piVar3 != 0) {
          FUN_005d3370(*piVar3);
          *piVar3 = 0;
        }
        *(undefined1 *)(piVar3 + -5) = 0;
        piVar3[-2] = 0;
        *(undefined1 *)((int)piVar3 + -0x13) = 0;
        iVar2 = iVar2 + 1;
      }
      piVar3 = piVar3 + 6;
    } while (iVar4 < DAT_00edbb1c);
  }
  DAT_00edbb1c = DAT_00edbb1c - iVar2;
  return 0;
}

