
undefined4 FUN_005bd5f0(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_00a38124;
  do {
    if (*piVar1 != 0) goto LAB_005bd682;
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0xa38140);
  if (((((DAT_00a38120 != 0xfffffffe) && (DAT_00a38120 != 0xfffffffc)) &&
       (DAT_00a38120 != 0xfffffffd)) &&
      (((DAT_00a38120 != 0xfffffff0 && (DAT_00cc47d0 != 0)) &&
       ((-1 < (int)DAT_00a38120 &&
        (((DAT_00a38120 & 0x7c000000) == DAT_00cc47f8 &&
         ((int)(DAT_00a38120 & 0xffff) < DAT_00cc4800)))))))) &&
     ((piVar1 = *(int **)(DAT_00cc47d4 + (DAT_00a38120 & 0xffff) * 4), piVar1 != (int *)0x0 &&
      ((((*piVar1 * 0x10000 == (DAT_00a38120 & 0x3ff0000) && (piVar1[4] == 0)) &&
        (*(char *)(piVar1[0x13] + 10) != '\0')) && (*(char *)(piVar1[0x13] + 8) != '\0')))))) {
    iVar2 = 1;
  }
LAB_005bd682:
  if (iVar2 != DAT_00a380c8) {
    DAT_00ef72e4 = 1;
    DAT_00a3d360 = 1;
    DAT_00a380c8 = iVar2;
  }
  return 0;
}

