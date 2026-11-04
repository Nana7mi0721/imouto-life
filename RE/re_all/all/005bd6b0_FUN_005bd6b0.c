
undefined4 FUN_005bd6b0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if (((((DAT_00cc79c0 != 0) && (-1 < (int)DAT_00a38120)) &&
       ((DAT_00a38120 & 0x7c000000) == DAT_00cc79e8)) &&
      (((int)(DAT_00a38120 & 0xffff) < DAT_00cc79f0 &&
       (piVar1 = *(int **)(DAT_00cc79c4 + (DAT_00a38120 & 0xffff) * 4), piVar1 != (int *)0x0)))) &&
     ((*piVar1 * 0x10000 == (DAT_00a38120 & 0x3ff0000) && (piVar1[4] == 0)))) {
    FUN_005bb610(*(undefined4 *)(piVar1[0x114] + 0xc),*(undefined4 *)(piVar1[0x114] + 0x10));
    return 0;
  }
  if (DAT_00cc47d0 == 0) {
LAB_005bd859:
    FUN_005bb610(DAT_00ef1b64,DAT_00ef1b68);
    return 0;
  }
  if (((-1 < (int)DAT_00a38120) && ((DAT_00a38120 & 0x7c000000) == DAT_00cc47f8)) &&
     ((int)(DAT_00a38120 & 0xffff) < DAT_00cc4800)) {
    iVar3 = *(int *)(DAT_00cc47d4 + (DAT_00a38120 & 0xffff) * 4);
  }
  if (((-1 < (int)DAT_00a38180) && ((DAT_00a38180 & 0x7c000000) == DAT_00cc47f8)) &&
     ((int)(DAT_00a38180 & 0xffff) < DAT_00cc4800)) {
    iVar2 = *(int *)(DAT_00cc47d4 + (DAT_00a38180 & 0xffff) * 4);
  }
  if (iVar3 == 0) {
    if (((iVar2 == 0) || (*(int *)(iVar2 + 0x60) != DAT_00a381b4)) ||
       (*(int *)(iVar2 + 100) != DAT_00a381b8)) goto LAB_005bd859;
  }
  else if (((iVar2 == 0) || (*(int *)(iVar2 + 0x60) < *(int *)(iVar3 + 0x60))) ||
          (*(int *)(iVar2 + 100) < *(int *)(iVar3 + 100))) {
    if (*(int *)(**(int **)(iVar3 + 0x100) + 0x10) != 0) {
      iVar3 = **(int **)(iVar3 + 0x100);
      FUN_005bb610(*(undefined4 *)(iVar3 + 0x10),
                   *(undefined4 *)(*(int *)(iVar3 + 0x14) + DAT_00a38160 * 4));
      return 0;
    }
    if ((*(int *)(iVar3 + 0x60) == DAT_00ef1b6c) && (*(int *)(iVar3 + 100) == DAT_00ef1b70)) {
      FUN_005bb610(DAT_00ef1b64,DAT_00ef1b68);
      return 0;
    }
    FUN_005bb610(0,0);
    return 0;
  }
  FUN_005bb610(*(undefined4 *)(**(int **)(iVar2 + 0x100) + 0x10),
               *(undefined4 *)(*(int *)(**(int **)(iVar2 + 0x100) + 0x14) + DAT_00a38160 * 4));
  return 0;
}

