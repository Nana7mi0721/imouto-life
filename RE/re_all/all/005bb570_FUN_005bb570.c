
void FUN_005bb570(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    if ((&DAT_00f1370c)[iVar4] != 0) break;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  iVar1 = iVar4 + 1;
  if (iVar1 < 8) {
    piVar2 = (int *)(&DAT_00f13730 + iVar1 * 0x2c);
    piVar3 = &DAT_00f1370c + iVar1;
    do {
      if (*piVar3 != 0) {
        if (piVar2[-1] != *(int *)(&DAT_00f1372c + iVar4 * 0x2c)) {
          return;
        }
        if (*piVar2 != *(int *)(&DAT_00f13730 + iVar4 * 0x2c)) {
          return;
        }
      }
      piVar3 = piVar3 + 1;
      piVar2 = piVar2 + 0xb;
    } while ((int)piVar3 < 0xf1372c);
  }
  if ((DAT_00f138ac == 0) ||
     ((DAT_00f138b0 == *(int *)(&DAT_00f1372c + iVar4 * 0x2c) &&
      (DAT_00f138b4 == *(int *)(&DAT_00f13730 + iVar4 * 0x2c))))) {
    FUN_005d2d10(8,&DAT_00f1388c,DAT_00f138dc);
  }
  return;
}

