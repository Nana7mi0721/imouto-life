
int FUN_0055d770(void)

{
  int *piVar1;
  int iVar2;
  uint unaff_ESI;
  int unaff_EDI;
  
  iVar2 = FUN_0057e0e0();
  if (((((iVar2 == 0) || (DAT_00cc50a0 == 0)) || ((int)unaff_ESI < 0)) ||
      (((unaff_ESI & 0x7c000000) != DAT_00cc50c8 || (DAT_00cc50d0 <= (int)(unaff_ESI & 0xffff)))))
     || ((piVar1 = *(int **)(DAT_00cc50a4 + (unaff_ESI & 0xffff) * 4), piVar1 == (int *)0x0 ||
         (*piVar1 * 0x10000 != (unaff_ESI & 0x3ff0000))))) {
    return -1;
  }
  if ((unaff_EDI < 0) || (iVar2 = FUN_005526a0(), -1 < iVar2)) {
    iVar2 = FUN_00551e70();
    return (-1 < iVar2) - 1;
  }
  return -1;
}

