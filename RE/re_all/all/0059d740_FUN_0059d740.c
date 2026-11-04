
undefined4 FUN_0059d740(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if ((((DAT_00cc79c0 != 0) && (-1 < (int)DAT_00a38120)) &&
      ((DAT_00a38120 & 0x7c000000) == DAT_00cc79e8)) &&
     ((((int)(DAT_00a38120 & 0xffff) < DAT_00cc79f0 &&
       (piVar1 = *(int **)(DAT_00cc79c4 + (DAT_00a38120 & 0xffff) * 4), piVar1 != (int *)0x0)) &&
      ((*piVar1 * 0x10000 == (DAT_00a38120 & 0x3ff0000) && (piVar1[4] == 0)))))) {
    FUN_005d38f0(*(undefined4 *)(piVar1[0x114] + 8));
    return 0;
  }
  if (DAT_00cc47d0 != 0) {
    if (((-1 < (int)DAT_00a38120) && ((DAT_00a38120 & 0x7c000000) == DAT_00cc47f8)) &&
       ((int)(DAT_00a38120 & 0xffff) < DAT_00cc4800)) {
      iVar3 = *(int *)(DAT_00cc47d4 + (DAT_00a38120 & 0xffff) * 4);
    }
    if (((-1 < (int)DAT_00a38180) && ((DAT_00a38180 & 0x7c000000) == DAT_00cc47f8)) &&
       ((int)(DAT_00a38180 & 0xffff) < DAT_00cc4800)) {
      iVar2 = *(int *)(DAT_00cc47d4 + (DAT_00a38180 & 0xffff) * 4);
    }
  }
  if ((DAT_00ca39f4 != 0) && (DAT_00f3a154 != 0)) {
    FUN_005d38f0(DAT_00ddb5c8);
    return 0;
  }
  if (iVar3 == 0) {
    if (((iVar2 != 0) && (DAT_00a381b4 <= *(int *)(iVar2 + 0x60))) &&
       (DAT_00a381b8 <= *(int *)(iVar2 + 100))) {
      FUN_005d38f0(*(undefined4 *)(**(int **)(iVar2 + 0x100) + 0x20));
      return 0;
    }
  }
  else {
    if (((iVar2 != 0) && (*(int *)(iVar3 + 0x60) <= *(int *)(iVar2 + 0x60))) &&
       (*(int *)(iVar3 + 100) <= *(int *)(iVar2 + 100))) {
      FUN_005d38f0(*(undefined4 *)(**(int **)(iVar2 + 0x100) + 0x20));
      return 0;
    }
    iVar2 = *(int *)(**(int **)(iVar3 + 0x100) + 0x20);
    if (iVar2 != 0) goto LAB_0059d8d3;
    if ((DAT_00ddb5cc < *(int *)(iVar3 + 0x60)) || (DAT_00ddb5d0 < *(int *)(iVar3 + 100))) {
      FUN_005d38f0(0);
      return 0;
    }
  }
  iVar2 = DAT_00ddb5c8;
LAB_0059d8d3:
  FUN_005d38f0(iVar2);
  return 0;
}

