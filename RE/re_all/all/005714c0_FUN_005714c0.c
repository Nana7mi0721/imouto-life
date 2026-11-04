
void FUN_005714c0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar3 = DAT_00b22da4;
  iVar5 = 0;
  if (0 < DAT_00b22da4) {
    piVar4 = &DAT_00afed08;
    do {
      piVar2 = (int *)*piVar4;
      if ((piVar2 != (int *)0x0) && (iVar5 = iVar5 + 1, *piVar2 < 1)) {
        piVar1 = piVar2 + 2;
        FUN_0056f750(piVar1);
        FUN_0056f750(piVar1);
        FUN_0056d380(piVar1,0,0x890);
        FUN_0056e1d0(piVar2);
        *piVar4 = 0;
        DAT_00b22da4 = DAT_00b22da4 + -1;
      }
      piVar4 = piVar4 + 1;
    } while (iVar5 < iVar3);
  }
  return;
}

